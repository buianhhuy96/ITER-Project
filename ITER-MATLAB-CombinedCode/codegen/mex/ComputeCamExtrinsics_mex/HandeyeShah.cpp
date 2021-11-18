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
#include "ComputeCamExtrinsics_mex_mexutil.h"
#include "det.h"
#include "indexShapeCheck.h"
#include "qrsolve.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "svd1.h"
#include "vAllOrAny.h"
#include "warning.h"
#include "xgeqp3.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstring>

// Variable Definitions
static emlrtRSInfo xh_emlrtRSI{
    44,       // lineNo
    "mpower", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m" // pathName
};

static emlrtRSInfo tbb_emlrtRSI{
    25,            // lineNo
    "HandeyeShah", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\HandeyeShah.m" // pathName
};

static emlrtRSInfo ubb_emlrtRSI{
    28,            // lineNo
    "HandeyeShah", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\HandeyeShah.m" // pathName
};

static emlrtRSInfo vbb_emlrtRSI{
    32,            // lineNo
    "HandeyeShah", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\HandeyeShah.m" // pathName
};

static emlrtRSInfo wbb_emlrtRSI{
    34,            // lineNo
    "HandeyeShah", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\HandeyeShah.m" // pathName
};

static emlrtRSInfo xbb_emlrtRSI{
    37,            // lineNo
    "HandeyeShah", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\HandeyeShah.m" // pathName
};

static emlrtRSInfo ybb_emlrtRSI{
    39,            // lineNo
    "HandeyeShah", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\HandeyeShah.m" // pathName
};

static emlrtRSInfo acb_emlrtRSI{
    41,            // lineNo
    "HandeyeShah", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\HandeyeShah.m" // pathName
};

static emlrtRSInfo bcb_emlrtRSI{
    44,            // lineNo
    "HandeyeShah", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\HandeyeShah.m" // pathName
};

static emlrtRSInfo ccb_emlrtRSI{
    51,            // lineNo
    "HandeyeShah", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\HandeyeShah.m" // pathName
};

static emlrtRSInfo dcb_emlrtRSI{
    53,            // lineNo
    "HandeyeShah", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\HandeyeShah.m" // pathName
};

static emlrtRSInfo ecb_emlrtRSI{
    54,            // lineNo
    "HandeyeShah", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\HandeyeShah.m" // pathName
};

static emlrtECInfo gd_emlrtECI{
    -1,            // nDims
    48,            // lineNo
    5,             // colNo
    "HandeyeShah", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\HandeyeShah.m" // pName
};

static emlrtBCInfo iu_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    54,            // lineNo
    9,             // colNo
    "t",           // aName
    "HandeyeShah", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\HandeyeShah.m", // pName
    0                                                // checkKind
};

static emlrtBCInfo ju_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    53,            // lineNo
    9,             // colNo
    "t",           // aName
    "HandeyeShah", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\HandeyeShah.m", // pName
    0                                                // checkKind
};

static emlrtRTEInfo ds_emlrtRTEI{
    45,            // lineNo
    1,             // colNo
    "HandeyeShah", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\HandeyeShah.m" // pName
};

static emlrtRTEInfo es_emlrtRTEI{
    46,            // lineNo
    1,             // colNo
    "HandeyeShah", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\HandeyeShah.m" // pName
};

static emlrtRTEInfo fs_emlrtRTEI{
    48,            // lineNo
    17,            // colNo
    "HandeyeShah", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\HandeyeShah.m" // pName
};

// Function Definitions
void HandeyeShah(const emlrtStack *sp, const real_T As[240],
                 const real_T Bs[240], real_T b_X[16], real_T Y[16],
                 int32_T *err)
{
  static const int32_T iv3[2]{1, 6};
  static const char_T rfmt[6]{'%', '1', '4', '.', '6', 'e'};
  static const int8_T B[9]{1, 0, 0, 0, 1, 0, 0, 0, 1};
  coder::array<real_T, 2U> A;
  coder::array<real_T, 2U> b_T;
  coder::array<real_T, 1U> b;
  coder::array<real_T, 1U> t;
  coder::array<real_T, 1U> tau;
  coder::array<int32_T, 2U> jpvt;
  coder::array<int8_T, 1U> r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  real_T K[81];
  real_T T[81];
  real_T V1[81];
  real_T c_T[81];
  real_T a[27];
  real_T b_As[18];
  real_T b_v[9];
  real_T b_y1[9];
  real_T s[9];
  real_T u[9];
  real_T v[9];
  real_T x1[9];
  real_T b_x;
  real_T d;
  real_T tol;
  int32_T b_iv[2];
  int32_T iv1[2];
  int32_T b_i;
  int32_T i;
  int32_T j2;
  int32_T kidx;
  int32_T maxmn;
  int32_T minmn;
  char_T str[14];
  int8_T iv2[3];
  boolean_T x[81];
  boolean_T c_x[9];
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 3, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 3, 0);
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
  std::memset(&T[0], 0, 81U * sizeof(real_T));
  for (i = 0; i < 15; i++) {
    covrtLogFor(&emlrtCoverageInstance, 3, 0, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 1);
    kidx = -1;
    b_i = (i + 1) << 2;
    for (maxmn = 0; maxmn < 3; maxmn++) {
      for (j2 = 0; j2 < 3; j2++) {
        minmn = ((j2 + b_i) - 4) << 2;
        for (int32_T i1{0}; i1 < 3; i1++) {
          tol = Bs[i1 + (((maxmn + b_i) - 4) << 2)];
          K[kidx + 1] = tol * As[minmn];
          K[kidx + 2] = tol * As[minmn + 1];
          K[kidx + 3] = tol * As[minmn + 2];
          kidx += 3;
        }
      }
    }
    for (b_i = 0; b_i < 81; b_i++) {
      T[b_i] += K[b_i];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 3, 0, 0, 0);
  //  Check for NaN in T
  for (b_i = 0; b_i < 81; b_i++) {
    x[b_i] = muDoubleScalarIsNaN(T[b_i]);
  }
  kidx = x[0];
  for (j2 = 0; j2 < 80; j2++) {
    kidx += x[j2 + 1];
  }
  st.site = &tbb_emlrtRSI;
  if (covrtLogIf(&emlrtCoverageInstance, 3, 0, 0, kidx != 0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 2);
    *err = -1;
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 3, 3);
  st.site = &ubb_emlrtRSI;
  b_st.site = &cy_emlrtRSI;
  c_st.site = &fy_emlrtRSI;
  b_T.set(&T[0], 9, 9);
  d_st.site = &gy_emlrtRSI;
  p = coder::internal::flatVectorAllOrAny(&d_st, b_T);
  if (p) {
    std::copy(&T[0], &T[81], &c_T[0]);
    b_st.site = &ju_emlrtRSI;
    coder::internal::b_svd(&b_st, c_T, K, s, V1);
  } else {
    std::memset(&T[0], 0, 81U * sizeof(real_T));
    std::copy(&T[0], &T[81], &c_T[0]);
    b_st.site = &sab_emlrtRSI;
    coder::internal::b_svd(&b_st, c_T, K, x1, V1);
    for (b_i = 0; b_i < 81; b_i++) {
      K[b_i] = rtNaN;
      V1[b_i] = rtNaN;
    }
  }
  st.site = &vbb_emlrtRSI;
  b_st.site = &vbb_emlrtRSI;
  tol = coder::det(&b_st, *(real_T(*)[9]) & V1[0]);
  b_st.site = &xh_emlrtRSI;
  c_st.site = &qd_emlrtRSI;
  st.site = &vbb_emlrtRSI;
  b_x = coder::det(&st, *(real_T(*)[9]) & V1[0]);
  b_x = muDoubleScalarSign(b_x);
  tol = b_x / muDoubleScalarPower(muDoubleScalarAbs(tol), 0.33333333333333331);
  //  Check for NaN in x1
  for (b_i = 0; b_i < 9; b_i++) {
    d = tol * V1[b_i];
    x1[b_i] = d;
    c_x[b_i] = muDoubleScalarIsNaN(d);
  }
  kidx = c_x[0];
  for (j2 = 0; j2 < 8; j2++) {
    kidx += c_x[j2 + 1];
  }
  st.site = &wbb_emlrtRSI;
  if (covrtLogIf(&emlrtCoverageInstance, 3, 0, 1, kidx != 0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 4);
    *err = -1;
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 3, 5);
  st.site = &xbb_emlrtRSI;
  coder::svd(&st, x1, u, s, v);
  st.site = &ybb_emlrtRSI;
  b_st.site = &ybb_emlrtRSI;
  tol = coder::det(&b_st, *(real_T(*)[9]) & K[0]);
  b_st.site = &xh_emlrtRSI;
  c_st.site = &qd_emlrtRSI;
  st.site = &ybb_emlrtRSI;
  b_x = coder::det(&st, *(real_T(*)[9]) & K[0]);
  b_x = muDoubleScalarSign(b_x);
  tol = b_x / muDoubleScalarPower(muDoubleScalarAbs(tol), 0.33333333333333331);
  //  Check for NaN in Y
  for (b_i = 0; b_i < 9; b_i++) {
    d = tol * K[b_i];
    b_y1[b_i] = d;
    c_x[b_i] = muDoubleScalarIsNaN(d);
  }
  kidx = c_x[0];
  for (j2 = 0; j2 < 8; j2++) {
    kidx += c_x[j2 + 1];
  }
  st.site = &acb_emlrtRSI;
  if (covrtLogIf(&emlrtCoverageInstance, 3, 0, 2, kidx != 0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 6);
    *err = -1;
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 3, 7);
  st.site = &bcb_emlrtRSI;
  coder::svd(&st, b_y1, x1, s, b_v);
  for (b_i = 0; b_i < 3; b_i++) {
    d = x1[b_i];
    tol = x1[b_i + 3];
    b_x = x1[b_i + 6];
    for (minmn = 0; minmn < 3; minmn++) {
      b_y1[b_i + 3 * minmn] =
          (d * b_v[minmn] + tol * b_v[minmn + 3]) + b_x * b_v[minmn + 6];
    }
  }
  A.set_size(&ds_emlrtRTEI, sp, 45, 6);
  for (b_i = 0; b_i < 270; b_i++) {
    A[b_i] = 0.0;
  }
  b.set_size(&es_emlrtRTEI, sp, 45);
  for (b_i = 0; b_i < 45; b_i++) {
    b[b_i] = 0.0;
  }
  b_iv[0] = 3;
  b_iv[1] = 6;
  iv1[0] = 3;
  iv1[1] = 6;
  for (i = 0; i < 15; i++) {
    int8_T b_i1;
    covrtLogFor(&emlrtCoverageInstance, 3, 0, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 8);
    b_i1 = static_cast<int8_T>(3 * (i + 1) - 2);
    iv2[0] = b_i1;
    iv2[1] = static_cast<int8_T>(b_i1 + 1);
    iv2[2] = static_cast<int8_T>(b_i1 + 2);
    r.set_size(&fs_emlrtRTEI, sp, 6);
    for (b_i = 0; b_i < 6; b_i++) {
      r[b_i] = static_cast<int8_T>(b_i);
    }
    emlrtSubAssignSizeCheckR2012b(&iv1[0], 2, &b_iv[0], 2, &gd_emlrtECI,
                                  (emlrtCTX)sp);
    std::memset(&x1[0], 0, 9U * sizeof(real_T));
    b_i = (i + 1) << 2;
    for (j2 = 0; j2 < 3; j2++) {
      x1[j2 + 3 * j2] = 1.0;
      kidx = ((j2 + b_i) - 4) << 2;
      b_As[3 * j2] = -As[kidx];
      minmn = 3 * j2 + 1;
      b_As[minmn] = -As[kidx + 1];
      maxmn = 3 * j2 + 2;
      b_As[maxmn] = -As[kidx + 2];
      kidx = 3 * (j2 + 3);
      b_As[kidx] = x1[3 * j2];
      b_As[kidx + 1] = x1[minmn];
      b_As[kidx + 2] = x1[maxmn];
    }
    for (minmn = 0; minmn < 6; minmn++) {
      A[(b_i1 + A.size(0) * r[minmn]) - 1] = b_As[3 * minmn];
      A[b_i1 + A.size(0) * r[minmn]] = b_As[3 * minmn + 1];
      A[(b_i1 + A.size(0) * r[minmn]) + 1] = b_As[3 * minmn + 2];
    }
    kidx = -1;
    for (maxmn = 0; maxmn < 3; maxmn++) {
      tol = Bs[maxmn + ((b_i - 1) << 2)];
      for (j2 = 0; j2 < 3; j2++) {
        a[kidx + 1] = tol * static_cast<real_T>(B[3 * j2]);
        a[kidx + 2] = tol * static_cast<real_T>(B[3 * j2 + 1]);
        a[kidx + 3] = tol * static_cast<real_T>(B[3 * j2 + 2]);
        kidx += 3;
      }
    }
    for (minmn = 0; minmn < 3; minmn++) {
      d = 0.0;
      for (maxmn = 0; maxmn < 9; maxmn++) {
        d += a[minmn + 3 * maxmn] * b_y1[maxmn];
      }
      b[iv2[minmn] - 1] = As[minmn + ((b_i - 1) << 2)] - d;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 3, 0, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 3, 9);
  st.site = &ccb_emlrtRSI;
  b_st.site = &iy_emlrtRSI;
  c_st.site = &ky_emlrtRSI;
  d_st.site = &im_emlrtRSI;
  coder::internal::lapack::xgeqp3(&d_st, A, tau, jpvt);
  d_st.site = &gab_emlrtRSI;
  kidx = 0;
  tol = 0.0;
  if (A.size(0) < A.size(1)) {
    minmn = A.size(0);
    maxmn = A.size(1);
  } else {
    minmn = A.size(1);
    maxmn = A.size(0);
  }
  if (minmn > 0) {
    tol =
        muDoubleScalarMin(1.4901161193847656E-8,
                          2.2204460492503131E-15 * static_cast<real_T>(maxmn)) *
        muDoubleScalarAbs(A[0]);
    while ((kidx < minmn) &&
           (!(muDoubleScalarAbs(A[kidx + A.size(0) * kidx]) <= tol))) {
      kidx++;
    }
  }
  if (kidx < minmn) {
    e_st.site = &hab_emlrtRSI;
    y = nullptr;
    m = emlrtCreateCharArray(2, &iv3[0]);
    emlrtInitCharArrayR2013a(&e_st, 6, m, &rfmt[0]);
    emlrtAssign(&y, m);
    b_y = nullptr;
    m = emlrtCreateDoubleScalar(tol);
    emlrtAssign(&b_y, m);
    f_st.site = &xdb_emlrtRSI;
    emlrt_marshallIn(&f_st, b_sprintf(&f_st, y, b_y, &c_emlrtMCI),
                     "<output of sprintf>", str);
    e_st.site = &iab_emlrtRSI;
    coder::internal::warning(&e_st, kidx, str);
  }
  d_st.site = &km_emlrtRSI;
  coder::internal::LSQFromQR(&d_st, A, tau, jpvt, b, kidx, t);
  st.site = &dcb_emlrtRSI;
  coder::internal::indexShapeCheck(&st, t.size(0));
  for (b_i = 0; b_i < 3; b_i++) {
    d = u[b_i];
    tol = u[b_i + 3];
    b_x = u[b_i + 6];
    for (minmn = 0; minmn < 3; minmn++) {
      x1[b_i + 3 * minmn] =
          (d * v[minmn] + tol * v[minmn + 3]) + b_x * v[minmn + 6];
    }
  }
  for (b_i = 0; b_i < 3; b_i++) {
    kidx = b_i << 2;
    b_X[kidx] = x1[3 * b_i];
    b_X[kidx + 1] = x1[3 * b_i + 1];
    b_X[kidx + 2] = x1[3 * b_i + 2];
  }
  if (1 > t.size(0)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, t.size(0), &ju_emlrtBCI, (emlrtCTX)sp);
  }
  b_X[12] = t[0];
  if (2 > t.size(0)) {
    emlrtDynamicBoundsCheckR2012b(2, 1, t.size(0), &ju_emlrtBCI, (emlrtCTX)sp);
  }
  b_X[13] = t[1];
  if (3 > t.size(0)) {
    emlrtDynamicBoundsCheckR2012b(3, 1, t.size(0), &ju_emlrtBCI, (emlrtCTX)sp);
  }
  b_X[14] = t[2];
  b_X[3] = 0.0;
  b_X[7] = 0.0;
  b_X[11] = 0.0;
  b_X[15] = 1.0;
  st.site = &ecb_emlrtRSI;
  coder::internal::indexShapeCheck(&st, t.size(0));
  for (b_i = 0; b_i < 3; b_i++) {
    kidx = b_i << 2;
    Y[kidx] = b_y1[3 * b_i];
    Y[kidx + 1] = b_y1[3 * b_i + 1];
    Y[kidx + 2] = b_y1[3 * b_i + 2];
  }
  if (4 > t.size(0)) {
    emlrtDynamicBoundsCheckR2012b(4, 1, t.size(0), &iu_emlrtBCI, (emlrtCTX)sp);
  }
  Y[12] = t[3];
  if (5 > t.size(0)) {
    emlrtDynamicBoundsCheckR2012b(5, 1, t.size(0), &iu_emlrtBCI, (emlrtCTX)sp);
  }
  Y[13] = t[4];
  if (6 > t.size(0)) {
    emlrtDynamicBoundsCheckR2012b(6, 1, t.size(0), &iu_emlrtBCI, (emlrtCTX)sp);
  }
  Y[14] = t[5];
  Y[3] = 0.0;
  Y[7] = 0.0;
  Y[11] = 0.0;
  Y[15] = 1.0;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

// End of code generation (HandeyeShah.cpp)
