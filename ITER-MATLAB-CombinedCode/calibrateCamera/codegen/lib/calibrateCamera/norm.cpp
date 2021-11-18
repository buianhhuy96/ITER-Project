//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: norm.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "norm.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<real_T, 1U> &b_x
// Return Type  : real_T
//
namespace Codegen {
namespace coder {
real_T b_norm(const ::coder::array<real_T, 1U> &b_x)
{
  real_T y;
  if (b_x.size(0) == 0) {
    y = 0.0;
  } else {
    y = 0.0;
    if (b_x.size(0) == 1) {
      y = std::abs(b_x[0]);
    } else {
      real_T scale;
      int32_T b_kend;
      scale = 3.3121686421112381E-170;
      b_kend = b_x.size(0);
      for (int32_T k{0}; k < b_kend; k++) {
        real_T absxk;
        absxk = std::abs(b_x[k]);
        if (absxk > scale) {
          real_T b_t;
          b_t = scale / absxk;
          y = ((y * b_t) * b_t) + 1.0;
          scale = absxk;
        } else {
          real_T b_t;
          b_t = absxk / scale;
          y += b_t * b_t;
        }
      }
      y = scale * std::sqrt(y);
    }
  }
  return y;
}

} // namespace coder
} // namespace Codegen

//
// File trailer for norm.cpp
//
// [EOF]
//
