//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// rot90.cpp
//
// Code generation for function 'rot90'
//

// Include files
#include "rot90.h"
#include "calibrateCamera_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo jq_emlrtRSI{
    53,      // lineNo
    "rot90", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\rot90.m" // pathName
};

static emlrtRSInfo kq_emlrtRSI{
    54,      // lineNo
    "rot90", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\rot90.m" // pathName
};

static emlrtRSInfo lq_emlrtRSI{
    61,      // lineNo
    "rot90", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\rot90.m" // pathName
};

static emlrtRSInfo mq_emlrtRSI{
    62,      // lineNo
    "rot90", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\rot90.m" // pathName
};

static emlrtRSInfo br_emlrtRSI{
    73,      // lineNo
    "rot90", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\rot90.m" // pathName
};

static emlrtRSInfo cr_emlrtRSI{
    74,      // lineNo
    "rot90", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\rot90.m" // pathName
};

static emlrtRSInfo dr_emlrtRSI{
    81,      // lineNo
    "rot90", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\rot90.m" // pathName
};

static emlrtRSInfo er_emlrtRSI{
    82,      // lineNo
    "rot90", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\rot90.m" // pathName
};

static emlrtRTEInfo to_emlrtRTEI{
    50,      // lineNo
    24,      // colNo
    "rot90", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\rot90.m" // pName
};

static emlrtRTEInfo ap_emlrtRTEI{
    70,      // lineNo
    24,      // colNo
    "rot90", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\rot90.m" // pName
};

// Function Definitions
namespace Codegen {
namespace coder {
void b_rot90(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A,
             ::coder::array<real_T, 2U> &B)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T b_i;
  int32_T b_j;
  int32_T i;
  int32_T j;
  int32_T m;
  int32_T n;
  boolean_T emlrtHadParallelError{false};
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  m = A.size(0);
  n = A.size(1);
  B.set_size(&ap_emlrtRTEI, sp, A.size(0), A.size(1));
  if (A.size(0) * A.size(1) >= 8192) {
    st.site = &br_emlrtRSI;
    if ((1 <= A.size(1)) && (A.size(1) > 2147483646)) {
      b_st.site = &qc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    j = A.size(1) - 1;
    emlrtEnterParallelRegion((emlrtCTX)sp,
                             static_cast<boolean_T>(omp_in_parallel()));
#pragma omp parallel num_threads(                                              \
    emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(),    \
                         omp_get_num_procs())) private(e_st, b_i)              \
    firstprivate(c_st, d_st, emlrtHadParallelError)
    {
      try {

        c_st.prev = sp;
        c_st.tls = emlrtAllocTLS((emlrtCTX)sp, omp_get_thread_num());
        c_st.site = nullptr;
        d_st.prev = &c_st;
        d_st.tls = c_st.tls;
        e_st.prev = &d_st;
        e_st.tls = d_st.tls;
      } catch (...) {
        emlrtHadParallelError = true;
      }
#pragma omp for nowait
      for (b_j = 0; b_j <= j; b_j++) {
        if (emlrtHadParallelError)
          continue;
        try {

          d_st.site = &cr_emlrtRSI;
          if ((1 <= m) && (m > 2147483646)) {
            e_st.site = &qc_emlrtRSI;
            check_forloop_overflow_error(&e_st);
          }
          for (b_i = 0; b_i < m; b_i++) {
            B[b_i + B.size(0) * b_j] =
                A[((m - b_i) + A.size(0) * ((n - b_j) - 1)) - 1];
          }
        } catch (...) {
          emlrtHadParallelError = true;
        }
      }
    }
    emlrtExitParallelRegion((emlrtCTX)sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  } else {
    st.site = &dr_emlrtRSI;
    if ((1 <= A.size(1)) && (A.size(1) > 2147483646)) {
      b_st.site = &qc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (j = 0; j < n; j++) {
      st.site = &er_emlrtRSI;
      if ((1 <= m) && (m > 2147483646)) {
        b_st.site = &qc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (i = 0; i < m; i++) {
        B[i + B.size(0) * j] = A[((m - i) + A.size(0) * ((n - j) - 1)) - 1];
      }
    }
  }
}

void rot90(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A,
           ::coder::array<real_T, 2U> &B)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T b_i;
  int32_T b_j;
  int32_T i;
  int32_T j;
  int32_T m;
  int32_T n;
  boolean_T emlrtHadParallelError{false};
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  m = A.size(0);
  n = A.size(1);
  B.set_size(&to_emlrtRTEI, sp, A.size(1), A.size(0));
  if (A.size(0) * A.size(1) >= 8192) {
    st.site = &jq_emlrtRSI;
    if ((1 <= A.size(1)) && (A.size(1) > 2147483646)) {
      b_st.site = &qc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    i = A.size(1) - 1;
    emlrtEnterParallelRegion((emlrtCTX)sp,
                             static_cast<boolean_T>(omp_in_parallel()));
#pragma omp parallel num_threads(                                              \
    emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(),    \
                         omp_get_num_procs())) private(e_st, b_j)              \
    firstprivate(c_st, d_st, emlrtHadParallelError)
    {
      try {

        c_st.prev = sp;
        c_st.tls = emlrtAllocTLS((emlrtCTX)sp, omp_get_thread_num());
        c_st.site = nullptr;
        d_st.prev = &c_st;
        d_st.tls = c_st.tls;
        e_st.prev = &d_st;
        e_st.tls = d_st.tls;
      } catch (...) {
        emlrtHadParallelError = true;
      }
#pragma omp for nowait
      for (b_i = 0; b_i <= i; b_i++) {
        if (emlrtHadParallelError)
          continue;
        try {

          d_st.site = &kq_emlrtRSI;
          if ((1 <= m) && (m > 2147483646)) {
            e_st.site = &qc_emlrtRSI;
            check_forloop_overflow_error(&e_st);
          }
          for (b_j = 0; b_j < m; b_j++) {
            B[b_i + B.size(0) * b_j] = A[b_j + A.size(0) * ((n - b_i) - 1)];
          }
        } catch (...) {
          emlrtHadParallelError = true;
        }
      }
    }
    emlrtExitParallelRegion((emlrtCTX)sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  } else {
    st.site = &lq_emlrtRSI;
    if ((1 <= A.size(1)) && (A.size(1) > 2147483646)) {
      b_st.site = &qc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (i = 0; i < n; i++) {
      st.site = &mq_emlrtRSI;
      if ((1 <= m) && (m > 2147483646)) {
        b_st.site = &qc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (j = 0; j < m; j++) {
        B[i + B.size(0) * j] = A[j + A.size(0) * ((n - i) - 1)];
      }
    }
  }
}

} // namespace coder
} // namespace Codegen

// End of code generation (rot90.cpp)
