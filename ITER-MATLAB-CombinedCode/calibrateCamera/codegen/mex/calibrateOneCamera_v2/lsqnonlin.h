//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// lsqnonlin.h
//
// Code generation for function 'lsqnonlin'
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

// Type Declarations
namespace coder {
class anonymous_function;

}

// Function Declarations
namespace coder {
void lsqnonlin(const emlrtStack *sp, const anonymous_function *fun,
               ::coder::array<real_T, 1U> &xCurrent, real_T *resnorm,
               ::coder::array<real_T, 1U> &fval, real_T *exitflag,
               ::coder::array<real_T, 2U> &jacob);

}

// End of code generation (lsqnonlin.h)
