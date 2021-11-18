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
#include "calibrateOneCamera_mex_data.h"
#include "power.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo fab_emlrtRSI{
    25,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtRSInfo gab_emlrtRSI{
    42,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtRSInfo hab_emlrtRSI{
    43,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtRSInfo iab_emlrtRSI{
    46,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtRSInfo jab_emlrtRSI{
    47,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtRSInfo kab_emlrtRSI{
    48,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtRSInfo lab_emlrtRSI{
    56,              // lineNo
    "distortPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pathName
};

static emlrtECInfo ed_emlrtECI{
    -1,              // nDims
    25,              // lineNo
    6,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo fd_emlrtECI{
    -1,              // nDims
    27,              // lineNo
    6,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo gd_emlrtECI{
    -1,              // nDims
    37,              // lineNo
    9,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo hd_emlrtECI{
    -1,              // nDims
    41,              // lineNo
    13,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo id_emlrtECI{
    -1,              // nDims
    42,              // lineNo
    47,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo jd_emlrtECI{
    -1,              // nDims
    42,              // lineNo
    16,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo kd_emlrtECI{
    -1,              // nDims
    43,              // lineNo
    24,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo ld_emlrtECI{
    -1,              // nDims
    43,              // lineNo
    16,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo md_emlrtECI{
    2,               // nDims
    47,              // lineNo
    48,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo nd_emlrtECI{
    2,               // nDims
    47,              // lineNo
    29,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtECInfo od_emlrtECI{
    -1,              // nDims
    51,              // lineNo
    20,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo cr_emlrtRTEI{
    21,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo dr_emlrtRTEI{
    22,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo er_emlrtRTEI{
    26,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo fr_emlrtRTEI{
    37,              // lineNo
    9,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo gr_emlrtRTEI{
    37,              // lineNo
    21,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo hr_emlrtRTEI{
    37,              // lineNo
    33,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo ir_emlrtRTEI{
    41,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo jr_emlrtRTEI{
    42,              // lineNo
    16,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo kr_emlrtRTEI{
    42,              // lineNo
    39,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo lr_emlrtRTEI{
    46,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo mr_emlrtRTEI{
    47,              // lineNo
    68,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo nr_emlrtRTEI{
    47,              // lineNo
    48,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo or_emlrtRTEI{
    48,              // lineNo
    5,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo pr_emlrtRTEI{
    47,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo qr_emlrtRTEI{
    51,              // lineNo
    20,              // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo rr_emlrtRTEI{
    52,              // lineNo
    5,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo sr_emlrtRTEI{
    53,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\distortPoints.m" // pName
};

static emlrtRTEInfo tr_emlrtRTEI{
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
                   const real_T tangentialDistortion[2],
                   ::coder::array<real_T, 2U> &distortedPoints)
{
  ::coder::array<real_T, 2U> centeredPoints;
  ::coder::array<real_T, 2U> r;
  ::coder::array<real_T, 2U> r1;
  ::coder::array<real_T, 1U> alpha;
  ::coder::array<real_T, 1U> dxTangential;
  ::coder::array<real_T, 1U> r2;
  ::coder::array<real_T, 1U> r4;
  ::coder::array<real_T, 1U> xNorm;
  ::coder::array<real_T, 1U> xyProduct;
  ::coder::array<real_T, 1U> yNorm;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T b[2];
  real_T k_idx_0;
  real_T k_idx_1;
  int32_T b_iv[2];
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
  centeredPoints.set_size(&if_emlrtRTEI, sp, points.size(0), 2);
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
  yNorm.set_size(&cr_emlrtRTEI, sp, centeredPoints.size(0));
  for (i = 0; i < acoef; i++) {
    yNorm[i] = centeredPoints[i + centeredPoints.size(0)] / intrinsicMatrix[4];
  }
  acoef = centeredPoints.size(0);
  xNorm.set_size(&dr_emlrtRTEI, sp, centeredPoints.size(0));
  for (i = 0; i < acoef; i++) {
    xNorm[i] = centeredPoints[i] / intrinsicMatrix[0];
  }
  st.site = &fab_emlrtRSI;
  power(&st, xNorm, r2);
  st.site = &fab_emlrtRSI;
  power(&st, yNorm, dxTangential);
  if (r2.size(0) != dxTangential.size(0)) {
    emlrtSizeEqCheck1DR2012b(r2.size(0), dxTangential.size(0), &ed_emlrtECI,
                             (emlrtCTX)sp);
  }
  acoef = r2.size(0);
  for (i = 0; i < acoef; i++) {
    r2[i] = r2[i] + dxTangential[i];
  }
  r4.set_size(&er_emlrtRTEI, sp, r2.size(0));
  acoef = r2.size(0);
  for (i = 0; i < acoef; i++) {
    r4[i] = r2[i] * r2[i];
  }
  if (r2.size(0) != r4.size(0)) {
    emlrtSizeEqCheck1DR2012b(r2.size(0), r4.size(0), &fd_emlrtECI,
                             (emlrtCTX)sp);
  }
  k_idx_0 = radialDistortion[0];
  k_idx_1 = radialDistortion[1];
  alpha.set_size(&fr_emlrtRTEI, sp, r2.size(0));
  acoef = r2.size(0);
  for (i = 0; i < acoef; i++) {
    alpha[i] = k_idx_0 * r2[i];
  }
  dxTangential.set_size(&gr_emlrtRTEI, sp, r4.size(0));
  acoef = r4.size(0);
  for (i = 0; i < acoef; i++) {
    dxTangential[i] = k_idx_1 * r4[i];
  }
  if (alpha.size(0) != dxTangential.size(0)) {
    emlrtSizeEqCheck1DR2012b(alpha.size(0), dxTangential.size(0), &gd_emlrtECI,
                             (emlrtCTX)sp);
  }
  r4.set_size(&hr_emlrtRTEI, sp, r2.size(0));
  acoef = r2.size(0);
  for (i = 0; i < acoef; i++) {
    r4[i] = radialDistortion[2] * (r2[i] * r4[i]);
  }
  if (alpha.size(0) != r4.size(0)) {
    emlrtSizeEqCheck1DR2012b(alpha.size(0), r4.size(0), &gd_emlrtECI,
                             (emlrtCTX)sp);
  }
  acoef = alpha.size(0);
  for (i = 0; i < acoef; i++) {
    alpha[i] = (alpha[i] + dxTangential[i]) + r4[i];
  }
  if (xNorm.size(0) != yNorm.size(0)) {
    emlrtSizeEqCheck1DR2012b(xNorm.size(0), yNorm.size(0), &hd_emlrtECI,
                             (emlrtCTX)sp);
  }
  xyProduct.set_size(&ir_emlrtRTEI, sp, xNorm.size(0));
  acoef = xNorm.size(0);
  for (i = 0; i < acoef; i++) {
    xyProduct[i] = xNorm[i] * yNorm[i];
  }
  st.site = &gab_emlrtRSI;
  power(&st, xNorm, r4);
  acoef = r4.size(0);
  for (i = 0; i < acoef; i++) {
    r4[i] = 2.0 * r4[i];
  }
  if (r2.size(0) != r4.size(0)) {
    emlrtSizeEqCheck1DR2012b(r2.size(0), r4.size(0), &id_emlrtECI,
                             (emlrtCTX)sp);
  }
  k_idx_0 = 2.0 * tangentialDistortion[0];
  dxTangential.set_size(&jr_emlrtRTEI, sp, xyProduct.size(0));
  acoef = xyProduct.size(0);
  for (i = 0; i < acoef; i++) {
    dxTangential[i] = k_idx_0 * xyProduct[i];
  }
  r4.set_size(&kr_emlrtRTEI, sp, r2.size(0));
  acoef = r2.size(0);
  for (i = 0; i < acoef; i++) {
    r4[i] = tangentialDistortion[1] * (r2[i] + r4[i]);
  }
  if (dxTangential.size(0) != r4.size(0)) {
    emlrtSizeEqCheck1DR2012b(dxTangential.size(0), r4.size(0), &jd_emlrtECI,
                             (emlrtCTX)sp);
  }
  acoef = dxTangential.size(0);
  for (i = 0; i < acoef; i++) {
    dxTangential[i] = dxTangential[i] + r4[i];
  }
  st.site = &hab_emlrtRSI;
  power(&st, yNorm, r4);
  acoef = r4.size(0);
  for (i = 0; i < acoef; i++) {
    r4[i] = 2.0 * r4[i];
  }
  if (r2.size(0) != r4.size(0)) {
    emlrtSizeEqCheck1DR2012b(r2.size(0), r4.size(0), &kd_emlrtECI,
                             (emlrtCTX)sp);
  }
  acoef = r2.size(0);
  for (i = 0; i < acoef; i++) {
    r2[i] = tangentialDistortion[0] * (r2[i] + r4[i]);
  }
  k_idx_0 = 2.0 * tangentialDistortion[1];
  acoef = xyProduct.size(0);
  for (i = 0; i < acoef; i++) {
    xyProduct[i] = k_idx_0 * xyProduct[i];
  }
  if (r2.size(0) != xyProduct.size(0)) {
    emlrtSizeEqCheck1DR2012b(r2.size(0), xyProduct.size(0), &ld_emlrtECI,
                             (emlrtCTX)sp);
  }
  acoef = r2.size(0);
  for (i = 0; i < acoef; i++) {
    r2[i] = r2[i] + xyProduct[i];
  }
  st.site = &iab_emlrtRSI;
  b_st.site = &bn_emlrtRSI;
  c_st.site = &cn_emlrtRSI;
  if (yNorm.size(0) != xNorm.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  centeredPoints.set_size(&lr_emlrtRTEI, &b_st, xNorm.size(0), 2);
  acoef = xNorm.size(0);
  for (i = 0; i < acoef; i++) {
    centeredPoints[i] = xNorm[i];
  }
  acoef = yNorm.size(0);
  for (i = 0; i < acoef; i++) {
    centeredPoints[i + centeredPoints.size(0)] = yNorm[i];
  }
  st.site = &jab_emlrtRSI;
  b_st.site = &bn_emlrtRSI;
  r.set_size(&mr_emlrtRTEI, &b_st, alpha.size(0), 2);
  acoef = alpha.size(0);
  for (i = 0; i < acoef; i++) {
    r[i] = alpha[i];
  }
  acoef = alpha.size(0);
  for (i = 0; i < acoef; i++) {
    r[i + r.size(0)] = alpha[i];
  }
  b_iv[0] = (*(int32_T(*)[2])centeredPoints.size())[0];
  b_iv[1] = (*(int32_T(*)[2])centeredPoints.size())[1];
  iv1[0] = (*(int32_T(*)[2])r.size())[0];
  iv1[1] = (*(int32_T(*)[2])r.size())[1];
  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &md_emlrtECI, (emlrtCTX)sp);
  acoef = centeredPoints.size(0) * 2;
  r.set_size(&nr_emlrtRTEI, sp, centeredPoints.size(0), 2);
  for (i = 0; i < acoef; i++) {
    r[i] = centeredPoints[i] * r[i];
  }
  b_iv[0] = (*(int32_T(*)[2])centeredPoints.size())[0];
  b_iv[1] = (*(int32_T(*)[2])centeredPoints.size())[1];
  iv1[0] = (*(int32_T(*)[2])r.size())[0];
  iv1[1] = (*(int32_T(*)[2])r.size())[1];
  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &nd_emlrtECI, (emlrtCTX)sp);
  st.site = &kab_emlrtRSI;
  b_st.site = &bn_emlrtRSI;
  c_st.site = &cn_emlrtRSI;
  if (r2.size(0) != dxTangential.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  r1.set_size(&or_emlrtRTEI, &b_st, dxTangential.size(0), 2);
  acoef = dxTangential.size(0);
  for (i = 0; i < acoef; i++) {
    r1[i] = dxTangential[i];
  }
  acoef = r2.size(0);
  for (i = 0; i < acoef; i++) {
    r1[i + r1.size(0)] = r2[i];
  }
  b_iv[0] = (*(int32_T(*)[2])centeredPoints.size())[0];
  b_iv[1] = (*(int32_T(*)[2])centeredPoints.size())[1];
  iv1[0] = (*(int32_T(*)[2])r1.size())[0];
  iv1[1] = (*(int32_T(*)[2])r1.size())[1];
  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &nd_emlrtECI, (emlrtCTX)sp);
  acoef = centeredPoints.size(0) * 2;
  centeredPoints.set_size(&pr_emlrtRTEI, sp, centeredPoints.size(0), 2);
  for (i = 0; i < acoef; i++) {
    centeredPoints[i] = (centeredPoints[i] + r[i]) + r1[i];
  }
  acoef = centeredPoints.size(0);
  xyProduct.set_size(&qr_emlrtRTEI, sp, centeredPoints.size(0));
  for (i = 0; i < acoef; i++) {
    xyProduct[i] = centeredPoints[i] * intrinsicMatrix[0];
  }
  acoef = centeredPoints.size(0);
  dxTangential.set_size(&rr_emlrtRTEI, sp, centeredPoints.size(0));
  for (i = 0; i < acoef; i++) {
    dxTangential[i] =
        intrinsicMatrix[1] * centeredPoints[i + centeredPoints.size(0)];
  }
  if (xyProduct.size(0) != dxTangential.size(0)) {
    emlrtSizeEqCheck1DR2012b(xyProduct.size(0), dxTangential.size(0),
                             &od_emlrtECI, (emlrtCTX)sp);
  }
  acoef = xyProduct.size(0);
  for (i = 0; i < acoef; i++) {
    xyProduct[i] = (xyProduct[i] + intrinsicMatrix[2]) + dxTangential[i];
  }
  acoef = centeredPoints.size(0);
  r4.set_size(&sr_emlrtRTEI, sp, centeredPoints.size(0));
  for (i = 0; i < acoef; i++) {
    r4[i] = centeredPoints[i + centeredPoints.size(0)] * intrinsicMatrix[4] +
            intrinsicMatrix[5];
  }
  st.site = &lab_emlrtRSI;
  b_st.site = &bn_emlrtRSI;
  c_st.site = &cn_emlrtRSI;
  if (r4.size(0) != xyProduct.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  distortedPoints.set_size(&tr_emlrtRTEI, &b_st, xyProduct.size(0), 2);
  acoef = xyProduct.size(0);
  for (i = 0; i < acoef; i++) {
    distortedPoints[i] = xyProduct[i];
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
