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
#include "ImageTransformer.h"
#include "any1.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "calibrateOneCamera_v2_mex_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo m_emlrtRSI{
    6,                       // lineNo
    "HandleBase/HandleBase", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "enforcescalar\\HandleBase.m" // pathName
};

static emlrtRSInfo s_emlrtRSI{
    562,                                          // lineNo
    "CameraParametersImpl/checkRadialDistortion", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo u_emlrtRSI{
    572,                                              // lineNo
    "CameraParametersImpl/checkTangentialDistortion", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo w_emlrtRSI{
    582,                                   // lineNo
    "CameraParametersImpl/checkImageSize", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo x_emlrtRSI{
    637,                                         // lineNo
    "CameraParametersImpl/checkNumRadialCoeffs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo rbb_emlrtRSI{
    377,                                       // lineNo
    "CameraParametersImpl/parseInputsCodegen", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo sbb_emlrtRSI{
    554,                                         // lineNo
    "CameraParametersImpl/checkIntrinsicMatrix", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo tbb_emlrtRSI{
    592,                                         // lineNo
    "CameraParametersImpl/checkRotationVectors", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo ubb_emlrtRSI{
    602,                                            // lineNo
    "CameraParametersImpl/checkTranslationVectors", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo vbb_emlrtRSI{
    612,                                     // lineNo
    "CameraParametersImpl/checkWorldPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo ccb_emlrtRSI{
    382,                                       // lineNo
    "CameraParametersImpl/parseInputsCodegen", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo dcb_emlrtRSI{
    623,                                    // lineNo
    "CameraParametersImpl/checkWorldUnits", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRTEInfo f_emlrtRTEI{
    22,           // lineNo
    27,           // colNo
    "validatege", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatege.m" // pName
};

static emlrtRTEInfo g_emlrtRTEI{
    22,           // lineNo
    27,           // colNo
    "validatele", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatele.m" // pName
};

static emlrtRTEInfo kc_emlrtRTEI{
    568,                                          // lineNo
    17,                                           // colNo
    "CameraParametersImpl/checkRadialDistortion", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

static emlrtRTEInfo bt_emlrtRTEI{
    368,                    // lineNo
    17,                     // colNo
    "CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

static emlrtRTEInfo dt_emlrtRTEI{
    373,                    // lineNo
    17,                     // colNo
    "CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

static emlrtRTEInfo et_emlrtRTEI{
    375,                    // lineNo
    13,                     // colNo
    "CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

static emlrtRTEInfo ft_emlrtRTEI{
    314,                    // lineNo
    13,                     // colNo
    "CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

static emlrtRTEInfo gt_emlrtRTEI{
    380,                    // lineNo
    13,                     // colNo
    "CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

static emlrtRTEInfo ox_emlrtRTEI{
    45,                 // lineNo
    13,                 // colNo
    "ImageTransformer", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pName
};

static emlrtRTEInfo px_emlrtRTEI{
    46,                 // lineNo
    13,                 // colNo
    "ImageTransformer", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pName
};

static emlrtRTEInfo qx_emlrtRTEI{
    47,                 // lineNo
    13,                 // colNo
    "ImageTransformer", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pName
};

static emlrtRTEInfo rx_emlrtRTEI{
    48,                 // lineNo
    13,                 // colNo
    "ImageTransformer", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pName
};

static emlrtRTEInfo sx_emlrtRTEI{
    49,                 // lineNo
    13,                 // colNo
    "ImageTransformer", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pName
};

static emlrtRTEInfo tx_emlrtRTEI{
    50,                 // lineNo
    13,                 // colNo
    "ImageTransformer", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pName
};

static emlrtRTEInfo ux_emlrtRTEI{
    55,                 // lineNo
    13,                 // colNo
    "ImageTransformer", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pName
};

static emlrtRTEInfo vx_emlrtRTEI{
    56,                 // lineNo
    13,                 // colNo
    "ImageTransformer", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pName
};

// Function Definitions
namespace coder {
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
    st.site = &tbb_emlrtRSI;
    b_st.site = &t_emlrtRSI;
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
          &b_st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
          "MATLAB:cameraParameters:expectedFinite", 3, 4, 15,
          "RotationVectors");
    }
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
    st.site = &ubb_emlrtRSI;
    b_st.site = &t_emlrtRSI;
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
          &b_st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
          "MATLAB:cameraParameters:expectedFinite", 3, 4, 18,
          "TranslationVectors");
    }
  }
}

void cameraParameters::b_checkRotationVectors(
    const emlrtStack *sp, const ::coder::array<real_T, 2U> &rotationVectors)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((rotationVectors.size(0) != 0) && (rotationVectors.size(1) != 0)) {
    int32_T i;
    int32_T k;
    boolean_T exitg1;
    boolean_T p;
    st.site = &tbb_emlrtRSI;
    b_st.site = &t_emlrtRSI;
    p = true;
    i = rotationVectors.size(0) * rotationVectors.size(1);
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
          &b_st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
          "MATLAB:cameraParameters:expectedFinite", 3, 4, 15,
          "RotationVectors");
    }
    b_st.site = &t_emlrtRSI;
    if (rotationVectors.size(1) != 3) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &bc_emlrtRTEI,
          "Coder:toolbox:ValidateattributesincorrectNumcols",
          "MATLAB:cameraParameters:incorrectNumcols", 5, 4, 15,
          "RotationVectors", 6, 3.0);
    }
  }
}

void cameraParameters::b_checkTranslationVectors(
    const emlrtStack *sp, const ::coder::array<real_T, 2U> &translationVectors)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((translationVectors.size(0) != 0) && (translationVectors.size(1) != 0)) {
    int32_T i;
    int32_T k;
    boolean_T exitg1;
    boolean_T p;
    st.site = &ubb_emlrtRSI;
    b_st.site = &t_emlrtRSI;
    p = true;
    i = translationVectors.size(0) * translationVectors.size(1);
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
          &b_st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
          "MATLAB:cameraParameters:expectedFinite", 3, 4, 18,
          "TranslationVectors");
    }
    b_st.site = &t_emlrtRSI;
    if (translationVectors.size(1) != 3) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &bc_emlrtRTEI,
          "Coder:toolbox:ValidateattributesincorrectNumcols",
          "MATLAB:cameraParameters:incorrectNumcols", 5, 4, 18,
          "TranslationVectors", 6, 3.0);
    }
  }
}

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
  st.site = &w_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &t_emlrtRSI;
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
        &b_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:CameraParametersImpl:expectedInteger", 3, 4, 9, "imageSize");
  }
  b_st.site = &t_emlrtRSI;
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
  st.site = &sbb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &t_emlrtRSI;
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
        &b_st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
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
  st.site = &x_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &t_emlrtRSI;
  if (muDoubleScalarIsInf(numRadialCoeffs) ||
      muDoubleScalarIsNaN(numRadialCoeffs) ||
      (!(muDoubleScalarFloor(numRadialCoeffs) == numRadialCoeffs))) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:cameraParameters:expectedInteger", 3, 4, 31,
        "NumRadialDistortionCoefficients");
  }
  b_st.site = &t_emlrtRSI;
  if (!(numRadialCoeffs >= 2.0)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &f_emlrtRTEI, "MATLAB:validateattributes:expectedScalar",
        "MATLAB:cameraParameters:notGreaterEqual", 9, 4, 31,
        "NumRadialDistortionCoefficients", 4, 2, ">=", 4, 1, "2");
  }
  b_st.site = &t_emlrtRSI;
  if (!(numRadialCoeffs <= 3.0)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &g_emlrtRTEI, "MATLAB:validateattributes:expectedScalar",
        "MATLAB:cameraParameters:notLessEqual", 9, 4, 31,
        "NumRadialDistortionCoefficients", 4, 2, "<=", 4, 1, "3");
  }
}

void cameraParameters::checkRadialDistortion(
    const emlrtStack *sp, const ::coder::array<real_T, 2U> &radialDistortion)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &s_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &t_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= radialDistortion.size(1) - 1)) {
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
        &b_st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:cameraParameters:expectedFinite", 3, 4, 16, "RadialDistortion");
  }
  if ((radialDistortion.size(1) != 2) && (radialDistortion.size(1) != 3)) {
    emlrtErrorWithMessageIdR2018a(
        sp, &kc_emlrtRTEI, "vision:dims:twoOrThreeElementVector",
        "vision:dims:twoOrThreeElementVector", 3, 4, 16, "RadialDistortion");
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
  st.site = &s_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &t_emlrtRSI;
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
        &b_st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
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
  st.site = &u_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &t_emlrtRSI;
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
        &b_st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:cameraParameters:expectedFinite", 3, 4, 20,
        "TangentialDistortion");
  }
}

void b_cameraParameters::get_FocalLength(real_T focalLength[2]) const
{
  focalLength[0] = IntrinsicMatrixInternal[0];
  focalLength[1] = IntrinsicMatrixInternal[4];
}

void b_cameraParameters::get_PrincipalPoint(real_T principalPoint[2]) const
{
  principalPoint[0] = IntrinsicMatrixInternal[6];
  principalPoint[1] = IntrinsicMatrixInternal[7];
}

c_cameraParameters *
c_cameraParameters::init(const emlrtStack *sp, const real_T varargin_2[9],
                         const ::coder::array<real_T, 2U> &varargin_4,
                         const ::coder::array<real_T, 2U> &varargin_6,
                         const ::coder::array<real_T, 2U> &varargin_8,
                         const real_T varargin_20[2])
{
  c_cameraParameters *this_;
  array<real_T, 2U> c_this;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T b_this[2];
  int32_T loop_ub;
  int32_T worldPoints_size_idx_1;
  boolean_T d_this[2];
  boolean_T b;
  boolean_T guard1{false};
  boolean_T guard2{false};
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
  st.site = &i_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &j_emlrtRSI;
  b_st.site = &obb_emlrtRSI;
  cameraParameters::checkIntrinsicMatrix(&b_st, varargin_2);
  for (worldPoints_size_idx_1 = 0; worldPoints_size_idx_1 < 3;
       worldPoints_size_idx_1++) {
    this_->IntrinsicMatrixInternal[3 * worldPoints_size_idx_1] =
        varargin_2[worldPoints_size_idx_1];
    this_->IntrinsicMatrixInternal[3 * worldPoints_size_idx_1 + 1] =
        varargin_2[worldPoints_size_idx_1 + 3];
    this_->IntrinsicMatrixInternal[3 * worldPoints_size_idx_1 + 2] =
        varargin_2[worldPoints_size_idx_1 + 6];
  }
  this_->RadialDistortion[0] = 0.0;
  this_->RadialDistortion[1] = 0.0;
  this_->RadialDistortion[2] = 0.0;
  b_st.site = &n_emlrtRSI;
  cameraParameters::checkRadialDistortion(&b_st, this_->RadialDistortion);
  this_->TangentialDistortion[0] = 0.0;
  this_->TangentialDistortion[1] = 0.0;
  b_st.site = &o_emlrtRSI;
  cameraParameters::checkTangentialDistortion(&b_st,
                                              this_->TangentialDistortion);
  b_st.site = &p_emlrtRSI;
  c_st.site = &v_emlrtRSI;
  cameraParameters::checkImageSize(&c_st, varargin_20);
  this_->ImageSize[0] = varargin_20[0];
  this_->ImageSize[1] = varargin_20[1];
  b_this[0] = this_->ImageSize[0];
  b_this[1] = this_->ImageSize[1];
  b_st.site = &q_emlrtRSI;
  cameraParameters::checkImageSize(&b_st, b_this);
  this_->RotationVectors.set_size(&at_emlrtRTEI, &st, varargin_4.size(0), 3);
  loop_ub = varargin_4.size(0) * 3;
  for (worldPoints_size_idx_1 = 0; worldPoints_size_idx_1 < loop_ub;
       worldPoints_size_idx_1++) {
    this_->RotationVectors[worldPoints_size_idx_1] =
        varargin_4[worldPoints_size_idx_1];
  }
  c_this.set_size(&bt_emlrtRTEI, &st, this_->RotationVectors.size(0), 3);
  loop_ub = this_->RotationVectors.size(0) * this_->RotationVectors.size(1) - 1;
  for (worldPoints_size_idx_1 = 0; worldPoints_size_idx_1 <= loop_ub;
       worldPoints_size_idx_1++) {
    c_this[worldPoints_size_idx_1] =
        this_->RotationVectors[worldPoints_size_idx_1];
  }
  b_st.site = &pbb_emlrtRSI;
  cameraParameters::checkRotationVectors(&b_st, c_this);
  this_->TranslationVectors.set_size(&ct_emlrtRTEI, &st, varargin_6.size(0), 3);
  loop_ub = varargin_6.size(0) * 3;
  for (worldPoints_size_idx_1 = 0; worldPoints_size_idx_1 < loop_ub;
       worldPoints_size_idx_1++) {
    this_->TranslationVectors[worldPoints_size_idx_1] =
        varargin_6[worldPoints_size_idx_1];
  }
  c_this.set_size(&dt_emlrtRTEI, &st, this_->TranslationVectors.size(0), 3);
  loop_ub =
      this_->TranslationVectors.size(0) * this_->TranslationVectors.size(1) - 1;
  for (worldPoints_size_idx_1 = 0; worldPoints_size_idx_1 <= loop_ub;
       worldPoints_size_idx_1++) {
    c_this[worldPoints_size_idx_1] =
        this_->TranslationVectors[worldPoints_size_idx_1];
  }
  b_st.site = &qbb_emlrtRSI;
  cameraParameters::checkTranslationVectors(&b_st, c_this);
  this_->WorldPoints.set_size(&et_emlrtRTEI, &st, varargin_8.size(0),
                              varargin_8.size(1));
  loop_ub = varargin_8.size(0) * varargin_8.size(1);
  for (worldPoints_size_idx_1 = 0; worldPoints_size_idx_1 < loop_ub;
       worldPoints_size_idx_1++) {
    this_->WorldPoints[worldPoints_size_idx_1] =
        varargin_8[worldPoints_size_idx_1];
  }
  b_st.site = &rbb_emlrtRSI;
  loop_ub = this_->WorldPoints.size(0);
  worldPoints_size_idx_1 = this_->WorldPoints.size(1);
  if ((loop_ub != 0) && (worldPoints_size_idx_1 != 0)) {
    c_st.site = &vbb_emlrtRSI;
    d_st.site = &t_emlrtRSI;
    if (worldPoints_size_idx_1 != 2) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &bc_emlrtRTEI,
          "Coder:toolbox:ValidateattributesincorrectNumcols",
          "MATLAB:cameraParameters:incorrectNumcols", 5, 4, 11, "WorldPoints",
          6, 2.0);
    }
  }
  this_->WorldUnits = 'm';
  this_->EstimateSkew = false;
  this_->NumRadialDistortionCoefficients = 3.0;
  b_st.site = &r_emlrtRSI;
  cameraParameters::checkNumRadialCoeffs(
      &b_st, this_->NumRadialDistortionCoefficients);
  this_->EstimateTangentialDistortion = false;
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
        sp, &gc_emlrtRTEI,
        "vision:calibrate:rotationAndTranslationVectorsMustBeSetTogether",
        "vision:calibrate:rotationAndTranslationVectorsMustBeSetTogether", 0);
  }
  d_this[0] =
      (this_->RotationVectors.size(0) != this_->TranslationVectors.size(0));
  d_this[1] = false;
  st.site = &nbb_emlrtRSI;
  if (any(d_this)) {
    emlrtErrorWithMessageIdR2018a(
        sp, &hc_emlrtRTEI,
        "vision:calibrate:rotationAndTranslationVectorsNotSameSize",
        "vision:calibrate:rotationAndTranslationVectorsNotSameSize", 0);
  }
  st.site = &k_emlrtRSI;
  b_st.site = &bb_emlrtRSI;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return this_;
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
  st.site = &i_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  st.site = &j_emlrtRSI;
  for (int32_T i{0}; i < 9; i++) {
    this_->IntrinsicMatrixInternal[i] = iv[i];
  }
  this_->RadialDistortion[0] = 0.0;
  this_->RadialDistortion[1] = 0.0;
  this_->RadialDistortion[2] = 0.0;
  b_st.site = &n_emlrtRSI;
  cameraParameters::checkRadialDistortion(&b_st, this_->RadialDistortion);
  this_->TangentialDistortion[0] = 0.0;
  this_->TangentialDistortion[1] = 0.0;
  b_st.site = &o_emlrtRSI;
  cameraParameters::checkTangentialDistortion(&b_st,
                                              this_->TangentialDistortion);
  b_st.site = &p_emlrtRSI;
  c_st.site = &v_emlrtRSI;
  cameraParameters::checkImageSize(&c_st, varargin_2);
  this_->ImageSize[0] = varargin_2[0];
  this_->ImageSize[1] = varargin_2[1];
  b_this[0] = this_->ImageSize[0];
  b_this[1] = this_->ImageSize[1];
  b_st.site = &q_emlrtRSI;
  cameraParameters::checkImageSize(&b_st, b_this);
  this_->WorldUnits[0] = 'm';
  this_->WorldUnits[1] = 'm';
  this_->EstimateSkew = false;
  this_->NumRadialDistortionCoefficients = 2.0;
  b_st.site = &r_emlrtRSI;
  cameraParameters::checkNumRadialCoeffs(
      &b_st, this_->NumRadialDistortionCoefficients);
  this_->EstimateTangentialDistortion = false;
  st.site = &k_emlrtRSI;
  b_st.site = &bb_emlrtRSI;
  return this_;
}

b_cameraParameters *b_cameraParameters::init(const emlrtStack *sp,
                                             const struct_T *varargin_1)
{
  b_cameraParameters *this_;
  array<real_T, 2U> c_this;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T b_this[2];
  int32_T loop_ub;
  int32_T worldPoints_size_idx_1;
  boolean_T d_this[2];
  boolean_T b;
  boolean_T guard1{false};
  boolean_T guard2{false};
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
  st.site = &i_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &j_emlrtRSI;
  b_st.site = &obb_emlrtRSI;
  cameraParameters::checkIntrinsicMatrix(&b_st, varargin_1->IntrinsicMatrix);
  for (worldPoints_size_idx_1 = 0; worldPoints_size_idx_1 < 3;
       worldPoints_size_idx_1++) {
    this_->IntrinsicMatrixInternal[3 * worldPoints_size_idx_1] =
        varargin_1->IntrinsicMatrix[worldPoints_size_idx_1];
    this_->IntrinsicMatrixInternal[3 * worldPoints_size_idx_1 + 1] =
        varargin_1->IntrinsicMatrix[worldPoints_size_idx_1 + 3];
    this_->IntrinsicMatrixInternal[3 * worldPoints_size_idx_1 + 2] =
        varargin_1->IntrinsicMatrix[worldPoints_size_idx_1 + 6];
  }
  this_->RadialDistortion[0] = varargin_1->RadialDistortion[0];
  this_->RadialDistortion[1] = varargin_1->RadialDistortion[1];
  this_->RadialDistortion[2] = varargin_1->RadialDistortion[2];
  b_st.site = &n_emlrtRSI;
  cameraParameters::checkRadialDistortion(&b_st, this_->RadialDistortion);
  this_->TangentialDistortion[0] = varargin_1->TangentialDistortion[0];
  this_->TangentialDistortion[1] = varargin_1->TangentialDistortion[1];
  b_st.site = &o_emlrtRSI;
  cameraParameters::checkTangentialDistortion(&b_st,
                                              this_->TangentialDistortion);
  b_st.site = &p_emlrtRSI;
  c_st.site = &v_emlrtRSI;
  cameraParameters::checkImageSize(&c_st, varargin_1->ImageSize);
  this_->ImageSize[0] = varargin_1->ImageSize[0];
  this_->ImageSize[1] = varargin_1->ImageSize[1];
  b_this[0] = this_->ImageSize[0];
  b_this[1] = this_->ImageSize[1];
  b_st.site = &q_emlrtRSI;
  cameraParameters::checkImageSize(&b_st, b_this);
  this_->RotationVectors.set_size(&at_emlrtRTEI, &st,
                                  varargin_1->RotationVectors.size(0), 3);
  loop_ub = varargin_1->RotationVectors.size(0) * 3;
  for (worldPoints_size_idx_1 = 0; worldPoints_size_idx_1 < loop_ub;
       worldPoints_size_idx_1++) {
    this_->RotationVectors[worldPoints_size_idx_1] =
        varargin_1->RotationVectors[worldPoints_size_idx_1];
  }
  c_this.set_size(&bt_emlrtRTEI, &st, this_->RotationVectors.size(0), 3);
  loop_ub = this_->RotationVectors.size(0) * this_->RotationVectors.size(1) - 1;
  for (worldPoints_size_idx_1 = 0; worldPoints_size_idx_1 <= loop_ub;
       worldPoints_size_idx_1++) {
    c_this[worldPoints_size_idx_1] =
        this_->RotationVectors[worldPoints_size_idx_1];
  }
  b_st.site = &pbb_emlrtRSI;
  cameraParameters::checkRotationVectors(&b_st, c_this);
  this_->TranslationVectors.set_size(&ct_emlrtRTEI, &st,
                                     varargin_1->TranslationVectors.size(0), 3);
  loop_ub = varargin_1->TranslationVectors.size(0) * 3;
  for (worldPoints_size_idx_1 = 0; worldPoints_size_idx_1 < loop_ub;
       worldPoints_size_idx_1++) {
    this_->TranslationVectors[worldPoints_size_idx_1] =
        varargin_1->TranslationVectors[worldPoints_size_idx_1];
  }
  c_this.set_size(&dt_emlrtRTEI, &st, this_->TranslationVectors.size(0), 3);
  loop_ub =
      this_->TranslationVectors.size(0) * this_->TranslationVectors.size(1) - 1;
  for (worldPoints_size_idx_1 = 0; worldPoints_size_idx_1 <= loop_ub;
       worldPoints_size_idx_1++) {
    c_this[worldPoints_size_idx_1] =
        this_->TranslationVectors[worldPoints_size_idx_1];
  }
  b_st.site = &qbb_emlrtRSI;
  cameraParameters::checkTranslationVectors(&b_st, c_this);
  this_->WorldPoints.set_size(&et_emlrtRTEI, &st,
                              varargin_1->WorldPoints.size(0),
                              varargin_1->WorldPoints.size(1));
  loop_ub = varargin_1->WorldPoints.size(0) * varargin_1->WorldPoints.size(1);
  for (worldPoints_size_idx_1 = 0; worldPoints_size_idx_1 < loop_ub;
       worldPoints_size_idx_1++) {
    this_->WorldPoints[worldPoints_size_idx_1] =
        varargin_1->WorldPoints[worldPoints_size_idx_1];
  }
  b_st.site = &rbb_emlrtRSI;
  loop_ub = this_->WorldPoints.size(0);
  worldPoints_size_idx_1 = this_->WorldPoints.size(1);
  if ((loop_ub != 0) && (worldPoints_size_idx_1 != 0)) {
    c_st.site = &vbb_emlrtRSI;
    d_st.site = &t_emlrtRSI;
    if (worldPoints_size_idx_1 != 2) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &bc_emlrtRTEI,
          "Coder:toolbox:ValidateattributesincorrectNumcols",
          "MATLAB:cameraParameters:incorrectNumcols", 5, 4, 11, "WorldPoints",
          6, 2.0);
    }
  }
  this_->WorldUnits.set_size(&gt_emlrtRTEI, &st, 1,
                             varargin_1->WorldUnits.size(1));
  loop_ub = varargin_1->WorldUnits.size(1);
  for (worldPoints_size_idx_1 = 0; worldPoints_size_idx_1 < loop_ub;
       worldPoints_size_idx_1++) {
    this_->WorldUnits[worldPoints_size_idx_1] =
        varargin_1->WorldUnits[worldPoints_size_idx_1];
  }
  b_st.site = &ccb_emlrtRSI;
  worldPoints_size_idx_1 = this_->WorldUnits.size(1);
  c_st.site = &dcb_emlrtRSI;
  d_st.site = &t_emlrtRSI;
  if (worldPoints_size_idx_1 == 0) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonempty",
        "MATLAB:cameraParameters:expectedNonempty", 3, 4, 10, "WorldUnits");
  }
  this_->EstimateSkew = varargin_1->EstimateSkew;
  this_->NumRadialDistortionCoefficients =
      varargin_1->NumRadialDistortionCoefficients;
  b_st.site = &r_emlrtRSI;
  cameraParameters::checkNumRadialCoeffs(
      &b_st, this_->NumRadialDistortionCoefficients);
  this_->EstimateTangentialDistortion =
      varargin_1->EstimateTangentialDistortion;
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
        sp, &gc_emlrtRTEI,
        "vision:calibrate:rotationAndTranslationVectorsMustBeSetTogether",
        "vision:calibrate:rotationAndTranslationVectorsMustBeSetTogether", 0);
  }
  d_this[0] =
      (this_->RotationVectors.size(0) != this_->TranslationVectors.size(0));
  d_this[1] = false;
  st.site = &nbb_emlrtRSI;
  if (any(d_this)) {
    emlrtErrorWithMessageIdR2018a(
        sp, &hc_emlrtRTEI,
        "vision:calibrate:rotationAndTranslationVectorsNotSameSize",
        "vision:calibrate:rotationAndTranslationVectorsNotSameSize", 0);
  }
  st.site = &k_emlrtRSI;
  b_st.site = &bb_emlrtRSI;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return this_;
}

e_cameraParameters *
e_cameraParameters::init(const emlrtStack *sp,
                         const real_T varargin_1_RadialDistortion[3],
                         const real_T varargin_1_TangentialDistortion[2],
                         const real_T varargin_1_ImageSize[2],
                         real_T c_varargin_1_NumRadialDistortio,
                         const real_T varargin_1_IntrinsicMatrix[9])
{
  static const char_T b_cv[5]{'u', 'i', 'n', 't', '8'};
  e_cameraParameters *this_;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T b_this[2];
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  this_ = this;
  st.site = &i_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  st.site = &j_emlrtRSI;
  b_st.site = &obb_emlrtRSI;
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
  b_st.site = &n_emlrtRSI;
  cameraParameters::checkRadialDistortion(&b_st, this_->RadialDistortion);
  this_->TangentialDistortion[0] = varargin_1_TangentialDistortion[0];
  this_->TangentialDistortion[1] = varargin_1_TangentialDistortion[1];
  b_st.site = &o_emlrtRSI;
  cameraParameters::checkTangentialDistortion(&b_st,
                                              this_->TangentialDistortion);
  b_st.site = &p_emlrtRSI;
  c_st.site = &v_emlrtRSI;
  cameraParameters::checkImageSize(&c_st, varargin_1_ImageSize);
  this_->ImageSize[0] = varargin_1_ImageSize[0];
  this_->ImageSize[1] = varargin_1_ImageSize[1];
  b_this[0] = this_->ImageSize[0];
  b_this[1] = this_->ImageSize[1];
  b_st.site = &q_emlrtRSI;
  cameraParameters::checkImageSize(&b_st, b_this);
  this_->NumRadialDistortionCoefficients = c_varargin_1_NumRadialDistortio;
  b_st.site = &r_emlrtRSI;
  cameraParameters::checkNumRadialCoeffs(
      &b_st, this_->NumRadialDistortionCoefficients);
  st.site = &k_emlrtRSI;
  this_->UndistortMap.XBounds[0] = -1.0;
  this_->UndistortMap.XBounds[1] = -1.0;
  this_->UndistortMap.YBounds[0] = -1.0;
  this_->UndistortMap.YBounds[1] = -1.0;
  b_st.site = &bb_emlrtRSI;
  this_->UndistortMap.SizeOfImage.set_size(&ox_emlrtRTEI, &st, 1, 2);
  this_->UndistortMap.SizeOfImage[0] = 0.0;
  this_->UndistortMap.SizeOfImage[1] = 0.0;
  this_->UndistortMap.SizeOfImage.set_size(&px_emlrtRTEI, &st, 1, 3);
  this_->UndistortMap.SizeOfImage[0] = 0.0;
  this_->UndistortMap.SizeOfImage[1] = 0.0;
  this_->UndistortMap.SizeOfImage[2] = 0.0;
  this_->UndistortMap.ClassOfImage.set_size(&qx_emlrtRTEI, &st, 1, 1);
  this_->UndistortMap.ClassOfImage[0] = 'a';
  this_->UndistortMap.ClassOfImage.set_size(&rx_emlrtRTEI, &st, 1, 5);
  for (i = 0; i < 5; i++) {
    this_->UndistortMap.ClassOfImage[i] = b_cv[i];
  }
  this_->UndistortMap.OutputView.set_size(&sx_emlrtRTEI, &st, 1, 1);
  this_->UndistortMap.OutputView[0] = 'a';
  this_->UndistortMap.OutputView.set_size(&tx_emlrtRTEI, &st, 1, 4);
  this_->UndistortMap.OutputView[0] = 's';
  this_->UndistortMap.OutputView[1] = 'a';
  this_->UndistortMap.OutputView[2] = 'm';
  this_->UndistortMap.OutputView[3] = 'e';
  this_->UndistortMap.XmapSingle.set_size(&ux_emlrtRTEI, &st, 2, 2);
  this_->UndistortMap.XmapSingle[0] = 0.0F;
  this_->UndistortMap.XmapSingle[1] = 0.0F;
  this_->UndistortMap.XmapSingle[2] = 0.0F;
  this_->UndistortMap.XmapSingle[3] = 0.0F;
  this_->UndistortMap.YmapSingle.set_size(&vx_emlrtRTEI, &st, 2, 2);
  this_->UndistortMap.YmapSingle[0] = 0.0F;
  this_->UndistortMap.YmapSingle[1] = 0.0F;
  this_->UndistortMap.YmapSingle[2] = 0.0F;
  this_->UndistortMap.YmapSingle[3] = 0.0F;
  return this_;
}

void c_cameraParameters::toStruct(
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
  st.site = &cb_emlrtRSI;
  paramStruct_RadialDistortion[0] = RadialDistortion[0];
  paramStruct_RadialDistortion[1] = RadialDistortion[1];
  paramStruct_RadialDistortion[2] = RadialDistortion[2];
  c_paramStruct_TangentialDistort[0] = TangentialDistortion[0];
  paramStruct_ImageSize[0] = ImageSize[0];
  c_paramStruct_TangentialDistort[1] = TangentialDistortion[1];
  paramStruct_ImageSize[1] = ImageSize[1];
  paramStruct_WorldPoints.set_size(&ft_emlrtRTEI, &st, WorldPoints.size(0),
                                   WorldPoints.size(1));
  loop_ub = WorldPoints.size(0) * WorldPoints.size(1);
  for (i = 0; i < loop_ub; i++) {
    paramStruct_WorldPoints[i] = WorldPoints[i];
  }
  paramStruct_RotationVectors.set_size(&ft_emlrtRTEI, &st,
                                       RotationVectors.size(0), 3);
  loop_ub = RotationVectors.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    paramStruct_RotationVectors[i] = RotationVectors[i];
  }
  paramStruct_TranslationVectors.set_size(&ft_emlrtRTEI, &st,
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

} // namespace coder

// End of code generation (cameraParameters.cpp)
