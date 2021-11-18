//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// warning.cpp
//
// Code generation for function 'warning'
//

// Include files
#include "warning.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtMCInfo emlrtMCI{
    14,        // lineNo
    25,        // colNo
    "warning", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\warning.m" // pName
};

static emlrtMCInfo b_emlrtMCI{
    14,        // lineNo
    9,         // colNo
    "warning", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\warning.m" // pName
};

static emlrtRSInfo cjb_emlrtRSI{
    14,        // lineNo
    "warning", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\warning.m" // pathName
};

// Function Declarations
static void b_feval(const emlrtStack *sp, const mxArray *m, const mxArray *m1,
                    emlrtMCInfo *location);

static const mxArray *feval(const emlrtStack *sp, const mxArray *m1,
                            const mxArray *m2, const mxArray *m3,
                            emlrtMCInfo *location);

static const mxArray *feval(const emlrtStack *sp, const mxArray *m1,
                            const mxArray *m2, const mxArray *m3,
                            const mxArray *m4, emlrtMCInfo *location);

static const mxArray *feval(const emlrtStack *sp, const mxArray *m1,
                            const mxArray *m2, emlrtMCInfo *location);

// Function Definitions
static void b_feval(const emlrtStack *sp, const mxArray *m, const mxArray *m1,
                    emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = m;
  pArrays[1] = m1;
  emlrtCallMATLABR2012b((emlrtCTX)sp, 0, nullptr, 2, &pArrays[0],
                        (const char_T *)"feval", true, location);
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *m1,
                            const mxArray *m2, const mxArray *m3,
                            emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  pArrays[2] = m3;
  return emlrtCallMATLABR2012b((emlrtCTX)sp, 1, &m, 3, &pArrays[0],
                               (const char_T *)"feval", true, location);
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *m1,
                            const mxArray *m2, const mxArray *m3,
                            const mxArray *m4, emlrtMCInfo *location)
{
  const mxArray *pArrays[4];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  pArrays[2] = m3;
  pArrays[3] = m4;
  return emlrtCallMATLABR2012b((emlrtCTX)sp, 1, &m, 4, &pArrays[0],
                               (const char_T *)"feval", true, location);
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *m1,
                            const mxArray *m2, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  return emlrtCallMATLABR2012b((emlrtCTX)sp, 1, &m, 2, &pArrays[0],
                               (const char_T *)"feval", true, location);
}

namespace coder {
namespace internal {
void b_warning(const emlrtStack *sp)
{
  static const int32_T b_iv[2]{1, 7};
  static const int32_T iv1[2]{1, 7};
  static const int32_T iv2[2]{1, 28};
  static const char_T msgID[28]{
      'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'o', 'l', 'y', 'f', 'i', 't',
      ':', 'P', 'o', 'l', 'y', 'N', 'o', 't', 'U', 'n', 'i', 'q', 'u', 'e'};
  static const char_T b_u[7]{'m', 'e', 's', 's', 'a', 'g', 'e'};
  static const char_T u[7]{'w', 'a', 'r', 'n', 'i', 'n', 'g'};
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *y;
  st.prev = sp;
  st.tls = sp->tls;
  y = nullptr;
  m = emlrtCreateCharArray(2, &b_iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 7, m, &u[0]);
  emlrtAssign(&y, m);
  b_y = nullptr;
  m = emlrtCreateCharArray(2, &iv1[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 7, m, &b_u[0]);
  emlrtAssign(&b_y, m);
  c_y = nullptr;
  m = emlrtCreateCharArray(2, &iv2[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 28, m, &msgID[0]);
  emlrtAssign(&c_y, m);
  st.site = &cjb_emlrtRSI;
  b_feval(&st, y, feval(&st, b_y, c_y, &emlrtMCI), &b_emlrtMCI);
}

void c_warning(const emlrtStack *sp)
{
  static const int32_T b_iv[2]{1, 7};
  static const int32_T iv1[2]{1, 7};
  static const int32_T iv2[2]{1, 38};
  static const char_T msgID[38]{
      'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'o', 'l', 'y', 'f', 'i',
      't', ':', 'R', 'e', 'p', 'e', 'a', 't', 'e', 'd', 'P', 'o', 'i',
      'n', 't', 's', 'O', 'r', 'R', 'e', 's', 'c', 'a', 'l', 'e'};
  static const char_T b_u[7]{'m', 'e', 's', 's', 'a', 'g', 'e'};
  static const char_T u[7]{'w', 'a', 'r', 'n', 'i', 'n', 'g'};
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *y;
  st.prev = sp;
  st.tls = sp->tls;
  y = nullptr;
  m = emlrtCreateCharArray(2, &b_iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 7, m, &u[0]);
  emlrtAssign(&y, m);
  b_y = nullptr;
  m = emlrtCreateCharArray(2, &iv1[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 7, m, &b_u[0]);
  emlrtAssign(&b_y, m);
  c_y = nullptr;
  m = emlrtCreateCharArray(2, &iv2[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 38, m, &msgID[0]);
  emlrtAssign(&c_y, m);
  st.site = &cjb_emlrtRSI;
  b_feval(&st, y, feval(&st, b_y, c_y, &emlrtMCI), &b_emlrtMCI);
}

void d_warning(const emlrtStack *sp)
{
  static const int32_T b_iv[2]{1, 7};
  static const int32_T iv1[2]{1, 7};
  static const int32_T iv2[2]{1, 21};
  static const char_T msgID[21]{'M', 'A', 'T', 'L', 'A', 'B', ':',
                                's', 'i', 'n', 'g', 'u', 'l', 'a',
                                'r', 'M', 'a', 't', 'r', 'i', 'x'};
  static const char_T b_u[7]{'m', 'e', 's', 's', 'a', 'g', 'e'};
  static const char_T u[7]{'w', 'a', 'r', 'n', 'i', 'n', 'g'};
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *y;
  st.prev = sp;
  st.tls = sp->tls;
  y = nullptr;
  m = emlrtCreateCharArray(2, &b_iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 7, m, &u[0]);
  emlrtAssign(&y, m);
  b_y = nullptr;
  m = emlrtCreateCharArray(2, &iv1[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 7, m, &b_u[0]);
  emlrtAssign(&b_y, m);
  c_y = nullptr;
  m = emlrtCreateCharArray(2, &iv2[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 21, m, &msgID[0]);
  emlrtAssign(&c_y, m);
  st.site = &cjb_emlrtRSI;
  b_feval(&st, y, feval(&st, b_y, c_y, &emlrtMCI), &b_emlrtMCI);
}

void e_warning(const emlrtStack *sp)
{
  static const int32_T b_iv[2]{1, 7};
  static const int32_T iv1[2]{1, 7};
  static const int32_T iv2[2]{1, 33};
  static const char_T msgID[33]{'o', 'p', 't', 'i', 'm', '_', 'c', 'o', 'd',
                                'e', 'g', 'e', 'n', ':', 'c', 'o', 'm', 'm',
                                'o', 'n', ':', 'I', 'n', 'f', 'e', 'a', 's',
                                'i', 'b', 'l', 'e', 'X', '0'};
  static const char_T b_u[7]{'m', 'e', 's', 's', 'a', 'g', 'e'};
  static const char_T u[7]{'w', 'a', 'r', 'n', 'i', 'n', 'g'};
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *y;
  st.prev = sp;
  st.tls = sp->tls;
  y = nullptr;
  m = emlrtCreateCharArray(2, &b_iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 7, m, &u[0]);
  emlrtAssign(&y, m);
  b_y = nullptr;
  m = emlrtCreateCharArray(2, &iv1[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 7, m, &b_u[0]);
  emlrtAssign(&b_y, m);
  c_y = nullptr;
  m = emlrtCreateCharArray(2, &iv2[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 33, m, &msgID[0]);
  emlrtAssign(&c_y, m);
  st.site = &cjb_emlrtRSI;
  b_feval(&st, y, feval(&st, b_y, c_y, &emlrtMCI), &b_emlrtMCI);
}

void warning(const emlrtStack *sp)
{
  static const int32_T b_iv[2]{1, 7};
  static const int32_T iv1[2]{1, 7};
  static const int32_T iv2[2]{1, 43};
  static const char_T msgID[43]{
      'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'F',
      'i', 'n', 'd', 'V', 'e', 'c', 't', 'o', 'r', 'O', 'r', 'i', 'e', 'n', 't',
      'a', 't', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h'};
  static const char_T b_u[7]{'m', 'e', 's', 's', 'a', 'g', 'e'};
  static const char_T u[7]{'w', 'a', 'r', 'n', 'i', 'n', 'g'};
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *y;
  st.prev = sp;
  st.tls = sp->tls;
  y = nullptr;
  m = emlrtCreateCharArray(2, &b_iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 7, m, &u[0]);
  emlrtAssign(&y, m);
  b_y = nullptr;
  m = emlrtCreateCharArray(2, &iv1[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 7, m, &b_u[0]);
  emlrtAssign(&b_y, m);
  c_y = nullptr;
  m = emlrtCreateCharArray(2, &iv2[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 43, m, &msgID[0]);
  emlrtAssign(&c_y, m);
  st.site = &cjb_emlrtRSI;
  b_feval(&st, y, feval(&st, b_y, c_y, &emlrtMCI), &b_emlrtMCI);
}

void warning(const emlrtStack *sp, const char_T varargin_1[14])
{
  static const int32_T b_iv[2]{1, 7};
  static const int32_T iv1[2]{1, 7};
  static const int32_T iv2[2]{1, 33};
  static const int32_T iv3[2]{1, 14};
  static const char_T msgID[33]{'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
                                'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o',
                                'n', 'd', 'i', 't', 'i', 'o', 'n', 'e', 'd',
                                'M', 'a', 't', 'r', 'i', 'x'};
  static const char_T b_u[7]{'m', 'e', 's', 's', 'a', 'g', 'e'};
  static const char_T u[7]{'w', 'a', 'r', 'n', 'i', 'n', 'g'};
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *m;
  const mxArray *y;
  st.prev = sp;
  st.tls = sp->tls;
  y = nullptr;
  m = emlrtCreateCharArray(2, &b_iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 7, m, &u[0]);
  emlrtAssign(&y, m);
  b_y = nullptr;
  m = emlrtCreateCharArray(2, &iv1[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 7, m, &b_u[0]);
  emlrtAssign(&b_y, m);
  c_y = nullptr;
  m = emlrtCreateCharArray(2, &iv2[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 33, m, &msgID[0]);
  emlrtAssign(&c_y, m);
  d_y = nullptr;
  m = emlrtCreateCharArray(2, &iv3[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 14, m, &varargin_1[0]);
  emlrtAssign(&d_y, m);
  st.site = &cjb_emlrtRSI;
  b_feval(&st, y, feval(&st, b_y, c_y, d_y, &emlrtMCI), &b_emlrtMCI);
}

void warning(const emlrtStack *sp, int32_T varargin_1,
             const char_T varargin_2[14])
{
  static const int32_T b_iv[2]{1, 7};
  static const int32_T iv1[2]{1, 7};
  static const int32_T iv2[2]{1, 32};
  static const int32_T iv3[2]{1, 14};
  static const char_T msgID[32]{'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
                                'T', 'L', 'A', 'B', ':', 'r', 'a', 'n',
                                'k', 'D', 'e', 'f', 'i', 'c', 'i', 'e',
                                'n', 't', 'M', 'a', 't', 'r', 'i', 'x'};
  static const char_T b_u[7]{'m', 'e', 's', 's', 'a', 'g', 'e'};
  static const char_T u[7]{'w', 'a', 'r', 'n', 'i', 'n', 'g'};
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *m;
  const mxArray *y;
  st.prev = sp;
  st.tls = sp->tls;
  y = nullptr;
  m = emlrtCreateCharArray(2, &b_iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 7, m, &u[0]);
  emlrtAssign(&y, m);
  b_y = nullptr;
  m = emlrtCreateCharArray(2, &iv1[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 7, m, &b_u[0]);
  emlrtAssign(&b_y, m);
  c_y = nullptr;
  m = emlrtCreateCharArray(2, &iv2[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 32, m, &msgID[0]);
  emlrtAssign(&c_y, m);
  d_y = nullptr;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m) = varargin_1;
  emlrtAssign(&d_y, m);
  e_y = nullptr;
  m = emlrtCreateCharArray(2, &iv3[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 14, m, &varargin_2[0]);
  emlrtAssign(&e_y, m);
  st.site = &cjb_emlrtRSI;
  b_feval(&st, y, feval(&st, b_y, c_y, d_y, e_y, &emlrtMCI), &b_emlrtMCI);
}

} // namespace internal
} // namespace coder

// End of code generation (warning.cpp)
