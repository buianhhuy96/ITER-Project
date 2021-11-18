//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// extrinsics.cpp
//
// Code generation for function 'extrinsics'
//

// Include files
#include "extrinsics.h"
#include "ComputeCamExtrinsics_mex_data.h"
#include "cameraParameters.h"
#include "fitgeotrans.h"
#include "mldivide.h"
#include "projective2d.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo eb_emlrtRSI{
    11,               // lineNo
    "validatefinite", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatefinite.m" // pathName
};

static emlrtRSInfo
    qw_emlrtRSI{
        115,          // lineNo
        "extrinsics", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extrinsics.m" // pathName
    };

static emlrtRSInfo
    rw_emlrtRSI{
        124,          // lineNo
        "extrinsics", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extrinsics.m" // pathName
    };

static emlrtRSInfo
    sw_emlrtRSI{
        126,          // lineNo
        "extrinsics", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extrinsics.m" // pathName
    };

static emlrtRSInfo tw_emlrtRSI{
    10,                         // lineNo
    "validateExtrinsicsInputs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "inputValidation\\validateExtrinsicsInputs.m" // pathName
};

static emlrtRSInfo uw_emlrtRSI{
    15,                         // lineNo
    "validateExtrinsicsInputs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "inputValidation\\validateExtrinsicsInputs.m" // pathName
};

static emlrtRSInfo vw_emlrtRSI{
    17,                 // lineNo
    "extrinsicsPlanar", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\extrinsicsPlanar.m" // pathName
};

static emlrtRSInfo ww_emlrtRSI{
    23,                 // lineNo
    "extrinsicsPlanar", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\extrinsicsPlanar.m" // pathName
};

static emlrtRSInfo xw_emlrtRSI{
    26,                 // lineNo
    "extrinsicsPlanar", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\extrinsicsPlanar.m" // pathName
};

static emlrtRSInfo yw_emlrtRSI{
    27,                 // lineNo
    "extrinsicsPlanar", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\extrinsicsPlanar.m" // pathName
};

static emlrtRSInfo ax_emlrtRSI{
    33,                 // lineNo
    "extrinsicsPlanar", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\extrinsicsPlanar.m" // pathName
};

static emlrtRSInfo bx_emlrtRSI{
    37,                 // lineNo
    "extrinsicsPlanar", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\extrinsicsPlanar.m" // pathName
};

static emlrtRSInfo cx_emlrtRSI{
    11,            // lineNo
    "fitgeotrans", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo dx_emlrtRSI{
    31,            // lineNo
    "fitgeotrans", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo ex_emlrtRSI{
    15,                      // lineNo
    "validateControlPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\validateControlPoints.m" // pathName
};

static emlrtRSInfo fx_emlrtRSI{
    16,                      // lineNo
    "validateControlPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\validateControlPoints.m" // pathName
};

static emlrtRTEInfo dc_emlrtRTEI{
    19,                      // lineNo
    55,                      // colNo
    "validateControlPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\validateControlPoints.m" // pName
};

static emlrtRTEInfo ec_emlrtRTEI{
    18,              // lineNo
    23,              // colNo
    "validatencols", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatencols.m" // pName
};

static emlrtRTEInfo fc_emlrtRTEI{
    31,                         // lineNo
    5,                          // colNo
    "validateExtrinsicsInputs", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "inputValidation\\validateExtrinsicsInputs.m" // pName
};

static emlrtRTEInfo gc_emlrtRTEI{
    24,                         // lineNo
    1,                          // colNo
    "validateExtrinsicsInputs", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "inputValidation\\validateExtrinsicsInputs.m" // pName
};

// Function Definitions
namespace coder {
void extrinsics(const emlrtStack *sp,
                const ::coder::array<real_T, 2U> &imagePoints,
                const ::coder::array<real_T, 2U> &worldPoints,
                const cameraParameters *cameraParams, real_T rotationMatrix[9],
                real_T translationVector[3])
{
  projective2d H;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T U[9];
  real_T V[9];
  real_T a__1[9];
  real_T b_H[9];
  real_T b_r1[9];
  real_T lambda[3];
  real_T r1[3];
  real_T r2[3];
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T i;
  int32_T k;
  uint32_T varargin_1[2];
  uint32_T varargin_2[2];
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &qw_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &tw_emlrtRSI;
  c_st.site = &x_emlrtRSI;
  d_st.site = &eb_emlrtRSI;
  p = true;
  i = imagePoints.size(0) * imagePoints.size(1);
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= i - 1)) {
    if ((!muDoubleScalarIsInf(imagePoints[k])) &&
        (!muDoubleScalarIsNaN(imagePoints[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:extrinsics:expectedFinite", 3, 4, 11, "imagePoints");
  }
  c_st.site = &x_emlrtRSI;
  if (imagePoints.size(1) != 2) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &ec_emlrtRTEI,
        "Coder:toolbox:ValidateattributesincorrectNumcols",
        "MATLAB:extrinsics:incorrectNumcols", 5, 4, 11, "imagePoints", 6, 2.0);
  }
  b_st.site = &uw_emlrtRSI;
  c_st.site = &x_emlrtRSI;
  d_st.site = &eb_emlrtRSI;
  p = true;
  i = worldPoints.size(0) * worldPoints.size(1);
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= i - 1)) {
    if ((!muDoubleScalarIsInf(worldPoints[k])) &&
        (!muDoubleScalarIsNaN(worldPoints[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:extrinsics:expectedFinite", 3, 4, 11, "worldPoints");
  }
  c_st.site = &x_emlrtRSI;
  if (worldPoints.size(1) != 2) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &ec_emlrtRTEI,
        "Coder:toolbox:ValidateattributesincorrectNumcols",
        "MATLAB:extrinsics:incorrectNumcols", 5, 4, 11, "worldPoints", 6, 2.0);
  }
  if (imagePoints.size(0) != worldPoints.size(0)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &gc_emlrtRTEI, "vision:calibrate:numberOfPointsMustMatch",
        "vision:calibrate:numberOfPointsMustMatch", 0);
  }
  if (worldPoints.size(0) < 4) {
    emlrtErrorWithMessageIdR2018a(
        &st, &fc_emlrtRTEI, "vision:calibrate:minNumWorldPoints",
        "vision:calibrate:minNumWorldPoints", 2, 6, 3.0);
  }
  st.site = &rw_emlrtRSI;
  st.site = &sw_emlrtRSI;
  b_st.site = &vw_emlrtRSI;
  c_st.site = &cx_emlrtRSI;
  d_st.site = &ex_emlrtRSI;
  e_st.site = &x_emlrtRSI;
  p = true;
  i = worldPoints.size(0) << 1;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= i - 1)) {
    if ((!muDoubleScalarIsInf(worldPoints[k])) &&
        (!muDoubleScalarIsNaN(worldPoints[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:validateControlPoints:expectedFinite", 3, 4, 12,
        "movingPoints");
  }
  d_st.site = &fx_emlrtRSI;
  e_st.site = &x_emlrtRSI;
  p = true;
  i = imagePoints.size(0) << 1;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= i - 1)) {
    if ((!muDoubleScalarIsInf(imagePoints[k])) &&
        (!muDoubleScalarIsNaN(imagePoints[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:validateControlPoints:expectedFinite", 3, 4, 11, "fixedPoints");
  }
  varargin_1[0] = static_cast<uint32_T>(worldPoints.size(0));
  varargin_2[0] = static_cast<uint32_T>(imagePoints.size(0));
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
        &c_st, &dc_emlrtRTEI, "images:geotrans:differentNumbersOfControlPoints",
        "images:geotrans:differentNumbersOfControlPoints", 6, 4, 11,
        "fixedPoints", 4, 12, "movingPoints");
  }
  c_st.site = &dx_emlrtRSI;
  findProjectiveTransform(&c_st, worldPoints, imagePoints, &H);
  for (i = 0; i < 3; i++) {
    b_H[3 * i] = H.T[i];
    b_H[3 * i + 1] = H.T[i + 3];
    b_H[3 * i + 2] = H.T[i + 6];
  }
  b_st.site = &ww_emlrtRSI;
  b_mldivide(&b_st, cameraParams->IntrinsicMatrixInternal,
             *(real_T(*)[3]) & b_H[0], r1);
  scale = 3.3121686421112381E-170;
  absxk = muDoubleScalarAbs(r1[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }
  absxk = muDoubleScalarAbs(r1[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }
  absxk = muDoubleScalarAbs(r1[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }
  y = scale * muDoubleScalarSqrt(y);
  scale = 1.0 / y;
  lambda[0] = scale * b_H[0];
  lambda[1] = scale * b_H[1];
  lambda[2] = scale * b_H[2];
  b_st.site = &xw_emlrtRSI;
  b_mldivide(&b_st, cameraParams->IntrinsicMatrixInternal, lambda, r1);
  lambda[0] = scale * b_H[3];
  lambda[1] = scale * b_H[4];
  lambda[2] = scale * b_H[5];
  b_st.site = &yw_emlrtRSI;
  b_mldivide(&b_st, cameraParams->IntrinsicMatrixInternal, lambda, r2);
  b_r1[0] = r1[0];
  b_r1[1] = r2[0];
  b_r1[3] = r1[1];
  b_r1[4] = r2[1];
  b_r1[6] = r1[2];
  b_r1[7] = r2[2];
  b_r1[2] = r1[1] * r2[2] - r2[1] * r1[2];
  b_r1[5] = r2[0] * r1[2] - r1[0] * r2[2];
  b_r1[8] = r1[0] * r2[1] - r2[0] * r1[1];
  b_st.site = &ax_emlrtRSI;
  svd(&b_st, b_r1, U, a__1, V);
  for (i = 0; i < 3; i++) {
    absxk = U[i];
    t = U[i + 3];
    y = U[i + 6];
    for (k = 0; k < 3; k++) {
      rotationMatrix[i + 3 * k] = (absxk * V[k] + t * V[k + 3]) + y * V[k + 6];
    }
    lambda[i] = scale * b_H[i + 6];
  }
  b_st.site = &bx_emlrtRSI;
  b_mldivide(&b_st, cameraParams->IntrinsicMatrixInternal, lambda, r1);
  translationVector[0] = r1[0];
  translationVector[1] = r1[1];
  translationVector[2] = r1[2];
}

} // namespace coder

// End of code generation (extrinsics.cpp)
