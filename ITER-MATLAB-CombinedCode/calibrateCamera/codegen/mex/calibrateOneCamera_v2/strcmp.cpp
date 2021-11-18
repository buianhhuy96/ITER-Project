//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// strcmp.cpp
//
// Code generation for function 'strcmp'
//

// Include files
#include "strcmp.h"
#include "calibrateOneCamera_v2_data.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRSInfo peb_emlrtRSI{
    91,       // lineNo
    "strcmp", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\strcmp.m" // pathName
};

static emlrtRSInfo qeb_emlrtRSI{
    167,          // lineNo
    "loc_strcmp", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\strcmp.m" // pathName
};

static emlrtRSInfo reb_emlrtRSI{
    240,       // lineNo
    "charcmp", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\strcmp.m" // pathName
};

static emlrtRTEInfo oc_emlrtRTEI{
    15,                      // lineNo
    9,                       // colNo
    "assertSupportedString", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\assertSupportedString.m" // pName
};

static const char_T cv3[128]{
    '\x00', '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\x07', '\x08',
    '	',    '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f', '\x10', '\x11',
    '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19', '\x1a',
    '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ',    '!',    '\"',   '#',
    '$',    '%',    '&',    '\'',   '(',    ')',    '*',    '+',    ',',
    '-',    '.',    '/',    '0',    '1',    '2',    '3',    '4',    '5',
    '6',    '7',    '8',    '9',    ':',    ';',    '<',    '=',    '>',
    '?',    '@',    'a',    'b',    'c',    'd',    'e',    'f',    'g',
    'h',    'i',    'j',    'k',    'l',    'm',    'n',    'o',    'p',
    'q',    'r',    's',    't',    'u',    'v',    'w',    'x',    'y',
    'z',    '[',    '\\',   ']',    '^',    '_',    '`',    'a',    'b',
    'c',    'd',    'e',    'f',    'g',    'h',    'i',    'j',    'k',
    'l',    'm',    'n',    'o',    'p',    'q',    'r',    's',    't',
    'u',    'v',    'w',    'x',    'y',    'z',    '{',    '|',    '}',
    '~',    '\x7f'};

// Function Definitions
namespace coder {
namespace internal {
boolean_T b_strcmp(const emlrtStack *sp, const char_T a[7])
{
  static const char_T b_cv[7]{'f', 'o', 'r', 'w', 'a', 'r', 'd'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T kstr;
  boolean_T b_bool;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &peb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &qeb_emlrtRSI;
  b_bool = false;
  kstr = 0;
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (kstr < 7) {
      int32_T i;
      c_st.site = &reb_emlrtRSI;
      i = static_cast<uint8_T>(a[kstr]);
      if (i > 127) {
        emlrtErrorWithMessageIdR2018a(
            &c_st, &oc_emlrtRTEI, "Coder:toolbox:unsupportedString",
            "Coder:toolbox:unsupportedString", 2, 12, 127);
      }
      if (cv3[i] != cv3[static_cast<int32_T>(b_cv[kstr])]) {
        exitg1 = 1;
      } else {
        kstr++;
      }
    } else {
      b_bool = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return b_bool;
}

boolean_T c_strcmp(const emlrtStack *sp, const char_T a[7])
{
  static const char_T b_cv[7]{'c', 'e', 'n', 't', 'r', 'a', 'l'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T kstr;
  boolean_T b_bool;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &peb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &qeb_emlrtRSI;
  b_bool = false;
  kstr = 0;
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (kstr < 7) {
      int32_T i;
      c_st.site = &reb_emlrtRSI;
      i = static_cast<uint8_T>(a[kstr]);
      if (i > 127) {
        emlrtErrorWithMessageIdR2018a(
            &c_st, &oc_emlrtRTEI, "Coder:toolbox:unsupportedString",
            "Coder:toolbox:unsupportedString", 2, 12, 127);
      }
      if (cv3[i] != cv3[static_cast<int32_T>(b_cv[kstr])]) {
        exitg1 = 1;
      } else {
        kstr++;
      }
    } else {
      b_bool = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return b_bool;
}

} // namespace internal
} // namespace coder

// End of code generation (strcmp.cpp)
