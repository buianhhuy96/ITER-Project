//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// qrsolve.cpp
//
// Code generation for function 'qrsolve'
//

// Include files
#include "qrsolve.h"
#include "calibrateCamera_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "xunormqr.h"
#include "coder_array.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo al_emlrtRSI{
    80,        // lineNo
    "qrsolve", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

static emlrtRSInfo kl_emlrtRSI{
    98,             // lineNo
    "ceval_xgeqp3", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pathName
};

static emlrtRSInfo wl_emlrtRSI{
    189,       // lineNo
    "nnzDiag", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

// Function Definitions
namespace Codegen {
namespace coder {
namespace internal {
void qrsolve(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A,
             const ::coder::array<real_T, 1U> &B, real_T Y_data[],
             int32_T *Y_size, int32_T *rankA)
{
  ptrdiff_t jpvt_t_data[5];
  ::coder::array<real_T, 2U> b_A;
  ::coder::array<real_T, 1U> b_B;
  ::coder::array<real_T, 1U> b_tau_data;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T tau_data[5];
  int32_T jpvt_data[5];
  int32_T b_na;
  int32_T i;
  int32_T j;
  int32_T ma;
  int32_T minmana;
  int32_T minmn;
  int32_T na;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &yk_emlrtRSI;
  b_A.set_size(&cj_emlrtRTEI, &st, A.size(0), A.size(1));
  na = A.size(0) * A.size(1);
  for (i = 0; i < na; i++) {
    b_A[i] = A[i];
  }
  minmn = b_A.size(0);
  b_na = b_A.size(1) - 1;
  na = b_A.size(1);
  if (0 <= na - 1) {
    std::memset(&jpvt_data[0], 0, na * sizeof(int32_T));
  }
  b_st.site = &cl_emlrtRSI;
  ma = b_A.size(0);
  na = b_A.size(1);
  minmana = muIntScalarMin_sint32(ma, na);
  if (b_A.size(0) == 0) {
    if (0 <= minmana - 1) {
      std::memset(&tau_data[0], 0, minmana * sizeof(real_T));
    }
    c_st.site = &kl_emlrtRSI;
    for (ma = 0; ma <= b_na; ma++) {
      jpvt_data[ma] = ma + 1;
    }
  } else {
    boolean_T p;
    na = b_A.size(1);
    for (i = 0; i < na; i++) {
      jpvt_t_data[i] = (ptrdiff_t)0;
    }
    ptrdiff_t info_t;
    info_t = LAPACKE_dgeqp3(102, (ptrdiff_t)b_A.size(0), (ptrdiff_t)b_A.size(1),
                            &(b_A.data())[0], (ptrdiff_t)b_A.size(0),
                            &jpvt_t_data[0], &tau_data[0]);
    c_st.site = &jl_emlrtRSI;
    na = (int32_T)info_t;
    if (na != 0) {
      p = true;
      if (na != -4) {
        if (na == -1010) {
          emlrtErrorWithMessageIdR2018a(&c_st, &fb_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(
              &c_st, &gb_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
              "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &cv[0], 12, na);
        }
      }
    } else {
      p = false;
    }
    if (p) {
      c_st.site = &il_emlrtRSI;
      for (j = 0; j <= b_na; j++) {
        c_st.site = &hl_emlrtRSI;
        if ((1 <= minmn) && (minmn > 2147483646)) {
          d_st.site = &qc_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }
        for (na = 0; na < minmn; na++) {
          b_A[j * ma + na] = rtNaN;
        }
      }
      i = b_na + 1;
      minmn = muIntScalarMin_sint32(minmn, i) - 1;
      c_st.site = &gl_emlrtRSI;
      for (ma = 0; ma <= minmn; ma++) {
        tau_data[ma] = rtNaN;
      }
      na = minmn + 2;
      c_st.site = &fl_emlrtRSI;
      if (na <= minmana) {
        std::memset(&tau_data[na + -1], 0,
                    ((minmana - na) + 1) * sizeof(real_T));
      }
      c_st.site = &el_emlrtRSI;
      for (ma = 0; ma <= b_na; ma++) {
        jpvt_data[ma] = ma + 1;
      }
    } else {
      c_st.site = &dl_emlrtRSI;
      for (ma = 0; ma <= b_na; ma++) {
        jpvt_data[ma] = (int32_T)jpvt_t_data[ma];
      }
    }
  }
  *rankA = 0;
  if (b_A.size(0) < b_A.size(1)) {
    minmn = b_A.size(0);
    na = b_A.size(1);
  } else {
    minmn = b_A.size(1);
    na = b_A.size(0);
  }
  if (minmn > 0) {
    real_T tol;
    tol = muDoubleScalarMin(1.4901161193847656E-8,
                            2.2204460492503131E-15 * static_cast<real_T>(na)) *
          muDoubleScalarAbs(b_A[0]);
    while ((*rankA < minmn) &&
           (!(muDoubleScalarAbs(b_A[*rankA + b_A.size(0) * *rankA]) <= tol))) {
      (*rankA)++;
    }
  }
  st.site = &al_emlrtRSI;
  minmn = 0;
  i = b_A.size(0);
  b_na = b_A.size(1);
  na = muIntScalarMin_sint32(i, b_na);
  if (na > 0) {
    b_st.site = &wl_emlrtRSI;
    for (ma = 0; ma < na; ma++) {
      if (b_A[ma + b_A.size(0) * ma] != 0.0) {
        minmn++;
      }
    }
  }
  st.site = &bl_emlrtRSI;
  *Y_size = static_cast<int8_T>(b_A.size(1));
  na = static_cast<int8_T>(b_A.size(1));
  if (0 <= na - 1) {
    std::memset(&Y_data[0], 0, na * sizeof(real_T));
  }
  b_B.set_size(&fj_emlrtRTEI, &st, B.size(0));
  na = B.size(0);
  for (i = 0; i < na; i++) {
    b_B[i] = B[i];
  }
  b_tau_data.set(&tau_data[0], minmana);
  b_st.site = &xl_emlrtRSI;
  lapack::xunormqr(&b_st, b_A, b_B, b_tau_data);
  b_st.site = &yl_emlrtRSI;
  if ((1 <= minmn) && (minmn > 2147483646)) {
    c_st.site = &qc_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (na = 0; na < minmn; na++) {
    Y_data[jpvt_data[na] - 1] = b_B[na];
  }
  for (j = minmn; j >= 1; j--) {
    i = jpvt_data[j - 1];
    Y_data[i - 1] /= b_A[(j + b_A.size(0) * (j - 1)) - 1];
    b_st.site = &am_emlrtRSI;
    for (na = 0; na <= j - 2; na++) {
      Y_data[jpvt_data[na] - 1] -=
          Y_data[jpvt_data[j - 1] - 1] * b_A[na + b_A.size(0) * (j - 1)];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace internal
} // namespace coder
} // namespace Codegen

// End of code generation (qrsolve.cpp)
