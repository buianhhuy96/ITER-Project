//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// calibrateOneCamera_mex_types.h
//
// Code generation for function 'calibrateOneCamera'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#define MAX_THREADS omp_get_max_threads()

// Type Definitions
namespace Codegen {
struct cell_wrap_0 {
  real_T f1[16];
};

struct emxArray_char_T_1x2 {
  char_T data[2];
  int32_T size[2];
};

struct struct1_T {
  real_T RadialDistortion[3];
  real_T TangentialDistortion[2];
  real_T ImageSize[2];
  ::coder::array<real_T, 2U> WorldPoints;
  emxArray_char_T_1x2 WorldUnits;
  boolean_T EstimateSkew;
  real_T NumRadialDistortionCoefficients;
  boolean_T EstimateTangentialDistortion;
  ::coder::array<real_T, 2U> RotationVectors;
  ::coder::array<real_T, 2U> TranslationVectors;
  real_T IntrinsicMatrix[9];
};

struct struct0_T {
  struct1_T CameraParameters;
  ::coder::array<cell_wrap_0, 2U> PatternPositions;
  ::coder::array<real_T, 3U> ImagePoints;
  ::coder::array<real_T, 1U> Error;
};

} // namespace Codegen

// End of code generation (calibrateOneCamera_mex_types.h)
