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
#include "ComputeCamExtrinsics_mex_data.h"
#include "ComputeCamExtrinsics_mex_types.h"
#include "all.h"
#include "any1.h"
#include "cameraParameters.h"
#include "combineVectorElements.h"
#include "detectCheckerboardPoints.h"
#include "extrinsics.h"
#include "generateCheckerboardPoints.h"
#include "inv.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Type Definitions
struct cell_wrap_15 {
  coder::array<real_T, 2U> f1;
};

// Variable Definitions
static emlrtRSInfo emlrtRSI{
    13,                     // lineNo
    "ComputeCamExtrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pathName
};

static emlrtRSInfo b_emlrtRSI{
    15,                     // lineNo
    "ComputeCamExtrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pathName
};

static emlrtRSInfo c_emlrtRSI{
    62,                     // lineNo
    "ComputeCamExtrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pathName
};

static emlrtRSInfo d_emlrtRSI{
    68,                     // lineNo
    "ComputeCamExtrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pathName
};

static emlrtRSInfo e_emlrtRSI{
    70,                     // lineNo
    "ComputeCamExtrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pathName
};

static emlrtRSInfo jb_emlrtRSI{
    12,                         // lineNo
    "extractCheckerboardPoint", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pathName
};

static emlrtRSInfo kb_emlrtRSI{
    34,                         // lineNo
    "extractCheckerboardPoint", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pathName
};

static emlrtRSInfo lb_emlrtRSI{
    42,                         // lineNo
    "extractCheckerboardPoint", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pathName
};

static emlrtRSInfo mb_emlrtRSI{
    52,                         // lineNo
    "extractCheckerboardPoint", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pathName
};

static emlrtRSInfo lw_emlrtRSI{
    15,    // lineNo
    "sum", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" // pathName
};

static emlrtBCInfo emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    68,                     // lineNo
    76,                     // colNo
    "image_points",         // aName
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m", // pName
    0                                                         // checkKind
};

static emlrtBCInfo b_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    70,                     // lineNo
    24,                     // colNo
    "cam_extrinsics",       // aName
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m", // pName
    0                                                         // checkKind
};

static emlrtECInfo emlrtECI{
    -1,                     // nDims
    70,                     // lineNo
    5,                      // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pName
};

static emlrtBCInfo c_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    73,                     // lineNo
    22,                     // colNo
    "camera_poses",         // aName
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m", // pName
    0                                                         // checkKind
};

static emlrtECInfo b_emlrtECI{
    -1,                     // nDims
    73,                     // lineNo
    5,                      // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pName
};

static emlrtBCInfo d_emlrtBCI{
    -1,                         // iFirst
    -1,                         // iLast
    11,                         // lineNo
    32,                         // colNo
    "images",                   // aName
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo e_emlrtBCI{
    -1,                         // iFirst
    -1,                         // iLast
    46,                         // lineNo
    26,                         // colNo
    "image_points",             // aName
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m", // pName
    0                                                   // checkKind
};

static emlrtECInfo c_emlrtECI{
    -1,                         // nDims
    46,                         // lineNo
    9,                          // colNo
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pName
};

static emlrtBCInfo f_emlrtBCI{
    -1,                         // iFirst
    -1,                         // iLast
    46,                         // lineNo
    44,                         // colNo
    "board_points",             // aName
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo g_emlrtBCI{
    -1,                         // iFirst
    -1,                         // iLast
    31,                         // lineNo
    18,                         // colNo
    "board_points",             // aName
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m", // pName
    0                                                   // checkKind
};

static emlrtDCInfo emlrtDCI{
    63,                     // lineNo
    28,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m", // pName
    4                                                         // checkKind
};

static emlrtBCInfo h_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    15,                     // lineNo
    1,                      // colNo
    "board_points",         // aName
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m", // pName
    0                                                         // checkKind
};

static emlrtDCInfo b_emlrtDCI{
    43,                         // lineNo
    22,                         // colNo
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m", // pName
    4                                                   // checkKind
};

static emlrtBCInfo i_emlrtBCI{
    -1,                         // iFirst
    -1,                         // iLast
    16,                         // lineNo
    19,                         // colNo
    "valid_idx",                // aName
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo j_emlrtBCI{
    -1,                         // iFirst
    -1,                         // iLast
    45,                         // lineNo
    18,                         // colNo
    "valid_idx",                // aName
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo k_emlrtBCI{
    -1,                         // iFirst
    -1,                         // iLast
    27,                         // lineNo
    19,                         // colNo
    "valid_idx",                // aName
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo l_emlrtBCI{
    -1,                         // iFirst
    -1,                         // iLast
    31,                         // lineNo
    5,                          // colNo
    "board_points",             // aName
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m", // pName
    0                                                   // checkKind
};

static emlrtRTEInfo wc_emlrtRTEI{
    15,                     // lineNo
    1,                      // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo xc_emlrtRTEI{
    11,                         // lineNo
    19,                         // colNo
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pName
};

static emlrtRTEInfo yc_emlrtRTEI{
    31,                         // lineNo
    5,                          // colNo
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pName
};

static emlrtRTEInfo ad_emlrtRTEI{
    42,                         // lineNo
    27,                         // colNo
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pName
};

static emlrtRTEInfo bd_emlrtRTEI{
    43,                         // lineNo
    1,                          // colNo
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pName
};

static emlrtRTEInfo cd_emlrtRTEI{
    46,                         // lineNo
    22,                         // colNo
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pName
};

static emlrtRTEInfo dd_emlrtRTEI{
    46,                         // lineNo
    24,                         // colNo
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pName
};

static emlrtRTEInfo ed_emlrtRTEI{
    52,                         // lineNo
    1,                          // colNo
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pName
};

static emlrtRTEInfo fd_emlrtRTEI{
    37,                         // lineNo
    5,                          // colNo
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pName
};

static emlrtRTEInfo gd_emlrtRTEI{
    38,                         // lineNo
    5,                          // colNo
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pName
};

static emlrtRTEInfo hd_emlrtRTEI{
    62,                     // lineNo
    27,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo id_emlrtRTEI{
    63,                     // lineNo
    1,                      // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo jd_emlrtRTEI{
    64,                     // lineNo
    1,                      // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo kd_emlrtRTEI{
    68,                     // lineNo
    59,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo ld_emlrtRTEI{
    70,                     // lineNo
    20,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo md_emlrtRTEI{
    70,                     // lineNo
    22,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo nd_emlrtRTEI{
    73,                     // lineNo
    18,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo od_emlrtRTEI{
    73,                     // lineNo
    20,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m" // pName
};

// Function Definitions
void ComputeCamExtrinsics(const emlrtStack *sp,
                          const coder::array<uint8_T, 4U> &images,
                          real_T square_size, const struct0_T *camera_params,
                          coder::array<real_T, 3U> &image_points,
                          coder::array<boolean_T, 1U> &valid_idx,
                          coder::array<real_T, 3U> &cam_extrinsics,
                          coder::array<real_T, 3U> &camera_poses,
                          coder::array<real_T, 2U> &world_points, int32_T *err)
{
  coder::cameraParameters b_camera_params;
  coder::array<cell_wrap_15, 2U> board_points;
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
  real_T c_orientation_matrix[16];
  real_T b_orientation_matrix[9];
  real_T orientation_matrix[9];
  real_T translation_vector[3];
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
  boolean_T c_camera_params[2];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 0);
  //  images: images in a [row x col x channel x numImages] array
  //  square: Checkerboard square size in meter size
  //  camera_params: camera parameters  matlab object
  st.site = &emlrtRSI;
  b_st.site = &f_emlrtRSI;
  c_st.site = &j_emlrtRSI;
  b_st.site = &g_emlrtRSI;
  c_st.site = &l_emlrtRSI;
  coder::cameraParameters::checkIntrinsicMatrix(&c_st,
                                                camera_params->IntrinsicMatrix);
  for (i = 0; i < 3; i++) {
    b_camera_params.IntrinsicMatrixInternal[3 * i] =
        camera_params->IntrinsicMatrix[i];
    b_camera_params.IntrinsicMatrixInternal[3 * i + 1] =
        camera_params->IntrinsicMatrix[i + 3];
    b_camera_params.IntrinsicMatrixInternal[3 * i + 2] =
        camera_params->IntrinsicMatrix[i + 6];
    b_camera_params.RadialDistortion[i] = camera_params->RadialDistortion[i];
  }
  c_st.site = &m_emlrtRSI;
  coder::cameraParameters::checkRadialDistortion(
      &c_st, camera_params->RadialDistortion);
  b_camera_params.TangentialDistortion[0] =
      camera_params->TangentialDistortion[0];
  b_camera_params.TangentialDistortion[1] =
      camera_params->TangentialDistortion[1];
  c_st.site = &n_emlrtRSI;
  coder::cameraParameters::checkTangentialDistortion(
      &c_st, camera_params->TangentialDistortion);
  c_st.site = &o_emlrtRSI;
  d_st.site = &y_emlrtRSI;
  coder::cameraParameters::checkImageSize(&d_st, camera_params->ImageSize);
  b_camera_params.ImageSize[0] = camera_params->ImageSize[0];
  b_camera_params.ImageSize[1] = camera_params->ImageSize[1];
  c_st.site = &p_emlrtRSI;
  coder::cameraParameters::checkImageSize(&c_st, camera_params->ImageSize);
  b_camera_params.RotationVectors.set_size(
      &qc_emlrtRTEI, &b_st, camera_params->RotationVectors.size(0), 3);
  loop_ub = camera_params->RotationVectors.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    b_camera_params.RotationVectors[i] = camera_params->RotationVectors[i];
  }
  c_st.site = &q_emlrtRSI;
  coder::cameraParameters::checkRotationVectors(&c_st,
                                                camera_params->RotationVectors);
  b_camera_params.TranslationVectors.set_size(
      &rc_emlrtRTEI, &b_st, camera_params->TranslationVectors.size(0), 3);
  loop_ub = camera_params->TranslationVectors.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    b_camera_params.TranslationVectors[i] =
        camera_params->TranslationVectors[i];
  }
  c_st.site = &r_emlrtRSI;
  coder::cameraParameters::checkTranslationVectors(
      &c_st, camera_params->TranslationVectors);
  b_camera_params.WorldPoints.set_size(&sc_emlrtRTEI, &b_st,
                                       camera_params->WorldPoints.size(0), 2);
  loop_ub = camera_params->WorldPoints.size(0) * 2;
  for (i = 0; i < loop_ub; i++) {
    b_camera_params.WorldPoints[i] = camera_params->WorldPoints[i];
  }
  b_camera_params.NumRadialDistortionCoefficients =
      camera_params->NumRadialDistortionCoefficients;
  c_st.site = &s_emlrtRSI;
  coder::cameraParameters::checkNumRadialCoeffs(
      &c_st, camera_params->NumRadialDistortionCoefficients);
  b_camera_params.DetectedKeypoints.set_size(
      &tc_emlrtRTEI, &b_st, camera_params->DetectedKeypoints.size(0),
      camera_params->DetectedKeypoints.size(1));
  loop_ub = camera_params->DetectedKeypoints.size(0) *
            camera_params->DetectedKeypoints.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_camera_params.DetectedKeypoints[i] = camera_params->DetectedKeypoints[i];
  }
  if ((camera_params->ReprojectionErrors.size(0) == 0) ||
      (camera_params->ReprojectionErrors.size(2) == 0)) {
    b_camera_params.ReprojectionErrors.set_size(&vc_emlrtRTEI, &b_st, 0, 2, 1);
  } else {
    b_camera_params.ReprojectionErrors.set_size(
        &uc_emlrtRTEI, &b_st, camera_params->ReprojectionErrors.size(0), 2,
        camera_params->ReprojectionErrors.size(2));
    loop_ub = camera_params->ReprojectionErrors.size(0) * 2 *
              camera_params->ReprojectionErrors.size(2);
    for (i = 0; i < loop_ub; i++) {
      b_camera_params.ReprojectionErrors[i] =
          camera_params->ReprojectionErrors[i];
    }
  }
  c_st.site = &t_emlrtRSI;
  if (((camera_params->RotationVectors.size(0) == 0) &&
       (camera_params->TranslationVectors.size(0) != 0)) ||
      ((camera_params->TranslationVectors.size(0) == 0) &&
       (camera_params->RotationVectors.size(0) != 0))) {
    emlrtErrorWithMessageIdR2018a(
        &st, &b_emlrtRTEI,
        "vision:calibrate:rotationAndTranslationVectorsMustBeSetTogether",
        "vision:calibrate:rotationAndTranslationVectorsMustBeSetTogether", 0);
  }
  c_camera_params[0] = (camera_params->RotationVectors.size(0) !=
                        camera_params->TranslationVectors.size(0));
  c_camera_params[1] = false;
  b_st.site = &h_emlrtRSI;
  if (coder::any(c_camera_params)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &c_emlrtRTEI,
        "vision:calibrate:rotationAndTranslationVectorsNotSameSize",
        "vision:calibrate:rotationAndTranslationVectorsNotSameSize", 0);
  }
  if ((b_camera_params.ReprojectionErrors.size(0) != 0) &&
      (b_camera_params.ReprojectionErrors.size(2) != 0) &&
      (camera_params->TranslationVectors.size(0) !=
       b_camera_params.ReprojectionErrors.size(2))) {
    emlrtErrorWithMessageIdR2018a(
        &st, &d_emlrtRTEI, "vision:calibrate:reprojectionErrorsSizeMismatch",
        "vision:calibrate:reprojectionErrorsSizeMismatch", 0);
  }
  b_st.site = &i_emlrtRSI;
  c_st.site = &ib_emlrtRSI;
  st.site = &b_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1, 0);
  *err = 0;
  board_size_valid[0] = 0.0;
  image_point_valid_size[0] = 0;
  board_size_valid[1] = 0.0;
  image_point_valid_size[1] = 0;
  // board_sizes = zeros(num_of_images,1);
  valid_idx.set_size(&wc_emlrtRTEI, &st, images.size(3));
  b_iv[1] = images.size(3);
  board_points.set_size(&wc_emlrtRTEI, &st, 1, images.size(3));
  for (i = 0; i < b_iv[1]; i++) {
    loop_ub = board_points.size(1) - 1;
    if (i > board_points.size(1) - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, board_points.size(1) - 1, &h_emlrtBCI,
                                    &st);
    }
    board_points[board_points.size(0) * i].f1.set_size(
        &wc_emlrtRTEI, &st, 0,
        board_points[board_points.size(0) * i].f1.size(1));
    if (i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i, 0, loop_ub, &h_emlrtBCI, &st);
    }
    board_points[board_points.size(0) * i].f1.set_size(
        &wc_emlrtRTEI, &st, board_points[board_points.size(0) * i].f1.size(0),
        0);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  i = images.size(3);
  board_points.set_size(&wc_emlrtRTEI, &st, 1, images.size(3));
  for (b_i = 0; b_i < i; b_i++) {
    boolean_T exitg1;
    boolean_T p;
    covrtLogFor(&emlrtCoverageInstance, 1, 0, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 1);
    //  perform checkerboards detection in each image
    if (b_i + 1 > images.size(3)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, images.size(3), &d_emlrtBCI,
                                    &st);
    }
    loop_ub = images.size(0);
    nz = images.size(1);
    b_images.set_size(&xc_emlrtRTEI, &st, images.size(0), images.size(1));
    for (i1 = 0; i1 < nz; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_images[i2 + b_images.size(0) * i1] =
            images[(i2 + images.size(0) * i1) +
                   images.size(0) * images.size(1) * b_i];
      }
    }
    b_st.site = &jb_emlrtRSI;
    coder::detectCheckerboardPoints(&b_st, b_images, current_board_points,
                                    board_size_detected);
    //  mark if checkerboards is detected or not
    p = true;
    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub < 2)) {
      if (!(board_size_detected[loop_ub] == 0.0)) {
        p = false;
        exitg1 = true;
      } else {
        loop_ub++;
      }
    }
    if (covrtLogCond(&emlrtCoverageInstance, 1, 0, 0, p)) {
      covrtLogMcdc(&emlrtCoverageInstance, 1, 0, 0, true);
      covrtLogIf(&emlrtCoverageInstance, 1, 0, 0, true);
      covrtLogBasicBlock(&emlrtCoverageInstance, 1, 2);
      if (b_i + 1 > valid_idx.size(0)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, valid_idx.size(0),
                                      &i_emlrtBCI, &st);
      }
      valid_idx[b_i] = false;
    } else {
      covrtLogCond(&emlrtCoverageInstance, 1, 0, 1, true);
      covrtLogMcdc(&emlrtCoverageInstance, 1, 0, 0, false);
      covrtLogIf(&emlrtCoverageInstance, 1, 0, 0, false);
      p = true;
      loop_ub = 0;
      exitg1 = false;
      while ((!exitg1) && (loop_ub < 2)) {
        if (!(board_size_valid[loop_ub] == 0.0)) {
          p = false;
          exitg1 = true;
        } else {
          loop_ub++;
        }
      }
      if (covrtLogIf(&emlrtCoverageInstance, 1, 0, 1, p)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 1, 3);
        board_size_valid[0] = board_size_detected[0];
        image_point_valid_size[0] = current_board_points.size(0);
        board_size_valid[1] = board_size_detected[1];
        image_point_valid_size[1] = current_board_points.size(1);
      } else {
        p = true;
        loop_ub = 0;
        exitg1 = false;
        while ((!exitg1) && (loop_ub < 2)) {
          if (!(board_size_valid[loop_ub] == board_size_detected[loop_ub])) {
            p = false;
            exitg1 = true;
          } else {
            loop_ub++;
          }
        }
        if (covrtLogIf(&emlrtCoverageInstance, 1, 0, 2,
                       covrtLogMcdc(&emlrtCoverageInstance, 1, 0, 1,
                                    !covrtLogCond(&emlrtCoverageInstance, 1, 0,
                                                  3, p)))) {
          covrtLogBasicBlock(&emlrtCoverageInstance, 1, 4);
          *err = -1;
          // return;
        }
      }
      covrtLogBasicBlock(&emlrtCoverageInstance, 1, 5);
      if (b_i + 1 > valid_idx.size(0)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, valid_idx.size(0),
                                      &k_emlrtBCI, &st);
      }
      valid_idx[b_i] = true;
    }
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 6);
    loop_ub = current_board_points.size(0) * current_board_points.size(1);
    if (b_i > board_points.size(1) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(1) - 1,
                                    &g_emlrtBCI, &st);
    }
    board_points[board_points.size(0) * b_i].f1.set_size(
        &yc_emlrtRTEI, &st, current_board_points.size(0),
        board_points[board_points.size(0) * b_i].f1.size(1));
    if (b_i > board_points.size(1) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(1) - 1,
                                    &g_emlrtBCI, &st);
    }
    board_points[board_points.size(0) * b_i].f1.set_size(
        &yc_emlrtRTEI, &st, board_points[board_points.size(0) * b_i].f1.size(0),
        current_board_points.size(1));
    i1 = board_points.size(1);
    if (b_i > board_points.size(1) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(1) - 1,
                                    &g_emlrtBCI, &st);
    }
    if (b_i > board_points.size(1) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(1) - 1,
                                    &g_emlrtBCI, &st);
    }
    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &l_emlrtBCI, &st);
      }
      board_points[b_i].f1[i2] = current_board_points[i2];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 1, 0, 0, 0);
  b_st.site = &kb_emlrtRSI;
  if (covrtLogIf(&emlrtCoverageInstance, 1, 0, 3,
                 covrtLogMcdc(&emlrtCoverageInstance, 1, 0, 2,
                              !covrtLogCond(&emlrtCoverageInstance, 1, 0, 4,
                                            coder::all(&b_st, valid_idx))))) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 7);
    // err = "Wrong detection of board size";
    *err = -1;
    image_points.set_size(&fd_emlrtRTEI, &st, 0, 0, 1);
    world_points.set_size(&gd_emlrtRTEI, &st, 0, 0);
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 8);
    b_st.site = &lb_emlrtRSI;
    x.set_size(&ad_emlrtRTEI, &b_st, valid_idx.size(0));
    loop_ub = valid_idx.size(0);
    for (i = 0; i < loop_ub; i++) {
      x[i] = valid_idx[i];
    }
    c_st.site = &lw_emlrtRSI;
    d_st.site = &cp_emlrtRSI;
    nz = coder::combineVectorElements(&d_st, x);
    if (nz < 0) {
      emlrtNonNegativeCheckR2012b(static_cast<real_T>(nz), &b_emlrtDCI, &st);
    }
    image_points.set_size(&bd_emlrtRTEI, &st, image_point_valid_size[0],
                          image_point_valid_size[1], nz);
    loop_ub = image_point_valid_size[0] * image_point_valid_size[1] * nz;
    for (i = 0; i < loop_ub; i++) {
      image_points[i] = 0.0;
    }
    i = images.size(3);
    for (b_i = 0; b_i < i; b_i++) {
      covrtLogFor(&emlrtCoverageInstance, 1, 0, 1, 1);
      if (b_i + 1 > valid_idx.size(0)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, valid_idx.size(0),
                                      &j_emlrtBCI, &st);
      }
      if (covrtLogIf(&emlrtCoverageInstance, 1, 0, 4, valid_idx[b_i])) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 1, 9);
        loop_ub = image_points.size(0);
        r1.set_size(&cd_emlrtRTEI, &st, image_points.size(0));
        for (i1 = 0; i1 < loop_ub; i1++) {
          r1[i1] = i1;
        }
        loop_ub = image_points.size(1);
        r2.set_size(&dd_emlrtRTEI, &st, image_points.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          r2[i1] = i1;
        }
        if (b_i + 1 > image_points.size(2)) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, image_points.size(2),
                                        &e_emlrtBCI, &st);
        }
        if (b_i > board_points.size(1) - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(1) - 1,
                                        &f_emlrtBCI, &st);
        }
        b_iv[0] = r1.size(0);
        b_iv[1] = r2.size(0);
        emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, board_points[b_i].f1.size(),
                                      2, &c_emlrtECI, &st);
        loop_ub = board_points[b_i].f1.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          nz = board_points[b_i].f1.size(0);
          for (i2 = 0; i2 < nz; i2++) {
            image_points[(r1[i2] + image_points.size(0) * r2[i1]) +
                         image_points.size(0) * image_points.size(1) * b_i] =
                board_points[b_i].f1[i2 + board_points[b_i].f1.size(0) * i1];
          }
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    covrtLogFor(&emlrtCoverageInstance, 1, 0, 1, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 10);
    //  Generate world coordinates of the corners of the squares in meters
    b_st.site = &mb_emlrtRSI;
    coder::generateCheckerboardPoints(&b_st, board_size_valid, square_size, r);
    world_points.set_size(&ed_emlrtRTEI, &st, r.size(0), 2);
    loop_ub = r.size(0) * 2;
    for (i = 0; i < loop_ub; i++) {
      world_points[i] = r[i];
    }
  }
  // {
  //  Detect checkerboards in images
  // valid_idx = false(num_of_images,1);
  // board_points = cell(num_of_images,1);
  // board_sizes = cell(num_of_images,1);
  // valid_counter = int32(0);
  // for i=1:num_of_images
  // 	% perform checkerboards detection in each image
  //     current_image=images(:,:,:,i);
  //     [current_board_points, board_size_detected] =
  //     detectCheckerboardPoints(current_image, 'PartialDetections', false);
  //
  // 	% mark if checkerboards is detected or not
  //     if (isequal(board_size_detected, [0 0]))
  //         valid_idx(i)=false;
  //     else
  //         valid_idx(i)=true;
  //     end
  //     board_points{i} = current_board_points;
  //     board_sizes{i} = board_size_detected;
  //
  // end
  //
  // if ~all(valid_idx)
  //     %err = "Error during detection of checkerboard in images";
  //     err = int32(-1);
  //     return;
  // end
  //
  // num_of_valid_images = sum(valid_idx(:) == true);
  // image_points = zeros([size(board_points{1}) num_of_valid_images]);
  // board_size = zeros(1,2);
  // for i=1:num_of_valid_images
  //     if valid_idx(i)
  //         if (isequal(board_size, [0 0]))
  //             board_size = board_sizes{i};
  //         elseif (~isequal(board_size, board_sizes{i}))
  //               %err = "Detect checker board with different size at " +
  //               int2str(i); err = int32(-1); return;
  //         end
  //         image_points(:,:,i) = board_points{i};
  //     end
  // end
  // }
  //  compute extrinsics
  st.site = &c_emlrtRSI;
  x.set_size(&hd_emlrtRTEI, &st, valid_idx.size(0));
  loop_ub = valid_idx.size(0);
  for (i = 0; i < loop_ub; i++) {
    x[i] = valid_idx[i];
  }
  b_st.site = &lw_emlrtRSI;
  c_st.site = &cp_emlrtRSI;
  nz = coder::combineVectorElements(&c_st, x);
  cam_extrinsics.set_size(&id_emlrtRTEI, sp, 4, 4, cam_extrinsics.size(2));
  if (nz < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(nz), &emlrtDCI,
                                (emlrtCTX)sp);
  }
  cam_extrinsics.set_size(&id_emlrtRTEI, sp, cam_extrinsics.size(0),
                          cam_extrinsics.size(1), nz);
  loop_ub = nz << 4;
  for (i = 0; i < loop_ub; i++) {
    cam_extrinsics[i] = 0.0;
  }
  camera_poses.set_size(&jd_emlrtRTEI, sp, 4, 4, camera_poses.size(2));
  camera_poses.set_size(&jd_emlrtRTEI, sp, camera_poses.size(0),
                        camera_poses.size(1), nz);
  for (i = 0; i < loop_ub; i++) {
    camera_poses[i] = 0.0;
  }
  if (0 <= nz - 1) {
    b_loop_ub = image_points.size(0);
    c_loop_ub = image_points.size(1);
  }
  for (b_i = 0; b_i < nz; b_i++) {
    real_T d;
    real_T d1;
    real_T d2;
    covrtLogFor(&emlrtCoverageInstance, 0, 0, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 1);
    //  transformations from the grid/world coordinates to the camera-based
    //  coordinates
    if (static_cast<int32_T>(b_i + 1U) > image_points.size(2)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i + 1U), 1,
                                    image_points.size(2), &emlrtBCI,
                                    (emlrtCTX)sp);
    }
    current_board_points.set_size(&kd_emlrtRTEI, sp, image_points.size(0),
                                  image_points.size(1));
    for (i = 0; i < c_loop_ub; i++) {
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        current_board_points[i1 + current_board_points.size(0) * i] =
            image_points[(i1 + image_points.size(0) * i) +
                         image_points.size(0) * image_points.size(1) * b_i];
      }
    }
    st.site = &d_emlrtRSI;
    coder::extrinsics(&st, current_board_points, world_points, &b_camera_params,
                      orientation_matrix, translation_vector);
    r1.set_size(&ld_emlrtRTEI, sp, 4);
    r2.set_size(&md_emlrtRTEI, sp, 4);
    r1[0] = 0;
    r2[0] = 0;
    r1[1] = 1;
    r2[1] = 1;
    r1[2] = 2;
    r2[2] = 2;
    r1[3] = 3;
    r2[3] = 3;
    if (b_i + 1 > cam_extrinsics.size(2)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, cam_extrinsics.size(2),
                                    &b_emlrtBCI, (emlrtCTX)sp);
    }
    b_iv[0] = 4;
    b_iv[1] = 4;
    image_point_valid_size[0] = 4;
    image_point_valid_size[1] = 4;
    emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &image_point_valid_size[0], 2,
                                  &emlrtECI, (emlrtCTX)sp);
    st.site = &e_emlrtRSI;
    coder::inv(&st, orientation_matrix, b_orientation_matrix);
    for (i = 0; i < 3; i++) {
      loop_ub = i << 2;
      c_orientation_matrix[loop_ub] = b_orientation_matrix[3 * i];
      c_orientation_matrix[loop_ub + 1] = b_orientation_matrix[3 * i + 1];
      c_orientation_matrix[loop_ub + 2] = b_orientation_matrix[3 * i + 2];
      c_orientation_matrix[i + 12] = translation_vector[i];
    }
    c_orientation_matrix[3] = 0.0;
    c_orientation_matrix[7] = 0.0;
    c_orientation_matrix[11] = 0.0;
    c_orientation_matrix[15] = 1.0;
    for (i = 0; i < 4; i++) {
      for (i1 = 0; i1 < 4; i1++) {
        cam_extrinsics[(r1[i1] + cam_extrinsics.size(0) * r2[i]) +
                       cam_extrinsics.size(0) * cam_extrinsics.size(1) * b_i] =
            c_orientation_matrix[i1 + 4 * i];
      }
    }
    //  inverted of cam_extrinsics
    r1.set_size(&nd_emlrtRTEI, sp, 4);
    r2.set_size(&od_emlrtRTEI, sp, 4);
    r1[0] = 0;
    r2[0] = 0;
    r1[1] = 1;
    r2[1] = 1;
    r1[2] = 2;
    r2[2] = 2;
    r1[3] = 3;
    r2[3] = 3;
    if (b_i + 1 > camera_poses.size(2)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, camera_poses.size(2),
                                    &c_emlrtBCI, (emlrtCTX)sp);
    }
    b_iv[0] = 4;
    b_iv[1] = 4;
    image_point_valid_size[0] = 4;
    image_point_valid_size[1] = 4;
    emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &image_point_valid_size[0], 2,
                                  &b_emlrtECI, (emlrtCTX)sp);
    for (i = 0; i < 9; i++) {
      b_orientation_matrix[i] = -orientation_matrix[i];
    }
    d = translation_vector[0];
    d1 = translation_vector[1];
    d2 = translation_vector[2];
    for (i = 0; i < 3; i++) {
      loop_ub = i << 2;
      c_orientation_matrix[loop_ub] = orientation_matrix[3 * i];
      c_orientation_matrix[loop_ub + 1] = orientation_matrix[3 * i + 1];
      c_orientation_matrix[loop_ub + 2] = orientation_matrix[3 * i + 2];
      c_orientation_matrix[i + 12] =
          (b_orientation_matrix[i] * d + b_orientation_matrix[i + 3] * d1) +
          b_orientation_matrix[i + 6] * d2;
    }
    c_orientation_matrix[3] = 0.0;
    c_orientation_matrix[7] = 0.0;
    c_orientation_matrix[11] = 0.0;
    c_orientation_matrix[15] = 1.0;
    for (i = 0; i < 4; i++) {
      for (i1 = 0; i1 < 4; i1++) {
        camera_poses[(r1[i1] + camera_poses.size(0) * r2[i]) +
                     camera_poses.size(0) * camera_poses.size(1) * b_i] =
            c_orientation_matrix[i1 + 4 * i];
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 0, 0, 0, 0);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

// End of code generation (ComputeCamExtrinsics.cpp)
