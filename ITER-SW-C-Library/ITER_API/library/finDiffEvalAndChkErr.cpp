//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: finDiffEvalAndChkErr.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "finDiffEvalAndChkErr.h"
#include "ITER_API_internal_types1.h"
#include "ITER_API_internal_types11.h"
#include "ITER_API_types.h"
#include "anonymous_function.h"
#include "anonymous_function1.h"
#include "calibrateOneCamera.h"
#include "optimizeCamPose.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const c_anonymous_function *obj_nonlin
//                int obj_mEq
//                bool obj_SpecifyConstraintGradient
//                ::coder::array<double, 1U> &cEqPlus
//                int dim
//                double delta
//                ::coder::array<double, 1U> &b_xk
// Return Type  : bool
//
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
namespace internal {
bool b_finDiffEvalAndChkErr(const c_anonymous_function *obj_nonlin, int obj_mEq,
                            bool obj_SpecifyConstraintGradient,
                            ::coder::array<double, 1U> &cEqPlus, int dim,
                            double delta, ::coder::array<double, 1U> &b_xk)
{
  double temp_tmp;
  bool evalOK;
  evalOK = true;
  temp_tmp = b_xk[dim - 1];
  b_xk[dim - 1] = temp_tmp + delta;
  if (!obj_SpecifyConstraintGradient) {
    int idx;
    reprojectWrapper(b_xk, &obj_nonlin->workspace.fun.workspace.initialParams,
                     obj_nonlin->workspace.fun.workspace.b_world_points,
                     obj_nonlin->workspace.fun.workspace.image_points, cEqPlus);
    idx = 0;
    while (evalOK && ((idx + 1) <= obj_mEq)) {
      evalOK = ((!std::isinf(cEqPlus[idx])) && (!std::isnan(cEqPlus[idx])));
      idx++;
    }
  }
  b_xk[dim - 1] = temp_tmp;
  return evalOK;
}

//
// Arguments    : const anonymous_function *obj_objfun
//                bool obj_SpecifyObjectiveGradient
//                double *fplus
//                int dim
//                double delta
//                double b_xk[7]
// Return Type  : bool
//
bool finDiffEvalAndChkErr(const anonymous_function *obj_objfun,
                          bool obj_SpecifyObjectiveGradient, double *fplus,
                          int dim, double delta, double b_xk[7])
{
  double temp_tmp;
  bool evalOK;
  evalOK = true;
  temp_tmp = b_xk[dim - 1];
  b_xk[dim - 1] = temp_tmp + delta;
  if (!obj_SpecifyObjectiveGradient) {
    *fplus = optimizeCamPose_anonFcn1(obj_objfun->workspace.undist_imgMarkerPts,
                                      obj_objfun->workspace.WptsTrio,
                                      obj_objfun->workspace.K11, b_xk);
    evalOK = ((!std::isinf(*fplus)) && (!std::isnan(*fplus)));
    if (evalOK) {
      b_xk[dim - 1] = temp_tmp;
    }
  } else {
    b_xk[dim - 1] = temp_tmp;
  }
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
