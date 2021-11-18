//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// readRobotPoses.cpp
//
// Code generation for function 'readRobotPoses'
//

// Include files
#include "readRobotPoses.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtBCInfo yw_emlrtBCI{
    -1,               // iFirst
    -1,               // iLast
    8,                // lineNo
    33,               // colNo
    "robotPosesVec",  // aName
    "readRobotPoses", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\readRobotPoses.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo ax_emlrtBCI{
    -1,               // iFirst
    -1,               // iLast
    8,                // lineNo
    12,               // colNo
    "poses",          // aName
    "readRobotPoses", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\readRobotPoses.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo bx_emlrtBCI{
    -1,               // iFirst
    -1,               // iLast
    9,                // lineNo
    54,               // colNo
    "poses",          // aName
    "readRobotPoses", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\readRobotPoses.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo cx_emlrtBCI{
    -1,               // iFirst
    -1,               // iLast
    9,                // lineNo
    17,               // colNo
    "extrinsics",     // aName
    "readRobotPoses", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\readRobotPoses.m", // pName
    0                                                   // checkKind
};

static emlrtRTEInfo mx_emlrtRTEI{
    3,                // lineNo
    1,                // colNo
    "readRobotPoses", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\readRobotPoses.m" // pName
};

static emlrtRTEInfo nx_emlrtRTEI{
    4,                // lineNo
    1,                // colNo
    "readRobotPoses", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\readRobotPoses.m" // pName
};

// Function Definitions
void readRobotPoses(const emlrtStack *sp,
                    const coder::array<real_T, 3U> &robotPosesVec,
                    coder::array<real_T, 3U> &poses,
                    coder::array<real_T, 3U> &extrinsics)
{
  real_T b_poses[9];
  real_T c_poses[3];
  int32_T i;
  int32_T loop_ub;
  covrtLogFcn(&emlrtCoverageInstance, 7, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 7, 0);
  //  Initialize arrays of poses and extrinsics
  poses.set_size(&mx_emlrtRTEI, sp, 4, 4, robotPosesVec.size(2));
  loop_ub = robotPosesVec.size(2) << 4;
  for (i = 0; i < loop_ub; i++) {
    poses[i] = 0.0;
  }
  extrinsics.set_size(&nx_emlrtRTEI, sp, 4, 4, robotPosesVec.size(2));
  loop_ub = robotPosesVec.size(2) << 4;
  for (i = 0; i < loop_ub; i++) {
    extrinsics[i] = 0.0;
  }
  // read valid poses and reshape them to 4x4xn matrix
  i = robotPosesVec.size(2);
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    int32_T i1;
    covrtLogFor(&emlrtCoverageInstance, 7, 0, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 7, 1);
    if (loop_ub + 1 > robotPosesVec.size(2)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, robotPosesVec.size(2),
                                    &yw_emlrtBCI, (emlrtCTX)sp);
    }
    if (loop_ub + 1 > poses.size(2)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, poses.size(2), &ax_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < 4; i1++) {
      poses[4 * i1 + 16 * loop_ub] = robotPosesVec[4 * i1 + 16 * loop_ub];
      poses[(4 * i1 + 16 * loop_ub) + 1] =
          robotPosesVec[(4 * i1 + 16 * loop_ub) + 1];
      poses[(4 * i1 + 16 * loop_ub) + 2] =
          robotPosesVec[(4 * i1 + 16 * loop_ub) + 2];
      poses[(4 * i1 + 16 * loop_ub) + 3] =
          robotPosesVec[(4 * i1 + 16 * loop_ub) + 3];
    }
    if (loop_ub + 1 > poses.size(2)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, poses.size(2), &bx_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < 3; i1++) {
      b_poses[3 * i1] = -poses[i1 + 16 * loop_ub];
      b_poses[3 * i1 + 1] = -poses[(i1 + 16 * loop_ub) + 4];
      b_poses[3 * i1 + 2] = -poses[(i1 + 16 * loop_ub) + 8];
    }
    for (i1 = 0; i1 < 3; i1++) {
      c_poses[i1] = (b_poses[i1] * poses[16 * loop_ub + 12] +
                     b_poses[i1 + 3] * poses[16 * loop_ub + 13]) +
                    b_poses[i1 + 6] * poses[16 * loop_ub + 14];
    }
    if (loop_ub + 1 > extrinsics.size(2)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, extrinsics.size(2),
                                    &cx_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < 3; i1++) {
      extrinsics[4 * i1 + 16 * loop_ub] = poses[i1 + 16 * loop_ub];
      extrinsics[(4 * i1 + 16 * loop_ub) + 1] = poses[(i1 + 16 * loop_ub) + 4];
      extrinsics[(4 * i1 + 16 * loop_ub) + 2] = poses[(i1 + 16 * loop_ub) + 8];
      extrinsics[(i1 + 16 * loop_ub) + 12] = c_poses[i1];
    }
    extrinsics[16 * loop_ub + 3] = 0.0;
    extrinsics[16 * loop_ub + 7] = 0.0;
    extrinsics[16 * loop_ub + 11] = 0.0;
    extrinsics[16 * loop_ub + 15] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 7, 0, 0, 0);
}

// End of code generation (readRobotPoses.cpp)
