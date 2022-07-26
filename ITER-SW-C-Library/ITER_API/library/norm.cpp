//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: norm.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "norm.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &b_x
// Return Type  : double
//
namespace ITER {
namespace coder {
double b_norm(const ::coder::array<double, 1U> &b_x)
{
  double y;
  if (b_x.size(0) == 0) {
    y = 0.0;
  } else {
    y = 0.0;
    if (b_x.size(0) == 1) {
      y = std::abs(b_x[0]);
    } else {
      double scale;
      int kend;
      scale = 3.3121686421112381E-170;
      kend = b_x.size(0);
      for (int k{0}; k < kend; k++) {
        double absxk;
        absxk = std::abs(b_x[k]);
        if (absxk > scale) {
          double b_t;
          b_t = scale / absxk;
          y = ((y * b_t) * b_t) + 1.0;
          scale = absxk;
        } else {
          double b_t;
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
} // namespace ITER

//
// File trailer for norm.cpp
//
// [EOF]
//
