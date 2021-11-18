//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeCentralDifferences.cpp
//
// Code generation for function 'computeCentralDifferences'
//

// Include files
#include "computeCentralDifferences.h"
#include "anonymous_function.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "calibrateOneCamera_v2_mex_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "finDiffEvalAndChkErr.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo bfb_emlrtRSI{
    1,                           // lineNo
    "computeCentralDifferences", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\+internal\\computeCentralDifferences.p" // pathName
};

static emlrtRSInfo cfb_emlrtRSI{
    1,                        // lineNo
    "twoStepFinDiffFormulas", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\+internal\\twoStepFinDiffFormulas.p" // pathName
};

static emlrtBCInfo hab_emlrtBCI{
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

static emlrtBCInfo iab_emlrtBCI{
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

static emlrtBCInfo jab_emlrtBCI{
    1,                           // iFirst
    0,                           // iLast
    1,                           // lineNo
    1,                           // colNo
    "",                          // aName
    "computeCentralDifferences", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\+internal\\computeCentralDifferences.p", // pName
    0                                                            // checkKind
};

static emlrtBCInfo kab_emlrtBCI{
    1,                        // iFirst
    0,                        // iLast
    1,                        // lineNo
    1,                        // colNo
    "",                       // aName
    "twoStepFinDiffFormulas", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\+internal\\twoStepFinDiffFormulas.p", // pName
    0                                                         // checkKind
};

static emlrtBCInfo lab_emlrtBCI{
    1,                        // iFirst
    0,                        // iLast
    1,                        // lineNo
    1,                        // colNo
    "",                       // aName
    "twoStepFinDiffFormulas", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\+internal\\twoStepFinDiffFormulas.p", // pName
    3                                                         // checkKind
};

static emlrtBCInfo mab_emlrtBCI{
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
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
namespace internal {
boolean_T computeCentralDifferences(
    const emlrtStack *sp, d_struct_T *obj,
    const ::coder::array<real_T, 1U> &cEqCurrent,
    ::coder::array<real_T, 1U> &xk, ::coder::array<real_T, 2U> &JacCeqTrans,
    int32_T ldJE, const ::coder::array<real_T, 1U> &runTimeOptions_TypicalX,
    const ::coder::array<real_T, 1U> &c_runTimeOptions_FiniteDifferen)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T formulaType;
  int32_T idx;
  boolean_T evalOK;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  evalOK = true;
  obj->numEvals = 0;
  st.site = &bfb_emlrtRSI;
  if ((1 <= obj->nVar) && (obj->nVar > 2147483646)) {
    b_st.site = &yc_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx <= obj->nVar - 1)) {
    real_T delta1;
    real_T delta2;
    real_T deltaX;
    int32_T i;
    boolean_T guard1{false};
    boolean_T guard2{false};
    st.site = &bfb_emlrtRSI;
    b_st.site = &web_emlrtRSI;
    i = xk.size(0);
    if ((idx + 1 < 1) || (idx + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &iab_emlrtBCI, &b_st);
    }
    if ((idx + 1 < 1) || (idx + 1 > runTimeOptions_TypicalX.size(0))) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, runTimeOptions_TypicalX.size(0),
                                    &iab_emlrtBCI, &b_st);
    }
    if ((idx + 1 < 1) || (idx + 1 > c_runTimeOptions_FiniteDifferen.size(0))) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1,
                                    c_runTimeOptions_FiniteDifferen.size(0),
                                    &iab_emlrtBCI, &b_st);
    }
    deltaX = c_runTimeOptions_FiniteDifferen[idx] *
             muDoubleScalarMax(muDoubleScalarAbs(xk[idx]),
                               muDoubleScalarAbs(runTimeOptions_TypicalX[idx]));
    i = obj->hasLB.size(0);
    if ((idx + 1 < 1) || (idx + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &hab_emlrtBCI, (emlrtCTX)sp);
    }
    guard1 = false;
    guard2 = false;
    if (obj->hasLB[idx]) {
      guard2 = true;
    } else {
      i = obj->hasUB.size(0);
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &hab_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (obj->hasUB[idx]) {
        guard2 = true;
      } else {
        formulaType = 0;
      }
    }
    if (guard2) {
      i = obj->hasLB.size(0);
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &hab_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (obj->hasLB[idx]) {
        i = obj->hasUB.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &hab_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (obj->hasUB[idx]) {
          i = xk.size(0);
          if ((idx + 1 < 1) || (idx + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &hab_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          if ((idx + 1 < 1) || (idx + 1 > 0)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 0, &jab_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          formulaType = 0;
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
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &hab_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (obj->hasUB[idx]) {
        i = xk.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &hab_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if ((idx + 1 < 1) || (idx + 1 > 0)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 0, &jab_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        formulaType = 0;
      } else {
        i = xk.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &hab_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if ((idx + 1 < 1) || (idx + 1 > 0)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 0, &jab_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        formulaType = 0;
      }
    }
    delta1 = -deltaX;
    delta2 = deltaX;
    int32_T exitg2;
    do {
      exitg2 = 0;
      st.site = &bfb_emlrtRSI;
      evalOK = finDiffEvalAndChkErr(&st, &obj->nonlin, obj->mIneq, obj->mEq,
                                    obj->SpecifyConstraintGradient, obj->cEq_1,
                                    idx + 1, delta1, xk);
      obj->numEvals++;
      if (!evalOK) {
        if (formulaType == 0) {
          if (!obj->hasBounds) {
            formulaType = 1;
            delta1 = deltaX;
            delta2 = 2.0 * deltaX;
          } else {
            i = obj->hasUB.size(0);
            if ((idx + 1 < 1) || (idx + 1 > i)) {
              emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &hab_emlrtBCI,
                                            (emlrtCTX)sp);
            }
            if (obj->hasUB[idx]) {
              i = xk.size(0);
              if ((idx + 1 < 1) || (idx + 1 > i)) {
                emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &hab_emlrtBCI,
                                              (emlrtCTX)sp);
              }
              if ((idx + 1 < 1) || (idx + 1 > 0)) {
                emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 0, &jab_emlrtBCI,
                                              (emlrtCTX)sp);
              }
            }
            exitg2 = 1;
          }
        } else {
          exitg2 = 1;
        }
      } else {
        st.site = &bfb_emlrtRSI;
        evalOK = finDiffEvalAndChkErr(&st, &obj->nonlin, obj->mIneq, obj->mEq,
                                      obj->SpecifyConstraintGradient,
                                      obj->cEq_2, idx + 1, delta2, xk);
        obj->numEvals++;
        if ((!evalOK) && (formulaType == 0)) {
          if (!obj->hasBounds) {
            formulaType = -1;
            delta1 = -2.0 * deltaX;
            delta2 = -deltaX;
          } else {
            i = obj->hasLB.size(0);
            if ((idx + 1 < 1) || (idx + 1 > i)) {
              emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &hab_emlrtBCI,
                                            (emlrtCTX)sp);
            }
            if (obj->hasLB[idx]) {
              i = xk.size(0);
              if ((idx + 1 < 1) || (idx + 1 > i)) {
                emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &hab_emlrtBCI,
                                              (emlrtCTX)sp);
              }
              if ((idx + 1 < 1) || (idx + 1 > 0)) {
                emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 0, &jab_emlrtBCI,
                                              (emlrtCTX)sp);
              }
            }
            exitg2 = 1;
          }
        } else {
          exitg2 = 1;
        }
      }
    } while (exitg2 == 0);
    if (!evalOK) {
      exitg1 = true;
    } else {
      if (!obj->SpecifyConstraintGradient) {
        int32_T idx_col;
        int32_T ncols;
        if (obj->mIneq > 0) {
          st.site = &bfb_emlrtRSI;
          ncols = obj->mIneq - 1;
          switch (formulaType) {
          case 0:
            b_st.site = &cfb_emlrtRSI;
            if ((1 <= obj->mIneq) && (obj->mIneq > 2147483646)) {
              c_st.site = &yc_emlrtRSI;
              check_forloop_overflow_error(&c_st);
            }
            for (idx_col = 0; idx_col <= ncols; idx_col++) {
              if ((idx_col + 1 < 1) || (idx_col + 1 > 0)) {
                emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, 0, &kab_emlrtBCI,
                                              &st);
              }
              if ((idx + 1 < 1) || (idx + 1 > 0)) {
                emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 0, &lab_emlrtBCI,
                                              &st);
              }
            }
            break;
          case 1:
            b_st.site = &cfb_emlrtRSI;
            if ((1 <= obj->mIneq) && (obj->mIneq > 2147483646)) {
              c_st.site = &yc_emlrtRSI;
              check_forloop_overflow_error(&c_st);
            }
            for (idx_col = 0; idx_col <= ncols; idx_col++) {
              if ((idx_col + 1 < 1) || (idx_col + 1 > 0)) {
                emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, 0, &kab_emlrtBCI,
                                              &st);
              }
              if ((idx + 1 < 1) || (idx + 1 > 0)) {
                emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 0, &lab_emlrtBCI,
                                              &st);
              }
            }
            break;
          default:
            b_st.site = &cfb_emlrtRSI;
            if ((1 <= obj->mIneq) && (obj->mIneq > 2147483646)) {
              c_st.site = &yc_emlrtRSI;
              check_forloop_overflow_error(&c_st);
            }
            for (idx_col = 0; idx_col <= ncols; idx_col++) {
              if ((idx_col + 1 < 1) || (idx_col + 1 > 0)) {
                emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, 0, &kab_emlrtBCI,
                                              &st);
              }
              if ((idx + 1 < 1) || (idx + 1 > 0)) {
                emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 0, &lab_emlrtBCI,
                                              &st);
              }
            }
            break;
          }
        }
        if (obj->mEq > 0) {
          st.site = &bfb_emlrtRSI;
          ncols = obj->mEq - 1;
          switch (formulaType) {
          case 0:
            b_st.site = &cfb_emlrtRSI;
            if ((1 <= obj->mEq) && (obj->mEq > 2147483646)) {
              c_st.site = &yc_emlrtRSI;
              check_forloop_overflow_error(&c_st);
            }
            for (idx_col = 0; idx_col <= ncols; idx_col++) {
              i = obj->cEq_1.size(0);
              if ((idx_col + 1 < 1) || (idx_col + 1 > i)) {
                emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, i, &mab_emlrtBCI,
                                              &st);
              }
              i = obj->cEq_2.size(0);
              if ((idx_col + 1 < 1) || (idx_col + 1 > i)) {
                emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, i, &mab_emlrtBCI,
                                              &st);
              }
              i = JacCeqTrans.size(0) * JacCeqTrans.size(1);
              formulaType = (idx + ldJE * idx_col) + 1;
              if ((formulaType < 1) || (formulaType > i)) {
                emlrtDynamicBoundsCheckR2012b(formulaType, 1, i, &mab_emlrtBCI,
                                              &st);
              }
              JacCeqTrans[formulaType - 1] =
                  (-obj->cEq_1[idx_col] + obj->cEq_2[idx_col]) / (2.0 * deltaX);
            }
            break;
          case 1:
            b_st.site = &cfb_emlrtRSI;
            if ((1 <= obj->mEq) && (obj->mEq > 2147483646)) {
              c_st.site = &yc_emlrtRSI;
              check_forloop_overflow_error(&c_st);
            }
            for (idx_col = 0; idx_col <= ncols; idx_col++) {
              if ((idx_col + 1 < 1) || (idx_col + 1 > cEqCurrent.size(0))) {
                emlrtDynamicBoundsCheckR2012b(
                    idx_col + 1, 1, cEqCurrent.size(0), &mab_emlrtBCI, &st);
              }
              i = obj->cEq_1.size(0);
              if (idx_col + 1 > i) {
                emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, i, &mab_emlrtBCI,
                                              &st);
              }
              i = obj->cEq_2.size(0);
              if (idx_col + 1 > i) {
                emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, i, &mab_emlrtBCI,
                                              &st);
              }
              i = JacCeqTrans.size(0) * JacCeqTrans.size(1);
              formulaType = (idx + ldJE * idx_col) + 1;
              if ((formulaType < 1) || (formulaType > i)) {
                emlrtDynamicBoundsCheckR2012b(formulaType, 1, i, &mab_emlrtBCI,
                                              &st);
              }
              JacCeqTrans[formulaType - 1] =
                  ((-3.0 * cEqCurrent[idx_col] + 4.0 * obj->cEq_1[idx_col]) -
                   obj->cEq_2[idx_col]) /
                  (2.0 * deltaX);
            }
            break;
          default:
            b_st.site = &cfb_emlrtRSI;
            if ((1 <= obj->mEq) && (obj->mEq > 2147483646)) {
              c_st.site = &yc_emlrtRSI;
              check_forloop_overflow_error(&c_st);
            }
            for (idx_col = 0; idx_col <= ncols; idx_col++) {
              i = obj->cEq_1.size(0);
              if ((idx_col + 1 < 1) || (idx_col + 1 > i)) {
                emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, i, &mab_emlrtBCI,
                                              &st);
              }
              i = obj->cEq_2.size(0);
              if (idx_col + 1 > i) {
                emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, i, &mab_emlrtBCI,
                                              &st);
              }
              if (idx_col + 1 > cEqCurrent.size(0)) {
                emlrtDynamicBoundsCheckR2012b(
                    idx_col + 1, 1, cEqCurrent.size(0), &mab_emlrtBCI, &st);
              }
              i = JacCeqTrans.size(0) * JacCeqTrans.size(1);
              formulaType = (idx + ldJE * idx_col) + 1;
              if ((formulaType < 1) || (formulaType > i)) {
                emlrtDynamicBoundsCheckR2012b(formulaType, 1, i, &mab_emlrtBCI,
                                              &st);
              }
              JacCeqTrans[formulaType - 1] =
                  ((obj->cEq_1[idx_col] - 4.0 * obj->cEq_2[idx_col]) +
                   3.0 * cEqCurrent[idx_col]) /
                  (2.0 * deltaX);
            }
            break;
          }
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

// End of code generation (computeCentralDifferences.cpp)
