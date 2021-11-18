//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// unserializeCalib.cpp
//
// Code generation for function 'unserializeCalib'
//

// Include files
#include "unserializeCalib.h"
#include "calibrateOneCamera_mex_data.h"
#include "calibrateOneCamera_mex_internal_types.h"
#include "calibrateOneCamera_mex_types.h"
#include "cameraParameters.h"
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo xy_emlrtRSI{
    22,                 // lineNo
    "unserializeCalib", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\unserializeCalib.m" // pathName
};

static emlrtRSInfo yy_emlrtRSI{
    36,                 // lineNo
    "unserializeCalib", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\unserializeCalib.m" // pathName
};

static emlrtRSInfo aab_emlrtRSI{
    37,                 // lineNo
    "unserializeCalib", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\unserializeCalib.m" // pathName
};

static emlrtRSInfo bab_emlrtRSI{
    38,                 // lineNo
    "unserializeCalib", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\unserializeCalib.m" // pathName
};

static emlrtBCInfo st_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    17,                 // lineNo
    35,                 // colNo
    "x",                // aName
    "unserializeCalib", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\unserializeCalib.m", // pName
    0                                      // checkKind
};

static emlrtBCInfo tt_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    17,                 // lineNo
    51,                 // colNo
    "x",                // aName
    "unserializeCalib", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\unserializeCalib.m", // pName
    0                                      // checkKind
};

static emlrtBCInfo ut_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    17,                 // lineNo
    67,                 // colNo
    "x",                // aName
    "unserializeCalib", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\unserializeCalib.m", // pName
    0                                      // checkKind
};

static emlrtBCInfo vt_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    38,                 // lineNo
    17,                 // colNo
    "RTpnc1",           // aName
    "unserializeCalib", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\unserializeCalib.m", // pName
    0                                      // checkKind
};

static emlrtBCInfo wt_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    6,               // lineNo
    5,               // colNo
    "RTpnc1",        // aName
    "RTtoTransform", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\RTtoTransform.m", // pName
    0                                   // checkKind
};

static emlrtBCInfo xt_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    5,               // lineNo
    5,               // colNo
    "RTpnc1",        // aName
    "RTtoTransform", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\RTtoTransform.m", // pName
    0                                   // checkKind
};

static emlrtBCInfo yt_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    4,               // lineNo
    5,               // colNo
    "RTpnc1",        // aName
    "RTtoTransform", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\RTtoTransform.m", // pName
    0                                   // checkKind
};

static emlrtBCInfo au_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    37,                 // lineNo
    23,                 // colNo
    "x",                // aName
    "unserializeCalib", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\unserializeCalib.m", // pName
    0                                      // checkKind
};

static emlrtBCInfo bu_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    36,                 // lineNo
    36,                 // colNo
    "x",                // aName
    "unserializeCalib", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\unserializeCalib.m", // pName
    0                                      // checkKind
};

static emlrtRTEInfo br_emlrtRTEI{
    7,                  // lineNo
    9,                  // colNo
    "unserializeCalib", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\unserializeCalib.m" // pName
};

// Function Definitions
namespace Codegen {
void unserializeCalib(
    const emlrtStack *sp, const ::coder::array<real_T, 1U> &x,
    const real_T c_refCalibration_CameraParamete[2],
    const ::coder::array<cell_wrap_0, 2U> &refCalibration_PatternPositions,
    c_struct_T *CameraParameters,
    ::coder::array<cell_wrap_0, 2U> &PatternPositions)
{
  coder::cameraParameters lobj_0;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T K[9];
  real_T b_rotationVector[9];
  real_T rotationVector[3];
  real_T b_dv[2];
  real_T camLength;
  int32_T b_x;
  int32_T c_x;
  int32_T i;
  int32_T loop_ub;
  int8_T a[9];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  covrtLogFcn(&emlrtCoverageInstance, 5, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 5, 0);
  //  Start with original values. Overwrite if changed.
  // newCalibration=refCalibration;
  // RTcnc1 = refCalibration.Extrinsics;
  PatternPositions.set_size(&br_emlrtRTEI, sp, 1,
                            refCalibration_PatternPositions.size(1));
  loop_ub = refCalibration_PatternPositions.size(1);
  for (i = 0; i < loop_ub; i++) {
    PatternPositions[i] = refCalibration_PatternPositions[i];
  }
  // options (fixedK, fixedDistortions, fixedRTpnc1, fixedRTcnc1)
  covrtLogCond(&emlrtCoverageInstance, 5, 0, 0, false);
  covrtLogMcdc(&emlrtCoverageInstance, 5, 0, 0, true);
  covrtLogIf(&emlrtCoverageInstance, 5, 0, 0, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 5, 1);
  K[0] = x[0];
  K[3] = 0.0;
  K[6] = 0.0;
  K[1] = 0.0;
  K[4] = x[1];
  K[7] = 0.0;
  K[2] = x[2];
  K[5] = x[3];
  K[8] = 1.0;
  covrtLogCond(&emlrtCoverageInstance, 5, 0, 1, false);
  covrtLogMcdc(&emlrtCoverageInstance, 5, 0, 1, true);
  covrtLogIf(&emlrtCoverageInstance, 5, 0, 1, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 5, 3);
  if (5 > x.size(0)) {
    emlrtDynamicBoundsCheckR2012b(5, 1, x.size(0), &st_emlrtBCI, (emlrtCTX)sp);
  }
  if (6 > x.size(0)) {
    emlrtDynamicBoundsCheckR2012b(6, 1, x.size(0), &tt_emlrtBCI, (emlrtCTX)sp);
  }
  if (7 > x.size(0)) {
    emlrtDynamicBoundsCheckR2012b(7, 1, x.size(0), &ut_emlrtBCI, (emlrtCTX)sp);
  }
  camLength = 7.0;
  covrtLogBasicBlock(&emlrtCoverageInstance, 5, 5);
  st.site = &xy_emlrtRSI;
  b_st.site = &yw_emlrtRSI;
  c_st.site = &ww_emlrtRSI;
  b_st.site = &ax_emlrtRSI;
  c_st.site = &cx_emlrtRSI;
  coder::cameraParameters::checkIntrinsicMatrix(&c_st, K);
  for (i = 0; i < 3; i++) {
    lobj_0.IntrinsicMatrixInternal[3 * i] = K[i];
    lobj_0.IntrinsicMatrixInternal[3 * i + 1] = K[i + 3];
    lobj_0.IntrinsicMatrixInternal[3 * i + 2] = K[i + 6];
  }
  lobj_0.RadialDistortion[0] = x[4];
  lobj_0.RadialDistortion[1] = x[5];
  lobj_0.RadialDistortion[2] = x[6];
  c_st.site = &dx_emlrtRSI;
  coder::cameraParameters::checkRadialDistortion(&c_st,
                                                 lobj_0.RadialDistortion);
  lobj_0.TangentialDistortion[0] = 0.0;
  b_dv[0] = 0.0;
  lobj_0.TangentialDistortion[1] = 0.0;
  b_dv[1] = 0.0;
  c_st.site = &ex_emlrtRSI;
  coder::cameraParameters::checkTangentialDistortion(&c_st, b_dv);
  c_st.site = &fx_emlrtRSI;
  d_st.site = &nx_emlrtRSI;
  coder::b_cameraParameters::checkImageSize(&d_st,
                                            c_refCalibration_CameraParamete);
  lobj_0.ImageSize[0] = c_refCalibration_CameraParamete[0];
  lobj_0.ImageSize[1] = c_refCalibration_CameraParamete[1];
  c_st.site = &gx_emlrtRSI;
  coder::b_cameraParameters::checkImageSize(&c_st,
                                            c_refCalibration_CameraParamete);
  lobj_0.WorldUnits[0] = 'm';
  lobj_0.WorldUnits[1] = 'm';
  lobj_0.EstimateSkew = false;
  lobj_0.NumRadialDistortionCoefficients = 3.0;
  c_st.site = &jx_emlrtRSI;
  coder::cameraParameters::checkNumRadialCoeffs(&c_st, 3.0);
  lobj_0.EstimateTangentialDistortion = false;
  b_st.site = &bx_emlrtRSI;
  c_st.site = &sx_emlrtRSI;
  st.site = &xy_emlrtRSI;
  lobj_0.toStruct(CameraParameters->RadialDistortion,
                  CameraParameters->TangentialDistortion,
                  CameraParameters->ImageSize, CameraParameters->WorldUnits,
                  &CameraParameters->EstimateSkew,
                  &CameraParameters->NumRadialDistortionCoefficients,
                  &CameraParameters->EstimateTangentialDistortion,
                  CameraParameters->IntrinsicMatrix);
  //             %{
  //             newCalibration.CameraParameters.IntrinsicMatrix = K;
  //             newCalibration.CameraParameters.FocalLength = [K(1, 1) K(2,
  //             2)]; newCalibration.CameraParameters.PrincipalPoint = [K(3, 1)
  //             K(3, 2)]; newCalibration.CameraParameters.Skew = K(2, 1);
  //             newCalibration.CameraParameters.RadialDistortion =
  //             radialCoeffs;
  //             newCalibration.CameraParameters.NumRadialDistortionCoefficients
  //             = 3;
  //             %}
  covrtLogCond(&emlrtCoverageInstance, 5, 0, 2, false);
  covrtLogMcdc(&emlrtCoverageInstance, 5, 0, 2, true);
  covrtLogIf(&emlrtCoverageInstance, 5, 0, 2, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 5, 6);
  i = refCalibration_PatternPositions.size(1);
  if (0 <= refCalibration_PatternPositions.size(1) - 1) {
    b_x = x.size(0);
    c_x = x.size(0);
  }
  for (int32_T b_i{0}; b_i < i; b_i++) {
    real_T absxk;
    real_T scale;
    real_T t;
    real_T theta;
    int32_T i1;
    covrtLogFor(&emlrtCoverageInstance, 5, 0, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 5, 7);
    st.site = &yy_emlrtRSI;
    coder::internal::indexShapeCheck(&st, x.size(0));
    if ((static_cast<int32_T>(camLength + 1.0) < 1) ||
        (static_cast<int32_T>(camLength + 1.0) > b_x)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(camLength + 1.0), 1,
                                    b_x, &bu_emlrtBCI, (emlrtCTX)sp);
    }
    rotationVector[0] = x[static_cast<int32_T>(camLength + 1.0) - 1];
    if ((static_cast<int32_T>(camLength + 2.0) < 1) ||
        (static_cast<int32_T>(camLength + 2.0) > b_x)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(camLength + 2.0), 1,
                                    b_x, &bu_emlrtBCI, (emlrtCTX)sp);
    }
    rotationVector[1] = x[static_cast<int32_T>(camLength + 2.0) - 1];
    if ((static_cast<int32_T>(camLength + 3.0) < 1) ||
        (static_cast<int32_T>(camLength + 3.0) > b_x)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(camLength + 3.0), 1,
                                    b_x, &bu_emlrtBCI, (emlrtCTX)sp);
    }
    rotationVector[2] = x[static_cast<int32_T>(camLength + 3.0) - 1];
    st.site = &aab_emlrtRSI;
    coder::internal::indexShapeCheck(&st, x.size(0));
    if ((static_cast<int32_T>(camLength + 4.0) < 1) ||
        (static_cast<int32_T>(camLength + 4.0) > c_x)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(camLength + 4.0), 1,
                                    c_x, &au_emlrtBCI, (emlrtCTX)sp);
    }
    if ((static_cast<int32_T>(camLength + 5.0) < 1) ||
        (static_cast<int32_T>(camLength + 5.0) > c_x)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(camLength + 5.0), 1,
                                    c_x, &au_emlrtBCI, (emlrtCTX)sp);
    }
    if ((static_cast<int32_T>(camLength + 6.0) < 1) ||
        (static_cast<int32_T>(camLength + 6.0) > c_x)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(camLength + 6.0), 1,
                                    c_x, &au_emlrtBCI, (emlrtCTX)sp);
    }
    st.site = &bab_emlrtRSI;
    scale = 3.3121686421112381E-170;
    absxk = muDoubleScalarAbs(x[static_cast<int32_T>(camLength + 1.0) - 1]);
    if (absxk > 3.3121686421112381E-170) {
      theta = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      theta = t * t;
    }
    absxk = muDoubleScalarAbs(x[static_cast<int32_T>(camLength + 2.0) - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      theta = theta * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      theta += t * t;
    }
    absxk = muDoubleScalarAbs(x[static_cast<int32_T>(camLength + 3.0) - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      theta = theta * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      theta += t * t;
    }
    theta = scale * muDoubleScalarSqrt(theta);
    if (theta < 1.0E-6) {
      std::memset(&K[0], 0, 9U * sizeof(real_T));
      K[0] = 1.0;
      K[4] = 1.0;
      K[8] = 1.0;
    } else {
      rotationVector[0] /= theta;
      rotationVector[1] /= theta;
      rotationVector[2] /= theta;
      absxk = muDoubleScalarCos(theta);
      scale = muDoubleScalarSin(theta);
      for (i1 = 0; i1 < 9; i1++) {
        a[i1] = 0;
      }
      K[0] = scale * 0.0;
      K[3] = scale * -rotationVector[2];
      K[6] = scale * rotationVector[1];
      K[1] = scale * rotationVector[2];
      K[4] = scale * 0.0;
      K[7] = scale * -rotationVector[0];
      K[2] = scale * -rotationVector[1];
      K[5] = scale * rotationVector[0];
      K[8] = scale * 0.0;
      for (loop_ub = 0; loop_ub < 3; loop_ub++) {
        a[loop_ub + 3 * loop_ub] = 1;
        b_rotationVector[3 * loop_ub] =
            rotationVector[0] * rotationVector[loop_ub];
        b_rotationVector[3 * loop_ub + 1] =
            rotationVector[1] * rotationVector[loop_ub];
        b_rotationVector[3 * loop_ub + 2] =
            rotationVector[2] * rotationVector[loop_ub];
      }
      for (i1 = 0; i1 < 9; i1++) {
        K[i1] = (static_cast<real_T>(a[i1]) * absxk + K[i1]) +
                (1.0 - absxk) * b_rotationVector[i1];
      }
    }
    covrtLogFcn(&emlrtCoverageInstance, 2, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 0);
    //  Before applying transform all R's coming from outside Matlab
    loop_ub = PatternPositions.size(1) - 1;
    for (i1 = 0; i1 < 16; i1++) {
      if (b_i > loop_ub) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &vt_emlrtBCI, &st);
      }
      PatternPositions[b_i].f1[i1] = 0.0;
    }
    loop_ub = PatternPositions.size(1) - 1;
    for (i1 = 0; i1 < 3; i1++) {
      int32_T i2;
      if (b_i > loop_ub) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &yt_emlrtBCI, &st);
      }
      i2 = i1 << 2;
      PatternPositions[b_i].f1[i2] = K[i1];
      if (b_i > loop_ub) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &yt_emlrtBCI, &st);
      }
      PatternPositions[b_i].f1[i2 + 1] = K[i1 + 3];
      if (b_i > loop_ub) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &yt_emlrtBCI, &st);
      }
      PatternPositions[b_i].f1[i2 + 2] = K[i1 + 6];
    }
    loop_ub = PatternPositions.size(1) - 1;
    if (b_i > PatternPositions.size(1) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, PatternPositions.size(1) - 1,
                                    &xt_emlrtBCI, &st);
    }
    PatternPositions[b_i].f1[3] = x[static_cast<int32_T>(camLength + 4.0) - 1];
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &xt_emlrtBCI, &st);
    }
    PatternPositions[b_i].f1[7] = x[static_cast<int32_T>(camLength + 5.0) - 1];
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &xt_emlrtBCI, &st);
    }
    PatternPositions[b_i].f1[11] = x[static_cast<int32_T>(camLength + 6.0) - 1];
    loop_ub = PatternPositions.size(1) - 1;
    if (b_i > PatternPositions.size(1) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, PatternPositions.size(1) - 1,
                                    &wt_emlrtBCI, &st);
    }
    PatternPositions[b_i].f1[12] = 0.0;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &wt_emlrtBCI, &st);
    }
    PatternPositions[b_i].f1[13] = 0.0;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &wt_emlrtBCI, &st);
    }
    PatternPositions[b_i].f1[14] = 0.0;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &wt_emlrtBCI, &st);
    }
    PatternPositions[b_i].f1[15] = 1.0;
    camLength += 6.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 5, 0, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 5, 8);
  // numel(x);
  // newCalibration.Extrinsics = RTcnc1;
  // newCalibration.PatternPositions = RTpnc1;
}

} // namespace Codegen

// End of code generation (unserializeCalib.cpp)
