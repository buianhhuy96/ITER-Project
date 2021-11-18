//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// projectBox.cpp
//
// Code generation for function 'projectBox'
//

// Include files
#include "projectBox.h"
#include "calibrateOneCamera_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo oy_emlrtRSI{
    1,            // lineNo
    "projectBox", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\projectBox.p" // pathName
};

static emlrtBCInfo vv_emlrtBCI{
    -1,           // iFirst
    -1,           // iLast
    1,            // lineNo
    1,            // colNo
    "",           // aName
    "projectBox", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\projectBox.p", // pName
    0                                   // checkKind
};

// Function Definitions
namespace Codegen {
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
real_T projectBox(const emlrtStack *sp, const ::coder::array<real_T, 1U> &dx,
                  const ::coder::array<boolean_T, 1U> &hasLB,
                  const ::coder::array<boolean_T, 1U> &hasUB)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T dxInfNorm;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  n = dx.size(0);
  dxInfNorm = 0.0;
  st.site = &oy_emlrtRSI;
  if ((1 <= dx.size(0)) && (dx.size(0) > 2147483646)) {
    b_st.site = &hc_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T i{0}; i < n; i++) {
    int32_T b_i;
    if ((i + 1 < 1) || (i + 1 > hasLB.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, hasLB.size(0), &vv_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (i + 1 > hasUB.size(0)) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, hasUB.size(0), &vv_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    b_i = dx.size(0);
    if (i + 1 > b_i) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_i, &vv_emlrtBCI, (emlrtCTX)sp);
    }
    dxInfNorm = muDoubleScalarMax(dxInfNorm, muDoubleScalarAbs(dx[i]));
  }
  return dxInfNorm;
}

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace Codegen

// End of code generation (projectBox.cpp)
