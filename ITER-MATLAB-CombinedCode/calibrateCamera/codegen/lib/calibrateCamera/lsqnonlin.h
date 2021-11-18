//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: lsqnonlin.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef LSQNONLIN_H
#define LSQNONLIN_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace Codegen {
namespace coder {
class anonymous_function;

}
} // namespace Codegen

// Function Declarations
namespace Codegen {
namespace coder {
void lsqnonlin(const anonymous_function *fun,
               ::coder::array<real_T, 1U> &xCurrent, real_T *resnorm,
               ::coder::array<real_T, 1U> &fval, real_T *exitflag,
               real_T *output_iterations, real_T *output_funcCount,
               real_T *output_stepsize, real_T *output_firstorderopt,
               char_T output_algorithm[19],
               ::coder::array<real_T, 1U> &lambda_lower,
               ::coder::array<real_T, 1U> &lambda_upper,
               ::coder::array<real_T, 2U> &jacob);

}
} // namespace Codegen

#endif
//
// File trailer for lsqnonlin.h
//
// [EOF]
//
