/*
 * Copyright (c) 2016, Alliance for Open Media. All rights reserved
 *
 * This source code is subject to the terms of the BSD 2 Clause License and
 * the Alliance for Open Media Patent License 1.0. If the BSD 2 Clause License
 * was not distributed with this source code in the LICENSE file, you can
 * obtain it at www.aomedia.org/license/software. If the Alliance for Open
 * Media Patent License 1.0 was not distributed with this source code in the
 * PATENTS file, you can obtain it at www.aomedia.org/license/patent.
 */

#ifndef AOM_DSP_BITWRITER_H_
#define AOM_DSP_BITWRITER_H_

#include <assert.h>
#include "./aom_config.h"
#if CONFIG_EC_ADAPT && !CONFIG_EC_MULTISYMBOL
#error "CONFIG_EC_ADAPT is enabled without enabling CONFIG_EC_MULTISYMBOL"
#endif

#if CONFIG_ANS
#include "aom_dsp/buf_ans.h"
#elif CONFIG_DAALA_EC
#include "aom_dsp/daalaboolwriter.h"
#else
#include "aom_dsp/dkboolwriter.h"
#endif
#include "aom_dsp/prob.h"

#if CONFIG_RD_DEBUG
#include "av1/common/blockd.h"
#include "av1/encoder/cost.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if CONFIG_ANS
typedef struct BufAnsCoder aom_writer;
#elif CONFIG_DAALA_EC
typedef struct daala_writer aom_writer;
#else
typedef struct aom_dk_writer aom_writer;
#endif

typedef struct TOKEN_STATS {
  int cost;
#if CONFIG_VAR_TX
#if CONFIG_RD_DEBUG
  int txb_coeff_cost_map[TXB_COEFF_COST_MAP_SIZE][TXB_COEFF_COST_MAP_SIZE];
#endif
#endif
} TOKEN_STATS;

static INLINE void init_token_stats(TOKEN_STATS *token_stats) {
#if CONFIG_VAR_TX
#if CONFIG_RD_DEBUG
  int r, c;
  for (r = 0; r < TXB_COEFF_COST_MAP_SIZE; ++r) {
    for (c = 0; c < TXB_COEFF_COST_MAP_SIZE; ++c) {
      token_stats->txb_coeff_cost_map[r][c] = 0;
    }
  }
#endif
#endif
  token_stats->cost = 0;
}

static INLINE void aom_start_encode(aom_writer *bc, uint8_t *buffer) {
#if CONFIG_ANS
  (void)bc;
  (void)buffer;
  assert(0 && "buf_ans requires a more complicated startup procedure");
#elif CONFIG_DAALA_EC
  aom_daala_start_encode(bc, buffer);
#else
  aom_dk_start_encode(bc, buffer);
#endif
}

static INLINE void aom_stop_encode(aom_writer *bc) {
#if CONFIG_ANS
  (void)bc;
  assert(0 && "buf_ans requires a more complicated shutdown procedure");
#elif CONFIG_DAALA_EC
  aom_daala_stop_encode(bc);
#else
  aom_dk_stop_encode(bc);
#endif
}

static INLINE void aom_write(aom_writer *br, int bit, int probability) {
#if CONFIG_ANS
  buf_uabs_write(br, bit, probability);
#elif CONFIG_DAALA_EC
  // Note this uses raw bits and is not the same as aom_daala_write(r, 128);
  aom_daala_write(br, bit, probability);
#else
  aom_dk_write(br, bit, probability);
#endif
}

static INLINE void aom_write_record(aom_writer *br, int bit, int probability,
                                    TOKEN_STATS *token_stats) {
  aom_write(br, bit, probability);
#if CONFIG_RD_DEBUG
  token_stats->cost += av1_cost_bit(probability, bit);
#else
  (void)token_stats;
#endif
}

static INLINE void aom_write_bit(aom_writer *w, int bit) {
#if CONFIG_ANS
  buf_uabs_write_bit(w, bit);
#elif CONFIG_DAALA_EC
  aom_daala_write_bit(w, bit);
#else
  aom_write(w, bit, 128);  // aom_prob_half
#endif
}

static INLINE void aom_write_bit_record(aom_writer *w, int bit,
                                        TOKEN_STATS *token_stats) {
  aom_write_bit(w, bit);
#if CONFIG_RD_DEBUG
  token_stats->cost += av1_cost_bit(128, bit);  // aom_prob_half
#else
  (void)token_stats;
#endif
}

static INLINE void aom_write_literal(aom_writer *w, int data, int bits) {
  int bit;

  for (bit = bits - 1; bit >= 0; bit--) aom_write_bit(w, 1 & (data >> bit));
}

static INLINE void aom_write_tree_bits(aom_writer *w, const aom_tree_index *tr,
                                       const aom_prob *probs, int bits, int len,
                                       aom_tree_index i) {
  do {
    const int bit = (bits >> --len) & 1;
    aom_write(w, bit, probs[i >> 1]);
    i = tr[i + bit];
  } while (len);
}

static INLINE void aom_write_tree_bits_record(aom_writer *w,
                                              const aom_tree_index *tr,
                                              const aom_prob *probs, int bits,
                                              int len, aom_tree_index i,
                                              TOKEN_STATS *token_stats) {
  do {
    const int bit = (bits >> --len) & 1;
    aom_write_record(w, bit, probs[i >> 1], token_stats);
    i = tr[i + bit];
  } while (len);
}

static INLINE void aom_write_tree(aom_writer *w, const aom_tree_index *tree,
                                  const aom_prob *probs, int bits, int len,
                                  aom_tree_index i) {
#if CONFIG_DAALA_EC
  daala_write_tree_bits(w, tree, probs, bits, len, i);
#else
  aom_write_tree_bits(w, tree, probs, bits, len, i);
#endif
}

static INLINE void aom_write_tree_record(aom_writer *w,
                                         const aom_tree_index *tree,
                                         const aom_prob *probs, int bits,
                                         int len, aom_tree_index i,
                                         TOKEN_STATS *token_stats) {
#if CONFIG_DAALA_EC
  (void)token_stats;
  daala_write_tree_bits(w, tree, probs, bits, len, i);
#else
  aom_write_tree_bits_record(w, tree, probs, bits, len, i, token_stats);
#endif
}

#if CONFIG_EC_MULTISYMBOL
static INLINE void aom_write_symbol(aom_writer *w, int symb, aom_cdf_prob *cdf,
                                    int nsymbs) {
#if CONFIG_ANS
  struct rans_sym s;
  (void)nsymbs;
  assert(cdf);
  s.cum_prob = symb > 0 ? cdf[symb - 1] : 0;
  s.prob = cdf[symb] - s.cum_prob;
  buf_rans_write(w, &s);
#elif CONFIG_DAALA_EC
  daala_write_symbol(w, symb, cdf, nsymbs);
#else
#error \
    "CONFIG_EC_MULTISYMBOL is selected without a valid backing entropy " \
  "coder. Enable daala_ec or ans for a valid configuration."
#endif

#if CONFIG_EC_ADAPT
  update_cdf(cdf, symb, nsymbs);
#endif
}

#if CONFIG_PVQ
static INLINE void aom_write_symbol_unscaled(aom_writer *w, int symb,
                                             const aom_cdf_prob *cdf,
                                             int nsymbs) {
#if CONFIG_DAALA_EC
  od_ec_encode_cdf_unscaled(&w->ec, symb, cdf, nsymbs);
#else
#error "CONFIG_PVQ currently requires CONFIG_DAALA_EC."
#endif
}
#endif
#endif  // CONFIG_EC_MULTISYMBOL

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // AOM_DSP_BITWRITER_H_
