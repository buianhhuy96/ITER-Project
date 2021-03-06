//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ITER_API_rtwutil.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

// Include Files
#include "ITER_API_rtwutil.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : int c_u
//                unsigned int h_n
// Return Type  : int
//
int asr_s32(int c_u, unsigned int h_n)
{
  int y;
  if (c_u >= 0) {
    y = static_cast<int>(static_cast<unsigned int>(
        (static_cast<unsigned int>(c_u)) >> (static_cast<unsigned long>(h_n))));
  } else {
    y = (-(static_cast<int>(static_cast<unsigned int>(
            (static_cast<unsigned int>(static_cast<int>(-1 - c_u))) >>
            (static_cast<unsigned long>(h_n)))))) -
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
    unsigned int tempAbsQuotient;
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
    tempAbsQuotient = b_numerator / b_denominator;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -(static_cast<int>(tempAbsQuotient));
    } else {
      quotient = static_cast<int>(tempAbsQuotient);
    }
  }
  return quotient;
}

//
// Arguments    : double u0
//                double b_u1
// Return Type  : double
//
double rt_hypotd_snf(double u0, double b_u1)
{
  double b;
  double b_a;
  double y;
  b_a = std::abs(u0);
  b = std::abs(b_u1);
  if (b_a < b) {
    b_a /= b;
    y = b * std::sqrt((b_a * b_a) + 1.0);
  } else if (b_a > b) {
    b /= b_a;
    y = b_a * std::sqrt((b * b) + 1.0);
  } else if (std::isnan(b)) {
    y = b;
  } else {
    y = b_a * 1.4142135623730951;
  }
  return y;
}

//
// Arguments    : double u0
//                double b_u1
// Return Type  : double
//
double rt_powd_snf(double u0, double b_u1)
{
  double y;
  if ((std::isnan(u0)) || (std::isnan(b_u1))) {
    y = rtNaN;
  } else {
    double b_d1;
    double d;
    d = std::abs(u0);
    b_d1 = std::abs(b_u1);
    if (std::isinf(b_u1)) {
      if (d == 1.0) {
        y = 1.0;
      } else if (d > 1.0) {
        if (b_u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (b_u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (b_d1 == 0.0) {
      y = 1.0;
    } else if (b_d1 == 1.0) {
      if (b_u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (b_u1 == 2.0) {
      y = u0 * u0;
    } else if ((b_u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (b_u1 > std::floor(b_u1))) {
      y = rtNaN;
    } else {
      y = std::pow(u0, b_u1);
    }
  }
  return y;
}

//
// Arguments    : float u0
//                float b_u1
// Return Type  : float
//
float rt_powf_snf(float u0, float b_u1)
{
  float y;
  if ((std::isnan(u0)) || (std::isnan(b_u1))) {
    y = rtNaNF;
  } else {
    float f;
    float f1;
    f = std::abs(u0);
    f1 = std::abs(b_u1);
    if (std::isinf(b_u1)) {
      if (f == 1.0F) {
        y = 1.0F;
      } else if (f > 1.0F) {
        if (b_u1 > 0.0F) {
          y = rtInfF;
        } else {
          y = 0.0F;
        }
      } else if (b_u1 > 0.0F) {
        y = 0.0F;
      } else {
        y = rtInfF;
      }
    } else if (f1 == 0.0F) {
      y = 1.0F;
    } else if (f1 == 1.0F) {
      if (b_u1 > 0.0F) {
        y = u0;
      } else {
        y = 1.0F / u0;
      }
    } else if (b_u1 == 2.0F) {
      y = u0 * u0;
    } else if ((b_u1 == 0.5F) && (u0 >= 0.0F)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0F) && (b_u1 > std::floor(b_u1))) {
      y = rtNaNF;
    } else {
      y = std::pow(u0, b_u1);
    }
  }
  return y;
}

//
// File trailer for ITER_API_rtwutil.cpp
//
// [EOF]
//
