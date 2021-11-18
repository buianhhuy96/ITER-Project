//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// ismember.cpp
//
// Code generation for function 'ismember'
//

// Include files
#include "ismember.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cmath>
#include <math.h>

// Variable Definitions
static emlrtRSInfo up_emlrtRSI{
    135,              // lineNo
    "local_ismember", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\ismember.m" // pathName
};

static emlrtRSInfo vp_emlrtRSI{
    150,              // lineNo
    "local_ismember", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\ismember.m" // pathName
};

static emlrtRSInfo wp_emlrtRSI{
    151,              // lineNo
    "local_ismember", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\ismember.m" // pathName
};

static emlrtRSInfo xp_emlrtRSI{
    152,              // lineNo
    "local_ismember", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\ismember.m" // pathName
};

static emlrtRSInfo yp_emlrtRSI{
    161,              // lineNo
    "local_ismember", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\ismember.m" // pathName
};

static emlrtRSInfo aq_emlrtRSI{
    168,              // lineNo
    "local_ismember", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\ismember.m" // pathName
};

static emlrtRSInfo bq_emlrtRSI{
    179,              // lineNo
    "local_ismember", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\ismember.m" // pathName
};

static emlrtRSInfo cq_emlrtRSI{
    180,              // lineNo
    "local_ismember", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\ismember.m" // pathName
};

static emlrtRSInfo dq_emlrtRSI{
    198,              // lineNo
    "local_ismember", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\ismember.m" // pathName
};

static emlrtRSInfo eq_emlrtRSI{
    199,              // lineNo
    "local_ismember", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\ismember.m" // pathName
};

static emlrtRSInfo fq_emlrtRSI{
    11,         // lineNo
    "nextpow2", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elfun\\nextpow2.m" // pathName
};

static emlrtRSInfo gq_emlrtRSI{
    17,                           // lineNo
    "applyScalarFunctionInPlace", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyScalarFunctionInPlace.m" // pathName
};

static emlrtRSInfo hq_emlrtRSI{
    9,          // lineNo
    "nextpow2", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "scalar\\nextpow2.m" // pathName
};

static emlrtRSInfo iq_emlrtRSI{
    74,         // lineNo
    "issorted", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\issorted.m" // pathName
};

static emlrtRSInfo jq_emlrtRSI{
    95,       // lineNo
    "looper", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\issorted.m" // pathName
};

static emlrtRSInfo kq_emlrtRSI{
    112,      // lineNo
    "looper", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\issorted.m" // pathName
};

static emlrtRTEInfo yl_emlrtRTEI{
    111,        // lineNo
    5,          // colNo
    "ismember", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\ismember.m" // pName
};

// Function Definitions
namespace coder {
void local_ismember(const emlrtStack *sp, const ::coder::array<real_T, 2U> &a,
                    const ::coder::array<real_T, 2U> &s,
                    ::coder::array<boolean_T, 2U> &tf)
{
  array<real_T, 1U> b_s;
  array<real_T, 1U> ss;
  array<int32_T, 1U> kjb_emlrtRSI;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T absx;
  int32_T subs[2];
  int32_T exponent;
  int32_T imid;
  int32_T na;
  int32_T ns;
  int32_T pmax;
  int32_T pow2p;
  boolean_T exitg1;
  boolean_T guard1{false};
  boolean_T y;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  na = a.size(1) - 1;
  ns = s.size(1);
  tf.set_size(&yl_emlrtRTEI, sp, 1, a.size(1));
  pmax = a.size(1);
  for (imid = 0; imid < pmax; imid++) {
    tf[imid] = false;
  }
  guard1 = false;
  if (s.size(1) <= 4) {
    guard1 = true;
  } else {
    int32_T n;
    int32_T pmin;
    st.site = &up_emlrtRSI;
    n = s.size(1);
    b_st.site = &fq_emlrtRSI;
    c_st.site = &gq_emlrtRSI;
    d_st.site = &hq_emlrtRSI;
    pmax = 31;
    pmin = 0;
    exitg1 = false;
    while ((!exitg1) && (pmax - pmin > 1)) {
      imid = (pmin + pmax) >> 1;
      pow2p = 1 << imid;
      if (pow2p == n) {
        pmax = imid;
        exitg1 = true;
      } else if (pow2p > n) {
        pmax = imid;
      } else {
        pmin = imid;
      }
    }
    if (a.size(1) <= pmax + 4) {
      guard1 = true;
    } else {
      pmax = s.size(1);
      b_s = s.reshape(pmax);
      st.site = &yp_emlrtRSI;
      y = true;
      pmax = 2;
      if (b_s.size(0) != 1) {
        pmax = 1;
      }
      if (b_s.size(0) != 0) {
        if (pmax <= 1) {
          ns = b_s.size(0);
        } else {
          ns = 1;
        }
        if (ns != 1) {
          b_st.site = &iq_emlrtRSI;
          if (pmax == 2) {
            n = -1;
          } else {
            n = 0;
          }
          c_st.site = &jq_emlrtRSI;
          pow2p = 0;
          exitg1 = false;
          while ((!exitg1) && (pow2p <= n)) {
            boolean_T exitg2;
            c_st.site = &kq_emlrtRSI;
            if (pmax == 1) {
              pmin = b_s.size(0) - 1;
            } else {
              pmin = b_s.size(0);
            }
            d_st.site = &jq_emlrtRSI;
            if ((1 <= pmin) && (pmin > 2147483646)) {
              e_st.site = &yc_emlrtRSI;
              check_forloop_overflow_error(&e_st);
            }
            pow2p = 0;
            exitg2 = false;
            while ((!exitg2) && (pow2p <= pmin - 1)) {
              subs[0] = pow2p + 1;
              subs[1] = 1;
              subs[pmax - 1]++;
              absx = b_s[subs[0] - 1];
              if ((b_s[pow2p] <= absx) || muDoubleScalarIsNaN(absx)) {
                y = true;
              } else {
                y = false;
              }
              if (!y) {
                exitg2 = true;
              } else {
                pow2p++;
              }
            }
            if (!y) {
              exitg1 = true;
            } else {
              pow2p = 1;
            }
          }
        }
      }
      if (!y) {
        st.site = &aq_emlrtRSI;
        ss.set_size(&rf_emlrtRTEI, &st, s.size(1));
        pmax = s.size(1);
        for (imid = 0; imid < pmax; imid++) {
          ss[imid] = s[imid];
        }
        b_st.site = &gg_emlrtRSI;
        internal::sort(&b_st, ss, kjb_emlrtRSI);
        st.site = &bq_emlrtRSI;
        if (a.size(1) > 2147483646) {
          b_st.site = &yc_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
        for (pow2p = 0; pow2p <= na; pow2p++) {
          st.site = &cq_emlrtRSI;
          absx = a[pow2p];
          pmax = ss.size(0);
          n = -1;
          pmin = 1;
          exitg1 = false;
          while ((!exitg1) && (pmax >= pmin)) {
            imid = ((pmin >> 1) + (pmax >> 1)) - 1;
            if (((pmin & 1) == 1) && ((pmax & 1) == 1)) {
              imid++;
            }
            if (absx == ss[imid]) {
              n = imid;
              exitg1 = true;
            } else {
              if (muDoubleScalarIsNaN(ss[imid])) {
                y = !muDoubleScalarIsNaN(absx);
              } else if (muDoubleScalarIsNaN(absx)) {
                y = false;
              } else {
                y = (absx < ss[imid]);
              }
              if (y) {
                pmax = imid;
              } else {
                pmin = imid + 2;
              }
            }
          }
          if (n + 1 > 0) {
            while ((n > 0) && (absx == ss[n - 1])) {
              n--;
            }
          }
          if (n + 1 > 0) {
            tf[pow2p] = true;
          }
        }
      } else {
        st.site = &dq_emlrtRSI;
        if (a.size(1) > 2147483646) {
          b_st.site = &yc_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
        for (pow2p = 0; pow2p <= na; pow2p++) {
          st.site = &eq_emlrtRSI;
          absx = a[pow2p];
          pmax = s.size(1);
          n = -1;
          pmin = 1;
          exitg1 = false;
          while ((!exitg1) && (pmax >= pmin)) {
            imid = ((pmin >> 1) + (pmax >> 1)) - 1;
            if (((pmin & 1) == 1) && ((pmax & 1) == 1)) {
              imid++;
            }
            if (absx == s[imid]) {
              n = imid;
              exitg1 = true;
            } else {
              if (muDoubleScalarIsNaN(s[imid])) {
                y = !muDoubleScalarIsNaN(absx);
              } else if (muDoubleScalarIsNaN(absx)) {
                y = false;
              } else {
                y = (absx < s[imid]);
              }
              if (y) {
                pmax = imid;
              } else {
                pmin = imid + 2;
              }
            }
          }
          if (n + 1 > 0) {
            while ((n > 0) && (absx == s[n - 1])) {
              n--;
            }
          }
          if (n + 1 > 0) {
            tf[pow2p] = true;
          }
        }
      }
    }
  }
  if (guard1) {
    st.site = &vp_emlrtRSI;
    if ((1 <= a.size(1)) && (a.size(1) > 2147483646)) {
      b_st.site = &yc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (imid = 0; imid <= na; imid++) {
      st.site = &wp_emlrtRSI;
      if ((1 <= ns) && (ns > 2147483646)) {
        b_st.site = &yc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      pow2p = 0;
      exitg1 = false;
      while ((!exitg1) && (pow2p <= ns - 1)) {
        st.site = &xp_emlrtRSI;
        b_st.site = &mo_emlrtRSI;
        c_st.site = &pe_emlrtRSI;
        absx = muDoubleScalarAbs(s[pow2p] / 2.0);
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
        if ((muDoubleScalarAbs(s[pow2p] - a[imid]) < absx) ||
            (muDoubleScalarIsInf(a[imid]) && muDoubleScalarIsInf(s[pow2p]) &&
             ((a[imid] > 0.0) == (s[pow2p] > 0.0)))) {
          y = true;
        } else {
          y = false;
        }
        if (y) {
          tf[imid] = true;
          exitg1 = true;
        } else {
          pow2p++;
        }
      }
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace coder

// End of code generation (ismember.cpp)
