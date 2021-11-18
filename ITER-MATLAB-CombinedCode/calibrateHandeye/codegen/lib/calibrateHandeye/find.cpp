//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: find.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
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
    if (1 > idx) {
      nx = 0;
    } else {
      nx = idx;
    }
    c_i.set_size(1, nx);
    for (idx = 0; idx < nx; idx++) {
      c_i[idx] = b_i[idx];
    }
    b_i.set_size(1, c_i.size(1));
    nx = c_i.size(1);
    for (idx = 0; idx < nx; idx++) {
      b_i[idx] = c_i[idx];
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
    if (1 > idx) {
      idx = 0;
    }
    b_i.set_size(idx);
  }
}

} // namespace coder

//
// File trailer for find.cpp
//
// [EOF]
//
