#ifndef AV1_RTCD_H_
#define AV1_RTCD_H_

#ifdef RTCD_C
#define RTCD_EXTERN
#else
#define RTCD_EXTERN extern
#endif

/*
 * AV1
 */

#include "aom/aom_integer.h"
#include "av1/common/common.h"
#include "av1/common/enums.h"
#include "av1/common/quant_common.h"
#include "av1/common/filter.h"
#include "av1/common/av1_txfm.h"

struct macroblockd;

/* Encoder forward decls */
struct macroblock;
struct aom_variance_vtable;
struct search_site_config;
struct mv;
union int_mv;
struct yv12_buffer_config;
typedef int16_t od_dering_in;

#ifdef __cplusplus
extern "C" {
#endif

int64_t av1_block_error_c(const tran_low_t *coeff, const tran_low_t *dqcoeff, intptr_t block_size, int64_t *ssz);
int64_t av1_block_error_sse2(const tran_low_t *coeff, const tran_low_t *dqcoeff, intptr_t block_size, int64_t *ssz);
int64_t av1_block_error_avx2(const tran_low_t *coeff, const tran_low_t *dqcoeff, intptr_t block_size, int64_t *ssz);
#define av1_block_error av1_block_error_avx2

int64_t av1_block_error_fp_c(const int16_t *coeff, const int16_t *dqcoeff, int block_size);
int64_t av1_block_error_fp_sse2(const int16_t *coeff, const int16_t *dqcoeff, int block_size);
#define av1_block_error_fp av1_block_error_fp_sse2

void av1_convolve_horiz_c(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, const InterpFilterParams fp, const int subpel_x_q4, int x_step_q4, int avg);
void av1_convolve_horiz_ssse3(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, const InterpFilterParams fp, const int subpel_x_q4, int x_step_q4, int avg);
#define av1_convolve_horiz av1_convolve_horiz_ssse3

void av1_convolve_init_c(void);
void av1_convolve_init_ssse3(void);
#define av1_convolve_init av1_convolve_init_ssse3

void av1_convolve_vert_c(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, const InterpFilterParams fp, const int subpel_x_q4, int x_step_q4, int avg);
void av1_convolve_vert_ssse3(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, const InterpFilterParams fp, const int subpel_x_q4, int x_step_q4, int avg);
#define av1_convolve_vert av1_convolve_vert_ssse3

int av1_diamond_search_sad_c(struct macroblock *x, const struct search_site_config *cfg,  struct mv *ref_mv, struct mv *best_mv, int search_param, int sad_per_bit, int *num00, const struct aom_variance_vtable *fn_ptr, const struct mv *center_mv);
#define av1_diamond_search_sad av1_diamond_search_sad_c

void av1_fdct8x8_quant_c(const int16_t *input, int stride, tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
void av1_fdct8x8_quant_sse2(const int16_t *input, int stride, tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
void av1_fdct8x8_quant_ssse3(const int16_t *input, int stride, tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
#define av1_fdct8x8_quant av1_fdct8x8_quant_ssse3

void av1_fht16x16_c(const int16_t *input, tran_low_t *output, int stride, int tx_type);
void av1_fht16x16_sse2(const int16_t *input, tran_low_t *output, int stride, int tx_type);
void av1_fht16x16_avx2(const int16_t *input, tran_low_t *output, int stride, int tx_type);
#define av1_fht16x16 av1_fht16x16_avx2

void av1_fht16x32_c(const int16_t *input, tran_low_t *output, int stride, int tx_type);
void av1_fht16x32_sse2(const int16_t *input, tran_low_t *output, int stride, int tx_type);
#define av1_fht16x32 av1_fht16x32_sse2

void av1_fht16x4_c(const int16_t *input, tran_low_t *output, int stride, int tx_type);
#define av1_fht16x4 av1_fht16x4_c

void av1_fht16x8_c(const int16_t *input, tran_low_t *output, int stride, int tx_type);
void av1_fht16x8_sse2(const int16_t *input, tran_low_t *output, int stride, int tx_type);
#define av1_fht16x8 av1_fht16x8_sse2

void av1_fht32x16_c(const int16_t *input, tran_low_t *output, int stride, int tx_type);
void av1_fht32x16_sse2(const int16_t *input, tran_low_t *output, int stride, int tx_type);
#define av1_fht32x16 av1_fht32x16_sse2

void av1_fht32x32_c(const int16_t *input, tran_low_t *output, int stride, int tx_type);
void av1_fht32x32_avx2(const int16_t *input, tran_low_t *output, int stride, int tx_type);
#define av1_fht32x32 av1_fht32x32_avx2

void av1_fht32x8_c(const int16_t *input, tran_low_t *output, int stride, int tx_type);
#define av1_fht32x8 av1_fht32x8_c

void av1_fht4x16_c(const int16_t *input, tran_low_t *output, int stride, int tx_type);
#define av1_fht4x16 av1_fht4x16_c

void av1_fht4x4_c(const int16_t *input, tran_low_t *output, int stride, int tx_type);
void av1_fht4x4_sse2(const int16_t *input, tran_low_t *output, int stride, int tx_type);
#define av1_fht4x4 av1_fht4x4_sse2

void av1_fht4x8_c(const int16_t *input, tran_low_t *output, int stride, int tx_type);
void av1_fht4x8_sse2(const int16_t *input, tran_low_t *output, int stride, int tx_type);
#define av1_fht4x8 av1_fht4x8_sse2

void av1_fht8x16_c(const int16_t *input, tran_low_t *output, int stride, int tx_type);
void av1_fht8x16_sse2(const int16_t *input, tran_low_t *output, int stride, int tx_type);
#define av1_fht8x16 av1_fht8x16_sse2

void av1_fht8x32_c(const int16_t *input, tran_low_t *output, int stride, int tx_type);
#define av1_fht8x32 av1_fht8x32_c

void av1_fht8x4_c(const int16_t *input, tran_low_t *output, int stride, int tx_type);
void av1_fht8x4_sse2(const int16_t *input, tran_low_t *output, int stride, int tx_type);
#define av1_fht8x4 av1_fht8x4_sse2

void av1_fht8x8_c(const int16_t *input, tran_low_t *output, int stride, int tx_type);
void av1_fht8x8_sse2(const int16_t *input, tran_low_t *output, int stride, int tx_type);
#define av1_fht8x8 av1_fht8x8_sse2

int av1_full_range_search_c(const struct macroblock *x, const struct search_site_config *cfg, struct mv *ref_mv, struct mv *best_mv, int search_param, int sad_per_bit, int *num00, const struct aom_variance_vtable *fn_ptr, const struct mv *center_mv);
#define av1_full_range_search av1_full_range_search_c

int av1_full_search_sad_c(const struct macroblock *x, const struct mv *ref_mv, int sad_per_bit, int distance, const struct aom_variance_vtable *fn_ptr, const struct mv *center_mv, struct mv *best_mv);
int av1_full_search_sadx3(const struct macroblock *x, const struct mv *ref_mv, int sad_per_bit, int distance, const struct aom_variance_vtable *fn_ptr, const struct mv *center_mv, struct mv *best_mv);
int av1_full_search_sadx8(const struct macroblock *x, const struct mv *ref_mv, int sad_per_bit, int distance, const struct aom_variance_vtable *fn_ptr, const struct mv *center_mv, struct mv *best_mv);
#define av1_full_search_sad av1_full_search_sadx8

void av1_fwd_idtx_c(const int16_t *src_diff, tran_low_t *coeff, int stride, int bs, int tx_type);
#define av1_fwd_idtx av1_fwd_idtx_c

void av1_fwht4x4_c(const int16_t *input, tran_low_t *output, int stride);
#define av1_fwht4x4 av1_fwht4x4_c

void av1_iht16x16_256_add_c(const tran_low_t *input, uint8_t *output, int pitch, int tx_type);
void av1_iht16x16_256_add_sse2(const tran_low_t *input, uint8_t *output, int pitch, int tx_type);
void av1_iht16x16_256_add_avx2(const tran_low_t *input, uint8_t *output, int pitch, int tx_type);
#define av1_iht16x16_256_add av1_iht16x16_256_add_avx2

void av1_iht16x32_512_add_c(const tran_low_t *input, uint8_t *dest, int dest_stride, int tx_type);
void av1_iht16x32_512_add_sse2(const tran_low_t *input, uint8_t *dest, int dest_stride, int tx_type);
#define av1_iht16x32_512_add av1_iht16x32_512_add_sse2

void av1_iht16x4_64_add_c(const tran_low_t *input, uint8_t *dest, int dest_stride, int tx_type);
#define av1_iht16x4_64_add av1_iht16x4_64_add_c

void av1_iht16x8_128_add_c(const tran_low_t *input, uint8_t *dest, int dest_stride, int tx_type);
void av1_iht16x8_128_add_sse2(const tran_low_t *input, uint8_t *dest, int dest_stride, int tx_type);
#define av1_iht16x8_128_add av1_iht16x8_128_add_sse2

void av1_iht32x16_512_add_c(const tran_low_t *input, uint8_t *dest, int dest_stride, int tx_type);
void av1_iht32x16_512_add_sse2(const tran_low_t *input, uint8_t *dest, int dest_stride, int tx_type);
#define av1_iht32x16_512_add av1_iht32x16_512_add_sse2

void av1_iht32x32_1024_add_c(const tran_low_t *input, uint8_t *output, int pitch, int tx_type);
#define av1_iht32x32_1024_add av1_iht32x32_1024_add_c

void av1_iht32x8_256_add_c(const tran_low_t *input, uint8_t *dest, int dest_stride, int tx_type);
#define av1_iht32x8_256_add av1_iht32x8_256_add_c

void av1_iht4x16_64_add_c(const tran_low_t *input, uint8_t *dest, int dest_stride, int tx_type);
#define av1_iht4x16_64_add av1_iht4x16_64_add_c

void av1_iht4x4_16_add_c(const tran_low_t *input, uint8_t *dest, int dest_stride, int tx_type);
void av1_iht4x4_16_add_sse2(const tran_low_t *input, uint8_t *dest, int dest_stride, int tx_type);
#define av1_iht4x4_16_add av1_iht4x4_16_add_sse2

void av1_iht4x8_32_add_c(const tran_low_t *input, uint8_t *dest, int dest_stride, int tx_type);
void av1_iht4x8_32_add_sse2(const tran_low_t *input, uint8_t *dest, int dest_stride, int tx_type);
#define av1_iht4x8_32_add av1_iht4x8_32_add_sse2

void av1_iht8x16_128_add_c(const tran_low_t *input, uint8_t *dest, int dest_stride, int tx_type);
void av1_iht8x16_128_add_sse2(const tran_low_t *input, uint8_t *dest, int dest_stride, int tx_type);
#define av1_iht8x16_128_add av1_iht8x16_128_add_sse2

void av1_iht8x32_256_add_c(const tran_low_t *input, uint8_t *dest, int dest_stride, int tx_type);
#define av1_iht8x32_256_add av1_iht8x32_256_add_c

void av1_iht8x4_32_add_c(const tran_low_t *input, uint8_t *dest, int dest_stride, int tx_type);
void av1_iht8x4_32_add_sse2(const tran_low_t *input, uint8_t *dest, int dest_stride, int tx_type);
#define av1_iht8x4_32_add av1_iht8x4_32_add_sse2

void av1_iht8x8_64_add_c(const tran_low_t *input, uint8_t *dest, int dest_stride, int tx_type);
void av1_iht8x8_64_add_sse2(const tran_low_t *input, uint8_t *dest, int dest_stride, int tx_type);
#define av1_iht8x8_64_add av1_iht8x8_64_add_sse2

void av1_quantize_b_c(const tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan, int log_scale);
#define av1_quantize_b av1_quantize_b_c

void av1_quantize_fp_c(const tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
void av1_quantize_fp_sse2(const tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
void av1_quantize_fp_ssse3(const tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
#define av1_quantize_fp av1_quantize_fp_ssse3

void av1_quantize_fp_32x32_c(const tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
void av1_quantize_fp_32x32_ssse3(const tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
#define av1_quantize_fp_32x32 av1_quantize_fp_32x32_ssse3

void av1_temporal_filter_apply_c(uint8_t *frame1, unsigned int stride, uint8_t *frame2, unsigned int block_width, unsigned int block_height, int strength, int filter_weight, unsigned int *accumulator, uint16_t *count);
void av1_temporal_filter_apply_sse2(uint8_t *frame1, unsigned int stride, uint8_t *frame2, unsigned int block_width, unsigned int block_height, int strength, int filter_weight, unsigned int *accumulator, uint16_t *count);
#define av1_temporal_filter_apply av1_temporal_filter_apply_sse2

void av1_rtcd(void);

#ifdef RTCD_C
#include "aom_ports/x86.h"
static void setup_rtcd_internal(void)
{
    int flags = x86_simd_caps();

    (void)flags;

}
#endif

#ifdef __cplusplus
}  // extern "C"
#endif

#endif
