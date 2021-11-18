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
#include "calibrateOneCamera_v2_data.h"
#include "calibrateOneCamera_v2_types.h"
#include "cameraParameters.h"
#include "fitgeotrans.h"
#include "inv.h"
#include "norm.h"
#include "projective2d.h"
#include "rodriguesMatrixToVector.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo pw_emlrtRSI{
    6,                                 // lineNo
    "computeInitialParameterEstimate", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo qw_emlrtRSI{
    12,                                // lineNo
    "computeInitialParameterEstimate", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo rw_emlrtRSI{
    13,                                // lineNo
    "computeInitialParameterEstimate", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo sw_emlrtRSI{
    14,                                // lineNo
    "computeInitialParameterEstimate", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo tw_emlrtRSI{
    16,                                // lineNo
    "computeInitialParameterEstimate", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo uw_emlrtRSI{
    20,                                // lineNo
    "computeInitialParameterEstimate", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo vw_emlrtRSI{
    31,                                // lineNo
    "computeInitialParameterEstimate", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo ww_emlrtRSI{
    105,                   // lineNo
    "computeHomographies", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo xw_emlrtRSI{
    113,                   // lineNo
    "computeHomographies", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo yw_emlrtRSI{
    87,                  // lineNo
    "computeHomography", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo pab_emlrtRSI{
    135,        // lineNo
    "computeV", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo qab_emlrtRSI{
    136,        // lineNo
    "computeV", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo rab_emlrtRSI{
    148,        // lineNo
    "computeB", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo wab_emlrtRSI{
    158,                 // lineNo
    "computeIntrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo xab_emlrtRSI{
    159,                 // lineNo
    "computeIntrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo yab_emlrtRSI{
    160,                 // lineNo
    "computeIntrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo abb_emlrtRSI{
    161,                 // lineNo
    "computeIntrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo bbb_emlrtRSI{
    162,                 // lineNo
    "computeIntrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo cbb_emlrtRSI{
    163,                 // lineNo
    "computeIntrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo dbb_emlrtRSI{
    180,                 // lineNo
    "computeExtrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pathName
};

static emlrtRSInfo ebb_emlrtRSI{
    194,                 // lineNo
    "computeExtrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pathName
};

static emlrtBCInfo it_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    85,                  // lineNo
    39,                  // colNo
    "imagePoints",       // aName
    "computeHomography", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m", // pName
    0 // checkKind
};

static emlrtBCInfo jt_emlrtBCI{
    -1,                    // iFirst
    -1,                    // iLast
    104,                   // lineNo
    28,                    // colNo
    "homographies",        // aName
    "computeHomographies", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m", // pName
    0 // checkKind
};

static emlrtBCInfo kt_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    182,                 // lineNo
    28,                  // colNo
    "homographies",      // aName
    "computeExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m", // pName
    0 // checkKind
};

static emlrtBCInfo lt_emlrtBCI{
    -1,         // iFirst
    -1,         // iLast
    136,        // lineNo
    7,          // colNo
    "V",        // aName
    "computeV", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m", // pName
    0 // checkKind
};

static emlrtBCInfo mt_emlrtBCI{
    -1,             // iFirst
    -1,             // iLast
    134,            // lineNo
    28,             // colNo
    "homographies", // aName
    "computeV",     // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m", // pName
    0 // checkKind
};

static emlrtBCInfo nt_emlrtBCI{
    -1,                    // iFirst
    -1,                    // iLast
    105,                   // lineNo
    51,                    // colNo
    "points",              // aName
    "computeHomographies", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m", // pName
    0 // checkKind
};

static emlrtBCInfo ot_emlrtBCI{
    -1,         // iFirst
    -1,         // iLast
    135,        // lineNo
    7,          // colNo
    "V",        // aName
    "computeV", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m", // pName
    0 // checkKind
};

static emlrtBCInfo pt_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    198,                  // lineNo
    27,                   // colNo
    "translationVectors", // aName
    "computeExtrinsics",  // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m", // pName
    0 // checkKind
};

static emlrtDCInfo ng_emlrtDCI{
    132,        // lineNo
    11,         // colNo
    "computeV", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m", // pName
    1 // checkKind
};

static emlrtBCInfo qt_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    87,                  // lineNo
    29,                  // colNo
    "worldPoints",       // aName
    "computeHomography", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m", // pName
    0 // checkKind
};

static emlrtBCInfo rt_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    87,                  // lineNo
    60,                  // colNo
    "imagePoints",       // aName
    "computeHomography", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m", // pName
    0 // checkKind
};

static emlrtDCInfo og_emlrtDCI{
    12,                                // lineNo
    1,                                 // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m", // pName
    1 // checkKind
};

static emlrtBCInfo st_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    194,                 // lineNo
    24,                  // colNo
    "rotationVectors",   // aName
    "computeExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m", // pName
    0 // checkKind
};

static emlrtBCInfo tt_emlrtBCI{
    -1,                    // iFirst
    -1,                    // iLast
    112,                   // lineNo
    35,                    // colNo
    "homographies",        // aName
    "computeHomographies", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m", // pName
    0 // checkKind
};

static emlrtRTEInfo br_emlrtRTEI{
    100,                               // lineNo
    1,                                 // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo cr_emlrtRTEI{
    101,                               // lineNo
    1,                                 // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo dr_emlrtRTEI{
    105,                               // lineNo
    38,                                // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo er_emlrtRTEI{
    105,                               // lineNo
    13,                                // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo fr_emlrtRTEI{
    87,                                // lineNo
    17,                                // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo gr_emlrtRTEI{
    87,                                // lineNo
    48,                                // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo hr_emlrtRTEI{
    6,                                 // lineNo
    1,                                 // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo ir_emlrtRTEI{
    112,                               // lineNo
    16,                                // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo jr_emlrtRTEI{
    112,                               // lineNo
    1,                                 // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo kr_emlrtRTEI{
    31,                                // lineNo
    5,                                 // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo lr_emlrtRTEI{
    12,                                // lineNo
    1,                                 // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo mr_emlrtRTEI{
    16,                                // lineNo
    1,                                 // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo nr_emlrtRTEI{
    201,                               // lineNo
    19,                                // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo or_emlrtRTEI{
    202,                               // lineNo
    22,                                // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pName
};

static emlrtRTEInfo pr_emlrtRTEI{
    20,                                // lineNo
    1,                                 // colNo
    "computeInitialParameterEstimate", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m" // pName
};

// Function Definitions
void computeInitialParameterEstimate(
    const emlrtStack *sp, const coder::array<real_T, 2U> &worldPoints,
    const coder::array<real_T, 3U> &imagePoints, const real_T imageSize[2],
    struct_T *initialParams, coder::array<boolean_T, 1U> &validIdx,
    int32_T *err)
{
  coder::c_cameraParameters lobj_0;
  coder::cameraParameters lobj_1;
  coder::projective2d c_H;
  coder::array<real_T, 3U> H;
  coder::array<real_T, 3U> b_H;
  coder::array<real_T, 2U> V;
  coder::array<real_T, 2U> a__2;
  coder::array<real_T, 2U> b_imagePoints;
  coder::array<real_T, 2U> b_rotationVectors;
  coder::array<real_T, 2U> b_translationVectors;
  coder::array<real_T, 2U> b_worldPoints;
  coder::array<real_T, 2U> c_imagePoints;
  coder::array<real_T, 2U> rotationVectors;
  coder::array<real_T, 2U> translationVectors;
  coder::array<int32_T, 1U> r;
  coder::array<int32_T, 1U> r1;
  coder::array<boolean_T, 1U> validPointsIdx;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T U[36];
  real_T A[9];
  real_T c_r1[9];
  real_T d_H[9];
  real_T r1_tmp[9];
  real_T e_H[6];
  real_T f_H[6];
  real_T b_r1[3];
  real_T r2[3];
  real_T fy;
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  char_T t10_WorldUnits[2];
  char_T t11_WorldUnits;
  boolean_T c_t10_EstimateTangentialDistort;
  boolean_T t10_EstimateSkew;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 2, 0);
  //  Solve for the camera intriniscs and extrinsics in closed form ignoring
  //  distortion.
  st.site = &pw_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 2, 3);
  covrtLogBasicBlock(&emlrtCoverageInstance, 2, 10);
  // --------------------------------------------------------------------------
  //  Compute homographies for all images
  *err = 0;
  // w1 = warning('Error', 'MATLAB:nearlySingularMatrix'); %#ok
  // w2 = warning('Error', 'images:maketform:conditionNumberofAIsHigh'); %#ok
  validIdx.set_size(&br_emlrtRTEI, &st, imagePoints.size(2));
  loop_ub = imagePoints.size(2);
  for (i = 0; i < loop_ub; i++) {
    validIdx[i] = true;
  }
  H.set_size(&cr_emlrtRTEI, &st, 3, 3, imagePoints.size(2));
  loop_ub = 9 * imagePoints.size(2);
  for (i = 0; i < loop_ub; i++) {
    H[i] = 0.0;
  }
  i = imagePoints.size(2);
  for (b_i = 0; b_i < i; b_i++) {
    int32_T c_i;
    int32_T i2;
    covrtLogFor(&emlrtCoverageInstance, 2, 0, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 11);
    //  try
    b_st.site = &ww_emlrtRSI;
    if (b_i + 1 > imagePoints.size(2)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, imagePoints.size(2),
                                    &nt_emlrtBCI, &b_st);
    }
    loop_ub = imagePoints.size(0);
    b_loop_ub = imagePoints.size(1);
    b_imagePoints.set_size(&dr_emlrtRTEI, &b_st, imagePoints.size(0),
                           imagePoints.size(1));
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_imagePoints[i2 + b_imagePoints.size(0) * i1] =
            imagePoints[(i2 + imagePoints.size(0) * i1) +
                        imagePoints.size(0) * imagePoints.size(1) * b_i];
      }
    }
    covrtLogFcn(&emlrtCoverageInstance, 2, 2);
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 9);
    // --------------------------------------------------------------------------
    //  Compute projective transformation from worldPoints to imagePoints
    if (1 > imagePoints.size(1)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, imagePoints.size(1), &it_emlrtBCI,
                                    &b_st);
    }
    loop_ub = imagePoints.size(0) - 1;
    validPointsIdx.set_size(&pe_emlrtRTEI, &b_st, imagePoints.size(0));
    for (i1 = 0; i1 <= loop_ub; i1++) {
      validPointsIdx[i1] = muDoubleScalarIsNaN(b_imagePoints[i1]);
    }
    loop_ub = validPointsIdx.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      validPointsIdx[i1] = !validPointsIdx[i1];
    }
    b_loop_ub = validPointsIdx.size(0) - 1;
    loop_ub = 0;
    for (c_i = 0; c_i <= b_loop_ub; c_i++) {
      if (validPointsIdx[c_i]) {
        loop_ub++;
      }
    }
    r1.set_size(&er_emlrtRTEI, &b_st, loop_ub);
    loop_ub = 0;
    for (c_i = 0; c_i <= b_loop_ub; c_i++) {
      if (validPointsIdx[c_i]) {
        r1[loop_ub] = c_i + 1;
        loop_ub++;
      }
    }
    loop_ub = imagePoints.size(1) - 1;
    b_loop_ub = worldPoints.size(1);
    b_worldPoints.set_size(&fr_emlrtRTEI, &b_st, r1.size(0),
                           worldPoints.size(1));
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      c_i = r1.size(0);
      for (i2 = 0; i2 < c_i; i2++) {
        if (r1[i2] > worldPoints.size(0)) {
          emlrtDynamicBoundsCheckR2012b(r1[i2], 1, worldPoints.size(0),
                                        &qt_emlrtBCI, &b_st);
        }
        b_worldPoints[i2 + b_worldPoints.size(0) * i1] =
            worldPoints[(r1[i2] + worldPoints.size(0) * i1) - 1];
      }
    }
    c_imagePoints.set_size(&gr_emlrtRTEI, &b_st, r1.size(0),
                           imagePoints.size(1));
    for (i1 = 0; i1 <= loop_ub; i1++) {
      b_loop_ub = r1.size(0);
      for (i2 = 0; i2 < b_loop_ub; i2++) {
        if (r1[i2] > imagePoints.size(0)) {
          emlrtDynamicBoundsCheckR2012b(r1[i2], 1, imagePoints.size(0),
                                        &rt_emlrtBCI, &b_st);
        }
        c_imagePoints[i2 + c_imagePoints.size(0) * i1] =
            b_imagePoints[(r1[i2] + b_imagePoints.size(0) * i1) - 1];
      }
    }
    c_st.site = &yw_emlrtRSI;
    coder::fitgeotrans(&c_st, b_worldPoints, c_imagePoints, &c_H);
    if (b_i + 1 > H.size(2)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, H.size(2), &jt_emlrtBCI, &b_st);
    }
    for (i1 = 0; i1 < 3; i1++) {
      H[3 * i1 + 9 * b_i] = c_H.T[i1];
      H[(3 * i1 + 9 * b_i) + 1] = c_H.T[i1 + 3];
      H[(3 * i1 + 9 * b_i) + 2] = c_H.T[i1 + 6];
    }
    if (b_i + 1 > H.size(2)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, H.size(2), &jt_emlrtBCI, &b_st);
    }
    fy = H[9 * b_i + 8];
    if (b_i + 1 > H.size(2)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, H.size(2), &jt_emlrtBCI, &b_st);
    }
    for (i1 = 0; i1 < 3; i1++) {
      H[3 * i1 + 9 * b_i] = H[3 * i1 + 9 * b_i] / fy;
      H[(3 * i1 + 9 * b_i) + 1] = H[(3 * i1 + 9 * b_i) + 1] / fy;
      H[(3 * i1 + 9 * b_i) + 2] = H[(3 * i1 + 9 * b_i) + 2] / fy;
    }
    //  catch
    //      validIdx(i) = false;
    //  end
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 2, 0, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 2, 12);
  // warning(w1);
  // warning(w2);
  b_loop_ub = imagePoints.size(2) - 1;
  loop_ub = 0;
  for (b_i = 0; b_i <= b_loop_ub; b_i++) {
    loop_ub++;
  }
  r.set_size(&hr_emlrtRTEI, &st, loop_ub);
  for (b_i = 0; b_i <= b_loop_ub; b_i++) {
    r[b_i] = b_i + 1;
  }
  b_H.set_size(&ir_emlrtRTEI, &st, 3, 3, r.size(0));
  loop_ub = r.size(0);
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < 3; i1++) {
      if (r[i] > H.size(2)) {
        emlrtDynamicBoundsCheckR2012b(r[i], 1, H.size(2), &tt_emlrtBCI, &st);
      }
      b_H[3 * i1 + 9 * i] = H[3 * i1 + 9 * (r[i] - 1)];
      if (r[i] > H.size(2)) {
        emlrtDynamicBoundsCheckR2012b(r[i], 1, H.size(2), &tt_emlrtBCI, &st);
      }
      b_H[(3 * i1 + 9 * i) + 1] = H[(3 * i1 + 9 * (r[i] - 1)) + 1];
      if (r[i] > H.size(2)) {
        emlrtDynamicBoundsCheckR2012b(r[i], 1, H.size(2), &tt_emlrtBCI, &st);
      }
      b_H[(3 * i1 + 9 * i) + 2] = H[(3 * i1 + 9 * (r[i] - 1)) + 2];
    }
  }
  H.set_size(&jr_emlrtRTEI, &st, 3, 3, b_H.size(2));
  loop_ub = 9 * b_H.size(2);
  for (i = 0; i < loop_ub; i++) {
    H[i] = b_H[i];
  }
  b_st.site = &xw_emlrtRSI;
  if (covrtLogIf(&emlrtCoverageInstance, 2, 0, 3,
                 covrtLogMcdc(&emlrtCoverageInstance, 2, 0, 2,
                              !covrtLogCond(&emlrtCoverageInstance, 2, 0, 2,
                                            coder::all(&b_st, validIdx))))) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 13);
    // warning(message('vision:calibrate:invalidHomographies', ...
    //     numImages - size(homographies, 3), numImages));
    // err = "invalid Homographies";
    *err = -201;
  } else if (covrtLogIf(&emlrtCoverageInstance, 2, 0, 4, H.size(2) < 2)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 14);
    // error(message('vision:calibrate:notEnoughValidHomographies'));
    *err = -201;
  }
  if (covrtLogIf(&emlrtCoverageInstance, 2, 0, 0, *err == 0)) {
    real_T cy;
    real_T fx;
    real_T lambda;
    real_T skew;
    real_T skew_tmp;
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 1);
    st.site = &qw_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 2, 4);
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 15);
    // --------------------------------------------------------------------------
    //  Vb = 0
    fy = 2.0 * static_cast<real_T>(H.size(2));
    if (fy != static_cast<int32_T>(fy)) {
      emlrtIntegerCheckR2012b(fy, &ng_emlrtDCI, &st);
    }
    V.set_size(&lr_emlrtRTEI, &st, static_cast<int32_T>(fy), 6);
    fy = 2.0 * static_cast<real_T>(H.size(2));
    if (fy != static_cast<int32_T>(fy)) {
      emlrtIntegerCheckR2012b(fy, &og_emlrtDCI, &st);
    }
    loop_ub = static_cast<int32_T>(fy) * 6;
    for (i = 0; i < loop_ub; i++) {
      V[i] = 0.0;
    }
    i = H.size(2);
    for (b_i = 0; b_i < i; b_i++) {
      uint32_T u;
      covrtLogFor(&emlrtCoverageInstance, 2, 0, 2, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 2, 16);
      if (b_i + 1 > H.size(2)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, H.size(2), &mt_emlrtBCI, &st);
      }
      for (i1 = 0; i1 < 3; i1++) {
        d_H[3 * i1] = H[i1 + 9 * b_i];
        d_H[3 * i1 + 1] = H[(i1 + 9 * b_i) + 3];
        d_H[3 * i1 + 2] = H[(i1 + 9 * b_i) + 6];
      }
      b_st.site = &pab_emlrtRSI;
      covrtLogFcn(&emlrtCoverageInstance, 2, 5);
      covrtLogBasicBlock(&emlrtCoverageInstance, 2, 17);
      // --------------------------------------------------------------------------
      u = static_cast<uint32_T>(b_i + 1) << 1;
      if ((static_cast<int32_T>(u - 1U) < 1) ||
          (static_cast<int32_T>(u - 1U) > V.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(u - 1U), 1,
                                      V.size(0), &ot_emlrtBCI, &b_st);
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
      b_st.site = &qab_emlrtRSI;
      covrtLogFcn(&emlrtCoverageInstance, 2, 5);
      covrtLogBasicBlock(&emlrtCoverageInstance, 2, 17);
      // --------------------------------------------------------------------------
      b_st.site = &qab_emlrtRSI;
      covrtLogFcn(&emlrtCoverageInstance, 2, 5);
      covrtLogBasicBlock(&emlrtCoverageInstance, 2, 17);
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
                                      &lt_emlrtBCI, &st);
      }
      for (i1 = 0; i1 < 6; i1++) {
        V[(static_cast<int32_T>(u) + V.size(0) * i1) - 1] = e_H[i1] - f_H[i1];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    covrtLogFor(&emlrtCoverageInstance, 2, 0, 2, 0);
    st.site = &rw_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 2, 6);
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 18);
    // --------------------------------------------------------------------------
    //  lambda * B = inv(A)' * inv(A), where A is the intrinsic matrix
    b_st.site = &rab_emlrtRSI;
    coder::svd(&b_st, V, b_imagePoints, a__2, U);
    //  b = [B11, B12, B22, B13, B23, B33]
    st.site = &sw_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 2, 7);
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 19);
    // --------------------------------------------------------------------------
    //  Compute the intrinsic matrix
    b_st.site = &wab_emlrtRSI;
    fy = U[31] * U[33] - U[30] * U[34];
    skew = U[30] * U[32] - U[31] * U[31];
    cy = fy / skew;
    b_st.site = &xab_emlrtRSI;
    lambda = U[35] - (U[33] * U[33] + cy * fy) / U[30];
    b_st.site = &yab_emlrtRSI;
    fx = lambda / U[30];
    if (fx < 0.0) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &x_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
    }
    fx = muDoubleScalarSqrt(fx);
    b_st.site = &abb_emlrtRSI;
    b_st.site = &abb_emlrtRSI;
    fy = lambda * U[30] / skew;
    if (fy < 0.0) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &x_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
    }
    fy = muDoubleScalarSqrt(fy);
    b_st.site = &bbb_emlrtRSI;
    skew_tmp = fx * fx;
    skew = -U[31] * skew_tmp * fy / lambda;
    b_st.site = &cbb_emlrtRSI;
    A[0] = fx;
    A[3] = skew;
    A[6] = skew * cy / fx - U[33] * skew_tmp / lambda;
    A[1] = 0.0;
    A[4] = fy;
    A[7] = cy;
    A[2] = 0.0;
    A[5] = 0.0;
    A[8] = 1.0;
    covrtLogCond(&emlrtCoverageInstance, 2, 0, 3, true);
    covrtLogMcdc(&emlrtCoverageInstance, 2, 0, 3, false);
    covrtLogIf(&emlrtCoverageInstance, 2, 0, 5, false);
    st.site = &tw_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 2, 8);
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 21);
    // --------------------------------------------------------------------------
    //  Compute translation and rotation vectors for all images
    rotationVectors.set_size(&mr_emlrtRTEI, &st, 3, H.size(2));
    translationVectors.set_size(&mr_emlrtRTEI, &st, 3, H.size(2));
    b_st.site = &dbb_emlrtRSI;
    coder::inv(&b_st, A, d_H);
    i = H.size(2);
    for (b_i = 0; b_i < i; b_i++) {
      covrtLogFor(&emlrtCoverageInstance, 2, 0, 3, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 2, 22);
      if (b_i + 1 > H.size(2)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, H.size(2), &kt_emlrtBCI, &st);
      }
      for (i1 = 0; i1 < 3; i1++) {
        b_r1[i1] = (d_H[i1] * H[9 * b_i] + d_H[i1 + 3] * H[9 * b_i + 1]) +
                   d_H[i1 + 6] * H[9 * b_i + 2];
      }
      fy = 1.0 / coder::b_norm(b_r1);
      //  3D rotation matrix
      for (i1 = 0; i1 < 9; i1++) {
        r1_tmp[i1] = fy * d_H[i1];
      }
      for (i1 = 0; i1 < 3; i1++) {
        fy = r1_tmp[i1];
        skew = fy * H[9 * b_i];
        skew_tmp = fy * H[9 * b_i + 3];
        fy = r1_tmp[i1 + 3];
        skew += fy * H[9 * b_i + 1];
        skew_tmp += fy * H[9 * b_i + 4];
        fy = r1_tmp[i1 + 6];
        skew += fy * H[9 * b_i + 2];
        skew_tmp += fy * H[9 * b_i + 5];
        r2[i1] = skew_tmp;
        b_r1[i1] = skew;
        c_r1[i1] = skew;
        c_r1[i1 + 3] = skew_tmp;
      }
      c_r1[6] = b_r1[1] * r2[2] - r2[1] * b_r1[2];
      c_r1[7] = r2[0] * b_r1[2] - b_r1[0] * r2[2];
      c_r1[8] = b_r1[0] * r2[1] - r2[0] * b_r1[1];
      if (b_i + 1 > rotationVectors.size(1)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, rotationVectors.size(1),
                                      &st_emlrtBCI, &st);
      }
      b_st.site = &ebb_emlrtRSI;
      coder::vision::internal::calibration::rodriguesMatrixToVector(&b_st, c_r1,
                                                                    b_r1);
      (*(real_T(*)[3]) & rotationVectors[3 * b_i])[0] = b_r1[0];
      (*(real_T(*)[3]) & rotationVectors[3 * b_i])[1] = b_r1[1];
      (*(real_T(*)[3]) & rotationVectors[3 * b_i])[2] = b_r1[2];
      //  translation vector
      if (b_i + 1 > translationVectors.size(1)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, translationVectors.size(1),
                                      &pt_emlrtBCI, &st);
      }
      for (i1 = 0; i1 < 3; i1++) {
        translationVectors[i1 + 3 * b_i] =
            (r1_tmp[i1] * H[9 * b_i + 6] + r1_tmp[i1 + 3] * H[9 * b_i + 7]) +
            r1_tmp[i1 + 6] * H[9 * b_i + 8];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    covrtLogFor(&emlrtCoverageInstance, 2, 0, 3, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 23);
    // iniltialParams =
    // my_CameraParameters(radialCoeffs,worldPoints,worldUnits,cameraModel,rvecs,tvecs,A',size(imagePoints,
    // 3));
    b_rotationVectors.set_size(&nr_emlrtRTEI, sp, rotationVectors.size(1), 3);
    b_translationVectors.set_size(&or_emlrtRTEI, sp, translationVectors.size(1),
                                  3);
    loop_ub = rotationVectors.size(1);
    b_loop_ub = translationVectors.size(1);
    for (i = 0; i < 3; i++) {
      d_H[3 * i] = A[i];
      d_H[3 * i + 1] = A[i + 3];
      d_H[3 * i + 2] = A[i + 6];
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_rotationVectors[i1 + b_rotationVectors.size(0) * i] =
            rotationVectors[i + 3 * i1];
      }
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        b_translationVectors[i1 + b_translationVectors.size(0) * i] =
            translationVectors[i + 3 * i1];
      }
    }
    st.site = &uw_emlrtRSI;
    lobj_0
        .init(&st, d_H, b_rotationVectors, b_translationVectors, worldPoints,
              imageSize)
        ->toStruct(
            &st, initialParams->RadialDistortion,
            initialParams->TangentialDistortion, initialParams->ImageSize,
            initialParams->WorldPoints, &t11_WorldUnits, &t10_EstimateSkew, &fy,
            &c_t10_EstimateTangentialDistort, initialParams->RotationVectors,
            initialParams->TranslationVectors, initialParams->IntrinsicMatrix);
    initialParams->WorldUnits.set_size(&pr_emlrtRTEI, sp, 1, 1);
    initialParams->WorldUnits[0] = t11_WorldUnits;
    initialParams->EstimateSkew = t10_EstimateSkew;
    initialParams->NumRadialDistortionCoefficients = fy;
    initialParams->EstimateTangentialDistortion =
        c_t10_EstimateTangentialDistort;
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 2);
    // iniltialParams = my_CameraParameters(zeros(1,3),worldPoints,'',
    // cameraModel,zeros(1,3),zeros(1,3),zeros(3,3),[]);
    st.site = &vw_emlrtRSI;
    lobj_1.init(&st, imageSize)
        ->toStruct(initialParams->RadialDistortion,
                   initialParams->TangentialDistortion,
                   initialParams->ImageSize, t10_WorldUnits, &t10_EstimateSkew,
                   &fy, &c_t10_EstimateTangentialDistort,
                   initialParams->IntrinsicMatrix);
    initialParams->WorldPoints.set_size(&kr_emlrtRTEI, sp, 0, 2);
    initialParams->WorldUnits.set_size(&kr_emlrtRTEI, sp, 1, 2);
    initialParams->WorldUnits[0] = t10_WorldUnits[0];
    initialParams->WorldUnits[1] = t10_WorldUnits[1];
    initialParams->EstimateSkew = t10_EstimateSkew;
    initialParams->NumRadialDistortionCoefficients = fy;
    initialParams->EstimateTangentialDistortion =
        c_t10_EstimateTangentialDistort;
    initialParams->RotationVectors.set_size(&kr_emlrtRTEI, sp, 0, 3);
    initialParams->TranslationVectors.set_size(&kr_emlrtRTEI, sp, 0, 3);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

// End of code generation (computeInitialParameterEstimate.cpp)
