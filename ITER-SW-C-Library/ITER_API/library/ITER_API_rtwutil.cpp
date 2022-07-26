//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ITER_API_rtwutil.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "ITER_API_rtwutil.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : int c_u
//                unsigned int h_n
// Return Type  : int
//
namespace ITER {
int asr_s32(int c_u, unsigned int h_n)
{
  int y;
  if (c_u >= 0) {
    y = static_cast<int>(
        static_cast<unsigned int>((static_cast<unsigned int>(c_u)) >> h_n));
  } else {
    y = (-(static_cast<int>(static_cast<unsigned int>(
            (static_cast<unsigned int>(static_cast<int>(-1 - c_u))) >> h_n)))) -
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
// Arguments    : int b_a
//                int b
// Return Type  : int
//
int mul_s32_sat(int b_a, int b)
{
  int result;
  unsigned int u32_chi;
  unsigned int u32_clo;
  mul_wide_s32(b_a, b, &u32_chi, &u32_clo);
  if (((static_cast<int>(u32_chi)) > 0) ||
      ((u32_chi == 0U) && (u32_clo >= 2147483648U))) {
    result = MAX_int32_T;
  } else if (((static_cast<int>(u32_chi)) < -1) ||
             (((static_cast<int>(u32_chi)) == -1) && (u32_clo < 2147483648U))) {
    result = MIN_int32_T;
  } else {
    result = static_cast<int>(u32_clo);
  }
  return result;
}

//
// Arguments    : int in0
//                int in1
//                unsigned int *ptrOutBitsHi
//                unsigned int *ptrOutBitsLo
// Return Type  : void
//
void mul_wide_s32(int in0, int in1, unsigned int *ptrOutBitsHi,
                  unsigned int *ptrOutBitsLo)
{
  unsigned int absIn0;
  unsigned int absIn1;
  int carry;
  int in0Hi;
  int in0Lo;
  int in1Hi;
  int in1Lo;
  unsigned int outBitsHi;
  unsigned int outBitsLo;
  unsigned int productHiLo;
  unsigned int productLoHi;
  unsigned int productLoLo;
  if (in0 < 0) {
    absIn0 = (~(static_cast<unsigned int>(in0))) + 1U;
  } else {
    absIn0 = static_cast<unsigned int>(in0);
  }
  if (in1 < 0) {
    absIn1 = (~(static_cast<unsigned int>(in1))) + 1U;
  } else {
    absIn1 = static_cast<unsigned int>(in1);
  }
  in0Hi = static_cast<int>(static_cast<unsigned int>(absIn0 >> 16U));
  in0Lo = static_cast<int>(static_cast<unsigned int>(absIn0 & 65535U));
  in1Hi = static_cast<int>(static_cast<unsigned int>(absIn1 >> 16U));
  in1Lo = static_cast<int>(static_cast<unsigned int>(absIn1 & 65535U));
  productHiLo =
      (static_cast<unsigned int>(in0Hi)) * (static_cast<unsigned int>(in1Lo));
  productLoHi =
      (static_cast<unsigned int>(in0Lo)) * (static_cast<unsigned int>(in1Hi));
  productLoLo =
      (static_cast<unsigned int>(in0Lo)) * (static_cast<unsigned int>(in1Lo));
  carry = 0;
  outBitsLo = productLoLo + (productLoHi << 16U);
  if (outBitsLo < productLoLo) {
    carry = 1;
  }
  productLoLo = outBitsLo;
  outBitsLo += (productHiLo << 16U);
  if (outBitsLo < productLoLo) {
    carry = static_cast<int>(
        static_cast<unsigned int>((static_cast<unsigned int>(carry)) + 1U));
  }
  outBitsHi = (((static_cast<unsigned int>(carry)) +
                ((static_cast<unsigned int>(in0Hi)) *
                 (static_cast<unsigned int>(in1Hi)))) +
               (productLoHi >> 16U)) +
              (productHiLo >> 16U);
  if ((static_cast<int>((in0 != 0) &&
                        ((in1 != 0) && ((in0 > 0) != (in1 > 0))))) != 0) {
    outBitsHi = ~outBitsHi;
    outBitsLo = ~outBitsLo;
    outBitsLo++;
    if (outBitsLo == 0U) {
      outBitsHi++;
    }
  }
  *ptrOutBitsHi = outBitsHi;
  *ptrOutBitsLo = outBitsLo;
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
// Arguments    : float u0
//                float b_u1
// Return Type  : float
//
float rt_hypotf_snf(float u0, float b_u1)
{
  float b;
  float b_a;
  float y;
  b_a = std::abs(u0);
  b = std::abs(b_u1);
  if (b_a < b) {
    b_a /= b;
    y = b * std::sqrt((b_a * b_a) + 1.0F);
  } else if (b_a > b) {
    b /= b_a;
    y = b_a * std::sqrt((b * b) + 1.0F);
  } else if (std::isnan(b)) {
    y = b;
  } else {
    y = b_a * 1.41421354F;
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

} // namespace ITER

//
// File trailer for ITER_API_rtwutil.cpp
//
// [EOF]
//
