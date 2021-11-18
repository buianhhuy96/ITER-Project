//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// rank.cpp
//
// Code generation for function 'rank'
//

// Include files
#include "rank.h"
#include "calibrateOneCamera_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <cmath>
#include <cstddef>
#include <math.h>

// Variable Definitions
static emlrtRSInfo rt_emlrtRSI{
    20,           // lineNo
    "local_rank", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\rank.m" // pathName
};

static emlrtRSInfo st_emlrtRSI{
    22,           // lineNo
    "local_rank", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\rank.m" // pathName
};

static emlrtRSInfo tt_emlrtRSI{
    31,           // lineNo
    "local_rank", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\rank.m" // pathName
};

static emlrtRSInfo vt_emlrtRSI{
    18,    // lineNo
    "svd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" // pathName
};

static emlrtRSInfo yt_emlrtRSI{
    20,    // lineNo
    "svd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pathName
};

static emlrtRTEInfo wp_emlrtRTEI{
    31,       // lineNo
    33,       // colNo
    "xgesvd", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" // pName
};

// Function Definitions
namespace Codegen {
namespace coder {
int32_T local_rank(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A)
{
  ::coder::array<real_T, 2U> b_A;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T s_data[8];
  real_T superb_data[7];
  int32_T exponent;
  int32_T irank;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  irank = 0;
  if (A.size(0) != 0) {
    real_T absx;
    int32_T k;
    int32_T minnm;
    int32_T nx;
    boolean_T p;
    st.site = &rt_emlrtRSI;
    b_st.site = &ut_emlrtRSI;
    c_st.site = &wt_emlrtRSI;
    d_st.site = &xt_emlrtRSI;
    nx = A.size(0) << 3;
    p = true;
    e_st.site = &ad_emlrtRSI;
    if ((1 <= nx) && (nx > 2147483646)) {
      f_st.site = &hc_emlrtRSI;
      check_forloop_overflow_error(&f_st);
    }
    for (k = 0; k < nx; k++) {
      if ((!p) || (muDoubleScalarIsInf(A[k]) || muDoubleScalarIsNaN(A[k]))) {
        p = false;
      }
    }
    minnm = static_cast<int32_T>(
        muDoubleScalarMin(static_cast<real_T>(A.size(0)), 8.0));
    if (p) {
      b_st.site = &vt_emlrtRSI;
      c_st.site = &yt_emlrtRSI;
      d_st.site = &au_emlrtRSI;
      e_st.site = &as_emlrtRSI;
      b_A.set_size(&wp_emlrtRTEI, &e_st, A.size(0), 8);
      nx = A.size(0) * 8;
      for (k = 0; k < nx; k++) {
        b_A[k] = A[k];
      }
      ptrdiff_t info_t;
      nx = A.size(0);
      minnm = muIntScalarMin_sint32(8, nx);
      info_t = LAPACKE_dgesvd(102, 'N', 'N', (ptrdiff_t)A.size(0), (ptrdiff_t)8,
                              &(b_A.data())[0], (ptrdiff_t)A.size(0),
                              &s_data[0], nullptr, (ptrdiff_t)1, nullptr,
                              (ptrdiff_t)1, &superb_data[0]);
      nx = (int32_T)info_t;
      f_st.site = &bs_emlrtRSI;
      if (nx < 0) {
        if (nx == -1010) {
          emlrtErrorWithMessageIdR2018a(&f_st, &fb_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(
              &f_st, &gb_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
              "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &cv1[0], 12, nx);
        }
      }
      if (nx > 0) {
        emlrtErrorWithMessageIdR2018a(&c_st, &sb_emlrtRTEI,
                                      "Coder:MATLAB:svd_NoConvergence",
                                      "Coder:MATLAB:svd_NoConvergence", 0);
      }
    } else {
      for (k = 0; k < minnm; k++) {
        s_data[k] = rtNaN;
      }
    }
    st.site = &st_emlrtRSI;
    b_st.site = &td_emlrtRSI;
    absx = muDoubleScalarAbs(s_data[0]);
    if ((!muDoubleScalarIsInf(absx)) && (!muDoubleScalarIsNaN(absx))) {
      if (absx <= 2.2250738585072014E-308) {
        absx = 4.94065645841247E-324;
      } else {
        frexp(absx, &exponent);
        absx = std::ldexp(1.0, exponent - 53);
      }
    } else {
      absx = rtNaN;
    }
    nx = A.size(0);
    absx *= static_cast<real_T>(muIntScalarMax_sint32(nx, 8));
    st.site = &tt_emlrtRSI;
    k = 0;
    while ((k <= minnm - 1) && (s_data[k] > absx)) {
      irank++;
      k++;
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return irank;
}

} // namespace coder
} // namespace Codegen

// End of code generation (rank.cpp)
