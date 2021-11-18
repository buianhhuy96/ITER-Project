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
#include "any1.h"
#include "calibrateCamera_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <algorithm>

// Variable Definitions
static real_T X[150];

static emlrtRSInfo or_emlrtRSI{
    9,                  // lineNo
    "subPixelLocation", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m" // pathName
};

static emlrtRSInfo pr_emlrtRSI{
    23,                     // lineNo
    "subPixelLocationImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m" // pathName
};

static emlrtRSInfo qr_emlrtRSI{
    43,                     // lineNo
    "subPixelLocationImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m" // pathName
};

static emlrtRSInfo rr_emlrtRSI{
    54,                     // lineNo
    "subPixelLocationImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m" // pathName
};

static emlrtRSInfo sr_emlrtRSI{
    55,                     // lineNo
    "subPixelLocationImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m" // pathName
};

static emlrtBCInfo av_emlrtBCI{
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

static emlrtBCInfo bv_emlrtBCI{
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

static emlrtECInfo be_emlrtECI{
    -1,                 // nDims
    9,                  // lineNo
    5,                  // colNo
    "subPixelLocation", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m" // pName
};

static emlrtBCInfo cv_emlrtBCI{
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

static emlrtBCInfo dv_emlrtBCI{
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

static emlrtBCInfo ev_emlrtBCI{
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

static emlrtBCInfo fv_emlrtBCI{
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

static emlrtDCInfo nd_emlrtDCI{
    30,                     // lineNo
    16,                     // colNo
    "subPixelLocationImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m", // pName
    1                                                 // checkKind
};

static emlrtBCInfo gv_emlrtBCI{
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

static emlrtDCInfo od_emlrtDCI{
    30,                     // lineNo
    37,                     // colNo
    "subPixelLocationImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m", // pName
    1                                                 // checkKind
};

static emlrtBCInfo hv_emlrtBCI{
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

static emlrtBCInfo iv_emlrtBCI{
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

static emlrtBCInfo jv_emlrtBCI{
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

static emlrtDCInfo pd_emlrtDCI{
    31,                     // lineNo
    16,                     // colNo
    "subPixelLocationImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m", // pName
    1                                                 // checkKind
};

static emlrtBCInfo kv_emlrtBCI{
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

static emlrtDCInfo qd_emlrtDCI{
    31,                     // lineNo
    37,                     // colNo
    "subPixelLocationImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m", // pName
    1                                                 // checkKind
};

static emlrtBCInfo lv_emlrtBCI{
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

static emlrtECInfo ce_emlrtECI{
    2,                      // nDims
    62,                     // lineNo
    15,                     // colNo
    "subPixelLocationImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m" // pName
};

static emlrtRTEInfo ms_emlrtRTEI{
    30,                 // lineNo
    9,                  // colNo
    "subPixelLocation", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\subPixelLocation.m" // pName
};

// Function Definitions
namespace Codegen {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void subPixelLocation(const emlrtStack *sp,
                      const ::coder::array<real32_T, 2U> &metric,
                      ::coder::array<real_T, 2U> &loc)
{
  ::coder::array<real32_T, 2U> b_metric;
  ::coder::array<boolean_T, 1U> loc_data;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T c_loc_data[2];
  int32_T iv[2];
  int32_T loc_size[2];
  int32_T i;
  real32_T beta[6];
  real32_T subPixelLoc_data[2];
  boolean_T b_loc_data[2];
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
      emlrtDynamicBoundsCheckR2012b(id + 1, 1, i1, &bv_emlrtBCI, (emlrtCTX)sp);
    }
    st.site = &or_emlrtRSI;
    i1 = loc.size(0);
    if ((id + 1 < 1) || (id + 1 > i1)) {
      emlrtDynamicBoundsCheckR2012b(id + 1, 1, i1, &av_emlrtBCI, &st);
    }
    loop_ub = loc.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_loc_data[i1] = (loc[id + loc.size(0) * i1] < 3.0);
    }
    loc_data.set(&b_loc_data[0], loop_ub);
    guard1 = false;
    b_st.site = &pr_emlrtRSI;
    if (any(&b_st, loc_data)) {
      guard1 = true;
    } else {
      i1 = loc.size(1);
      if (1 > i1) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i1, &cv_emlrtBCI, &st);
      }
      if (loc[id] > (static_cast<real_T>(metric.size(1)) - 2.0) - 1.0) {
        guard1 = true;
      } else {
        i1 = loc.size(1);
        if (2 > i1) {
          emlrtDynamicBoundsCheckR2012b(2, 1, i1, &dv_emlrtBCI, &st);
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
            emlrtDynamicBoundsCheckR2012b(2, 1, i1, &ev_emlrtBCI, &st);
          }
          i1 = loc.size(1);
          if (2 > i1) {
            emlrtDynamicBoundsCheckR2012b(2, 1, i1, &fv_emlrtBCI, &st);
          }
          if (loc[id + loc.size(0)] - 2.0 > loc[id + loc.size(0)] + 2.0) {
            i1 = -1;
            i2 = -1;
          } else {
            d = loc[id + loc.size(0)] - 2.0;
            if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
              emlrtIntegerCheckR2012b(d, &nd_emlrtDCI, &st);
            }
            if ((static_cast<int32_T>(d) < 1) ||
                (static_cast<int32_T>(d) > metric.size(0))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                                            metric.size(0), &gv_emlrtBCI, &st);
            }
            i1 = static_cast<int32_T>(d) - 2;
            d = loc[id + loc.size(0)] + 2.0;
            if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
              emlrtIntegerCheckR2012b(d, &od_emlrtDCI, &st);
            }
            if ((static_cast<int32_T>(d) < 1) ||
                (static_cast<int32_T>(d) > metric.size(0))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                                            metric.size(0), &hv_emlrtBCI, &st);
            }
            i2 = static_cast<int32_T>(d) - 1;
          }
          i3 = loc.size(1);
          if (1 > i3) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i3, &iv_emlrtBCI, &st);
          }
          i3 = loc.size(1);
          if (1 > i3) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i3, &jv_emlrtBCI, &st);
          }
          if (loc[id] - 2.0 > loc[id] + 2.0) {
            i3 = -1;
            i4 = -1;
          } else {
            d = loc[id] - 2.0;
            if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
              emlrtIntegerCheckR2012b(d, &pd_emlrtDCI, &st);
            }
            if ((static_cast<int32_T>(d) < 1) ||
                (static_cast<int32_T>(d) > metric.size(1))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                                            metric.size(1), &kv_emlrtBCI, &st);
            }
            i3 = static_cast<int32_T>(d) - 2;
            d = loc[id] + 2.0;
            if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
              emlrtIntegerCheckR2012b(d, &qd_emlrtDCI, &st);
            }
            if ((static_cast<int32_T>(d) < 1) ||
                (static_cast<int32_T>(d) > metric.size(1))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                                            metric.size(1), &lv_emlrtBCI, &st);
            }
            i4 = static_cast<int32_T>(d) - 1;
          }
          b_st.site = &qr_emlrtRSI;
          c_st.site = &qh_emlrtRSI;
          loop_ub = i2 - i1;
          b_loop_ub = i4 - i3;
          i2 = loop_ub * b_loop_ub;
          if (25 != i2) {
            if (i2 == 1) {
              emlrtErrorWithMessageIdR2018a(
                  &c_st, &y_emlrtRTEI,
                  "Coder:toolbox:mtimes_noDynamicScalarExpansion",
                  "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
            } else {
              emlrtErrorWithMessageIdR2018a(&c_st, &ab_emlrtRTEI,
                                            "MATLAB:innerdim",
                                            "MATLAB:innerdim", 0);
            }
          }
          b_metric.set_size(&ms_emlrtRTEI, &b_st, loop_ub, b_loop_ub);
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
          b_st.site = &rr_emlrtRSI;
          y = 4.0F * beta[0] * beta[1] - beta[4] * beta[4];
          x = -(2.0F * beta[1] * beta[2] - beta[3] * beta[4]) / y;
          b_st.site = &sr_emlrtRSI;
          y = -(2.0F * beta[0] * beta[3] - beta[2] * beta[4]) / y;
          if (muSingleScalarIsInf(x) || muSingleScalarIsNaN(x) ||
              (muSingleScalarAbs(x) > 2.0F) ||
              (muSingleScalarIsInf(y) || muSingleScalarIsNaN(y)) ||
              (muSingleScalarAbs(y) > 2.0F)) {
            x = 0.0F;
            y = 0.0F;
          }
          loop_ub = loc.size(1);
          loc_size[0] = 1;
          loc_size[1] = loop_ub;
          iv[0] = 1;
          iv[1] = 2;
          emlrtSizeEqCheckNDR2012b(&loc_size[0], &iv[0], &ce_emlrtECI, &st);
          loop_ub = 2;
          subPixelLoc_data[0] = static_cast<real32_T>(loc[id]) + x;
          subPixelLoc_data[1] =
              static_cast<real32_T>(loc[id + loc.size(0)]) + y;
        }
      }
    }
    if (guard1) {
      loop_ub = loc.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        subPixelLoc_data[i1] =
            static_cast<real32_T>(loc[id + loc.size(0) * i1]);
      }
    }
    loc_size[0] = 1;
    loc_size[1] = loop_ub;
    for (i1 = 0; i1 < loop_ub; i1++) {
      c_loc_data[i1] = subPixelLoc_data[i1];
    }
    iv[0] = 1;
    iv[1] = loc.size(1);
    emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &loc_size[0], 2, &be_emlrtECI,
                                  (emlrtCTX)sp);
    for (i1 = 0; i1 < loop_ub; i1++) {
      loc[id + loc.size(0) * i1] = c_loc_data[i1];
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

} // namespace Codegen

// End of code generation (subPixelLocation.cpp)
