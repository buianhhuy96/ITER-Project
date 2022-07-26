//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: find.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "find.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<bool, 1U> &b_x
//                ::coder::array<int, 1U> &b_i
// Return Type  : void
//
namespace ITER {
namespace coder {
void b_eml_find(const ::coder::array<bool, 1U> &b_x,
                ::coder::array<int, 1U> &b_i)
{
  int b_nx;
  int c_ii;
  int idx;
  bool exitg1;
  b_nx = b_x.size(0);
  idx = 0;
  b_i.set_size(b_x.size(0));
  c_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (c_ii <= (b_nx - 1))) {
    if (b_x[c_ii]) {
      idx++;
      b_i[idx - 1] = c_ii + 1;
      if (idx >= b_nx) {
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

//
// Arguments    : const ::coder::array<double, 2U> &b_x
//                ::coder::array<int, 2U> &b_i
// Return Type  : void
//
void c_eml_find(const ::coder::array<double, 2U> &b_x,
                ::coder::array<int, 2U> &b_i)
{
  ::coder::array<int, 2U> c_i;
  int b_nx;
  int c_ii;
  int idx;
  bool exitg1;
  b_nx = b_x.size(1);
  idx = 0;
  b_i.set_size(1, b_x.size(1));
  c_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (c_ii <= (b_nx - 1))) {
    if (b_x[c_ii] != 0.0) {
      idx++;
      b_i[idx - 1] = c_ii + 1;
      if (idx >= b_nx) {
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
    int c_loop_ub;
    int loop_ub;
    if (1 > idx) {
      loop_ub = 0;
    } else {
      loop_ub = idx;
    }
    c_i.set_size(1, loop_ub);
    b_loop_ub = loop_ub;
    if ((static_cast<int>(loop_ub < 4)) != 0) {
      for (int d_i{0}; d_i < loop_ub; d_i++) {
        c_i[d_i] = b_i[d_i];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int d_i = 0; d_i < b_loop_ub; d_i++) {
        c_i[d_i] = b_i[d_i];
      }
    }
    b_i.set_size(1, c_i.size(1));
    c_loop_ub = c_i.size(1);
    if ((static_cast<int>(c_i.size(1) < 4)) != 0) {
      for (int i1{0}; i1 < c_loop_ub; i1++) {
        b_i[i1] = c_i[i1];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i1 = 0; i1 < c_loop_ub; i1++) {
        b_i[i1] = c_i[i1];
      }
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
  int b_nx;
  int c_ii;
  int idx;
  bool exitg1;
  b_nx = b_x.size(0);
  idx = 0;
  b_i.set_size(b_x.size(0));
  c_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (c_ii <= (b_nx - 1))) {
    if (b_x[c_ii] != 0.0) {
      idx++;
      b_i[idx - 1] = c_ii + 1;
      if (idx >= b_nx) {
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
} // namespace ITER

//
// File trailer for find.cpp
//
// [EOF]
//
