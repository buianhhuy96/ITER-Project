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
#include "ComputeCamExtrinsics_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo ug_emlrtRSI{
    105,       // lineNo
    "sortIdx", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo vg_emlrtRSI{
    308,                // lineNo
    "block_merge_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo wg_emlrtRSI{
    316,                // lineNo
    "block_merge_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo xg_emlrtRSI{
    317,                // lineNo
    "block_merge_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo yg_emlrtRSI{
    325,                // lineNo
    "block_merge_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo ah_emlrtRSI{
    333,                // lineNo
    "block_merge_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo bh_emlrtRSI{
    340,                // lineNo
    "block_merge_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo ch_emlrtRSI{
    385,                      // lineNo
    "initialize_vector_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo dh_emlrtRSI{
    387,                      // lineNo
    "initialize_vector_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo eh_emlrtRSI{
    392,                      // lineNo
    "initialize_vector_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo fh_emlrtRSI{
    420,                      // lineNo
    "initialize_vector_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo gh_emlrtRSI{
    427,                      // lineNo
    "initialize_vector_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo kh_emlrtRSI{
    499,           // lineNo
    "merge_block", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo mh_emlrtRSI{
    507,           // lineNo
    "merge_block", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo nh_emlrtRSI{
    514,           // lineNo
    "merge_block", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo oh_emlrtRSI{
    530,     // lineNo
    "merge", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo ph_emlrtRSI{
    561,     // lineNo
    "merge", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo qh_emlrtRSI{
    354,          // lineNo
    "shift_NaNs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo rh_emlrtRSI{
    359,          // lineNo
    "shift_NaNs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo sh_emlrtRSI{
    363,          // lineNo
    "shift_NaNs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo qo_emlrtRSI{
    443,                      // lineNo
    "initialize_vector_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo ro_emlrtRSI{
    468,                      // lineNo
    "initialize_vector_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo so_emlrtRSI{
    473,                      // lineNo
    "initialize_vector_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtBCInfo
    dw_emlrtBCI{
        0,             // iFirst
        31,            // iLast
        490,           // lineNo
        24,            // colNo
        "",            // aName
        "merge_block", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx."
        "m", // pName
        1    // checkKind
    };

static emlrtRTEInfo xk_emlrtRTEI{
    56,        // lineNo
    5,         // colNo
    "sortIdx", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pName
};

static emlrtRTEInfo nv_emlrtRTEI{
    61,        // lineNo
    5,         // colNo
    "sortIdx", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pName
};

static emlrtRTEInfo ov_emlrtRTEI{
    386,       // lineNo
    1,         // colNo
    "sortIdx", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pName
};

static emlrtRTEInfo pv_emlrtRTEI{
    388,       // lineNo
    1,         // colNo
    "sortIdx", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pName
};

// Function Declarations
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

static void merge_block(const emlrtStack *sp, ::coder::array<int32_T, 1U> &idx,
                        ::coder::array<int32_T, 1U> &x, int32_T offset,
                        int32_T n, int32_T preSortLevel,
                        ::coder::array<int32_T, 1U> &iwork,
                        ::coder::array<int32_T, 1U> &xwork);

static void merge_pow2_block(::coder::array<int32_T, 1U> &idx,
                             ::coder::array<real32_T, 1U> &x, int32_T offset);

static void merge_pow2_block(::coder::array<int32_T, 1U> &idx,
                             ::coder::array<real_T, 1U> &x, int32_T offset);

static void merge_pow2_block(::coder::array<int32_T, 1U> &idx,
                             ::coder::array<int32_T, 1U> &x, int32_T offset);

} // namespace internal
} // namespace coder

// Function Definitions
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
  if ((np != 0) && (nq != 0)) {
    int32_T iout;
    int32_T j;
    int32_T n_tmp;
    int32_T p;
    int32_T q;
    n_tmp = np + nq;
    st.site = &oh_emlrtRSI;
    if ((1 <= n_tmp) && (n_tmp > 2147483646)) {
      b_st.site = &ed_emlrtRSI;
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
          st.site = &ph_emlrtRSI;
          if ((p + 1 <= np) && (np > 2147483646)) {
            b_st.site = &ed_emlrtRSI;
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
  if ((np != 0) && (nq != 0)) {
    int32_T iout;
    int32_T j;
    int32_T n_tmp;
    int32_T p;
    int32_T q;
    n_tmp = np + nq;
    st.site = &oh_emlrtRSI;
    if ((1 <= n_tmp) && (n_tmp > 2147483646)) {
      b_st.site = &ed_emlrtRSI;
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
          st.site = &ph_emlrtRSI;
          if ((p + 1 <= np) && (np > 2147483646)) {
            b_st.site = &ed_emlrtRSI;
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
  if ((np != 0) && (nq != 0)) {
    int32_T iout;
    int32_T j;
    int32_T n_tmp;
    int32_T p;
    int32_T q;
    n_tmp = np + nq;
    st.site = &oh_emlrtRSI;
    if ((1 <= n_tmp) && (n_tmp > 2147483646)) {
      b_st.site = &ed_emlrtRSI;
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
          st.site = &ph_emlrtRSI;
          if ((p + 1 <= np) && (np > 2147483646)) {
            b_st.site = &ed_emlrtRSI;
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
  if ((preSortLevel < 0) || (preSortLevel > 31)) {
    emlrtDynamicBoundsCheckR2012b(preSortLevel, 0, 31, &dw_emlrtBCI,
                                  (emlrtCTX)sp);
  }
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
        st.site = &kh_emlrtRSI;
        merge(&st, idx, x, offset + tailOffset, bLen, nTail - bLen, iwork,
              xwork);
      }
    }
    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 0; nTail < nPairs; nTail++) {
      st.site = &mh_emlrtRSI;
      merge(&st, idx, x, offset + nTail * tailOffset, bLen, bLen, iwork, xwork);
    }
    bLen = tailOffset;
  }
  if (n > bLen) {
    st.site = &nh_emlrtRSI;
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
  if ((preSortLevel < 0) || (preSortLevel > 31)) {
    emlrtDynamicBoundsCheckR2012b(preSortLevel, 0, 31, &dw_emlrtBCI,
                                  (emlrtCTX)sp);
  }
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
        st.site = &kh_emlrtRSI;
        merge(&st, idx, x, offset + tailOffset, bLen, nTail - bLen, iwork,
              xwork);
      }
    }
    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 0; nTail < nPairs; nTail++) {
      st.site = &mh_emlrtRSI;
      merge(&st, idx, x, offset + nTail * tailOffset, bLen, bLen, iwork, xwork);
    }
    bLen = tailOffset;
  }
  if (n > bLen) {
    st.site = &nh_emlrtRSI;
    merge(&st, idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

static void merge_block(const emlrtStack *sp, ::coder::array<int32_T, 1U> &idx,
                        ::coder::array<int32_T, 1U> &x, int32_T offset,
                        int32_T n, int32_T preSortLevel,
                        ::coder::array<int32_T, 1U> &iwork,
                        ::coder::array<int32_T, 1U> &xwork)
{
  emlrtStack st;
  int32_T bLen;
  int32_T nPairs;
  st.prev = sp;
  st.tls = sp->tls;
  if ((preSortLevel < 0) || (preSortLevel > 31)) {
    emlrtDynamicBoundsCheckR2012b(preSortLevel, 0, 31, &dw_emlrtBCI,
                                  (emlrtCTX)sp);
  }
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
        st.site = &kh_emlrtRSI;
        merge(&st, idx, x, offset + tailOffset, bLen, nTail - bLen, iwork,
              xwork);
      }
    }
    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 0; nTail < nPairs; nTail++) {
      st.site = &mh_emlrtRSI;
      merge(&st, idx, x, offset + nTail * tailOffset, bLen, bLen, iwork, xwork);
    }
    bLen = tailOffset;
  }
  if (n > bLen) {
    st.site = &nh_emlrtRSI;
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

static void merge_pow2_block(::coder::array<int32_T, 1U> &idx,
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
  array<int32_T, 1U> iwork;
  array<real32_T, 1U> xwork;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T idx4[4];
  int32_T ib;
  int32_T quartetOffset;
  real32_T x4[4];
  uint32_T u;
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
  u = static_cast<uint32_T>(x.size(0));
  idx.set_size(&nv_emlrtRTEI, sp, static_cast<int32_T>(u));
  ib = static_cast<int32_T>(u);
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
    st.site = &ug_emlrtRSI;
    n = x.size(0);
    b_st.site = &vg_emlrtRSI;
    b_n = x.size(0);
    x4[0] = 0.0F;
    idx4[0] = 0;
    x4[1] = 0.0F;
    idx4[1] = 0;
    x4[2] = 0.0F;
    idx4[2] = 0;
    x4[3] = 0.0F;
    idx4[3] = 0;
    c_st.site = &ch_emlrtRSI;
    iwork.set_size(&ov_emlrtRTEI, &b_st, static_cast<int32_T>(u));
    ib = static_cast<int32_T>(u);
    for (quartetOffset = 0; quartetOffset < ib; quartetOffset++) {
      iwork[quartetOffset] = 0;
    }
    c_st.site = &dh_emlrtRSI;
    u = static_cast<uint32_T>(x.size(0));
    xwork.set_size(&pv_emlrtRTEI, &b_st, static_cast<int32_T>(u));
    ib = static_cast<int32_T>(u);
    for (quartetOffset = 0; quartetOffset < ib; quartetOffset++) {
      xwork[quartetOffset] = 0.0F;
    }
    nNaNs = 0;
    ib = -1;
    c_st.site = &eh_emlrtRSI;
    if ((1 <= x.size(0)) && (x.size(0) > 2147483646)) {
      d_st.site = &ed_emlrtRSI;
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
      c_st.site = &fh_emlrtRSI;
      if (ib + 1 > 2147483646) {
        d_st.site = &ed_emlrtRSI;
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
    c_st.site = &gh_emlrtRSI;
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
          b_st.site = &wg_emlrtRSI;
          for (ib = 0; ib < quartetOffset; ib++) {
            b_st.site = &xg_emlrtRSI;
            merge_pow2_block(idx, x, ib << 8);
          }
          ib = quartetOffset << 8;
          quartetOffset = i2 - ib;
          if (quartetOffset > 0) {
            b_st.site = &yg_emlrtRSI;
            merge_block(&b_st, idx, x, ib, quartetOffset, 2, iwork, xwork);
          }
          ib = 8;
        }
      }
      b_st.site = &ah_emlrtRSI;
      merge_block(&b_st, idx, x, 0, i2, ib, iwork, xwork);
    }
    if ((nNaNs > 0) && (i2 > 0)) {
      b_st.site = &bh_emlrtRSI;
      c_st.site = &qh_emlrtRSI;
      if (nNaNs > 2147483646) {
        d_st.site = &ed_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (k = 0; k < nNaNs; k++) {
        ib = i2 + k;
        xwork[k] = x[ib];
        iwork[k] = idx[ib];
      }
      c_st.site = &rh_emlrtRSI;
      for (k = i2; k >= 1; k--) {
        quartetOffset = (nNaNs + k) - 1;
        x[quartetOffset] = x[k - 1];
        idx[quartetOffset] = idx[k - 1];
      }
      c_st.site = &sh_emlrtRSI;
      if (nNaNs > 2147483646) {
        d_st.site = &ed_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
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
  array<real_T, 1U> xwork;
  array<int32_T, 1U> iwork;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T x4[4];
  int32_T idx4[4];
  int32_T ib;
  int32_T quartetOffset;
  uint32_T u;
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
  u = static_cast<uint32_T>(x.size(0));
  idx.set_size(&nv_emlrtRTEI, sp, static_cast<int32_T>(u));
  ib = static_cast<int32_T>(u);
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
    st.site = &ug_emlrtRSI;
    n = x.size(0);
    b_st.site = &vg_emlrtRSI;
    b_n = x.size(0);
    x4[0] = 0.0;
    idx4[0] = 0;
    x4[1] = 0.0;
    idx4[1] = 0;
    x4[2] = 0.0;
    idx4[2] = 0;
    x4[3] = 0.0;
    idx4[3] = 0;
    c_st.site = &ch_emlrtRSI;
    iwork.set_size(&ov_emlrtRTEI, &b_st, static_cast<int32_T>(u));
    ib = static_cast<int32_T>(u);
    for (quartetOffset = 0; quartetOffset < ib; quartetOffset++) {
      iwork[quartetOffset] = 0;
    }
    c_st.site = &dh_emlrtRSI;
    u = static_cast<uint32_T>(x.size(0));
    xwork.set_size(&pv_emlrtRTEI, &b_st, static_cast<int32_T>(u));
    ib = static_cast<int32_T>(u);
    for (quartetOffset = 0; quartetOffset < ib; quartetOffset++) {
      xwork[quartetOffset] = 0.0;
    }
    nNaNs = 0;
    ib = -1;
    c_st.site = &eh_emlrtRSI;
    if ((1 <= x.size(0)) && (x.size(0) > 2147483646)) {
      d_st.site = &ed_emlrtRSI;
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
      c_st.site = &fh_emlrtRSI;
      if (ib + 1 > 2147483646) {
        d_st.site = &ed_emlrtRSI;
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
    c_st.site = &gh_emlrtRSI;
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
          b_st.site = &wg_emlrtRSI;
          for (ib = 0; ib < quartetOffset; ib++) {
            b_st.site = &xg_emlrtRSI;
            merge_pow2_block(idx, x, ib << 8);
          }
          ib = quartetOffset << 8;
          quartetOffset = i1 - ib;
          if (quartetOffset > 0) {
            b_st.site = &yg_emlrtRSI;
            merge_block(&b_st, idx, x, ib, quartetOffset, 2, iwork, xwork);
          }
          ib = 8;
        }
      }
      b_st.site = &ah_emlrtRSI;
      merge_block(&b_st, idx, x, 0, i1, ib, iwork, xwork);
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void sortIdx(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x,
             ::coder::array<int32_T, 2U> &idx)
{
  array<int32_T, 1U> iwork;
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
  idx.set_size(&xk_emlrtRTEI, sp, 1, x.size(1));
  i = x.size(1);
  for (b_i = 0; b_i < i; b_i++) {
    idx[b_i] = 0;
  }
  if (x.size(1) != 0) {
    real_T d;
    int32_T k;
    st.site = &ko_emlrtRSI;
    b_st.site = &lo_emlrtRSI;
    iwork.set_size(&uk_emlrtRTEI, &b_st, x.size(1));
    i = x.size(1) - 1;
    b_st.site = &mo_emlrtRSI;
    if ((1 <= x.size(1) - 1) && (x.size(1) - 1 > 2147483645)) {
      c_st.site = &ed_emlrtRSI;
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
        b_st.site = &no_emlrtRSI;
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

void sortIdx(const emlrtStack *sp, ::coder::array<int32_T, 1U> &x,
             ::coder::array<int32_T, 1U> &idx)
{
  array<int32_T, 1U> iwork;
  array<int32_T, 1U> xwork;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T idx4[4];
  int32_T x4[4];
  int32_T i;
  int32_T i3;
  uint32_T u;
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
  u = static_cast<uint32_T>(x.size(0));
  idx.set_size(&nv_emlrtRTEI, sp, static_cast<int32_T>(u));
  i3 = static_cast<int32_T>(u);
  for (i = 0; i < i3; i++) {
    idx[i] = 0;
  }
  if (x.size(0) != 0) {
    int32_T b_n;
    int32_T i1;
    int32_T i2;
    int32_T i4;
    int32_T n;
    int32_T nLeft;
    int32_T nQuartets;
    st.site = &ug_emlrtRSI;
    n = x.size(0);
    b_st.site = &vg_emlrtRSI;
    b_n = x.size(0) - 1;
    x4[0] = 0;
    idx4[0] = 0;
    x4[1] = 0;
    idx4[1] = 0;
    x4[2] = 0;
    idx4[2] = 0;
    x4[3] = 0;
    idx4[3] = 0;
    c_st.site = &ch_emlrtRSI;
    iwork.set_size(&ov_emlrtRTEI, &b_st, static_cast<int32_T>(u));
    i3 = static_cast<int32_T>(u);
    for (i = 0; i < i3; i++) {
      iwork[i] = 0;
    }
    c_st.site = &dh_emlrtRSI;
    u = static_cast<uint32_T>(x.size(0));
    xwork.set_size(&pv_emlrtRTEI, &b_st, static_cast<int32_T>(u));
    i3 = static_cast<int32_T>(u);
    for (i = 0; i < i3; i++) {
      xwork[i] = 0;
    }
    nQuartets = x.size(0) >> 2;
    c_st.site = &qo_emlrtRSI;
    for (int32_T j{0}; j < nQuartets; j++) {
      int32_T b_i;
      b_i = j << 2;
      idx4[0] = b_i + 1;
      idx4[1] = b_i + 2;
      idx4[2] = b_i + 3;
      idx4[3] = b_i + 4;
      x4[0] = x[b_i];
      i3 = x[b_i + 1];
      x4[1] = i3;
      i4 = x[b_i + 2];
      x4[2] = i4;
      nLeft = x[b_i + 3];
      x4[3] = nLeft;
      if (x[b_i] <= i3) {
        i1 = 1;
        i2 = 2;
      } else {
        i1 = 2;
        i2 = 1;
      }
      if (i4 <= nLeft) {
        i3 = 3;
        i4 = 4;
      } else {
        i3 = 4;
        i4 = 3;
      }
      i = x4[i1 - 1];
      nLeft = x4[i3 - 1];
      if (i <= nLeft) {
        i = x4[i2 - 1];
        if (i <= nLeft) {
          perm[0] = static_cast<int8_T>(i1);
          perm[1] = static_cast<int8_T>(i2);
          perm[2] = static_cast<int8_T>(i3);
          perm[3] = static_cast<int8_T>(i4);
        } else if (i <= x4[i4 - 1]) {
          perm[0] = static_cast<int8_T>(i1);
          perm[1] = static_cast<int8_T>(i3);
          perm[2] = static_cast<int8_T>(i2);
          perm[3] = static_cast<int8_T>(i4);
        } else {
          perm[0] = static_cast<int8_T>(i1);
          perm[1] = static_cast<int8_T>(i3);
          perm[2] = static_cast<int8_T>(i4);
          perm[3] = static_cast<int8_T>(i2);
        }
      } else {
        nLeft = x4[i4 - 1];
        if (i <= nLeft) {
          if (x4[i2 - 1] <= nLeft) {
            perm[0] = static_cast<int8_T>(i3);
            perm[1] = static_cast<int8_T>(i1);
            perm[2] = static_cast<int8_T>(i2);
            perm[3] = static_cast<int8_T>(i4);
          } else {
            perm[0] = static_cast<int8_T>(i3);
            perm[1] = static_cast<int8_T>(i1);
            perm[2] = static_cast<int8_T>(i4);
            perm[3] = static_cast<int8_T>(i2);
          }
        } else {
          perm[0] = static_cast<int8_T>(i3);
          perm[1] = static_cast<int8_T>(i4);
          perm[2] = static_cast<int8_T>(i1);
          perm[3] = static_cast<int8_T>(i2);
        }
      }
      idx[b_i] = idx4[perm[0] - 1];
      idx[b_i + 1] = idx4[perm[1] - 1];
      idx[b_i + 2] = idx4[perm[2] - 1];
      idx[b_i + 3] = idx4[perm[3] - 1];
      x[b_i] = x4[perm[0] - 1];
      x[b_i + 1] = x4[perm[1] - 1];
      x[b_i + 2] = x4[perm[2] - 1];
      x[b_i + 3] = x4[perm[3] - 1];
    }
    i1 = nQuartets << 2;
    nLeft = (b_n - i1) + 1;
    if (nLeft > 0) {
      c_st.site = &ro_emlrtRSI;
      if (nLeft > 2147483646) {
        d_st.site = &ed_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (i2 = 0; i2 < nLeft; i2++) {
        i3 = i1 + i2;
        idx4[i2] = i3 + 1;
        x4[i2] = x[i3];
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
      c_st.site = &so_emlrtRSI;
      if (nLeft > 2147483646) {
        d_st.site = &ed_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (i2 = 0; i2 < nLeft; i2++) {
        i3 = perm[i2] - 1;
        i4 = i1 + i2;
        idx[i4] = idx4[i3];
        x[i4] = x4[i3];
      }
    }
    i3 = 2;
    if (n > 1) {
      if (n >= 256) {
        i3 = n >> 8;
        b_st.site = &wg_emlrtRSI;
        for (i4 = 0; i4 < i3; i4++) {
          b_st.site = &xg_emlrtRSI;
          merge_pow2_block(idx, x, i4 << 8);
        }
        i3 <<= 8;
        i4 = n - i3;
        if (i4 > 0) {
          b_st.site = &yg_emlrtRSI;
          merge_block(&b_st, idx, x, i3, i4, 2, iwork, xwork);
        }
        i3 = 8;
      }
      b_st.site = &ah_emlrtRSI;
      merge_block(&b_st, idx, x, 0, n, i3, iwork, xwork);
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace internal
} // namespace coder

// End of code generation (sortIdx.cpp)
