//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: lsqnonlin.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef LSQNONLIN_H
#define LSQNONLIN_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class b_anonymous_function;

}

// Function Declarations
namespace coder {
void lsqnonlin(const b_anonymous_function *fun,
               ::coder::array<double, 1U> &xCurrent,
               const ::coder::array<double, 1U> &lb,
               const ::coder::array<double, 1U> &ub, double *resnorm,
               ::coder::array<double, 1U> &fval, double *exitflag,
               double *output_iterations, double *output_funcCount,
               double *output_stepsize, double *output_firstorderopt,
               char output_algorithm[19],
               ::coder::array<double, 1U> &lambda_lower,
               ::coder::array<double, 1U> &lambda_upper,
               ::coder::array<double, 2U> &jacob);

}

#endif
//
// File trailer for lsqnonlin.h
//
// [EOF]
//
