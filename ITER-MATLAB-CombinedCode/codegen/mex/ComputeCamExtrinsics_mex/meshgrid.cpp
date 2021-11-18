//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// meshgrid.cpp
//
// Code generation for function 'meshgrid'
//

// Include files
#include "meshgrid.h"
#include "ComputeCamExtrinsics_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo bdb_emlrtRSI{
    31,         // lineNo
    "meshgrid", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\meshgrid.m" // pathName
};

static emlrtRSInfo cdb_emlrtRSI{
    32,         // lineNo
    "meshgrid", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\meshgrid.m" // pathName
};

static emlrtRTEInfo dt_emlrtRTEI{
    20,         // lineNo
    25,         // colNo
    "meshgrid", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\meshgrid.m" // pName
};

static emlrtRTEInfo et_emlrtRTEI{
    21,         // lineNo
    25,         // colNo
    "meshgrid", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\meshgrid.m" // pName
};

// Function Definitions
namespace coder {
void meshgrid(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x,
              const ::coder::array<real_T, 2U> &y,
              ::coder::array<real_T, 2U> &xx, ::coder::array<real_T, 2U> &yy)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T nx;
  int32_T ny;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nx = x.size(1);
  ny = y.size(1);
  xx.set_size(&dt_emlrtRTEI, sp, y.size(1), x.size(1));
  yy.set_size(&et_emlrtRTEI, sp, y.size(1), x.size(1));
  if ((x.size(1) != 0) && (y.size(1) != 0)) {
    st.site = &bdb_emlrtRSI;
    if (x.size(1) > 2147483646) {
      b_st.site = &ed_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (int32_T j{0}; j < nx; j++) {
      st.site = &cdb_emlrtRSI;
      if ((1 <= ny) && (ny > 2147483646)) {
        b_st.site = &ed_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (int32_T i{0}; i < ny; i++) {
        xx[i + xx.size(0) * j] = x[j];
        yy[i + yy.size(0) * j] = y[i];
      }
    }
  }
}

} // namespace coder

// End of code generation (meshgrid.cpp)
