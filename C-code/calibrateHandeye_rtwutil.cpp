//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calibrateHandeye_rtwutil.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

// Include Files
#include "calibrateHandeye_rtwutil.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : int u
//                unsigned int n
// Return Type  : int
//
int asr_s32(int u, unsigned int n)
{
  int y;
  if (u >= 0) {
    y = static_cast<int>(static_cast<unsigned int>(
        (static_cast<unsigned int>(u)) >> (static_cast<unsigned long>(n))));
  } else {
    y = (-(static_cast<int>(static_cast<unsigned int>(
            (static_cast<unsigned int>(static_cast<int>(-1 - u))) >>
            (static_cast<unsigned long>(n)))))) -
        1;
  }
  return y;
}

//
// Arguments    : int numerator
//                int denominator
// Return Type  : int
//
int div_s32(int numerator, int denominator)
{
  int quotient;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    unsigned int b_denominator;
    unsigned int b_numerator;
    if (numerator < 0) {
      b_numerator = (~(static_cast<unsigned int>(numerator))) + 1U;
    } else {
      b_numerator = static_cast<unsigned int>(numerator);
    }
    if (denominator < 0) {
      b_denominator = (~(static_cast<unsigned int>(denominator))) + 1U;
    } else {
      b_denominator = static_cast<unsigned int>(denominator);
    }
    b_numerator /= b_denominator;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -(static_cast<int>(b_numerator));
    } else {
      quotient = static_cast<int>(b_numerator);
    }
  }
  return quotient;
}

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
double rt_hypotd_snf(double u0, double u1)
{
  double a;
  double y;
  a = std::abs(u0);
  y = std::abs(u1);
  if (a < y) {
    a /= y;
    y *= std::sqrt((a * a) + 1.0);
  } else if (a > y) {
    y /= a;
    y = a * std::sqrt((y * y) + 1.0);
  } else if (!std::isnan(y)) {
    y = a * 1.4142135623730951;
  } else {
    /* no actions */
  }
  return y;
}

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
double rt_powd_snf(double u0, double u1)
{
  double y;
  if ((std::isnan(u0)) || (std::isnan(u1))) {
    y = rtNaN;
  } else {
    double d;
    double d1;
    d = std::abs(u0);
    d1 = std::abs(u1);
    if (std::isinf(u1)) {
      if (d == 1.0) {
        y = 1.0;
      } else if (d > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = rtNaN;
    } else {
      y = std::pow(u0, u1);
    }
  }
  return y;
}

//
// Arguments    : float u0
//                float u1
// Return Type  : float
//
float rt_powf_snf(float u0, float u1)
{
  float y;
  if ((std::isnan(u0)) || (std::isnan(u1))) {
    y = rtNaNF;
  } else {
    float f;
    float f1;
    f = std::abs(u0);
    f1 = std::abs(u1);
    if (std::isinf(u1)) {
      if (f == 1.0F) {
        y = 1.0F;
      } else if (f > 1.0F) {
        if (u1 > 0.0F) {
          y = rtInfF;
        } else {
          y = 0.0F;
        }
      } else if (u1 > 0.0F) {
        y = 0.0F;
      } else {
        y = rtInfF;
      }
    } else if (f1 == 0.0F) {
      y = 1.0F;
    } else if (f1 == 1.0F) {
      if (u1 > 0.0F) {
        y = u0;
      } else {
        y = 1.0F / u0;
      }
    } else if (u1 == 2.0F) {
      y = u0 * u0;
    } else if ((u1 == 0.5F) && (u0 >= 0.0F)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0F) && (u1 > std::floor(u1))) {
      y = rtNaNF;
    } else {
      y = std::pow(u0, u1);
    }
  }
  return y;
}

//
// File trailer for calibrateHandeye_rtwutil.cpp
//
// [EOF]
//
