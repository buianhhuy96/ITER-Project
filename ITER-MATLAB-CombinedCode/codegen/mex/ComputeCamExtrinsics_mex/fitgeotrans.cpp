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
#include "ComputeCamExtrinsics_mex_data.h"
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
static emlrtRSInfo ix_emlrtRSI{
    85,                        // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo jx_emlrtRSI{
    86,                        // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo kx_emlrtRSI{
    99,                        // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo lx_emlrtRSI{
    100,                       // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo mx_emlrtRSI{
    103,                       // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo nx_emlrtRSI{
    106,                       // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo ox_emlrtRSI{
    113,                       // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo px_emlrtRSI{
    115,                       // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo qx_emlrtRSI{
    118,                       // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo xx_emlrtRSI{
    11,     // lineNo
    "rank", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\rank.m" // pathName
};

static emlrtRSInfo
    oab_emlrtRSI{
        113,                         // lineNo
        "projective2d/projective2d", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\projective2d.m" // pathName
    };

static emlrtRSInfo
    pab_emlrtRSI{
        332,                  // lineNo
        "projective2d/set.T", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\projective2d.m" // pathName
    };

static emlrtRSInfo
    qab_emlrtRSI{
        338,                  // lineNo
        "projective2d/set.T", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\projective2d.m" // pathName
    };

static emlrtBCInfo lt_emlrtBCI{
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

static emlrtBCInfo mt_emlrtBCI{
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

static emlrtBCInfo nt_emlrtBCI{
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

static emlrtBCInfo ot_emlrtBCI{
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

static emlrtECInfo ad_emlrtECI{
    -1,                        // nDims
    99,                        // lineNo
    48,                        // colNo
    "findProjectiveTransform", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtECInfo bd_emlrtECI{
    -1,                        // nDims
    100,                       // lineNo
    48,                        // colNo
    "findProjectiveTransform", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtRTEInfo hc_emlrtRTEI{
    103,                       // lineNo
    23,                        // colNo
    "findProjectiveTransform", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtECInfo cd_emlrtECI{
    -1,                        // nDims
    106,                       // lineNo
    1,                         // colNo
    "findProjectiveTransform", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtRTEInfo
    ic_emlrtRTEI{
        338,                  // lineNo
        13,                   // colNo
        "projective2d/set.T", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\projective2d.m" // pName
    };

static emlrtRTEInfo vq_emlrtRTEI{
    90,            // lineNo
    1,             // colNo
    "fitgeotrans", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtRTEInfo wq_emlrtRTEI{
    91,            // lineNo
    1,             // colNo
    "fitgeotrans", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtRTEInfo xq_emlrtRTEI{
    94,            // lineNo
    1,             // colNo
    "fitgeotrans", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtRTEInfo yq_emlrtRTEI{
    95,            // lineNo
    1,             // colNo
    "fitgeotrans", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtRTEInfo ar_emlrtRTEI{
    99,            // lineNo
    48,            // colNo
    "fitgeotrans", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtRTEInfo br_emlrtRTEI{
    100,           // lineNo
    48,            // colNo
    "fitgeotrans", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtRTEInfo cr_emlrtRTEI{
    99,            // lineNo
    1,             // colNo
    "fitgeotrans", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtRTEInfo dr_emlrtRTEI{
    106,           // lineNo
    13,            // colNo
    "fitgeotrans", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

// Function Definitions
namespace coder {
void findProjectiveTransform(const emlrtStack *sp,
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
  st.site = &ix_emlrtRSI;
  images::geotrans::internal::normalizeControlPoints(&st, uv, b_uv, tform->T);
  st.site = &jx_emlrtRSI;
  images::geotrans::internal::normalizeControlPoints(&st, xy, b_xy,
                                                     normMatrix2);
  if (1 > b_xy.size(1)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, b_xy.size(1), &lt_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  irank = b_xy.size(0);
  x.set_size(&vq_emlrtRTEI, sp, b_xy.size(0));
  for (i = 0; i < irank; i++) {
    x[i] = b_xy[i];
  }
  if (2 > b_xy.size(1)) {
    emlrtDynamicBoundsCheckR2012b(2, 1, b_xy.size(1), &mt_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  irank = b_xy.size(0);
  y.set_size(&wq_emlrtRTEI, sp, b_xy.size(0));
  for (i = 0; i < irank; i++) {
    y[i] = b_xy[i + b_xy.size(0)];
  }
  if (1 > b_uv.size(1)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, b_uv.size(1), &nt_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  irank = b_uv.size(0);
  u.set_size(&xq_emlrtRTEI, sp, b_uv.size(0));
  for (i = 0; i < irank; i++) {
    u[i] = b_uv[i];
  }
  if (2 > b_uv.size(1)) {
    emlrtDynamicBoundsCheckR2012b(2, 1, b_uv.size(1), &ot_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  irank = b_uv.size(0);
  v.set_size(&yq_emlrtRTEI, sp, b_uv.size(0));
  for (i = 0; i < irank; i++) {
    v[i] = b_uv[i + b_uv.size(0)];
  }
  varargin_8.set_size(&ar_emlrtRTEI, sp, u.size(0));
  irank = u.size(0);
  for (i = 0; i < irank; i++) {
    varargin_8[i] = -u[i];
  }
  if (varargin_8.size(0) != b_xy.size(0)) {
    emlrtSizeEqCheck1DR2012b(varargin_8.size(0), b_xy.size(0), &ad_emlrtECI,
                             (emlrtCTX)sp);
  }
  b_varargin_8.set_size(&br_emlrtRTEI, sp, v.size(0));
  irank = v.size(0);
  for (i = 0; i < irank; i++) {
    b_varargin_8[i] = -v[i];
  }
  if (b_varargin_8.size(0) != b_xy.size(0)) {
    emlrtSizeEqCheck1DR2012b(b_varargin_8.size(0), b_xy.size(0), &bd_emlrtECI,
                             (emlrtCTX)sp);
  }
  st.site = &kx_emlrtRSI;
  varargin_7.set_size(&ar_emlrtRTEI, &st, varargin_8.size(0));
  irank = varargin_8.size(0);
  for (i = 0; i < irank; i++) {
    varargin_7[i] = varargin_8[i] * x[i];
  }
  irank = varargin_8.size(0);
  for (i = 0; i < irank; i++) {
    varargin_8[i] = varargin_8[i] * y[i];
  }
  b_st.site = &wo_emlrtRSI;
  c_st.site = &xo_emlrtRSI;
  if (varargin_7.size(0) != b_xy.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &mb_emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  if (varargin_8.size(0) != b_xy.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &mb_emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  st.site = &lx_emlrtRSI;
  b_varargin_7.set_size(&br_emlrtRTEI, &st, b_varargin_8.size(0));
  irank = b_varargin_8.size(0);
  for (i = 0; i < irank; i++) {
    b_varargin_7[i] = b_varargin_8[i] * x[i];
  }
  irank = b_varargin_8.size(0);
  for (i = 0; i < irank; i++) {
    b_varargin_8[i] = b_varargin_8[i] * y[i];
  }
  b_st.site = &wo_emlrtRSI;
  c_st.site = &xo_emlrtRSI;
  if (b_varargin_7.size(0) != b_xy.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &mb_emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  if (b_varargin_8.size(0) != b_xy.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &mb_emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  b_X.set_size(&cr_emlrtRTEI, sp, x.size(0) + b_xy.size(0), 8);
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
  st.site = &mx_emlrtRSI;
  b_st.site = &xx_emlrtRSI;
  irank = local_rank(&b_st, b_X);
  if (irank < 8) {
    emlrtErrorWithMessageIdR2018a(sp, &hc_emlrtRTEI,
                                  "images:geotrans:requiredNonCollinearPoints",
                                  "images:geotrans:requiredNonCollinearPoints",
                                  5, 6, 4.0, 4, 10, "projective");
  }
  x.set_size(&dr_emlrtRTEI, sp, u.size(0) + v.size(0));
  irank = u.size(0);
  for (i = 0; i < irank; i++) {
    x[i] = u[i];
  }
  irank = v.size(0);
  for (i = 0; i < irank; i++) {
    x[i + u.size(0)] = v[i];
  }
  st.site = &nx_emlrtRSI;
  mldivide(&st, b_X, x);
  if (8 != x.size(0)) {
    emlrtSubAssignSizeCheck1dR2017a(8, x.size(0), &cd_emlrtECI, (emlrtCTX)sp);
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
  st.site = &ox_emlrtRSI;
  mldivide(&st, normMatrix2, b_Tvec, Tvec);
  st.site = &px_emlrtRSI;
  inv(&st, Tvec, tform->T);
  b_tform = tform->T[8];
  for (i = 0; i < 9; i++) {
    tform->T[i] /= b_tform;
  }
  st.site = &qx_emlrtRSI;
  b_st.site = &oab_emlrtRSI;
  c_st.site = &pab_emlrtRSI;
  d_st.site = &v_emlrtRSI;
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
        &d_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:projective2d:set:T:expectedFinite", 3, 4, 1, "T");
  }
  d_st.site = &v_emlrtRSI;
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
  c_st.site = &qab_emlrtRSI;
  b_tform = det(&c_st, tform->T);
  if (b_tform == 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &ic_emlrtRTEI, "images:geotrans:singularTransformationMatrix",
        "images:geotrans:singularTransformationMatrix", 0);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace coder

// End of code generation (fitgeotrans.cpp)
