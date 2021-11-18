//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ITER_API_v2_types.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

#ifndef ITER_API_V2_TYPES_H
#define ITER_API_V2_TYPES_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#define MAX_THREADS omp_get_max_threads()

// Type Definitions
struct struct0_T {
  double RadialDistortion[3];
  double TangentialDistortion[2];
  double ImageSize[2];
  char WorldUnits[2];
  bool EstimateSkew;
  double NumRadialDistortionCoefficients;
  bool EstimateTangentialDistortion;
  double IntrinsicMatrix[3][3];
};

struct struct1_T {
  double RadialDistortion[3];
  double TangentialDistortion[2];
  double ImageSize[2];
  coder::array<double, 2U> WorldPoints;
  char WorldUnits;
  bool EstimateSkew;
  double NumRadialDistortionCoefficients;
  bool EstimateTangentialDistortion;
  coder::array<double, 2U> RotationVectors;
  coder::array<double, 2U> TranslationVectors;
  coder::array<double, 3U> ReprojectionErrors;
  double IntrinsicMatrix[3][3];
  coder::array<bool, 2U> DetectedKeypoints;
};

#endif
//
// File trailer for ITER_API_v2_types.h
//
// [EOF]
//
