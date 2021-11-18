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
#include "ComputeCamExtrinsics_mex_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "libmwbwlookup_tbb.h"

// Variable Definitions
static emlrtRSInfo gf_emlrtRSI{
    230,                // lineNo
    "bwmorphApplyOnce", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

static emlrtRSInfo hf_emlrtRSI{
    235,                // lineNo
    "bwmorphApplyOnce", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

static emlrtRSInfo if_emlrtRSI{
    240,                // lineNo
    "bwmorphApplyOnce", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

static emlrtRSInfo jf_emlrtRSI{
    245,                // lineNo
    "bwmorphApplyOnce", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

static emlrtECInfo ud_emlrtECI{
    -1,                 // nDims
    247,                // lineNo
    9,                  // colNo
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtBCInfo ev_emlrtBCI{
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

static emlrtBCInfo fv_emlrtBCI{
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

static emlrtBCInfo gv_emlrtBCI{
    0,                  // iFirst
    MAX_int32_T,        // iLast
    247,                // lineNo
    24,                 // colNo
    "",                 // aName
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m", // pName
    0                         // checkKind
};

static emlrtBCInfo hv_emlrtBCI{
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

static emlrtBCInfo iv_emlrtBCI{
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

static emlrtBCInfo jv_emlrtBCI{
    0,                  // iFirst
    MAX_int32_T,        // iLast
    247,                // lineNo
    16,                 // colNo
    "",                 // aName
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m", // pName
    0                         // checkKind
};

static emlrtECInfo vd_emlrtECI{
    2,                  // nDims
    246,                // lineNo
    15,                 // colNo
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtECInfo wd_emlrtECI{
    -1,                 // nDims
    242,                // lineNo
    9,                  // colNo
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtBCInfo kv_emlrtBCI{
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

static emlrtBCInfo lv_emlrtBCI{
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

static emlrtBCInfo mv_emlrtBCI{
    0,                  // iFirst
    MAX_int32_T,        // iLast
    242,                // lineNo
    24,                 // colNo
    "",                 // aName
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m", // pName
    0                         // checkKind
};

static emlrtBCInfo nv_emlrtBCI{
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

static emlrtBCInfo ov_emlrtBCI{
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

static emlrtBCInfo pv_emlrtBCI{
    0,                  // iFirst
    MAX_int32_T,        // iLast
    242,                // lineNo
    16,                 // colNo
    "",                 // aName
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m", // pName
    0                         // checkKind
};

static emlrtECInfo xd_emlrtECI{
    2,                  // nDims
    241,                // lineNo
    15,                 // colNo
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtECInfo yd_emlrtECI{
    -1,                 // nDims
    237,                // lineNo
    9,                  // colNo
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtBCInfo qv_emlrtBCI{
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

static emlrtBCInfo rv_emlrtBCI{
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

static emlrtBCInfo sv_emlrtBCI{
    0,                  // iFirst
    MAX_int32_T,        // iLast
    237,                // lineNo
    24,                 // colNo
    "",                 // aName
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m", // pName
    0                         // checkKind
};

static emlrtBCInfo tv_emlrtBCI{
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

static emlrtBCInfo uv_emlrtBCI{
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

static emlrtBCInfo vv_emlrtBCI{
    0,                  // iFirst
    MAX_int32_T,        // iLast
    237,                // lineNo
    16,                 // colNo
    "",                 // aName
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m", // pName
    0                         // checkKind
};

static emlrtECInfo ae_emlrtECI{
    2,                  // nDims
    236,                // lineNo
    15,                 // colNo
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtECInfo be_emlrtECI{
    -1,                 // nDims
    232,                // lineNo
    9,                  // colNo
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtBCInfo wv_emlrtBCI{
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

static emlrtBCInfo xv_emlrtBCI{
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

static emlrtBCInfo yv_emlrtBCI{
    0,                  // iFirst
    MAX_int32_T,        // iLast
    232,                // lineNo
    24,                 // colNo
    "",                 // aName
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m", // pName
    0                         // checkKind
};

static emlrtBCInfo aw_emlrtBCI{
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

static emlrtBCInfo bw_emlrtBCI{
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

static emlrtBCInfo cw_emlrtBCI{
    0,                  // iFirst
    MAX_int32_T,        // iLast
    232,                // lineNo
    16,                 // colNo
    "",                 // aName
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m", // pName
    0                         // checkKind
};

static emlrtECInfo ce_emlrtECI{
    2,                  // nDims
    231,                // lineNo
    15,                 // colNo
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtDCInfo rg_emlrtDCI{
    47,         // lineNo
    30,         // colNo
    "bwlookup", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\bwlookup.m", // pName
    4 // checkKind
};

static emlrtRTEInfo xu_emlrtRTEI{
    47,         // lineNo
    24,         // colNo
    "bwlookup", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\bwlookup.m" // pName
};

static emlrtRTEInfo yu_emlrtRTEI{
    231,          // lineNo
    9,            // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo av_emlrtRTEI{
    232,          // lineNo
    12,           // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo bv_emlrtRTEI{
    232,          // lineNo
    20,           // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo cv_emlrtRTEI{
    236,          // lineNo
    9,            // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo dv_emlrtRTEI{
    237,          // lineNo
    12,           // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo ev_emlrtRTEI{
    237,          // lineNo
    20,           // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo fv_emlrtRTEI{
    241,          // lineNo
    9,            // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo gv_emlrtRTEI{
    242,          // lineNo
    12,           // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo hv_emlrtRTEI{
    242,          // lineNo
    20,           // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo iv_emlrtRTEI{
    246,          // lineNo
    9,            // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo jv_emlrtRTEI{
    247,          // lineNo
    12,           // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo kv_emlrtRTEI{
    247,          // lineNo
    20,           // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRSInfo beb_emlrtRSI{
    247,                // lineNo
    "bwmorphApplyOnce", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

static emlrtRSInfo ceb_emlrtRSI{
    242,                // lineNo
    "bwmorphApplyOnce", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

static emlrtRSInfo deb_emlrtRSI{
    237,                // lineNo
    "bwmorphApplyOnce", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

static emlrtRSInfo eeb_emlrtRSI{
    232,                // lineNo
    "bwmorphApplyOnce", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

// Function Declarations
static int32_T div_s32_floor(const emlrtStack *sp, int32_T numerator,
                             int32_T denominator);

// Function Definitions
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
  array<int32_T, 1U> r;
  array<int32_T, 1U> r1;
  array<boolean_T, 2U> m;
  emlrtStack st;
  real_T sizeIn[2];
  int32_T b_iv[2];
  int32_T iv1[2];
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i10;
  int32_T i11;
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
  st.site = &gf_emlrtRSI;
  i = bw.size(0);
  if (i < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &rg_emlrtDCI, &st);
  }
  i1 = bw.size(1);
  if (i1 < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i1), &rg_emlrtDCI, &st);
  }
  m.set_size(&xu_emlrtRTEI, &st, i, i1);
  if ((bw.size(0) != 0) && (bw.size(1) != 0)) {
    sizeIn[0] = bw.size(0);
    sizeIn[1] = bw.size(1);
    bwlookup_tbb_boolean(&bw[0], &sizeIn[0], 2.0, &lut[0], 512.0, &m[0]);
  }
  loop_ub = m.size(0) * m.size(1);
  for (i = 0; i < loop_ub; i++) {
    m[i] = !m[i];
  }
  b_iv[0] = (*(int32_T(*)[2])bw.size())[0];
  b_iv[1] = (*(int32_T(*)[2])bw.size())[1];
  iv1[0] = (*(int32_T(*)[2])m.size())[0];
  iv1[1] = (*(int32_T(*)[2])m.size())[1];
  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &ce_emlrtECI, (emlrtCTX)sp);
  loop_ub = bw.size(0) * bw.size(1);
  m.set_size(&yu_emlrtRTEI, sp, bw.size(0), bw.size(1));
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
  i4 = bw.size(0);
  if (i4 < 0) {
    emlrtDynamicBoundsCheckR2012b(i4, 0, MAX_int32_T, &cw_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (1 > bw.size(0)) {
    i4 = 1;
    i5 = -1;
  } else {
    i4 = bw.size(0);
    if (1 > i4) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i4, &bw_emlrtBCI, (emlrtCTX)sp);
    }
    i4 = 2;
    i5 = bw.size(0);
    i6 = bw.size(0);
    if ((i6 < 1) || (i6 > i5)) {
      emlrtDynamicBoundsCheckR2012b(i6, 1, i5, &aw_emlrtBCI, (emlrtCTX)sp);
    }
    i5 = i6 - 1;
  }
  i6 = bw.size(1);
  if (i6 < 0) {
    emlrtDynamicBoundsCheckR2012b(i6, 0, MAX_int32_T, &yv_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (1 > bw.size(1)) {
    i6 = 1;
    i7 = -1;
  } else {
    i6 = bw.size(1);
    if (1 > i6) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i6, &xv_emlrtBCI, (emlrtCTX)sp);
    }
    i6 = 2;
    i7 = bw.size(1);
    i8 = bw.size(1);
    if ((i8 < 1) || (i8 > i7)) {
      emlrtDynamicBoundsCheckR2012b(i8, 1, i7, &wv_emlrtBCI, (emlrtCTX)sp);
    }
    i7 = i8 - 1;
  }
  st.site = &eeb_emlrtRSI;
  loop_ub = div_s32_floor(&st, i5, i4);
  r.set_size(&av_emlrtRTEI, sp, loop_ub + 1);
  for (i5 = 0; i5 <= loop_ub; i5++) {
    r[i5] = i4 * i5;
  }
  st.site = &eeb_emlrtRSI;
  loop_ub = div_s32_floor(&st, i7, i6);
  r1.set_size(&bv_emlrtRTEI, sp, loop_ub + 1);
  for (i4 = 0; i4 <= loop_ub; i4++) {
    r1[i4] = i6 * i4;
  }
  b_iv[0] = r.size(0);
  b_iv[1] = r1.size(0);
  st.site = &eeb_emlrtRSI;
  loop_ub = div_s32_floor(&st, i1, i);
  iv1[0] = loop_ub + 1;
  st.site = &eeb_emlrtRSI;
  b_loop_ub = div_s32_floor(&st, i3, i2);
  iv1[1] = b_loop_ub + 1;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &iv1[0], 2, &be_emlrtECI,
                                (emlrtCTX)sp);
  for (i1 = 0; i1 <= b_loop_ub; i1++) {
    for (i3 = 0; i3 <= loop_ub; i3++) {
      bw[r[i3] + bw.size(0) * r1[i1]] = m[i * i3 + m.size(0) * (i2 * i1)];
    }
  }
  st.site = &hf_emlrtRSI;
  i = bw.size(0);
  if (i < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &rg_emlrtDCI, &st);
  }
  i1 = bw.size(1);
  if (i1 < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i1), &rg_emlrtDCI, &st);
  }
  m.set_size(&xu_emlrtRTEI, &st, i, i1);
  if ((bw.size(0) != 0) && (bw.size(1) != 0)) {
    sizeIn[0] = bw.size(0);
    sizeIn[1] = bw.size(1);
    bwlookup_tbb_boolean(&bw[0], &sizeIn[0], 2.0, &lut[0], 512.0, &m[0]);
  }
  loop_ub = m.size(0) * m.size(1);
  for (i = 0; i < loop_ub; i++) {
    m[i] = !m[i];
  }
  b_iv[0] = (*(int32_T(*)[2])bw.size())[0];
  b_iv[1] = (*(int32_T(*)[2])bw.size())[1];
  iv1[0] = (*(int32_T(*)[2])m.size())[0];
  iv1[1] = (*(int32_T(*)[2])m.size())[1];
  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &ae_emlrtECI, (emlrtCTX)sp);
  loop_ub = bw.size(0) * bw.size(1);
  m.set_size(&cv_emlrtRTEI, sp, bw.size(0), bw.size(1));
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
    i5 = -1;
  } else {
    i3 = 1;
    i4 = 2;
    i5 = m.size(1) - 1;
  }
  i6 = bw.size(0);
  if (i6 < 0) {
    emlrtDynamicBoundsCheckR2012b(i6, 0, MAX_int32_T, &vv_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (2 > bw.size(0)) {
    i6 = 0;
    i7 = 1;
    i8 = -1;
  } else {
    i6 = bw.size(0);
    if (2 > i6) {
      emlrtDynamicBoundsCheckR2012b(2, 1, i6, &uv_emlrtBCI, (emlrtCTX)sp);
    }
    i6 = 1;
    i7 = 2;
    i8 = bw.size(0);
    i9 = bw.size(0);
    if ((i9 < 1) || (i9 > i8)) {
      emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &tv_emlrtBCI, (emlrtCTX)sp);
    }
    i8 = i9 - 1;
  }
  i9 = bw.size(1);
  if (i9 < 0) {
    emlrtDynamicBoundsCheckR2012b(i9, 0, MAX_int32_T, &sv_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (2 > bw.size(1)) {
    i9 = 0;
    i10 = 1;
    i11 = -1;
  } else {
    i9 = bw.size(1);
    if (2 > i9) {
      emlrtDynamicBoundsCheckR2012b(2, 1, i9, &rv_emlrtBCI, (emlrtCTX)sp);
    }
    i9 = 1;
    i10 = 2;
    i11 = bw.size(1);
    b_loop_ub = bw.size(1);
    if ((b_loop_ub < 1) || (b_loop_ub > i11)) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i11, &qv_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i11 = b_loop_ub - 1;
  }
  st.site = &deb_emlrtRSI;
  loop_ub = div_s32_floor(&st, i8 - i6, i7);
  r.set_size(&dv_emlrtRTEI, sp, loop_ub + 1);
  for (i8 = 0; i8 <= loop_ub; i8++) {
    r[i8] = i6 + i7 * i8;
  }
  st.site = &deb_emlrtRSI;
  loop_ub = div_s32_floor(&st, i11 - i9, i10);
  r1.set_size(&ev_emlrtRTEI, sp, loop_ub + 1);
  for (i6 = 0; i6 <= loop_ub; i6++) {
    r1[i6] = i9 + i10 * i6;
  }
  b_iv[0] = r.size(0);
  b_iv[1] = r1.size(0);
  st.site = &deb_emlrtRSI;
  loop_ub = div_s32_floor(&st, i2 - i, i1);
  iv1[0] = loop_ub + 1;
  st.site = &deb_emlrtRSI;
  b_loop_ub = div_s32_floor(&st, i5 - i3, i4);
  iv1[1] = b_loop_ub + 1;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &iv1[0], 2, &yd_emlrtECI,
                                (emlrtCTX)sp);
  for (i2 = 0; i2 <= b_loop_ub; i2++) {
    for (i5 = 0; i5 <= loop_ub; i5++) {
      bw[r[i5] + bw.size(0) * r1[i2]] =
          m[(i + i1 * i5) + m.size(0) * (i3 + i4 * i2)];
    }
  }
  st.site = &if_emlrtRSI;
  i = bw.size(0);
  if (i < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &rg_emlrtDCI, &st);
  }
  i1 = bw.size(1);
  if (i1 < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i1), &rg_emlrtDCI, &st);
  }
  m.set_size(&xu_emlrtRTEI, &st, i, i1);
  if ((bw.size(0) != 0) && (bw.size(1) != 0)) {
    sizeIn[0] = bw.size(0);
    sizeIn[1] = bw.size(1);
    bwlookup_tbb_boolean(&bw[0], &sizeIn[0], 2.0, &lut[0], 512.0, &m[0]);
  }
  loop_ub = m.size(0) * m.size(1);
  for (i = 0; i < loop_ub; i++) {
    m[i] = !m[i];
  }
  b_iv[0] = (*(int32_T(*)[2])bw.size())[0];
  b_iv[1] = (*(int32_T(*)[2])bw.size())[1];
  iv1[0] = (*(int32_T(*)[2])m.size())[0];
  iv1[1] = (*(int32_T(*)[2])m.size())[1];
  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &xd_emlrtECI, (emlrtCTX)sp);
  loop_ub = bw.size(0) * bw.size(1);
  m.set_size(&fv_emlrtRTEI, sp, bw.size(0), bw.size(1));
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
  i5 = bw.size(0);
  if (i5 < 0) {
    emlrtDynamicBoundsCheckR2012b(i5, 0, MAX_int32_T, &pv_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (1 > bw.size(0)) {
    i5 = 1;
    i6 = -1;
  } else {
    i5 = bw.size(0);
    if (1 > i5) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i5, &ov_emlrtBCI, (emlrtCTX)sp);
    }
    i5 = 2;
    i6 = bw.size(0);
    i7 = bw.size(0);
    if ((i7 < 1) || (i7 > i6)) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &nv_emlrtBCI, (emlrtCTX)sp);
    }
    i6 = i7 - 1;
  }
  i7 = bw.size(1);
  if (i7 < 0) {
    emlrtDynamicBoundsCheckR2012b(i7, 0, MAX_int32_T, &mv_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (2 > bw.size(1)) {
    i7 = 0;
    i8 = 1;
    i9 = -1;
  } else {
    i7 = bw.size(1);
    if (2 > i7) {
      emlrtDynamicBoundsCheckR2012b(2, 1, i7, &lv_emlrtBCI, (emlrtCTX)sp);
    }
    i7 = 1;
    i8 = 2;
    i9 = bw.size(1);
    i10 = bw.size(1);
    if ((i10 < 1) || (i10 > i9)) {
      emlrtDynamicBoundsCheckR2012b(i10, 1, i9, &kv_emlrtBCI, (emlrtCTX)sp);
    }
    i9 = i10 - 1;
  }
  st.site = &ceb_emlrtRSI;
  loop_ub = div_s32_floor(&st, i6, i5);
  r.set_size(&gv_emlrtRTEI, sp, loop_ub + 1);
  for (i6 = 0; i6 <= loop_ub; i6++) {
    r[i6] = i5 * i6;
  }
  st.site = &ceb_emlrtRSI;
  loop_ub = div_s32_floor(&st, i9 - i7, i8);
  r1.set_size(&hv_emlrtRTEI, sp, loop_ub + 1);
  for (i5 = 0; i5 <= loop_ub; i5++) {
    r1[i5] = i7 + i8 * i5;
  }
  b_iv[0] = r.size(0);
  b_iv[1] = r1.size(0);
  st.site = &ceb_emlrtRSI;
  loop_ub = div_s32_floor(&st, i1, i);
  iv1[0] = loop_ub + 1;
  st.site = &ceb_emlrtRSI;
  b_loop_ub = div_s32_floor(&st, i4 - i2, i3);
  iv1[1] = b_loop_ub + 1;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &iv1[0], 2, &wd_emlrtECI,
                                (emlrtCTX)sp);
  for (i1 = 0; i1 <= b_loop_ub; i1++) {
    for (i4 = 0; i4 <= loop_ub; i4++) {
      bw[r[i4] + bw.size(0) * r1[i1]] = m[i * i4 + m.size(0) * (i2 + i3 * i1)];
    }
  }
  st.site = &jf_emlrtRSI;
  i = bw.size(0);
  if (i < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &rg_emlrtDCI, &st);
  }
  i1 = bw.size(1);
  if (i1 < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i1), &rg_emlrtDCI, &st);
  }
  m.set_size(&xu_emlrtRTEI, &st, i, i1);
  if ((bw.size(0) != 0) && (bw.size(1) != 0)) {
    sizeIn[0] = bw.size(0);
    sizeIn[1] = bw.size(1);
    bwlookup_tbb_boolean(&bw[0], &sizeIn[0], 2.0, &lut[0], 512.0, &m[0]);
  }
  loop_ub = m.size(0) * m.size(1);
  for (i = 0; i < loop_ub; i++) {
    m[i] = !m[i];
  }
  b_iv[0] = (*(int32_T(*)[2])bw.size())[0];
  b_iv[1] = (*(int32_T(*)[2])bw.size())[1];
  iv1[0] = (*(int32_T(*)[2])m.size())[0];
  iv1[1] = (*(int32_T(*)[2])m.size())[1];
  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &vd_emlrtECI, (emlrtCTX)sp);
  loop_ub = bw.size(0) * bw.size(1);
  m.set_size(&iv_emlrtRTEI, sp, bw.size(0), bw.size(1));
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
  i5 = bw.size(0);
  if (i5 < 0) {
    emlrtDynamicBoundsCheckR2012b(i5, 0, MAX_int32_T, &jv_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (2 > bw.size(0)) {
    i5 = 0;
    i6 = 1;
    i7 = -1;
  } else {
    i5 = bw.size(0);
    if (2 > i5) {
      emlrtDynamicBoundsCheckR2012b(2, 1, i5, &iv_emlrtBCI, (emlrtCTX)sp);
    }
    i5 = 1;
    i6 = 2;
    i7 = bw.size(0);
    i8 = bw.size(0);
    if ((i8 < 1) || (i8 > i7)) {
      emlrtDynamicBoundsCheckR2012b(i8, 1, i7, &hv_emlrtBCI, (emlrtCTX)sp);
    }
    i7 = i8 - 1;
  }
  i8 = bw.size(1);
  if (i8 < 0) {
    emlrtDynamicBoundsCheckR2012b(i8, 0, MAX_int32_T, &gv_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (1 > bw.size(1)) {
    i8 = 1;
    i9 = -1;
  } else {
    i8 = bw.size(1);
    if (1 > i8) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i8, &fv_emlrtBCI, (emlrtCTX)sp);
    }
    i8 = 2;
    i9 = bw.size(1);
    i10 = bw.size(1);
    if ((i10 < 1) || (i10 > i9)) {
      emlrtDynamicBoundsCheckR2012b(i10, 1, i9, &ev_emlrtBCI, (emlrtCTX)sp);
    }
    i9 = i10 - 1;
  }
  st.site = &beb_emlrtRSI;
  loop_ub = div_s32_floor(&st, i7 - i5, i6);
  r.set_size(&jv_emlrtRTEI, sp, loop_ub + 1);
  for (i7 = 0; i7 <= loop_ub; i7++) {
    r[i7] = i5 + i6 * i7;
  }
  st.site = &beb_emlrtRSI;
  loop_ub = div_s32_floor(&st, i9, i8);
  r1.set_size(&kv_emlrtRTEI, sp, loop_ub + 1);
  for (i5 = 0; i5 <= loop_ub; i5++) {
    r1[i5] = i8 * i5;
  }
  b_iv[0] = r.size(0);
  b_iv[1] = r1.size(0);
  st.site = &beb_emlrtRSI;
  loop_ub = div_s32_floor(&st, i2 - i, i1);
  iv1[0] = loop_ub + 1;
  st.site = &beb_emlrtRSI;
  b_loop_ub = div_s32_floor(&st, i4, i3);
  iv1[1] = b_loop_ub + 1;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &iv1[0], 2, &ud_emlrtECI,
                                (emlrtCTX)sp);
  for (i2 = 0; i2 <= b_loop_ub; i2++) {
    for (i4 = 0; i4 <= loop_ub; i4++) {
      bw[r[i4] + bw.size(0) * r1[i2]] =
          m[(i + i1 * i4) + m.size(0) * (i3 * i2)];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace internal
} // namespace images
} // namespace coder

// End of code generation (algbwmorph.cpp)
