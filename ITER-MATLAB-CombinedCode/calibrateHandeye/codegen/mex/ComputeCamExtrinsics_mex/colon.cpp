//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// colon.cpp
//
// Code generation for function 'colon'
//

// Include files
#include "colon.h"
#include "ComputeCamExtrinsics_mex_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo
    so_emlrtRSI{
        311,               // lineNo
        "eml_float_colon", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" // pathName
    };

static emlrtRTEInfo
    pb_emlrtRTEI{
        411,               // lineNo
        15,                // colNo
        "assert_pmaxsize", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" // pName
    };

static emlrtDCInfo tb_emlrtDCI{
    312,               // lineNo
    28,                // colNo
    "eml_float_colon", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m", // pName
    4 // checkKind
};

static emlrtRTEInfo
    el_emlrtRTEI{
        312,     // lineNo
        20,      // colNo
        "colon", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" // pName
    };

// Function Definitions
namespace coder {
void eml_float_colon(const emlrtStack *sp, real_T a, real_T b,
                     ::coder::array<real_T, 2U> &y)
{
  emlrtStack st;
  real_T apnd;
  real_T cdiff;
  real_T ndbl;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  ndbl = muDoubleScalarFloor((b - a) + 0.5);
  apnd = a + ndbl;
  cdiff = apnd - b;
  if (muDoubleScalarAbs(cdiff) <
      4.4408920985006262E-16 *
          muDoubleScalarMax(muDoubleScalarAbs(a), muDoubleScalarAbs(b))) {
    ndbl++;
    apnd = b;
  } else if (cdiff > 0.0) {
    apnd = a + (ndbl - 1.0);
  } else {
    ndbl++;
  }
  if (ndbl >= 0.0) {
    n = static_cast<int32_T>(ndbl);
  } else {
    n = 0;
  }
  st.site = &so_emlrtRSI;
  if (ndbl > 2.147483647E+9) {
    emlrtErrorWithMessageIdR2018a(&st, &pb_emlrtRTEI, "Coder:MATLAB:pmaxsize",
                                  "Coder:MATLAB:pmaxsize", 0);
  }
  y.set_size(&el_emlrtRTEI, sp, 1, y.size(1));
  if (n < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(n), &tb_emlrtDCI,
                                (emlrtCTX)sp);
  }
  y.set_size(&el_emlrtRTEI, sp, y.size(0), n);
  if (n > 0) {
    y[0] = a;
    if (n > 1) {
      int32_T nm1d2;
      y[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (int32_T k{0}; k <= nm1d2 - 2; k++) {
        y[k + 1] = a + (static_cast<real_T>(k) + 1.0);
        y[(n - k) - 2] = apnd - (static_cast<real_T>(k) + 1.0);
      }
      if (nm1d2 << 1 == n - 1) {
        y[nm1d2] = (a + apnd) / 2.0;
      } else {
        y[nm1d2] = a + static_cast<real_T>(nm1d2);
        y[nm1d2 + 1] = apnd - static_cast<real_T>(nm1d2);
      }
    }
  }
}

} // namespace coder

// End of code generation (colon.cpp)
