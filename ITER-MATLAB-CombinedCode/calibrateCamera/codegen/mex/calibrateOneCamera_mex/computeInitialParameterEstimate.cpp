//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeInitialParameterEstimate.cpp
//
// Code generation for function 'computeInitialParameterEstimate'
//

// Include files
#include "computeInitialParameterEstimate.h"
#include "all.h"
#include "calibrateOneCamera_mex_data.h"
#include "calibrateOneCamera_mex_types.h"
#include "cameraParameters.h"
#include "fitgeotrans.h"
#include "inv.h"
#include "projective2d.h"
#include "rodriguesMatrixToVector.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo ms_emlrtRSI{
    6,                                 // lineNo
    "computeInitialParameterEstimate", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo ns_emlrtRSI{
    12,                                // lineNo
    "computeInitialParameterEstimate", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo os_emlrtRSI{
    13,                                // lineNo
    "computeInitialParameterEstimate", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo ps_emlrtRSI{
    14,                                // lineNo
    "computeInitialParameterEstimate", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo qs_emlrtRSI{
    16,                                // lineNo
    "computeInitialParameterEstimate", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo rs_emlrtRSI{
    20,                                // lineNo
    "computeInitialParameterEstimate", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo ss_emlrtRSI{
    31,                                // lineNo
    "computeInitialParameterEstimate", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo ts_emlrtRSI{
    113,                   // lineNo
    "computeHomographies", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo us_emlrtRSI{
    105,                   // lineNo
    "computeHomographies", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo vs_emlrtRSI{
    87,                  // lineNo
    "computeHomography", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo jv_emlrtRSI{
    135,        // lineNo
    "computeV", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo kv_emlrtRSI{
    136,        // lineNo
    "computeV", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo lv_emlrtRSI{
    148,        // lineNo
    "computeB", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo nv_emlrtRSI{
    158,                 // lineNo
    "computeIntrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo ov_emlrtRSI{
    159,                 // lineNo
    "computeIntrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo pv_emlrtRSI{
    160,                 // lineNo
    "computeIntrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo qv_emlrtRSI{
    161,                 // lineNo
    "computeIntrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo rv_emlrtRSI{
    162,                 // lineNo
    "computeIntrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo sv_emlrtRSI{
    163,                 // lineNo
    "computeIntrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo tv_emlrtRSI{
    180,                 // lineNo
    "computeExtrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo uv_emlrtRSI{
    194,                 // lineNo
    "computeExtrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtBCInfo ms_emlrtBCI{
    -1,                    // iFirst
    -1,                    // iLast
    105,                   // lineNo
    51,                    // colNo
    "points",              // aName
    "computeHomographies", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    0                                        // checkKind
};

static emlrtBCInfo ns_emlrtBCI{
    -1,             // iFirst
    -1,             // iLast
    134,            // lineNo
    28,             // colNo
    "homographies", // aName
    "computeV",     // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    0                                        // checkKind
};

static emlrtBCInfo os_emlrtBCI{
    -1,         // iFirst
    -1,         // iLast
    136,        // lineNo
    7,          // colNo
    "V",        // aName
    "computeV", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    0                                        // checkKind
};

static emlrtBCInfo ps_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    182,                 // lineNo
    28,                  // colNo
    "homographies",      // aName
    "computeExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    0                                        // checkKind
};

static emlrtBCInfo qs_emlrtBCI{
    -1,                    // iFirst
    -1,                    // iLast
    104,                   // lineNo
    28,                    // colNo
    "homographies",        // aName
    "computeHomographies", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    0                                        // checkKind
};

static emlrtBCInfo rs_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    85,                  // lineNo
    39,                  // colNo
    "imagePoints",       // aName
    "computeHomography", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    0                                        // checkKind
};

static emlrtBCInfo ss_emlrtBCI{
    -1,         // iFirst
    -1,         // iLast
    135,        // lineNo
    7,          // colNo
    "V",        // aName
    "computeV", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    0                                        // checkKind
};

static emlrtBCInfo ts_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    198,                  // lineNo
    27,                   // colNo
    "translationVectors", // aName
    "computeExtrinsics",  // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    0                                        // checkKind
};

static emlrtDCInfo jd_emlrtDCI{
    132,        // lineNo
    11,         // colNo
    "computeV", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    1                                        // checkKind
};

static emlrtBCInfo us_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    87,                  // lineNo
    29,                  // colNo
    "worldPoints",       // aName
    "computeHomography", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    0                                        // checkKind
};

static emlrtBCInfo vs_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    87,                  // lineNo
    60,                  // colNo
    "imagePoints",       // aName
    "computeHomography", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    0                                        // checkKind
};

static emlrtDCInfo kd_emlrtDCI{
    12,                                // lineNo
    1,                                 // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    1                                        // checkKind
};

static emlrtBCInfo ws_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    194,                 // lineNo
    24,                  // colNo
    "rotationVectors",   // aName
    "computeExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    0                                        // checkKind
};

static emlrtBCInfo xs_emlrtBCI{
    -1,                    // iFirst
    -1,                    // iLast
    112,                   // lineNo
    35,                    // colNo
    "homographies",        // aName
    "computeHomographies", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    0                                        // checkKind
};

static emlrtRTEInfo cp_emlrtRTEI{
    100,                               // lineNo
    1,                                 // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo dp_emlrtRTEI{
    101,                               // lineNo
    1,                                 // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo ep_emlrtRTEI{
    105,                               // lineNo
    13,                                // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo fp_emlrtRTEI{
    87,                                // lineNo
    17,                                // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo gp_emlrtRTEI{
    87,                                // lineNo
    48,                                // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo hp_emlrtRTEI{
    6,                                 // lineNo
    1,                                 // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo ip_emlrtRTEI{
    112,                               // lineNo
    16,                                // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo jp_emlrtRTEI{
    112,                               // lineNo
    1,                                 // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo kp_emlrtRTEI{
    100,                               // lineNo
    12,                                // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo lp_emlrtRTEI{
    12,                                // lineNo
    1,                                 // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo mp_emlrtRTEI{
    16,                                // lineNo
    1,                                 // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo np_emlrtRTEI{
    201,                               // lineNo
    19,                                // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo op_emlrtRTEI{
    202,                               // lineNo
    22,                                // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

// Function Definitions
namespace Codegen {
void computeInitialParameterEstimate(
    const emlrtStack *sp, const ::coder::array<real_T, 2U> &worldPoints,
    const ::coder::array<real_T, 3U> &imagePoints, const real_T imageSize[2],
    struct1_T *initialParams, ::coder::array<boolean_T, 1U> &validIdx,
    int32_T *err)
{
  coder::b_cameraParameters lobj_0;
  coder::cameraParameters lobj_1;
  coder::projective2d c_H;
  ::coder::array<real_T, 3U> H;
  ::coder::array<real_T, 3U> b_H;
  ::coder::array<real_T, 2U> V;
  ::coder::array<real_T, 2U> a__1;
  ::coder::array<real_T, 2U> a__2;
  ::coder::array<real_T, 2U> b_imagePoints;
  ::coder::array<real_T, 2U> b_rotationVectors;
  ::coder::array<real_T, 2U> b_translationVectors;
  ::coder::array<real_T, 2U> b_worldPoints;
  ::coder::array<real_T, 2U> rotationVectors;
  ::coder::array<real_T, 2U> translationVectors;
  ::coder::array<int32_T, 1U> r;
  ::coder::array<int32_T, 1U> r1;
  ::coder::array<boolean_T, 1U> validPointsIdx;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T U[36];
  real_T A[9];
  real_T b_r1[9];
  real_T d_H[9];
  real_T r1_tmp[9];
  real_T e_H[6];
  real_T f_H[6];
  real_T c_r1[3];
  real_T r2[3];
  real_T fy;
  int32_T b_i;
  int32_T c_i;
  int32_T end;
  int32_T i;
  int32_T loop_ub;
  char_T t9_WorldUnits[2];
  char_T t10_WorldUnits;
  boolean_T t9_EstimateSkew;
  boolean_T t9_EstimateTangentialDistortion;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1, 0);
  //  Solve for the camera intriniscs and extrinsics in closed form ignoring
  //  distortion.
  st.site = &ms_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 1, 3);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1, 10);
  // --------------------------------------------------------------------------
  //  Compute homographies for all images
  *err = 0;
  // w1 = warning('Error', 'MATLAB:nearlySingularMatrix'); %#ok
  // w2 = warning('Error', 'images:maketform:conditionNumberofAIsHigh'); %#ok
  validIdx.set_size(&cp_emlrtRTEI, &st, imagePoints.size(2));
  loop_ub = imagePoints.size(2);
  for (i = 0; i < loop_ub; i++) {
    validIdx[i] = true;
  }
  H.set_size(&dp_emlrtRTEI, &st, 3, 3, imagePoints.size(2));
  loop_ub = 9 * imagePoints.size(2);
  for (i = 0; i < loop_ub; i++) {
    H[i] = 0.0;
  }
  i = imagePoints.size(2);
  for (b_i = 0; b_i < i; b_i++) {
    int32_T i1;
    covrtLogFor(&emlrtCoverageInstance, 1, 0, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 11);
    //  try
    b_st.site = &us_emlrtRSI;
    if (b_i + 1 > imagePoints.size(2)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, imagePoints.size(2),
                                    &ms_emlrtBCI, &b_st);
    }
    covrtLogFcn(&emlrtCoverageInstance, 1, 2);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 9);
    // --------------------------------------------------------------------------
    //  Compute projective transformation from worldPoints to imagePoints
    if (1 > imagePoints.size(1)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, imagePoints.size(1), &rs_emlrtBCI,
                                    &b_st);
    }
    loop_ub = imagePoints.size(0) - 1;
    validPointsIdx.set_size(&ce_emlrtRTEI, &b_st, imagePoints.size(0));
    for (c_i = 0; c_i <= loop_ub; c_i++) {
      validPointsIdx[c_i] = muDoubleScalarIsNaN(
          imagePoints[c_i + imagePoints.size(0) * imagePoints.size(1) * b_i]);
    }
    loop_ub = validPointsIdx.size(0);
    for (c_i = 0; c_i < loop_ub; c_i++) {
      validPointsIdx[c_i] = !validPointsIdx[c_i];
    }
    end = validPointsIdx.size(0) - 1;
    loop_ub = 0;
    for (c_i = 0; c_i <= end; c_i++) {
      if (validPointsIdx[c_i]) {
        loop_ub++;
      }
    }
    r1.set_size(&ep_emlrtRTEI, &b_st, loop_ub);
    loop_ub = 0;
    for (c_i = 0; c_i <= end; c_i++) {
      if (validPointsIdx[c_i]) {
        r1[loop_ub] = c_i + 1;
        loop_ub++;
      }
    }
    loop_ub = imagePoints.size(1) - 1;
    end = r1.size(0);
    b_worldPoints.set_size(&fp_emlrtRTEI, &b_st, r1.size(0), 2);
    for (c_i = 0; c_i < 2; c_i++) {
      for (i1 = 0; i1 < end; i1++) {
        if (r1[i1] > worldPoints.size(0)) {
          emlrtDynamicBoundsCheckR2012b(r1[i1], 1, worldPoints.size(0),
                                        &us_emlrtBCI, &b_st);
        }
        b_worldPoints[i1 + b_worldPoints.size(0) * c_i] =
            worldPoints[(r1[i1] + worldPoints.size(0) * c_i) - 1];
      }
    }
    b_imagePoints.set_size(&gp_emlrtRTEI, &b_st, r1.size(0),
                           imagePoints.size(1));
    for (c_i = 0; c_i <= loop_ub; c_i++) {
      end = r1.size(0);
      for (i1 = 0; i1 < end; i1++) {
        if (r1[i1] > imagePoints.size(0)) {
          emlrtDynamicBoundsCheckR2012b(r1[i1], 1, imagePoints.size(0),
                                        &vs_emlrtBCI, &b_st);
        }
        b_imagePoints[i1 + b_imagePoints.size(0) * c_i] =
            imagePoints[((r1[i1] + imagePoints.size(0) * c_i) +
                         imagePoints.size(0) * imagePoints.size(1) * b_i) -
                        1];
      }
    }
    c_st.site = &vs_emlrtRSI;
    coder::fitgeotrans(&c_st, b_worldPoints, b_imagePoints, &c_H);
    if (b_i + 1 > H.size(2)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, H.size(2), &qs_emlrtBCI, &b_st);
    }
    for (c_i = 0; c_i < 3; c_i++) {
      H[3 * c_i + 9 * b_i] = c_H.T[c_i];
      H[(3 * c_i + 9 * b_i) + 1] = c_H.T[c_i + 3];
      H[(3 * c_i + 9 * b_i) + 2] = c_H.T[c_i + 6];
    }
    if (b_i + 1 > H.size(2)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, H.size(2), &qs_emlrtBCI, &b_st);
    }
    fy = H[9 * b_i + 8];
    if (b_i + 1 > H.size(2)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, H.size(2), &qs_emlrtBCI, &b_st);
    }
    for (c_i = 0; c_i < 3; c_i++) {
      H[3 * c_i + 9 * b_i] = H[3 * c_i + 9 * b_i] / fy;
      H[(3 * c_i + 9 * b_i) + 1] = H[(3 * c_i + 9 * b_i) + 1] / fy;
      H[(3 * c_i + 9 * b_i) + 2] = H[(3 * c_i + 9 * b_i) + 2] / fy;
    }
    //  catch
    //      validIdx(i) = false;
    //  end
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 1, 0, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1, 12);
  // warning(w1);
  // warning(w2);
  end = imagePoints.size(2) - 1;
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    loop_ub++;
  }
  r.set_size(&hp_emlrtRTEI, &st, loop_ub);
  for (b_i = 0; b_i <= end; b_i++) {
    r[b_i] = b_i + 1;
  }
  b_H.set_size(&ip_emlrtRTEI, &st, 3, 3, r.size(0));
  loop_ub = r.size(0);
  for (i = 0; i < loop_ub; i++) {
    for (c_i = 0; c_i < 3; c_i++) {
      if (r[i] > H.size(2)) {
        emlrtDynamicBoundsCheckR2012b(r[i], 1, H.size(2), &xs_emlrtBCI, &st);
      }
      b_H[3 * c_i + 9 * i] = H[3 * c_i + 9 * (r[i] - 1)];
      if (r[i] > H.size(2)) {
        emlrtDynamicBoundsCheckR2012b(r[i], 1, H.size(2), &xs_emlrtBCI, &st);
      }
      b_H[(3 * c_i + 9 * i) + 1] = H[(3 * c_i + 9 * (r[i] - 1)) + 1];
      if (r[i] > H.size(2)) {
        emlrtDynamicBoundsCheckR2012b(r[i], 1, H.size(2), &xs_emlrtBCI, &st);
      }
      b_H[(3 * c_i + 9 * i) + 2] = H[(3 * c_i + 9 * (r[i] - 1)) + 2];
    }
  }
  H.set_size(&jp_emlrtRTEI, &st, 3, 3, b_H.size(2));
  loop_ub = 9 * b_H.size(2);
  for (i = 0; i < loop_ub; i++) {
    H[i] = b_H[i];
  }
  validPointsIdx.set_size(&kp_emlrtRTEI, &st, imagePoints.size(2));
  loop_ub = imagePoints.size(2);
  for (i = 0; i < loop_ub; i++) {
    validPointsIdx[i] = true;
  }
  b_st.site = &ts_emlrtRSI;
  if (covrtLogIf(
          &emlrtCoverageInstance, 1, 0, 3,
          covrtLogMcdc(&emlrtCoverageInstance, 1, 0, 2,
                       !covrtLogCond(&emlrtCoverageInstance, 1, 0, 2,
                                     coder::all(&b_st, validPointsIdx))))) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 13);
    // warning(message('vision:calibrate:invalidHomographies', ...
    //     numImages - size(homographies, 3), numImages));
    // err = "invalid Homographies";
    *err = -201;
  } else if (covrtLogIf(&emlrtCoverageInstance, 1, 0, 4, H.size(2) < 2)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 14);
    // error(message('vision:calibrate:notEnoughValidHomographies'));
    *err = -201;
  }
  if (covrtLogIf(&emlrtCoverageInstance, 1, 0, 0, *err == 0)) {
    real_T cy;
    real_T fx;
    real_T lambda;
    real_T scale;
    real_T skew;
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 1);
    st.site = &ns_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 1, 4);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 15);
    // --------------------------------------------------------------------------
    //  Vb = 0
    fy = 2.0 * static_cast<real_T>(H.size(2));
    if (fy != static_cast<int32_T>(fy)) {
      emlrtIntegerCheckR2012b(fy, &jd_emlrtDCI, &st);
    }
    V.set_size(&lp_emlrtRTEI, &st, static_cast<int32_T>(fy), 6);
    fy = 2.0 * static_cast<real_T>(H.size(2));
    if (fy != static_cast<int32_T>(fy)) {
      emlrtIntegerCheckR2012b(fy, &kd_emlrtDCI, &st);
    }
    loop_ub = static_cast<int32_T>(fy) * 6;
    for (i = 0; i < loop_ub; i++) {
      V[i] = 0.0;
    }
    i = H.size(2);
    for (b_i = 0; b_i < i; b_i++) {
      uint32_T u;
      covrtLogFor(&emlrtCoverageInstance, 1, 0, 2, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 1, 16);
      if (b_i + 1 > H.size(2)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, H.size(2), &ns_emlrtBCI, &st);
      }
      for (c_i = 0; c_i < 3; c_i++) {
        d_H[3 * c_i] = H[c_i + 9 * b_i];
        d_H[3 * c_i + 1] = H[(c_i + 9 * b_i) + 3];
        d_H[3 * c_i + 2] = H[(c_i + 9 * b_i) + 6];
      }
      b_st.site = &jv_emlrtRSI;
      covrtLogFcn(&emlrtCoverageInstance, 1, 5);
      covrtLogBasicBlock(&emlrtCoverageInstance, 1, 17);
      // --------------------------------------------------------------------------
      u = static_cast<uint32_T>(b_i + 1) << 1;
      if ((static_cast<int32_T>(u - 1U) < 1) ||
          (static_cast<int32_T>(u - 1U) > V.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(u - 1U), 1,
                                      V.size(0), &ss_emlrtBCI, &b_st);
      }
      V[static_cast<int32_T>(u) - 2] = d_H[0] * d_H[1];
      V[(static_cast<int32_T>(u) + V.size(0)) - 2] =
          d_H[0] * d_H[4] + d_H[1] * d_H[3];
      V[(static_cast<int32_T>(u) + V.size(0) * 2) - 2] = d_H[3] * d_H[4];
      V[(static_cast<int32_T>(u) + V.size(0) * 3) - 2] =
          d_H[1] * d_H[6] + d_H[0] * d_H[7];
      V[(static_cast<int32_T>(u) + V.size(0) * 4) - 2] =
          d_H[4] * d_H[6] + d_H[3] * d_H[7];
      V[(static_cast<int32_T>(u) + V.size(0) * 5) - 2] = d_H[6] * d_H[7];
      b_st.site = &kv_emlrtRSI;
      covrtLogFcn(&emlrtCoverageInstance, 1, 5);
      covrtLogBasicBlock(&emlrtCoverageInstance, 1, 17);
      // --------------------------------------------------------------------------
      b_st.site = &kv_emlrtRSI;
      covrtLogFcn(&emlrtCoverageInstance, 1, 5);
      covrtLogBasicBlock(&emlrtCoverageInstance, 1, 17);
      // --------------------------------------------------------------------------
      e_H[0] = d_H[0] * d_H[0];
      fy = d_H[0] * d_H[3];
      e_H[1] = fy + fy;
      e_H[2] = d_H[3] * d_H[3];
      fy = d_H[0] * d_H[6];
      e_H[3] = fy + fy;
      fy = d_H[3] * d_H[6];
      e_H[4] = fy + fy;
      e_H[5] = d_H[6] * d_H[6];
      f_H[0] = d_H[1] * d_H[1];
      fy = d_H[1] * d_H[4];
      f_H[1] = fy + fy;
      f_H[2] = d_H[4] * d_H[4];
      fy = d_H[1] * d_H[7];
      f_H[3] = fy + fy;
      fy = d_H[4] * d_H[7];
      f_H[4] = fy + fy;
      f_H[5] = d_H[7] * d_H[7];
      if ((static_cast<int32_T>(u) < 1) ||
          (static_cast<int32_T>(u) > V.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(u), 1, V.size(0),
                                      &os_emlrtBCI, &st);
      }
      for (c_i = 0; c_i < 6; c_i++) {
        V[(static_cast<int32_T>(u) + V.size(0) * c_i) - 1] =
            e_H[c_i] - f_H[c_i];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    covrtLogFor(&emlrtCoverageInstance, 1, 0, 2, 0);
    st.site = &os_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 1, 6);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 18);
    // --------------------------------------------------------------------------
    //  lambda * B = inv(A)' * inv(A), where A is the intrinsic matrix
    b_st.site = &lv_emlrtRSI;
    coder::svd(&b_st, V, a__1, a__2, U);
    //  b = [B11, B12, B22, B13, B23, B33]
    st.site = &ps_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 1, 7);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 19);
    // --------------------------------------------------------------------------
    //  Compute the intrinsic matrix
    b_st.site = &nv_emlrtRSI;
    fy = U[31] * U[33] - U[30] * U[34];
    scale = U[30] * U[32] - U[31] * U[31];
    cy = fy / scale;
    b_st.site = &ov_emlrtRSI;
    lambda = U[35] - (U[33] * U[33] + cy * fy) / U[30];
    b_st.site = &pv_emlrtRSI;
    fx = lambda / U[30];
    if (fx < 0.0) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &u_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
    }
    fx = muDoubleScalarSqrt(fx);
    b_st.site = &qv_emlrtRSI;
    b_st.site = &qv_emlrtRSI;
    fy = lambda * U[30] / scale;
    if (fy < 0.0) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &u_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
    }
    fy = muDoubleScalarSqrt(fy);
    b_st.site = &rv_emlrtRSI;
    scale = fx * fx;
    skew = -U[31] * scale * fy / lambda;
    b_st.site = &sv_emlrtRSI;
    A[0] = fx;
    A[3] = skew;
    A[6] = skew * cy / fx - U[33] * scale / lambda;
    A[1] = 0.0;
    A[4] = fy;
    A[7] = cy;
    A[2] = 0.0;
    A[5] = 0.0;
    A[8] = 1.0;
    covrtLogCond(&emlrtCoverageInstance, 1, 0, 3, true);
    covrtLogMcdc(&emlrtCoverageInstance, 1, 0, 3, false);
    covrtLogIf(&emlrtCoverageInstance, 1, 0, 5, false);
    st.site = &qs_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 1, 8);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 21);
    // --------------------------------------------------------------------------
    //  Compute translation and rotation vectors for all images
    rotationVectors.set_size(&mp_emlrtRTEI, &st, 3, H.size(2));
    translationVectors.set_size(&mp_emlrtRTEI, &st, 3, H.size(2));
    b_st.site = &tv_emlrtRSI;
    coder::inv(&b_st, A, d_H);
    i = H.size(2);
    for (b_i = 0; b_i < i; b_i++) {
      covrtLogFor(&emlrtCoverageInstance, 1, 0, 3, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 1, 22);
      if (b_i + 1 > H.size(2)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, H.size(2), &ps_emlrtBCI, &st);
      }
      fy = 0.0;
      scale = 3.3121686421112381E-170;
      for (loop_ub = 0; loop_ub < 3; loop_ub++) {
        skew = muDoubleScalarAbs(
            (d_H[loop_ub] * H[9 * b_i] + d_H[loop_ub + 3] * H[9 * b_i + 1]) +
            d_H[loop_ub + 6] * H[9 * b_i + 2]);
        if (skew > scale) {
          lambda = scale / skew;
          fy = fy * lambda * lambda + 1.0;
          scale = skew;
        } else {
          lambda = skew / scale;
          fy += lambda * lambda;
        }
      }
      fy = scale * muDoubleScalarSqrt(fy);
      fy = 1.0 / fy;
      //  3D rotation matrix
      for (c_i = 0; c_i < 9; c_i++) {
        r1_tmp[c_i] = fy * d_H[c_i];
      }
      for (c_i = 0; c_i < 3; c_i++) {
        fy = r1_tmp[c_i];
        scale = fy * H[9 * b_i];
        skew = fy * H[9 * b_i + 3];
        fy = r1_tmp[c_i + 3];
        scale += fy * H[9 * b_i + 1];
        skew += fy * H[9 * b_i + 4];
        fy = r1_tmp[c_i + 6];
        scale += fy * H[9 * b_i + 2];
        skew += fy * H[9 * b_i + 5];
        r2[c_i] = skew;
        c_r1[c_i] = scale;
        b_r1[c_i] = scale;
        b_r1[c_i + 3] = skew;
      }
      b_r1[6] = c_r1[1] * r2[2] - r2[1] * c_r1[2];
      b_r1[7] = r2[0] * c_r1[2] - c_r1[0] * r2[2];
      b_r1[8] = c_r1[0] * r2[1] - r2[0] * c_r1[1];
      if (b_i + 1 > rotationVectors.size(1)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, rotationVectors.size(1),
                                      &ws_emlrtBCI, &st);
      }
      b_st.site = &uv_emlrtRSI;
      coder::vision::internal::calibration::rodriguesMatrixToVector(&b_st, b_r1,
                                                                    c_r1);
      (*(real_T(*)[3]) & rotationVectors[3 * b_i])[0] = c_r1[0];
      (*(real_T(*)[3]) & rotationVectors[3 * b_i])[1] = c_r1[1];
      (*(real_T(*)[3]) & rotationVectors[3 * b_i])[2] = c_r1[2];
      //  translation vector
      if (b_i + 1 > translationVectors.size(1)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, translationVectors.size(1),
                                      &ts_emlrtBCI, &st);
      }
      for (c_i = 0; c_i < 3; c_i++) {
        translationVectors[c_i + 3 * b_i] =
            (r1_tmp[c_i] * H[9 * b_i + 6] + r1_tmp[c_i + 3] * H[9 * b_i + 7]) +
            r1_tmp[c_i + 6] * H[9 * b_i + 8];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    covrtLogFor(&emlrtCoverageInstance, 1, 0, 3, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 23);
    // iniltialParams =
    // my_CameraParameters(radialCoeffs,worldPoints,worldUnits,cameraModel,rvecs,tvecs,A',size(imagePoints,
    // 3));
    b_rotationVectors.set_size(&np_emlrtRTEI, sp, rotationVectors.size(1), 3);
    b_translationVectors.set_size(&op_emlrtRTEI, sp, translationVectors.size(1),
                                  3);
    loop_ub = rotationVectors.size(1);
    end = translationVectors.size(1);
    for (i = 0; i < 3; i++) {
      d_H[3 * i] = A[i];
      d_H[3 * i + 1] = A[i + 3];
      d_H[3 * i + 2] = A[i + 6];
      for (c_i = 0; c_i < loop_ub; c_i++) {
        b_rotationVectors[c_i + b_rotationVectors.size(0) * i] =
            rotationVectors[i + 3 * c_i];
      }
      for (c_i = 0; c_i < end; c_i++) {
        b_translationVectors[c_i + b_translationVectors.size(0) * i] =
            translationVectors[i + 3 * c_i];
      }
    }
    st.site = &rs_emlrtRSI;
    lobj_0
        .init(&st, d_H, b_rotationVectors, b_translationVectors, worldPoints,
              imageSize)
        ->toStruct(
            &st, initialParams->RadialDistortion,
            initialParams->TangentialDistortion, initialParams->ImageSize,
            initialParams->WorldPoints, &t10_WorldUnits, &t9_EstimateSkew, &fy,
            &t9_EstimateTangentialDistortion, initialParams->RotationVectors,
            initialParams->TranslationVectors, initialParams->IntrinsicMatrix);
    initialParams->WorldUnits.size[0] = 1;
    initialParams->WorldUnits.size[1] = 1;
    initialParams->WorldUnits.data[0] = t10_WorldUnits;
    initialParams->EstimateSkew = t9_EstimateSkew;
    initialParams->NumRadialDistortionCoefficients = fy;
    initialParams->EstimateTangentialDistortion =
        t9_EstimateTangentialDistortion;
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 2);
    // iniltialParams = my_CameraParameters(zeros(1,3),worldPoints,'',
    // cameraModel,zeros(1,3),zeros(1,3),zeros(3,3),[]);
    st.site = &ss_emlrtRSI;
    lobj_1.init(&st, imageSize)
        ->toStruct(initialParams->RadialDistortion,
                   initialParams->TangentialDistortion,
                   initialParams->ImageSize, t9_WorldUnits, &t9_EstimateSkew,
                   &fy, &t9_EstimateTangentialDistortion,
                   initialParams->IntrinsicMatrix);
    initialParams->WorldPoints.set_size(&bd_emlrtRTEI, sp, 0, 2);
    initialParams->WorldUnits.size[0] = 1;
    initialParams->WorldUnits.size[1] = 2;
    initialParams->WorldUnits.data[0] = t9_WorldUnits[0];
    initialParams->WorldUnits.data[1] = t9_WorldUnits[1];
    initialParams->EstimateSkew = t9_EstimateSkew;
    initialParams->NumRadialDistortionCoefficients = fy;
    initialParams->EstimateTangentialDistortion =
        t9_EstimateTangentialDistortion;
    initialParams->RotationVectors.set_size(&bd_emlrtRTEI, sp, 0, 3);
    initialParams->TranslationVectors.set_size(&bd_emlrtRTEI, sp, 0, 3);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace Codegen

// End of code generation (computeInitialParameterEstimate.cpp)
