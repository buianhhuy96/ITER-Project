//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: costFunc1.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "costFunc1.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : coder::array<double, 2U> &err
//                const coder::array<double, 2U> &undist_imgMarkerPts
//                const coder::array<double, 2U> &b_x
// Return Type  : void
//
void c_binary_expand_op(coder::array<double, 2U> &err,
                        const coder::array<double, 2U> &undist_imgMarkerPts,
                        const coder::array<double, 2U> &b_x)
{
  int b_i;
  int i1;
  int i3;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  b_i = b_x.size(1);
  if (b_i == 1) {
    i1 = undist_imgMarkerPts.size(0);
  } else {
    i1 = b_i;
  }
  err.set_size(i1, 2);
  stride_0_0 = static_cast<int>(undist_imgMarkerPts.size(0) != 1);
  stride_1_0 = static_cast<int>(b_i != 1);
  if (b_i == 1) {
    loop_ub = undist_imgMarkerPts.size(0);
  } else {
    loop_ub = b_i;
  }
  if ((static_cast<int>((loop_ub * 2) < 4)) != 0) {
    for (int i2{0}; i2 < 2; i2++) {
      for (i3 = 0; i3 < loop_ub; i3++) {
        err[i3 + (err.size(0) * i2)] =
            undist_imgMarkerPts[(i3 * stride_0_0) +
                                (undist_imgMarkerPts.size(0) * i2)] -
            b_x[i2 + (3 * (i3 * stride_1_0))];
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3)

    for (int i2 = 0; i2 < 2; i2++) {
      for (i3 = 0; i3 < loop_ub; i3++) {
        err[i3 + (err.size(0) * i2)] =
            undist_imgMarkerPts[(i3 * stride_0_0) +
                                (undist_imgMarkerPts.size(0) * i2)] -
            b_x[i2 + (3 * (i3 * stride_1_0))];
      }
    }
  }
}

//
// File trailer for costFunc1.cpp
//
// [EOF]
//
