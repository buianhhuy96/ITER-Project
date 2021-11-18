//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: cat.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 14:44:26
//

// Include Files
#include "cat.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &varargin_1
//                const ::coder::array<double, 2U> &varargin_2
//                ::coder::array<double, 3U> &y
// Return Type  : void
//
namespace coder {
void cat(const ::coder::array<double, 2U> &varargin_1,
         const ::coder::array<double, 2U> &varargin_2,
         ::coder::array<double, 3U> &y)
{
  array<double, 2U> b_f1;
  array<double, 2U> f1;
  int c_loop_ub;
  int i3;
  int i5;
  int loop_ub;
  int subsarg_idx_1;
  y.set_size(varargin_1.size(0), varargin_1.size(1), 2);
  f1.set_size(varargin_1.size(0), varargin_1.size(1));
  loop_ub = varargin_1.size(1);
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    int b_loop_ub;
    b_loop_ub = varargin_1.size(0);
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      f1[i1 + (f1.size(0) * b_i)] = varargin_1[i1 + (varargin_1.size(0) * b_i)];
    }
  }
  b_f1.set_size(varargin_2.size(0), varargin_2.size(1));
  c_loop_ub = varargin_2.size(1);
  for (int i2{0}; i2 < c_loop_ub; i2++) {
    int d_loop_ub;
    d_loop_ub = varargin_2.size(0);
    for (int i4{0}; i4 < d_loop_ub; i4++) {
      b_f1[i4 + (b_f1.size(0) * i2)] =
          varargin_2[i4 + (varargin_2.size(0) * i2)];
    }
  }
  i3 = varargin_1.size(1);
  for (int k{0}; k < i3; k++) {
    int i6;
    i6 = y.size(0);
    if (0 <= (y.size(0) - 1)) {
      subsarg_idx_1 = k + 1;
    }
    for (int c_k{0}; c_k < i6; c_k++) {
      y[c_k + (y.size(0) * k)] = f1[c_k + (f1.size(0) * (subsarg_idx_1 - 1))];
    }
  }
  i5 = y.size(1);
  for (int b_k{0}; b_k < i5; b_k++) {
    int i7;
    i7 = y.size(0);
    if (0 <= (y.size(0) - 1)) {
      subsarg_idx_1 = b_k + 1;
    }
    for (int d_k{0}; d_k < i7; d_k++) {
      y[(d_k + (y.size(0) * b_k)) + (y.size(0) * y.size(1))] =
          b_f1[d_k + (b_f1.size(0) * (subsarg_idx_1 - 1))];
    }
  }
}

} // namespace coder

//
// File trailer for cat.cpp
//
// [EOF]
//
