//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calibrateOneCamera_types.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

#ifndef CALIBRATEONECAMERA_TYPES_H
#define CALIBRATEONECAMERA_TYPES_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#define MAX_THREADS omp_get_max_threads()

// Type Definitions
namespace Codegen {
struct cell_wrap_0 {
  double f1[4][4];
};

struct struct1_T {
  double RadialDistortion[3];
  double TangentialDistortion[2];
  double ImageSize[2];
  ::coder::array<double, 2U> WorldPoints;
  ::coder::array<char, 2U> WorldUnits;
  bool EstimateSkew;
  double NumRadialDistortionCoefficients;
  bool EstimateTangentialDistortion;
  ::coder::array<double, 2U> RotationVectors;
  ::coder::array<double, 2U> TranslationVectors;
  double IntrinsicMatrix[3][3];
};

struct struct0_T {
  struct1_T CameraParameters;
  ::coder::array<cell_wrap_0, 2U> PatternPositions;
  ::coder::array<double, 3U> ImagePoints;
  ::coder::array<double, 1U> b_Error;
};

} // namespace Codegen

#endif
//
// File trailer for calibrateOneCamera_types.h
//
// [EOF]
//
