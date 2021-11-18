//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sqrt.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
//

// Include Files
#include "sqrt.h"
#include "calibrateHandeye_rtwutil.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : creal_T *b_x
// Return Type  : void
//
namespace coder {
namespace internal {
namespace scalar {
void b_sqrt(creal_T *b_x)
{
  double absxi;
  double b_xi;
  double xr;
  xr = b_x->re;
  b_xi = b_x->im;
  if (b_xi == 0.0) {
    if (xr < 0.0) {
      absxi = 0.0;
      xr = std::sqrt(-xr);
    } else {
      absxi = std::sqrt(xr);
      xr = 0.0;
    }
  } else if (xr == 0.0) {
    if (b_xi < 0.0) {
      absxi = std::sqrt((-b_xi) / 2.0);
      xr = -absxi;
    } else {
      absxi = std::sqrt(b_xi / 2.0);
      xr = absxi;
    }
  } else if (std::isnan(xr)) {
    absxi = xr;
  } else if (std::isnan(b_xi)) {
    absxi = b_xi;
    xr = b_xi;
  } else if (std::isinf(b_xi)) {
    absxi = std::abs(b_xi);
    xr = b_xi;
  } else if (std::isinf(xr)) {
    if (xr < 0.0) {
      absxi = 0.0;
      xr = b_xi * (-xr);
    } else {
      absxi = xr;
      xr = 0.0;
    }
  } else {
    double absxr;
    absxr = std::abs(xr);
    absxi = std::abs(b_xi);
    if ((absxr > 4.4942328371557893E+307) ||
        (absxi > 4.4942328371557893E+307)) {
      absxr *= 0.5;
      absxi = rt_hypotd_snf(absxr, absxi * 0.5);
      if (absxi > absxr) {
        absxi = std::sqrt(absxi) * std::sqrt((absxr / absxi) + 1.0);
      } else {
        absxi = std::sqrt(absxi) * 1.4142135623730951;
      }
    } else {
      absxi = std::sqrt((rt_hypotd_snf(absxr, absxi) + absxr) * 0.5);
    }
    if (xr > 0.0) {
      xr = 0.5 * (b_xi / absxi);
    } else {
      if (b_xi < 0.0) {
        xr = -absxi;
      } else {
        xr = absxi;
      }
      absxi = 0.5 * (b_xi / xr);
    }
  }
  b_x->re = absxi;
  b_x->im = xr;
}

} // namespace scalar
} // namespace internal
} // namespace coder

//
// File trailer for sqrt.cpp
//
// [EOF]
//
