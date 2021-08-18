//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: algbwmorph.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

// Include Files
#include "algbwmorph.h"
#include "bwlookup.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
static int div_s32_floor(int numerator, int denominator);

// Function Definitions
//
// Arguments    : int numerator
//                int denominator
// Return Type  : int
//
static int div_s32_floor(int numerator, int denominator)
{
  int quotient;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    unsigned int absDenominator;
    unsigned int absNumerator;
    unsigned int tempAbsQuotient;
    bool quotientNeedsNegation;
    if (numerator < 0) {
      absNumerator = (~(static_cast<unsigned int>(numerator))) + 1U;
    } else {
      absNumerator = static_cast<unsigned int>(numerator);
    }
    if (denominator < 0) {
      absDenominator = (~(static_cast<unsigned int>(denominator))) + 1U;
    } else {
      absDenominator = static_cast<unsigned int>(denominator);
    }
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
      quotient = -(static_cast<int>(tempAbsQuotient));
    } else {
      quotient = static_cast<int>(tempAbsQuotient);
    }
  }
  return quotient;
}

//
// Arguments    : ::coder::array<bool, 2U> &bw
// Return Type  : void
//
namespace coder {
namespace images {
namespace internal {
void bwmorphApplyOnce(::coder::array<bool, 2U> &bw)
{
  array<bool, 2U> m;
  int b_loop_ub;
  int i;
  int i1;
  int i2;
  int i3;
  int i4;
  int i5;
  int i6;
  int i7;
  int i8;
  int i9;
  int loop_ub;
  bwlookup(bw, m);
  m.set_size(bw.size(0), bw.size(1));
  loop_ub = bw.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = bw.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      m[i1 + (m.size(0) * i)] =
          ((bw[i1 + (bw.size(0) * i)]) && (!m[i1 + (m.size(0) * i)]));
    }
  }
  if (1 > m.size(0)) {
    i = 1;
    i1 = 0;
  } else {
    i = 2;
    i1 = m.size(0);
  }
  if (1 > m.size(1)) {
    i2 = 1;
    i3 = 0;
  } else {
    i2 = 2;
    i3 = m.size(1);
  }
  if (1 > bw.size(0)) {
    i4 = 1;
  } else {
    i4 = 2;
  }
  if (1 > bw.size(1)) {
    i5 = 1;
  } else {
    i5 = 2;
  }
  loop_ub = div_s32_floor(i3 - 1, i2);
  for (i3 = 0; i3 <= loop_ub; i3++) {
    b_loop_ub = div_s32_floor(i1 - 1, i);
    for (i6 = 0; i6 <= b_loop_ub; i6++) {
      bw[(i4 * i6) + (bw.size(0) * (i5 * i3))] =
          m[(i * i6) + (m.size(0) * (i2 * i3))];
    }
  }
  bwlookup(bw, m);
  m.set_size(bw.size(0), bw.size(1));
  loop_ub = bw.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = bw.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      m[i1 + (m.size(0) * i)] =
          ((bw[i1 + (bw.size(0) * i)]) && (!m[i1 + (m.size(0) * i)]));
    }
  }
  if (2 > m.size(0)) {
    i = 0;
    i1 = 1;
    i2 = 0;
  } else {
    i = 1;
    i1 = 2;
    i2 = m.size(0);
  }
  if (2 > m.size(1)) {
    i3 = 0;
    i4 = 1;
    i5 = 0;
  } else {
    i3 = 1;
    i4 = 2;
    i5 = m.size(1);
  }
  if (2 > bw.size(0)) {
    i6 = 0;
    i7 = 1;
  } else {
    i6 = 1;
    i7 = 2;
  }
  if (2 > bw.size(1)) {
    i8 = 0;
    i9 = 1;
  } else {
    i8 = 1;
    i9 = 2;
  }
  loop_ub = div_s32_floor((i5 - i3) - 1, i4);
  for (i5 = 0; i5 <= loop_ub; i5++) {
    b_loop_ub = div_s32_floor((i2 - i) - 1, i1);
    for (int i10{0}; i10 <= b_loop_ub; i10++) {
      bw[(i6 + (i7 * i10)) + (bw.size(0) * (i8 + (i9 * i5)))] =
          m[(i + (i1 * i10)) + (m.size(0) * (i3 + (i4 * i5)))];
    }
  }
  bwlookup(bw, m);
  m.set_size(bw.size(0), bw.size(1));
  loop_ub = bw.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = bw.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      m[i1 + (m.size(0) * i)] =
          ((bw[i1 + (bw.size(0) * i)]) && (!m[i1 + (m.size(0) * i)]));
    }
  }
  if (1 > m.size(0)) {
    i = 1;
    i1 = 0;
  } else {
    i = 2;
    i1 = m.size(0);
  }
  if (2 > m.size(1)) {
    i2 = 0;
    i3 = 1;
    i4 = 0;
  } else {
    i2 = 1;
    i3 = 2;
    i4 = m.size(1);
  }
  if (1 > bw.size(0)) {
    i5 = 1;
  } else {
    i5 = 2;
  }
  if (2 > bw.size(1)) {
    i6 = 0;
    i7 = 1;
  } else {
    i6 = 1;
    i7 = 2;
  }
  loop_ub = div_s32_floor((i4 - i2) - 1, i3);
  for (i4 = 0; i4 <= loop_ub; i4++) {
    b_loop_ub = div_s32_floor(i1 - 1, i);
    for (i8 = 0; i8 <= b_loop_ub; i8++) {
      bw[(i5 * i8) + (bw.size(0) * (i6 + (i7 * i4)))] =
          m[(i * i8) + (m.size(0) * (i2 + (i3 * i4)))];
    }
  }
  bwlookup(bw, m);
  m.set_size(bw.size(0), bw.size(1));
  loop_ub = bw.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = bw.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      m[i1 + (m.size(0) * i)] =
          ((bw[i1 + (bw.size(0) * i)]) && (!m[i1 + (m.size(0) * i)]));
    }
  }
  if (2 > m.size(0)) {
    i = 0;
    i1 = 1;
    i2 = 0;
  } else {
    i = 1;
    i1 = 2;
    i2 = m.size(0);
  }
  if (1 > m.size(1)) {
    i3 = 1;
    i4 = 0;
  } else {
    i3 = 2;
    i4 = m.size(1);
  }
  if (2 > bw.size(0)) {
    i5 = 0;
    i6 = 1;
  } else {
    i5 = 1;
    i6 = 2;
  }
  if (1 > bw.size(1)) {
    i7 = 1;
  } else {
    i7 = 2;
  }
  loop_ub = div_s32_floor(i4 - 1, i3);
  for (i4 = 0; i4 <= loop_ub; i4++) {
    b_loop_ub = div_s32_floor((i2 - i) - 1, i1);
    for (i8 = 0; i8 <= b_loop_ub; i8++) {
      bw[(i5 + (i6 * i8)) + (bw.size(0) * (i7 * i4))] =
          m[(i + (i1 * i8)) + (m.size(0) * (i3 * i4))];
    }
  }
}

} // namespace internal
} // namespace images
} // namespace coder

//
// File trailer for algbwmorph.cpp
//
// [EOF]
//
