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
#include "calibrateOneCamera_v2_mex_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "libmwbwlookup_tbb.h"

// Variable Definitions
static emlrtRSInfo cf_emlrtRSI{
    230,                // lineNo
    "bwmorphApplyOnce", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

static emlrtRSInfo df_emlrtRSI{
    235,                // lineNo
    "bwmorphApplyOnce", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

static emlrtRSInfo ef_emlrtRSI{
    240,                // lineNo
    "bwmorphApplyOnce", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

static emlrtRSInfo ff_emlrtRSI{
    245,                // lineNo
    "bwmorphApplyOnce", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

static emlrtECInfo ee_emlrtECI{
    -1,                 // nDims
    247,                // lineNo
    9,                  // colNo
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtBCInfo gx_emlrtBCI{
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

static emlrtBCInfo hx_emlrtBCI{
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

static emlrtBCInfo ix_emlrtBCI{
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

static emlrtBCInfo jx_emlrtBCI{
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

static emlrtBCInfo kx_emlrtBCI{
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

static emlrtBCInfo lx_emlrtBCI{
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

static emlrtECInfo fe_emlrtECI{
    2,                  // nDims
    246,                // lineNo
    15,                 // colNo
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtECInfo ge_emlrtECI{
    -1,                 // nDims
    242,                // lineNo
    9,                  // colNo
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtBCInfo mx_emlrtBCI{
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

static emlrtBCInfo nx_emlrtBCI{
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

static emlrtBCInfo ox_emlrtBCI{
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

static emlrtBCInfo px_emlrtBCI{
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

static emlrtBCInfo qx_emlrtBCI{
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

static emlrtBCInfo rx_emlrtBCI{
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

static emlrtECInfo he_emlrtECI{
    2,                  // nDims
    241,                // lineNo
    15,                 // colNo
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtECInfo ie_emlrtECI{
    -1,                 // nDims
    237,                // lineNo
    9,                  // colNo
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtBCInfo sx_emlrtBCI{
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

static emlrtBCInfo tx_emlrtBCI{
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

static emlrtBCInfo ux_emlrtBCI{
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

static emlrtBCInfo vx_emlrtBCI{
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

static emlrtBCInfo wx_emlrtBCI{
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

static emlrtBCInfo xx_emlrtBCI{
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

static emlrtECInfo je_emlrtECI{
    2,                  // nDims
    236,                // lineNo
    15,                 // colNo
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtECInfo ke_emlrtECI{
    -1,                 // nDims
    232,                // lineNo
    9,                  // colNo
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtBCInfo yx_emlrtBCI{
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

static emlrtBCInfo ay_emlrtBCI{
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

static emlrtBCInfo by_emlrtBCI{
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

static emlrtBCInfo cy_emlrtBCI{
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

static emlrtBCInfo dy_emlrtBCI{
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

static emlrtBCInfo ey_emlrtBCI{
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

static emlrtECInfo le_emlrtECI{
    2,                  // nDims
    231,                // lineNo
    15,                 // colNo
    "bwmorphApplyOnce", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtDCInfo fh_emlrtDCI{
    47,         // lineNo
    30,         // colNo
    "bwlookup", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\bwlookup.m", // pName
    4 // checkKind
};

static emlrtRTEInfo cy_emlrtRTEI{
    47,         // lineNo
    24,         // colNo
    "bwlookup", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\bwlookup.m" // pName
};

static emlrtRTEInfo dy_emlrtRTEI{
    231,          // lineNo
    9,            // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo ey_emlrtRTEI{
    232,          // lineNo
    12,           // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo fy_emlrtRTEI{
    232,          // lineNo
    20,           // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo gy_emlrtRTEI{
    236,          // lineNo
    9,            // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo hy_emlrtRTEI{
    237,          // lineNo
    12,           // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo iy_emlrtRTEI{
    237,          // lineNo
    20,           // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo jy_emlrtRTEI{
    241,          // lineNo
    9,            // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo ky_emlrtRTEI{
    242,          // lineNo
    12,           // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo ly_emlrtRTEI{
    242,          // lineNo
    20,           // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo my_emlrtRTEI{
    246,          // lineNo
    9,            // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo ny_emlrtRTEI{
    247,          // lineNo
    12,           // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo oy_emlrtRTEI{
    247,          // lineNo
    20,           // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRSInfo gjb_emlrtRSI{
    247,                // lineNo
    "bwmorphApplyOnce", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

static emlrtRSInfo hjb_emlrtRSI{
    242,                // lineNo
    "bwmorphApplyOnce", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

static emlrtRSInfo ijb_emlrtRSI{
    237,                // lineNo
    "bwmorphApplyOnce", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

static emlrtRSInfo jjb_emlrtRSI{
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
  st.site = &cf_emlrtRSI;
  i = bw.size(0);
  if (i < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &fh_emlrtDCI, &st);
  }
  i1 = bw.size(1);
  if (i1 < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i1), &fh_emlrtDCI, &st);
  }
  m.set_size(&cy_emlrtRTEI, &st, i, i1);
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
  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &le_emlrtECI, (emlrtCTX)sp);
  loop_ub = bw.size(0) * bw.size(1);
  m.set_size(&dy_emlrtRTEI, sp, bw.size(0), bw.size(1));
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
    emlrtDynamicBoundsCheckR2012b(i4, 0, MAX_int32_T, &ey_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (1 > bw.size(0)) {
    i4 = 1;
    i5 = -1;
  } else {
    i4 = bw.size(0);
    if (1 > i4) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i4, &dy_emlrtBCI, (emlrtCTX)sp);
    }
    i4 = 2;
    i5 = bw.size(0);
    i6 = bw.size(0);
    if ((i6 < 1) || (i6 > i5)) {
      emlrtDynamicBoundsCheckR2012b(i6, 1, i5, &cy_emlrtBCI, (emlrtCTX)sp);
    }
    i5 = i6 - 1;
  }
  i6 = bw.size(1);
  if (i6 < 0) {
    emlrtDynamicBoundsCheckR2012b(i6, 0, MAX_int32_T, &by_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (1 > bw.size(1)) {
    i6 = 1;
    i7 = -1;
  } else {
    i6 = bw.size(1);
    if (1 > i6) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i6, &ay_emlrtBCI, (emlrtCTX)sp);
    }
    i6 = 2;
    i7 = bw.size(1);
    i8 = bw.size(1);
    if ((i8 < 1) || (i8 > i7)) {
      emlrtDynamicBoundsCheckR2012b(i8, 1, i7, &yx_emlrtBCI, (emlrtCTX)sp);
    }
    i7 = i8 - 1;
  }
  st.site = &jjb_emlrtRSI;
  loop_ub = div_s32_floor(&st, i5, i4);
  r.set_size(&ey_emlrtRTEI, sp, loop_ub + 1);
  for (i5 = 0; i5 <= loop_ub; i5++) {
    r[i5] = i4 * i5;
  }
  st.site = &jjb_emlrtRSI;
  loop_ub = div_s32_floor(&st, i7, i6);
  r1.set_size(&fy_emlrtRTEI, sp, loop_ub + 1);
  for (i4 = 0; i4 <= loop_ub; i4++) {
    r1[i4] = i6 * i4;
  }
  b_iv[0] = r.size(0);
  b_iv[1] = r1.size(0);
  st.site = &jjb_emlrtRSI;
  loop_ub = div_s32_floor(&st, i1, i);
  iv1[0] = loop_ub + 1;
  st.site = &jjb_emlrtRSI;
  b_loop_ub = div_s32_floor(&st, i3, i2);
  iv1[1] = b_loop_ub + 1;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &iv1[0], 2, &ke_emlrtECI,
                                (emlrtCTX)sp);
  for (i1 = 0; i1 <= b_loop_ub; i1++) {
    for (i3 = 0; i3 <= loop_ub; i3++) {
      bw[r[i3] + bw.size(0) * r1[i1]] = m[i * i3 + m.size(0) * (i2 * i1)];
    }
  }
  st.site = &df_emlrtRSI;
  i = bw.size(0);
  if (i < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &fh_emlrtDCI, &st);
  }
  i1 = bw.size(1);
  if (i1 < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i1), &fh_emlrtDCI, &st);
  }
  m.set_size(&cy_emlrtRTEI, &st, i, i1);
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
  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &je_emlrtECI, (emlrtCTX)sp);
  loop_ub = bw.size(0) * bw.size(1);
  m.set_size(&gy_emlrtRTEI, sp, bw.size(0), bw.size(1));
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
    emlrtDynamicBoundsCheckR2012b(i6, 0, MAX_int32_T, &xx_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (2 > bw.size(0)) {
    i6 = 0;
    i7 = 1;
    i8 = -1;
  } else {
    i6 = bw.size(0);
    if (2 > i6) {
      emlrtDynamicBoundsCheckR2012b(2, 1, i6, &wx_emlrtBCI, (emlrtCTX)sp);
    }
    i6 = 1;
    i7 = 2;
    i8 = bw.size(0);
    i9 = bw.size(0);
    if ((i9 < 1) || (i9 > i8)) {
      emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &vx_emlrtBCI, (emlrtCTX)sp);
    }
    i8 = i9 - 1;
  }
  i9 = bw.size(1);
  if (i9 < 0) {
    emlrtDynamicBoundsCheckR2012b(i9, 0, MAX_int32_T, &ux_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (2 > bw.size(1)) {
    i9 = 0;
    i10 = 1;
    i11 = -1;
  } else {
    i9 = bw.size(1);
    if (2 > i9) {
      emlrtDynamicBoundsCheckR2012b(2, 1, i9, &tx_emlrtBCI, (emlrtCTX)sp);
    }
    i9 = 1;
    i10 = 2;
    i11 = bw.size(1);
    b_loop_ub = bw.size(1);
    if ((b_loop_ub < 1) || (b_loop_ub > i11)) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i11, &sx_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i11 = b_loop_ub - 1;
  }
  st.site = &ijb_emlrtRSI;
  loop_ub = div_s32_floor(&st, i8 - i6, i7);
  r.set_size(&hy_emlrtRTEI, sp, loop_ub + 1);
  for (i8 = 0; i8 <= loop_ub; i8++) {
    r[i8] = i6 + i7 * i8;
  }
  st.site = &ijb_emlrtRSI;
  loop_ub = div_s32_floor(&st, i11 - i9, i10);
  r1.set_size(&iy_emlrtRTEI, sp, loop_ub + 1);
  for (i6 = 0; i6 <= loop_ub; i6++) {
    r1[i6] = i9 + i10 * i6;
  }
  b_iv[0] = r.size(0);
  b_iv[1] = r1.size(0);
  st.site = &ijb_emlrtRSI;
  loop_ub = div_s32_floor(&st, i2 - i, i1);
  iv1[0] = loop_ub + 1;
  st.site = &ijb_emlrtRSI;
  b_loop_ub = div_s32_floor(&st, i5 - i3, i4);
  iv1[1] = b_loop_ub + 1;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &iv1[0], 2, &ie_emlrtECI,
                                (emlrtCTX)sp);
  for (i2 = 0; i2 <= b_loop_ub; i2++) {
    for (i5 = 0; i5 <= loop_ub; i5++) {
      bw[r[i5] + bw.size(0) * r1[i2]] =
          m[(i + i1 * i5) + m.size(0) * (i3 + i4 * i2)];
    }
  }
  st.site = &ef_emlrtRSI;
  i = bw.size(0);
  if (i < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &fh_emlrtDCI, &st);
  }
  i1 = bw.size(1);
  if (i1 < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i1), &fh_emlrtDCI, &st);
  }
  m.set_size(&cy_emlrtRTEI, &st, i, i1);
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
  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &he_emlrtECI, (emlrtCTX)sp);
  loop_ub = bw.size(0) * bw.size(1);
  m.set_size(&jy_emlrtRTEI, sp, bw.size(0), bw.size(1));
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
    emlrtDynamicBoundsCheckR2012b(i5, 0, MAX_int32_T, &rx_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (1 > bw.size(0)) {
    i5 = 1;
    i6 = -1;
  } else {
    i5 = bw.size(0);
    if (1 > i5) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i5, &qx_emlrtBCI, (emlrtCTX)sp);
    }
    i5 = 2;
    i6 = bw.size(0);
    i7 = bw.size(0);
    if ((i7 < 1) || (i7 > i6)) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &px_emlrtBCI, (emlrtCTX)sp);
    }
    i6 = i7 - 1;
  }
  i7 = bw.size(1);
  if (i7 < 0) {
    emlrtDynamicBoundsCheckR2012b(i7, 0, MAX_int32_T, &ox_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (2 > bw.size(1)) {
    i7 = 0;
    i8 = 1;
    i9 = -1;
  } else {
    i7 = bw.size(1);
    if (2 > i7) {
      emlrtDynamicBoundsCheckR2012b(2, 1, i7, &nx_emlrtBCI, (emlrtCTX)sp);
    }
    i7 = 1;
    i8 = 2;
    i9 = bw.size(1);
    i10 = bw.size(1);
    if ((i10 < 1) || (i10 > i9)) {
      emlrtDynamicBoundsCheckR2012b(i10, 1, i9, &mx_emlrtBCI, (emlrtCTX)sp);
    }
    i9 = i10 - 1;
  }
  st.site = &hjb_emlrtRSI;
  loop_ub = div_s32_floor(&st, i6, i5);
  r.set_size(&ky_emlrtRTEI, sp, loop_ub + 1);
  for (i6 = 0; i6 <= loop_ub; i6++) {
    r[i6] = i5 * i6;
  }
  st.site = &hjb_emlrtRSI;
  loop_ub = div_s32_floor(&st, i9 - i7, i8);
  r1.set_size(&ly_emlrtRTEI, sp, loop_ub + 1);
  for (i5 = 0; i5 <= loop_ub; i5++) {
    r1[i5] = i7 + i8 * i5;
  }
  b_iv[0] = r.size(0);
  b_iv[1] = r1.size(0);
  st.site = &hjb_emlrtRSI;
  loop_ub = div_s32_floor(&st, i1, i);
  iv1[0] = loop_ub + 1;
  st.site = &hjb_emlrtRSI;
  b_loop_ub = div_s32_floor(&st, i4 - i2, i3);
  iv1[1] = b_loop_ub + 1;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &iv1[0], 2, &ge_emlrtECI,
                                (emlrtCTX)sp);
  for (i1 = 0; i1 <= b_loop_ub; i1++) {
    for (i4 = 0; i4 <= loop_ub; i4++) {
      bw[r[i4] + bw.size(0) * r1[i1]] = m[i * i4 + m.size(0) * (i2 + i3 * i1)];
    }
  }
  st.site = &ff_emlrtRSI;
  i = bw.size(0);
  if (i < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &fh_emlrtDCI, &st);
  }
  i1 = bw.size(1);
  if (i1 < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i1), &fh_emlrtDCI, &st);
  }
  m.set_size(&cy_emlrtRTEI, &st, i, i1);
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
  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &fe_emlrtECI, (emlrtCTX)sp);
  loop_ub = bw.size(0) * bw.size(1);
  m.set_size(&my_emlrtRTEI, sp, bw.size(0), bw.size(1));
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
    emlrtDynamicBoundsCheckR2012b(i5, 0, MAX_int32_T, &lx_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (2 > bw.size(0)) {
    i5 = 0;
    i6 = 1;
    i7 = -1;
  } else {
    i5 = bw.size(0);
    if (2 > i5) {
      emlrtDynamicBoundsCheckR2012b(2, 1, i5, &kx_emlrtBCI, (emlrtCTX)sp);
    }
    i5 = 1;
    i6 = 2;
    i7 = bw.size(0);
    i8 = bw.size(0);
    if ((i8 < 1) || (i8 > i7)) {
      emlrtDynamicBoundsCheckR2012b(i8, 1, i7, &jx_emlrtBCI, (emlrtCTX)sp);
    }
    i7 = i8 - 1;
  }
  i8 = bw.size(1);
  if (i8 < 0) {
    emlrtDynamicBoundsCheckR2012b(i8, 0, MAX_int32_T, &ix_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (1 > bw.size(1)) {
    i8 = 1;
    i9 = -1;
  } else {
    i8 = bw.size(1);
    if (1 > i8) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i8, &hx_emlrtBCI, (emlrtCTX)sp);
    }
    i8 = 2;
    i9 = bw.size(1);
    i10 = bw.size(1);
    if ((i10 < 1) || (i10 > i9)) {
      emlrtDynamicBoundsCheckR2012b(i10, 1, i9, &gx_emlrtBCI, (emlrtCTX)sp);
    }
    i9 = i10 - 1;
  }
  st.site = &gjb_emlrtRSI;
  loop_ub = div_s32_floor(&st, i7 - i5, i6);
  r.set_size(&ny_emlrtRTEI, sp, loop_ub + 1);
  for (i7 = 0; i7 <= loop_ub; i7++) {
    r[i7] = i5 + i6 * i7;
  }
  st.site = &gjb_emlrtRSI;
  loop_ub = div_s32_floor(&st, i9, i8);
  r1.set_size(&oy_emlrtRTEI, sp, loop_ub + 1);
  for (i5 = 0; i5 <= loop_ub; i5++) {
    r1[i5] = i8 * i5;
  }
  b_iv[0] = r.size(0);
  b_iv[1] = r1.size(0);
  st.site = &gjb_emlrtRSI;
  loop_ub = div_s32_floor(&st, i2 - i, i1);
  iv1[0] = loop_ub + 1;
  st.site = &gjb_emlrtRSI;
  b_loop_ub = div_s32_floor(&st, i4, i3);
  iv1[1] = b_loop_ub + 1;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &iv1[0], 2, &ee_emlrtECI,
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
