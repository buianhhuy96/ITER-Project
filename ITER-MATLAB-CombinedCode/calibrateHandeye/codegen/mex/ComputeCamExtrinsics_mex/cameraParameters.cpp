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
#include "ComputeCamExtrinsics_mex_data.h"
#include "ImageTransformer.h"
#include "any1.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo w_emlrtRSI{
    554,                                         // lineNo
    "CameraParametersImpl/checkIntrinsicMatrix", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo y_emlrtRSI{
    562,                                          // lineNo
    "CameraParametersImpl/checkRadialDistortion", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo ab_emlrtRSI{
    572,                                              // lineNo
    "CameraParametersImpl/checkTangentialDistortion", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo cb_emlrtRSI{
    582,                                   // lineNo
    "CameraParametersImpl/checkImageSize", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo db_emlrtRSI{
    592,                                         // lineNo
    "CameraParametersImpl/checkRotationVectors", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo fb_emlrtRSI{
    602,                                            // lineNo
    "CameraParametersImpl/checkTranslationVectors", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo gb_emlrtRSI{
    637,                                         // lineNo
    "CameraParametersImpl/checkNumRadialCoeffs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRTEInfo h_emlrtRTEI{
    22,           // lineNo
    27,           // colNo
    "validatege", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatege.m" // pName
};

static emlrtRTEInfo i_emlrtRTEI{
    22,           // lineNo
    27,           // colNo
    "validatele", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatele.m" // pName
};

static emlrtRTEInfo su_emlrtRTEI{
    368,                    // lineNo
    17,                     // colNo
    "CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

static emlrtRTEInfo tu_emlrtRTEI{
    373,                    // lineNo
    17,                     // colNo
    "CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

static emlrtRTEInfo uu_emlrtRTEI{
    45,                 // lineNo
    13,                 // colNo
    "ImageTransformer", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pName
};

static emlrtRTEInfo vu_emlrtRTEI{
    46,                 // lineNo
    13,                 // colNo
    "ImageTransformer", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pName
};

static emlrtRTEInfo wu_emlrtRTEI{
    47,                 // lineNo
    13,                 // colNo
    "ImageTransformer", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pName
};

static emlrtRTEInfo xu_emlrtRTEI{
    48,                 // lineNo
    13,                 // colNo
    "ImageTransformer", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pName
};

static emlrtRTEInfo yu_emlrtRTEI{
    49,                 // lineNo
    13,                 // colNo
    "ImageTransformer", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pName
};

static emlrtRTEInfo av_emlrtRTEI{
    50,                 // lineNo
    13,                 // colNo
    "ImageTransformer", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pName
};

static emlrtRTEInfo bv_emlrtRTEI{
    55,                 // lineNo
    13,                 // colNo
    "ImageTransformer", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pName
};

static emlrtRTEInfo cv_emlrtRTEI{
    56,                 // lineNo
    13,                 // colNo
    "ImageTransformer", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pName
};

// Function Definitions
namespace coder {
void cameraParameters::checkImageSize(const emlrtStack *sp,
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
  st.site = &cb_emlrtRSI;
  b_st.site = &x_emlrtRSI;
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
        &b_st, &f_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:CameraParametersImpl:expectedInteger", 3, 4, 9, "imageSize");
  }
  b_st.site = &x_emlrtRSI;
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
        &b_st, &g_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
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
  st.site = &w_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &x_emlrtRSI;
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
        &b_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
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
  st.site = &gb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &x_emlrtRSI;
  if (muDoubleScalarIsInf(numRadialCoeffs) ||
      muDoubleScalarIsNaN(numRadialCoeffs) ||
      (!(muDoubleScalarFloor(numRadialCoeffs) == numRadialCoeffs))) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &f_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:cameraParameters:expectedInteger", 3, 4, 31,
        "NumRadialDistortionCoefficients");
  }
  b_st.site = &x_emlrtRSI;
  if (!(numRadialCoeffs >= 2.0)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &h_emlrtRTEI, "MATLAB:validateattributes:expectedScalar",
        "MATLAB:cameraParameters:notGreaterEqual", 9, 4, 31,
        "NumRadialDistortionCoefficients", 4, 2, ">=", 4, 1, "2");
  }
  b_st.site = &x_emlrtRSI;
  if (!(numRadialCoeffs <= 3.0)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &i_emlrtRTEI, "MATLAB:validateattributes:expectedScalar",
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
  st.site = &y_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &x_emlrtRSI;
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
        &b_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:cameraParameters:expectedFinite", 3, 4, 16, "RadialDistortion");
  }
}

void cameraParameters::checkRotationVectors(
    const emlrtStack *sp, const ::coder::array<real_T, 2U> &rotationVectors)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (rotationVectors.size(0) != 0) {
    int32_T i;
    int32_T k;
    boolean_T exitg1;
    boolean_T p;
    st.site = &db_emlrtRSI;
    b_st.site = &x_emlrtRSI;
    p = true;
    i = rotationVectors.size(0) * 3;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= i - 1)) {
      if ((!muDoubleScalarIsInf(rotationVectors[k])) &&
          (!muDoubleScalarIsNaN(rotationVectors[k]))) {
        k++;
      } else {
        p = false;
        exitg1 = true;
      }
    }
    if (!p) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
          "MATLAB:cameraParameters:expectedFinite", 3, 4, 15,
          "RotationVectors");
    }
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
  st.site = &ab_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &x_emlrtRSI;
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
        &b_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:cameraParameters:expectedFinite", 3, 4, 20,
        "TangentialDistortion");
  }
}

void cameraParameters::checkTranslationVectors(
    const emlrtStack *sp, const ::coder::array<real_T, 2U> &translationVectors)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (translationVectors.size(0) != 0) {
    int32_T i;
    int32_T k;
    boolean_T exitg1;
    boolean_T p;
    st.site = &fb_emlrtRSI;
    b_st.site = &x_emlrtRSI;
    p = true;
    i = translationVectors.size(0) * 3;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= i - 1)) {
      if ((!muDoubleScalarIsInf(translationVectors[k])) &&
          (!muDoubleScalarIsNaN(translationVectors[k]))) {
        k++;
      } else {
        p = false;
        exitg1 = true;
      }
    }
    if (!p) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
          "MATLAB:cameraParameters:expectedFinite", 3, 4, 18,
          "TranslationVectors");
    }
  }
}

b_cameraParameters *b_cameraParameters::init(
    const emlrtStack *sp, const real_T varargin_1_RadialDistortion[3],
    const real_T varargin_1_TangentialDistortion[2],
    const real_T varargin_1_ImageSize[2],
    const ::coder::array<real_T, 2U> &varargin_1_WorldPoints,
    real_T c_varargin_1_NumRadialDistortio,
    const ::coder::array<real_T, 2U> &varargin_1_RotationVectors,
    const ::coder::array<real_T, 2U> &varargin_1_TranslationVectors,
    const ::coder::array<real_T, 3U> &varargin_1_ReprojectionErrors,
    const real_T varargin_1_IntrinsicMatrix[9],
    const ::coder::array<boolean_T, 2U> &varargin_1_DetectedKeypoints)
{
  static const char_T b_cv[5]{'u', 'i', 'n', 't', '8'};
  b_cameraParameters *this_;
  array<real_T, 2U> c_this;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T b_this[2];
  int32_T i;
  int32_T loop_ub;
  boolean_T d_this[2];
  boolean_T b;
  boolean_T b1;
  boolean_T guard1{false};
  boolean_T guard2{false};
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  this_ = this;
  st.site = &h_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  st.site = &i_emlrtRSI;
  b_st.site = &n_emlrtRSI;
  cameraParameters::checkIntrinsicMatrix(&b_st, varargin_1_IntrinsicMatrix);
  for (i = 0; i < 3; i++) {
    this_->IntrinsicMatrixInternal[3 * i] = varargin_1_IntrinsicMatrix[i];
    this_->IntrinsicMatrixInternal[3 * i + 1] =
        varargin_1_IntrinsicMatrix[i + 3];
    this_->IntrinsicMatrixInternal[3 * i + 2] =
        varargin_1_IntrinsicMatrix[i + 6];
  }
  this_->RadialDistortion[0] = varargin_1_RadialDistortion[0];
  this_->RadialDistortion[1] = varargin_1_RadialDistortion[1];
  this_->RadialDistortion[2] = varargin_1_RadialDistortion[2];
  b_st.site = &o_emlrtRSI;
  cameraParameters::checkRadialDistortion(&b_st, this_->RadialDistortion);
  this_->TangentialDistortion[0] = varargin_1_TangentialDistortion[0];
  this_->TangentialDistortion[1] = varargin_1_TangentialDistortion[1];
  b_st.site = &p_emlrtRSI;
  cameraParameters::checkTangentialDistortion(&b_st,
                                              this_->TangentialDistortion);
  b_st.site = &q_emlrtRSI;
  c_st.site = &bb_emlrtRSI;
  cameraParameters::checkImageSize(&c_st, varargin_1_ImageSize);
  this_->ImageSize[0] = varargin_1_ImageSize[0];
  this_->ImageSize[1] = varargin_1_ImageSize[1];
  b_this[0] = this_->ImageSize[0];
  b_this[1] = this_->ImageSize[1];
  b_st.site = &r_emlrtRSI;
  cameraParameters::checkImageSize(&b_st, b_this);
  this_->RotationVectors.set_size(&xc_emlrtRTEI, &st,
                                  varargin_1_RotationVectors.size(0), 3);
  loop_ub = varargin_1_RotationVectors.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    this_->RotationVectors[i] = varargin_1_RotationVectors[i];
  }
  c_this.set_size(&su_emlrtRTEI, &st, this_->RotationVectors.size(0), 3);
  loop_ub = this_->RotationVectors.size(0) * this_->RotationVectors.size(1) - 1;
  for (i = 0; i <= loop_ub; i++) {
    c_this[i] = this_->RotationVectors[i];
  }
  b_st.site = &s_emlrtRSI;
  cameraParameters::checkRotationVectors(&b_st, c_this);
  this_->TranslationVectors.set_size(&yc_emlrtRTEI, &st,
                                     varargin_1_TranslationVectors.size(0), 3);
  loop_ub = varargin_1_TranslationVectors.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    this_->TranslationVectors[i] = varargin_1_TranslationVectors[i];
  }
  c_this.set_size(&tu_emlrtRTEI, &st, this_->TranslationVectors.size(0), 3);
  loop_ub =
      this_->TranslationVectors.size(0) * this_->TranslationVectors.size(1) - 1;
  for (i = 0; i <= loop_ub; i++) {
    c_this[i] = this_->TranslationVectors[i];
  }
  b_st.site = &t_emlrtRSI;
  cameraParameters::checkTranslationVectors(&b_st, c_this);
  this_->WorldPoints.set_size(&ad_emlrtRTEI, &st,
                              varargin_1_WorldPoints.size(0), 2);
  loop_ub = varargin_1_WorldPoints.size(0) * 2;
  for (i = 0; i < loop_ub; i++) {
    this_->WorldPoints[i] = varargin_1_WorldPoints[i];
  }
  this_->NumRadialDistortionCoefficients = c_varargin_1_NumRadialDistortio;
  b_st.site = &u_emlrtRSI;
  cameraParameters::checkNumRadialCoeffs(
      &b_st, this_->NumRadialDistortionCoefficients);
  this_->DetectedKeypoints.set_size(&bd_emlrtRTEI, &st,
                                    varargin_1_DetectedKeypoints.size(0),
                                    varargin_1_DetectedKeypoints.size(1));
  loop_ub = varargin_1_DetectedKeypoints.size(0) *
            varargin_1_DetectedKeypoints.size(1);
  for (i = 0; i < loop_ub; i++) {
    this_->DetectedKeypoints[i] = varargin_1_DetectedKeypoints[i];
  }
  if ((varargin_1_ReprojectionErrors.size(0) == 0) ||
      (varargin_1_ReprojectionErrors.size(2) == 0)) {
    this_->ReprojectionErrors.set_size(&dd_emlrtRTEI, &st, 0, 2, 1);
  } else {
    this_->ReprojectionErrors.set_size(&cd_emlrtRTEI, &st,
                                       varargin_1_ReprojectionErrors.size(0), 2,
                                       varargin_1_ReprojectionErrors.size(2));
    loop_ub = varargin_1_ReprojectionErrors.size(0) * 2 *
              varargin_1_ReprojectionErrors.size(2);
    for (i = 0; i < loop_ub; i++) {
      this_->ReprojectionErrors[i] = varargin_1_ReprojectionErrors[i];
    }
  }
  b_st.site = &v_emlrtRSI;
  b = (this_->RotationVectors.size(0) == 0);
  guard1 = false;
  guard2 = false;
  if (b) {
    b = (this_->TranslationVectors.size(0) == 0);
    if (!b) {
      guard1 = true;
    } else {
      guard2 = true;
    }
  } else {
    guard2 = true;
  }
  if (guard2) {
    b = (this_->TranslationVectors.size(0) == 0);
    if (b) {
      b = (this_->RotationVectors.size(0) == 0);
      if (!b) {
        guard1 = true;
      }
    }
  }
  if (guard1) {
    emlrtErrorWithMessageIdR2018a(
        sp, &c_emlrtRTEI,
        "vision:calibrate:rotationAndTranslationVectorsMustBeSetTogether",
        "vision:calibrate:rotationAndTranslationVectorsMustBeSetTogether", 0);
  }
  d_this[0] =
      (this_->RotationVectors.size(0) != this_->TranslationVectors.size(0));
  d_this[1] = false;
  st.site = &j_emlrtRSI;
  if (any(d_this)) {
    emlrtErrorWithMessageIdR2018a(
        sp, &b_emlrtRTEI,
        "vision:calibrate:rotationAndTranslationVectorsNotSameSize",
        "vision:calibrate:rotationAndTranslationVectorsNotSameSize", 0);
  }
  b = (this_->ReprojectionErrors.size(0) == 0);
  b1 = (this_->ReprojectionErrors.size(2) == 0);
  if ((!b) && (!b1) &&
      (this_->TranslationVectors.size(0) !=
       this_->ReprojectionErrors.size(2))) {
    emlrtErrorWithMessageIdR2018a(
        sp, &emlrtRTEI, "vision:calibrate:reprojectionErrorsSizeMismatch",
        "vision:calibrate:reprojectionErrorsSizeMismatch", 0);
  }
  st.site = &k_emlrtRSI;
  this_->UndistortMap.XBounds[0] = -1.0;
  this_->UndistortMap.XBounds[1] = -1.0;
  this_->UndistortMap.YBounds[0] = -1.0;
  this_->UndistortMap.YBounds[1] = -1.0;
  b_st.site = &kb_emlrtRSI;
  this_->UndistortMap.SizeOfImage.set_size(&uu_emlrtRTEI, &st, 1, 2);
  this_->UndistortMap.SizeOfImage[0] = 0.0;
  this_->UndistortMap.SizeOfImage[1] = 0.0;
  this_->UndistortMap.SizeOfImage.set_size(&vu_emlrtRTEI, &st, 1, 3);
  this_->UndistortMap.SizeOfImage[0] = 0.0;
  this_->UndistortMap.SizeOfImage[1] = 0.0;
  this_->UndistortMap.SizeOfImage[2] = 0.0;
  this_->UndistortMap.ClassOfImage.set_size(&wu_emlrtRTEI, &st, 1, 1);
  this_->UndistortMap.ClassOfImage[0] = 'a';
  this_->UndistortMap.ClassOfImage.set_size(&xu_emlrtRTEI, &st, 1, 5);
  for (i = 0; i < 5; i++) {
    this_->UndistortMap.ClassOfImage[i] = b_cv[i];
  }
  this_->UndistortMap.OutputView.set_size(&yu_emlrtRTEI, &st, 1, 1);
  this_->UndistortMap.OutputView[0] = 'a';
  this_->UndistortMap.OutputView.set_size(&av_emlrtRTEI, &st, 1, 4);
  this_->UndistortMap.OutputView[0] = 's';
  this_->UndistortMap.OutputView[1] = 'a';
  this_->UndistortMap.OutputView[2] = 'm';
  this_->UndistortMap.OutputView[3] = 'e';
  this_->UndistortMap.XmapSingle.set_size(&bv_emlrtRTEI, &st, 2, 2);
  this_->UndistortMap.XmapSingle[0] = 0.0F;
  this_->UndistortMap.XmapSingle[1] = 0.0F;
  this_->UndistortMap.XmapSingle[2] = 0.0F;
  this_->UndistortMap.XmapSingle[3] = 0.0F;
  this_->UndistortMap.YmapSingle.set_size(&cv_emlrtRTEI, &st, 2, 2);
  this_->UndistortMap.YmapSingle[0] = 0.0F;
  this_->UndistortMap.YmapSingle[1] = 0.0F;
  this_->UndistortMap.YmapSingle[2] = 0.0F;
  this_->UndistortMap.YmapSingle[3] = 0.0F;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return this_;
}

} // namespace coder

// End of code generation (cameraParameters.cpp)
