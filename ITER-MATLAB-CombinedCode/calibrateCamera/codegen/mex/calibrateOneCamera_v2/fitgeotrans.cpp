//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// fitgeotrans.cpp
//
// Code generation for function 'fitgeotrans'
//

// Include files
#include "fitgeotrans.h"
#include "calibrateOneCamera_v2_data.h"
#include "det.h"
#include "inv.h"
#include "mldivide.h"
#include "normalizeControlPoints.h"
#include "projective2d.h"
#include "rank.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo ax_emlrtRSI{
    11,            // lineNo
    "fitgeotrans", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo bx_emlrtRSI{
    31,            // lineNo
    "fitgeotrans", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo cx_emlrtRSI{
    15,                      // lineNo
    "validateControlPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\validateControlPoints.m" // pathName
};

static emlrtRSInfo dx_emlrtRSI{
    16,                      // lineNo
    "validateControlPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\validateControlPoints.m" // pathName
};

static emlrtRSInfo fx_emlrtRSI{
    85,                        // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo gx_emlrtRSI{
    86,                        // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo hx_emlrtRSI{
    99,                        // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo ix_emlrtRSI{
    100,                       // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo jx_emlrtRSI{
    103,                       // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo kx_emlrtRSI{
    106,                       // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo lx_emlrtRSI{
    113,                       // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo mx_emlrtRSI{
    115,                       // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo nx_emlrtRSI{
    118,                       // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo ux_emlrtRSI{
    11,     // lineNo
    "rank", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\rank.m" // pathName
};

static emlrtRSInfo
    lab_emlrtRSI{
        113,                         // lineNo
        "projective2d/projective2d", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\projective2d.m" // pathName
    };

static emlrtRSInfo
    mab_emlrtRSI{
        332,                  // lineNo
        "projective2d/set.T", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\projective2d.m" // pathName
    };

static emlrtRSInfo
    nab_emlrtRSI{
        338,                  // lineNo
        "projective2d/set.T", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\projective2d.m" // pathName
    };

static emlrtRTEInfo ac_emlrtRTEI{
    19,                      // lineNo
    55,                      // colNo
    "validateControlPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\validateControlPoints.m" // pName
};

static emlrtBCInfo ut_emlrtBCI{
    -1,                        // iFirst
    -1,                        // iLast
    90,                        // lineNo
    10,                        // colNo
    "",                        // aName
    "findProjectiveTransform", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m", // pName
    0 // checkKind
};

static emlrtBCInfo vt_emlrtBCI{
    -1,                        // iFirst
    -1,                        // iLast
    91,                        // lineNo
    10,                        // colNo
    "",                        // aName
    "findProjectiveTransform", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m", // pName
    0 // checkKind
};

static emlrtBCInfo wt_emlrtBCI{
    -1,                        // iFirst
    -1,                        // iLast
    94,                        // lineNo
    10,                        // colNo
    "",                        // aName
    "findProjectiveTransform", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m", // pName
    0 // checkKind
};

static emlrtBCInfo xt_emlrtBCI{
    -1,                        // iFirst
    -1,                        // iLast
    95,                        // lineNo
    10,                        // colNo
    "",                        // aName
    "findProjectiveTransform", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m", // pName
    0 // checkKind
};

static emlrtECInfo xc_emlrtECI{
    -1,                        // nDims
    99,                        // lineNo
    48,                        // colNo
    "findProjectiveTransform", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtECInfo yc_emlrtECI{
    -1,                        // nDims
    100,                       // lineNo
    48,                        // colNo
    "findProjectiveTransform", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtRTEInfo cc_emlrtRTEI{
    103,                       // lineNo
    23,                        // colNo
    "findProjectiveTransform", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtECInfo ad_emlrtECI{
    -1,                        // nDims
    106,                       // lineNo
    1,                         // colNo
    "findProjectiveTransform", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtRTEInfo
    dc_emlrtRTEI{
        338,                  // lineNo
        13,                   // colNo
        "projective2d/set.T", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\projective2d.m" // pName
    };

static emlrtRTEInfo qr_emlrtRTEI{
    90,            // lineNo
    1,             // colNo
    "fitgeotrans", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtRTEInfo rr_emlrtRTEI{
    91,            // lineNo
    1,             // colNo
    "fitgeotrans", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtRTEInfo sr_emlrtRTEI{
    94,            // lineNo
    1,             // colNo
    "fitgeotrans", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtRTEInfo tr_emlrtRTEI{
    95,            // lineNo
    1,             // colNo
    "fitgeotrans", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtRTEInfo ur_emlrtRTEI{
    99,            // lineNo
    48,            // colNo
    "fitgeotrans", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtRTEInfo vr_emlrtRTEI{
    100,           // lineNo
    48,            // colNo
    "fitgeotrans", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtRTEInfo wr_emlrtRTEI{
    99,            // lineNo
    1,             // colNo
    "fitgeotrans", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtRTEInfo xr_emlrtRTEI{
    106,           // lineNo
    13,            // colNo
    "fitgeotrans", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

// Function Declarations
namespace coder {
static void findProjectiveTransform(const emlrtStack *sp,
                                    const ::coder::array<real_T, 2U> &uv,
                                    const ::coder::array<real_T, 2U> &xy,
                                    projective2d *tform);

}

// Function Definitions
namespace coder {
static void findProjectiveTransform(const emlrtStack *sp,
                                    const ::coder::array<real_T, 2U> &uv,
                                    const ::coder::array<real_T, 2U> &xy,
                                    projective2d *tform)
{
  array<real_T, 2U> b_X;
  array<real_T, 2U> b_uv;
  array<real_T, 2U> b_xy;
  array<real_T, 1U> b_varargin_7;
  array<real_T, 1U> b_varargin_8;
  array<real_T, 1U> u;
  array<real_T, 1U> v;
  array<real_T, 1U> varargin_7;
  array<real_T, 1U> varargin_8;
  array<real_T, 1U> x;
  array<real_T, 1U> y;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T Tvec[9];
  real_T b_Tvec[9];
  real_T normMatrix2[9];
  real_T b_tform;
  int32_T i;
  int32_T irank;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &fx_emlrtRSI;
  images::geotrans::internal::normalizeControlPoints(&st, uv, b_uv, tform->T);
  st.site = &gx_emlrtRSI;
  images::geotrans::internal::normalizeControlPoints(&st, xy, b_xy,
                                                     normMatrix2);
  if (1 > b_xy.size(1)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, b_xy.size(1), &ut_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  irank = b_xy.size(0);
  x.set_size(&qr_emlrtRTEI, sp, b_xy.size(0));
  for (i = 0; i < irank; i++) {
    x[i] = b_xy[i];
  }
  if (2 > b_xy.size(1)) {
    emlrtDynamicBoundsCheckR2012b(2, 1, b_xy.size(1), &vt_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  irank = b_xy.size(0);
  y.set_size(&rr_emlrtRTEI, sp, b_xy.size(0));
  for (i = 0; i < irank; i++) {
    y[i] = b_xy[i + b_xy.size(0)];
  }
  if (1 > b_uv.size(1)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, b_uv.size(1), &wt_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  irank = b_uv.size(0);
  u.set_size(&sr_emlrtRTEI, sp, b_uv.size(0));
  for (i = 0; i < irank; i++) {
    u[i] = b_uv[i];
  }
  if (2 > b_uv.size(1)) {
    emlrtDynamicBoundsCheckR2012b(2, 1, b_uv.size(1), &xt_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  irank = b_uv.size(0);
  v.set_size(&tr_emlrtRTEI, sp, b_uv.size(0));
  for (i = 0; i < irank; i++) {
    v[i] = b_uv[i + b_uv.size(0)];
  }
  varargin_8.set_size(&ur_emlrtRTEI, sp, u.size(0));
  irank = u.size(0);
  for (i = 0; i < irank; i++) {
    varargin_8[i] = -u[i];
  }
  if (varargin_8.size(0) != b_xy.size(0)) {
    emlrtSizeEqCheck1DR2012b(varargin_8.size(0), b_xy.size(0), &xc_emlrtECI,
                             (emlrtCTX)sp);
  }
  b_varargin_8.set_size(&vr_emlrtRTEI, sp, v.size(0));
  irank = v.size(0);
  for (i = 0; i < irank; i++) {
    b_varargin_8[i] = -v[i];
  }
  if (b_varargin_8.size(0) != b_xy.size(0)) {
    emlrtSizeEqCheck1DR2012b(b_varargin_8.size(0), b_xy.size(0), &yc_emlrtECI,
                             (emlrtCTX)sp);
  }
  st.site = &hx_emlrtRSI;
  varargin_7.set_size(&ur_emlrtRTEI, &st, varargin_8.size(0));
  irank = varargin_8.size(0);
  for (i = 0; i < irank; i++) {
    varargin_7[i] = varargin_8[i] * x[i];
  }
  irank = varargin_8.size(0);
  for (i = 0; i < irank; i++) {
    varargin_8[i] = varargin_8[i] * y[i];
  }
  b_st.site = &to_emlrtRSI;
  c_st.site = &uo_emlrtRSI;
  if (varargin_7.size(0) != b_xy.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  if (varargin_8.size(0) != b_xy.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  st.site = &ix_emlrtRSI;
  b_varargin_7.set_size(&vr_emlrtRTEI, &st, b_varargin_8.size(0));
  irank = b_varargin_8.size(0);
  for (i = 0; i < irank; i++) {
    b_varargin_7[i] = b_varargin_8[i] * x[i];
  }
  irank = b_varargin_8.size(0);
  for (i = 0; i < irank; i++) {
    b_varargin_8[i] = b_varargin_8[i] * y[i];
  }
  b_st.site = &to_emlrtRSI;
  c_st.site = &uo_emlrtRSI;
  if (b_varargin_7.size(0) != b_xy.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  if (b_varargin_8.size(0) != b_xy.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  b_X.set_size(&wr_emlrtRTEI, sp, x.size(0) + b_xy.size(0), 8);
  irank = x.size(0);
  for (i = 0; i < irank; i++) {
    b_X[i] = x[i];
  }
  irank = y.size(0);
  for (i = 0; i < irank; i++) {
    b_X[i + b_X.size(0)] = y[i];
  }
  irank = b_xy.size(0);
  for (i = 0; i < irank; i++) {
    b_X[i + b_X.size(0) * 2] = 1.0;
  }
  irank = b_xy.size(0);
  for (i = 0; i < irank; i++) {
    b_X[i + b_X.size(0) * 3] = 0.0;
  }
  irank = b_xy.size(0);
  for (i = 0; i < irank; i++) {
    b_X[i + b_X.size(0) * 4] = 0.0;
  }
  irank = b_xy.size(0);
  for (i = 0; i < irank; i++) {
    b_X[i + b_X.size(0) * 5] = 0.0;
  }
  irank = varargin_7.size(0);
  for (i = 0; i < irank; i++) {
    b_X[i + b_X.size(0) * 6] = varargin_7[i];
  }
  irank = varargin_8.size(0);
  for (i = 0; i < irank; i++) {
    b_X[i + b_X.size(0) * 7] = varargin_8[i];
  }
  irank = b_xy.size(0);
  for (i = 0; i < irank; i++) {
    b_X[i + x.size(0)] = 0.0;
  }
  irank = b_xy.size(0);
  for (i = 0; i < irank; i++) {
    b_X[(i + x.size(0)) + b_X.size(0)] = 0.0;
  }
  irank = b_xy.size(0);
  for (i = 0; i < irank; i++) {
    b_X[(i + x.size(0)) + b_X.size(0) * 2] = 0.0;
  }
  irank = x.size(0);
  for (i = 0; i < irank; i++) {
    b_X[(i + x.size(0)) + b_X.size(0) * 3] = x[i];
  }
  irank = y.size(0);
  for (i = 0; i < irank; i++) {
    b_X[(i + x.size(0)) + b_X.size(0) * 4] = y[i];
  }
  irank = b_xy.size(0);
  for (i = 0; i < irank; i++) {
    b_X[(i + x.size(0)) + b_X.size(0) * 5] = 1.0;
  }
  irank = b_varargin_7.size(0);
  for (i = 0; i < irank; i++) {
    b_X[(i + x.size(0)) + b_X.size(0) * 6] = b_varargin_7[i];
  }
  irank = b_varargin_8.size(0);
  for (i = 0; i < irank; i++) {
    b_X[(i + x.size(0)) + b_X.size(0) * 7] = b_varargin_8[i];
  }
  st.site = &jx_emlrtRSI;
  b_st.site = &ux_emlrtRSI;
  irank = local_rank(&b_st, b_X);
  if (irank < 8) {
    emlrtErrorWithMessageIdR2018a(sp, &cc_emlrtRTEI,
                                  "images:geotrans:requiredNonCollinearPoints",
                                  "images:geotrans:requiredNonCollinearPoints",
                                  5, 6, 4.0, 4, 10, "projective");
  }
  x.set_size(&xr_emlrtRTEI, sp, u.size(0) + v.size(0));
  irank = u.size(0);
  for (i = 0; i < irank; i++) {
    x[i] = u[i];
  }
  irank = v.size(0);
  for (i = 0; i < irank; i++) {
    x[i + u.size(0)] = v[i];
  }
  st.site = &kx_emlrtRSI;
  mldivide(&st, b_X, x);
  if (8 != x.size(0)) {
    emlrtSubAssignSizeCheck1dR2017a(8, x.size(0), &ad_emlrtECI, (emlrtCTX)sp);
  }
  for (i = 0; i < 8; i++) {
    Tvec[i] = x[i];
  }
  Tvec[8] = 1.0;
  for (i = 0; i < 3; i++) {
    real_T d;
    real_T d1;
    b_tform = Tvec[i];
    d = Tvec[i + 3];
    d1 = Tvec[i + 6];
    for (irank = 0; irank < 3; irank++) {
      b_Tvec[i + 3 * irank] =
          (b_tform * tform->T[3 * irank] + d * tform->T[3 * irank + 1]) +
          d1 * tform->T[3 * irank + 2];
    }
  }
  st.site = &lx_emlrtRSI;
  mldivide(&st, normMatrix2, b_Tvec, Tvec);
  st.site = &mx_emlrtRSI;
  inv(&st, Tvec, tform->T);
  b_tform = tform->T[8];
  for (i = 0; i < 9; i++) {
    tform->T[i] /= b_tform;
  }
  st.site = &nx_emlrtRSI;
  b_st.site = &lab_emlrtRSI;
  c_st.site = &mab_emlrtRSI;
  d_st.site = &t_emlrtRSI;
  p = true;
  irank = 0;
  exitg1 = false;
  while ((!exitg1) && (irank < 9)) {
    if ((!muDoubleScalarIsInf(tform->T[irank])) &&
        (!muDoubleScalarIsNaN(tform->T[irank]))) {
      irank++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:projective2d:set:T:expectedFinite", 3, 4, 1, "T");
  }
  d_st.site = &t_emlrtRSI;
  p = true;
  irank = 0;
  exitg1 = false;
  while ((!exitg1) && (irank < 9)) {
    if (!muDoubleScalarIsNaN(tform->T[irank])) {
      irank++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &l_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:projective2d:set:T:expectedNonNaN", 3, 4, 1, "T");
  }
  c_st.site = &nab_emlrtRSI;
  b_tform = det(&c_st, tform->T);
  if (b_tform == 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &dc_emlrtRTEI, "images:geotrans:singularTransformationMatrix",
        "images:geotrans:singularTransformationMatrix", 0);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void fitgeotrans(const emlrtStack *sp,
                 const ::coder::array<real_T, 2U> &movingPoints,
                 const ::coder::array<real_T, 2U> &fixedPoints,
                 projective2d *tform)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T i;
  int32_T k;
  uint32_T varargin_1[2];
  uint32_T varargin_2[2];
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ax_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &cx_emlrtRSI;
  c_st.site = &t_emlrtRSI;
  p = true;
  i = movingPoints.size(0) * movingPoints.size(1);
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= i - 1)) {
    if ((!muDoubleScalarIsInf(movingPoints[k])) &&
        (!muDoubleScalarIsNaN(movingPoints[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:validateControlPoints:expectedFinite", 3, 4, 12,
        "movingPoints");
  }
  c_st.site = &t_emlrtRSI;
  if (movingPoints.size(1) != 2) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &bc_emlrtRTEI,
        "Coder:toolbox:ValidateattributesincorrectNumcols",
        "MATLAB:validateControlPoints:incorrectNumcols", 5, 4, 12,
        "movingPoints", 6, 2.0);
  }
  b_st.site = &dx_emlrtRSI;
  c_st.site = &t_emlrtRSI;
  p = true;
  i = fixedPoints.size(0) * fixedPoints.size(1);
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= i - 1)) {
    if ((!muDoubleScalarIsInf(fixedPoints[k])) &&
        (!muDoubleScalarIsNaN(fixedPoints[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:validateControlPoints:expectedFinite", 3, 4, 11, "fixedPoints");
  }
  c_st.site = &t_emlrtRSI;
  if (fixedPoints.size(1) != 2) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &bc_emlrtRTEI,
        "Coder:toolbox:ValidateattributesincorrectNumcols",
        "MATLAB:validateControlPoints:incorrectNumcols", 5, 4, 11,
        "fixedPoints", 6, 2.0);
  }
  varargin_1[0] = static_cast<uint32_T>(movingPoints.size(0));
  varargin_2[0] = static_cast<uint32_T>(fixedPoints.size(0));
  varargin_1[1] = 2U;
  varargin_2[1] = 2U;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (static_cast<int32_T>(varargin_1[k]) !=
        static_cast<int32_T>(varargin_2[k])) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &st, &ac_emlrtRTEI, "images:geotrans:differentNumbersOfControlPoints",
        "images:geotrans:differentNumbersOfControlPoints", 6, 4, 11,
        "fixedPoints", 4, 12, "movingPoints");
  }
  st.site = &bx_emlrtRSI;
  findProjectiveTransform(&st, movingPoints, fixedPoints, tform);
}

} // namespace coder

// End of code generation (fitgeotrans.cpp)
