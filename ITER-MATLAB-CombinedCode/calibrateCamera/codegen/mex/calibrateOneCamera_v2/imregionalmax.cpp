//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// imregionalmax.cpp
//
// Code generation for function 'imregionalmax'
//

// Include files
#include "imregionalmax.h"
#include "calibrateOneCamera_v2_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "libmwimregionalmax.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo qe_emlrtRSI{
    14,              // lineNo
    "imregionalmax", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imregionalmax.m" // pathName
};

static emlrtRSInfo re_emlrtRSI{
    28,              // lineNo
    "imregionalmax", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imregionalmax.m" // pathName
};

static emlrtRSInfo se_emlrtRSI{
    35,              // lineNo
    "imregionalmax", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imregionalmax.m" // pathName
};

static emlrtRSInfo te_emlrtRSI{
    37,              // lineNo
    "imregionalmax", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imregionalmax.m" // pathName
};

static emlrtRTEInfo ef_emlrtRTEI{
    35,              // lineNo
    28,              // colNo
    "imregionalmax", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imregionalmax.m" // pName
};

// Function Definitions
namespace coder {
void imregionalmax(const emlrtStack *sp,
                   const ::coder::array<real32_T, 2U> &varargin_1,
                   ::coder::array<boolean_T, 2U> &BW)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T connSizeT[2];
  real_T imSizeT[2];
  int32_T i;
  int32_T k;
  boolean_T conn[9];
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &qe_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &t_emlrtRSI;
  p = true;
  i = varargin_1.size(0) * varargin_1.size(1);
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= i - 1)) {
    if (!muSingleScalarIsNaN(varargin_1[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &l_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:imregionalmax:expectedNonNaN", 3, 4, 18, "input number 1, I,");
  }
  st.site = &re_emlrtRSI;
  st.site = &se_emlrtRSI;
  i = varargin_1.size(0) * varargin_1.size(1) - 1;
  for (k = 0; k <= i; k++) {
    if (muSingleScalarIsNaN(varargin_1[k])) {
      emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI, "MATLAB:nologicalnan",
                                    "MATLAB:nologicalnan", 0);
    }
  }
  BW.set_size(&ef_emlrtRTEI, sp, varargin_1.size(0), varargin_1.size(1));
  st.site = &te_emlrtRSI;
  imSizeT[0] = varargin_1.size(0);
  imSizeT[1] = varargin_1.size(1);
  for (i = 0; i < 9; i++) {
    conn[i] = true;
  }
  connSizeT[0] = 3.0;
  connSizeT[1] = 3.0;
  imregionalmax_real32(&varargin_1[0], &BW[0], 2.0, &imSizeT[0], &conn[0], 2.0,
                       &connSizeT[0]);
}

} // namespace coder

// End of code generation (imregionalmax.cpp)
