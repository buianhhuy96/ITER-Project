//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// jacobianFiniteDifference.h
//
// Code generation for function 'jacobianFiniteDifference'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include "omp.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Declarations
namespace Codegen {
struct d_struct_T;

}

// Function Declarations
namespace Codegen {
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
boolean_T b_jacobianFiniteDifference(
    const emlrtStack *sp, ::coder::array<real_T, 2U> &augJacobian,
    const ::coder::array<real_T, 1U> &fCurrent, int32_T *funcCount,
    const ::coder::array<real_T, 1U> &x,
    const char_T options_FiniteDifferenceType[7],
    const ::coder::array<real_T, 1U> &TypicalX,
    const d_struct_T *FiniteDifferences,
    const ::coder::array<real_T, 1U> &runTimeOptions_TypicalX,
    const ::coder::array<real_T, 1U> &c_runTimeOptions_FiniteDifferen);

void jacobianFiniteDifference(
    const emlrtStack *sp, ::coder::array<real_T, 2U> &augJacobian,
    const ::coder::array<real_T, 1U> &fCurrent,
    const ::coder::array<real_T, 1U> &x,
    const char_T options_FiniteDifferenceType[7],
    const ::coder::array<real_T, 1U> &TypicalX, d_struct_T *FiniteDifferences,
    const ::coder::array<real_T, 1U> &runTimeOptions_TypicalX,
    const ::coder::array<real_T, 1U> &c_runTimeOptions_FiniteDifferen,
    int32_T *funcCount, boolean_T *evalOK);

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace Codegen

// End of code generation (jacobianFiniteDifference.h)
