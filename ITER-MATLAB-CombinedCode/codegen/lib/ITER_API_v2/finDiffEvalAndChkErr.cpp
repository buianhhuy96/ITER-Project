//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: finDiffEvalAndChkErr.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "finDiffEvalAndChkErr.h"
#include "CalculateCost.h"
#include "ITER_API_v2_internal_types1.h"
#include "ITER_API_v2_internal_types11.h"
#include "ITER_API_v2_internal_types2.h"
#include "ITER_API_v2_internal_types3.h"
#include "anonymous_function.h"
#include "anonymous_function1.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const b_anonymous_function *obj_nonlin
//                int obj_mEq
//                bool obj_SpecifyConstraintGradient
//                ::coder::array<double, 1U> &cEqPlus
//                int dim
//                double delta
//                ::coder::array<double, 1U> &xk
// Return Type  : bool
//
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
namespace internal {
bool finDiffEvalAndChkErr(const b_anonymous_function *obj_nonlin, int obj_mEq,
                          bool obj_SpecifyConstraintGradient,
                          ::coder::array<double, 1U> &cEqPlus, int dim,
                          double delta, ::coder::array<double, 1U> &xk)
{
  double temp_tmp;
  bool evalOK;
  evalOK = true;
  temp_tmp = xk[dim - 1];
  xk[dim - 1] = temp_tmp + delta;
  if (!obj_SpecifyConstraintGradient) {
    int idx;
    CalculateCost(
        xk,
        obj_nonlin->workspace.fun.workspace.calibration.CameraParameters
            .ImageSize,
        obj_nonlin->workspace.fun.workspace.calibration.PatternPositions,
        obj_nonlin->workspace.fun.workspace.genPoints,
        obj_nonlin->workspace.fun.workspace.detPoints, cEqPlus);
    idx = 0;
    while (evalOK && ((idx + 1) <= obj_mEq)) {
      evalOK = ((!std::isinf(cEqPlus[idx])) && (!std::isnan(cEqPlus[idx])));
      idx++;
    }
  }
  xk[dim - 1] = temp_tmp;
  return evalOK;
}

} // namespace internal
} // namespace FiniteDifferences
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for finDiffEvalAndChkErr.cpp
//
// [EOF]
//
