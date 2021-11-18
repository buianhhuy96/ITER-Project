//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calibrateCamera_internal_types.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef CALIBRATECAMERA_INTERNAL_TYPES_H
#define CALIBRATECAMERA_INTERNAL_TYPES_H

// Include Files
#include "anonymous_function.h"
#include "calibrateCamera_types.h"
#include "rtwtypes.h"
#include "coder_array.h"

// Type Definitions
namespace Codegen {
struct c_struct_T {
  coder::b_anonymous_function nonlin;
  real_T b_f_1;
  ::coder::array<real_T, 1U> cEq_1;
  real_T f_2;
  ::coder::array<real_T, 1U> cEq_2;
  int32_T nVar;
  int32_T mIneq;
  int32_T mEq;
  int32_T numEvals;
  boolean_T SpecifyObjectiveGradient;
  boolean_T SpecifyConstraintGradient;
  boolean_T isEmptyNonlcon;
  ::coder::array<boolean_T, 1U> hasLB;
  ::coder::array<boolean_T, 1U> hasUB;
  boolean_T hasBounds;
  int32_T FiniteDifferenceType;
};

} // namespace Codegen

#endif
//
// File trailer for calibrateCamera_internal_types.h
//
// [EOF]
//
