//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// cameraParameters.cpp
//
// Code generation for function 'cameraParameters'
//

// Include files
#include "cameraParameters.h"
#include "calibrateOneCamera_mex_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo xw_emlrtRSI{
    6,                       // lineNo
    "HandleBase/HandleBase", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "enforcescalar\\HandleBase.m" // pathName
};

static emlrtRSInfo hx_emlrtRSI{
    367,                                       // lineNo
    "CameraParametersImpl/parseInputsCodegen", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo ix_emlrtRSI{
    372,                                       // lineNo
    "CameraParametersImpl/parseInputsCodegen", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo kx_emlrtRSI{
    554,                                         // lineNo
    "CameraParametersImpl/checkIntrinsicMatrix", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo lx_emlrtRSI{
    562,                                          // lineNo
    "CameraParametersImpl/checkRadialDistortion", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo mx_emlrtRSI{
    572,                                              // lineNo
    "CameraParametersImpl/checkTangentialDistortion", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo ox_emlrtRSI{
    582,                                   // lineNo
    "CameraParametersImpl/checkImageSize", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo px_emlrtRSI{
    592,                                         // lineNo
    "CameraParametersImpl/checkRotationVectors", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo qx_emlrtRSI{
    602,                                            // lineNo
    "CameraParametersImpl/checkTranslationVectors", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo rx_emlrtRSI{
    637,                                         // lineNo
    "CameraParametersImpl/checkNumRadialCoeffs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo tx_emlrtRSI{
    314,                             // lineNo
    "CameraParametersImpl/toStruct", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRTEInfo ac_emlrtRTEI{
    284,                                         // lineNo
    13,                                          // colNo
    "CameraParametersImpl/CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

static emlrtRTEInfo bc_emlrtRTEI{
    290,                                         // lineNo
    13,                                          // colNo
    "CameraParametersImpl/CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

static emlrtRTEInfo cc_emlrtRTEI{
    22,           // lineNo
    27,           // colNo
    "validatege", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatege.m" // pName
};

static emlrtRTEInfo dc_emlrtRTEI{
    22,           // lineNo
    27,           // colNo
    "validatele", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatele.m" // pName
};

static emlrtRTEInfo fq_emlrtRTEI{
    365,                    // lineNo
    13,                     // colNo
    "CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

static emlrtRTEInfo gq_emlrtRTEI{
    368,                    // lineNo
    17,                     // colNo
    "CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

static emlrtRTEInfo hq_emlrtRTEI{
    370,                    // lineNo
    13,                     // colNo
    "CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

static emlrtRTEInfo iq_emlrtRTEI{
    373,                    // lineNo
    17,                     // colNo
    "CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

static emlrtRTEInfo jq_emlrtRTEI{
    375,                    // lineNo
    13,                     // colNo
    "CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

static emlrtRTEInfo kq_emlrtRTEI{
    314,                    // lineNo
    13,                     // colNo
    "CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

// Function Definitions
namespace Codegen {
namespace coder {
void b_cameraParameters::checkImageSize(const emlrtStack *sp,
                                        const real_T imageSize[2])
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &ox_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(imageSize[k])) &&
        (!muDoubleScalarIsNaN(imageSize[k])) &&
        (muDoubleScalarFloor(imageSize[k]) == imageSize[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &k_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:CameraParametersImpl:expectedInteger", 3, 4, 9, "imageSize");
  }
  b_st.site = &p_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(imageSize[k] <= 0.0)) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:CameraParametersImpl:expectedPositive", 3, 4, 9, "imageSize");
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void cameraParameters::checkIntrinsicMatrix(const emlrtStack *sp,
                                            const real_T IntrinsicMatrix[9])
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kx_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &p_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if ((!muDoubleScalarIsInf(IntrinsicMatrix[k])) &&
        (!muDoubleScalarIsNaN(IntrinsicMatrix[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &g_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:cameraParameters:expectedFinite", 3, 4, 15, "IntrinsicMatrix");
  }
}

void cameraParameters::checkNumRadialCoeffs(const emlrtStack *sp,
                                            real_T numRadialCoeffs)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &rx_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &p_emlrtRSI;
  if (muDoubleScalarIsInf(numRadialCoeffs) ||
      muDoubleScalarIsNaN(numRadialCoeffs) ||
      (!(muDoubleScalarFloor(numRadialCoeffs) == numRadialCoeffs))) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &k_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:cameraParameters:expectedInteger", 3, 4, 31,
        "NumRadialDistortionCoefficients");
  }
  b_st.site = &p_emlrtRSI;
  if (!(numRadialCoeffs >= 2.0)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &cc_emlrtRTEI, "MATLAB:validateattributes:expectedScalar",
        "MATLAB:cameraParameters:notGreaterEqual", 9, 4, 31,
        "NumRadialDistortionCoefficients", 4, 2, ">=", 4, 1, "2");
  }
  b_st.site = &p_emlrtRSI;
  if (!(numRadialCoeffs <= 3.0)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &dc_emlrtRTEI, "MATLAB:validateattributes:expectedScalar",
        "MATLAB:cameraParameters:notLessEqual", 9, 4, 31,
        "NumRadialDistortionCoefficients", 4, 2, "<=", 4, 1, "3");
  }
}

void cameraParameters::checkRadialDistortion(const emlrtStack *sp,
                                             const real_T radialDistortion[3])
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &lx_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &p_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if ((!muDoubleScalarIsInf(radialDistortion[k])) &&
        (!muDoubleScalarIsNaN(radialDistortion[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &g_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:cameraParameters:expectedFinite", 3, 4, 16, "RadialDistortion");
  }
}

void cameraParameters::checkTangentialDistortion(
    const emlrtStack *sp, const real_T tangentialDistortion[2])
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &mx_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &p_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(tangentialDistortion[k])) &&
        (!muDoubleScalarIsNaN(tangentialDistortion[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &g_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:cameraParameters:expectedFinite", 3, 4, 20,
        "TangentialDistortion");
  }
}

cameraParameters *cameraParameters::init(const emlrtStack *sp,
                                         const real_T varargin_2[2])
{
  cameraParameters *this_;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T b_this[2];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  this_ = this;
  st.site = &yw_emlrtRSI;
  b_st.site = &ww_emlrtRSI;
  st.site = &ax_emlrtRSI;
  for (int32_T i{0}; i < 9; i++) {
    this_->IntrinsicMatrixInternal[i] = iv[i];
  }
  this_->RadialDistortion[0] = 0.0;
  this_->RadialDistortion[1] = 0.0;
  this_->RadialDistortion[2] = 0.0;
  b_st.site = &dx_emlrtRSI;
  cameraParameters::checkRadialDistortion(&b_st, this_->RadialDistortion);
  this_->TangentialDistortion[0] = 0.0;
  this_->TangentialDistortion[1] = 0.0;
  b_st.site = &ex_emlrtRSI;
  cameraParameters::checkTangentialDistortion(&b_st,
                                              this_->TangentialDistortion);
  b_st.site = &fx_emlrtRSI;
  c_st.site = &nx_emlrtRSI;
  b_cameraParameters::checkImageSize(&c_st, varargin_2);
  this_->ImageSize[0] = varargin_2[0];
  this_->ImageSize[1] = varargin_2[1];
  b_this[0] = this_->ImageSize[0];
  b_this[1] = this_->ImageSize[1];
  b_st.site = &gx_emlrtRSI;
  b_cameraParameters::checkImageSize(&b_st, b_this);
  this_->WorldUnits[0] = 'm';
  this_->WorldUnits[1] = 'm';
  this_->EstimateSkew = false;
  this_->NumRadialDistortionCoefficients = 2.0;
  b_st.site = &jx_emlrtRSI;
  cameraParameters::checkNumRadialCoeffs(
      &b_st, this_->NumRadialDistortionCoefficients);
  this_->EstimateTangentialDistortion = false;
  st.site = &bx_emlrtRSI;
  b_st.site = &sx_emlrtRSI;
  return this_;
}

b_cameraParameters *
b_cameraParameters::init(const emlrtStack *sp, const real_T varargin_2[9],
                         const ::coder::array<real_T, 2U> &varargin_4,
                         const ::coder::array<real_T, 2U> &varargin_6,
                         const ::coder::array<real_T, 2U> &varargin_8,
                         const real_T varargin_20[2])
{
  b_cameraParameters *this_;
  ::coder::array<real_T, 2U> rotationVectors;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T b_this[2];
  int32_T i;
  int32_T loop_ub;
  boolean_T x[2];
  boolean_T exitg1;
  boolean_T guard1{false};
  boolean_T guard2{false};
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
  this_ = this;
  st.site = &yw_emlrtRSI;
  b_st.site = &ww_emlrtRSI;
  c_st.site = &xw_emlrtRSI;
  st.site = &ax_emlrtRSI;
  b_st.site = &cx_emlrtRSI;
  cameraParameters::checkIntrinsicMatrix(&b_st, varargin_2);
  for (i = 0; i < 3; i++) {
    this_->IntrinsicMatrixInternal[3 * i] = varargin_2[i];
    this_->IntrinsicMatrixInternal[3 * i + 1] = varargin_2[i + 3];
    this_->IntrinsicMatrixInternal[3 * i + 2] = varargin_2[i + 6];
  }
  this_->RadialDistortion[0] = 0.0;
  this_->RadialDistortion[1] = 0.0;
  this_->RadialDistortion[2] = 0.0;
  b_st.site = &dx_emlrtRSI;
  cameraParameters::checkRadialDistortion(&b_st, this_->RadialDistortion);
  this_->TangentialDistortion[0] = 0.0;
  this_->TangentialDistortion[1] = 0.0;
  b_st.site = &ex_emlrtRSI;
  cameraParameters::checkTangentialDistortion(&b_st,
                                              this_->TangentialDistortion);
  b_st.site = &fx_emlrtRSI;
  c_st.site = &nx_emlrtRSI;
  b_cameraParameters::checkImageSize(&c_st, varargin_20);
  this_->ImageSize[0] = varargin_20[0];
  this_->ImageSize[1] = varargin_20[1];
  b_this[0] = this_->ImageSize[0];
  b_this[1] = this_->ImageSize[1];
  b_st.site = &gx_emlrtRSI;
  b_cameraParameters::checkImageSize(&b_st, b_this);
  this_->RotationVectors.set_size(&fq_emlrtRTEI, &st, varargin_4.size(0), 3);
  loop_ub = varargin_4.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    this_->RotationVectors[i] = varargin_4[i];
  }
  b_st.site = &hx_emlrtRSI;
  rotationVectors.set_size(&gq_emlrtRTEI, &b_st, this_->RotationVectors.size(0),
                           3);
  loop_ub = this_->RotationVectors.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    rotationVectors[i] = this_->RotationVectors[i];
  }
  if (rotationVectors.size(0) != 0) {
    c_st.site = &px_emlrtRSI;
    d_st.site = &p_emlrtRSI;
    p = true;
    i = rotationVectors.size(0) * 3;
    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub <= i - 1)) {
      if ((!muDoubleScalarIsInf(rotationVectors[loop_ub])) &&
          (!muDoubleScalarIsNaN(rotationVectors[loop_ub]))) {
        loop_ub++;
      } else {
        p = false;
        exitg1 = true;
      }
    }
    if (!p) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &g_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
          "MATLAB:cameraParameters:expectedFinite", 3, 4, 15,
          "RotationVectors");
    }
  }
  this_->TranslationVectors.set_size(&hq_emlrtRTEI, &st, varargin_6.size(0), 3);
  loop_ub = varargin_6.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    this_->TranslationVectors[i] = varargin_6[i];
  }
  b_st.site = &ix_emlrtRSI;
  rotationVectors.set_size(&iq_emlrtRTEI, &b_st,
                           this_->TranslationVectors.size(0), 3);
  loop_ub = this_->TranslationVectors.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    rotationVectors[i] = this_->TranslationVectors[i];
  }
  if (rotationVectors.size(0) != 0) {
    c_st.site = &qx_emlrtRSI;
    d_st.site = &p_emlrtRSI;
    p = true;
    i = rotationVectors.size(0) * 3;
    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub <= i - 1)) {
      if ((!muDoubleScalarIsInf(rotationVectors[loop_ub])) &&
          (!muDoubleScalarIsNaN(rotationVectors[loop_ub]))) {
        loop_ub++;
      } else {
        p = false;
        exitg1 = true;
      }
    }
    if (!p) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &g_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
          "MATLAB:cameraParameters:expectedFinite", 3, 4, 18,
          "TranslationVectors");
    }
  }
  this_->WorldPoints.set_size(&jq_emlrtRTEI, &st, varargin_8.size(0), 2);
  loop_ub = varargin_8.size(0) * 2;
  for (i = 0; i < loop_ub; i++) {
    this_->WorldPoints[i] = varargin_8[i];
  }
  this_->WorldUnits = 'm';
  this_->EstimateSkew = false;
  this_->NumRadialDistortionCoefficients = 3.0;
  b_st.site = &jx_emlrtRSI;
  cameraParameters::checkNumRadialCoeffs(
      &b_st, this_->NumRadialDistortionCoefficients);
  this_->EstimateTangentialDistortion = false;
  p = (this_->RotationVectors.size(0) == 0);
  guard1 = false;
  guard2 = false;
  if (p) {
    p = (this_->TranslationVectors.size(0) == 0);
    if (!p) {
      guard1 = true;
    } else {
      guard2 = true;
    }
  } else {
    guard2 = true;
  }
  if (guard2) {
    p = (this_->TranslationVectors.size(0) == 0);
    if (p) {
      p = (this_->RotationVectors.size(0) == 0);
      if (!p) {
        guard1 = true;
      }
    }
  }
  if (guard1) {
    emlrtErrorWithMessageIdR2018a(
        sp, &ac_emlrtRTEI,
        "vision:calibrate:rotationAndTranslationVectorsMustBeSetTogether",
        "vision:calibrate:rotationAndTranslationVectorsMustBeSetTogether", 0);
  }
  x[0] = (this_->RotationVectors.size(0) != this_->TranslationVectors.size(0));
  x[1] = false;
  p = false;
  loop_ub = 0;
  exitg1 = false;
  while ((!exitg1) && (loop_ub < 2)) {
    if (x[loop_ub]) {
      p = true;
      exitg1 = true;
    } else {
      loop_ub++;
    }
  }
  if (p) {
    emlrtErrorWithMessageIdR2018a(
        sp, &bc_emlrtRTEI,
        "vision:calibrate:rotationAndTranslationVectorsNotSameSize",
        "vision:calibrate:rotationAndTranslationVectorsNotSameSize", 0);
  }
  st.site = &bx_emlrtRSI;
  b_st.site = &sx_emlrtRSI;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return this_;
}

void cameraParameters::toStruct(real_T paramStruct_RadialDistortion[3],
                                real_T c_paramStruct_TangentialDistort[2],
                                real_T paramStruct_ImageSize[2],
                                char_T paramStruct_WorldUnits[2],
                                boolean_T *paramStruct_EstimateSkew,
                                real_T *c_paramStruct_NumRadialDistorti,
                                boolean_T *c_paramStruct_EstimateTangentia,
                                real_T paramStruct_IntrinsicMatrix[9]) const
{
  paramStruct_RadialDistortion[0] = RadialDistortion[0];
  paramStruct_RadialDistortion[1] = RadialDistortion[1];
  paramStruct_RadialDistortion[2] = RadialDistortion[2];
  c_paramStruct_TangentialDistort[0] = TangentialDistortion[0];
  paramStruct_ImageSize[0] = ImageSize[0];
  paramStruct_WorldUnits[0] = WorldUnits[0];
  c_paramStruct_TangentialDistort[1] = TangentialDistortion[1];
  paramStruct_ImageSize[1] = ImageSize[1];
  paramStruct_WorldUnits[1] = WorldUnits[1];
  *paramStruct_EstimateSkew = EstimateSkew;
  *c_paramStruct_NumRadialDistorti = NumRadialDistortionCoefficients;
  *c_paramStruct_EstimateTangentia = EstimateTangentialDistortion;
  for (int32_T i{0}; i < 3; i++) {
    paramStruct_IntrinsicMatrix[3 * i] = IntrinsicMatrixInternal[i];
    paramStruct_IntrinsicMatrix[3 * i + 1] = IntrinsicMatrixInternal[i + 3];
    paramStruct_IntrinsicMatrix[3 * i + 2] = IntrinsicMatrixInternal[i + 6];
  }
}

void b_cameraParameters::toStruct(
    const emlrtStack *sp, real_T paramStruct_RadialDistortion[3],
    real_T c_paramStruct_TangentialDistort[2], real_T paramStruct_ImageSize[2],
    ::coder::array<real_T, 2U> &paramStruct_WorldPoints,
    char_T *paramStruct_WorldUnits, boolean_T *paramStruct_EstimateSkew,
    real_T *c_paramStruct_NumRadialDistorti,
    boolean_T *c_paramStruct_EstimateTangentia,
    ::coder::array<real_T, 2U> &paramStruct_RotationVectors,
    ::coder::array<real_T, 2U> &paramStruct_TranslationVectors,
    real_T paramStruct_IntrinsicMatrix[9]) const
{
  emlrtStack st;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &tx_emlrtRSI;
  paramStruct_RadialDistortion[0] = RadialDistortion[0];
  paramStruct_RadialDistortion[1] = RadialDistortion[1];
  paramStruct_RadialDistortion[2] = RadialDistortion[2];
  c_paramStruct_TangentialDistort[0] = TangentialDistortion[0];
  paramStruct_ImageSize[0] = ImageSize[0];
  c_paramStruct_TangentialDistort[1] = TangentialDistortion[1];
  paramStruct_ImageSize[1] = ImageSize[1];
  paramStruct_WorldPoints.set_size(&kq_emlrtRTEI, &st, WorldPoints.size(0), 2);
  loop_ub = WorldPoints.size(0) * 2;
  for (i = 0; i < loop_ub; i++) {
    paramStruct_WorldPoints[i] = WorldPoints[i];
  }
  paramStruct_RotationVectors.set_size(&kq_emlrtRTEI, &st,
                                       RotationVectors.size(0), 3);
  loop_ub = RotationVectors.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    paramStruct_RotationVectors[i] = RotationVectors[i];
  }
  paramStruct_TranslationVectors.set_size(&kq_emlrtRTEI, &st,
                                          TranslationVectors.size(0), 3);
  loop_ub = TranslationVectors.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    paramStruct_TranslationVectors[i] = TranslationVectors[i];
  }
  for (i = 0; i < 3; i++) {
    paramStruct_IntrinsicMatrix[3 * i] = IntrinsicMatrixInternal[i];
    paramStruct_IntrinsicMatrix[3 * i + 1] = IntrinsicMatrixInternal[i + 3];
    paramStruct_IntrinsicMatrix[3 * i + 2] = IntrinsicMatrixInternal[i + 6];
  }
  *paramStruct_WorldUnits = WorldUnits;
  *paramStruct_EstimateSkew = EstimateSkew;
  *c_paramStruct_NumRadialDistorti = NumRadialDistortionCoefficients;
  *c_paramStruct_EstimateTangentia = EstimateTangentialDistortion;
}

} // namespace coder
} // namespace Codegen

// End of code generation (cameraParameters.cpp)
