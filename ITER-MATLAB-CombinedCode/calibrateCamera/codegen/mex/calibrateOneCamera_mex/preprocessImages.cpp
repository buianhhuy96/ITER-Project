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
#include "calibrateOneCamera_mex_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "libmwrgb2gray_tbb.h"

// Variable Definitions
static emlrtRSInfo ibb_emlrtRSI{
    7,                  // lineNo
    "preprocessImages", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\preprocessImages.m" // pathName
};

static emlrtBCInfo eu_emlrtBCI{
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

static emlrtBCInfo fu_emlrtBCI{
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

static emlrtBCInfo gu_emlrtBCI{
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

static emlrtECInfo pd_emlrtECI{
    -1,                 // nDims
    7,                  // lineNo
    8,                  // colNo
    "preprocessImages", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\preprocessImages.m" // pName
};

static emlrtBCInfo hu_emlrtBCI{
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

static emlrtECInfo qd_emlrtECI{
    -1,                 // nDims
    9,                  // lineNo
    8,                  // colNo
    "preprocessImages", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\preprocessImages.m" // pName
};

static emlrtRTEInfo vr_emlrtRTEI{
    3,                  // lineNo
    1,                  // colNo
    "preprocessImages", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\preprocessImages.m" // pName
};

static emlrtRTEInfo wr_emlrtRTEI{
    9,                  // lineNo
    29,                 // colNo
    "preprocessImages", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\preprocessImages.m" // pName
};

static emlrtRTEInfo xr_emlrtRTEI{
    7,                  // lineNo
    38,                 // colNo
    "preprocessImages", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\preprocessImages.m" // pName
};

static emlrtRTEInfo yr_emlrtRTEI{
    43,         // lineNo
    24,         // colNo
    "rgb2gray", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\images\\rgb2gray.m" // pName
};

// Function Definitions
namespace Codegen {
void preprocessImages(const emlrtStack *sp,
                      const ::coder::array<uint8_T, 4U> &images,
                      ::coder::array<uint8_T, 4U> &gray_images)
{
  ::coder::array<uint8_T, 3U> b_X;
  ::coder::array<uint8_T, 3U> b_images;
  ::coder::array<uint8_T, 2U> r;
  emlrtStack st;
  int32_T b_iv[3];
  int32_T c_gray_images[2];
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 6, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 6, 0);
  gray_images.set_size(&vr_emlrtRTEI, sp, images.size(0), images.size(1), 1,
                       images.size(3));
  loop_ub = images.size(0) * images.size(1) * images.size(3);
  for (i = 0; i < loop_ub; i++) {
    gray_images[i] = 0U;
  }
  i = images.size(3);
  for (int32_T b_i{0}; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 6, 0, 0, 1);
    //  If gray images, convert to RGB
    loop_ub = images.size(2);
    if (covrtLogIf(&emlrtCoverageInstance, 6, 0, 0, images.size(2) == 3)) {
      int32_T b_loop_ub;
      int32_T i1;
      int32_T i2;
      covrtLogBasicBlock(&emlrtCoverageInstance, 6, 1);
      if (b_i + 1 > gray_images.size(3)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, gray_images.size(3),
                                      &gu_emlrtBCI, (emlrtCTX)sp);
      }
      st.site = &ibb_emlrtRSI;
      if (b_i + 1 > images.size(3)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, images.size(3), &eu_emlrtBCI,
                                      &st);
      }
      loop_ub = images.size(0);
      b_loop_ub = images.size(1);
      b_X.set_size(&xr_emlrtRTEI, &st, images.size(0), images.size(1), 3);
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
      r.set_size(&yr_emlrtRTEI, &st, images.size(0), images.size(1));
      rgb2gray_tbb_uint8(&b_X[0],
                         static_cast<real_T>(images.size(0)) *
                             static_cast<real_T>(images.size(1)),
                         &r[0], true);
      c_gray_images[0] = gray_images.size(0);
      c_gray_images[1] = gray_images.size(1);
      emlrtSubAssignSizeCheckR2012b(&c_gray_images[0], 2, r.size(), 2,
                                    &pd_emlrtECI, (emlrtCTX)sp);
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
      int32_T b_gray_images;
      int32_T b_loop_ub;
      int32_T c_loop_ub;
      int32_T i1;
      int32_T i2;
      covrtLogBasicBlock(&emlrtCoverageInstance, 6, 2);
      if (b_i + 1 > gray_images.size(3)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, gray_images.size(3),
                                      &hu_emlrtBCI, (emlrtCTX)sp);
      }
      if (b_i + 1 > images.size(3)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, images.size(3), &fu_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      b_loop_ub = images.size(0);
      c_loop_ub = images.size(1);
      b_gray_images = gray_images.size(0);
      c_gray_images[0] = gray_images.size(0);
      c_gray_images[1] = gray_images.size(1);
      b_iv[0] = images.size(0);
      b_iv[1] = images.size(1);
      b_iv[2] = images.size(2);
      emlrtSubAssignSizeCheckR2012b(&c_gray_images[0], 2, &b_iv[0], 3,
                                    &qd_emlrtECI, (emlrtCTX)sp);
      b_images.set_size(&wr_emlrtRTEI, sp, images.size(0), images.size(1),
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
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 6, 0, 0, 0);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace Codegen

// End of code generation (preprocessImages.cpp)
