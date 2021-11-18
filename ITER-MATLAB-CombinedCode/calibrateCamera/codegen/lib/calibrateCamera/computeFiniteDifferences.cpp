//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeFiniteDifferences.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "computeFiniteDifferences.h"
#include "anonymous_function.h"
#include "calibrateCamera_internal_types.h"
#include "finDiffEvalAndChkErr.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : c_struct_T *obj
//                const ::coder::array<real_T, 1U> &cEqCurrent
//                ::coder::array<real_T, 1U> &xk
//                ::coder::array<real_T, 2U> &JacCeqTrans
//                int32_T ldJE
// Return Type  : boolean_T
//
namespace Codegen {
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
boolean_T computeFiniteDifferences(c_struct_T *obj,
                                   const ::coder::array<real_T, 1U> &cEqCurrent,
                                   ::coder::array<real_T, 1U> &xk,
                                   ::coder::array<real_T, 2U> &JacCeqTrans,
                                   int32_T ldJE)
{
  real_T d;
  boolean_T evalOK;
  if (obj->isEmptyNonlcon) {
    evalOK = true;
  } else if (obj->FiniteDifferenceType == 0) {
    int32_T idx;
    boolean_T exitg2;
    evalOK = true;
    obj->numEvals = 0;
    idx = 0;
    exitg2 = false;
    while ((!exitg2) && (idx <= (obj->nVar - 1))) {
      real_T deltaX;
      boolean_T guard1{false};
      deltaX = (1.4901161193847656E-8 *
                (1.0 - (2.0 * (static_cast<real_T>(xk[idx] < 0.0))))) *
               std::fmax(std::abs(xk[idx]), 1.0);
      internal::finDiffEvalAndChkErr(&obj->nonlin, obj->mEq, obj->cEq_1,
                                     idx + 1, deltaX, xk, &evalOK, &d);
      obj->b_f_1 = 0.0;
      obj->numEvals++;
      guard1 = false;
      if (!evalOK) {
        deltaX = -deltaX;
        internal::finDiffEvalAndChkErr(&obj->nonlin, obj->mEq, obj->cEq_1,
                                       idx + 1, deltaX, xk, &evalOK, &d);
        obj->b_f_1 = 0.0;
        obj->numEvals++;
        if (!evalOK) {
          exitg2 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        int32_T formulaType;
        formulaType = obj->mEq;
        for (int32_T ncols{0}; ncols < formulaType; ncols++) {
          JacCeqTrans[idx + (ldJE * ncols)] =
              (obj->cEq_1[ncols] - cEqCurrent[ncols]) / deltaX;
        }
        idx++;
      }
    }
  } else {
    int32_T idx;
    boolean_T exitg1;
    evalOK = true;
    obj->numEvals = 0;
    idx = 0;
    exitg1 = false;
    while ((!exitg1) && (idx <= (obj->nVar - 1))) {
      real_T delta1;
      real_T delta2;
      real_T deltaX;
      int32_T formulaType;
      deltaX = 1.4901161193847656E-8 * std::fmax(std::abs(xk[idx]), 1.0);
      formulaType = 0;
      delta1 = -deltaX;
      delta2 = deltaX;
      int32_T exitg3;
      do {
        exitg3 = 0;
        internal::finDiffEvalAndChkErr(&obj->nonlin, obj->mEq, obj->cEq_1,
                                       idx + 1, delta1, xk, &evalOK, &d);
        obj->b_f_1 = 0.0;
        obj->numEvals++;
        if (!evalOK) {
          if (formulaType == 0) {
            formulaType = 1;
            delta1 = deltaX;
            delta2 = 2.0 * deltaX;
          } else {
            exitg3 = 1;
          }
        } else {
          internal::finDiffEvalAndChkErr(&obj->nonlin, obj->mEq, obj->cEq_2,
                                         idx + 1, delta2, xk, &evalOK, &d);
          obj->f_2 = 0.0;
          obj->numEvals++;
          if ((!evalOK) && (formulaType == 0)) {
            formulaType = -1;
            delta1 = -2.0 * deltaX;
            delta2 = -deltaX;
          } else {
            exitg3 = 1;
          }
        }
      } while (exitg3 == 0);
      if (!evalOK) {
        exitg1 = true;
      } else {
        if (obj->mEq > 0) {
          int32_T ncols;
          ncols = obj->mEq - 1;
          switch (formulaType) {
          case 0:
            for (formulaType = 0; formulaType <= ncols; formulaType++) {
              JacCeqTrans[idx + (ldJE * formulaType)] =
                  ((-obj->cEq_1[formulaType]) + obj->cEq_2[formulaType]) /
                  (2.0 * deltaX);
            }
            break;
          case 1:
            for (formulaType = 0; formulaType <= ncols; formulaType++) {
              JacCeqTrans[idx + (ldJE * formulaType)] =
                  (((-3.0 * cEqCurrent[formulaType]) +
                    (4.0 * obj->cEq_1[formulaType])) -
                   obj->cEq_2[formulaType]) /
                  (2.0 * deltaX);
            }
            break;
          default:
            for (formulaType = 0; formulaType <= ncols; formulaType++) {
              JacCeqTrans[idx + (ldJE * formulaType)] =
                  ((obj->cEq_1[formulaType] - (4.0 * obj->cEq_2[formulaType])) +
                   (3.0 * cEqCurrent[formulaType])) /
                  (2.0 * deltaX);
            }
            break;
          }
        }
        idx++;
      }
    }
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
