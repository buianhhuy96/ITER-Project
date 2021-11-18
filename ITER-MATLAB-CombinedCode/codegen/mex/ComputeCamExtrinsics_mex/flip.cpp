//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// flip.cpp
//
// Code generation for function 'flip'
//

// Include files
#include "flip.h"
#include "ComputeCamExtrinsics_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo kt_emlrtRSI{
    20,     // lineNo
    "flip", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\flip.m" // pathName
};

static emlrtRSInfo lt_emlrtRSI{
    29,     // lineNo
    "flip", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\flip.m" // pathName
};

static emlrtRSInfo mt_emlrtRSI{
    31,     // lineNo
    "flip", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\flip.m" // pathName
};

static emlrtRSInfo nt_emlrtRSI{
    34,     // lineNo
    "flip", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\flip.m" // pathName
};

static emlrtRSInfo ot_emlrtRSI{
    35,     // lineNo
    "flip", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\flip.m" // pathName
};

static emlrtRSInfo pt_emlrtRSI{
    37,     // lineNo
    "flip", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\flip.m" // pathName
};

static emlrtRTEInfo oc_emlrtRTEI{
    57,               // lineNo
    27,               // colNo
    "assertValidDim", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\assertValidDim.m" // pName
};

// Function Definitions
namespace coder {
void flip(const emlrtStack *sp, ::coder::array<real_T, 2U> &x, real_T dim)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kt_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((!(dim >= 1.0)) || (!(dim == muDoubleScalarFloor(dim))) ||
      (!(dim <= 2.147483647E+9))) {
    emlrtErrorWithMessageIdR2018a(
        &st, &oc_emlrtRTEI, "MATLAB:getdimarg:dimensionMustBePositiveInteger",
        "MATLAB:getdimarg:dimensionMustBePositiveInteger", 0);
  }
  if ((dim <= 2.0) && ((x.size(0) != 0) && (x.size(1) != 0)) &&
      (x.size(static_cast<int32_T>(dim) - 1) > 1)) {
    int32_T b;
    int32_T i;
    int32_T k;
    int32_T nd2;
    int32_T npages;
    int32_T pagelen;
    int32_T vstride;
    st.site = &lt_emlrtRSI;
    vstride = 1;
    b = static_cast<int32_T>(dim);
    for (k = 0; k <= b - 2; k++) {
      i = x.size(0);
      vstride *= i;
    }
    pagelen = vstride * x.size(static_cast<int32_T>(dim) - 1);
    st.site = &mt_emlrtRSI;
    npages = 0;
    b = static_cast<int32_T>(dim) + 1;
    for (k = b; k < 3; k++) {
      npages = (npages + 1) * x.size(1) - 1;
    }
    i = x.size(static_cast<int32_T>(dim) - 1) - 1;
    nd2 = (i + 1) >> 1;
    st.site = &nt_emlrtRSI;
    if ((0 <= npages) && (npages > 2147483646)) {
      b_st.site = &ed_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (int32_T j{0}; j <= npages; j++) {
      b = vstride - 1;
      st.site = &ot_emlrtRSI;
      if ((0 <= vstride - 1) && (vstride - 1 > 2147483646)) {
        b_st.site = &ed_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (int32_T b_i{0}; b_i <= b; b_i++) {
        int32_T offset;
        offset = j * pagelen + b_i;
        st.site = &pt_emlrtRSI;
        for (k = 0; k < nd2; k++) {
          real_T tmp;
          int32_T i1;
          int32_T tmp_tmp;
          tmp_tmp = offset + k * vstride;
          tmp = x[tmp_tmp];
          i1 = offset + (i - k) * vstride;
          x[tmp_tmp] = x[i1];
          x[i1] = tmp;
        }
      }
    }
  }
}

} // namespace coder

// End of code generation (flip.cpp)
