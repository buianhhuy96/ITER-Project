//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// driver.h
//
// Code generation for function 'driver'
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
namespace optim {
namespace coder {
namespace levenbergMarquardt {
void driver(const emlrtStack *sp, const anonymous_function *fun,
            const ::coder::array<real_T, 1U> &x0, ::coder::array<real_T, 1U> &x,
            real_T *resnorm, ::coder::array<real_T, 1U> &fCurrent,
            real_T *exitflag, real_T *output_iterations,
            real_T *output_funcCount, real_T *output_stepsize,
            real_T *output_firstorderopt, char_T output_algorithm[19],
            ::coder::array<real_T, 1U> &lambda_lower,
            ::coder::array<real_T, 1U> &lambda_upper,
            ::coder::array<real_T, 2U> &jacobian);

void driver_anonFcn1(const emlrtStack *sp, const anonymous_function *fun,
                     const ::coder::array<real_T, 1U> &x,
                     ::coder::array<real_T, 1U> &varargout_2);

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (driver.h)
