//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// HandeyeShah.cpp
//
// Code generation for function 'HandeyeShah'
//

// Include files
#include "HandeyeShah.h"
#include "ComputeCamExtrinsics_mex_data.h"
#include "det.h"
#include "indexShapeCheck.h"
#include "mldivide.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo mp_emlrtRSI{
    29,                  // lineNo
    "reshapeSizeChecks", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" // pathName
};

static emlrtRSInfo rbb_emlrtRSI{
    13,            // lineNo
    "HandeyeShah", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m" // pathName
};

static emlrtRSInfo sbb_emlrtRSI{
    14,            // lineNo
    "HandeyeShah", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m" // pathName
};

static emlrtRSInfo tbb_emlrtRSI{
    25,            // lineNo
    "HandeyeShah", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m" // pathName
};

static emlrtRSInfo ubb_emlrtRSI{
    28,            // lineNo
    "HandeyeShah", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m" // pathName
};

static emlrtRSInfo vbb_emlrtRSI{
    32,            // lineNo
    "HandeyeShah", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m" // pathName
};

static emlrtRSInfo wbb_emlrtRSI{
    34,            // lineNo
    "HandeyeShah", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m" // pathName
};

static emlrtRSInfo xbb_emlrtRSI{
    37,            // lineNo
    "HandeyeShah", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m" // pathName
};

static emlrtRSInfo ybb_emlrtRSI{
    39,            // lineNo
    "HandeyeShah", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m" // pathName
};

static emlrtRSInfo acb_emlrtRSI{
    41,            // lineNo
    "HandeyeShah", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m" // pathName
};

static emlrtRSInfo bcb_emlrtRSI{
    44,            // lineNo
    "HandeyeShah", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m" // pathName
};

static emlrtRSInfo ccb_emlrtRSI{
    51,            // lineNo
    "HandeyeShah", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m" // pathName
};

static emlrtRSInfo dcb_emlrtRSI{
    53,            // lineNo
    "HandeyeShah", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m" // pathName
};

static emlrtRSInfo ecb_emlrtRSI{
    54,            // lineNo
    "HandeyeShah", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m" // pathName
};

static emlrtRTEInfo kc_emlrtRTEI{
    116,               // lineNo
    9,                 // colNo
    "computeDimsData", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" // pName
};

static emlrtECInfo gd_emlrtECI{
    -1,            // nDims
    48,            // lineNo
    5,             // colNo
    "HandeyeShah", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m" // pName
};

static emlrtBCInfo lu_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    49,            // lineNo
    48,            // colNo
    "BB",          // aName
    "HandeyeShah", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m", // pName
    0                      // checkKind
};

static emlrtBCInfo mu_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    49,            // lineNo
    29,            // colNo
    "AA",          // aName
    "HandeyeShah", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m", // pName
    0                      // checkKind
};

static emlrtRTEInfo mc_emlrtRTEI{
    47,            // lineNo
    9,             // colNo
    "HandeyeShah", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m" // pName
};

static emlrtRTEInfo nc_emlrtRTEI{
    19,            // lineNo
    9,             // colNo
    "HandeyeShah", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m" // pName
};

static emlrtDCInfo qg_emlrtDCI{
    18,            // lineNo
    11,            // colNo
    "HandeyeShah", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m", // pName
    1                      // checkKind
};

static emlrtDCInfo rg_emlrtDCI{
    16,            // lineNo
    11,            // colNo
    "HandeyeShah", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m", // pName
    1                      // checkKind
};

static emlrtDCInfo sg_emlrtDCI{
    45,            // lineNo
    11,            // colNo
    "HandeyeShah", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m", // pName
    1                      // checkKind
};

static emlrtDCInfo tg_emlrtDCI{
    45,            // lineNo
    1,             // colNo
    "HandeyeShah", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m", // pName
    1                      // checkKind
};

static emlrtDCInfo ug_emlrtDCI{
    46,            // lineNo
    1,             // colNo
    "HandeyeShah", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m", // pName
    1                      // checkKind
};

static emlrtBCInfo nu_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    49,            // lineNo
    5,             // colNo
    "b",           // aName
    "HandeyeShah", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m", // pName
    0                      // checkKind
};

static emlrtBCInfo ou_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    54,            // lineNo
    9,             // colNo
    "t",           // aName
    "HandeyeShah", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m", // pName
    0                      // checkKind
};

static emlrtBCInfo pu_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    53,            // lineNo
    9,             // colNo
    "t",           // aName
    "HandeyeShah", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m", // pName
    0                      // checkKind
};

static emlrtBCInfo qu_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    48,            // lineNo
    23,            // colNo
    "AA",          // aName
    "HandeyeShah", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m", // pName
    0                      // checkKind
};

static emlrtBCInfo ru_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    48,            // lineNo
    7,             // colNo
    "A",           // aName
    "HandeyeShah", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m", // pName
    0                      // checkKind
};

static emlrtBCInfo su_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    21,            // lineNo
    17,            // colNo
    "BB",          // aName
    "HandeyeShah", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m", // pName
    0                      // checkKind
};

static emlrtBCInfo tu_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    20,            // lineNo
    17,            // colNo
    "AA",          // aName
    "HandeyeShah", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m", // pName
    0                      // checkKind
};

static emlrtRTEInfo is_emlrtRTEI{
    45,            // lineNo
    1,             // colNo
    "HandeyeShah", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m" // pName
};

static emlrtRTEInfo js_emlrtRTEI{
    46,            // lineNo
    1,             // colNo
    "HandeyeShah", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m" // pName
};

static emlrtRTEInfo ks_emlrtRTEI{
    48,            // lineNo
    17,            // colNo
    "HandeyeShah", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\HandeyeShah.m" // pName
};

// Function Definitions
void HandeyeShah(const emlrtStack *sp, const coder::array<real_T, 3U> &As,
                 const coder::array<real_T, 3U> &Bs, real_T b_X[16],
                 real_T Y[16], int32_T *err)
{
  static const int8_T B[9]{1, 0, 0, 0, 1, 0, 0, 0, 1};
  coder::array<real_T, 2U> A;
  coder::array<real_T, 1U> b;
  coder::array<real_T, 1U> t;
  coder::array<int8_T, 1U> r;
  emlrtStack b_st;
  emlrtStack st;
  real_T K[81];
  real_T T[81];
  real_T s[81];
  real_T v[81];
  real_T a[27];
  real_T b_As[18];
  real_T b_s[9];
  real_T b_v[9];
  real_T b_y1[9];
  real_T c_v[9];
  real_T u[9];
  real_T x1[9];
  real_T K_tmp;
  real_T b_n;
  real_T b_x;
  real_T d;
  int32_T Ra_tmp[3];
  int32_T b_b[2];
  int32_T b_iv[2];
  int32_T b_calclen;
  int32_T b_i;
  int32_T b_j1;
  int32_T calclen;
  int32_T i;
  int32_T i1;
  int32_T j2;
  int32_T n;
  int32_T nx;
  boolean_T x[81];
  boolean_T c_x[9];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 2, 0);
  //  Solves the problem AX=YB
  //  using the formulation of
  //
  //  Simultaneous Robot/World and Tool/Flange
  //  Calibration by Solving Homogeneous Transformation
  //  Equations of the form AX=YB
  //  M. Shah
  //
  //  Mili Shah
  //  July 2014
  *err = 0;
  st.site = &rbb_emlrtRSI;
  nx = As.size(2) << 4;
  b_st.site = &mp_emlrtRSI;
  calclen = nx / 4;
  if (calclen > nx) {
    emlrtErrorWithMessageIdR2018a(&b_st, &kc_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  n = 4;
  if (As.size(2) > 4) {
    n = As.size(2);
  }
  if (calclen > muIntScalarMax_sint32(nx, n)) {
    emlrtErrorWithMessageIdR2018a(&st, &tb_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (calclen < 0) {
    emlrtErrorWithMessageIdR2018a(&st, &lc_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  if (calclen << 2 != nx) {
    emlrtErrorWithMessageIdR2018a(
        &st, &ub_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  st.site = &sbb_emlrtRSI;
  nx = Bs.size(2) << 4;
  b_st.site = &mp_emlrtRSI;
  b_calclen = nx / 4;
  if (b_calclen > nx) {
    emlrtErrorWithMessageIdR2018a(&b_st, &kc_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  n = 4;
  if (Bs.size(2) > 4) {
    n = Bs.size(2);
  }
  if (b_calclen > muIntScalarMax_sint32(nx, n)) {
    emlrtErrorWithMessageIdR2018a(&st, &tb_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (b_calclen < 0) {
    emlrtErrorWithMessageIdR2018a(&st, &lc_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  if (b_calclen << 2 != nx) {
    emlrtErrorWithMessageIdR2018a(
        &st, &ub_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  b_n = static_cast<real_T>(calclen) / 4.0;
  d = 9.0 * b_n;
  K_tmp = muDoubleScalarFloor(d);
  if (d != K_tmp) {
    emlrtIntegerCheckR2012b(d, &rg_emlrtDCI, (emlrtCTX)sp);
  }
  std::memset(&T[0], 0, 81U * sizeof(real_T));
  if (d != K_tmp) {
    emlrtIntegerCheckR2012b(d, &qg_emlrtDCI, (emlrtCTX)sp);
  }
  i = static_cast<int32_T>(b_n);
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, b_n, mxDOUBLE_CLASS,
                                static_cast<int32_T>(b_n), &nc_emlrtRTEI,
                                (emlrtCTX)sp);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 2, 0, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 1);
    b_j1 = ((b_i + 1) << 2) - 3;
    Ra_tmp[0] = b_j1;
    Ra_tmp[1] = b_j1 + 1;
    Ra_tmp[2] = b_j1 + 2;
    if (b_j1 > calclen) {
      emlrtDynamicBoundsCheckR2012b(b_j1, 1, calclen, &tu_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (b_j1 + 1 > calclen) {
      emlrtDynamicBoundsCheckR2012b(b_j1 + 1, 1, calclen, &tu_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (b_j1 + 2 > calclen) {
      emlrtDynamicBoundsCheckR2012b(b_j1 + 2, 1, calclen, &tu_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (b_j1 > b_calclen) {
      emlrtDynamicBoundsCheckR2012b(b_j1, 1, b_calclen, &su_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (b_j1 + 1 > b_calclen) {
      emlrtDynamicBoundsCheckR2012b(b_j1 + 1, 1, b_calclen, &su_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (b_j1 + 2 > b_calclen) {
      emlrtDynamicBoundsCheckR2012b(b_j1 + 2, 1, b_calclen, &su_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    nx = -1;
    for (b_j1 = 0; b_j1 < 3; b_j1++) {
      for (j2 = 0; j2 < 3; j2++) {
        for (n = 0; n < 3; n++) {
          K_tmp = Bs[n + 4 * (Ra_tmp[b_j1] - 1)];
          K[nx + 1] = K_tmp * As[4 * (Ra_tmp[j2] - 1)];
          K[nx + 2] = K_tmp * As[4 * (Ra_tmp[j2] - 1) + 1];
          K[nx + 3] = K_tmp * As[4 * (Ra_tmp[j2] - 1) + 2];
          nx += 3;
        }
      }
    }
    for (b_j1 = 0; b_j1 < 81; b_j1++) {
      T[b_j1] += K[b_j1];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 2, 0, 0, 0);
  //  Check for NaN in T
  for (b_j1 = 0; b_j1 < 81; b_j1++) {
    x[b_j1] = muDoubleScalarIsNaN(T[b_j1]);
  }
  nx = x[0];
  for (n = 0; n < 80; n++) {
    nx += x[n + 1];
  }
  st.site = &tbb_emlrtRSI;
  if (covrtLogIf(&emlrtCoverageInstance, 2, 0, 0, nx != 0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 2);
    *err = -1;
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 2, 3);
  st.site = &ubb_emlrtRSI;
  coder::b_svd(&st, T, K, s, v);
  st.site = &vbb_emlrtRSI;
  b_st.site = &vbb_emlrtRSI;
  K_tmp = coder::det(&b_st, *(real_T(*)[9]) & v[0]);
  st.site = &vbb_emlrtRSI;
  b_x = coder::det(&st, *(real_T(*)[9]) & v[0]);
  b_x = muDoubleScalarSign(b_x);
  K_tmp =
      b_x / muDoubleScalarPower(muDoubleScalarAbs(K_tmp), 0.33333333333333331);
  //  Check for NaN in x1
  for (b_j1 = 0; b_j1 < 9; b_j1++) {
    d = K_tmp * v[b_j1];
    x1[b_j1] = d;
    c_x[b_j1] = muDoubleScalarIsNaN(d);
  }
  nx = c_x[0];
  for (n = 0; n < 8; n++) {
    nx += c_x[n + 1];
  }
  st.site = &wbb_emlrtRSI;
  if (covrtLogIf(&emlrtCoverageInstance, 2, 0, 1, nx != 0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 4);
    *err = -1;
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 2, 5);
  st.site = &xbb_emlrtRSI;
  coder::svd(&st, x1, u, b_s, b_v);
  st.site = &ybb_emlrtRSI;
  b_st.site = &ybb_emlrtRSI;
  K_tmp = coder::det(&b_st, *(real_T(*)[9]) & K[0]);
  st.site = &ybb_emlrtRSI;
  b_x = coder::det(&st, *(real_T(*)[9]) & K[0]);
  b_x = muDoubleScalarSign(b_x);
  K_tmp =
      b_x / muDoubleScalarPower(muDoubleScalarAbs(K_tmp), 0.33333333333333331);
  //  Check for NaN in Y
  for (b_j1 = 0; b_j1 < 9; b_j1++) {
    d = K_tmp * K[b_j1];
    b_y1[b_j1] = d;
    c_x[b_j1] = muDoubleScalarIsNaN(d);
  }
  nx = c_x[0];
  for (n = 0; n < 8; n++) {
    nx += c_x[n + 1];
  }
  st.site = &acb_emlrtRSI;
  if (covrtLogIf(&emlrtCoverageInstance, 2, 0, 2, nx != 0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 6);
    *err = -1;
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 2, 7);
  st.site = &bcb_emlrtRSI;
  coder::svd(&st, b_y1, x1, b_s, c_v);
  for (b_j1 = 0; b_j1 < 3; b_j1++) {
    d = x1[b_j1];
    K_tmp = x1[b_j1 + 3];
    b_x = x1[b_j1 + 6];
    for (i1 = 0; i1 < 3; i1++) {
      b_y1[b_j1 + 3 * i1] =
          (d * c_v[i1] + K_tmp * c_v[i1 + 3]) + b_x * c_v[i1 + 6];
    }
  }
  d = 3.0 * b_n;
  K_tmp = muDoubleScalarFloor(d);
  if (d != K_tmp) {
    emlrtIntegerCheckR2012b(d, &sg_emlrtDCI, (emlrtCTX)sp);
  }
  A.set_size(&is_emlrtRTEI, sp, static_cast<int32_T>(d), 6);
  if (d != K_tmp) {
    emlrtIntegerCheckR2012b(d, &tg_emlrtDCI, (emlrtCTX)sp);
  }
  nx = static_cast<int32_T>(d) * 6;
  for (b_j1 = 0; b_j1 < nx; b_j1++) {
    A[b_j1] = 0.0;
  }
  if (d != K_tmp) {
    emlrtIntegerCheckR2012b(d, &ug_emlrtDCI, (emlrtCTX)sp);
  }
  b.set_size(&js_emlrtRTEI, sp, static_cast<int32_T>(d));
  if (d != K_tmp) {
    emlrtIntegerCheckR2012b(d, &ug_emlrtDCI, (emlrtCTX)sp);
  }
  nx = static_cast<int32_T>(d);
  for (b_j1 = 0; b_j1 < nx; b_j1++) {
    b[b_j1] = 0.0;
  }
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, b_n, mxDOUBLE_CLASS,
                                static_cast<int32_T>(b_n), &mc_emlrtRTEI,
                                (emlrtCTX)sp);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 2, 0, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 8);
    b_j1 = 3 * (b_i + 1) - 2;
    Ra_tmp[0] = b_j1;
    Ra_tmp[1] = b_j1 + 1;
    Ra_tmp[2] = b_j1 + 2;
    if (b_j1 > A.size(0)) {
      emlrtDynamicBoundsCheckR2012b(b_j1, 1, A.size(0), &ru_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (b_j1 + 1 > A.size(0)) {
      emlrtDynamicBoundsCheckR2012b(b_j1 + 1, 1, A.size(0), &ru_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (b_j1 + 2 > A.size(0)) {
      emlrtDynamicBoundsCheckR2012b(b_j1 + 2, 1, A.size(0), &ru_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    r.set_size(&ks_emlrtRTEI, sp, 6);
    for (i1 = 0; i1 < 6; i1++) {
      r[i1] = static_cast<int8_T>(i1);
    }
    b_iv[0] = 3;
    b_iv[1] = 6;
    b_b[0] = 3;
    b_b[1] = 6;
    emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &b_b[0], 2, &gd_emlrtECI,
                                  (emlrtCTX)sp);
    std::memset(&x1[0], 0, 9U * sizeof(real_T));
    x1[0] = 1.0;
    x1[4] = 1.0;
    x1[8] = 1.0;
    i1 = (b_i + 1) << 2;
    for (n = 0; n < 3; n++) {
      nx = (n + i1) - 3;
      if (nx > calclen) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, calclen, &qu_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      b_As[3 * n] = -As[4 * (nx - 1)];
      if (nx > calclen) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, calclen, &qu_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      b_As[3 * n + 1] = -As[4 * (nx - 1) + 1];
      if (nx > calclen) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, calclen, &qu_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      b_As[3 * n + 2] = -As[4 * (nx - 1) + 2];
    }
    for (n = 0; n < 3; n++) {
      nx = 3 * (n + 3);
      b_As[nx] = x1[3 * n];
      b_As[nx + 1] = x1[3 * n + 1];
      b_As[nx + 2] = x1[3 * n + 2];
    }
    for (n = 0; n < 6; n++) {
      A[(b_j1 + A.size(0) * r[n]) - 1] = b_As[3 * n];
      A[b_j1 + A.size(0) * r[n]] = b_As[3 * n + 1];
      A[(b_j1 + A.size(0) * r[n]) + 1] = b_As[3 * n + 2];
    }
    b_j1 = 4 * (b_i + 1);
    if (b_j1 > b_calclen) {
      emlrtDynamicBoundsCheckR2012b(b_j1, 1, b_calclen, &lu_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    nx = -1;
    for (b_j1 = 0; b_j1 < 3; b_j1++) {
      K_tmp = Bs[b_j1 + 4 * (i1 - 1)];
      for (j2 = 0; j2 < 3; j2++) {
        a[nx + 1] = K_tmp * static_cast<real_T>(B[3 * j2]);
        a[nx + 2] = K_tmp * static_cast<real_T>(B[3 * j2 + 1]);
        a[nx + 3] = K_tmp * static_cast<real_T>(B[3 * j2 + 2]);
        nx += 3;
      }
    }
    if (i1 > calclen) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, calclen, &mu_emlrtBCI, (emlrtCTX)sp);
    }
    nx = b.size(0);
    for (b_j1 = 0; b_j1 < 3; b_j1++) {
      d = 0.0;
      for (n = 0; n < 9; n++) {
        d += a[b_j1 + 3 * n] * b_y1[n];
      }
      n = Ra_tmp[b_j1];
      if (n > nx) {
        emlrtDynamicBoundsCheckR2012b(n, 1, nx, &nu_emlrtBCI, (emlrtCTX)sp);
      }
      b[n - 1] = As[b_j1 + 4 * (i1 - 1)] - d;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 2, 0, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 2, 9);
  st.site = &ccb_emlrtRSI;
  coder::mldivide(&st, A, b, t);
  st.site = &dcb_emlrtRSI;
  coder::internal::indexShapeCheck(&st, t.size(0));
  for (i = 0; i < 3; i++) {
    d = u[i];
    K_tmp = u[i + 3];
    b_x = u[i + 6];
    for (b_j1 = 0; b_j1 < 3; b_j1++) {
      x1[i + 3 * b_j1] =
          (d * b_v[b_j1] + K_tmp * b_v[b_j1 + 3]) + b_x * b_v[b_j1 + 6];
    }
  }
  for (i = 0; i < 3; i++) {
    nx = i << 2;
    b_X[nx] = x1[3 * i];
    b_X[nx + 1] = x1[3 * i + 1];
    b_X[nx + 2] = x1[3 * i + 2];
  }
  if (1 > t.size(0)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, t.size(0), &pu_emlrtBCI, (emlrtCTX)sp);
  }
  b_X[12] = t[0];
  if (2 > t.size(0)) {
    emlrtDynamicBoundsCheckR2012b(2, 1, t.size(0), &pu_emlrtBCI, (emlrtCTX)sp);
  }
  b_X[13] = t[1];
  if (3 > t.size(0)) {
    emlrtDynamicBoundsCheckR2012b(3, 1, t.size(0), &pu_emlrtBCI, (emlrtCTX)sp);
  }
  b_X[14] = t[2];
  b_X[3] = 0.0;
  b_X[7] = 0.0;
  b_X[11] = 0.0;
  b_X[15] = 1.0;
  st.site = &ecb_emlrtRSI;
  coder::internal::indexShapeCheck(&st, t.size(0));
  for (i = 0; i < 3; i++) {
    nx = i << 2;
    Y[nx] = b_y1[3 * i];
    Y[nx + 1] = b_y1[3 * i + 1];
    Y[nx + 2] = b_y1[3 * i + 2];
  }
  if (4 > t.size(0)) {
    emlrtDynamicBoundsCheckR2012b(4, 1, t.size(0), &ou_emlrtBCI, (emlrtCTX)sp);
  }
  Y[12] = t[3];
  if (5 > t.size(0)) {
    emlrtDynamicBoundsCheckR2012b(5, 1, t.size(0), &ou_emlrtBCI, (emlrtCTX)sp);
  }
  Y[13] = t[4];
  if (6 > t.size(0)) {
    emlrtDynamicBoundsCheckR2012b(6, 1, t.size(0), &ou_emlrtBCI, (emlrtCTX)sp);
  }
  Y[14] = t[5];
  Y[3] = 0.0;
  Y[7] = 0.0;
  Y[11] = 0.0;
  Y[15] = 1.0;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

// End of code generation (HandeyeShah.cpp)
