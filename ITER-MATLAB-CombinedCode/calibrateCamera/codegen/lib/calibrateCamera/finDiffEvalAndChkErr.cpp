//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: finDiffEvalAndChkErr.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "finDiffEvalAndChkErr.h"
#include "CalculateCost.h"
#include "anonymous_function.h"
#include "anonymous_function1.h"
#include "calibrateCamera_internal_types1.h"
#include "calibrateCamera_internal_types11.h"
#include "calibrateCamera_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const b_anonymous_function *obj_nonlin
//                int32_T obj_mEq
//                ::coder::array<real_T, 1U> &cEqPlus
//                int32_T dim
//                real_T delta
//                ::coder::array<real_T, 1U> &xk
//                boolean_T *evalOK
//                real_T *fplus
// Return Type  : void
//
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
                          real_T *fplus)
{
  real_T temp_tmp;
  int32_T idx;
  *fplus = 0.0;
  *evalOK = true;
  temp_tmp = xk[dim - 1];
  xk[dim - 1] = temp_tmp + delta;
  CalculateCost(
      xk, &obj_nonlin->workspace.fun.workspace.calibration.CameraParameters,
      obj_nonlin->workspace.fun.workspace.calibration.PatternPositions,
      obj_nonlin->workspace.fun.workspace.calibration.ImagePoints,
      obj_nonlin->workspace.fun.workspace.genPoints,
      obj_nonlin->workspace.fun.workspace.detPoints, cEqPlus);
  idx = 0;
  while ((*evalOK) && ((idx + 1) <= obj_mEq)) {
    *evalOK = ((!std::isinf(cEqPlus[idx])) && (!std::isnan(cEqPlus[idx])));
    idx++;
  }
  xk[dim - 1] = temp_tmp;
}

} // namespace internal
} // namespace FiniteDifferences
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace Codegen

//
// File trailer for finDiffEvalAndChkErr.cpp
//
// [EOF]
//
