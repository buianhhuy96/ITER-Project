//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// calibrateOneCamera_v2_mex_types.h
//
// Code generation for function 'calibrateOneCamera_v2'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"

// Type Definitions
struct struct0_T {
  coder::array<real_T, 2U> RadialDistortion;
  real_T TangentialDistortion[2];
  real_T ImageSize[2];
  char_T WorldUnits[2];
  boolean_T EstimateSkew;
  real_T NumRadialDistortionCoefficients;
  boolean_T EstimateTangentialDistortion;
  coder::array<real_T, 2U> RotationVectors;
  coder::array<real_T, 2U> TranslationVectors;
  real_T IntrinsicMatrix[9];
};

struct struct_T {
  real_T RadialDistortion[3];
  real_T TangentialDistortion[2];
  real_T ImageSize[2];
  coder::array<real_T, 2U> WorldPoints;
  coder::array<char_T, 2U> WorldUnits;
  boolean_T EstimateSkew;
  real_T NumRadialDistortionCoefficients;
  boolean_T EstimateTangentialDistortion;
  coder::array<real_T, 2U> RotationVectors;
  coder::array<real_T, 2U> TranslationVectors;
  real_T IntrinsicMatrix[9];
};

struct struct1_T {
  real_T RadialDistortion[3];
  real_T TangentialDistortion[2];
  real_T ImageSize[2];
  char_T WorldUnits[2];
  boolean_T EstimateSkew;
  real_T NumRadialDistortionCoefficients;
  boolean_T EstimateTangentialDistortion;
  real_T IntrinsicMatrix[9];
};

// End of code generation (calibrateOneCamera_v2_mex_types.h)
