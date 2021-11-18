//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// validateRotationMatrix.cpp
//
// Code generation for function 'validateRotationMatrix'
//

// Include files
#include "validateRotationMatrix.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "det.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo vdb_emlrtRSI{
    6,                        // lineNo
    "validateRotationMatrix", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "inputValidation\\validateRotationMatrix.m" // pathName
};

static emlrtRSInfo wdb_emlrtRSI{
    12,                       // lineNo
    "validateRotationMatrix", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "inputValidation\\validateRotationMatrix.m" // pathName
};

static emlrtRSInfo xdb_emlrtRSI{
    17,                       // lineNo
    "validateRotationMatrix", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "inputValidation\\validateRotationMatrix.m" // pathName
};

static emlrtRTEInfo mc_emlrtRTEI{
    17,                       // lineNo
    1,                        // colNo
    "validateRotationMatrix", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "inputValidation\\validateRotationMatrix.m" // pName
};

static emlrtRTEInfo nc_emlrtRTEI{
    12,                       // lineNo
    1,                        // colNo
    "validateRotationMatrix", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "inputValidation\\validateRotationMatrix.m" // pName
};

// Function Definitions
namespace coder {
namespace vision {
namespace internal {
namespace inputValidation {
void validateRotationMatrix(const emlrtStack *sp, const real_T M[9])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T b_I[9];
  real_T b_M[9];
  real_T x;
  int32_T idx;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &vdb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &t_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if ((!muDoubleScalarIsInf(M[k])) && (!muDoubleScalarIsNaN(M[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:worldToImage:expectedFinite", 3, 4, 14, "rotationMatrix");
  }
  st.site = &wdb_emlrtRSI;
  x = det(&st, M) - 1.0;
  if (muDoubleScalarAbs(x) > 0.001) {
    emlrtErrorWithMessageIdR2018a(
        sp, &nc_emlrtRTEI, "vision:validation:invalid3DRotationMatrix",
        "vision:validation:invalid3DRotationMatrix", 0);
  }
  std::memset(&b_I[0], 0, 9U * sizeof(real_T));
  b_I[0] = 1.0;
  b_I[4] = 1.0;
  b_I[8] = 1.0;
  st.site = &xdb_emlrtRSI;
  for (idx = 0; idx < 3; idx++) {
    for (k = 0; k < 3; k++) {
      b_M[idx + 3 * k] =
          (M[idx] * M[k] + M[idx + 3] * M[k + 3]) + M[idx + 6] * M[k + 6];
    }
  }
  for (k = 0; k < 9; k++) {
    b_I[k] = muDoubleScalarAbs(b_M[k] - b_I[k]);
  }
  if (!muDoubleScalarIsNaN(b_I[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!muDoubleScalarIsNaN(b_I[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    x = b_I[0];
  } else {
    x = b_I[idx - 1];
    idx++;
    for (k = idx; k < 10; k++) {
      real_T d;
      d = b_I[k - 1];
      if (x < d) {
        x = d;
      }
    }
  }
  if (x > 0.001) {
    emlrtErrorWithMessageIdR2018a(
        sp, &mc_emlrtRTEI, "vision:validation:invalid3DRotationMatrix",
        "vision:validation:invalid3DRotationMatrix", 0);
  }
}

} // namespace inputValidation
} // namespace internal
} // namespace vision
} // namespace coder

// End of code generation (validateRotationMatrix.cpp)
