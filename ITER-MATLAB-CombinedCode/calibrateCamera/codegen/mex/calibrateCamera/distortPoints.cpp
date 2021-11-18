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
#include "calibrateCamera_data.h"
#include "power.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo ey_emlrtRSI{
    25,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtRSInfo fy_emlrtRSI{
    42,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtRSInfo gy_emlrtRSI{
    43,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtRSInfo hy_emlrtRSI{
    46,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtRSInfo iy_emlrtRSI{
    47,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtRSInfo jy_emlrtRSI{
    48,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtRSInfo ky_emlrtRSI{
    56,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtECInfo gd_emlrtECI{
    -1,              // nDims
    25,              // lineNo
    6,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo hd_emlrtECI{
    -1,              // nDims
    27,              // lineNo
    6,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo id_emlrtECI{
    -1,              // nDims
    37,              // lineNo
    9,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo jd_emlrtECI{
    -1,              // nDims
    41,              // lineNo
    13,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo kd_emlrtECI{
    -1,              // nDims
    42,              // lineNo
    47,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo ld_emlrtECI{
    -1,              // nDims
    42,              // lineNo
    16,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo md_emlrtECI{
    -1,              // nDims
    43,              // lineNo
    24,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo nd_emlrtECI{
    -1,              // nDims
    43,              // lineNo
    16,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo od_emlrtECI{
    2,               // nDims
    47,              // lineNo
    48,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo pd_emlrtECI{
    2,               // nDims
    47,              // lineNo
    29,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo qd_emlrtECI{
    -1,              // nDims
    51,              // lineNo
    20,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo br_emlrtRTEI{
    21,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo cr_emlrtRTEI{
    22,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo dr_emlrtRTEI{
    26,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo er_emlrtRTEI{
    37,              // lineNo
    9,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo fr_emlrtRTEI{
    37,              // lineNo
    21,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo gr_emlrtRTEI{
    37,              // lineNo
    33,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo hr_emlrtRTEI{
    42,              // lineNo
    16,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo ir_emlrtRTEI{
    42,              // lineNo
    39,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo jr_emlrtRTEI{
    42,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo kr_emlrtRTEI{
    46,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo lr_emlrtRTEI{
    47,              // lineNo
    68,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo mr_emlrtRTEI{
    47,              // lineNo
    48,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo nr_emlrtRTEI{
    48,              // lineNo
    5,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo or_emlrtRTEI{
    47,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo pr_emlrtRTEI{
    51,              // lineNo
    20,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo qr_emlrtRTEI{
    52,              // lineNo
    5,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo rr_emlrtRTEI{
    53,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo sr_emlrtRTEI{
    56,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

// Function Definitions
namespace Codegen {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
void distortPoints(const emlrtStack *sp,
                   const ::coder::array<real_T, 2U> &points,
                   const real_T intrinsicMatrix[9],
                   const real_T radialDistortion[3],
                   ::coder::array<real_T, 2U> &distortedPoints)
{
  ::coder::array<real_T, 2U> b_r2;
  ::coder::array<real_T, 2U> centeredPoints;
  ::coder::array<real_T, 2U> r1;
  ::coder::array<real_T, 1U> alpha;
  ::coder::array<real_T, 1U> dxTangential;
  ::coder::array<real_T, 1U> r;
  ::coder::array<real_T, 1U> r2;
  ::coder::array<real_T, 1U> r4;
  ::coder::array<real_T, 1U> xNorm;
  ::coder::array<real_T, 1U> yNorm;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T b[2];
  real_T k_idx_0;
  real_T k_idx_1;
  int32_T iv[2];
  int32_T iv1[2];
  int32_T acoef;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  b[0] = intrinsicMatrix[2];
  b[1] = intrinsicMatrix[5];
  centeredPoints.set_size(&mf_emlrtRTEI, sp, points.size(0), 2);
  if (points.size(0) != 0) {
    acoef = (points.size(0) != 1);
    for (int32_T k{0}; k < 2; k++) {
      i = centeredPoints.size(0) - 1;
      for (int32_T b_k{0}; b_k <= i; b_k++) {
        centeredPoints[b_k + centeredPoints.size(0) * k] =
            points[acoef * b_k + points.size(0) * k] - b[k];
      }
    }
  }
  acoef = centeredPoints.size(0);
  yNorm.set_size(&br_emlrtRTEI, sp, centeredPoints.size(0));
  for (i = 0; i < acoef; i++) {
    yNorm[i] = centeredPoints[i + centeredPoints.size(0)] / intrinsicMatrix[4];
  }
  acoef = centeredPoints.size(0);
  xNorm.set_size(&cr_emlrtRTEI, sp, centeredPoints.size(0));
  for (i = 0; i < acoef; i++) {
    xNorm[i] = centeredPoints[i] / intrinsicMatrix[0];
  }
  st.site = &ey_emlrtRSI;
  power(&st, xNorm, r2);
  st.site = &ey_emlrtRSI;
  power(&st, yNorm, r);
  if (r2.size(0) != r.size(0)) {
    emlrtSizeEqCheck1DR2012b(r2.size(0), r.size(0), &gd_emlrtECI, (emlrtCTX)sp);
  }
  acoef = r2.size(0);
  for (i = 0; i < acoef; i++) {
    r2[i] = r2[i] + r[i];
  }
  r4.set_size(&dr_emlrtRTEI, sp, r2.size(0));
  acoef = r2.size(0);
  for (i = 0; i < acoef; i++) {
    r4[i] = r2[i] * r2[i];
  }
  if (r2.size(0) != r4.size(0)) {
    emlrtSizeEqCheck1DR2012b(r2.size(0), r4.size(0), &hd_emlrtECI,
                             (emlrtCTX)sp);
  }
  k_idx_0 = radialDistortion[0];
  k_idx_1 = radialDistortion[1];
  alpha.set_size(&er_emlrtRTEI, sp, r2.size(0));
  acoef = r2.size(0);
  for (i = 0; i < acoef; i++) {
    alpha[i] = k_idx_0 * r2[i];
  }
  r.set_size(&fr_emlrtRTEI, sp, r4.size(0));
  acoef = r4.size(0);
  for (i = 0; i < acoef; i++) {
    r[i] = k_idx_1 * r4[i];
  }
  if (alpha.size(0) != r.size(0)) {
    emlrtSizeEqCheck1DR2012b(alpha.size(0), r.size(0), &id_emlrtECI,
                             (emlrtCTX)sp);
  }
  r4.set_size(&gr_emlrtRTEI, sp, r2.size(0));
  acoef = r2.size(0);
  for (i = 0; i < acoef; i++) {
    r4[i] = radialDistortion[2] * (r2[i] * r4[i]);
  }
  if (alpha.size(0) != r4.size(0)) {
    emlrtSizeEqCheck1DR2012b(alpha.size(0), r4.size(0), &id_emlrtECI,
                             (emlrtCTX)sp);
  }
  acoef = alpha.size(0);
  for (i = 0; i < acoef; i++) {
    alpha[i] = (alpha[i] + r[i]) + r4[i];
  }
  if (xNorm.size(0) != yNorm.size(0)) {
    emlrtSizeEqCheck1DR2012b(xNorm.size(0), yNorm.size(0), &jd_emlrtECI,
                             (emlrtCTX)sp);
  }
  st.site = &fy_emlrtRSI;
  power(&st, xNorm, dxTangential);
  acoef = dxTangential.size(0);
  for (i = 0; i < acoef; i++) {
    dxTangential[i] = 2.0 * dxTangential[i];
  }
  if (r2.size(0) != dxTangential.size(0)) {
    emlrtSizeEqCheck1DR2012b(r2.size(0), dxTangential.size(0), &kd_emlrtECI,
                             (emlrtCTX)sp);
  }
  r.set_size(&hr_emlrtRTEI, sp, xNorm.size(0));
  acoef = xNorm.size(0);
  for (i = 0; i < acoef; i++) {
    r[i] = 0.0 * (xNorm[i] * yNorm[i]);
  }
  dxTangential.set_size(&ir_emlrtRTEI, sp, r2.size(0));
  acoef = r2.size(0);
  for (i = 0; i < acoef; i++) {
    dxTangential[i] = 0.0 * (r2[i] + dxTangential[i]);
  }
  if (r.size(0) != dxTangential.size(0)) {
    emlrtSizeEqCheck1DR2012b(r.size(0), dxTangential.size(0), &ld_emlrtECI,
                             (emlrtCTX)sp);
  }
  dxTangential.set_size(&jr_emlrtRTEI, sp, r.size(0));
  acoef = r.size(0);
  for (i = 0; i < acoef; i++) {
    dxTangential[i] = r[i] + dxTangential[i];
  }
  st.site = &gy_emlrtRSI;
  power(&st, yNorm, r4);
  acoef = r4.size(0);
  for (i = 0; i < acoef; i++) {
    r4[i] = 2.0 * r4[i];
  }
  if (r2.size(0) != r4.size(0)) {
    emlrtSizeEqCheck1DR2012b(r2.size(0), r4.size(0), &md_emlrtECI,
                             (emlrtCTX)sp);
  }
  acoef = r2.size(0);
  for (i = 0; i < acoef; i++) {
    r2[i] = 0.0 * (r2[i] + r4[i]);
  }
  if (r2.size(0) != r.size(0)) {
    emlrtSizeEqCheck1DR2012b(r2.size(0), r.size(0), &nd_emlrtECI, (emlrtCTX)sp);
  }
  acoef = r2.size(0);
  for (i = 0; i < acoef; i++) {
    r2[i] = r2[i] + r[i];
  }
  st.site = &hy_emlrtRSI;
  b_st.site = &kn_emlrtRSI;
  c_st.site = &ln_emlrtRSI;
  if (yNorm.size(0) != xNorm.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  centeredPoints.set_size(&kr_emlrtRTEI, &b_st, xNorm.size(0), 2);
  acoef = xNorm.size(0);
  for (i = 0; i < acoef; i++) {
    centeredPoints[i] = xNorm[i];
  }
  acoef = yNorm.size(0);
  for (i = 0; i < acoef; i++) {
    centeredPoints[i + centeredPoints.size(0)] = yNorm[i];
  }
  st.site = &iy_emlrtRSI;
  b_st.site = &kn_emlrtRSI;
  r1.set_size(&lr_emlrtRTEI, &b_st, alpha.size(0), 2);
  acoef = alpha.size(0);
  for (i = 0; i < acoef; i++) {
    r1[i] = alpha[i];
  }
  acoef = alpha.size(0);
  for (i = 0; i < acoef; i++) {
    r1[i + r1.size(0)] = alpha[i];
  }
  iv[0] = (*(int32_T(*)[2])centeredPoints.size())[0];
  iv[1] = (*(int32_T(*)[2])centeredPoints.size())[1];
  iv1[0] = (*(int32_T(*)[2])r1.size())[0];
  iv1[1] = (*(int32_T(*)[2])r1.size())[1];
  emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &od_emlrtECI, (emlrtCTX)sp);
  acoef = centeredPoints.size(0) * 2;
  r1.set_size(&mr_emlrtRTEI, sp, centeredPoints.size(0), 2);
  for (i = 0; i < acoef; i++) {
    r1[i] = centeredPoints[i] * r1[i];
  }
  iv[0] = (*(int32_T(*)[2])centeredPoints.size())[0];
  iv[1] = (*(int32_T(*)[2])centeredPoints.size())[1];
  iv1[0] = (*(int32_T(*)[2])r1.size())[0];
  iv1[1] = (*(int32_T(*)[2])r1.size())[1];
  emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &pd_emlrtECI, (emlrtCTX)sp);
  st.site = &jy_emlrtRSI;
  b_st.site = &kn_emlrtRSI;
  c_st.site = &ln_emlrtRSI;
  if (r2.size(0) != dxTangential.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  b_r2.set_size(&nr_emlrtRTEI, &b_st, dxTangential.size(0), 2);
  acoef = dxTangential.size(0);
  for (i = 0; i < acoef; i++) {
    b_r2[i] = dxTangential[i];
  }
  acoef = r2.size(0);
  for (i = 0; i < acoef; i++) {
    b_r2[i + b_r2.size(0)] = r2[i];
  }
  iv[0] = (*(int32_T(*)[2])centeredPoints.size())[0];
  iv[1] = (*(int32_T(*)[2])centeredPoints.size())[1];
  iv1[0] = (*(int32_T(*)[2])b_r2.size())[0];
  iv1[1] = (*(int32_T(*)[2])b_r2.size())[1];
  emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &pd_emlrtECI, (emlrtCTX)sp);
  acoef = centeredPoints.size(0) * 2;
  centeredPoints.set_size(&or_emlrtRTEI, sp, centeredPoints.size(0), 2);
  for (i = 0; i < acoef; i++) {
    centeredPoints[i] = (centeredPoints[i] + r1[i]) + b_r2[i];
  }
  acoef = centeredPoints.size(0);
  dxTangential.set_size(&pr_emlrtRTEI, sp, centeredPoints.size(0));
  for (i = 0; i < acoef; i++) {
    dxTangential[i] = centeredPoints[i] * intrinsicMatrix[0];
  }
  acoef = centeredPoints.size(0);
  r.set_size(&qr_emlrtRTEI, sp, centeredPoints.size(0));
  for (i = 0; i < acoef; i++) {
    r[i] = intrinsicMatrix[1] * centeredPoints[i + centeredPoints.size(0)];
  }
  if (dxTangential.size(0) != r.size(0)) {
    emlrtSizeEqCheck1DR2012b(dxTangential.size(0), r.size(0), &qd_emlrtECI,
                             (emlrtCTX)sp);
  }
  acoef = dxTangential.size(0);
  for (i = 0; i < acoef; i++) {
    dxTangential[i] = (dxTangential[i] + intrinsicMatrix[2]) + r[i];
  }
  acoef = centeredPoints.size(0);
  r4.set_size(&rr_emlrtRTEI, sp, centeredPoints.size(0));
  for (i = 0; i < acoef; i++) {
    r4[i] = centeredPoints[i + centeredPoints.size(0)] * intrinsicMatrix[4] +
            intrinsicMatrix[5];
  }
  st.site = &ky_emlrtRSI;
  b_st.site = &kn_emlrtRSI;
  c_st.site = &ln_emlrtRSI;
  if (r4.size(0) != dxTangential.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  distortedPoints.set_size(&sr_emlrtRTEI, &b_st, dxTangential.size(0), 2);
  acoef = dxTangential.size(0);
  for (i = 0; i < acoef; i++) {
    distortedPoints[i] = dxTangential[i];
  }
  acoef = r4.size(0);
  for (i = 0; i < acoef; i++) {
    distortedPoints[i + distortedPoints.size(0)] = r4[i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace Codegen

// End of code generation (distortPoints.cpp)
