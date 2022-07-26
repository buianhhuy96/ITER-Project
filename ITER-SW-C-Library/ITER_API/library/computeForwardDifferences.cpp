//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeForwardDifferences.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "computeForwardDifferences.h"
#include "ITER_API_internal_types.h"
#include "anonymous_function.h"
#include "finDiffEvalAndChkErr.h"
#include "fwdFinDiffInsideBnds.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : t_struct_T *obj
//                double fCurrent
//                double b_xk[7]
//                double gradf[8]
// Return Type  : bool
//
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
namespace internal {
bool computeForwardDifferences(t_struct_T *obj, double fCurrent, double b_xk[7],
                               double gradf[8])
{
  double b_deltaX;
  int idx;
  bool evalOK;
  bool exitg1;
  evalOK = true;
  obj->numEvals = 0;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx <= (obj->nVar - 1))) {
    bool b_evalOK;
    bool guard1{false};
    bool modifiedStep;
    modifiedStep = false;
    b_deltaX = (1.4901161193847656E-8 *
                (1.0 - (2.0 * (static_cast<double>(b_xk[idx] < 0.0))))) *
               std::fmax(std::abs(b_xk[idx]), 1.0);
    if ((obj->hasLB[idx]) || (obj->hasUB[idx])) {
      if ((obj->hasLB[idx]) && (obj->hasUB[idx])) {
        modifiedStep = fwdFinDiffInsideBnds(b_xk[idx], -1.7976931348623157E+308,
                                            1.7976931348623157E+308, &b_deltaX);
      } else if (obj->hasUB[idx]) {
        double d_deltaX;
        d_deltaX = b_deltaX;
        if ((b_xk[idx] <= 1.7976931348623157E+308) &&
            ((b_xk[idx] + b_deltaX) > 1.7976931348623157E+308)) {
          d_deltaX = -b_deltaX;
          modifiedStep = true;
        }
        b_deltaX = d_deltaX;
      } else {
        double c_deltaX;
        c_deltaX = b_deltaX;
        if ((b_xk[idx] >= -1.7976931348623157E+308) &&
            ((b_xk[idx] + b_deltaX) < -1.7976931348623157E+308)) {
          c_deltaX = -b_deltaX;
          modifiedStep = true;
        }
        b_deltaX = c_deltaX;
      }
    }
    b_evalOK =
        b_finDiffEvalAndChkErr(&obj->objfun, obj->SpecifyObjectiveGradient,
                               &obj->b_f_1, idx + 1, b_deltaX, b_xk);
    evalOK = b_evalOK;
    obj->numEvals++;
    guard1 = false;
    if (!b_evalOK) {
      if (!modifiedStep) {
        bool insideBnds;
        b_deltaX = -b_deltaX;
        if (obj->hasLB[idx]) {
          double d;
          d = b_xk[idx] + b_deltaX;
          if (((d >= -1.7976931348623157E+308) && (obj->hasUB[idx])) &&
              (d <= 1.7976931348623157E+308)) {
            insideBnds = true;
          } else {
            insideBnds = false;
          }
        } else {
          insideBnds = false;
        }
        if ((!obj->hasBounds) || insideBnds) {
          evalOK = b_finDiffEvalAndChkErr(&obj->objfun,
                                          obj->SpecifyObjectiveGradient,
                                          &obj->b_f_1, idx + 1, b_deltaX, b_xk);
          obj->numEvals++;
        }
      }
      if (!evalOK) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      gradf[idx] = (obj->b_f_1 - fCurrent) / b_deltaX;
      idx++;
    }
  }
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
// File trailer for computeForwardDifferences.cpp
//
// [EOF]
//
