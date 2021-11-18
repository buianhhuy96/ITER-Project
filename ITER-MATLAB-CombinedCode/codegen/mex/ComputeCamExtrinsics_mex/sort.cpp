//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sort.cpp
//
// Code generation for function 'sort'
//

// Include files
#include "sort.h"
#include "ComputeCamExtrinsics_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo lg_emlrtRSI{
    76,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pathName
};

static emlrtRSInfo mg_emlrtRSI{
    77,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pathName
};

static emlrtRSInfo ng_emlrtRSI{
    79,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pathName
};

static emlrtRSInfo og_emlrtRSI{
    81,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pathName
};

static emlrtRSInfo pg_emlrtRSI{
    84,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pathName
};

static emlrtRSInfo qg_emlrtRSI{
    87,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pathName
};

static emlrtRSInfo rg_emlrtRSI{
    90,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pathName
};

static emlrtDCInfo sg_emlrtDCI{
    56,     // lineNo
    62,     // colNo
    "sort", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m", // pName
    4 // checkKind
};

static emlrtRTEInfo lv_emlrtRTEI{
    56,     // lineNo
    24,     // colNo
    "sort", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pName
};

static emlrtRTEInfo mv_emlrtRTEI{
    75,     // lineNo
    26,     // colNo
    "sort", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pName
};

// Function Definitions
namespace coder {
namespace internal {
void sort(const emlrtStack *sp, ::coder::array<real32_T, 1U> &x,
          ::coder::array<int32_T, 1U> &idx)
{
  array<int32_T, 1U> iidx;
  array<real32_T, 1U> vwork;
  emlrtStack b_st;
  emlrtStack st;
  int32_T dim;
  int32_T i;
  int32_T k;
  int32_T vlen;
  int32_T vstride;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  dim = 0;
  if (x.size(0) != 1) {
    dim = -1;
  }
  if (dim + 2 <= 1) {
    i = x.size(0);
  } else {
    i = 1;
  }
  vlen = i - 1;
  if (i < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &sg_emlrtDCI,
                                (emlrtCTX)sp);
  }
  vwork.set_size(&lv_emlrtRTEI, sp, i);
  idx.set_size(&mv_emlrtRTEI, sp, x.size(0));
  st.site = &lg_emlrtRSI;
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    vstride *= x.size(0);
  }
  st.site = &mg_emlrtRSI;
  st.site = &ng_emlrtRSI;
  st.site = &og_emlrtRSI;
  if ((1 <= vstride) && (vstride > 2147483646)) {
    b_st.site = &ed_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T j{0}; j < vstride; j++) {
    st.site = &pg_emlrtRSI;
    if ((1 <= i) && (i > 2147483646)) {
      b_st.site = &ed_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (k = 0; k <= vlen; k++) {
      vwork[k] = x[j + k * vstride];
    }
    st.site = &qg_emlrtRSI;
    sortIdx(&st, vwork, iidx);
    st.site = &rg_emlrtRSI;
    if ((1 <= i) && (i > 2147483646)) {
      b_st.site = &ed_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (k = 0; k <= vlen; k++) {
      dim = j + k * vstride;
      x[dim] = vwork[k];
      idx[dim] = iidx[k];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void sort(const emlrtStack *sp, ::coder::array<real_T, 1U> &x,
          ::coder::array<int32_T, 1U> &idx)
{
  array<real_T, 1U> vwork;
  array<int32_T, 1U> iidx;
  emlrtStack b_st;
  emlrtStack st;
  int32_T dim;
  int32_T i;
  int32_T k;
  int32_T vlen;
  int32_T vstride;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  dim = 0;
  if (x.size(0) != 1) {
    dim = -1;
  }
  if (dim + 2 <= 1) {
    i = x.size(0);
  } else {
    i = 1;
  }
  vlen = i - 1;
  if (i < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &sg_emlrtDCI,
                                (emlrtCTX)sp);
  }
  vwork.set_size(&lv_emlrtRTEI, sp, i);
  idx.set_size(&mv_emlrtRTEI, sp, x.size(0));
  st.site = &lg_emlrtRSI;
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    vstride *= x.size(0);
  }
  st.site = &mg_emlrtRSI;
  st.site = &ng_emlrtRSI;
  st.site = &og_emlrtRSI;
  if ((1 <= vstride) && (vstride > 2147483646)) {
    b_st.site = &ed_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T j{0}; j < vstride; j++) {
    st.site = &pg_emlrtRSI;
    if ((1 <= i) && (i > 2147483646)) {
      b_st.site = &ed_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (k = 0; k <= vlen; k++) {
      vwork[k] = x[j + k * vstride];
    }
    st.site = &qg_emlrtRSI;
    sortIdx(&st, vwork, iidx);
    st.site = &rg_emlrtRSI;
    if ((1 <= i) && (i > 2147483646)) {
      b_st.site = &ed_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (k = 0; k <= vlen; k++) {
      dim = j + k * vstride;
      x[dim] = vwork[k];
      idx[dim] = iidx[k];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void sort(const emlrtStack *sp, ::coder::array<int32_T, 1U> &x,
          ::coder::array<int32_T, 1U> &idx)
{
  array<int32_T, 1U> iidx;
  array<int32_T, 1U> vwork;
  emlrtStack b_st;
  emlrtStack st;
  int32_T dim;
  int32_T i;
  int32_T k;
  int32_T vlen;
  int32_T vstride;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  dim = 0;
  if (x.size(0) != 1) {
    dim = -1;
  }
  if (dim + 2 <= 1) {
    i = x.size(0);
  } else {
    i = 1;
  }
  vlen = i - 1;
  if (i < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &sg_emlrtDCI,
                                (emlrtCTX)sp);
  }
  vwork.set_size(&lv_emlrtRTEI, sp, i);
  idx.set_size(&mv_emlrtRTEI, sp, x.size(0));
  st.site = &lg_emlrtRSI;
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    vstride *= x.size(0);
  }
  st.site = &mg_emlrtRSI;
  st.site = &ng_emlrtRSI;
  st.site = &og_emlrtRSI;
  if ((1 <= vstride) && (vstride > 2147483646)) {
    b_st.site = &ed_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T j{0}; j < vstride; j++) {
    st.site = &pg_emlrtRSI;
    if ((1 <= i) && (i > 2147483646)) {
      b_st.site = &ed_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (k = 0; k <= vlen; k++) {
      vwork[k] = x[j + k * vstride];
    }
    st.site = &qg_emlrtRSI;
    sortIdx(&st, vwork, iidx);
    st.site = &rg_emlrtRSI;
    if ((1 <= i) && (i > 2147483646)) {
      b_st.site = &ed_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (k = 0; k <= vlen; k++) {
      dim = j + k * vstride;
      x[dim] = vwork[k];
      idx[dim] = iidx[k];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void sort(real_T x[4])
{
  real_T x4[4];
  real_T xwork[4];
  int32_T i2;
  int32_T i3;
  int32_T ib;
  int32_T nNaNs;
  int8_T perm[4];
  x4[0] = 0.0;
  xwork[0] = 0.0;
  x4[1] = 0.0;
  xwork[1] = 0.0;
  x4[2] = 0.0;
  xwork[2] = 0.0;
  x4[3] = 0.0;
  xwork[3] = 0.0;
  nNaNs = 0;
  ib = 0;
  if (muDoubleScalarIsNaN(x[0])) {
    xwork[3] = x[0];
    nNaNs = 1;
  } else {
    ib = 1;
    x4[0] = x[0];
  }
  if (muDoubleScalarIsNaN(x[1])) {
    xwork[3 - nNaNs] = x[1];
    nNaNs++;
  } else {
    ib++;
    x4[ib - 1] = x[1];
  }
  if (muDoubleScalarIsNaN(x[2])) {
    xwork[3 - nNaNs] = x[2];
    nNaNs++;
  } else {
    ib++;
    x4[ib - 1] = x[2];
  }
  if (muDoubleScalarIsNaN(x[3])) {
    xwork[3 - nNaNs] = x[3];
    nNaNs++;
  } else {
    ib++;
    x4[ib - 1] = x[3];
    if (ib == 4) {
      real_T d;
      real_T d1;
      int32_T i4;
      if (x4[0] <= x4[1]) {
        ib = 1;
        i2 = 2;
      } else {
        ib = 2;
        i2 = 1;
      }
      if (x4[2] <= x4[3]) {
        i3 = 3;
        i4 = 4;
      } else {
        i3 = 4;
        i4 = 3;
      }
      d = x4[ib - 1];
      d1 = x4[i3 - 1];
      if (d <= d1) {
        d = x4[i2 - 1];
        if (d <= d1) {
          perm[0] = static_cast<int8_T>(ib);
          perm[1] = static_cast<int8_T>(i2);
          perm[2] = static_cast<int8_T>(i3);
          perm[3] = static_cast<int8_T>(i4);
        } else if (d <= x4[i4 - 1]) {
          perm[0] = static_cast<int8_T>(ib);
          perm[1] = static_cast<int8_T>(i3);
          perm[2] = static_cast<int8_T>(i2);
          perm[3] = static_cast<int8_T>(i4);
        } else {
          perm[0] = static_cast<int8_T>(ib);
          perm[1] = static_cast<int8_T>(i3);
          perm[2] = static_cast<int8_T>(i4);
          perm[3] = static_cast<int8_T>(i2);
        }
      } else {
        d1 = x4[i4 - 1];
        if (d <= d1) {
          if (x4[i2 - 1] <= d1) {
            perm[0] = static_cast<int8_T>(i3);
            perm[1] = static_cast<int8_T>(ib);
            perm[2] = static_cast<int8_T>(i2);
            perm[3] = static_cast<int8_T>(i4);
          } else {
            perm[0] = static_cast<int8_T>(i3);
            perm[1] = static_cast<int8_T>(ib);
            perm[2] = static_cast<int8_T>(i4);
            perm[3] = static_cast<int8_T>(i2);
          }
        } else {
          perm[0] = static_cast<int8_T>(i3);
          perm[1] = static_cast<int8_T>(i4);
          perm[2] = static_cast<int8_T>(ib);
          perm[3] = static_cast<int8_T>(i2);
        }
      }
      x[-nNaNs] = x4[perm[0] - 1];
      x[1 - nNaNs] = x4[perm[1] - 1];
      x[2 - nNaNs] = x4[perm[2] - 1];
      x[3 - nNaNs] = x4[perm[3] - 1];
      ib = 0;
    }
  }
  if (ib > 0) {
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    if (ib == 1) {
      perm[0] = 1;
    } else if (ib == 2) {
      if (x4[0] <= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
    } else if (x4[0] <= x4[1]) {
      if (x4[1] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 2;
        perm[2] = 3;
      } else if (x4[0] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 3;
        perm[2] = 2;
      } else {
        perm[0] = 3;
        perm[1] = 1;
        perm[2] = 2;
      }
    } else if (x4[0] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 1;
      perm[2] = 3;
    } else if (x4[1] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 3;
      perm[2] = 1;
    } else {
      perm[0] = 3;
      perm[1] = 2;
      perm[2] = 1;
    }
    for (i3 = 0; i3 < ib; i3++) {
      x[((i3 - nNaNs) - ib) + 4] = x4[perm[i3] - 1];
    }
  }
  ib = (nNaNs >> 1) + 4;
  for (i3 = 0; i3 <= ib - 5; i3++) {
    i2 = (i3 - nNaNs) + 4;
    x[i2] = xwork[3 - i3];
    x[3 - i3] = xwork[i2];
  }
  if ((nNaNs & 1) != 0) {
    ib -= nNaNs;
    x[ib] = xwork[ib];
  }
}

} // namespace internal
} // namespace coder

// End of code generation (sort.cpp)
