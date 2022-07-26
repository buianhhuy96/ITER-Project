//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mod.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "mod.h"
#include "ITER_API_rtwutil.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : int b_x
//                double y
// Return Type  : int
//
namespace ITER {
namespace coder {
int b_mod(int b_x, double y)
{
  int r;
  if ((static_cast<double>(static_cast<int>(y))) == y) {
    if (y == 0.0) {
      r = b_x;
    } else {
      int c_r_tmp;
      c_r_tmp = static_cast<int>(y);
      r = b_x - (div_s32(b_x, c_r_tmp) * c_r_tmp);
    }
  } else {
    double c_r;
    c_r = static_cast<double>(b_x);
    if (y == 0.0) {
      if (b_x == 0) {
        c_r = y;
      }
    } else if (std::isnan(y)) {
      c_r = rtNaN;
    } else if (b_x == 0) {
      c_r = 0.0 / y;
    } else if (std::isinf(y)) {
      if ((y < 0.0) != (b_x < 0)) {
        c_r = y;
      }
    } else {
      bool rEQ0;
      c_r = std::fmod(static_cast<double>(b_x), y);
      rEQ0 = (c_r == 0.0);
      if (!rEQ0) {
        if (y > std::floor(y)) {
          double b_q;
          b_q = std::abs((static_cast<double>(b_x)) / y);
          rEQ0 = !(std::abs(b_q - std::floor(b_q + 0.5)) >
                   (2.2204460492503131E-16 * b_q));
        }
      }
      if (rEQ0) {
        c_r = y * 0.0;
      } else if ((b_x < 0) != (y < 0.0)) {
        c_r += y;
      } else {
        /* no actions */
      }
    }
    r = static_cast<int>(c_r);
  }
  return r;
}

} // namespace coder
} // namespace ITER

//
// File trailer for mod.cpp
//
// [EOF]
//
