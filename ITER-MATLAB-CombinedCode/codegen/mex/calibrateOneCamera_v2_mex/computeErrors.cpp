//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeErrors.cpp
//
// Code generation for function 'computeErrors'
//

// Include files
#include "computeErrors.h"
#include "bsxfun.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "inv.h"
#include "mean.h"
#include "rotm2axang.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "sum.h"
#include "unsafeSxfun.h"
#include "blas.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstddef>

// Variable Definitions
static emlrtRSInfo hgb_emlrtRSI{
    36,              // lineNo
    "computeErrors", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m" // pathName
};

static emlrtRSInfo igb_emlrtRSI{
    47,              // lineNo
    "computeErrors", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m" // pathName
};

static emlrtRSInfo jgb_emlrtRSI{
    48,              // lineNo
    "computeErrors", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m" // pathName
};

static emlrtRSInfo kgb_emlrtRSI{
    51,              // lineNo
    "computeErrors", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m" // pathName
};

static emlrtRSInfo lgb_emlrtRSI{
    60,              // lineNo
    "computeErrors", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m" // pathName
};

static emlrtRSInfo mgb_emlrtRSI{
    68,              // lineNo
    "computeErrors", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m" // pathName
};

static emlrtRSInfo ngb_emlrtRSI{
    69,              // lineNo
    "computeErrors", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m" // pathName
};

static emlrtRSInfo ogb_emlrtRSI{
    70,              // lineNo
    "computeErrors", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m" // pathName
};

static emlrtRSInfo pgb_emlrtRSI{
    72,              // lineNo
    "computeErrors", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m" // pathName
};

static emlrtRSInfo bhb_emlrtRSI{
    35,                                                          // lineNo
    "@(ptProj)selectRow12(bsxfun(@rdivide,ptProj,ptProj(3,:)))", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m" // pathName
};

static emlrtBCInfo pv_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    47,              // lineNo
    22,              // colNo
    "PoseErrR",      // aName
    "computeErrors", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m", // pName
    0                                                  // checkKind
};

static emlrtBCInfo qv_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    47,              // lineNo
    68,              // colNo
    "Hcam2grid",     // aName
    "computeErrors", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m", // pName
    0                                                  // checkKind
};

static emlrtBCInfo rv_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    47,              // lineNo
    92,              // colNo
    "Hhand2base",    // aName
    "computeErrors", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m", // pName
    0                                                  // checkKind
};

static emlrtBCInfo sv_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    48,              // lineNo
    42,              // colNo
    "PoseErrR",      // aName
    "computeErrors", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m", // pName
    0                                                  // checkKind
};

static emlrtBCInfo tv_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    57,              // lineNo
    48,              // colNo
    "Hhand2base",    // aName
    "computeErrors", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m", // pName
    0                                                  // checkKind
};

static emlrtBCInfo uv_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    57,              // lineNo
    90,              // colNo
    "Hhand2base",    // aName
    "computeErrors", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m", // pName
    0                                                  // checkKind
};

static emlrtBCInfo vv_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    58,              // lineNo
    60,              // colNo
    "Hcam2grid",     // aName
    "computeErrors", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m", // pName
    0                                                  // checkKind
};

static emlrtBCInfo wv_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    57,              // lineNo
    19,              // colNo
    "PoseErrt",      // aName
    "computeErrors", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m", // pName
    0                                                  // checkKind
};

static emlrtBCInfo xv_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    66,              // lineNo
    26,              // colNo
    "Hhand2base",    // aName
    "computeErrors", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m", // pName
    0                                                  // checkKind
};

static emlrtBCInfo yv_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    67,              // lineNo
    25,              // colNo
    "imgPts",        // aName
    "computeErrors", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m", // pName
    0                                                  // checkKind
};

static emlrtECInfo wd_emlrtECI{
    1,               // nDims
    70,              // lineNo
    25,              // colNo
    "computeErrors", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m" // pName
};

static emlrtBCInfo aw_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    70,              // lineNo
    15,              // colNo
    "err",           // aName
    "computeErrors", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m", // pName
    0                                                  // checkKind
};

static emlrtECInfo xd_emlrtECI{
    -1,              // nDims
    70,              // lineNo
    9,               // colNo
    "computeErrors", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m" // pName
};

static emlrtBCInfo bw_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    49,              // lineNo
    14,              // colNo
    "angR",          // aName
    "computeErrors", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m", // pName
    0                                                  // checkKind
};

static emlrtRTEInfo pv_emlrtRTEI{
    36,              // lineNo
    8,               // colNo
    "computeErrors", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m" // pName
};

static emlrtRTEInfo qv_emlrtRTEI{
    45,              // lineNo
    5,               // colNo
    "computeErrors", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m" // pName
};

static emlrtRTEInfo rv_emlrtRTEI{
    45,              // lineNo
    33,              // colNo
    "computeErrors", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m" // pName
};

static emlrtRTEInfo sv_emlrtRTEI{
    55,              // lineNo
    14,              // colNo
    "computeErrors", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m" // pName
};

static emlrtRTEInfo tv_emlrtRTEI{
    64,              // lineNo
    5,               // colNo
    "computeErrors", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m" // pName
};

static emlrtRTEInfo uv_emlrtRTEI{
    35,              // lineNo
    58,              // colNo
    "computeErrors", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m" // pName
};

static emlrtRTEInfo vv_emlrtRTEI{
    69,              // lineNo
    9,               // colNo
    "computeErrors", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m" // pName
};

static emlrtRTEInfo wv_emlrtRTEI{
    70,              // lineNo
    13,              // colNo
    "computeErrors", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\computeErrors.m" // pName
};

static emlrtRTEInfo
    yv_emlrtRTEI{
        71,      // lineNo
        5,       // colNo
        "power", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\power.m" // pName
    };

// Function Definitions
void computeErrors(const emlrtStack *sp,
                   const coder::array<real_T, 3U> &Hhand2base,
                   const real_T Hhand2eye[16], const real_T Hbase2grid[16],
                   const coder::array<real_T, 3U> &Hcam2grid,
                   const coder::array<real_T, 3U> &imgPts,
                   const coder::array<real_T, 2U> &Worldpts, const real_T K[12],
                   real_T errors[3])
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  coder::array<real_T, 3U> PoseErrR;
  coder::array<real_T, 2U> PoseErrt;
  coder::array<real_T, 2U> b_y;
  coder::array<real_T, 2U> c_y;
  coder::array<real_T, 2U> err;
  coder::array<real_T, 2U> proj;
  coder::array<real_T, 2U> r;
  coder::array<real_T, 2U> x;
  coder::array<real_T, 2U> y;
  coder::array<real_T, 1U> angR;
  coder::array<real_T, 1U> r1;
  coder::array<int32_T, 1U> r2;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T HT[16];
  real_T b_a[16];
  real_T a[9];
  real_T b_Hhand2eye[9];
  real_T AxAngVec[4];
  real_T b_Hhand2base[3];
  real_T c_Hhand2eye[3];
  real_T Rerr;
  real_T alpha1;
  real_T beta1;
  real_T d;
  real_T terr;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T j;
  int32_T loop_ub;
  int32_T result;
  char_T TRANSA1;
  char_T TRANSB1;
  int8_T b_input_sizes_idx_1;
  int8_T input_sizes_idx_1;
  int8_T sizes_idx_1;
  boolean_T empty_non_axis_sizes;
  boolean_T innerDimOk;
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
  // where the Input:
  // Hhand2base         a 4x4xNumber_of_Views Matrix of the form
  //                    Hhand2base(:,:,i) = [Ri_3x3 ti_3x1;[ 0 0 0 1]]
  //                    with
  //                    i = number of the view,
  //                    Ri_3x3 the rotation matrix
  //                    ti_3x1 the translation vector.
  // Hhand2eye          a 4x4xNumber_entries_to_examine Matrix of the form
  //                    Hhand2eye(:,:,i) = [Ri_3x3 ti_3x1;[ 0 0 0 1]]
  // Hbase2grid         a 4x4xNumber_entries_to_examine Matrix of the form
  //                    Hbase2grid(:,:,i) = [Ri_3x3 ti_3x1;[ 0 0 0 1]]
  // Hcam2grid          a 4x4xNumber_of_Views Matrix (like above)
  //                    Defining the transformation of the  camera to the
  //                    grid/calibration block/world
  // K                  The camera intrinsic  (4x4 matrix)
  // imgPts             an array with  containing the imgpoints corresponding to
  // the corner points on the
  //                    calibration board.(Nx2xM), where N is number of corners
  //                    in M images
  //                    and M is the number of calibration images
  // Worldpts           world coordinates of the corners (Nx2) matrix
  // Output:
  // Rerr               The rotation error in degrees corresponding to each
  //                    each entry
  // terr               The translation error in meters corresponding to each
  // each entry ReprojErr          The reprojection error from reprojecting the
  // world/grid
  //                    points on the camera images corresponding to each each
  //                    entry
  //  computing dependencies
  //  % Divide with Z to complete the perspective projection
  st.site = &hgb_emlrtRSI;
  b_st.site = &lcb_emlrtRSI;
  if (Worldpts.size(0) != 0) {
    result = Worldpts.size(0);
  } else {
    result = 0;
  }
  c_st.site = &uo_emlrtRSI;
  if ((Worldpts.size(0) != result) && (Worldpts.size(0) != 0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  if ((Worldpts.size(0) != result) && (Worldpts.size(0) != 0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  if ((Worldpts.size(0) != result) && (Worldpts.size(0) != 0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  empty_non_axis_sizes = (result == 0);
  if (empty_non_axis_sizes || (Worldpts.size(0) != 0)) {
    input_sizes_idx_1 = 2;
  } else {
    input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes || (Worldpts.size(0) != 0)) {
    b_input_sizes_idx_1 = 1;
  } else {
    b_input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes || (Worldpts.size(0) != 0)) {
    sizes_idx_1 = 1;
  } else {
    sizes_idx_1 = 0;
  }
  r.set_size(&pv_emlrtRTEI, &b_st, result,
             (input_sizes_idx_1 + b_input_sizes_idx_1) + sizes_idx_1);
  loop_ub = input_sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < result; i1++) {
      r[i1 + r.size(0) * i] = Worldpts[i1 + result * i];
    }
  }
  loop_ub = b_input_sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < result; i1++) {
      r[i1 + r.size(0) * input_sizes_idx_1] = 0.0;
    }
  }
  loop_ub = sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < result; i1++) {
      r[i1 + r.size(0) * (input_sizes_idx_1 + b_input_sizes_idx_1)] = 1.0;
    }
  }
  //  Computing Errors
  covrtLogFor(&emlrtCoverageInstance, 4, 0, 0, 1);
  covrtLogBasicBlock(&emlrtCoverageInstance, 4, 3);
  //     %% Computing Rotation errors distribution
  angR.set_size(&qv_emlrtRTEI, sp, imgPts.size(2));
  loop_ub = imgPts.size(2);
  for (i = 0; i < loop_ub; i++) {
    angR[i] = 0.0;
  }
  PoseErrR.set_size(&rv_emlrtRTEI, sp, 3, 3, imgPts.size(2));
  loop_ub = 9 * imgPts.size(2);
  for (i = 0; i < loop_ub; i++) {
    PoseErrR[i] = 0.0;
  }
  i = imgPts.size(2);
  for (j = 0; j < i; j++) {
    covrtLogFor(&emlrtCoverageInstance, 4, 0, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 4, 4);
    if (j + 1 > Hcam2grid.size(2)) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, Hcam2grid.size(2), &qv_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (j + 1 > Hhand2base.size(2)) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, Hhand2base.size(2), &rv_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < 3; i1++) {
      alpha1 = Hhand2eye[i1];
      beta1 = Hhand2eye[i1 + 4];
      d = Hhand2eye[i1 + 8];
      for (i2 = 0; i2 < 3; i2++) {
        b_Hhand2eye[i1 + 3 * i2] = (alpha1 * Hcam2grid[4 * i2 + 16 * j] +
                                    beta1 * Hcam2grid[(4 * i2 + 16 * j) + 1]) +
                                   d * Hcam2grid[(4 * i2 + 16 * j) + 2];
      }
    }
    st.site = &igb_emlrtRSI;
    coder::inv(&st, b_Hhand2eye, a);
    for (i1 = 0; i1 < 3; i1++) {
      for (i2 = 0; i2 < 3; i2++) {
        result = i2 << 2;
        b_Hhand2eye[i1 + 3 * i2] =
            (Hhand2base[i1 + 16 * j] * Hbase2grid[result] +
             Hhand2base[(i1 + 16 * j) + 4] * Hbase2grid[result + 1]) +
            Hhand2base[(i1 + 16 * j) + 8] * Hbase2grid[result + 2];
      }
    }
    if (j + 1 > PoseErrR.size(2)) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, PoseErrR.size(2), &pv_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < 3; i1++) {
      alpha1 = a[i1];
      beta1 = a[i1 + 3];
      d = a[i1 + 6];
      for (i2 = 0; i2 < 3; i2++) {
        PoseErrR[(i1 + 3 * i2) + 9 * j] =
            (alpha1 * b_Hhand2eye[3 * i2] + beta1 * b_Hhand2eye[3 * i2 + 1]) +
            d * b_Hhand2eye[3 * i2 + 2];
      }
    }
    //  inv(Rz*Rb)(Ra*Rx)
    if (j + 1 > PoseErrR.size(2)) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, PoseErrR.size(2), &sv_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    st.site = &jgb_emlrtRSI;
    coder::rotm2axang(&st, *(real_T(*)[9]) & PoseErrR[9 * j], AxAngVec);
    if (j + 1 > angR.size(0)) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, angR.size(0), &bw_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    angR[j] = AxAngVec[3] * 57.295779513082323;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 4, 0, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 4, 5);
  st.site = &kgb_emlrtRSI;
  b_st.site = &fd_emlrtRSI;
  r1.set_size(&yv_emlrtRTEI, &b_st, angR.size(0));
  loop_ub = angR.size(0);
  for (i = 0; i < loop_ub; i++) {
    alpha1 = angR[i];
    r1[i] = alpha1 * alpha1;
  }
  st.site = &kgb_emlrtRSI;
  coder::sum(&st, r1, angR);
  st.site = &kgb_emlrtRSI;
  coder::b_sqrt(&st, angR);
  st.site = &kgb_emlrtRSI;
  Rerr = coder::mean(&st, angR);
  //     %% Computing Translation errors distribution
  PoseErrt.set_size(&sv_emlrtRTEI, sp, imgPts.size(2), 3);
  i = imgPts.size(2);
  for (j = 0; j < i; j++) {
    covrtLogFor(&emlrtCoverageInstance, 4, 0, 2, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 4, 6);
    if (j + 1 > Hhand2base.size(2)) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, Hhand2base.size(2), &tv_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (j + 1 > Hcam2grid.size(2)) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, Hcam2grid.size(2), &vv_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    alpha1 = Hbase2grid[12];
    beta1 = Hbase2grid[13];
    d = Hbase2grid[14];
    for (i1 = 0; i1 < 3; i1++) {
      b_Hhand2base[i1] = (Hhand2base[i1 + 16 * j] * alpha1 +
                          Hhand2base[(i1 + 16 * j) + 4] * beta1) +
                         Hhand2base[(i1 + 16 * j) + 8] * d;
    }
    if (j + 1 > Hhand2base.size(2)) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, Hhand2base.size(2), &uv_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < 3; i1++) {
      c_Hhand2eye[i1] = (Hhand2eye[i1] * Hcam2grid[16 * j + 12] +
                         Hhand2eye[i1 + 4] * Hcam2grid[16 * j + 13]) +
                        Hhand2eye[i1 + 8] * Hcam2grid[16 * j + 14];
    }
    if (j + 1 > PoseErrt.size(0)) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, PoseErrt.size(0), &wv_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    PoseErrt[j] = (b_Hhand2base[0] + Hhand2base[16 * j + 12]) -
                  (c_Hhand2eye[0] + Hhand2eye[12]);
    PoseErrt[j + PoseErrt.size(0)] =
        (b_Hhand2base[1] + Hhand2base[16 * j + 13]) -
        (c_Hhand2eye[1] + Hhand2eye[13]);
    PoseErrt[j + PoseErrt.size(0) * 2] =
        (b_Hhand2base[2] + Hhand2base[16 * j + 14]) -
        (c_Hhand2eye[2] + Hhand2eye[14]);
    // (Ra*tx)+ta -(Rz*tb)+tz
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 4, 0, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 4, 7);
  loop_ub = PoseErrt.size(0) * 3;
  PoseErrt.set_size(&st_emlrtRTEI, sp, PoseErrt.size(0), 3);
  for (i = 0; i < loop_ub; i++) {
    alpha1 = PoseErrt[i];
    PoseErrt[i] = alpha1 * alpha1;
  }
  st.site = &lgb_emlrtRSI;
  coder::b_sum(&st, PoseErrt, r1);
  st.site = &lgb_emlrtRSI;
  coder::b_sqrt(&st, r1);
  st.site = &lgb_emlrtRSI;
  terr = coder::mean(&st, r1);
  //     %% Computing Reprojection errors
  err.set_size(&tv_emlrtRTEI, sp, imgPts.size(0), imgPts.size(2));
  loop_ub = imgPts.size(0) * imgPts.size(2);
  for (i = 0; i < loop_ub; i++) {
    err[i] = 0.0;
  }
  i = imgPts.size(2);
  if (0 <= imgPts.size(2) - 1) {
    innerDimOk = (4 == r.size(1));
  }
  for (j = 0; j < i; j++) {
    covrtLogFor(&emlrtCoverageInstance, 4, 0, 3, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 4, 8);
    if (j + 1 > Hhand2base.size(2)) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, Hhand2base.size(2), &xv_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (j + 1 > imgPts.size(2)) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, imgPts.size(2), &yv_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    st.site = &mgb_emlrtRSI;
    coder::b_inv(&st, Hhand2eye, HT);
    for (i1 = 0; i1 < 4; i1++) {
      real_T d1;
      alpha1 = HT[i1];
      beta1 = HT[i1 + 4];
      d = HT[i1 + 8];
      d1 = HT[i1 + 12];
      for (i2 = 0; i2 < 4; i2++) {
        b_a[i1 + (i2 << 2)] = ((alpha1 * Hhand2base[4 * i2 + 16 * j] +
                                beta1 * Hhand2base[(4 * i2 + 16 * j) + 1]) +
                               d * Hhand2base[(4 * i2 + 16 * j) + 2]) +
                              d1 * Hhand2base[(4 * i2 + 16 * j) + 3];
      }
      alpha1 = b_a[i1];
      beta1 = b_a[i1 + 4];
      d = b_a[i1 + 8];
      d1 = b_a[i1 + 12];
      for (i2 = 0; i2 < 4; i2++) {
        result = i2 << 2;
        HT[i1 + result] =
            ((alpha1 * Hbase2grid[result] + beta1 * Hbase2grid[result + 1]) +
             d * Hbase2grid[result + 2]) +
            d1 * Hbase2grid[result + 3];
      }
    }
    //  either inv(Z)*A*X  ,where Z is H2e and X is base 2 grid
    st.site = &ngb_emlrtRSI;
    b_st.site = &qi_emlrtRSI;
    if (!innerDimOk) {
      if ((r.size(0) == 1) && (r.size(1) == 1)) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &bb_emlrtRTEI,
            "Coder:toolbox:mtimes_noDynamicScalarExpansion",
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &cb_emlrtRTEI, "MATLAB:innerdim",
                                      "MATLAB:innerdim", 0);
      }
    }
    b_st.site = &pi_emlrtRSI;
    if ((r.size(0) == 0) || (r.size(1) == 0)) {
      y.set_size(&nh_emlrtRTEI, &b_st, 4, r.size(0));
      loop_ub = r.size(0) << 2;
      for (i1 = 0; i1 < loop_ub; i1++) {
        y[i1] = 0.0;
      }
    } else {
      c_st.site = &ri_emlrtRSI;
      d_st.site = &si_emlrtRSI;
      TRANSB1 = 'T';
      TRANSA1 = 'N';
      alpha1 = 1.0;
      beta1 = 0.0;
      m_t = (ptrdiff_t)4;
      n_t = (ptrdiff_t)r.size(0);
      k_t = (ptrdiff_t)4;
      lda_t = (ptrdiff_t)4;
      ldb_t = (ptrdiff_t)r.size(0);
      ldc_t = (ptrdiff_t)4;
      y.set_size(&mh_emlrtRTEI, &d_st, 4, r.size(0));
      dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &HT[0], &lda_t,
            &(r.data())[0], &ldb_t, &beta1, &(y.data())[0], &ldc_t);
    }
    st.site = &ngb_emlrtRSI;
    b_st.site = &pi_emlrtRSI;
    if (y.size(1) == 0) {
      b_y.set_size(&nh_emlrtRTEI, &b_st, 3, 0);
    } else {
      c_st.site = &ri_emlrtRSI;
      d_st.site = &si_emlrtRSI;
      TRANSB1 = 'N';
      TRANSA1 = 'N';
      alpha1 = 1.0;
      beta1 = 0.0;
      m_t = (ptrdiff_t)3;
      n_t = (ptrdiff_t)y.size(1);
      k_t = (ptrdiff_t)4;
      lda_t = (ptrdiff_t)3;
      ldb_t = (ptrdiff_t)4;
      ldc_t = (ptrdiff_t)3;
      b_y.set_size(&mh_emlrtRTEI, &d_st, 3, y.size(1));
      dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&K[0],
            &lda_t, &(y.data())[0], &ldb_t, &beta1, &(b_y.data())[0], &ldc_t);
    }
    st.site = &ngb_emlrtRSI;
    b_st.site = &rcb_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 4, 2);
    covrtLogBasicBlock(&emlrtCoverageInstance, 4, 2);
    c_st.site = &bhb_emlrtRSI;
    loop_ub = b_y.size(1);
    c_y.set_size(&uv_emlrtRTEI, &c_st, 1, b_y.size(1));
    for (i1 = 0; i1 < loop_ub; i1++) {
      c_y[i1] = b_y[3 * i1 + 2];
    }
    d_st.site = &bhb_emlrtRSI;
    coder::bsxfun(&d_st, b_y, c_y, x);
    covrtLogFcn(&emlrtCoverageInstance, 4, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 4, 1);
    loop_ub = x.size(1);
    proj.set_size(&vv_emlrtRTEI, sp, x.size(1), 2);
    for (i1 = 0; i1 < 2; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        proj[i2 + proj.size(0) * i1] = x[i1 + 3 * i2];
      }
    }
    // need to invert HT befor invR, if the representation change of whole
    // inverse is followed
    if ((imgPts.size(0) != proj.size(0)) &&
        ((imgPts.size(0) != 1) && (proj.size(0) != 1))) {
      emlrtDimSizeImpxCheckR2021b(imgPts.size(0), proj.size(0), &wd_emlrtECI,
                                  (emlrtCTX)sp);
    }
    loop_ub = err.size(0);
    r2.set_size(&wv_emlrtRTEI, sp, err.size(0));
    for (i1 = 0; i1 < loop_ub; i1++) {
      r2[i1] = i1;
    }
    if (j + 1 > err.size(1)) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, err.size(1), &aw_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    loop_ub = imgPts.size(0);
    if (imgPts.size(0) == proj.size(0)) {
      proj.set_size(&st_emlrtRTEI, sp, imgPts.size(0), 2);
      for (i1 = 0; i1 < 2; i1++) {
        for (i2 = 0; i2 < loop_ub; i2++) {
          alpha1 = imgPts[(i2 + imgPts.size(0) * i1) + imgPts.size(0) * 2 * j] -
                   proj[i2 + proj.size(0) * i1];
          proj[i2 + proj.size(0) * i1] = alpha1 * alpha1;
        }
      }
    } else {
      st.site = &ejb_emlrtRSI;
      b_binary_expand_op(&st, proj, imgPts, j);
    }
    st.site = &ogb_emlrtRSI;
    coder::sum(&st, proj, r1);
    emlrtSubAssignSizeCheckR2012b(r2.size(), 1, r1.size(), 1, &xd_emlrtECI,
                                  (emlrtCTX)sp);
    loop_ub = r1.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      err[r2[i1] + err.size(0) * j] = r1[i1];
    }
    //  adopted approach
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 4, 0, 3, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 4, 9);
  st.site = &pgb_emlrtRSI;
  result = err.size(0) * err.size(1);
  angR = err.reshape(result);
  b_st.site = &pgb_emlrtRSI;
  alpha1 = coder::mean(&b_st, angR);
  if (alpha1 < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &x_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  // rrmse
  covrtLogFor(&emlrtCoverageInstance, 4, 0, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 4, 10);
  errors[0] = Rerr;
  errors[1] = terr;
  errors[2] = muDoubleScalarSqrt(alpha1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

// End of code generation (computeErrors.cpp)
