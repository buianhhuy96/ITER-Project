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
#include "calibrateCamera_data.h"
#include "calibrateCamera_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rodriguesMatrixToVector.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo ex_emlrtRSI{
    43,               // lineNo
    "serializeCalib", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\serializeCalib.m" // pathName
};

static emlrtRSInfo fx_emlrtRSI{
    39,               // lineNo
    "serializeCalib", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\serializeCalib.m" // pathName
};

static emlrtRSInfo gx_emlrtRSI{
    30,               // lineNo
    "serializeCalib", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\serializeCalib.m" // pathName
};

static emlrtRSInfo hx_emlrtRSI{
    27,               // lineNo
    "serializeCalib", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\serializeCalib.m" // pathName
};

static emlrtRSInfo ix_emlrtRSI{
    19,               // lineNo
    "serializeCalib", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\serializeCalib.m" // pathName
};

static emlrtRSInfo
    jx_emlrtRSI{
        100,   // lineNo
        "cat", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" // pathName
    };

static emlrtRSInfo
    kx_emlrtRSI{
        132,      // lineNo
        "looper", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" // pathName
    };

static emlrtRSInfo
    lx_emlrtRSI{
        117,      // lineNo
        "looper", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" // pathName
    };

static emlrtRSInfo
    mx_emlrtRSI{
        41,                       // lineNo
        "rotationMatrixToVector", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\rotationMatrixToVector"
        ".m" // pathName
    };

static emlrtBCInfo nt_emlrtBCI{
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

static emlrtBCInfo ot_emlrtBCI{
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

static emlrtBCInfo pt_emlrtBCI{
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
    boolean_T d_calibration_CameraParameters_,
    boolean_T e_calibration_CameraParameters_,
    const real_T f_calibration_CameraParameters_[9],
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
  real_T b_calibration_PatternPositions[9];
  real_T b_y_data[7];
  real_T t8_f2[6];
  real_T b_dv[3];
  real_T y_data;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 5, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 5, 0);
  //  Changed for just 1 camera - 1/10/2021
  // RTcnc1 = calibration.Extrinsics;
  //  options (fixedK, fixedDistortions, fixedRTpnc1, fixedRTcnc1)
  //  x = [fx; fy; cx; cy; skew; radial; tangential; rvecs; tvecs];
  covrtLogCond(&emlrtCoverageInstance, 5, 0, 0, false);
  covrtLogMcdc(&emlrtCoverageInstance, 5, 0, 0, true);
  covrtLogIf(&emlrtCoverageInstance, 5, 0, 0, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 5, 1);
  covrtLogIf(&emlrtCoverageInstance, 5, 0, 1, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 5, 2);
  x.set_size(&lq_emlrtRTEI, sp, 4);
  x[0] = f_calibration_CameraParameters_[0];
  x[1] = f_calibration_CameraParameters_[4];
  x[2] = f_calibration_CameraParameters_[2];
  x[3] = f_calibration_CameraParameters_[5];
  if (covrtLogIf(&emlrtCoverageInstance, 5, 0, 2,
                 d_calibration_CameraParameters_)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 5, 4);
    st.site = &ix_emlrtRSI;
    b_st.site = &jx_emlrtRSI;
    c_st.site = &kx_emlrtRSI;
    d_st.site = &lx_emlrtRSI;
    y_data = f_calibration_CameraParameters_[3];
    x.set_size(&mq_emlrtRTEI, sp, 5);
    for (i = 0; i < 5; i++) {
      x[i] = y_data;
    }
  }
  covrtLogCond(&emlrtCoverageInstance, 5, 0, 1, false);
  covrtLogMcdc(&emlrtCoverageInstance, 5, 0, 1, true);
  covrtLogIf(&emlrtCoverageInstance, 5, 0, 3, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 5, 5);
  if (covrtLogIf(&emlrtCoverageInstance, 5, 0, 4, x.size(0) == 0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 5, 6);
    x.set_size(&pq_emlrtRTEI, sp, 3);
    x[0] = c_calibration_CameraParameters_[0];
    x[1] = c_calibration_CameraParameters_[1];
    x[2] = c_calibration_CameraParameters_[2];
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 5, 7);
    st.site = &hx_emlrtRSI;
    f1.set_size(&nq_emlrtRTEI, &st, x.size(0));
    loop_ub = x.size(0);
    for (i = 0; i < loop_ub; i++) {
      f1[i] = x[i];
    }
    b_f1.set_size(&nq_emlrtRTEI, &st, 3);
    b_f1[0] = c_calibration_CameraParameters_[0];
    b_f1[1] = c_calibration_CameraParameters_[1];
    b_f1[2] = c_calibration_CameraParameters_[2];
    b_st.site = &jx_emlrtRSI;
    c_st.site = &kx_emlrtRSI;
    d_st.site = &lx_emlrtRSI;
    b_y_data[0] = f1[0];
    b_y_data[1] = f1[1];
    b_y_data[2] = f1[2];
    b_y_data[3] = f1[3];
    d_st.site = &lx_emlrtRSI;
    b_y_data[4] = b_f1[0];
    b_y_data[5] = b_f1[1];
    b_y_data[6] = b_f1[2];
    x.set_size(&oq_emlrtRTEI, sp, 7);
    for (i = 0; i < 7; i++) {
      x[i] = b_y_data[i];
    }
  }
  if (covrtLogIf(&emlrtCoverageInstance, 5, 0, 5,
                 e_calibration_CameraParameters_)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 5, 8);
    st.site = &gx_emlrtRSI;
    b_st.site = &jx_emlrtRSI;
    c_st.site = &kx_emlrtRSI;
    d_st.site = &lx_emlrtRSI;
    x.set_size(&qq_emlrtRTEI, sp, 9);
    for (i = 0; i < 9; i++) {
      x[i] = y_data;
    }
  }
  //  Extrinsics
  //  x = [fx; fy; cx; cy; skew; radial; tangential; rvecs; tvecs; A; B; C; Tx;
  //  Ty; Tz];
  covrtLogCond(&emlrtCoverageInstance, 5, 0, 2, false);
  covrtLogMcdc(&emlrtCoverageInstance, 5, 0, 2, true);
  covrtLogIf(&emlrtCoverageInstance, 5, 0, 6, true);
  i = calibration_PatternPositions.size(1);
  for (int32_T b_i{0}; b_i < i; b_i++) {
    int32_T j;
    covrtLogFor(&emlrtCoverageInstance, 5, 0, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 5, 9);
    st.site = &fx_emlrtRSI;
    if (b_i > calibration_PatternPositions.size(1) - 1) {
      emlrtDynamicBoundsCheckR2012b(
          b_i, 0, calibration_PatternPositions.size(1) - 1, &nt_emlrtBCI, &st);
    }
    for (j = 0; j < 3; j++) {
      b_calibration_PatternPositions[3 * j] =
          calibration_PatternPositions[b_i].f1[j];
      b_calibration_PatternPositions[3 * j + 1] =
          calibration_PatternPositions[b_i].f1[j + 4];
      b_calibration_PatternPositions[3 * j + 2] =
          calibration_PatternPositions[b_i].f1[j + 8];
    }
    b_st.site = &mx_emlrtRSI;
    coder::vision::internal::calibration::rodriguesMatrixToVector(
        &b_st, b_calibration_PatternPositions, b_dv);
    loop_ub = x.size(0);
    if (covrtLogIf(&emlrtCoverageInstance, 5, 0, 7, x.size(0) == 0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 5, 10);
      t8_f2[0] = b_dv[0];
      t8_f2[1] = b_dv[1];
      t8_f2[2] = b_dv[2];
      if (b_i > calibration_PatternPositions.size(1) - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0,
                                      calibration_PatternPositions.size(1) - 1,
                                      &ot_emlrtBCI, (emlrtCTX)sp);
      }
      t8_f2[3] = calibration_PatternPositions[b_i].f1[3];
      if (b_i > calibration_PatternPositions.size(1) - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0,
                                      calibration_PatternPositions.size(1) - 1,
                                      &ot_emlrtBCI, (emlrtCTX)sp);
      }
      t8_f2[4] = calibration_PatternPositions[b_i].f1[7];
      if (b_i > calibration_PatternPositions.size(1) - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0,
                                      calibration_PatternPositions.size(1) - 1,
                                      &ot_emlrtBCI, (emlrtCTX)sp);
      }
      t8_f2[5] = calibration_PatternPositions[b_i].f1[11];
      x.set_size(&sq_emlrtRTEI, sp, 6);
      for (j = 0; j < 6; j++) {
        x[j] = t8_f2[j];
      }
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 5, 11);
      st.site = &ex_emlrtRSI;
      varargin_1.set_size(&rq_emlrtRTEI, &st, x.size(0));
      for (j = 0; j < loop_ub; j++) {
        varargin_1[j] = x[j];
      }
      t8_f2[0] = b_dv[0];
      t8_f2[1] = b_dv[1];
      t8_f2[2] = b_dv[2];
      if (b_i > calibration_PatternPositions.size(1) - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0,
                                      calibration_PatternPositions.size(1) - 1,
                                      &pt_emlrtBCI, &st);
      }
      t8_f2[3] = calibration_PatternPositions[b_i].f1[3];
      if (b_i > calibration_PatternPositions.size(1) - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0,
                                      calibration_PatternPositions.size(1) - 1,
                                      &pt_emlrtBCI, &st);
      }
      t8_f2[4] = calibration_PatternPositions[b_i].f1[7];
      if (b_i > calibration_PatternPositions.size(1) - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0,
                                      calibration_PatternPositions.size(1) - 1,
                                      &pt_emlrtBCI, &st);
      }
      t8_f2[5] = calibration_PatternPositions[b_i].f1[11];
      j = x.size(0) + 6;
      x.set_size(&uo_emlrtRTEI, &st, j);
      b_st.site = &jx_emlrtRSI;
      c_st.site = &kx_emlrtRSI;
      loop_ub = varargin_1.size(0);
      d_st.site = &lx_emlrtRSI;
      if (varargin_1.size(0) > 2147483646) {
        e_st.site = &qc_emlrtRSI;
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
  covrtLogFor(&emlrtCoverageInstance, 5, 0, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 5, 12);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace Codegen

// End of code generation (serializeCalib.cpp)
