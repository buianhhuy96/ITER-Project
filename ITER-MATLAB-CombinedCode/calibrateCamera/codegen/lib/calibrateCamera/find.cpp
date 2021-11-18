//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: find.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "find.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<boolean_T, 2U> &b_x
//                ::coder::array<int32_T, 2U> &b_i
// Return Type  : void
//
namespace Codegen {
namespace coder {
void b_eml_find(const ::coder::array<boolean_T, 2U> &b_x,
                ::coder::array<int32_T, 2U> &b_i)
{
  int32_T b_ii;
  int32_T idx;
  int32_T nx;
  boolean_T exitg1;
  nx = b_x.size(1);
  idx = 0;
  b_i.set_size(1, b_x.size(1));
  b_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (b_ii <= (nx - 1))) {
    if (b_x[b_ii]) {
      idx++;
      b_i[idx - 1] = b_ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        b_ii++;
      }
    } else {
      b_ii++;
    }
  }
  if (b_x.size(1) == 1) {
    if (idx == 0) {
      b_i.set_size(1, 0);
    }
  } else {
    if (1 > idx) {
      idx = 0;
    }
    b_i.set_size(b_i.size(0), idx);
  }
}

//
// Arguments    : const ::coder::array<real_T, 2U> &b_x
//                ::coder::array<int32_T, 2U> &b_i
// Return Type  : void
//
void c_eml_find(const ::coder::array<real_T, 2U> &b_x,
                ::coder::array<int32_T, 2U> &b_i)
{
  int32_T b_ii;
  int32_T idx;
  int32_T nx;
  boolean_T exitg1;
  nx = b_x.size(1);
  idx = 0;
  b_i.set_size(1, b_x.size(1));
  b_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (b_ii <= (nx - 1))) {
    if (b_x[b_ii] != 0.0) {
      idx++;
      b_i[idx - 1] = b_ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        b_ii++;
      }
    } else {
      b_ii++;
    }
  }
  if (b_x.size(1) == 1) {
    if (idx == 0) {
      b_i.set_size(1, 0);
    }
  } else {
    if (1 > idx) {
      idx = 0;
    }
    b_i.set_size(b_i.size(0), idx);
  }
}

//
// Arguments    : const ::coder::array<real_T, 1U> &b_x
//                ::coder::array<int32_T, 1U> &b_i
// Return Type  : void
//
void eml_find(const ::coder::array<real_T, 1U> &b_x,
              ::coder::array<int32_T, 1U> &b_i)
{
  int32_T b_ii;
  int32_T idx;
  int32_T nx;
  boolean_T exitg1;
  nx = b_x.size(0);
  idx = 0;
  b_i.set_size(b_x.size(0));
  b_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (b_ii <= (nx - 1))) {
    if (b_x[b_ii] != 0.0) {
      idx++;
      b_i[idx - 1] = b_ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        b_ii++;
      }
    } else {
      b_ii++;
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
} // namespace Codegen

//
// File trailer for find.cpp
//
// [EOF]
//
