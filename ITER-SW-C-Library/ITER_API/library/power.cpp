//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: power.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "power.h"
#include "ITER_API_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &b_a
//                ::coder::array<double, 1U> &y
// Return Type  : void
//
namespace coder {
void power(const ::coder::array<double, 1U> &b_a, ::coder::array<double, 1U> &y)
{
  int k_N;
  y.set_size(b_a.size(0));
  k_N = b_a.size(0);
  if ((static_cast<int>(b_a.size(0) < 4)) != 0) {
    for (int k{0}; k < k_N; k++) {
      y[k] = rt_powd_snf(b_a[k], 2.0);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int k = 0; k < k_N; k++) {
      y[k] = rt_powd_snf(b_a[k], 2.0);
    }
  }
}

} // namespace coder

//
// File trailer for power.cpp
//
// [EOF]
//
