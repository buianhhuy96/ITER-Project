//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: nullAssignment.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 18-Jul-2022 16:59:00
//

// Include Files
#include "nullAssignment.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : ::coder::array<double, 2U> &b_x
//                const ::coder::array<int, 1U> &idx
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace internal {
void nullAssignment(::coder::array<double, 2U> &b_x,
                    const ::coder::array<int, 1U> &idx)
{
  ::coder::array<double, 2U> e_x;
  ::coder::array<bool, 2U> b;
  int b_loop_ub;
  int c_loop_ub;
  int d_loop_ub;
  int h_n;
  int i1;
  int i2;
  int k0;
  int loop_ub;
  int nxin;
  int nxout;
  int unnamed_idx_1;
  nxin = b_x.size(1);
  unnamed_idx_1 = b_x.size(1);
  b.set_size(1, unnamed_idx_1);
  loop_ub = unnamed_idx_1;
  if ((static_cast<int>(unnamed_idx_1 < 4)) != 0) {
    for (int b_i{0}; b_i < unnamed_idx_1; b_i++) {
      b[b_i] = false;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i = 0; b_i < loop_ub; b_i++) {
      b[b_i] = false;
    }
  }
  i1 = idx.size(0);
  for (int k{0}; k < i1; k++) {
    b[idx[k] - 1] = true;
  }
  h_n = 0;
  i2 = b.size(1);
  for (int b_k{0}; b_k < i2; b_k++) {
    h_n += static_cast<int>(b[b_k]);
  }
  nxout = b_x.size(1) - h_n;
  k0 = -1;
  for (int c_k{0}; c_k < nxin; c_k++) {
    bool guard1{false};
    guard1 = false;
    if ((c_k + 1) > b.size(1)) {
      guard1 = true;
    } else if (!b[c_k]) {
      guard1 = true;
    } else {
      /* no actions */
    }
    if (guard1) {
      k0++;
      b_x[k0] = b_x[c_k];
    }
  }
  if (1 > nxout) {
    b_loop_ub = 0;
  } else {
    b_loop_ub = nxout;
  }
  e_x.set_size(1, b_loop_ub);
  c_loop_ub = b_loop_ub;
  if ((static_cast<int>(b_loop_ub < 4)) != 0) {
    for (int i3{0}; i3 < b_loop_ub; i3++) {
      e_x[i3] = b_x[i3];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i3 = 0; i3 < c_loop_ub; i3++) {
      e_x[i3] = b_x[i3];
    }
  }
  b_x.set_size(1, e_x.size(1));
  d_loop_ub = e_x.size(1);
  if ((static_cast<int>(e_x.size(1) < 4)) != 0) {
    for (int i4{0}; i4 < d_loop_ub; i4++) {
      b_x[i4] = e_x[i4];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i4 = 0; i4 < d_loop_ub; i4++) {
      b_x[i4] = e_x[i4];
    }
  }
}

} // namespace internal
} // namespace coder
} // namespace ITER

//
// File trailer for nullAssignment.cpp
//
// [EOF]
//
