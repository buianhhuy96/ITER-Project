//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// rotm2axang.cpp
//
// Code generation for function 'rotm2axang'
//

// Include files
#include "rotm2axang.h"
#include "ComputeCamExtrinsics_mex_data.h"
#include "all.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "sumMatrixIncludeNaN.h"
#include "svd.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo
    cbb_emlrtRSI{
        35,           // lineNo
        "rotm2axang", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\shared\\robotics\\robotutils\\rotm2axa"
        "ng.m" // pathName
    };

static emlrtRSInfo
    dbb_emlrtRSI{
        44,           // lineNo
        "rotm2axang", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\shared\\robotics\\robotutils\\rotm2axa"
        "ng.m" // pathName
    };

static emlrtRSInfo
    ebb_emlrtRSI{
        53,           // lineNo
        "rotm2axang", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\shared\\robotics\\robotutils\\rotm2axa"
        "ng.m" // pathName
    };

static emlrtRSInfo fbb_emlrtRSI{
    15,              // lineNo
    "normalizeRows", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\robotics\\robotutils\\+robotics\\+"
    "internal\\normalizeRows.m" // pathName
};

static emlrtBCInfo ju_emlrtBCI{
    -1,           // iFirst
    -1,           // iLast
    44,           // lineNo
    41,           // colNo
    "",           // aName
    "rotm2axang", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\robotics\\robotutils\\rotm2axang."
    "m", // pName
    0    // checkKind
};

static emlrtBCInfo ku_emlrtBCI{
    -1,           // iFirst
    -1,           // iLast
    45,           // lineNo
    20,           // colNo
    "",           // aName
    "rotm2axang", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\robotics\\robotutils\\rotm2axang."
    "m", // pName
    0    // checkKind
};

static emlrtECInfo
    fd_emlrtECI{
        -1,           // nDims
        47,           // lineNo
        5,            // colNo
        "rotm2axang", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\shared\\robotics\\robotutils\\rotm2axa"
        "ng.m" // pName
    };

static emlrtRTEInfo
    gs_emlrtRTEI{
        40,           // lineNo
        5,            // colNo
        "rotm2axang", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\shared\\robotics\\robotutils\\rotm2axa"
        "ng.m" // pName
    };

// Function Definitions
namespace coder {
void rotm2axang(const emlrtStack *sp, const real_T R[9], real_T axang[4])
{
  array<real_T, 2U> vspecial;
  array<int8_T, 2U> ii;
  emlrtStack b_st;
  emlrtStack st;
  creal_T u;
  creal_T v;
  real_T V[9];
  real_T a__1[9];
  real_T a__2[9];
  real_T c_I[9];
  real_T y[3];
  real_T br_tmp_tmp;
  real_T v_idx_0;
  real_T v_idx_1;
  real_T v_idx_2;
  int32_T b_iv[3];
  int32_T nz_tmp;
  int8_T b_I[9];
  boolean_T b_v[3];
  boolean_T b;
  boolean_T rEQ0;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  u.re = 0.5 * (((R[0] + R[4]) + R[8]) - 1.0);
  if (!(muDoubleScalarAbs(u.re) > 1.0)) {
    br_tmp_tmp = u.re;
    u.re = muDoubleScalarAcos(br_tmp_tmp);
  } else {
    v.re = u.re + 1.0;
    v.im = 0.0;
    internal::scalar::c_sqrt(&v);
    br_tmp_tmp = u.re;
    u.re = 1.0 - br_tmp_tmp;
    u.im = 0.0;
    internal::scalar::c_sqrt(&u);
    br_tmp_tmp = u.re;
    u.re = 2.0 * muDoubleScalarAtan2(br_tmp_tmp, v.re);
  }
  br_tmp_tmp = 2.0 * muDoubleScalarSin(u.re);
  v_idx_0 = (R[5] - R[7]) / br_tmp_tmp;
  v_idx_1 = (R[6] - R[2]) / br_tmp_tmp;
  v_idx_2 = (R[1] - R[3]) / br_tmp_tmp;
  if (muDoubleScalarIsNaN(u.re) || muDoubleScalarIsInf(u.re)) {
    br_tmp_tmp = rtNaN;
  } else if (u.re == 0.0) {
    br_tmp_tmp = 0.0;
  } else {
    br_tmp_tmp = muDoubleScalarRem(u.re, 3.1415926535897931);
    rEQ0 = (br_tmp_tmp == 0.0);
    if (!rEQ0) {
      real_T q;
      q = muDoubleScalarAbs(u.re / 3.1415926535897931);
      rEQ0 = !(muDoubleScalarAbs(q - muDoubleScalarFloor(q + 0.5)) >
               2.2204460492503131E-16 * q);
    }
    if (rEQ0) {
      br_tmp_tmp = 0.0;
    } else if (u.re < 0.0) {
      br_tmp_tmp += 3.1415926535897931;
    }
  }
  rEQ0 = (br_tmp_tmp == 0.0);
  b_v[0] = (v_idx_0 == 0.0);
  b_v[1] = (v_idx_1 == 0.0);
  b_v[2] = (v_idx_2 == 0.0);
  st.site = &cbb_emlrtRSI;
  b = c_all(b_v);
  nz_tmp = (rEQ0 || b);
  if (rEQ0 || b) {
    int32_T i;
    int32_T loop_ub;
    vspecial.set_size(&gs_emlrtRTEI, sp, 3, nz_tmp);
    loop_ub = 3 * nz_tmp;
    for (i = 0; i < loop_ub; i++) {
      vspecial[i] = 0.0;
    }
    if (rEQ0 || b) {
      ii.set_size(&nl_emlrtRTEI, sp, 1, 1);
      ii[0] = 1;
    } else {
      ii.set_size(&nl_emlrtRTEI, sp, 0, 0);
    }
    for (loop_ub = 0; loop_ub < nz_tmp; loop_ub++) {
      i = ii.size(0) * ii.size(1);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &ju_emlrtBCI, (emlrtCTX)sp);
      }
      for (i = 0; i < 9; i++) {
        b_I[i] = 0;
      }
      b_I[0] = 1;
      b_I[4] = 1;
      b_I[8] = 1;
      for (i = 0; i < 9; i++) {
        c_I[i] = static_cast<real_T>(b_I[i]) - R[i];
      }
      st.site = &dbb_emlrtRSI;
      svd(&st, c_I, a__1, a__2, V);
      if (1 > vspecial.size(1)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, vspecial.size(1), &ku_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      vspecial[0] = V[6];
      vspecial[1] = V[7];
      vspecial[2] = V[8];
    }
    loop_ub = 0;
    if (rEQ0 || b) {
      loop_ub = 1;
    }
    b_iv[0] = 1;
    b_iv[1] = 3;
    b_iv[2] = loop_ub;
    emlrtSubAssignSizeCheckR2012b(&b_iv[0], 3, vspecial.size(), 2, &fd_emlrtECI,
                                  (emlrtCTX)sp);
    loop_ub = 0;
    if (rEQ0 || b) {
      loop_ub = 1;
    }
    for (i = 0; i < loop_ub; i++) {
      v_idx_0 = vspecial[0];
      v_idx_1 = vspecial[1];
      v_idx_2 = vspecial[2];
    }
  }
  st.site = &ebb_emlrtRSI;
  y[0] = v_idx_0 * v_idx_0;
  y[1] = v_idx_1 * v_idx_1;
  y[2] = v_idx_2 * v_idx_2;
  br_tmp_tmp = sumColumnB(y);
  b_st.site = &fbb_emlrtRSI;
  if (br_tmp_tmp < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &ab_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  br_tmp_tmp = muDoubleScalarSqrt(br_tmp_tmp);
  br_tmp_tmp = 1.0 / br_tmp_tmp;
  v_idx_0 *= br_tmp_tmp;
  v_idx_1 *= br_tmp_tmp;
  v_idx_2 *= br_tmp_tmp;
  axang[0] = v_idx_0;
  axang[1] = v_idx_1;
  axang[2] = v_idx_2;
  axang[3] = u.re;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace coder

// End of code generation (rotm2axang.cpp)
