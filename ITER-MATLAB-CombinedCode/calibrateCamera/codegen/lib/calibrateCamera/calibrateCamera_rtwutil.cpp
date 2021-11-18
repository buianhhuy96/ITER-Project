//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calibrateCamera_rtwutil.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "calibrateCamera_rtwutil.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : int32_T b_u
//                uint32_T g_n
// Return Type  : int32_T
//
namespace Codegen {
int32_T asr_s32(int32_T b_u, uint32_T g_n)
{
  int32_T y;
  if (b_u >= 0) {
    y = static_cast<int32_T>(static_cast<uint32_T>(
        (static_cast<uint32_T>(b_u)) >> (static_cast<uint64_T>(g_n))));
  } else {
    y = (-(static_cast<int32_T>(static_cast<uint32_T>(
            (static_cast<uint32_T>(static_cast<int32_T>(-1 - b_u))) >>
            (static_cast<uint64_T>(g_n)))))) -
        1;
  }
  return y;
}

//
// Arguments    : int32_T numerator
//                int32_T denominator
// Return Type  : int32_T
//
int32_T div_s32(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    uint32_T b_denominator;
    uint32_T b_numerator;
    if (numerator < 0) {
      b_numerator = (~(static_cast<uint32_T>(numerator))) + 1U;
    } else {
      b_numerator = static_cast<uint32_T>(numerator);
    }
    if (denominator < 0) {
      b_denominator = (~(static_cast<uint32_T>(denominator))) + 1U;
    } else {
      b_denominator = static_cast<uint32_T>(denominator);
    }
    b_numerator /= b_denominator;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -(static_cast<int32_T>(b_numerator));
    } else {
      quotient = static_cast<int32_T>(b_numerator);
    }
  }
  return quotient;
}

//
// Arguments    : real_T u0
//                real_T u1
// Return Type  : real_T
//
real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T b_a;
  real_T y;
  b_a = std::abs(u0);
  y = std::abs(u1);
  if (b_a < y) {
    b_a /= y;
    y *= std::sqrt((b_a * b_a) + 1.0);
  } else if (b_a > y) {
    y /= b_a;
    y = b_a * std::sqrt((y * y) + 1.0);
  } else if (!std::isnan(y)) {
    y = b_a * 1.4142135623730951;
  } else {
    /* no actions */
  }
  return y;
}

//
// Arguments    : real_T u0
//                real_T u1
// Return Type  : real_T
//
real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if ((std::isnan(u0)) || (std::isnan(u1))) {
    y = rtNaN;
  } else {
    real_T b_d1;
    real_T d;
    d = std::abs(u0);
    b_d1 = std::abs(u1);
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
    } else if (b_d1 == 0.0) {
      y = 1.0;
    } else if (b_d1 == 1.0) {
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
// Arguments    : real32_T u0
//                real32_T u1
// Return Type  : real32_T
//
real32_T rt_powf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  if ((std::isnan(u0)) || (std::isnan(u1))) {
    y = rtNaNF;
  } else {
    real32_T f;
    real32_T f1;
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

} // namespace Codegen

//
// File trailer for calibrateCamera_rtwutil.cpp
//
// [EOF]
//
