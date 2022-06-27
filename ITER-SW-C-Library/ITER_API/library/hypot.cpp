//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: hypot.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "hypot.h"
#include "ITER_API_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<float, 1U> &b_x
//                const ::coder::array<float, 1U> &y
//                ::coder::array<float, 1U> &r
// Return Type  : void
//
namespace coder {
void b_hypot(const ::coder::array<float, 1U> &b_x,
             const ::coder::array<float, 1U> &y, ::coder::array<float, 1U> &r)
{
  int b_u0;
  int b_u1;
  int b_y;
  int c_u1;
  int csz_idx_0;
  int k_N;
  int u0;
  u0 = b_x.size(0);
  b_u1 = y.size(0);
  if (u0 <= b_u1) {
    csz_idx_0 = u0;
  } else {
    csz_idx_0 = b_u1;
  }
  r.set_size(csz_idx_0);
  k_N = csz_idx_0;
  b_u0 = b_x.size(0);
  c_u1 = y.size(0);
  if (b_u0 <= c_u1) {
    b_y = b_u0;
  } else {
    b_y = c_u1;
  }
  if ((static_cast<int>(b_y < 4)) != 0) {
    for (int k{0}; k < csz_idx_0; k++) {
      r[k] = rt_hypotf_snf(b_x[k], y[k]);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int k = 0; k < k_N; k++) {
      r[k] = rt_hypotf_snf(b_x[k], y[k]);
    }
  }
}

//
// Arguments    : const ::coder::array<double, 1U> &b_x
//                const ::coder::array<double, 1U> &y
//                ::coder::array<double, 1U> &r
// Return Type  : void
//
void c_hypot(const ::coder::array<double, 1U> &b_x,
             const ::coder::array<double, 1U> &y, ::coder::array<double, 1U> &r)
{
  int b_u0;
  int b_u1;
  int b_y;
  int c_u1;
  int csz_idx_0;
  int k_N;
  int u0;
  u0 = b_x.size(0);
  b_u1 = y.size(0);
  if (u0 <= b_u1) {
    csz_idx_0 = u0;
  } else {
    csz_idx_0 = b_u1;
  }
  r.set_size(csz_idx_0);
  k_N = csz_idx_0;
  b_u0 = b_x.size(0);
  c_u1 = y.size(0);
  if (b_u0 <= c_u1) {
    b_y = b_u0;
  } else {
    b_y = c_u1;
  }
  if ((static_cast<int>(b_y < 4)) != 0) {
    for (int k{0}; k < csz_idx_0; k++) {
      r[k] = rt_hypotd_snf(b_x[k], y[k]);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int k = 0; k < k_N; k++) {
      r[k] = rt_hypotd_snf(b_x[k], y[k]);
    }
  }
}

} // namespace coder

//
// File trailer for hypot.cpp
//
// [EOF]
//
