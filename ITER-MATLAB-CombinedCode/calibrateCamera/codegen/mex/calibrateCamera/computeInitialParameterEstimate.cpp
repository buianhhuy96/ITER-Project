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
#include "calibrateCamera_data.h"
#include "calibrateCamera_types.h"
#include "fitgeotrans.h"
#include "inv.h"
#include "projective2d.h"
#include "rodriguesMatrixToVector.h"
#include "rodriguesVectorToMatrix.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo vs_emlrtRSI{
    6,                                 // lineNo
    "computeInitialParameterEstimate", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo ws_emlrtRSI{
    9,                                 // lineNo
    "computeInitialParameterEstimate", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo xs_emlrtRSI{
    10,                                // lineNo
    "computeInitialParameterEstimate", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo ys_emlrtRSI{
    11,                                // lineNo
    "computeInitialParameterEstimate", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo at_emlrtRSI{
    13,                                // lineNo
    "computeInitialParameterEstimate", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo bt_emlrtRSI{
    16,                                // lineNo
    "computeInitialParameterEstimate", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo ct_emlrtRSI{
    19,                                // lineNo
    "computeInitialParameterEstimate", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo dt_emlrtRSI{
    101,                   // lineNo
    "computeHomographies", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo et_emlrtRSI{
    93,                    // lineNo
    "computeHomographies", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo ft_emlrtRSI{
    75,                  // lineNo
    "computeHomography", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo gt_emlrtRSI{
    11,            // lineNo
    "fitgeotrans", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo ht_emlrtRSI{
    31,            // lineNo
    "fitgeotrans", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo it_emlrtRSI{
    15,                      // lineNo
    "validateControlPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\validateControlPoints.m" // pathName
};

static emlrtRSInfo jt_emlrtRSI{
    16,                      // lineNo
    "validateControlPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\validateControlPoints.m" // pathName
};

static emlrtRSInfo pv_emlrtRSI{
    121,        // lineNo
    "computeV", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo rv_emlrtRSI{
    134,        // lineNo
    "computeB", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo vv_emlrtRSI{
    146,                 // lineNo
    "computeIntrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo wv_emlrtRSI{
    147,                 // lineNo
    "computeIntrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo aw_emlrtRSI{
    166,                 // lineNo
    "computeExtrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo bw_emlrtRSI{
    180,                 // lineNo
    "computeExtrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pathName
};

static emlrtBCInfo qs_emlrtBCI{
    -1,             // iFirst
    -1,             // iLast
    120,            // lineNo
    28,             // colNo
    "homographies", // aName
    "computeV",     // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    0                                        // checkKind
};

static emlrtBCInfo rs_emlrtBCI{
    -1,         // iFirst
    -1,         // iLast
    122,        // lineNo
    7,          // colNo
    "V",        // aName
    "computeV", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    0                                        // checkKind
};

static emlrtBCInfo ss_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    168,                 // lineNo
    28,                  // colNo
    "homographies",      // aName
    "computeExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    0                                        // checkKind
};

static emlrtBCInfo ts_emlrtBCI{
    -1,                    // iFirst
    -1,                    // iLast
    29,                    // lineNo
    25,                    // colNo
    "RotationVectors",     // aName
    "my_CameraParameters", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    0                                        // checkKind
};

static emlrtBCInfo us_emlrtBCI{
    -1,                    // iFirst
    -1,                    // iLast
    31,                    // lineNo
    28,                    // colNo
    "rotationMatrices",    // aName
    "my_CameraParameters", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    0                                        // checkKind
};

static emlrtBCInfo vs_emlrtBCI{
    -1,         // iFirst
    -1,         // iLast
    121,        // lineNo
    7,          // colNo
    "V",        // aName
    "computeV", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    0                                        // checkKind
};

static emlrtBCInfo ws_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    184,                  // lineNo
    27,                   // colNo
    "translationVectors", // aName
    "computeExtrinsics",  // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    0                                        // checkKind
};

static emlrtDCInfo jd_emlrtDCI{
    118,        // lineNo
    11,         // colNo
    "computeV", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    1                                        // checkKind
};

static emlrtDCInfo kd_emlrtDCI{
    9,                                 // lineNo
    1,                                 // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    1                                        // checkKind
};

static emlrtBCInfo xs_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    180,                 // lineNo
    24,                  // colNo
    "rotationVectors",   // aName
    "computeExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    0                                        // checkKind
};

static emlrtBCInfo ys_emlrtBCI{
    -1,                    // iFirst
    -1,                    // iLast
    93,                    // lineNo
    51,                    // colNo
    "points",              // aName
    "computeHomographies", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    0                                        // checkKind
};

static emlrtBCInfo at_emlrtBCI{
    -1,                    // iFirst
    -1,                    // iLast
    92,                    // lineNo
    28,                    // colNo
    "homographies",        // aName
    "computeHomographies", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    0                                        // checkKind
};

static emlrtBCInfo bt_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    73,                  // lineNo
    39,                  // colNo
    "imagePoints",       // aName
    "computeHomography", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    0                                        // checkKind
};

static emlrtRTEInfo tb_emlrtRTEI{
    19,                      // lineNo
    55,                      // colNo
    "validateControlPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\validateControlPoints.m" // pName
};

static emlrtRTEInfo ub_emlrtRTEI{
    18,              // lineNo
    23,              // colNo
    "validatencols", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatencols.m" // pName
};

static emlrtBCInfo ct_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    75,                  // lineNo
    29,                  // colNo
    "worldPoints",       // aName
    "computeHomography", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    0                                        // checkKind
};

static emlrtBCInfo dt_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    75,                  // lineNo
    60,                  // colNo
    "imagePoints",       // aName
    "computeHomography", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    0                                        // checkKind
};

static emlrtBCInfo et_emlrtBCI{
    -1,                    // iFirst
    -1,                    // iLast
    100,                   // lineNo
    35,                    // colNo
    "homographies",        // aName
    "computeHomographies", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m", // pName
    0                                        // checkKind
};

static emlrtRTEInfo gp_emlrtRTEI{
    19,                                // lineNo
    5,                                 // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo hp_emlrtRTEI{
    9,                                 // lineNo
    1,                                 // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo ip_emlrtRTEI{
    13,                                // lineNo
    1,                                 // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo jp_emlrtRTEI{
    187,                               // lineNo
    1,                                 // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo kp_emlrtRTEI{
    16,                                // lineNo
    18,                                // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo lp_emlrtRTEI{
    16,                                // lineNo
    1,                                 // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo mp_emlrtRTEI{
    88,                                // lineNo
    1,                                 // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo np_emlrtRTEI{
    89,                                // lineNo
    1,                                 // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo op_emlrtRTEI{
    93,                                // lineNo
    13,                                // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo pp_emlrtRTEI{
    75,                                // lineNo
    17,                                // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo qp_emlrtRTEI{
    75,                                // lineNo
    48,                                // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo rp_emlrtRTEI{
    81,                                // lineNo
    42,                                // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo sp_emlrtRTEI{
    100,                               // lineNo
    16,                                // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo tp_emlrtRTEI{
    100,                               // lineNo
    1,                                 // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo up_emlrtRTEI{
    88,                                // lineNo
    12,                                // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\computeInitialParameterEstimate.m" // pName
};

// Function Declarations
namespace Codegen {
static void computeHomographies(const emlrtStack *sp,
                                const ::coder::array<real_T, 3U> &points,
                                const ::coder::array<real_T, 2U> &worldPoints,
                                ::coder::array<real_T, 3U> &homographies,
                                ::coder::array<boolean_T, 1U> &validIdx,
                                int8_T *err);

}

// Function Definitions
namespace Codegen {
static void computeHomographies(const emlrtStack *sp,
                                const ::coder::array<real_T, 3U> &points,
                                const ::coder::array<real_T, 2U> &worldPoints,
                                ::coder::array<real_T, 3U> &homographies,
                                ::coder::array<boolean_T, 1U> &validIdx,
                                int8_T *err)
{
  coder::projective2d H;
  ::coder::array<real_T, 3U> b_homographies;
  ::coder::array<real_T, 2U> b_points;
  ::coder::array<real_T, 2U> c_worldPoints;
  ::coder::array<int32_T, 1U> r;
  ::coder::array<int32_T, 1U> r1;
  ::coder::array<boolean_T, 1U> validPointsIdx;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T b_worldPoints;
  int32_T c_loop_ub;
  int32_T end;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  int32_T loop_ub;
  uint32_T varargin_1[2];
  uint32_T varargin_2[2];
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 3, 3);
  covrtLogBasicBlock(&emlrtCoverageInstance, 3, 10);
  // --------------------------------------------------------------------------
  //  Compute homographies for all images
  *err = 0;
  // w1 = warning('Error', 'MATLAB:nearlySingularMatrix'); %#ok
  // w2 = warning('Error', 'images:maketform:conditionNumberofAIsHigh'); %#ok
  validIdx.set_size(&mp_emlrtRTEI, sp, points.size(2));
  loop_ub = points.size(2);
  for (i = 0; i < loop_ub; i++) {
    validIdx[i] = true;
  }
  homographies.set_size(&np_emlrtRTEI, sp, 3, 3, points.size(2));
  loop_ub = 9 * points.size(2);
  for (i = 0; i < loop_ub; i++) {
    homographies[i] = 0.0;
  }
  i = points.size(2);
  if (0 <= points.size(2) - 1) {
    i1 = points.size(1);
    i2 = points.size(0) - 1;
    b_loop_ub = points.size(0) - 1;
    b_worldPoints = worldPoints.size(0);
    i3 = points.size(0);
    i4 = points.size(1);
    i5 = points.size(1);
    varargin_1[1] = 2U;
    varargin_2[1] = static_cast<uint32_T>(points.size(1));
    i6 = points.size(1) - 1;
    c_loop_ub = points.size(1) - 1;
  }
  for (b_i = 0; b_i < i; b_i++) {
    real_T x;
    int32_T c_i;
    boolean_T exitg1;
    boolean_T p;
    covrtLogFor(&emlrtCoverageInstance, 3, 0, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 11);
    //  try
    st.site = &et_emlrtRSI;
    if (b_i + 1 > points.size(2)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, points.size(2), &ys_emlrtBCI,
                                    &st);
    }
    covrtLogFcn(&emlrtCoverageInstance, 3, 2);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 9);
    // --------------------------------------------------------------------------
    //  Compute projective transformation from worldPoints to imagePoints
    if (1 > i1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i1, &bt_emlrtBCI, &st);
    }
    validPointsIdx.set_size(&rc_emlrtRTEI, &st, i2 + 1);
    for (c_i = 0; c_i <= b_loop_ub; c_i++) {
      validPointsIdx[c_i] = muDoubleScalarIsNaN(
          points[c_i + points.size(0) * points.size(1) * b_i]);
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
    r1.set_size(&op_emlrtRTEI, &st, loop_ub);
    loop_ub = 0;
    for (c_i = 0; c_i <= end; c_i++) {
      if (validPointsIdx[c_i]) {
        r1[loop_ub] = c_i + 1;
        loop_ub++;
      }
    }
    b_st.site = &ft_emlrtRSI;
    loop_ub = r1.size(0);
    for (c_i = 0; c_i < loop_ub; c_i++) {
      if (r1[c_i] > b_worldPoints) {
        emlrtDynamicBoundsCheckR2012b(r1[c_i], 1, b_worldPoints, &ct_emlrtBCI,
                                      &b_st);
      }
    }
    loop_ub = r1.size(0);
    for (c_i = 0; c_i < loop_ub; c_i++) {
      if (r1[c_i] > i3) {
        emlrtDynamicBoundsCheckR2012b(r1[c_i], 1, i3, &dt_emlrtBCI, &b_st);
      }
    }
    c_st.site = &gt_emlrtRSI;
    d_st.site = &it_emlrtRSI;
    e_st.site = &v_emlrtRSI;
    p = true;
    c_i = r1.size(0) << 1;
    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub <= c_i - 1)) {
      x = worldPoints[(r1[loop_ub % r1.size(0)] +
                       worldPoints.size(0) * (loop_ub / r1.size(0))) -
                      1];
      if ((!muDoubleScalarIsInf(x)) && (!muDoubleScalarIsNaN(x))) {
        loop_ub++;
      } else {
        p = false;
        exitg1 = true;
      }
    }
    if (!p) {
      emlrtErrorWithMessageIdR2018a(
          &e_st, &g_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
          "MATLAB:validateControlPoints:expectedFinite", 3, 4, 12,
          "movingPoints");
    }
    d_st.site = &jt_emlrtRSI;
    e_st.site = &v_emlrtRSI;
    p = true;
    c_i = r1.size(0) * i4;
    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub <= c_i - 1)) {
      x = points[((r1[loop_ub % r1.size(0)] +
                   points.size(0) * (loop_ub / r1.size(0))) +
                  points.size(0) * points.size(1) * b_i) -
                 1];
      if ((!muDoubleScalarIsInf(x)) && (!muDoubleScalarIsNaN(x))) {
        loop_ub++;
      } else {
        p = false;
        exitg1 = true;
      }
    }
    if (!p) {
      emlrtErrorWithMessageIdR2018a(
          &e_st, &g_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
          "MATLAB:validateControlPoints:expectedFinite", 3, 4, 11,
          "fixedPoints");
    }
    e_st.site = &v_emlrtRSI;
    if (i5 != 2) {
      emlrtErrorWithMessageIdR2018a(
          &e_st, &ub_emlrtRTEI,
          "Coder:toolbox:ValidateattributesincorrectNumcols",
          "MATLAB:validateControlPoints:incorrectNumcols", 5, 4, 11,
          "fixedPoints", 6, 2.0);
    }
    varargin_1[0] = static_cast<uint32_T>(r1.size(0));
    varargin_2[0] = static_cast<uint32_T>(r1.size(0));
    p = true;
    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub < 2)) {
      if (static_cast<int32_T>(varargin_1[loop_ub]) !=
          static_cast<int32_T>(varargin_2[loop_ub])) {
        p = false;
        exitg1 = true;
      } else {
        loop_ub++;
      }
    }
    if (!p) {
      emlrtErrorWithMessageIdR2018a(
          &c_st, &tb_emlrtRTEI,
          "images:geotrans:differentNumbersOfControlPoints",
          "images:geotrans:differentNumbersOfControlPoints", 6, 4, 11,
          "fixedPoints", 4, 12, "movingPoints");
    }
    loop_ub = r1.size(0);
    c_worldPoints.set_size(&pp_emlrtRTEI, &b_st, r1.size(0), 2);
    for (c_i = 0; c_i < 2; c_i++) {
      for (end = 0; end < loop_ub; end++) {
        c_worldPoints[end + c_worldPoints.size(0) * c_i] =
            worldPoints[(r1[end] + worldPoints.size(0) * c_i) - 1];
      }
    }
    b_points.set_size(&qp_emlrtRTEI, &b_st, r1.size(0), i6 + 1);
    for (c_i = 0; c_i <= c_loop_ub; c_i++) {
      loop_ub = r1.size(0);
      for (end = 0; end < loop_ub; end++) {
        b_points[end + b_points.size(0) * c_i] =
            points[((r1[end] + points.size(0) * c_i) +
                    points.size(0) * points.size(1) * b_i) -
                   1];
      }
    }
    c_st.site = &ht_emlrtRSI;
    coder::findProjectiveTransform(&c_st, c_worldPoints, b_points, &H);
    if (b_i + 1 > homographies.size(2)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, homographies.size(2),
                                    &at_emlrtBCI, &st);
    }
    for (c_i = 0; c_i < 3; c_i++) {
      homographies[3 * c_i + 9 * b_i] = H.T[c_i];
      homographies[(3 * c_i + 9 * b_i) + 1] = H.T[c_i + 3];
      homographies[(3 * c_i + 9 * b_i) + 2] = H.T[c_i + 6];
    }
    if (b_i + 1 > homographies.size(2)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, homographies.size(2),
                                    &at_emlrtBCI, &st);
    }
    x = homographies[9 * b_i + 8];
    if (b_i + 1 > homographies.size(2)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, homographies.size(2),
                                    &at_emlrtBCI, &st);
    }
    for (c_i = 0; c_i < 3; c_i++) {
      homographies[3 * c_i + 9 * b_i] = homographies[3 * c_i + 9 * b_i] / x;
      homographies[(3 * c_i + 9 * b_i) + 1] =
          homographies[(3 * c_i + 9 * b_i) + 1] / x;
      homographies[(3 * c_i + 9 * b_i) + 2] =
          homographies[(3 * c_i + 9 * b_i) + 2] / x;
    }
    //  catch
    //      validIdx(i) = false;
    //  end
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 3, 0, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 3, 12);
  // warning(w1);
  // warning(w2);
  end = points.size(2) - 1;
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    loop_ub++;
  }
  r.set_size(&rp_emlrtRTEI, sp, loop_ub);
  for (b_i = 0; b_i <= end; b_i++) {
    r[b_i] = b_i + 1;
  }
  b_homographies.set_size(&sp_emlrtRTEI, sp, 3, 3, r.size(0));
  loop_ub = r.size(0);
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < 3; i1++) {
      if (r[i] > homographies.size(2)) {
        emlrtDynamicBoundsCheckR2012b(r[i], 1, homographies.size(2),
                                      &et_emlrtBCI, (emlrtCTX)sp);
      }
      b_homographies[3 * i1 + 9 * i] = homographies[3 * i1 + 9 * (r[i] - 1)];
      if (r[i] > homographies.size(2)) {
        emlrtDynamicBoundsCheckR2012b(r[i], 1, homographies.size(2),
                                      &et_emlrtBCI, (emlrtCTX)sp);
      }
      b_homographies[(3 * i1 + 9 * i) + 1] =
          homographies[(3 * i1 + 9 * (r[i] - 1)) + 1];
      if (r[i] > homographies.size(2)) {
        emlrtDynamicBoundsCheckR2012b(r[i], 1, homographies.size(2),
                                      &et_emlrtBCI, (emlrtCTX)sp);
      }
      b_homographies[(3 * i1 + 9 * i) + 2] =
          homographies[(3 * i1 + 9 * (r[i] - 1)) + 2];
    }
  }
  homographies.set_size(&tp_emlrtRTEI, sp, 3, 3, b_homographies.size(2));
  loop_ub = 9 * b_homographies.size(2);
  for (i = 0; i < loop_ub; i++) {
    homographies[i] = b_homographies[i];
  }
  validPointsIdx.set_size(&up_emlrtRTEI, sp, points.size(2));
  loop_ub = points.size(2);
  for (i = 0; i < loop_ub; i++) {
    validPointsIdx[i] = true;
  }
  st.site = &dt_emlrtRSI;
  if (covrtLogIf(
          &emlrtCoverageInstance, 3, 0, 3,
          covrtLogMcdc(&emlrtCoverageInstance, 3, 0, 2,
                       !covrtLogCond(&emlrtCoverageInstance, 3, 0, 2,
                                     coder::all(&st, validPointsIdx))))) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 13);
    // warning(message('vision:calibrate:invalidHomographies', ...
    //     numImages - size(homographies, 3), numImages));
    // err = "invalid Homographies";
    *err = -1;
  }
  if (covrtLogIf(&emlrtCoverageInstance, 3, 0, 4, homographies.size(2) < 2)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 14);
    // error(message('vision:calibrate:notEnoughValidHomographies'));
    *err = -1;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void computeInitialParameterEstimate(
    const emlrtStack *sp, const ::coder::array<real_T, 2U> &worldPoints,
    const ::coder::array<real_T, 3U> &imagePoints, struct1_T *iniltialParams,
    ::coder::array<boolean_T, 1U> &validIdx, int8_T *err)
{
  ::coder::array<real_T, 3U> H;
  ::coder::array<real_T, 3U> rotationMatrices;
  ::coder::array<real_T, 2U> V;
  ::coder::array<real_T, 2U> a__1;
  ::coder::array<real_T, 2U> a__2;
  ::coder::array<real_T, 2U> rotationVectors;
  ::coder::array<real_T, 2U> translationVectors;
  emlrtStack b_st;
  emlrtStack st;
  real_T U[36];
  real_T A[9];
  real_T b_H[9];
  real_T r1[9];
  real_T c_H[6];
  real_T d_H[6];
  real_T b_r1[3];
  real_T r2[3];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 3, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 3, 0);
  //  Solve for the camera intriniscs and extrinsics in closed form ignoring
  //  distortion.
  st.site = &vs_emlrtRSI;
  computeHomographies(&st, imagePoints, worldPoints, H, validIdx, err);
  if (covrtLogIf(&emlrtCoverageInstance, 3, 0, 0, *err == 0)) {
    real_T cy;
    real_T fx;
    real_T fy;
    real_T lambda;
    real_T scale;
    real_T skew;
    int32_T b_i;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 1);
    st.site = &ws_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 3, 4);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 15);
    // --------------------------------------------------------------------------
    //  Vb = 0
    fy = 2.0 * static_cast<real_T>(H.size(2));
    if (fy != static_cast<int32_T>(fy)) {
      emlrtIntegerCheckR2012b(fy, &jd_emlrtDCI, &st);
    }
    V.set_size(&hp_emlrtRTEI, &st, static_cast<int32_T>(fy), 6);
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
      covrtLogFor(&emlrtCoverageInstance, 3, 0, 2, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 3, 16);
      if (b_i + 1 > H.size(2)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, H.size(2), &qs_emlrtBCI, &st);
      }
      for (i1 = 0; i1 < 3; i1++) {
        b_H[3 * i1] = H[i1 + 9 * b_i];
        b_H[3 * i1 + 1] = H[(i1 + 9 * b_i) + 3];
        b_H[3 * i1 + 2] = H[(i1 + 9 * b_i) + 6];
      }
      b_st.site = &pv_emlrtRSI;
      covrtLogFcn(&emlrtCoverageInstance, 3, 5);
      covrtLogBasicBlock(&emlrtCoverageInstance, 3, 17);
      // --------------------------------------------------------------------------
      u = static_cast<uint32_T>(b_i + 1) << 1;
      if ((static_cast<int32_T>(u - 1U) < 1) ||
          (static_cast<int32_T>(u - 1U) > V.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(u - 1U), 1,
                                      V.size(0), &vs_emlrtBCI, &b_st);
      }
      V[static_cast<int32_T>(u) - 2] = b_H[0] * b_H[1];
      V[(static_cast<int32_T>(u) + V.size(0)) - 2] =
          b_H[0] * b_H[4] + b_H[1] * b_H[3];
      V[(static_cast<int32_T>(u) + V.size(0) * 2) - 2] = b_H[3] * b_H[4];
      V[(static_cast<int32_T>(u) + V.size(0) * 3) - 2] =
          b_H[1] * b_H[6] + b_H[0] * b_H[7];
      V[(static_cast<int32_T>(u) + V.size(0) * 4) - 2] =
          b_H[4] * b_H[6] + b_H[3] * b_H[7];
      V[(static_cast<int32_T>(u) + V.size(0) * 5) - 2] = b_H[6] * b_H[7];
      covrtLogFcn(&emlrtCoverageInstance, 3, 5);
      covrtLogBasicBlock(&emlrtCoverageInstance, 3, 17);
      // --------------------------------------------------------------------------
      covrtLogFcn(&emlrtCoverageInstance, 3, 5);
      covrtLogBasicBlock(&emlrtCoverageInstance, 3, 17);
      // --------------------------------------------------------------------------
      c_H[0] = b_H[0] * b_H[0];
      fy = b_H[0] * b_H[3];
      c_H[1] = fy + fy;
      c_H[2] = b_H[3] * b_H[3];
      fy = b_H[0] * b_H[6];
      c_H[3] = fy + fy;
      fy = b_H[3] * b_H[6];
      c_H[4] = fy + fy;
      c_H[5] = b_H[6] * b_H[6];
      d_H[0] = b_H[1] * b_H[1];
      fy = b_H[1] * b_H[4];
      d_H[1] = fy + fy;
      d_H[2] = b_H[4] * b_H[4];
      fy = b_H[1] * b_H[7];
      d_H[3] = fy + fy;
      fy = b_H[4] * b_H[7];
      d_H[4] = fy + fy;
      d_H[5] = b_H[7] * b_H[7];
      if ((static_cast<int32_T>(u) < 1) ||
          (static_cast<int32_T>(u) > V.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(u), 1, V.size(0),
                                      &rs_emlrtBCI, &st);
      }
      for (i1 = 0; i1 < 6; i1++) {
        V[(static_cast<int32_T>(u) + V.size(0) * i1) - 1] = c_H[i1] - d_H[i1];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    covrtLogFor(&emlrtCoverageInstance, 3, 0, 2, 0);
    st.site = &xs_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 3, 6);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 18);
    // --------------------------------------------------------------------------
    //  lambda * B = inv(A)' * inv(A), where A is the intrinsic matrix
    b_st.site = &rv_emlrtRSI;
    coder::svd(&b_st, V, a__1, a__2, U);
    //  b = [B11, B12, B22, B13, B23, B33]
    st.site = &ys_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 3, 7);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 19);
    // --------------------------------------------------------------------------
    //  Compute the intrinsic matrix
    fy = U[31] * U[33] - U[30] * U[34];
    scale = U[30] * U[32] - U[31] * U[31];
    cy = fy / scale;
    lambda = U[35] - (U[33] * U[33] + cy * fy) / U[30];
    b_st.site = &vv_emlrtRSI;
    fy = lambda / U[30];
    if (fy < 0.0) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &u_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
    }
    fx = muDoubleScalarSqrt(fy);
    b_st.site = &wv_emlrtRSI;
    fy = lambda * U[30] / scale;
    if (fy < 0.0) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &u_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
    }
    fy = muDoubleScalarSqrt(fy);
    scale = fx * fx;
    skew = -U[31] * scale * fy / lambda;
    A[0] = fx;
    A[3] = skew;
    A[6] = skew * cy / fx - U[33] * scale / lambda;
    A[1] = 0.0;
    A[4] = fy;
    A[7] = cy;
    A[2] = 0.0;
    A[5] = 0.0;
    A[8] = 1.0;
    covrtLogCond(&emlrtCoverageInstance, 3, 0, 3, true);
    covrtLogMcdc(&emlrtCoverageInstance, 3, 0, 3, false);
    covrtLogIf(&emlrtCoverageInstance, 3, 0, 5, false);
    st.site = &at_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 3, 8);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 21);
    // --------------------------------------------------------------------------
    //  Compute translation and rotation vectors for all images
    rotationVectors.set_size(&ip_emlrtRTEI, &st, 3, H.size(2));
    translationVectors.set_size(&ip_emlrtRTEI, &st, 3, H.size(2));
    b_st.site = &aw_emlrtRSI;
    coder::inv(&b_st, A, b_H);
    i = H.size(2);
    for (b_i = 0; b_i < i; b_i++) {
      covrtLogFor(&emlrtCoverageInstance, 3, 0, 3, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 3, 22);
      if (b_i + 1 > H.size(2)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, H.size(2), &ss_emlrtBCI, &st);
      }
      fy = 0.0;
      scale = 3.3121686421112381E-170;
      for (loop_ub = 0; loop_ub < 3; loop_ub++) {
        skew = muDoubleScalarAbs(
            (b_H[loop_ub] * H[9 * b_i] + b_H[loop_ub + 3] * H[9 * b_i + 1]) +
            b_H[loop_ub + 6] * H[9 * b_i + 2]);
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
      for (i1 = 0; i1 < 9; i1++) {
        iniltialParams->IntrinsicMatrix[i1] = fy * b_H[i1];
      }
      for (i1 = 0; i1 < 3; i1++) {
        fy = iniltialParams->IntrinsicMatrix[i1];
        scale = fy * H[9 * b_i];
        skew = fy * H[9 * b_i + 3];
        fy = iniltialParams->IntrinsicMatrix[i1 + 3];
        scale += fy * H[9 * b_i + 1];
        skew += fy * H[9 * b_i + 4];
        fy = iniltialParams->IntrinsicMatrix[i1 + 6];
        scale += fy * H[9 * b_i + 2];
        skew += fy * H[9 * b_i + 5];
        r2[i1] = skew;
        b_r1[i1] = scale;
        r1[i1] = scale;
        r1[i1 + 3] = skew;
      }
      r1[6] = b_r1[1] * r2[2] - r2[1] * b_r1[2];
      r1[7] = r2[0] * b_r1[2] - b_r1[0] * r2[2];
      r1[8] = b_r1[0] * r2[1] - r2[0] * b_r1[1];
      if (b_i + 1 > rotationVectors.size(1)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, rotationVectors.size(1),
                                      &xs_emlrtBCI, &st);
      }
      b_st.site = &bw_emlrtRSI;
      coder::vision::internal::calibration::rodriguesMatrixToVector(&b_st, r1,
                                                                    b_r1);
      (*(real_T(*)[3]) & rotationVectors[3 * b_i])[0] = b_r1[0];
      (*(real_T(*)[3]) & rotationVectors[3 * b_i])[1] = b_r1[1];
      (*(real_T(*)[3]) & rotationVectors[3 * b_i])[2] = b_r1[2];
      //  translation vector
      if (b_i + 1 > translationVectors.size(1)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, translationVectors.size(1),
                                      &ws_emlrtBCI, &st);
      }
      for (i1 = 0; i1 < 3; i1++) {
        translationVectors[i1 + 3 * b_i] =
            (iniltialParams->IntrinsicMatrix[i1] * H[9 * b_i + 6] +
             iniltialParams->IntrinsicMatrix[i1 + 3] * H[9 * b_i + 7]) +
            iniltialParams->IntrinsicMatrix[i1 + 6] * H[9 * b_i + 8];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    covrtLogFor(&emlrtCoverageInstance, 3, 0, 3, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 23);
    iniltialParams->RotationVectors.set_size(&jp_emlrtRTEI, &st,
                                             rotationVectors.size(1), 3);
    loop_ub = rotationVectors.size(1);
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        iniltialParams
            ->RotationVectors[i1 + iniltialParams->RotationVectors.size(0) *
                                       i] = rotationVectors[i + 3 * i1];
      }
    }
    st.site = &bt_emlrtRSI;
    for (i = 0; i < 3; i++) {
      iniltialParams->IntrinsicMatrix[3 * i] = A[i];
      iniltialParams->IntrinsicMatrix[3 * i + 1] = A[i + 3];
      iniltialParams->IntrinsicMatrix[3 * i + 2] = A[i + 6];
    }
    covrtLogFcn(&emlrtCoverageInstance, 3, 1);
    covrtLogCond(&emlrtCoverageInstance, 3, 0, 0, false);
    covrtLogMcdc(&emlrtCoverageInstance, 3, 0, 0, true);
    covrtLogIf(&emlrtCoverageInstance, 3, 0, 1, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 3);
    rotationMatrices.set_size(&kp_emlrtRTEI, &st, 3, 3, imagePoints.size(2));
    i = imagePoints.size(2);
    for (b_i = 0; b_i < i; b_i++) {
      covrtLogFor(&emlrtCoverageInstance, 3, 0, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 3, 4);
      if (b_i + 1 > iniltialParams->RotationVectors.size(0)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                                      iniltialParams->RotationVectors.size(0),
                                      &ts_emlrtBCI, &st);
      }
      b_r1[0] = iniltialParams->RotationVectors[b_i];
      b_r1[1] =
          iniltialParams
              ->RotationVectors[b_i + iniltialParams->RotationVectors.size(0)];
      b_r1[2] =
          iniltialParams
              ->RotationVectors[b_i +
                                iniltialParams->RotationVectors.size(0) * 2];
      coder::vision::internal::calibration::rodriguesVectorToMatrix(b_r1, b_H);
      if (b_i + 1 > rotationMatrices.size(2)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, rotationMatrices.size(2),
                                      &us_emlrtBCI, &st);
      }
      for (i1 = 0; i1 < 3; i1++) {
        rotationMatrices[3 * i1 + 9 * b_i] = b_H[i1];
        rotationMatrices[(3 * i1 + 9 * b_i) + 1] = b_H[i1 + 3];
        rotationMatrices[(3 * i1 + 9 * b_i) + 2] = b_H[i1 + 6];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    covrtLogFor(&emlrtCoverageInstance, 3, 0, 0, 0);
    covrtLogCond(&emlrtCoverageInstance, 3, 0, 1, false);
    covrtLogMcdc(&emlrtCoverageInstance, 3, 0, 1, true);
    covrtLogIf(&emlrtCoverageInstance, 3, 0, 2, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 6);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 8);
    iniltialParams->RadialDistortion[0] = 0.0;
    iniltialParams->RadialDistortion[1] = 0.0;
    iniltialParams->RadialDistortion[2] = 0.0;
    iniltialParams->TangentialDistortion[0] = 0.0;
    iniltialParams->TangentialDistortion[1] = 0.0;
    iniltialParams->WorldPoints.set_size(&lp_emlrtRTEI, sp, worldPoints.size(0),
                                         2);
    loop_ub = worldPoints.size(0) * 2;
    for (i = 0; i < loop_ub; i++) {
      iniltialParams->WorldPoints[i] = worldPoints[i];
    }
    iniltialParams->WorldUnits.size[0] = 1;
    iniltialParams->WorldUnits.size[1] = 2;
    iniltialParams->WorldUnits.data[0] = 'm';
    iniltialParams->WorldUnits.data[1] = 'm';
    iniltialParams->EstimateSkew = false;
    iniltialParams->NumRadialDistortionCoefficients = 3.0;
    iniltialParams->EstimateTangentialDistortion = false;
    iniltialParams->TranslationVectors.set_size(&lp_emlrtRTEI, sp,
                                                translationVectors.size(1), 3);
    loop_ub = translationVectors.size(1);
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        iniltialParams->TranslationVectors
            [i1 + iniltialParams->TranslationVectors.size(0) * i] =
            translationVectors[i + 3 * i1];
      }
    }
    iniltialParams->NumPatterns.size[0] = 1;
    iniltialParams->NumPatterns.size[1] = 1;
    iniltialParams->NumPatterns.data[0] = imagePoints.size(2);
    iniltialParams->FocalLength[0] = iniltialParams->IntrinsicMatrix[0];
    iniltialParams->FocalLength[1] = iniltialParams->IntrinsicMatrix[4];
    iniltialParams->PrincipalPoint[0] = iniltialParams->IntrinsicMatrix[2];
    iniltialParams->PrincipalPoint[1] = iniltialParams->IntrinsicMatrix[5];
    iniltialParams->Skew = iniltialParams->IntrinsicMatrix[1];
    iniltialParams->RotationMatrices.set_size(&lp_emlrtRTEI, sp, 3, 3,
                                              rotationMatrices.size(2));
    loop_ub = 9 * rotationMatrices.size(2);
    for (i = 0; i < loop_ub; i++) {
      iniltialParams->RotationMatrices[i] = rotationMatrices[i];
    }
    iniltialParams->MeanReprojectionError = rtNaN;
  } else {
    int32_T loop_ub;
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 2);
    st.site = &ct_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 3, 1);
    covrtLogCond(&emlrtCoverageInstance, 3, 0, 0, true);
    covrtLogMcdc(&emlrtCoverageInstance, 3, 0, 0, false);
    covrtLogIf(&emlrtCoverageInstance, 3, 0, 1, false);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 5);
    covrtLogCond(&emlrtCoverageInstance, 3, 0, 1, false);
    covrtLogMcdc(&emlrtCoverageInstance, 3, 0, 1, true);
    covrtLogIf(&emlrtCoverageInstance, 3, 0, 2, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 6);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 8);
    iniltialParams->RadialDistortion[0] = 0.0;
    iniltialParams->RadialDistortion[1] = 0.0;
    iniltialParams->RadialDistortion[2] = 0.0;
    iniltialParams->TangentialDistortion[0] = 0.0;
    iniltialParams->TangentialDistortion[1] = 0.0;
    iniltialParams->WorldPoints.set_size(&gp_emlrtRTEI, sp, worldPoints.size(0),
                                         2);
    loop_ub = worldPoints.size(0) * 2;
    for (int32_T i{0}; i < loop_ub; i++) {
      iniltialParams->WorldPoints[i] = worldPoints[i];
    }
    iniltialParams->WorldUnits.size[0] = 1;
    iniltialParams->WorldUnits.size[1] = 0;
    iniltialParams->EstimateSkew = false;
    iniltialParams->NumRadialDistortionCoefficients = 3.0;
    iniltialParams->EstimateTangentialDistortion = false;
    iniltialParams->RotationVectors.set_size(&gp_emlrtRTEI, sp, 1, 3);
    iniltialParams->TranslationVectors.set_size(&gp_emlrtRTEI, sp, 1, 3);
    iniltialParams->RotationVectors[0] = 0.0;
    iniltialParams->TranslationVectors[0] = 0.0;
    iniltialParams->RotationVectors[1] = 0.0;
    iniltialParams->TranslationVectors[1] = 0.0;
    iniltialParams->RotationVectors[2] = 0.0;
    iniltialParams->TranslationVectors[2] = 0.0;
    std::memset(&iniltialParams->IntrinsicMatrix[0], 0, 9U * sizeof(real_T));
    iniltialParams->NumPatterns.size[0] = 0;
    iniltialParams->NumPatterns.size[1] = 0;
    iniltialParams->FocalLength[0] = 0.0;
    iniltialParams->PrincipalPoint[0] = 0.0;
    iniltialParams->FocalLength[1] = 0.0;
    iniltialParams->PrincipalPoint[1] = 0.0;
    iniltialParams->Skew = 0.0;
    iniltialParams->RotationMatrices.set_size(&gp_emlrtRTEI, sp, 0, 0, 1);
    iniltialParams->MeanReprojectionError = rtNaN;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace Codegen

// End of code generation (computeInitialParameterEstimate.cpp)
