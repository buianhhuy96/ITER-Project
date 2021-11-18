//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeFiniteDifferences.cpp
//
// Code generation for function 'computeFiniteDifferences'
//

// Include files
#include "computeFiniteDifferences.h"
#include "anonymous_function.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "calibrateOneCamera_v2_mex_internal_types.h"
#include "computeCentralDifferences.h"
#include "eml_int_forloop_overflow_check.h"
#include "finDiffEvalAndChkErr.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo xeb_emlrtRSI{
    1,                          // lineNo
    "computeFiniteDifferences", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\computeFiniteDifferences.p" // pathName
};

static emlrtRSInfo yeb_emlrtRSI{
    1,                           // lineNo
    "computeForwardDifferences", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\+internal\\computeForwardDifferences.p" // pathName
};

static emlrtBCInfo bab_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    1,                 // lineNo
    1,                 // colNo
    "",                // aName
    "ForwardStepSize", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\+internal\\ForwardStepSize.p", // pName
    0                                                  // checkKind
};

static emlrtBCInfo cab_emlrtBCI{
    -1,                          // iFirst
    -1,                          // iLast
    1,                           // lineNo
    1,                           // colNo
    "",                          // aName
    "computeForwardDifferences", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\+internal\\computeForwardDifferences.p", // pName
    0                                                            // checkKind
};

static emlrtBCInfo dab_emlrtBCI{
    1,                           // iFirst
    0,                           // iLast
    1,                           // lineNo
    1,                           // colNo
    "",                          // aName
    "computeForwardDifferences", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\+internal\\computeForwardDifferences.p", // pName
    0                                                            // checkKind
};

static emlrtBCInfo eab_emlrtBCI{
    1,                           // iFirst
    0,                           // iLast
    1,                           // lineNo
    1,                           // colNo
    "",                          // aName
    "computeForwardDifferences", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\+internal\\computeForwardDifferences.p", // pName
    3                                                            // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
boolean_T computeFiniteDifferences(
    const emlrtStack *sp, d_struct_T *obj,
    const ::coder::array<real_T, 1U> &cEqCurrent,
    ::coder::array<real_T, 1U> &xk, ::coder::array<real_T, 2U> &JacCeqTrans,
    int32_T ldJE, const ::coder::array<real_T, 1U> &runTimeOptions_TypicalX,
    const ::coder::array<real_T, 1U> &c_runTimeOptions_FiniteDifferen)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  boolean_T evalOK;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (obj->isEmptyNonlcon) {
    evalOK = true;
  } else if (obj->FiniteDifferenceType == 0) {
    int32_T idx;
    boolean_T exitg1;
    st.site = &xeb_emlrtRSI;
    evalOK = true;
    obj->numEvals = 0;
    b_st.site = &yeb_emlrtRSI;
    if ((1 <= obj->nVar) && (obj->nVar > 2147483646)) {
      c_st.site = &yc_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    idx = 0;
    exitg1 = false;
    while ((!exitg1) && (idx <= obj->nVar - 1)) {
      real_T deltaX;
      int32_T i;
      boolean_T b_guard1{false};
      boolean_T guard1{false};
      boolean_T guard2{false};
      b_st.site = &yeb_emlrtRSI;
      c_st.site = &web_emlrtRSI;
      i = xk.size(0);
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &bab_emlrtBCI, &c_st);
      }
      i = xk.size(0);
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &bab_emlrtBCI, &c_st);
      }
      if ((idx + 1 < 1) || (idx + 1 > runTimeOptions_TypicalX.size(0))) {
        emlrtDynamicBoundsCheckR2012b(
            idx + 1, 1, runTimeOptions_TypicalX.size(0), &bab_emlrtBCI, &c_st);
      }
      if ((idx + 1 < 1) ||
          (idx + 1 > c_runTimeOptions_FiniteDifferen.size(0))) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1,
                                      c_runTimeOptions_FiniteDifferen.size(0),
                                      &bab_emlrtBCI, &c_st);
      }
      deltaX =
          c_runTimeOptions_FiniteDifferen[idx] *
          (1.0 - 2.0 * static_cast<real_T>(xk[idx] < 0.0)) *
          muDoubleScalarMax(muDoubleScalarAbs(xk[idx]),
                            muDoubleScalarAbs(runTimeOptions_TypicalX[idx]));
      i = obj->hasLB.size(0);
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &cab_emlrtBCI, &st);
      }
      guard1 = false;
      guard2 = false;
      if (obj->hasLB[idx]) {
        guard2 = true;
      } else {
        i = obj->hasUB.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &cab_emlrtBCI, &st);
        }
        if (obj->hasUB[idx]) {
          guard2 = true;
        }
      }
      if (guard2) {
        i = obj->hasLB.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &cab_emlrtBCI, &st);
        }
        if (obj->hasLB[idx]) {
          i = obj->hasUB.size(0);
          if ((idx + 1 < 1) || (idx + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &cab_emlrtBCI, &st);
          }
          if (obj->hasUB[idx]) {
            i = xk.size(0);
            if ((idx + 1 < 1) || (idx + 1 > i)) {
              emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &cab_emlrtBCI, &st);
            }
            if ((idx + 1 < 1) || (idx + 1 > 0)) {
              emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 0, &dab_emlrtBCI, &st);
            }
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }
      }
      if (guard1) {
        i = obj->hasUB.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &cab_emlrtBCI, &st);
        }
        if (obj->hasUB[idx]) {
          i = xk.size(0);
          if ((idx + 1 < 1) || (idx + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &cab_emlrtBCI, &st);
          }
          if ((idx + 1 < 1) || (idx + 1 > 0)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 0, &dab_emlrtBCI, &st);
          }
        } else {
          i = xk.size(0);
          if ((idx + 1 < 1) || (idx + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &cab_emlrtBCI, &st);
          }
          if ((idx + 1 < 1) || (idx + 1 > 0)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 0, &dab_emlrtBCI, &st);
          }
        }
      }
      b_st.site = &yeb_emlrtRSI;
      evalOK = internal::finDiffEvalAndChkErr(
          &b_st, &obj->nonlin, obj->mIneq, obj->mEq,
          obj->SpecifyConstraintGradient, obj->cEq_1, idx + 1, deltaX, xk);
      obj->numEvals++;
      b_guard1 = false;
      if (!evalOK) {
        deltaX = -deltaX;
        i = obj->hasLB.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &cab_emlrtBCI, &st);
        }
        if (obj->hasLB[idx]) {
          i = xk.size(0);
          if ((idx + 1 < 1) || (idx + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &cab_emlrtBCI, &st);
          }
          if ((idx + 1 < 1) || (idx + 1 > 0)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 0, &dab_emlrtBCI, &st);
          }
        }
        if (!obj->hasBounds) {
          b_st.site = &yeb_emlrtRSI;
          evalOK = internal::finDiffEvalAndChkErr(
              &b_st, &obj->nonlin, obj->mIneq, obj->mEq,
              obj->SpecifyConstraintGradient, obj->cEq_1, idx + 1, deltaX, xk);
          obj->numEvals++;
        }
        if (!evalOK) {
          exitg1 = true;
        } else {
          b_guard1 = true;
        }
      } else {
        b_guard1 = true;
      }
      if (b_guard1) {
        int32_T b;
        int32_T idx_row;
        b = obj->mIneq;
        b_st.site = &yeb_emlrtRSI;
        if ((1 <= obj->mIneq) && (obj->mIneq > 2147483646)) {
          c_st.site = &yc_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        for (idx_row = 0; idx_row < b; idx_row++) {
          if ((idx_row + 1 < 1) || (idx_row + 1 > 0)) {
            emlrtDynamicBoundsCheckR2012b(idx_row + 1, 1, 0, &dab_emlrtBCI,
                                          &st);
          }
          if ((idx + 1 < 1) || (idx + 1 > 0)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 0, &eab_emlrtBCI, &st);
          }
        }
        b = obj->mEq;
        b_st.site = &yeb_emlrtRSI;
        if ((1 <= obj->mEq) && (obj->mEq > 2147483646)) {
          c_st.site = &yc_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        for (idx_row = 0; idx_row < b; idx_row++) {
          int32_T i1;
          i = obj->cEq_1.size(0);
          if ((idx_row + 1 < 1) || (idx_row + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(idx_row + 1, 1, i, &cab_emlrtBCI,
                                          &st);
          }
          if ((idx_row + 1 < 1) || (idx_row + 1 > cEqCurrent.size(0))) {
            emlrtDynamicBoundsCheckR2012b(idx_row + 1, 1, cEqCurrent.size(0),
                                          &cab_emlrtBCI, &st);
          }
          i = JacCeqTrans.size(0) * JacCeqTrans.size(1);
          i1 = (idx + ldJE * idx_row) + 1;
          if ((i1 < 1) || (i1 > i)) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, i, &cab_emlrtBCI, &st);
          }
          JacCeqTrans[i1 - 1] =
              (obj->cEq_1[idx_row] - cEqCurrent[idx_row]) / deltaX;
        }
        idx++;
      }
    }
  } else {
    st.site = &xeb_emlrtRSI;
    evalOK = internal::computeCentralDifferences(
        &st, obj, cEqCurrent, xk, JacCeqTrans, ldJE, runTimeOptions_TypicalX,
        c_runTimeOptions_FiniteDifferen);
  }
  return evalOK;
}

} // namespace FiniteDifferences
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeFiniteDifferences.cpp)
