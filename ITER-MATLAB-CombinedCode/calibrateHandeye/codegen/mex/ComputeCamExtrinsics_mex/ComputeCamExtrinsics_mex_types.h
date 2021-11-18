//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// ComputeCamExtrinsics_mex_types.h
//
// Code generation for function 'ComputeCamExtrinsics'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"

// Type Definitions
struct struct0_T {
  real_T RadialDistortion[3];
  real_T TangentialDistortion[2];
  real_T ImageSize[2];
  coder::array<real_T, 2U> WorldPoints;
  char_T WorldUnits;
  boolean_T EstimateSkew;
  real_T NumRadialDistortionCoefficients;
  boolean_T EstimateTangentialDistortion;
  coder::array<real_T, 2U> RotationVectors;
  coder::array<real_T, 2U> TranslationVectors;
  coder::array<real_T, 3U> ReprojectionErrors;
  real_T IntrinsicMatrix[9];
  coder::array<boolean_T, 2U> DetectedKeypoints;
};

// End of code generation (ComputeCamExtrinsics_mex_types.h)
