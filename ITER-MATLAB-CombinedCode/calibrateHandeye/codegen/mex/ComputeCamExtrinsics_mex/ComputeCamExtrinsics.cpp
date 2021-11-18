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
#include "detectCheckerboardPoints.h"
#include "eml_int_forloop_overflow_check.h"
#include "extrinsics.h"
#include "generateCheckerboardPoints.h"
#include "inv.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Type Definitions
struct cell_wrap_1 {
  real_T f1[2];
};

struct cell_wrap_0 {
  coder::array<real_T, 2U> f1;
};

// Variable Definitions
static emlrtRSInfo emlrtRSI{
    13,                     // lineNo
    "ComputeCamExtrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pathName
};

static emlrtRSInfo b_emlrtRSI{
    23,                     // lineNo
    "ComputeCamExtrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pathName
};

static emlrtRSInfo c_emlrtRSI{
    36,                     // lineNo
    "ComputeCamExtrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pathName
};

static emlrtRSInfo d_emlrtRSI{
    42,                     // lineNo
    "ComputeCamExtrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pathName
};

static emlrtRSInfo e_emlrtRSI{
    59,                     // lineNo
    "ComputeCamExtrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pathName
};

static emlrtRSInfo f_emlrtRSI{
    68,                     // lineNo
    "ComputeCamExtrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pathName
};

static emlrtRSInfo g_emlrtRSI{
    70,                     // lineNo
    "ComputeCamExtrinsics", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pathName
};

static emlrtRSInfo m_emlrtRSI{
    6,                       // lineNo
    "HandleBase/HandleBase", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "enforcescalar\\HandleBase.m" // pathName
};

static emlrtRSInfo hb_emlrtRSI{
    651,                                            // lineNo
    "CameraParametersImpl/checkReprojectionErrors", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo jw_emlrtRSI{
    15,    // lineNo
    "sum", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" // pathName
};

static emlrtRSInfo kw_emlrtRSI{
    138,                     // lineNo
    "combineVectorElements", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" // pathName
};

static emlrtRSInfo lw_emlrtRSI{
    198,                // lineNo
    "colMajorFlatIter", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" // pathName
};

static emlrtBCInfo emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    54,                     // lineNo
    44,                     // colNo
    "board_points",         // aName
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m", // pName
    0                               // checkKind
};

static emlrtBCInfo b_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    49,                     // lineNo
    50,                     // colNo
    "board_sizes",          // aName
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m", // pName
    0                               // checkKind
};

static emlrtBCInfo c_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    43,                     // lineNo
    41,                     // colNo
    "board_points",         // aName
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m", // pName
    0                               // checkKind
};

static emlrtECInfo emlrtECI{
    -1,                     // nDims
    73,                     // lineNo
    5,                      // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pName
};

static emlrtBCInfo d_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    73,                     // lineNo
    22,                     // colNo
    "camera_poses",         // aName
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m", // pName
    0                               // checkKind
};

static emlrtECInfo b_emlrtECI{
    -1,                     // nDims
    70,                     // lineNo
    5,                      // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pName
};

static emlrtBCInfo e_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    70,                     // lineNo
    24,                     // colNo
    "cam_extrinsics",       // aName
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m", // pName
    0                               // checkKind
};

static emlrtBCInfo f_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    68,                     // lineNo
    76,                     // colNo
    "image_points",         // aName
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m", // pName
    0                               // checkKind
};

static emlrtECInfo c_emlrtECI{
    -1,                     // nDims
    54,                     // lineNo
    9,                      // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pName
};

static emlrtBCInfo g_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    54,                     // lineNo
    26,                     // colNo
    "image_points",         // aName
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m", // pName
    0                               // checkKind
};

static emlrtDCInfo emlrtDCI{
    54,                     // lineNo
    44,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m", // pName
    1                               // checkKind
};

static emlrtDCInfo b_emlrtDCI{
    49,                     // lineNo
    50,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m", // pName
    1                               // checkKind
};

static emlrtBCInfo h_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    22,                     // lineNo
    32,                     // colNo
    "images",               // aName
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m", // pName
    0                               // checkKind
};

static emlrtBCInfo i_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    18,                     // lineNo
    35,                     // colNo
    "board_points",         // aName
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m", // pName
    0                               // checkKind
};

static emlrtBCInfo j_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    31,                     // lineNo
    18,                     // colNo
    "board_points",         // aName
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m", // pName
    0                               // checkKind
};

static emlrtBCInfo k_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    29,                     // lineNo
    19,                     // colNo
    "valid_idx",            // aName
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m", // pName
    0                               // checkKind
};

static emlrtBCInfo l_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    27,                     // lineNo
    19,                     // colNo
    "valid_idx",            // aName
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m", // pName
    0                               // checkKind
};

static emlrtDCInfo c_emlrtDCI{
    43,                     // lineNo
    22,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m", // pName
    4                               // checkKind
};

static emlrtBCInfo m_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    46,                     // lineNo
    18,                     // colNo
    "valid_idx",            // aName
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m", // pName
    0                               // checkKind
};

static emlrtBCInfo n_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    48,                     // lineNo
    26,                     // colNo
    "board_sizes",          // aName
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m", // pName
    0                               // checkKind
};

static emlrtDCInfo d_emlrtDCI{
    48,                     // lineNo
    26,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m", // pName
    1                               // checkKind
};

static emlrtBCInfo o_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    32,                     // lineNo
    5,                      // colNo
    "board_sizes",          // aName
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m", // pName
    0                               // checkKind
};

static emlrtRTEInfo tc_emlrtRTEI{
    7,                      // lineNo
    16,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo uc_emlrtRTEI{
    9,                      // lineNo
    1,                      // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo vc_emlrtRTEI{
    10,                     // lineNo
    1,                      // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo wc_emlrtRTEI{
    11,                     // lineNo
    1,                      // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo ed_emlrtRTEI{
    17,                     // lineNo
    13,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo fd_emlrtRTEI{
    5,                      // lineNo
    85,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo gd_emlrtRTEI{
    18,                     // lineNo
    35,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo hd_emlrtRTEI{
    22,                     // lineNo
    19,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo id_emlrtRTEI{
    42,                     // lineNo
    27,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo jd_emlrtRTEI{
    43,                     // lineNo
    1,                      // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo kd_emlrtRTEI{
    59,                     // lineNo
    1,                      // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo ld_emlrtRTEI{
    63,                     // lineNo
    1,                      // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo md_emlrtRTEI{
    64,                     // lineNo
    1,                      // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo nd_emlrtRTEI{
    68,                     // lineNo
    59,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo od_emlrtRTEI{
    70,                     // lineNo
    20,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo pd_emlrtRTEI{
    70,                     // lineNo
    22,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo qd_emlrtRTEI{
    73,                     // lineNo
    18,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo rd_emlrtRTEI{
    73,                     // lineNo
    20,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo sd_emlrtRTEI{
    54,                     // lineNo
    22,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pName
};

static emlrtRTEInfo td_emlrtRTEI{
    54,                     // lineNo
    24,                     // colNo
    "ComputeCamExtrinsics", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\ComputeCamExtrinsics.m" // pName
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
  coder::array<real_T, 3U> *reprojErrors;
  coder::cameraParameters b_camera_params;
  coder::array<cell_wrap_0, 1U> board_points;
  coder::array<cell_wrap_1, 1U> board_sizes;
  coder::array<real_T, 2U> b_image_points;
  coder::array<real_T, 2U> r;
  coder::array<int32_T, 1U> r1;
  coder::array<int32_T, 1U> r2;
  coder::array<uint8_T, 2U> b_images;
  coder::array<boolean_T, 1U> x;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T c_orientation_matrix[16];
  real_T b_orientation_matrix[9];
  real_T orientation_matrix[9];
  real_T translation_vector[3];
  real_T board_size[2];
  int32_T b_iv[2];
  int32_T iv1[2];
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T nz;
  int32_T vlen;
  boolean_T c_camera_params[2];
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
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 0);
  //  images: images in a [row x col x channel x numImages] array
  //  square: Checkerboard square size in meter size
  //  camera_params: camera parameters  matlab object
  image_points.set_size(&tc_emlrtRTEI, sp, 0, 0, 1);
  cam_extrinsics.set_size(&uc_emlrtRTEI, sp, 0, 0, 1);
  camera_poses.set_size(&vc_emlrtRTEI, sp, 0, 0, 1);
  world_points.set_size(&wc_emlrtRTEI, sp, 0, 0);
  *err = 0;
  st.site = &emlrtRSI;
  b_st.site = &h_emlrtRSI;
  c_st.site = &l_emlrtRSI;
  d_st.site = &m_emlrtRSI;
  b_st.site = &i_emlrtRSI;
  c_st.site = &n_emlrtRSI;
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
  c_st.site = &o_emlrtRSI;
  coder::cameraParameters::checkRadialDistortion(
      &c_st, camera_params->RadialDistortion);
  b_camera_params.TangentialDistortion[0] =
      camera_params->TangentialDistortion[0];
  b_camera_params.TangentialDistortion[1] =
      camera_params->TangentialDistortion[1];
  c_st.site = &p_emlrtRSI;
  coder::cameraParameters::checkTangentialDistortion(
      &c_st, camera_params->TangentialDistortion);
  c_st.site = &q_emlrtRSI;
  d_st.site = &bb_emlrtRSI;
  coder::cameraParameters::checkImageSize(&d_st, camera_params->ImageSize);
  b_camera_params.ImageSize[0] = camera_params->ImageSize[0];
  b_camera_params.ImageSize[1] = camera_params->ImageSize[1];
  c_st.site = &r_emlrtRSI;
  coder::cameraParameters::checkImageSize(&c_st, camera_params->ImageSize);
  b_camera_params.RotationVectors.set_size(
      &xc_emlrtRTEI, &b_st, camera_params->RotationVectors.size(0), 3);
  loop_ub = camera_params->RotationVectors.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    b_camera_params.RotationVectors[i] = camera_params->RotationVectors[i];
  }
  c_st.site = &s_emlrtRSI;
  coder::cameraParameters::checkRotationVectors(&c_st,
                                                camera_params->RotationVectors);
  b_camera_params.TranslationVectors.set_size(
      &yc_emlrtRTEI, &b_st, camera_params->TranslationVectors.size(0), 3);
  loop_ub = camera_params->TranslationVectors.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    b_camera_params.TranslationVectors[i] =
        camera_params->TranslationVectors[i];
  }
  c_st.site = &t_emlrtRSI;
  coder::cameraParameters::checkTranslationVectors(
      &c_st, camera_params->TranslationVectors);
  b_camera_params.WorldPoints.set_size(&ad_emlrtRTEI, &b_st,
                                       camera_params->WorldPoints.size(0), 2);
  loop_ub = camera_params->WorldPoints.size(0) * 2;
  for (i = 0; i < loop_ub; i++) {
    b_camera_params.WorldPoints[i] = camera_params->WorldPoints[i];
  }
  b_camera_params.NumRadialDistortionCoefficients =
      camera_params->NumRadialDistortionCoefficients;
  c_st.site = &u_emlrtRSI;
  coder::cameraParameters::checkNumRadialCoeffs(
      &c_st, camera_params->NumRadialDistortionCoefficients);
  b_camera_params.DetectedKeypoints.set_size(
      &bd_emlrtRTEI, &b_st, camera_params->DetectedKeypoints.size(0),
      camera_params->DetectedKeypoints.size(1));
  loop_ub = camera_params->DetectedKeypoints.size(0) *
            camera_params->DetectedKeypoints.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_camera_params.DetectedKeypoints[i] = camera_params->DetectedKeypoints[i];
  }
  if ((camera_params->ReprojectionErrors.size(0) == 0) ||
      (camera_params->ReprojectionErrors.size(2) == 0)) {
    b_camera_params.ReprojectionErrors.set_size(&dd_emlrtRTEI, &b_st, 0, 2, 1);
  } else {
    b_camera_params.ReprojectionErrors.set_size(
        &cd_emlrtRTEI, &b_st, camera_params->ReprojectionErrors.size(0), 2,
        camera_params->ReprojectionErrors.size(2));
    loop_ub = camera_params->ReprojectionErrors.size(0) * 2 *
              camera_params->ReprojectionErrors.size(2);
    for (i = 0; i < loop_ub; i++) {
      b_camera_params.ReprojectionErrors[i] =
          camera_params->ReprojectionErrors[i];
    }
  }
  c_st.site = &v_emlrtRSI;
  reprojErrors = &b_camera_params.ReprojectionErrors;
  if ((reprojErrors->size(0) != 0) && (reprojErrors->size(2) != 0)) {
    d_st.site = &hb_emlrtRSI;
    e_st.site = &x_emlrtRSI;
  }
  if (((camera_params->RotationVectors.size(0) == 0) &&
       (camera_params->TranslationVectors.size(0) != 0)) ||
      ((camera_params->TranslationVectors.size(0) == 0) &&
       (camera_params->RotationVectors.size(0) != 0))) {
    emlrtErrorWithMessageIdR2018a(
        &st, &c_emlrtRTEI,
        "vision:calibrate:rotationAndTranslationVectorsMustBeSetTogether",
        "vision:calibrate:rotationAndTranslationVectorsMustBeSetTogether", 0);
  }
  c_camera_params[0] = (camera_params->RotationVectors.size(0) !=
                        camera_params->TranslationVectors.size(0));
  c_camera_params[1] = false;
  b_st.site = &j_emlrtRSI;
  if (coder::any(c_camera_params)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &b_emlrtRTEI,
        "vision:calibrate:rotationAndTranslationVectorsNotSameSize",
        "vision:calibrate:rotationAndTranslationVectorsNotSameSize", 0);
  }
  if ((b_camera_params.ReprojectionErrors.size(0) != 0) &&
      (b_camera_params.ReprojectionErrors.size(2) != 0) &&
      (camera_params->TranslationVectors.size(0) !=
       b_camera_params.ReprojectionErrors.size(2))) {
    emlrtErrorWithMessageIdR2018a(
        &st, &emlrtRTEI, "vision:calibrate:reprojectionErrorsSizeMismatch",
        "vision:calibrate:reprojectionErrorsSizeMismatch", 0);
  }
  b_st.site = &k_emlrtRSI;
  c_st.site = &kb_emlrtRSI;
  //  Detect checkerboards in images
  valid_idx.set_size(&ed_emlrtRTEI, sp, images.size(3));
  vlen = images.size(3);
  board_points.set_size(&fd_emlrtRTEI, sp, images.size(3));
  for (i = 0; i < vlen; i++) {
    loop_ub = board_points.size(0) - 1;
    if (i > board_points.size(0) - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, board_points.size(0) - 1, &i_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    board_points[i].f1.set_size(&fd_emlrtRTEI, sp, 0,
                                board_points[i].f1.size(1));
    if (i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i, 0, loop_ub, &i_emlrtBCI, (emlrtCTX)sp);
    }
    board_points[i].f1.set_size(&fd_emlrtRTEI, sp, board_points[i].f1.size(0),
                                0);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = images.size(3);
  board_points.set_size(&gd_emlrtRTEI, sp, images.size(3));
  board_sizes.set_size(&gd_emlrtRTEI, sp, images.size(3));
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 0, 0, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 1);
    //  perform checkerboards detection in each image
    if (b_i + 1 > images.size(3)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, images.size(3), &h_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    loop_ub = images.size(0);
    vlen = images.size(1);
    b_images.set_size(&hd_emlrtRTEI, sp, images.size(0), images.size(1));
    for (i1 = 0; i1 < vlen; i1++) {
      for (nz = 0; nz < loop_ub; nz++) {
        b_images[nz + b_images.size(0) * i1] =
            images[(nz + images.size(0) * i1) +
                   images.size(0) * images.size(1) * b_i];
      }
    }
    if (b_i > board_points.size(0) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(0) - 1,
                                    &j_emlrtBCI, (emlrtCTX)sp);
    }
    st.site = &b_emlrtRSI;
    coder::detectCheckerboardPoints(&st, b_images, board_points[b_i].f1,
                                    board_size);
    //  mark if checkerboards is detected or not
    p = true;
    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub < 2)) {
      if (!(board_size[loop_ub] == 0.0)) {
        p = false;
        exitg1 = true;
      } else {
        loop_ub++;
      }
    }
    if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 0, p)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 2);
      if (b_i + 1 > valid_idx.size(0)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, valid_idx.size(0),
                                      &l_emlrtBCI, (emlrtCTX)sp);
      }
      valid_idx[b_i] = false;
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 3);
      if (b_i + 1 > valid_idx.size(0)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, valid_idx.size(0),
                                      &k_emlrtBCI, (emlrtCTX)sp);
      }
      valid_idx[b_i] = true;
    }
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 4);
    vlen = board_sizes.size(0) - 1;
    if (b_i > board_sizes.size(0) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, board_sizes.size(0) - 1,
                                    &o_emlrtBCI, (emlrtCTX)sp);
    }
    board_sizes[b_i].f1[0] = board_size[0];
    if (b_i > vlen) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, vlen, &o_emlrtBCI, (emlrtCTX)sp);
    }
    board_sizes[b_i].f1[1] = board_size[1];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 0, 0, 0, 0);
  st.site = &c_emlrtRSI;
  if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 1,
                 covrtLogMcdc(&emlrtCoverageInstance, 0, 0, 0,
                              !covrtLogCond(&emlrtCoverageInstance, 0, 0, 0,
                                            coder::all(&st, valid_idx))))) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 5);
    // err = "Error during detection of checkerboard in images";
    *err = -1;
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 6);
    st.site = &d_emlrtRSI;
    x.set_size(&id_emlrtRTEI, &st, valid_idx.size(0));
    loop_ub = valid_idx.size(0);
    for (i = 0; i < loop_ub; i++) {
      x[i] = valid_idx[i];
    }
    b_st.site = &jw_emlrtRSI;
    c_st.site = &ap_emlrtRSI;
    vlen = x.size(0);
    if (x.size(0) == 0) {
      nz = 0;
    } else {
      d_st.site = &kw_emlrtRSI;
      nz = x[0];
      e_st.site = &lw_emlrtRSI;
      if ((2 <= x.size(0)) && (x.size(0) > 2147483646)) {
        f_st.site = &cd_emlrtRSI;
        coder::check_forloop_overflow_error(&f_st);
      }
      for (loop_ub = 2; loop_ub <= vlen; loop_ub++) {
        nz += x[loop_ub - 1];
      }
    }
    if (0 > board_points.size(0) - 1) {
      emlrtDynamicBoundsCheckR2012b(0, 0, board_points.size(0) - 1, &c_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (nz < 0) {
      emlrtNonNegativeCheckR2012b(static_cast<real_T>(nz), &c_emlrtDCI,
                                  (emlrtCTX)sp);
    }
    image_points.set_size(&jd_emlrtRTEI, sp, board_points[0].f1.size(0),
                          board_points[0].f1.size(1), nz);
    loop_ub = board_points[0].f1.size(0) * board_points[0].f1.size(1) * nz;
    for (i = 0; i < loop_ub; i++) {
      image_points[i] = 0.0;
    }
    board_size[0] = 0.0;
    board_size[1] = 0.0;
    b_i = 0;
    int32_T exitg2;
    do {
      exitg2 = 0;
      if (b_i <= nz - 1) {
        boolean_T guard1{false};
        boolean_T guard2{false};
        covrtLogFor(&emlrtCoverageInstance, 0, 0, 1, 1);
        if (b_i + 1 > valid_idx.size(0)) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, valid_idx.size(0),
                                        &m_emlrtBCI, (emlrtCTX)sp);
        }
        guard1 = false;
        guard2 = false;
        if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 2, valid_idx[b_i])) {
          p = true;
          loop_ub = 0;
          exitg1 = false;
          while ((!exitg1) && (loop_ub < 2)) {
            if (!(board_size[loop_ub] == 0.0)) {
              p = false;
              exitg1 = true;
            } else {
              loop_ub++;
            }
          }
          if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 3, p)) {
            covrtLogBasicBlock(&emlrtCoverageInstance, 0, 7);
            if (b_i + 1 != b_i + 1) {
              emlrtIntegerCheckR2012b(static_cast<real_T>(b_i) + 1.0,
                                      &d_emlrtDCI, (emlrtCTX)sp);
            }
            if ((b_i < 0) || (b_i > board_sizes.size(0) - 1)) {
              emlrtDynamicBoundsCheckR2012b(b_i, 0, board_sizes.size(0) - 1,
                                            &n_emlrtBCI, (emlrtCTX)sp);
            }
            board_size[0] = board_sizes[b_i].f1[0];
            if (b_i + 1 != b_i + 1) {
              emlrtIntegerCheckR2012b(static_cast<real_T>(b_i) + 1.0,
                                      &d_emlrtDCI, (emlrtCTX)sp);
            }
            if ((b_i < 0) || (b_i > board_sizes.size(0) - 1)) {
              emlrtDynamicBoundsCheckR2012b(b_i, 0, board_sizes.size(0) - 1,
                                            &n_emlrtBCI, (emlrtCTX)sp);
            }
            board_size[1] = board_sizes[b_i].f1[1];
            guard2 = true;
          } else {
            if (b_i + 1 != b_i + 1) {
              emlrtIntegerCheckR2012b(static_cast<real_T>(b_i) + 1.0,
                                      &b_emlrtDCI, (emlrtCTX)sp);
            }
            if ((b_i < 0) || (b_i > board_sizes.size(0) - 1)) {
              emlrtDynamicBoundsCheckR2012b(b_i, 0, board_sizes.size(0) - 1,
                                            &b_emlrtBCI, (emlrtCTX)sp);
            }
            p = true;
            loop_ub = 0;
            exitg1 = false;
            while ((!exitg1) && (loop_ub < 2)) {
              if (!(board_size[loop_ub] == board_sizes[b_i].f1[loop_ub])) {
                p = false;
                exitg1 = true;
              } else {
                loop_ub++;
              }
            }
            if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 4,
                           covrtLogMcdc(&emlrtCoverageInstance, 0, 0, 1,
                                        !covrtLogCond(&emlrtCoverageInstance, 0,
                                                      0, 1, p)))) {
              covrtLogBasicBlock(&emlrtCoverageInstance, 0, 8);
              // err = "Detect checker board with different size at " +
              // int2str(i);
              *err = -1;
              exitg2 = 1;
            } else {
              guard2 = true;
            }
          }
        } else {
          guard1 = true;
        }
        if (guard2) {
          covrtLogBasicBlock(&emlrtCoverageInstance, 0, 9);
          loop_ub = image_points.size(0);
          r1.set_size(&sd_emlrtRTEI, sp, image_points.size(0));
          for (i = 0; i < loop_ub; i++) {
            r1[i] = i;
          }
          loop_ub = image_points.size(1);
          r2.set_size(&td_emlrtRTEI, sp, image_points.size(1));
          for (i = 0; i < loop_ub; i++) {
            r2[i] = i;
          }
          if (b_i + 1 > image_points.size(2)) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, image_points.size(2),
                                          &g_emlrtBCI, (emlrtCTX)sp);
          }
          if (b_i + 1 != b_i + 1) {
            emlrtIntegerCheckR2012b(static_cast<real_T>(b_i) + 1.0, &emlrtDCI,
                                    (emlrtCTX)sp);
          }
          if ((b_i < 0) || (b_i > board_points.size(0) - 1)) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(0) - 1,
                                          &emlrtBCI, (emlrtCTX)sp);
          }
          b_iv[0] = r1.size(0);
          b_iv[1] = r2.size(0);
          emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2,
                                        board_points[b_i].f1.size(), 2,
                                        &c_emlrtECI, (emlrtCTX)sp);
          loop_ub = board_points[b_i].f1.size(1);
          for (i = 0; i < loop_ub; i++) {
            vlen = board_points[b_i].f1.size(0);
            for (i1 = 0; i1 < vlen; i1++) {
              image_points[(r1[i1] + image_points.size(0) * r2[i]) +
                           image_points.size(0) * image_points.size(1) * b_i] =
                  board_points[b_i].f1[i1 + board_points[b_i].f1.size(0) * i];
            }
          }
          guard1 = true;
        }
        if (guard1) {
          b_i++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b((emlrtCTX)sp);
          }
        }
      } else {
        covrtLogFor(&emlrtCoverageInstance, 0, 0, 1, 0);
        covrtLogBasicBlock(&emlrtCoverageInstance, 0, 10);
        //  Generate world coordinates of the corners of the squares in meters
        st.site = &e_emlrtRSI;
        coder::generateCheckerboardPoints(&st, board_size, square_size, r);
        world_points.set_size(&kd_emlrtRTEI, sp, r.size(0), 2);
        loop_ub = r.size(0) * 2;
        for (i = 0; i < loop_ub; i++) {
          world_points[i] = r[i];
        }
        //  compute extrinsics
        cam_extrinsics.set_size(&ld_emlrtRTEI, sp, 4, 4,
                                cam_extrinsics.size(2));
        cam_extrinsics.set_size(&ld_emlrtRTEI, sp, cam_extrinsics.size(0),
                                cam_extrinsics.size(1), nz);
        loop_ub = nz << 4;
        for (i = 0; i < loop_ub; i++) {
          cam_extrinsics[i] = 0.0;
        }
        camera_poses.set_size(&md_emlrtRTEI, sp, 4, 4, camera_poses.size(2));
        camera_poses.set_size(&md_emlrtRTEI, sp, camera_poses.size(0),
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
          covrtLogFor(&emlrtCoverageInstance, 0, 0, 2, 1);
          covrtLogBasicBlock(&emlrtCoverageInstance, 0, 11);
          //  transformations from the grid/world coordinates to the
          //  camera-based coordinates
          if (static_cast<int32_T>(b_i + 1U) > image_points.size(2)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i + 1U), 1,
                                          image_points.size(2), &f_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          b_image_points.set_size(&nd_emlrtRTEI, sp, image_points.size(0),
                                  image_points.size(1));
          for (i = 0; i < c_loop_ub; i++) {
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              b_image_points[i1 + b_image_points.size(0) * i] =
                  image_points[(i1 + image_points.size(0) * i) +
                               image_points.size(0) * image_points.size(1) *
                                   b_i];
            }
          }
          st.site = &f_emlrtRSI;
          coder::extrinsics(&st, b_image_points, world_points, &b_camera_params,
                            orientation_matrix, translation_vector);
          r1.set_size(&od_emlrtRTEI, sp, 4);
          r2.set_size(&pd_emlrtRTEI, sp, 4);
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
                                          &e_emlrtBCI, (emlrtCTX)sp);
          }
          b_iv[0] = 4;
          b_iv[1] = 4;
          iv1[0] = 4;
          iv1[1] = 4;
          emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &iv1[0], 2, &b_emlrtECI,
                                        (emlrtCTX)sp);
          st.site = &g_emlrtRSI;
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
                             cam_extrinsics.size(0) * cam_extrinsics.size(1) *
                                 b_i] = c_orientation_matrix[i1 + 4 * i];
            }
          }
          //  inverted of cam_extrinsics
          r1.set_size(&qd_emlrtRTEI, sp, 4);
          r2.set_size(&rd_emlrtRTEI, sp, 4);
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
                                          &d_emlrtBCI, (emlrtCTX)sp);
          }
          b_iv[0] = 4;
          b_iv[1] = 4;
          iv1[0] = 4;
          iv1[1] = 4;
          emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &iv1[0], 2, &emlrtECI,
                                        (emlrtCTX)sp);
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
            c_orientation_matrix[i + 12] = (b_orientation_matrix[i] * d +
                                            b_orientation_matrix[i + 3] * d1) +
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
        covrtLogFor(&emlrtCoverageInstance, 0, 0, 2, 0);
        exitg2 = 1;
      }
    } while (exitg2 == 0);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

// End of code generation (ComputeCamExtrinsics.cpp)
