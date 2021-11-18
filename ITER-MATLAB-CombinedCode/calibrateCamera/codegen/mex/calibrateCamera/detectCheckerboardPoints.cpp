//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// detectCheckerboardPoints.cpp
//
// Code generation for function 'detectCheckerboardPoints'
//

// Include files
#include "detectCheckerboardPoints.h"
#include "Checkerboard.h"
#include "abs.h"
#include "any1.h"
#include "calibrateCamera_data.h"
#include "detectCheckerboard.h"
#include "find_peaks.h"
#include "imfilter.h"
#include "indexShapeCheck.h"
#include "power.h"
#include "rt_nonfinite.h"
#include "sub2ind.h"
#include "subPixelLocation.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo
    bb_emlrtRSI{
        210,                        // lineNo
        "detectCheckerboardPoints", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectCheckerboardPoin"
        "ts.m" // pathName
    };

static emlrtRSInfo
    cb_emlrtRSI{
        389,          // lineNo
        "detectMono", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectCheckerboardPoin"
        "ts.m" // pathName
    };

static emlrtRSInfo
    db_emlrtRSI{
        390,          // lineNo
        "detectMono", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectCheckerboardPoin"
        "ts.m" // pathName
    };

static emlrtRSInfo
    eb_emlrtRSI{
        395,          // lineNo
        "detectMono", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectCheckerboardPoin"
        "ts.m" // pathName
    };

static emlrtRSInfo
    fb_emlrtRSI{
        479,          // lineNo
        "checkImage", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectCheckerboardPoin"
        "ts.m" // pathName
    };

static emlrtRSInfo gb_emlrtRSI{
    44,              // lineNo
    "validateImage", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "inputValidation\\validateImage.m" // pathName
};

static emlrtRSInfo hb_emlrtRSI{
    51,              // lineNo
    "localValidate", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "inputValidation\\validateImage.m" // pathName
};

static emlrtRSInfo
    ib_emlrtRSI{
        731,                            // lineNo
        "detectCheckerboardInOneImage", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectCheckerboardPoin"
        "ts.m" // pathName
    };

static emlrtRSInfo
    jb_emlrtRSI{
        737,                            // lineNo
        "detectCheckerboardInOneImage", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectCheckerboardPoin"
        "ts.m" // pathName
    };

static emlrtRTEInfo i_emlrtRTEI{
    13,                 // lineNo
    37,                 // colNo
    "validatenonempty", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatenonempty.m" // pName
};

static emlrtRTEInfo
    id_emlrtRTEI{
        720,                        // lineNo
        1,                          // colNo
        "detectCheckerboardPoints", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectCheckerboardPoin"
        "ts.m" // pName
    };

// Function Definitions
namespace Codegen {
namespace coder {
void detectCheckerboardPoints(const emlrtStack *sp,
                              const ::coder::array<uint8_T, 2U> &b_I,
                              ::coder::array<real_T, 2U> &imagePoints,
                              real_T boardSize[2])
{
  vision::internal::calibration::checkerboard::Checkerboard lobj_0[6];
  vision::internal::calibration::checkerboard::Checkerboard *board0;
  vision::internal::calibration::checkerboard::Checkerboard *board45;
  ::coder::array<real_T, 1U> s;
  ::coder::array<int32_T, 1U> r3;
  ::coder::array<int32_T, 1U> r4;
  ::coder::array<real32_T, 2U> I_45;
  ::coder::array<real32_T, 2U> I_45_x;
  ::coder::array<real32_T, 2U> I_45_y;
  ::coder::array<real32_T, 2U> Ig;
  ::coder::array<real32_T, 2U> Ixy;
  ::coder::array<real32_T, 2U> Iy;
  ::coder::array<real32_T, 2U> b;
  ::coder::array<real32_T, 2U> c_I;
  ::coder::array<real32_T, 2U> cxy;
  ::coder::array<real32_T, 2U> points0;
  ::coder::array<real32_T, 2U> r1;
  ::coder::array<real32_T, 2U> r2;
  ::coder::array<real32_T, 1U> b_points0;
  ::coder::array<real32_T, 1U> c_points0;
  ::coder::array<boolean_T, 1U> r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  int32_T varargin_1[2];
  int32_T varargin_2[2];
  int32_T i;
  int32_T loop_ub;
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
  st.site = &bb_emlrtRSI;
  b_st.site = &cb_emlrtRSI;
  c_st.site = &fb_emlrtRSI;
  d_st.site = &gb_emlrtRSI;
  e_st.site = &hb_emlrtRSI;
  f_st.site = &v_emlrtRSI;
  if ((b_I.size(0) == 0) || (b_I.size(1) == 0)) {
    emlrtErrorWithMessageIdR2018a(
        &f_st, &i_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonempty",
        "MATLAB:validateImage:expectedNonempty", 3, 4, 1, "I");
  }
  b_st.site = &db_emlrtRSI;
  c_I.set_size(&id_emlrtRTEI, &b_st, b_I.size(0), b_I.size(1));
  loop_ub = b_I.size(0) * b_I.size(1);
  for (i = 0; i < loop_ub; i++) {
    c_I[i] = static_cast<real32_T>(b_I[i]) / 255.0F;
  }
  c_st.site = &ib_emlrtRSI;
  vision::internal::calibration::checkerboard::detectCheckerboard(
      &c_st, c_I, imagePoints, boardSize);
  if ((imagePoints.size(0) == 0) || (imagePoints.size(1) == 0)) {
    int32_T end;
    int32_T trueCount;
    boolean_T guard1{false};
    boolean_T guard2{false};
    c_st.site = &jb_emlrtRSI;
    d_st.site = &kb_emlrtRSI;
    Ig.set_size(&jd_emlrtRTEI, &d_st, c_I.size(0), c_I.size(1));
    loop_ub = c_I.size(0) * c_I.size(1);
    for (i = 0; i < loop_ub; i++) {
      Ig[i] = c_I[i];
    }
    e_st.site = &yb_emlrtRSI;
    d_imfilter(&e_st, Ig);
    Iy.set_size(&kd_emlrtRTEI, &d_st, Ig.size(0), Ig.size(1));
    loop_ub = Ig.size(0) * Ig.size(1);
    for (i = 0; i < loop_ub; i++) {
      Iy[i] = Ig[i];
    }
    e_st.site = &ac_emlrtRSI;
    imfilter(&e_st, Iy);
    e_st.site = &bc_emlrtRSI;
    b_imfilter(&e_st, Ig);
    Ixy.set_size(&ld_emlrtRTEI, &d_st, Ig.size(0), Ig.size(1));
    loop_ub = Ig.size(0) * Ig.size(1);
    for (i = 0; i < loop_ub; i++) {
      Ixy[i] = Ig[i];
    }
    e_st.site = &cc_emlrtRSI;
    imfilter(&e_st, Ixy);
    r1.set_size(&md_emlrtRTEI, &d_st, Ig.size(0), Ig.size(1));
    loop_ub = Ig.size(0) * Ig.size(1);
    for (i = 0; i < loop_ub; i++) {
      r1[i] = Ig[i] * 0.707106769F;
    }
    I_45.set_size(&nd_emlrtRTEI, &d_st, Iy.size(0), Iy.size(1));
    loop_ub = Iy.size(0) * Iy.size(1);
    for (i = 0; i < loop_ub; i++) {
      I_45[i] = Iy[i] * 0.707106769F;
    }
    varargin_1[0] = (*(int32_T(*)[2])r1.size())[0];
    varargin_1[1] = (*(int32_T(*)[2])r1.size())[1];
    varargin_2[0] = (*(int32_T(*)[2])I_45.size())[0];
    varargin_2[1] = (*(int32_T(*)[2])I_45.size())[1];
    emlrtSizeEqCheckNDR2012b(&varargin_1[0], &varargin_2[0], &e_emlrtECI,
                             &d_st);
    loop_ub = r1.size(0) * r1.size(1);
    I_45.set_size(&od_emlrtRTEI, &d_st, r1.size(0), r1.size(1));
    for (i = 0; i < loop_ub; i++) {
      I_45[i] = r1[i] + I_45[i];
    }
    r2.set_size(&pd_emlrtRTEI, &d_st, Iy.size(0), Iy.size(1));
    loop_ub = Iy.size(0) * Iy.size(1);
    for (i = 0; i < loop_ub; i++) {
      r2[i] = Iy[i] * -0.707106769F;
    }
    varargin_1[0] = (*(int32_T(*)[2])r1.size())[0];
    varargin_1[1] = (*(int32_T(*)[2])r1.size())[1];
    varargin_2[0] = (*(int32_T(*)[2])r2.size())[0];
    varargin_2[1] = (*(int32_T(*)[2])r2.size())[1];
    emlrtSizeEqCheckNDR2012b(&varargin_1[0], &varargin_2[0], &f_emlrtECI,
                             &d_st);
    I_45_x.set_size(&qd_emlrtRTEI, &d_st, I_45.size(0), I_45.size(1));
    loop_ub = I_45.size(0) * I_45.size(1);
    for (i = 0; i < loop_ub; i++) {
      I_45_x[i] = I_45[i];
    }
    e_st.site = &dc_emlrtRSI;
    b_imfilter(&e_st, I_45_x);
    I_45_y.set_size(&rd_emlrtRTEI, &d_st, I_45.size(0), I_45.size(1));
    loop_ub = I_45.size(0) * I_45.size(1);
    for (i = 0; i < loop_ub; i++) {
      I_45_y[i] = I_45[i];
    }
    e_st.site = &ec_emlrtRSI;
    imfilter(&e_st, I_45_y);
    loop_ub = I_45_x.size(0) * I_45_x.size(1);
    for (i = 0; i < loop_ub; i++) {
      I_45_x[i] = I_45_x[i] * 0.707106769F;
    }
    loop_ub = I_45_y.size(0) * I_45_y.size(1);
    for (i = 0; i < loop_ub; i++) {
      I_45_y[i] = I_45_y[i] * -0.707106769F;
    }
    varargin_1[0] = (*(int32_T(*)[2])I_45_x.size())[0];
    varargin_1[1] = (*(int32_T(*)[2])I_45_x.size())[1];
    varargin_2[0] = (*(int32_T(*)[2])I_45_y.size())[0];
    varargin_2[1] = (*(int32_T(*)[2])I_45_y.size())[1];
    emlrtSizeEqCheckNDR2012b(&varargin_1[0], &varargin_2[0], &g_emlrtECI,
                             &d_st);
    loop_ub = I_45_x.size(0) * I_45_x.size(1);
    for (i = 0; i < loop_ub; i++) {
      I_45_x[i] = I_45_x[i] + I_45_y[i];
    }
    e_st.site = &fc_emlrtRSI;
    b_abs(&e_st, I_45, I_45_y);
    I_45.set_size(&sd_emlrtRTEI, &d_st, r1.size(0), r1.size(1));
    loop_ub = r1.size(0) * r1.size(1);
    for (i = 0; i < loop_ub; i++) {
      I_45[i] = r1[i] + r2[i];
    }
    e_st.site = &fc_emlrtRSI;
    b_abs(&e_st, I_45, r1);
    varargin_1[0] = (*(int32_T(*)[2])I_45_y.size())[0];
    varargin_1[1] = (*(int32_T(*)[2])I_45_y.size())[1];
    varargin_2[0] = (*(int32_T(*)[2])r1.size())[0];
    varargin_2[1] = (*(int32_T(*)[2])r1.size())[1];
    emlrtSizeEqCheckNDR2012b(&varargin_1[0], &varargin_2[0], &h_emlrtECI,
                             &d_st);
    e_st.site = &fc_emlrtRSI;
    b_abs(&e_st, Ixy, b);
    loop_ub = b.size(0) * b.size(1);
    for (i = 0; i < loop_ub; i++) {
      b[i] = 16.0F * b[i];
    }
    loop_ub = I_45_y.size(0) * I_45_y.size(1);
    for (i = 0; i < loop_ub; i++) {
      I_45_y[i] = 6.0F * (I_45_y[i] + r1[i]);
    }
    varargin_1[0] = (*(int32_T(*)[2])b.size())[0];
    varargin_1[1] = (*(int32_T(*)[2])b.size())[1];
    varargin_2[0] = (*(int32_T(*)[2])I_45_y.size())[0];
    varargin_2[1] = (*(int32_T(*)[2])I_45_y.size())[1];
    emlrtSizeEqCheckNDR2012b(&varargin_1[0], &varargin_2[0], &i_emlrtECI,
                             &d_st);
    cxy.set_size(&td_emlrtRTEI, &d_st, b.size(0), b.size(1));
    loop_ub = b.size(0) * b.size(1);
    for (i = 0; i < loop_ub; i++) {
      cxy[i] = b[i] - I_45_y[i];
    }
    end = b.size(0) * b.size(1) - 1;
    trueCount = 0;
    for (loop_ub = 0; loop_ub <= end; loop_ub++) {
      if (b[loop_ub] - I_45_y[loop_ub] < 0.0F) {
        trueCount++;
      }
    }
    r3.set_size(&ud_emlrtRTEI, &d_st, trueCount);
    trueCount = 0;
    for (loop_ub = 0; loop_ub <= end; loop_ub++) {
      if (b[loop_ub] - I_45_y[loop_ub] < 0.0F) {
        r3[trueCount] = loop_ub + 1;
        trueCount++;
      }
    }
    trueCount = b.size(0) * b.size(1);
    loop_ub = r3.size(0);
    for (i = 0; i < loop_ub; i++) {
      if ((r3[i] < 1) || (r3[i] > trueCount)) {
        emlrtDynamicBoundsCheckR2012b(r3[i], 1, trueCount, &db_emlrtBCI, &d_st);
      }
      cxy[r3[i] - 1] = 0.0F;
    }
    e_st.site = &gc_emlrtRSI;
    b_abs(&e_st, Ig, r1);
    e_st.site = &gc_emlrtRSI;
    b_abs(&e_st, Iy, r2);
    varargin_1[0] = (*(int32_T(*)[2])r1.size())[0];
    varargin_1[1] = (*(int32_T(*)[2])r1.size())[1];
    varargin_2[0] = (*(int32_T(*)[2])r2.size())[0];
    varargin_2[1] = (*(int32_T(*)[2])r2.size())[1];
    emlrtSizeEqCheckNDR2012b(&varargin_1[0], &varargin_2[0], &j_emlrtECI,
                             &d_st);
    e_st.site = &gc_emlrtRSI;
    b_abs(&e_st, I_45_x, b);
    loop_ub = b.size(0) * b.size(1);
    for (i = 0; i < loop_ub; i++) {
      b[i] = 16.0F * b[i];
    }
    loop_ub = r1.size(0) * r1.size(1);
    for (i = 0; i < loop_ub; i++) {
      r1[i] = 6.0F * (r1[i] + r2[i]);
    }
    varargin_1[0] = (*(int32_T(*)[2])b.size())[0];
    varargin_1[1] = (*(int32_T(*)[2])b.size())[1];
    varargin_2[0] = (*(int32_T(*)[2])r1.size())[0];
    varargin_2[1] = (*(int32_T(*)[2])r1.size())[1];
    emlrtSizeEqCheckNDR2012b(&varargin_1[0], &varargin_2[0], &k_emlrtECI,
                             &d_st);
    loop_ub = b.size(0) * b.size(1);
    for (i = 0; i < loop_ub; i++) {
      b[i] = b[i] - r1[i];
    }
    end = b.size(0) * b.size(1) - 1;
    trueCount = 0;
    for (loop_ub = 0; loop_ub <= end; loop_ub++) {
      if (b[loop_ub] < 0.0F) {
        trueCount++;
      }
    }
    r4.set_size(&ud_emlrtRTEI, &d_st, trueCount);
    trueCount = 0;
    for (loop_ub = 0; loop_ub <= end; loop_ub++) {
      if (b[loop_ub] < 0.0F) {
        r4[trueCount] = loop_ub + 1;
        trueCount++;
      }
    }
    loop_ub = r4.size(0) - 1;
    trueCount = b.size(0) * b.size(1);
    for (i = 0; i <= loop_ub; i++) {
      if ((r4[i] < 1) || (r4[i] > trueCount)) {
        emlrtDynamicBoundsCheckR2012b(r4[i], 1, trueCount, &eb_emlrtBCI, &d_st);
      }
      b[r4[i] - 1] = 0.0F;
    }
    d_st.site = &lb_emlrtRSI;
    e_st.site = &ad_emlrtRSI;
    power(&e_st, Ig, I_45_y);
    e_st.site = &bd_emlrtRSI;
    power(&e_st, Iy, I_45);
    varargin_1[0] = (*(int32_T(*)[2])Ig.size())[0];
    varargin_1[1] = (*(int32_T(*)[2])Ig.size())[1];
    varargin_2[0] = (*(int32_T(*)[2])Iy.size())[0];
    varargin_2[1] = (*(int32_T(*)[2])Iy.size())[1];
    emlrtSizeEqCheckNDR2012b(&varargin_1[0], &varargin_2[0], &l_emlrtECI,
                             &d_st);
    e_st.site = &cd_emlrtRSI;
    c_imfilter(&e_st, I_45_y);
    e_st.site = &dd_emlrtRSI;
    c_imfilter(&e_st, I_45);
    loop_ub = Ig.size(0) * Ig.size(1);
    for (i = 0; i < loop_ub; i++) {
      Ig[i] = Ig[i] * Iy[i];
    }
    e_st.site = &ed_emlrtRSI;
    c_imfilter(&e_st, Ig);
    d_st.site = &mb_emlrtRSI;
    vision::internal::calibration::checkerboard::find_peaks(&d_st, cxy,
                                                            points0);
    d_st.site = &nb_emlrtRSI;
    loop_ub = points0.size(0);
    b_points0.set_size(&vd_emlrtRTEI, &d_st, points0.size(0));
    for (i = 0; i < loop_ub; i++) {
      b_points0[i] = points0[i + points0.size(0)];
    }
    loop_ub = points0.size(0);
    c_points0.set_size(&wd_emlrtRTEI, &d_st, points0.size(0));
    for (i = 0; i < loop_ub; i++) {
      c_points0[i] = points0[i];
    }
    varargin_1[0] = (*(int32_T(*)[2])cxy.size())[0];
    varargin_1[1] = (*(int32_T(*)[2])cxy.size())[1];
    e_st.site = &af_emlrtRSI;
    eml_sub2ind(&e_st, varargin_1, b_points0, c_points0, r3);
    s.set_size(&xd_emlrtRTEI, &d_st, r3.size(0));
    loop_ub = r3.size(0);
    for (i = 0; i < loop_ub; i++) {
      s[i] = r3[i];
    }
    varargin_1[0] = (*(int32_T(*)[2])cxy.size())[0];
    varargin_1[1] = (*(int32_T(*)[2])cxy.size())[1];
    d_st.site = &nb_emlrtRSI;
    internal::indexShapeCheck(&d_st, varargin_1, s.size(0));
    trueCount = cxy.size(0) * cxy.size(1);
    loop_ub = s.size(0);
    for (i = 0; i < loop_ub; i++) {
      end = static_cast<int32_T>(s[i]);
      if ((end < 1) || (end > trueCount)) {
        emlrtDynamicBoundsCheckR2012b(end, 1, trueCount, &fb_emlrtBCI, &c_st);
      }
    }
    b_points0.set_size(&yd_emlrtRTEI, &c_st, s.size(0));
    loop_ub = s.size(0);
    for (i = 0; i < loop_ub; i++) {
      b_points0[i] = cxy[static_cast<int32_T>(s[i]) - 1];
    }
    d_st.site = &wb_emlrtRSI;
    board0 = vision::internal::calibration::checkerboard::growCheckerboard(
        &d_st, points0, b_points0, I_45_y, I_45, Ig, 0.0, &lobj_0[0]);
    imagePoints.set_size(&ae_emlrtRTEI, &c_st, 0, 0);
    boardSize[0] = 0.0;
    boardSize[1] = 0.0;
    d_st.site = &ob_emlrtRSI;
    vision::internal::calibration::checkerboard::find_peaks(&d_st, b, points0);
    d_st.site = &pb_emlrtRSI;
    loop_ub = points0.size(0);
    b_points0.set_size(&be_emlrtRTEI, &d_st, points0.size(0));
    for (i = 0; i < loop_ub; i++) {
      b_points0[i] = points0[i + points0.size(0)];
    }
    loop_ub = points0.size(0);
    c_points0.set_size(&ce_emlrtRTEI, &d_st, points0.size(0));
    for (i = 0; i < loop_ub; i++) {
      c_points0[i] = points0[i];
    }
    varargin_1[0] = (*(int32_T(*)[2])b.size())[0];
    varargin_1[1] = (*(int32_T(*)[2])b.size())[1];
    e_st.site = &af_emlrtRSI;
    eml_sub2ind(&e_st, varargin_1, b_points0, c_points0, r3);
    s.set_size(&de_emlrtRTEI, &d_st, r3.size(0));
    loop_ub = r3.size(0);
    for (i = 0; i < loop_ub; i++) {
      s[i] = r3[i];
    }
    varargin_1[0] = (*(int32_T(*)[2])b.size())[0];
    varargin_1[1] = (*(int32_T(*)[2])b.size())[1];
    d_st.site = &pb_emlrtRSI;
    internal::indexShapeCheck(&d_st, varargin_1, s.size(0));
    trueCount = b.size(0) * b.size(1);
    loop_ub = s.size(0);
    for (i = 0; i < loop_ub; i++) {
      end = static_cast<int32_T>(s[i]);
      if ((end < 1) || (end > trueCount)) {
        emlrtDynamicBoundsCheckR2012b(end, 1, trueCount, &gb_emlrtBCI, &c_st);
      }
    }
    b_points0.set_size(&ee_emlrtRTEI, &c_st, s.size(0));
    loop_ub = s.size(0);
    for (i = 0; i < loop_ub; i++) {
      b_points0[i] = b[static_cast<int32_T>(s[i]) - 1];
    }
    d_st.site = &xb_emlrtRSI;
    board45 = vision::internal::calibration::checkerboard::growCheckerboard(
        &d_st, points0, b_points0, I_45_y, I_45, Ig, 0.78539816339744828,
        &lobj_0[3]);
    guard1 = false;
    guard2 = false;
    if (board0->isValid) {
      if (board0->Energy <= board45->Energy) {
        guard2 = true;
      } else {
        boolean_T exitg1;
        boolean_T p;
        varargin_1[0] = board0->BoardIdx.size(0);
        varargin_1[1] = board0->BoardIdx.size(1);
        varargin_2[0] = board45->BoardIdx.size(0);
        varargin_2[1] = board45->BoardIdx.size(1);
        p = true;
        loop_ub = 0;
        exitg1 = false;
        while ((!exitg1) && (loop_ub < 2)) {
          if (varargin_1[loop_ub] != varargin_2[loop_ub]) {
            p = false;
            exitg1 = true;
          } else {
            loop_ub++;
          }
        }
        if (p) {
          s.set_size(&fe_emlrtRTEI, &c_st,
                     board0->BoardIdx.size(0) * board0->BoardIdx.size(1));
          loop_ub = board0->BoardIdx.size(0) * board0->BoardIdx.size(1);
          for (i = 0; i < loop_ub; i++) {
            s[i] = board0->BoardIdx[i];
          }
          end = 0;
          i = s.size(0);
          for (loop_ub = 0; loop_ub < i; loop_ub++) {
            if (s[loop_ub] != 0.0) {
              end++;
            }
          }
          s.set_size(&ge_emlrtRTEI, &c_st,
                     board45->BoardIdx.size(0) * board45->BoardIdx.size(1));
          loop_ub = board45->BoardIdx.size(0) * board45->BoardIdx.size(1);
          for (i = 0; i < loop_ub; i++) {
            s[i] = board45->BoardIdx[i];
          }
          trueCount = 0;
          i = s.size(0);
          for (loop_ub = 0; loop_ub < i; loop_ub++) {
            if (s[loop_ub] != 0.0) {
              trueCount++;
            }
          }
          if (end > trueCount) {
            guard2 = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }
      }
    } else {
      guard1 = true;
    }
    if (guard2) {
      d_st.site = &qb_emlrtRSI;
      board0 = vision::internal::calibration::checkerboard::orient(&d_st,
                                                                   board0, c_I);
      d_st.site = &rb_emlrtRSI;
      vision::internal::calibration::checkerboard::toPoints(
          &d_st, board0, imagePoints, boardSize);
      d_st.site = &sb_emlrtRSI;
      vision::internal::calibration::checkerboard::subPixelLocation(
          &d_st, Ixy, imagePoints);
    }
    if (guard1 && board45->isValid) {
      d_st.site = &tb_emlrtRSI;
      board45 = vision::internal::calibration::checkerboard::orient(
          &d_st, board45, c_I);
      d_st.site = &ub_emlrtRSI;
      vision::internal::calibration::checkerboard::toPoints(
          &d_st, board45, imagePoints, boardSize);
      d_st.site = &vb_emlrtRSI;
      vision::internal::calibration::checkerboard::subPixelLocation(
          &d_st, I_45_x, imagePoints);
    }
  }
  if ((imagePoints.size(0) != 0) && (imagePoints.size(1) != 0)) {
    loop_ub = imagePoints.size(0);
    r.set_size(&rc_emlrtRTEI, &st, imagePoints.size(0));
    for (i = 0; i < loop_ub; i++) {
      r[i] = muDoubleScalarIsNaN(imagePoints[i]);
    }
    b_st.site = &eb_emlrtRSI;
    any(&b_st, r);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace coder
} // namespace Codegen

// End of code generation (detectCheckerboardPoints.cpp)
