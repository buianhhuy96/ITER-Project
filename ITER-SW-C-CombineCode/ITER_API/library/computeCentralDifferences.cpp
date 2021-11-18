//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeCentralDifferences.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

// Include Files
#include "computeCentralDifferences.h"
#include "ITER_API_internal_types.h"
#include "anonymous_function.h"
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
namespace internal {
bool computeCentralDifferences(
    f_struct_T *obj, const ::coder::array<double, 1U> &cEqCurrent,
    ::coder::array<double, 1U> &xk, ::coder::array<double, 2U> &JacCeqTrans,
    int ldJE, const ::coder::array<double, 1U> &runTimeOptions_TypicalX,
    const ::coder::array<double, 1U> &runTimeOptions_FiniteDifferenceStepSize)
{
  double b_deltaX;
  double b_lb_i;
  double b_ub_i;
  double c_lb_i;
  double ub_i;
  int formulaType;
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
    double deltaX;
    bool guard1{false};
    bool guard2{false};
    deltaX =
        runTimeOptions_FiniteDifferenceStepSize[idx] *
        std::fmax(std::abs(xk[idx]), std::abs(runTimeOptions_TypicalX[idx]));
    guard1 = false;
    guard2 = false;
    if (obj->hasLB[idx]) {
      guard2 = true;
    } else if (obj->hasUB[idx]) {
      guard2 = true;
    } else {
      formulaType = 0;
    }
    if (guard2) {
      if (obj->hasLB[idx]) {
        if (obj->hasUB[idx]) {
          // A check that is always false is detected at compile-time.
          // Eliminating code that follows.
          if (b_lb_i != ub_i) {
            if (xk[idx] >= b_lb_i) {
              if (xk[idx] <= ub_i) {
                if ((xk[idx] - deltaX) < b_lb_i) {
                  if (ub_i < (xk[idx] + deltaX)) {
                    double distNear_tmp;
                    distNear_tmp = xk[idx] - b_lb_i;
                    if (distNear_tmp >= (distNear_tmp / 2.0)) {
                      b_deltaX = distNear_tmp;
                    } else {
                      b_deltaX = distNear_tmp / 2.0;
                      if ((xk[idx] - b_lb_i) >= (ub_i - xk[idx])) {
                        formulaType = -1;
                      } else {
                        formulaType = 1;
                      }
                    }
                  } else if ((xk[idx] + (2.0 * deltaX)) <= ub_i) {
                    formulaType = 1;
                  } else {
                    double b_d1;
                    double d3;
                    b_d1 = (ub_i - xk[idx]) / 2.0;
                    d3 = xk[idx] - b_lb_i;
                    if (d3 >= b_d1) {
                      b_deltaX = d3;
                    } else {
                      b_deltaX = b_d1;
                      formulaType = 1;
                    }
                  }
                } else if (ub_i < (xk[idx] + deltaX)) {
                  if (b_lb_i <= (xk[idx] - (2.0 * deltaX))) {
                    formulaType = -1;
                  } else {
                    double d;
                    double d2;
                    d = (xk[idx] - b_lb_i) / 2.0;
                    d2 = ub_i - xk[idx];
                    if (d2 >= d) {
                      b_deltaX = d2;
                    } else {
                      b_deltaX = d;
                      formulaType = -1;
                    }
                  }
                } else {
                  /* no actions */
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
        // A check that is always false is detected at compile-time. Eliminating
        // code that follows.
        if (xk[idx] <= b_ub_i) {
          if (b_ub_i < (xk[idx] + deltaX)) {
            formulaType = -1;
          }
        }

        // A check that is always false is detected at compile-time. Eliminating
        // code that follows.
      } else if (xk[idx] >= c_lb_i) {
        if ((xk[idx] - deltaX) < c_lb_i) {
          formulaType = 1;
        }
      } else {
        /* no actions */
      }
    }
    delta1 = -deltaX;
    delta2 = deltaX;
    int exitg2;
    bool b_evalOK;
    do {
      exitg2 = 0;
      b_evalOK = finDiffEvalAndChkErr(&obj->nonlin, obj->mEq,
                                      obj->SpecifyConstraintGradient,
                                      obj->cEq_1, idx + 1, delta1, xk);
      evalOK = b_evalOK;
      obj->numEvals++;
      if (!b_evalOK) {
        if ((formulaType == 0) && (!obj->hasBounds)) {
          formulaType = 1;
          delta1 = deltaX;
          delta2 = 2.0 * deltaX;
        } else {
          exitg2 = 1;
        }
      } else {
        bool c_evalOK;
        c_evalOK = finDiffEvalAndChkErr(&obj->nonlin, obj->mEq,
                                        obj->SpecifyConstraintGradient,
                                        obj->cEq_2, idx + 1, delta2, xk);
        evalOK = c_evalOK;
        obj->numEvals++;
        if (((!c_evalOK) && (formulaType == 0)) && (!obj->hasBounds)) {
          formulaType = -1;
          delta1 = -2.0 * deltaX;
          delta2 = -deltaX;
        } else {
          exitg2 = 1;
        }
      }
    } while (exitg2 == 0);
    if (!evalOK) {
      exitg1 = true;
    } else {
      if ((!obj->SpecifyConstraintGradient) && (obj->mEq > 0)) {
        int ncols;
        ncols = obj->mEq - 1;
        switch (formulaType) {
        case 0:
          for (int b_idx_col{0}; b_idx_col <= ncols; b_idx_col++) {
            JacCeqTrans[idx + (ldJE * b_idx_col)] =
                ((-obj->cEq_1[b_idx_col]) + obj->cEq_2[b_idx_col]) /
                (2.0 * deltaX);
          }
          break;
        case 1:
          for (int c_idx_col{0}; c_idx_col <= ncols; c_idx_col++) {
            JacCeqTrans[idx + (ldJE * c_idx_col)] =
                (((-3.0 * cEqCurrent[c_idx_col]) +
                  (4.0 * obj->cEq_1[c_idx_col])) -
                 obj->cEq_2[c_idx_col]) /
                (2.0 * deltaX);
          }
          break;
        default:
          for (int idx_col{0}; idx_col <= ncols; idx_col++) {
            JacCeqTrans[idx + (ldJE * idx_col)] =
                ((obj->cEq_1[idx_col] - (4.0 * obj->cEq_2[idx_col])) +
                 (3.0 * cEqCurrent[idx_col])) /
                (2.0 * deltaX);
          }
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

//
// File trailer for computeCentralDifferences.cpp
//
// [EOF]
//
