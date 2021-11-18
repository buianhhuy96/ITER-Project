//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: unsafeSxfun.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

// Include Files
#include "unsafeSxfun.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : coder::array<double, 2U> &r
//                const coder::array<double, 3U> &imgPts
//                int j
//                const coder::array<double, 2U> &b_x
// Return Type  : void
//
void b_binary_expand_op(coder::array<double, 2U> &r,
                        const coder::array<double, 3U> &imgPts, int j,
                        const coder::array<double, 2U> &b_x)
{
  coder::array<double, 2U> b_imgPts;
  int b_i;
  int b_loop_ub;
  int i1;
  int i2;
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
  for (int i3{0}; i3 < 2; i3++) {
    for (int i4{0}; i4 < loop_ub; i4++) {
      b_imgPts[i4 + (b_imgPts.size(0) * i3)] =
          imgPts[((i4 * stride_0_0) + (imgPts.size(0) * i3)) +
                 ((imgPts.size(0) * 2) * j)] -
          b_x[i3 + (3 * (i4 * stride_1_0))];
    }
  }
  r.set_size(b_imgPts.size(0), 2);
  b_loop_ub = b_imgPts.size(0);
  for (int i5{0}; i5 < 2; i5++) {
    for (int i6{0}; i6 < b_loop_ub; i6++) {
      double varargin_1;
      varargin_1 = b_imgPts[i6 + (b_imgPts.size(0) * i5)];
      r[i6 + (r.size(0) * i5)] = varargin_1 * varargin_1;
    }
  }
}

//
// Arguments    : coder::array<double, 2U> &r
//                const coder::array<double, 2U> &projectedPoints
//                const coder::array<double, 3U> &e_ImagePoints
//                int h_n
// Return Type  : void
//
void binary_expand_op(coder::array<double, 2U> &r,
                      const coder::array<double, 2U> &projectedPoints,
                      const coder::array<double, 3U> &e_ImagePoints, int h_n)
{
  coder::array<double, 2U> b_projectedPoints;
  int aux_1_1;
  int b_i;
  int b_loop_ub;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_1_1;
  b_i = e_ImagePoints.size(0);
  if (b_i == 1) {
    i1 = projectedPoints.size(0);
  } else {
    i1 = b_i;
  }
  b_projectedPoints.set_size(i1, 2);
  stride_0_0 = static_cast<int>(projectedPoints.size(0) != 1);
  stride_1_0 = static_cast<int>(b_i != 1);
  stride_1_1 = static_cast<int>(e_ImagePoints.size(1) != 1);
  aux_1_1 = 0;
  if (b_i == 1) {
    loop_ub = projectedPoints.size(0);
  } else {
    loop_ub = b_i;
  }
  for (int i2{0}; i2 < 2; i2++) {
    for (int i3{0}; i3 < loop_ub; i3++) {
      b_projectedPoints[i3 + (b_projectedPoints.size(0) * i2)] =
          projectedPoints[(i3 * stride_0_0) + (projectedPoints.size(0) * i2)] -
          e_ImagePoints
              [((i3 * stride_1_0) + (e_ImagePoints.size(0) * aux_1_1)) +
               ((e_ImagePoints.size(0) * e_ImagePoints.size(1)) * h_n)];
    }
    aux_1_1 += stride_1_1;
  }
  r.set_size(b_projectedPoints.size(0), 2);
  b_loop_ub = b_projectedPoints.size(0);
  for (int i4{0}; i4 < 2; i4++) {
    for (int i5{0}; i5 < b_loop_ub; i5++) {
      double varargin_1;
      varargin_1 = b_projectedPoints[i5 + (b_projectedPoints.size(0) * i4)];
      r[i5 + (r.size(0) * i4)] = varargin_1 * varargin_1;
    }
  }
}

//
// File trailer for unsafeSxfun.cpp
//
// [EOF]
//
