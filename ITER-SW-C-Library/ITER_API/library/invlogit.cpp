//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: invlogit.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "invlogit.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &b_in
//                ::coder::array<double, 2U> &out
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace classreg {
namespace learning {
namespace coder {
namespace transform {
void b_invlogit(const ::coder::array<double, 2U> &b_in,
                ::coder::array<double, 2U> &out)
{
  int b_i;
  out.set_size(b_in.size(0), 2);
  b_i = b_in.size(0) * 2;
  if ((static_cast<int>(b_i < 4)) != 0) {
    for (int c_i{0}; c_i < b_i; c_i++) {
      if (b_in[c_i] == 0.0) {
        out[c_i] = rtMinusInf;
      } else if (b_in[c_i] == 1.0) {
        out[c_i] = rtInf;
      } else if (std::isnan(b_in[c_i])) {
        out[c_i] = rtNaN;
      } else {
        out[c_i] = std::log(b_in[c_i] / (1.0 - b_in[c_i]));
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int c_i = 0; c_i < b_i; c_i++) {
      if (b_in[c_i] == 0.0) {
        out[c_i] = rtMinusInf;
      } else if (b_in[c_i] == 1.0) {
        out[c_i] = rtInf;
      } else if (std::isnan(b_in[c_i])) {
        out[c_i] = rtNaN;
      } else {
        out[c_i] = std::log(b_in[c_i] / (1.0 - b_in[c_i]));
      }
    }
  }
}

} // namespace transform
} // namespace coder
} // namespace learning
} // namespace classreg
} // namespace coder
} // namespace ITER

//
// File trailer for invlogit.cpp
//
// [EOF]
//
