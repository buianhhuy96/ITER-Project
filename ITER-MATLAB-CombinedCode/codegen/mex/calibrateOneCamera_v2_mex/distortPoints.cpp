//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// distortPoints.cpp
//
// Code generation for function 'distortPoints'
//

// Include files
#include "distortPoints.h"
#include "bsxfun.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "power.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo beb_emlrtRSI{
    18,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtRSInfo ceb_emlrtRSI{
    25,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtRSInfo deb_emlrtRSI{
    42,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtRSInfo eeb_emlrtRSI{
    43,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtRSInfo feb_emlrtRSI{
    46,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtRSInfo geb_emlrtRSI{
    47,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtRSInfo heb_emlrtRSI{
    48,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtRSInfo ieb_emlrtRSI{
    56,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtECInfo jd_emlrtECI{
    -1,              // nDims
    25,              // lineNo
    6,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo kd_emlrtECI{
    -1,              // nDims
    27,              // lineNo
    6,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo ld_emlrtECI{
    -1,              // nDims
    37,              // lineNo
    9,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo md_emlrtECI{
    -1,              // nDims
    41,              // lineNo
    13,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo nd_emlrtECI{
    -1,              // nDims
    42,              // lineNo
    47,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo od_emlrtECI{
    -1,              // nDims
    42,              // lineNo
    16,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo pd_emlrtECI{
    -1,              // nDims
    43,              // lineNo
    24,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo qd_emlrtECI{
    -1,              // nDims
    43,              // lineNo
    16,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo rd_emlrtECI{
    2,               // nDims
    47,              // lineNo
    48,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo sd_emlrtECI{
    2,               // nDims
    47,              // lineNo
    29,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo td_emlrtECI{
    -1,              // nDims
    51,              // lineNo
    20,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtBCInfo iv_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    30,              // lineNo
    27,              // colNo
    "",              // aName
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m", // pName
    0                               // checkKind
};

static emlrtRTEInfo ku_emlrtRTEI{
    21,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo lu_emlrtRTEI{
    22,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo mu_emlrtRTEI{
    26,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo nu_emlrtRTEI{
    37,              // lineNo
    9,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo ou_emlrtRTEI{
    37,              // lineNo
    21,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo pu_emlrtRTEI{
    37,              // lineNo
    33,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo qu_emlrtRTEI{
    41,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo ru_emlrtRTEI{
    42,              // lineNo
    16,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo su_emlrtRTEI{
    42,              // lineNo
    39,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo tu_emlrtRTEI{
    46,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo uu_emlrtRTEI{
    47,              // lineNo
    68,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo vu_emlrtRTEI{
    47,              // lineNo
    48,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo wu_emlrtRTEI{
    48,              // lineNo
    5,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo xu_emlrtRTEI{
    47,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo yu_emlrtRTEI{
    51,              // lineNo
    20,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo av_emlrtRTEI{
    52,              // lineNo
    5,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo bv_emlrtRTEI{
    53,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo cv_emlrtRTEI{
    56,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

// Function Definitions
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
void distortPoints(const emlrtStack *sp,
                   const ::coder::array<real_T, 2U> &points,
                   const real_T intrinsicMatrix[9],
                   const ::coder::array<real_T, 2U> &radialDistortion,
                   const real_T tangentialDistortion[2],
                   ::coder::array<real_T, 2U> &distortedPoints)
{
  array<real_T, 2U> centeredPoints;
  array<real_T, 2U> r;
  array<real_T, 2U> r1;
  array<real_T, 1U> alpha;
  array<real_T, 1U> dxTangential;
  array<real_T, 1U> r2;
  array<real_T, 1U> r4;
  array<real_T, 1U> xNorm;
  array<real_T, 1U> xyProduct;
  array<real_T, 1U> yNorm;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T b_intrinsicMatrix[2];
  real_T k_idx_0;
  real_T k_idx_1;
  real_T k_idx_2;
  int32_T b_iv[2];
  int32_T iv1[2];
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  b_intrinsicMatrix[0] = intrinsicMatrix[2];
  b_intrinsicMatrix[1] = intrinsicMatrix[5];
  st.site = &beb_emlrtRSI;
  bsxfun(&st, points, b_intrinsicMatrix, centeredPoints);
  loop_ub = centeredPoints.size(0);
  yNorm.set_size(&ku_emlrtRTEI, sp, centeredPoints.size(0));
  for (i = 0; i < loop_ub; i++) {
    yNorm[i] = centeredPoints[i + centeredPoints.size(0)] / intrinsicMatrix[4];
  }
  loop_ub = centeredPoints.size(0);
  xNorm.set_size(&lu_emlrtRTEI, sp, centeredPoints.size(0));
  for (i = 0; i < loop_ub; i++) {
    xNorm[i] = centeredPoints[i] / intrinsicMatrix[0];
  }
  st.site = &ceb_emlrtRSI;
  power(&st, xNorm, r2);
  st.site = &ceb_emlrtRSI;
  power(&st, yNorm, dxTangential);
  if (r2.size(0) != dxTangential.size(0)) {
    emlrtSizeEqCheck1DR2012b(r2.size(0), dxTangential.size(0), &jd_emlrtECI,
                             (emlrtCTX)sp);
  }
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    r2[i] = r2[i] + dxTangential[i];
  }
  r4.set_size(&mu_emlrtRTEI, sp, r2.size(0));
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    r4[i] = r2[i] * r2[i];
  }
  if (r2.size(0) != r4.size(0)) {
    emlrtSizeEqCheck1DR2012b(r2.size(0), r4.size(0), &kd_emlrtECI,
                             (emlrtCTX)sp);
  }
  if (1 > radialDistortion.size(1)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, radialDistortion.size(1), &iv_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  k_idx_0 = radialDistortion[0];
  if (2 > radialDistortion.size(1)) {
    emlrtDynamicBoundsCheckR2012b(2, 1, radialDistortion.size(1), &iv_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  k_idx_1 = radialDistortion[1];
  if (radialDistortion.size(1) < 3) {
    k_idx_2 = 0.0;
  } else {
    k_idx_2 = radialDistortion[2];
  }
  alpha.set_size(&nu_emlrtRTEI, sp, r2.size(0));
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    alpha[i] = k_idx_0 * r2[i];
  }
  dxTangential.set_size(&ou_emlrtRTEI, sp, r4.size(0));
  loop_ub = r4.size(0);
  for (i = 0; i < loop_ub; i++) {
    dxTangential[i] = k_idx_1 * r4[i];
  }
  if (alpha.size(0) != dxTangential.size(0)) {
    emlrtSizeEqCheck1DR2012b(alpha.size(0), dxTangential.size(0), &ld_emlrtECI,
                             (emlrtCTX)sp);
  }
  r4.set_size(&pu_emlrtRTEI, sp, r2.size(0));
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    r4[i] = k_idx_2 * (r2[i] * r4[i]);
  }
  if (alpha.size(0) != r4.size(0)) {
    emlrtSizeEqCheck1DR2012b(alpha.size(0), r4.size(0), &ld_emlrtECI,
                             (emlrtCTX)sp);
  }
  loop_ub = alpha.size(0);
  for (i = 0; i < loop_ub; i++) {
    alpha[i] = (alpha[i] + dxTangential[i]) + r4[i];
  }
  if (xNorm.size(0) != yNorm.size(0)) {
    emlrtSizeEqCheck1DR2012b(xNorm.size(0), yNorm.size(0), &md_emlrtECI,
                             (emlrtCTX)sp);
  }
  xyProduct.set_size(&qu_emlrtRTEI, sp, xNorm.size(0));
  loop_ub = xNorm.size(0);
  for (i = 0; i < loop_ub; i++) {
    xyProduct[i] = xNorm[i] * yNorm[i];
  }
  st.site = &deb_emlrtRSI;
  power(&st, xNorm, r4);
  loop_ub = r4.size(0);
  for (i = 0; i < loop_ub; i++) {
    r4[i] = 2.0 * r4[i];
  }
  if (r2.size(0) != r4.size(0)) {
    emlrtSizeEqCheck1DR2012b(r2.size(0), r4.size(0), &nd_emlrtECI,
                             (emlrtCTX)sp);
  }
  k_idx_0 = 2.0 * tangentialDistortion[0];
  dxTangential.set_size(&ru_emlrtRTEI, sp, xyProduct.size(0));
  loop_ub = xyProduct.size(0);
  for (i = 0; i < loop_ub; i++) {
    dxTangential[i] = k_idx_0 * xyProduct[i];
  }
  r4.set_size(&su_emlrtRTEI, sp, r2.size(0));
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    r4[i] = tangentialDistortion[1] * (r2[i] + r4[i]);
  }
  if (dxTangential.size(0) != r4.size(0)) {
    emlrtSizeEqCheck1DR2012b(dxTangential.size(0), r4.size(0), &od_emlrtECI,
                             (emlrtCTX)sp);
  }
  loop_ub = dxTangential.size(0);
  for (i = 0; i < loop_ub; i++) {
    dxTangential[i] = dxTangential[i] + r4[i];
  }
  st.site = &eeb_emlrtRSI;
  power(&st, yNorm, r4);
  loop_ub = r4.size(0);
  for (i = 0; i < loop_ub; i++) {
    r4[i] = 2.0 * r4[i];
  }
  if (r2.size(0) != r4.size(0)) {
    emlrtSizeEqCheck1DR2012b(r2.size(0), r4.size(0), &pd_emlrtECI,
                             (emlrtCTX)sp);
  }
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    r2[i] = tangentialDistortion[0] * (r2[i] + r4[i]);
  }
  k_idx_0 = 2.0 * tangentialDistortion[1];
  loop_ub = xyProduct.size(0);
  for (i = 0; i < loop_ub; i++) {
    xyProduct[i] = k_idx_0 * xyProduct[i];
  }
  if (r2.size(0) != xyProduct.size(0)) {
    emlrtSizeEqCheck1DR2012b(r2.size(0), xyProduct.size(0), &qd_emlrtECI,
                             (emlrtCTX)sp);
  }
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    r2[i] = r2[i] + xyProduct[i];
  }
  st.site = &feb_emlrtRSI;
  b_st.site = &to_emlrtRSI;
  c_st.site = &uo_emlrtRSI;
  if (yNorm.size(0) != xNorm.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  centeredPoints.set_size(&tu_emlrtRTEI, &b_st, xNorm.size(0), 2);
  loop_ub = xNorm.size(0);
  for (i = 0; i < loop_ub; i++) {
    centeredPoints[i] = xNorm[i];
  }
  loop_ub = yNorm.size(0);
  for (i = 0; i < loop_ub; i++) {
    centeredPoints[i + centeredPoints.size(0)] = yNorm[i];
  }
  st.site = &geb_emlrtRSI;
  b_st.site = &to_emlrtRSI;
  r.set_size(&uu_emlrtRTEI, &b_st, alpha.size(0), 2);
  loop_ub = alpha.size(0);
  for (i = 0; i < loop_ub; i++) {
    r[i] = alpha[i];
  }
  loop_ub = alpha.size(0);
  for (i = 0; i < loop_ub; i++) {
    r[i + r.size(0)] = alpha[i];
  }
  b_iv[0] = (*(int32_T(*)[2])centeredPoints.size())[0];
  b_iv[1] = (*(int32_T(*)[2])centeredPoints.size())[1];
  iv1[0] = (*(int32_T(*)[2])r.size())[0];
  iv1[1] = (*(int32_T(*)[2])r.size())[1];
  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &rd_emlrtECI, (emlrtCTX)sp);
  loop_ub = centeredPoints.size(0) * 2;
  r.set_size(&vu_emlrtRTEI, sp, centeredPoints.size(0), 2);
  for (i = 0; i < loop_ub; i++) {
    r[i] = centeredPoints[i] * r[i];
  }
  b_iv[0] = (*(int32_T(*)[2])centeredPoints.size())[0];
  b_iv[1] = (*(int32_T(*)[2])centeredPoints.size())[1];
  iv1[0] = (*(int32_T(*)[2])r.size())[0];
  iv1[1] = (*(int32_T(*)[2])r.size())[1];
  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &sd_emlrtECI, (emlrtCTX)sp);
  st.site = &heb_emlrtRSI;
  b_st.site = &to_emlrtRSI;
  c_st.site = &uo_emlrtRSI;
  if (r2.size(0) != dxTangential.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  r1.set_size(&wu_emlrtRTEI, &b_st, dxTangential.size(0), 2);
  loop_ub = dxTangential.size(0);
  for (i = 0; i < loop_ub; i++) {
    r1[i] = dxTangential[i];
  }
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    r1[i + r1.size(0)] = r2[i];
  }
  b_iv[0] = (*(int32_T(*)[2])centeredPoints.size())[0];
  b_iv[1] = (*(int32_T(*)[2])centeredPoints.size())[1];
  iv1[0] = (*(int32_T(*)[2])r1.size())[0];
  iv1[1] = (*(int32_T(*)[2])r1.size())[1];
  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &sd_emlrtECI, (emlrtCTX)sp);
  loop_ub = centeredPoints.size(0) * 2;
  centeredPoints.set_size(&xu_emlrtRTEI, sp, centeredPoints.size(0), 2);
  for (i = 0; i < loop_ub; i++) {
    centeredPoints[i] = (centeredPoints[i] + r[i]) + r1[i];
  }
  loop_ub = centeredPoints.size(0);
  xyProduct.set_size(&yu_emlrtRTEI, sp, centeredPoints.size(0));
  for (i = 0; i < loop_ub; i++) {
    xyProduct[i] = centeredPoints[i] * intrinsicMatrix[0];
  }
  loop_ub = centeredPoints.size(0);
  dxTangential.set_size(&av_emlrtRTEI, sp, centeredPoints.size(0));
  for (i = 0; i < loop_ub; i++) {
    dxTangential[i] =
        intrinsicMatrix[1] * centeredPoints[i + centeredPoints.size(0)];
  }
  if (xyProduct.size(0) != dxTangential.size(0)) {
    emlrtSizeEqCheck1DR2012b(xyProduct.size(0), dxTangential.size(0),
                             &td_emlrtECI, (emlrtCTX)sp);
  }
  loop_ub = xyProduct.size(0);
  for (i = 0; i < loop_ub; i++) {
    xyProduct[i] = (xyProduct[i] + intrinsicMatrix[2]) + dxTangential[i];
  }
  loop_ub = centeredPoints.size(0);
  r4.set_size(&bv_emlrtRTEI, sp, centeredPoints.size(0));
  for (i = 0; i < loop_ub; i++) {
    r4[i] = centeredPoints[i + centeredPoints.size(0)] * intrinsicMatrix[4] +
            intrinsicMatrix[5];
  }
  st.site = &ieb_emlrtRSI;
  b_st.site = &to_emlrtRSI;
  c_st.site = &uo_emlrtRSI;
  if (r4.size(0) != xyProduct.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  distortedPoints.set_size(&cv_emlrtRTEI, &b_st, xyProduct.size(0), 2);
  loop_ub = xyProduct.size(0);
  for (i = 0; i < loop_ub; i++) {
    distortedPoints[i] = xyProduct[i];
  }
  loop_ub = r4.size(0);
  for (i = 0; i < loop_ub; i++) {
    distortedPoints[i + distortedPoints.size(0)] = r4[i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void distortPoints(const emlrtStack *sp,
                   const ::coder::array<real_T, 2U> &points,
                   const real_T intrinsicMatrix[9],
                   const real_T radialDistortion[3],
                   const real_T tangentialDistortion[2],
                   ::coder::array<real_T, 2U> &distortedPoints)
{
  array<real_T, 2U> centeredPoints;
  array<real_T, 2U> r;
  array<real_T, 2U> r1;
  array<real_T, 1U> alpha;
  array<real_T, 1U> dxTangential;
  array<real_T, 1U> r2;
  array<real_T, 1U> r4;
  array<real_T, 1U> xNorm;
  array<real_T, 1U> xyProduct;
  array<real_T, 1U> yNorm;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T b_intrinsicMatrix[2];
  real_T k_idx_0;
  real_T k_idx_1;
  int32_T b_iv[2];
  int32_T iv1[2];
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  b_intrinsicMatrix[0] = intrinsicMatrix[2];
  b_intrinsicMatrix[1] = intrinsicMatrix[5];
  st.site = &beb_emlrtRSI;
  bsxfun(&st, points, b_intrinsicMatrix, centeredPoints);
  loop_ub = centeredPoints.size(0);
  yNorm.set_size(&ku_emlrtRTEI, sp, centeredPoints.size(0));
  for (i = 0; i < loop_ub; i++) {
    yNorm[i] = centeredPoints[i + centeredPoints.size(0)] / intrinsicMatrix[4];
  }
  loop_ub = centeredPoints.size(0);
  xNorm.set_size(&lu_emlrtRTEI, sp, centeredPoints.size(0));
  for (i = 0; i < loop_ub; i++) {
    xNorm[i] = centeredPoints[i] / intrinsicMatrix[0];
  }
  st.site = &ceb_emlrtRSI;
  power(&st, xNorm, r2);
  st.site = &ceb_emlrtRSI;
  power(&st, yNorm, dxTangential);
  if (r2.size(0) != dxTangential.size(0)) {
    emlrtSizeEqCheck1DR2012b(r2.size(0), dxTangential.size(0), &jd_emlrtECI,
                             (emlrtCTX)sp);
  }
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    r2[i] = r2[i] + dxTangential[i];
  }
  r4.set_size(&mu_emlrtRTEI, sp, r2.size(0));
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    r4[i] = r2[i] * r2[i];
  }
  if (r2.size(0) != r4.size(0)) {
    emlrtSizeEqCheck1DR2012b(r2.size(0), r4.size(0), &kd_emlrtECI,
                             (emlrtCTX)sp);
  }
  k_idx_0 = radialDistortion[0];
  k_idx_1 = radialDistortion[1];
  alpha.set_size(&nu_emlrtRTEI, sp, r2.size(0));
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    alpha[i] = k_idx_0 * r2[i];
  }
  dxTangential.set_size(&ou_emlrtRTEI, sp, r4.size(0));
  loop_ub = r4.size(0);
  for (i = 0; i < loop_ub; i++) {
    dxTangential[i] = k_idx_1 * r4[i];
  }
  if (alpha.size(0) != dxTangential.size(0)) {
    emlrtSizeEqCheck1DR2012b(alpha.size(0), dxTangential.size(0), &ld_emlrtECI,
                             (emlrtCTX)sp);
  }
  r4.set_size(&pu_emlrtRTEI, sp, r2.size(0));
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    r4[i] = radialDistortion[2] * (r2[i] * r4[i]);
  }
  if (alpha.size(0) != r4.size(0)) {
    emlrtSizeEqCheck1DR2012b(alpha.size(0), r4.size(0), &ld_emlrtECI,
                             (emlrtCTX)sp);
  }
  loop_ub = alpha.size(0);
  for (i = 0; i < loop_ub; i++) {
    alpha[i] = (alpha[i] + dxTangential[i]) + r4[i];
  }
  if (xNorm.size(0) != yNorm.size(0)) {
    emlrtSizeEqCheck1DR2012b(xNorm.size(0), yNorm.size(0), &md_emlrtECI,
                             (emlrtCTX)sp);
  }
  xyProduct.set_size(&qu_emlrtRTEI, sp, xNorm.size(0));
  loop_ub = xNorm.size(0);
  for (i = 0; i < loop_ub; i++) {
    xyProduct[i] = xNorm[i] * yNorm[i];
  }
  st.site = &deb_emlrtRSI;
  power(&st, xNorm, r4);
  loop_ub = r4.size(0);
  for (i = 0; i < loop_ub; i++) {
    r4[i] = 2.0 * r4[i];
  }
  if (r2.size(0) != r4.size(0)) {
    emlrtSizeEqCheck1DR2012b(r2.size(0), r4.size(0), &nd_emlrtECI,
                             (emlrtCTX)sp);
  }
  k_idx_0 = 2.0 * tangentialDistortion[0];
  dxTangential.set_size(&ru_emlrtRTEI, sp, xyProduct.size(0));
  loop_ub = xyProduct.size(0);
  for (i = 0; i < loop_ub; i++) {
    dxTangential[i] = k_idx_0 * xyProduct[i];
  }
  r4.set_size(&su_emlrtRTEI, sp, r2.size(0));
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    r4[i] = tangentialDistortion[1] * (r2[i] + r4[i]);
  }
  if (dxTangential.size(0) != r4.size(0)) {
    emlrtSizeEqCheck1DR2012b(dxTangential.size(0), r4.size(0), &od_emlrtECI,
                             (emlrtCTX)sp);
  }
  loop_ub = dxTangential.size(0);
  for (i = 0; i < loop_ub; i++) {
    dxTangential[i] = dxTangential[i] + r4[i];
  }
  st.site = &eeb_emlrtRSI;
  power(&st, yNorm, r4);
  loop_ub = r4.size(0);
  for (i = 0; i < loop_ub; i++) {
    r4[i] = 2.0 * r4[i];
  }
  if (r2.size(0) != r4.size(0)) {
    emlrtSizeEqCheck1DR2012b(r2.size(0), r4.size(0), &pd_emlrtECI,
                             (emlrtCTX)sp);
  }
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    r2[i] = tangentialDistortion[0] * (r2[i] + r4[i]);
  }
  k_idx_0 = 2.0 * tangentialDistortion[1];
  loop_ub = xyProduct.size(0);
  for (i = 0; i < loop_ub; i++) {
    xyProduct[i] = k_idx_0 * xyProduct[i];
  }
  if (r2.size(0) != xyProduct.size(0)) {
    emlrtSizeEqCheck1DR2012b(r2.size(0), xyProduct.size(0), &qd_emlrtECI,
                             (emlrtCTX)sp);
  }
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    r2[i] = r2[i] + xyProduct[i];
  }
  st.site = &feb_emlrtRSI;
  b_st.site = &to_emlrtRSI;
  c_st.site = &uo_emlrtRSI;
  if (yNorm.size(0) != xNorm.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  centeredPoints.set_size(&tu_emlrtRTEI, &b_st, xNorm.size(0), 2);
  loop_ub = xNorm.size(0);
  for (i = 0; i < loop_ub; i++) {
    centeredPoints[i] = xNorm[i];
  }
  loop_ub = yNorm.size(0);
  for (i = 0; i < loop_ub; i++) {
    centeredPoints[i + centeredPoints.size(0)] = yNorm[i];
  }
  st.site = &geb_emlrtRSI;
  b_st.site = &to_emlrtRSI;
  r.set_size(&uu_emlrtRTEI, &b_st, alpha.size(0), 2);
  loop_ub = alpha.size(0);
  for (i = 0; i < loop_ub; i++) {
    r[i] = alpha[i];
  }
  loop_ub = alpha.size(0);
  for (i = 0; i < loop_ub; i++) {
    r[i + r.size(0)] = alpha[i];
  }
  b_iv[0] = (*(int32_T(*)[2])centeredPoints.size())[0];
  b_iv[1] = (*(int32_T(*)[2])centeredPoints.size())[1];
  iv1[0] = (*(int32_T(*)[2])r.size())[0];
  iv1[1] = (*(int32_T(*)[2])r.size())[1];
  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &rd_emlrtECI, (emlrtCTX)sp);
  loop_ub = centeredPoints.size(0) * 2;
  r.set_size(&vu_emlrtRTEI, sp, centeredPoints.size(0), 2);
  for (i = 0; i < loop_ub; i++) {
    r[i] = centeredPoints[i] * r[i];
  }
  b_iv[0] = (*(int32_T(*)[2])centeredPoints.size())[0];
  b_iv[1] = (*(int32_T(*)[2])centeredPoints.size())[1];
  iv1[0] = (*(int32_T(*)[2])r.size())[0];
  iv1[1] = (*(int32_T(*)[2])r.size())[1];
  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &sd_emlrtECI, (emlrtCTX)sp);
  st.site = &heb_emlrtRSI;
  b_st.site = &to_emlrtRSI;
  c_st.site = &uo_emlrtRSI;
  if (r2.size(0) != dxTangential.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  r1.set_size(&wu_emlrtRTEI, &b_st, dxTangential.size(0), 2);
  loop_ub = dxTangential.size(0);
  for (i = 0; i < loop_ub; i++) {
    r1[i] = dxTangential[i];
  }
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    r1[i + r1.size(0)] = r2[i];
  }
  b_iv[0] = (*(int32_T(*)[2])centeredPoints.size())[0];
  b_iv[1] = (*(int32_T(*)[2])centeredPoints.size())[1];
  iv1[0] = (*(int32_T(*)[2])r1.size())[0];
  iv1[1] = (*(int32_T(*)[2])r1.size())[1];
  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &sd_emlrtECI, (emlrtCTX)sp);
  loop_ub = centeredPoints.size(0) * 2;
  centeredPoints.set_size(&xu_emlrtRTEI, sp, centeredPoints.size(0), 2);
  for (i = 0; i < loop_ub; i++) {
    centeredPoints[i] = (centeredPoints[i] + r[i]) + r1[i];
  }
  loop_ub = centeredPoints.size(0);
  xyProduct.set_size(&yu_emlrtRTEI, sp, centeredPoints.size(0));
  for (i = 0; i < loop_ub; i++) {
    xyProduct[i] = centeredPoints[i] * intrinsicMatrix[0];
  }
  loop_ub = centeredPoints.size(0);
  dxTangential.set_size(&av_emlrtRTEI, sp, centeredPoints.size(0));
  for (i = 0; i < loop_ub; i++) {
    dxTangential[i] =
        intrinsicMatrix[1] * centeredPoints[i + centeredPoints.size(0)];
  }
  if (xyProduct.size(0) != dxTangential.size(0)) {
    emlrtSizeEqCheck1DR2012b(xyProduct.size(0), dxTangential.size(0),
                             &td_emlrtECI, (emlrtCTX)sp);
  }
  loop_ub = xyProduct.size(0);
  for (i = 0; i < loop_ub; i++) {
    xyProduct[i] = (xyProduct[i] + intrinsicMatrix[2]) + dxTangential[i];
  }
  loop_ub = centeredPoints.size(0);
  r4.set_size(&bv_emlrtRTEI, sp, centeredPoints.size(0));
  for (i = 0; i < loop_ub; i++) {
    r4[i] = centeredPoints[i + centeredPoints.size(0)] * intrinsicMatrix[4] +
            intrinsicMatrix[5];
  }
  st.site = &ieb_emlrtRSI;
  b_st.site = &to_emlrtRSI;
  c_st.site = &uo_emlrtRSI;
  if (r4.size(0) != xyProduct.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  distortedPoints.set_size(&cv_emlrtRTEI, &b_st, xyProduct.size(0), 2);
  loop_ub = xyProduct.size(0);
  for (i = 0; i < loop_ub; i++) {
    distortedPoints[i] = xyProduct[i];
  }
  loop_ub = r4.size(0);
  for (i = 0; i < loop_ub; i++) {
    distortedPoints[i + distortedPoints.size(0)] = r4[i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

// End of code generation (distortPoints.cpp)
