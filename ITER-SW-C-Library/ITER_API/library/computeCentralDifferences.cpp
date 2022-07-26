//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeCentralDifferences.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "computeCentralDifferences.h"
#include "ITER_API_internal_types.h"
#include "anonymous_function.h"
#include "cntrlFinDiffInsideBnds.h"
#include "finDiffEvalAndChkErr.h"
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
bool computeCentralDifferences(t_struct_T *obj, double fCurrent, double b_xk[7],
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
    double delta1;
    double delta2;
    int formulaType;
    b_deltaX = 1.4901161193847656E-8 * std::fmax(std::abs(b_xk[idx]), 1.0);
    if ((obj->hasLB[idx]) || (obj->hasUB[idx])) {
      if ((obj->hasLB[idx]) && (obj->hasUB[idx])) {
        formulaType =
            cntrlFinDiffInsideBnds(b_xk[idx], -1.7976931348623157E+308,
                                   1.7976931348623157E+308, &b_deltaX);
      } else if (obj->hasUB[idx]) {
        formulaType = 0;
        if ((b_xk[idx] <= 1.7976931348623157E+308) &&
            (1.7976931348623157E+308 < (b_xk[idx] + b_deltaX))) {
          formulaType = -1;
        }
      } else {
        formulaType = 0;
        if ((b_xk[idx] >= -1.7976931348623157E+308) &&
            ((b_xk[idx] - b_deltaX) < -1.7976931348623157E+308)) {
          formulaType = 1;
        }
      }
    } else {
      formulaType = 0;
    }
    switch (formulaType) {
    case 0:
      delta1 = -b_deltaX;
      delta2 = b_deltaX;
      break;
    case -1:
      delta1 = -2.0 * b_deltaX;
      delta2 = -b_deltaX;
      break;
    default:
      delta1 = b_deltaX;
      delta2 = 2.0 * b_deltaX;
      break;
    }
    int exitg2;
    bool b_evalOK;
    do {
      exitg2 = 0;
      b_evalOK =
          b_finDiffEvalAndChkErr(&obj->objfun, obj->SpecifyObjectiveGradient,
                                 &obj->b_f_1, idx + 1, delta1, b_xk);
      evalOK = b_evalOK;
      obj->numEvals++;
      if (!b_evalOK) {
        if ((formulaType == 0) &&
            ((!obj->hasBounds) ||
             ((obj->hasUB[idx]) &&
              ((b_xk[idx] + (2.0 * b_deltaX)) <= 1.7976931348623157E+308)))) {
          formulaType = 1;
          delta1 = b_deltaX;
          delta2 = 2.0 * b_deltaX;
        } else {
          exitg2 = 1;
        }
      } else {
        bool c_evalOK;
        c_evalOK =
            b_finDiffEvalAndChkErr(&obj->objfun, obj->SpecifyObjectiveGradient,
                                   &obj->f_2, idx + 1, delta2, b_xk);
        evalOK = c_evalOK;
        obj->numEvals++;
        if (((!c_evalOK) && (formulaType == 0)) &&
            ((!obj->hasBounds) ||
             ((obj->hasLB[idx]) &&
              ((b_xk[idx] - (2.0 * b_deltaX)) >= -1.7976931348623157E+308)))) {
          formulaType = -1;
          delta1 = -2.0 * b_deltaX;
          delta2 = -b_deltaX;
        } else {
          exitg2 = 1;
        }
      }
    } while (exitg2 == 0);
    if (!evalOK) {
      exitg1 = true;
    } else {
      if (!obj->SpecifyObjectiveGradient) {
        double val_left;
        double val_right;
        val_left = obj->b_f_1;
        val_right = obj->f_2;
        switch (formulaType) {
        case 0:
          gradf[idx] = ((-val_left) + val_right) / (2.0 * b_deltaX);
          break;
        case 1:
          gradf[idx] = (((-3.0 * fCurrent) + (4.0 * val_left)) - val_right) /
                       (2.0 * b_deltaX);
          break;
        default:
          gradf[idx] = ((val_left - (4.0 * val_right)) + (3.0 * fCurrent)) /
                       (2.0 * b_deltaX);
          break;
        }
      }
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
// File trailer for computeCentralDifferences.cpp
//
// [EOF]
//
