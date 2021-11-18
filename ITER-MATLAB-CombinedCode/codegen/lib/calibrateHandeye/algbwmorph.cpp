//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: algbwmorph.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 14:44:26
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
  array<bool, 2U> sub;
  int c_loop_ub;
  int e_loop_ub;
  int g_loop_ub;
  int i1;
  int i11;
  int i13;
  int i14;
  int i15;
  int i16;
  int i17;
  int i18;
  int i19;
  int i20;
  int i21;
  int i25;
  int i27;
  int i28;
  int i29;
  int i3;
  int i30;
  int i31;
  int i32;
  int i33;
  int i37;
  int i39;
  int i4;
  int i40;
  int i41;
  int i42;
  int i43;
  int i44;
  int i45;
  int i5;
  int i6;
  int i7;
  int i_loop_ub;
  int k_loop_ub;
  int loop_ub;
  int o_loop_ub;
  int q_loop_ub;
  bwlookup(bw, m);
  sub.set_size(bw.size(0), bw.size(1));
  loop_ub = bw.size(1);
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    int b_loop_ub;
    b_loop_ub = bw.size(0);
    for (int i2{0}; i2 < b_loop_ub; i2++) {
      sub[i2 + (sub.size(0) * b_i)] =
          ((bw[i2 + (bw.size(0) * b_i)]) && (!m[i2 + (m.size(0) * b_i)]));
    }
  }
  if (1 > sub.size(0)) {
    i1 = 1;
    i3 = 0;
  } else {
    i1 = 2;
    i3 = sub.size(0);
  }
  if (1 > sub.size(1)) {
    i4 = 1;
    i5 = 0;
  } else {
    i4 = 2;
    i5 = sub.size(1);
  }
  if (1 > bw.size(0)) {
    i6 = 1;
  } else {
    i6 = 2;
  }
  if (1 > bw.size(1)) {
    i7 = 1;
  } else {
    i7 = 2;
  }
  c_loop_ub = div_s32_floor(i5 - 1, i4);
  for (int i8{0}; i8 <= c_loop_ub; i8++) {
    int d_loop_ub;
    d_loop_ub = div_s32_floor(i3 - 1, i1);
    for (int i9{0}; i9 <= d_loop_ub; i9++) {
      bw[(i6 * i9) + (bw.size(0) * (i7 * i8))] =
          sub[(i1 * i9) + (sub.size(0) * (i4 * i8))];
    }
  }
  bwlookup(bw, m);
  sub.set_size(bw.size(0), bw.size(1));
  e_loop_ub = bw.size(1);
  for (int i10{0}; i10 < e_loop_ub; i10++) {
    int f_loop_ub;
    f_loop_ub = bw.size(0);
    for (int i12{0}; i12 < f_loop_ub; i12++) {
      sub[i12 + (sub.size(0) * i10)] =
          ((bw[i12 + (bw.size(0) * i10)]) && (!m[i12 + (m.size(0) * i10)]));
    }
  }
  if (2 > sub.size(0)) {
    i11 = 0;
    i13 = 1;
    i14 = 0;
  } else {
    i11 = 1;
    i13 = 2;
    i14 = sub.size(0);
  }
  if (2 > sub.size(1)) {
    i15 = 0;
    i16 = 1;
    i17 = 0;
  } else {
    i15 = 1;
    i16 = 2;
    i17 = sub.size(1);
  }
  if (2 > bw.size(0)) {
    i18 = 0;
    i19 = 1;
  } else {
    i18 = 1;
    i19 = 2;
  }
  if (2 > bw.size(1)) {
    i20 = 0;
    i21 = 1;
  } else {
    i20 = 1;
    i21 = 2;
  }
  g_loop_ub = div_s32_floor((i17 - i15) - 1, i16);
  for (int i22{0}; i22 <= g_loop_ub; i22++) {
    int h_loop_ub;
    h_loop_ub = div_s32_floor((i14 - i11) - 1, i13);
    for (int i23{0}; i23 <= h_loop_ub; i23++) {
      bw[(i18 + (i19 * i23)) + (bw.size(0) * (i20 + (i21 * i22)))] =
          sub[(i11 + (i13 * i23)) + (sub.size(0) * (i15 + (i16 * i22)))];
    }
  }
  bwlookup(bw, m);
  sub.set_size(bw.size(0), bw.size(1));
  i_loop_ub = bw.size(1);
  for (int i24{0}; i24 < i_loop_ub; i24++) {
    int j_loop_ub;
    j_loop_ub = bw.size(0);
    for (int i26{0}; i26 < j_loop_ub; i26++) {
      sub[i26 + (sub.size(0) * i24)] =
          ((bw[i26 + (bw.size(0) * i24)]) && (!m[i26 + (m.size(0) * i24)]));
    }
  }
  if (1 > sub.size(0)) {
    i25 = 1;
    i27 = 0;
  } else {
    i25 = 2;
    i27 = sub.size(0);
  }
  if (2 > sub.size(1)) {
    i28 = 0;
    i29 = 1;
    i30 = 0;
  } else {
    i28 = 1;
    i29 = 2;
    i30 = sub.size(1);
  }
  if (1 > bw.size(0)) {
    i31 = 1;
  } else {
    i31 = 2;
  }
  if (2 > bw.size(1)) {
    i32 = 0;
    i33 = 1;
  } else {
    i32 = 1;
    i33 = 2;
  }
  k_loop_ub = div_s32_floor((i30 - i28) - 1, i29);
  for (int i34{0}; i34 <= k_loop_ub; i34++) {
    int m_loop_ub;
    m_loop_ub = div_s32_floor(i27 - 1, i25);
    for (int i35{0}; i35 <= m_loop_ub; i35++) {
      bw[(i31 * i35) + (bw.size(0) * (i32 + (i33 * i34)))] =
          sub[(i25 * i35) + (sub.size(0) * (i28 + (i29 * i34)))];
    }
  }
  bwlookup(bw, m);
  sub.set_size(bw.size(0), bw.size(1));
  o_loop_ub = bw.size(1);
  for (int i36{0}; i36 < o_loop_ub; i36++) {
    int p_loop_ub;
    p_loop_ub = bw.size(0);
    for (int i38{0}; i38 < p_loop_ub; i38++) {
      sub[i38 + (sub.size(0) * i36)] =
          ((bw[i38 + (bw.size(0) * i36)]) && (!m[i38 + (m.size(0) * i36)]));
    }
  }
  if (2 > sub.size(0)) {
    i37 = 0;
    i39 = 1;
    i40 = 0;
  } else {
    i37 = 1;
    i39 = 2;
    i40 = sub.size(0);
  }
  if (1 > sub.size(1)) {
    i41 = 1;
    i42 = 0;
  } else {
    i41 = 2;
    i42 = sub.size(1);
  }
  if (2 > bw.size(0)) {
    i43 = 0;
    i44 = 1;
  } else {
    i43 = 1;
    i44 = 2;
  }
  if (1 > bw.size(1)) {
    i45 = 1;
  } else {
    i45 = 2;
  }
  q_loop_ub = div_s32_floor(i42 - 1, i41);
  for (int i46{0}; i46 <= q_loop_ub; i46++) {
    int r_loop_ub;
    r_loop_ub = div_s32_floor((i40 - i37) - 1, i39);
    for (int i47{0}; i47 <= r_loop_ub; i47++) {
      bw[(i43 + (i44 * i47)) + (bw.size(0) * (i45 * i46))] =
          sub[(i37 + (i39 * i47)) + (sub.size(0) * (i41 * i46))];
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
