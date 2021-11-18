//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// eml_setop.cpp
//
// Code generation for function 'eml_setop'
//

// Include files
#include "eml_setop.h"
#include "calibrateCamera_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "sortIdx.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cmath>
#include <math.h>

// Variable Definitions
static emlrtRSInfo qm_emlrtRSI{
    203,          // lineNo
    "do_vectors", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" // pathName
};

static emlrtRSInfo rm_emlrtRSI{
    204,          // lineNo
    "do_vectors", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" // pathName
};

static emlrtRSInfo sm_emlrtRSI{
    246,          // lineNo
    "do_vectors", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" // pathName
};

static emlrtRSInfo tm_emlrtRSI{
    247,          // lineNo
    "do_vectors", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" // pathName
};

static emlrtRSInfo um_emlrtRSI{
    252,          // lineNo
    "do_vectors", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" // pathName
};

static emlrtRSInfo vm_emlrtRSI{
    336,          // lineNo
    "do_vectors", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" // pathName
};

static emlrtRSInfo wm_emlrtRSI{
    406,          // lineNo
    "do_vectors", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" // pathName
};

static emlrtRSInfo xm_emlrtRSI{
    407,          // lineNo
    "do_vectors", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" // pathName
};

static emlrtRSInfo cn_emlrtRSI{
    450,                        // lineNo
    "skip_to_last_equal_value", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" // pathName
};

static emlrtRSInfo dn_emlrtRSI{
    40,       // lineNo
    "safeEq", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\safeEq.m" // pathName
};

static emlrtRTEInfo hb_emlrtRTEI{
    421,          // lineNo
    5,            // colNo
    "do_vectors", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" // pName
};

static emlrtRTEInfo ib_emlrtRTEI{
    383,          // lineNo
    5,            // colNo
    "do_vectors", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" // pName
};

static emlrtRTEInfo dk_emlrtRTEI{
    185,         // lineNo
    24,          // colNo
    "eml_setop", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" // pName
};

static emlrtRTEInfo ek_emlrtRTEI{
    192,         // lineNo
    29,          // colNo
    "eml_setop", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" // pName
};

static emlrtRTEInfo fk_emlrtRTEI{
    204,         // lineNo
    9,           // colNo
    "eml_setop", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" // pName
};

static emlrtRTEInfo hk_emlrtRTEI{
    389,         // lineNo
    9,           // colNo
    "eml_setop", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" // pName
};

static emlrtRTEInfo ik_emlrtRTEI{
    423,         // lineNo
    9,           // colNo
    "eml_setop", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" // pName
};

// Function Declarations
namespace Codegen {
namespace coder {
static real_T skip_to_last_equal_value(int32_T *k,
                                       const ::coder::array<real_T, 2U> &x,
                                       const ::coder::array<int32_T, 2U> &perm);

}
} // namespace Codegen

// Function Definitions
namespace Codegen {
namespace coder {
static real_T skip_to_last_equal_value(int32_T *k,
                                       const ::coder::array<real_T, 2U> &x,
                                       const ::coder::array<int32_T, 2U> &perm)
{
  real_T xk;
  int32_T exponent;
  boolean_T exitg1;
  xk = x[perm[*k - 1] - 1];
  exitg1 = false;
  while ((!exitg1) && (*k < x.size(1))) {
    real_T absx;
    real_T d;
    boolean_T p;
    absx = muDoubleScalarAbs(xk / 2.0);
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
    d = x[perm[*k] - 1];
    if ((muDoubleScalarAbs(xk - d) < absx) ||
        (muDoubleScalarIsInf(d) && muDoubleScalarIsInf(xk) &&
         ((d > 0.0) == (xk > 0.0)))) {
      p = true;
    } else {
      p = false;
    }
    if (p) {
      (*k)++;
    } else {
      exitg1 = true;
    }
  }
  return xk;
}

void do_vectors(const emlrtStack *sp, const ::coder::array<real_T, 2U> &a,
                const ::coder::array<real_T, 2U> &b,
                ::coder::array<real_T, 2U> &c, ::coder::array<int32_T, 1U> &ia,
                int32_T *ib_size)
{
  ::coder::array<int32_T, 2U> aperm;
  ::coder::array<int32_T, 2U> bperm;
  ::coder::array<int32_T, 1U> abb_emlrtRSI;
  emlrtStack b_st;
  emlrtStack st;
  int32_T b_ialast;
  int32_T exponent;
  int32_T iafirst;
  int32_T ialast;
  int32_T iblast;
  int32_T na;
  int32_T nc;
  int32_T nia;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  na = a.size(1);
  c.set_size(&dk_emlrtRTEI, sp, 1, a.size(1));
  ia.set_size(&ek_emlrtRTEI, sp, a.size(1));
  *ib_size = 0;
  st.site = &qm_emlrtRSI;
  internal::sortIdx(&st, a, aperm);
  st.site = &rm_emlrtRSI;
  internal::sortIdx(&st, b, bperm);
  nc = 0;
  nia = 0;
  iafirst = 0;
  ialast = 1;
  iblast = 1;
  while ((ialast <= na) && (iblast <= b.size(1))) {
    real_T absx;
    real_T ak;
    real_T bk;
    boolean_T p;
    b_ialast = ialast;
    st.site = &sm_emlrtRSI;
    ak = skip_to_last_equal_value(&b_ialast, a, aperm);
    ialast = b_ialast;
    st.site = &tm_emlrtRSI;
    bk = skip_to_last_equal_value(&iblast, b, bperm);
    st.site = &um_emlrtRSI;
    absx = muDoubleScalarAbs(bk / 2.0);
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
    if ((muDoubleScalarAbs(bk - ak) < absx) ||
        (muDoubleScalarIsInf(ak) && muDoubleScalarIsInf(bk) &&
         ((ak > 0.0) == (bk > 0.0)))) {
      p = true;
    } else {
      p = false;
    }
    if (p) {
      ialast = b_ialast + 1;
      iafirst = b_ialast;
      iblast++;
    } else {
      if (muDoubleScalarIsNaN(bk)) {
        p = !muDoubleScalarIsNaN(ak);
      } else if (muDoubleScalarIsNaN(ak)) {
        p = false;
      } else {
        p = (ak < bk);
      }
      if (p) {
        nc++;
        nia++;
        ia[nia - 1] = aperm[iafirst];
        ialast = b_ialast + 1;
        iafirst = b_ialast;
      } else {
        iblast++;
      }
    }
  }
  while (ialast <= na) {
    iblast = ialast;
    st.site = &vm_emlrtRSI;
    skip_to_last_equal_value(&iblast, a, aperm);
    nc++;
    nia++;
    ia[nia - 1] = aperm[iafirst];
    ialast = iblast + 1;
    iafirst = iblast;
  }
  if (a.size(1) > 0) {
    if (nia > a.size(1)) {
      emlrtErrorWithMessageIdR2018a(sp, &ib_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (1 > nia) {
      na = 0;
    } else {
      na = nia;
    }
    ia.set_size(&hk_emlrtRTEI, sp, na);
  }
  st.site = &wm_emlrtRSI;
  b_st.site = &nf_emlrtRSI;
  internal::sort(&b_st, ia, abb_emlrtRSI);
  st.site = &xm_emlrtRSI;
  if ((1 <= nia) && (nia > 2147483646)) {
    b_st.site = &qc_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (iblast = 0; iblast < nia; iblast++) {
    c[iblast] = a[ia[iblast] - 1];
  }
  if (a.size(1) > 0) {
    if (nc > a.size(1)) {
      emlrtErrorWithMessageIdR2018a(sp, &hb_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (1 > nc) {
      nc = 0;
    }
    c.set_size(&ik_emlrtRTEI, sp, c.size(0), nc);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void do_vectors(const emlrtStack *sp, const ::coder::array<real_T, 2U> &a,
                const ::coder::array<real_T, 1U> &b,
                ::coder::array<real_T, 2U> &c, ::coder::array<int32_T, 1U> &ia,
                int32_T *ib_size)
{
  ::coder::array<int32_T, 2U> aperm;
  ::coder::array<int32_T, 1U> abb_emlrtRSI;
  ::coder::array<int32_T, 1U> bperm;
  ::coder::array<int32_T, 1U> iwork;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T d;
  int32_T b_exponent;
  int32_T b_i;
  int32_T exponent;
  int32_T i;
  int32_T i2;
  int32_T iafirst;
  int32_T ialast;
  int32_T k;
  int32_T n;
  int32_T na;
  int32_T nc;
  int32_T nia;
  int32_T qEnd;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  na = a.size(1);
  c.set_size(&dk_emlrtRTEI, sp, 1, a.size(1));
  ia.set_size(&ek_emlrtRTEI, sp, a.size(1));
  *ib_size = 0;
  st.site = &qm_emlrtRSI;
  internal::sortIdx(&st, a, aperm);
  st.site = &rm_emlrtRSI;
  n = b.size(0) + 1;
  bperm.set_size(&fk_emlrtRTEI, &st, b.size(0));
  i = b.size(0);
  for (b_i = 0; b_i < i; b_i++) {
    bperm[b_i] = 0;
  }
  if (b.size(0) != 0) {
    b_st.site = &ym_emlrtRSI;
    iwork.set_size(&gk_emlrtRTEI, &b_st, b.size(0));
    i = b.size(0) - 1;
    c_st.site = &an_emlrtRSI;
    if ((1 <= b.size(0) - 1) && (b.size(0) - 1 > 2147483645)) {
      d_st.site = &qc_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (k = 1; k <= i; k += 2) {
      if ((b[k - 1] <= b[k]) || muDoubleScalarIsNaN(b[k])) {
        bperm[k - 1] = k;
        bperm[k] = k + 1;
      } else {
        bperm[k - 1] = k + 1;
        bperm[k] = k;
      }
    }
    if ((b.size(0) & 1) != 0) {
      bperm[b.size(0) - 1] = b.size(0);
    }
    i = 2;
    while (i < n - 1) {
      i2 = i << 1;
      iafirst = 1;
      for (ialast = i + 1; ialast < n; ialast = qEnd + i) {
        int32_T kEnd;
        nc = iafirst;
        nia = ialast - 1;
        qEnd = iafirst + i2;
        if (qEnd > n) {
          qEnd = n;
        }
        k = 0;
        kEnd = qEnd - iafirst;
        while (k + 1 <= kEnd) {
          d = b[bperm[nia] - 1];
          b_i = bperm[nc - 1];
          if ((b[b_i - 1] <= d) || muDoubleScalarIsNaN(d)) {
            iwork[k] = b_i;
            nc++;
            if (nc == ialast) {
              while (nia + 1 < qEnd) {
                k++;
                iwork[k] = bperm[nia];
                nia++;
              }
            }
          } else {
            iwork[k] = bperm[nia];
            nia++;
            if (nia + 1 == qEnd) {
              while (nc < ialast) {
                k++;
                iwork[k] = bperm[nc - 1];
                nc++;
              }
            }
          }
          k++;
        }
        c_st.site = &bn_emlrtRSI;
        for (k = 0; k < kEnd; k++) {
          bperm[(iafirst + k) - 1] = iwork[k];
        }
        iafirst = qEnd;
      }
      i = i2;
    }
  }
  nc = 0;
  nia = 0;
  iafirst = 0;
  ialast = 1;
  i = 1;
  while ((ialast <= na) && (i <= b.size(0))) {
    real_T absx;
    real_T ak;
    real_T bk;
    boolean_T exitg1;
    boolean_T p;
    i2 = ialast;
    st.site = &sm_emlrtRSI;
    ak = skip_to_last_equal_value(&i2, a, aperm);
    ialast = i2;
    st.site = &tm_emlrtRSI;
    bk = b[bperm[i - 1] - 1];
    exitg1 = false;
    while ((!exitg1) && (i < b.size(0))) {
      b_st.site = &cn_emlrtRSI;
      c_st.site = &dn_emlrtRSI;
      absx = muDoubleScalarAbs(bk / 2.0);
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
      d = b[bperm[i] - 1];
      if ((muDoubleScalarAbs(bk - d) < absx) ||
          (muDoubleScalarIsInf(d) && muDoubleScalarIsInf(bk) &&
           ((d > 0.0) == (bk > 0.0)))) {
        p = true;
      } else {
        p = false;
      }
      if (p) {
        i++;
      } else {
        exitg1 = true;
      }
    }
    st.site = &um_emlrtRSI;
    b_st.site = &dn_emlrtRSI;
    c_st.site = &de_emlrtRSI;
    absx = muDoubleScalarAbs(bk / 2.0);
    if ((!muDoubleScalarIsInf(absx)) && (!muDoubleScalarIsNaN(absx))) {
      if (absx <= 2.2250738585072014E-308) {
        absx = 4.94065645841247E-324;
      } else {
        frexp(absx, &b_exponent);
        absx = std::ldexp(1.0, b_exponent - 53);
      }
    } else {
      absx = rtNaN;
    }
    if ((muDoubleScalarAbs(bk - ak) < absx) ||
        (muDoubleScalarIsInf(ak) && muDoubleScalarIsInf(bk) &&
         ((ak > 0.0) == (bk > 0.0)))) {
      p = true;
    } else {
      p = false;
    }
    if (p) {
      ialast = i2 + 1;
      iafirst = i2;
      i++;
    } else {
      if (muDoubleScalarIsNaN(bk)) {
        p = !muDoubleScalarIsNaN(ak);
      } else if (muDoubleScalarIsNaN(ak)) {
        p = false;
      } else {
        p = (ak < bk);
      }
      if (p) {
        nc++;
        nia++;
        ia[nia - 1] = aperm[iafirst];
        ialast = i2 + 1;
        iafirst = i2;
      } else {
        i++;
      }
    }
  }
  while (ialast <= na) {
    i = ialast;
    st.site = &vm_emlrtRSI;
    skip_to_last_equal_value(&i, a, aperm);
    nc++;
    nia++;
    ia[nia - 1] = aperm[iafirst];
    ialast = i + 1;
    iafirst = i;
  }
  if (a.size(1) > 0) {
    if (nia > a.size(1)) {
      emlrtErrorWithMessageIdR2018a(sp, &ib_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (1 > nia) {
      b_i = 0;
    } else {
      b_i = nia;
    }
    ia.set_size(&hk_emlrtRTEI, sp, b_i);
  }
  st.site = &wm_emlrtRSI;
  b_st.site = &nf_emlrtRSI;
  internal::sort(&b_st, ia, abb_emlrtRSI);
  st.site = &xm_emlrtRSI;
  if ((1 <= nia) && (nia > 2147483646)) {
    b_st.site = &qc_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (k = 0; k < nia; k++) {
    c[k] = a[ia[k] - 1];
  }
  if (a.size(1) > 0) {
    if (nc > a.size(1)) {
      emlrtErrorWithMessageIdR2018a(sp, &hb_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (1 > nc) {
      nc = 0;
    }
    c.set_size(&ik_emlrtRTEI, sp, c.size(0), nc);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace coder
} // namespace Codegen

// End of code generation (eml_setop.cpp)
