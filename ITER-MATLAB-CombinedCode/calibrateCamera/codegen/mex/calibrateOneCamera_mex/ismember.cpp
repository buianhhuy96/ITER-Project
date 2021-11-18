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
#include "calibrateOneCamera_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cmath>
#include <math.h>

// Variable Definitions
static emlrtRSInfo co_emlrtRSI{
    150,              // lineNo
    "local_ismember", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\ismember.m" // pathName
};

static emlrtRSInfo do_emlrtRSI{
    151,              // lineNo
    "local_ismember", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\ismember.m" // pathName
};

static emlrtRSInfo eo_emlrtRSI{
    152,              // lineNo
    "local_ismember", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\ismember.m" // pathName
};

static emlrtRSInfo fo_emlrtRSI{
    161,              // lineNo
    "local_ismember", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\ismember.m" // pathName
};

static emlrtRSInfo go_emlrtRSI{
    168,              // lineNo
    "local_ismember", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\ismember.m" // pathName
};

static emlrtRSInfo ho_emlrtRSI{
    171,              // lineNo
    "local_ismember", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\ismember.m" // pathName
};

static emlrtRSInfo io_emlrtRSI{
    190,              // lineNo
    "local_ismember", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\ismember.m" // pathName
};

static emlrtRTEInfo wk_emlrtRTEI{
    111,        // lineNo
    5,          // colNo
    "ismember", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\ismember.m" // pName
};

// Function Declarations
namespace Codegen {
namespace coder {
static int32_T bsearchni(int32_T k, const ::coder::array<real_T, 2U> &x,
                         const ::coder::array<real_T, 2U> &s);

static int32_T bsearchni(int32_T k, const ::coder::array<real_T, 2U> &x,
                         const ::coder::array<real_T, 1U> &s);

} // namespace coder
} // namespace Codegen

// Function Definitions
namespace Codegen {
namespace coder {
static int32_T bsearchni(int32_T k, const ::coder::array<real_T, 2U> &x,
                         const ::coder::array<real_T, 2U> &s)
{
  real_T b_x;
  int32_T idx;
  int32_T ihi;
  int32_T ilo;
  boolean_T exitg1;
  b_x = x[k - 1];
  ihi = s.size(1);
  idx = 0;
  ilo = 1;
  exitg1 = false;
  while ((!exitg1) && (ihi >= ilo)) {
    int32_T imid;
    imid = ((ilo >> 1) + (ihi >> 1)) - 1;
    if (((ilo & 1) == 1) && ((ihi & 1) == 1)) {
      imid++;
    }
    if (b_x == s[imid]) {
      idx = imid + 1;
      exitg1 = true;
    } else {
      boolean_T p;
      if (muDoubleScalarIsNaN(s[imid])) {
        p = !muDoubleScalarIsNaN(b_x);
      } else if (muDoubleScalarIsNaN(b_x)) {
        p = false;
      } else {
        p = (b_x < s[imid]);
      }
      if (p) {
        ihi = imid;
      } else {
        ilo = imid + 2;
      }
    }
  }
  if (idx > 0) {
    idx--;
    while ((idx > 0) && (b_x == s[idx - 1])) {
      idx--;
    }
    idx++;
  }
  return idx;
}

static int32_T bsearchni(int32_T k, const ::coder::array<real_T, 2U> &x,
                         const ::coder::array<real_T, 1U> &s)
{
  real_T b_x;
  int32_T idx;
  int32_T ihi;
  int32_T ilo;
  boolean_T exitg1;
  b_x = x[k - 1];
  ihi = s.size(0);
  idx = 0;
  ilo = 1;
  exitg1 = false;
  while ((!exitg1) && (ihi >= ilo)) {
    int32_T imid;
    imid = ((ilo >> 1) + (ihi >> 1)) - 1;
    if (((ilo & 1) == 1) && ((ihi & 1) == 1)) {
      imid++;
    }
    if (b_x == s[imid]) {
      idx = imid + 1;
      exitg1 = true;
    } else {
      boolean_T p;
      if (muDoubleScalarIsNaN(s[imid])) {
        p = !muDoubleScalarIsNaN(b_x);
      } else if (muDoubleScalarIsNaN(b_x)) {
        p = false;
      } else {
        p = (b_x < s[imid]);
      }
      if (p) {
        ihi = imid;
      } else {
        ilo = imid + 2;
      }
    }
  }
  if (idx > 0) {
    idx--;
    while ((idx > 0) && (b_x == s[idx - 1])) {
      idx--;
    }
    idx++;
  }
  return idx;
}

void local_ismember(const emlrtStack *sp, const ::coder::array<real_T, 2U> &a,
                    const ::coder::array<real_T, 2U> &s,
                    ::coder::array<boolean_T, 2U> &tf)
{
  ::coder::array<real_T, 1U> ss;
  ::coder::array<int32_T, 1U> sbb_emlrtRSI;
  emlrtStack b_st;
  emlrtStack st;
  real_T absx;
  int32_T exponent;
  int32_T n;
  int32_T na;
  int32_T ns;
  int32_T pmax;
  int32_T pmin;
  boolean_T exitg1;
  boolean_T guard1{false};
  boolean_T y;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  na = a.size(1);
  ns = s.size(1);
  pmax = a.size(1);
  tf.set_size(&wk_emlrtRTEI, sp, 1, a.size(1));
  for (pmin = 0; pmin < pmax; pmin++) {
    tf[pmin] = false;
  }
  guard1 = false;
  if (s.size(1) <= 4) {
    guard1 = true;
  } else {
    pmax = 31;
    pmin = 0;
    exitg1 = false;
    while ((!exitg1) && (pmax - pmin > 1)) {
      int32_T p;
      int32_T pow2p;
      p = (pmin + pmax) >> 1;
      pow2p = 1 << p;
      if (pow2p == ns) {
        pmax = p;
        exitg1 = true;
      } else if (pow2p > ns) {
        pmax = p;
      } else {
        pmin = p;
      }
    }
    if (a.size(1) <= pmax + 4) {
      guard1 = true;
    } else {
      st.site = &fo_emlrtRSI;
      y = true;
      pmax = 0;
      exitg1 = false;
      while ((!exitg1) && (pmax <= s.size(1) - 2)) {
        absx = s[pmax + 1];
        if ((s[pmax] <= absx) || muDoubleScalarIsNaN(absx)) {
          pmax++;
        } else {
          y = false;
          exitg1 = true;
        }
      }
      if (!y) {
        st.site = &go_emlrtRSI;
        ss.set_size(&re_emlrtRTEI, &st, s.size(1));
        pmax = s.size(1);
        for (pmin = 0; pmin < pmax; pmin++) {
          ss[pmin] = s[pmin];
        }
        b_st.site = &ef_emlrtRSI;
        internal::sort(&b_st, ss, sbb_emlrtRSI);
        st.site = &ho_emlrtRSI;
        if ((1 <= a.size(1)) && (a.size(1) > 2147483646)) {
          b_st.site = &hc_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
        pmax = a.size(1) - 1;
        emlrtEnterParallelRegion((emlrtCTX)sp,
                                 static_cast<boolean_T>(omp_in_parallel()));
#pragma omp parallel for num_threads(                                          \
    emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(),    \
                         omp_get_num_procs())) private(n)

        for (int32_T k = 0; k <= pmax; k++) {
          n = bsearchni(k + 1, a, ss);
          if (n > 0) {
            tf[k] = true;
          }
        }
        emlrtExitParallelRegion((emlrtCTX)sp,
                                static_cast<boolean_T>(omp_in_parallel()));
      } else {
        st.site = &io_emlrtRSI;
        if ((1 <= a.size(1)) && (a.size(1) > 2147483646)) {
          b_st.site = &hc_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
        pmax = a.size(1) - 1;
        emlrtEnterParallelRegion((emlrtCTX)sp,
                                 static_cast<boolean_T>(omp_in_parallel()));
#pragma omp parallel for num_threads(                                          \
    emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(),    \
                         omp_get_num_procs())) private(n)

        for (int32_T k = 0; k <= pmax; k++) {
          n = bsearchni(k + 1, a, s);
          if (n > 0) {
            tf[k] = true;
          }
        }
        emlrtExitParallelRegion((emlrtCTX)sp,
                                static_cast<boolean_T>(omp_in_parallel()));
      }
    }
  }
  if (guard1) {
    st.site = &co_emlrtRSI;
    if ((1 <= a.size(1)) && (a.size(1) > 2147483646)) {
      b_st.site = &hc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (pmin = 0; pmin < na; pmin++) {
      st.site = &do_emlrtRSI;
      if ((1 <= ns) && (ns > 2147483646)) {
        b_st.site = &hc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      pmax = 0;
      exitg1 = false;
      while ((!exitg1) && (pmax <= ns - 1)) {
        st.site = &eo_emlrtRSI;
        absx = muDoubleScalarAbs(s[pmax] / 2.0);
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
        if ((muDoubleScalarAbs(s[pmax] - a[pmin]) < absx) ||
            (muDoubleScalarIsInf(a[pmin]) && muDoubleScalarIsInf(s[pmax]) &&
             ((a[pmin] > 0.0) == (s[pmax] > 0.0)))) {
          y = true;
        } else {
          y = false;
        }
        if (y) {
          tf[pmin] = true;
          exitg1 = true;
        } else {
          pmax++;
        }
      }
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace coder
} // namespace Codegen

// End of code generation (ismember.cpp)
