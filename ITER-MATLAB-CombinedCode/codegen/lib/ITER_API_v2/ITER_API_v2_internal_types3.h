//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ITER_API_v2_internal_types3.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

#ifndef ITER_API_V2_INTERNAL_TYPES3_H
#define ITER_API_V2_INTERNAL_TYPES3_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
struct cell_wrap_0 {
  double f1[4][4];
};

struct c_struct_T {
  double RadialDistortion[3];
  double TangentialDistortion[2];
  double ImageSize[2];
  coder::array<double, 2U> WorldPoints;
  coder::array<char, 2U> WorldUnits;
  bool EstimateSkew;
  double NumRadialDistortionCoefficients;
  bool EstimateTangentialDistortion;
  coder::array<double, 2U> RotationVectors;
  coder::array<double, 2U> TranslationVectors;
  double IntrinsicMatrix[3][3];
};

#endif
//
// File trailer for ITER_API_v2_internal_types3.h
//
// [EOF]
//
