//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// detectMyCheckerboard.cpp
//
// Code generation for function 'detectMyCheckerboard'
//

// Include files
#include "detectMyCheckerboard.h"
#include "all.h"
#include "calibrateCamera_data.h"
#include "detectCheckerboardPoints.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Type Definitions
namespace Codegen {
struct cell_wrap_7 {
  real_T f1[2];
};

struct cell_wrap_6 {
  ::coder::array<real_T, 2U> f1;
};

} // namespace Codegen

// Variable Definitions
static emlrtRSInfo x_emlrtRSI{
    7,                      // lineNo
    "detectMyCheckerboard", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\detectMyCheckerboard.m" // pathName
};

static emlrtRSInfo y_emlrtRSI{
    18,                     // lineNo
    "detectMyCheckerboard", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\detectMyCheckerboard.m" // pathName
};

static emlrtRSInfo ab_emlrtRSI{
    24,                     // lineNo
    "detectMyCheckerboard", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\detectMyCheckerboard.m" // pathName
};

static emlrtRSInfo ss_emlrtRSI{
    15,    // lineNo
    "sum", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" // pathName
};

static emlrtRSInfo ts_emlrtRSI{
    138,                     // lineNo
    "combineVectorElements", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" // pathName
};

static emlrtRSInfo us_emlrtRSI{
    198,                // lineNo
    "colMajorFlatIter", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" // pathName
};

static emlrtBCInfo r_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    28,                     // lineNo
    44,                     // colNo
    "board_points",         // aName
    "detectMyCheckerboard", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\detectMyCheckerboard.m", // pName
    0                             // checkKind
};

static emlrtBCInfo s_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    25,                     // lineNo
    41,                     // colNo
    "board_points",         // aName
    "detectMyCheckerboard", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\detectMyCheckerboard.m", // pName
    0                             // checkKind
};

static emlrtECInfo d_emlrtECI{
    -1,                     // nDims
    28,                     // lineNo
    9,                      // colNo
    "detectMyCheckerboard", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\detectMyCheckerboard.m" // pName
};

static emlrtBCInfo t_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    28,                     // lineNo
    26,                     // colNo
    "image_points",         // aName
    "detectMyCheckerboard", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\detectMyCheckerboard.m", // pName
    0                             // checkKind
};

static emlrtBCInfo u_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    6,                      // lineNo
    32,                     // colNo
    "images",               // aName
    "detectMyCheckerboard", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\detectMyCheckerboard.m", // pName
    0                             // checkKind
};

static emlrtBCInfo v_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    14,                     // lineNo
    18,                     // colNo
    "board_points",         // aName
    "detectMyCheckerboard", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\detectMyCheckerboard.m", // pName
    0                             // checkKind
};

static emlrtBCInfo w_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    4,                      // lineNo
    35,                     // colNo
    "board_points",         // aName
    "detectMyCheckerboard", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\detectMyCheckerboard.m", // pName
    0                             // checkKind
};

static emlrtBCInfo x_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    12,                     // lineNo
    19,                     // colNo
    "valid_idx",            // aName
    "detectMyCheckerboard", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\detectMyCheckerboard.m", // pName
    0                             // checkKind
};

static emlrtBCInfo y_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    10,                     // lineNo
    19,                     // colNo
    "valid_idx",            // aName
    "detectMyCheckerboard", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\detectMyCheckerboard.m", // pName
    0                             // checkKind
};

static emlrtBCInfo ab_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    27,                     // lineNo
    18,                     // colNo
    "valid_idx",            // aName
    "detectMyCheckerboard", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\detectMyCheckerboard.m", // pName
    0                             // checkKind
};

static emlrtBCInfo bb_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    14,                     // lineNo
    5,                      // colNo
    "board_points",         // aName
    "detectMyCheckerboard", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\detectMyCheckerboard.m", // pName
    0                             // checkKind
};

static emlrtBCInfo cb_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    15,                     // lineNo
    5,                      // colNo
    "board_sizes",          // aName
    "detectMyCheckerboard", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\detectMyCheckerboard.m", // pName
    0                             // checkKind
};

static emlrtRTEInfo ad_emlrtRTEI{
    3,                      // lineNo
    46,                     // colNo
    "detectMyCheckerboard", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\detectMyCheckerboard.m" // pName
};

static emlrtRTEInfo bd_emlrtRTEI{
    1,                      // lineNo
    32,                     // colNo
    "detectMyCheckerboard", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\detectMyCheckerboard.m" // pName
};

static emlrtRTEInfo cd_emlrtRTEI{
    4,                      // lineNo
    35,                     // colNo
    "detectMyCheckerboard", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\detectMyCheckerboard.m" // pName
};

static emlrtRTEInfo dd_emlrtRTEI{
    6,                      // lineNo
    19,                     // colNo
    "detectMyCheckerboard", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\detectMyCheckerboard.m" // pName
};

static emlrtRTEInfo ed_emlrtRTEI{
    14,                     // lineNo
    5,                      // colNo
    "detectMyCheckerboard", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\detectMyCheckerboard.m" // pName
};

static emlrtRTEInfo fd_emlrtRTEI{
    24,                     // lineNo
    27,                     // colNo
    "detectMyCheckerboard", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\detectMyCheckerboard.m" // pName
};

static emlrtRTEInfo gd_emlrtRTEI{
    25,                     // lineNo
    1,                      // colNo
    "detectMyCheckerboard", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\detectMyCheckerboard.m" // pName
};

static emlrtRTEInfo hd_emlrtRTEI{
    20,                     // lineNo
    5,                      // colNo
    "detectMyCheckerboard", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\detectMyCheckerboard.m" // pName
};

// Function Definitions
namespace Codegen {
void detectMyCheckerboard(const emlrtStack *sp,
                          const ::coder::array<uint8_T, 4U> &images,
                          const real_T boardSize[2],
                          ::coder::array<real_T, 3U> &image_points)
{
  ::coder::array<cell_wrap_6, 1U> board_points;
  ::coder::array<cell_wrap_7, 1U> board_sizes;
  ::coder::array<real_T, 2U> current_board_points;
  ::coder::array<uint8_T, 2U> b_images;
  ::coder::array<boolean_T, 1U> valid_idx;
  ::coder::array<boolean_T, 1U> x;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T board_size_detected[2];
  int32_T b_image_points[2];
  int32_T b_board_points;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T nz;
  int32_T vlen;
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
  covrtLogFcn(&emlrtCoverageInstance, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 2, 0);
  valid_idx.set_size(&ad_emlrtRTEI, sp, images.size(3));
  vlen = images.size(3);
  board_points.set_size(&bd_emlrtRTEI, sp, images.size(3));
  for (i = 0; i < vlen; i++) {
    b_board_points = board_points.size(0) - 1;
    if (i > board_points.size(0) - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, board_points.size(0) - 1, &w_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    board_points[i].f1.set_size(&bd_emlrtRTEI, sp, 0,
                                board_points[i].f1.size(1));
    if (i > b_board_points) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_board_points, &w_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    board_points[i].f1.set_size(&bd_emlrtRTEI, sp, board_points[i].f1.size(0),
                                0);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = images.size(3);
  board_points.set_size(&cd_emlrtRTEI, sp, images.size(3));
  board_sizes.set_size(&cd_emlrtRTEI, sp, images.size(3));
  for (b_i = 0; b_i < i; b_i++) {
    boolean_T exitg1;
    boolean_T p;
    covrtLogFor(&emlrtCoverageInstance, 2, 0, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 1);
    //  perform checkerboards detection in each image
    if (b_i + 1 > images.size(3)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, images.size(3), &u_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    b_board_points = images.size(0);
    vlen = images.size(1);
    b_images.set_size(&dd_emlrtRTEI, sp, images.size(0), images.size(1));
    for (i1 = 0; i1 < vlen; i1++) {
      for (nz = 0; nz < b_board_points; nz++) {
        b_images[nz + b_images.size(0) * i1] =
            images[(nz + images.size(0) * i1) +
                   images.size(0) * images.size(1) * b_i];
      }
    }
    st.site = &x_emlrtRSI;
    coder::detectCheckerboardPoints(&st, b_images, current_board_points,
                                    board_size_detected);
    //  mark if checkerboards is detected or not
    p = true;
    b_board_points = 0;
    exitg1 = false;
    while ((!exitg1) && (b_board_points < 2)) {
      if (!(boardSize[b_board_points] == board_size_detected[b_board_points])) {
        p = false;
        exitg1 = true;
      } else {
        b_board_points++;
      }
    }
    if ((!covrtLogCond(&emlrtCoverageInstance, 2, 0, 0, p)) ||
        covrtLogCond(&emlrtCoverageInstance, 2, 0, 1,
                     (current_board_points.size(0) == 0) ||
                         (current_board_points.size(1) == 0))) {
      covrtLogMcdc(&emlrtCoverageInstance, 2, 0, 0, true);
      covrtLogIf(&emlrtCoverageInstance, 2, 0, 0, true);
      covrtLogBasicBlock(&emlrtCoverageInstance, 2, 2);
      if (b_i + 1 > valid_idx.size(0)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, valid_idx.size(0),
                                      &y_emlrtBCI, (emlrtCTX)sp);
      }
      valid_idx[b_i] = false;
    } else {
      covrtLogMcdc(&emlrtCoverageInstance, 2, 0, 0, false);
      covrtLogIf(&emlrtCoverageInstance, 2, 0, 0, false);
      covrtLogBasicBlock(&emlrtCoverageInstance, 2, 3);
      if (b_i + 1 > valid_idx.size(0)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, valid_idx.size(0),
                                      &x_emlrtBCI, (emlrtCTX)sp);
      }
      valid_idx[b_i] = true;
    }
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 4);
    b_board_points =
        current_board_points.size(0) * current_board_points.size(1);
    if (b_i > board_points.size(0) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(0) - 1,
                                    &v_emlrtBCI, (emlrtCTX)sp);
    }
    board_points[b_i].f1.set_size(&ed_emlrtRTEI, sp,
                                  current_board_points.size(0),
                                  board_points[b_i].f1.size(1));
    if (b_i > board_points.size(0) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(0) - 1,
                                    &v_emlrtBCI, (emlrtCTX)sp);
    }
    board_points[b_i].f1.set_size(&ed_emlrtRTEI, sp,
                                  board_points[b_i].f1.size(0),
                                  current_board_points.size(1));
    i1 = board_points.size(0);
    if (b_i > board_points.size(0) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(0) - 1,
                                    &v_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > board_points.size(0) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(0) - 1,
                                    &v_emlrtBCI, (emlrtCTX)sp);
    }
    for (nz = 0; nz < b_board_points; nz++) {
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &bb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      board_points[b_i].f1[nz] = current_board_points[nz];
    }
    vlen = board_sizes.size(0) - 1;
    if (b_i > board_sizes.size(0) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, board_sizes.size(0) - 1,
                                    &cb_emlrtBCI, (emlrtCTX)sp);
    }
    board_sizes[b_i].f1[0] = board_size_detected[0];
    if (b_i > vlen) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, vlen, &cb_emlrtBCI, (emlrtCTX)sp);
    }
    board_sizes[b_i].f1[1] = board_size_detected[1];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 2, 0, 0, 0);
  st.site = &y_emlrtRSI;
  if (covrtLogIf(&emlrtCoverageInstance, 2, 0, 1,
                 covrtLogMcdc(&emlrtCoverageInstance, 2, 0, 1,
                              !covrtLogCond(&emlrtCoverageInstance, 2, 0, 2,
                                            coder::all(&st, valid_idx))))) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 5);
    image_points.set_size(&hd_emlrtRTEI, sp, 0, 0, 1);
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 6);
    st.site = &ab_emlrtRSI;
    x.set_size(&fd_emlrtRTEI, &st, valid_idx.size(0));
    b_board_points = valid_idx.size(0);
    for (i = 0; i < b_board_points; i++) {
      x[i] = valid_idx[i];
    }
    b_st.site = &ss_emlrtRSI;
    c_st.site = &pn_emlrtRSI;
    vlen = x.size(0);
    if (x.size(0) == 0) {
      nz = 0;
    } else {
      d_st.site = &ts_emlrtRSI;
      nz = x[0];
      e_st.site = &us_emlrtRSI;
      if ((2 <= x.size(0)) && (x.size(0) > 2147483646)) {
        f_st.site = &qc_emlrtRSI;
        coder::check_forloop_overflow_error(&f_st);
      }
      for (b_board_points = 2; b_board_points <= vlen; b_board_points++) {
        nz += x[b_board_points - 1];
      }
    }
    if (0 > board_points.size(0) - 1) {
      emlrtDynamicBoundsCheckR2012b(0, 0, board_points.size(0) - 1, &s_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    image_points.set_size(&gd_emlrtRTEI, sp, board_points[0].f1.size(0),
                          board_points[0].f1.size(1), nz);
    b_board_points =
        board_points[0].f1.size(0) * board_points[0].f1.size(1) * nz;
    for (i = 0; i < b_board_points; i++) {
      image_points[i] = 0.0;
    }
    for (b_i = 0; b_i < nz; b_i++) {
      covrtLogFor(&emlrtCoverageInstance, 2, 0, 1, 1);
      if ((static_cast<int32_T>(b_i + 1U) < 1) ||
          (static_cast<int32_T>(b_i + 1U) > valid_idx.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i + 1U), 1,
                                      valid_idx.size(0), &ab_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (covrtLogIf(&emlrtCoverageInstance, 2, 0, 2, valid_idx[b_i])) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 2, 7);
        if ((b_i + 1 < 1) || (b_i + 1 > image_points.size(2))) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, image_points.size(2),
                                        &t_emlrtBCI, (emlrtCTX)sp);
        }
        if (b_i > board_points.size(0) - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(0) - 1,
                                        &r_emlrtBCI, (emlrtCTX)sp);
        }
        b_image_points[0] = image_points.size(0);
        b_image_points[1] = image_points.size(1);
        emlrtSubAssignSizeCheckR2012b(&b_image_points[0], 2,
                                      board_points[b_i].f1.size(), 2,
                                      &d_emlrtECI, (emlrtCTX)sp);
        b_board_points = board_points[b_i].f1.size(1);
        for (i = 0; i < b_board_points; i++) {
          vlen = board_points[b_i].f1.size(0);
          for (i1 = 0; i1 < vlen; i1++) {
            image_points[(i1 + image_points.size(0) * i) +
                         image_points.size(0) * image_points.size(1) * b_i] =
                board_points[b_i].f1[i1 + board_points[b_i].f1.size(0) * i];
          }
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    covrtLogFor(&emlrtCoverageInstance, 2, 0, 1, 0);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace Codegen

// End of code generation (detectMyCheckerboard.cpp)
