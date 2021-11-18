//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: cat.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "cat.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &varargin_1
//                const double varargin_2[2]
//                ::coder::array<double, 1U> &y
// Return Type  : void
//
namespace Codegen {
namespace coder {
void b_cat(const ::coder::array<double, 1U> &varargin_1,
           const double varargin_2[2], ::coder::array<double, 1U> &y)
{
  int b_i;
  y.set_size(varargin_1.size(0) + 2);
  b_i = varargin_1.size(0);
  for (int j{0}; j < b_i; j++) {
    y[j] = varargin_1[j];
  }
  y[varargin_1.size(0)] = varargin_2[0];
  y[varargin_1.size(0) + 1] = varargin_2[1];
}

//
// Arguments    : const ::coder::array<double, 2U> &varargin_1
//                const ::coder::array<double, 2U> &varargin_2
//                ::coder::array<double, 3U> &y
// Return Type  : void
//
void cat(const ::coder::array<double, 2U> &varargin_1,
         const ::coder::array<double, 2U> &varargin_2,
         ::coder::array<double, 3U> &y)
{
  ::coder::array<double, 2U> c_f1;
  ::coder::array<double, 2U> f1;
  int b_i;
  int b_loop_ub;
  int i1;
  int loop_ub;
  int ysize_idx_1;
  ysize_idx_1 = varargin_1.size(1);
  y.set_size(varargin_1.size(0), varargin_1.size(1), 2);
  f1.set_size(varargin_1.size(0), varargin_1.size(1));
  loop_ub = varargin_1.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = varargin_1.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      f1[i1 + (f1.size(0) * b_i)] = varargin_1[i1 + (varargin_1.size(0) * b_i)];
    }
  }
  c_f1.set_size(varargin_2.size(0), varargin_2.size(1));
  loop_ub = varargin_2.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = varargin_2.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      c_f1[i1 + (c_f1.size(0) * b_i)] =
          varargin_2[i1 + (varargin_2.size(0) * b_i)];
    }
  }
  b_i = varargin_1.size(1);
  for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
    i1 = y.size(0);
    if (0 <= (y.size(0) - 1)) {
      ysize_idx_1 = loop_ub + 1;
    }
    for (b_loop_ub = 0; b_loop_ub < i1; b_loop_ub++) {
      y[b_loop_ub + (y.size(0) * loop_ub)] =
          f1[b_loop_ub + (f1.size(0) * (ysize_idx_1 - 1))];
    }
  }
  b_i = y.size(1);
  for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
    i1 = y.size(0);
    if (0 <= (y.size(0) - 1)) {
      ysize_idx_1 = loop_ub + 1;
    }
    for (b_loop_ub = 0; b_loop_ub < i1; b_loop_ub++) {
      y[(b_loop_ub + (y.size(0) * loop_ub)) + (y.size(0) * y.size(1))] =
          c_f1[b_loop_ub + (c_f1.size(0) * (ysize_idx_1 - 1))];
    }
  }
}

} // namespace coder
} // namespace Codegen

//
// File trailer for cat.cpp
//
// [EOF]
//
