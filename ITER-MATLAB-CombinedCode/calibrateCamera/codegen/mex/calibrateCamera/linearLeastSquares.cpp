//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// linearLeastSquares.cpp
//
// Code generation for function 'linearLeastSquares'
//

// Include files
#include "linearLeastSquares.h"
#include "calibrateCamera_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"
#include "validateattributes.h"
#include "xunormqr.h"
#include "blas.h"
#include "coder_array.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <cstddef>

// Variable Definitions
static emlrtRSInfo mab_emlrtRSI{
    1,                    // lineNo
    "linearLeastSquares", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\linearLeastSquares.p" // pathName
};

static emlrtRSInfo nab_emlrtRSI{
    62,      // lineNo
    "xtrsv", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsv."
    "m" // pathName
};

static emlrtRSInfo oab_emlrtRSI{
    75,           // lineNo
    "xtrsv_blas", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsv."
    "m" // pathName
};

static emlrtECInfo ee_emlrtECI{
    -1,                   // nDims
    1,                    // lineNo
    1,                    // colNo
    "linearLeastSquares", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\linearLeastSquares.p" // pName
};

static emlrtBCInfo uv_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    1,                    // lineNo
    1,                    // colNo
    "",                   // aName
    "linearLeastSquares", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\linearLeastSquares.p", // pName
    0                                           // checkKind
};

static emlrtRTEInfo ic_emlrtRTEI{
    18,              // lineNo
    23,              // colNo
    "validatenumel", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatenumel.m" // pName
};

static emlrtRTEInfo dj_emlrtRTEI{
    92,       // lineNo
    22,       // colNo
    "xgeqp3", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pName
};

static emlrtRTEInfo ej_emlrtRTEI{
    105,      // lineNo
    1,        // colNo
    "xgeqp3", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pName
};

static emlrtRTEInfo us_emlrtRTEI{
    1,                    // lineNo
    1,                    // colNo
    "linearLeastSquares", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\linearLeastSquares.p" // pName
};

// Function Definitions
namespace Codegen {
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
void linearLeastSquares(const emlrtStack *sp, ::coder::array<real_T, 2U> &lhs,
                        ::coder::array<real_T, 1U> &rhs,
                        ::coder::array<real_T, 1U> &dx, int32_T m, int32_T n)
{
  ptrdiff_t incx_t;
  ptrdiff_t info_t;
  ptrdiff_t lda_t;
  ::coder::array<ptrdiff_t, 1U> jpvt_t;
  ::coder::array<real_T, 1U> tau;
  ::coder::array<int32_T, 1U> jpvt;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T t3_f2[2];
  int32_T k;
  int32_T ma;
  int32_T minmana;
  int32_T na;
  char_T DIAGA1;
  char_T TRANSA1;
  char_T UPLO1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  t3_f2[0] = m;
  t3_f2[1] = n;
  st.site = &mab_emlrtRSI;
  validateattributes(&st, lhs, t3_f2);
  t3_f2[0] = m;
  t3_f2[1] = 1;
  st.site = &mab_emlrtRSI;
  validateattributes(&st, rhs, t3_f2);
  st.site = &mab_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  if (dx.size(0) != n) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &ic_emlrtRTEI, "Coder:toolbox:ValidateattributesincorrectNumel",
        "MATLAB:incorrectNumel", 5, 4, 5, "input", 12, n);
  }
  jpvt.set_size(&us_emlrtRTEI, sp, n);
  for (k = 0; k < n; k++) {
    jpvt[k] = 0;
  }
  st.site = &mab_emlrtRSI;
  b_st.site = &cl_emlrtRSI;
  ma = lhs.size(0);
  na = lhs.size(1);
  minmana = muIntScalarMin_sint32(ma, na);
  tau.set_size(&dj_emlrtRTEI, &b_st, minmana);
  jpvt_t.set_size(&ej_emlrtRTEI, &b_st, n);
  for (k = 0; k < n; k++) {
    jpvt_t[k] = (ptrdiff_t)0.0;
  }
  info_t = LAPACKE_dgeqp3(102, (ptrdiff_t)m, (ptrdiff_t)n, &(lhs.data())[0],
                          (ptrdiff_t)lhs.size(0), &(jpvt_t.data())[0],
                          &(tau.data())[0]);
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
    if ((1 <= n) && (n > 2147483646)) {
      d_st.site = &qc_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (na = 0; na < n; na++) {
      c_st.site = &hl_emlrtRSI;
      if ((1 <= m) && (m > 2147483646)) {
        d_st.site = &qc_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (k = 0; k < m; k++) {
        lhs[na * ma + k] = rtNaN;
      }
    }
    na = muIntScalarMin_sint32(m, n);
    c_st.site = &gl_emlrtRSI;
    for (k = 0; k < na; k++) {
      tau[k] = rtNaN;
    }
    ma = na + 1;
    c_st.site = &fl_emlrtRSI;
    if ((na + 1 <= minmana) && (minmana > 2147483646)) {
      d_st.site = &qc_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (k = ma; k <= minmana; k++) {
      tau[k - 1] = 0.0;
    }
    c_st.site = &el_emlrtRSI;
    for (k = 0; k < n; k++) {
      jpvt[k] = k + 1;
    }
  } else {
    c_st.site = &dl_emlrtRSI;
    if ((1 <= n) && (n > 2147483646)) {
      d_st.site = &qc_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (k = 0; k < n; k++) {
      jpvt[k] = (int32_T)jpvt_t[k];
    }
  }
  st.site = &mab_emlrtRSI;
  internal::lapack::xunormqr(&st, lhs, rhs, tau);
  k = rhs.size(0);
  if ((n < 1) || (n > k)) {
    emlrtDynamicBoundsCheckR2012b(n, 1, k, &uv_emlrtBCI, (emlrtCTX)sp);
  }
  t3_f2[0] = 1;
  t3_f2[1] = n;
  st.site = &mab_emlrtRSI;
  internal::indexShapeCheck(&st, rhs.size(0), t3_f2);
  st.site = &mab_emlrtRSI;
  tau.set_size(&us_emlrtRTEI, &st, n);
  for (k = 0; k < n; k++) {
    tau[k] = rhs[k];
  }
  b_st.site = &nab_emlrtRSI;
  c_st.site = &oab_emlrtRSI;
  DIAGA1 = 'N';
  TRANSA1 = 'N';
  UPLO1 = 'U';
  info_t = (ptrdiff_t)n;
  lda_t = (ptrdiff_t)m;
  incx_t = (ptrdiff_t)1;
  dtrsv(&UPLO1, &TRANSA1, &DIAGA1, &info_t, &(lhs.data())[0], &lda_t,
        &(tau.data())[0], &incx_t);
  k = dx.size(0);
  if (k != tau.size(0)) {
    emlrtSubAssignSizeCheck1dR2017a(k, tau.size(0), &ee_emlrtECI, (emlrtCTX)sp);
  }
  dx.set_size(&us_emlrtRTEI, sp, tau.size(0));
  na = tau.size(0);
  for (k = 0; k < na; k++) {
    dx[k] = tau[k];
  }
  na = jpvt.size(0);
  for (k = 0; k < na; k++) {
    if ((jpvt[k] < 1) || (jpvt[k] > tau.size(0))) {
      emlrtDynamicBoundsCheckR2012b(jpvt[k], 1, tau.size(0), &uv_emlrtBCI,
                                    (emlrtCTX)sp);
    }
  }
  if (jpvt.size(0) != tau.size(0)) {
    emlrtSubAssignSizeCheck1dR2017a(jpvt.size(0), tau.size(0), &ee_emlrtECI,
                                    (emlrtCTX)sp);
  }
  na = tau.size(0);
  for (k = 0; k < na; k++) {
    dx[jpvt[k] - 1] = tau[k];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace Codegen

// End of code generation (linearLeastSquares.cpp)
