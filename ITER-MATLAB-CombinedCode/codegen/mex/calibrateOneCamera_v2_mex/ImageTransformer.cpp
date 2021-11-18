//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// ImageTransformer.cpp
//
// Code generation for function 'ImageTransformer'
//

// Include files
#include "ImageTransformer.h"
#include "assertValidSizeArg.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "colon.h"
#include "distortPoints.h"
#include "meshgrid.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "libmwimterp2d.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo
    shb_emlrtRSI{
        28,      // lineNo
        "colon", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" // pathName
    };

static emlrtRSInfo fib_emlrtRSI{
    89,                        // lineNo
    "ImageTransformer/update", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pathName
};

static emlrtRSInfo gib_emlrtRSI{
    124,                           // lineNo
    "ImageTransformer/computeMap", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pathName
};

static emlrtRSInfo hib_emlrtRSI{
    125,                           // lineNo
    "ImageTransformer/computeMap", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pathName
};

static emlrtRSInfo iib_emlrtRSI{
    126,                           // lineNo
    "ImageTransformer/computeMap", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pathName
};

static emlrtRSInfo jib_emlrtRSI{
    136,                           // lineNo
    "ImageTransformer/computeMap", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pathName
};

static emlrtRSInfo kib_emlrtRSI{
    158,                           // lineNo
    "ImageTransformer/computeMap", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pathName
};

static emlrtRSInfo lib_emlrtRSI{
    159,                           // lineNo
    "ImageTransformer/computeMap", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pathName
};

static emlrtRSInfo mib_emlrtRSI{
    161,                           // lineNo
    "ImageTransformer/computeMap", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pathName
};

static emlrtRSInfo nib_emlrtRSI{
    163,                           // lineNo
    "ImageTransformer/computeMap", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pathName
};

static emlrtRSInfo qib_emlrtRSI{
    18,                  // lineNo
    "reshapeSizeChecks", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" // pathName
};

static emlrtRSInfo rib_emlrtRSI{
    110,                               // lineNo
    "ImageTransformer/transformImage", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pathName
};

static emlrtRSInfo sib_emlrtRSI{
    32,         // lineNo
    "interp2d", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+internal\\+"
    "coder\\interp2d.m" // pathName
};

static emlrtRSInfo tib_emlrtRSI{
    34,         // lineNo
    "interp2d", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+internal\\+"
    "coder\\interp2d.m" // pathName
};

static emlrtRSInfo uib_emlrtRSI{
    82,         // lineNo
    "interp2d", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+internal\\+"
    "coder\\interp2d.m" // pathName
};

static emlrtRSInfo vib_emlrtRSI{
    98,         // lineNo
    "interp2d", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+internal\\+"
    "coder\\interp2d.m" // pathName
};

static emlrtRSInfo bjb_emlrtRSI{
    138,                   // lineNo
    "interpolate_imterp2", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+internal\\+"
    "coder\\interp2d.m" // pathName
};

static emlrtBCInfo xw_emlrtBCI{
    0,                            // iFirst
    MAX_int32_T,                  // iLast
    110,                          // lineNo
    30,                           // colNo
    "",                           // aName
    "Imterp2DBuildable/imterp2d", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+internal\\+"
    "coder\\+buildable\\Imterp2DBuildable.m", // pName
    0                                         // checkKind
};

static emlrtRTEInfo bd_emlrtRTEI{
    44,         // lineNo
    1,          // colNo
    "interp2d", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+internal\\+"
    "coder\\interp2d.m" // pName
};

static emlrtDCInfo ch_emlrtDCI{
    118,                   // lineNo
    37,                    // colNo
    "interpolate_imterp2", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+internal\\+"
    "coder\\interp2d.m", // pName
    4                    // checkKind
};

static emlrtRTEInfo yw_emlrtRTEI{
    79,                 // lineNo
    13,                 // colNo
    "ImageTransformer", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pName
};

static emlrtRTEInfo ax_emlrtRTEI{
    80,                 // lineNo
    13,                 // colNo
    "ImageTransformer", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pName
};

static emlrtRTEInfo bx_emlrtRTEI{
    81,                 // lineNo
    13,                 // colNo
    "ImageTransformer", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pName
};

static emlrtRTEInfo cx_emlrtRTEI{
    297,   // lineNo
    14,    // colNo
    "cat", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" // pName
};

static emlrtRTEInfo dx_emlrtRTEI{
    161,                // lineNo
    48,                 // colNo
    "ImageTransformer", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pName
};

static emlrtRTEInfo ex_emlrtRTEI{
    161,                // lineNo
    17,                 // colNo
    "ImageTransformer", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pName
};

static emlrtRTEInfo fx_emlrtRTEI{
    163,                // lineNo
    48,                 // colNo
    "ImageTransformer", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pName
};

static emlrtRTEInfo gx_emlrtRTEI{
    163,                // lineNo
    17,                 // colNo
    "ImageTransformer", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pName
};

static emlrtRTEInfo jx_emlrtRTEI{
    85,         // lineNo
    5,          // colNo
    "interp2d", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+internal\\+"
    "coder\\interp2d.m" // pName
};

static emlrtRTEInfo kx_emlrtRTEI{
    78,       // lineNo
    28,       // colNo
    "repmat", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" // pName
};

static emlrtRTEInfo lx_emlrtRTEI{
    118,        // lineNo
    30,         // colNo
    "interp2d", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+internal\\+"
    "coder\\interp2d.m" // pName
};

// Function Definitions
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
void b_ImageTransformer::transformImage(
    const emlrtStack *sp, const ::coder::array<uint8_T, 3U> &b_I,
    const ::coder::array<uint8_T, 3U> &fillValues,
    ::coder::array<uint8_T, 3U> &J, real_T newOrigin[2]) const
{
  array<uint8_T, 3U> fill;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T inputImageSize[3];
  real_T outputImageSize[3];
  real_T sizeVec[2];
  int32_T varargin_2[2];
  int32_T k;
  int32_T t;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &rib_emlrtRSI;
  b_st.site = &sib_emlrtRSI;
  c_st.site = &t_emlrtRSI;
  p = true;
  t = XmapSingle.size(0) * XmapSingle.size(1);
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= t - 1)) {
    if (!muSingleScalarIsNaN(XmapSingle[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &j_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:interp2d:expectedNonNaN", 3, 4, 1, "X");
  }
  b_st.site = &tib_emlrtRSI;
  c_st.site = &t_emlrtRSI;
  p = true;
  t = YmapSingle.size(0) * YmapSingle.size(1);
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= t - 1)) {
    if (!muSingleScalarIsNaN(YmapSingle[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &j_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:interp2d:expectedNonNaN", 3, 4, 1, "Y");
  }
  sizeVec[0] = XmapSingle.size(0);
  varargin_2[0] = YmapSingle.size(0);
  sizeVec[1] = XmapSingle.size(1);
  varargin_2[1] = YmapSingle.size(1);
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (static_cast<int32_T>(sizeVec[k]) != varargin_2[k]) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&st, &bd_emlrtRTEI,
                                  "images:interp2d:inconsistentXYSize",
                                  "images:interp2d:inconsistentXYSize", 0);
  }
  if (fillValues.size(2) == 1) {
    sizeVec[0] = b_I.size(2);
    sizeVec[1] = 1.0;
    b_st.site = &uib_emlrtRSI;
    c_st.site = &vc_emlrtRSI;
    ::coder::internal::assertValidSizeArg(&c_st, sizeVec);
    fill.set_size(&kx_emlrtRTEI, &b_st, b_I.size(2), 1, 1);
    if (b_I.size(2) != 0) {
      k = b_I.size(2) - 1;
      for (t = 0; t <= k; t++) {
        fill[t] = fillValues[0];
      }
    }
  } else {
    fill.set_size(&jx_emlrtRTEI, &st, 1, 1, fillValues.size(2));
    k = fillValues.size(2);
    for (t = 0; t < k; t++) {
      fill[t] = fillValues[t];
    }
  }
  b_st.site = &vib_emlrtRSI;
  outputImageSize[0] = XmapSingle.size(0);
  outputImageSize[1] = XmapSingle.size(1);
  if (!(outputImageSize[0] >= 0.0)) {
    emlrtNonNegativeCheckR2012b(outputImageSize[0], &ch_emlrtDCI, &b_st);
  }
  if (!(outputImageSize[1] >= 0.0)) {
    emlrtNonNegativeCheckR2012b(outputImageSize[1], &ch_emlrtDCI, &b_st);
  }
  J.set_size(&lx_emlrtRTEI, &b_st, static_cast<int32_T>(outputImageSize[0]),
             static_cast<int32_T>(outputImageSize[1]), b_I.size(2));
  c_st.site = &bjb_emlrtRSI;
  inputImageSize[0] = static_cast<uint32_T>(b_I.size(0));
  inputImageSize[1] = static_cast<uint32_T>(b_I.size(1));
  inputImageSize[2] = static_cast<uint32_T>(b_I.size(2));
  outputImageSize[0] = J.size(0);
  outputImageSize[1] = J.size(1);
  outputImageSize[2] = b_I.size(2);
  t = fill.size(0) * fill.size(2);
  if (t < 0) {
    emlrtDynamicBoundsCheckR2012b(t, 0, MAX_int32_T, &xw_emlrtBCI, &c_st);
  }
  imterp2d32f_uint8(&b_I[0], &inputImageSize[0], &YmapSingle[0], &XmapSingle[0],
                    &outputImageSize[0], 2.0, t == 1, &fill[0], &J[0]);
  newOrigin[0] = XBounds[0] - 1.0;
  newOrigin[1] = YBounds[0] - 1.0;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void b_ImageTransformer::update(const emlrtStack *sp,
                                const ::coder::array<uint8_T, 3U> &b_I,
                                const real_T intrinsicMatrix[9],
                                const real_T radialDist[3],
                                const real_T tangentialDist[2],
                                const real_T xBounds[2],
                                const real_T yBounds[2])
{
  static const char_T b_cv1[6]{'d', 'o', 'u', 'b', 'l', 'e'};
  static const char_T b_cv[5]{'u', 'i', 'n', 't', '8'};
  array<real_T, 2U> Y;
  array<real_T, 2U> b_X;
  array<real_T, 2U> b_y;
  array<real_T, 2U> c_X;
  array<real_T, 2U> ptsOut;
  array<real_T, 2U> y;
  array<real_T, 1U> b_ptsOut;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T varargin_1_tmp[2];
  real_T m;
  real_T n;
  int32_T b_Y;
  int32_T i;
  int32_T loop_ub;
  int32_T maxdimlen;
  boolean_T b_bool;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  SizeOfImage.set_size(&yw_emlrtRTEI, sp, 1, 3);
  SizeOfImage[0] = b_I.size(0);
  SizeOfImage[1] = b_I.size(1);
  SizeOfImage[2] = b_I.size(2);
  ClassOfImage.set_size(&ax_emlrtRTEI, sp, 1, 5);
  for (i = 0; i < 5; i++) {
    ClassOfImage[i] = b_cv[i];
  }
  OutputView.set_size(&bx_emlrtRTEI, sp, 1, 4);
  OutputView[0] = 's';
  OutputView[1] = 'a';
  OutputView[2] = 'm';
  OutputView[3] = 'e';
  XBounds[0] = xBounds[0];
  YBounds[0] = yBounds[0];
  XBounds[1] = xBounds[1];
  YBounds[1] = yBounds[1];
  st.site = &fib_emlrtRSI;
  b_st.site = &gib_emlrtRSI;
  m = XBounds[0];
  n = XBounds[1];
  c_st.site = &shb_emlrtRSI;
  if (muDoubleScalarIsNaN(m) || muDoubleScalarIsNaN(n)) {
    y.set_size(&dk_emlrtRTEI, &c_st, 1, 1);
    y[0] = rtNaN;
  } else if (n < m) {
    y.set_size(&dk_emlrtRTEI, &c_st, 1, 0);
  } else if ((muDoubleScalarIsInf(m) || muDoubleScalarIsInf(n)) && (m == n)) {
    y.set_size(&dk_emlrtRTEI, &c_st, 1, 1);
    y[0] = rtNaN;
  } else if (muDoubleScalarFloor(m) == m) {
    loop_ub = static_cast<int32_T>(muDoubleScalarFloor(n - m));
    y.set_size(&dk_emlrtRTEI, &c_st, 1, loop_ub + 1);
    for (i = 0; i <= loop_ub; i++) {
      y[i] = m + static_cast<real_T>(i);
    }
  } else {
    d_st.site = &qo_emlrtRSI;
    eml_float_colon(&d_st, m, n, y);
  }
  b_st.site = &hib_emlrtRSI;
  m = YBounds[0];
  n = YBounds[1];
  c_st.site = &shb_emlrtRSI;
  if (muDoubleScalarIsNaN(m) || muDoubleScalarIsNaN(n)) {
    b_y.set_size(&dk_emlrtRTEI, &c_st, 1, 1);
    b_y[0] = rtNaN;
  } else if (n < m) {
    b_y.set_size(&dk_emlrtRTEI, &c_st, 1, 0);
  } else if ((muDoubleScalarIsInf(m) || muDoubleScalarIsInf(n)) && (m == n)) {
    b_y.set_size(&dk_emlrtRTEI, &c_st, 1, 1);
    b_y[0] = rtNaN;
  } else if (muDoubleScalarFloor(m) == m) {
    loop_ub = static_cast<int32_T>(muDoubleScalarFloor(n - m));
    b_y.set_size(&dk_emlrtRTEI, &c_st, 1, loop_ub + 1);
    for (i = 0; i <= loop_ub; i++) {
      b_y[i] = m + static_cast<real_T>(i);
    }
  } else {
    d_st.site = &qo_emlrtRSI;
    eml_float_colon(&d_st, m, n, b_y);
  }
  b_st.site = &gib_emlrtRSI;
  meshgrid(&b_st, y, b_y, b_X, Y);
  b_st.site = &iib_emlrtRSI;
  c_st.site = &to_emlrtRSI;
  d_st.site = &uo_emlrtRSI;
  if (Y.size(0) * Y.size(1) != b_X.size(0) * b_X.size(1)) {
    emlrtErrorWithMessageIdR2018a(&d_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  maxdimlen = b_X.size(0) * b_X.size(1);
  b_Y = Y.size(0) * Y.size(1);
  c_X.set_size(&cx_emlrtRTEI, &st, maxdimlen, 2);
  for (i = 0; i < maxdimlen; i++) {
    c_X[i] = b_X[i];
  }
  for (i = 0; i < b_Y; i++) {
    c_X[i + c_X.size(0)] = Y[i];
  }
  b_st.site = &jib_emlrtRSI;
  distortPoints(&b_st, c_X, intrinsicMatrix, radialDist, tangentialDist,
                ptsOut);
  m = (YBounds[1] - YBounds[0]) + 1.0;
  n = (XBounds[1] - XBounds[0]) + 1.0;
  b_bool = false;
  if (ClassOfImage.size(1) == 6) {
    maxdimlen = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (maxdimlen < 6) {
        if (ClassOfImage[maxdimlen] != b_cv1[maxdimlen]) {
          exitg1 = 1;
        } else {
          maxdimlen++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (b_bool) {
    i = ptsOut.size(0);
    b_st.site = &kib_emlrtRSI;
    varargin_1_tmp[0] = m;
    varargin_1_tmp[1] = n;
    c_st.site = &qib_emlrtRSI;
    ::coder::internal::assertValidSizeArg(&c_st, varargin_1_tmp);
    maxdimlen = ptsOut.size(0);
    if (1 > ptsOut.size(0)) {
      maxdimlen = 1;
    }
    maxdimlen = muIntScalarMax_sint32(i, maxdimlen);
    if (static_cast<int32_T>(m) > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &qb_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (static_cast<int32_T>(n) > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &qb_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if ((static_cast<int32_T>(m) < 0) || (static_cast<int32_T>(n) < 0)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &uc_emlrtRTEI,
                                    "MATLAB:checkDimCommon:nonnegativeSize",
                                    "MATLAB:checkDimCommon:nonnegativeSize", 0);
    }
    i = static_cast<int32_T>(m) * static_cast<int32_T>(n);
    if (i != ptsOut.size(0)) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &rb_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }
    b_Y = ptsOut.size(0);
    b_st.site = &lib_emlrtRSI;
    c_st.site = &qib_emlrtRSI;
    ::coder::internal::assertValidSizeArg(&c_st, varargin_1_tmp);
    maxdimlen = ptsOut.size(0);
    if (1 > ptsOut.size(0)) {
      maxdimlen = 1;
    }
    maxdimlen = muIntScalarMax_sint32(b_Y, maxdimlen);
    if (static_cast<int32_T>(m) > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &qb_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (static_cast<int32_T>(n) > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &qb_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if ((static_cast<int32_T>(m) < 0) || (static_cast<int32_T>(n) < 0)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &uc_emlrtRTEI,
                                    "MATLAB:checkDimCommon:nonnegativeSize",
                                    "MATLAB:checkDimCommon:nonnegativeSize", 0);
    }
    if (i != ptsOut.size(0)) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &rb_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }
  } else {
    b_st.site = &mib_emlrtRSI;
    varargin_1_tmp[0] = m;
    varargin_1_tmp[1] = n;
    i = ptsOut.size(0);
    c_st.site = &qib_emlrtRSI;
    ::coder::internal::assertValidSizeArg(&c_st, varargin_1_tmp);
    maxdimlen = ptsOut.size(0);
    if (1 > ptsOut.size(0)) {
      maxdimlen = 1;
    }
    maxdimlen = muIntScalarMax_sint32(i, maxdimlen);
    if (static_cast<int32_T>(m) > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &qb_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (static_cast<int32_T>(n) > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &qb_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if ((static_cast<int32_T>(m) < 0) || (static_cast<int32_T>(n) < 0)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &uc_emlrtRTEI,
                                    "MATLAB:checkDimCommon:nonnegativeSize",
                                    "MATLAB:checkDimCommon:nonnegativeSize", 0);
    }
    loop_ub = static_cast<int32_T>(m) * static_cast<int32_T>(n);
    if (loop_ub != ptsOut.size(0)) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &rb_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }
    b_Y = ptsOut.size(0);
    b_ptsOut.set_size(&dx_emlrtRTEI, &st, ptsOut.size(0));
    for (i = 0; i < b_Y; i++) {
      b_ptsOut[i] = ptsOut[i];
    }
    XmapSingle.set_size(&ex_emlrtRTEI, &st, static_cast<int32_T>(m),
                        static_cast<int32_T>(n));
    for (i = 0; i < loop_ub; i++) {
      XmapSingle[i] = static_cast<real32_T>(b_ptsOut[i]);
    }
    b_st.site = &nib_emlrtRSI;
    i = ptsOut.size(0);
    c_st.site = &qib_emlrtRSI;
    ::coder::internal::assertValidSizeArg(&c_st, varargin_1_tmp);
    maxdimlen = ptsOut.size(0);
    if (1 > ptsOut.size(0)) {
      maxdimlen = 1;
    }
    maxdimlen = muIntScalarMax_sint32(i, maxdimlen);
    if (static_cast<int32_T>(m) > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &qb_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (static_cast<int32_T>(n) > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &qb_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if ((static_cast<int32_T>(m) < 0) || (static_cast<int32_T>(n) < 0)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &uc_emlrtRTEI,
                                    "MATLAB:checkDimCommon:nonnegativeSize",
                                    "MATLAB:checkDimCommon:nonnegativeSize", 0);
    }
    if (loop_ub != ptsOut.size(0)) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &rb_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }
    b_Y = ptsOut.size(0);
    b_ptsOut.set_size(&fx_emlrtRTEI, &st, ptsOut.size(0));
    for (i = 0; i < b_Y; i++) {
      b_ptsOut[i] = ptsOut[i + ptsOut.size(0)];
    }
    YmapSingle.set_size(&gx_emlrtRTEI, &st, static_cast<int32_T>(m),
                        static_cast<int32_T>(n));
    for (i = 0; i < loop_ub; i++) {
      YmapSingle[i] = static_cast<real32_T>(b_ptsOut[i]);
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

// End of code generation (ImageTransformer.cpp)
