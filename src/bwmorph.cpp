//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bwmorph.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

// Include Files
#include "bwmorph.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "libmwbwlookup_tbb.h"

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
    boolean_T quotientNeedsNegation;
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
// Arguments    : ::coder::array<boolean_T, 2U> &bwin
// Return Type  : void
//
namespace coder {
void bwmorph(::coder::array<boolean_T, 2U> &bwin)
{
  static const boolean_T lut[512]{
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, true,  true,  true,
      true,  false, true,  true,  true,  true,  true,  true,  false, false,
      true,  true,  false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, true,  false,
      true,  true,  true,  false, true,  true,  false, false, true,  true,
      false, false, true,  true,  false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      true,  false, false, false, false, false, false, false, true,  true,
      true,  true,  false, false, true,  true,  false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, true,  true,  false, false, true,  true,  false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, true,  false, false, false, false, false,
      false, false, true,  true,  true,  true,  false, false, true,  true,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, true,  false, true,  true,
      true,  false, true,  true,  true,  true,  false, false, true,  true,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, true,  false,
      false, false, false, false, false, false, true,  true,  true,  true,
      false, false, true,  true,  false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      true,  false, true,  true,  true,  false, true,  true,  true,  true,
      false, false, true,  true,  false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, true,  false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, true,  false, true,  true,  true,  false,
      true,  true,  false, false, true,  true,  false, false, true,  true,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, true,  true,
      false, false, true,  true,  false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      true,  false, false, false, false, false, false, false, true,  true,
      true,  true,  false, false, true,  true,  false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, true,  false, true,  true,  true,  false, true,  true,
      true,  true,  false, false, true,  true,  false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, true,  false, false, false, false, false,
      false, false, true,  true,  true,  true,  false, false, true,  true,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, true,  false, true,  true,
      true,  false, true,  true,  true,  true,  false, false, true,  true,
      false, false};
  array<boolean_T, 2U> last_aout;
  array<boolean_T, 2U> m;
  double sizeIn[2];
  if ((bwin.size(0) != 0) && (bwin.size(1) != 0)) {
    int loop_ub;
    boolean_T b_p;
    do {
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
      boolean_T p;
      last_aout.set_size(bwin.size(0), bwin.size(1));
      loop_ub = bwin.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = bwin.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          last_aout[i1 + (last_aout.size(0) * i)] =
              bwin[i1 + (bwin.size(0) * i)];
        }
      }
      m.set_size(bwin.size(0), bwin.size(1));
      if ((bwin.size(0) != 0) && (bwin.size(1) != 0)) {
        sizeIn[0] = static_cast<double>(bwin.size(0));
        sizeIn[1] = static_cast<double>(bwin.size(1));
        bwlookup_tbb_boolean(&bwin[0], &sizeIn[0], 2.0, &lut[0], 512.0, &m[0]);
      }
      m.set_size(bwin.size(0), bwin.size(1));
      loop_ub = bwin.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = bwin.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          m[i1 + (m.size(0) * i)] =
              ((bwin[i1 + (bwin.size(0) * i)]) && (!m[i1 + (m.size(0) * i)]));
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
      if (1 > bwin.size(0)) {
        i4 = 1;
      } else {
        i4 = 2;
      }
      if (1 > bwin.size(1)) {
        i5 = 1;
      } else {
        i5 = 2;
      }
      loop_ub = div_s32_floor(i3 - 1, i2);
      for (i3 = 0; i3 <= loop_ub; i3++) {
        b_loop_ub = div_s32_floor(i1 - 1, i);
        for (i6 = 0; i6 <= b_loop_ub; i6++) {
          bwin[(i4 * i6) + (bwin.size(0) * (i5 * i3))] =
              m[(i * i6) + (m.size(0) * (i2 * i3))];
        }
      }
      m.set_size(bwin.size(0), bwin.size(1));
      if ((bwin.size(0) != 0) && (bwin.size(1) != 0)) {
        sizeIn[0] = static_cast<double>(bwin.size(0));
        sizeIn[1] = static_cast<double>(bwin.size(1));
        bwlookup_tbb_boolean(&bwin[0], &sizeIn[0], 2.0, &lut[0], 512.0, &m[0]);
      }
      m.set_size(bwin.size(0), bwin.size(1));
      loop_ub = bwin.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = bwin.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          m[i1 + (m.size(0) * i)] =
              ((bwin[i1 + (bwin.size(0) * i)]) && (!m[i1 + (m.size(0) * i)]));
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
      if (2 > bwin.size(0)) {
        i6 = 0;
        i7 = 1;
      } else {
        i6 = 1;
        i7 = 2;
      }
      if (2 > bwin.size(1)) {
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
          bwin[(i6 + (i7 * i10)) + (bwin.size(0) * (i8 + (i9 * i5)))] =
              m[(i + (i1 * i10)) + (m.size(0) * (i3 + (i4 * i5)))];
        }
      }
      m.set_size(bwin.size(0), bwin.size(1));
      if ((bwin.size(0) != 0) && (bwin.size(1) != 0)) {
        sizeIn[0] = static_cast<double>(bwin.size(0));
        sizeIn[1] = static_cast<double>(bwin.size(1));
        bwlookup_tbb_boolean(&bwin[0], &sizeIn[0], 2.0, &lut[0], 512.0, &m[0]);
      }
      m.set_size(bwin.size(0), bwin.size(1));
      loop_ub = bwin.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = bwin.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          m[i1 + (m.size(0) * i)] =
              ((bwin[i1 + (bwin.size(0) * i)]) && (!m[i1 + (m.size(0) * i)]));
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
      if (1 > bwin.size(0)) {
        i5 = 1;
      } else {
        i5 = 2;
      }
      if (2 > bwin.size(1)) {
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
          bwin[(i5 * i8) + (bwin.size(0) * (i6 + (i7 * i4)))] =
              m[(i * i8) + (m.size(0) * (i2 + (i3 * i4)))];
        }
      }
      m.set_size(bwin.size(0), bwin.size(1));
      if ((bwin.size(0) != 0) && (bwin.size(1) != 0)) {
        sizeIn[0] = static_cast<double>(bwin.size(0));
        sizeIn[1] = static_cast<double>(bwin.size(1));
        bwlookup_tbb_boolean(&bwin[0], &sizeIn[0], 2.0, &lut[0], 512.0, &m[0]);
      }
      m.set_size(bwin.size(0), bwin.size(1));
      loop_ub = bwin.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = bwin.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          m[i1 + (m.size(0) * i)] =
              ((bwin[i1 + (bwin.size(0) * i)]) && (!m[i1 + (m.size(0) * i)]));
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
      if (2 > bwin.size(0)) {
        i5 = 0;
        i6 = 1;
      } else {
        i5 = 1;
        i6 = 2;
      }
      if (1 > bwin.size(1)) {
        i7 = 1;
      } else {
        i7 = 2;
      }
      loop_ub = div_s32_floor(i4 - 1, i3);
      for (i4 = 0; i4 <= loop_ub; i4++) {
        b_loop_ub = div_s32_floor((i2 - i) - 1, i1);
        for (i8 = 0; i8 <= b_loop_ub; i8++) {
          bwin[(i5 + (i6 * i8)) + (bwin.size(0) * (i7 * i4))] =
              m[(i + (i1 * i8)) + (m.size(0) * (i3 * i4))];
        }
      }
      p = false;
      if (last_aout.size(0) == bwin.size(0)) {
        if (last_aout.size(1) == bwin.size(1)) {
          p = true;
        }
      }
      if (p) {
        if ((last_aout.size(0) != 0) && (last_aout.size(1) != 0)) {
          if ((bwin.size(0) != 0) && (bwin.size(1) != 0)) {
            boolean_T exitg1;
            p = true;
            loop_ub = 0;
            exitg1 = false;
            while ((!exitg1) && (loop_ub <= (last_aout.size(1) - 1))) {
              boolean_T exitg2;
              b_loop_ub = 0;
              exitg2 = false;
              while ((!exitg2) && (b_loop_ub <= (last_aout.size(0) - 1))) {
                p = ((last_aout[b_loop_ub + (last_aout.size(0) * loop_ub)] ==
                      bwin[b_loop_ub + (bwin.size(0) * loop_ub)]) &&
                     p);
                if (!p) {
                  exitg2 = true;
                } else {
                  b_loop_ub++;
                }
              }
              if (!p) {
                exitg1 = true;
              } else {
                loop_ub++;
              }
            }
          }
        }
      }
      b_p = p;
    } while (!b_p);
    //  the output is not changing anymore
  }
}

} // namespace coder

//
// File trailer for bwmorph.cpp
//
// [EOF]
//
