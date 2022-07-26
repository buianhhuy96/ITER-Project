//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: unsafeSxfun.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "unsafeSxfun.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : ::coder::array<double, 2U> &r
//                const ::coder::array<double, 3U> &imgPts
//                int j
//                const ::coder::array<double, 2U> &b_x
// Return Type  : void
//
namespace ITER {
void b_binary_expand_op(::coder::array<double, 2U> &r,
                        const ::coder::array<double, 3U> &imgPts, int j,
                        const ::coder::array<double, 2U> &b_x)
{
  ::coder::array<double, 2U> b_imgPts;
  double b_varargin_1;
  int b_i;
  int b_loop_ub;
  int i1;
  int i2;
  int i4;
  int i6;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  b_i = imgPts.size(0);
  i1 = b_x.size(1);
  if (i1 == 1) {
    i2 = b_i;
  } else {
    i2 = i1;
  }
  b_imgPts.set_size(i2, 2);
  stride_0_0 = static_cast<int>(b_i != 1);
  stride_1_0 = static_cast<int>(i1 != 1);
  if (i1 == 1) {
    loop_ub = b_i;
  } else {
    loop_ub = i1;
  }
  if ((static_cast<int>((loop_ub * 2) < 4)) != 0) {
    for (int i3{0}; i3 < 2; i3++) {
      for (i4 = 0; i4 < loop_ub; i4++) {
        b_imgPts[i4 + (b_imgPts.size(0) * i3)] =
            imgPts[((i4 * stride_0_0) + (imgPts.size(0) * i3)) +
                   ((imgPts.size(0) * 2) * j)] -
            b_x[i3 + (3 * (i4 * stride_1_0))];
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i4)

    for (int i3 = 0; i3 < 2; i3++) {
      for (i4 = 0; i4 < loop_ub; i4++) {
        b_imgPts[i4 + (b_imgPts.size(0) * i3)] =
            imgPts[((i4 * stride_0_0) + (imgPts.size(0) * i3)) +
                   ((imgPts.size(0) * 2) * j)] -
            b_x[i3 + (3 * (i4 * stride_1_0))];
      }
    }
  }
  r.set_size(b_imgPts.size(0), 2);
  b_loop_ub = b_imgPts.size(0);
  if ((static_cast<int>((b_imgPts.size(0) * 2) < 4)) != 0) {
    for (int i5{0}; i5 < 2; i5++) {
      for (i6 = 0; i6 < b_loop_ub; i6++) {
        double varargin_1;
        varargin_1 = b_imgPts[i6 + (b_imgPts.size(0) * i5)];
        r[i6 + (r.size(0) * i5)] = varargin_1 * varargin_1;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i6, b_varargin_1)

    for (int i5 = 0; i5 < 2; i5++) {
      for (i6 = 0; i6 < b_loop_ub; i6++) {
        b_varargin_1 = b_imgPts[i6 + (b_imgPts.size(0) * i5)];
        r[i6 + (r.size(0) * i5)] = b_varargin_1 * b_varargin_1;
      }
    }
  }
}

//
// Arguments    : ::coder::array<double, 2U> &r
//                const ::coder::array<double, 2U> &distortedNormalizedPoints
//                const double f_K[3][3]
//                const ::coder::array<double, 3U> &e_ImagePoints
//                int h_n
// Return Type  : void
//
void binary_expand_op(
    ::coder::array<double, 2U> &r,
    const ::coder::array<double, 2U> &distortedNormalizedPoints,
    const double f_K[3][3], const ::coder::array<double, 3U> &e_ImagePoints,
    int h_n)
{
  ::coder::array<double, 2U> b_distortedNormalizedPoints;
  ::coder::array<double, 2U> c_distortedNormalizedPoints;
  double ab_K;
  double b_varargin_1;
  double bb_K;
  double cb_K;
  double db_K;
  double y_K;
  int aux_1_1;
  int b_loop_ub;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int f_loop_ub;
  int g_loop_ub;
  int i2;
  int i3;
  int i7;
  int i9;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_1_1;
  y_K = f_K[0][0];
  ab_K = f_K[0][2];
  bb_K = f_K[0][1];
  cb_K = f_K[1][1];
  db_K = f_K[1][2];
  loop_ub = distortedNormalizedPoints.size(0);
  b_loop_ub = distortedNormalizedPoints.size(0);
  b_distortedNormalizedPoints.set_size(loop_ub, 2);
  c_loop_ub = loop_ub;
  if ((static_cast<int>(loop_ub < 4)) != 0) {
    for (int b_i{0}; b_i < loop_ub; b_i++) {
      b_distortedNormalizedPoints[b_i] =
          ((distortedNormalizedPoints[b_i] * y_K) + ab_K) +
          (bb_K *
           distortedNormalizedPoints[b_i + distortedNormalizedPoints.size(0)]);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i = 0; b_i < c_loop_ub; b_i++) {
      b_distortedNormalizedPoints[b_i] =
          ((distortedNormalizedPoints[b_i] * y_K) + ab_K) +
          (bb_K *
           distortedNormalizedPoints[b_i + distortedNormalizedPoints.size(0)]);
    }
  }
  d_loop_ub = b_loop_ub;
  if ((static_cast<int>(b_loop_ub < 4)) != 0) {
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      b_distortedNormalizedPoints[i1 + b_distortedNormalizedPoints.size(0)] =
          (distortedNormalizedPoints[i1 + distortedNormalizedPoints.size(0)] *
           cb_K) +
          db_K;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i1 = 0; i1 < d_loop_ub; i1++) {
      b_distortedNormalizedPoints[i1 + b_distortedNormalizedPoints.size(0)] =
          (distortedNormalizedPoints[i1 + distortedNormalizedPoints.size(0)] *
           cb_K) +
          db_K;
    }
  }
  i2 = e_ImagePoints.size(0);
  if (i2 == 1) {
    i3 = b_distortedNormalizedPoints.size(0);
  } else {
    i3 = i2;
  }
  c_distortedNormalizedPoints.set_size(i3, 2);
  stride_0_0 = static_cast<int>(b_distortedNormalizedPoints.size(0) != 1);
  stride_1_0 = static_cast<int>(i2 != 1);
  stride_1_1 = static_cast<int>(e_ImagePoints.size(1) != 1);
  aux_1_1 = 0;
  if (i2 == 1) {
    e_loop_ub = b_distortedNormalizedPoints.size(0);
  } else {
    e_loop_ub = i2;
  }
  for (int i4{0}; i4 < 2; i4++) {
    for (int i5{0}; i5 < e_loop_ub; i5++) {
      c_distortedNormalizedPoints[i5 +
                                  (c_distortedNormalizedPoints.size(0) * i4)] =
          b_distortedNormalizedPoints[(i5 * stride_0_0) +
                                      (b_distortedNormalizedPoints.size(0) *
                                       i4)] -
          e_ImagePoints
              [((i5 * stride_1_0) + (e_ImagePoints.size(0) * aux_1_1)) +
               ((e_ImagePoints.size(0) * e_ImagePoints.size(1)) * h_n)];
    }
    aux_1_1 += stride_1_1;
  }
  b_distortedNormalizedPoints.set_size(c_distortedNormalizedPoints.size(0), 2);
  f_loop_ub = c_distortedNormalizedPoints.size(0);
  if ((static_cast<int>((c_distortedNormalizedPoints.size(0) * 2) < 4)) != 0) {
    for (int i6{0}; i6 < 2; i6++) {
      for (i7 = 0; i7 < f_loop_ub; i7++) {
        b_distortedNormalizedPoints[i7 + (b_distortedNormalizedPoints.size(0) *
                                          i6)] = c_distortedNormalizedPoints
            [i7 + (c_distortedNormalizedPoints.size(0) * i6)];
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i7)

    for (int i6 = 0; i6 < 2; i6++) {
      for (i7 = 0; i7 < f_loop_ub; i7++) {
        b_distortedNormalizedPoints[i7 + (b_distortedNormalizedPoints.size(0) *
                                          i6)] = c_distortedNormalizedPoints
            [i7 + (c_distortedNormalizedPoints.size(0) * i6)];
      }
    }
  }
  r.set_size(b_distortedNormalizedPoints.size(0), 2);
  g_loop_ub = b_distortedNormalizedPoints.size(0);
  if ((static_cast<int>((b_distortedNormalizedPoints.size(0) * 2) < 4)) != 0) {
    for (int b_i8{0}; b_i8 < 2; b_i8++) {
      for (i9 = 0; i9 < g_loop_ub; i9++) {
        double varargin_1;
        varargin_1 = b_distortedNormalizedPoints
            [i9 + (b_distortedNormalizedPoints.size(0) * b_i8)];
        r[i9 + (r.size(0) * b_i8)] = varargin_1 * varargin_1;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i9, b_varargin_1)

    for (int b_i8 = 0; b_i8 < 2; b_i8++) {
      for (i9 = 0; i9 < g_loop_ub; i9++) {
        b_varargin_1 = b_distortedNormalizedPoints
            [i9 + (b_distortedNormalizedPoints.size(0) * b_i8)];
        r[i9 + (r.size(0) * b_i8)] = b_varargin_1 * b_varargin_1;
      }
    }
  }
}

} // namespace ITER

//
// File trailer for unsafeSxfun.cpp
//
// [EOF]
//
