//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeFiniteDifferences.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "computeFiniteDifferences.h"
#include "ITER_API_internal_types.h"
#include "anonymous_function.h"
#include "cntrlFinDiffInsideBnds.h"
#include "finDiffEvalAndChkErr.h"
#include "fwdFinDiffInsideBnds.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : ab_struct_T *obj
//                const ::coder::array<double, 1U> &cEqCurrent
//                ::coder::array<double, 1U> &b_xk
//                ::coder::array<double, 2U> &JacCeqTrans
//                int ldJE
//                const ::coder::array<double, 1U> &lb
//                const ::coder::array<double, 1U> &ub
//                const ::coder::array<double, 1U> &runTimeOptions_TypicalX
//                const ::coder::array<double, 1U>
//                &runTimeOptions_FiniteDifferenceStepSize
// Return Type  : bool
//
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
bool b_computeFiniteDifferences(
    ab_struct_T *obj, const ::coder::array<double, 1U> &cEqCurrent,
    ::coder::array<double, 1U> &b_xk, ::coder::array<double, 2U> &JacCeqTrans,
    int ldJE, const ::coder::array<double, 1U> &lb,
    const ::coder::array<double, 1U> &ub,
    const ::coder::array<double, 1U> &runTimeOptions_TypicalX,
    const ::coder::array<double, 1U> &runTimeOptions_FiniteDifferenceStepSize)
{
  double b_deltaX;
  double c_deltaX;
  int formulaType;
  bool evalOK;
  if (obj->isEmptyNonlcon) {
    evalOK = true;
  } else if (obj->FiniteDifferenceType == 0) {
    int b_idx;
    bool c_evalOK;
    bool exitg1;
    c_evalOK = true;
    obj->numEvals = 0;
    b_idx = 0;
    exitg1 = false;
    while ((!exitg1) && (b_idx <= (obj->nVar - 1))) {
      bool b_guard1;
      bool d_evalOK;
      bool guard1;
      bool guard2;
      bool modifiedStep;
      modifiedStep = false;
      c_deltaX = (runTimeOptions_FiniteDifferenceStepSize[b_idx] *
                  (1.0 - (2.0 * (static_cast<double>(b_xk[b_idx] < 0.0))))) *
                 std::fmax(std::abs(b_xk[b_idx]),
                           std::abs(runTimeOptions_TypicalX[b_idx]));
      guard1 = false;
      guard2 = false;
      if (obj->hasLB[b_idx]) {
        guard2 = true;
      } else if (obj->hasUB[b_idx]) {
        guard2 = true;
      } else {
        /* no actions */
      }
      if (guard2) {
        if (obj->hasLB[b_idx]) {
          if (obj->hasUB[b_idx]) {
            modifiedStep = internal::fwdFinDiffInsideBnds(
                b_xk[b_idx], lb[b_idx], ub[b_idx], &c_deltaX);
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }
      }
      if (guard1) {
        if (obj->hasUB[b_idx]) {
          double e_deltaX;
          e_deltaX = c_deltaX;
          if (b_xk[b_idx] <= ub[b_idx]) {
            if ((b_xk[b_idx] + c_deltaX) > ub[b_idx]) {
              e_deltaX = -c_deltaX;
              modifiedStep = true;
            }
          }
          c_deltaX = e_deltaX;
        } else {
          double d_deltaX;
          d_deltaX = c_deltaX;
          if (b_xk[b_idx] >= lb[b_idx]) {
            if ((b_xk[b_idx] + c_deltaX) < lb[b_idx]) {
              d_deltaX = -c_deltaX;
              modifiedStep = true;
            }
          }
          c_deltaX = d_deltaX;
        }
      }
      d_evalOK = internal::c_finDiffEvalAndChkErr(
          &obj->nonlin, obj->mEq, obj->SpecifyConstraintGradient, obj->cEq_1,
          b_idx + 1, c_deltaX, b_xk);
      c_evalOK = d_evalOK;
      obj->numEvals++;
      b_guard1 = false;
      if (!d_evalOK) {
        if (!modifiedStep) {
          bool insideBnds;
          c_deltaX = -c_deltaX;
          if (obj->hasLB[b_idx]) {
            double d;
            d = b_xk[b_idx] + c_deltaX;
            if (d >= lb[b_idx]) {
              if (obj->hasUB[b_idx]) {
                if (d <= ub[b_idx]) {
                  insideBnds = true;
                } else {
                  insideBnds = false;
                }
              } else {
                insideBnds = false;
              }
            } else {
              insideBnds = false;
            }
          } else {
            insideBnds = false;
          }
          if ((!obj->hasBounds) || insideBnds) {
            c_evalOK = internal::c_finDiffEvalAndChkErr(
                &obj->nonlin, obj->mEq, obj->SpecifyConstraintGradient,
                obj->cEq_1, b_idx + 1, c_deltaX, b_xk);
            obj->numEvals++;
          }
        }
        if (!c_evalOK) {
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
          JacCeqTrans[b_idx + (ldJE * idx_row)] =
              (obj->cEq_1[idx_row] - cEqCurrent[idx_row]) / c_deltaX;
        }
        b_idx++;
      }
    }
    evalOK = c_evalOK;
  } else {
    int idx;
    bool b_evalOK;
    bool exitg1;
    b_evalOK = true;
    obj->numEvals = 0;
    idx = 0;
    exitg1 = false;
    while ((!exitg1) && (idx <= (obj->nVar - 1))) {
      double delta1;
      double delta2;
      bool guard1{false};
      bool guard2{false};
      b_deltaX = runTimeOptions_FiniteDifferenceStepSize[idx] *
                 std::fmax(std::abs(b_xk[idx]),
                           std::abs(runTimeOptions_TypicalX[idx]));
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
            formulaType = internal::cntrlFinDiffInsideBnds(b_xk[idx], lb[idx],
                                                           ub[idx], &b_deltaX);
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }
      }
      if (guard1) {
        if (obj->hasUB[idx]) {
          formulaType = 0;
          if (b_xk[idx] <= ub[idx]) {
            if (ub[idx] < (b_xk[idx] + b_deltaX)) {
              formulaType = -1;
            }
          }
        } else {
          formulaType = 0;
          if (b_xk[idx] >= lb[idx]) {
            if ((b_xk[idx] - b_deltaX) < lb[idx]) {
              formulaType = 1;
            }
          }
        }
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
      bool b_guard1{false};
      bool b_guard2{false};
      bool e_evalOK;
      do {
        exitg2 = 0;
        e_evalOK = internal::c_finDiffEvalAndChkErr(
            &obj->nonlin, obj->mEq, obj->SpecifyConstraintGradient, obj->cEq_1,
            idx + 1, delta1, b_xk);
        b_evalOK = e_evalOK;
        obj->numEvals++;
        b_guard1 = false;
        b_guard2 = false;
        if (!e_evalOK) {
          if (formulaType == 0) {
            if (!obj->hasBounds) {
              b_guard1 = true;
            } else if (obj->hasUB[idx]) {
              if ((b_xk[idx] + (2.0 * b_deltaX)) <= ub[idx]) {
                b_guard1 = true;
              } else {
                exitg2 = 1;
              }
            } else {
              exitg2 = 1;
            }
          } else {
            exitg2 = 1;
          }
        } else {
          bool g_evalOK;
          g_evalOK = internal::c_finDiffEvalAndChkErr(
              &obj->nonlin, obj->mEq, obj->SpecifyConstraintGradient,
              obj->cEq_2, idx + 1, delta2, b_xk);
          b_evalOK = g_evalOK;
          obj->numEvals++;
          if ((!g_evalOK) && (formulaType == 0)) {
            if (!obj->hasBounds) {
              b_guard2 = true;
            } else if (obj->hasLB[idx]) {
              if ((b_xk[idx] - (2.0 * b_deltaX)) >= lb[idx]) {
                b_guard2 = true;
              } else {
                exitg2 = 1;
              }
            } else {
              exitg2 = 1;
            }
          } else {
            exitg2 = 1;
          }
        }
        if (b_guard2) {
          formulaType = -1;
          delta1 = -2.0 * b_deltaX;
          delta2 = -b_deltaX;
        }
        if (b_guard1) {
          formulaType = 1;
          delta1 = b_deltaX;
          delta2 = 2.0 * b_deltaX;
        }
      } while (exitg2 == 0);
      if (!b_evalOK) {
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
                  (2.0 * b_deltaX);
            }
            break;
          case 1:
            for (int c_idx_col{0}; c_idx_col <= ncols; c_idx_col++) {
              JacCeqTrans[idx + (ldJE * c_idx_col)] =
                  (((-3.0 * cEqCurrent[c_idx_col]) +
                    (4.0 * obj->cEq_1[c_idx_col])) -
                   obj->cEq_2[c_idx_col]) /
                  (2.0 * b_deltaX);
            }
            break;
          default:
            for (int idx_col{0}; idx_col <= ncols; idx_col++) {
              JacCeqTrans[idx + (ldJE * idx_col)] =
                  ((obj->cEq_1[idx_col] - (4.0 * obj->cEq_2[idx_col])) +
                   (3.0 * cEqCurrent[idx_col])) /
                  (2.0 * b_deltaX);
            }
            break;
          }
        }
        idx++;
      }
    }
    evalOK = b_evalOK;
  }
  return evalOK;
}

//
// Arguments    : w_struct_T *obj
//                const ::coder::array<double, 2U> &cEqCurrent
//                double b_xk[6]
//                ::coder::array<double, 2U> &JacCeqTrans
// Return Type  : bool
//
bool computeFiniteDifferences(w_struct_T *obj,
                              const ::coder::array<double, 2U> &cEqCurrent,
                              double b_xk[6],
                              ::coder::array<double, 2U> &JacCeqTrans)
{
  w_struct_T b_obj;
  double b_deltaX;
  double c_deltaX;
  bool evalOK;
  if (obj->isEmptyNonlcon) {
    evalOK = true;
  } else if (obj->FiniteDifferenceType == 0) {
    int b_idx;
    bool c_evalOK;
    bool exitg1;
    b_obj = *obj;
    c_evalOK = true;
    b_obj.numEvals = 0;
    b_idx = 0;
    exitg1 = false;
    while ((!exitg1) && (b_idx <= (b_obj.nVar - 1))) {
      bool d_evalOK;
      bool guard1{false};
      bool modifiedStep;
      modifiedStep = false;
      c_deltaX = (1.4901161193847656E-8 *
                  (1.0 - (2.0 * (static_cast<double>(b_xk[b_idx] < 0.0))))) *
                 std::fmax(std::abs(b_xk[b_idx]), 1.0);
      if ((b_obj.hasLB[b_idx]) || (b_obj.hasUB[b_idx])) {
        if ((b_obj.hasLB[b_idx]) && (b_obj.hasUB[b_idx])) {
          modifiedStep = internal::fwdFinDiffInsideBnds(
              b_xk[b_idx], -1.7976931348623157E+308, 1.7976931348623157E+308,
              &c_deltaX);
        } else if (b_obj.hasUB[b_idx]) {
          double e_deltaX;
          e_deltaX = c_deltaX;
          if ((b_xk[b_idx] <= 1.7976931348623157E+308) &&
              ((b_xk[b_idx] + c_deltaX) > 1.7976931348623157E+308)) {
            e_deltaX = -c_deltaX;
            modifiedStep = true;
          }
          c_deltaX = e_deltaX;
        } else {
          double d_deltaX;
          d_deltaX = c_deltaX;
          if ((b_xk[b_idx] >= -1.7976931348623157E+308) &&
              ((b_xk[b_idx] + c_deltaX) < -1.7976931348623157E+308)) {
            d_deltaX = -c_deltaX;
            modifiedStep = true;
          }
          c_deltaX = d_deltaX;
        }
      }
      d_evalOK = internal::finDiffEvalAndChkErr(
          &b_obj.nonlin, b_obj.mEq, b_obj.SpecifyConstraintGradient,
          b_obj.cEq_1, b_idx + 1, c_deltaX, b_xk);
      c_evalOK = d_evalOK;
      b_obj.numEvals++;
      guard1 = false;
      if (!d_evalOK) {
        if (!modifiedStep) {
          bool insideBnds;
          c_deltaX = -c_deltaX;
          if (b_obj.hasLB[b_idx]) {
            double d;
            d = b_xk[b_idx] + c_deltaX;
            if (((d >= -1.7976931348623157E+308) && (b_obj.hasUB[b_idx])) &&
                (d <= 1.7976931348623157E+308)) {
              insideBnds = true;
            } else {
              insideBnds = false;
            }
          } else {
            insideBnds = false;
          }
          if ((!b_obj.hasBounds) || insideBnds) {
            c_evalOK = internal::finDiffEvalAndChkErr(
                &b_obj.nonlin, b_obj.mEq, b_obj.SpecifyConstraintGradient,
                b_obj.cEq_1, b_idx + 1, c_deltaX, b_xk);
            b_obj.numEvals++;
          }
        }
        if (!c_evalOK) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        int b_i;
        b_i = b_obj.mEq;
        for (int idx_row{0}; idx_row < b_i; idx_row++) {
          JacCeqTrans[b_idx + (6 * idx_row)] =
              (b_obj.cEq_1[idx_row] - cEqCurrent[idx_row]) / c_deltaX;
        }
        b_idx++;
      }
    }
    evalOK = c_evalOK;
    *obj = b_obj;
  } else {
    int idx;
    bool b_evalOK;
    bool exitg1;
    b_obj = *obj;
    b_evalOK = true;
    b_obj.numEvals = 0;
    idx = 0;
    exitg1 = false;
    while ((!exitg1) && (idx <= (b_obj.nVar - 1))) {
      double delta1;
      double delta2;
      int formulaType;
      b_deltaX = 1.4901161193847656E-8 * std::fmax(std::abs(b_xk[idx]), 1.0);
      if ((b_obj.hasLB[idx]) || (b_obj.hasUB[idx])) {
        if ((b_obj.hasLB[idx]) && (b_obj.hasUB[idx])) {
          formulaType = internal::cntrlFinDiffInsideBnds(
              b_xk[idx], -1.7976931348623157E+308, 1.7976931348623157E+308,
              &b_deltaX);
        } else if (b_obj.hasUB[idx]) {
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
      bool e_evalOK;
      do {
        exitg2 = 0;
        e_evalOK = internal::finDiffEvalAndChkErr(
            &b_obj.nonlin, b_obj.mEq, b_obj.SpecifyConstraintGradient,
            b_obj.cEq_1, idx + 1, delta1, b_xk);
        b_evalOK = e_evalOK;
        b_obj.numEvals++;
        if (!e_evalOK) {
          if ((formulaType == 0) &&
              ((!b_obj.hasBounds) ||
               ((b_obj.hasUB[idx]) &&
                ((b_xk[idx] + (2.0 * b_deltaX)) <= 1.7976931348623157E+308)))) {
            formulaType = 1;
            delta1 = b_deltaX;
            delta2 = 2.0 * b_deltaX;
          } else {
            exitg2 = 1;
          }
        } else {
          bool g_evalOK;
          g_evalOK = internal::finDiffEvalAndChkErr(
              &b_obj.nonlin, b_obj.mEq, b_obj.SpecifyConstraintGradient,
              b_obj.cEq_2, idx + 1, delta2, b_xk);
          b_evalOK = g_evalOK;
          b_obj.numEvals++;
          if (((!g_evalOK) && (formulaType == 0)) &&
              ((!b_obj.hasBounds) ||
               ((b_obj.hasLB[idx]) && ((b_xk[idx] - (2.0 * b_deltaX)) >=
                                       -1.7976931348623157E+308)))) {
            formulaType = -1;
            delta1 = -2.0 * b_deltaX;
            delta2 = -b_deltaX;
          } else {
            exitg2 = 1;
          }
        }
      } while (exitg2 == 0);
      if (!b_evalOK) {
        exitg1 = true;
      } else {
        if ((!b_obj.SpecifyConstraintGradient) && (b_obj.mEq > 0)) {
          int ncols;
          ncols = b_obj.mEq - 1;
          switch (formulaType) {
          case 0:
            for (int b_idx_col{0}; b_idx_col <= ncols; b_idx_col++) {
              JacCeqTrans[idx + (6 * b_idx_col)] =
                  ((-b_obj.cEq_1[b_idx_col]) + b_obj.cEq_2[b_idx_col]) /
                  (2.0 * b_deltaX);
            }
            break;
          case 1:
            for (int c_idx_col{0}; c_idx_col <= ncols; c_idx_col++) {
              JacCeqTrans[idx + (6 * c_idx_col)] =
                  (((-3.0 * cEqCurrent[c_idx_col]) +
                    (4.0 * b_obj.cEq_1[c_idx_col])) -
                   b_obj.cEq_2[c_idx_col]) /
                  (2.0 * b_deltaX);
            }
            break;
          default:
            for (int idx_col{0}; idx_col <= ncols; idx_col++) {
              JacCeqTrans[idx + (6 * idx_col)] =
                  ((b_obj.cEq_1[idx_col] - (4.0 * b_obj.cEq_2[idx_col])) +
                   (3.0 * cEqCurrent[idx_col])) /
                  (2.0 * b_deltaX);
            }
            break;
          }
        }
        idx++;
      }
    }
    evalOK = b_evalOK;
    *obj = b_obj;
  }
  return evalOK;
}

} // namespace FiniteDifferences
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

//
// File trailer for computeFiniteDifferences.cpp
//
// [EOF]
//
