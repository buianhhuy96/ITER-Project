//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calibrateHandeye_types.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
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
  bool EstimateSkew;
  double NumRadialDistortionCoefficients;
  bool EstimateTangentialDistortion;
  coder::array<double, 2U> RotationVectors;
  coder::array<double, 2U> TranslationVectors;
  coder::array<double, 3U> ReprojectionErrors;
  double IntrinsicMatrix[3][3];
  coder::array<bool, 2U> DetectedKeypoints;
};

struct struct1_T {
  double RadialDistortion[3];
  double TangentialDistortion[2];
  double ImageSize[2];
  double WorldPoints[2][54];
  char WorldUnits;
  bool EstimateSkew;
  double NumRadialDistortionCoefficients;
  bool EstimateTangentialDistortion;
  double RotationVectors[3][30];
  double TranslationVectors[3][30];
  double ReprojectionErrors[30][2][54];
  double IntrinsicMatrix[3][3];
  bool DetectedKeypoints[30][54];
};

#endif
//
// File trailer for calibrateHandeye_types.h
//
// [EOF]
//
