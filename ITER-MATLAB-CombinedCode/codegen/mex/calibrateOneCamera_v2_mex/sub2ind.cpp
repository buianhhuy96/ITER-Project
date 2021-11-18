//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sub2ind.cpp
//
// Code generation for function 'sub2ind'
//

// Include files
#include "sub2ind.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRTEInfo v_emlrtRTEI{
    42,            // lineNo
    19,            // colNo
    "eml_sub2ind", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m" // pName
};

static emlrtRTEInfo w_emlrtRTEI{
    32,            // lineNo
    23,            // colNo
    "eml_sub2ind", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m" // pName
};

static emlrtRTEInfo pf_emlrtRTEI{
    49,        // lineNo
    5,         // colNo
    "sub2ind", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m" // pName
};

// Function Declarations
namespace coder {
static boolean_T allinrange(const ::coder::array<real32_T, 1U> &x, int32_T hi);

}

// Function Definitions
namespace coder {
static boolean_T allinrange(const ::coder::array<real32_T, 1U> &x, int32_T hi)
{
  int32_T k;
  boolean_T p;
  k = 0;
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (k <= x.size(0) - 1) {
      if ((x[k] >= 1.0F) &&
          ((x[k] <= -2.14748365E+9F) ||
           ((x[k] < 2.14748365E+9F) &&
            (hi >= static_cast<int32_T>(muSingleScalarCeil(x[k])))))) {
        k++;
      } else {
        p = false;
        exitg1 = 1;
      }
    } else {
      p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return p;
}

void eml_sub2ind(const emlrtStack *sp, const int32_T siz[2],
                 const ::coder::array<real32_T, 1U> &varargin_1,
                 const ::coder::array<real32_T, 1U> &varargin_2,
                 ::coder::array<int32_T, 1U> &idx)
{
  int32_T k;
  uint32_T b_varargin_1[2];
  uint32_T b_varargin_2[2];
  boolean_T exitg1;
  boolean_T p;
  if (!allinrange(varargin_1, siz[0])) {
    emlrtErrorWithMessageIdR2018a(sp, &v_emlrtRTEI,
                                  "MATLAB:sub2ind:IndexOutOfRange",
                                  "MATLAB:sub2ind:IndexOutOfRange", 0);
  }
  b_varargin_1[0] = static_cast<uint32_T>(varargin_1.size(0));
  b_varargin_1[1] = 1U;
  b_varargin_2[0] = static_cast<uint32_T>(varargin_2.size(0));
  b_varargin_2[1] = 1U;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (static_cast<int32_T>(b_varargin_1[k]) !=
        static_cast<int32_T>(b_varargin_2[k])) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(sp, &w_emlrtRTEI,
                                  "MATLAB:sub2ind:SubscriptVectorSize",
                                  "MATLAB:sub2ind:SubscriptVectorSize", 0);
  }
  if (!allinrange(varargin_2, siz[1])) {
    emlrtErrorWithMessageIdR2018a(sp, &v_emlrtRTEI,
                                  "MATLAB:sub2ind:IndexOutOfRange",
                                  "MATLAB:sub2ind:IndexOutOfRange", 0);
  }
  idx.set_size(&pf_emlrtRTEI, sp, varargin_1.size(0));
  k = varargin_1.size(0);
  for (int32_T i{0}; i < k; i++) {
    idx[i] = static_cast<int32_T>(varargin_1[i]) +
             siz[0] * (static_cast<int32_T>(varargin_2[i]) - 1);
  }
}

} // namespace coder

// End of code generation (sub2ind.cpp)
