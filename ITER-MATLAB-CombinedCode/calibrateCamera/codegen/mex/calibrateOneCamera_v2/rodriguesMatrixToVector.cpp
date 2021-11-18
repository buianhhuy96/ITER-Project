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
#include "calibrateOneCamera_v2_data.h"
#include "rt_nonfinite.h"
#include "xzsvdc.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo nu_emlrtRSI{
    34,       // lineNo
    "xgesvd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" // pathName
};

static emlrtRSInfo fbb_emlrtRSI{
    32,                        // lineNo
    "rodriguesMatrixToVector", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\rodriguesMatrixToVector.m" // pathName
};

static emlrtRSInfo gbb_emlrtRSI{
    41,                        // lineNo
    "rodriguesMatrixToVector", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\rodriguesMatrixToVector.m" // pathName
};

static emlrtRSInfo hbb_emlrtRSI{
    98,                        // lineNo
    "rodriguesMatrixToVector", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\rodriguesMatrixToVector.m" // pathName
};

static emlrtRSInfo ibb_emlrtRSI{
    113,                                       // lineNo
    "computeRotationVectorForAnglesCloseToPi", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\rodriguesMatrixToVector.m" // pathName
};

static emlrtRSInfo jbb_emlrtRSI{
    119,                                       // lineNo
    "computeRotationVectorForAnglesCloseToPi", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\rodriguesMatrixToVector.m" // pathName
};

static emlrtRSInfo kbb_emlrtRSI{
    17,    // lineNo
    "max", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" // pathName
};

static emlrtRSInfo
    lbb_emlrtRSI{
        38,         // lineNo
        "minOrMax", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" // pathName
    };

static emlrtRTEInfo ec_emlrtRTEI{
    14,     // lineNo
    9,      // colNo
    "acos", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elfun\\acos.m" // pName
};

static emlrtBCInfo du_emlrtBCI{
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

static emlrtBCInfo eu_emlrtBCI{
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

static emlrtBCInfo fu_emlrtBCI{
    1,                                         // iFirst
    3,                                         // iLast
    122,                                       // lineNo
    24,                                        // colNo
    "",                                        // aName
    "computeRotationVectorForAnglesCloseToPi", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\rodriguesMatrixToVector.m", // pName
    0                                         // checkKind
};

static emlrtBCInfo gu_emlrtBCI{
    1,                                         // iFirst
    3,                                         // iLast
    123,                                       // lineNo
    24,                                        // colNo
    "",                                        // aName
    "computeRotationVectorForAnglesCloseToPi", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\rodriguesMatrixToVector.m", // pName
    0                                         // checkKind
};

// Function Definitions
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
  int32_T i;
  int32_T i1;
  int32_T k;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &fbb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &yx_emlrtRSI;
  c_st.site = &cy_emlrtRSI;
  d_st.site = &dy_emlrtRSI;
  p = true;
  for (k = 0; k < 9; k++) {
    if ((!p) || (muDoubleScalarIsInf(rotationMatrix[k]) ||
                 muDoubleScalarIsNaN(rotationMatrix[k]))) {
      p = false;
    }
  }
  if (p) {
    b_st.site = &gu_emlrtRSI;
    c_st.site = &hu_emlrtRSI;
    d_st.site = &ku_emlrtRSI;
    e_st.site = &nu_emlrtRSI;
    ::coder::internal::reflapack::xzsvdc(&e_st, rotationMatrix, U, S, V);
  } else {
    b_st.site = &sab_emlrtRSI;
    c_st.site = &hu_emlrtRSI;
    d_st.site = &ku_emlrtRSI;
    std::memset(&b_dv[0], 0, 9U * sizeof(real_T));
    e_st.site = &nu_emlrtRSI;
    ::coder::internal::reflapack::xzsvdc(&e_st, b_dv, U, S, V);
    for (i = 0; i < 9; i++) {
      U[i] = rtNaN;
      V[i] = rtNaN;
    }
  }
  for (i = 0; i < 3; i++) {
    y = U[i];
    s = U[i + 3];
    absxk = U[i + 6];
    for (i1 = 0; i1 < 3; i1++) {
      rotationMatrix[i + 3 * i1] =
          (y * V[i1] + s * V[i1 + 3]) + absxk * V[i1 + 6];
    }
  }
  t = (rotationMatrix[0] + rotationMatrix[4]) + rotationMatrix[8];
  theta = (t - 1.0) / 2.0;
  st.site = &gbb_emlrtRSI;
  if ((theta < -1.0) || (theta > 1.0)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &ec_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
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
    int32_T idx;
    int32_T iindx;
    st.site = &hbb_emlrtRSI;
    b_st.site = &ibb_emlrtRSI;
    S[0] = rotationMatrix[0];
    S[1] = rotationMatrix[4];
    S[2] = rotationMatrix[8];
    c_st.site = &kbb_emlrtRSI;
    d_st.site = &lbb_emlrtRSI;
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
    b_st.site = &jbb_emlrtRSI;
    i = static_cast<int32_T>(
            muDoubleScalarRem(static_cast<real_T>(iindx) + 1.0, 3.0)) +
        1;
    if (i > 3) {
      emlrtDynamicBoundsCheckR2012b(4, 1, 3, &du_emlrtBCI, &b_st);
    }
    i1 = static_cast<int32_T>(
             muDoubleScalarRem((static_cast<real_T>(iindx) + 1.0) + 1.0, 3.0)) +
         1;
    if (i1 > 3) {
      emlrtDynamicBoundsCheckR2012b(4, 1, 3, &eu_emlrtBCI, &b_st);
    }
    idx = 3 * (i - 1);
    k = 3 * (i1 - 1);
    s = ((rotationMatrix[iindx + 3 * iindx] - rotationMatrix[(i + idx) - 1]) -
         rotationMatrix[(i1 + k) - 1]) +
        1.0;
    if (s < 0.0) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &x_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
    }
    s = muDoubleScalarSqrt(s);
    rotationVector[0] = 0.0;
    rotationVector[1] = 0.0;
    rotationVector[2] = 0.0;
    rotationVector[iindx] = s / 2.0;
    if (i > 3) {
      emlrtDynamicBoundsCheckR2012b(4, 1, 3, &fu_emlrtBCI, &st);
    }
    rotationVector[i - 1] =
        (rotationMatrix[(i + 3 * iindx) - 1] + rotationMatrix[iindx + idx]) /
        (2.0 * s);
    if (i1 > 3) {
      emlrtDynamicBoundsCheckR2012b(4, 1, 3, &gu_emlrtBCI, &st);
    }
    rotationVector[i1 - 1] =
        (rotationMatrix[(i1 + 3 * iindx) - 1] + rotationMatrix[iindx + k]) /
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

// End of code generation (rodriguesMatrixToVector.cpp)
