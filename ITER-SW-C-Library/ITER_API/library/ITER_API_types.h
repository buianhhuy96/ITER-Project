//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ITER_API_types.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef ITER_API_TYPES_H
#define ITER_API_TYPES_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#define MAX_THREADS omp_get_max_threads()

// Type Definitions
namespace ITER {
struct struct2_T {
  double minArea;
  double maxArea;
  double ThresholdDelta;
};

struct struct0_T {
  ::coder::array<double, 2U> RadialDistortion;
  double TangentialDistortion[2];
  double ImageSize[2];
  char WorldUnits[2];
  bool EstimateSkew;
  double NumRadialDistortionCoefficients;
  bool EstimateTangentialDistortion;
  ::coder::array<double, 2U> RotationVectors;
  ::coder::array<double, 2U> TranslationVectors;
  double IntrinsicMatrix[3][3];
};

struct k_struct_T {
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

struct struct1_T {
  double RadialDistortion[3];
  double TangentialDistortion[2];
  double ImageSize[2];
  char WorldUnits[2];
  bool EstimateSkew;
  double NumRadialDistortionCoefficients;
  bool EstimateTangentialDistortion;
  double IntrinsicMatrix[3][3];
};

} // namespace ITER

#endif
//
// File trailer for ITER_API_types.h
//
// [EOF]
//
