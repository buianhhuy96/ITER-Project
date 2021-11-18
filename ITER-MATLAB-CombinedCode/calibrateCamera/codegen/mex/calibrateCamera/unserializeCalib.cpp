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
#include "calibrateCamera_data.h"
#include "calibrateCamera_types.h"
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo qx_emlrtRSI{
    33,                 // lineNo
    "unserializeCalib", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\unserializeCalib.m" // pathName
};

static emlrtRSInfo rx_emlrtRSI{
    34,                 // lineNo
    "unserializeCalib", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\unserializeCalib.m" // pathName
};

static emlrtRSInfo sx_emlrtRSI{
    35,                 // lineNo
    "unserializeCalib", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\unserializeCalib.m" // pathName
};

static emlrtBCInfo au_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    35,                 // lineNo
    17,                 // colNo
    "RTpnc1",           // aName
    "unserializeCalib", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\unserializeCalib.m", // pName
    0                                      // checkKind
};

static emlrtBCInfo bu_emlrtBCI{
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

static emlrtBCInfo cu_emlrtBCI{
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

static emlrtBCInfo du_emlrtBCI{
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

static emlrtBCInfo eu_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    34,                 // lineNo
    23,                 // colNo
    "x",                // aName
    "unserializeCalib", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\unserializeCalib.m", // pName
    0                                      // checkKind
};

static emlrtBCInfo fu_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    33,                 // lineNo
    36,                 // colNo
    "x",                // aName
    "unserializeCalib", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\unserializeCalib.m", // pName
    0                                      // checkKind
};

static emlrtRTEInfo ur_emlrtRTEI{
    5,                  // lineNo
    9,                  // colNo
    "unserializeCalib", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\unserializeCalib.m" // pName
};

static emlrtRTEInfo vr_emlrtRTEI{
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
    const struct1_T *refCalibration_CameraParameters,
    const ::coder::array<cell_wrap_0, 2U> &refCalibration_PatternPositions,
    const ::coder::array<real_T, 3U> &refCalibration_ImagePoints,
    struct1_T *newCalibration_CameraParameters,
    ::coder::array<cell_wrap_0, 2U> &newCalibration_PatternPositions,
    ::coder::array<real_T, 3U> &newCalibration_ImagePoints)
{
  emlrtStack st;
  real_T a[9];
  real_T b_rotationVector[9];
  real_T rotationVector[3];
  real_T camLength;
  int32_T b_x;
  int32_T c_x;
  int32_T i;
  int32_T loop_ub;
  int8_T b_a[9];
  st.prev = sp;
  st.tls = sp->tls;
  covrtLogFcn(&emlrtCoverageInstance, 7, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 7, 0);
  //  Start with original values. Overwrite if changed.
  *newCalibration_CameraParameters = *refCalibration_CameraParameters;
  newCalibration_ImagePoints.set_size(
      &ur_emlrtRTEI, sp, refCalibration_ImagePoints.size(0),
      refCalibration_ImagePoints.size(1), refCalibration_ImagePoints.size(2));
  loop_ub = refCalibration_ImagePoints.size(0) *
            refCalibration_ImagePoints.size(1) *
            refCalibration_ImagePoints.size(2);
  for (i = 0; i < loop_ub; i++) {
    newCalibration_ImagePoints[i] = refCalibration_ImagePoints[i];
  }
  // RTcnc1 = refCalibration.Extrinsics;
  newCalibration_PatternPositions.set_size(
      &vr_emlrtRTEI, sp, 1, refCalibration_PatternPositions.size(1));
  loop_ub = refCalibration_PatternPositions.size(1);
  for (i = 0; i < loop_ub; i++) {
    newCalibration_PatternPositions[i] = refCalibration_PatternPositions[i];
  }
  // options (fixedK, fixedDistortions, fixedRTpnc1, fixedRTcnc1)
  covrtLogCond(&emlrtCoverageInstance, 7, 0, 0, false);
  covrtLogMcdc(&emlrtCoverageInstance, 7, 0, 0, true);
  covrtLogIf(&emlrtCoverageInstance, 7, 0, 0, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 7, 1);
  newCalibration_CameraParameters->IntrinsicMatrix[0] = x[0];
  newCalibration_CameraParameters->IntrinsicMatrix[3] = 0.0;
  newCalibration_CameraParameters->IntrinsicMatrix[6] = 0.0;
  newCalibration_CameraParameters->IntrinsicMatrix[1] = 0.0;
  newCalibration_CameraParameters->IntrinsicMatrix[4] = x[1];
  newCalibration_CameraParameters->IntrinsicMatrix[7] = 0.0;
  newCalibration_CameraParameters->IntrinsicMatrix[2] = x[2];
  newCalibration_CameraParameters->IntrinsicMatrix[5] = x[3];
  newCalibration_CameraParameters->IntrinsicMatrix[8] = 1.0;
  covrtLogCond(&emlrtCoverageInstance, 7, 0, 1, false);
  covrtLogMcdc(&emlrtCoverageInstance, 7, 0, 1, true);
  covrtLogIf(&emlrtCoverageInstance, 7, 0, 1, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 7, 3);
  newCalibration_CameraParameters->RadialDistortion[0] = x[4];
  newCalibration_CameraParameters->RadialDistortion[1] = x[5];
  newCalibration_CameraParameters->RadialDistortion[2] = x[6];
  camLength = 7.0;
  covrtLogBasicBlock(&emlrtCoverageInstance, 7, 5);
  // newCalibration.CameraParameters = cameraParameters('IntrinsicMatrix', K,
  // ...
  //     'RadialDistortion', radialCoeffs,  'NumRadialDistortionCoefficients',
  //     3);
  newCalibration_CameraParameters->NumRadialDistortionCoefficients = 3.0;
  covrtLogCond(&emlrtCoverageInstance, 7, 0, 2, false);
  covrtLogMcdc(&emlrtCoverageInstance, 7, 0, 2, true);
  covrtLogIf(&emlrtCoverageInstance, 7, 0, 2, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 7, 6);
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
    covrtLogFor(&emlrtCoverageInstance, 7, 0, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 7, 7);
    st.site = &qx_emlrtRSI;
    coder::internal::indexShapeCheck(&st, x.size(0));
    if ((static_cast<int32_T>(camLength + 1.0) < 1) ||
        (static_cast<int32_T>(camLength + 1.0) > b_x)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(camLength + 1.0), 1,
                                    b_x, &fu_emlrtBCI, (emlrtCTX)sp);
    }
    rotationVector[0] = x[static_cast<int32_T>(camLength + 1.0) - 1];
    if ((static_cast<int32_T>(camLength + 2.0) < 1) ||
        (static_cast<int32_T>(camLength + 2.0) > b_x)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(camLength + 2.0), 1,
                                    b_x, &fu_emlrtBCI, (emlrtCTX)sp);
    }
    rotationVector[1] = x[static_cast<int32_T>(camLength + 2.0) - 1];
    if ((static_cast<int32_T>(camLength + 3.0) < 1) ||
        (static_cast<int32_T>(camLength + 3.0) > b_x)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(camLength + 3.0), 1,
                                    b_x, &fu_emlrtBCI, (emlrtCTX)sp);
    }
    rotationVector[2] = x[static_cast<int32_T>(camLength + 3.0) - 1];
    st.site = &rx_emlrtRSI;
    coder::internal::indexShapeCheck(&st, x.size(0));
    if ((static_cast<int32_T>(camLength + 4.0) < 1) ||
        (static_cast<int32_T>(camLength + 4.0) > c_x)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(camLength + 4.0), 1,
                                    c_x, &eu_emlrtBCI, (emlrtCTX)sp);
    }
    if ((static_cast<int32_T>(camLength + 5.0) < 1) ||
        (static_cast<int32_T>(camLength + 5.0) > c_x)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(camLength + 5.0), 1,
                                    c_x, &eu_emlrtBCI, (emlrtCTX)sp);
    }
    if ((static_cast<int32_T>(camLength + 6.0) < 1) ||
        (static_cast<int32_T>(camLength + 6.0) > c_x)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(camLength + 6.0), 1,
                                    c_x, &eu_emlrtBCI, (emlrtCTX)sp);
    }
    st.site = &sx_emlrtRSI;
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
      std::memset(&a[0], 0, 9U * sizeof(real_T));
      a[0] = 1.0;
      a[4] = 1.0;
      a[8] = 1.0;
    } else {
      rotationVector[0] /= theta;
      rotationVector[1] /= theta;
      rotationVector[2] /= theta;
      absxk = muDoubleScalarCos(theta);
      scale = muDoubleScalarSin(theta);
      for (i1 = 0; i1 < 9; i1++) {
        b_a[i1] = 0;
      }
      a[0] = scale * 0.0;
      a[3] = scale * -rotationVector[2];
      a[6] = scale * rotationVector[1];
      a[1] = scale * rotationVector[2];
      a[4] = scale * 0.0;
      a[7] = scale * -rotationVector[0];
      a[2] = scale * -rotationVector[1];
      a[5] = scale * rotationVector[0];
      a[8] = scale * 0.0;
      for (loop_ub = 0; loop_ub < 3; loop_ub++) {
        b_a[loop_ub + 3 * loop_ub] = 1;
        b_rotationVector[3 * loop_ub] =
            rotationVector[0] * rotationVector[loop_ub];
        b_rotationVector[3 * loop_ub + 1] =
            rotationVector[1] * rotationVector[loop_ub];
        b_rotationVector[3 * loop_ub + 2] =
            rotationVector[2] * rotationVector[loop_ub];
      }
      for (i1 = 0; i1 < 9; i1++) {
        a[i1] = (static_cast<real_T>(b_a[i1]) * absxk + a[i1]) +
                (1.0 - absxk) * b_rotationVector[i1];
      }
    }
    covrtLogFcn(&emlrtCoverageInstance, 4, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 4, 0);
    //  Before applying transform all R's coming from outside Matlab
    loop_ub = newCalibration_PatternPositions.size(1) - 1;
    for (i1 = 0; i1 < 16; i1++) {
      if (b_i > loop_ub) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &au_emlrtBCI, &st);
      }
      newCalibration_PatternPositions[b_i].f1[i1] = 0.0;
    }
    loop_ub = newCalibration_PatternPositions.size(1) - 1;
    for (i1 = 0; i1 < 3; i1++) {
      int32_T i2;
      if (b_i > loop_ub) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &du_emlrtBCI, &st);
      }
      i2 = i1 << 2;
      newCalibration_PatternPositions[b_i].f1[i2] = a[i1];
      if (b_i > loop_ub) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &du_emlrtBCI, &st);
      }
      newCalibration_PatternPositions[b_i].f1[i2 + 1] = a[i1 + 3];
      if (b_i > loop_ub) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &du_emlrtBCI, &st);
      }
      newCalibration_PatternPositions[b_i].f1[i2 + 2] = a[i1 + 6];
    }
    loop_ub = newCalibration_PatternPositions.size(1) - 1;
    if (b_i > newCalibration_PatternPositions.size(1) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0,
                                    newCalibration_PatternPositions.size(1) - 1,
                                    &cu_emlrtBCI, &st);
    }
    newCalibration_PatternPositions[b_i].f1[3] =
        x[static_cast<int32_T>(camLength + 4.0) - 1];
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &cu_emlrtBCI, &st);
    }
    newCalibration_PatternPositions[b_i].f1[7] =
        x[static_cast<int32_T>(camLength + 5.0) - 1];
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &cu_emlrtBCI, &st);
    }
    newCalibration_PatternPositions[b_i].f1[11] =
        x[static_cast<int32_T>(camLength + 6.0) - 1];
    loop_ub = newCalibration_PatternPositions.size(1) - 1;
    if (b_i > newCalibration_PatternPositions.size(1) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0,
                                    newCalibration_PatternPositions.size(1) - 1,
                                    &bu_emlrtBCI, &st);
    }
    newCalibration_PatternPositions[b_i].f1[12] = 0.0;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &bu_emlrtBCI, &st);
    }
    newCalibration_PatternPositions[b_i].f1[13] = 0.0;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &bu_emlrtBCI, &st);
    }
    newCalibration_PatternPositions[b_i].f1[14] = 0.0;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &bu_emlrtBCI, &st);
    }
    newCalibration_PatternPositions[b_i].f1[15] = 1.0;
    camLength += 6.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 7, 0, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 7, 8);
  // numel(x);
  // newCalibration.Extrinsics = RTcnc1;
}

} // namespace Codegen

// End of code generation (unserializeCalib.cpp)
