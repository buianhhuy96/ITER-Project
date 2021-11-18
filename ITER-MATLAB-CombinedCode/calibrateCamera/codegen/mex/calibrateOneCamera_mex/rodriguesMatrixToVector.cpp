//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// rodriguesMatrixToVector.cpp
//
// Code generation for function 'rodriguesMatrixToVector'
//

// Include files
#include "rodriguesMatrixToVector.h"
#include "calibrateOneCamera_mex_data.h"
#include "rt_nonfinite.h"
#include "xzsvdc.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo vv_emlrtRSI{
    32,                        // lineNo
    "rodriguesMatrixToVector", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\rodriguesMatrixToVector.m" // pathName
};

static emlrtRSInfo wv_emlrtRSI{
    41,                        // lineNo
    "rodriguesMatrixToVector", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\rodriguesMatrixToVector.m" // pathName
};

static emlrtRSInfo xv_emlrtRSI{
    98,                        // lineNo
    "rodriguesMatrixToVector", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\rodriguesMatrixToVector.m" // pathName
};

static emlrtRSInfo yv_emlrtRSI{
    34,       // lineNo
    "xgesvd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" // pathName
};

static emlrtRSInfo rw_emlrtRSI{
    113,                                       // lineNo
    "computeRotationVectorForAnglesCloseToPi", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\rodriguesMatrixToVector.m" // pathName
};

static emlrtRSInfo sw_emlrtRSI{
    119,                                       // lineNo
    "computeRotationVectorForAnglesCloseToPi", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\rodriguesMatrixToVector.m" // pathName
};

static emlrtRSInfo tw_emlrtRSI{
    17,    // lineNo
    "max", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" // pathName
};

static emlrtRSInfo
    uw_emlrtRSI{
        38,         // lineNo
        "minOrMax", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" // pathName
    };

static emlrtRTEInfo xb_emlrtRTEI{
    14,     // lineNo
    9,      // colNo
    "acos", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elfun\\acos.m" // pName
};

static emlrtBCInfo ft_emlrtBCI{
    1,                                         // iFirst
    3,                                         // iLast
    119,                                       // lineNo
    48,                                        // colNo
    "",                                        // aName
    "computeRotationVectorForAnglesCloseToPi", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\rodriguesMatrixToVector.m", // pName
    0                                         // checkKind
};

static emlrtBCInfo gt_emlrtBCI{
    1,                                         // iFirst
    3,                                         // iLast
    119,                                       // lineNo
    71,                                        // colNo
    "",                                        // aName
    "computeRotationVectorForAnglesCloseToPi", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\rodriguesMatrixToVector.m", // pName
    0                                         // checkKind
};

// Function Definitions
namespace Codegen {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
void rodriguesMatrixToVector(const emlrtStack *sp, real_T rotationMatrix[9],
                             real_T rotationVector[3])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T U[9];
  real_T V[9];
  real_T b_dv[9];
  real_T S[3];
  real_T absxk;
  real_T s;
  real_T t;
  real_T theta;
  real_T y;
  int32_T idx;
  int32_T k;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &vv_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &ut_emlrtRSI;
  c_st.site = &wt_emlrtRSI;
  d_st.site = &xt_emlrtRSI;
  p = true;
  for (k = 0; k < 9; k++) {
    if ((!p) || (muDoubleScalarIsInf(rotationMatrix[k]) ||
                 muDoubleScalarIsNaN(rotationMatrix[k]))) {
      p = false;
    }
  }
  if (p) {
    b_st.site = &ur_emlrtRSI;
    c_st.site = &vr_emlrtRSI;
    d_st.site = &au_emlrtRSI;
    e_st.site = &yv_emlrtRSI;
    ::Codegen::coder::internal::reflapack::xzsvdc(&e_st, rotationMatrix, U, S,
                                                  V);
  } else {
    b_st.site = &mv_emlrtRSI;
    c_st.site = &vr_emlrtRSI;
    d_st.site = &au_emlrtRSI;
    std::memset(&b_dv[0], 0, 9U * sizeof(real_T));
    e_st.site = &yv_emlrtRSI;
    ::Codegen::coder::internal::reflapack::xzsvdc(&e_st, b_dv, U, S, V);
    for (idx = 0; idx < 9; idx++) {
      U[idx] = rtNaN;
      V[idx] = rtNaN;
    }
  }
  for (idx = 0; idx < 3; idx++) {
    y = U[idx];
    s = U[idx + 3];
    absxk = U[idx + 6];
    for (k = 0; k < 3; k++) {
      rotationMatrix[idx + 3 * k] =
          (y * V[k] + s * V[k + 3]) + absxk * V[k + 6];
    }
  }
  t = (rotationMatrix[0] + rotationMatrix[4]) + rotationMatrix[8];
  theta = (t - 1.0) / 2.0;
  st.site = &wv_emlrtRSI;
  if ((theta < -1.0) || (theta > 1.0)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &xb_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "acos");
  }
  theta = muDoubleScalarAcos(theta);
  rotationVector[0] = rotationMatrix[5] - rotationMatrix[7];
  rotationVector[1] = rotationMatrix[6] - rotationMatrix[2];
  rotationVector[2] = rotationMatrix[1] - rotationMatrix[3];
  y = muDoubleScalarSin(theta);
  if (y >= 0.0001) {
    s = 1.0 / (2.0 * y);
    rotationVector[0] = theta * (rotationVector[0] * s);
    rotationVector[1] = theta * (rotationVector[1] * s);
    rotationVector[2] = theta * (rotationVector[2] * s);
  } else if (t - 1.0 > 0.0) {
    s = 0.5 - (t - 3.0) / 12.0;
    rotationVector[0] *= s;
    rotationVector[1] *= s;
    rotationVector[2] *= s;
  } else {
    int32_T b_s_tmp;
    int32_T iindx;
    int32_T s_tmp;
    st.site = &xv_emlrtRSI;
    b_st.site = &rw_emlrtRSI;
    S[0] = rotationMatrix[0];
    S[1] = rotationMatrix[4];
    S[2] = rotationMatrix[8];
    c_st.site = &tw_emlrtRSI;
    d_st.site = &uw_emlrtRSI;
    if (!muDoubleScalarIsNaN(rotationMatrix[0])) {
      idx = 1;
    } else {
      boolean_T exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 4)) {
        if (!muDoubleScalarIsNaN(S[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      iindx = 0;
    } else {
      s = S[idx - 1];
      iindx = idx - 1;
      idx++;
      for (k = idx; k < 4; k++) {
        y = S[k - 1];
        if (s < y) {
          s = y;
          iindx = k - 1;
        }
      }
    }
    idx = static_cast<int32_T>(
        muDoubleScalarRem(static_cast<real_T>(iindx) + 1.0, 3.0));
    k = static_cast<int32_T>(
        muDoubleScalarRem((static_cast<real_T>(iindx) + 1.0) + 1.0, 3.0));
    b_st.site = &sw_emlrtRSI;
    if (idx + 1 > 3) {
      emlrtDynamicBoundsCheckR2012b(4, 1, 3, &ft_emlrtBCI, &b_st);
    }
    if (k + 1 > 3) {
      emlrtDynamicBoundsCheckR2012b(4, 1, 3, &gt_emlrtBCI, &b_st);
    }
    s_tmp = 3 * idx;
    b_s_tmp = 3 * k;
    s = ((rotationMatrix[iindx + 3 * iindx] - rotationMatrix[idx + s_tmp]) -
         rotationMatrix[k + b_s_tmp]) +
        1.0;
    if (s < 0.0) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &u_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
    }
    s = muDoubleScalarSqrt(s);
    rotationVector[0] = 0.0;
    rotationVector[1] = 0.0;
    rotationVector[2] = 0.0;
    rotationVector[iindx] = s / 2.0;
    rotationVector[idx] =
        (rotationMatrix[idx + 3 * iindx] + rotationMatrix[iindx + s_tmp]) /
        (2.0 * s);
    rotationVector[k] =
        (rotationMatrix[k + 3 * iindx] + rotationMatrix[iindx + b_s_tmp]) /
        (2.0 * s);
    s = 3.3121686421112381E-170;
    absxk = muDoubleScalarAbs(rotationVector[0]);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      s = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    absxk = muDoubleScalarAbs(rotationVector[1]);
    if (absxk > s) {
      t = s / absxk;
      y = y * t * t + 1.0;
      s = absxk;
    } else {
      t = absxk / s;
      y += t * t;
    }
    absxk = muDoubleScalarAbs(rotationVector[2]);
    if (absxk > s) {
      t = s / absxk;
      y = y * t * t + 1.0;
      s = absxk;
    } else {
      t = absxk / s;
      y += t * t;
    }
    y = s * muDoubleScalarSqrt(y);
    rotationVector[0] = theta * rotationVector[0] / y;
    rotationVector[1] = theta * rotationVector[1] / y;
    rotationVector[2] = theta * rotationVector[2] / y;
  }
}

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace Codegen

// End of code generation (rodriguesMatrixToVector.cpp)
