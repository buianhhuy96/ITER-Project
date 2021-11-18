//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// find.cpp
//
// Code generation for function 'find'
//

// Include files
#include "find.h"
#include "calibrateOneCamera_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo le_emlrtRSI{
    158,        // lineNo
    "eml_find", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pathName
};

static emlrtRTEInfo lb_emlrtRTEI{
    81,         // lineNo
    1,          // colNo
    "eml_find", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pName
};

static emlrtRTEInfo mb_emlrtRTEI{
    66,         // lineNo
    27,         // colNo
    "eml_find", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pName
};

static emlrtRTEInfo oe_emlrtRTEI{
    144,    // lineNo
    9,      // colNo
    "find", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pName
};

// Function Definitions
namespace Codegen {
namespace coder {
void b_eml_find(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x,
                ::coder::array<int32_T, 2U> &i)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T idx;
  int32_T ii;
  int32_T nx;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nx = x.size(1);
  st.site = &ke_emlrtRSI;
  idx = 0;
  i.set_size(&rm_emlrtRTEI, &st, 1, x.size(1));
  b_st.site = &me_emlrtRSI;
  if ((1 <= x.size(1)) && (x.size(1) > 2147483646)) {
    c_st.site = &hc_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x[ii] != 0.0) {
      idx++;
      i[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (idx > x.size(1)) {
    emlrtErrorWithMessageIdR2018a(&st, &q_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (x.size(1) == 1) {
    if (idx == 0) {
      i.set_size(&oe_emlrtRTEI, &st, 1, 0);
    }
  } else {
    if (1 > idx) {
      idx = 0;
    }
    i.set_size(&oe_emlrtRTEI, &st, i.size(0), idx);
  }
}

void b_eml_find(const emlrtStack *sp, const ::coder::array<real_T, 1U> &x,
                ::coder::array<int32_T, 1U> &i)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T b_iv[2];
  int32_T idx;
  int32_T ii;
  int32_T nx;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nx = x.size(0);
  st.site = &ke_emlrtRSI;
  idx = 0;
  i.set_size(&ne_emlrtRTEI, &st, x.size(0));
  b_st.site = &me_emlrtRSI;
  if ((1 <= x.size(0)) && (x.size(0) > 2147483646)) {
    c_st.site = &hc_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x[ii] != 0.0) {
      idx++;
      i[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (idx > x.size(0)) {
    emlrtErrorWithMessageIdR2018a(&st, &q_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (x.size(0) == 1) {
    if (idx == 0) {
      i.set_size(&oe_emlrtRTEI, &st, 0);
    }
  } else {
    if (1 > idx) {
      nx = 0;
    } else {
      nx = idx;
    }
    b_iv[0] = 1;
    b_iv[1] = nx;
    b_st.site = &ne_emlrtRSI;
    internal::indexShapeCheck(&b_st, i.size(0), b_iv);
    i.set_size(&oe_emlrtRTEI, &st, nx);
  }
}

void c_eml_find(const emlrtStack *sp, const ::coder::array<boolean_T, 1U> &x,
                real_T kin, ::coder::array<int32_T, 1U> &i)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T b_iv[2];
  int32_T idx;
  int32_T ii;
  int32_T k;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (!(muDoubleScalarFloor(kin) == kin)) {
    emlrtErrorWithMessageIdR2018a(sp, &mb_emlrtRTEI, "MATLAB:find:NotScalarInt",
                                  "MATLAB:find:NotScalarInt", 0);
  }
  if (kin <= x.size(0)) {
    k = static_cast<int32_T>(kin);
  } else {
    k = x.size(0);
  }
  if (k > x.size(0)) {
    emlrtErrorWithMessageIdR2018a(sp, &lb_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  st.site = &ke_emlrtRSI;
  idx = 0;
  i.set_size(&ne_emlrtRTEI, &st, k);
  b_st.site = &me_emlrtRSI;
  if ((1 <= x.size(0)) && (x.size(0) > 2147483646)) {
    c_st.site = &hc_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= x.size(0) - 1)) {
    if (x[ii]) {
      idx++;
      i[idx - 1] = ii + 1;
      if (idx >= k) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (idx > k) {
    emlrtErrorWithMessageIdR2018a(&st, &q_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (k == 1) {
    if (idx == 0) {
      i.set_size(&oe_emlrtRTEI, &st, 0);
    }
  } else {
    if (1 > idx) {
      k = 0;
    } else {
      k = idx;
    }
    b_iv[0] = 1;
    b_iv[1] = k;
    b_st.site = &ne_emlrtRSI;
    internal::indexShapeCheck(&b_st, i.size(0), b_iv);
    i.set_size(&oe_emlrtRTEI, &st, k);
  }
}

void eml_find(const emlrtStack *sp, const ::coder::array<boolean_T, 2U> &x,
              ::coder::array<int32_T, 1U> &i)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T b_iv[2];
  int32_T idx;
  int32_T ii;
  int32_T nx;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nx = x.size(0) * x.size(1);
  st.site = &ke_emlrtRSI;
  idx = 0;
  i.set_size(&ne_emlrtRTEI, &st, nx);
  b_st.site = &me_emlrtRSI;
  if ((1 <= nx) && (nx > 2147483646)) {
    c_st.site = &hc_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x[ii]) {
      idx++;
      i[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (idx > nx) {
    emlrtErrorWithMessageIdR2018a(&st, &q_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (nx == 1) {
    if (idx == 0) {
      i.set_size(&oe_emlrtRTEI, &st, 0);
    }
  } else {
    if (1 > idx) {
      nx = 0;
    } else {
      nx = idx;
    }
    b_iv[0] = 1;
    b_iv[1] = nx;
    b_st.site = &ne_emlrtRSI;
    internal::indexShapeCheck(&b_st, i.size(0), b_iv);
    i.set_size(&oe_emlrtRTEI, &st, nx);
  }
  if ((x.size(0) == 1) && (i.size(0) != 1) && (x.size(1) >= 2)) {
    st.site = &le_emlrtRSI;
    internal::warning(&st);
  }
}

} // namespace coder
} // namespace Codegen

// End of code generation (find.cpp)
