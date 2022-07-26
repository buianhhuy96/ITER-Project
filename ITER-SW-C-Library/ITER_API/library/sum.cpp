//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sum.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "sum.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const double b_x[3][4]
//                double y[4]
// Return Type  : void
//
namespace ITER {
namespace coder {
void b_sum(const double b_x[3][4], double y[4])
{
  for (int k{0}; k < 4; k++) {
    y[k] = b_x[0][k];
  }
  for (int b_k{0}; b_k < 2; b_k++) {
    for (int c_k{0}; c_k < 4; c_k++) {
      y[c_k] += b_x[b_k + 1][c_k];
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &b_x
//                ::coder::array<double, 1U> &y
// Return Type  : void
//
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
} // namespace ITER

//
// File trailer for sum.cpp
//
// [EOF]
//
