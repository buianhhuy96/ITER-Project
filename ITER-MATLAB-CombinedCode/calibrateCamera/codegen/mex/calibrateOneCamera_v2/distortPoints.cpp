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
#include "calibrateOneCamera_v2_data.h"
#include "power.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo ceb_emlrtRSI{
    18,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtRSInfo deb_emlrtRSI{
    25,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtRSInfo eeb_emlrtRSI{
    42,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtRSInfo feb_emlrtRSI{
    43,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtRSInfo geb_emlrtRSI{
    46,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtRSInfo heb_emlrtRSI{
    47,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtRSInfo ieb_emlrtRSI{
    48,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtRSInfo jeb_emlrtRSI{
    56,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtECInfo id_emlrtECI{
    -1,              // nDims
    25,              // lineNo
    6,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo jd_emlrtECI{
    -1,              // nDims
    27,              // lineNo
    6,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo kd_emlrtECI{
    -1,              // nDims
    37,              // lineNo
    9,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo ld_emlrtECI{
    -1,              // nDims
    41,              // lineNo
    13,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo md_emlrtECI{
    -1,              // nDims
    42,              // lineNo
    47,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo nd_emlrtECI{
    -1,              // nDims
    42,              // lineNo
    16,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo od_emlrtECI{
    -1,              // nDims
    43,              // lineNo
    24,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo pd_emlrtECI{
    -1,              // nDims
    43,              // lineNo
    16,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo qd_emlrtECI{
    2,               // nDims
    47,              // lineNo
    48,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo rd_emlrtECI{
    2,               // nDims
    47,              // lineNo
    29,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo sd_emlrtECI{
    -1,              // nDims
    51,              // lineNo
    20,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtBCInfo fv_emlrtBCI{
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

static emlrtRTEInfo eu_emlrtRTEI{
    21,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo fu_emlrtRTEI{
    22,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo gu_emlrtRTEI{
    26,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo hu_emlrtRTEI{
    37,              // lineNo
    9,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo iu_emlrtRTEI{
    37,              // lineNo
    21,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo ju_emlrtRTEI{
    37,              // lineNo
    33,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo ku_emlrtRTEI{
    41,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo lu_emlrtRTEI{
    42,              // lineNo
    16,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo mu_emlrtRTEI{
    42,              // lineNo
    39,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo nu_emlrtRTEI{
    46,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo ou_emlrtRTEI{
    47,              // lineNo
    68,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo pu_emlrtRTEI{
    47,              // lineNo
    48,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo qu_emlrtRTEI{
    48,              // lineNo
    5,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo ru_emlrtRTEI{
    47,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo su_emlrtRTEI{
    51,              // lineNo
    20,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo tu_emlrtRTEI{
    52,              // lineNo
    5,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo uu_emlrtRTEI{
    53,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo vu_emlrtRTEI{
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
  real_T center[2];
  real_T k_idx_0;
  real_T k_idx_1;
  real_T k_idx_2;
  int32_T iv[2];
  int32_T iv1[2];
  int32_T acoef;
  int32_T b;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  center[0] = intrinsicMatrix[2];
  center[1] = intrinsicMatrix[5];
  st.site = &ceb_emlrtRSI;
  centeredPoints.set_size(&ag_emlrtRTEI, &st, points.size(0), 2);
  if (points.size(0) != 0) {
    b_st.site = &hi_emlrtRSI;
    acoef = (points.size(0) != 1);
    for (int32_T k{0}; k < 2; k++) {
      b = centeredPoints.size(0) - 1;
      for (int32_T b_k{0}; b_k <= b; b_k++) {
        centeredPoints[b_k + centeredPoints.size(0) * k] =
            points[acoef * b_k + points.size(0) * k] - center[k];
      }
    }
  }
  acoef = centeredPoints.size(0);
  yNorm.set_size(&eu_emlrtRTEI, sp, centeredPoints.size(0));
  for (b = 0; b < acoef; b++) {
    yNorm[b] = centeredPoints[b + centeredPoints.size(0)] / intrinsicMatrix[4];
  }
  acoef = centeredPoints.size(0);
  xNorm.set_size(&fu_emlrtRTEI, sp, centeredPoints.size(0));
  for (b = 0; b < acoef; b++) {
    xNorm[b] = centeredPoints[b] / intrinsicMatrix[0];
  }
  st.site = &deb_emlrtRSI;
  power(&st, xNorm, r2);
  st.site = &deb_emlrtRSI;
  power(&st, yNorm, dxTangential);
  if (r2.size(0) != dxTangential.size(0)) {
    emlrtSizeEqCheck1DR2012b(r2.size(0), dxTangential.size(0), &id_emlrtECI,
                             (emlrtCTX)sp);
  }
  acoef = r2.size(0);
  for (b = 0; b < acoef; b++) {
    r2[b] = r2[b] + dxTangential[b];
  }
  r4.set_size(&gu_emlrtRTEI, sp, r2.size(0));
  acoef = r2.size(0);
  for (b = 0; b < acoef; b++) {
    r4[b] = r2[b] * r2[b];
  }
  if (r2.size(0) != r4.size(0)) {
    emlrtSizeEqCheck1DR2012b(r2.size(0), r4.size(0), &jd_emlrtECI,
                             (emlrtCTX)sp);
  }
  if (1 > radialDistortion.size(1)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, radialDistortion.size(1), &fv_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  k_idx_0 = radialDistortion[0];
  if (2 > radialDistortion.size(1)) {
    emlrtDynamicBoundsCheckR2012b(2, 1, radialDistortion.size(1), &fv_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  k_idx_1 = radialDistortion[1];
  if (radialDistortion.size(1) < 3) {
    k_idx_2 = 0.0;
  } else {
    k_idx_2 = radialDistortion[2];
  }
  alpha.set_size(&hu_emlrtRTEI, sp, r2.size(0));
  acoef = r2.size(0);
  for (b = 0; b < acoef; b++) {
    alpha[b] = k_idx_0 * r2[b];
  }
  dxTangential.set_size(&iu_emlrtRTEI, sp, r4.size(0));
  acoef = r4.size(0);
  for (b = 0; b < acoef; b++) {
    dxTangential[b] = k_idx_1 * r4[b];
  }
  if (alpha.size(0) != dxTangential.size(0)) {
    emlrtSizeEqCheck1DR2012b(alpha.size(0), dxTangential.size(0), &kd_emlrtECI,
                             (emlrtCTX)sp);
  }
  r4.set_size(&ju_emlrtRTEI, sp, r2.size(0));
  acoef = r2.size(0);
  for (b = 0; b < acoef; b++) {
    r4[b] = k_idx_2 * (r2[b] * r4[b]);
  }
  if (alpha.size(0) != r4.size(0)) {
    emlrtSizeEqCheck1DR2012b(alpha.size(0), r4.size(0), &kd_emlrtECI,
                             (emlrtCTX)sp);
  }
  acoef = alpha.size(0);
  for (b = 0; b < acoef; b++) {
    alpha[b] = (alpha[b] + dxTangential[b]) + r4[b];
  }
  if (xNorm.size(0) != yNorm.size(0)) {
    emlrtSizeEqCheck1DR2012b(xNorm.size(0), yNorm.size(0), &ld_emlrtECI,
                             (emlrtCTX)sp);
  }
  xyProduct.set_size(&ku_emlrtRTEI, sp, xNorm.size(0));
  acoef = xNorm.size(0);
  for (b = 0; b < acoef; b++) {
    xyProduct[b] = xNorm[b] * yNorm[b];
  }
  st.site = &eeb_emlrtRSI;
  power(&st, xNorm, r4);
  acoef = r4.size(0);
  for (b = 0; b < acoef; b++) {
    r4[b] = 2.0 * r4[b];
  }
  if (r2.size(0) != r4.size(0)) {
    emlrtSizeEqCheck1DR2012b(r2.size(0), r4.size(0), &md_emlrtECI,
                             (emlrtCTX)sp);
  }
  k_idx_0 = 2.0 * tangentialDistortion[0];
  dxTangential.set_size(&lu_emlrtRTEI, sp, xyProduct.size(0));
  acoef = xyProduct.size(0);
  for (b = 0; b < acoef; b++) {
    dxTangential[b] = k_idx_0 * xyProduct[b];
  }
  r4.set_size(&mu_emlrtRTEI, sp, r2.size(0));
  acoef = r2.size(0);
  for (b = 0; b < acoef; b++) {
    r4[b] = tangentialDistortion[1] * (r2[b] + r4[b]);
  }
  if (dxTangential.size(0) != r4.size(0)) {
    emlrtSizeEqCheck1DR2012b(dxTangential.size(0), r4.size(0), &nd_emlrtECI,
                             (emlrtCTX)sp);
  }
  acoef = dxTangential.size(0);
  for (b = 0; b < acoef; b++) {
    dxTangential[b] = dxTangential[b] + r4[b];
  }
  st.site = &feb_emlrtRSI;
  power(&st, yNorm, r4);
  acoef = r4.size(0);
  for (b = 0; b < acoef; b++) {
    r4[b] = 2.0 * r4[b];
  }
  if (r2.size(0) != r4.size(0)) {
    emlrtSizeEqCheck1DR2012b(r2.size(0), r4.size(0), &od_emlrtECI,
                             (emlrtCTX)sp);
  }
  acoef = r2.size(0);
  for (b = 0; b < acoef; b++) {
    r2[b] = tangentialDistortion[0] * (r2[b] + r4[b]);
  }
  k_idx_0 = 2.0 * tangentialDistortion[1];
  acoef = xyProduct.size(0);
  for (b = 0; b < acoef; b++) {
    xyProduct[b] = k_idx_0 * xyProduct[b];
  }
  if (r2.size(0) != xyProduct.size(0)) {
    emlrtSizeEqCheck1DR2012b(r2.size(0), xyProduct.size(0), &pd_emlrtECI,
                             (emlrtCTX)sp);
  }
  acoef = r2.size(0);
  for (b = 0; b < acoef; b++) {
    r2[b] = r2[b] + xyProduct[b];
  }
  st.site = &geb_emlrtRSI;
  b_st.site = &to_emlrtRSI;
  c_st.site = &uo_emlrtRSI;
  if (yNorm.size(0) != xNorm.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  centeredPoints.set_size(&nu_emlrtRTEI, &b_st, xNorm.size(0), 2);
  acoef = xNorm.size(0);
  for (b = 0; b < acoef; b++) {
    centeredPoints[b] = xNorm[b];
  }
  acoef = yNorm.size(0);
  for (b = 0; b < acoef; b++) {
    centeredPoints[b + centeredPoints.size(0)] = yNorm[b];
  }
  st.site = &heb_emlrtRSI;
  b_st.site = &to_emlrtRSI;
  r.set_size(&ou_emlrtRTEI, &b_st, alpha.size(0), 2);
  acoef = alpha.size(0);
  for (b = 0; b < acoef; b++) {
    r[b] = alpha[b];
  }
  acoef = alpha.size(0);
  for (b = 0; b < acoef; b++) {
    r[b + r.size(0)] = alpha[b];
  }
  iv[0] = (*(int32_T(*)[2])centeredPoints.size())[0];
  iv[1] = (*(int32_T(*)[2])centeredPoints.size())[1];
  iv1[0] = (*(int32_T(*)[2])r.size())[0];
  iv1[1] = (*(int32_T(*)[2])r.size())[1];
  emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &qd_emlrtECI, (emlrtCTX)sp);
  acoef = centeredPoints.size(0) * 2;
  r.set_size(&pu_emlrtRTEI, sp, centeredPoints.size(0), 2);
  for (b = 0; b < acoef; b++) {
    r[b] = centeredPoints[b] * r[b];
  }
  iv[0] = (*(int32_T(*)[2])centeredPoints.size())[0];
  iv[1] = (*(int32_T(*)[2])centeredPoints.size())[1];
  iv1[0] = (*(int32_T(*)[2])r.size())[0];
  iv1[1] = (*(int32_T(*)[2])r.size())[1];
  emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &rd_emlrtECI, (emlrtCTX)sp);
  st.site = &ieb_emlrtRSI;
  b_st.site = &to_emlrtRSI;
  c_st.site = &uo_emlrtRSI;
  if (r2.size(0) != dxTangential.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  r1.set_size(&qu_emlrtRTEI, &b_st, dxTangential.size(0), 2);
  acoef = dxTangential.size(0);
  for (b = 0; b < acoef; b++) {
    r1[b] = dxTangential[b];
  }
  acoef = r2.size(0);
  for (b = 0; b < acoef; b++) {
    r1[b + r1.size(0)] = r2[b];
  }
  iv[0] = (*(int32_T(*)[2])centeredPoints.size())[0];
  iv[1] = (*(int32_T(*)[2])centeredPoints.size())[1];
  iv1[0] = (*(int32_T(*)[2])r1.size())[0];
  iv1[1] = (*(int32_T(*)[2])r1.size())[1];
  emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &rd_emlrtECI, (emlrtCTX)sp);
  acoef = centeredPoints.size(0) * 2;
  centeredPoints.set_size(&ru_emlrtRTEI, sp, centeredPoints.size(0), 2);
  for (b = 0; b < acoef; b++) {
    centeredPoints[b] = (centeredPoints[b] + r[b]) + r1[b];
  }
  acoef = centeredPoints.size(0);
  xyProduct.set_size(&su_emlrtRTEI, sp, centeredPoints.size(0));
  for (b = 0; b < acoef; b++) {
    xyProduct[b] = centeredPoints[b] * intrinsicMatrix[0];
  }
  acoef = centeredPoints.size(0);
  dxTangential.set_size(&tu_emlrtRTEI, sp, centeredPoints.size(0));
  for (b = 0; b < acoef; b++) {
    dxTangential[b] =
        intrinsicMatrix[1] * centeredPoints[b + centeredPoints.size(0)];
  }
  if (xyProduct.size(0) != dxTangential.size(0)) {
    emlrtSizeEqCheck1DR2012b(xyProduct.size(0), dxTangential.size(0),
                             &sd_emlrtECI, (emlrtCTX)sp);
  }
  acoef = xyProduct.size(0);
  for (b = 0; b < acoef; b++) {
    xyProduct[b] = (xyProduct[b] + intrinsicMatrix[2]) + dxTangential[b];
  }
  acoef = centeredPoints.size(0);
  r4.set_size(&uu_emlrtRTEI, sp, centeredPoints.size(0));
  for (b = 0; b < acoef; b++) {
    r4[b] = centeredPoints[b + centeredPoints.size(0)] * intrinsicMatrix[4] +
            intrinsicMatrix[5];
  }
  st.site = &jeb_emlrtRSI;
  b_st.site = &to_emlrtRSI;
  c_st.site = &uo_emlrtRSI;
  if (r4.size(0) != xyProduct.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  distortedPoints.set_size(&vu_emlrtRTEI, &b_st, xyProduct.size(0), 2);
  acoef = xyProduct.size(0);
  for (b = 0; b < acoef; b++) {
    distortedPoints[b] = xyProduct[b];
  }
  acoef = r4.size(0);
  for (b = 0; b < acoef; b++) {
    distortedPoints[b + distortedPoints.size(0)] = r4[b];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

// End of code generation (distortPoints.cpp)
