//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// preprocessImages.cpp
//
// Code generation for function 'preprocessImages'
//

// Include files
#include "preprocessImages.h"
#include "ComputeCamExtrinsics_mex_data.h"
#include "ComputeCamExtrinsics_mex_types.h"
#include "ImageTransformer.h"
#include "cameraParameters.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "libmwrgb2gray_tbb.h"

// Variable Definitions
static emlrtRSInfo jcb_emlrtRSI{
    2,                  // lineNo
    "preprocessImages", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\preprocessImages.m" // pathName
};

static emlrtRSInfo kcb_emlrtRSI{
    8,                  // lineNo
    "preprocessImages", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\preprocessImages.m" // pathName
};

static emlrtRSInfo lcb_emlrtRSI{
    10,                 // lineNo
    "preprocessImages", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\preprocessImages.m" // pathName
};

static emlrtRSInfo mcb_emlrtRSI{
    48,         // lineNo
    "rgb2gray", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\images\\rgb2gray.m" // pathName
};

static emlrtRSInfo ncb_emlrtRSI{
    92,               // lineNo
    "undistortImage", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\undistortImage.m" // pathName
};

static emlrtRSInfo ocb_emlrtRSI{
    94,               // lineNo
    "undistortImage", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\undistortImage.m" // pathName
};

static emlrtRSInfo pcb_emlrtRSI{
    108,              // lineNo
    "undistortImage", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\undistortImage.m" // pathName
};

static emlrtRSInfo qcb_emlrtRSI{
    113,           // lineNo
    "parseInputs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\undistortImage.m" // pathName
};

static emlrtRSInfo rcb_emlrtRSI{
    528,                                       // lineNo
    "CameraParametersImpl/undistortImageImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo scb_emlrtRSI{
    532,                                       // lineNo
    "CameraParametersImpl/undistortImageImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo tcb_emlrtRSI{
    537,                                       // lineNo
    "CameraParametersImpl/undistortImageImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRTEInfo pc_emlrtRTEI{
    80,              // lineNo
    13,              // colNo
    "localValidate", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "inputValidation\\validateImage.m" // pName
};

static emlrtECInfo hd_emlrtECI{
    -1,                                        // nDims
    541,                                       // lineNo
    17,                                        // colNo
    "CameraParametersImpl/undistortImageImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

static emlrtBCInfo uu_emlrtBCI{
    -1,                                        // iFirst
    -1,                                        // iLast
    541,                                       // lineNo
    63,                                        // colNo
    "",                                        // aName
    "CameraParametersImpl/undistortImageImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m", // pName
    0                                      // checkKind
};

static emlrtBCInfo vu_emlrtBCI{
    -1,                                        // iFirst
    -1,                                        // iLast
    541,                                       // lineNo
    61,                                        // colNo
    "",                                        // aName
    "CameraParametersImpl/undistortImageImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m", // pName
    0                                      // checkKind
};

static emlrtBCInfo wu_emlrtBCI{
    -1,                                        // iFirst
    -1,                                        // iLast
    541,                                       // lineNo
    49,                                        // colNo
    "",                                        // aName
    "CameraParametersImpl/undistortImageImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m", // pName
    0                                      // checkKind
};

static emlrtBCInfo xu_emlrtBCI{
    -1,                                        // iFirst
    -1,                                        // iLast
    541,                                       // lineNo
    47,                                        // colNo
    "",                                        // aName
    "CameraParametersImpl/undistortImageImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m", // pName
    0                                      // checkKind
};

static emlrtBCInfo yu_emlrtBCI{
    -1,                                        // iFirst
    -1,                                        // iLast
    541,                                       // lineNo
    35,                                        // colNo
    "",                                        // aName
    "CameraParametersImpl/undistortImageImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m", // pName
    0                                      // checkKind
};

static emlrtBCInfo av_emlrtBCI{
    -1,                                        // iFirst
    -1,                                        // iLast
    541,                                       // lineNo
    33,                                        // colNo
    "",                                        // aName
    "CameraParametersImpl/undistortImageImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m", // pName
    0                                      // checkKind
};

static emlrtRTEInfo qc_emlrtRTEI{
    17,               // lineNo
    9,                // colNo
    "checkImageSize", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "inputValidation\\checkImageSize.m" // pName
};

static emlrtECInfo id_emlrtECI{
    -1,                 // nDims
    10,                 // lineNo
    4,                  // colNo
    "preprocessImages", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\preprocessImages.m" // pName
};

static emlrtBCInfo bv_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    10,                 // lineNo
    22,                 // colNo
    "gray_images",      // aName
    "preprocessImages", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\preprocessImages.m", // pName
    0                           // checkKind
};

static emlrtBCInfo cv_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    8,                  // lineNo
    47,                 // colNo
    "images",           // aName
    "preprocessImages", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\preprocessImages.m", // pName
    0                           // checkKind
};

static emlrtBCInfo dv_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    5,                  // lineNo
    32,                 // colNo
    "images",           // aName
    "preprocessImages", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\preprocessImages.m", // pName
    0                           // checkKind
};

static emlrtRTEInfo qs_emlrtRTEI{
    3,                  // lineNo
    1,                  // colNo
    "preprocessImages", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\preprocessImages.m" // pName
};

static emlrtRTEInfo rs_emlrtRTEI{
    5,                  // lineNo
    4,                  // colNo
    "preprocessImages", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\preprocessImages.m" // pName
};

static emlrtRTEInfo ss_emlrtRTEI{
    8,                  // lineNo
    34,                 // colNo
    "preprocessImages", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\preprocessImages.m" // pName
};

static emlrtRTEInfo ts_emlrtRTEI{
    43,         // lineNo
    24,         // colNo
    "rgb2gray", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\images\\rgb2gray.m" // pName
};

static emlrtRTEInfo us_emlrtRTEI{
    8,                  // lineNo
    8,                  // colNo
    "preprocessImages", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\preprocessImages.m" // pName
};

static emlrtRTEInfo vs_emlrtRTEI{
    10,                 // lineNo
    16,                 // colNo
    "preprocessImages", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\preprocessImages.m" // pName
};

static emlrtRTEInfo ws_emlrtRTEI{
    10,                 // lineNo
    18,                 // colNo
    "preprocessImages", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\preprocessImages.m" // pName
};

static emlrtRTEInfo xs_emlrtRTEI{
    92,               // lineNo
    1,                // colNo
    "undistortImage", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\undistortImage.m" // pName
};

static emlrtRTEInfo ys_emlrtRTEI{
    63,                 // lineNo
    41,                 // colNo
    "ImageTransformer", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pName
};

static emlrtRTEInfo at_emlrtRTEI{
    64,                 // lineNo
    37,                 // colNo
    "ImageTransformer", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pName
};

static emlrtRTEInfo bt_emlrtRTEI{
    540,                    // lineNo
    39,                     // colNo
    "CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

static emlrtRTEInfo ct_emlrtRTEI{
    541,                    // lineNo
    22,                     // colNo
    "CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

static emlrtRTEInfo dt_emlrtRTEI{
    541,                    // lineNo
    24,                     // colNo
    "CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

static emlrtRTEInfo et_emlrtRTEI{
    541,                    // lineNo
    26,                     // colNo
    "CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

// Function Definitions
void preprocessImages(const emlrtStack *sp,
                      const coder::array<uint8_T, 4U> &images,
                      const struct0_T *camera_params,
                      coder::array<uint8_T, 4U> &gray_images)
{
  static const char_T b_cv[5]{'u', 'i', 'n', 't', '8'};
  static const char_T b_cv1[4]{'s', 'a', 'm', 'e'};
  coder::b_cameraParameters b_camera_params;
  coder::array<int32_T, 1U> r;
  coder::array<int32_T, 1U> r1;
  coder::array<int32_T, 1U> r2;
  coder::array<int32_T, 1U> r3;
  coder::array<char_T, 2U> b;
  coder::array<int8_T, 1U> r4;
  coder::array<uint8_T, 3U> J;
  coder::array<uint8_T, 3U> b_J;
  coder::array<uint8_T, 3U> current_images;
  coder::array<uint8_T, 3U> fillValues;
  coder::array<uint8_T, 2U> b_current_images;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T intrinsicMatrix[9];
  real_T c_camera_params[3];
  real_T b_dv[2];
  real_T d_camera_params[2];
  real_T sizeOutput[2];
  int32_T b_iv[3];
  int32_T iv1[3];
  int32_T iv2[2];
  int32_T i;
  int32_T loop_ub;
  uint32_T origSize[3];
  uint32_T varargin_1[2];
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
  covrtLogFcn(&emlrtCoverageInstance, 3, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 3, 0);
  st.site = &jcb_emlrtRSI;
  b_camera_params.init(
      &st, camera_params->RadialDistortion, camera_params->TangentialDistortion,
      camera_params->ImageSize, camera_params->WorldPoints,
      camera_params->NumRadialDistortionCoefficients,
      camera_params->RotationVectors, camera_params->TranslationVectors,
      camera_params->ReprojectionErrors, camera_params->IntrinsicMatrix,
      camera_params->DetectedKeypoints);
  gray_images.set_size(&qs_emlrtRTEI, sp, images.size(0), images.size(1), 1,
                       images.size(3));
  loop_ub = images.size(0) * images.size(1) * images.size(3);
  for (i = 0; i < loop_ub; i++) {
    gray_images[i] = 0U;
  }
  i = images.size(3);
  for (int32_T b_i{0}; b_i < i; b_i++) {
    int32_T b_loop_ub;
    int32_T c_loop_ub;
    int32_T i1;
    int32_T i2;
    int32_T k;
    boolean_T b_p;
    boolean_T exitg1;
    boolean_T p;
    boolean_T sameClass;
    covrtLogFor(&emlrtCoverageInstance, 3, 0, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 1);
    if (b_i + 1 > images.size(3)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, images.size(3), &dv_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    loop_ub = images.size(0);
    b_loop_ub = images.size(1);
    c_loop_ub = images.size(2);
    current_images.set_size(&rs_emlrtRTEI, sp, images.size(0), images.size(1),
                            images.size(2));
    for (i1 = 0; i1 < c_loop_ub; i1++) {
      for (k = 0; k < b_loop_ub; k++) {
        for (i2 = 0; i2 < loop_ub; i2++) {
          current_images[(i2 + current_images.size(0) * k) +
                         current_images.size(0) * current_images.size(1) * i1] =
              images[((i2 + images.size(0) * k) +
                      images.size(0) * images.size(1) * i1) +
                     images.size(0) * images.size(1) * images.size(2) * b_i];
        }
      }
    }
    //  If gray images, convert to RGB
    if (covrtLogIf(&emlrtCoverageInstance, 3, 0, 0, images.size(2) == 3)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 3, 2);
      st.site = &kcb_emlrtRSI;
      if (b_i + 1 > images.size(3)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, images.size(3), &cv_emlrtBCI,
                                      &st);
      }
      loop_ub = images.size(0);
      b_loop_ub = images.size(1);
      current_images.set_size(&ss_emlrtRTEI, &st, images.size(0),
                              images.size(1), 3);
      for (i1 = 0; i1 < 3; i1++) {
        for (k = 0; k < b_loop_ub; k++) {
          for (i2 = 0; i2 < loop_ub; i2++) {
            current_images[(i2 + current_images.size(0) * k) +
                           current_images.size(0) * current_images.size(1) *
                               i1] =
                images[((i2 + images.size(0) * k) +
                        images.size(0) * images.size(1) * i1) +
                       images.size(0) * images.size(1) * images.size(2) * b_i];
          }
        }
      }
      b_current_images.set_size(&ts_emlrtRTEI, &st, images.size(0),
                                images.size(1));
      b_st.site = &mcb_emlrtRSI;
      rgb2gray_tbb_uint8(&current_images[0],
                         static_cast<real_T>(images.size(0)) *
                             static_cast<real_T>(images.size(1)),
                         &b_current_images[0], true);
      current_images.set_size(&us_emlrtRTEI, sp, b_current_images.size(0),
                              b_current_images.size(1), 1);
      loop_ub = b_current_images.size(0) * b_current_images.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        current_images[i1] = b_current_images[i1];
      }
    }
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 3);
    loop_ub = gray_images.size(0);
    r.set_size(&vs_emlrtRTEI, sp, gray_images.size(0));
    for (i1 = 0; i1 < loop_ub; i1++) {
      r[i1] = i1;
    }
    loop_ub = gray_images.size(1);
    r1.set_size(&ws_emlrtRTEI, sp, gray_images.size(1));
    for (i1 = 0; i1 < loop_ub; i1++) {
      r1[i1] = i1;
    }
    if (b_i + 1 > gray_images.size(3)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, gray_images.size(3),
                                    &bv_emlrtBCI, (emlrtCTX)sp);
    }
    st.site = &lcb_emlrtRSI;
    b_st.site = &ncb_emlrtRSI;
    c_st.site = &qcb_emlrtRSI;
    d_st.site = &qb_emlrtRSI;
    e_st.site = &rb_emlrtRSI;
    f_st.site = &x_emlrtRSI;
    if ((current_images.size(0) == 0) || (current_images.size(1) == 0) ||
        (current_images.size(2) == 0)) {
      emlrtErrorWithMessageIdR2018a(
          &f_st, &j_emlrtRTEI,
          "Coder:toolbox:ValidateattributesexpectedNonempty",
          "MATLAB:validateImage:expectedNonempty", 3, 4, 5, "Image");
    }
    if ((current_images.size(2) != 1) && (current_images.size(2) != 3)) {
      emlrtErrorWithMessageIdR2018a(&d_st, &pc_emlrtRTEI,
                                    "vision:dims:imageNot2DorRGB",
                                    "vision:dims:imageNot2DorRGB", 0);
    }
    if (current_images.size(2) > 1) {
      fillValues.set_size(&xs_emlrtRTEI, &b_st, 1, 1, 3);
      fillValues[0] = 0U;
      fillValues[1] = 0U;
      fillValues[2] = 0U;
    } else {
      fillValues.set_size(&xs_emlrtRTEI, &b_st, 1, 1, 1);
      fillValues[0] = 0U;
    }
    b_st.site = &ocb_emlrtRSI;
    sizeOutput[0] = b_camera_params.ImageSize[0];
    sizeOutput[1] = b_camera_params.ImageSize[1];
    varargin_1[0] = static_cast<uint32_T>(current_images.size(0));
    varargin_1[1] = static_cast<uint32_T>(current_images.size(1));
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if (!(varargin_1[k] == sizeOutput[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (!p) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &qc_emlrtRTEI, "vision:calibrate:inconsistentImageSize",
          "vision:calibrate:inconsistentImageSize", 0);
    }
    b_st.site = &pcb_emlrtRSI;
    c_st.site = &rcb_emlrtRSI;
    origSize[0] = static_cast<uint32_T>(current_images.size(0));
    origSize[1] = static_cast<uint32_T>(current_images.size(1));
    origSize[2] = static_cast<uint32_T>(current_images.size(2));
    p = (b_camera_params.UndistortMap.SizeOfImage.size(1) == 3);
    if (p && (b_camera_params.UndistortMap.SizeOfImage.size(1) != 0)) {
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 3)) {
        if (!(b_camera_params.UndistortMap.SizeOfImage[k] == origSize[k])) {
          p = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    b.set_size(&ys_emlrtRTEI, &c_st, 1,
               b_camera_params.UndistortMap.ClassOfImage.size(1));
    loop_ub = b_camera_params.UndistortMap.ClassOfImage.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b[i1] = b_camera_params.UndistortMap.ClassOfImage[i1];
    }
    sameClass = false;
    if (5 == b.size(1)) {
      k = 0;
      int32_T exitg2;
      do {
        exitg2 = 0;
        if (k < 5) {
          if (b_cv[k] != b[k]) {
            exitg2 = 1;
          } else {
            k++;
          }
        } else {
          sameClass = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
    }
    b.set_size(&at_emlrtRTEI, &c_st, 1,
               b_camera_params.UndistortMap.OutputView.size(1));
    loop_ub = b_camera_params.UndistortMap.OutputView.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b[i1] = b_camera_params.UndistortMap.OutputView[i1];
    }
    b_p = (b.size(1) == 4);
    if (b_p && (b.size(1) != 0)) {
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 4)) {
        if (!(b[k] == b_cv1[k])) {
          b_p = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (p && sameClass && b_p) {
      p = true;
    } else {
      p = false;
    }
    if (!p) {
      c_st.site = &scb_emlrtRSI;
      for (i1 = 0; i1 < 3; i1++) {
        intrinsicMatrix[3 * i1] = b_camera_params.IntrinsicMatrixInternal[i1];
        intrinsicMatrix[3 * i1 + 1] =
            b_camera_params.IntrinsicMatrixInternal[i1 + 3];
        intrinsicMatrix[3 * i1 + 2] =
            b_camera_params.IntrinsicMatrixInternal[i1 + 6];
      }
      sizeOutput[0] = 1.0;
      sizeOutput[1] = static_cast<uint32_T>(current_images.size(1));
      b_dv[0] = 1.0;
      b_dv[1] = static_cast<uint32_T>(current_images.size(0));
      c_camera_params[0] = b_camera_params.RadialDistortion[0];
      c_camera_params[1] = b_camera_params.RadialDistortion[1];
      c_camera_params[2] = b_camera_params.RadialDistortion[2];
      d_camera_params[0] = b_camera_params.TangentialDistortion[0];
      d_camera_params[1] = b_camera_params.TangentialDistortion[1];
      c_st.site = &scb_emlrtRSI;
      b_camera_params.UndistortMap.update(&c_st, current_images,
                                          intrinsicMatrix, c_camera_params,
                                          d_camera_params, sizeOutput, b_dv);
    }
    c_st.site = &tcb_emlrtRSI;
    b_camera_params.UndistortMap.transformImage(&c_st, current_images,
                                                fillValues, J, sizeOutput);
    b_J.set_size(&bt_emlrtRTEI, &b_st, current_images.size(0),
                 current_images.size(1), current_images.size(2));
    if (1 > J.size(0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, J.size(0), &av_emlrtBCI, &b_st);
    }
    loop_ub = current_images.size(0);
    if (current_images.size(0) > J.size(0)) {
      emlrtDynamicBoundsCheckR2012b(current_images.size(0), 1, J.size(0),
                                    &yu_emlrtBCI, &b_st);
    }
    if (1 > J.size(1)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, J.size(1), &xu_emlrtBCI, &b_st);
    }
    b_loop_ub = current_images.size(1);
    if (current_images.size(1) > J.size(1)) {
      emlrtDynamicBoundsCheckR2012b(current_images.size(1), 1, J.size(1),
                                    &wu_emlrtBCI, &b_st);
    }
    if (1 > J.size(2)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, J.size(2), &vu_emlrtBCI, &b_st);
    }
    c_loop_ub = current_images.size(2);
    if (current_images.size(2) > J.size(2)) {
      emlrtDynamicBoundsCheckR2012b(current_images.size(2), 1, J.size(2),
                                    &uu_emlrtBCI, &b_st);
    }
    k = current_images.size(0);
    r2.set_size(&ct_emlrtRTEI, &b_st, current_images.size(0));
    for (i1 = 0; i1 < k; i1++) {
      r2[i1] = i1;
    }
    k = current_images.size(1);
    r3.set_size(&dt_emlrtRTEI, &b_st, current_images.size(1));
    for (i1 = 0; i1 < k; i1++) {
      r3[i1] = i1;
    }
    r4.set_size(&et_emlrtRTEI, &b_st,
                static_cast<int8_T>(current_images.size(2) - 1) + 1);
    k = static_cast<int8_T>(current_images.size(2) - 1);
    for (i1 = 0; i1 <= k; i1++) {
      r4[i1] = static_cast<int8_T>(i1);
    }
    b_iv[0] = r2.size(0);
    b_iv[1] = r3.size(0);
    b_iv[2] = r4.size(0);
    iv1[0] = current_images.size(0);
    iv1[1] = current_images.size(1);
    iv1[2] = current_images.size(2);
    emlrtSubAssignSizeCheckR2012b(&b_iv[0], 3, &iv1[0], 3, &hd_emlrtECI, &b_st);
    for (i1 = 0; i1 < c_loop_ub; i1++) {
      for (k = 0; k < b_loop_ub; k++) {
        for (i2 = 0; i2 < loop_ub; i2++) {
          b_J[(r2[i2] + b_J.size(0) * r3[k]) +
              b_J.size(0) * b_J.size(1) * r4[i1]] =
              J[(i2 + J.size(0) * k) + J.size(0) * J.size(1) * i1];
        }
      }
    }
    iv2[0] = r.size(0);
    iv2[1] = r1.size(0);
    emlrtSubAssignSizeCheckR2012b(&iv2[0], 2, b_J.size(), 3, &id_emlrtECI,
                                  (emlrtCTX)sp);
    iv2[0] = r.size(0);
    loop_ub = r1.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_loop_ub = iv2[0];
      for (k = 0; k < b_loop_ub; k++) {
        gray_images[(r[k] + gray_images.size(0) * r1[i1]) +
                    gray_images.size(0) * gray_images.size(1) * b_i] =
            b_J[k + iv2[0] * i1];
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 3, 0, 0, 0);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

// End of code generation (preprocessImages.cpp)
