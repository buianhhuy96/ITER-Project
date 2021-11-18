//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// cameraParameters.h
//
// Code generation for function 'cameraParameters'
//

#pragma once

// Include files
#include "ImageTransformer.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Definitions
namespace coder {
class cameraParameters {
public:
  static void checkIntrinsicMatrix(const emlrtStack *sp,
                                   const real_T IntrinsicMatrix[9]);
  static void checkRadialDistortion(const emlrtStack *sp,
                                    const real_T radialDistortion[3]);
  static void checkTangentialDistortion(const emlrtStack *sp,
                                        const real_T tangentialDistortion[2]);
  static void checkImageSize(const emlrtStack *sp, const real_T imageSize[2]);
  static void
  checkRotationVectors(const emlrtStack *sp,
                       const ::coder::array<real_T, 2U> &rotationVectors);
  static void
  checkTranslationVectors(const emlrtStack *sp,
                          const ::coder::array<real_T, 2U> &translationVectors);
  static void checkNumRadialCoeffs(const emlrtStack *sp,
                                   real_T numRadialCoeffs);
  real_T ImageSize[2];
  real_T RadialDistortion[3];
  real_T TangentialDistortion[2];
  array<real_T, 2U> WorldPoints;
  real_T NumRadialDistortionCoefficients;
  array<real_T, 2U> TranslationVectors;
  array<real_T, 3U> ReprojectionErrors;
  array<boolean_T, 2U> DetectedKeypoints;
  array<real_T, 2U> RotationVectors;
  real_T IntrinsicMatrixInternal[9];

protected:
  vision::internal::calibration::ImageTransformer UndistortMap;
};

class b_cameraParameters {
public:
  b_cameraParameters *
  init(const emlrtStack *sp, const real_T varargin_1_RadialDistortion[3],
       const real_T varargin_1_TangentialDistortion[2],
       const real_T varargin_1_ImageSize[2],
       const ::coder::array<real_T, 2U> &varargin_1_WorldPoints,
       real_T c_varargin_1_NumRadialDistortio,
       const ::coder::array<real_T, 2U> &varargin_1_RotationVectors,
       const ::coder::array<real_T, 2U> &varargin_1_TranslationVectors,
       const ::coder::array<real_T, 3U> &varargin_1_ReprojectionErrors,
       const real_T varargin_1_IntrinsicMatrix[9],
       const ::coder::array<boolean_T, 2U> &varargin_1_DetectedKeypoints);
  real_T ImageSize[2];
  real_T RadialDistortion[3];
  real_T TangentialDistortion[2];
  array<real_T, 2U> WorldPoints;
  real_T NumRadialDistortionCoefficients;
  array<real_T, 2U> TranslationVectors;
  array<real_T, 3U> ReprojectionErrors;
  array<boolean_T, 2U> DetectedKeypoints;
  array<real_T, 2U> RotationVectors;
  vision::internal::calibration::b_ImageTransformer UndistortMap;
  real_T IntrinsicMatrixInternal[9];
};

} // namespace coder

// End of code generation (cameraParameters.h)
