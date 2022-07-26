//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: power.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "power.h"
#include "ITER_API_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<int, 1U> &b_a
//                ::coder::array<int, 1U> &y
// Return Type  : void
//
namespace ITER {
namespace coder {
void b_power(const ::coder::array<int, 1U> &b_a, ::coder::array<int, 1U> &y)
{
  unsigned int b_bu;
  int b_y;
  int c_a;
  int exitg1;
  int i_N;
  y.set_size(b_a.size(0));
  i_N = b_a.size(0);
  if ((static_cast<int>((b_a.size(0) * 10) < 4)) != 0) {
    for (int k{0}; k < i_N; k++) {
      c_a = b_a[k];
      b_y = 1;
      b_bu = 2U;
      do {
        exitg1 = 0;
        if ((b_bu & 1U) != 0U) {
          b_y = mul_s32_sat(c_a, b_y);
        }
        b_bu >>= 1U;
        if ((static_cast<int>(b_bu)) == 0) {
          exitg1 = 1;
        } else {
          c_a = mul_s32_sat(c_a, c_a);
        }
      } while (exitg1 == 0);
      y[k] = b_y;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    b_bu, b_y, c_a, exitg1)

    for (int k = 0; k < i_N; k++) {
      c_a = b_a[k];
      b_y = 1;
      b_bu = 2U;
      do {
        exitg1 = 0;
        if ((b_bu & 1U) != 0U) {
          b_y = mul_s32_sat(c_a, b_y);
        }
        b_bu >>= 1U;
        if ((static_cast<int>(b_bu)) == 0) {
          exitg1 = 1;
        } else {
          c_a = mul_s32_sat(c_a, c_a);
        }
      } while (exitg1 == 0);
      y[k] = b_y;
    }
  }
}

//
// Arguments    : const ::coder::array<double, 1U> &b_a
//                ::coder::array<double, 1U> &y
// Return Type  : void
//
void power(const ::coder::array<double, 1U> &b_a, ::coder::array<double, 1U> &y)
{
  int i_N;
  y.set_size(b_a.size(0));
  i_N = b_a.size(0);
  if ((static_cast<int>(b_a.size(0) < 4)) != 0) {
    for (int k{0}; k < i_N; k++) {
      y[k] = rt_powd_snf(b_a[k], 2.0);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int k = 0; k < i_N; k++) {
      y[k] = rt_powd_snf(b_a[k], 2.0);
    }
  }
}

} // namespace coder
} // namespace ITER

//
// File trailer for power.cpp
//
// [EOF]
//
