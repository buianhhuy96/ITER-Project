//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// calibrateOneCamera_mex_internal_types.h
//
// Code generation for function 'calibrateOneCamera'
//

#pragma once

// Include files
#include "anonymous_function.h"
#include "calibrateOneCamera_mex_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"

// Type Definitions
namespace Codegen {
struct c_struct_T {
  real_T RadialDistortion[3];
  real_T TangentialDistortion[2];
  real_T ImageSize[2];
  char_T WorldUnits[2];
  boolean_T EstimateSkew;
  real_T NumRadialDistortionCoefficients;
  boolean_T EstimateTangentialDistortion;
  real_T IntrinsicMatrix[9];
};

struct e_struct_T {
  coder::b_anonymous_function nonlin;
  real_T f_1;
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

struct rtDesignRangeCheckInfo {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
};

struct rtRunTimeErrorInfo {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
};

} // namespace Codegen

// End of code generation (calibrateOneCamera_mex_internal_types.h)
