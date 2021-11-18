//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// algbwmorph.cpp
//
// Code generation for function 'algbwmorph'
//

// Include files
#include "algbwmorph.h"
#include "calibrateCamera_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "libmwbwlookup_tbb.h"

// Variable Definitions
static emlrtRSInfo ne_emlrtRSI{
    230,                // lineNo
    "bwmorphApplyOnce", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

static emlrtRSInfo oe_emlrtRSI{
    235,                // lineNo
    "bwmorphApplyOnce", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

static emlrtRSInfo pe_emlrtRSI{
    240,                // lineNo
    "bwmorphApplyOnce", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

static emlrtRSInfo qe_emlrtRSI{
    245,                // lineNo
    "bwmorphApplyOnce", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

static emlrtECInfo sd_emlrtECI{
    -1,                 // nDims
    247,                // lineNo
    9,                  // colNo
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtBCInfo ju_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    247,                // lineNo
    24,                 // colNo
    "",                 // aName
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m", // pName
    0                         // checkKind
};

static emlrtBCInfo ku_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    247,                // lineNo
    20,                 // colNo
    "",                 // aName
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m", // pName
    0                         // checkKind
};

static emlrtBCInfo lu_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    247,                // lineNo
    16,                 // colNo
    "",                 // aName
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m", // pName
    0                         // checkKind
};

static emlrtBCInfo mu_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    247,                // lineNo
    12,                 // colNo
    "",                 // aName
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m", // pName
    0                         // checkKind
};

static emlrtECInfo td_emlrtECI{
    2,                  // nDims
    246,                // lineNo
    15,                 // colNo
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtECInfo ud_emlrtECI{
    -1,                 // nDims
    242,                // lineNo
    9,                  // colNo
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtBCInfo nu_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    242,                // lineNo
    24,                 // colNo
    "",                 // aName
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m", // pName
    0                         // checkKind
};

static emlrtBCInfo ou_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    242,                // lineNo
    20,                 // colNo
    "",                 // aName
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m", // pName
    0                         // checkKind
};

static emlrtBCInfo pu_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    242,                // lineNo
    16,                 // colNo
    "",                 // aName
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m", // pName
    0                         // checkKind
};

static emlrtBCInfo qu_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    242,                // lineNo
    12,                 // colNo
    "",                 // aName
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m", // pName
    0                         // checkKind
};

static emlrtECInfo vd_emlrtECI{
    2,                  // nDims
    241,                // lineNo
    15,                 // colNo
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtECInfo wd_emlrtECI{
    -1,                 // nDims
    237,                // lineNo
    9,                  // colNo
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtBCInfo ru_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    237,                // lineNo
    24,                 // colNo
    "",                 // aName
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m", // pName
    0                         // checkKind
};

static emlrtBCInfo su_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    237,                // lineNo
    20,                 // colNo
    "",                 // aName
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m", // pName
    0                         // checkKind
};

static emlrtBCInfo tu_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    237,                // lineNo
    16,                 // colNo
    "",                 // aName
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m", // pName
    0                         // checkKind
};

static emlrtBCInfo uu_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    237,                // lineNo
    12,                 // colNo
    "",                 // aName
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m", // pName
    0                         // checkKind
};

static emlrtECInfo xd_emlrtECI{
    2,                  // nDims
    236,                // lineNo
    15,                 // colNo
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtECInfo yd_emlrtECI{
    -1,                 // nDims
    232,                // lineNo
    9,                  // colNo
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtBCInfo vu_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    232,                // lineNo
    24,                 // colNo
    "",                 // aName
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m", // pName
    0                         // checkKind
};

static emlrtBCInfo wu_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    232,                // lineNo
    20,                 // colNo
    "",                 // aName
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m", // pName
    0                         // checkKind
};

static emlrtBCInfo xu_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    232,                // lineNo
    16,                 // colNo
    "",                 // aName
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m", // pName
    0                         // checkKind
};

static emlrtBCInfo yu_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    232,                // lineNo
    12,                 // colNo
    "",                 // aName
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m", // pName
    0                         // checkKind
};

static emlrtECInfo ae_emlrtECI{
    2,                  // nDims
    231,                // lineNo
    15,                 // colNo
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo bs_emlrtRTEI{
    47,         // lineNo
    24,         // colNo
    "bwlookup", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\bwlookup.m" // pName
};

static emlrtRTEInfo cs_emlrtRTEI{
    231,          // lineNo
    9,            // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo ds_emlrtRTEI{
    236,          // lineNo
    9,            // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo es_emlrtRTEI{
    241,          // lineNo
    9,            // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo fs_emlrtRTEI{
    246,          // lineNo
    9,            // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRSInfo vab_emlrtRSI{
    247,                // lineNo
    "bwmorphApplyOnce", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

static emlrtRSInfo wab_emlrtRSI{
    242,                // lineNo
    "bwmorphApplyOnce", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

static emlrtRSInfo xab_emlrtRSI{
    237,                // lineNo
    "bwmorphApplyOnce", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

static emlrtRSInfo yab_emlrtRSI{
    232,                // lineNo
    "bwmorphApplyOnce", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

// Function Declarations
namespace Codegen {
static int32_T div_s32_floor(const emlrtStack *sp, int32_T numerator,
                             int32_T denominator);

}

// Function Definitions
namespace Codegen {
static int32_T div_s32_floor(const emlrtStack *sp, int32_T numerator,
                             int32_T denominator)
{
  int32_T quotient;
  if (denominator == 0) {
    emlrtDivisionByZeroErrorR2012b(nullptr, (emlrtCTX)sp);
  } else {
    uint32_T absDenominator;
    uint32_T absNumerator;
    uint32_T tempAbsQuotient;
    boolean_T quotientNeedsNegation;
    if (numerator < 0) {
      absNumerator = ~static_cast<uint32_T>(numerator) + 1U;
    } else {
      absNumerator = static_cast<uint32_T>(numerator);
    }
    if (denominator < 0) {
      absDenominator = ~static_cast<uint32_T>(denominator) + 1U;
    } else {
      absDenominator = static_cast<uint32_T>(denominator);
    }
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
      quotient = -static_cast<int32_T>(tempAbsQuotient);
    } else {
      quotient = static_cast<int32_T>(tempAbsQuotient);
    }
  }
  return quotient;
}

namespace coder {
namespace images {
namespace internal {
void bwmorphApplyOnce(const emlrtStack *sp, ::coder::array<boolean_T, 2U> &bw)
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
  ::coder::array<boolean_T, 2U> m;
  emlrtStack st;
  real_T sizeIn[2];
  int32_T iv[2];
  int32_T iv1[2];
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i10;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  int32_T i7;
  int32_T i8;
  int32_T i9;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &ne_emlrtRSI;
  m.set_size(&bs_emlrtRTEI, &st, bw.size(0), bw.size(1));
  if ((bw.size(0) != 0) && (bw.size(1) != 0)) {
    sizeIn[0] = bw.size(0);
    sizeIn[1] = bw.size(1);
    bwlookup_tbb_boolean(&bw[0], &sizeIn[0], 2.0, &lut[0], 512.0, &m[0]);
  }
  loop_ub = m.size(0) * m.size(1);
  for (i = 0; i < loop_ub; i++) {
    m[i] = !m[i];
  }
  iv[0] = (*(int32_T(*)[2])bw.size())[0];
  iv[1] = (*(int32_T(*)[2])bw.size())[1];
  iv1[0] = (*(int32_T(*)[2])m.size())[0];
  iv1[1] = (*(int32_T(*)[2])m.size())[1];
  emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &ae_emlrtECI, (emlrtCTX)sp);
  loop_ub = bw.size(0) * bw.size(1);
  m.set_size(&cs_emlrtRTEI, sp, bw.size(0), bw.size(1));
  for (i = 0; i < loop_ub; i++) {
    m[i] = (bw[i] && m[i]);
  }
  if (1 > m.size(0)) {
    i = 1;
    i1 = -1;
  } else {
    i = 2;
    i1 = m.size(0) - 1;
  }
  if (1 > m.size(1)) {
    i2 = 1;
    i3 = -1;
  } else {
    i2 = 2;
    i3 = m.size(1) - 1;
  }
  if (1 > bw.size(0)) {
    i4 = 1;
    i5 = 0;
  } else {
    i4 = bw.size(0);
    if (1 > i4) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i4, &yu_emlrtBCI, (emlrtCTX)sp);
    }
    i4 = 2;
    i6 = bw.size(0);
    i5 = bw.size(0);
    if ((i5 < 1) || (i5 > i6)) {
      emlrtDynamicBoundsCheckR2012b(i5, 1, i6, &xu_emlrtBCI, (emlrtCTX)sp);
    }
  }
  if (1 > bw.size(1)) {
    i6 = 1;
    i7 = 0;
  } else {
    i6 = bw.size(1);
    if (1 > i6) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i6, &wu_emlrtBCI, (emlrtCTX)sp);
    }
    i6 = 2;
    i8 = bw.size(1);
    i7 = bw.size(1);
    if ((i7 < 1) || (i7 > i8)) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, i8, &vu_emlrtBCI, (emlrtCTX)sp);
    }
  }
  st.site = &yab_emlrtRSI;
  iv[0] = div_s32_floor(&st, i5 - 1, i4) + 1;
  st.site = &yab_emlrtRSI;
  iv[1] = div_s32_floor(&st, i7 - 1, i6) + 1;
  st.site = &yab_emlrtRSI;
  loop_ub = div_s32_floor(&st, i1, i);
  iv1[0] = loop_ub + 1;
  st.site = &yab_emlrtRSI;
  b_loop_ub = div_s32_floor(&st, i3, i2);
  iv1[1] = b_loop_ub + 1;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &iv1[0], 2, &yd_emlrtECI,
                                (emlrtCTX)sp);
  for (i1 = 0; i1 <= b_loop_ub; i1++) {
    for (i3 = 0; i3 <= loop_ub; i3++) {
      bw[i4 * i3 + bw.size(0) * (i6 * i1)] = m[i * i3 + m.size(0) * (i2 * i1)];
    }
  }
  st.site = &oe_emlrtRSI;
  m.set_size(&bs_emlrtRTEI, &st, bw.size(0), bw.size(1));
  if ((bw.size(0) != 0) && (bw.size(1) != 0)) {
    sizeIn[0] = bw.size(0);
    sizeIn[1] = bw.size(1);
    bwlookup_tbb_boolean(&bw[0], &sizeIn[0], 2.0, &lut[0], 512.0, &m[0]);
  }
  loop_ub = m.size(0) * m.size(1);
  for (i = 0; i < loop_ub; i++) {
    m[i] = !m[i];
  }
  iv[0] = (*(int32_T(*)[2])bw.size())[0];
  iv[1] = (*(int32_T(*)[2])bw.size())[1];
  iv1[0] = (*(int32_T(*)[2])m.size())[0];
  iv1[1] = (*(int32_T(*)[2])m.size())[1];
  emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &xd_emlrtECI, (emlrtCTX)sp);
  loop_ub = bw.size(0) * bw.size(1);
  m.set_size(&ds_emlrtRTEI, sp, bw.size(0), bw.size(1));
  for (i = 0; i < loop_ub; i++) {
    m[i] = (bw[i] && m[i]);
  }
  if (2 > m.size(0)) {
    i = 0;
    i1 = 1;
    i2 = -1;
  } else {
    i = 1;
    i1 = 2;
    i2 = m.size(0) - 1;
  }
  if (2 > m.size(1)) {
    i3 = 0;
    i4 = 1;
    i6 = -1;
  } else {
    i3 = 1;
    i4 = 2;
    i6 = m.size(1) - 1;
  }
  if (2 > bw.size(0)) {
    i5 = 1;
    i8 = 1;
    loop_ub = 0;
  } else {
    i5 = bw.size(0);
    if (2 > i5) {
      emlrtDynamicBoundsCheckR2012b(2, 1, i5, &uu_emlrtBCI, (emlrtCTX)sp);
    }
    i5 = 2;
    i8 = 2;
    i7 = bw.size(0);
    loop_ub = bw.size(0);
    if ((loop_ub < 1) || (loop_ub > i7)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, &tu_emlrtBCI, (emlrtCTX)sp);
    }
  }
  if (2 > bw.size(1)) {
    i7 = 1;
    i9 = 1;
    i10 = 0;
  } else {
    i7 = bw.size(1);
    if (2 > i7) {
      emlrtDynamicBoundsCheckR2012b(2, 1, i7, &su_emlrtBCI, (emlrtCTX)sp);
    }
    i7 = 2;
    i9 = 2;
    b_loop_ub = bw.size(1);
    i10 = bw.size(1);
    if ((i10 < 1) || (i10 > b_loop_ub)) {
      emlrtDynamicBoundsCheckR2012b(i10, 1, b_loop_ub, &ru_emlrtBCI,
                                    (emlrtCTX)sp);
    }
  }
  st.site = &xab_emlrtRSI;
  iv[0] = div_s32_floor(&st, loop_ub - i5, i8) + 1;
  st.site = &xab_emlrtRSI;
  iv[1] = div_s32_floor(&st, i10 - i7, i9) + 1;
  st.site = &xab_emlrtRSI;
  loop_ub = div_s32_floor(&st, i2 - i, i1);
  iv1[0] = loop_ub + 1;
  st.site = &xab_emlrtRSI;
  b_loop_ub = div_s32_floor(&st, i6 - i3, i4);
  iv1[1] = b_loop_ub + 1;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &iv1[0], 2, &wd_emlrtECI,
                                (emlrtCTX)sp);
  for (i2 = 0; i2 <= b_loop_ub; i2++) {
    for (i6 = 0; i6 <= loop_ub; i6++) {
      bw[((i5 + i8 * i6) + bw.size(0) * ((i7 + i9 * i2) - 1)) - 1] =
          m[(i + i1 * i6) + m.size(0) * (i3 + i4 * i2)];
    }
  }
  st.site = &pe_emlrtRSI;
  m.set_size(&bs_emlrtRTEI, &st, bw.size(0), bw.size(1));
  if ((bw.size(0) != 0) && (bw.size(1) != 0)) {
    sizeIn[0] = bw.size(0);
    sizeIn[1] = bw.size(1);
    bwlookup_tbb_boolean(&bw[0], &sizeIn[0], 2.0, &lut[0], 512.0, &m[0]);
  }
  loop_ub = m.size(0) * m.size(1);
  for (i = 0; i < loop_ub; i++) {
    m[i] = !m[i];
  }
  iv[0] = (*(int32_T(*)[2])bw.size())[0];
  iv[1] = (*(int32_T(*)[2])bw.size())[1];
  iv1[0] = (*(int32_T(*)[2])m.size())[0];
  iv1[1] = (*(int32_T(*)[2])m.size())[1];
  emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &vd_emlrtECI, (emlrtCTX)sp);
  loop_ub = bw.size(0) * bw.size(1);
  m.set_size(&es_emlrtRTEI, sp, bw.size(0), bw.size(1));
  for (i = 0; i < loop_ub; i++) {
    m[i] = (bw[i] && m[i]);
  }
  if (1 > m.size(0)) {
    i = 1;
    i1 = -1;
  } else {
    i = 2;
    i1 = m.size(0) - 1;
  }
  if (2 > m.size(1)) {
    i2 = 0;
    i3 = 1;
    i4 = -1;
  } else {
    i2 = 1;
    i3 = 2;
    i4 = m.size(1) - 1;
  }
  if (1 > bw.size(0)) {
    i6 = 1;
    i8 = 0;
  } else {
    i6 = bw.size(0);
    if (1 > i6) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i6, &qu_emlrtBCI, (emlrtCTX)sp);
    }
    i6 = 2;
    i5 = bw.size(0);
    i8 = bw.size(0);
    if ((i8 < 1) || (i8 > i5)) {
      emlrtDynamicBoundsCheckR2012b(i8, 1, i5, &pu_emlrtBCI, (emlrtCTX)sp);
    }
  }
  if (2 > bw.size(1)) {
    i5 = 1;
    i7 = 1;
    i9 = 0;
  } else {
    i5 = bw.size(1);
    if (2 > i5) {
      emlrtDynamicBoundsCheckR2012b(2, 1, i5, &ou_emlrtBCI, (emlrtCTX)sp);
    }
    i5 = 2;
    i7 = 2;
    loop_ub = bw.size(1);
    i9 = bw.size(1);
    if ((i9 < 1) || (i9 > loop_ub)) {
      emlrtDynamicBoundsCheckR2012b(i9, 1, loop_ub, &nu_emlrtBCI, (emlrtCTX)sp);
    }
  }
  st.site = &wab_emlrtRSI;
  iv[0] = div_s32_floor(&st, i8 - 1, i6) + 1;
  st.site = &wab_emlrtRSI;
  iv[1] = div_s32_floor(&st, i9 - i5, i7) + 1;
  st.site = &wab_emlrtRSI;
  loop_ub = div_s32_floor(&st, i1, i);
  iv1[0] = loop_ub + 1;
  st.site = &wab_emlrtRSI;
  b_loop_ub = div_s32_floor(&st, i4 - i2, i3);
  iv1[1] = b_loop_ub + 1;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &iv1[0], 2, &ud_emlrtECI,
                                (emlrtCTX)sp);
  for (i1 = 0; i1 <= b_loop_ub; i1++) {
    for (i4 = 0; i4 <= loop_ub; i4++) {
      bw[i6 * i4 + bw.size(0) * ((i5 + i7 * i1) - 1)] =
          m[i * i4 + m.size(0) * (i2 + i3 * i1)];
    }
  }
  st.site = &qe_emlrtRSI;
  m.set_size(&bs_emlrtRTEI, &st, bw.size(0), bw.size(1));
  if ((bw.size(0) != 0) && (bw.size(1) != 0)) {
    sizeIn[0] = bw.size(0);
    sizeIn[1] = bw.size(1);
    bwlookup_tbb_boolean(&bw[0], &sizeIn[0], 2.0, &lut[0], 512.0, &m[0]);
  }
  loop_ub = m.size(0) * m.size(1);
  for (i = 0; i < loop_ub; i++) {
    m[i] = !m[i];
  }
  iv[0] = (*(int32_T(*)[2])bw.size())[0];
  iv[1] = (*(int32_T(*)[2])bw.size())[1];
  iv1[0] = (*(int32_T(*)[2])m.size())[0];
  iv1[1] = (*(int32_T(*)[2])m.size())[1];
  emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &td_emlrtECI, (emlrtCTX)sp);
  loop_ub = bw.size(0) * bw.size(1);
  m.set_size(&fs_emlrtRTEI, sp, bw.size(0), bw.size(1));
  for (i = 0; i < loop_ub; i++) {
    m[i] = (bw[i] && m[i]);
  }
  if (2 > m.size(0)) {
    i = 0;
    i1 = 1;
    i2 = -1;
  } else {
    i = 1;
    i1 = 2;
    i2 = m.size(0) - 1;
  }
  if (1 > m.size(1)) {
    i3 = 1;
    i4 = -1;
  } else {
    i3 = 2;
    i4 = m.size(1) - 1;
  }
  if (2 > bw.size(0)) {
    i6 = 1;
    i5 = 1;
    i7 = 0;
  } else {
    i6 = bw.size(0);
    if (2 > i6) {
      emlrtDynamicBoundsCheckR2012b(2, 1, i6, &mu_emlrtBCI, (emlrtCTX)sp);
    }
    i6 = 2;
    i5 = 2;
    i8 = bw.size(0);
    i7 = bw.size(0);
    if ((i7 < 1) || (i7 > i8)) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, i8, &lu_emlrtBCI, (emlrtCTX)sp);
    }
  }
  if (1 > bw.size(1)) {
    i8 = 1;
    i9 = 0;
  } else {
    i8 = bw.size(1);
    if (1 > i8) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i8, &ku_emlrtBCI, (emlrtCTX)sp);
    }
    i8 = 2;
    loop_ub = bw.size(1);
    i9 = bw.size(1);
    if ((i9 < 1) || (i9 > loop_ub)) {
      emlrtDynamicBoundsCheckR2012b(i9, 1, loop_ub, &ju_emlrtBCI, (emlrtCTX)sp);
    }
  }
  st.site = &vab_emlrtRSI;
  iv[0] = div_s32_floor(&st, i7 - i6, i5) + 1;
  st.site = &vab_emlrtRSI;
  iv[1] = div_s32_floor(&st, i9 - 1, i8) + 1;
  st.site = &vab_emlrtRSI;
  loop_ub = div_s32_floor(&st, i2 - i, i1);
  iv1[0] = loop_ub + 1;
  st.site = &vab_emlrtRSI;
  b_loop_ub = div_s32_floor(&st, i4, i3);
  iv1[1] = b_loop_ub + 1;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &iv1[0], 2, &sd_emlrtECI,
                                (emlrtCTX)sp);
  for (i2 = 0; i2 <= b_loop_ub; i2++) {
    for (i4 = 0; i4 <= loop_ub; i4++) {
      bw[((i6 + i5 * i4) + bw.size(0) * (i8 * i2)) - 1] =
          m[(i + i1 * i4) + m.size(0) * (i3 * i2)];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace internal
} // namespace images
} // namespace coder
} // namespace Codegen

// End of code generation (algbwmorph.cpp)
