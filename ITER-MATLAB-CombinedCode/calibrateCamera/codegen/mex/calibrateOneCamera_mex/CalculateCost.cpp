//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// CalculateCost.cpp
//
// Code generation for function 'CalculateCost'
//

// Include files
#include "CalculateCost.h"
#include "all.h"
#include "bsxfun.h"
#include "calibrateOneCamera_mex_data.h"
#include "calibrateOneCamera_mex_internal_types.h"
#include "calibrateOneCamera_mex_types.h"
#include "distortPoints.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "unsafeSxfun.h"
#include "unserializeCalib.h"
#include "blas.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstddef>

// Variable Definitions
static emlrtRSInfo qy_emlrtRSI{
    4,               // lineNo
    "CalculateCost", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\CalculateCost.m" // pathName
};

static emlrtRSInfo ry_emlrtRSI{
    23,              // lineNo
    "CalculateCost", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\CalculateCost.m" // pathName
};

static emlrtRSInfo sy_emlrtRSI{
    26,              // lineNo
    "CalculateCost", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\CalculateCost.m" // pathName
};

static emlrtRSInfo ty_emlrtRSI{
    33,              // lineNo
    "CalculateCost", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\CalculateCost.m" // pathName
};

static emlrtRSInfo uy_emlrtRSI{
    35,              // lineNo
    "CalculateCost", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\CalculateCost.m" // pathName
};

static emlrtRSInfo vy_emlrtRSI{
    37,              // lineNo
    "CalculateCost", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\CalculateCost.m" // pathName
};

static emlrtRSInfo wy_emlrtRSI{
    41,              // lineNo
    "CalculateCost", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\CalculateCost.m" // pathName
};

static emlrtRSInfo cab_emlrtRSI{
    136,      // lineNo
    "mtimes", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\mtimes.m" // pathName
};

static emlrtRSInfo mab_emlrtRSI{
    16,     // lineNo
    "sqrt", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" // pathName
};

static emlrtRSInfo nab_emlrtRSI{
    33,                           // lineNo
    "applyScalarFunctionInPlace", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyScalarFunctionInPlace.m" // pathName
};

static emlrtBCInfo nt_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    18,              // lineNo
    22,              // colNo
    "RTpnc1",        // aName
    "CalculateCost", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\CalculateCost.m", // pName
    0                                   // checkKind
};

static emlrtECInfo cd_emlrtECI{
    -1,              // nDims
    43,              // lineNo
    13,              // colNo
    "CalculateCost", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\CalculateCost.m" // pName
};

static emlrtBCInfo ot_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    43,              // lineNo
    32,              // colNo
    "cost",          // aName
    "CalculateCost", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\CalculateCost.m", // pName
    0                                   // checkKind
};

static emlrtBCInfo pt_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    43,              // lineNo
    18,              // colNo
    "cost",          // aName
    "CalculateCost", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\CalculateCost.m", // pName
    0                                   // checkKind
};

static emlrtECInfo dd_emlrtECI{
    1,               // nDims
    40,              // lineNo
    27,              // colNo
    "CalculateCost", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\CalculateCost.m" // pName
};

static emlrtBCInfo qt_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    14,              // lineNo
    40,              // colNo
    "detPoints",     // aName
    "CalculateCost", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\CalculateCost.m", // pName
    0                                   // checkKind
};

static emlrtDCInfo md_emlrtDCI{
    9,               // lineNo
    1,               // colNo
    "CalculateCost", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\CalculateCost.m", // pName
    1                                   // checkKind
};

static emlrtBCInfo rt_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    14,              // lineNo
    30,              // colNo
    "detPoints",     // aName
    "CalculateCost", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\CalculateCost.m", // pName
    0                                   // checkKind
};

static emlrtRTEInfo tq_emlrtRTEI{
    9,               // lineNo
    1,               // colNo
    "CalculateCost", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\CalculateCost.m" // pName
};

static emlrtRTEInfo uq_emlrtRTEI{
    14,              // lineNo
    9,               // colNo
    "CalculateCost", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\CalculateCost.m" // pName
};

static emlrtRTEInfo vq_emlrtRTEI{
    28,    // lineNo
    5,     // colNo
    "cat", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" // pName
};

static emlrtRTEInfo wq_emlrtRTEI{
    33,              // lineNo
    13,              // colNo
    "CalculateCost", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\CalculateCost.m" // pName
};

static emlrtRTEInfo xq_emlrtRTEI{
    35,              // lineNo
    52,              // colNo
    "CalculateCost", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\CalculateCost.m" // pName
};

static emlrtRTEInfo yq_emlrtRTEI{
    35,              // lineNo
    80,              // colNo
    "CalculateCost", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\CalculateCost.m" // pName
};

static emlrtRSInfo
    mbb_emlrtRSI{
        31,            // lineNo
        "unsafeSxfun", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\unsafeSxfun.m" // pathName
    };

// Function Definitions
namespace Codegen {
void CalculateCost(
    const emlrtStack *sp, const ::coder::array<real_T, 1U> &calib,
    const real_T c_refCalibration_CameraParamete[2],
    const ::coder::array<cell_wrap_0, 2U> &refCalibration_PatternPositions,
    const ::coder::array<real_T, 2U> &genPoints,
    const ::coder::array<real_T, 3U> &detPoints,
    ::coder::array<real_T, 1U> &cost)
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ::coder::array<cell_wrap_0, 2U> PatternPositions;
  ::coder::array<real_T, 2U> distortedPoints;
  ::coder::array<real_T, 2U> points;
  ::coder::array<real_T, 2U> projectedPointsnorm;
  ::coder::array<real_T, 2U> projectedPointsraw;
  ::coder::array<real_T, 2U> result;
  ::coder::array<real_T, 1U> b_error;
  ::coder::array<boolean_T, 1U> r;
  c_struct_T CameraParameters;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T c_PatternPositions[12];
  real_T cameraMatrix[12];
  real_T b_PatternPositions[9];
  real_T b_y[3];
  real_T alpha1;
  real_T beta1;
  int32_T aoffset;
  int32_T i;
  char_T TRANSA1;
  char_T TRANSB1;
  boolean_T y[3];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 4, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 4, 0);
  //  Changed for 1 camera
  st.site = &qy_emlrtRSI;
  unserializeCalib(&st, calib, c_refCalibration_CameraParamete,
                   refCalibration_PatternPositions, &CameraParameters,
                   PatternPositions);
  alpha1 = static_cast<real_T>(PatternPositions.size(1)) *
           static_cast<real_T>(genPoints.size(0));
  if (alpha1 != static_cast<int32_T>(alpha1)) {
    emlrtIntegerCheckR2012b(alpha1, &md_emlrtDCI, (emlrtCTX)sp);
  }
  cost.set_size(&tq_emlrtRTEI, sp, static_cast<int32_T>(alpha1));
  alpha1 = static_cast<real_T>(PatternPositions.size(1)) *
           static_cast<real_T>(genPoints.size(0));
  if (alpha1 != static_cast<int32_T>(alpha1)) {
    emlrtIntegerCheckR2012b(alpha1, &md_emlrtDCI, (emlrtCTX)sp);
  }
  aoffset = static_cast<int32_T>(alpha1);
  for (i = 0; i < aoffset; i++) {
    cost[i] = 0.0;
  }
  i = PatternPositions.size(1);
  for (int32_T n{0}; n < i; n++) {
    int32_T i1;
    int32_T i2;
    boolean_T guard1{false};
    covrtLogFor(&emlrtCoverageInstance, 4, 0, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 4, 1);
    //  for each image
    if (n + 1 > detPoints.size(2)) {
      emlrtDynamicBoundsCheckR2012b(n + 1, 1, detPoints.size(2), &qt_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    aoffset = detPoints.size(0);
    points.set_size(&uq_emlrtRTEI, sp, detPoints.size(0), 2);
    for (i1 = 0; i1 < 2; i1++) {
      for (i2 = 0; i2 < aoffset; i2++) {
        if (i1 + 1 > detPoints.size(1)) {
          emlrtDynamicBoundsCheckR2012b(i1 + 1, 1, detPoints.size(1),
                                        &rt_emlrtBCI, (emlrtCTX)sp);
        }
        points[i2 + points.size(0) * i1] =
            detPoints[(i2 + detPoints.size(0) * i1) +
                      detPoints.size(0) * detPoints.size(1) * n];
      }
    }
    if (n > PatternPositions.size(1) - 1) {
      emlrtDynamicBoundsCheckR2012b(n, 0, PatternPositions.size(1) - 1,
                                    &nt_emlrtBCI, (emlrtCTX)sp);
    }
    r.set_size(&ce_emlrtRTEI, sp, detPoints.size(0) << 1);
    aoffset = detPoints.size(0) << 1;
    for (i1 = 0; i1 < aoffset; i1++) {
      r[i1] = muDoubleScalarIsNaN(points[i1]);
    }
    guard1 = false;
    st.site = &ry_emlrtRSI;
    if (covrtLogCond(&emlrtCoverageInstance, 4, 0, 0, !coder::all(&st, r))) {
      int32_T k;
      boolean_T empty_non_axis_sizes;
      boolean_T exitg1;
      st.site = &ry_emlrtRSI;
      b_st.site = &sh_emlrtRSI;
      y[0] = true;
      y[1] = true;
      y[2] = true;
      c_st.site = &rh_emlrtRSI;
      aoffset = 1;
      exitg1 = false;
      while ((!exitg1) && (aoffset <= 3)) {
        if (PatternPositions[n]
                .f1[(aoffset - 1) % 3 + (((aoffset - 1) / 3) << 2)] == 0.0) {
          y[0] = false;
          exitg1 = true;
        } else {
          aoffset++;
        }
      }
      c_st.site = &rh_emlrtRSI;
      aoffset = 4;
      exitg1 = false;
      while ((!exitg1) && (aoffset <= 6)) {
        if (PatternPositions[n]
                .f1[(aoffset - 1) % 3 + (((aoffset - 1) / 3) << 2)] == 0.0) {
          y[1] = false;
          exitg1 = true;
        } else {
          aoffset++;
        }
      }
      c_st.site = &rh_emlrtRSI;
      aoffset = 7;
      exitg1 = false;
      while ((!exitg1) && (aoffset <= 9)) {
        if (PatternPositions[n]
                .f1[(aoffset - 1) % 3 + (((aoffset - 1) / 3) << 2)] == 0.0) {
          y[2] = false;
          exitg1 = true;
        } else {
          aoffset++;
        }
      }
      empty_non_axis_sizes = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 3)) {
        if (!y[k]) {
          empty_non_axis_sizes = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
      if (covrtLogCond(&emlrtCoverageInstance, 4, 0, 1, empty_non_axis_sizes)) {
        int8_T i3;
        int8_T sizes_idx_1;
        covrtLogMcdc(&emlrtCoverageInstance, 4, 0, 0, true);
        covrtLogIf(&emlrtCoverageInstance, 4, 0, 0, true);
        covrtLogBasicBlock(&emlrtCoverageInstance, 4, 2);
        st.site = &sy_emlrtRSI;
        b_st.site = &gh_emlrtRSI;
        c_st.site = &cab_emlrtRSI;
        for (k = 0; k < 3; k++) {
          aoffset = k * 3;
          b_y[k] =
              (static_cast<real_T>(iv[aoffset]) * PatternPositions[n].f1[3] +
               static_cast<real_T>(iv[aoffset + 1]) *
                   PatternPositions[n].f1[7]) +
              static_cast<real_T>(iv[aoffset + 2]) * PatternPositions[n].f1[11];
        }
        for (i1 = 0; i1 < 3; i1++) {
          for (i2 = 0; i2 < 3; i2++) {
            b_PatternPositions[i1 + 3 * i2] =
                (PatternPositions[n].f1[i1] * static_cast<real_T>(iv[3 * i2]) +
                 PatternPositions[n].f1[i1 + 4] *
                     static_cast<real_T>(iv[3 * i2 + 1])) +
                PatternPositions[n].f1[i1 + 8] *
                    static_cast<real_T>(iv[3 * i2 + 2]);
          }
        }
        for (i1 = 0; i1 < 3; i1++) {
          aoffset = i1 << 2;
          c_PatternPositions[aoffset] = b_PatternPositions[3 * i1];
          c_PatternPositions[aoffset + 1] = b_PatternPositions[3 * i1 + 1];
          c_PatternPositions[aoffset + 2] = b_PatternPositions[3 * i1 + 2];
          c_PatternPositions[aoffset + 3] = b_y[i1];
        }
        for (i1 = 0; i1 < 4; i1++) {
          real_T d;
          alpha1 = c_PatternPositions[i1];
          beta1 = c_PatternPositions[i1 + 4];
          d = c_PatternPositions[i1 + 8];
          for (i2 = 0; i2 < 3; i2++) {
            cameraMatrix[i1 + (i2 << 2)] =
                (alpha1 * CameraParameters.IntrinsicMatrix[3 * i2] +
                 beta1 * CameraParameters.IntrinsicMatrix[3 * i2 + 1]) +
                d * CameraParameters.IntrinsicMatrix[3 * i2 + 2];
          }
        }
        st.site = &ty_emlrtRSI;
        b_st.site = &vx_emlrtRSI;
        if ((genPoints.size(0) != 0) && (genPoints.size(1) != 0)) {
          k = genPoints.size(0);
        } else if (genPoints.size(0) != 0) {
          k = genPoints.size(0);
        } else {
          k = 0;
        }
        c_st.site = &cn_emlrtRSI;
        if ((genPoints.size(0) != k) &&
            ((genPoints.size(0) != 0) && (genPoints.size(1) != 0))) {
          emlrtErrorWithMessageIdR2018a(
              &c_st, &emlrtRTEI, "MATLAB:catenate:matrixDimensionMismatch",
              "MATLAB:catenate:matrixDimensionMismatch", 0);
        }
        if ((genPoints.size(0) != k) && (genPoints.size(0) != 0)) {
          emlrtErrorWithMessageIdR2018a(
              &c_st, &emlrtRTEI, "MATLAB:catenate:matrixDimensionMismatch",
              "MATLAB:catenate:matrixDimensionMismatch", 0);
        }
        empty_non_axis_sizes = (k == 0);
        if (empty_non_axis_sizes ||
            ((genPoints.size(0) != 0) && (genPoints.size(1) != 0))) {
          i3 = static_cast<int8_T>(genPoints.size(1));
        } else {
          i3 = 0;
        }
        if (empty_non_axis_sizes || (genPoints.size(0) != 0)) {
          sizes_idx_1 = 1;
        } else {
          sizes_idx_1 = 0;
        }
        result.set_size(&vq_emlrtRTEI, &b_st, k, i3 + sizes_idx_1);
        aoffset = i3;
        for (i1 = 0; i1 < aoffset; i1++) {
          for (i2 = 0; i2 < k; i2++) {
            result[i2 + result.size(0) * i1] = genPoints[i2 + k * i1];
          }
        }
        aoffset = sizes_idx_1;
        for (i1 = 0; i1 < aoffset; i1++) {
          for (i2 = 0; i2 < k; i2++) {
            result[i2 + result.size(0) * i3] = 1.0;
          }
        }
        st.site = &ty_emlrtRSI;
        b_st.site = &hh_emlrtRSI;
        if (result.size(1) != 4) {
          if ((result.size(0) == 1) && (result.size(1) == 1)) {
            emlrtErrorWithMessageIdR2018a(
                &b_st, &y_emlrtRTEI,
                "Coder:toolbox:mtimes_noDynamicScalarExpansion",
                "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
          } else {
            emlrtErrorWithMessageIdR2018a(
                &b_st, &ab_emlrtRTEI, "MATLAB:innerdim", "MATLAB:innerdim", 0);
          }
        }
        b_st.site = &gh_emlrtRSI;
        if (result.size(0) == 0) {
          projectedPointsraw.set_size(&wq_emlrtRTEI, &b_st, 0, 3);
        } else {
          c_st.site = &ih_emlrtRSI;
          d_st.site = &jh_emlrtRSI;
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
          projectedPointsraw.set_size(&mg_emlrtRTEI, &d_st, result.size(0), 3);
          dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1,
                &(result.data())[0], &lda_t, &cameraMatrix[0], &ldb_t, &beta1,
                &(projectedPointsraw.data())[0], &ldc_t);
        }
        aoffset = projectedPointsraw.size(0);
        distortedPoints.set_size(&xq_emlrtRTEI, sp, projectedPointsraw.size(0),
                                 2);
        for (i1 = 0; i1 < 2; i1++) {
          for (i2 = 0; i2 < aoffset; i2++) {
            distortedPoints[i2 + distortedPoints.size(0) * i1] =
                projectedPointsraw[i2 + projectedPointsraw.size(0) * i1];
          }
        }
        aoffset = projectedPointsraw.size(0);
        b_error.set_size(&yq_emlrtRTEI, sp, projectedPointsraw.size(0));
        for (i1 = 0; i1 < aoffset; i1++) {
          b_error[i1] = projectedPointsraw[i1 + projectedPointsraw.size(0) * 2];
        }
        st.site = &uy_emlrtRSI;
        coder::bsxfun(&st, distortedPoints, b_error, projectedPointsnorm);
        st.site = &vy_emlrtRSI;
        coder::vision::internal::calibration::distortPoints(
            &st, projectedPointsnorm, CameraParameters.IntrinsicMatrix,
            CameraParameters.RadialDistortion,
            CameraParameters.TangentialDistortion, distortedPoints);
        if ((distortedPoints.size(0) != detPoints.size(0)) &&
            ((distortedPoints.size(0) != 1) && (detPoints.size(0) != 1))) {
          emlrtDimSizeImpxCheckR2021b(distortedPoints.size(0),
                                      detPoints.size(0), &dd_emlrtECI,
                                      (emlrtCTX)sp);
        }
        st.site = &wy_emlrtRSI;
        if (distortedPoints.size(0) == points.size(0)) {
          aoffset = distortedPoints.size(0) * 2;
          points.set_size(&ar_emlrtRTEI, &st, distortedPoints.size(0), 2);
          for (i1 = 0; i1 < aoffset; i1++) {
            alpha1 = distortedPoints[i1] - points[i1];
            points[i1] = alpha1 * alpha1;
          }
        } else {
          b_st.site = &mbb_emlrtRSI;
          binary_expand_op(&b_st, points, distortedPoints);
        }
        b_st.site = &wy_emlrtRSI;
        coder::sum(&b_st, points, b_error);
        empty_non_axis_sizes = false;
        i1 = b_error.size(0);
        for (k = 0; k < i1; k++) {
          if (empty_non_axis_sizes || (b_error[k] < 0.0)) {
            empty_non_axis_sizes = true;
          }
        }
        if (empty_non_axis_sizes) {
          emlrtErrorWithMessageIdR2018a(
              &st, &u_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
              "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
        }
        b_st.site = &mab_emlrtRSI;
        aoffset = b_error.size(0);
        c_st.site = &nab_emlrtRSI;
        if ((1 <= b_error.size(0)) && (b_error.size(0) > 2147483646)) {
          d_st.site = &hc_emlrtRSI;
          coder::check_forloop_overflow_error(&d_st);
        }
        for (k = 0; k < aoffset; k++) {
          b_error[k] = muDoubleScalarSqrt(b_error[k]);
        }
        alpha1 = ((static_cast<real_T>(n) + 1.0) - 1.0) *
                     static_cast<real_T>(b_error.size(0)) +
                 1.0;
        beta1 = (static_cast<real_T>(n) + 1.0) *
                static_cast<real_T>(b_error.size(0));
        if (alpha1 > beta1) {
          i1 = -1;
          i2 = -1;
        } else {
          if ((static_cast<int32_T>(alpha1) < 1) ||
              (static_cast<int32_T>(alpha1) > cost.size(0))) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(alpha1), 1,
                                          cost.size(0), &pt_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          i1 = static_cast<int32_T>(alpha1) - 2;
          if ((static_cast<int32_T>(beta1) < 1) ||
              (static_cast<int32_T>(beta1) > cost.size(0))) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(beta1), 1,
                                          cost.size(0), &ot_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          i2 = static_cast<int32_T>(beta1) - 1;
        }
        aoffset = i2 - i1;
        if (aoffset != b_error.size(0)) {
          emlrtSubAssignSizeCheck1dR2017a(aoffset, b_error.size(0),
                                          &cd_emlrtECI, (emlrtCTX)sp);
        }
        for (i2 = 0; i2 < aoffset; i2++) {
          cost[(i1 + i2) + 1] = b_error[i2];
        }
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      covrtLogMcdc(&emlrtCoverageInstance, 4, 0, 0, false);
      covrtLogIf(&emlrtCoverageInstance, 4, 0, 0, false);
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 4, 0, 0, 0);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace Codegen

// End of code generation (CalculateCost.cpp)
