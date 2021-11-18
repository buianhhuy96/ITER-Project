//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sqrt.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

// Include Files
#include "sqrt.h"
#include "ITER_API_rtwutil.h"
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
  double b_xi;
  double c_yi;
  double xr;
  double yr;
  xr = b_x->re;
  b_xi = b_x->im;
  if (b_xi == 0.0) {
    if (xr < 0.0) {
      yr = 0.0;
      c_yi = std::sqrt(-xr);
    } else {
      yr = std::sqrt(xr);
      c_yi = 0.0;
    }
  } else if (xr == 0.0) {
    if (b_xi < 0.0) {
      yr = std::sqrt((-b_xi) / 2.0);
      c_yi = -yr;
    } else {
      yr = std::sqrt(b_xi / 2.0);
      c_yi = yr;
    }
  } else if (std::isnan(xr)) {
    yr = xr;
    c_yi = xr;
  } else if (std::isnan(b_xi)) {
    yr = b_xi;
    c_yi = b_xi;
  } else if (std::isinf(b_xi)) {
    yr = std::abs(b_xi);
    c_yi = b_xi;
  } else if (std::isinf(xr)) {
    if (xr < 0.0) {
      yr = 0.0;
      c_yi = b_xi * (-xr);
    } else {
      yr = xr;
      c_yi = 0.0;
    }
  } else {
    double absxi;
    double absxr;
    absxr = std::abs(xr);
    absxi = std::abs(b_xi);
    if ((absxr > 4.4942328371557893E+307) ||
        (absxi > 4.4942328371557893E+307)) {
      double absxd2;
      absxr *= 0.5;
      absxd2 = rt_hypotd_snf(absxr, absxi * 0.5);
      if (absxd2 > absxr) {
        yr = std::sqrt(absxd2) * std::sqrt((absxr / absxd2) + 1.0);
      } else {
        yr = std::sqrt(absxd2) * 1.4142135623730951;
      }
    } else {
      yr = std::sqrt((rt_hypotd_snf(absxr, absxi) + absxr) * 0.5);
    }
    if (xr > 0.0) {
      c_yi = 0.5 * (b_xi / yr);
    } else {
      if (b_xi < 0.0) {
        c_yi = -yr;
      } else {
        c_yi = yr;
      }
      yr = 0.5 * (b_xi / c_yi);
    }
  }
  b_x->re = yr;
  b_x->im = c_yi;
}

} // namespace scalar
} // namespace internal
} // namespace coder

//
// File trailer for sqrt.cpp
//
// [EOF]
//
