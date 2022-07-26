//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: finDiffEvalAndChkErr.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef FINDIFFEVALANDCHKERR_H
#define FINDIFFEVALANDCHKERR_H

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
class c_anonymous_function;

class b_anonymous_function;

class e_anonymous_function;

} // namespace coder
} // namespace ITER

// Function Declarations
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
namespace internal {
bool b_finDiffEvalAndChkErr(const b_anonymous_function *obj_objfun,
                            bool obj_SpecifyObjectiveGradient, double *fplus,
                            int dim, double delta, double b_xk[7]);

bool c_finDiffEvalAndChkErr(const e_anonymous_function *obj_nonlin, int obj_mEq,
                            bool obj_SpecifyConstraintGradient,
                            ::coder::array<double, 1U> &cEqPlus, int dim,
                            double delta, ::coder::array<double, 1U> &b_xk);

bool finDiffEvalAndChkErr(const c_anonymous_function *obj_nonlin, int obj_mEq,
                          bool obj_SpecifyConstraintGradient,
                          ::coder::array<double, 1U> &cEqPlus, int dim,
                          double delta, double b_xk[6]);

} // namespace internal
} // namespace FiniteDifferences
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for finDiffEvalAndChkErr.h
//
// [EOF]
//
