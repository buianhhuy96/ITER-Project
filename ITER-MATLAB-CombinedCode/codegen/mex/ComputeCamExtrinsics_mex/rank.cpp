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
#include "ComputeCamExtrinsics_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <cmath>
#include <cstddef>
#include <math.h>

// Variable Definitions
static emlrtRSInfo yx_emlrtRSI{
    20,           // lineNo
    "local_rank", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\rank.m" // pathName
};

static emlrtRSInfo ay_emlrtRSI{
    22,           // lineNo
    "local_rank", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\rank.m" // pathName
};

static emlrtRSInfo by_emlrtRSI{
    31,           // lineNo
    "local_rank", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\rank.m" // pathName
};

static emlrtRSInfo dy_emlrtRSI{
    18,    // lineNo
    "svd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" // pathName
};

static emlrtRSInfo ey_emlrtRSI{
    20,    // lineNo
    "svd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" // pathName
};

static emlrtRSInfo hy_emlrtRSI{
    20,    // lineNo
    "svd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pathName
};

static emlrtRTEInfo jr_emlrtRTEI{
    20,    // lineNo
    9,     // colNo
    "svd", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" // pName
};

static emlrtRTEInfo kr_emlrtRTEI{
    49,    // lineNo
    33,    // colNo
    "svd", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pName
};

static emlrtRTEInfo lr_emlrtRTEI{
    90,       // lineNo
    20,       // colNo
    "xgesvd", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" // pName
};

static emlrtRTEInfo mr_emlrtRTEI{
    123,      // lineNo
    9,        // colNo
    "xgesvd", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" // pName
};

static emlrtRTEInfo nr_emlrtRTEI{
    121,      // lineNo
    33,       // colNo
    "xgesvd", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" // pName
};

// Function Definitions
namespace coder {
int32_T local_rank(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A)
{
  array<real_T, 2U> b_A;
  array<real_T, 1U> s;
  array<real_T, 1U> superb;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
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
    int32_T nx;
    boolean_T p;
    st.site = &yx_emlrtRSI;
    b_st.site = &cy_emlrtRSI;
    c_st.site = &fy_emlrtRSI;
    d_st.site = &gy_emlrtRSI;
    nx = A.size(0) << 3;
    p = true;
    e_st.site = &ae_emlrtRSI;
    if ((1 <= nx) && (nx > 2147483646)) {
      f_st.site = &ed_emlrtRSI;
      check_forloop_overflow_error(&f_st);
    }
    for (k = 0; k < nx; k++) {
      if ((!p) || (muDoubleScalarIsInf(A[k]) || muDoubleScalarIsNaN(A[k]))) {
        p = false;
      }
    }
    nx = static_cast<int32_T>(
        muDoubleScalarMin(static_cast<real_T>(A.size(0)), 8.0));
    if (p) {
      ptrdiff_t info_t;
      b_st.site = &dy_emlrtRSI;
      c_st.site = &hy_emlrtRSI;
      d_st.site = &nu_emlrtRSI;
      b_A.set_size(&kr_emlrtRTEI, &d_st, A.size(0), 8);
      nx = A.size(0) * 8;
      for (k = 0; k < nx; k++) {
        b_A[k] = A[k];
      }
      e_st.site = &pu_emlrtRSI;
      nx = A.size(0);
      nx = muIntScalarMin_sint32(8, nx);
      s.set_size(&lr_emlrtRTEI, &e_st, nx);
      if (nx > 1) {
        superb.set_size(&nr_emlrtRTEI, &e_st, nx - 1);
      } else {
        superb.set_size(&mr_emlrtRTEI, &e_st, 1);
      }
      info_t = LAPACKE_dgesvd(102, 'N', 'N', (ptrdiff_t)A.size(0), (ptrdiff_t)8,
                              &(b_A.data())[0], (ptrdiff_t)A.size(0),
                              &(s.data())[0], nullptr, (ptrdiff_t)1, nullptr,
                              (ptrdiff_t)1, &(superb.data())[0]);
      nx = (int32_T)info_t;
      f_st.site = &ru_emlrtRSI;
      if (nx < 0) {
        if (nx == -1010) {
          emlrtErrorWithMessageIdR2018a(&f_st, &kb_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(
              &f_st, &lb_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
              "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &cv[0], 12, nx);
        }
      }
      if (nx > 0) {
        emlrtErrorWithMessageIdR2018a(&c_st, &yb_emlrtRTEI,
                                      "Coder:MATLAB:svd_NoConvergence",
                                      "Coder:MATLAB:svd_NoConvergence", 0);
      }
    } else {
      b_st.site = &ey_emlrtRSI;
      s.set_size(&jr_emlrtRTEI, &b_st, nx);
      for (k = 0; k < nx; k++) {
        s[k] = rtNaN;
      }
    }
    st.site = &ay_emlrtRSI;
    b_st.site = &te_emlrtRSI;
    absx = muDoubleScalarAbs(s[0]);
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
    st.site = &by_emlrtRSI;
    k = 0;
    while ((k <= s.size(0) - 1) && (s[k] > absx)) {
      irank++;
      k++;
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return irank;
}

} // namespace coder

// End of code generation (rank.cpp)
