//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// serializeCalib.cpp
//
// Code generation for function 'serializeCalib'
//

// Include files
#include "serializeCalib.h"
#include "calibrateOneCamera_mex_data.h"
#include "calibrateOneCamera_mex_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rodriguesMatrixToVector.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo wx_emlrtRSI{
    19,               // lineNo
    "serializeCalib", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\serializeCalib.m" // pathName
};

static emlrtRSInfo xx_emlrtRSI{
    27,               // lineNo
    "serializeCalib", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\serializeCalib.m" // pathName
};

static emlrtRSInfo yx_emlrtRSI{
    30,               // lineNo
    "serializeCalib", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\serializeCalib.m" // pathName
};

static emlrtRSInfo ay_emlrtRSI{
    39,               // lineNo
    "serializeCalib", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\serializeCalib.m" // pathName
};

static emlrtRSInfo by_emlrtRSI{
    43,               // lineNo
    "serializeCalib", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\serializeCalib.m" // pathName
};

static emlrtRSInfo
    cy_emlrtRSI{
        100,   // lineNo
        "cat", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" // pathName
    };

static emlrtRSInfo
    dy_emlrtRSI{
        132,      // lineNo
        "looper", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" // pathName
    };

static emlrtRSInfo
    ey_emlrtRSI{
        117,      // lineNo
        "looper", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" // pathName
    };

static emlrtRSInfo
    fy_emlrtRSI{
        41,                       // lineNo
        "rotationMatrixToVector", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\rotationMatrixToVector"
        ".m" // pathName
    };

static emlrtDCInfo ld_emlrtDCI{
    23,               // lineNo
    42,               // colNo
    "serializeCalib", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\serializeCalib.m", // pName
    1                                    // checkKind
};

static emlrtBCInfo ht_emlrtBCI{
    1,                               // iFirst
    3,                               // iLast
    23,                              // lineNo
    42,                              // colNo
    "cameraParams.RadialDistortion", // aName
    "serializeCalib",                // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\serializeCalib.m", // pName
    0                                    // checkKind
};

static emlrtBCInfo it_emlrtBCI{
    -1,               // iFirst
    -1,               // iLast
    39,               // lineNo
    46,               // colNo
    "RTpnc1",         // aName
    "serializeCalib", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\serializeCalib.m", // pName
    0                                    // checkKind
};

static emlrtBCInfo jt_emlrtBCI{
    -1,               // iFirst
    -1,               // iLast
    41,               // lineNo
    23,               // colNo
    "RTpnc1",         // aName
    "serializeCalib", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\serializeCalib.m", // pName
    0                                    // checkKind
};

static emlrtBCInfo kt_emlrtBCI{
    -1,               // iFirst
    -1,               // iLast
    43,               // lineNo
    31,               // colNo
    "RTpnc1",         // aName
    "serializeCalib", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\serializeCalib.m", // pName
    0                                    // checkKind
};

static emlrtRTEInfo lq_emlrtRTEI{
    14,               // lineNo
    9,                // colNo
    "serializeCalib", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\serializeCalib.m" // pName
};

static emlrtRTEInfo mq_emlrtRTEI{
    19,               // lineNo
    9,                // colNo
    "serializeCalib", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\serializeCalib.m" // pName
};

static emlrtRTEInfo
    nq_emlrtRTEI{
        100,   // lineNo
        14,    // colNo
        "cat", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" // pName
    };

static emlrtRTEInfo oq_emlrtRTEI{
    27,               // lineNo
    9,                // colNo
    "serializeCalib", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\serializeCalib.m" // pName
};

static emlrtRTEInfo pq_emlrtRTEI{
    25,               // lineNo
    9,                // colNo
    "serializeCalib", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\serializeCalib.m" // pName
};

static emlrtRTEInfo qq_emlrtRTEI{
    30,               // lineNo
    9,                // colNo
    "serializeCalib", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\serializeCalib.m" // pName
};

static emlrtRTEInfo rq_emlrtRTEI{
    43,               // lineNo
    19,               // colNo
    "serializeCalib", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\serializeCalib.m" // pName
};

static emlrtRTEInfo sq_emlrtRTEI{
    41,               // lineNo
    9,                // colNo
    "serializeCalib", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\serializeCalib.m" // pName
};

// Function Definitions
namespace Codegen {
void serializeCalib(
    const emlrtStack *sp, const real_T c_calibration_CameraParameters_[3],
    const real_T d_calibration_CameraParameters_[2],
    boolean_T e_calibration_CameraParameters_,
    real_T f_calibration_CameraParameters_,
    boolean_T g_calibration_CameraParameters_,
    const real_T h_calibration_CameraParameters_[9],
    const ::coder::array<cell_wrap_0, 2U> &calibration_PatternPositions,
    ::coder::array<real_T, 1U> &x)
{
  ::coder::array<real_T, 1U> b_f1;
  ::coder::array<real_T, 1U> f1;
  ::coder::array<real_T, 1U> varargin_1;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T b_y_data[10];
  real_T b_calibration_PatternPositions[9];
  real_T c_y_data[8];
  real_T t8_f2[6];
  real_T y_data[5];
  real_T b_dv[3];
  int32_T b_loop_ub;
  int32_T i;
  int32_T j;
  int32_T loop_ub;
  int32_T y_size;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 3, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 3, 0);
  //  Changed for just 1 camera - 1/10/2021
  // RTcnc1 = calibration.Extrinsics;
  //  options (fixedK, fixedDistortions, fixedRTpnc1, fixedRTcnc1)
  //  x = [fx; fy; cx; cy; skew; radial; tangential; rvecs; tvecs];
  covrtLogCond(&emlrtCoverageInstance, 3, 0, 0, false);
  covrtLogMcdc(&emlrtCoverageInstance, 3, 0, 0, true);
  covrtLogIf(&emlrtCoverageInstance, 3, 0, 0, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 3, 1);
  covrtLogIf(&emlrtCoverageInstance, 3, 0, 1, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 3, 2);
  x.set_size(&lq_emlrtRTEI, sp, 4);
  x[0] = h_calibration_CameraParameters_[0];
  x[1] = h_calibration_CameraParameters_[4];
  x[2] = h_calibration_CameraParameters_[2];
  x[3] = h_calibration_CameraParameters_[5];
  if (covrtLogIf(&emlrtCoverageInstance, 3, 0, 2,
                 e_calibration_CameraParameters_)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 4);
    st.site = &wx_emlrtRSI;
    b_st.site = &cy_emlrtRSI;
    c_st.site = &dy_emlrtRSI;
    d_st.site = &ey_emlrtRSI;
    y_data[0] = x[0];
    y_data[1] = x[1];
    y_data[2] = x[2];
    y_data[3] = x[3];
    y_data[4] = h_calibration_CameraParameters_[3];
    x.set_size(&mq_emlrtRTEI, sp, 5);
    for (i = 0; i < 5; i++) {
      x[i] = y_data[i];
    }
  }
  covrtLogCond(&emlrtCoverageInstance, 3, 0, 1, false);
  covrtLogMcdc(&emlrtCoverageInstance, 3, 0, 1, true);
  covrtLogIf(&emlrtCoverageInstance, 3, 0, 3, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 3, 5);
  if (1.0 > f_calibration_CameraParameters_) {
    loop_ub = 0;
  } else {
    if (f_calibration_CameraParameters_ !=
        static_cast<int32_T>(
            muDoubleScalarFloor(f_calibration_CameraParameters_))) {
      emlrtIntegerCheckR2012b(f_calibration_CameraParameters_, &ld_emlrtDCI,
                              (emlrtCTX)sp);
    }
    if ((static_cast<int32_T>(f_calibration_CameraParameters_) < 1) ||
        (static_cast<int32_T>(f_calibration_CameraParameters_) > 3)) {
      emlrtDynamicBoundsCheckR2012b(
          static_cast<int32_T>(f_calibration_CameraParameters_), 1, 3,
          &ht_emlrtBCI, (emlrtCTX)sp);
    }
    loop_ub = static_cast<int32_T>(f_calibration_CameraParameters_);
  }
  if (covrtLogIf(&emlrtCoverageInstance, 3, 0, 4, x.size(0) == 0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 6);
    x.set_size(&pq_emlrtRTEI, sp, loop_ub);
    for (i = 0; i < loop_ub; i++) {
      x[i] = c_calibration_CameraParameters_[i];
    }
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 7);
    st.site = &xx_emlrtRSI;
    y_size = static_cast<int8_T>(x.size(0) + loop_ub);
    f1.set_size(&nq_emlrtRTEI, &st, x.size(0));
    b_loop_ub = x.size(0);
    for (i = 0; i < b_loop_ub; i++) {
      f1[i] = x[i];
    }
    b_f1.set_size(&nq_emlrtRTEI, &st, loop_ub);
    for (i = 0; i < loop_ub; i++) {
      b_f1[i] = c_calibration_CameraParameters_[i];
    }
    b_st.site = &cy_emlrtRSI;
    c_st.site = &dy_emlrtRSI;
    loop_ub = f1.size(0);
    d_st.site = &ey_emlrtRSI;
    for (j = 0; j < loop_ub; j++) {
      c_y_data[j] = f1[j];
    }
    b_loop_ub = b_f1.size(0);
    d_st.site = &ey_emlrtRSI;
    for (j = 0; j < b_loop_ub; j++) {
      c_y_data[loop_ub + j] = b_f1[j];
    }
    x.set_size(&oq_emlrtRTEI, sp, y_size);
    for (i = 0; i < y_size; i++) {
      x[i] = c_y_data[i];
    }
  }
  if (covrtLogIf(&emlrtCoverageInstance, 3, 0, 5,
                 g_calibration_CameraParameters_)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 8);
    st.site = &yx_emlrtRSI;
    y_size = static_cast<int8_T>(x.size(0) + 2);
    b_st.site = &cy_emlrtRSI;
    c_st.site = &dy_emlrtRSI;
    loop_ub = x.size(0);
    d_st.site = &ey_emlrtRSI;
    for (j = 0; j < loop_ub; j++) {
      b_y_data[j] = x[j];
    }
    b_y_data[x.size(0)] = d_calibration_CameraParameters_[0];
    b_y_data[x.size(0) + 1] = d_calibration_CameraParameters_[1];
    x.set_size(&qq_emlrtRTEI, sp, y_size);
    for (i = 0; i < y_size; i++) {
      x[i] = b_y_data[i];
    }
  }
  //  Extrinsics
  //  x = [fx; fy; cx; cy; skew; radial; tangential; rvecs; tvecs; A; B; C; Tx;
  //  Ty; Tz];
  covrtLogCond(&emlrtCoverageInstance, 3, 0, 2, false);
  covrtLogMcdc(&emlrtCoverageInstance, 3, 0, 2, true);
  covrtLogIf(&emlrtCoverageInstance, 3, 0, 6, true);
  i = calibration_PatternPositions.size(1);
  for (y_size = 0; y_size < i; y_size++) {
    covrtLogFor(&emlrtCoverageInstance, 3, 0, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 9);
    st.site = &ay_emlrtRSI;
    if (y_size > calibration_PatternPositions.size(1) - 1) {
      emlrtDynamicBoundsCheckR2012b(y_size, 0,
                                    calibration_PatternPositions.size(1) - 1,
                                    &it_emlrtBCI, &st);
    }
    for (b_loop_ub = 0; b_loop_ub < 3; b_loop_ub++) {
      b_calibration_PatternPositions[3 * b_loop_ub] =
          calibration_PatternPositions[y_size].f1[b_loop_ub];
      b_calibration_PatternPositions[3 * b_loop_ub + 1] =
          calibration_PatternPositions[y_size].f1[b_loop_ub + 4];
      b_calibration_PatternPositions[3 * b_loop_ub + 2] =
          calibration_PatternPositions[y_size].f1[b_loop_ub + 8];
    }
    b_st.site = &fy_emlrtRSI;
    coder::vision::internal::calibration::rodriguesMatrixToVector(
        &b_st, b_calibration_PatternPositions, b_dv);
    loop_ub = x.size(0);
    if (covrtLogIf(&emlrtCoverageInstance, 3, 0, 7, x.size(0) == 0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 3, 10);
      t8_f2[0] = b_dv[0];
      t8_f2[1] = b_dv[1];
      t8_f2[2] = b_dv[2];
      if (y_size > calibration_PatternPositions.size(1) - 1) {
        emlrtDynamicBoundsCheckR2012b(y_size, 0,
                                      calibration_PatternPositions.size(1) - 1,
                                      &jt_emlrtBCI, (emlrtCTX)sp);
      }
      t8_f2[3] = calibration_PatternPositions[y_size].f1[3];
      if (y_size > calibration_PatternPositions.size(1) - 1) {
        emlrtDynamicBoundsCheckR2012b(y_size, 0,
                                      calibration_PatternPositions.size(1) - 1,
                                      &jt_emlrtBCI, (emlrtCTX)sp);
      }
      t8_f2[4] = calibration_PatternPositions[y_size].f1[7];
      if (y_size > calibration_PatternPositions.size(1) - 1) {
        emlrtDynamicBoundsCheckR2012b(y_size, 0,
                                      calibration_PatternPositions.size(1) - 1,
                                      &jt_emlrtBCI, (emlrtCTX)sp);
      }
      t8_f2[5] = calibration_PatternPositions[y_size].f1[11];
      x.set_size(&sq_emlrtRTEI, sp, 6);
      for (b_loop_ub = 0; b_loop_ub < 6; b_loop_ub++) {
        x[b_loop_ub] = t8_f2[b_loop_ub];
      }
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 3, 11);
      st.site = &by_emlrtRSI;
      varargin_1.set_size(&rq_emlrtRTEI, &st, x.size(0));
      for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
        varargin_1[b_loop_ub] = x[b_loop_ub];
      }
      t8_f2[0] = b_dv[0];
      t8_f2[1] = b_dv[1];
      t8_f2[2] = b_dv[2];
      if (y_size > calibration_PatternPositions.size(1) - 1) {
        emlrtDynamicBoundsCheckR2012b(y_size, 0,
                                      calibration_PatternPositions.size(1) - 1,
                                      &kt_emlrtBCI, &st);
      }
      t8_f2[3] = calibration_PatternPositions[y_size].f1[3];
      if (y_size > calibration_PatternPositions.size(1) - 1) {
        emlrtDynamicBoundsCheckR2012b(y_size, 0,
                                      calibration_PatternPositions.size(1) - 1,
                                      &kt_emlrtBCI, &st);
      }
      t8_f2[4] = calibration_PatternPositions[y_size].f1[7];
      if (y_size > calibration_PatternPositions.size(1) - 1) {
        emlrtDynamicBoundsCheckR2012b(y_size, 0,
                                      calibration_PatternPositions.size(1) - 1,
                                      &kt_emlrtBCI, &st);
      }
      t8_f2[5] = calibration_PatternPositions[y_size].f1[11];
      b_loop_ub = x.size(0) + 6;
      x.set_size(&qo_emlrtRTEI, &st, b_loop_ub);
      b_st.site = &cy_emlrtRSI;
      c_st.site = &dy_emlrtRSI;
      loop_ub = varargin_1.size(0);
      d_st.site = &ey_emlrtRSI;
      if (varargin_1.size(0) > 2147483646) {
        e_st.site = &hc_emlrtRSI;
        coder::check_forloop_overflow_error(&e_st);
      }
      for (j = 0; j < loop_ub; j++) {
        x[j] = varargin_1[j];
      }
      for (j = 0; j < 6; j++) {
        x[loop_ub + j] = t8_f2[j];
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 3, 0, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 3, 12);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace Codegen

// End of code generation (serializeCalib.cpp)
