//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: normalizeControlPoints.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "normalizeControlPoints.h"
#include "ITER_API_rtwutil.h"
#include "combineVectorElements.h"
#include "hypot.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &pts
//                ::coder::array<double, 2U> &ptsNorm
//                double normMatrixInv[3][3]
// Return Type  : void
//
namespace coder {
namespace images {
namespace geotrans {
namespace internal {
void b_normalizeControlPoints(const ::coder::array<double, 2U> &pts,
                              ::coder::array<double, 2U> &ptsNorm,
                              double normMatrixInv[3][3])
{
  array<double, 1U> b_a;
  array<double, 1U> b_ptsNorm;
  array<double, 1U> b_x;
  array<double, 1U> c_ptsNorm;
  double cent[2];
  double y[2];
  double scaleFactor;
  double sumOfPointDistancesFromOriginSquared;
  int b_loop_ub;
  int c_loop_ub;
  int d_k;
  int d_loop_ub;
  int e_loop_ub;
  int i1;
  int i4;
  int k_N;
  int loop_ub;
  int vlen;
  int xsubs_idx_1;
  short ysubs_idx_1;
  vlen = pts.size(0);
  if (pts.size(0) == 0) {
    y[0] = 0.0;
    y[1] = 0.0;
  } else {
    int firstBlockLength;
    int lastBlockLength;
    int nblocks;
    if (pts.size(0) <= 1024) {
      firstBlockLength = pts.size(0);
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = pts.size(0) / 1024;
      lastBlockLength = pts.size(0) - (nblocks * 1024);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    for (int k{0}; k < 2; k++) {
      y[k] = pts[pts.size(0) * k];
      for (int b_k{2}; b_k <= firstBlockLength; b_k++) {
        if (vlen >= 2) {
          ysubs_idx_1 = static_cast<short>(k + 1);
          y[k] += pts[(b_k + (pts.size(0) * k)) - 1];
        }
      }
      if (2 <= nblocks) {
        xsubs_idx_1 = k + 1;
        ysubs_idx_1 = static_cast<short>(k + 1);
      }
      for (int c_ib{2}; c_ib <= nblocks; c_ib++) {
        double bsum;
        int b_hi;
        int offset;
        offset = (c_ib - 1) * 1024;
        bsum = pts[offset + (pts.size(0) * (xsubs_idx_1 - 1))];
        if (c_ib == nblocks) {
          b_hi = lastBlockLength;
        } else {
          b_hi = 1024;
        }
        for (int e_k{2}; e_k <= b_hi; e_k++) {
          double b_bsum;
          b_bsum = bsum;
          if (vlen >= 2) {
            b_bsum = bsum + pts[((offset + e_k) + (pts.size(0) * k)) - 1];
          }
          bsum = b_bsum;
        }
        y[ysubs_idx_1 - 1] += bsum;
      }
    }
  }
  cent[0] = y[0] / (static_cast<double>(pts.size(0)));
  cent[1] = y[1] / (static_cast<double>(pts.size(0)));
  ptsNorm.set_size(pts.size(0), 2);
  if (pts.size(0) != 0) {
    int acoef;
    acoef = static_cast<int>(pts.size(0) != 1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(d_k, i1)

    for (int c_k = 0; c_k < 2; c_k++) {
      i1 = ptsNorm.size(0) - 1;
      for (d_k = 0; d_k <= i1; d_k++) {
        ptsNorm[d_k + (ptsNorm.size(0) * c_k)] =
            pts[(acoef * d_k) + (pts.size(0) * c_k)] - cent[c_k];
      }
    }
  }
  loop_ub = ptsNorm.size(0);
  b_ptsNorm.set_size(ptsNorm.size(0));
  b_loop_ub = ptsNorm.size(0);
  if ((static_cast<int>(ptsNorm.size(0) < 4)) != 0) {
    for (int b_i{0}; b_i < loop_ub; b_i++) {
      b_ptsNorm[b_i] = ptsNorm[b_i];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i = 0; b_i < b_loop_ub; b_i++) {
      b_ptsNorm[b_i] = ptsNorm[b_i];
    }
  }
  c_loop_ub = ptsNorm.size(0);
  c_ptsNorm.set_size(ptsNorm.size(0));
  d_loop_ub = ptsNorm.size(0);
  if ((static_cast<int>(ptsNorm.size(0) < 4)) != 0) {
    for (int i2{0}; i2 < c_loop_ub; i2++) {
      c_ptsNorm[i2] = ptsNorm[i2 + ptsNorm.size(0)];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i2 = 0; i2 < d_loop_ub; i2++) {
      c_ptsNorm[i2] = ptsNorm[i2 + ptsNorm.size(0)];
    }
  }
  c_hypot(b_ptsNorm, c_ptsNorm, b_a);
  b_x.set_size(b_a.size(0));
  k_N = b_a.size(0);
  if ((static_cast<int>(b_a.size(0) < 4)) != 0) {
    for (int g_k{0}; g_k < k_N; g_k++) {
      b_x[g_k] = rt_powd_snf(b_a[g_k], 2.0);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int g_k = 0; g_k < k_N; g_k++) {
      b_x[g_k] = rt_powd_snf(b_a[g_k], 2.0);
    }
  }
  sumOfPointDistancesFromOriginSquared = combineVectorElements(b_x);
  if (sumOfPointDistancesFromOriginSquared > 0.0) {
    scaleFactor = std::sqrt(2.0 * (static_cast<double>(pts.size(0)))) /
                  std::sqrt(sumOfPointDistancesFromOriginSquared);
  } else {
    scaleFactor = 1.0;
  }
  ptsNorm.set_size(ptsNorm.size(0), 2);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i4,        \
                                                                    e_loop_ub)

  for (int i3 = 0; i3 < 2; i3++) {
    e_loop_ub = ptsNorm.size(0);
    for (i4 = 0; i4 < e_loop_ub; i4++) {
      ptsNorm[i4 + (ptsNorm.size(0) * i3)] =
          ptsNorm[i4 + (ptsNorm.size(0) * i3)] * scaleFactor;
    }
  }
  normMatrixInv[0][0] = 1.0 / scaleFactor;
  normMatrixInv[1][0] = 0.0;
  normMatrixInv[2][0] = 0.0;
  normMatrixInv[0][1] = 0.0;
  normMatrixInv[1][1] = 1.0 / scaleFactor;
  normMatrixInv[2][1] = 0.0;
  normMatrixInv[0][2] = cent[0];
  normMatrixInv[1][2] = cent[1];
  normMatrixInv[2][2] = 1.0;
}

//
// Arguments    : const ::coder::array<double, 2U> &pts
//                ::coder::array<double, 2U> &ptsNorm
//                double normMatrixInv[3][3]
// Return Type  : void
//
void normalizeControlPoints(const ::coder::array<double, 2U> &pts,
                            ::coder::array<double, 2U> &ptsNorm,
                            double normMatrixInv[3][3])
{
  array<double, 2U> cent;
  array<double, 2U> y;
  array<double, 1U> b_a;
  array<double, 1U> b_ptsNorm;
  array<double, 1U> b_x;
  array<double, 1U> c_ptsNorm;
  double scaleFactor;
  double sumOfPointDistancesFromOriginSquared;
  int b_acoef;
  int b_loop_ub;
  int b_pts;
  int b_u0;
  int b_u1;
  int b_y;
  int c_loop_ub;
  int c_u1;
  int c_y;
  int csz_idx_1;
  int d_loop_ub;
  int e_k;
  int e_loop_ub;
  int f_loop_ub;
  int g_loop_ub;
  int h_loop_ub;
  int i3;
  int i6;
  int i9;
  int k_N;
  int u0;
  int varargin_2;
  int varargin_3;
  int vlen;
  int xsubs_idx_1;
  int ysubs_idx_1;
  vlen = pts.size(0);
  if ((pts.size(0) == 0) || (pts.size(1) == 0)) {
    int loop_ub;
    y.set_size(1, pts.size(1));
    loop_ub = pts.size(1);
    if ((static_cast<int>(pts.size(1) < 4)) != 0) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        y[i1] = 0.0;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i1 = 0; i1 < loop_ub; i1++) {
        y[i1] = 0.0;
      }
    }
  } else {
    int b_i;
    int firstBlockLength;
    int lastBlockLength;
    int nblocks;
    y.set_size(1, pts.size(1));
    b_i = pts.size(1);
    if (pts.size(0) <= 1024) {
      firstBlockLength = pts.size(0);
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = pts.size(0) / 1024;
      lastBlockLength = pts.size(0) - (nblocks * 1024);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    for (int k{0}; k < b_i; k++) {
      y[k] = pts[pts.size(0) * k];
      for (int b_k{2}; b_k <= firstBlockLength; b_k++) {
        if (vlen >= 2) {
          ysubs_idx_1 = k + 1;
          y[k] = y[k] + pts[(b_k + (pts.size(0) * k)) - 1];
        }
      }
      if (2 <= nblocks) {
        xsubs_idx_1 = k + 1;
        ysubs_idx_1 = k + 1;
      }
      for (int c_ib{2}; c_ib <= nblocks; c_ib++) {
        double bsum;
        int b_hi;
        int offset;
        offset = (c_ib - 1) * 1024;
        bsum = pts[offset + (pts.size(0) * (xsubs_idx_1 - 1))];
        if (c_ib == nblocks) {
          b_hi = lastBlockLength;
        } else {
          b_hi = 1024;
        }
        for (int c_k{2}; c_k <= b_hi; c_k++) {
          double b_bsum;
          b_bsum = bsum;
          if (vlen >= 2) {
            b_bsum = bsum + pts[((offset + c_k) + (pts.size(0) * k)) - 1];
          }
          bsum = b_bsum;
        }
        y[ysubs_idx_1 - 1] = y[ysubs_idx_1 - 1] + bsum;
      }
    }
  }
  b_pts = pts.size(0);
  cent.set_size(1, y.size(1));
  b_loop_ub = y.size(1);
  if ((static_cast<int>(y.size(1) < 4)) != 0) {
    for (int i2{0}; i2 < b_loop_ub; i2++) {
      cent[i2] = y[i2] / (static_cast<double>(b_pts));
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i2 = 0; i2 < b_loop_ub; i2++) {
      cent[i2] = y[i2] / (static_cast<double>(b_pts));
    }
  }
  u0 = cent.size(1);
  b_u1 = pts.size(1);
  if (u0 <= b_u1) {
    b_y = u0;
  } else {
    b_y = b_u1;
  }
  if (cent.size(1) == 1) {
    csz_idx_1 = pts.size(1);
  } else if (pts.size(1) == 1) {
    csz_idx_1 = cent.size(1);
  } else if (pts.size(1) == cent.size(1)) {
    csz_idx_1 = pts.size(1);
  } else {
    csz_idx_1 = b_y;
  }
  b_u0 = cent.size(1);
  c_u1 = pts.size(1);
  if (b_u0 <= c_u1) {
    c_y = b_u0;
  } else {
    c_y = c_u1;
  }
  if (cent.size(1) == 1) {
    i3 = pts.size(1);
  } else if (pts.size(1) == 1) {
    i3 = cent.size(1);
  } else if (pts.size(1) == cent.size(1)) {
    i3 = pts.size(1);
  } else {
    i3 = c_y;
  }
  ptsNorm.set_size(pts.size(0), i3);
  if ((pts.size(0) != 0) && (csz_idx_1 != 0)) {
    int acoef;
    int bcoef;
    int i4;
    acoef = static_cast<int>(pts.size(1) != 1);
    bcoef = static_cast<int>(cent.size(1) != 1);
    i4 = csz_idx_1 - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    e_k, i6, b_acoef, varargin_3, varargin_2)

    for (int d_k = 0; d_k <= i4; d_k++) {
      varargin_2 = acoef * d_k;
      varargin_3 = bcoef * d_k;
      b_acoef = static_cast<int>(pts.size(0) != 1);
      i6 = ptsNorm.size(0) - 1;
      for (e_k = 0; e_k <= i6; e_k++) {
        ptsNorm[e_k + (ptsNorm.size(0) * d_k)] =
            pts[(b_acoef * e_k) + (pts.size(0) * varargin_2)] -
            cent[varargin_3];
      }
    }
  }
  c_loop_ub = ptsNorm.size(0);
  b_ptsNorm.set_size(ptsNorm.size(0));
  d_loop_ub = ptsNorm.size(0);
  if ((static_cast<int>(ptsNorm.size(0) < 4)) != 0) {
    for (int i5{0}; i5 < c_loop_ub; i5++) {
      b_ptsNorm[i5] = ptsNorm[i5];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i5 = 0; i5 < d_loop_ub; i5++) {
      b_ptsNorm[i5] = ptsNorm[i5];
    }
  }
  e_loop_ub = ptsNorm.size(0);
  c_ptsNorm.set_size(ptsNorm.size(0));
  f_loop_ub = ptsNorm.size(0);
  if ((static_cast<int>(ptsNorm.size(0) < 4)) != 0) {
    for (int i7{0}; i7 < e_loop_ub; i7++) {
      c_ptsNorm[i7] = ptsNorm[i7 + ptsNorm.size(0)];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i7 = 0; i7 < f_loop_ub; i7++) {
      c_ptsNorm[i7] = ptsNorm[i7 + ptsNorm.size(0)];
    }
  }
  c_hypot(b_ptsNorm, c_ptsNorm, b_a);
  b_x.set_size(b_a.size(0));
  k_N = b_a.size(0);
  if ((static_cast<int>(b_a.size(0) < 4)) != 0) {
    for (int g_k{0}; g_k < k_N; g_k++) {
      b_x[g_k] = rt_powd_snf(b_a[g_k], 2.0);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int g_k = 0; g_k < k_N; g_k++) {
      b_x[g_k] = rt_powd_snf(b_a[g_k], 2.0);
    }
  }
  sumOfPointDistancesFromOriginSquared = combineVectorElements(b_x);
  if (sumOfPointDistancesFromOriginSquared > 0.0) {
    scaleFactor = std::sqrt(2.0 * (static_cast<double>(pts.size(0)))) /
                  std::sqrt(sumOfPointDistancesFromOriginSquared);
  } else {
    scaleFactor = 1.0;
  }
  g_loop_ub = ptsNorm.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i9,        \
                                                                    h_loop_ub)

  for (int b_i8 = 0; b_i8 < g_loop_ub; b_i8++) {
    h_loop_ub = ptsNorm.size(0);
    for (i9 = 0; i9 < h_loop_ub; i9++) {
      ptsNorm[i9 + (ptsNorm.size(0) * b_i8)] =
          ptsNorm[i9 + (ptsNorm.size(0) * b_i8)] * scaleFactor;
    }
  }
  normMatrixInv[0][0] = 1.0 / scaleFactor;
  normMatrixInv[1][0] = 0.0;
  normMatrixInv[2][0] = 0.0;
  normMatrixInv[0][1] = 0.0;
  normMatrixInv[1][1] = 1.0 / scaleFactor;
  normMatrixInv[2][1] = 0.0;
  normMatrixInv[0][2] = cent[0];
  normMatrixInv[1][2] = cent[1];
  normMatrixInv[2][2] = 1.0;
}

} // namespace internal
} // namespace geotrans
} // namespace images
} // namespace coder

//
// File trailer for normalizeControlPoints.cpp
//
// [EOF]
//
