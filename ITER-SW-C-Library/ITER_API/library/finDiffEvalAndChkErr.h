//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: finDiffEvalAndChkErr.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef FINDIFFEVALANDCHKERR_H
#define FINDIFFEVALANDCHKERR_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class anonymous_function;

class c_anonymous_function;

} // namespace coder

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
namespace internal {
bool b_finDiffEvalAndChkErr(const c_anonymous_function *obj_nonlin, int obj_mEq,
                            bool obj_SpecifyConstraintGradient,
                            ::coder::array<double, 1U> &cEqPlus, int dim,
                            double delta, ::coder::array<double, 1U> &b_xk);

bool finDiffEvalAndChkErr(const anonymous_function *obj_objfun,
                          bool obj_SpecifyObjectiveGradient, double *fplus,
                          int dim, double delta, double b_xk[7]);

} // namespace internal
} // namespace FiniteDifferences
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

#endif
//
// File trailer for finDiffEvalAndChkErr.h
//
// [EOF]
//
