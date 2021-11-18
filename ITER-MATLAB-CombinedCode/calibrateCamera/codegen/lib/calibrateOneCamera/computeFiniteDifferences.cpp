//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeFiniteDifferences.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "computeFiniteDifferences.h"
#include "anonymous_function.h"
#include "calibrateOneCamera_internal_types.h"
#include "computeCentralDifferences.h"
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
bool computeFiniteDifferences(
    g_struct_T *obj, const ::coder::array<double, 1U> &cEqCurrent,
    ::coder::array<double, 1U> &xk, ::coder::array<double, 2U> &JacCeqTrans,
    int ldJE, const ::coder::array<double, 1U> &runTimeOptions_TypicalX,
    const ::coder::array<double, 1U> &runTimeOptions_FiniteDifferenceStepSize)
{
  bool evalOK;
  if (obj->isEmptyNonlcon) {
    evalOK = true;
  } else if (obj->FiniteDifferenceType == 0) {
    int idx;
    bool exitg1;
    evalOK = true;
    obj->numEvals = 0;
    idx = 0;
    exitg1 = false;
    while ((!exitg1) && (idx <= (obj->nVar - 1))) {
      double deltaX;
      bool guard1{false};
      deltaX =
          (runTimeOptions_FiniteDifferenceStepSize[idx] *
           (1.0 - (2.0 * (static_cast<double>(xk[idx] < 0.0))))) *
          std::fmax(std::abs(xk[idx]), std::abs(runTimeOptions_TypicalX[idx]));
      evalOK = internal::finDiffEvalAndChkErr(&obj->nonlin, obj->mEq,
                                              obj->SpecifyConstraintGradient,
                                              obj->cEq_1, idx + 1, deltaX, xk);
      obj->numEvals++;
      guard1 = false;
      if (!evalOK) {
        deltaX = -deltaX;
        if (!obj->hasBounds) {
          evalOK = internal::finDiffEvalAndChkErr(
              &obj->nonlin, obj->mEq, obj->SpecifyConstraintGradient,
              obj->cEq_1, idx + 1, deltaX, xk);
          obj->numEvals++;
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
        int b_i;
        b_i = obj->mEq;
        for (int idx_row{0}; idx_row < b_i; idx_row++) {
          JacCeqTrans[idx + (ldJE * idx_row)] =
              (obj->cEq_1[idx_row] - cEqCurrent[idx_row]) / deltaX;
        }
        idx++;
      }
    }
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
} // namespace Codegen

//
// File trailer for computeFiniteDifferences.cpp
//
// [EOF]
//
