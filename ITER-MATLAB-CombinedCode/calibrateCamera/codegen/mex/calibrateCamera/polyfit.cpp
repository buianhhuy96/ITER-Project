//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// polyfit.cpp
//
// Code generation for function 'polyfit'
//

// Include files
#include "polyfit.h"
#include "calibrateCamera_data.h"
#include "qrsolve.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "coder_array.h"
#include <algorithm>

// Variable Definitions
static emlrtRSInfo uk_emlrtRSI{
    32,        // lineNo
    "polyfit", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\polyfun\\polyfit.m" // pathName
};

static emlrtRSInfo vk_emlrtRSI{
    36,        // lineNo
    "polyfit", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\polyfun\\polyfit.m" // pathName
};

static emlrtRSInfo wk_emlrtRSI{
    40,        // lineNo
    "polyfit", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\polyfun\\polyfit.m" // pathName
};

static emlrtRSInfo xk_emlrtRSI{
    47,        // lineNo
    "polyfit", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\polyfun\\polyfit.m" // pathName
};

static emlrtRTEInfo db_emlrtRTEI{
    26,        // lineNo
    23,        // colNo
    "polyfit", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\polyfun\\polyfit.m" // pName
};

static emlrtRTEInfo eb_emlrtRTEI{
    30,       // lineNo
    9,        // colNo
    "vander", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\vander.m" // pName
};

static emlrtRTEInfo bj_emlrtRTEI{
    17,       // lineNo
    20,       // colNo
    "vander", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\vander.m" // pName
};

// Function Definitions
namespace Codegen {
namespace coder {
void polyfit(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x,
             const ::coder::array<real_T, 2U> &y, real_T n, real_T p_data[],
             int32_T p_size[2])
{
  ::coder::array<real_T, 2U> V;
  ::coder::array<real_T, 1U> c_y;
  emlrtStack st;
  real_T p1_data[5];
  int32_T b_y;
  int32_T rr;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (x.size(1) != y.size(1)) {
    emlrtErrorWithMessageIdR2018a(sp, &db_emlrtRTEI,
                                  "MATLAB:polyfit:XYSizeMismatch",
                                  "MATLAB:polyfit:XYSizeMismatch", 0);
  }
  st.site = &uk_emlrtRSI;
  V.set_size(&bj_emlrtRTEI, &st, x.size(1), static_cast<int32_T>(n + 1.0));
  if (x.size(1) != 0) {
    int32_T k;
    b_y = x.size(1);
    for (k = 0; k < b_y; k++) {
      V[k + V.size(0) * (static_cast<int32_T>(n + 1.0) - 1)] = 1.0;
    }
    b_y = x.size(1);
    for (k = 0; k < b_y; k++) {
      V[k + V.size(0) * (static_cast<int32_T>(n) - 1)] = x[k];
    }
    b_y = static_cast<int32_T>(-((-1.0 - (n - 1.0)) + 1.0));
    emlrtForLoopVectorCheckR2021a(
        n - 1.0, -1.0, 1.0, mxDOUBLE_CLASS,
        static_cast<int32_T>(-((-1.0 - (n - 1.0)) + 1.0)), &eb_emlrtRTEI, &st);
    for (int32_T j{0}; j < b_y; j++) {
      real_T b_j;
      b_j = (n - 1.0) + -static_cast<real_T>(j);
      rr = x.size(1);
      for (k = 0; k < rr; k++) {
        V[k + V.size(0) * (static_cast<int32_T>(b_j) - 1)] =
            x[k] * V[k + V.size(0) * (static_cast<int32_T>(b_j + 1.0) - 1)];
      }
    }
  }
  b_y = y.size(1);
  c_y = y.reshape(b_y);
  st.site = &vk_emlrtRSI;
  internal::qrsolve(&st, V, c_y, p1_data, &b_y, &rr);
  if (n >= x.size(1)) {
    if (!emlrtSetWarningFlag((emlrtCTX)sp)) {
      st.site = &wk_emlrtRSI;
      internal::c_warning(&st);
    }
  } else if ((rr <= n) && (!emlrtSetWarningFlag((emlrtCTX)sp))) {
    st.site = &xk_emlrtRSI;
    internal::d_warning(&st);
  }
  p_size[0] = 1;
  p_size[1] = b_y;
  if (0 <= b_y - 1) {
    std::copy(&p1_data[0], &p1_data[b_y], &p_data[0]);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void polyfit(const emlrtStack *sp, const ::coder::array<real_T, 1U> &x,
             const ::coder::array<real_T, 1U> &y, real_T n, real_T p_data[],
             int32_T p_size[2])
{
  ::coder::array<real_T, 2U> V;
  emlrtStack st;
  real_T p1_data[5];
  int32_T p1_size;
  int32_T rr;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (x.size(0) != y.size(0)) {
    emlrtErrorWithMessageIdR2018a(sp, &db_emlrtRTEI,
                                  "MATLAB:polyfit:XYSizeMismatch",
                                  "MATLAB:polyfit:XYSizeMismatch", 0);
  }
  st.site = &uk_emlrtRSI;
  V.set_size(&bj_emlrtRTEI, &st, x.size(0), static_cast<int32_T>(n + 1.0));
  if (x.size(0) != 0) {
    int32_T k;
    p1_size = x.size(0);
    for (k = 0; k < p1_size; k++) {
      V[k + V.size(0) * (static_cast<int32_T>(n + 1.0) - 1)] = 1.0;
    }
    p1_size = x.size(0);
    for (k = 0; k < p1_size; k++) {
      V[k + V.size(0) * (static_cast<int32_T>(n) - 1)] = x[k];
    }
    p1_size = static_cast<int32_T>(-((-1.0 - (n - 1.0)) + 1.0));
    emlrtForLoopVectorCheckR2021a(
        n - 1.0, -1.0, 1.0, mxDOUBLE_CLASS,
        static_cast<int32_T>(-((-1.0 - (n - 1.0)) + 1.0)), &eb_emlrtRTEI, &st);
    for (int32_T j{0}; j < p1_size; j++) {
      real_T b_j;
      b_j = (n - 1.0) + -static_cast<real_T>(j);
      rr = x.size(0);
      for (k = 0; k < rr; k++) {
        V[k + V.size(0) * (static_cast<int32_T>(b_j) - 1)] =
            x[k] * V[k + V.size(0) * (static_cast<int32_T>(b_j + 1.0) - 1)];
      }
    }
  }
  st.site = &vk_emlrtRSI;
  internal::qrsolve(&st, V, y, p1_data, &p1_size, &rr);
  if (n >= x.size(0)) {
    if (!emlrtSetWarningFlag((emlrtCTX)sp)) {
      st.site = &wk_emlrtRSI;
      internal::c_warning(&st);
    }
  } else if ((rr <= n) && (!emlrtSetWarningFlag((emlrtCTX)sp))) {
    st.site = &xk_emlrtRSI;
    internal::d_warning(&st);
  }
  p_size[0] = 1;
  p_size[1] = p1_size;
  if (0 <= p1_size - 1) {
    std::copy(&p1_data[0], &p1_data[p1_size], &p_data[0]);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace coder
} // namespace Codegen

// End of code generation (polyfit.cpp)
