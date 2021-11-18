//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calibrateOneCamera_internal_types.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

#ifndef CALIBRATEONECAMERA_INTERNAL_TYPES_H
#define CALIBRATEONECAMERA_INTERNAL_TYPES_H

// Include Files
#include "anonymous_function.h"
#include "calibrateOneCamera_types.h"
#include "rtwtypes.h"
#include "coder_array.h"

// Type Definitions
namespace Codegen {
struct struct_T {
  ::coder::array<bool, 2U> bw;
};

struct e_struct_T {
  double RadialDistortion[3];
  double TangentialDistortion[2];
  double ImageSize[2];
  char WorldUnits[2];
  bool EstimateSkew;
  double NumRadialDistortionCoefficients;
  bool EstimateTangentialDistortion;
  double IntrinsicMatrix[3][3];
};

struct g_struct_T {
  coder::b_anonymous_function nonlin;
  double b_f_1;
  ::coder::array<double, 1U> cEq_1;
  double f_2;
  ::coder::array<double, 1U> cEq_2;
  int nVar;
  int mIneq;
  int mEq;
  int numEvals;
  bool SpecifyObjectiveGradient;
  bool SpecifyConstraintGradient;
  bool isEmptyNonlcon;
  ::coder::array<bool, 1U> hasLB;
  ::coder::array<bool, 1U> hasUB;
  bool hasBounds;
  int FiniteDifferenceType;
};

} // namespace Codegen

#endif
//
// File trailer for calibrateOneCamera_internal_types.h
//
// [EOF]
//
