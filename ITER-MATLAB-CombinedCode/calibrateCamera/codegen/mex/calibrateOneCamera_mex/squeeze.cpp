//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// squeeze.cpp
//
// Code generation for function 'squeeze'
//

// Include files
#include "squeeze.h"
#include "calibrateOneCamera_mex_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo rn_emlrtRSI{
    38,        // lineNo
    "squeeze", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\squeeze.m" // pathName
};

static emlrtRTEInfo nb_emlrtRTEI{
    59,                  // lineNo
    23,                  // colNo
    "reshapeSizeChecks", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" // pName
};

static emlrtRTEInfo nk_emlrtRTEI{
    38,        // lineNo
    1,         // colNo
    "squeeze", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\squeeze.m" // pName
};

// Function Definitions
namespace Codegen {
namespace coder {
void b_squeeze(const emlrtStack *sp, const ::coder::array<real_T, 3U> &a,
               ::coder::array<real_T, 2U> &b)
{
  emlrtStack st;
  int32_T szb[2];
  int32_T j;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  szb[0] = a.size(0);
  szb[1] = 1;
  if (a.size(2) != 1) {
    j = 0;
    if (a.size(0) != 1) {
      j = 1;
      szb[0] = a.size(0);
    }
    if (a.size(2) != 1) {
      szb[j] = a.size(2);
    }
  }
  st.site = &rn_emlrtRSI;
  nx = a.size(0) * a.size(2);
  j = a.size(0);
  if (1 > a.size(0)) {
    j = 1;
  }
  if (a.size(2) > j) {
    j = a.size(2);
  }
  j = muIntScalarMax_sint32(nx, j);
  if (szb[0] > j) {
    emlrtErrorWithMessageIdR2018a(&st, &ob_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (szb[1] > j) {
    emlrtErrorWithMessageIdR2018a(&st, &ob_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  j = szb[0] * szb[1];
  if (j != nx) {
    emlrtErrorWithMessageIdR2018a(
        &st, &nb_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  b.set_size(&nk_emlrtRTEI, sp, szb[0], szb[1]);
  for (nx = 0; nx < j; nx++) {
    b[nx] = a[nx];
  }
}

void squeeze(const emlrtStack *sp, const ::coder::array<real_T, 3U> &a,
             ::coder::array<real_T, 2U> &b)
{
  emlrtStack st;
  int32_T szb[2];
  int32_T j;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  szb[0] = 1;
  szb[1] = a.size(1);
  if (a.size(2) != 1) {
    j = 0;
    if (a.size(1) != 1) {
      j = 1;
      szb[0] = a.size(1);
    }
    if (a.size(2) != 1) {
      szb[j] = a.size(2);
    }
  }
  st.site = &rn_emlrtRSI;
  nx = a.size(1) * a.size(2);
  j = 1;
  if (a.size(1) > 1) {
    j = a.size(1);
  }
  if (a.size(2) > j) {
    j = a.size(2);
  }
  j = muIntScalarMax_sint32(nx, j);
  if (szb[0] > j) {
    emlrtErrorWithMessageIdR2018a(&st, &ob_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (szb[1] > j) {
    emlrtErrorWithMessageIdR2018a(&st, &ob_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  j = szb[0] * szb[1];
  if (j != nx) {
    emlrtErrorWithMessageIdR2018a(
        &st, &nb_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  b.set_size(&nk_emlrtRTEI, sp, szb[0], szb[1]);
  for (nx = 0; nx < j; nx++) {
    b[nx] = a[nx];
  }
}

} // namespace coder
} // namespace Codegen

// End of code generation (squeeze.cpp)
