//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: unsafeSxfun.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
//

// Include Files
#include "unsafeSxfun.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : coder::array<double, 2U> &y
//                const coder::array<double, 3U> &imgPts
//                int j
//                const coder::array<double, 2U> &b_x
// Return Type  : void
//
void binary_expand_op(coder::array<double, 2U> &y,
                      const coder::array<double, 3U> &imgPts, int j,
                      const coder::array<double, 2U> &b_x)
{
  coder::array<double, 2U> b_imgPts;
  int b_i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  b_i = imgPts.size(0);
  i1 = b_x.size(1);
  if (i1 == 1) {
    stride_0_0 = b_i;
  } else {
    stride_0_0 = i1;
  }
  b_imgPts.set_size(stride_0_0, 2);
  stride_0_0 = static_cast<int>(b_i != 1);
  stride_1_0 = static_cast<int>(i1 != 1);
  if (i1 == 1) {
    loop_ub = b_i;
  } else {
    loop_ub = i1;
  }
  for (b_i = 0; b_i < 2; b_i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_imgPts[i1 + (b_imgPts.size(0) * b_i)] =
          imgPts[((i1 * stride_0_0) + (imgPts.size(0) * b_i)) +
                 ((imgPts.size(0) * 2) * j)] -
          b_x[b_i + (3 * (i1 * stride_1_0))];
    }
  }
  y.set_size(b_imgPts.size(0), 2);
  loop_ub = b_imgPts.size(0);
  for (b_i = 0; b_i < 2; b_i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      double varargin_1;
      varargin_1 = b_imgPts[i1 + (b_imgPts.size(0) * b_i)];
      y[i1 + (y.size(0) * b_i)] = varargin_1 * varargin_1;
    }
  }
}

//
// File trailer for unsafeSxfun.cpp
//
// [EOF]
//
