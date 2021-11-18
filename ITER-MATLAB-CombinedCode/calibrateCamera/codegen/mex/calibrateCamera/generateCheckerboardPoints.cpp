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
#include "calibrateCamera_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo s_emlrtRSI{
    31,                           // lineNo
    "generateCheckerboardPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\generateCheckerboardPoints"
    ".m" // pathName
};

static emlrtRSInfo t_emlrtRSI{
    46,            // lineNo
    "checkInputs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\generateCheckerboardPoints"
    ".m" // pathName
};

static emlrtRSInfo u_emlrtRSI{
    50,            // lineNo
    "checkInputs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\generateCheckerboardPoints"
    ".m" // pathName
};

static emlrtRSInfo w_emlrtRSI{
    8,                 // lineNo
    "checkSquareSize", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\checkSquareSize.m" // pathName
};

static emlrtRTEInfo b_emlrtRTEI{
    35,                           // lineNo
    9,                            // colNo
    "generateCheckerboardPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\generateCheckerboardPoints"
    ".m" // pName
};

static emlrtRTEInfo c_emlrtRTEI{
    36,                           // lineNo
    13,                           // colNo
    "generateCheckerboardPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\generateCheckerboardPoints"
    ".m" // pName
};

static emlrtRTEInfo e_emlrtRTEI{
    14,                 // lineNo
    37,                 // colNo
    "validatepositive", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatepositive.m" // pName
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

static emlrtBCInfo p_emlrtBCI{
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

static emlrtBCInfo q_emlrtBCI{
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

static emlrtRTEInfo yc_emlrtRTEI{
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
void generateCheckerboardPoints(const emlrtStack *sp, real_T boardSize[2],
                                real_T squareSize,
                                ::coder::array<real_T, 2U> &worldPoints)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T d;
  real_T d1;
  int32_T i;
  int32_T k;
  uint32_T b_k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &s_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &t_emlrtRSI;
  c_st.site = &v_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(boardSize[k])) &&
        (!muDoubleScalarIsNaN(boardSize[k])) &&
        (muDoubleScalarFloor(boardSize[k]) == boardSize[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:generateCheckerboardPoints:expectedInteger", 3, 4, 9,
        "boardSize");
  }
  c_st.site = &v_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(boardSize[k] <= 0.0)) {
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
  c_st.site = &v_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (boardSize[k] >= 3.0) {
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
  b_st.site = &u_emlrtRSI;
  c_st.site = &w_emlrtRSI;
  d_st.site = &v_emlrtRSI;
  if (squareSize <= 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:generateCheckerboardPoints:expectedPositive", 3, 4, 10,
        "squareSize");
  }
  d_st.site = &v_emlrtRSI;
  if (muDoubleScalarIsInf(squareSize) || muDoubleScalarIsNaN(squareSize)) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &g_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:generateCheckerboardPoints:expectedFinite", 3, 4, 10,
        "squareSize");
  }
  boardSize[0]--;
  boardSize[1]--;
  d = boardSize[0] * boardSize[1];
  if (!(d >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d, &b_emlrtDCI, (emlrtCTX)sp);
  }
  d1 = static_cast<int32_T>(muDoubleScalarFloor(d));
  if (d != d1) {
    emlrtIntegerCheckR2012b(d, &emlrtDCI, (emlrtCTX)sp);
  }
  worldPoints.set_size(&yc_emlrtRTEI, sp, static_cast<int32_T>(d), 2);
  if (d != d1) {
    emlrtIntegerCheckR2012b(d, &c_emlrtDCI, (emlrtCTX)sp);
  }
  k = static_cast<int32_T>(d) << 1;
  for (i = 0; i < k; i++) {
    worldPoints[i] = 0.0;
  }
  b_k = 1U;
  i = static_cast<int32_T>((boardSize[1] - 1.0) + 1.0);
  emlrtForLoopVectorCheckR2021a(
      0.0, 1.0, boardSize[1] - 1.0, mxDOUBLE_CLASS,
      static_cast<int32_T>((boardSize[1] - 1.0) + 1.0), &b_emlrtRTEI,
      (emlrtCTX)sp);
  for (int32_T j{0}; j < i; j++) {
    k = static_cast<int32_T>((boardSize[0] - 1.0) + 1.0);
    emlrtForLoopVectorCheckR2021a(
        0.0, 1.0, boardSize[0] - 1.0, mxDOUBLE_CLASS,
        static_cast<int32_T>((boardSize[0] - 1.0) + 1.0), &c_emlrtRTEI,
        (emlrtCTX)sp);
    for (int32_T b_i{0}; b_i < k; b_i++) {
      int32_T i1;
      i1 = static_cast<int32_T>(b_k + b_i);
      if ((i1 < 1) || (i1 > worldPoints.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, worldPoints.size(0), &p_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      worldPoints[i1 - 1] = static_cast<real_T>(j) * squareSize;
      if (i1 > worldPoints.size(0)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, worldPoints.size(0), &q_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      worldPoints[(i1 + worldPoints.size(0)) - 1] =
          static_cast<real_T>(b_i) * squareSize;
    }
    b_k += static_cast<int32_T>((boardSize[0] - 1.0) + 1.0);
  }
}

} // namespace coder
} // namespace Codegen

// End of code generation (generateCheckerboardPoints.cpp)
