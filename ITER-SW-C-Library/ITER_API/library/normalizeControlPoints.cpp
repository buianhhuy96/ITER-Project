//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: normalizeControlPoints.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "normalizeControlPoints.h"
#include "ITER_API_rtwutil.h"
#include "combineVectorElements.h"
#include "hypot.h"
#include "mean.h"
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
namespace ITER {
namespace coder {
namespace images {
namespace geotrans {
namespace internal {
void b_normalizeControlPoints(const ::coder::array<double, 2U> &pts,
                              ::coder::array<double, 2U> &ptsNorm,
                              double normMatrixInv[3][3])
{
  ::coder::array<double, 1U> b_a;
  ::coder::array<double, 1U> b_ptsNorm;
  ::coder::array<double, 1U> b_x;
  ::coder::array<double, 1U> c_ptsNorm;
  double cent[2];
  double scaleFactor;
  double sumOfPointDistancesFromOriginSquared;
  int b_k;
  int b_loop_ub;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int i1;
  int i4;
  int i_N;
  int loop_ub;
  c_mean(pts, cent);
  ptsNorm.set_size(pts.size(0), 2);
  if (pts.size(0) != 0) {
    int acoef;
    acoef = static_cast<int>(pts.size(0) != 1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_k, i1)

    for (int k = 0; k < 2; k++) {
      i1 = ptsNorm.size(0) - 1;
      for (b_k = 0; b_k <= i1; b_k++) {
        ptsNorm[b_k + (ptsNorm.size(0) * k)] =
            pts[(acoef * b_k) + (pts.size(0) * k)] - cent[k];
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
  i_N = b_a.size(0);
  if ((static_cast<int>(b_a.size(0) < 4)) != 0) {
    for (int c_k{0}; c_k < i_N; c_k++) {
      b_x[c_k] = rt_powd_snf(b_a[c_k], 2.0);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int c_k = 0; c_k < i_N; c_k++) {
      b_x[c_k] = rt_powd_snf(b_a[c_k], 2.0);
    }
  }
  sumOfPointDistancesFromOriginSquared = b_combineVectorElements(b_x);
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
  ::coder::array<double, 2U> cent;
  ::coder::array<double, 1U> b_a;
  ::coder::array<double, 1U> b_ptsNorm;
  ::coder::array<double, 1U> b_x;
  ::coder::array<double, 1U> c_ptsNorm;
  double scaleFactor;
  double sumOfPointDistancesFromOriginSquared;
  int b_acoef;
  int b_i;
  int b_k;
  int b_loop_ub;
  int b_u0;
  int b_u1;
  int b_y;
  int c_loop_ub;
  int c_u1;
  int csz_idx_1;
  int d_loop_ub;
  int e_loop_ub;
  int f_loop_ub;
  int i3;
  int i6;
  int i_N;
  int loop_ub;
  int u0;
  int varargin_2;
  int varargin_3;
  int y;
  b_mean(pts, cent);
  u0 = cent.size(1);
  b_u1 = pts.size(1);
  if (u0 <= b_u1) {
    y = u0;
  } else {
    y = b_u1;
  }
  if (cent.size(1) == 1) {
    csz_idx_1 = pts.size(1);
  } else if (pts.size(1) == 1) {
    csz_idx_1 = cent.size(1);
  } else if (pts.size(1) == cent.size(1)) {
    csz_idx_1 = pts.size(1);
  } else {
    csz_idx_1 = y;
  }
  b_u0 = cent.size(1);
  c_u1 = pts.size(1);
  if (b_u0 <= c_u1) {
    b_y = b_u0;
  } else {
    b_y = c_u1;
  }
  if (cent.size(1) == 1) {
    b_i = pts.size(1);
  } else if (pts.size(1) == 1) {
    b_i = cent.size(1);
  } else if (pts.size(1) == cent.size(1)) {
    b_i = pts.size(1);
  } else {
    b_i = b_y;
  }
  ptsNorm.set_size(pts.size(0), b_i);
  if ((pts.size(0) != 0) && (csz_idx_1 != 0)) {
    int acoef;
    int bcoef;
    int i1;
    acoef = static_cast<int>(pts.size(1) != 1);
    bcoef = static_cast<int>(cent.size(1) != 1);
    i1 = csz_idx_1 - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    b_k, i3, b_acoef, varargin_3, varargin_2)

    for (int k = 0; k <= i1; k++) {
      varargin_2 = acoef * k;
      varargin_3 = bcoef * k;
      b_acoef = static_cast<int>(pts.size(0) != 1);
      i3 = ptsNorm.size(0) - 1;
      for (b_k = 0; b_k <= i3; b_k++) {
        ptsNorm[b_k + (ptsNorm.size(0) * k)] =
            pts[(b_acoef * b_k) + (pts.size(0) * varargin_2)] -
            cent[varargin_3];
      }
    }
  }
  loop_ub = ptsNorm.size(0);
  b_ptsNorm.set_size(ptsNorm.size(0));
  b_loop_ub = ptsNorm.size(0);
  if ((static_cast<int>(ptsNorm.size(0) < 4)) != 0) {
    for (int i2{0}; i2 < loop_ub; i2++) {
      b_ptsNorm[i2] = ptsNorm[i2];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i2 = 0; i2 < b_loop_ub; i2++) {
      b_ptsNorm[i2] = ptsNorm[i2];
    }
  }
  c_loop_ub = ptsNorm.size(0);
  c_ptsNorm.set_size(ptsNorm.size(0));
  d_loop_ub = ptsNorm.size(0);
  if ((static_cast<int>(ptsNorm.size(0) < 4)) != 0) {
    for (int i4{0}; i4 < c_loop_ub; i4++) {
      c_ptsNorm[i4] = ptsNorm[i4 + ptsNorm.size(0)];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i4 = 0; i4 < d_loop_ub; i4++) {
      c_ptsNorm[i4] = ptsNorm[i4 + ptsNorm.size(0)];
    }
  }
  c_hypot(b_ptsNorm, c_ptsNorm, b_a);
  b_x.set_size(b_a.size(0));
  i_N = b_a.size(0);
  if ((static_cast<int>(b_a.size(0) < 4)) != 0) {
    for (int c_k{0}; c_k < i_N; c_k++) {
      b_x[c_k] = rt_powd_snf(b_a[c_k], 2.0);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int c_k = 0; c_k < i_N; c_k++) {
      b_x[c_k] = rt_powd_snf(b_a[c_k], 2.0);
    }
  }
  sumOfPointDistancesFromOriginSquared = b_combineVectorElements(b_x);
  if (sumOfPointDistancesFromOriginSquared > 0.0) {
    scaleFactor = std::sqrt(2.0 * (static_cast<double>(pts.size(0)))) /
                  std::sqrt(sumOfPointDistancesFromOriginSquared);
  } else {
    scaleFactor = 1.0;
  }
  e_loop_ub = ptsNorm.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i6,        \
                                                                    f_loop_ub)

  for (int i5 = 0; i5 < e_loop_ub; i5++) {
    f_loop_ub = ptsNorm.size(0);
    for (i6 = 0; i6 < f_loop_ub; i6++) {
      ptsNorm[i6 + (ptsNorm.size(0) * i5)] =
          ptsNorm[i6 + (ptsNorm.size(0) * i5)] * scaleFactor;
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
} // namespace ITER

//
// File trailer for normalizeControlPoints.cpp
//
// [EOF]
//
