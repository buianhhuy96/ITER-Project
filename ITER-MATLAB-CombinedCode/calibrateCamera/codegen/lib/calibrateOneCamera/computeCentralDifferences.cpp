//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeCentralDifferences.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "computeCentralDifferences.h"
#include "anonymous_function.h"
#include "calibrateOneCamera_internal_types.h"
#include "finDiffEvalAndChkErr.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : g_struct_T *obj
//                const ::coder::array<double, 1U> &cEqCurrent
//                ::coder::array<double, 1U> &xk
//                ::coder::array<double, 2U> &JacCeqTrans
//                int ldJE
//                const ::coder::array<double, 1U> &runTimeOptions_TypicalX
//                const ::coder::array<double, 1U>
//                &runTimeOptions_FiniteDifferenceStepSize
// Return Type  : bool
//
namespace Codegen {
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
namespace internal {
bool computeCentralDifferences(
    g_struct_T *obj, const ::coder::array<double, 1U> &cEqCurrent,
    ::coder::array<double, 1U> &xk, ::coder::array<double, 2U> &JacCeqTrans,
    int ldJE, const ::coder::array<double, 1U> &runTimeOptions_TypicalX,
    const ::coder::array<double, 1U> &runTimeOptions_FiniteDifferenceStepSize)
{
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
    deltaX =
        runTimeOptions_FiniteDifferenceStepSize[idx] *
        std::fmax(std::abs(xk[idx]), std::abs(runTimeOptions_TypicalX[idx]));
    if (!obj->hasLB[idx]) {
      if (!obj->hasUB[idx]) {
        formulaType = 0;
      }
    }
    delta1 = -deltaX;
    delta2 = deltaX;
    int exitg2;
    do {
      exitg2 = 0;
      evalOK = finDiffEvalAndChkErr(&obj->nonlin, obj->mEq,
                                    obj->SpecifyConstraintGradient, obj->cEq_1,
                                    idx + 1, delta1, xk);
      obj->numEvals++;
      if (!evalOK) {
        if ((formulaType == 0) && (!obj->hasBounds)) {
          formulaType = 1;
          delta1 = deltaX;
          delta2 = 2.0 * deltaX;
        } else {
          exitg2 = 1;
        }
      } else {
        evalOK = finDiffEvalAndChkErr(&obj->nonlin, obj->mEq,
                                      obj->SpecifyConstraintGradient,
                                      obj->cEq_2, idx + 1, delta2, xk);
        obj->numEvals++;
        if (((!evalOK) && (formulaType == 0)) && (!obj->hasBounds)) {
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
          for (int idx_col{0}; idx_col <= ncols; idx_col++) {
            JacCeqTrans[idx + (ldJE * idx_col)] =
                ((-obj->cEq_1[idx_col]) + obj->cEq_2[idx_col]) / (2.0 * deltaX);
          }
          break;
        case 1:
          for (int idx_col{0}; idx_col <= ncols; idx_col++) {
            JacCeqTrans[idx + (ldJE * idx_col)] =
                (((-3.0 * cEqCurrent[idx_col]) + (4.0 * obj->cEq_1[idx_col])) -
                 obj->cEq_2[idx_col]) /
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
} // namespace Codegen

//
// File trailer for computeCentralDifferences.cpp
//
// [EOF]
//
