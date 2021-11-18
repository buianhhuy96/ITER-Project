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
#include "calibrateCamera_data.h"
#include "calibrateCamera_internal_types1.h"
#include "driver.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo eab_emlrtRSI{
    1,                      // lineNo
    "finDiffEvalAndChkErr", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\+internal\\finDiffEvalAndChkErr.p" // pathName
};

static emlrtBCInfo vv_emlrtBCI{
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

static emlrtECInfo fe_emlrtECI{
    -1,                     // nDims
    1,                      // lineNo
    1,                      // colNo
    "finDiffEvalAndChkErr", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\+internal\\finDiffEvalAndChkErr.p" // pName
};

static emlrtRTEInfo vs_emlrtRTEI{
    1,                      // lineNo
    1,                      // colNo
    "finDiffEvalAndChkErr", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\+internal\\finDiffEvalAndChkErr.p" // pName
};

// Function Definitions
namespace Codegen {
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
namespace internal {
void finDiffEvalAndChkErr(const emlrtStack *sp,
                          const b_anonymous_function *obj_nonlin,
                          int32_T obj_mEq, ::coder::array<real_T, 1U> &cEqPlus,
                          int32_T dim, real_T delta,
                          ::coder::array<real_T, 1U> &xk, boolean_T *evalOK,
                          real_T *fplus)
{
  ::coder::array<real_T, 1U> varargout_2;
  emlrtStack b_st;
  emlrtStack st;
  real_T temp_tmp;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  *fplus = 0.0;
  *evalOK = true;
  i = xk.size(0);
  if ((dim < 1) || (dim > i)) {
    emlrtDynamicBoundsCheckR2012b(dim, 1, i, &vv_emlrtBCI, (emlrtCTX)sp);
  }
  temp_tmp = xk[dim - 1];
  i = xk.size(0);
  if (dim > i) {
    emlrtDynamicBoundsCheckR2012b(dim, 1, i, &vv_emlrtBCI, (emlrtCTX)sp);
  }
  i = xk.size(0);
  if (dim > i) {
    emlrtDynamicBoundsCheckR2012b(dim, 1, i, &vv_emlrtBCI, (emlrtCTX)sp);
  }
  xk[dim - 1] = temp_tmp + delta;
  st.site = &eab_emlrtRSI;
  b_st.site = &sy_emlrtRSI;
  levenbergMarquardt::driver_anonFcn1(&b_st, &obj_nonlin->workspace.fun, xk,
                                      varargout_2);
  i = cEqPlus.size(0);
  if (i != varargout_2.size(0)) {
    emlrtSubAssignSizeCheck1dR2017a(i, varargout_2.size(0), &fe_emlrtECI,
                                    (emlrtCTX)sp);
  }
  cEqPlus.set_size(&vs_emlrtRTEI, sp, varargout_2.size(0));
  loop_ub = varargout_2.size(0);
  for (i = 0; i < loop_ub; i++) {
    cEqPlus[i] = varargout_2[i];
  }
  loop_ub = 1;
  while ((*evalOK) && (loop_ub <= obj_mEq)) {
    real_T evalOK_tmp;
    if ((loop_ub < 1) || (loop_ub > varargout_2.size(0))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, varargout_2.size(0),
                                    &vv_emlrtBCI, (emlrtCTX)sp);
    }
    evalOK_tmp = varargout_2[loop_ub - 1];
    *evalOK = ((!muDoubleScalarIsInf(evalOK_tmp)) &&
               (!muDoubleScalarIsNaN(evalOK_tmp)));
    loop_ub++;
  }
  i = xk.size(0);
  if (dim > i) {
    emlrtDynamicBoundsCheckR2012b(dim, 1, i, &vv_emlrtBCI, (emlrtCTX)sp);
  }
  xk[dim - 1] = temp_tmp;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace internal
} // namespace FiniteDifferences
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace Codegen

// End of code generation (finDiffEvalAndChkErr.cpp)
