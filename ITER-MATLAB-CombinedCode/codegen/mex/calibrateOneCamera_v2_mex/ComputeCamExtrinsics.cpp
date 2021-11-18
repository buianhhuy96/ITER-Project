//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// ComputeCamExtrinsics.cpp
//
// Code generation for function 'ComputeCamExtrinsics'
//

// Include files
#include "ComputeCamExtrinsics.h"
#include "all1.h"
#include "any1.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "calibrateOneCamera_v2_mex_internal_types.h"
#include "calibrateOneCamera_v2_mex_types.h"
#include "cameraParameters.h"
#include "combineVectorElements.h"
#include "detectCheckerboardPoints.h"
#include "fitgeotrans.h"
#include "generateCheckerboardPoints.h"
#include "inv.h"
#include "isequal.h"
#include "mldivide.h"
#include "projective2d.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo rfb_emlrtRSI{
    9,                      // lineNo
    "ComputeCamExtrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pathName
};

static emlrtRSInfo sfb_emlrtRSI{
    12,                     // lineNo
    "ComputeCamExtrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pathName
};

static emlrtRSInfo tfb_emlrtRSI{
    27,                     // lineNo
    "ComputeCamExtrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pathName
};

static emlrtRSInfo ufb_emlrtRSI{
    29,                     // lineNo
    "ComputeCamExtrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pathName
};

static emlrtRSInfo
    vfb_emlrtRSI{
        115,          // lineNo
        "extrinsics", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extrinsics.m" // pathName
    };

static emlrtRSInfo
    wfb_emlrtRSI{
        124,          // lineNo
        "extrinsics", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extrinsics.m" // pathName
    };

static emlrtRSInfo
    xfb_emlrtRSI{
        126,          // lineNo
        "extrinsics", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extrinsics.m" // pathName
    };

static emlrtRSInfo yfb_emlrtRSI{
    10,                         // lineNo
    "validateExtrinsicsInputs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "inputValidation\\validateExtrinsicsInputs.m" // pathName
};

static emlrtRSInfo agb_emlrtRSI{
    15,                         // lineNo
    "validateExtrinsicsInputs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "inputValidation\\validateExtrinsicsInputs.m" // pathName
};

static emlrtRSInfo bgb_emlrtRSI{
    17,                 // lineNo
    "extrinsicsPlanar", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\extrinsicsPlanar.m" // pathName
};

static emlrtRSInfo cgb_emlrtRSI{
    23,                 // lineNo
    "extrinsicsPlanar", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\extrinsicsPlanar.m" // pathName
};

static emlrtRSInfo dgb_emlrtRSI{
    26,                 // lineNo
    "extrinsicsPlanar", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\extrinsicsPlanar.m" // pathName
};

static emlrtRSInfo egb_emlrtRSI{
    27,                 // lineNo
    "extrinsicsPlanar", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\extrinsicsPlanar.m" // pathName
};

static emlrtRSInfo fgb_emlrtRSI{
    33,                 // lineNo
    "extrinsicsPlanar", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\extrinsicsPlanar.m" // pathName
};

static emlrtRSInfo ggb_emlrtRSI{
    37,                 // lineNo
    "extrinsicsPlanar", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\extrinsicsPlanar.m" // pathName
};

static emlrtDCInfo b_emlrtDCI{
    51,                         // lineNo
    21,                         // colNo
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m", // pName
    4                                                   // checkKind
};

static emlrtRTEInfo sc_emlrtRTEI{
    31,                         // lineNo
    5,                          // colNo
    "validateExtrinsicsInputs", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "inputValidation\\validateExtrinsicsInputs.m" // pName
};

static emlrtRTEInfo tc_emlrtRTEI{
    24,                         // lineNo
    1,                          // colNo
    "validateExtrinsicsInputs", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "inputValidation\\validateExtrinsicsInputs.m" // pName
};

static emlrtECInfo ud_emlrtECI{
    -1,                     // nDims
    32,                     // lineNo
    5,                      // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pName
};

static emlrtBCInfo lv_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    32,                     // lineNo
    21,                     // colNo
    "cameraPoses",          // aName
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m", // pName
    0                                                         // checkKind
};

static emlrtECInfo vd_emlrtECI{
    -1,                     // nDims
    29,                     // lineNo
    5,                      // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pName
};

static emlrtBCInfo mv_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    29,                     // lineNo
    23,                     // colNo
    "camExtrinsics",        // aName
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m", // pName
    0                                                         // checkKind
};

static emlrtBCInfo nv_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    27,                     // lineNo
    75,                     // colNo
    "imagePoints",          // aName
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m", // pName
    0                                                         // checkKind
};

static emlrtBCInfo ov_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    12,                     // lineNo
    1,                      // colNo
    "board_points",         // aName
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m", // pName
    0                                                         // checkKind
};

static emlrtRTEInfo fv_emlrtRTEI{
    12,                     // lineNo
    1,                      // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo gv_emlrtRTEI{
    22,                     // lineNo
    1,                      // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo hv_emlrtRTEI{
    23,                     // lineNo
    1,                      // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo iv_emlrtRTEI{
    27,                     // lineNo
    59,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo jv_emlrtRTEI{
    29,                     // lineNo
    19,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo kv_emlrtRTEI{
    29,                     // lineNo
    21,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo lv_emlrtRTEI{
    32,                     // lineNo
    17,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo mv_emlrtRTEI{
    32,                     // lineNo
    19,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo nv_emlrtRTEI{
    16,                     // lineNo
    21,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo ov_emlrtRTEI{
    17,                     // lineNo
    5,                      // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pName
};

// Function Definitions
void ComputeCamExtrinsics(const emlrtStack *sp,
                          const coder::array<uint8_T, 4U> &images,
                          real_T squareSize, const struct1_T *cameraParams,
                          coder::array<real_T, 3U> &imagePoints,
                          coder::array<boolean_T, 1U> &validIdx,
                          coder::array<real_T, 3U> &camExtrinsics,
                          coder::array<real_T, 3U> &cameraPoses,
                          coder::array<real_T, 2U> &worldPoints, int32_T *err)
{
  coder::cameraParameters b_cameraParams;
  coder::projective2d H;
  coder::array<cell_wrap_12, 2U> board_points;
  coder::array<real_T, 2U> current_board_points;
  coder::array<real_T, 2U> r;
  coder::array<int32_T, 1U> r1;
  coder::array<int32_T, 1U> r2;
  coder::array<uint8_T, 2U> b_images;
  coder::array<boolean_T, 1U> x;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T _1[16];
  real_T U[9];
  real_T V[9];
  real_T a__1[9];
  real_T b_H[9];
  real_T c_r1[9];
  real_T rotationMatrix[9];
  real_T b_r1[3];
  real_T b_r2[3];
  real_T lambda[3];
  real_T b_dv[2];
  real_T board_size_detected[2];
  real_T board_size_valid[2];
  int32_T b_iv[2];
  int32_T image_point_valid_size[2];
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T nz;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 3, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 3, 0);
  //  images: images in a [row x col x channel x numImages] array
  //  square: Checkerboard square size in meter size
  //  cameraParams: camera parameters  matlab object
  //  Initialize error and camera parameters
  st.site = &rfb_emlrtRSI;
  b_st.site = &i_emlrtRSI;
  c_st.site = &l_emlrtRSI;
  b_st.site = &j_emlrtRSI;
  c_st.site = &obb_emlrtRSI;
  coder::cameraParameters::checkIntrinsicMatrix(&c_st,
                                                cameraParams->IntrinsicMatrix);
  for (i = 0; i < 3; i++) {
    b_cameraParams.IntrinsicMatrixInternal[3 * i] =
        cameraParams->IntrinsicMatrix[i];
    b_cameraParams.IntrinsicMatrixInternal[3 * i + 1] =
        cameraParams->IntrinsicMatrix[i + 3];
    b_cameraParams.IntrinsicMatrixInternal[3 * i + 2] =
        cameraParams->IntrinsicMatrix[i + 6];
  }
  c_st.site = &n_emlrtRSI;
  coder::cameraParameters::checkRadialDistortion(
      &c_st, cameraParams->RadialDistortion);
  c_st.site = &o_emlrtRSI;
  coder::cameraParameters::checkTangentialDistortion(
      &c_st, cameraParams->TangentialDistortion);
  c_st.site = &p_emlrtRSI;
  d_st.site = &v_emlrtRSI;
  coder::cameraParameters::checkImageSize(&d_st, cameraParams->ImageSize);
  c_st.site = &q_emlrtRSI;
  coder::cameraParameters::checkImageSize(&c_st, cameraParams->ImageSize);
  c_st.site = &r_emlrtRSI;
  coder::cameraParameters::checkNumRadialCoeffs(
      &c_st, cameraParams->NumRadialDistortionCoefficients);
  b_st.site = &k_emlrtRSI;
  c_st.site = &bb_emlrtRSI;
  //  Get checkerboard points
  st.site = &sfb_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1, 0);
  //  Initialize error flags
  *err = 0;
  board_size_valid[0] = 0.0;
  image_point_valid_size[0] = 0;
  board_size_valid[1] = 0.0;
  image_point_valid_size[1] = 0;
  validIdx.set_size(&fv_emlrtRTEI, &st, images.size(3));
  b_iv[1] = images.size(3);
  board_points.set_size(&fv_emlrtRTEI, &st, 1, images.size(3));
  for (i = 0; i < b_iv[1]; i++) {
    nz = board_points.size(1) - 1;
    if (i > board_points.size(1) - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, board_points.size(1) - 1,
                                    &ov_emlrtBCI, &st);
    }
    board_points[board_points.size(0) * i].f1.set_size(
        &fv_emlrtRTEI, &st, 0,
        board_points[board_points.size(0) * i].f1.size(1));
    if (i > nz) {
      emlrtDynamicBoundsCheckR2012b(i, 0, nz, &ov_emlrtBCI, &st);
    }
    board_points[board_points.size(0) * i].f1.set_size(
        &fv_emlrtRTEI, &st, board_points[board_points.size(0) * i].f1.size(0),
        0);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  //  perform checkerboards detection in each image
  i = images.size(3);
  board_points.set_size(&fv_emlrtRTEI, &st, 1, images.size(3));
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 1, 0, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 1);
    if (b_i + 1 > images.size(3)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, images.size(3), &d_emlrtBCI,
                                    &st);
    }
    nz = images.size(0);
    loop_ub = images.size(1);
    b_images.set_size(&jd_emlrtRTEI, &st, images.size(0), images.size(1));
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (i2 = 0; i2 < nz; i2++) {
        b_images[i2 + b_images.size(0) * i1] =
            images[(i2 + images.size(0) * i1) +
                   images.size(0) * images.size(1) * b_i];
      }
    }
    b_st.site = &eb_emlrtRSI;
    coder::detectCheckerboardPoints(&b_st, b_images, current_board_points,
                                    board_size_detected);
    //  mark if checkerboards is detected or not
    b_dv[0] = 0.0;
    b_dv[1] = 0.0;
    if (covrtLogCond(&emlrtCoverageInstance, 1, 0, 0,
                     coder::isequal(board_size_detected, b_dv))) {
      covrtLogMcdc(&emlrtCoverageInstance, 1, 0, 0, true);
      covrtLogIf(&emlrtCoverageInstance, 1, 0, 0, true);
      covrtLogBasicBlock(&emlrtCoverageInstance, 1, 2);
      if (b_i + 1 > validIdx.size(0)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, validIdx.size(0), &g_emlrtBCI,
                                      &st);
      }
      validIdx[b_i] = false;
    } else {
      covrtLogCond(&emlrtCoverageInstance, 1, 0, 1, true);
      covrtLogMcdc(&emlrtCoverageInstance, 1, 0, 0, false);
      covrtLogIf(&emlrtCoverageInstance, 1, 0, 0, false);
      b_dv[0] = 0.0;
      b_dv[1] = 0.0;
      if (covrtLogIf(&emlrtCoverageInstance, 1, 0, 1,
                     coder::isequal(board_size_valid, b_dv))) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 1, 3);
        board_size_valid[0] = board_size_detected[0];
        image_point_valid_size[0] = current_board_points.size(0);
        board_size_valid[1] = board_size_detected[1];
        image_point_valid_size[1] = current_board_points.size(1);
      } else if (covrtLogIf(
                     &emlrtCoverageInstance, 1, 0, 2,
                     covrtLogMcdc(
                         &emlrtCoverageInstance, 1, 0, 1,
                         !covrtLogCond(&emlrtCoverageInstance, 1, 0, 3,
                                       coder::isequal(board_size_valid,
                                                      board_size_detected))))) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 1, 4);
        *err = -102;
      }
      covrtLogBasicBlock(&emlrtCoverageInstance, 1, 5);
      if (b_i + 1 > validIdx.size(0)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, validIdx.size(0), &h_emlrtBCI,
                                      &st);
      }
      validIdx[b_i] = true;
    }
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 6);
    nz = current_board_points.size(0) * current_board_points.size(1);
    if (b_i > board_points.size(1) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(1) - 1,
                                    &e_emlrtBCI, &st);
    }
    board_points[board_points.size(0) * b_i].f1.set_size(
        &kd_emlrtRTEI, &st, current_board_points.size(0),
        board_points[board_points.size(0) * b_i].f1.size(1));
    if (b_i > board_points.size(1) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(1) - 1,
                                    &e_emlrtBCI, &st);
    }
    board_points[board_points.size(0) * b_i].f1.set_size(
        &kd_emlrtRTEI, &st, board_points[board_points.size(0) * b_i].f1.size(0),
        current_board_points.size(1));
    i1 = board_points.size(1);
    if (b_i > board_points.size(1) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(1) - 1,
                                    &e_emlrtBCI, &st);
    }
    if (b_i > board_points.size(1) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(1) - 1,
                                    &e_emlrtBCI, &st);
    }
    for (i2 = 0; i2 < nz; i2++) {
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &i_emlrtBCI, &st);
      }
      board_points[b_i].f1[i2] = current_board_points[i2];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 1, 0, 0, 0);
  if (covrtLogIf(&emlrtCoverageInstance, 1, 0, 3, *err != 0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 7);
    // err = "Checkerboards detected has different size from given boardSize";
    imagePoints.set_size(&sd_emlrtRTEI, &st, 0, 0, 1);
    worldPoints.set_size(&td_emlrtRTEI, &st, 0, 0);
  } else {
    b_st.site = &fb_emlrtRSI;
    if (covrtLogIf(
            &emlrtCoverageInstance, 1, 0, 4,
            covrtLogMcdc(&emlrtCoverageInstance, 1, 0, 2,
                         !covrtLogCond(&emlrtCoverageInstance, 1, 0, 4,
                                       coder::b_any(&b_st, validIdx))))) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 1, 8);
      // err = "No detect of checkerboard in all images";
      *err = -101;
      imagePoints.set_size(&qd_emlrtRTEI, &st, 0, 0, 1);
      worldPoints.set_size(&rd_emlrtRTEI, &st, 0, 0);
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 1, 9);
      //  Extract valid image points into matrix
      b_st.site = &gb_emlrtRSI;
      x.set_size(&ld_emlrtRTEI, &b_st, validIdx.size(0));
      nz = validIdx.size(0);
      for (i = 0; i < nz; i++) {
        x[i] = validIdx[i];
      }
      c_st.site = &iw_emlrtRSI;
      d_st.site = &yo_emlrtRSI;
      nz = coder::combineVectorElements(&d_st, x);
      if (nz < 0) {
        emlrtNonNegativeCheckR2012b(static_cast<real_T>(nz), &b_emlrtDCI, &st);
      }
      imagePoints.set_size(&md_emlrtRTEI, &st, image_point_valid_size[0],
                           image_point_valid_size[1], nz);
      nz *= image_point_valid_size[0] * image_point_valid_size[1];
      for (i = 0; i < nz; i++) {
        imagePoints[i] = 0.0;
      }
      i = images.size(3);
      for (b_i = 0; b_i < i; b_i++) {
        covrtLogFor(&emlrtCoverageInstance, 1, 0, 1, 1);
        if (b_i + 1 > validIdx.size(0)) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, validIdx.size(0),
                                        &j_emlrtBCI, &st);
        }
        if (covrtLogIf(&emlrtCoverageInstance, 1, 0, 5, validIdx[b_i])) {
          covrtLogBasicBlock(&emlrtCoverageInstance, 1, 10);
          nz = imagePoints.size(0);
          r1.set_size(&nd_emlrtRTEI, &st, imagePoints.size(0));
          for (i1 = 0; i1 < nz; i1++) {
            r1[i1] = i1;
          }
          nz = imagePoints.size(1);
          r2.set_size(&od_emlrtRTEI, &st, imagePoints.size(1));
          for (i1 = 0; i1 < nz; i1++) {
            r2[i1] = i1;
          }
          if (b_i + 1 > imagePoints.size(2)) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, imagePoints.size(2),
                                          &c_emlrtBCI, &st);
          }
          if (b_i > board_points.size(1) - 1) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(1) - 1,
                                          &b_emlrtBCI, &st);
          }
          b_iv[0] = r1.size(0);
          b_iv[1] = r2.size(0);
          emlrtSubAssignSizeCheckR2012b(
              &b_iv[0], 2, board_points[b_i].f1.size(), 2, &emlrtECI, &st);
          nz = board_points[b_i].f1.size(1);
          for (i1 = 0; i1 < nz; i1++) {
            loop_ub = board_points[b_i].f1.size(0);
            for (i2 = 0; i2 < loop_ub; i2++) {
              imagePoints[(r1[i2] + imagePoints.size(0) * r2[i1]) +
                          imagePoints.size(0) * imagePoints.size(1) * b_i] =
                  board_points[b_i].f1[i2 + board_points[b_i].f1.size(0) * i1];
            }
          }
        }
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }
      covrtLogFor(&emlrtCoverageInstance, 1, 0, 1, 0);
      covrtLogBasicBlock(&emlrtCoverageInstance, 1, 11);
      //  Generate world coordinates of the corners of the squares in meters
      b_st.site = &hb_emlrtRSI;
      coder::generateCheckerboardPoints(&b_st, board_size_valid, squareSize, r);
      worldPoints.set_size(&pd_emlrtRTEI, &st, r.size(0), 2);
      nz = r.size(0) * 2;
      for (i = 0; i < nz; i++) {
        worldPoints[i] = r[i];
      }
    }
  }
  //  Terminate in case of error
  if (covrtLogIf(&emlrtCoverageInstance, 3, 0, 0, *err != 0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 1);
    camExtrinsics.set_size(&nv_emlrtRTEI, sp, 0, 0, 1);
    cameraPoses.set_size(&ov_emlrtRTEI, sp, 0, 0, 1);
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 2);
    //  compute extrinsics
    camExtrinsics.set_size(&gv_emlrtRTEI, sp, 4, 4, imagePoints.size(2));
    nz = imagePoints.size(2) << 4;
    for (i = 0; i < nz; i++) {
      camExtrinsics[i] = 0.0;
    }
    cameraPoses.set_size(&hv_emlrtRTEI, sp, 4, 4, imagePoints.size(2));
    nz = imagePoints.size(2) << 4;
    for (i = 0; i < nz; i++) {
      cameraPoses[i] = 0.0;
    }
    i = imagePoints.size(2);
    if (0 <= i - 1) {
      b_loop_ub = imagePoints.size(0);
      c_loop_ub = imagePoints.size(1);
    }
    for (b_i = 0; b_i < i; b_i++) {
      real_T absxk;
      real_T scale;
      real_T t;
      real_T y;
      covrtLogFor(&emlrtCoverageInstance, 3, 0, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 3, 3);
      //  transformations from the grid/world coordinates to the camera-based
      //  coordinates
      st.site = &tfb_emlrtRSI;
      if (b_i + 1 > imagePoints.size(2)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, imagePoints.size(2),
                                      &nv_emlrtBCI, &st);
      }
      current_board_points.set_size(&iv_emlrtRTEI, &st, imagePoints.size(0),
                                    imagePoints.size(1));
      for (i1 = 0; i1 < c_loop_ub; i1++) {
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          current_board_points[i2 + current_board_points.size(0) * i1] =
              imagePoints[(i2 + imagePoints.size(0) * i1) +
                          imagePoints.size(0) * imagePoints.size(1) * b_i];
        }
      }
      b_st.site = &vfb_emlrtRSI;
      c_st.site = &yfb_emlrtRSI;
      d_st.site = &t_emlrtRSI;
      if (!coder::internal::valattr::d_all(current_board_points)) {
        emlrtErrorWithMessageIdR2018a(
            &d_st, &c_emlrtRTEI,
            "Coder:toolbox:ValidateattributesexpectedFinite",
            "MATLAB:extrinsics:expectedFinite", 3, 4, 11, "imagePoints");
      }
      d_st.site = &t_emlrtRSI;
      if (imagePoints.size(1) != 2) {
        emlrtErrorWithMessageIdR2018a(
            &d_st, &bc_emlrtRTEI,
            "Coder:toolbox:ValidateattributesincorrectNumcols",
            "MATLAB:extrinsics:incorrectNumcols", 5, 4, 11, "imagePoints", 6,
            2.0);
      }
      c_st.site = &agb_emlrtRSI;
      d_st.site = &t_emlrtRSI;
      if (!coder::internal::valattr::d_all(worldPoints)) {
        emlrtErrorWithMessageIdR2018a(
            &d_st, &c_emlrtRTEI,
            "Coder:toolbox:ValidateattributesexpectedFinite",
            "MATLAB:extrinsics:expectedFinite", 3, 4, 11, "worldPoints");
      }
      d_st.site = &t_emlrtRSI;
      if (worldPoints.size(1) != 2) {
        emlrtErrorWithMessageIdR2018a(
            &d_st, &bc_emlrtRTEI,
            "Coder:toolbox:ValidateattributesincorrectNumcols",
            "MATLAB:extrinsics:incorrectNumcols", 5, 4, 11, "worldPoints", 6,
            2.0);
      }
      if (imagePoints.size(0) != worldPoints.size(0)) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &tc_emlrtRTEI, "vision:calibrate:numberOfPointsMustMatch",
            "vision:calibrate:numberOfPointsMustMatch", 0);
      }
      if (worldPoints.size(0) < 4) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &sc_emlrtRTEI, "vision:calibrate:minNumWorldPoints",
            "vision:calibrate:minNumWorldPoints", 2, 6, 3.0);
      }
      b_st.site = &wfb_emlrtRSI;
      b_st.site = &xfb_emlrtRSI;
      c_st.site = &bgb_emlrtRSI;
      coder::fitgeotrans(&c_st, worldPoints, current_board_points, &H);
      for (i1 = 0; i1 < 3; i1++) {
        b_H[3 * i1] = H.T[i1];
        b_H[3 * i1 + 1] = H.T[i1 + 3];
        b_H[3 * i1 + 2] = H.T[i1 + 6];
      }
      c_st.site = &cgb_emlrtRSI;
      coder::b_mldivide(&c_st, b_cameraParams.IntrinsicMatrixInternal,
                        *(real_T(*)[3]) & b_H[0], b_r1);
      scale = 3.3121686421112381E-170;
      absxk = muDoubleScalarAbs(b_r1[0]);
      if (absxk > 3.3121686421112381E-170) {
        y = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        y = t * t;
      }
      absxk = muDoubleScalarAbs(b_r1[1]);
      if (absxk > scale) {
        t = scale / absxk;
        y = y * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        y += t * t;
      }
      absxk = muDoubleScalarAbs(b_r1[2]);
      if (absxk > scale) {
        t = scale / absxk;
        y = y * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        y += t * t;
      }
      y = scale * muDoubleScalarSqrt(y);
      scale = 1.0 / y;
      lambda[0] = scale * b_H[0];
      lambda[1] = scale * b_H[1];
      lambda[2] = scale * b_H[2];
      c_st.site = &dgb_emlrtRSI;
      coder::b_mldivide(&c_st, b_cameraParams.IntrinsicMatrixInternal, lambda,
                        b_r1);
      lambda[0] = scale * b_H[3];
      lambda[1] = scale * b_H[4];
      lambda[2] = scale * b_H[5];
      c_st.site = &egb_emlrtRSI;
      coder::b_mldivide(&c_st, b_cameraParams.IntrinsicMatrixInternal, lambda,
                        b_r2);
      c_r1[0] = b_r1[0];
      c_r1[1] = b_r2[0];
      c_r1[3] = b_r1[1];
      c_r1[4] = b_r2[1];
      c_r1[6] = b_r1[2];
      c_r1[7] = b_r2[2];
      c_r1[2] = b_r1[1] * b_r2[2] - b_r2[1] * b_r1[2];
      c_r1[5] = b_r2[0] * b_r1[2] - b_r1[0] * b_r2[2];
      c_r1[8] = b_r1[0] * b_r2[1] - b_r2[0] * b_r1[1];
      c_st.site = &fgb_emlrtRSI;
      coder::svd(&c_st, c_r1, U, a__1, V);
      for (i1 = 0; i1 < 3; i1++) {
        absxk = U[i1];
        t = U[i1 + 3];
        y = U[i1 + 6];
        for (i2 = 0; i2 < 3; i2++) {
          rotationMatrix[i1 + 3 * i2] =
              (absxk * V[i2] + t * V[i2 + 3]) + y * V[i2 + 6];
        }
        lambda[i1] = scale * b_H[i1 + 6];
      }
      c_st.site = &ggb_emlrtRSI;
      coder::b_mldivide(&c_st, b_cameraParams.IntrinsicMatrixInternal, lambda,
                        b_r1);
      r1.set_size(&jv_emlrtRTEI, sp, 4);
      r2.set_size(&kv_emlrtRTEI, sp, 4);
      r1[0] = 0;
      r2[0] = 0;
      r1[1] = 1;
      r2[1] = 1;
      r1[2] = 2;
      r2[2] = 2;
      r1[3] = 3;
      r2[3] = 3;
      if (b_i + 1 > camExtrinsics.size(2)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, camExtrinsics.size(2),
                                      &mv_emlrtBCI, (emlrtCTX)sp);
      }
      b_iv[0] = 4;
      b_iv[1] = 4;
      image_point_valid_size[0] = 4;
      image_point_valid_size[1] = 4;
      emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &image_point_valid_size[0], 2,
                                    &vd_emlrtECI, (emlrtCTX)sp);
      st.site = &ufb_emlrtRSI;
      coder::inv(&st, rotationMatrix, a__1);
      for (i1 = 0; i1 < 3; i1++) {
        nz = i1 << 2;
        _1[nz] = a__1[3 * i1];
        _1[nz + 1] = a__1[3 * i1 + 1];
        _1[nz + 2] = a__1[3 * i1 + 2];
        _1[i1 + 12] = b_r1[i1];
      }
      _1[3] = 0.0;
      _1[7] = 0.0;
      _1[11] = 0.0;
      _1[15] = 1.0;
      for (i1 = 0; i1 < 4; i1++) {
        for (i2 = 0; i2 < 4; i2++) {
          camExtrinsics[(r1[i2] + camExtrinsics.size(0) * r2[i1]) +
                        camExtrinsics.size(0) * camExtrinsics.size(1) * b_i] =
              _1[i2 + 4 * i1];
        }
      }
      //  inverted of camExtrinsics
      r1.set_size(&lv_emlrtRTEI, sp, 4);
      r2.set_size(&mv_emlrtRTEI, sp, 4);
      r1[0] = 0;
      r2[0] = 0;
      r1[1] = 1;
      r2[1] = 1;
      r1[2] = 2;
      r2[2] = 2;
      r1[3] = 3;
      r2[3] = 3;
      if (b_i + 1 > cameraPoses.size(2)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, cameraPoses.size(2),
                                      &lv_emlrtBCI, (emlrtCTX)sp);
      }
      b_iv[0] = 4;
      b_iv[1] = 4;
      image_point_valid_size[0] = 4;
      image_point_valid_size[1] = 4;
      emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &image_point_valid_size[0], 2,
                                    &ud_emlrtECI, (emlrtCTX)sp);
      for (i1 = 0; i1 < 9; i1++) {
        c_r1[i1] = -rotationMatrix[i1];
      }
      absxk = b_r1[0];
      t = b_r1[1];
      y = b_r1[2];
      for (i1 = 0; i1 < 3; i1++) {
        nz = i1 << 2;
        _1[nz] = rotationMatrix[3 * i1];
        _1[nz + 1] = rotationMatrix[3 * i1 + 1];
        _1[nz + 2] = rotationMatrix[3 * i1 + 2];
        _1[i1 + 12] = (c_r1[i1] * absxk + c_r1[i1 + 3] * t) + c_r1[i1 + 6] * y;
      }
      _1[3] = 0.0;
      _1[7] = 0.0;
      _1[11] = 0.0;
      _1[15] = 1.0;
      for (i1 = 0; i1 < 4; i1++) {
        for (i2 = 0; i2 < 4; i2++) {
          cameraPoses[(r1[i2] + cameraPoses.size(0) * r2[i1]) +
                      cameraPoses.size(0) * cameraPoses.size(1) * b_i] =
              _1[i2 + 4 * i1];
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    covrtLogFor(&emlrtCoverageInstance, 3, 0, 0, 0);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

// End of code generation (ComputeCamExtrinsics.cpp)
