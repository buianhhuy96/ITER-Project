//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// generateCheckerboardPoints.cpp
//
// Code generation for function 'generateCheckerboardPoints'
//

// Include files
#include "generateCheckerboardPoints.h"
#include "calibrateOneCamera_mex_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo m_emlrtRSI{
    31,                           // lineNo
    "generateCheckerboardPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\generateCheckerboardPoints"
    ".m" // pathName
};

static emlrtRSInfo n_emlrtRSI{
    46,            // lineNo
    "checkInputs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\generateCheckerboardPoints"
    ".m" // pathName
};

static emlrtRSInfo o_emlrtRSI{
    50,            // lineNo
    "checkInputs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\generateCheckerboardPoints"
    ".m" // pathName
};

static emlrtRSInfo q_emlrtRSI{
    8,                 // lineNo
    "checkSquareSize", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\checkSquareSize.m" // pathName
};

static emlrtRTEInfo c_emlrtRTEI{
    35,                           // lineNo
    9,                            // colNo
    "generateCheckerboardPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\generateCheckerboardPoints"
    ".m" // pName
};

static emlrtRTEInfo d_emlrtRTEI{
    36,                           // lineNo
    13,                           // colNo
    "generateCheckerboardPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\generateCheckerboardPoints"
    ".m" // pName
};

static emlrtRTEInfo f_emlrtRTEI{
    28,           // lineNo
    27,           // colNo
    "validatege", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatege.m" // pName
};

static emlrtDCInfo emlrtDCI{
    33,                           // lineNo
    21,                           // colNo
    "generateCheckerboardPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\generateCheckerboardPoints"
    ".m", // pName
    1     // checkKind
};

static emlrtDCInfo b_emlrtDCI{
    33,                           // lineNo
    21,                           // colNo
    "generateCheckerboardPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\generateCheckerboardPoints"
    ".m", // pName
    4     // checkKind
};

static emlrtDCInfo c_emlrtDCI{
    33,                           // lineNo
    1,                            // colNo
    "generateCheckerboardPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\generateCheckerboardPoints"
    ".m", // pName
    1     // checkKind
};

static emlrtBCInfo w_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    37,                           // lineNo
    21,                           // colNo
    "",                           // aName
    "generateCheckerboardPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\generateCheckerboardPoints"
    ".m", // pName
    0     // checkKind
};

static emlrtBCInfo x_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    38,                           // lineNo
    21,                           // colNo
    "",                           // aName
    "generateCheckerboardPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\generateCheckerboardPoints"
    ".m", // pName
    0     // checkKind
};

static emlrtRTEInfo cd_emlrtRTEI{
    33,                           // lineNo
    1,                            // colNo
    "generateCheckerboardPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\generateCheckerboardPoints"
    ".m" // pName
};

// Function Definitions
namespace Codegen {
namespace coder {
void generateCheckerboardPoints(const emlrtStack *sp,
                                const int32_T boardSize[2], real_T squareSize,
                                ::coder::array<real_T, 2U> &worldPoints)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T boardSize_idx_0_tmp;
  real_T d;
  int32_T i;
  int32_T k;
  uint32_T b_k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &m_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &n_emlrtRSI;
  c_st.site = &p_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (boardSize[k] > 0) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:generateCheckerboardPoints:expectedPositive", 3, 4, 9,
        "boardSize");
  }
  c_st.site = &p_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (boardSize[k] >= 3) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &f_emlrtRTEI, "MATLAB:validateattributes:expectedArray",
        "MATLAB:generateCheckerboardPoints:notGreaterEqual", 9, 4, 9,
        "boardSize", 4, 2, ">=", 4, 1, "3");
  }
  b_st.site = &o_emlrtRSI;
  c_st.site = &q_emlrtRSI;
  d_st.site = &p_emlrtRSI;
  if (squareSize <= 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:generateCheckerboardPoints:expectedPositive", 3, 4, 10,
        "squareSize");
  }
  d_st.site = &p_emlrtRSI;
  if (muDoubleScalarIsInf(squareSize) || muDoubleScalarIsNaN(squareSize)) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &g_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:generateCheckerboardPoints:expectedFinite", 3, 4, 10,
        "squareSize");
  }
  boardSize_idx_0_tmp = static_cast<real_T>(boardSize[0]) - 1.0;
  d = (static_cast<real_T>(boardSize[0]) - 1.0) *
      (static_cast<real_T>(boardSize[1]) - 1.0);
  if (!(d >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d, &b_emlrtDCI, (emlrtCTX)sp);
  }
  if (d != static_cast<int32_T>(d)) {
    emlrtIntegerCheckR2012b(d, &emlrtDCI, (emlrtCTX)sp);
  }
  worldPoints.set_size(&cd_emlrtRTEI, sp, static_cast<int32_T>(d), 2);
  if (d != static_cast<int32_T>(d)) {
    emlrtIntegerCheckR2012b(d, &c_emlrtDCI, (emlrtCTX)sp);
  }
  k = static_cast<int32_T>(d) << 1;
  for (i = 0; i < k; i++) {
    worldPoints[i] = 0.0;
  }
  b_k = 1U;
  i = static_cast<int32_T>(((static_cast<real_T>(boardSize[1]) - 1.0) - 1.0) +
                           1.0);
  emlrtForLoopVectorCheckR2021a(
      0.0, 1.0, (static_cast<real_T>(boardSize[1]) - 1.0) - 1.0, mxDOUBLE_CLASS,
      static_cast<int32_T>(((static_cast<real_T>(boardSize[1]) - 1.0) - 1.0) +
                           1.0),
      &c_emlrtRTEI, (emlrtCTX)sp);
  for (int32_T j{0}; j < i; j++) {
    k = static_cast<int32_T>((boardSize_idx_0_tmp - 1.0) + 1.0);
    emlrtForLoopVectorCheckR2021a(
        0.0, 1.0, boardSize_idx_0_tmp - 1.0, mxDOUBLE_CLASS,
        static_cast<int32_T>((boardSize_idx_0_tmp - 1.0) + 1.0), &d_emlrtRTEI,
        (emlrtCTX)sp);
    for (int32_T b_i{0}; b_i < k; b_i++) {
      int32_T i1;
      i1 = static_cast<int32_T>(b_k + b_i);
      if ((i1 < 1) || (i1 > worldPoints.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, worldPoints.size(0), &w_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      worldPoints[i1 - 1] = static_cast<real_T>(j) * squareSize;
      if (i1 > worldPoints.size(0)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, worldPoints.size(0), &x_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      worldPoints[(i1 + worldPoints.size(0)) - 1] =
          static_cast<real_T>(b_i) * squareSize;
    }
    b_k += static_cast<int32_T>((boardSize_idx_0_tmp - 1.0) + 1.0);
  }
}

} // namespace coder
} // namespace Codegen

// End of code generation (generateCheckerboardPoints.cpp)
