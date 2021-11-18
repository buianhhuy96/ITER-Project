//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sortIdx.cpp
//
// Code generation for function 'sortIdx'
//

// Include files
#include "sortIdx.h"
#include "calibrateCamera_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo cg_emlrtRSI{
    340,                // lineNo
    "block_merge_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo dg_emlrtRSI{
    392,                      // lineNo
    "initialize_vector_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo eg_emlrtRSI{
    420,                      // lineNo
    "initialize_vector_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo fg_emlrtRSI{
    427,                      // lineNo
    "initialize_vector_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo jg_emlrtRSI{
    499,           // lineNo
    "merge_block", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo lg_emlrtRSI{
    507,           // lineNo
    "merge_block", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo mg_emlrtRSI{
    514,           // lineNo
    "merge_block", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo ng_emlrtRSI{
    561,     // lineNo
    "merge", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo og_emlrtRSI{
    530,     // lineNo
    "merge", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo pg_emlrtRSI{
    354,          // lineNo
    "shift_NaNs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo qg_emlrtRSI{
    363,          // lineNo
    "shift_NaNs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRTEInfo jk_emlrtRTEI{
    56,        // lineNo
    5,         // colNo
    "sortIdx", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pName
};

// Function Declarations
namespace Codegen {
namespace coder {
namespace internal {
static void merge(const emlrtStack *sp, ::coder::array<int32_T, 1U> &idx,
                  ::coder::array<real32_T, 1U> &x, int32_T offset, int32_T np,
                  int32_T nq, ::coder::array<int32_T, 1U> &iwork,
                  ::coder::array<real32_T, 1U> &xwork);

static void merge(const emlrtStack *sp, ::coder::array<int32_T, 1U> &idx,
                  ::coder::array<real_T, 1U> &x, int32_T offset, int32_T np,
                  int32_T nq, ::coder::array<int32_T, 1U> &iwork,
                  ::coder::array<real_T, 1U> &xwork);

static void merge(const emlrtStack *sp, ::coder::array<int32_T, 1U> &idx,
                  ::coder::array<int32_T, 1U> &x, int32_T offset, int32_T np,
                  int32_T nq, ::coder::array<int32_T, 1U> &iwork,
                  ::coder::array<int32_T, 1U> &xwork);

static void merge_block(const emlrtStack *sp, ::coder::array<int32_T, 1U> &idx,
                        ::coder::array<real32_T, 1U> &x, int32_T offset,
                        int32_T n, int32_T preSortLevel,
                        ::coder::array<int32_T, 1U> &iwork,
                        ::coder::array<real32_T, 1U> &xwork);

static void merge_block(const emlrtStack *sp, ::coder::array<int32_T, 1U> &idx,
                        ::coder::array<real_T, 1U> &x, int32_T offset,
                        int32_T n, int32_T preSortLevel,
                        ::coder::array<int32_T, 1U> &iwork,
                        ::coder::array<real_T, 1U> &xwork);

static void merge_pow2_block(::coder::array<int32_T, 1U> &idx,
                             ::coder::array<real32_T, 1U> &x, int32_T offset);

static void merge_pow2_block(::coder::array<int32_T, 1U> &idx,
                             ::coder::array<real_T, 1U> &x, int32_T offset);

} // namespace internal
} // namespace coder
} // namespace Codegen

// Function Definitions
namespace Codegen {
namespace coder {
namespace internal {
static void merge(const emlrtStack *sp, ::coder::array<int32_T, 1U> &idx,
                  ::coder::array<real32_T, 1U> &x, int32_T offset, int32_T np,
                  int32_T nq, ::coder::array<int32_T, 1U> &iwork,
                  ::coder::array<real32_T, 1U> &xwork)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (nq != 0) {
    int32_T iout;
    int32_T j;
    int32_T n_tmp;
    int32_T p;
    int32_T q;
    n_tmp = np + nq;
    st.site = &og_emlrtRSI;
    if ((1 <= n_tmp) && (n_tmp > 2147483646)) {
      b_st.site = &qc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (j = 0; j < n_tmp; j++) {
      iout = offset + j;
      iwork[j] = idx[iout];
      xwork[j] = x[iout];
    }
    p = 0;
    q = np;
    iout = offset - 1;
    int32_T exitg1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[p] >= xwork[q]) {
        idx[iout] = iwork[p];
        x[iout] = xwork[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[q];
        x[iout] = xwork[q];
        if (q + 1 < n_tmp) {
          q++;
        } else {
          q = iout - p;
          st.site = &ng_emlrtRSI;
          if ((p + 1 <= np) && (np > 2147483646)) {
            b_st.site = &qc_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }
          for (j = p + 1; j <= np; j++) {
            iout = q + j;
            idx[iout] = iwork[j - 1];
            x[iout] = xwork[j - 1];
          }
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

static void merge(const emlrtStack *sp, ::coder::array<int32_T, 1U> &idx,
                  ::coder::array<real_T, 1U> &x, int32_T offset, int32_T np,
                  int32_T nq, ::coder::array<int32_T, 1U> &iwork,
                  ::coder::array<real_T, 1U> &xwork)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (nq != 0) {
    int32_T iout;
    int32_T j;
    int32_T n_tmp;
    int32_T p;
    int32_T q;
    n_tmp = np + nq;
    st.site = &og_emlrtRSI;
    if ((1 <= n_tmp) && (n_tmp > 2147483646)) {
      b_st.site = &qc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (j = 0; j < n_tmp; j++) {
      iout = offset + j;
      iwork[j] = idx[iout];
      xwork[j] = x[iout];
    }
    p = 0;
    q = np;
    iout = offset - 1;
    int32_T exitg1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[p] <= xwork[q]) {
        idx[iout] = iwork[p];
        x[iout] = xwork[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[q];
        x[iout] = xwork[q];
        if (q + 1 < n_tmp) {
          q++;
        } else {
          q = iout - p;
          st.site = &ng_emlrtRSI;
          if ((p + 1 <= np) && (np > 2147483646)) {
            b_st.site = &qc_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }
          for (j = p + 1; j <= np; j++) {
            iout = q + j;
            idx[iout] = iwork[j - 1];
            x[iout] = xwork[j - 1];
          }
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

static void merge(const emlrtStack *sp, ::coder::array<int32_T, 1U> &idx,
                  ::coder::array<int32_T, 1U> &x, int32_T offset, int32_T np,
                  int32_T nq, ::coder::array<int32_T, 1U> &iwork,
                  ::coder::array<int32_T, 1U> &xwork)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (nq != 0) {
    int32_T iout;
    int32_T j;
    int32_T n_tmp;
    int32_T p;
    int32_T q;
    n_tmp = np + nq;
    st.site = &og_emlrtRSI;
    if ((1 <= n_tmp) && (n_tmp > 2147483646)) {
      b_st.site = &qc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (j = 0; j < n_tmp; j++) {
      iout = offset + j;
      iwork[j] = idx[iout];
      xwork[j] = x[iout];
    }
    p = 0;
    q = np;
    iout = offset - 1;
    int32_T exitg1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[p] <= xwork[q]) {
        idx[iout] = iwork[p];
        x[iout] = xwork[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[q];
        x[iout] = xwork[q];
        if (q + 1 < n_tmp) {
          q++;
        } else {
          q = iout - p;
          st.site = &ng_emlrtRSI;
          if ((p + 1 <= np) && (np > 2147483646)) {
            b_st.site = &qc_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }
          for (j = p + 1; j <= np; j++) {
            iout = q + j;
            idx[iout] = iwork[j - 1];
            x[iout] = xwork[j - 1];
          }
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

static void merge_block(const emlrtStack *sp, ::coder::array<int32_T, 1U> &idx,
                        ::coder::array<real32_T, 1U> &x, int32_T offset,
                        int32_T n, int32_T preSortLevel,
                        ::coder::array<int32_T, 1U> &iwork,
                        ::coder::array<real32_T, 1U> &xwork)
{
  emlrtStack st;
  int32_T bLen;
  int32_T nPairs;
  st.prev = sp;
  st.tls = sp->tls;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    int32_T nTail;
    int32_T tailOffset;
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        st.site = &jg_emlrtRSI;
        merge(&st, idx, x, offset + tailOffset, bLen, nTail - bLen, iwork,
              xwork);
      }
    }
    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 0; nTail < nPairs; nTail++) {
      st.site = &lg_emlrtRSI;
      merge(&st, idx, x, offset + nTail * tailOffset, bLen, bLen, iwork, xwork);
    }
    bLen = tailOffset;
  }
  if (n > bLen) {
    st.site = &mg_emlrtRSI;
    merge(&st, idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

static void merge_block(const emlrtStack *sp, ::coder::array<int32_T, 1U> &idx,
                        ::coder::array<real_T, 1U> &x, int32_T offset,
                        int32_T n, int32_T preSortLevel,
                        ::coder::array<int32_T, 1U> &iwork,
                        ::coder::array<real_T, 1U> &xwork)
{
  emlrtStack st;
  int32_T bLen;
  int32_T nPairs;
  st.prev = sp;
  st.tls = sp->tls;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    int32_T nTail;
    int32_T tailOffset;
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        st.site = &jg_emlrtRSI;
        merge(&st, idx, x, offset + tailOffset, bLen, nTail - bLen, iwork,
              xwork);
      }
    }
    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 0; nTail < nPairs; nTail++) {
      st.site = &lg_emlrtRSI;
      merge(&st, idx, x, offset + nTail * tailOffset, bLen, bLen, iwork, xwork);
    }
    bLen = tailOffset;
  }
  if (n > bLen) {
    st.site = &mg_emlrtRSI;
    merge(&st, idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

static void merge_pow2_block(::coder::array<int32_T, 1U> &idx,
                             ::coder::array<real32_T, 1U> &x, int32_T offset)
{
  int32_T iwork[256];
  real32_T xwork[256];
  for (int32_T b{0}; b < 6; b++) {
    int32_T bLen;
    int32_T bLen2;
    int32_T nPairs;
    bLen = 1 << (b + 2);
    bLen2 = bLen << 1;
    nPairs = 256 >> (b + 3);
    for (int32_T k{0}; k < nPairs; k++) {
      int32_T blockOffset;
      int32_T iout;
      int32_T j;
      int32_T p;
      int32_T q;
      blockOffset = offset + k * bLen2;
      for (j = 0; j < bLen2; j++) {
        iout = blockOffset + j;
        iwork[j] = idx[iout];
        xwork[j] = x[iout];
      }
      p = 0;
      q = bLen;
      iout = blockOffset - 1;
      int32_T exitg1;
      do {
        exitg1 = 0;
        iout++;
        if (xwork[p] >= xwork[q]) {
          idx[iout] = iwork[p];
          x[iout] = xwork[p];
          if (p + 1 < bLen) {
            p++;
          } else {
            exitg1 = 1;
          }
        } else {
          idx[iout] = iwork[q];
          x[iout] = xwork[q];
          if (q + 1 < bLen2) {
            q++;
          } else {
            iout -= p;
            for (j = p + 1; j <= bLen; j++) {
              q = iout + j;
              idx[q] = iwork[j - 1];
              x[q] = xwork[j - 1];
            }
            exitg1 = 1;
          }
        }
      } while (exitg1 == 0);
    }
  }
}

static void merge_pow2_block(::coder::array<int32_T, 1U> &idx,
                             ::coder::array<real_T, 1U> &x, int32_T offset)
{
  real_T xwork[256];
  int32_T iwork[256];
  for (int32_T b{0}; b < 6; b++) {
    int32_T bLen;
    int32_T bLen2;
    int32_T nPairs;
    bLen = 1 << (b + 2);
    bLen2 = bLen << 1;
    nPairs = 256 >> (b + 3);
    for (int32_T k{0}; k < nPairs; k++) {
      int32_T blockOffset;
      int32_T iout;
      int32_T j;
      int32_T p;
      int32_T q;
      blockOffset = offset + k * bLen2;
      for (j = 0; j < bLen2; j++) {
        iout = blockOffset + j;
        iwork[j] = idx[iout];
        xwork[j] = x[iout];
      }
      p = 0;
      q = bLen;
      iout = blockOffset - 1;
      int32_T exitg1;
      do {
        exitg1 = 0;
        iout++;
        if (xwork[p] <= xwork[q]) {
          idx[iout] = iwork[p];
          x[iout] = xwork[p];
          if (p + 1 < bLen) {
            p++;
          } else {
            exitg1 = 1;
          }
        } else {
          idx[iout] = iwork[q];
          x[iout] = xwork[q];
          if (q + 1 < bLen2) {
            q++;
          } else {
            iout -= p;
            for (j = p + 1; j <= bLen; j++) {
              q = iout + j;
              idx[q] = iwork[j - 1];
              x[q] = xwork[j - 1];
            }
            exitg1 = 1;
          }
        }
      } while (exitg1 == 0);
    }
  }
}

void merge_block(const emlrtStack *sp, ::coder::array<int32_T, 1U> &idx,
                 ::coder::array<int32_T, 1U> &x, int32_T offset, int32_T n,
                 int32_T preSortLevel, ::coder::array<int32_T, 1U> &iwork,
                 ::coder::array<int32_T, 1U> &xwork)
{
  emlrtStack st;
  int32_T bLen;
  int32_T nPairs;
  st.prev = sp;
  st.tls = sp->tls;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    int32_T nTail;
    int32_T tailOffset;
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        st.site = &jg_emlrtRSI;
        merge(&st, idx, x, offset + tailOffset, bLen, nTail - bLen, iwork,
              xwork);
      }
    }
    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 0; nTail < nPairs; nTail++) {
      st.site = &lg_emlrtRSI;
      merge(&st, idx, x, offset + nTail * tailOffset, bLen, bLen, iwork, xwork);
    }
    bLen = tailOffset;
  }
  if (n > bLen) {
    st.site = &mg_emlrtRSI;
    merge(&st, idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

void merge_pow2_block(::coder::array<int32_T, 1U> &idx,
                      ::coder::array<int32_T, 1U> &x, int32_T offset)
{
  int32_T iwork[256];
  int32_T xwork[256];
  for (int32_T b{0}; b < 6; b++) {
    int32_T bLen;
    int32_T bLen2;
    int32_T nPairs;
    bLen = 1 << (b + 2);
    bLen2 = bLen << 1;
    nPairs = 256 >> (b + 3);
    for (int32_T k{0}; k < nPairs; k++) {
      int32_T blockOffset;
      int32_T iout;
      int32_T j;
      int32_T p;
      int32_T q;
      blockOffset = offset + k * bLen2;
      for (j = 0; j < bLen2; j++) {
        iout = blockOffset + j;
        iwork[j] = idx[iout];
        xwork[j] = x[iout];
      }
      p = 0;
      q = bLen;
      iout = blockOffset - 1;
      int32_T exitg1;
      do {
        exitg1 = 0;
        iout++;
        if (xwork[p] <= xwork[q]) {
          idx[iout] = iwork[p];
          x[iout] = xwork[p];
          if (p + 1 < bLen) {
            p++;
          } else {
            exitg1 = 1;
          }
        } else {
          idx[iout] = iwork[q];
          x[iout] = xwork[q];
          if (q + 1 < bLen2) {
            q++;
          } else {
            iout -= p;
            for (j = p + 1; j <= bLen; j++) {
              q = iout + j;
              idx[q] = iwork[j - 1];
              x[q] = xwork[j - 1];
            }
            exitg1 = 1;
          }
        }
      } while (exitg1 == 0);
    }
  }
}

void sortIdx(const emlrtStack *sp, ::coder::array<real32_T, 1U> &x,
             ::coder::array<int32_T, 1U> &idx)
{
  ::coder::array<int32_T, 1U> iwork;
  ::coder::array<real32_T, 1U> xwork;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T idx4[4];
  int32_T ib;
  int32_T quartetOffset;
  real32_T x4[4];
  int8_T perm[4];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  ib = x.size(0);
  idx.set_size(&is_emlrtRTEI, sp, ib);
  for (quartetOffset = 0; quartetOffset < ib; quartetOffset++) {
    idx[quartetOffset] = 0;
  }
  if (x.size(0) != 0) {
    int32_T b_n;
    int32_T i2;
    int32_T i3;
    int32_T i4;
    int32_T k;
    int32_T n;
    int32_T nNaNs;
    st.site = &vf_emlrtRSI;
    n = x.size(0);
    b_st.site = &wf_emlrtRSI;
    b_n = x.size(0);
    x4[0] = 0.0F;
    idx4[0] = 0;
    x4[1] = 0.0F;
    idx4[1] = 0;
    x4[2] = 0.0F;
    idx4[2] = 0;
    x4[3] = 0.0F;
    idx4[3] = 0;
    iwork.set_size(&js_emlrtRTEI, &b_st, ib);
    for (quartetOffset = 0; quartetOffset < ib; quartetOffset++) {
      iwork[quartetOffset] = 0;
    }
    ib = x.size(0);
    xwork.set_size(&ks_emlrtRTEI, &b_st, ib);
    for (quartetOffset = 0; quartetOffset < ib; quartetOffset++) {
      xwork[quartetOffset] = 0.0F;
    }
    nNaNs = 0;
    ib = -1;
    c_st.site = &dg_emlrtRSI;
    if ((1 <= x.size(0)) && (x.size(0) > 2147483646)) {
      d_st.site = &qc_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (k = 0; k < b_n; k++) {
      if (muSingleScalarIsNaN(x[k])) {
        i3 = (b_n - nNaNs) - 1;
        idx[i3] = k + 1;
        xwork[i3] = x[k];
        nNaNs++;
      } else {
        ib++;
        idx4[ib] = k + 1;
        x4[ib] = x[k];
        if (ib + 1 == 4) {
          real32_T f;
          real32_T f1;
          quartetOffset = k - nNaNs;
          if (x4[0] >= x4[1]) {
            ib = 1;
            i2 = 2;
          } else {
            ib = 2;
            i2 = 1;
          }
          if (x4[2] >= x4[3]) {
            i3 = 3;
            i4 = 4;
          } else {
            i3 = 4;
            i4 = 3;
          }
          f = x4[ib - 1];
          f1 = x4[i3 - 1];
          if (f >= f1) {
            f = x4[i2 - 1];
            if (f >= f1) {
              perm[0] = static_cast<int8_T>(ib);
              perm[1] = static_cast<int8_T>(i2);
              perm[2] = static_cast<int8_T>(i3);
              perm[3] = static_cast<int8_T>(i4);
            } else if (f >= x4[i4 - 1]) {
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
            f1 = x4[i4 - 1];
            if (f >= f1) {
              if (x4[i2 - 1] >= f1) {
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
          idx[quartetOffset - 3] = idx4[perm[0] - 1];
          idx[quartetOffset - 2] = idx4[perm[1] - 1];
          idx[quartetOffset - 1] = idx4[perm[2] - 1];
          idx[quartetOffset] = idx4[perm[3] - 1];
          x[quartetOffset - 3] = x4[perm[0] - 1];
          x[quartetOffset - 2] = x4[perm[1] - 1];
          x[quartetOffset - 1] = x4[perm[2] - 1];
          x[quartetOffset] = x4[perm[3] - 1];
          ib = -1;
        }
      }
    }
    i4 = (b_n - nNaNs) - 1;
    if (ib + 1 > 0) {
      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      if (ib + 1 == 1) {
        perm[0] = 1;
      } else if (ib + 1 == 2) {
        if (x4[0] >= x4[1]) {
          perm[0] = 1;
          perm[1] = 2;
        } else {
          perm[0] = 2;
          perm[1] = 1;
        }
      } else if (x4[0] >= x4[1]) {
        if (x4[1] >= x4[2]) {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        } else if (x4[0] >= x4[2]) {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        } else {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      } else if (x4[0] >= x4[2]) {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      } else if (x4[1] >= x4[2]) {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      } else {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }
      c_st.site = &eg_emlrtRSI;
      if (ib + 1 > 2147483646) {
        d_st.site = &qc_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (k = 0; k <= ib; k++) {
        i3 = perm[k] - 1;
        quartetOffset = (i4 - ib) + k;
        idx[quartetOffset] = idx4[i3];
        x[quartetOffset] = x4[i3];
      }
    }
    ib = (nNaNs >> 1) + 1;
    c_st.site = &fg_emlrtRSI;
    for (k = 0; k <= ib - 2; k++) {
      quartetOffset = (i4 + k) + 1;
      i2 = idx[quartetOffset];
      i3 = (b_n - k) - 1;
      idx[quartetOffset] = idx[i3];
      idx[i3] = i2;
      x[quartetOffset] = xwork[i3];
      x[i3] = xwork[quartetOffset];
    }
    if ((nNaNs & 1) != 0) {
      quartetOffset = i4 + ib;
      x[quartetOffset] = xwork[quartetOffset];
    }
    i2 = n - nNaNs;
    ib = 2;
    if (i2 > 1) {
      if (n >= 256) {
        quartetOffset = i2 >> 8;
        if (quartetOffset > 0) {
          b_st.site = &xf_emlrtRSI;
          for (ib = 0; ib < quartetOffset; ib++) {
            b_st.site = &yf_emlrtRSI;
            merge_pow2_block(idx, x, ib << 8);
          }
          ib = quartetOffset << 8;
          quartetOffset = i2 - ib;
          if (quartetOffset > 0) {
            b_st.site = &ag_emlrtRSI;
            merge_block(&b_st, idx, x, ib, quartetOffset, 2, iwork, xwork);
          }
          ib = 8;
        }
      }
      b_st.site = &bg_emlrtRSI;
      merge_block(&b_st, idx, x, 0, i2, ib, iwork, xwork);
    }
    if ((nNaNs > 0) && (i2 > 0)) {
      b_st.site = &cg_emlrtRSI;
      c_st.site = &pg_emlrtRSI;
      if (nNaNs > 2147483646) {
        d_st.site = &qc_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (k = 0; k < nNaNs; k++) {
        ib = i2 + k;
        xwork[k] = x[ib];
        iwork[k] = idx[ib];
      }
      for (k = i2; k >= 1; k--) {
        quartetOffset = (nNaNs + k) - 1;
        x[quartetOffset] = x[k - 1];
        idx[quartetOffset] = idx[k - 1];
      }
      c_st.site = &qg_emlrtRSI;
      for (k = 0; k < nNaNs; k++) {
        x[k] = xwork[k];
        idx[k] = iwork[k];
      }
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void sortIdx(const emlrtStack *sp, ::coder::array<real_T, 1U> &x,
             ::coder::array<int32_T, 1U> &idx)
{
  ::coder::array<real_T, 1U> xwork;
  ::coder::array<int32_T, 1U> iwork;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T x4[4];
  int32_T idx4[4];
  int32_T ib;
  int32_T quartetOffset;
  int8_T perm[4];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  ib = x.size(0);
  idx.set_size(&is_emlrtRTEI, sp, ib);
  for (quartetOffset = 0; quartetOffset < ib; quartetOffset++) {
    idx[quartetOffset] = 0;
  }
  if (x.size(0) != 0) {
    int32_T b_n;
    int32_T i1;
    int32_T i3;
    int32_T i4;
    int32_T k;
    int32_T n;
    int32_T nNaNs;
    st.site = &vf_emlrtRSI;
    n = x.size(0);
    b_st.site = &wf_emlrtRSI;
    b_n = x.size(0);
    x4[0] = 0.0;
    idx4[0] = 0;
    x4[1] = 0.0;
    idx4[1] = 0;
    x4[2] = 0.0;
    idx4[2] = 0;
    x4[3] = 0.0;
    idx4[3] = 0;
    iwork.set_size(&js_emlrtRTEI, &b_st, ib);
    for (quartetOffset = 0; quartetOffset < ib; quartetOffset++) {
      iwork[quartetOffset] = 0;
    }
    ib = x.size(0);
    xwork.set_size(&ks_emlrtRTEI, &b_st, ib);
    for (quartetOffset = 0; quartetOffset < ib; quartetOffset++) {
      xwork[quartetOffset] = 0.0;
    }
    nNaNs = 0;
    ib = -1;
    c_st.site = &dg_emlrtRSI;
    if ((1 <= x.size(0)) && (x.size(0) > 2147483646)) {
      d_st.site = &qc_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (k = 0; k < b_n; k++) {
      if (muDoubleScalarIsNaN(x[k])) {
        i3 = (b_n - nNaNs) - 1;
        idx[i3] = k + 1;
        xwork[i3] = x[k];
        nNaNs++;
      } else {
        ib++;
        idx4[ib] = k + 1;
        x4[ib] = x[k];
        if (ib + 1 == 4) {
          real_T d;
          real_T d1;
          quartetOffset = k - nNaNs;
          if (x4[0] <= x4[1]) {
            i1 = 1;
            ib = 2;
          } else {
            i1 = 2;
            ib = 1;
          }
          if (x4[2] <= x4[3]) {
            i3 = 3;
            i4 = 4;
          } else {
            i3 = 4;
            i4 = 3;
          }
          d = x4[i1 - 1];
          d1 = x4[i3 - 1];
          if (d <= d1) {
            d = x4[ib - 1];
            if (d <= d1) {
              perm[0] = static_cast<int8_T>(i1);
              perm[1] = static_cast<int8_T>(ib);
              perm[2] = static_cast<int8_T>(i3);
              perm[3] = static_cast<int8_T>(i4);
            } else if (d <= x4[i4 - 1]) {
              perm[0] = static_cast<int8_T>(i1);
              perm[1] = static_cast<int8_T>(i3);
              perm[2] = static_cast<int8_T>(ib);
              perm[3] = static_cast<int8_T>(i4);
            } else {
              perm[0] = static_cast<int8_T>(i1);
              perm[1] = static_cast<int8_T>(i3);
              perm[2] = static_cast<int8_T>(i4);
              perm[3] = static_cast<int8_T>(ib);
            }
          } else {
            d1 = x4[i4 - 1];
            if (d <= d1) {
              if (x4[ib - 1] <= d1) {
                perm[0] = static_cast<int8_T>(i3);
                perm[1] = static_cast<int8_T>(i1);
                perm[2] = static_cast<int8_T>(ib);
                perm[3] = static_cast<int8_T>(i4);
              } else {
                perm[0] = static_cast<int8_T>(i3);
                perm[1] = static_cast<int8_T>(i1);
                perm[2] = static_cast<int8_T>(i4);
                perm[3] = static_cast<int8_T>(ib);
              }
            } else {
              perm[0] = static_cast<int8_T>(i3);
              perm[1] = static_cast<int8_T>(i4);
              perm[2] = static_cast<int8_T>(i1);
              perm[3] = static_cast<int8_T>(ib);
            }
          }
          idx[quartetOffset - 3] = idx4[perm[0] - 1];
          idx[quartetOffset - 2] = idx4[perm[1] - 1];
          idx[quartetOffset - 1] = idx4[perm[2] - 1];
          idx[quartetOffset] = idx4[perm[3] - 1];
          x[quartetOffset - 3] = x4[perm[0] - 1];
          x[quartetOffset - 2] = x4[perm[1] - 1];
          x[quartetOffset - 1] = x4[perm[2] - 1];
          x[quartetOffset] = x4[perm[3] - 1];
          ib = -1;
        }
      }
    }
    i4 = (b_n - nNaNs) - 1;
    if (ib + 1 > 0) {
      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      if (ib + 1 == 1) {
        perm[0] = 1;
      } else if (ib + 1 == 2) {
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
      c_st.site = &eg_emlrtRSI;
      if (ib + 1 > 2147483646) {
        d_st.site = &qc_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (k = 0; k <= ib; k++) {
        i3 = perm[k] - 1;
        quartetOffset = (i4 - ib) + k;
        idx[quartetOffset] = idx4[i3];
        x[quartetOffset] = x4[i3];
      }
    }
    ib = (nNaNs >> 1) + 1;
    c_st.site = &fg_emlrtRSI;
    for (k = 0; k <= ib - 2; k++) {
      quartetOffset = (i4 + k) + 1;
      i1 = idx[quartetOffset];
      i3 = (b_n - k) - 1;
      idx[quartetOffset] = idx[i3];
      idx[i3] = i1;
      x[quartetOffset] = xwork[i3];
      x[i3] = xwork[quartetOffset];
    }
    if ((nNaNs & 1) != 0) {
      quartetOffset = i4 + ib;
      x[quartetOffset] = xwork[quartetOffset];
    }
    i1 = n - nNaNs;
    ib = 2;
    if (i1 > 1) {
      if (n >= 256) {
        quartetOffset = i1 >> 8;
        if (quartetOffset > 0) {
          b_st.site = &xf_emlrtRSI;
          for (ib = 0; ib < quartetOffset; ib++) {
            b_st.site = &yf_emlrtRSI;
            merge_pow2_block(idx, x, ib << 8);
          }
          ib = quartetOffset << 8;
          quartetOffset = i1 - ib;
          if (quartetOffset > 0) {
            b_st.site = &ag_emlrtRSI;
            merge_block(&b_st, idx, x, ib, quartetOffset, 2, iwork, xwork);
          }
          ib = 8;
        }
      }
      b_st.site = &bg_emlrtRSI;
      merge_block(&b_st, idx, x, 0, i1, ib, iwork, xwork);
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void sortIdx(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x,
             ::coder::array<int32_T, 2U> &idx)
{
  ::coder::array<int32_T, 1U> iwork;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T b_i;
  int32_T i;
  int32_T n;
  int32_T qEnd;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  n = x.size(1) + 1;
  idx.set_size(&jk_emlrtRTEI, sp, 1, x.size(1));
  i = x.size(1);
  for (b_i = 0; b_i < i; b_i++) {
    idx[b_i] = 0;
  }
  if (x.size(1) != 0) {
    real_T d;
    int32_T k;
    st.site = &ym_emlrtRSI;
    iwork.set_size(&gk_emlrtRTEI, &st, x.size(1));
    i = x.size(1) - 1;
    b_st.site = &an_emlrtRSI;
    if ((1 <= x.size(1) - 1) && (x.size(1) - 1 > 2147483645)) {
      c_st.site = &qc_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (k = 1; k <= i; k += 2) {
      d = x[k];
      if ((x[k - 1] <= d) || muDoubleScalarIsNaN(d)) {
        idx[k - 1] = k;
        idx[k] = k + 1;
      } else {
        idx[k - 1] = k + 1;
        idx[k] = k;
      }
    }
    if ((x.size(1) & 1) != 0) {
      idx[x.size(1) - 1] = x.size(1);
    }
    i = 2;
    while (i < n - 1) {
      int32_T i2;
      int32_T j;
      i2 = i << 1;
      j = 1;
      for (int32_T pEnd{i + 1}; pEnd < n; pEnd = qEnd + i) {
        int32_T kEnd;
        int32_T p;
        int32_T q;
        p = j;
        q = pEnd - 1;
        qEnd = j + i2;
        if (qEnd > n) {
          qEnd = n;
        }
        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          d = x[idx[q] - 1];
          b_i = idx[p - 1];
          if ((x[b_i - 1] <= d) || muDoubleScalarIsNaN(d)) {
            iwork[k] = b_i;
            p++;
            if (p == pEnd) {
              while (q + 1 < qEnd) {
                k++;
                iwork[k] = idx[q];
                q++;
              }
            }
          } else {
            iwork[k] = idx[q];
            q++;
            if (q + 1 == qEnd) {
              while (p < pEnd) {
                k++;
                iwork[k] = idx[p - 1];
                p++;
              }
            }
          }
          k++;
        }
        b_st.site = &bn_emlrtRSI;
        for (k = 0; k < kEnd; k++) {
          idx[(j + k) - 1] = iwork[k];
        }
        j = qEnd;
      }
      i = i2;
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace internal
} // namespace coder
} // namespace Codegen

// End of code generation (sortIdx.cpp)
