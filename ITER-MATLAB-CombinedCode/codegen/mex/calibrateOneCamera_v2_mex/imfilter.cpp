//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// imfilter.cpp
//
// Code generation for function 'imfilter'
//

// Include files
#include "imfilter.h"
#include "assertValidSizeArg.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "coder_array.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo rc_emlrtRSI{
    858,        // lineNo
    "padImage", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pathName
};

static emlrtRSInfo sc_emlrtRSI{
    20,         // lineNo
    "padarray", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\padarray.m" // pathName
};

static emlrtRSInfo tc_emlrtRSI{
    66,         // lineNo
    "padarray", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\padarray.m" // pathName
};

static emlrtRSInfo uc_emlrtRSI{
    72,         // lineNo
    "padarray", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\padarray.m" // pathName
};

static emlrtRSInfo wc_emlrtRSI{
    402,           // lineNo
    "ConstantPad", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\padarray.m" // pathName
};

static emlrtRSInfo xc_emlrtRSI{
    417,           // lineNo
    "ConstantPad", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\padarray.m" // pathName
};

static emlrtRSInfo wt_emlrtRSI{
    55,         // lineNo
    "imfilter", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pathName
};

static emlrtRSInfo xt_emlrtRSI{
    59,         // lineNo
    "imfilter", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pathName
};

static emlrtRSInfo yt_emlrtRSI{
    64,         // lineNo
    "imfilter", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pathName
};

static emlrtRSInfo au_emlrtRSI{
    67,         // lineNo
    "imfilter", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pathName
};

static emlrtRSInfo bu_emlrtRSI{
    68,         // lineNo
    "imfilter", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pathName
};

static emlrtRSInfo cu_emlrtRSI{
    84,         // lineNo
    "imfilter", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pathName
};

static emlrtRSInfo du_emlrtRSI{
    88,         // lineNo
    "imfilter", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pathName
};

static emlrtRSInfo eu_emlrtRSI{
    688,           // lineNo
    "isSeparable", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pathName
};

static emlrtRSInfo fu_emlrtRSI{
    692,           // lineNo
    "isSeparable", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pathName
};

static emlrtRTEInfo i_emlrtRTEI{
    14,                    // lineNo
    37,                    // colNo
    "validatenonnegative", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatenonnegative.m" // pName
};

static emlrtRTEInfo k_emlrtRTEI{
    410,           // lineNo
    21,            // colNo
    "ConstantPad", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\padarray.m" // pName
};

static emlrtRTEInfo l_emlrtRTEI{
    395,           // lineNo
    17,            // colNo
    "ConstantPad", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\padarray.m" // pName
};

static emlrtBCInfo p_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    397,           // lineNo
    19,            // colNo
    "",            // aName
    "ConstantPad", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\padarray.m", // pName
    0 // checkKind
};

static emlrtBCInfo q_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    397,           // lineNo
    21,            // colNo
    "",            // aName
    "ConstantPad", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\padarray.m", // pName
    0 // checkKind
};

static emlrtBCInfo r_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    404,           // lineNo
    19,            // colNo
    "",            // aName
    "ConstantPad", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\padarray.m", // pName
    0 // checkKind
};

static emlrtBCInfo s_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    404,           // lineNo
    21,            // colNo
    "",            // aName
    "ConstantPad", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\padarray.m", // pName
    0 // checkKind
};

static emlrtBCInfo t_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    411,           // lineNo
    19,            // colNo
    "",            // aName
    "ConstantPad", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\padarray.m", // pName
    0 // checkKind
};

static emlrtBCInfo u_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    411,           // lineNo
    21,            // colNo
    "",            // aName
    "ConstantPad", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\padarray.m", // pName
    0 // checkKind
};

static emlrtBCInfo v_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    441,           // lineNo
    102,           // colNo
    "",            // aName
    "ConstantPad", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\padarray.m", // pName
    0 // checkKind
};

static emlrtBCInfo w_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    441,           // lineNo
    104,           // colNo
    "",            // aName
    "ConstantPad", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\padarray.m", // pName
    0 // checkKind
};

static emlrtBCInfo x_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    441,           // lineNo
    19,            // colNo
    "",            // aName
    "ConstantPad", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\padarray.m", // pName
    0 // checkKind
};

static emlrtBCInfo y_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    441,           // lineNo
    58,            // colNo
    "",            // aName
    "ConstantPad", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\padarray.m", // pName
    0 // checkKind
};

static emlrtBCInfo ab_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    418,           // lineNo
    19,            // colNo
    "",            // aName
    "ConstantPad", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\padarray.m", // pName
    0 // checkKind
};

static emlrtBCInfo bb_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    418,           // lineNo
    21,            // colNo
    "",            // aName
    "ConstantPad", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\padarray.m", // pName
    0 // checkKind
};

static emlrtDCInfo d_emlrtDCI{
    250,           // lineNo
    35,            // colNo
    "ConstantPad", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\padarray.m", // pName
    1 // checkKind
};

static emlrtDCInfo e_emlrtDCI{
    250,           // lineNo
    35,            // colNo
    "ConstantPad", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\padarray.m", // pName
    4 // checkKind
};

static emlrtDCInfo eh_emlrtDCI{
    1024,               // lineNo
    32,                 // colNo
    "imfiltercoreAlgo", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m", // pName
    4 // checkKind
};

static emlrtRTEInfo bf_emlrtRTEI{
    250,        // lineNo
    28,         // colNo
    "padarray", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\padarray.m" // pName
};

static emlrtRTEInfo cf_emlrtRTEI{
    858,        // lineNo
    5,          // colNo
    "imfilter", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pName
};

static emlrtRTEInfo fab_emlrtRTEI{
    75,         // lineNo
    13,         // colNo
    "imfilter", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pName
};

static emlrtRTEInfo gab_emlrtRTEI{
    84,         // lineNo
    13,         // colNo
    "imfilter", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pName
};

static emlrtRTEInfo hab_emlrtRTEI{
    905,        // lineNo
    21,         // colNo
    "imfilter", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pName
};

static emlrtRTEInfo iab_emlrtRTEI{
    88,         // lineNo
    13,         // colNo
    "imfilter", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pName
};

static emlrtRTEInfo jab_emlrtRTEI{
    1002,       // lineNo
    28,         // colNo
    "imfilter", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pName
};

static emlrtRTEInfo kab_emlrtRTEI{
    96,         // lineNo
    17,         // colNo
    "imfilter", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pName
};

// Function Definitions
namespace coder {
void b_imfilter(const emlrtStack *sp, ::coder::array<real32_T, 2U> &varargin_1)
{
  static const boolean_T conn[3]{true, false, true};
  array<real32_T, 2U> a;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T kernel[3];
  real_T connDimsT[2];
  real_T nonZeroKernel[2];
  real_T outSizeT[2];
  real_T padSizeT[2];
  real_T startT[2];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  outSizeT[0] = varargin_1.size(0);
  startT[0] = 0.0;
  outSizeT[1] = varargin_1.size(1);
  startT[1] = 1.0;
  if ((varargin_1.size(0) != 0) && (varargin_1.size(1) != 0)) {
    boolean_T tooBig;
    st.site = &pc_emlrtRSI;
    padImage(&st, varargin_1, startT, a);
    st.site = &qc_emlrtRSI;
    b_st.site = &ad_emlrtRSI;
    tooBig = true;
    if ((outSizeT[0] <= 65500.0) || (!(outSizeT[1] > 65500.0))) {
      tooBig = false;
    }
    c_st.site = &bd_emlrtRSI;
    if (!(outSizeT[0] >= 0.0)) {
      emlrtNonNegativeCheckR2012b(outSizeT[0], &eh_emlrtDCI, &c_st);
    }
    if (!(outSizeT[1] >= 0.0)) {
      emlrtNonNegativeCheckR2012b(outSizeT[1], &eh_emlrtDCI, &c_st);
    }
    varargin_1.set_size(&af_emlrtRTEI, &c_st, static_cast<int32_T>(outSizeT[0]),
                        static_cast<int32_T>(outSizeT[1]));
    if (!tooBig) {
      padSizeT[0] = a.size(0);
      padSizeT[1] = a.size(1);
      kernel[0] = -1.0;
      kernel[1] = 0.0;
      kernel[2] = 1.0;
      startT[0] = 1.0;
      startT[1] = 3.0;
      ippfilter_real32(&a[0], &varargin_1[0], &outSizeT[0], 2.0, &padSizeT[0],
                       &kernel[0], &startT[0], true);
    } else {
      padSizeT[0] = a.size(0);
      nonZeroKernel[0] = -1.0;
      connDimsT[0] = 1.0;
      padSizeT[1] = a.size(1);
      nonZeroKernel[1] = 1.0;
      connDimsT[1] = 3.0;
      imfilter_real32(&a[0], &varargin_1[0], 2.0, &outSizeT[0], 2.0,
                      &padSizeT[0], &nonZeroKernel[0], 2.0, &conn[0], 2.0,
                      &connDimsT[0], &startT[0], 2.0, true, true);
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void c_imfilter(const emlrtStack *sp, ::coder::array<real32_T, 2U> &varargin_1)
{
  static const real_T kernel[49]{
      0.0013419653598432805, 0.0040765308179236169, 0.0079399978434782879,
      0.0099158573267036573, 0.0079399978434782879, 0.0040765308179236169,
      0.0013419653598432805, 0.0040765308179236169, 0.012383407207635906,
      0.02411958376255428,   0.030121714902657252,  0.02411958376255428,
      0.012383407207635906,  0.0040765308179236169, 0.0079399978434782879,
      0.02411958376255428,   0.046978534350396596,  0.058669089490849466,
      0.046978534350396596,  0.02411958376255428,   0.0079399978434782879,
      0.0099158573267036573, 0.030121714902657252,  0.058669089490849466,
      0.073268826056005834,  0.058669089490849466,  0.030121714902657252,
      0.0099158573267036573, 0.0079399978434782879, 0.02411958376255428,
      0.046978534350396596,  0.058669089490849466,  0.046978534350396596,
      0.02411958376255428,   0.0079399978434782879, 0.0040765308179236169,
      0.012383407207635906,  0.02411958376255428,   0.030121714902657252,
      0.02411958376255428,   0.012383407207635906,  0.0040765308179236169,
      0.0013419653598432805, 0.0040765308179236169, 0.0079399978434782879,
      0.0099158573267036573, 0.0079399978434782879, 0.0040765308179236169,
      0.0013419653598432805};
  static const real_T nonZeroKernel[49]{
      0.0013419653598432805, 0.0040765308179236169, 0.0079399978434782879,
      0.0099158573267036573, 0.0079399978434782879, 0.0040765308179236169,
      0.0013419653598432805, 0.0040765308179236169, 0.012383407207635906,
      0.02411958376255428,   0.030121714902657252,  0.02411958376255428,
      0.012383407207635906,  0.0040765308179236169, 0.0079399978434782879,
      0.02411958376255428,   0.046978534350396596,  0.058669089490849466,
      0.046978534350396596,  0.02411958376255428,   0.0079399978434782879,
      0.0099158573267036573, 0.030121714902657252,  0.058669089490849466,
      0.073268826056005834,  0.058669089490849466,  0.030121714902657252,
      0.0099158573267036573, 0.0079399978434782879, 0.02411958376255428,
      0.046978534350396596,  0.058669089490849466,  0.046978534350396596,
      0.02411958376255428,   0.0079399978434782879, 0.0040765308179236169,
      0.012383407207635906,  0.02411958376255428,   0.030121714902657252,
      0.02411958376255428,   0.012383407207635906,  0.0040765308179236169,
      0.0013419653598432805, 0.0040765308179236169, 0.0079399978434782879,
      0.0099158573267036573, 0.0079399978434782879, 0.0040765308179236169,
      0.0013419653598432805};
  array<real32_T, 2U> a;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T connDimsT[2];
  real_T outSizeT[2];
  real_T padSizeT[2];
  real_T startT[2];
  boolean_T conn[49];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  outSizeT[0] = varargin_1.size(0);
  startT[0] = 3.0;
  outSizeT[1] = varargin_1.size(1);
  startT[1] = 3.0;
  if ((varargin_1.size(0) != 0) && (varargin_1.size(1) != 0)) {
    boolean_T tooBig;
    st.site = &pc_emlrtRSI;
    padImage(&st, varargin_1, startT, a);
    st.site = &qc_emlrtRSI;
    b_st.site = &ad_emlrtRSI;
    tooBig = true;
    if ((outSizeT[0] <= 65500.0) || (!(outSizeT[1] > 65500.0))) {
      tooBig = false;
    }
    c_st.site = &bd_emlrtRSI;
    if (!(outSizeT[0] >= 0.0)) {
      emlrtNonNegativeCheckR2012b(outSizeT[0], &eh_emlrtDCI, &c_st);
    }
    if (!(outSizeT[1] >= 0.0)) {
      emlrtNonNegativeCheckR2012b(outSizeT[1], &eh_emlrtDCI, &c_st);
    }
    varargin_1.set_size(&af_emlrtRTEI, &c_st, static_cast<int32_T>(outSizeT[0]),
                        static_cast<int32_T>(outSizeT[1]));
    if (!tooBig) {
      padSizeT[0] = a.size(0);
      startT[0] = 7.0;
      padSizeT[1] = a.size(1);
      startT[1] = 7.0;
      ippfilter_real32(&a[0], &varargin_1[0], &outSizeT[0], 2.0, &padSizeT[0],
                       &kernel[0], &startT[0], false);
    } else {
      padSizeT[0] = a.size(0);
      padSizeT[1] = a.size(1);
      for (int32_T i{0}; i < 49; i++) {
        conn[i] = true;
      }
      connDimsT[0] = 7.0;
      connDimsT[1] = 7.0;
      imfilter_real32(&a[0], &varargin_1[0], 2.0, &outSizeT[0], 2.0,
                      &padSizeT[0], &nonZeroKernel[0], 49.0, &conn[0], 2.0,
                      &connDimsT[0], &startT[0], 2.0, true, false);
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void d_imfilter(const emlrtStack *sp, ::coder::array<real32_T, 2U> &varargin_1)
{
  array<real_T, 2U> b;
  array<real_T, 2U> b_a;
  array<real_T, 1U> nonzero_h;
  array<real32_T, 2U> a;
  array<int8_T, 1U> r;
  array<int8_T, 1U> r1;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T a__1[841];
  real_T a__2[841];
  real_T s[841];
  real_T b_s[29];
  real_T hcol[29];
  real_T connDimsT[2];
  real_T outSizeT[2];
  real_T out_size_row[2];
  real_T padSizeT[2];
  real_T startT[2];
  boolean_T conn[841];
  boolean_T x[29];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  outSizeT[0] = varargin_1.size(0);
  startT[0] = 14.0;
  outSizeT[1] = varargin_1.size(1);
  startT[1] = 14.0;
  if ((varargin_1.size(0) != 0) && (varargin_1.size(1) != 0)) {
    real_T tol;
    int32_T i;
    int32_T idx;
    st.site = &wt_emlrtRSI;
    b_st.site = &eu_emlrtRSI;
    svd(&b_st, a__1, s, a__2);
    for (i = 0; i < 29; i++) {
      b_s[i] = s[i + 29 * i];
    }
    b_st.site = &fu_emlrtRSI;
    if (!muDoubleScalarIsNaN(b_s[0])) {
      idx = 1;
    } else {
      boolean_T exitg1;
      idx = 0;
      i = 2;
      exitg1 = false;
      while ((!exitg1) && (i < 30)) {
        if (!muDoubleScalarIsNaN(b_s[i - 1])) {
          idx = i;
          exitg1 = true;
        } else {
          i++;
        }
      }
    }
    if (idx == 0) {
      tol = b_s[0];
    } else {
      tol = b_s[idx - 1];
      idx++;
      for (i = idx; i < 30; i++) {
        real_T d;
        d = b_s[i - 1];
        if (tol < d) {
          tol = d;
        }
      }
    }
    tol = 29.0 * tol * 2.2204460492503131E-16;
    for (i = 0; i < 29; i++) {
      x[i] = (b_s[i] > tol);
    }
    idx = x[0];
    for (i = 0; i < 28; i++) {
      idx += x[i + 1];
    }
    if (idx == 1) {
      int32_T b_i;
      boolean_T tooBig;
      st.site = &xt_emlrtRSI;
      padImage(&st, varargin_1, startT, a);
      st.site = &yt_emlrtRSI;
      svd(&st, a__1, s, a__2);
      for (i = 0; i < 29; i++) {
        b_s[i] = s[i + 29 * i];
      }
      st.site = &au_emlrtRSI;
      if (b_s[0] < 0.0) {
        emlrtErrorWithMessageIdR2018a(
            &st, &x_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
            "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
      }
      tol = muDoubleScalarSqrt(b_s[0]);
      for (b_i = 0; b_i < 29; b_i++) {
        hcol[b_i] = a__1[b_i] * tol;
      }
      st.site = &bu_emlrtRSI;
      if (b_s[0] < 0.0) {
        emlrtErrorWithMessageIdR2018a(
            &st, &x_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
            "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
      }
      tol = muDoubleScalarSqrt(b_s[0]);
      for (b_i = 0; b_i < 29; b_i++) {
        b_s[b_i] = a__2[b_i] * tol;
      }
      b_a.set_size(&fab_emlrtRTEI, sp, a.size(0), a.size(1));
      idx = a.size(0) * a.size(1);
      for (b_i = 0; b_i < idx; b_i++) {
        b_a[b_i] = a[b_i];
      }
      out_size_row[0] = b_a.size(0);
      out_size_row[1] = varargin_1.size(1);
      startT[0] = 0.0;
      startT[1] = 14.0;
      st.site = &cu_emlrtRSI;
      idx = 0;
      for (i = 0; i < 29; i++) {
        if (b_s[i] != 0.0) {
          idx++;
        }
      }
      r.set_size(&gab_emlrtRTEI, &st, idx);
      idx = 0;
      for (i = 0; i < 29; i++) {
        if (b_s[i] != 0.0) {
          r[idx] = static_cast<int8_T>(i + 1);
          idx++;
        }
      }
      b_st.site = &ad_emlrtRSI;
      nonzero_h.set_size(&hab_emlrtRTEI, &b_st, r.size(0));
      idx = r.size(0);
      for (b_i = 0; b_i < idx; b_i++) {
        nonzero_h[b_i] = b_s[r[b_i] - 1];
      }
      for (i = 0; i < 29; i++) {
        x[i] = (b_s[i] != 0.0);
      }
      tooBig = true;
      if ((b_a.size(0) <= 65500) || (!(out_size_row[1] > 65500.0))) {
        tooBig = false;
      }
      if ((static_cast<real_T>(r.size(0)) / 29.0 > 0.05) && (!tooBig)) {
        tooBig = true;
      } else {
        tooBig = false;
      }
      c_st.site = &bd_emlrtRSI;
      if (!(out_size_row[1] >= 0.0)) {
        emlrtNonNegativeCheckR2012b(out_size_row[1], &eh_emlrtDCI, &c_st);
      }
      b.set_size(&af_emlrtRTEI, &c_st, b_a.size(0),
                 static_cast<int32_T>(out_size_row[1]));
      if (tooBig) {
        padSizeT[0] = b_a.size(0);
        startT[0] = 1.0;
        padSizeT[1] = b_a.size(1);
        startT[1] = 29.0;
        ippfilter_real64(&b_a[0], &b[0], &out_size_row[0], 2.0, &padSizeT[0],
                         &b_s[0], &startT[0], true);
      } else {
        padSizeT[0] = b_a.size(0);
        connDimsT[0] = 1.0;
        padSizeT[1] = b_a.size(1);
        connDimsT[1] = 29.0;
        imfilter_real64(&b_a[0], &b[0], 2.0, &out_size_row[0], 2.0,
                        &padSizeT[0], &(nonzero_h.data())[0],
                        static_cast<real_T>(r.size(0)), &x[0], 2.0,
                        &connDimsT[0], &startT[0], 2.0, true, true);
      }
      startT[0] = 14.0;
      startT[1] = 0.0;
      st.site = &du_emlrtRSI;
      idx = 0;
      for (i = 0; i < 29; i++) {
        if (hcol[i] != 0.0) {
          idx++;
        }
      }
      r1.set_size(&iab_emlrtRTEI, &st, idx);
      idx = 0;
      for (i = 0; i < 29; i++) {
        if (hcol[i] != 0.0) {
          r1[idx] = static_cast<int8_T>(i + 1);
          idx++;
        }
      }
      b_st.site = &ad_emlrtRSI;
      nonzero_h.set_size(&hab_emlrtRTEI, &b_st, r1.size(0));
      idx = r1.size(0);
      for (b_i = 0; b_i < idx; b_i++) {
        nonzero_h[b_i] = hcol[r1[b_i] - 1];
      }
      for (i = 0; i < 29; i++) {
        x[i] = (hcol[i] != 0.0);
      }
      tooBig = true;
      if ((outSizeT[0] <= 65500.0) || (!(outSizeT[1] > 65500.0))) {
        tooBig = false;
      }
      if ((static_cast<real_T>(r1.size(0)) / 29.0 > 0.05) && (!tooBig)) {
        tooBig = true;
      } else {
        tooBig = false;
      }
      c_st.site = &bd_emlrtRSI;
      b_a.set_size(&jab_emlrtRTEI, &c_st, b.size(0), b.size(1));
      idx = b.size(0) * b.size(1);
      for (b_i = 0; b_i < idx; b_i++) {
        b_a[b_i] = b[b_i];
      }
      if (!(outSizeT[0] >= 0.0)) {
        emlrtNonNegativeCheckR2012b(outSizeT[0], &eh_emlrtDCI, &c_st);
      }
      if (!(outSizeT[1] >= 0.0)) {
        emlrtNonNegativeCheckR2012b(outSizeT[1], &eh_emlrtDCI, &c_st);
      }
      b.set_size(&af_emlrtRTEI, &c_st, static_cast<int32_T>(outSizeT[0]),
                 static_cast<int32_T>(outSizeT[1]));
      if (tooBig) {
        padSizeT[0] = b_a.size(0);
        startT[0] = 29.0;
        padSizeT[1] = b_a.size(1);
        startT[1] = 1.0;
        ippfilter_real64(&b_a[0], &b[0], &outSizeT[0], 2.0, &padSizeT[0],
                         &hcol[0], &startT[0], true);
      } else {
        padSizeT[0] = b_a.size(0);
        connDimsT[0] = 29.0;
        padSizeT[1] = b_a.size(1);
        connDimsT[1] = 1.0;
        imfilter_real64(&b_a[0], &b[0], 2.0, &outSizeT[0], 2.0, &padSizeT[0],
                        &(nonzero_h.data())[0], static_cast<real_T>(r1.size(0)),
                        &x[0], 2.0, &connDimsT[0], &startT[0], 2.0, true, true);
      }
      varargin_1.set_size(&kab_emlrtRTEI, sp, b.size(0), b.size(1));
      idx = b.size(1);
      for (b_i = 0; b_i < idx; b_i++) {
        i = b.size(0);
        for (int32_T i1{0}; i1 < i; i1++) {
          varargin_1[i1 + varargin_1.size(0) * b_i] =
              static_cast<real32_T>(b[i1 + b.size(0) * b_i]);
        }
      }
    } else {
      boolean_T tooBig;
      st.site = &pc_emlrtRSI;
      padImage(&st, varargin_1, startT, a);
      st.site = &qc_emlrtRSI;
      b_st.site = &ad_emlrtRSI;
      tooBig = true;
      if ((outSizeT[0] <= 65500.0) || (!(outSizeT[1] > 65500.0))) {
        tooBig = false;
      }
      c_st.site = &bd_emlrtRSI;
      if (!(outSizeT[0] >= 0.0)) {
        emlrtNonNegativeCheckR2012b(outSizeT[0], &eh_emlrtDCI, &c_st);
      }
      if (!(outSizeT[1] >= 0.0)) {
        emlrtNonNegativeCheckR2012b(outSizeT[1], &eh_emlrtDCI, &c_st);
      }
      varargin_1.set_size(&af_emlrtRTEI, &c_st,
                          static_cast<int32_T>(outSizeT[0]),
                          static_cast<int32_T>(outSizeT[1]));
      if (!tooBig) {
        padSizeT[0] = a.size(0);
        startT[0] = 29.0;
        padSizeT[1] = a.size(1);
        startT[1] = 29.0;
        ippfilter_real32(&a[0], &varargin_1[0], &outSizeT[0], 2.0, &padSizeT[0],
                         &dv[0], &startT[0], true);
      } else {
        padSizeT[0] = a.size(0);
        padSizeT[1] = a.size(1);
        for (int32_T b_i{0}; b_i < 841; b_i++) {
          conn[b_i] = true;
        }
        connDimsT[0] = 29.0;
        connDimsT[1] = 29.0;
        imfilter_real32(&a[0], &varargin_1[0], 2.0, &outSizeT[0], 2.0,
                        &padSizeT[0], &dv[0], 841.0, &conn[0], 2.0,
                        &connDimsT[0], &startT[0], 2.0, true, true);
      }
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void imfilter(const emlrtStack *sp, ::coder::array<real32_T, 2U> &varargin_1)
{
  static const boolean_T conn[3]{true, false, true};
  array<real32_T, 2U> a;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T kernel[3];
  real_T connDimsT[2];
  real_T nonZeroKernel[2];
  real_T outSizeT[2];
  real_T padSizeT[2];
  real_T startT[2];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  outSizeT[0] = varargin_1.size(0);
  startT[0] = 1.0;
  outSizeT[1] = varargin_1.size(1);
  startT[1] = 0.0;
  if ((varargin_1.size(0) != 0) && (varargin_1.size(1) != 0)) {
    boolean_T tooBig;
    st.site = &pc_emlrtRSI;
    padImage(&st, varargin_1, startT, a);
    st.site = &qc_emlrtRSI;
    b_st.site = &ad_emlrtRSI;
    tooBig = true;
    if ((outSizeT[0] <= 65500.0) || (!(outSizeT[1] > 65500.0))) {
      tooBig = false;
    }
    c_st.site = &bd_emlrtRSI;
    if (!(outSizeT[0] >= 0.0)) {
      emlrtNonNegativeCheckR2012b(outSizeT[0], &eh_emlrtDCI, &c_st);
    }
    if (!(outSizeT[1] >= 0.0)) {
      emlrtNonNegativeCheckR2012b(outSizeT[1], &eh_emlrtDCI, &c_st);
    }
    varargin_1.set_size(&af_emlrtRTEI, &c_st, static_cast<int32_T>(outSizeT[0]),
                        static_cast<int32_T>(outSizeT[1]));
    if (!tooBig) {
      padSizeT[0] = a.size(0);
      padSizeT[1] = a.size(1);
      kernel[0] = -1.0;
      kernel[1] = 0.0;
      kernel[2] = 1.0;
      startT[0] = 3.0;
      startT[1] = 1.0;
      ippfilter_real32(&a[0], &varargin_1[0], &outSizeT[0], 2.0, &padSizeT[0],
                       &kernel[0], &startT[0], true);
    } else {
      padSizeT[0] = a.size(0);
      nonZeroKernel[0] = -1.0;
      connDimsT[0] = 3.0;
      padSizeT[1] = a.size(1);
      nonZeroKernel[1] = 1.0;
      connDimsT[1] = 1.0;
      imfilter_real32(&a[0], &varargin_1[0], 2.0, &outSizeT[0], 2.0,
                      &padSizeT[0], &nonZeroKernel[0], 2.0, &conn[0], 2.0,
                      &connDimsT[0], &startT[0], 2.0, true, true);
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void padImage(const emlrtStack *sp, const ::coder::array<real32_T, 2U> &a_tmp,
              const real_T pad[2], ::coder::array<real32_T, 2U> &a)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T varargin_1[2];
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &rc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &sc_emlrtRSI;
  c_st.site = &t_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!muDoubleScalarIsNaN(pad[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &j_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:padarray:expectedNonNaN", 3, 4, 24, "input number 2, PADSIZE,");
  }
  c_st.site = &t_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(pad[k] < 0.0)) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &i_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonnegative",
        "MATLAB:padarray:expectedNonnegative", 3, 4, 24,
        "input number 2, PADSIZE,");
  }
  c_st.site = &t_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(pad[k])) && (!muDoubleScalarIsNaN(pad[k])) &&
        (muDoubleScalarFloor(pad[k]) == pad[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:padarray:expectedInteger", 3, 4, 24,
        "input number 2, PADSIZE,");
  }
  if ((a_tmp.size(0) == 0) || (a_tmp.size(1) == 0)) {
    real_T sizeB_idx_0;
    real_T sizeB_idx_1;
    sizeB_idx_0 = static_cast<real_T>(a_tmp.size(0)) + 2.0 * pad[0];
    sizeB_idx_1 = static_cast<real_T>(a_tmp.size(1)) + 2.0 * pad[1];
    b_st.site = &tc_emlrtRSI;
    varargin_1[0] = sizeB_idx_0;
    varargin_1[1] = sizeB_idx_1;
    c_st.site = &vc_emlrtRSI;
    internal::assertValidSizeArg(&c_st, varargin_1);
    if (!(sizeB_idx_0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(sizeB_idx_0, &c_emlrtDCI, &b_st);
    }
    if (!(sizeB_idx_1 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(sizeB_idx_1, &c_emlrtDCI, &b_st);
    }
    a.set_size(&cf_emlrtRTEI, &b_st, static_cast<int32_T>(sizeB_idx_0),
               static_cast<int32_T>(sizeB_idx_1));
    k = static_cast<int32_T>(sizeB_idx_0) * static_cast<int32_T>(sizeB_idx_1);
    for (int32_T i{0}; i < k; i++) {
      a[i] = 0.0F;
    }
  } else {
    real_T sizeB_idx_0;
    real_T sizeB_idx_1;
    int32_T b;
    int32_T b_i;
    int32_T i;
    int32_T i1;
    int32_T i2;
    int32_T j;
    b_st.site = &uc_emlrtRSI;
    sizeB_idx_0 = static_cast<real_T>(a_tmp.size(0)) + 2.0 * pad[0];
    if (!(sizeB_idx_0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(sizeB_idx_0, &e_emlrtDCI, &b_st);
    }
    if (sizeB_idx_0 != static_cast<int32_T>(muDoubleScalarFloor(sizeB_idx_0))) {
      emlrtIntegerCheckR2012b(sizeB_idx_0, &d_emlrtDCI, &b_st);
    }
    sizeB_idx_1 = static_cast<real_T>(a_tmp.size(1)) + 2.0 * pad[1];
    if (!(sizeB_idx_1 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(sizeB_idx_1, &e_emlrtDCI, &b_st);
    }
    if (sizeB_idx_1 != static_cast<int32_T>(muDoubleScalarFloor(sizeB_idx_1))) {
      emlrtIntegerCheckR2012b(sizeB_idx_1, &d_emlrtDCI, &b_st);
    }
    a.set_size(&bf_emlrtRTEI, &b_st, static_cast<int32_T>(sizeB_idx_0),
               static_cast<int32_T>(sizeB_idx_1));
    i = static_cast<int32_T>(pad[1]);
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, pad[1], mxDOUBLE_CLASS,
                                  static_cast<int32_T>(pad[1]), &l_emlrtRTEI,
                                  &b_st);
    for (j = 0; j < i; j++) {
      i1 = a.size(0);
      for (b_i = 0; b_i < i1; b_i++) {
        if (b_i + 1 > a.size(0)) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, a.size(0), &p_emlrtBCI,
                                        &b_st);
        }
        if ((static_cast<int32_T>(j + 1U) < 1) ||
            (static_cast<int32_T>(j + 1U) > a.size(1))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1,
                                        a.size(1), &q_emlrtBCI, &b_st);
        }
        a[b_i + a.size(0) * j] = 0.0F;
      }
    }
    k = (a_tmp.size(1) + static_cast<int32_T>(pad[1])) + 1;
    b = a.size(1);
    c_st.site = &wc_emlrtRSI;
    if (((a_tmp.size(1) + static_cast<int32_T>(pad[1])) + 1 <= a.size(1)) &&
        (a.size(1) > 2147483646)) {
      d_st.site = &yc_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (j = k; j <= b; j++) {
      i1 = a.size(0);
      for (b_i = 0; b_i < i1; b_i++) {
        if (b_i + 1 > a.size(0)) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, a.size(0), &r_emlrtBCI,
                                        &b_st);
        }
        if ((j < 1) || (j > a.size(1))) {
          emlrtDynamicBoundsCheckR2012b(j, 1, a.size(1), &s_emlrtBCI, &b_st);
        }
        a[b_i + a.size(0) * (j - 1)] = 0.0F;
      }
    }
    i1 = a_tmp.size(1);
    for (j = 0; j < i1; j++) {
      i2 = static_cast<int32_T>(pad[0]);
      emlrtForLoopVectorCheckR2021a(1.0, 1.0, pad[0], mxDOUBLE_CLASS,
                                    static_cast<int32_T>(pad[0]), &k_emlrtRTEI,
                                    &b_st);
      for (b_i = 0; b_i < i2; b_i++) {
        if ((static_cast<int32_T>(b_i + 1U) < 1) ||
            (static_cast<int32_T>(b_i + 1U) > a.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i + 1U), 1,
                                        a.size(0), &t_emlrtBCI, &b_st);
        }
        k = (j + i) + 1;
        if ((k < 1) || (k > a.size(1))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, a.size(1), &u_emlrtBCI, &b_st);
        }
        a[b_i + a.size(0) * (k - 1)] = 0.0F;
      }
    }
    i1 = a_tmp.size(1);
    for (j = 0; j < i1; j++) {
      k = (static_cast<int32_T>(pad[0]) + a_tmp.size(0)) + 1;
      b = a.size(0);
      c_st.site = &xc_emlrtRSI;
      if (((static_cast<int32_T>(pad[0]) + a_tmp.size(0)) + 1 <= a.size(0)) &&
          (a.size(0) > 2147483646)) {
        d_st.site = &yc_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (b_i = k; b_i <= b; b_i++) {
        if ((b_i < 1) || (b_i > a.size(0))) {
          emlrtDynamicBoundsCheckR2012b(b_i, 1, a.size(0), &ab_emlrtBCI, &b_st);
        }
        i2 = (j + i) + 1;
        if ((i2 < 1) || (i2 > a.size(1))) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, a.size(1), &bb_emlrtBCI, &b_st);
        }
        a[(b_i + a.size(0) * (i2 - 1)) - 1] = 0.0F;
      }
    }
    i1 = a_tmp.size(1);
    for (j = 0; j < i1; j++) {
      i2 = a_tmp.size(0);
      for (b_i = 0; b_i < i2; b_i++) {
        if (b_i + 1 > a_tmp.size(0)) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, a_tmp.size(0), &v_emlrtBCI,
                                        &b_st);
        }
        if (j + 1 > a_tmp.size(1)) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, a_tmp.size(1), &w_emlrtBCI,
                                        &b_st);
        }
        k = (b_i + static_cast<int32_T>(pad[0])) + 1;
        if ((k < 1) || (k > a.size(0))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, a.size(0), &x_emlrtBCI, &b_st);
        }
        b = (j + i) + 1;
        if ((b < 1) || (b > a.size(1))) {
          emlrtDynamicBoundsCheckR2012b(b, 1, a.size(1), &y_emlrtBCI, &b_st);
        }
        a[(k + a.size(0) * (b - 1)) - 1] = a_tmp[b_i + a_tmp.size(0) * j];
      }
    }
  }
}

} // namespace coder

// End of code generation (imfilter.cpp)
