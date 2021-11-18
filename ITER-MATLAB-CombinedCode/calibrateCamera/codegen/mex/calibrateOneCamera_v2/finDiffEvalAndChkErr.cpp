//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// finDiffEvalAndChkErr.cpp
//
// Code generation for function 'finDiffEvalAndChkErr'
//

// Include files
#include "finDiffEvalAndChkErr.h"
#include "anonymous_function.h"
#include "anonymous_function1.h"
#include "calibrateOneCamera_v2_data.h"
#include "calibrateOneCamera_v2_internal_types1.h"
#include "driver.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo bfb_emlrtRSI{
    1,                      // lineNo
    "finDiffEvalAndChkErr", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\+internal\\finDiffEvalAndChkErr.p" // pathName
};

static emlrtBCInfo kx_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    1,                      // lineNo
    1,                      // colNo
    "",                     // aName
    "finDiffEvalAndChkErr", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\+internal\\finDiffEvalAndChkErr.p", // pName
    0                                                       // checkKind
};

static emlrtBCInfo lx_emlrtBCI{
    1,                      // iFirst
    0,                      // iLast
    1,                      // lineNo
    1,                      // colNo
    "",                     // aName
    "finDiffEvalAndChkErr", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\+internal\\finDiffEvalAndChkErr.p", // pName
    0                                                       // checkKind
};

static emlrtECInfo fe_emlrtECI{
    -1,                     // nDims
    1,                      // lineNo
    1,                      // colNo
    "finDiffEvalAndChkErr", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\+internal\\finDiffEvalAndChkErr.p" // pName
};

static emlrtRTEInfo pw_emlrtRTEI{
    1,                      // lineNo
    1,                      // colNo
    "finDiffEvalAndChkErr", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\+internal\\finDiffEvalAndChkErr.p" // pName
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
namespace internal {
boolean_T finDiffEvalAndChkErr(const emlrtStack *sp,
                               const b_anonymous_function *obj_nonlin,
                               int32_T obj_mIneq, int32_T obj_mEq,
                               boolean_T obj_SpecifyConstraintGradient,
                               ::coder::array<real_T, 1U> &cEqPlus, int32_T dim,
                               real_T delta, ::coder::array<real_T, 1U> &xk)
{
  array<real_T, 1U> varargout_2;
  emlrtStack b_st;
  emlrtStack st;
  real_T temp_tmp;
  int32_T i;
  boolean_T evalOK;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  evalOK = true;
  i = xk.size(0);
  if ((dim < 1) || (dim > i)) {
    emlrtDynamicBoundsCheckR2012b(dim, 1, i, &kx_emlrtBCI, (emlrtCTX)sp);
  }
  temp_tmp = xk[dim - 1];
  i = xk.size(0);
  if (dim > i) {
    emlrtDynamicBoundsCheckR2012b(dim, 1, i, &kx_emlrtBCI, (emlrtCTX)sp);
  }
  i = xk.size(0);
  if (dim > i) {
    emlrtDynamicBoundsCheckR2012b(dim, 1, i, &kx_emlrtBCI, (emlrtCTX)sp);
  }
  xk[dim - 1] = temp_tmp + delta;
  if (!obj_SpecifyConstraintGradient) {
    int32_T loop_ub;
    st.site = &bfb_emlrtRSI;
    b_st.site = &rcb_emlrtRSI;
    levenbergMarquardt::driver_anonFcn1(&b_st, &obj_nonlin->workspace.fun, xk,
                                        varargout_2);
    i = cEqPlus.size(0);
    if (i != varargout_2.size(0)) {
      emlrtSubAssignSizeCheck1dR2017a(i, varargout_2.size(0), &fe_emlrtECI,
                                      (emlrtCTX)sp);
    }
    cEqPlus.set_size(&pw_emlrtRTEI, sp, varargout_2.size(0));
    loop_ub = varargout_2.size(0);
    for (i = 0; i < loop_ub; i++) {
      cEqPlus[i] = varargout_2[i];
    }
    loop_ub = 1;
    while (1 <= obj_mIneq) {
      emlrtDynamicBoundsCheckR2012b(1, 1, 0, &lx_emlrtBCI, (emlrtCTX)sp);
    }
    while (evalOK && (loop_ub <= obj_mEq)) {
      real_T evalOK_tmp;
      i = cEqPlus.size(0);
      if ((loop_ub < 1) || (loop_ub > i)) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i, &kx_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      evalOK_tmp = cEqPlus[loop_ub - 1];
      evalOK = ((!muDoubleScalarIsInf(evalOK_tmp)) &&
                (!muDoubleScalarIsNaN(evalOK_tmp)));
      loop_ub++;
    }
  }
  i = xk.size(0);
  if (dim > i) {
    emlrtDynamicBoundsCheckR2012b(dim, 1, i, &kx_emlrtBCI, (emlrtCTX)sp);
  }
  xk[dim - 1] = temp_tmp;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return evalOK;
}

} // namespace internal
} // namespace FiniteDifferences
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (finDiffEvalAndChkErr.cpp)
