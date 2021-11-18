//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: find.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 14:44:26
//

// Include Files
#include "find.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &b_x
//                ::coder::array<int, 2U> &b_i
// Return Type  : void
//
namespace coder {
void b_eml_find(const ::coder::array<double, 2U> &b_x,
                ::coder::array<int, 2U> &b_i)
{
  array<int, 2U> c_i;
  int c_ii;
  int idx;
  int nx;
  bool exitg1;
  nx = b_x.size(1);
  idx = 0;
  b_i.set_size(1, b_x.size(1));
  c_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (c_ii <= (nx - 1))) {
    if (b_x[c_ii] != 0.0) {
      idx++;
      b_i[idx - 1] = c_ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        c_ii++;
      }
    } else {
      c_ii++;
    }
  }
  if (b_x.size(1) == 1) {
    if (idx == 0) {
      b_i.set_size(1, 0);
    }
  } else {
    int b_loop_ub;
    int loop_ub;
    if (1 > idx) {
      loop_ub = 0;
    } else {
      loop_ub = idx;
    }
    c_i.set_size(1, loop_ub);
    for (int d_i{0}; d_i < loop_ub; d_i++) {
      c_i[d_i] = b_i[d_i];
    }
    b_i.set_size(1, c_i.size(1));
    b_loop_ub = c_i.size(1);
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      b_i[i1] = c_i[i1];
    }
  }
}

//
// Arguments    : const ::coder::array<double, 1U> &b_x
//                ::coder::array<int, 1U> &b_i
// Return Type  : void
//
void eml_find(const ::coder::array<double, 1U> &b_x,
              ::coder::array<int, 1U> &b_i)
{
  int c_ii;
  int idx;
  int nx;
  bool exitg1;
  nx = b_x.size(0);
  idx = 0;
  b_i.set_size(b_x.size(0));
  c_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (c_ii <= (nx - 1))) {
    if (b_x[c_ii] != 0.0) {
      idx++;
      b_i[idx - 1] = c_ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        c_ii++;
      }
    } else {
      c_ii++;
    }
  }
  if (b_x.size(0) == 1) {
    if (idx == 0) {
      b_i.set_size(0);
    }
  } else {
    int c_i;
    if (1 > idx) {
      c_i = 0;
    } else {
      c_i = idx;
    }
    b_i.set_size(c_i);
  }
}

} // namespace coder

//
// File trailer for find.cpp
//
// [EOF]
//
