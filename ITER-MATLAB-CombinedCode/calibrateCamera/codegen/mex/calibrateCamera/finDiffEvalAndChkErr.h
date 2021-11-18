//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// finDiffEvalAndChkErr.h
//
// Code generation for function 'finDiffEvalAndChkErr'
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
namespace coder {
class b_anonymous_function;

}
} // namespace Codegen

// Function Declarations
namespace Codegen {
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
namespace internal {
void finDiffEvalAndChkErr(const emlrtStack *sp,
                          const b_anonymous_function *obj_nonlin,
                          int32_T obj_mEq, ::coder::array<real_T, 1U> &cEqPlus,
                          int32_T dim, real_T delta,
                          ::coder::array<real_T, 1U> &xk, boolean_T *evalOK,
                          real_T *fplus);

}
} // namespace FiniteDifferences
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace Codegen

// End of code generation (finDiffEvalAndChkErr.h)
