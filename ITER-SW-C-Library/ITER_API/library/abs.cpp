//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: abs.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "abs.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &b_x
//                ::coder::array<double, 1U> &y
// Return Type  : void
//
namespace ITER {
namespace coder {
void b_abs(const ::coder::array<double, 1U> &b_x, ::coder::array<double, 1U> &y)
{
  y.set_size(b_x.size(0));
  if (b_x.size(0) != 0) {
    int b_i;
    b_i = b_x.size(0);
    if ((static_cast<int>(b_x.size(0) < 4)) != 0) {
      for (int k{0}; k < b_i; k++) {
        y[k] = std::abs(b_x[k]);
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int k = 0; k < b_i; k++) {
        y[k] = std::abs(b_x[k]);
      }
    }
  }
}

} // namespace coder
} // namespace ITER

//
// File trailer for abs.cpp
//
// [EOF]
//
