//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// calibrateOneCamera.cpp
//
// Code generation for function 'calibrateOneCamera'
//

// Include files
#include "calibrateOneCamera.h"
#include "CalculateCost.h"
#include "all.h"
#include "anonymous_function1.h"
#include "calibrateOneCamera_mex_data.h"
#include "calibrateOneCamera_mex_internal_types.h"
#include "calibrateOneCamera_mex_internal_types11.h"
#include "calibrateOneCamera_mex_internal_types2.h"
#include "calibrateOneCamera_mex_types.h"
#include "combineVectorElements.h"
#include "computeInitialParameterEstimate.h"
#include "detectCheckerboardPoints.h"
#include "generateCheckerboardPoints.h"
#include "lsqnonlin.h"
#include "nanmean.h"
#include "rodriguesVectorToMatrix.h"
#include "rt_nonfinite.h"
#include "serializeCalib.h"
#include "unserializeCalib.h"
#include "coder_array.h"
#include <algorithm>

// Type Definitions
namespace Codegen {
struct cell_wrap_2 {
  real_T f1[2];
};

struct cell_wrap_1 {
  ::coder::array<real_T, 2U> f1;
};

} // namespace Codegen

// Variable Definitions
static emlrtRSInfo emlrtRSI{
    28,                   // lineNo
    "calibrateOneCamera", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m" // pathName
};

static emlrtRSInfo b_emlrtRSI{
    34,                   // lineNo
    "calibrateOneCamera", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m" // pathName
};

static emlrtRSInfo c_emlrtRSI{
    45,                   // lineNo
    "calibrateOneCamera", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m" // pathName
};

static emlrtRSInfo d_emlrtRSI{
    50,                   // lineNo
    "calibrateOneCamera", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m" // pathName
};

static emlrtRSInfo e_emlrtRSI{
    64,                   // lineNo
    "calibrateOneCamera", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m" // pathName
};

static emlrtRSInfo f_emlrtRSI{
    81,                   // lineNo
    "calibrateOneCamera", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m" // pathName
};

static emlrtRSInfo g_emlrtRSI{
    101,                  // lineNo
    "calibrateOneCamera", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m" // pathName
};

static emlrtRSInfo h_emlrtRSI{
    104,                  // lineNo
    "calibrateOneCamera", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m" // pathName
};

static emlrtRSInfo i_emlrtRSI{
    118,                  // lineNo
    "calibrateOneCamera", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m" // pathName
};

static emlrtRSInfo j_emlrtRSI{
    128,                  // lineNo
    "calibrateOneCamera", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m" // pathName
};

static emlrtRSInfo k_emlrtRSI{
    129,                  // lineNo
    "calibrateOneCamera", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m" // pathName
};

static emlrtRSInfo l_emlrtRSI{
    132,                  // lineNo
    "calibrateOneCamera", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m" // pathName
};

static emlrtRSInfo js_emlrtRSI{
    15,    // lineNo
    "sum", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" // pathName
};

static emlrtBCInfo emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    77,                   // lineNo
    29,                   // colNo
    "RotationMatrices",   // aName
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m", // pName
    0                           // checkKind
};

static emlrtBCInfo b_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    54,                   // lineNo
    44,                   // colNo
    "board_points",       // aName
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m", // pName
    0                           // checkKind
};

static emlrtBCInfo c_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    51,                   // lineNo
    41,                   // colNo
    "board_points",       // aName
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m", // pName
    0                           // checkKind
};

static emlrtBCInfo d_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    81,                   // lineNo
    50,                   // colNo
    "tempt",              // aName
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m", // pName
    0                           // checkKind
};

static emlrtBCInfo e_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    81,                   // lineNo
    41,                   // colNo
    "tempR",              // aName
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m", // pName
    0                           // checkKind
};

static emlrtBCInfo f_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    73,                   // lineNo
    28,                   // colNo
    "RotationMatrices",   // aName
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m", // pName
    0                           // checkKind
};

static emlrtBCInfo g_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    72,                              // lineNo
    39,                              // colNo
    "initialParams.RotationVectors", // aName
    "calibrateOneCamera",            // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m", // pName
    0                           // checkKind
};

static emlrtECInfo emlrtECI{
    -1,                   // nDims
    54,                   // lineNo
    9,                    // colNo
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m" // pName
};

static emlrtBCInfo h_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    54,                   // lineNo
    26,                   // colNo
    "image_points",       // aName
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m", // pName
    0                           // checkKind
};

static emlrtBCInfo i_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    33,                   // lineNo
    32,                   // colNo
    "images",             // aName
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m", // pName
    0                           // checkKind
};

static emlrtBCInfo j_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    41,                   // lineNo
    18,                   // colNo
    "board_points",       // aName
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m", // pName
    0                           // checkKind
};

static emlrtBCInfo k_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    23,                   // lineNo
    35,                   // colNo
    "board_points",       // aName
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m", // pName
    0                           // checkKind
};

static emlrtBCInfo l_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    39,                   // lineNo
    19,                   // colNo
    "valid_idx",          // aName
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m", // pName
    0                           // checkKind
};

static emlrtBCInfo m_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    37,                   // lineNo
    19,                   // colNo
    "valid_idx",          // aName
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m", // pName
    0                           // checkKind
};

static emlrtBCInfo n_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    53,                   // lineNo
    18,                   // colNo
    "valid_idx",          // aName
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m", // pName
    0                           // checkKind
};

static emlrtBCInfo o_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    41,                   // lineNo
    5,                    // colNo
    "board_points",       // aName
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m", // pName
    0                           // checkKind
};

static emlrtBCInfo p_emlrtBCI{
    -1,                                 // iFirst
    -1,                                 // iLast
    78,                                 // lineNo
    41,                                 // colNo
    "initialParams.TranslationVectors", // aName
    "calibrateOneCamera",               // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m", // pName
    0                           // checkKind
};

static emlrtBCInfo q_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    81,                   // lineNo
    5,                    // colNo
    "RTc1pn",             // aName
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m", // pName
    0                           // checkKind
};

static emlrtBCInfo r_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    129,                  // lineNo
    27,                   // colNo
    "tmp",                // aName
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m", // pName
    0                           // checkKind
};

static emlrtBCInfo s_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    6,               // lineNo
    5,               // colNo
    "RTc1pn",        // aName
    "RTtoTransform", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\RTtoTransform.m", // pName
    0                                   // checkKind
};

static emlrtBCInfo t_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    5,               // lineNo
    5,               // colNo
    "RTc1pn",        // aName
    "RTtoTransform", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\RTtoTransform.m", // pName
    0                                   // checkKind
};

static emlrtBCInfo u_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    4,               // lineNo
    5,               // colNo
    "RTc1pn",        // aName
    "RTtoTransform", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\RTtoTransform.m", // pName
    0                                   // checkKind
};

static emlrtBCInfo v_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    42,                   // lineNo
    5,                    // colNo
    "board_sizes",        // aName
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m", // pName
    0                           // checkKind
};

static emlrtRTEInfo nc_emlrtRTEI{
    22,                   // lineNo
    46,                   // colNo
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m" // pName
};

static emlrtRTEInfo oc_emlrtRTEI{
    18,                   // lineNo
    57,                   // colNo
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m" // pName
};

static emlrtRTEInfo pc_emlrtRTEI{
    23,                   // lineNo
    35,                   // colNo
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m" // pName
};

static emlrtRTEInfo qc_emlrtRTEI{
    33,                   // lineNo
    19,                   // colNo
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m" // pName
};

static emlrtRTEInfo rc_emlrtRTEI{
    41,                   // lineNo
    5,                    // colNo
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m" // pName
};

static emlrtRTEInfo sc_emlrtRTEI{
    50,                   // lineNo
    27,                   // colNo
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m" // pName
};

static emlrtRTEInfo tc_emlrtRTEI{
    51,                   // lineNo
    1,                    // colNo
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m" // pName
};

static emlrtRTEInfo uc_emlrtRTEI{
    70,                   // lineNo
    1,                    // colNo
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m" // pName
};

static emlrtRTEInfo vc_emlrtRTEI{
    297,   // lineNo
    5,     // colNo
    "cat", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" // pName
};

static emlrtRTEInfo wc_emlrtRTEI{
    30,                // lineNo
    21,                // colNo
    "function_handle", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\function_"
    "handle.m" // pName
};

static emlrtRTEInfo xc_emlrtRTEI{
    35,                // lineNo
    13,                // colNo
    "function_handle", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\function_"
    "handle.m" // pName
};

static emlrtRTEInfo yc_emlrtRTEI{
    129,                  // lineNo
    1,                    // colNo
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m" // pName
};

static emlrtRTEInfo ad_emlrtRTEI{
    133,                  // lineNo
    1,                    // colNo
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m" // pName
};

// Function Definitions
namespace Codegen {
void calibrateOneCamera(const emlrtStack *sp,
                        const ::coder::array<uint8_T, 4U> &images,
                        real_T squareSize, const int32_T boardSize[2],
                        struct0_T *calibrationOptimized,
                        real_T *calculation_err, int32_T *err)
{
  coder::anonymous_function b_this;
  ::coder::array<cell_wrap_1, 1U> board_points;
  ::coder::array<cell_wrap_2, 1U> board_sizes;
  ::coder::array<real_T, 3U> RotationMatrices;
  ::coder::array<real_T, 2U> current_board_points;
  ::coder::array<real_T, 2U> jacobian;
  ::coder::array<real_T, 2U> result;
  ::coder::array<real_T, 2U> world_points;
  ::coder::array<real_T, 1U> serialCalib;
  ::coder::array<real_T, 1U> tmp;
  ::coder::array<int32_T, 1U> r;
  ::coder::array<int32_T, 1U> r1;
  ::coder::array<int32_T, 1U> r2;
  ::coder::array<int32_T, 1U> r3;
  ::coder::array<uint8_T, 2U> b_images;
  ::coder::array<boolean_T, 1U> valid_idx;
  ::coder::array<boolean_T, 1U> x;
  c_struct_T CameraParameters;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  struct1_T initialParams;
  real_T b_dv[9];
  real_T b_initialParams[3];
  real_T board_size_detected[2];
  real_T a__1;
  real_T a__2;
  int32_T c_this[2];
  int32_T b_board_points;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T nz;
  int8_T input_sizes_idx_1;
  int8_T sizes_idx_1;
  boolean_T empty_non_axis_sizes;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 0);
  //  Multiple Camera Calibration Toolbox - V1
  //  Laura Ribeiro, Tampere University, Finland
  //  (laura.goncalvesribeiro@tuni.fi)
  //  Step 1
  //  Calibrates each camera independently using Matlab Camera Calibrator
  //  Application Calculates extrinsic parameters between camera N and camera 1
  //  Inputs: directory of calibration images, squareSize, boardSize
  //  Follow the naming convetion for calibration images: PositionXXX_CameraXX
  //  Step 2
  //  Overall Optimization
  //  Options:
  //  Re-estimate all: [1, 1, 1 ,1];
  //  Fixed Intrinsics: [1, 1, 0 ,0];
  //  Fixed lens distortions: [0, 1, 0 ,0];
  //  Default: Fixed intrinsics.
  //  ITER API ALGORITHM IMPLEMENTATION STARTS HERE
  //  Calibrate One Camera
  //  Retrieve useful information
  valid_idx.set_size(&nc_emlrtRTEI, sp, images.size(3));
  nz = images.size(3);
  board_points.set_size(&oc_emlrtRTEI, sp, images.size(3));
  for (i = 0; i < nz; i++) {
    b_board_points = board_points.size(0) - 1;
    if (i > board_points.size(0) - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, board_points.size(0) - 1, &k_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    board_points[i].f1.set_size(&oc_emlrtRTEI, sp, 0,
                                board_points[i].f1.size(1));
    if (i > b_board_points) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_board_points, &k_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    board_points[i].f1.set_size(&oc_emlrtRTEI, sp, board_points[i].f1.size(0),
                                0);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  //  Initalize error flag
  //  Generate world coordinates of the checkerboard keypoints
  st.site = &emlrtRSI;
  coder::generateCheckerboardPoints(&st, boardSize, squareSize, world_points);
  //  REPLACE WITH FOR LOOP OF SINGLE detectCheckerBoardPoints
  //   load("detectCheckerboard_workspace.mat");
  i = images.size(3);
  board_points.set_size(&pc_emlrtRTEI, sp, images.size(3));
  board_sizes.set_size(&pc_emlrtRTEI, sp, images.size(3));
  for (b_i = 0; b_i < i; b_i++) {
    boolean_T exitg1;
    covrtLogFor(&emlrtCoverageInstance, 0, 0, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 1);
    //  perform checkerboards detection in each image
    if (b_i + 1 > images.size(3)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, images.size(3), &i_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    loop_ub = images.size(0);
    b_board_points = images.size(1);
    b_images.set_size(&qc_emlrtRTEI, sp, images.size(0), images.size(1));
    for (i1 = 0; i1 < b_board_points; i1++) {
      for (nz = 0; nz < loop_ub; nz++) {
        b_images[nz + b_images.size(0) * i1] =
            images[(nz + images.size(0) * i1) +
                   images.size(0) * images.size(1) * b_i];
      }
    }
    st.site = &b_emlrtRSI;
    coder::detectCheckerboardPoints(&st, b_images, current_board_points,
                                    board_size_detected);
    //  mark if checkerboards is detected or not
    empty_non_axis_sizes = true;
    nz = 0;
    exitg1 = false;
    while ((!exitg1) && (nz < 2)) {
      if (!(boardSize[nz] == board_size_detected[nz])) {
        empty_non_axis_sizes = false;
        exitg1 = true;
      } else {
        nz++;
      }
    }
    if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 0,
                   covrtLogMcdc(&emlrtCoverageInstance, 0, 0, 0,
                                !covrtLogCond(&emlrtCoverageInstance, 0, 0, 0,
                                              empty_non_axis_sizes)))) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 2);
      if (b_i + 1 > valid_idx.size(0)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, valid_idx.size(0),
                                      &m_emlrtBCI, (emlrtCTX)sp);
      }
      valid_idx[b_i] = false;
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 3);
      if (b_i + 1 > valid_idx.size(0)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, valid_idx.size(0),
                                      &l_emlrtBCI, (emlrtCTX)sp);
      }
      valid_idx[b_i] = true;
    }
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 4);
    loop_ub = current_board_points.size(0) * current_board_points.size(1);
    if (b_i > board_points.size(0) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(0) - 1,
                                    &j_emlrtBCI, (emlrtCTX)sp);
    }
    board_points[b_i].f1.set_size(&rc_emlrtRTEI, sp,
                                  current_board_points.size(0),
                                  board_points[b_i].f1.size(1));
    if (b_i > board_points.size(0) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(0) - 1,
                                    &j_emlrtBCI, (emlrtCTX)sp);
    }
    board_points[b_i].f1.set_size(&rc_emlrtRTEI, sp,
                                  board_points[b_i].f1.size(0),
                                  current_board_points.size(1));
    i1 = board_points.size(0);
    if (b_i > board_points.size(0) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(0) - 1,
                                    &j_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > board_points.size(0) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(0) - 1,
                                    &j_emlrtBCI, (emlrtCTX)sp);
    }
    for (nz = 0; nz < loop_ub; nz++) {
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &o_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      board_points[b_i].f1[nz] = current_board_points[nz];
    }
    nz = board_sizes.size(0) - 1;
    if (b_i > board_sizes.size(0) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, board_sizes.size(0) - 1,
                                    &v_emlrtBCI, (emlrtCTX)sp);
    }
    board_sizes[b_i].f1[0] = board_size_detected[0];
    if (b_i > nz) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, nz, &v_emlrtBCI, (emlrtCTX)sp);
    }
    board_sizes[b_i].f1[1] = board_size_detected[1];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 0, 0, 0, 0);
  st.site = &c_emlrtRSI;
  if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 1,
                 covrtLogMcdc(&emlrtCoverageInstance, 0, 0, 1,
                              !covrtLogCond(&emlrtCoverageInstance, 0, 0, 1,
                                            coder::all(&st, valid_idx))))) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 5);
    // err = "Wrong detection of board size";
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 6);
  st.site = &d_emlrtRSI;
  x.set_size(&sc_emlrtRTEI, &st, valid_idx.size(0));
  loop_ub = valid_idx.size(0);
  for (i = 0; i < loop_ub; i++) {
    x[i] = valid_idx[i];
  }
  b_st.site = &js_emlrtRSI;
  c_st.site = &gn_emlrtRSI;
  nz = coder::combineVectorElements(&c_st, x);
  if (0 > board_points.size(0) - 1) {
    emlrtDynamicBoundsCheckR2012b(0, 0, board_points.size(0) - 1, &c_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  b_this.workspace.calibration.ImagePoints.set_size(
      &tc_emlrtRTEI, sp, board_points[0].f1.size(0), board_points[0].f1.size(1),
      nz);
  loop_ub = board_points[0].f1.size(0) * board_points[0].f1.size(1) * nz;
  for (i = 0; i < loop_ub; i++) {
    b_this.workspace.calibration.ImagePoints[i] = 0.0;
  }
  for (b_i = 0; b_i < nz; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 0, 0, 1, 1);
    if ((static_cast<int32_T>(b_i + 1U) < 1) ||
        (static_cast<int32_T>(b_i + 1U) > valid_idx.size(0))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i + 1U), 1,
                                    valid_idx.size(0), &n_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 2, valid_idx[b_i])) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 7);
      if ((b_i + 1 < 1) ||
          (b_i + 1 > b_this.workspace.calibration.ImagePoints.size(2))) {
        emlrtDynamicBoundsCheckR2012b(
            b_i + 1, 1, b_this.workspace.calibration.ImagePoints.size(2),
            &h_emlrtBCI, (emlrtCTX)sp);
      }
      if (b_i > board_points.size(0) - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(0) - 1,
                                      &b_emlrtBCI, (emlrtCTX)sp);
      }
      c_this[0] = b_this.workspace.calibration.ImagePoints.size(0);
      c_this[1] = b_this.workspace.calibration.ImagePoints.size(1);
      emlrtSubAssignSizeCheckR2012b(&c_this[0], 2, board_points[b_i].f1.size(),
                                    2, &emlrtECI, (emlrtCTX)sp);
      loop_ub = board_points[b_i].f1.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_board_points = board_points[b_i].f1.size(0);
        for (i1 = 0; i1 < b_board_points; i1++) {
          b_this.workspace.calibration.ImagePoints
              [(i1 + b_this.workspace.calibration.ImagePoints.size(0) * i) +
               b_this.workspace.calibration.ImagePoints.size(0) *
                   b_this.workspace.calibration.ImagePoints.size(1) * b_i] =
              board_points[b_i].f1[i1 + board_points[b_i].f1.size(0) * i];
        }
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 0, 0, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 8);
  //  Estimate without using estimateCameraParameters
  // If want different values of EstimateSkew, EstimateTangentialDistortion,
  // NumRadialDistortionCoefficients unserializeCalib fuction needs be changed
  board_size_detected[0] = static_cast<uint32_T>(images.size(0));
  board_size_detected[1] = static_cast<uint32_T>(images.size(1));
  st.site = &e_emlrtRSI;
  computeInitialParameterEstimate(
      &st, world_points, b_this.workspace.calibration.ImagePoints,
      board_size_detected, &initialParams, valid_idx, err);
  covrtLogIf(&emlrtCoverageInstance, 0, 0, 3, *err != 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 9);
  //  Convert Extrinsics to my way
  RotationMatrices.set_size(&uc_emlrtRTEI, sp, 3, 3,
                            b_this.workspace.calibration.ImagePoints.size(2));
  loop_ub = 9 * b_this.workspace.calibration.ImagePoints.size(2);
  for (i = 0; i < loop_ub; i++) {
    RotationMatrices[i] = 0.0;
  }
  i = b_this.workspace.calibration.ImagePoints.size(2);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 0, 0, 2, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 10);
    if (b_i + 1 > initialParams.RotationVectors.size(0)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                                    initialParams.RotationVectors.size(0),
                                    &g_emlrtBCI, (emlrtCTX)sp);
    }
    b_initialParams[0] = initialParams.RotationVectors[b_i];
    b_initialParams[1] =
        initialParams
            .RotationVectors[b_i + initialParams.RotationVectors.size(0)];
    b_initialParams[2] =
        initialParams
            .RotationVectors[b_i + initialParams.RotationVectors.size(0) * 2];
    coder::vision::internal::calibration::rodriguesVectorToMatrix(
        b_initialParams, b_dv);
    if (b_i + 1 > RotationMatrices.size(2)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, RotationMatrices.size(2),
                                    &f_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < 3; i1++) {
      RotationMatrices[3 * i1 + 9 * b_i] = b_dv[i1];
      RotationMatrices[(3 * i1 + 9 * b_i) + 1] = b_dv[i1 + 3];
      RotationMatrices[(3 * i1 + 9 * b_i) + 2] = b_dv[i1 + 6];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 0, 0, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 11);
  nz = valid_idx.size(0);
  for (b_i = 0; b_i < nz; b_i++) {
    if (valid_idx[b_i] && (b_i + 1 > RotationMatrices.size(2))) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, RotationMatrices.size(2),
                                    &emlrtBCI, (emlrtCTX)sp);
    }
  }
  nz = valid_idx.size(0) - 1;
  b_board_points = 0;
  for (b_i = 0; b_i <= nz; b_i++) {
    if (valid_idx[b_i]) {
      b_board_points++;
    }
  }
  r.set_size(&oc_emlrtRTEI, sp, b_board_points);
  b_board_points = 0;
  for (b_i = 0; b_i <= nz; b_i++) {
    if (valid_idx[b_i]) {
      r[b_board_points] = b_i + 1;
      b_board_points++;
    }
  }
  loop_ub = r.size(0);
  for (i = 0; i < loop_ub; i++) {
    if (r[i] > initialParams.TranslationVectors.size(0)) {
      emlrtDynamicBoundsCheckR2012b(r[i], 1,
                                    initialParams.TranslationVectors.size(0),
                                    &p_emlrtBCI, (emlrtCTX)sp);
    }
  }
  nz = valid_idx.size(0) - 1;
  b_board_points = 0;
  for (b_i = 0; b_i <= nz; b_i++) {
    if (valid_idx[b_i]) {
      b_board_points++;
    }
  }
  r1.set_size(&oc_emlrtRTEI, sp, b_board_points);
  b_board_points = 0;
  for (b_i = 0; b_i <= nz; b_i++) {
    if (valid_idx[b_i]) {
      r1[b_board_points] = b_i + 1;
      b_board_points++;
    }
  }
  b_this.workspace.calibration.PatternPositions.set_size(&oc_emlrtRTEI, sp, 1,
                                                         r1.size(0));
  nz = valid_idx.size(0) - 1;
  b_board_points = 0;
  for (b_i = 0; b_i <= nz; b_i++) {
    if (valid_idx[b_i]) {
      b_board_points++;
    }
  }
  r2.set_size(&oc_emlrtRTEI, sp, b_board_points);
  b_board_points = 0;
  for (b_i = 0; b_i <= nz; b_i++) {
    if (valid_idx[b_i]) {
      r2[b_board_points] = b_i + 1;
      b_board_points++;
    }
  }
  i = r2.size(0);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 0, 0, 3, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 12);
    nz = valid_idx.size(0) - 1;
    b_board_points = 0;
    for (loop_ub = 0; loop_ub <= nz; loop_ub++) {
      if (valid_idx[loop_ub]) {
        b_board_points++;
      }
    }
    r3.set_size(&oc_emlrtRTEI, sp, b_board_points);
    b_board_points = 0;
    for (loop_ub = 0; loop_ub <= nz; loop_ub++) {
      if (valid_idx[loop_ub]) {
        r3[b_board_points] = loop_ub + 1;
        b_board_points++;
      }
    }
    st.site = &f_emlrtRSI;
    if (b_i + 1 > r3.size(0)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, r3.size(0), &e_emlrtBCI, &st);
    }
    if (b_i + 1 > r3.size(0)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, r3.size(0), &d_emlrtBCI, &st);
    }
    covrtLogFcn(&emlrtCoverageInstance, 2, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 0);
    //  Before applying transform all R's coming from outside Matlab
    b_board_points = b_this.workspace.calibration.PatternPositions.size(1) - 1;
    for (i1 = 0; i1 < 16; i1++) {
      if (b_i > b_board_points) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_board_points, &q_emlrtBCI, &st);
      }
      b_this.workspace.calibration.PatternPositions[b_i].f1[i1] = 0.0;
    }
    b_board_points = b_this.workspace.calibration.PatternPositions.size(1) - 1;
    for (i1 = 0; i1 < 3; i1++) {
      if (b_i > b_board_points) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_board_points, &u_emlrtBCI, &st);
      }
      nz = i1 << 2;
      b_this.workspace.calibration.PatternPositions[b_i].f1[nz] =
          RotationMatrices[3 * i1 + 9 * (r3[b_i] - 1)];
      if (b_i > b_board_points) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_board_points, &u_emlrtBCI, &st);
      }
      b_this.workspace.calibration.PatternPositions[b_i].f1[nz + 1] =
          RotationMatrices[(3 * i1 + 9 * (r3[b_i] - 1)) + 1];
      if (b_i > b_board_points) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_board_points, &u_emlrtBCI, &st);
      }
      b_this.workspace.calibration.PatternPositions[b_i].f1[nz + 2] =
          RotationMatrices[(3 * i1 + 9 * (r3[b_i] - 1)) + 2];
    }
    b_board_points = b_this.workspace.calibration.PatternPositions.size(1) - 1;
    if (b_i > b_this.workspace.calibration.PatternPositions.size(1) - 1) {
      emlrtDynamicBoundsCheckR2012b(
          b_i, 0, b_this.workspace.calibration.PatternPositions.size(1) - 1,
          &t_emlrtBCI, &st);
    }
    b_this.workspace.calibration.PatternPositions[b_i].f1[3] =
        initialParams.TranslationVectors[r3[b_i] - 1];
    if (b_i > b_board_points) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, b_board_points, &t_emlrtBCI, &st);
    }
    b_this.workspace.calibration.PatternPositions[b_i].f1[7] =
        initialParams.TranslationVectors
            [(r3[b_i] + initialParams.TranslationVectors.size(0)) - 1];
    if (b_i > b_board_points) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, b_board_points, &t_emlrtBCI, &st);
    }
    b_this.workspace.calibration.PatternPositions[b_i].f1[11] =
        initialParams.TranslationVectors
            [(r3[b_i] + initialParams.TranslationVectors.size(0) * 2) - 1];
    b_board_points = b_this.workspace.calibration.PatternPositions.size(1) - 1;
    if (b_i > b_this.workspace.calibration.PatternPositions.size(1) - 1) {
      emlrtDynamicBoundsCheckR2012b(
          b_i, 0, b_this.workspace.calibration.PatternPositions.size(1) - 1,
          &s_emlrtBCI, &st);
    }
    b_this.workspace.calibration.PatternPositions[b_i].f1[12] = 0.0;
    if (b_i > b_board_points) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, b_board_points, &s_emlrtBCI, &st);
    }
    b_this.workspace.calibration.PatternPositions[b_i].f1[13] = 0.0;
    if (b_i > b_board_points) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, b_board_points, &s_emlrtBCI, &st);
    }
    b_this.workspace.calibration.PatternPositions[b_i].f1[14] = 0.0;
    if (b_i > b_board_points) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, b_board_points, &s_emlrtBCI, &st);
    }
    b_this.workspace.calibration.PatternPositions[b_i].f1[15] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 0, 0, 3, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 13);
  //  Crete Calibration Struct
  //  Minimization options
  //  Default options give better outcome
  //  minimization_options=optimset('LargeScale','on',...
  //      'Algorithm','levenberg-marquardt',...
  //      'TolFun',1e-10,...
  //      'Display','on',...
  //      'TolX',1e-10,...
  //      'MaxFunEvals',200000,...
  //      'MaxIter',10000,...
  //      'UseParallel', false);
  //  Optimization options: fixedK, fixedDistortions, fixedRTpnc1
  // World and Image Points
  st.site = &g_emlrtRSI;
  b_st.site = &vx_emlrtRSI;
  if (world_points.size(0) != 0) {
    nz = world_points.size(0);
  } else {
    nz = 0;
  }
  c_st.site = &cn_emlrtRSI;
  if ((world_points.size(0) != nz) && (world_points.size(0) != 0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  if ((world_points.size(0) != nz) && (world_points.size(0) != 0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  empty_non_axis_sizes = (nz == 0);
  if (empty_non_axis_sizes || (world_points.size(0) != 0)) {
    input_sizes_idx_1 = 2;
  } else {
    input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes || (world_points.size(0) != 0)) {
    sizes_idx_1 = 1;
  } else {
    sizes_idx_1 = 0;
  }
  result.set_size(&vc_emlrtRTEI, &b_st, nz, input_sizes_idx_1 + sizes_idx_1);
  loop_ub = input_sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < nz; i1++) {
      result[i1 + result.size(0) * i] = world_points[i1 + nz * i];
    }
  }
  loop_ub = sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < nz; i1++) {
      result[i1 + result.size(0) * input_sizes_idx_1] = 1.0;
    }
  }
  //  Convert initial estimate
  st.site = &h_emlrtRSI;
  serializeCalib(
      &st, initialParams.RadialDistortion, initialParams.TangentialDistortion,
      initialParams.EstimateSkew, initialParams.NumRadialDistortionCoefficients,
      initialParams.EstimateTangentialDistortion, initialParams.IntrinsicMatrix,
      b_this.workspace.calibration.PatternPositions, serialCalib);
  // [calibrationConverted] = unserializeCalib(serialCalib, options,
  // calibration);
  // {
  // errorInitial = CalculateCost(serialCalib, options, calibration, genPoints,
  // detPoints); tmp = errorInitial; tmp(tmp<0.000001)=NaN; MREi =
  // mean(tmp(~isnan(tmp(:)))); disp (['Mean Reprojection Error - Before
  // Optimization: ', num2str(MREi)]);
  // }
  //  Optimization
  // h = waitbar(0, 'Running global Optimization...','Name', 'Global
  // Optimization');
  b_this.workspace.calibration.CameraParameters.RadialDistortion[0] =
      initialParams.RadialDistortion[0];
  b_this.workspace.calibration.CameraParameters.RadialDistortion[1] =
      initialParams.RadialDistortion[1];
  b_this.workspace.calibration.CameraParameters.RadialDistortion[2] =
      initialParams.RadialDistortion[2];
  b_this.workspace.calibration.CameraParameters.TangentialDistortion[0] =
      initialParams.TangentialDistortion[0];
  b_this.workspace.calibration.CameraParameters.ImageSize[0] =
      initialParams.ImageSize[0];
  b_this.workspace.calibration.CameraParameters.TangentialDistortion[1] =
      initialParams.TangentialDistortion[1];
  b_this.workspace.calibration.CameraParameters.ImageSize[1] =
      initialParams.ImageSize[1];
  b_this.workspace.calibration.CameraParameters.WorldPoints.set_size(
      &wc_emlrtRTEI, sp, initialParams.WorldPoints.size(0), 2);
  loop_ub = initialParams.WorldPoints.size(0) * 2;
  for (i = 0; i < loop_ub; i++) {
    b_this.workspace.calibration.CameraParameters.WorldPoints[i] =
        initialParams.WorldPoints[i];
  }
  b_this.workspace.calibration.CameraParameters.WorldUnits.size[0] = 1;
  b_this.workspace.calibration.CameraParameters.WorldUnits.size[1] =
      initialParams.WorldUnits.size[1];
  loop_ub = initialParams.WorldUnits.size[1];
  if (0 <= loop_ub - 1) {
    std::copy(
        &initialParams.WorldUnits.data[0],
        &initialParams.WorldUnits.data[loop_ub],
        &b_this.workspace.calibration.CameraParameters.WorldUnits.data[0]);
  }
  b_this.workspace.calibration.CameraParameters.EstimateSkew =
      initialParams.EstimateSkew;
  b_this.workspace.calibration.CameraParameters
      .NumRadialDistortionCoefficients =
      initialParams.NumRadialDistortionCoefficients;
  b_this.workspace.calibration.CameraParameters.EstimateTangentialDistortion =
      initialParams.EstimateTangentialDistortion;
  b_this.workspace.calibration.CameraParameters.RotationVectors.set_size(
      &wc_emlrtRTEI, sp, initialParams.RotationVectors.size(0), 3);
  loop_ub = initialParams.RotationVectors.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    b_this.workspace.calibration.CameraParameters.RotationVectors[i] =
        initialParams.RotationVectors[i];
  }
  b_this.workspace.calibration.CameraParameters.TranslationVectors.set_size(
      &wc_emlrtRTEI, sp, initialParams.TranslationVectors.size(0), 3);
  loop_ub = initialParams.TranslationVectors.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    b_this.workspace.calibration.CameraParameters.TranslationVectors[i] =
        initialParams.TranslationVectors[i];
  }
  std::copy(&initialParams.IntrinsicMatrix[0],
            &initialParams.IntrinsicMatrix[9],
            &b_this.workspace.calibration.CameraParameters.IntrinsicMatrix[0]);
  b_this.workspace.genPoints.set_size(&xc_emlrtRTEI, sp, result.size(0),
                                      result.size(1));
  loop_ub = result.size(0) * result.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_this.workspace.genPoints[i] = result[i];
  }
  b_this.workspace.detPoints.set_size(
      &xc_emlrtRTEI, sp, b_this.workspace.calibration.ImagePoints.size(0),
      b_this.workspace.calibration.ImagePoints.size(1),
      b_this.workspace.calibration.ImagePoints.size(2));
  loop_ub = b_this.workspace.calibration.ImagePoints.size(0) *
            b_this.workspace.calibration.ImagePoints.size(1) *
            b_this.workspace.calibration.ImagePoints.size(2);
  for (i = 0; i < loop_ub; i++) {
    b_this.workspace.detPoints[i] = b_this.workspace.calibration.ImagePoints[i];
  }
  st.site = &i_emlrtRSI;
  coder::lsqnonlin(&st, &b_this, serialCalib, &a__1,
                   calibrationOptimized->Error, &a__2, jacobian);
  // delete(h);
  // serialCI = nlparci(optimizedSerialCalib,residual,'jacobian',jacobian);
  // serialCI = my_nlparci(optimizedSerialCalib,residual,jacobian);
  // CI = cell(1,2);
  // CI{1} = unserializeCalib(serialCI(:,1)', options, calibration);
  // CI{2} = unserializeCalib(serialCI(:,2)', options, calibration);
  st.site = &j_emlrtRSI;
  CalculateCost(&st, serialCalib, initialParams.ImageSize,
                b_this.workspace.calibration.PatternPositions, result,
                b_this.workspace.calibration.ImagePoints,
                calibrationOptimized->Error);
  tmp.set_size(&yc_emlrtRTEI, sp, calibrationOptimized->Error.size(0));
  loop_ub = calibrationOptimized->Error.size(0);
  for (i = 0; i < loop_ub; i++) {
    tmp[i] = calibrationOptimized->Error[i];
  }
  nz = calibrationOptimized->Error.size(0);
  for (b_i = 0; b_i < nz; b_i++) {
    if (calibrationOptimized->Error[b_i] < 1.0E-6) {
      if (b_i + 1 > calibrationOptimized->Error.size(0)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                                      calibrationOptimized->Error.size(0),
                                      &r_emlrtBCI, (emlrtCTX)sp);
      }
      tmp[b_i] = rtNaN;
    }
  }
  st.site = &k_emlrtRSI;
  *calculation_err = coder::nanmean(&st, tmp);
  // disp (['Mean Reprojection Error - After Optimization: ', num2str(MREf)]);
  st.site = &l_emlrtRSI;
  unserializeCalib(&st, serialCalib, initialParams.ImageSize,
                   b_this.workspace.calibration.PatternPositions,
                   &CameraParameters, calibrationOptimized->PatternPositions);
  calibrationOptimized->ImagePoints.set_size(
      &ad_emlrtRTEI, sp, b_this.workspace.calibration.ImagePoints.size(0),
      b_this.workspace.calibration.ImagePoints.size(1),
      b_this.workspace.calibration.ImagePoints.size(2));
  loop_ub = b_this.workspace.calibration.ImagePoints.size(0) *
            b_this.workspace.calibration.ImagePoints.size(1) *
            b_this.workspace.calibration.ImagePoints.size(2);
  for (i = 0; i < loop_ub; i++) {
    calibrationOptimized->ImagePoints[i] =
        b_this.workspace.calibration.ImagePoints[i];
  }
  // calibrationOptimized.OptimizationOptions = options;
  // calibrationOptimized.Jacobian = jacobian;
  // calibrationOptimized.CI = CI;
  calibrationOptimized->CameraParameters.RadialDistortion[0] =
      CameraParameters.RadialDistortion[0];
  calibrationOptimized->CameraParameters.RadialDistortion[1] =
      CameraParameters.RadialDistortion[1];
  calibrationOptimized->CameraParameters.RadialDistortion[2] =
      CameraParameters.RadialDistortion[2];
  calibrationOptimized->CameraParameters.WorldPoints.set_size(&bd_emlrtRTEI, sp,
                                                              0, 2);
  calibrationOptimized->CameraParameters.WorldUnits.size[0] = 1;
  calibrationOptimized->CameraParameters.WorldUnits.size[1] = 2;
  calibrationOptimized->CameraParameters.TangentialDistortion[0] =
      CameraParameters.TangentialDistortion[0];
  calibrationOptimized->CameraParameters.ImageSize[0] =
      CameraParameters.ImageSize[0];
  calibrationOptimized->CameraParameters.WorldUnits.data[0] =
      CameraParameters.WorldUnits[0];
  calibrationOptimized->CameraParameters.TangentialDistortion[1] =
      CameraParameters.TangentialDistortion[1];
  calibrationOptimized->CameraParameters.ImageSize[1] =
      CameraParameters.ImageSize[1];
  calibrationOptimized->CameraParameters.WorldUnits.data[1] =
      CameraParameters.WorldUnits[1];
  calibrationOptimized->CameraParameters.EstimateSkew =
      CameraParameters.EstimateSkew;
  calibrationOptimized->CameraParameters.NumRadialDistortionCoefficients =
      CameraParameters.NumRadialDistortionCoefficients;
  calibrationOptimized->CameraParameters.EstimateTangentialDistortion =
      CameraParameters.EstimateTangentialDistortion;
  calibrationOptimized->CameraParameters.RotationVectors.set_size(&bd_emlrtRTEI,
                                                                  sp, 0, 3);
  calibrationOptimized->CameraParameters.TranslationVectors.set_size(
      &bd_emlrtRTEI, sp, 0, 3);
  std::copy(&CameraParameters.IntrinsicMatrix[0],
            &CameraParameters.IntrinsicMatrix[9],
            &calibrationOptimized->CameraParameters.IntrinsicMatrix[0]);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void calibrateOneCamera_anonFcn1(
    const emlrtStack *sp, const real_T c_calibration_CameraParameters_[2],
    const ::coder::array<cell_wrap_0, 2U> &calibration_PatternPositions,
    const ::coder::array<real_T, 2U> &genPoints,
    const ::coder::array<real_T, 3U> &detPoints,
    const ::coder::array<real_T, 1U> &x,
    ::coder::array<real_T, 1U> &varargout_1)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  covrtLogFcn(&emlrtCoverageInstance, 0, 1);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 14);
  st.site = &py_emlrtRSI;
  CalculateCost(&st, x, c_calibration_CameraParameters_,
                calibration_PatternPositions, genPoints, detPoints,
                varargout_1);
}

emlrtCTX emlrtGetRootTLSGlobal()
{
  return emlrtRootTLSGlobal;
}

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData)
{
  omp_set_lock(&emlrtLockGlobal);
  emlrtCallLockeeFunction(aLockee, aTLS, aData);
  omp_unset_lock(&emlrtLockGlobal);
}

} // namespace Codegen

// End of code generation (calibrateOneCamera.cpp)
