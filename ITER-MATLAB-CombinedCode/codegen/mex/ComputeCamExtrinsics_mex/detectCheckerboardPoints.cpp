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
#include "ComputeCamExtrinsics_mex_data.h"
#include "abs.h"
#include "any1.h"
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
    nb_emlrtRSI{
        210,                        // lineNo
        "detectCheckerboardPoints", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectCheckerboardPoin"
        "ts.m" // pathName
    };

static emlrtRSInfo
    ob_emlrtRSI{
        389,          // lineNo
        "detectMono", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectCheckerboardPoin"
        "ts.m" // pathName
    };

static emlrtRSInfo
    pb_emlrtRSI{
        390,          // lineNo
        "detectMono", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectCheckerboardPoin"
        "ts.m" // pathName
    };

static emlrtRSInfo
    qb_emlrtRSI{
        395,          // lineNo
        "detectMono", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectCheckerboardPoin"
        "ts.m" // pathName
    };

static emlrtRSInfo
    rb_emlrtRSI{
        479,          // lineNo
        "checkImage", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectCheckerboardPoin"
        "ts.m" // pathName
    };

static emlrtRSInfo
    ub_emlrtRSI{
        731,                            // lineNo
        "detectCheckerboardInOneImage", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectCheckerboardPoin"
        "ts.m" // pathName
    };

static emlrtRSInfo
    vb_emlrtRSI{
        737,                            // lineNo
        "detectCheckerboardInOneImage", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectCheckerboardPoin"
        "ts.m" // pathName
    };

static emlrtRTEInfo
    pd_emlrtRTEI{
        720,                        // lineNo
        1,                          // colNo
        "detectCheckerboardPoints", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectCheckerboardPoin"
        "ts.m" // pName
    };

// Function Definitions
namespace coder {
void detectCheckerboardPoints(const emlrtStack *sp,
                              const ::coder::array<uint8_T, 2U> &b_I,
                              ::coder::array<real_T, 2U> &imagePoints,
                              real_T boardSize[2])
{
  vision::internal::calibration::checkerboard::Checkerboard lobj_0[6];
  vision::internal::calibration::checkerboard::Checkerboard *board0;
  vision::internal::calibration::checkerboard::Checkerboard *board45;
  array<real_T, 1U> s;
  array<int32_T, 1U> r3;
  array<int32_T, 1U> r4;
  array<real32_T, 2U> I_45;
  array<real32_T, 2U> I_45_x;
  array<real32_T, 2U> I_45_y;
  array<real32_T, 2U> Ig;
  array<real32_T, 2U> Ixy;
  array<real32_T, 2U> Iy;
  array<real32_T, 2U> b;
  array<real32_T, 2U> c_I;
  array<real32_T, 2U> cxy;
  array<real32_T, 2U> points0;
  array<real32_T, 2U> r1;
  array<real32_T, 2U> r2;
  array<real32_T, 1U> b_points0;
  array<real32_T, 1U> c_points0;
  array<boolean_T, 1U> r;
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
  st.site = &nb_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  c_st.site = &rb_emlrtRSI;
  d_st.site = &sb_emlrtRSI;
  e_st.site = &tb_emlrtRSI;
  f_st.site = &v_emlrtRSI;
  if ((b_I.size(0) == 0) || (b_I.size(1) == 0)) {
    emlrtErrorWithMessageIdR2018a(
        &f_st, &j_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonempty",
        "MATLAB:validateImage:expectedNonempty", 3, 4, 1, "I");
  }
  b_st.site = &pb_emlrtRSI;
  c_I.set_size(&pd_emlrtRTEI, &b_st, b_I.size(0), b_I.size(1));
  loop_ub = b_I.size(0) * b_I.size(1);
  for (i = 0; i < loop_ub; i++) {
    c_I[i] = static_cast<real32_T>(b_I[i]) / 255.0F;
  }
  c_st.site = &ub_emlrtRSI;
  vision::internal::calibration::checkerboard::detectCheckerboard(
      &c_st, c_I, imagePoints, boardSize);
  if ((imagePoints.size(0) == 0) || (imagePoints.size(1) == 0)) {
    int32_T end;
    int32_T trueCount;
    boolean_T guard1{false};
    boolean_T guard2{false};
    c_st.site = &vb_emlrtRSI;
    d_st.site = &wb_emlrtRSI;
    Ig.set_size(&qd_emlrtRTEI, &d_st, c_I.size(0), c_I.size(1));
    loop_ub = c_I.size(0) * c_I.size(1);
    for (i = 0; i < loop_ub; i++) {
      Ig[i] = c_I[i];
    }
    e_st.site = &mc_emlrtRSI;
    d_imfilter(&e_st, Ig);
    Iy.set_size(&rd_emlrtRTEI, &d_st, Ig.size(0), Ig.size(1));
    loop_ub = Ig.size(0) * Ig.size(1);
    for (i = 0; i < loop_ub; i++) {
      Iy[i] = Ig[i];
    }
    e_st.site = &nc_emlrtRSI;
    imfilter(&e_st, Iy);
    e_st.site = &oc_emlrtRSI;
    b_imfilter(&e_st, Ig);
    Ixy.set_size(&sd_emlrtRTEI, &d_st, Ig.size(0), Ig.size(1));
    loop_ub = Ig.size(0) * Ig.size(1);
    for (i = 0; i < loop_ub; i++) {
      Ixy[i] = Ig[i];
    }
    e_st.site = &pc_emlrtRSI;
    imfilter(&e_st, Ixy);
    r1.set_size(&td_emlrtRTEI, &d_st, Ig.size(0), Ig.size(1));
    loop_ub = Ig.size(0) * Ig.size(1);
    for (i = 0; i < loop_ub; i++) {
      r1[i] = Ig[i] * 0.707106769F;
    }
    I_45.set_size(&ud_emlrtRTEI, &d_st, Iy.size(0), Iy.size(1));
    loop_ub = Iy.size(0) * Iy.size(1);
    for (i = 0; i < loop_ub; i++) {
      I_45[i] = Iy[i] * 0.707106769F;
    }
    varargin_1[0] = (*(int32_T(*)[2])r1.size())[0];
    varargin_1[1] = (*(int32_T(*)[2])r1.size())[1];
    varargin_2[0] = (*(int32_T(*)[2])I_45.size())[0];
    varargin_2[1] = (*(int32_T(*)[2])I_45.size())[1];
    emlrtSizeEqCheckNDR2012b(&varargin_1[0], &varargin_2[0], &d_emlrtECI,
                             &d_st);
    loop_ub = r1.size(0) * r1.size(1);
    I_45.set_size(&vd_emlrtRTEI, &d_st, r1.size(0), r1.size(1));
    for (i = 0; i < loop_ub; i++) {
      I_45[i] = r1[i] + I_45[i];
    }
    r2.set_size(&wd_emlrtRTEI, &d_st, Iy.size(0), Iy.size(1));
    loop_ub = Iy.size(0) * Iy.size(1);
    for (i = 0; i < loop_ub; i++) {
      r2[i] = Iy[i] * -0.707106769F;
    }
    varargin_1[0] = (*(int32_T(*)[2])r1.size())[0];
    varargin_1[1] = (*(int32_T(*)[2])r1.size())[1];
    varargin_2[0] = (*(int32_T(*)[2])r2.size())[0];
    varargin_2[1] = (*(int32_T(*)[2])r2.size())[1];
    emlrtSizeEqCheckNDR2012b(&varargin_1[0], &varargin_2[0], &e_emlrtECI,
                             &d_st);
    I_45_x.set_size(&xd_emlrtRTEI, &d_st, I_45.size(0), I_45.size(1));
    loop_ub = I_45.size(0) * I_45.size(1);
    for (i = 0; i < loop_ub; i++) {
      I_45_x[i] = I_45[i];
    }
    e_st.site = &qc_emlrtRSI;
    b_imfilter(&e_st, I_45_x);
    I_45_y.set_size(&yd_emlrtRTEI, &d_st, I_45.size(0), I_45.size(1));
    loop_ub = I_45.size(0) * I_45.size(1);
    for (i = 0; i < loop_ub; i++) {
      I_45_y[i] = I_45[i];
    }
    e_st.site = &rc_emlrtRSI;
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
    emlrtSizeEqCheckNDR2012b(&varargin_1[0], &varargin_2[0], &f_emlrtECI,
                             &d_st);
    loop_ub = I_45_x.size(0) * I_45_x.size(1);
    for (i = 0; i < loop_ub; i++) {
      I_45_x[i] = I_45_x[i] + I_45_y[i];
    }
    e_st.site = &sc_emlrtRSI;
    b_abs(&e_st, I_45, I_45_y);
    I_45.set_size(&ae_emlrtRTEI, &d_st, r1.size(0), r1.size(1));
    loop_ub = r1.size(0) * r1.size(1);
    for (i = 0; i < loop_ub; i++) {
      I_45[i] = r1[i] + r2[i];
    }
    e_st.site = &sc_emlrtRSI;
    b_abs(&e_st, I_45, r1);
    varargin_1[0] = (*(int32_T(*)[2])I_45_y.size())[0];
    varargin_1[1] = (*(int32_T(*)[2])I_45_y.size())[1];
    varargin_2[0] = (*(int32_T(*)[2])r1.size())[0];
    varargin_2[1] = (*(int32_T(*)[2])r1.size())[1];
    emlrtSizeEqCheckNDR2012b(&varargin_1[0], &varargin_2[0], &g_emlrtECI,
                             &d_st);
    e_st.site = &sc_emlrtRSI;
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
    emlrtSizeEqCheckNDR2012b(&varargin_1[0], &varargin_2[0], &h_emlrtECI,
                             &d_st);
    cxy.set_size(&be_emlrtRTEI, &d_st, b.size(0), b.size(1));
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
    r3.set_size(&ce_emlrtRTEI, &d_st, trueCount);
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
        emlrtDynamicBoundsCheckR2012b(r3[i], 1, trueCount, &m_emlrtBCI, &d_st);
      }
      cxy[r3[i] - 1] = 0.0F;
    }
    e_st.site = &tc_emlrtRSI;
    b_abs(&e_st, Ig, r1);
    e_st.site = &tc_emlrtRSI;
    b_abs(&e_st, Iy, r2);
    varargin_1[0] = (*(int32_T(*)[2])r1.size())[0];
    varargin_1[1] = (*(int32_T(*)[2])r1.size())[1];
    varargin_2[0] = (*(int32_T(*)[2])r2.size())[0];
    varargin_2[1] = (*(int32_T(*)[2])r2.size())[1];
    emlrtSizeEqCheckNDR2012b(&varargin_1[0], &varargin_2[0], &i_emlrtECI,
                             &d_st);
    e_st.site = &tc_emlrtRSI;
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
    emlrtSizeEqCheckNDR2012b(&varargin_1[0], &varargin_2[0], &j_emlrtECI,
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
    r4.set_size(&ce_emlrtRTEI, &d_st, trueCount);
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
        emlrtDynamicBoundsCheckR2012b(r4[i], 1, trueCount, &n_emlrtBCI, &d_st);
      }
      b[r4[i] - 1] = 0.0F;
    }
    d_st.site = &xb_emlrtRSI;
    e_st.site = &ld_emlrtRSI;
    power(&e_st, Ig, I_45_y);
    e_st.site = &md_emlrtRSI;
    power(&e_st, Iy, I_45);
    varargin_1[0] = (*(int32_T(*)[2])Ig.size())[0];
    varargin_1[1] = (*(int32_T(*)[2])Ig.size())[1];
    varargin_2[0] = (*(int32_T(*)[2])Iy.size())[0];
    varargin_2[1] = (*(int32_T(*)[2])Iy.size())[1];
    emlrtSizeEqCheckNDR2012b(&varargin_1[0], &varargin_2[0], &k_emlrtECI,
                             &d_st);
    e_st.site = &nd_emlrtRSI;
    c_imfilter(&e_st, I_45_y);
    e_st.site = &od_emlrtRSI;
    c_imfilter(&e_st, I_45);
    loop_ub = Ig.size(0) * Ig.size(1);
    for (i = 0; i < loop_ub; i++) {
      Ig[i] = Ig[i] * Iy[i];
    }
    e_st.site = &pd_emlrtRSI;
    c_imfilter(&e_st, Ig);
    d_st.site = &yb_emlrtRSI;
    vision::internal::calibration::checkerboard::find_peaks(&d_st, cxy,
                                                            points0);
    d_st.site = &ac_emlrtRSI;
    loop_ub = points0.size(0);
    b_points0.set_size(&de_emlrtRTEI, &d_st, points0.size(0));
    for (i = 0; i < loop_ub; i++) {
      b_points0[i] = points0[i + points0.size(0)];
    }
    loop_ub = points0.size(0);
    c_points0.set_size(&ee_emlrtRTEI, &d_st, points0.size(0));
    for (i = 0; i < loop_ub; i++) {
      c_points0[i] = points0[i];
    }
    varargin_1[0] = (*(int32_T(*)[2])cxy.size())[0];
    varargin_1[1] = (*(int32_T(*)[2])cxy.size())[1];
    e_st.site = &vf_emlrtRSI;
    eml_sub2ind(&e_st, varargin_1, b_points0, c_points0, r3);
    s.set_size(&fe_emlrtRTEI, &d_st, r3.size(0));
    loop_ub = r3.size(0);
    for (i = 0; i < loop_ub; i++) {
      s[i] = r3[i];
    }
    varargin_1[0] = (*(int32_T(*)[2])cxy.size())[0];
    varargin_1[1] = (*(int32_T(*)[2])cxy.size())[1];
    d_st.site = &ac_emlrtRSI;
    internal::indexShapeCheck(&d_st, varargin_1, s.size(0));
    trueCount = cxy.size(0) * cxy.size(1);
    loop_ub = s.size(0);
    for (i = 0; i < loop_ub; i++) {
      end = static_cast<int32_T>(s[i]);
      if ((end < 1) || (end > trueCount)) {
        emlrtDynamicBoundsCheckR2012b(end, 1, trueCount, &o_emlrtBCI, &c_st);
      }
    }
    b_points0.set_size(&ge_emlrtRTEI, &c_st, s.size(0));
    loop_ub = s.size(0);
    for (i = 0; i < loop_ub; i++) {
      b_points0[i] = cxy[static_cast<int32_T>(s[i]) - 1];
    }
    d_st.site = &kc_emlrtRSI;
    board0 = vision::internal::calibration::checkerboard::growCheckerboard(
        &d_st, points0, b_points0, I_45_y, I_45, Ig, 0.0, &lobj_0[0]);
    imagePoints.set_size(&he_emlrtRTEI, &c_st, 0, 0);
    boardSize[0] = 0.0;
    boardSize[1] = 0.0;
    d_st.site = &bc_emlrtRSI;
    vision::internal::calibration::checkerboard::find_peaks(&d_st, b, points0);
    d_st.site = &cc_emlrtRSI;
    loop_ub = points0.size(0);
    b_points0.set_size(&ie_emlrtRTEI, &d_st, points0.size(0));
    for (i = 0; i < loop_ub; i++) {
      b_points0[i] = points0[i + points0.size(0)];
    }
    loop_ub = points0.size(0);
    c_points0.set_size(&je_emlrtRTEI, &d_st, points0.size(0));
    for (i = 0; i < loop_ub; i++) {
      c_points0[i] = points0[i];
    }
    varargin_1[0] = (*(int32_T(*)[2])b.size())[0];
    varargin_1[1] = (*(int32_T(*)[2])b.size())[1];
    e_st.site = &vf_emlrtRSI;
    eml_sub2ind(&e_st, varargin_1, b_points0, c_points0, r3);
    s.set_size(&ke_emlrtRTEI, &d_st, r3.size(0));
    loop_ub = r3.size(0);
    for (i = 0; i < loop_ub; i++) {
      s[i] = r3[i];
    }
    varargin_1[0] = (*(int32_T(*)[2])b.size())[0];
    varargin_1[1] = (*(int32_T(*)[2])b.size())[1];
    d_st.site = &cc_emlrtRSI;
    internal::indexShapeCheck(&d_st, varargin_1, s.size(0));
    trueCount = b.size(0) * b.size(1);
    loop_ub = s.size(0);
    for (i = 0; i < loop_ub; i++) {
      end = static_cast<int32_T>(s[i]);
      if ((end < 1) || (end > trueCount)) {
        emlrtDynamicBoundsCheckR2012b(end, 1, trueCount, &p_emlrtBCI, &c_st);
      }
    }
    b_points0.set_size(&le_emlrtRTEI, &c_st, s.size(0));
    loop_ub = s.size(0);
    for (i = 0; i < loop_ub; i++) {
      b_points0[i] = b[static_cast<int32_T>(s[i]) - 1];
    }
    d_st.site = &lc_emlrtRSI;
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
          d_st.site = &dc_emlrtRSI;
          s.set_size(&me_emlrtRTEI, &d_st,
                     board0->BoardIdx.size(0) * board0->BoardIdx.size(1));
          loop_ub = board0->BoardIdx.size(0) * board0->BoardIdx.size(1);
          for (i = 0; i < loop_ub; i++) {
            s[i] = board0->BoardIdx[i];
          }
          e_st.site = &bm_emlrtRSI;
          end = 0;
          i = s.size(0);
          for (loop_ub = 0; loop_ub < i; loop_ub++) {
            if (s[loop_ub] != 0.0) {
              end++;
            }
          }
          d_st.site = &dc_emlrtRSI;
          s.set_size(&ne_emlrtRTEI, &d_st,
                     board45->BoardIdx.size(0) * board45->BoardIdx.size(1));
          loop_ub = board45->BoardIdx.size(0) * board45->BoardIdx.size(1);
          for (i = 0; i < loop_ub; i++) {
            s[i] = board45->BoardIdx[i];
          }
          e_st.site = &bm_emlrtRSI;
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
      d_st.site = &ec_emlrtRSI;
      board0 = vision::internal::calibration::checkerboard::orient(&d_st,
                                                                   board0, c_I);
      d_st.site = &fc_emlrtRSI;
      vision::internal::calibration::checkerboard::toPoints(
          &d_st, board0, imagePoints, boardSize);
      d_st.site = &gc_emlrtRSI;
      vision::internal::calibration::checkerboard::subPixelLocation(
          &d_st, Ixy, imagePoints);
    }
    if (guard1 && board45->isValid) {
      d_st.site = &hc_emlrtRSI;
      board45 = vision::internal::calibration::checkerboard::orient(
          &d_st, board45, c_I);
      d_st.site = &ic_emlrtRSI;
      vision::internal::calibration::checkerboard::toPoints(
          &d_st, board45, imagePoints, boardSize);
      d_st.site = &jc_emlrtRSI;
      vision::internal::calibration::checkerboard::subPixelLocation(
          &d_st, I_45_x, imagePoints);
    }
  }
  if ((imagePoints.size(0) != 0) && (imagePoints.size(1) != 0)) {
    loop_ub = imagePoints.size(0);
    r.set_size(&oe_emlrtRTEI, &st, imagePoints.size(0));
    for (i = 0; i < loop_ub; i++) {
      r[i] = muDoubleScalarIsNaN(imagePoints[i]);
    }
    b_st.site = &qb_emlrtRSI;
    b_any(&b_st, r);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace coder

// End of code generation (detectCheckerboardPoints.cpp)
