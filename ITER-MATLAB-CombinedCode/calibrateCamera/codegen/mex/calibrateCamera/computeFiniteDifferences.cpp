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
#include "calibrateCamera_data.h"
#include "calibrateCamera_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "finDiffEvalAndChkErr.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo bab_emlrtRSI{
    1,               // lineNo
    "computeDeltaX", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\computeDeltaX.p" // pathName
};

static emlrtRSInfo cab_emlrtRSI{
    1,                          // lineNo
    "computeFiniteDifferences", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\computeFiniteDifferences.p" // pathName
};

static emlrtRSInfo dab_emlrtRSI{
    1,                           // lineNo
    "computeForwardDifferences", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\+internal\\computeForwardDifferences.p" // pathName
};

static emlrtRSInfo fab_emlrtRSI{
    1,                           // lineNo
    "computeCentralDifferences", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\+internal\\computeCentralDifferences.p" // pathName
};

static emlrtRSInfo gab_emlrtRSI{
    1,                        // lineNo
    "twoStepFinDiffFormulas", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\+internal\\twoStepFinDiffFormulas.p" // pathName
};

static emlrtBCInfo ov_emlrtBCI{
    -1,                          // iFirst
    -1,                          // iLast
    1,                           // lineNo
    1,                           // colNo
    "",                          // aName
    "computeCentralDifferences", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\+internal\\computeCentralDifferences.p", // pName
    0                                                            // checkKind
};

static emlrtBCInfo pv_emlrtBCI{
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

static emlrtBCInfo qv_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    1,                 // lineNo
    1,                 // colNo
    "",                // aName
    "CentralStepSize", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\+internal\\CentralStepSize.p", // pName
    0                                                  // checkKind
};

static emlrtBCInfo rv_emlrtBCI{
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

static emlrtBCInfo sv_emlrtBCI{
    -1,                       // iFirst
    -1,                       // iLast
    1,                        // lineNo
    1,                        // colNo
    "",                       // aName
    "twoStepFinDiffFormulas", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\+internal\\twoStepFinDiffFormulas.p", // pName
    0                                                         // checkKind
};

// Function Definitions
namespace Codegen {
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
  emlrtStack d_st;
  emlrtStack st;
  real_T d;
  boolean_T evalOK;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if (obj->isEmptyNonlcon) {
    evalOK = true;
  } else if (obj->FiniteDifferenceType == 0) {
    int32_T idx;
    boolean_T exitg1;
    st.site = &cab_emlrtRSI;
    evalOK = true;
    obj->numEvals = 0;
    b_st.site = &dab_emlrtRSI;
    if ((1 <= obj->nVar) && (obj->nVar > 2147483646)) {
      c_st.site = &qc_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    idx = 0;
    exitg1 = false;
    while ((!exitg1) && (idx <= obj->nVar - 1)) {
      real_T deltaX;
      int32_T i;
      boolean_T guard1{false};
      b_st.site = &dab_emlrtRSI;
      c_st.site = &bab_emlrtRSI;
      i = xk.size(0);
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &rv_emlrtBCI, &c_st);
      }
      if ((idx + 1 < 1) ||
          (idx + 1 > c_runTimeOptions_FiniteDifferen.size(0))) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1,
                                      c_runTimeOptions_FiniteDifferen.size(0),
                                      &rv_emlrtBCI, &c_st);
      }
      if ((idx + 1 < 1) || (idx + 1 > runTimeOptions_TypicalX.size(0))) {
        emlrtDynamicBoundsCheckR2012b(
            idx + 1, 1, runTimeOptions_TypicalX.size(0), &rv_emlrtBCI, &c_st);
      }
      i = xk.size(0);
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &rv_emlrtBCI, &c_st);
      }
      deltaX = 1.4901161193847656E-8 *
               (1.0 - 2.0 * static_cast<real_T>(xk[idx] < 0.0)) *
               muDoubleScalarMax(muDoubleScalarAbs(xk[idx]), 1.0);
      i = obj->hasLB.size(0);
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &pv_emlrtBCI, &st);
      }
      i = obj->hasUB.size(0);
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &pv_emlrtBCI, &st);
      }
      b_st.site = &dab_emlrtRSI;
      internal::finDiffEvalAndChkErr(&b_st, &obj->nonlin, obj->mEq, obj->cEq_1,
                                     idx + 1, deltaX, xk, &evalOK, &d);
      obj->f_1 = 0.0;
      obj->numEvals++;
      guard1 = false;
      if (!evalOK) {
        deltaX = -deltaX;
        i = obj->hasLB.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &pv_emlrtBCI, &st);
        }
        b_st.site = &dab_emlrtRSI;
        internal::finDiffEvalAndChkErr(&b_st, &obj->nonlin, obj->mEq,
                                       obj->cEq_1, idx + 1, deltaX, xk, &evalOK,
                                       &d);
        obj->f_1 = 0.0;
        obj->numEvals++;
        if (!evalOK) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        int32_T formulaType;
        b_st.site = &dab_emlrtRSI;
        formulaType = obj->mEq;
        b_st.site = &dab_emlrtRSI;
        if ((1 <= obj->mEq) && (obj->mEq > 2147483646)) {
          c_st.site = &qc_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        for (int32_T ncols{0}; ncols < formulaType; ncols++) {
          int32_T i1;
          i = obj->cEq_1.size(0);
          if ((ncols + 1 < 1) || (ncols + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(ncols + 1, 1, i, &pv_emlrtBCI, &st);
          }
          if ((ncols + 1 < 1) || (ncols + 1 > cEqCurrent.size(0))) {
            emlrtDynamicBoundsCheckR2012b(ncols + 1, 1, cEqCurrent.size(0),
                                          &pv_emlrtBCI, &st);
          }
          i = JacCeqTrans.size(0) * JacCeqTrans.size(1);
          i1 = (idx + ldJE * ncols) + 1;
          if ((i1 < 1) || (i1 > i)) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, i, &pv_emlrtBCI, &st);
          }
          JacCeqTrans[i1 - 1] =
              (obj->cEq_1[ncols] - cEqCurrent[ncols]) / deltaX;
        }
        idx++;
      }
    }
  } else {
    int32_T idx;
    boolean_T exitg1;
    st.site = &cab_emlrtRSI;
    evalOK = true;
    obj->numEvals = 0;
    b_st.site = &fab_emlrtRSI;
    if ((1 <= obj->nVar) && (obj->nVar > 2147483646)) {
      c_st.site = &qc_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    idx = 0;
    exitg1 = false;
    while ((!exitg1) && (idx <= obj->nVar - 1)) {
      real_T delta1;
      real_T delta2;
      real_T deltaX;
      int32_T formulaType;
      int32_T i;
      b_st.site = &fab_emlrtRSI;
      c_st.site = &bab_emlrtRSI;
      if ((idx + 1 < 1) ||
          (idx + 1 > c_runTimeOptions_FiniteDifferen.size(0))) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1,
                                      c_runTimeOptions_FiniteDifferen.size(0),
                                      &qv_emlrtBCI, &c_st);
      }
      if ((idx + 1 < 1) || (idx + 1 > runTimeOptions_TypicalX.size(0))) {
        emlrtDynamicBoundsCheckR2012b(
            idx + 1, 1, runTimeOptions_TypicalX.size(0), &qv_emlrtBCI, &c_st);
      }
      i = xk.size(0);
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &qv_emlrtBCI, &c_st);
      }
      deltaX = 1.4901161193847656E-8 *
               muDoubleScalarMax(muDoubleScalarAbs(xk[idx]), 1.0);
      i = obj->hasLB.size(0);
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ov_emlrtBCI, &st);
      }
      i = obj->hasUB.size(0);
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ov_emlrtBCI, &st);
      }
      formulaType = 0;
      delta1 = -deltaX;
      delta2 = deltaX;
      int32_T exitg2;
      do {
        exitg2 = 0;
        b_st.site = &fab_emlrtRSI;
        internal::finDiffEvalAndChkErr(&b_st, &obj->nonlin, obj->mEq,
                                       obj->cEq_1, idx + 1, delta1, xk, &evalOK,
                                       &d);
        obj->f_1 = 0.0;
        obj->numEvals++;
        if (!evalOK) {
          if (formulaType == 0) {
            formulaType = 1;
            delta1 = deltaX;
            delta2 = 2.0 * deltaX;
          } else {
            exitg2 = 1;
          }
        } else {
          b_st.site = &fab_emlrtRSI;
          internal::finDiffEvalAndChkErr(&b_st, &obj->nonlin, obj->mEq,
                                         obj->cEq_2, idx + 1, delta2, xk,
                                         &evalOK, &d);
          obj->f_2 = 0.0;
          obj->numEvals++;
          if ((!evalOK) && (formulaType == 0)) {
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
        if (obj->mEq > 0) {
          int32_T ncols;
          b_st.site = &fab_emlrtRSI;
          ncols = obj->mEq - 1;
          switch (formulaType) {
          case 0: {
            c_st.site = &gab_emlrtRSI;
            if ((1 <= obj->mEq) && (obj->mEq > 2147483646)) {
              d_st.site = &qc_emlrtRSI;
              check_forloop_overflow_error(&d_st);
            }
            for (formulaType = 0; formulaType <= ncols; formulaType++) {
              int32_T i1;
              i = obj->cEq_1.size(0);
              if ((formulaType + 1 < 1) || (formulaType + 1 > i)) {
                emlrtDynamicBoundsCheckR2012b(formulaType + 1, 1, i,
                                              &sv_emlrtBCI, &b_st);
              }
              i = obj->cEq_2.size(0);
              if ((formulaType + 1 < 1) || (formulaType + 1 > i)) {
                emlrtDynamicBoundsCheckR2012b(formulaType + 1, 1, i,
                                              &sv_emlrtBCI, &b_st);
              }
              i = JacCeqTrans.size(0) * JacCeqTrans.size(1);
              i1 = (idx + ldJE * formulaType) + 1;
              if ((i1 < 1) || (i1 > i)) {
                emlrtDynamicBoundsCheckR2012b(i1, 1, i, &sv_emlrtBCI, &b_st);
              }
              JacCeqTrans[i1 - 1] =
                  (-obj->cEq_1[formulaType] + obj->cEq_2[formulaType]) /
                  (2.0 * deltaX);
            }
          } break;
          case 1: {
            c_st.site = &gab_emlrtRSI;
            if ((1 <= obj->mEq) && (obj->mEq > 2147483646)) {
              d_st.site = &qc_emlrtRSI;
              check_forloop_overflow_error(&d_st);
            }
            for (formulaType = 0; formulaType <= ncols; formulaType++) {
              int32_T i1;
              if ((formulaType + 1 < 1) ||
                  (formulaType + 1 > cEqCurrent.size(0))) {
                emlrtDynamicBoundsCheckR2012b(formulaType + 1, 1,
                                              cEqCurrent.size(0), &sv_emlrtBCI,
                                              &b_st);
              }
              i = obj->cEq_1.size(0);
              if (formulaType + 1 > i) {
                emlrtDynamicBoundsCheckR2012b(formulaType + 1, 1, i,
                                              &sv_emlrtBCI, &b_st);
              }
              i = obj->cEq_2.size(0);
              if (formulaType + 1 > i) {
                emlrtDynamicBoundsCheckR2012b(formulaType + 1, 1, i,
                                              &sv_emlrtBCI, &b_st);
              }
              i = JacCeqTrans.size(0) * JacCeqTrans.size(1);
              i1 = (idx + ldJE * formulaType) + 1;
              if ((i1 < 1) || (i1 > i)) {
                emlrtDynamicBoundsCheckR2012b(i1, 1, i, &sv_emlrtBCI, &b_st);
              }
              JacCeqTrans[i1 - 1] = ((-3.0 * cEqCurrent[formulaType] +
                                      4.0 * obj->cEq_1[formulaType]) -
                                     obj->cEq_2[formulaType]) /
                                    (2.0 * deltaX);
            }
          } break;
          default: {
            c_st.site = &gab_emlrtRSI;
            if ((1 <= obj->mEq) && (obj->mEq > 2147483646)) {
              d_st.site = &qc_emlrtRSI;
              check_forloop_overflow_error(&d_st);
            }
            for (formulaType = 0; formulaType <= ncols; formulaType++) {
              int32_T i1;
              i = obj->cEq_1.size(0);
              if ((formulaType + 1 < 1) || (formulaType + 1 > i)) {
                emlrtDynamicBoundsCheckR2012b(formulaType + 1, 1, i,
                                              &sv_emlrtBCI, &b_st);
              }
              i = obj->cEq_2.size(0);
              if (formulaType + 1 > i) {
                emlrtDynamicBoundsCheckR2012b(formulaType + 1, 1, i,
                                              &sv_emlrtBCI, &b_st);
              }
              if (formulaType + 1 > cEqCurrent.size(0)) {
                emlrtDynamicBoundsCheckR2012b(formulaType + 1, 1,
                                              cEqCurrent.size(0), &sv_emlrtBCI,
                                              &b_st);
              }
              i = JacCeqTrans.size(0) * JacCeqTrans.size(1);
              i1 = (idx + ldJE * formulaType) + 1;
              if ((i1 < 1) || (i1 > i)) {
                emlrtDynamicBoundsCheckR2012b(i1, 1, i, &sv_emlrtBCI, &b_st);
              }
              JacCeqTrans[i1 - 1] =
                  ((obj->cEq_1[formulaType] - 4.0 * obj->cEq_2[formulaType]) +
                   3.0 * cEqCurrent[formulaType]) /
                  (2.0 * deltaX);
            }
          } break;
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

// End of code generation (computeFiniteDifferences.cpp)
