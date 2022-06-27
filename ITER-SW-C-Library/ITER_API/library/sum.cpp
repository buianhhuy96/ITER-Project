//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sum.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "sum.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &b_x
//                ::coder::array<double, 1U> &y
// Return Type  : void
//
namespace coder {
void sum(const ::coder::array<double, 2U> &b_x, ::coder::array<double, 1U> &y)
{
  if (b_x.size(0) == 0) {
    y.set_size(0);
  } else {
    int b_i;
    int i1;
    y.set_size(b_x.size(0));
    b_i = b_x.size(0);
    if ((static_cast<int>(b_x.size(0) < 4)) != 0) {
      for (int k{0}; k < b_i; k++) {
        y[k] = b_x[k];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int k = 0; k < b_i; k++) {
        y[k] = b_x[k];
      }
    }
    i1 = b_x.size(0);
    for (int b_k{0}; b_k < i1; b_k++) {
      y[b_k] = y[b_k] + b_x[b_k + b_x.size(0)];
    }
  }
}

} // namespace coder

//
// File trailer for sum.cpp
//
// [EOF]
//
