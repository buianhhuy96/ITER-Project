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

// Type Declarations
struct struct_T;

// Type Definitions
namespace coder {
class cameraParameters {
public:
  cameraParameters *init(const emlrtStack *sp, const real_T varargin_2[2]);
  static void checkRadialDistortion(const emlrtStack *sp,
                                    const real_T radialDistortion[3]);
  static void checkTangentialDistortion(const emlrtStack *sp,
                                        const real_T tangentialDistortion[2]);
  static void checkImageSize(const emlrtStack *sp, const real_T imageSize[2]);
  static void checkNumRadialCoeffs(const emlrtStack *sp,
                                   real_T numRadialCoeffs);
  void toStruct(real_T paramStruct_RadialDistortion[3],
                real_T c_paramStruct_TangentialDistort[2],
                real_T paramStruct_ImageSize[2],
                char_T paramStruct_WorldUnits[2],
                boolean_T *paramStruct_EstimateSkew,
                real_T *c_paramStruct_NumRadialDistorti,
                boolean_T *c_paramStruct_EstimateTangentia,
                real_T paramStruct_IntrinsicMatrix[9]) const;
  static void checkIntrinsicMatrix(const emlrtStack *sp,
                                   const real_T IntrinsicMatrix[9]);
  static void
  checkRotationVectors(const emlrtStack *sp,
                       const ::coder::array<real_T, 2U> &rotationVectors);
  static void
  checkTranslationVectors(const emlrtStack *sp,
                          const ::coder::array<real_T, 2U> &translationVectors);
  static void
  checkRadialDistortion(const emlrtStack *sp,
                        const ::coder::array<real_T, 2U> &radialDistortion);
  static void
  b_checkRotationVectors(const emlrtStack *sp,
                         const ::coder::array<real_T, 2U> &rotationVectors);
  static void b_checkTranslationVectors(
      const emlrtStack *sp,
      const ::coder::array<real_T, 2U> &translationVectors);
  real_T ImageSize[2];
  real_T RadialDistortion[3];
  real_T TangentialDistortion[2];
  char_T WorldUnits[2];
  boolean_T EstimateSkew;
  real_T NumRadialDistortionCoefficients;
  boolean_T EstimateTangentialDistortion;

protected:
  vision::internal::calibration::ImageTransformer UndistortMap;
  real_T IntrinsicMatrixInternal[9];
};

class b_cameraParameters {
public:
  b_cameraParameters *init(const emlrtStack *sp, const struct_T *varargin_1);
  void get_FocalLength(real_T focalLength[2]) const;
  void get_PrincipalPoint(real_T principalPoint[2]) const;
  real_T ImageSize[2];
  real_T RadialDistortion[3];
  real_T TangentialDistortion[2];
  array<real_T, 2U> WorldPoints;
  array<char_T, 2U> WorldUnits;
  boolean_T EstimateSkew;
  real_T NumRadialDistortionCoefficients;
  boolean_T EstimateTangentialDistortion;
  array<real_T, 2U> TranslationVectors;
  array<real_T, 2U> RotationVectors;
  real_T IntrinsicMatrixInternal[9];

protected:
  vision::internal::calibration::ImageTransformer UndistortMap;
};

class c_cameraParameters {
public:
  c_cameraParameters *init(const emlrtStack *sp, const real_T varargin_2[9],
                           const ::coder::array<real_T, 2U> &varargin_4,
                           const ::coder::array<real_T, 2U> &varargin_6,
                           const ::coder::array<real_T, 2U> &varargin_8,
                           const real_T varargin_20[2]);
  void toStruct(const emlrtStack *sp, real_T paramStruct_RadialDistortion[3],
                real_T c_paramStruct_TangentialDistort[2],
                real_T paramStruct_ImageSize[2],
                ::coder::array<real_T, 2U> &paramStruct_WorldPoints,
                char_T *paramStruct_WorldUnits,
                boolean_T *paramStruct_EstimateSkew,
                real_T *c_paramStruct_NumRadialDistorti,
                boolean_T *c_paramStruct_EstimateTangentia,
                ::coder::array<real_T, 2U> &paramStruct_RotationVectors,
                ::coder::array<real_T, 2U> &paramStruct_TranslationVectors,
                real_T paramStruct_IntrinsicMatrix[9]) const;
  real_T ImageSize[2];
  real_T RadialDistortion[3];
  real_T TangentialDistortion[2];
  array<real_T, 2U> WorldPoints;
  char_T WorldUnits;
  boolean_T EstimateSkew;
  real_T NumRadialDistortionCoefficients;
  boolean_T EstimateTangentialDistortion;
  array<real_T, 2U> TranslationVectors;
  array<real_T, 2U> RotationVectors;

protected:
  vision::internal::calibration::ImageTransformer UndistortMap;
  real_T IntrinsicMatrixInternal[9];
};

class d_cameraParameters {
public:
  d_cameraParameters *
  init(const emlrtStack *sp,
       const ::coder::array<real_T, 2U> &varargin_1_RadialDistortion,
       const real_T varargin_1_TangentialDistortion[2],
       const real_T varargin_1_ImageSize[2],
       const char_T varargin_1_WorldUnits[2], boolean_T varargin_1_EstimateSkew,
       real_T c_varargin_1_NumRadialDistortio,
       boolean_T c_varargin_1_EstimateTangential,
       const ::coder::array<real_T, 2U> &varargin_1_RotationVectors,
       const ::coder::array<real_T, 2U> &varargin_1_TranslationVectors,
       const real_T varargin_1_IntrinsicMatrix[9]);
  real_T ImageSize[2];
  array<real_T, 2U> RadialDistortion;
  real_T TangentialDistortion[2];
  char_T WorldUnits[2];
  boolean_T EstimateSkew;
  real_T NumRadialDistortionCoefficients;
  boolean_T EstimateTangentialDistortion;
  array<real_T, 2U> TranslationVectors;
  array<real_T, 2U> RotationVectors;
  real_T IntrinsicMatrixInternal[9];

protected:
  vision::internal::calibration::ImageTransformer UndistortMap;
};

} // namespace coder

// End of code generation (cameraParameters.h)
