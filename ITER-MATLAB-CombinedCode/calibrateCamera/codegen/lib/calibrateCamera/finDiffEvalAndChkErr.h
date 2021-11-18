//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: finDiffEvalAndChkErr.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef FINDIFFEVALANDCHKERR_H
#define FINDIFFEVALANDCHKERR_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

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
void finDiffEvalAndChkErr(const b_anonymous_function *obj_nonlin,
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

#endif
//
// File trailer for finDiffEvalAndChkErr.h
//
// [EOF]
//
