//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// worldToImage.cpp
//
// Code generation for function 'worldToImage'
//

// Include files
#include "worldToImage.h"
#include "bsxfun.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "cameraParameters.h"
#include "distortPoints.h"
#include "rt_nonfinite.h"
#include "validateRotationMatrix.h"
#include "blas.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstddef>

// Variable Definitions
static emlrtRSInfo
    mdb_emlrtRSI{
        100,            // lineNo
        "worldToImage", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\worldToImage.m" // pathName
    };

static emlrtRSInfo
    ndb_emlrtRSI{
        103,            // lineNo
        "worldToImage", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\worldToImage.m" // pathName
    };

static emlrtRSInfo
    odb_emlrtRSI{
        116,            // lineNo
        "worldToImage", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\worldToImage.m" // pathName
    };

static emlrtRSInfo
    pdb_emlrtRSI{
        143,            // lineNo
        "worldToImage", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\worldToImage.m" // pathName
    };

static emlrtRSInfo
    qdb_emlrtRSI{
        147,            // lineNo
        "worldToImage", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\worldToImage.m" // pathName
    };

static emlrtRSInfo
    rdb_emlrtRSI{
        148,            // lineNo
        "worldToImage", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\worldToImage.m" // pathName
    };

static emlrtRSInfo
    sdb_emlrtRSI{
        149,            // lineNo
        "worldToImage", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\worldToImage.m" // pathName
    };

static emlrtRSInfo
    tdb_emlrtRSI{
        155,            // lineNo
        "worldToImage", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\worldToImage.m" // pathName
    };

static emlrtRSInfo
    udb_emlrtRSI{
        168,            // lineNo
        "worldToImage", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\worldToImage.m" // pathName
    };

static emlrtRSInfo ydb_emlrtRSI{
    6,                           // lineNo
    "validateTranslationVector", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "inputValidation\\validateTranslationVector.m" // pathName
};

static emlrtRSInfo aeb_emlrtRSI{
    20,                      // lineNo
    "parseProjectionInputs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "inputValidation\\parseProjectionInputs.m" // pathName
};

static emlrtECInfo
    hd_emlrtECI{
        -1,             // nDims
        158,            // lineNo
        13,             // colNo
        "worldToImage", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\worldToImage.m" // pName
    };

static emlrtECInfo
    id_emlrtECI{
        -1,             // nDims
        158,            // lineNo
        36,             // colNo
        "worldToImage", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\worldToImage.m" // pName
    };

static emlrtRTEInfo cu_emlrtRTEI{
    32,                      // lineNo
    5,                       // colNo
    "parseProjectionInputs", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "inputValidation\\parseProjectionInputs.m" // pName
};

static emlrtRTEInfo du_emlrtRTEI{
    28,    // lineNo
    5,     // colNo
    "cat", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" // pName
};

static emlrtRTEInfo
    eu_emlrtRTEI{
        149,            // lineNo
        39,             // colNo
        "worldToImage", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\worldToImage.m" // pName
    };

static emlrtRTEInfo
    fu_emlrtRTEI{
        150,            // lineNo
        9,              // colNo
        "worldToImage", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\worldToImage.m" // pName
    };

static emlrtRTEInfo
    gu_emlrtRTEI{
        158,            // lineNo
        59,             // colNo
        "worldToImage", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\worldToImage.m" // pName
    };

static emlrtRTEInfo
    hu_emlrtRTEI{
        158,            // lineNo
        28,             // colNo
        "worldToImage", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\worldToImage.m" // pName
    };

static emlrtRTEInfo
    iu_emlrtRTEI{
        158,            // lineNo
        36,             // colNo
        "worldToImage", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\worldToImage.m" // pName
    };

static emlrtRTEInfo
    ju_emlrtRTEI{
        169,            // lineNo
        17,             // colNo
        "worldToImage", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\worldToImage.m" // pName
    };

// Function Definitions
namespace coder {
void worldToImage(const emlrtStack *sp, const d_cameraParameters *intrinsics,
                  const real_T varargin_1[9],
                  const ::coder::array<real_T, 2U> &varargin_2,
                  const ::coder::array<real_T, 2U> &varargin_3,
                  ::coder::array<real_T, 2U> &varargout_1)
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  array<real_T, 2U> b_projectedPoints;
  array<real_T, 2U> b_varargin_2;
  array<real_T, 2U> cameraMatrix;
  array<real_T, 2U> projectedPoints;
  array<real_T, 2U> result;
  array<real_T, 1U> c_projectedPoints;
  array<int32_T, 1U> r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T K[9];
  real_T alpha1;
  real_T beta1;
  int32_T i;
  int32_T i1;
  int32_T k;
  int32_T result_idx_0;
  char_T TRANSA1;
  char_T TRANSB1;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &mdb_emlrtRSI;
  vision::internal::inputValidation::validateRotationMatrix(&st, varargin_1);
  st.site = &ndb_emlrtRSI;
  b_st.site = &ydb_emlrtRSI;
  c_st.site = &t_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= varargin_2.size(1) - 1)) {
    if ((!muDoubleScalarIsInf(varargin_2[k])) &&
        (!muDoubleScalarIsNaN(varargin_2[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:worldToImage:expectedFinite", 3, 4, 17, "translationVector");
  }
  c_st.site = &t_emlrtRSI;
  if (varargin_2.size(1) != 3) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &lc_emlrtRTEI, "Coder:toolbox:ValidateattributesincorrectNumel",
        "MATLAB:worldToImage:incorrectNumel", 5, 4, 17, "translationVector", 6,
        3.0);
  }
  st.site = &odb_emlrtRSI;
  b_st.site = &t_emlrtRSI;
  if ((varargin_3.size(0) == 0) || (varargin_3.size(1) == 0)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonempty",
        "MATLAB:worldToImage:expectedNonempty", 3, 4, 11, "worldPoints");
  }
  b_st.site = &t_emlrtRSI;
  if (varargin_3.size(1) != 3) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &bc_emlrtRTEI,
        "Coder:toolbox:ValidateattributesincorrectNumcols",
        "MATLAB:worldToImage:incorrectNumcols", 5, 4, 11, "worldPoints", 6,
        3.0);
  }
  st.site = &pdb_emlrtRSI;
  b_st.site = &aeb_emlrtRSI;
  for (i = 0; i < 3; i++) {
    K[3 * i] = intrinsics->IntrinsicMatrixInternal[i];
    K[3 * i + 1] = intrinsics->IntrinsicMatrixInternal[i + 3];
    K[3 * i + 2] = intrinsics->IntrinsicMatrixInternal[i + 6];
  }
  st.site = &qdb_emlrtRSI;
  b_st.site = &lcb_emlrtRSI;
  c_st.site = &uo_emlrtRSI;
  b_varargin_2.set_size(&cu_emlrtRTEI, &b_st, 1, 3);
  for (i = 0; i < 3; i++) {
    b_varargin_2[i] = varargin_2[i];
  }
  projectedPoints.set_size(&du_emlrtRTEI, &b_st, 4, 3);
  for (i = 0; i < 3; i++) {
    projectedPoints[projectedPoints.size(0) * i] = varargin_1[3 * i];
    projectedPoints[projectedPoints.size(0) * i + 1] = varargin_1[3 * i + 1];
    projectedPoints[projectedPoints.size(0) * i + 2] = varargin_1[3 * i + 2];
    projectedPoints[projectedPoints.size(0) * i + 3] = b_varargin_2[i];
  }
  st.site = &qdb_emlrtRSI;
  b_st.site = &pi_emlrtRSI;
  c_st.site = &ri_emlrtRSI;
  d_st.site = &si_emlrtRSI;
  TRANSB1 = 'N';
  TRANSA1 = 'N';
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)4;
  n_t = (ptrdiff_t)3;
  k_t = (ptrdiff_t)3;
  lda_t = (ptrdiff_t)4;
  ldb_t = (ptrdiff_t)3;
  ldc_t = (ptrdiff_t)4;
  cameraMatrix.set_size(&mh_emlrtRTEI, &d_st, 4, 3);
  dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1,
        &(projectedPoints.data())[0], &lda_t, &K[0], &ldb_t, &beta1,
        &(cameraMatrix.data())[0], &ldc_t);
  st.site = &rdb_emlrtRSI;
  b_st.site = &lcb_emlrtRSI;
  k = varargin_3.size(0);
  c_st.site = &uo_emlrtRSI;
  result_idx_0 = varargin_3.size(0);
  result.set_size(&du_emlrtRTEI, &b_st, varargin_3.size(0), 4);
  for (i = 0; i < 3; i++) {
    for (i1 = 0; i1 < k; i1++) {
      result[i1 + result.size(0) * i] = varargin_3[i1 + result_idx_0 * i];
    }
  }
  for (i = 0; i < k; i++) {
    result[i + result.size(0) * 3] = 1.0;
  }
  st.site = &rdb_emlrtRSI;
  b_st.site = &qi_emlrtRSI;
  b_st.site = &pi_emlrtRSI;
  c_st.site = &ri_emlrtRSI;
  d_st.site = &si_emlrtRSI;
  TRANSB1 = 'N';
  TRANSA1 = 'N';
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)result.size(0);
  n_t = (ptrdiff_t)3;
  k_t = (ptrdiff_t)4;
  lda_t = (ptrdiff_t)result.size(0);
  ldb_t = (ptrdiff_t)4;
  ldc_t = (ptrdiff_t)result.size(0);
  projectedPoints.set_size(&mh_emlrtRTEI, &d_st, result.size(0), 3);
  dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &(result.data())[0],
        &lda_t, &(cameraMatrix.data())[0], &ldb_t, &beta1,
        &(projectedPoints.data())[0], &ldc_t);
  k = projectedPoints.size(0);
  b_projectedPoints.set_size(&eu_emlrtRTEI, sp, projectedPoints.size(0), 2);
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < k; i1++) {
      b_projectedPoints[i1 + b_projectedPoints.size(0) * i] =
          projectedPoints[i1 + projectedPoints.size(0) * i];
    }
  }
  k = projectedPoints.size(0);
  c_projectedPoints.set_size(&fu_emlrtRTEI, sp, projectedPoints.size(0));
  for (i = 0; i < k; i++) {
    c_projectedPoints[i] = projectedPoints[i + projectedPoints.size(0) * 2];
  }
  st.site = &sdb_emlrtRSI;
  bsxfun(&st, b_projectedPoints, c_projectedPoints, varargout_1);
  st.site = &tdb_emlrtRSI;
  if (muDoubleScalarIsNaN(K[1])) {
    emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI, "MATLAB:nologicalnan",
                                  "MATLAB:nologicalnan", 0);
  }
  if (K[1] != 0.0) {
    k = varargout_1.size(0);
    c_projectedPoints.set_size(&gu_emlrtRTEI, sp, varargout_1.size(0));
    for (i = 0; i < k; i++) {
      c_projectedPoints[i] =
          K[1] * (varargout_1[i + varargout_1.size(0)] - K[5]) / K[4];
    }
    if (varargout_1.size(0) != c_projectedPoints.size(0)) {
      emlrtSizeEqCheck1DR2012b(varargout_1.size(0), c_projectedPoints.size(0),
                               &id_emlrtECI, (emlrtCTX)sp);
    }
    k = varargout_1.size(0);
    r.set_size(&hu_emlrtRTEI, sp, varargout_1.size(0));
    for (i = 0; i < k; i++) {
      r[i] = i;
    }
    emlrtSubAssignSizeCheckR2012b(r.size(), 1, varargout_1.size(), 1,
                                  &hd_emlrtECI, (emlrtCTX)sp);
    k = varargout_1.size(0) - 1;
    c_projectedPoints.set_size(&iu_emlrtRTEI, sp, varargout_1.size(0));
    for (i = 0; i <= k; i++) {
      c_projectedPoints[i] = varargout_1[i] - c_projectedPoints[i];
    }
    k = c_projectedPoints.size(0);
    for (i = 0; i < k; i++) {
      varargout_1[r[i]] = c_projectedPoints[i];
    }
  }
  b_projectedPoints.set_size(&ju_emlrtRTEI, sp, varargout_1.size(0), 2);
  k = varargout_1.size(0) * varargout_1.size(1) - 1;
  for (i = 0; i <= k; i++) {
    b_projectedPoints[i] = varargout_1[i];
  }
  st.site = &udb_emlrtRSI;
  vision::internal::calibration::distortPoints(
      &st, b_projectedPoints, K, intrinsics->RadialDistortion,
      intrinsics->TangentialDistortion, varargout_1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace coder

// End of code generation (worldToImage.cpp)
