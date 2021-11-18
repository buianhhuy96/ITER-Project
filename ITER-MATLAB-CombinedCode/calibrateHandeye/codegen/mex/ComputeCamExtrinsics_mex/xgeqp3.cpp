//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xgeqp3.cpp
//
// Code generation for function 'xgeqp3'
//

// Include files
#include "xgeqp3.h"
#include "ComputeCamExtrinsics_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <cstddef>

// Variable Definitions
static emlrtRSInfo km_emlrtRSI{
    98,             // lineNo
    "ceval_xgeqp3", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pathName
};

static emlrtRSInfo mm_emlrtRSI{
    141,            // lineNo
    "ceval_xgeqp3", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pathName
};

static emlrtRSInfo qm_emlrtRSI{
    154,            // lineNo
    "ceval_xgeqp3", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pathName
};

static emlrtRSInfo rm_emlrtRSI{
    158,            // lineNo
    "ceval_xgeqp3", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pathName
};

static emlrtDCInfo bh_emlrtDCI{
    61,       // lineNo
    24,       // colNo
    "xgeqp3", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m", // pName
    4                   // checkKind
};

static emlrtDCInfo ch_emlrtDCI{
    61,       // lineNo
    9,        // colNo
    "xgeqp3", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m", // pName
    4                   // checkKind
};

static emlrtDCInfo dh_emlrtDCI{
    92,             // lineNo
    28,             // colNo
    "ceval_xgeqp3", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m", // pName
    4                   // checkKind
};

static emlrtRTEInfo bw_emlrtRTEI{
    61,       // lineNo
    9,        // colNo
    "xgeqp3", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pName
};

static emlrtRTEInfo cw_emlrtRTEI{
    105,      // lineNo
    1,        // colNo
    "xgeqp3", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pName
};

// Function Definitions
namespace coder {
namespace internal {
namespace lapack {
void xgeqp3(const emlrtStack *sp, ::coder::array<real_T, 2U> &A,
            ::coder::array<real_T, 1U> &tau, ::coder::array<int32_T, 2U> &jpvt)
{
  array<ptrdiff_t, 1U> jpvt_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T b_na;
  int32_T i;
  int32_T m;
  int32_T ma;
  int32_T minmana;
  int32_T na;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  m = A.size(0);
  na = A.size(1);
  jpvt.set_size(&bw_emlrtRTEI, sp, 1, jpvt.size(1));
  i = A.size(1);
  if (i < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &bh_emlrtDCI,
                                (emlrtCTX)sp);
  }
  jpvt.set_size(&bw_emlrtRTEI, sp, jpvt.size(0), i);
  b_na = A.size(1);
  if (b_na < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(b_na), &ch_emlrtDCI,
                                (emlrtCTX)sp);
  }
  for (i = 0; i < b_na; i++) {
    jpvt[i] = 0;
  }
  st.site = &jm_emlrtRSI;
  ma = A.size(0);
  b_na = A.size(1);
  minmana = muIntScalarMin_sint32(ma, b_na);
  if (minmana < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(minmana), &dh_emlrtDCI,
                                &st);
  }
  tau.set_size(&ur_emlrtRTEI, &st, minmana);
  if ((A.size(0) == 0) || (A.size(1) == 0) || (A.size(0) < 1) ||
      (A.size(1) < 1)) {
    tau.set_size(&vr_emlrtRTEI, &st, minmana);
    for (i = 0; i < minmana; i++) {
      tau[i] = 0.0;
    }
    b_st.site = &km_emlrtRSI;
    if ((1 <= A.size(1)) && (A.size(1) > 2147483646)) {
      c_st.site = &cd_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (ma = 0; ma < na; ma++) {
      jpvt[ma] = ma + 1;
    }
  } else {
    boolean_T p;
    jpvt_t.set_size(&cw_emlrtRTEI, &st, A.size(1));
    b_na = A.size(1);
    for (i = 0; i < b_na; i++) {
      jpvt_t[i] = (ptrdiff_t)0;
    }
    ptrdiff_t info_t;
    info_t = LAPACKE_dgeqp3(102, (ptrdiff_t)A.size(0), (ptrdiff_t)A.size(1),
                            &(A.data())[0], (ptrdiff_t)A.size(0),
                            &(jpvt_t.data())[0], &(tau.data())[0]);
    b_st.site = &lm_emlrtRSI;
    b_na = (int32_T)info_t;
    if (b_na != 0) {
      p = true;
      if (b_na != -4) {
        if (b_na == -1010) {
          emlrtErrorWithMessageIdR2018a(&b_st, &kb_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(
              &b_st, &lb_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
              "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &cv2[0], 12, b_na);
        }
      }
    } else {
      p = false;
    }
    if (p) {
      b_st.site = &mm_emlrtRSI;
      if ((1 <= na) && (na > 2147483646)) {
        c_st.site = &cd_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (b_na = 0; b_na < na; b_na++) {
        b_st.site = &nm_emlrtRSI;
        if ((1 <= m) && (m > 2147483646)) {
          c_st.site = &cd_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        for (i = 0; i < m; i++) {
          A[b_na * ma + i] = rtNaN;
        }
      }
      b_na = muIntScalarMin_sint32(m, na);
      b_st.site = &om_emlrtRSI;
      if ((1 <= b_na) && (b_na > 2147483646)) {
        c_st.site = &cd_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (ma = 0; ma < b_na; ma++) {
        tau[ma] = rtNaN;
      }
      m = b_na + 1;
      b_st.site = &pm_emlrtRSI;
      if ((b_na + 1 <= minmana) && (minmana > 2147483646)) {
        c_st.site = &cd_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (ma = m; ma <= minmana; ma++) {
        tau[ma - 1] = 0.0;
      }
      b_st.site = &qm_emlrtRSI;
      if ((1 <= na) && (na > 2147483646)) {
        c_st.site = &cd_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (ma = 0; ma < na; ma++) {
        jpvt[ma] = ma + 1;
      }
    } else {
      b_st.site = &rm_emlrtRSI;
      if ((1 <= na) && (na > 2147483646)) {
        c_st.site = &cd_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (ma = 0; ma < na; ma++) {
        jpvt[ma] = (int32_T)jpvt_t[ma];
      }
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace lapack
} // namespace internal
} // namespace coder

// End of code generation (xgeqp3.cpp)
