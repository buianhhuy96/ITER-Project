//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mod.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "mod.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : double b_x
//                double y
// Return Type  : double
//
namespace coder {
double b_mod(double b_x, double y)
{
  double r;
  r = b_x;
  if (y == 0.0) {
    if (b_x == 0.0) {
      r = y;
    }
  } else if (std::isnan(b_x)) {
    r = rtNaN;
  } else if (std::isnan(y)) {
    r = rtNaN;
  } else if (std::isinf(b_x)) {
    r = rtNaN;
  } else if (b_x == 0.0) {
    r = 0.0 / y;
  } else if (std::isinf(y)) {
    if ((y < 0.0) != (b_x < 0.0)) {
      r = y;
    }
  } else {
    bool rEQ0;
    r = std::fmod(b_x, y);
    rEQ0 = (r == 0.0);
    if (!rEQ0) {
      if (y > std::floor(y)) {
        double q;
        q = std::abs(b_x / y);
        rEQ0 =
            !(std::abs(q - std::floor(q + 0.5)) > (2.2204460492503131E-16 * q));
      }
    }
    if (rEQ0) {
      r = y * 0.0;
    } else if ((b_x < 0.0) != (y < 0.0)) {
      r += y;
    } else {
      /* no actions */
    }
  }
  return r;
}

} // namespace coder

//
// File trailer for mod.cpp
//
// [EOF]
//
