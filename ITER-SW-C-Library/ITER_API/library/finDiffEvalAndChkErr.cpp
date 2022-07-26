//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: finDiffEvalAndChkErr.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "finDiffEvalAndChkErr.h"
#include "ITER_API_internal_types1.h"
#include "ITER_API_internal_types11.h"
#include "ITER_API_types.h"
#include "anonymous_function.h"
#include "anonymous_function1.h"
#include "calibrateOneCamera.h"
#include "cameraParameters.h"
#include "estimateKnucklePose.h"
#include "optimizeCamPose.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const b_anonymous_function *obj_objfun
//                bool obj_SpecifyObjectiveGradient
//                double *fplus
//                int dim
//                double delta
//                double b_xk[7]
// Return Type  : bool
//
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
namespace internal {
bool b_finDiffEvalAndChkErr(const b_anonymous_function *obj_objfun,
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

//
// Arguments    : const e_anonymous_function *obj_nonlin
//                int obj_mEq
//                bool obj_SpecifyConstraintGradient
//                ::coder::array<double, 1U> &cEqPlus
//                int dim
//                double delta
//                ::coder::array<double, 1U> &b_xk
// Return Type  : bool
//
bool c_finDiffEvalAndChkErr(const e_anonymous_function *obj_nonlin, int obj_mEq,
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
// Arguments    : const c_anonymous_function *obj_nonlin
//                int obj_mEq
//                bool obj_SpecifyConstraintGradient
//                ::coder::array<double, 1U> &cEqPlus
//                int dim
//                double delta
//                double b_xk[6]
// Return Type  : bool
//
bool finDiffEvalAndChkErr(const c_anonymous_function *obj_nonlin, int obj_mEq,
                          bool obj_SpecifyConstraintGradient,
                          ::coder::array<double, 1U> &cEqPlus, int dim,
                          double delta, double b_xk[6])
{
  ::coder::array<double, 2U> r;
  double temp;
  double temp_tmp;
  bool evalOK;
  evalOK = true;
  temp_tmp = b_xk[dim - 1];
  temp = temp_tmp;
  b_xk[dim - 1] = temp_tmp + delta;
  if (!obj_SpecifyConstraintGradient) {
    int b_loop_ub;
    int idx;
    int loop_ub;
    estimateKnucklePose_anonFcn1(
        obj_nonlin->workspace.fun.workspace.imagePointsTmp,
        obj_nonlin->workspace.fun.workspace.worldPointsTmp,
        obj_nonlin->workspace.fun.workspace.cameraParams, b_xk, r);
    loop_ub = r.size(0) * 2;
    cEqPlus.set_size(loop_ub);
    b_loop_ub = loop_ub;
    if ((static_cast<int>(loop_ub < 4)) != 0) {
      for (int b_i{0}; b_i < loop_ub; b_i++) {
        cEqPlus[b_i] = r[b_i];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int b_i = 0; b_i < b_loop_ub; b_i++) {
        cEqPlus[b_i] = r[b_i];
      }
    }
    idx = 0;
    while (evalOK && ((idx + 1) <= obj_mEq)) {
      evalOK = ((!std::isinf(r[idx])) && (!std::isnan(r[idx])));
      idx++;
    }
  }
  b_xk[dim - 1] = temp;
  return evalOK;
}

} // namespace internal
} // namespace FiniteDifferences
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

//
// File trailer for finDiffEvalAndChkErr.cpp
//
// [EOF]
//
