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
#include "calibrateOneCamera_v2_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo ucb_emlrtRSI{
    1,            // lineNo
    "projectBox", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\projectBox.p" // pathName
};

static emlrtBCInfo uy_emlrtBCI{
    0,            // iFirst
    MAX_int32_T,  // iLast
    1,            // lineNo
    1,            // colNo
    "",           // aName
    "projectBox", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\projectBox.p", // pName
    0                                   // checkKind
};

static emlrtBCInfo vy_emlrtBCI{
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
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
real_T b_projectBox(const emlrtStack *sp, const ::coder::array<real_T, 1U> &x,
                    const ::coder::array<real_T, 1U> &dx,
                    const ::coder::array<boolean_T, 1U> &hasLB,
                    const ::coder::array<boolean_T, 1U> &hasUB)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T dxInfNorm;
  int32_T i;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  i = dx.size(0);
  if (i < 0) {
    emlrtDynamicBoundsCheckR2012b(i, 0, MAX_int32_T, &uy_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  n = i - 1;
  dxInfNorm = 0.0;
  if (x.size(0) == 0) {
    st.site = &ucb_emlrtRSI;
    if ((1 <= dx.size(0)) && (dx.size(0) > 2147483646)) {
      b_st.site = &yc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (int32_T b_i{0}; b_i <= n; b_i++) {
      if (b_i + 1 > hasLB.size(0)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, hasLB.size(0), &vy_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (b_i + 1 > hasUB.size(0)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, hasUB.size(0), &vy_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      i = dx.size(0);
      if (b_i + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i, &vy_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      dxInfNorm = muDoubleScalarMax(dxInfNorm, muDoubleScalarAbs(dx[b_i]));
    }
  } else {
    st.site = &ucb_emlrtRSI;
    if ((1 <= dx.size(0)) && (dx.size(0) > 2147483646)) {
      b_st.site = &yc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (int32_T b_i{0}; b_i <= n; b_i++) {
      if (b_i + 1 > hasLB.size(0)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, hasLB.size(0), &vy_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (b_i + 1 > hasUB.size(0)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, hasUB.size(0), &vy_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      i = dx.size(0);
      if (b_i + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i, &vy_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      dxInfNorm = muDoubleScalarMax(dxInfNorm, muDoubleScalarAbs(dx[b_i]));
    }
  }
  return dxInfNorm;
}

void c_projectBox(const emlrtStack *sp, const ::coder::array<real_T, 1U> &dx,
                  const ::coder::array<boolean_T, 1U> &hasLB,
                  const ::coder::array<boolean_T, 1U> &hasUB)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  i = dx.size(0);
  if (i < 0) {
    emlrtDynamicBoundsCheckR2012b(i, 0, MAX_int32_T, &uy_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  st.site = &ucb_emlrtRSI;
  if ((1 <= dx.size(0)) && (dx.size(0) > 2147483646)) {
    b_st.site = &yc_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T b_i{0}; b_i < i; b_i++) {
    int32_T i1;
    if (b_i + 1 > hasLB.size(0)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, hasLB.size(0), &vy_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (b_i + 1 > hasUB.size(0)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, hasUB.size(0), &vy_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = dx.size(0);
    if (b_i + 1 > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i1, &vy_emlrtBCI, (emlrtCTX)sp);
    }
  }
}

void projectBox(const emlrtStack *sp, const ::coder::array<real_T, 1U> &x,
                const ::coder::array<real_T, 1U> &dx,
                const ::coder::array<boolean_T, 1U> &hasLB,
                const ::coder::array<boolean_T, 1U> &hasUB)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  i = dx.size(0);
  if (i < 0) {
    emlrtDynamicBoundsCheckR2012b(i, 0, MAX_int32_T, &uy_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  n = i - 1;
  if (x.size(0) == 0) {
    st.site = &ucb_emlrtRSI;
    if ((1 <= dx.size(0)) && (dx.size(0) > 2147483646)) {
      b_st.site = &yc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (int32_T b_i{0}; b_i <= n; b_i++) {
      if (b_i + 1 > hasLB.size(0)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, hasLB.size(0), &vy_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (b_i + 1 > hasUB.size(0)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, hasUB.size(0), &vy_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      i = dx.size(0);
      if (b_i + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i, &vy_emlrtBCI,
                                      (emlrtCTX)sp);
      }
    }
  } else {
    st.site = &ucb_emlrtRSI;
    if ((1 <= dx.size(0)) && (dx.size(0) > 2147483646)) {
      b_st.site = &yc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (int32_T b_i{0}; b_i <= n; b_i++) {
      if (b_i + 1 > hasLB.size(0)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, hasLB.size(0), &vy_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (b_i + 1 > hasUB.size(0)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, hasUB.size(0), &vy_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      i = dx.size(0);
      if (b_i + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i, &vy_emlrtBCI,
                                      (emlrtCTX)sp);
      }
    }
  }
}

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (projectBox.cpp)
