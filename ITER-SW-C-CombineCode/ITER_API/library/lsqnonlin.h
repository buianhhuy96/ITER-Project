//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: lsqnonlin.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
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
class anonymous_function;

}

// Function Declarations
namespace coder {
void lsqnonlin(const anonymous_function *fun,
               ::coder::array<double, 1U> &xCurrent, double *resnorm,
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
