//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeFiniteDifferences.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

// Include Files
#include "computeFiniteDifferences.h"
#include "ITER_API_internal_types.h"
#include "anonymous_function.h"
#include "computeCentralDifferences.h"
#include "finDiffEvalAndChkErr.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : f_struct_T *obj
//                const ::coder::array<double, 1U> &cEqCurrent
//                ::coder::array<double, 1U> &xk
//                ::coder::array<double, 2U> &JacCeqTrans
//                int ldJE
//                const ::coder::array<double, 1U> &runTimeOptions_TypicalX
//                const ::coder::array<double, 1U>
//                &runTimeOptions_FiniteDifferenceStepSize
// Return Type  : bool
//
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
bool computeFiniteDifferences(
    f_struct_T *obj, const ::coder::array<double, 1U> &cEqCurrent,
    ::coder::array<double, 1U> &xk, ::coder::array<double, 2U> &JacCeqTrans,
    int ldJE, const ::coder::array<double, 1U> &runTimeOptions_TypicalX,
    const ::coder::array<double, 1U> &runTimeOptions_FiniteDifferenceStepSize)
{
  double b_deltaX;
  double b_lb_i;
  double b_ub_i;
  double c_deltaX;
  double c_lb_i;
  double d_deltaX;
  double ub_i;
  bool evalOK;
  if (obj->isEmptyNonlcon) {
    evalOK = true;
  } else if (obj->FiniteDifferenceType == 0) {
    int idx;
    bool b_evalOK;
    bool exitg1;
    b_evalOK = true;
    obj->numEvals = 0;
    idx = 0;
    exitg1 = false;
    while ((!exitg1) && (idx <= (obj->nVar - 1))) {
      double deltaX;
      bool b_guard1{false};
      bool c_evalOK;
      bool guard1{false};
      bool guard2{false};
      bool modifiedStep;
      modifiedStep = false;
      deltaX =
          (runTimeOptions_FiniteDifferenceStepSize[idx] *
           (1.0 - (2.0 * (static_cast<double>(xk[idx] < 0.0))))) *
          std::fmax(std::abs(xk[idx]), std::abs(runTimeOptions_TypicalX[idx]));
      guard1 = false;
      guard2 = false;
      if (obj->hasLB[idx]) {
        guard2 = true;
      } else if (obj->hasUB[idx]) {
        guard2 = true;
      } else {
        /* no actions */
      }
      if (guard2) {
        if (obj->hasLB[idx]) {
          if (obj->hasUB[idx]) {
            // A check that is always false is detected at compile-time.
            // Eliminating code that follows.
            if (b_lb_i != ub_i) {
              if (xk[idx] >= b_lb_i) {
                if (xk[idx] <= ub_i) {
                  bool guard3{false};
                  guard3 = false;
                  if ((xk[idx] + deltaX) > ub_i) {
                    guard3 = true;
                  } else if ((xk[idx] + deltaX) < b_lb_i) {
                    guard3 = true;
                  } else {
                    /* no actions */
                  }
                  if (guard3) {
                    double d;
                    b_deltaX = -deltaX;
                    modifiedStep = true;
                    d = xk[idx] + (-deltaX);
                    if ((d > ub_i) || (d < b_lb_i)) {
                      double lbDiff;
                      double ubDiff;
                      lbDiff = xk[idx] - b_lb_i;
                      ubDiff = ub_i - xk[idx];
                      if (lbDiff <= ubDiff) {
                        b_deltaX = -lbDiff;
                      } else {
                        b_deltaX = ubDiff;
                      }
                    }
                  }
                }
              }
            }
            deltaX = b_deltaX;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }
      }
      if (guard1) {
        if (obj->hasUB[idx]) {
          // A check that is always false is detected at compile-time.
          // Eliminating code that follows.
          if (xk[idx] <= b_ub_i) {
            if ((xk[idx] + deltaX) > b_ub_i) {
              d_deltaX = -deltaX;
              modifiedStep = true;
            }
          }
          deltaX = d_deltaX;
        } else {
          // A check that is always false is detected at compile-time.
          // Eliminating code that follows.
          if (xk[idx] >= c_lb_i) {
            if ((xk[idx] + deltaX) < c_lb_i) {
              c_deltaX = -deltaX;
              modifiedStep = true;
            }
          }
          deltaX = c_deltaX;
        }
      }
      c_evalOK = internal::finDiffEvalAndChkErr(
          &obj->nonlin, obj->mEq, obj->SpecifyConstraintGradient, obj->cEq_1,
          idx + 1, deltaX, xk);
      b_evalOK = c_evalOK;
      obj->numEvals++;
      b_guard1 = false;
      if (!c_evalOK) {
        if (!modifiedStep) {
          deltaX = -deltaX;
          if (!obj->hasBounds) {
            b_evalOK = internal::finDiffEvalAndChkErr(
                &obj->nonlin, obj->mEq, obj->SpecifyConstraintGradient,
                obj->cEq_1, idx + 1, deltaX, xk);
            obj->numEvals++;
          }
        }
        if (!b_evalOK) {
          exitg1 = true;
        } else {
          b_guard1 = true;
        }
      } else {
        b_guard1 = true;
      }
      if (b_guard1) {
        int b_i;
        b_i = obj->mEq;
        for (int idx_row{0}; idx_row < b_i; idx_row++) {
          JacCeqTrans[idx + (ldJE * idx_row)] =
              (obj->cEq_1[idx_row] - cEqCurrent[idx_row]) / deltaX;
        }
        idx++;
      }
    }
    evalOK = b_evalOK;
  } else {
    evalOK = internal::computeCentralDifferences(
        obj, cEqCurrent, xk, JacCeqTrans, ldJE, runTimeOptions_TypicalX,
        runTimeOptions_FiniteDifferenceStepSize);
  }
  return evalOK;
}

} // namespace FiniteDifferences
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for computeFiniteDifferences.cpp
//
// [EOF]
//
