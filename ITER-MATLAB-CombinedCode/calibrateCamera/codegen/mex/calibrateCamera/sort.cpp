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
#include "calibrateCamera_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo of_emlrtRSI{
    76,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pathName
};

static emlrtRSInfo pf_emlrtRSI{
    79,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pathName
};

static emlrtRSInfo qf_emlrtRSI{
    81,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pathName
};

static emlrtRSInfo rf_emlrtRSI{
    84,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pathName
};

static emlrtRSInfo sf_emlrtRSI{
    87,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pathName
};

static emlrtRSInfo tf_emlrtRSI{
    90,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pathName
};

static emlrtRSInfo en_emlrtRSI{
    443,                      // lineNo
    "initialize_vector_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo fn_emlrtRSI{
    468,                      // lineNo
    "initialize_vector_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo gn_emlrtRSI{
    473,                      // lineNo
    "initialize_vector_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRTEInfo gs_emlrtRTEI{
    56,     // lineNo
    24,     // colNo
    "sort", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pName
};

static emlrtRTEInfo hs_emlrtRTEI{
    75,     // lineNo
    26,     // colNo
    "sort", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pName
};

// Function Definitions
namespace Codegen {
namespace coder {
namespace internal {
void sort(const emlrtStack *sp, ::coder::array<real32_T, 1U> &x,
          ::coder::array<int32_T, 1U> &idx)
{
  ::coder::array<int32_T, 1U> iidx;
  ::coder::array<real32_T, 1U> vwork;
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
  vwork.set_size(&gs_emlrtRTEI, sp, i);
  idx.set_size(&hs_emlrtRTEI, sp, x.size(0));
  st.site = &of_emlrtRSI;
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    vstride *= x.size(0);
  }
  st.site = &pf_emlrtRSI;
  st.site = &qf_emlrtRSI;
  if ((1 <= vstride) && (vstride > 2147483646)) {
    b_st.site = &qc_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T j{0}; j < vstride; j++) {
    st.site = &rf_emlrtRSI;
    if ((1 <= i) && (i > 2147483646)) {
      b_st.site = &qc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (k = 0; k <= vlen; k++) {
      vwork[k] = x[j + k * vstride];
    }
    st.site = &sf_emlrtRSI;
    sortIdx(&st, vwork, iidx);
    st.site = &tf_emlrtRSI;
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
  ::coder::array<real_T, 1U> vwork;
  ::coder::array<int32_T, 1U> iidx;
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
  vwork.set_size(&gs_emlrtRTEI, sp, i);
  idx.set_size(&hs_emlrtRTEI, sp, x.size(0));
  st.site = &of_emlrtRSI;
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    vstride *= x.size(0);
  }
  st.site = &pf_emlrtRSI;
  st.site = &qf_emlrtRSI;
  if ((1 <= vstride) && (vstride > 2147483646)) {
    b_st.site = &qc_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T j{0}; j < vstride; j++) {
    st.site = &rf_emlrtRSI;
    if ((1 <= i) && (i > 2147483646)) {
      b_st.site = &qc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (k = 0; k <= vlen; k++) {
      vwork[k] = x[j + k * vstride];
    }
    st.site = &sf_emlrtRSI;
    sortIdx(&st, vwork, iidx);
    st.site = &tf_emlrtRSI;
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
  ::coder::array<int32_T, 1U> iidx;
  ::coder::array<int32_T, 1U> iwork;
  ::coder::array<int32_T, 1U> vwork;
  ::coder::array<int32_T, 1U> xwork;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T idx4[4];
  int32_T x4[4];
  int32_T dim;
  int32_T i;
  int32_T i2;
  int32_T vlen;
  int32_T vstride;
  int8_T perm[4];
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
  vwork.set_size(&gs_emlrtRTEI, sp, i);
  idx.set_size(&hs_emlrtRTEI, sp, x.size(0));
  st.site = &of_emlrtRSI;
  vstride = 1;
  b_st.site = &uf_emlrtRSI;
  for (i2 = 0; i2 <= dim; i2++) {
    vstride *= x.size(0);
  }
  st.site = &pf_emlrtRSI;
  st.site = &qf_emlrtRSI;
  if ((1 <= vstride) && (vstride > 2147483646)) {
    b_st.site = &qc_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T j{0}; j < vstride; j++) {
    int32_T i1;
    st.site = &rf_emlrtRSI;
    if ((1 <= i) && (i > 2147483646)) {
      b_st.site = &qc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (i2 = 0; i2 <= vlen; i2++) {
      vwork[i2] = x[j + i2 * vstride];
    }
    st.site = &sf_emlrtRSI;
    emlrtHeapReferenceStackEnterFcnR2012b(&st);
    dim = vwork.size(0);
    iidx.set_size(&is_emlrtRTEI, &st, dim);
    for (i1 = 0; i1 < dim; i1++) {
      iidx[i1] = 0;
    }
    if (vwork.size(0) != 0) {
      int32_T b_i1;
      int32_T b_n;
      int32_T i4;
      int32_T n;
      int32_T nLeft;
      int32_T nQuartets;
      b_st.site = &vf_emlrtRSI;
      n = vwork.size(0);
      c_st.site = &wf_emlrtRSI;
      b_n = vwork.size(0) - 1;
      x4[0] = 0;
      idx4[0] = 0;
      x4[1] = 0;
      idx4[1] = 0;
      x4[2] = 0;
      idx4[2] = 0;
      x4[3] = 0;
      idx4[3] = 0;
      iwork.set_size(&js_emlrtRTEI, &c_st, dim);
      for (i1 = 0; i1 < dim; i1++) {
        iwork[i1] = 0;
      }
      dim = vwork.size(0);
      xwork.set_size(&ks_emlrtRTEI, &c_st, dim);
      for (i1 = 0; i1 < dim; i1++) {
        xwork[i1] = 0;
      }
      nQuartets = vwork.size(0) >> 2;
      d_st.site = &en_emlrtRSI;
      for (int32_T b_j{0}; b_j < nQuartets; b_j++) {
        int32_T b_i;
        b_i = b_j << 2;
        idx4[0] = b_i + 1;
        idx4[1] = b_i + 2;
        idx4[2] = b_i + 3;
        idx4[3] = b_i + 4;
        x4[0] = vwork[b_i];
        dim = vwork[b_i + 1];
        x4[1] = dim;
        i4 = vwork[b_i + 2];
        x4[2] = i4;
        nLeft = vwork[b_i + 3];
        x4[3] = nLeft;
        if (vwork[b_i] <= dim) {
          b_i1 = 1;
          i2 = 2;
        } else {
          b_i1 = 2;
          i2 = 1;
        }
        if (i4 <= nLeft) {
          dim = 3;
          i4 = 4;
        } else {
          dim = 4;
          i4 = 3;
        }
        i1 = x4[b_i1 - 1];
        nLeft = x4[dim - 1];
        if (i1 <= nLeft) {
          i1 = x4[i2 - 1];
          if (i1 <= nLeft) {
            perm[0] = static_cast<int8_T>(b_i1);
            perm[1] = static_cast<int8_T>(i2);
            perm[2] = static_cast<int8_T>(dim);
            perm[3] = static_cast<int8_T>(i4);
          } else if (i1 <= x4[i4 - 1]) {
            perm[0] = static_cast<int8_T>(b_i1);
            perm[1] = static_cast<int8_T>(dim);
            perm[2] = static_cast<int8_T>(i2);
            perm[3] = static_cast<int8_T>(i4);
          } else {
            perm[0] = static_cast<int8_T>(b_i1);
            perm[1] = static_cast<int8_T>(dim);
            perm[2] = static_cast<int8_T>(i4);
            perm[3] = static_cast<int8_T>(i2);
          }
        } else {
          nLeft = x4[i4 - 1];
          if (i1 <= nLeft) {
            if (x4[i2 - 1] <= nLeft) {
              perm[0] = static_cast<int8_T>(dim);
              perm[1] = static_cast<int8_T>(b_i1);
              perm[2] = static_cast<int8_T>(i2);
              perm[3] = static_cast<int8_T>(i4);
            } else {
              perm[0] = static_cast<int8_T>(dim);
              perm[1] = static_cast<int8_T>(b_i1);
              perm[2] = static_cast<int8_T>(i4);
              perm[3] = static_cast<int8_T>(i2);
            }
          } else {
            perm[0] = static_cast<int8_T>(dim);
            perm[1] = static_cast<int8_T>(i4);
            perm[2] = static_cast<int8_T>(b_i1);
            perm[3] = static_cast<int8_T>(i2);
          }
        }
        iidx[b_i] = idx4[perm[0] - 1];
        iidx[b_i + 1] = idx4[perm[1] - 1];
        iidx[b_i + 2] = idx4[perm[2] - 1];
        iidx[b_i + 3] = idx4[perm[3] - 1];
        vwork[b_i] = x4[perm[0] - 1];
        vwork[b_i + 1] = x4[perm[1] - 1];
        vwork[b_i + 2] = x4[perm[2] - 1];
        vwork[b_i + 3] = x4[perm[3] - 1];
      }
      b_i1 = nQuartets << 2;
      nLeft = (b_n - b_i1) + 1;
      if (nLeft > 0) {
        d_st.site = &fn_emlrtRSI;
        if (nLeft > 2147483646) {
          e_st.site = &qc_emlrtRSI;
          check_forloop_overflow_error(&e_st);
        }
        for (i2 = 0; i2 < nLeft; i2++) {
          dim = b_i1 + i2;
          idx4[i2] = dim + 1;
          x4[i2] = vwork[dim];
        }
        perm[1] = 0;
        perm[2] = 0;
        perm[3] = 0;
        if (nLeft == 1) {
          perm[0] = 1;
        } else if (nLeft == 2) {
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
        d_st.site = &gn_emlrtRSI;
        for (i2 = 0; i2 < nLeft; i2++) {
          dim = perm[i2] - 1;
          i4 = b_i1 + i2;
          iidx[i4] = idx4[dim];
          vwork[i4] = x4[dim];
        }
      }
      dim = 2;
      if (n > 1) {
        if (n >= 256) {
          dim = n >> 8;
          c_st.site = &xf_emlrtRSI;
          for (i4 = 0; i4 < dim; i4++) {
            c_st.site = &yf_emlrtRSI;
            merge_pow2_block(iidx, vwork, i4 << 8);
          }
          dim <<= 8;
          i4 = n - dim;
          if (i4 > 0) {
            c_st.site = &ag_emlrtRSI;
            merge_block(&c_st, iidx, vwork, dim, i4, 2, iwork, xwork);
          }
          dim = 8;
        }
        c_st.site = &bg_emlrtRSI;
        merge_block(&c_st, iidx, vwork, 0, n, dim, iwork, xwork);
      }
    }
    emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
    st.site = &tf_emlrtRSI;
    for (i2 = 0; i2 <= vlen; i2++) {
      i1 = j + i2 * vstride;
      x[i1] = vwork[i2];
      idx[i1] = iidx[i2];
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
} // namespace Codegen

// End of code generation (sort.cpp)
