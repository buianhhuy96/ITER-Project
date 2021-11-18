//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// calibrateCamera.cpp
//
// Code generation for function 'calibrateCamera'
//

// Include files
#include "calibrateCamera.h"
#include "CalculateCost.h"
#include "anonymous_function1.h"
#include "calibrateCamera_data.h"
#include "calibrateCamera_internal_types11.h"
#include "calibrateCamera_internal_types2.h"
#include "calibrateCamera_types.h"
#include "computeInitialParameterEstimate.h"
#include "detectMyCheckerboard.h"
#include "generateCheckerboardPoints.h"
#include "lsqnonlin.h"
#include "mean.h"
#include "nanmean.h"
#include "rt_nonfinite.h"
#include "serializeCalib.h"
#include "unserializeCalib.h"
#include "coder_array.h"
#include "libmwrgb2gray_tbb.h"
#include "mwmathutil.h"
#include <algorithm>

// Variable Definitions
static emlrtRSInfo emlrtRSI{
    21,                // lineNo
    "calibrateCamera", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m" // pathName
};

static emlrtRSInfo b_emlrtRSI{
    23,                // lineNo
    "calibrateCamera", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m" // pathName
};

static emlrtRSInfo c_emlrtRSI{
    31,                // lineNo
    "calibrateCamera", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m" // pathName
};

static emlrtRSInfo d_emlrtRSI{
    39,                // lineNo
    "calibrateCamera", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m" // pathName
};

static emlrtRSInfo e_emlrtRSI{
    47,                // lineNo
    "calibrateCamera", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m" // pathName
};

static emlrtRSInfo f_emlrtRSI{
    67,                // lineNo
    "calibrateCamera", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m" // pathName
};

static emlrtRSInfo g_emlrtRSI{
    70,                // lineNo
    "calibrateCamera", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m" // pathName
};

static emlrtRSInfo h_emlrtRSI{
    73,                // lineNo
    "calibrateCamera", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m" // pathName
};

static emlrtRSInfo i_emlrtRSI{
    75,                // lineNo
    "calibrateCamera", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m" // pathName
};

static emlrtRSInfo j_emlrtRSI{
    82,                // lineNo
    "calibrateCamera", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m" // pathName
};

static emlrtRSInfo k_emlrtRSI{
    92,                // lineNo
    "calibrateCamera", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m" // pathName
};

static emlrtRSInfo l_emlrtRSI{
    93,                // lineNo
    "calibrateCamera", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m" // pathName
};

static emlrtRSInfo m_emlrtRSI{
    96,                // lineNo
    "calibrateCamera", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m" // pathName
};

static emlrtRSInfo n_emlrtRSI{
    7,                  // lineNo
    "preprocessImages", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\preprocessImages.m" // pathName
};

static emlrtECInfo emlrtECI{
    -1,              // nDims
    4,               // lineNo
    5,               // colNo
    "RTtoTransform", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\RTtoTransform.m" // pName
};

static emlrtECInfo b_emlrtECI{
    -1,                 // nDims
    9,                  // lineNo
    8,                  // colNo
    "preprocessImages", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\preprocessImages.m" // pName
};

static emlrtBCInfo emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    9,                  // lineNo
    26,                 // colNo
    "gray_images",      // aName
    "preprocessImages", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\preprocessImages.m", // pName
    0                         // checkKind
};

static emlrtECInfo c_emlrtECI{
    -1,                 // nDims
    7,                  // lineNo
    8,                  // colNo
    "preprocessImages", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\preprocessImages.m" // pName
};

static emlrtBCInfo b_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    7,                  // lineNo
    26,                 // colNo
    "gray_images",      // aName
    "preprocessImages", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\preprocessImages.m", // pName
    0                         // checkKind
};

static emlrtBCInfo c_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    9,                  // lineNo
    42,                 // colNo
    "images",           // aName
    "preprocessImages", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\preprocessImages.m", // pName
    0                         // checkKind
};

static emlrtBCInfo d_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    7,                  // lineNo
    51,                 // colNo
    "images",           // aName
    "preprocessImages", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\preprocessImages.m", // pName
    0                         // checkKind
};

static emlrtBCInfo e_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    47,                // lineNo
    50,                // colNo
    "tempt",           // aName
    "calibrateCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m", // pName
    0                        // checkKind
};

static emlrtBCInfo f_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    47,                // lineNo
    41,                // colNo
    "tempR",           // aName
    "calibrateCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m", // pName
    0                        // checkKind
};

static emlrtBCInfo g_emlrtBCI{
    -1,                               // iFirst
    -1,                               // iLast
    43,                               // lineNo
    43,                               // colNo
    "initialParams.RotationMatrices", // aName
    "calibrateCamera",                // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m", // pName
    0                        // checkKind
};

static emlrtBCInfo h_emlrtBCI{
    -1,                                 // iFirst
    -1,                                 // iLast
    44,                                 // lineNo
    41,                                 // colNo
    "initialParams.TranslationVectors", // aName
    "calibrateCamera",                  // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m", // pName
    0                        // checkKind
};

static emlrtBCInfo i_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    47,                // lineNo
    5,                 // colNo
    "RTc1pn",          // aName
    "calibrateCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m", // pName
    0                        // checkKind
};

static emlrtBCInfo j_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    74,                // lineNo
    25,                // colNo
    "tmp",             // aName
    "calibrateCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m", // pName
    0                        // checkKind
};

static emlrtBCInfo k_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    75,                // lineNo
    17,                // colNo
    "tmp",             // aName
    "calibrateCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m", // pName
    0                        // checkKind
};

static emlrtBCInfo l_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    93,                // lineNo
    27,                // colNo
    "tmp",             // aName
    "calibrateCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m", // pName
    0                        // checkKind
};

static emlrtBCInfo m_emlrtBCI{
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

static emlrtBCInfo n_emlrtBCI{
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

static emlrtBCInfo o_emlrtBCI{
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

static emlrtRTEInfo jc_emlrtRTEI{
    21,                // lineNo
    1,                 // colNo
    "calibrateCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m" // pName
};

static emlrtRTEInfo kc_emlrtRTEI{
    9,                  // lineNo
    29,                 // colNo
    "preprocessImages", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\preprocessImages.m" // pName
};

static emlrtRTEInfo lc_emlrtRTEI{
    7,                  // lineNo
    38,                 // colNo
    "preprocessImages", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\preprocessImages.m" // pName
};

static emlrtRTEInfo mc_emlrtRTEI{
    43,         // lineNo
    24,         // colNo
    "rgb2gray", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\images\\rgb2gray.m" // pName
};

static emlrtRTEInfo nc_emlrtRTEI{
    18,                // lineNo
    40,                // colNo
    "calibrateCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m" // pName
};

static emlrtRTEInfo oc_emlrtRTEI{
    297,   // lineNo
    5,     // colNo
    "cat", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" // pName
};

static emlrtRTEInfo pc_emlrtRTEI{
    73,                // lineNo
    16,                // colNo
    "calibrateCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m" // pName
};

static emlrtRTEInfo qc_emlrtRTEI{
    74,                // lineNo
    1,                 // colNo
    "calibrateCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m" // pName
};

static emlrtRTEInfo sc_emlrtRTEI{
    75,                // lineNo
    13,                // colNo
    "calibrateCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m" // pName
};

static emlrtRTEInfo tc_emlrtRTEI{
    30,                // lineNo
    21,                // colNo
    "function_handle", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\function_"
    "handle.m" // pName
};

static emlrtRTEInfo uc_emlrtRTEI{
    35,                // lineNo
    13,                // colNo
    "function_handle", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\function_"
    "handle.m" // pName
};

static emlrtRTEInfo vc_emlrtRTEI{
    92,                // lineNo
    18,                // colNo
    "calibrateCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m" // pName
};

static emlrtRTEInfo wc_emlrtRTEI{
    93,                // lineNo
    1,                 // colNo
    "calibrateCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m" // pName
};

static emlrtRTEInfo xc_emlrtRTEI{
    96,                // lineNo
    26,                // colNo
    "calibrateCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateCamera.m" // pName
};

// Function Definitions
namespace Codegen {
void calibrateCamera(const emlrtStack *sp,
                     const ::coder::array<uint8_T, 4U> &images,
                     real_T squareSize, const real_T boardSize[2],
                     struct0_T *calibrationOptimized, int8_T *err)
{
  coder::anonymous_function b_this;
  ::coder::array<real_T, 2U> b_result;
  ::coder::array<real_T, 2U> jacobian;
  ::coder::array<real_T, 2U> world_points;
  ::coder::array<real_T, 1U> b_tmp;
  ::coder::array<real_T, 1U> serialCalib;
  ::coder::array<real_T, 1U> tmp;
  ::coder::array<int32_T, 1U> r1;
  ::coder::array<int32_T, 1U> r2;
  ::coder::array<int32_T, 1U> r3;
  ::coder::array<int32_T, 1U> r4;
  ::coder::array<int32_T, 1U> r5;
  ::coder::array<int32_T, 1U> r6;
  ::coder::array<uint8_T, 4U> gray_images;
  ::coder::array<uint8_T, 3U> b_X;
  ::coder::array<uint8_T, 3U> b_images;
  ::coder::array<uint8_T, 2U> r;
  ::coder::array<boolean_T, 1U> imagesUsed;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  struct1_T b_expl_temp;
  struct1_T c_expl_temp;
  struct1_T expl_temp;
  struct1_T initialParams;
  real_T b_boardSize[2];
  real_T a__1;
  real_T a__2;
  int32_T iv[3];
  int32_T c_gray_images[2];
  int32_T result[2];
  int32_T b_gray_images;
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T end;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
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
  //  Initalize error flag
  st.site = &emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1, 0);
  gray_images.set_size(&jc_emlrtRTEI, &st, images.size(0), images.size(1), 1,
                       images.size(3));
  loop_ub = images.size(0) * images.size(1) * images.size(3);
  for (i = 0; i < loop_ub; i++) {
    gray_images[i] = 0U;
  }
  i = images.size(3);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 1, 0, 0, 1);
    //  If gray images, convert to RGB
    loop_ub = images.size(2);
    if (covrtLogIf(&emlrtCoverageInstance, 1, 0, 0, images.size(2) == 3)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 1, 1);
      if (b_i + 1 > gray_images.size(3)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, gray_images.size(3),
                                      &b_emlrtBCI, &st);
      }
      b_st.site = &n_emlrtRSI;
      if (b_i + 1 > images.size(3)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, images.size(3), &d_emlrtBCI,
                                      &b_st);
      }
      loop_ub = images.size(0);
      b_loop_ub = images.size(1);
      b_X.set_size(&lc_emlrtRTEI, &b_st, images.size(0), images.size(1), 3);
      for (i1 = 0; i1 < 3; i1++) {
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          for (int32_T i3{0}; i3 < loop_ub; i3++) {
            b_X[(i3 + b_X.size(0) * i2) + b_X.size(0) * b_X.size(1) * i1] =
                images[((i3 + images.size(0) * i2) +
                        images.size(0) * images.size(1) * i1) +
                       images.size(0) * images.size(1) * images.size(2) * b_i];
          }
        }
      }
      r.set_size(&mc_emlrtRTEI, &b_st, images.size(0), images.size(1));
      rgb2gray_tbb_uint8(&b_X[0],
                         static_cast<real_T>(images.size(0)) *
                             static_cast<real_T>(images.size(1)),
                         &r[0], true);
      c_gray_images[0] = gray_images.size(0);
      c_gray_images[1] = gray_images.size(1);
      emlrtSubAssignSizeCheckR2012b(&c_gray_images[0], 2, r.size(), 2,
                                    &c_emlrtECI, &st);
      loop_ub = r.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_loop_ub = r.size(0);
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          gray_images[(i2 + gray_images.size(0) * i1) +
                      gray_images.size(0) * gray_images.size(1) * b_i] =
              r[i2 + r.size(0) * i1];
        }
      }
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 1, 2);
      if (b_i + 1 > gray_images.size(3)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, gray_images.size(3),
                                      &emlrtBCI, &st);
      }
      if (b_i + 1 > images.size(3)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, images.size(3), &c_emlrtBCI,
                                      &st);
      }
      b_loop_ub = images.size(0);
      c_loop_ub = images.size(1);
      b_gray_images = gray_images.size(0);
      c_gray_images[0] = gray_images.size(0);
      c_gray_images[1] = gray_images.size(1);
      iv[0] = images.size(0);
      iv[1] = images.size(1);
      iv[2] = images.size(2);
      emlrtSubAssignSizeCheckR2012b(&c_gray_images[0], 2, &iv[0], 3,
                                    &b_emlrtECI, &st);
      b_images.set_size(&kc_emlrtRTEI, &st, images.size(0), images.size(1),
                        images.size(2));
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (i2 = 0; i2 < c_loop_ub; i2++) {
          for (int32_T i3{0}; i3 < b_loop_ub; i3++) {
            b_images[(i3 + b_images.size(0) * i2) +
                     b_images.size(0) * b_images.size(1) * i1] =
                images[((i3 + images.size(0) * i2) +
                        images.size(0) * images.size(1) * i1) +
                       images.size(0) * images.size(1) * images.size(2) * b_i];
          }
        }
      }
      c_gray_images[0] = gray_images.size(0);
      c_gray_images[1] = gray_images.size(1);
      loop_ub = gray_images.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (i2 = 0; i2 < b_gray_images; i2++) {
          gray_images[(i2 + gray_images.size(0) * i1) +
                      gray_images.size(0) * gray_images.size(1) * b_i] =
              b_images[i2 + c_gray_images[0] * i1];
        }
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 1, 0, 0, 0);
  //  Generate world coordinates of the checkerboard keypoints
  b_boardSize[0] = boardSize[0];
  b_boardSize[1] = boardSize[1];
  st.site = &b_emlrtRSI;
  coder::generateCheckerboardPoints(&st, b_boardSize, squareSize, world_points);
  //  REPLACE WITH FOR LOOP OF SINGLE detectCheckerBoardPoints
  // [ImagePoints, boardSizeDetected ] = detectCheckerboardPoints(images,
  // 'PartialDetections', false); % detect checkerboard for every position of
  // camera i flag = false; if (flag)
  //   load("detectCheckerboard_workspace.mat");
  // else
  st.site = &c_emlrtRSI;
  detectMyCheckerboard(&st, gray_images, boardSize,
                       b_this.workspace.calibration.ImagePoints);
  // end
  //  Estimate without using estimateCameraParameters
  // If want different values of EstimateSkew, EstimateTangentialDistortion,
  // NumRadialDistortionCoefficients unserializeCalib fuction needs be changed
  st.site = &d_emlrtRSI;
  computeInitialParameterEstimate(&st, world_points,
                                  b_this.workspace.calibration.ImagePoints,
                                  &initialParams, imagesUsed, err);
  //  Convert Extrinsics to my way
  b_loop_ub = imagesUsed.size(0) - 1;
  c_loop_ub = 0;
  for (b_i = 0; b_i <= b_loop_ub; b_i++) {
    if (imagesUsed[b_i]) {
      c_loop_ub++;
    }
  }
  r1.set_size(&nc_emlrtRTEI, sp, c_loop_ub);
  c_loop_ub = 0;
  for (b_i = 0; b_i <= b_loop_ub; b_i++) {
    if (imagesUsed[b_i]) {
      r1[c_loop_ub] = b_i + 1;
      c_loop_ub++;
    }
  }
  loop_ub = r1.size(0);
  for (i = 0; i < loop_ub; i++) {
    if (r1[i] > initialParams.RotationMatrices.size(2)) {
      emlrtDynamicBoundsCheckR2012b(r1[i], 1,
                                    initialParams.RotationMatrices.size(2),
                                    &g_emlrtBCI, (emlrtCTX)sp);
    }
  }
  b_loop_ub = imagesUsed.size(0) - 1;
  c_loop_ub = 0;
  for (b_i = 0; b_i <= b_loop_ub; b_i++) {
    if (imagesUsed[b_i]) {
      c_loop_ub++;
    }
  }
  r2.set_size(&nc_emlrtRTEI, sp, c_loop_ub);
  c_loop_ub = 0;
  for (b_i = 0; b_i <= b_loop_ub; b_i++) {
    if (imagesUsed[b_i]) {
      r2[c_loop_ub] = b_i + 1;
      c_loop_ub++;
    }
  }
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    if (r2[i] > initialParams.TranslationVectors.size(0)) {
      emlrtDynamicBoundsCheckR2012b(r2[i], 1,
                                    initialParams.TranslationVectors.size(0),
                                    &h_emlrtBCI, (emlrtCTX)sp);
    }
  }
  b_loop_ub = imagesUsed.size(0) - 1;
  c_loop_ub = 0;
  for (b_i = 0; b_i <= b_loop_ub; b_i++) {
    if (imagesUsed[b_i]) {
      c_loop_ub++;
    }
  }
  r3.set_size(&nc_emlrtRTEI, sp, c_loop_ub);
  c_loop_ub = 0;
  for (b_i = 0; b_i <= b_loop_ub; b_i++) {
    if (imagesUsed[b_i]) {
      r3[c_loop_ub] = b_i + 1;
      c_loop_ub++;
    }
  }
  b_this.workspace.calibration.PatternPositions.set_size(&nc_emlrtRTEI, sp, 1,
                                                         r3.size(0));
  b_loop_ub = imagesUsed.size(0) - 1;
  c_loop_ub = 0;
  for (b_i = 0; b_i <= b_loop_ub; b_i++) {
    if (imagesUsed[b_i]) {
      c_loop_ub++;
    }
  }
  r4.set_size(&nc_emlrtRTEI, sp, c_loop_ub);
  c_loop_ub = 0;
  for (b_i = 0; b_i <= b_loop_ub; b_i++) {
    if (imagesUsed[b_i]) {
      r4[c_loop_ub] = b_i + 1;
      c_loop_ub++;
    }
  }
  i = r4.size(0);
  if (0 <= r4.size(0) - 1) {
    end = imagesUsed.size(0) - 1;
    result[0] = initialParams.RotationMatrices.size(0);
    result[1] = initialParams.RotationMatrices.size(1);
    c_gray_images[0] = 3;
    c_gray_images[1] = 3;
  }
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 0, 0, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 1);
    c_loop_ub = 0;
    for (b_loop_ub = 0; b_loop_ub <= end; b_loop_ub++) {
      if (imagesUsed[b_loop_ub]) {
        c_loop_ub++;
      }
    }
    r5.set_size(&nc_emlrtRTEI, sp, c_loop_ub);
    c_loop_ub = 0;
    for (b_loop_ub = 0; b_loop_ub <= end; b_loop_ub++) {
      if (imagesUsed[b_loop_ub]) {
        r5[c_loop_ub] = b_loop_ub + 1;
        c_loop_ub++;
      }
    }
    st.site = &e_emlrtRSI;
    if (b_i + 1 > r5.size(0)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, r5.size(0), &f_emlrtBCI, &st);
    }
    if (b_i + 1 > r5.size(0)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, r5.size(0), &e_emlrtBCI, &st);
    }
    covrtLogFcn(&emlrtCoverageInstance, 4, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 4, 0);
    //  Before applying transform all R's coming from outside Matlab
    b_loop_ub = b_this.workspace.calibration.PatternPositions.size(1) - 1;
    for (i1 = 0; i1 < 16; i1++) {
      if (b_i > b_loop_ub) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_loop_ub, &i_emlrtBCI, &st);
      }
      b_this.workspace.calibration.PatternPositions[b_i].f1[i1] = 0.0;
    }
    emlrtSubAssignSizeCheckR2012b(&c_gray_images[0], 2, &result[0], 2,
                                  &emlrtECI, &st);
    b_loop_ub = b_this.workspace.calibration.PatternPositions.size(1) - 1;
    for (i1 = 0; i1 < 3; i1++) {
      if (b_i > b_loop_ub) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_loop_ub, &o_emlrtBCI, &st);
      }
      i2 = i1 << 2;
      b_this.workspace.calibration.PatternPositions[b_i].f1[i2] =
          initialParams
              .RotationMatrices[initialParams.RotationMatrices.size(0) * i1 +
                                initialParams.RotationMatrices.size(0) *
                                    initialParams.RotationMatrices.size(1) *
                                    (r5[b_i] - 1)];
      if (b_i > b_loop_ub) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_loop_ub, &o_emlrtBCI, &st);
      }
      b_this.workspace.calibration.PatternPositions[b_i].f1[i2 + 1] =
          initialParams
              .RotationMatrices[(initialParams.RotationMatrices.size(0) * i1 +
                                 initialParams.RotationMatrices.size(0) *
                                     initialParams.RotationMatrices.size(1) *
                                     (r5[b_i] - 1)) +
                                1];
      if (b_i > b_loop_ub) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_loop_ub, &o_emlrtBCI, &st);
      }
      b_this.workspace.calibration.PatternPositions[b_i].f1[i2 + 2] =
          initialParams
              .RotationMatrices[(initialParams.RotationMatrices.size(0) * i1 +
                                 initialParams.RotationMatrices.size(0) *
                                     initialParams.RotationMatrices.size(1) *
                                     (r5[b_i] - 1)) +
                                2];
    }
    b_loop_ub = b_this.workspace.calibration.PatternPositions.size(1) - 1;
    if (b_i > b_this.workspace.calibration.PatternPositions.size(1) - 1) {
      emlrtDynamicBoundsCheckR2012b(
          b_i, 0, b_this.workspace.calibration.PatternPositions.size(1) - 1,
          &n_emlrtBCI, &st);
    }
    b_this.workspace.calibration.PatternPositions[b_i].f1[3] =
        initialParams.TranslationVectors[r5[b_i] - 1];
    if (b_i > b_loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, b_loop_ub, &n_emlrtBCI, &st);
    }
    b_this.workspace.calibration.PatternPositions[b_i].f1[7] =
        initialParams.TranslationVectors
            [(r5[b_i] + initialParams.TranslationVectors.size(0)) - 1];
    if (b_i > b_loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, b_loop_ub, &n_emlrtBCI, &st);
    }
    b_this.workspace.calibration.PatternPositions[b_i].f1[11] =
        initialParams.TranslationVectors
            [(r5[b_i] + initialParams.TranslationVectors.size(0) * 2) - 1];
    b_loop_ub = b_this.workspace.calibration.PatternPositions.size(1) - 1;
    if (b_i > b_this.workspace.calibration.PatternPositions.size(1) - 1) {
      emlrtDynamicBoundsCheckR2012b(
          b_i, 0, b_this.workspace.calibration.PatternPositions.size(1) - 1,
          &m_emlrtBCI, &st);
    }
    b_this.workspace.calibration.PatternPositions[b_i].f1[12] = 0.0;
    if (b_i > b_loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, b_loop_ub, &m_emlrtBCI, &st);
    }
    b_this.workspace.calibration.PatternPositions[b_i].f1[13] = 0.0;
    if (b_i > b_loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, b_loop_ub, &m_emlrtBCI, &st);
    }
    b_this.workspace.calibration.PatternPositions[b_i].f1[14] = 0.0;
    if (b_i > b_loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, b_loop_ub, &m_emlrtBCI, &st);
    }
    b_this.workspace.calibration.PatternPositions[b_i].f1[15] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 0, 0, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 2);
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
  st.site = &f_emlrtRSI;
  b_st.site = &dx_emlrtRSI;
  if (world_points.size(0) != 0) {
    b_loop_ub = world_points.size(0);
  } else {
    b_loop_ub = 0;
  }
  c_st.site = &ln_emlrtRSI;
  if ((world_points.size(0) != b_loop_ub) && (world_points.size(0) != 0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  if ((world_points.size(0) != b_loop_ub) && (world_points.size(0) != 0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  empty_non_axis_sizes = (b_loop_ub == 0);
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
  b_result.set_size(&oc_emlrtRTEI, &b_st, b_loop_ub,
                    input_sizes_idx_1 + sizes_idx_1);
  loop_ub = input_sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_result[i1 + b_result.size(0) * i] = world_points[i1 + b_loop_ub * i];
    }
  }
  loop_ub = sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_result[i1 + b_result.size(0) * input_sizes_idx_1] = 1.0;
    }
  }
  //  Convert initial estimate
  st.site = &g_emlrtRSI;
  serializeCalib(
      &st, initialParams.RadialDistortion, initialParams.EstimateSkew,
      initialParams.EstimateTangentialDistortion, initialParams.IntrinsicMatrix,
      b_this.workspace.calibration.PatternPositions, serialCalib);
  // [calibrationConverted] = unserializeCalib(serialCalib, options,
  // calibration);
  expl_temp.MeanReprojectionError = initialParams.MeanReprojectionError;
  expl_temp.RotationMatrices.set_size(&pc_emlrtRTEI, sp,
                                      initialParams.RotationMatrices.size(0),
                                      initialParams.RotationMatrices.size(1),
                                      initialParams.RotationMatrices.size(2));
  loop_ub = initialParams.RotationMatrices.size(0) *
            initialParams.RotationMatrices.size(1) *
            initialParams.RotationMatrices.size(2);
  for (i = 0; i < loop_ub; i++) {
    expl_temp.RotationMatrices[i] = initialParams.RotationMatrices[i];
  }
  expl_temp.Skew = initialParams.Skew;
  expl_temp.PrincipalPoint[0] = initialParams.PrincipalPoint[0];
  expl_temp.FocalLength[0] = initialParams.FocalLength[0];
  expl_temp.PrincipalPoint[1] = initialParams.PrincipalPoint[1];
  expl_temp.FocalLength[1] = initialParams.FocalLength[1];
  expl_temp.NumPatterns.size[0] = initialParams.NumPatterns.size[0];
  expl_temp.NumPatterns.size[1] = initialParams.NumPatterns.size[1];
  b_gray_images =
      initialParams.NumPatterns.size[0] * initialParams.NumPatterns.size[1];
  for (i = 0; i < b_gray_images; i++) {
    expl_temp.NumPatterns.data[0] = initialParams.NumPatterns.data[0];
  }
  std::copy(&initialParams.IntrinsicMatrix[0],
            &initialParams.IntrinsicMatrix[9], &expl_temp.IntrinsicMatrix[0]);
  expl_temp.TranslationVectors.set_size(
      &pc_emlrtRTEI, sp, initialParams.TranslationVectors.size(0), 3);
  loop_ub = initialParams.TranslationVectors.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    expl_temp.TranslationVectors[i] = initialParams.TranslationVectors[i];
  }
  expl_temp.RotationVectors.set_size(&pc_emlrtRTEI, sp,
                                     initialParams.RotationVectors.size(0), 3);
  loop_ub = initialParams.RotationVectors.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    expl_temp.RotationVectors[i] = initialParams.RotationVectors[i];
  }
  expl_temp.EstimateTangentialDistortion =
      initialParams.EstimateTangentialDistortion;
  expl_temp.NumRadialDistortionCoefficients =
      initialParams.NumRadialDistortionCoefficients;
  expl_temp.EstimateSkew = initialParams.EstimateSkew;
  expl_temp.WorldUnits.size[0] = 1;
  expl_temp.WorldUnits.size[1] = initialParams.WorldUnits.size[1];
  loop_ub = initialParams.WorldUnits.size[1];
  if (0 <= loop_ub - 1) {
    std::copy(&initialParams.WorldUnits.data[0],
              &initialParams.WorldUnits.data[loop_ub],
              &expl_temp.WorldUnits.data[0]);
  }
  expl_temp.WorldPoints.set_size(&pc_emlrtRTEI, sp,
                                 initialParams.WorldPoints.size(0), 2);
  loop_ub = initialParams.WorldPoints.size(0) * 2;
  for (i = 0; i < loop_ub; i++) {
    expl_temp.WorldPoints[i] = initialParams.WorldPoints[i];
  }
  expl_temp.TangentialDistortion[0] = initialParams.TangentialDistortion[0];
  expl_temp.TangentialDistortion[1] = initialParams.TangentialDistortion[1];
  expl_temp.RadialDistortion[0] = initialParams.RadialDistortion[0];
  expl_temp.RadialDistortion[1] = initialParams.RadialDistortion[1];
  expl_temp.RadialDistortion[2] = initialParams.RadialDistortion[2];
  st.site = &h_emlrtRSI;
  CalculateCost(&st, serialCalib, &expl_temp,
                b_this.workspace.calibration.PatternPositions,
                b_this.workspace.calibration.ImagePoints, b_result,
                b_this.workspace.calibration.ImagePoints,
                calibrationOptimized->Error);
  tmp.set_size(&qc_emlrtRTEI, sp, calibrationOptimized->Error.size(0));
  loop_ub = calibrationOptimized->Error.size(0);
  for (i = 0; i < loop_ub; i++) {
    tmp[i] = calibrationOptimized->Error[i];
  }
  b_loop_ub = calibrationOptimized->Error.size(0);
  for (b_i = 0; b_i < b_loop_ub; b_i++) {
    if (calibrationOptimized->Error[b_i] < 1.0E-6) {
      if (b_i + 1 > calibrationOptimized->Error.size(0)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                                      calibrationOptimized->Error.size(0),
                                      &j_emlrtBCI, (emlrtCTX)sp);
      }
      tmp[b_i] = rtNaN;
    }
  }
  imagesUsed.set_size(&rc_emlrtRTEI, sp, tmp.size(0));
  loop_ub = tmp.size(0);
  for (i = 0; i < loop_ub; i++) {
    imagesUsed[i] = muDoubleScalarIsNaN(tmp[i]);
  }
  loop_ub = imagesUsed.size(0);
  for (i = 0; i < loop_ub; i++) {
    imagesUsed[i] = !imagesUsed[i];
  }
  b_loop_ub = imagesUsed.size(0) - 1;
  c_loop_ub = 0;
  for (b_i = 0; b_i <= b_loop_ub; b_i++) {
    if (imagesUsed[b_i]) {
      c_loop_ub++;
    }
  }
  r6.set_size(&nc_emlrtRTEI, sp, c_loop_ub);
  c_loop_ub = 0;
  for (b_i = 0; b_i <= b_loop_ub; b_i++) {
    if (imagesUsed[b_i]) {
      r6[c_loop_ub] = b_i + 1;
      c_loop_ub++;
    }
  }
  b_tmp.set_size(&sc_emlrtRTEI, sp, r6.size(0));
  loop_ub = r6.size(0);
  for (i = 0; i < loop_ub; i++) {
    if (r6[i] > tmp.size(0)) {
      emlrtDynamicBoundsCheckR2012b(r6[i], 1, tmp.size(0), &k_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    b_tmp[i] = tmp[r6[i] - 1];
  }
  st.site = &i_emlrtRSI;
  coder::mean(&st, b_tmp);
  // disp (['Mean Reprojection Error - Before Optimization: ', num2str(MREi)]);
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
  b_this.workspace.calibration.CameraParameters.TangentialDistortion[1] =
      initialParams.TangentialDistortion[1];
  b_this.workspace.calibration.CameraParameters.WorldPoints.set_size(
      &tc_emlrtRTEI, sp, initialParams.WorldPoints.size(0), 2);
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
      &tc_emlrtRTEI, sp, initialParams.RotationVectors.size(0), 3);
  loop_ub = initialParams.RotationVectors.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    b_this.workspace.calibration.CameraParameters.RotationVectors[i] =
        initialParams.RotationVectors[i];
  }
  b_this.workspace.calibration.CameraParameters.TranslationVectors.set_size(
      &tc_emlrtRTEI, sp, initialParams.TranslationVectors.size(0), 3);
  loop_ub = initialParams.TranslationVectors.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    b_this.workspace.calibration.CameraParameters.TranslationVectors[i] =
        initialParams.TranslationVectors[i];
  }
  std::copy(&initialParams.IntrinsicMatrix[0],
            &initialParams.IntrinsicMatrix[9],
            &b_this.workspace.calibration.CameraParameters.IntrinsicMatrix[0]);
  b_this.workspace.calibration.CameraParameters.NumPatterns.size[0] =
      initialParams.NumPatterns.size[0];
  b_this.workspace.calibration.CameraParameters.NumPatterns.size[1] =
      initialParams.NumPatterns.size[1];
  for (i = 0; i < b_gray_images; i++) {
    b_this.workspace.calibration.CameraParameters.NumPatterns.data[0] =
        initialParams.NumPatterns.data[0];
  }
  b_this.workspace.calibration.CameraParameters.FocalLength[0] =
      initialParams.FocalLength[0];
  b_this.workspace.calibration.CameraParameters.PrincipalPoint[0] =
      initialParams.PrincipalPoint[0];
  b_this.workspace.calibration.CameraParameters.FocalLength[1] =
      initialParams.FocalLength[1];
  b_this.workspace.calibration.CameraParameters.PrincipalPoint[1] =
      initialParams.PrincipalPoint[1];
  b_this.workspace.calibration.CameraParameters.Skew = initialParams.Skew;
  b_this.workspace.calibration.CameraParameters.RotationMatrices.set_size(
      &tc_emlrtRTEI, sp, initialParams.RotationMatrices.size(0),
      initialParams.RotationMatrices.size(1),
      initialParams.RotationMatrices.size(2));
  loop_ub = initialParams.RotationMatrices.size(0) *
            initialParams.RotationMatrices.size(1) *
            initialParams.RotationMatrices.size(2);
  for (i = 0; i < loop_ub; i++) {
    b_this.workspace.calibration.CameraParameters.RotationMatrices[i] =
        initialParams.RotationMatrices[i];
  }
  b_this.workspace.calibration.CameraParameters.MeanReprojectionError =
      initialParams.MeanReprojectionError;
  b_this.workspace.genPoints.set_size(&uc_emlrtRTEI, sp, b_result.size(0),
                                      b_result.size(1));
  loop_ub = b_result.size(0) * b_result.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_this.workspace.genPoints[i] = b_result[i];
  }
  b_this.workspace.detPoints.set_size(
      &uc_emlrtRTEI, sp, b_this.workspace.calibration.ImagePoints.size(0),
      b_this.workspace.calibration.ImagePoints.size(1),
      b_this.workspace.calibration.ImagePoints.size(2));
  loop_ub = b_this.workspace.calibration.ImagePoints.size(0) *
            b_this.workspace.calibration.ImagePoints.size(1) *
            b_this.workspace.calibration.ImagePoints.size(2);
  for (i = 0; i < loop_ub; i++) {
    b_this.workspace.detPoints[i] = b_this.workspace.calibration.ImagePoints[i];
  }
  st.site = &j_emlrtRSI;
  coder::lsqnonlin(&st, &b_this, serialCalib, &a__1,
                   calibrationOptimized->Error, &a__2, jacobian);
  // delete(h);
  // serialCI = nlparci(optimizedSerialCalib,residual,'jacobian',jacobian);
  // serialCI = my_nlparci(optimizedSerialCalib,residual,jacobian);
  // CI = cell(1,2);
  // CI{1} = unserializeCalib(serialCI(:,1)', options, calibration);
  // CI{2} = unserializeCalib(serialCI(:,2)', options, calibration);
  b_expl_temp.MeanReprojectionError = initialParams.MeanReprojectionError;
  b_expl_temp.RotationMatrices.set_size(&vc_emlrtRTEI, sp,
                                        initialParams.RotationMatrices.size(0),
                                        initialParams.RotationMatrices.size(1),
                                        initialParams.RotationMatrices.size(2));
  loop_ub = initialParams.RotationMatrices.size(0) *
            initialParams.RotationMatrices.size(1) *
            initialParams.RotationMatrices.size(2);
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.RotationMatrices[i] = initialParams.RotationMatrices[i];
  }
  b_expl_temp.Skew = initialParams.Skew;
  b_expl_temp.PrincipalPoint[0] = initialParams.PrincipalPoint[0];
  b_expl_temp.FocalLength[0] = initialParams.FocalLength[0];
  b_expl_temp.PrincipalPoint[1] = initialParams.PrincipalPoint[1];
  b_expl_temp.FocalLength[1] = initialParams.FocalLength[1];
  b_expl_temp.NumPatterns.size[0] = initialParams.NumPatterns.size[0];
  b_expl_temp.NumPatterns.size[1] = initialParams.NumPatterns.size[1];
  for (i = 0; i < b_gray_images; i++) {
    b_expl_temp.NumPatterns.data[0] = initialParams.NumPatterns.data[0];
  }
  std::copy(&initialParams.IntrinsicMatrix[0],
            &initialParams.IntrinsicMatrix[9], &b_expl_temp.IntrinsicMatrix[0]);
  b_expl_temp.TranslationVectors.set_size(
      &vc_emlrtRTEI, sp, initialParams.TranslationVectors.size(0), 3);
  loop_ub = initialParams.TranslationVectors.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.TranslationVectors[i] = initialParams.TranslationVectors[i];
  }
  b_expl_temp.RotationVectors.set_size(
      &vc_emlrtRTEI, sp, initialParams.RotationVectors.size(0), 3);
  loop_ub = initialParams.RotationVectors.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.RotationVectors[i] = initialParams.RotationVectors[i];
  }
  b_expl_temp.EstimateTangentialDistortion =
      initialParams.EstimateTangentialDistortion;
  b_expl_temp.NumRadialDistortionCoefficients =
      initialParams.NumRadialDistortionCoefficients;
  b_expl_temp.EstimateSkew = initialParams.EstimateSkew;
  b_expl_temp.WorldUnits.size[0] = 1;
  b_expl_temp.WorldUnits.size[1] = initialParams.WorldUnits.size[1];
  loop_ub = initialParams.WorldUnits.size[1];
  if (0 <= loop_ub - 1) {
    std::copy(&initialParams.WorldUnits.data[0],
              &initialParams.WorldUnits.data[loop_ub],
              &b_expl_temp.WorldUnits.data[0]);
  }
  b_expl_temp.WorldPoints.set_size(&vc_emlrtRTEI, sp,
                                   initialParams.WorldPoints.size(0), 2);
  loop_ub = initialParams.WorldPoints.size(0) * 2;
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.WorldPoints[i] = initialParams.WorldPoints[i];
  }
  b_expl_temp.TangentialDistortion[0] = initialParams.TangentialDistortion[0];
  b_expl_temp.TangentialDistortion[1] = initialParams.TangentialDistortion[1];
  b_expl_temp.RadialDistortion[0] = initialParams.RadialDistortion[0];
  b_expl_temp.RadialDistortion[1] = initialParams.RadialDistortion[1];
  b_expl_temp.RadialDistortion[2] = initialParams.RadialDistortion[2];
  st.site = &k_emlrtRSI;
  CalculateCost(&st, serialCalib, &b_expl_temp,
                b_this.workspace.calibration.PatternPositions,
                b_this.workspace.calibration.ImagePoints, b_result,
                b_this.workspace.calibration.ImagePoints,
                calibrationOptimized->Error);
  tmp.set_size(&wc_emlrtRTEI, sp, calibrationOptimized->Error.size(0));
  loop_ub = calibrationOptimized->Error.size(0);
  for (i = 0; i < loop_ub; i++) {
    tmp[i] = calibrationOptimized->Error[i];
  }
  b_loop_ub = calibrationOptimized->Error.size(0);
  for (b_i = 0; b_i < b_loop_ub; b_i++) {
    if (calibrationOptimized->Error[b_i] < 1.0E-6) {
      if (b_i + 1 > calibrationOptimized->Error.size(0)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                                      calibrationOptimized->Error.size(0),
                                      &l_emlrtBCI, (emlrtCTX)sp);
      }
      tmp[b_i] = rtNaN;
    }
  }
  st.site = &l_emlrtRSI;
  calibrationOptimized->MREf = coder::nanmean(&st, tmp);
  // disp (['Mean Reprojection Error - After Optimization: ', num2str(MREf)]);
  c_expl_temp.MeanReprojectionError = initialParams.MeanReprojectionError;
  c_expl_temp.RotationMatrices.set_size(&xc_emlrtRTEI, sp,
                                        initialParams.RotationMatrices.size(0),
                                        initialParams.RotationMatrices.size(1),
                                        initialParams.RotationMatrices.size(2));
  loop_ub = initialParams.RotationMatrices.size(0) *
            initialParams.RotationMatrices.size(1) *
            initialParams.RotationMatrices.size(2);
  for (i = 0; i < loop_ub; i++) {
    c_expl_temp.RotationMatrices[i] = initialParams.RotationMatrices[i];
  }
  c_expl_temp.Skew = initialParams.Skew;
  c_expl_temp.PrincipalPoint[0] = initialParams.PrincipalPoint[0];
  c_expl_temp.FocalLength[0] = initialParams.FocalLength[0];
  c_expl_temp.PrincipalPoint[1] = initialParams.PrincipalPoint[1];
  c_expl_temp.FocalLength[1] = initialParams.FocalLength[1];
  c_expl_temp.NumPatterns.size[0] = initialParams.NumPatterns.size[0];
  c_expl_temp.NumPatterns.size[1] = initialParams.NumPatterns.size[1];
  for (i = 0; i < b_gray_images; i++) {
    c_expl_temp.NumPatterns.data[0] = initialParams.NumPatterns.data[0];
  }
  std::copy(&initialParams.IntrinsicMatrix[0],
            &initialParams.IntrinsicMatrix[9], &c_expl_temp.IntrinsicMatrix[0]);
  c_expl_temp.TranslationVectors.set_size(
      &xc_emlrtRTEI, sp, initialParams.TranslationVectors.size(0), 3);
  loop_ub = initialParams.TranslationVectors.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    c_expl_temp.TranslationVectors[i] = initialParams.TranslationVectors[i];
  }
  c_expl_temp.RotationVectors.set_size(
      &xc_emlrtRTEI, sp, initialParams.RotationVectors.size(0), 3);
  loop_ub = initialParams.RotationVectors.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    c_expl_temp.RotationVectors[i] = initialParams.RotationVectors[i];
  }
  c_expl_temp.EstimateTangentialDistortion =
      initialParams.EstimateTangentialDistortion;
  c_expl_temp.NumRadialDistortionCoefficients =
      initialParams.NumRadialDistortionCoefficients;
  c_expl_temp.EstimateSkew = initialParams.EstimateSkew;
  c_expl_temp.WorldUnits.size[0] = 1;
  c_expl_temp.WorldUnits.size[1] = initialParams.WorldUnits.size[1];
  loop_ub = initialParams.WorldUnits.size[1];
  if (0 <= loop_ub - 1) {
    std::copy(&initialParams.WorldUnits.data[0],
              &initialParams.WorldUnits.data[loop_ub],
              &c_expl_temp.WorldUnits.data[0]);
  }
  c_expl_temp.WorldPoints.set_size(&xc_emlrtRTEI, sp,
                                   initialParams.WorldPoints.size(0), 2);
  loop_ub = initialParams.WorldPoints.size(0) * 2;
  for (i = 0; i < loop_ub; i++) {
    c_expl_temp.WorldPoints[i] = initialParams.WorldPoints[i];
  }
  c_expl_temp.TangentialDistortion[0] = initialParams.TangentialDistortion[0];
  c_expl_temp.TangentialDistortion[1] = initialParams.TangentialDistortion[1];
  c_expl_temp.RadialDistortion[0] = initialParams.RadialDistortion[0];
  c_expl_temp.RadialDistortion[1] = initialParams.RadialDistortion[1];
  c_expl_temp.RadialDistortion[2] = initialParams.RadialDistortion[2];
  st.site = &m_emlrtRSI;
  unserializeCalib(&st, serialCalib, &c_expl_temp,
                   b_this.workspace.calibration.PatternPositions,
                   b_this.workspace.calibration.ImagePoints,
                   &calibrationOptimized->CameraParameters,
                   calibrationOptimized->PatternPositions,
                   calibrationOptimized->ImagePoints);
  // calibrationOptimized.OptimizationOptions = options;
  // calibrationOptimized.Jacobian = jacobian;
  // calibrationOptimized.CI = CI;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void calibrateCamera_anonFcn1(
    const emlrtStack *sp, const struct1_T *calibration_CameraParameters,
    const ::coder::array<cell_wrap_0, 2U> &calibration_PatternPositions,
    const ::coder::array<real_T, 3U> &calibration_ImagePoints,
    const ::coder::array<real_T, 2U> &genPoints,
    const ::coder::array<real_T, 3U> &detPoints,
    const ::coder::array<real_T, 1U> &x,
    ::coder::array<real_T, 1U> &varargout_1)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  covrtLogFcn(&emlrtCoverageInstance, 0, 1);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 3);
  st.site = &wy_emlrtRSI;
  CalculateCost(&st, x, calibration_CameraParameters,
                calibration_PatternPositions, calibration_ImagePoints,
                genPoints, detPoints, varargout_1);
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

// End of code generation (calibrateCamera.cpp)
