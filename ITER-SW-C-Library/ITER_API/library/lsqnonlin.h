//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: lsqnonlin.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef LSQNONLIN_H
#define LSQNONLIN_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace ITER {
namespace coder {
class d_anonymous_function;

}
} // namespace ITER

// Function Declarations
namespace ITER {
namespace coder {
void lsqnonlin(const d_anonymous_function *fun,
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
} // namespace ITER

#endif
//
// File trailer for lsqnonlin.h
//
// [EOF]
//
