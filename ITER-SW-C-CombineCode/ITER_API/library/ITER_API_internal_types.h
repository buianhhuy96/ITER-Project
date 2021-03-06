//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ITER_API_internal_types.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

#ifndef ITER_API_INTERNAL_TYPES_H
#define ITER_API_INTERNAL_TYPES_H

// Include Files
#include "ITER_API_types.h"
#include "anonymous_function.h"
#include "rtwtypes.h"
#include "coder_array.h"

// Type Definitions
struct cell_wrap_19 {
  coder::array<double, 2U> f1;
};

struct struct_T {
  coder::array<bool, 2U> bw;
};

struct f_struct_T {
  coder::b_anonymous_function nonlin;
  double b_f_1;
  coder::array<double, 1U> cEq_1;
  double f_2;
  coder::array<double, 1U> cEq_2;
  int nVar;
  int mIneq;
  int mEq;
  int numEvals;
  bool SpecifyObjectiveGradient;
  bool SpecifyConstraintGradient;
  bool isEmptyNonlcon;
  coder::array<bool, 1U> hasLB;
  coder::array<bool, 1U> hasUB;
  bool hasBounds;
  int FiniteDifferenceType;
};

#endif
//
// File trailer for ITER_API_internal_types.h
//
// [EOF]
//
