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
#include "ComputeCamExtrinsics_mex_data.h"
#include "qrsolve.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo cm_emlrtRSI{
    32,        // lineNo
    "polyfit", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\polyfun\\polyfit.m" // pathName
};

static emlrtRSInfo dm_emlrtRSI{
    36,        // lineNo
    "polyfit", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\polyfun\\polyfit.m" // pathName
};

static emlrtRSInfo em_emlrtRSI{
    40,        // lineNo
    "polyfit", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\polyfun\\polyfit.m" // pathName
};

static emlrtRSInfo fm_emlrtRSI{
    47,        // lineNo
    "polyfit", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\polyfun\\polyfit.m" // pathName
};

static emlrtRTEInfo ib_emlrtRTEI{
    26,        // lineNo
    23,        // colNo
    "polyfit", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\polyfun\\polyfit.m" // pName
};

static emlrtRTEInfo jb_emlrtRTEI{
    30,       // lineNo
    9,        // colNo
    "vander", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\vander.m" // pName
};

static emlrtDCInfo ob_emlrtDCI{
    17,       // lineNo
    28,       // colNo
    "vander", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\vander.m", // pName
    4 // checkKind
};

static emlrtRTEInfo sj_emlrtRTEI{
    17,       // lineNo
    20,       // colNo
    "vander", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\vander.m" // pName
};

static emlrtRTEInfo tj_emlrtRTEI{
    60,        // lineNo
    1,         // colNo
    "polyfit", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\polyfun\\polyfit.m" // pName
};

// Function Definitions
namespace coder {
void polyfit(const emlrtStack *sp, const ::coder::array<real_T, 1U> &x,
             const ::coder::array<real_T, 1U> &y, real_T n,
             ::coder::array<real_T, 2U> &p)
{
  array<real_T, 2U> V;
  array<real_T, 1U> p1;
  emlrtStack st;
  int32_T b_n;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (x.size(0) != y.size(0)) {
    emlrtErrorWithMessageIdR2018a(sp, &ib_emlrtRTEI,
                                  "MATLAB:polyfit:XYSizeMismatch",
                                  "MATLAB:polyfit:XYSizeMismatch", 0);
  }
  st.site = &cm_emlrtRSI;
  b_n = x.size(0) - 1;
  V.set_size(&sj_emlrtRTEI, &st, x.size(0), V.size(1));
  if (!(n + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(n + 1.0, &ob_emlrtDCI, &st);
  }
  V.set_size(&sj_emlrtRTEI, &st, V.size(0), static_cast<int32_T>(n + 1.0));
  if ((x.size(0) != 0) && (static_cast<int32_T>(n + 1.0) != 0)) {
    int32_T k;
    i = x.size(0);
    for (k = 0; k < i; k++) {
      V[k + V.size(0) * (static_cast<int32_T>(n + 1.0) - 1)] = 1.0;
    }
    if (!(n < 1.0)) {
      i = x.size(0);
      for (k = 0; k < i; k++) {
        V[k + V.size(0) * (static_cast<int32_T>(n) - 1)] = x[k];
      }
      i = static_cast<int32_T>(-((-1.0 - (n - 1.0)) + 1.0));
      emlrtForLoopVectorCheckR2021a(
          n - 1.0, -1.0, 1.0, mxDOUBLE_CLASS,
          static_cast<int32_T>(-((-1.0 - (n - 1.0)) + 1.0)), &jb_emlrtRTEI,
          &st);
      for (int32_T j{0}; j < i; j++) {
        real_T b_j;
        b_j = (n - 1.0) + -static_cast<real_T>(j);
        for (k = 0; k <= b_n; k++) {
          V[k + V.size(0) * (static_cast<int32_T>(b_j) - 1)] =
              x[k] * V[k + V.size(0) * (static_cast<int32_T>(b_j + 1.0) - 1)];
        }
      }
    }
  }
  st.site = &dm_emlrtRSI;
  internal::qrsolve(&st, V, y, p1, &b_n);
  if (n >= x.size(0)) {
    st.site = &em_emlrtRSI;
    internal::b_warning(&st);
  } else if (b_n <= n) {
    st.site = &fm_emlrtRSI;
    internal::c_warning(&st);
  }
  p.set_size(&tj_emlrtRTEI, sp, 1, p1.size(0));
  b_n = p1.size(0);
  for (i = 0; i < b_n; i++) {
    p[i] = p1[i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void polyfit(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x,
             const ::coder::array<real_T, 2U> &y, real_T n,
             ::coder::array<real_T, 2U> &p)
{
  array<real_T, 2U> V;
  array<real_T, 1U> b_y;
  array<real_T, 1U> p1;
  emlrtStack st;
  int32_T b_n;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (x.size(1) != y.size(1)) {
    emlrtErrorWithMessageIdR2018a(sp, &ib_emlrtRTEI,
                                  "MATLAB:polyfit:XYSizeMismatch",
                                  "MATLAB:polyfit:XYSizeMismatch", 0);
  }
  st.site = &cm_emlrtRSI;
  b_n = x.size(1) - 1;
  V.set_size(&sj_emlrtRTEI, &st, x.size(1), V.size(1));
  if (!(n + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(n + 1.0, &ob_emlrtDCI, &st);
  }
  V.set_size(&sj_emlrtRTEI, &st, V.size(0), static_cast<int32_T>(n + 1.0));
  if ((x.size(1) != 0) && (static_cast<int32_T>(n + 1.0) != 0)) {
    int32_T k;
    i = x.size(1);
    for (k = 0; k < i; k++) {
      V[k + V.size(0) * (static_cast<int32_T>(n + 1.0) - 1)] = 1.0;
    }
    if (!(n < 1.0)) {
      i = x.size(1);
      for (k = 0; k < i; k++) {
        V[k + V.size(0) * (static_cast<int32_T>(n) - 1)] = x[k];
      }
      i = static_cast<int32_T>(-((-1.0 - (n - 1.0)) + 1.0));
      emlrtForLoopVectorCheckR2021a(
          n - 1.0, -1.0, 1.0, mxDOUBLE_CLASS,
          static_cast<int32_T>(-((-1.0 - (n - 1.0)) + 1.0)), &jb_emlrtRTEI,
          &st);
      for (int32_T j{0}; j < i; j++) {
        real_T b_j;
        b_j = (n - 1.0) + -static_cast<real_T>(j);
        for (k = 0; k <= b_n; k++) {
          V[k + V.size(0) * (static_cast<int32_T>(b_j) - 1)] =
              x[k] * V[k + V.size(0) * (static_cast<int32_T>(b_j + 1.0) - 1)];
        }
      }
    }
  }
  b_n = y.size(1);
  b_y = y.reshape(b_n);
  st.site = &dm_emlrtRSI;
  internal::qrsolve(&st, V, b_y, p1, &b_n);
  if (n >= x.size(1)) {
    st.site = &em_emlrtRSI;
    internal::b_warning(&st);
  } else if (b_n <= n) {
    st.site = &fm_emlrtRSI;
    internal::c_warning(&st);
  }
  p.set_size(&tj_emlrtRTEI, sp, 1, p1.size(0));
  b_n = p1.size(0);
  for (i = 0; i < b_n; i++) {
    p[i] = p1[i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace coder

// End of code generation (polyfit.cpp)
