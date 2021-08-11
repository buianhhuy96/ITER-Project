//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: cat.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
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
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  int ysize_idx_1;
  ysize_idx_1 = varargin_1.size(1);
  y.set_size(varargin_1.size(0), varargin_1.size(1), 2);
  f1.set_size(varargin_1.size(0), varargin_1.size(1));
  loop_ub = varargin_1.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = varargin_1.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      f1[i1 + (f1.size(0) * i)] = varargin_1[i1 + (varargin_1.size(0) * i)];
    }
  }
  b_f1.set_size(varargin_2.size(0), varargin_2.size(1));
  loop_ub = varargin_2.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = varargin_2.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_f1[i1 + (b_f1.size(0) * i)] = varargin_2[i1 + (varargin_2.size(0) * i)];
    }
  }
  i = varargin_1.size(1);
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    i1 = y.size(0);
    if (0 <= (y.size(0) - 1)) {
      ysize_idx_1 = loop_ub + 1;
    }
    for (b_loop_ub = 0; b_loop_ub < i1; b_loop_ub++) {
      y[b_loop_ub + (y.size(0) * loop_ub)] =
          f1[b_loop_ub + (f1.size(0) * (ysize_idx_1 - 1))];
    }
  }
  i = y.size(1);
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    i1 = y.size(0);
    if (0 <= (y.size(0) - 1)) {
      ysize_idx_1 = loop_ub + 1;
    }
    for (b_loop_ub = 0; b_loop_ub < i1; b_loop_ub++) {
      y[(b_loop_ub + (y.size(0) * loop_ub)) + (y.size(0) * y.size(1))] =
          b_f1[b_loop_ub + (b_f1.size(0) * (ysize_idx_1 - 1))];
    }
  }
}

} // namespace coder

//
// File trailer for cat.cpp
//
// [EOF]
//
