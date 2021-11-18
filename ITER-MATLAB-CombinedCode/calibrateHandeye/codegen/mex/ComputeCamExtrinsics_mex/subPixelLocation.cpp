//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// subPixelLocation.cpp
//
// Code generation for function 'subPixelLocation'
//

// Include files
#include "subPixelLocation.h"
#include "ComputeCamExtrinsics_mex_data.h"
#include "any1.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <algorithm>

// Variable Definitions
static real_T X[150];

static emlrtRSInfo rt_emlrtRSI{
    9,                  // lineNo
    "subPixelLocation", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m" // pathName
};

static emlrtRSInfo st_emlrtRSI{
    23,                     // lineNo
    "subPixelLocationImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m" // pathName
};

static emlrtRSInfo tt_emlrtRSI{
    43,                     // lineNo
    "subPixelLocationImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m" // pathName
};

static emlrtRSInfo ut_emlrtRSI{
    54,                     // lineNo
    "subPixelLocationImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m" // pathName
};

static emlrtRSInfo vt_emlrtRSI{
    55,                     // lineNo
    "subPixelLocationImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m" // pathName
};

static emlrtBCInfo ow_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    9,                  // lineNo
    50,                 // colNo
    "",                 // aName
    "subPixelLocation", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m", // pName
    0                                                 // checkKind
};

static emlrtBCInfo pw_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    9,                  // lineNo
    9,                  // colNo
    "",                 // aName
    "subPixelLocation", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m", // pName
    0                                                 // checkKind
};

static emlrtECInfo de_emlrtECI{
    -1,                 // nDims
    9,                  // lineNo
    5,                  // colNo
    "subPixelLocation", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m" // pName
};

static emlrtBCInfo qw_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    23,                     // lineNo
    43,                     // colNo
    "",                     // aName
    "subPixelLocationImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m", // pName
    0                                                 // checkKind
};

static emlrtBCInfo rw_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    24,                     // lineNo
    12,                     // colNo
    "",                     // aName
    "subPixelLocationImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m", // pName
    0                                                 // checkKind
};

static emlrtBCInfo sw_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    30,                     // lineNo
    20,                     // colNo
    "",                     // aName
    "subPixelLocationImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m", // pName
    0                                                 // checkKind
};

static emlrtBCInfo tw_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    30,                     // lineNo
    41,                     // colNo
    "",                     // aName
    "subPixelLocationImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m", // pName
    0                                                 // checkKind
};

static emlrtDCInfo eh_emlrtDCI{
    30,                     // lineNo
    16,                     // colNo
    "subPixelLocationImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m", // pName
    1                                                 // checkKind
};

static emlrtBCInfo uw_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    30,                     // lineNo
    16,                     // colNo
    "",                     // aName
    "subPixelLocationImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m", // pName
    0                                                 // checkKind
};

static emlrtDCInfo fh_emlrtDCI{
    30,                     // lineNo
    37,                     // colNo
    "subPixelLocationImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m", // pName
    1                                                 // checkKind
};

static emlrtBCInfo vw_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    30,                     // lineNo
    37,                     // colNo
    "",                     // aName
    "subPixelLocationImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m", // pName
    0                                                 // checkKind
};

static emlrtBCInfo ww_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    31,                     // lineNo
    20,                     // colNo
    "",                     // aName
    "subPixelLocationImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m", // pName
    0                                                 // checkKind
};

static emlrtBCInfo xw_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    31,                     // lineNo
    41,                     // colNo
    "",                     // aName
    "subPixelLocationImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m", // pName
    0                                                 // checkKind
};

static emlrtDCInfo gh_emlrtDCI{
    31,                     // lineNo
    16,                     // colNo
    "subPixelLocationImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m", // pName
    1                                                 // checkKind
};

static emlrtBCInfo yw_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    31,                     // lineNo
    16,                     // colNo
    "",                     // aName
    "subPixelLocationImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m", // pName
    0                                                 // checkKind
};

static emlrtDCInfo hh_emlrtDCI{
    31,                     // lineNo
    37,                     // colNo
    "subPixelLocationImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m", // pName
    1                                                 // checkKind
};

static emlrtBCInfo ax_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    31,                     // lineNo
    37,                     // colNo
    "",                     // aName
    "subPixelLocationImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m", // pName
    0                                                 // checkKind
};

static emlrtECInfo ee_emlrtECI{
    2,                      // nDims
    62,                     // lineNo
    15,                     // colNo
    "subPixelLocationImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m" // pName
};

static emlrtRTEInfo dw_emlrtRTEI{
    9,                  // lineNo
    12,                 // colNo
    "subPixelLocation", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m" // pName
};

static emlrtRTEInfo ew_emlrtRTEI{
    9,                  // lineNo
    46,                 // colNo
    "subPixelLocation", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m" // pName
};

static emlrtRTEInfo fw_emlrtRTEI{
    23,                 // lineNo
    8,                  // colNo
    "subPixelLocation", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m" // pName
};

static emlrtRTEInfo gw_emlrtRTEI{
    30,                 // lineNo
    9,                  // colNo
    "subPixelLocation", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m" // pName
};

static emlrtRTEInfo hw_emlrtRTEI{
    62,                 // lineNo
    1,                  // colNo
    "subPixelLocation", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m" // pName
};

static emlrtRTEInfo iw_emlrtRTEI{
    25,                 // lineNo
    5,                  // colNo
    "subPixelLocation", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m" // pName
};

static emlrtRTEInfo jw_emlrtRTEI{
    9,                  // lineNo
    5,                  // colNo
    "subPixelLocation", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m" // pName
};

// Function Definitions
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void subPixelLocation(const emlrtStack *sp,
                      const ::coder::array<real32_T, 2U> &metric,
                      ::coder::array<real_T, 2U> &loc)
{
  array<real_T, 2U> b_loc;
  array<real_T, 2U> d_loc;
  array<int32_T, 1U> r;
  array<real32_T, 2U> b_metric;
  array<real32_T, 2U> subPixelLoc;
  array<boolean_T, 1U> c_loc;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T b_iv[2];
  int32_T iv1[2];
  int32_T i;
  real32_T beta[6];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  i = loc.size(0);
  for (int32_T id{0}; id < i; id++) {
    int32_T i1;
    int32_T loop_ub;
    boolean_T guard1{false};
    i1 = loc.size(0);
    if ((id + 1 < 1) || (id + 1 > i1)) {
      emlrtDynamicBoundsCheckR2012b(id + 1, 1, i1, &pw_emlrtBCI, (emlrtCTX)sp);
    }
    loop_ub = loc.size(1);
    r.set_size(&dw_emlrtRTEI, sp, loop_ub);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r[i1] = i1;
    }
    st.site = &rt_emlrtRSI;
    i1 = loc.size(0);
    if ((static_cast<int32_T>(id + 1U) < 1) ||
        (static_cast<int32_T>(id + 1U) > i1)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(id + 1U), 1, i1,
                                    &ow_emlrtBCI, &st);
    }
    loop_ub = loc.size(1);
    b_loc.set_size(&ew_emlrtRTEI, &st, 1, loop_ub);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_loc[i1] = loc[id + loc.size(0) * i1];
    }
    loop_ub = loc.size(1);
    c_loc.set_size(&fw_emlrtRTEI, &st, loop_ub);
    for (i1 = 0; i1 < loop_ub; i1++) {
      c_loc[i1] = (b_loc[i1] < 3.0);
    }
    guard1 = false;
    b_st.site = &st_emlrtRSI;
    if (b_any(&b_st, c_loc)) {
      guard1 = true;
    } else {
      i1 = loc.size(1);
      if (1 > i1) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i1, &qw_emlrtBCI, &st);
      }
      if (loc[id] > (static_cast<real_T>(metric.size(1)) - 2.0) - 1.0) {
        guard1 = true;
      } else {
        i1 = loc.size(1);
        if (2 > i1) {
          emlrtDynamicBoundsCheckR2012b(2, 1, i1, &rw_emlrtBCI, &st);
        }
        if (loc[id + loc.size(0)] >
            (static_cast<real_T>(metric.size(0)) - 2.0) - 1.0) {
          guard1 = true;
        } else {
          real_T d;
          int32_T b_loop_ub;
          int32_T i2;
          int32_T i3;
          int32_T i4;
          real32_T x;
          real32_T y;
          i1 = loc.size(1);
          if (2 > i1) {
            emlrtDynamicBoundsCheckR2012b(2, 1, i1, &sw_emlrtBCI, &st);
          }
          i1 = loc.size(1);
          if (2 > i1) {
            emlrtDynamicBoundsCheckR2012b(2, 1, i1, &tw_emlrtBCI, &st);
          }
          if (loc[id + loc.size(0)] - 2.0 > loc[id + loc.size(0)] + 2.0) {
            i1 = -1;
            i2 = -1;
          } else {
            d = loc[id + loc.size(0)] - 2.0;
            if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
              emlrtIntegerCheckR2012b(d, &eh_emlrtDCI, &st);
            }
            if ((static_cast<int32_T>(d) < 1) ||
                (static_cast<int32_T>(d) > metric.size(0))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                                            metric.size(0), &uw_emlrtBCI, &st);
            }
            i1 = static_cast<int32_T>(d) - 2;
            d = loc[id + loc.size(0)] + 2.0;
            if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
              emlrtIntegerCheckR2012b(d, &fh_emlrtDCI, &st);
            }
            if ((static_cast<int32_T>(d) < 1) ||
                (static_cast<int32_T>(d) > metric.size(0))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                                            metric.size(0), &vw_emlrtBCI, &st);
            }
            i2 = static_cast<int32_T>(d) - 1;
          }
          i3 = loc.size(1);
          if (1 > i3) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i3, &ww_emlrtBCI, &st);
          }
          i3 = loc.size(1);
          if (1 > i3) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i3, &xw_emlrtBCI, &st);
          }
          if (loc[id] - 2.0 > loc[id] + 2.0) {
            i3 = -1;
            i4 = -1;
          } else {
            d = loc[id] - 2.0;
            if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
              emlrtIntegerCheckR2012b(d, &gh_emlrtDCI, &st);
            }
            if ((static_cast<int32_T>(d) < 1) ||
                (static_cast<int32_T>(d) > metric.size(1))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                                            metric.size(1), &yw_emlrtBCI, &st);
            }
            i3 = static_cast<int32_T>(d) - 2;
            d = loc[id] + 2.0;
            if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
              emlrtIntegerCheckR2012b(d, &hh_emlrtDCI, &st);
            }
            if ((static_cast<int32_T>(d) < 1) ||
                (static_cast<int32_T>(d) > metric.size(1))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                                            metric.size(1), &ax_emlrtBCI, &st);
            }
            i4 = static_cast<int32_T>(d) - 1;
          }
          b_st.site = &tt_emlrtRSI;
          c_st.site = &ti_emlrtRSI;
          loop_ub = i2 - i1;
          b_loop_ub = i4 - i3;
          i2 = loop_ub * b_loop_ub;
          if (25 != i2) {
            if (i2 == 1) {
              emlrtErrorWithMessageIdR2018a(
                  &c_st, &db_emlrtRTEI,
                  "Coder:toolbox:mtimes_noDynamicScalarExpansion",
                  "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
            } else {
              emlrtErrorWithMessageIdR2018a(&c_st, &eb_emlrtRTEI,
                                            "MATLAB:innerdim",
                                            "MATLAB:innerdim", 0);
            }
          }
          b_metric.set_size(&gw_emlrtRTEI, &b_st, loop_ub, b_loop_ub);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            for (i4 = 0; i4 < loop_ub; i4++) {
              b_metric[i4 + b_metric.size(0) * i2] =
                  metric[((i1 + i4) + metric.size(0) * ((i3 + i2) + 1)) + 1];
            }
          }
          for (i1 = 0; i1 < 6; i1++) {
            y = 0.0F;
            for (i2 = 0; i2 < 25; i2++) {
              y += static_cast<real32_T>(X[i1 + 6 * i2]) * b_metric[i2];
            }
            beta[i1] = y;
          }
          b_st.site = &ut_emlrtRSI;
          y = 4.0F * beta[0] * beta[1] - beta[4] * beta[4];
          x = -(2.0F * beta[1] * beta[2] - beta[3] * beta[4]) / y;
          b_st.site = &vt_emlrtRSI;
          y = -(2.0F * beta[0] * beta[3] - beta[2] * beta[4]) / y;
          if (muSingleScalarIsInf(x) || muSingleScalarIsNaN(x) ||
              (muSingleScalarAbs(x) > 2.0F) ||
              (muSingleScalarIsInf(y) || muSingleScalarIsNaN(y)) ||
              (muSingleScalarAbs(y) > 2.0F)) {
            x = 0.0F;
            y = 0.0F;
          }
          loop_ub = loc.size(1);
          d_loc.set_size(&ew_emlrtRTEI, &st, 1, loop_ub);
          for (i1 = 0; i1 < loop_ub; i1++) {
            d_loc[i1] = loc[id + loc.size(0) * i1];
          }
          b_iv[0] = 1;
          b_iv[1] = 2;
          iv1[0] = (*(int32_T(*)[2])d_loc.size())[0];
          iv1[1] = (*(int32_T(*)[2])d_loc.size())[1];
          emlrtSizeEqCheckNDR2012b(&iv1[0], &b_iv[0], &ee_emlrtECI, &st);
          subPixelLoc.set_size(&hw_emlrtRTEI, &st, 1, 2);
          subPixelLoc[0] = static_cast<real32_T>(b_loc[0]) + x;
          subPixelLoc[1] = static_cast<real32_T>(b_loc[1]) + y;
        }
      }
    }
    if (guard1) {
      subPixelLoc.set_size(&iw_emlrtRTEI, &st, 1, b_loc.size(1));
      loop_ub = b_loc.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        subPixelLoc[i1] = static_cast<real32_T>(b_loc[i1]);
      }
    }
    b_loc.set_size(&jw_emlrtRTEI, sp, 1, subPixelLoc.size(1));
    loop_ub = subPixelLoc.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_loc[i1] = subPixelLoc[i1];
    }
    b_iv[0] = 1;
    b_iv[1] = r.size(0);
    emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, b_loc.size(), 2, &de_emlrtECI,
                                  (emlrtCTX)sp);
    loop_ub = b_loc.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      loc[id + loc.size(0) * r[i1]] = b_loc[i1];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
void subPixelLocationImpl_init()
{
  static const real_T b_dv[150]{0.028571428571428574,
                                0.028571428571428574,
                                -0.04,
                                -0.04,
                                0.04,
                                -0.0742857142857143,
                                0.028571428571428574,
                                -0.014285714285714285,
                                -0.04,
                                -0.02,
                                0.02,
                                0.01142857142857142,
                                0.028571428571428574,
                                -0.028571428571428571,
                                -0.04,
                                0.0,
                                0.0,
                                0.039999999999999994,
                                0.028571428571428574,
                                -0.014285714285714285,
                                -0.04,
                                0.02,
                                -0.02,
                                0.01142857142857142,
                                0.028571428571428574,
                                0.028571428571428574,
                                -0.04,
                                0.04,
                                -0.04,
                                -0.0742857142857143,
                                -0.014285714285714287,
                                0.028571428571428571,
                                -0.02,
                                -0.04,
                                0.02,
                                0.011428571428571429,
                                -0.014285714285714285,
                                -0.014285714285714284,
                                -0.02,
                                -0.02,
                                0.01,
                                0.097142857142857142,
                                -0.01428571428571429,
                                -0.028571428571428574,
                                -0.02,
                                0.0,
                                0.0,
                                0.12571428571428572,
                                -0.014285714285714285,
                                -0.014285714285714284,
                                -0.02,
                                0.02,
                                -0.01,
                                0.097142857142857142,
                                -0.014285714285714287,
                                0.028571428571428571,
                                -0.02,
                                0.04,
                                -0.02,
                                0.011428571428571429,
                                -0.028571428571428574,
                                0.028571428571428571,
                                0.0,
                                -0.04,
                                0.0,
                                0.040000000000000008,
                                -0.028571428571428574,
                                -0.014285714285714287,
                                0.0,
                                -0.02,
                                0.0,
                                0.12571428571428572,
                                -0.028571428571428574,
                                -0.028571428571428574,
                                0.0,
                                0.0,
                                0.0,
                                0.1542857142857143,
                                -0.028571428571428574,
                                -0.014285714285714287,
                                0.0,
                                0.02,
                                0.0,
                                0.12571428571428572,
                                -0.028571428571428574,
                                0.028571428571428571,
                                0.0,
                                0.04,
                                0.0,
                                0.040000000000000008,
                                -0.014285714285714287,
                                0.028571428571428571,
                                0.02,
                                -0.04,
                                -0.02,
                                0.011428571428571429,
                                -0.014285714285714285,
                                -0.014285714285714284,
                                0.02,
                                -0.02,
                                -0.01,
                                0.097142857142857142,
                                -0.01428571428571429,
                                -0.028571428571428574,
                                0.02,
                                0.0,
                                0.0,
                                0.12571428571428572,
                                -0.014285714285714285,
                                -0.014285714285714284,
                                0.02,
                                0.02,
                                0.01,
                                0.097142857142857142,
                                -0.014285714285714287,
                                0.028571428571428571,
                                0.02,
                                0.04,
                                0.02,
                                0.011428571428571429,
                                0.028571428571428574,
                                0.028571428571428574,
                                0.04,
                                -0.04,
                                -0.04,
                                -0.0742857142857143,
                                0.028571428571428574,
                                -0.014285714285714285,
                                0.04,
                                -0.02,
                                -0.02,
                                0.01142857142857142,
                                0.028571428571428574,
                                -0.028571428571428571,
                                0.04,
                                0.0,
                                0.0,
                                0.039999999999999994,
                                0.028571428571428574,
                                -0.014285714285714285,
                                0.04,
                                0.02,
                                0.02,
                                0.01142857142857142,
                                0.028571428571428574,
                                0.028571428571428574,
                                0.04,
                                0.04,
                                0.04,
                                -0.0742857142857143};
  std::copy(&b_dv[0], &b_dv[150], &X[0]);
}

// End of code generation (subPixelLocation.cpp)
