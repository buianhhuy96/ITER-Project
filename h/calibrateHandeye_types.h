//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calibrateHandeye_types.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

#ifndef CALIBRATEHANDEYE_TYPES_H
#define CALIBRATEHANDEYE_TYPES_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#define MAX_THREADS omp_get_max_threads()

// Type Definitions
struct struct0_T {
  double RadialDistortion[3];
  double TangentialDistortion[2];
  double ImageSize[2];
  coder::array<double, 2U> WorldPoints;
  char WorldUnits;
  boolean_T EstimateSkew;
  double NumRadialDistortionCoefficients;
  boolean_T EstimateTangentialDistortion;
  coder::array<double, 2U> RotationVectors;
  coder::array<double, 2U> TranslationVectors;
  coder::array<double, 3U> ReprojectionErrors;
  double IntrinsicMatrix[3][3];
  coder::array<boolean_T, 2U> DetectedKeypoints;
};

#endif
//
// File trailer for calibrateHandeye_types.h
//
// [EOF]
//
