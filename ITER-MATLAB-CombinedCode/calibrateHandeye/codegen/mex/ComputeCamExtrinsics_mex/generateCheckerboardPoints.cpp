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
#include "ComputeCamExtrinsics_mex_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo mw_emlrtRSI{
    31,                           // lineNo
    "generateCheckerboardPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\generateCheckerboardPoints"
    ".m" // pathName
};

static emlrtRSInfo nw_emlrtRSI{
    46,            // lineNo
    "checkInputs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\generateCheckerboardPoints"
    ".m" // pathName
};

static emlrtRSInfo ow_emlrtRSI{
    50,            // lineNo
    "checkInputs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\generateCheckerboardPoints"
    ".m" // pathName
};

static emlrtRSInfo pw_emlrtRSI{
    8,                 // lineNo
    "checkSquareSize", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\checkSquareSize.m" // pathName
};

static emlrtRTEInfo ac_emlrtRTEI{
    35,                           // lineNo
    9,                            // colNo
    "generateCheckerboardPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\generateCheckerboardPoints"
    ".m" // pName
};

static emlrtRTEInfo bc_emlrtRTEI{
    36,                           // lineNo
    13,                           // colNo
    "generateCheckerboardPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\generateCheckerboardPoints"
    ".m" // pName
};

static emlrtRTEInfo cc_emlrtRTEI{
    28,           // lineNo
    27,           // colNo
    "validatege", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatege.m" // pName
};

static emlrtDCInfo ng_emlrtDCI{
    33,                           // lineNo
    21,                           // colNo
    "generateCheckerboardPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\generateCheckerboardPoints"
    ".m", // pName
    1     // checkKind
};

static emlrtDCInfo og_emlrtDCI{
    33,                           // lineNo
    21,                           // colNo
    "generateCheckerboardPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\generateCheckerboardPoints"
    ".m", // pName
    4     // checkKind
};

static emlrtDCInfo pg_emlrtDCI{
    33,                           // lineNo
    1,                            // colNo
    "generateCheckerboardPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\generateCheckerboardPoints"
    ".m", // pName
    1     // checkKind
};

static emlrtBCInfo mt_emlrtBCI{
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

static emlrtBCInfo nt_emlrtBCI{
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

static emlrtRTEInfo ar_emlrtRTEI{
    33,                           // lineNo
    1,                            // colNo
    "generateCheckerboardPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\generateCheckerboardPoints"
    ".m" // pName
};

// Function Definitions
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
  st.site = &mw_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &nw_emlrtRSI;
  c_st.site = &x_emlrtRSI;
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
        &c_st, &f_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:generateCheckerboardPoints:expectedInteger", 3, 4, 9,
        "boardSize");
  }
  c_st.site = &x_emlrtRSI;
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
        &c_st, &g_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:generateCheckerboardPoints:expectedPositive", 3, 4, 9,
        "boardSize");
  }
  c_st.site = &x_emlrtRSI;
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
        &c_st, &cc_emlrtRTEI, "MATLAB:validateattributes:expectedArray",
        "MATLAB:generateCheckerboardPoints:notGreaterEqual", 9, 4, 9,
        "boardSize", 4, 2, ">=", 4, 1, "3");
  }
  b_st.site = &ow_emlrtRSI;
  c_st.site = &pw_emlrtRSI;
  d_st.site = &x_emlrtRSI;
  if (squareSize <= 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &g_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:generateCheckerboardPoints:expectedPositive", 3, 4, 10,
        "squareSize");
  }
  d_st.site = &x_emlrtRSI;
  if (muDoubleScalarIsInf(squareSize) || muDoubleScalarIsNaN(squareSize)) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:generateCheckerboardPoints:expectedFinite", 3, 4, 10,
        "squareSize");
  }
  boardSize[0]--;
  boardSize[1]--;
  d = boardSize[0] * boardSize[1];
  if (!(d >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d, &og_emlrtDCI, (emlrtCTX)sp);
  }
  d1 = static_cast<int32_T>(muDoubleScalarFloor(d));
  if (d != d1) {
    emlrtIntegerCheckR2012b(d, &ng_emlrtDCI, (emlrtCTX)sp);
  }
  worldPoints.set_size(&ar_emlrtRTEI, sp, static_cast<int32_T>(d), 2);
  if (d != d1) {
    emlrtIntegerCheckR2012b(d, &pg_emlrtDCI, (emlrtCTX)sp);
  }
  k = static_cast<int32_T>(d) << 1;
  for (i = 0; i < k; i++) {
    worldPoints[i] = 0.0;
  }
  b_k = 1U;
  i = static_cast<int32_T>((boardSize[1] - 1.0) + 1.0);
  emlrtForLoopVectorCheckR2021a(
      0.0, 1.0, boardSize[1] - 1.0, mxDOUBLE_CLASS,
      static_cast<int32_T>((boardSize[1] - 1.0) + 1.0), &ac_emlrtRTEI,
      (emlrtCTX)sp);
  for (int32_T j{0}; j < i; j++) {
    k = static_cast<int32_T>((boardSize[0] - 1.0) + 1.0);
    emlrtForLoopVectorCheckR2021a(
        0.0, 1.0, boardSize[0] - 1.0, mxDOUBLE_CLASS,
        static_cast<int32_T>((boardSize[0] - 1.0) + 1.0), &bc_emlrtRTEI,
        (emlrtCTX)sp);
    for (int32_T b_i{0}; b_i < k; b_i++) {
      int32_T i1;
      i1 = static_cast<int32_T>(b_k + b_i);
      if ((i1 < 1) || (i1 > worldPoints.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, worldPoints.size(0), &mt_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      worldPoints[i1 - 1] = static_cast<real_T>(j) * squareSize;
      if (i1 > worldPoints.size(0)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, worldPoints.size(0), &nt_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      worldPoints[(i1 + worldPoints.size(0)) - 1] =
          static_cast<real_T>(b_i) * squareSize;
    }
    b_k += static_cast<int32_T>((boardSize[0] - 1.0) + 1.0);
  }
}

} // namespace coder

// End of code generation (generateCheckerboardPoints.cpp)
