//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// rot90.cpp
//
// Code generation for function 'rot90'
//

// Include files
#include "rot90.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo gs_emlrtRSI{
    53,      // lineNo
    "rot90", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\rot90.m" // pathName
};

static emlrtRSInfo hs_emlrtRSI{
    54,      // lineNo
    "rot90", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\rot90.m" // pathName
};

static emlrtRSInfo is_emlrtRSI{
    61,      // lineNo
    "rot90", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\rot90.m" // pathName
};

static emlrtRSInfo js_emlrtRSI{
    62,      // lineNo
    "rot90", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\rot90.m" // pathName
};

static emlrtRSInfo xs_emlrtRSI{
    73,      // lineNo
    "rot90", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\rot90.m" // pathName
};

static emlrtRSInfo ys_emlrtRSI{
    74,      // lineNo
    "rot90", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\rot90.m" // pathName
};

static emlrtRSInfo at_emlrtRSI{
    81,      // lineNo
    "rot90", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\rot90.m" // pathName
};

static emlrtRSInfo bt_emlrtRSI{
    82,      // lineNo
    "rot90", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\rot90.m" // pathName
};

static emlrtRTEInfo sq_emlrtRTEI{
    50,      // lineNo
    24,      // colNo
    "rot90", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\rot90.m" // pName
};

static emlrtRTEInfo vq_emlrtRTEI{
    70,      // lineNo
    24,      // colNo
    "rot90", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\rot90.m" // pName
};

// Function Definitions
namespace coder {
void b_rot90(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A,
             ::coder::array<real_T, 2U> &B)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T m;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  m = A.size(0);
  n = A.size(1) - 1;
  B.set_size(&vq_emlrtRTEI, sp, A.size(0), A.size(1));
  if (A.size(0) * A.size(1) >= 8192) {
    st.site = &xs_emlrtRSI;
    if ((1 <= A.size(1)) && (A.size(1) > 2147483646)) {
      b_st.site = &yc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (int32_T j{0}; j <= n; j++) {
      st.site = &ys_emlrtRSI;
      if ((1 <= m) && (m > 2147483646)) {
        b_st.site = &yc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (int32_T i{0}; i < m; i++) {
        B[i + B.size(0) * j] = A[((m - i) + A.size(0) * (n - j)) - 1];
      }
    }
  } else {
    st.site = &at_emlrtRSI;
    if ((1 <= A.size(1)) && (A.size(1) > 2147483646)) {
      b_st.site = &yc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (int32_T j{0}; j <= n; j++) {
      st.site = &bt_emlrtRSI;
      if ((1 <= m) && (m > 2147483646)) {
        b_st.site = &yc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (int32_T i{0}; i < m; i++) {
        B[i + B.size(0) * j] = A[((m - i) + A.size(0) * (n - j)) - 1];
      }
    }
  }
}

void rot90(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A,
           ::coder::array<real_T, 2U> &B)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T m;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  m = A.size(0);
  n = A.size(1) - 1;
  B.set_size(&sq_emlrtRTEI, sp, A.size(1), A.size(0));
  if (A.size(0) * A.size(1) >= 8192) {
    st.site = &gs_emlrtRSI;
    if ((1 <= A.size(1)) && (A.size(1) > 2147483646)) {
      b_st.site = &yc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (int32_T i{0}; i <= n; i++) {
      st.site = &hs_emlrtRSI;
      if ((1 <= m) && (m > 2147483646)) {
        b_st.site = &yc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (int32_T j{0}; j < m; j++) {
        B[i + B.size(0) * j] = A[j + A.size(0) * (n - i)];
      }
    }
  } else {
    st.site = &is_emlrtRSI;
    if ((1 <= A.size(1)) && (A.size(1) > 2147483646)) {
      b_st.site = &yc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (int32_T i{0}; i <= n; i++) {
      st.site = &js_emlrtRSI;
      if ((1 <= m) && (m > 2147483646)) {
        b_st.site = &yc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (int32_T j{0}; j < m; j++) {
        B[i + B.size(0) * j] = A[j + A.size(0) * (n - i)];
      }
    }
  }
}

} // namespace coder

// End of code generation (rot90.cpp)
