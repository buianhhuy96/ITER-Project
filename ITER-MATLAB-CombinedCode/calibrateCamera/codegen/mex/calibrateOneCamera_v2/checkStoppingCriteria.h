//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// checkStoppingCriteria.h
//
// Code generation for function 'checkStoppingCriteria'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
int32_T b_checkStoppingCriteria(
    real_T options_MaxFunctionEvaluations,
    const ::coder::array<real_T, 1U> &gradf, real_T relFactor, real_T funDiff,
    const ::coder::array<real_T, 1U> &x, const ::coder::array<real_T, 1U> &dx,
    int32_T funcCount, boolean_T stepSuccessful, int32_T *iter,
    real_T projSteepestDescentInfNorm, boolean_T hasFiniteBounds);

int32_T checkStoppingCriteria(real_T options_MaxFunctionEvaluations,
                              const ::coder::array<real_T, 1U> &gradf,
                              real_T relFactor,
                              const ::coder::array<real_T, 1U> &x,
                              const ::coder::array<real_T, 1U> &dx,
                              int32_T funcCount,
                              real_T projSteepestDescentInfNorm,
                              boolean_T hasFiniteBounds);

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (checkStoppingCriteria.h)
