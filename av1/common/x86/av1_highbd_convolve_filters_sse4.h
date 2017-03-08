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

#ifndef AV1_COMMON_X86_AV1_HIGHBD_CONVOLVE_FILTERS_SSE4_H_
#define AV1_COMMON_X86_AV1_HIGHBD_CONVOLVE_FILTERS_SSE4_H_

#include "./aom_config.h"

#if CONFIG_AOM_HIGHBITDEPTH
#if CONFIG_DUAL_FILTER
DECLARE_ALIGNED(16, static const int16_t,
                sub_pel_filters_12sharp_highbd_ver_signal_dir[15][6][8]) = {
  {
      { 0, 1, 0, 1, 0, 1, 0, 1 },
      { -1, 3, -1, 3, -1, 3, -1, 3 },
      { -7, 127, -7, 127, -7, 127, -7, 127 },
      { 8, -4, 8, -4, 8, -4, 8, -4 },
      { 2, -1, 2, -1, 2, -1, 2, -1 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
  },
  {
      { 0, 1, 0, 1, 0, 1, 0, 1 },
      { -3, 5, -3, 5, -3, 5, -3, 5 },
      { -12, 124, -12, 124, -12, 124, -12, 124 },
      { 18, -8, 18, -8, 18, -8, 18, -8 },
      { 4, -2, 4, -2, 4, -2, 4, -2 },
      { 1, 0, 1, 0, 1, 0, 1, 0 },
  },
  {
      { -1, 2, -1, 2, -1, 2, -1, 2 },
      { -4, 8, -4, 8, -4, 8, -4, 8 },
      { -17, 120, -17, 120, -17, 120, -17, 120 },
      { 28, -11, 28, -11, 28, -11, 28, -11 },
      { 6, -3, 6, -3, 6, -3, 6, -3 },
      { 1, -1, 1, -1, 1, -1, 1, -1 },
  },
  {
      { -1, 2, -1, 2, -1, 2, -1, 2 },
      { -4, 10, -4, 10, -4, 10, -4, 10 },
      { -21, 114, -21, 114, -21, 114, -21, 114 },
      { 38, -15, 38, -15, 38, -15, 38, -15 },
      { 8, -4, 8, -4, 8, -4, 8, -4 },
      { 2, -1, 2, -1, 2, -1, 2, -1 },
  },
  {
      { -1, 3, -1, 3, -1, 3, -1, 3 },
      { -5, 11, -5, 11, -5, 11, -5, 11 },
      { -23, 107, -23, 107, -23, 107, -23, 107 },
      { 49, -18, 49, -18, 49, -18, 49, -18 },
      { 9, -5, 9, -5, 9, -5, 9, -5 },
      { 2, -1, 2, -1, 2, -1, 2, -1 },
  },
  {
      { -1, 3, -1, 3, -1, 3, -1, 3 },
      { -6, 12, -6, 12, -6, 12, -6, 12 },
      { -25, 99, -25, 99, -25, 99, -25, 99 },
      { 60, -21, 60, -21, 60, -21, 60, -21 },
      { 11, -6, 11, -6, 11, -6, 11, -6 },
      { 3, -1, 3, -1, 3, -1, 3, -1 },
  },
  {
      { -1, 3, -1, 3, -1, 3, -1, 3 },
      { -6, 12, -6, 12, -6, 12, -6, 12 },
      { -25, 90, -25, 90, -25, 90, -25, 90 },
      { 70, -23, 70, -23, 70, -23, 70, -23 },
      { 12, -6, 12, -6, 12, -6, 12, -6 },
      { 3, -1, 3, -1, 3, -1, 3, -1 },
  },
  {
      { -1, 3, -1, 3, -1, 3, -1, 3 },
      { -6, 12, -6, 12, -6, 12, -6, 12 },
      { -24, 80, -24, 80, -24, 80, -24, 80 },
      { 80, -24, 80, -24, 80, -24, 80, -24 },
      { 12, -6, 12, -6, 12, -6, 12, -6 },
      { 3, -1, 3, -1, 3, -1, 3, -1 },
  },
  {
      { -1, 3, -1, 3, -1, 3, -1, 3 },
      { -6, 12, -6, 12, -6, 12, -6, 12 },
      { -23, 70, -23, 70, -23, 70, -23, 70 },
      { 90, -25, 90, -25, 90, -25, 90, -25 },
      { 12, -6, 12, -6, 12, -6, 12, -6 },
      { 3, -1, 3, -1, 3, -1, 3, -1 },
  },
  {
      { -1, 3, -1, 3, -1, 3, -1, 3 },
      { -6, 11, -6, 11, -6, 11, -6, 11 },
      { -21, 60, -21, 60, -21, 60, -21, 60 },
      { 99, -25, 99, -25, 99, -25, 99, -25 },
      { 12, -6, 12, -6, 12, -6, 12, -6 },
      { 3, -1, 3, -1, 3, -1, 3, -1 },
  },
  {
      { -1, 2, -1, 2, -1, 2, -1, 2 },
      { -5, 9, -5, 9, -5, 9, -5, 9 },
      { -18, 49, -18, 49, -18, 49, -18, 49 },
      { 107, -23, 107, -23, 107, -23, 107, -23 },
      { 11, -5, 11, -5, 11, -5, 11, -5 },
      { 3, -1, 3, -1, 3, -1, 3, -1 },
  },
  {
      { -1, 2, -1, 2, -1, 2, -1, 2 },
      { -4, 8, -4, 8, -4, 8, -4, 8 },
      { -15, 38, -15, 38, -15, 38, -15, 38 },
      { 114, -21, 114, -21, 114, -21, 114, -21 },
      { 10, -4, 10, -4, 10, -4, 10, -4 },
      { 2, -1, 2, -1, 2, -1, 2, -1 },
  },
  {
      { -1, 1, -1, 1, -1, 1, -1, 1 },
      { -3, 6, -3, 6, -3, 6, -3, 6 },
      { -11, 28, -11, 28, -11, 28, -11, 28 },
      { 120, -17, 120, -17, 120, -17, 120, -17 },
      { 8, -4, 8, -4, 8, -4, 8, -4 },
      { 2, -1, 2, -1, 2, -1, 2, -1 },
  },
  {
      { 0, 1, 0, 1, 0, 1, 0, 1 },
      { -2, 4, -2, 4, -2, 4, -2, 4 },
      { -8, 18, -8, 18, -8, 18, -8, 18 },
      { 124, -12, 124, -12, 124, -12, 124, -12 },
      { 5, -3, 5, -3, 5, -3, 5, -3 },
      { 1, 0, 1, 0, 1, 0, 1, 0 },
  },
  {
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { -1, 2, -1, 2, -1, 2, -1, 2 },
      { -4, 8, -4, 8, -4, 8, -4, 8 },
      { 127, -7, 127, -7, 127, -7, 127, -7 },
      { 3, -1, 3, -1, 3, -1, 3, -1 },
      { 1, 0, 1, 0, 1, 0, 1, 0 },
  },
};
#endif
#endif
#if CONFIG_AOM_HIGHBITDEPTH
#if USE_TEMPORALFILTER_12TAP
DECLARE_ALIGNED(16, static const int16_t,
                sub_pel_filters_temporalfilter_12_highbd_ver_signal_dir[15][6]
                                                                       [8]) = {
  {
      { 0, 1, 0, 1, 0, 1, 0, 1 },
      { -1, 3, -1, 3, -1, 3, -1, 3 },
      { -7, 127, -7, 127, -7, 127, -7, 127 },
      { 8, -4, 8, -4, 8, -4, 8, -4 },
      { 2, -1, 2, -1, 2, -1, 2, -1 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
  },
  {
      { 0, 1, 0, 1, 0, 1, 0, 1 },
      { -3, 5, -3, 5, -3, 5, -3, 5 },
      { -12, 124, -12, 124, -12, 124, -12, 124 },
      { 18, -8, 18, -8, 18, -8, 18, -8 },
      { 4, -2, 4, -2, 4, -2, 4, -2 },
      { 1, 0, 1, 0, 1, 0, 1, 0 },
  },
  {
      { -1, 2, -1, 2, -1, 2, -1, 2 },
      { -4, 8, -4, 8, -4, 8, -4, 8 },
      { -17, 120, -17, 120, -17, 120, -17, 120 },
      { 28, -11, 28, -11, 28, -11, 28, -11 },
      { 6, -3, 6, -3, 6, -3, 6, -3 },
      { 1, -1, 1, -1, 1, -1, 1, -1 },
  },
  {
      { -1, 2, -1, 2, -1, 2, -1, 2 },
      { -4, 10, -4, 10, -4, 10, -4, 10 },
      { -21, 114, -21, 114, -21, 114, -21, 114 },
      { 38, -15, 38, -15, 38, -15, 38, -15 },
      { 8, -4, 8, -4, 8, -4, 8, -4 },
      { 2, -1, 2, -1, 2, -1, 2, -1 },
  },
  {
      { -1, 3, -1, 3, -1, 3, -1, 3 },
      { -5, 11, -5, 11, -5, 11, -5, 11 },
      { -23, 107, -23, 107, -23, 107, -23, 107 },
      { 49, -18, 49, -18, 49, -18, 49, -18 },
      { 9, -5, 9, -5, 9, -5, 9, -5 },
      { 2, -1, 2, -1, 2, -1, 2, -1 },
  },
  {
      { -1, 3, -1, 3, -1, 3, -1, 3 },
      { -6, 12, -6, 12, -6, 12, -6, 12 },
      { -25, 99, -25, 99, -25, 99, -25, 99 },
      { 60, -21, 60, -21, 60, -21, 60, -21 },
      { 11, -6, 11, -6, 11, -6, 11, -6 },
      { 3, -1, 3, -1, 3, -1, 3, -1 },
  },
  {
      { -1, 3, -1, 3, -1, 3, -1, 3 },
      { -6, 12, -6, 12, -6, 12, -6, 12 },
      { -25, 90, -25, 90, -25, 90, -25, 90 },
      { 70, -23, 70, -23, 70, -23, 70, -23 },
      { 12, -6, 12, -6, 12, -6, 12, -6 },
      { 3, -1, 3, -1, 3, -1, 3, -1 },
  },
  {
      { -1, 3, -1, 3, -1, 3, -1, 3 },
      { -6, 12, -6, 12, -6, 12, -6, 12 },
      { -24, 80, -24, 80, -24, 80, -24, 80 },
      { 80, -24, 80, -24, 80, -24, 80, -24 },
      { 12, -6, 12, -6, 12, -6, 12, -6 },
      { 3, -1, 3, -1, 3, -1, 3, -1 },
  },
  {
      { -1, 3, -1, 3, -1, 3, -1, 3 },
      { -6, 12, -6, 12, -6, 12, -6, 12 },
      { -23, 70, -23, 70, -23, 70, -23, 70 },
      { 90, -25, 90, -25, 90, -25, 90, -25 },
      { 12, -6, 12, -6, 12, -6, 12, -6 },
      { 3, -1, 3, -1, 3, -1, 3, -1 },
  },
  {
      { -1, 3, -1, 3, -1, 3, -1, 3 },
      { -6, 11, -6, 11, -6, 11, -6, 11 },
      { -21, 60, -21, 60, -21, 60, -21, 60 },
      { 99, -25, 99, -25, 99, -25, 99, -25 },
      { 12, -6, 12, -6, 12, -6, 12, -6 },
      { 3, -1, 3, -1, 3, -1, 3, -1 },
  },
  {
      { -1, 2, -1, 2, -1, 2, -1, 2 },
      { -5, 9, -5, 9, -5, 9, -5, 9 },
      { -18, 49, -18, 49, -18, 49, -18, 49 },
      { 107, -23, 107, -23, 107, -23, 107, -23 },
      { 11, -5, 11, -5, 11, -5, 11, -5 },
      { 3, -1, 3, -1, 3, -1, 3, -1 },
  },
  {
      { -1, 2, -1, 2, -1, 2, -1, 2 },
      { -4, 8, -4, 8, -4, 8, -4, 8 },
      { -15, 38, -15, 38, -15, 38, -15, 38 },
      { 114, -21, 114, -21, 114, -21, 114, -21 },
      { 10, -4, 10, -4, 10, -4, 10, -4 },
      { 2, -1, 2, -1, 2, -1, 2, -1 },
  },
  {
      { -1, 1, -1, 1, -1, 1, -1, 1 },
      { -3, 6, -3, 6, -3, 6, -3, 6 },
      { -11, 28, -11, 28, -11, 28, -11, 28 },
      { 120, -17, 120, -17, 120, -17, 120, -17 },
      { 8, -4, 8, -4, 8, -4, 8, -4 },
      { 2, -1, 2, -1, 2, -1, 2, -1 },
  },
  {
      { 0, 1, 0, 1, 0, 1, 0, 1 },
      { -2, 4, -2, 4, -2, 4, -2, 4 },
      { -8, 18, -8, 18, -8, 18, -8, 18 },
      { 124, -12, 124, -12, 124, -12, 124, -12 },
      { 5, -3, 5, -3, 5, -3, 5, -3 },
      { 1, 0, 1, 0, 1, 0, 1, 0 },
  },
  {
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { -1, 2, -1, 2, -1, 2, -1, 2 },
      { -4, 8, -4, 8, -4, 8, -4, 8 },
      { 127, -7, 127, -7, 127, -7, 127, -7 },
      { 3, -1, 3, -1, 3, -1, 3, -1 },
      { 1, 0, 1, 0, 1, 0, 1, 0 },
  },
};
#endif
#endif
#endif  // AV1_COMMON_X86_AV1_HIGHBD_CONVOLVE_FILTERS_SSE4_H_
