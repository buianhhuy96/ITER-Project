//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sum.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

// Include Files
#include "sum.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &x
//                ::coder::array<double, 1U> &y
// Return Type  : void
//
namespace coder {
void sum(const ::coder::array<double, 2U> &x, ::coder::array<double, 1U> &y)
{
  if (x.size(0) == 0) {
    y.set_size(0);
  } else {
    int i;
    int k;
    y.set_size(x.size(0));
    i = x.size(0);
    for (k = 0; k < i; k++) {
      y[k] = x[k];
    }
    i = x.size(0);
    for (k = 0; k < 2; k++) {
      for (int b_k{0}; b_k < i; b_k++) {
        y[b_k] = y[b_k] + x[b_k + (x.size(0) * (k + 1))];
      }
    }
  }
}

} // namespace coder

//
// File trailer for sum.cpp
//
// [EOF]
//
