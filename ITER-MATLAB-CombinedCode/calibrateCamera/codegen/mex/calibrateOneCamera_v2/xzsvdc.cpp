//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xzsvdc.cpp
//
// Code generation for function 'xzsvdc'
//

// Include files
#include "xzsvdc.h"
#include "calibrateOneCamera_v2_data.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xrot.h"
#include "xrotg.h"
#include "xscal.h"
#include "xswap.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo pu_emlrtRSI{
    77,       // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo qu_emlrtRSI{
    82,       // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo ru_emlrtRSI{
    89,       // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo su_emlrtRSI{
    94,       // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo tu_emlrtRSI{
    97,       // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo uu_emlrtRSI{
    105,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo vu_emlrtRSI{
    114,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo wu_emlrtRSI{
    120,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo xu_emlrtRSI{
    129,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo yu_emlrtRSI{
    132,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo av_emlrtRSI{
    135,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo bv_emlrtRSI{
    137,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo cv_emlrtRSI{
    141,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo dv_emlrtRSI{
    147,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo ev_emlrtRSI{
    181,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo fv_emlrtRSI{
    184,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo gv_emlrtRSI{
    187,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo hv_emlrtRSI{
    190,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo iv_emlrtRSI{
    194,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo jv_emlrtRSI{
    212,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo kv_emlrtRSI{
    215,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo lv_emlrtRSI{
    218,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo mv_emlrtRSI{
    240,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo nv_emlrtRSI{
    251,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo ov_emlrtRSI{
    282,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo pv_emlrtRSI{
    299,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo qv_emlrtRSI{
    332,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo rv_emlrtRSI{
    334,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo sv_emlrtRSI{
    351,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo tv_emlrtRSI{
    353,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo uv_emlrtRSI{
    380,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo vv_emlrtRSI{
    391,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo wv_emlrtRSI{
    394,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo xv_emlrtRSI{
    407,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo yv_emlrtRSI{
    428,      // lineNo
    "xzsvdc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pathName
};

static emlrtRSInfo aw_emlrtRSI{
    21,                   // lineNo
    "scaleVectorByRecip", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\scaleVectorByRecip.m" // pathName
};

static emlrtRTEInfo fc_emlrtRTEI{
    269,      // lineNo
    13,       // colNo
    "xzsvdc", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" // pName
};

// Function Definitions
namespace coder {
namespace internal {
namespace reflapack {
void xzsvdc(const emlrtStack *sp, real_T A[9], real_T U[9], real_T S[3],
            real_T V[9])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T e[3];
  real_T s[3];
  real_T work[3];
  real_T nrm;
  real_T rt;
  real_T sm;
  real_T snorm;
  real_T sqds;
  int32_T iter;
  int32_T k;
  int32_T m;
  int32_T q;
  int32_T qjj;
  int32_T qp1;
  int32_T qq;
  int32_T qs;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  s[0] = 0.0;
  e[0] = 0.0;
  work[0] = 0.0;
  s[1] = 0.0;
  e[1] = 0.0;
  work[1] = 0.0;
  s[2] = 0.0;
  e[2] = 0.0;
  work[2] = 0.0;
  std::memset(&U[0], 0, 9U * sizeof(real_T));
  std::memset(&V[0], 0, 9U * sizeof(real_T));
  for (q = 0; q < 2; q++) {
    boolean_T apply_transform;
    qp1 = q + 2;
    qs = q + 3 * q;
    qq = qs + 1;
    apply_transform = false;
    st.site = &pu_emlrtRSI;
    nrm = blas::xnrm2(&st, 3 - q, A, qs + 1);
    if (nrm > 0.0) {
      apply_transform = true;
      if (A[qs] < 0.0) {
        nrm = -nrm;
      }
      s[q] = nrm;
      st.site = &qu_emlrtRSI;
      if (muDoubleScalarAbs(nrm) >= 1.0020841800044864E-292) {
        b_st.site = &aw_emlrtRSI;
        blas::xscal(&b_st, 3 - q, 1.0 / nrm, A, qs + 1);
      } else {
        qjj = (qs - q) + 3;
        for (k = qq; k <= qjj; k++) {
          A[k - 1] /= s[q];
        }
      }
      A[qs]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }
    st.site = &ru_emlrtRSI;
    for (iter = qp1; iter < 4; iter++) {
      qjj = q + 3 * (iter - 1);
      if (apply_transform) {
        st.site = &su_emlrtRSI;
        nrm = blas::xdotc(&st, 3 - q, A, qs + 1, A, qjj + 1);
        nrm = -(nrm / A[qs]);
        st.site = &tu_emlrtRSI;
        blas::xaxpy(3 - q, nrm, qs + 1, A, qjj + 1);
      }
      e[iter - 1] = A[qjj];
    }
    st.site = &uu_emlrtRSI;
    for (k = q + 1; k < 4; k++) {
      qjj = (k + 3 * q) - 1;
      U[qjj] = A[qjj];
    }
    if (q + 1 <= 1) {
      st.site = &vu_emlrtRSI;
      nrm = blas::xnrm2(e);
      if (nrm == 0.0) {
        e[0] = 0.0;
      } else {
        if (e[1] < 0.0) {
          e[0] = -nrm;
        } else {
          e[0] = nrm;
        }
        st.site = &wu_emlrtRSI;
        nrm = e[0];
        if (muDoubleScalarAbs(e[0]) >= 1.0020841800044864E-292) {
          blas::xscal(1.0 / e[0], e);
        } else {
          for (k = qp1; k < 4; k++) {
            e[k - 1] /= nrm;
          }
        }
        e[1]++;
        e[0] = -e[0];
        st.site = &xu_emlrtRSI;
        for (k = qp1; k < 4; k++) {
          work[k - 1] = 0.0;
        }
        st.site = &yu_emlrtRSI;
        for (iter = qp1; iter < 4; iter++) {
          st.site = &av_emlrtRSI;
          blas::xaxpy(e[iter - 1], A, 3 * (iter - 1) + 2, work);
        }
        st.site = &bv_emlrtRSI;
        for (iter = qp1; iter < 4; iter++) {
          st.site = &cv_emlrtRSI;
          blas::xaxpy(-e[iter - 1] / e[1], work, A, 3 * (iter - 1) + 2);
        }
      }
      st.site = &dv_emlrtRSI;
      for (k = qp1; k < 4; k++) {
        V[k - 1] = e[k - 1];
      }
    }
  }
  m = 1;
  s[2] = A[8];
  e[1] = A[7];
  e[2] = 0.0;
  U[6] = 0.0;
  U[7] = 0.0;
  U[8] = 1.0;
  for (q = 1; q >= 0; q--) {
    qp1 = q + 2;
    qq = q + 3 * q;
    if (s[q] != 0.0) {
      st.site = &ev_emlrtRSI;
      for (iter = qp1; iter < 4; iter++) {
        qjj = (q + 3 * (iter - 1)) + 1;
        st.site = &fv_emlrtRSI;
        nrm = blas::xdotc(&st, 3 - q, U, qq + 1, U, qjj);
        nrm = -(nrm / U[qq]);
        st.site = &gv_emlrtRSI;
        blas::xaxpy(3 - q, nrm, qq + 1, U, qjj);
      }
      st.site = &hv_emlrtRSI;
      for (k = q + 1; k < 4; k++) {
        qjj = (k + 3 * q) - 1;
        U[qjj] = -U[qjj];
      }
      U[qq]++;
      st.site = &iv_emlrtRSI;
      if (0 <= q - 1) {
        U[3 * q] = 0.0;
      }
    } else {
      U[3 * q] = 0.0;
      U[3 * q + 1] = 0.0;
      U[3 * q + 2] = 0.0;
      U[qq] = 1.0;
    }
  }
  for (q = 2; q >= 0; q--) {
    if ((q + 1 <= 1) && (e[0] != 0.0)) {
      st.site = &jv_emlrtRSI;
      st.site = &kv_emlrtRSI;
      nrm = blas::xdotc(&st, 2, V, 2, V, 5);
      nrm = -(nrm / V[1]);
      st.site = &lv_emlrtRSI;
      blas::xaxpy(2, nrm, 2, V, 5);
      st.site = &kv_emlrtRSI;
      nrm = blas::xdotc(&st, 2, V, 2, V, 8);
      nrm = -(nrm / V[1]);
      st.site = &lv_emlrtRSI;
      blas::xaxpy(2, nrm, 2, V, 8);
    }
    V[3 * q] = 0.0;
    V[3 * q + 1] = 0.0;
    V[3 * q + 2] = 0.0;
    V[q + 3 * q] = 1.0;
  }
  if (s[0] != 0.0) {
    rt = muDoubleScalarAbs(s[0]);
    nrm = s[0] / rt;
    s[0] = rt;
    e[0] /= nrm;
    st.site = &mv_emlrtRSI;
    blas::xscal(&st, nrm, U, 1);
  }
  if (e[0] != 0.0) {
    rt = muDoubleScalarAbs(e[0]);
    nrm = rt / e[0];
    e[0] = rt;
    s[1] *= nrm;
    st.site = &nv_emlrtRSI;
    blas::xscal(&st, nrm, V, 4);
  }
  if (s[1] != 0.0) {
    rt = muDoubleScalarAbs(s[1]);
    nrm = s[1] / rt;
    s[1] = rt;
    e[1] = A[7] / nrm;
    st.site = &mv_emlrtRSI;
    blas::xscal(&st, nrm, U, 4);
  }
  if (e[1] != 0.0) {
    rt = muDoubleScalarAbs(e[1]);
    nrm = rt / e[1];
    e[1] = rt;
    s[2] = A[8] * nrm;
    st.site = &nv_emlrtRSI;
    blas::xscal(&st, nrm, V, 7);
  }
  if (s[2] != 0.0) {
    rt = muDoubleScalarAbs(s[2]);
    nrm = s[2] / rt;
    s[2] = rt;
    st.site = &mv_emlrtRSI;
    blas::xscal(&st, nrm, U, 7);
  }
  iter = 0;
  snorm = muDoubleScalarMax(muDoubleScalarMax(muDoubleScalarMax(s[0], e[0]),
                                              muDoubleScalarMax(s[1], e[1])),
                            muDoubleScalarMax(s[2], 0.0));
  exitg1 = false;
  while ((!exitg1) && (m + 2 > 0)) {
    if (iter >= 75) {
      emlrtErrorWithMessageIdR2018a(sp, &fc_emlrtRTEI,
                                    "Coder:MATLAB:svd_NoConvergence",
                                    "Coder:MATLAB:svd_NoConvergence", 0);
    } else {
      st.site = &ov_emlrtRSI;
      k = m;
      int32_T exitg2;
      do {
        exitg2 = 0;
        q = k + 1;
        if (k + 1 == 0) {
          exitg2 = 1;
        } else {
          nrm = muDoubleScalarAbs(e[k]);
          if ((nrm <= 2.2204460492503131E-16 * (muDoubleScalarAbs(s[k]) +
                                                muDoubleScalarAbs(s[k + 1]))) ||
              (nrm <= 1.0020841800044864E-292) ||
              ((iter > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
            e[k] = 0.0;
            exitg2 = 1;
          } else {
            k--;
          }
        }
      } while (exitg2 == 0);
      if (k + 1 == m + 1) {
        qjj = 4;
      } else {
        boolean_T exitg3;
        qs = m + 2;
        st.site = &pv_emlrtRSI;
        qjj = m + 2;
        exitg3 = false;
        while ((!exitg3) && (qjj >= k + 1)) {
          qs = qjj;
          if (qjj == k + 1) {
            exitg3 = true;
          } else {
            nrm = 0.0;
            if (qjj < m + 2) {
              nrm = muDoubleScalarAbs(e[qjj - 1]);
            }
            if (qjj > k + 2) {
              nrm += muDoubleScalarAbs(e[qjj - 2]);
            }
            rt = muDoubleScalarAbs(s[qjj - 1]);
            if ((rt <= 2.2204460492503131E-16 * nrm) ||
                (rt <= 1.0020841800044864E-292)) {
              s[qjj - 1] = 0.0;
              exitg3 = true;
            } else {
              qjj--;
            }
          }
        }
        if (qs == k + 1) {
          qjj = 3;
        } else if (qs == m + 2) {
          qjj = 1;
        } else {
          qjj = 2;
          q = qs;
        }
      }
      switch (qjj) {
      case 1:
        rt = e[m];
        e[m] = 0.0;
        qjj = m + 1;
        st.site = &qv_emlrtRSI;
        for (k = qjj; k >= q + 1; k--) {
          st.site = &rv_emlrtRSI;
          blas::xrotg(&s[k - 1], &rt, &sm, &sqds);
          if (k > q + 1) {
            rt = -sqds * e[0];
            e[0] *= sm;
          }
          blas::xrot(V, 3 * (k - 1) + 1, 3 * (m + 1) + 1, sm, sqds);
        }
        break;
      case 2: {
        rt = e[q - 1];
        e[q - 1] = 0.0;
        st.site = &sv_emlrtRSI;
        for (k = q + 1; k <= m + 2; k++) {
          real_T b;
          st.site = &tv_emlrtRSI;
          blas::xrotg(&s[k - 1], &rt, &sm, &sqds);
          b = e[k - 1];
          rt = -sqds * b;
          e[k - 1] = b * sm;
          blas::xrot(U, 3 * (k - 1) + 1, 3 * (q - 1) + 1, sm, sqds);
        }
      } break;
      case 3: {
        real_T b;
        real_T scale;
        qjj = m + 1;
        nrm = s[m + 1];
        scale = muDoubleScalarMax(
            muDoubleScalarMax(
                muDoubleScalarMax(muDoubleScalarMax(muDoubleScalarAbs(nrm),
                                                    muDoubleScalarAbs(s[m])),
                                  muDoubleScalarAbs(e[m])),
                muDoubleScalarAbs(s[q])),
            muDoubleScalarAbs(e[q]));
        sm = nrm / scale;
        nrm = s[m] / scale;
        rt = e[m] / scale;
        sqds = s[q] / scale;
        b = ((nrm + sm) * (nrm - sm) + rt * rt) / 2.0;
        nrm = sm * rt;
        nrm *= nrm;
        if ((b != 0.0) || (nrm != 0.0)) {
          rt = b * b + nrm;
          st.site = &uv_emlrtRSI;
          if (rt < 0.0) {
            emlrtErrorWithMessageIdR2018a(
                &st, &x_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
                "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
          }
          rt = muDoubleScalarSqrt(rt);
          if (b < 0.0) {
            rt = -rt;
          }
          rt = nrm / (b + rt);
        } else {
          rt = 0.0;
        }
        rt += (sqds + sm) * (sqds - sm);
        nrm = sqds * (e[q] / scale);
        st.site = &vv_emlrtRSI;
        for (k = q + 1; k <= qjj; k++) {
          st.site = &wv_emlrtRSI;
          blas::xrotg(&rt, &nrm, &sm, &sqds);
          if (k > q + 1) {
            e[0] = rt;
          }
          nrm = e[k - 1];
          b = s[k - 1];
          e[k - 1] = sm * nrm - sqds * b;
          rt = sqds * s[k];
          s[k] *= sm;
          blas::xrot(V, 3 * (k - 1) + 1, 3 * k + 1, sm, sqds);
          s[k - 1] = sm * b + sqds * nrm;
          st.site = &xv_emlrtRSI;
          blas::xrotg(&s[k - 1], &rt, &sm, &sqds);
          rt = sm * e[k - 1] + sqds * s[k];
          s[k] = -sqds * e[k - 1] + sm * s[k];
          nrm = sqds * e[k];
          e[k] *= sm;
          blas::xrot(U, 3 * (k - 1) + 1, 3 * k + 1, sm, sqds);
        }
        e[m] = rt;
        iter++;
      } break;
      default:
        if (s[q] < 0.0) {
          s[q] = -s[q];
          st.site = &yv_emlrtRSI;
          blas::xscal(&st, -1.0, V, 3 * q + 1);
        }
        qp1 = q + 1;
        while ((q + 1 < 3) && (s[q] < s[qp1])) {
          rt = s[q];
          s[q] = s[qp1];
          s[qp1] = rt;
          blas::xswap(V, 3 * q + 1, 3 * (q + 1) + 1);
          blas::xswap(U, 3 * q + 1, 3 * (q + 1) + 1);
          q = qp1;
          qp1++;
        }
        iter = 0;
        m--;
        break;
      }
    }
  }
  S[0] = s[0];
  S[1] = s[1];
  S[2] = s[2];
}

} // namespace reflapack
} // namespace internal
} // namespace coder

// End of code generation (xzsvdc.cpp)
