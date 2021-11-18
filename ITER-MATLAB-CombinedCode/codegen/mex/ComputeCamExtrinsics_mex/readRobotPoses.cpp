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
#include "ComputeCamExtrinsics_mex_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtBCInfo uu_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    8,                 // lineNo
    35,                // colNo
    "robot_poses_vec", // aName
    "readRobotPoses",  // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\readRobotPoses.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo vu_emlrtBCI{
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

static emlrtBCInfo wu_emlrtBCI{
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

static emlrtBCInfo xu_emlrtBCI{
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

static emlrtBCInfo yu_emlrtBCI{
    -1,               // iFirst
    -1,               // iLast
    14,               // lineNo
    27,               // colNo
    "extrinsics",     // aName
    "readRobotPoses", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\readRobotPoses.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo av_emlrtBCI{
    -1,               // iFirst
    -1,               // iLast
    13,               // lineNo
    17,               // colNo
    "poses",          // aName
    "readRobotPoses", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\readRobotPoses.m", // pName
    0                                                   // checkKind
};

static emlrtRTEInfo bu_emlrtRTEI{
    3,                // lineNo
    1,                // colNo
    "readRobotPoses", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\readRobotPoses.m" // pName
};

static emlrtRTEInfo cu_emlrtRTEI{
    4,                // lineNo
    1,                // colNo
    "readRobotPoses", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\readRobotPoses.m" // pName
};

static emlrtRTEInfo du_emlrtRTEI{
    1,                // lineNo
    30,               // colNo
    "readRobotPoses", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\readRobotPoses.m" // pName
};

static emlrtRTEInfo eu_emlrtRTEI{
    13,               // lineNo
    7,                // colNo
    "readRobotPoses", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\readRobotPoses.m" // pName
};

static emlrtRTEInfo fu_emlrtRTEI{
    13,               // lineNo
    1,                // colNo
    "readRobotPoses", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\readRobotPoses.m" // pName
};

static emlrtRTEInfo gu_emlrtRTEI{
    14,               // lineNo
    12,               // colNo
    "readRobotPoses", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\readRobotPoses.m" // pName
};

static emlrtRTEInfo hu_emlrtRTEI{
    14,               // lineNo
    1,                // colNo
    "readRobotPoses", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateHandeye\\readRobotPoses.m" // pName
};

// Function Definitions
void readRobotPoses(const emlrtStack *sp,
                    const coder::array<real_T, 3U> &robot_poses_vec,
                    const coder::array<boolean_T, 1U> &valid_idx,
                    coder::array<real_T, 3U> &poses,
                    coder::array<real_T, 3U> &extrinsics)
{
  coder::array<real_T, 3U> b_poses;
  coder::array<int32_T, 1U> r;
  coder::array<int32_T, 1U> r1;
  real_T c_poses[9];
  real_T d_poses[3];
  int32_T b_i;
  int32_T end;
  int32_T i;
  int32_T loop_ub;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 5, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 5, 0);
  poses.set_size(&bu_emlrtRTEI, sp, 4, 4, robot_poses_vec.size(2));
  loop_ub = robot_poses_vec.size(2) << 4;
  for (end = 0; end < loop_ub; end++) {
    poses[end] = 0.0;
  }
  extrinsics.set_size(&cu_emlrtRTEI, sp, 4, 4, robot_poses_vec.size(2));
  loop_ub = robot_poses_vec.size(2) << 4;
  for (end = 0; end < loop_ub; end++) {
    extrinsics[end] = 0.0;
  }
  // read valid poses and reshape them to 4x4xn matrix
  end = robot_poses_vec.size(2);
  for (i = 0; i < end; i++) {
    covrtLogFor(&emlrtCoverageInstance, 5, 0, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 5, 1);
    if (i + 1 > robot_poses_vec.size(2)) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, robot_poses_vec.size(2),
                                    &uu_emlrtBCI, (emlrtCTX)sp);
    }
    if (i + 1 > poses.size(2)) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, poses.size(2), &vu_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    for (b_i = 0; b_i < 4; b_i++) {
      poses[4 * b_i + 16 * i] = robot_poses_vec[4 * b_i + 16 * i];
      poses[(4 * b_i + 16 * i) + 1] = robot_poses_vec[(4 * b_i + 16 * i) + 1];
      poses[(4 * b_i + 16 * i) + 2] = robot_poses_vec[(4 * b_i + 16 * i) + 2];
      poses[(4 * b_i + 16 * i) + 3] = robot_poses_vec[(4 * b_i + 16 * i) + 3];
    }
    if (i + 1 > poses.size(2)) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, poses.size(2), &wu_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    for (b_i = 0; b_i < 3; b_i++) {
      c_poses[3 * b_i] = -poses[b_i + 16 * i];
      c_poses[3 * b_i + 1] = -poses[(b_i + 16 * i) + 4];
      c_poses[3 * b_i + 2] = -poses[(b_i + 16 * i) + 8];
    }
    for (b_i = 0; b_i < 3; b_i++) {
      d_poses[b_i] = (c_poses[b_i] * poses[16 * i + 12] +
                      c_poses[b_i + 3] * poses[16 * i + 13]) +
                     c_poses[b_i + 6] * poses[16 * i + 14];
    }
    if (i + 1 > extrinsics.size(2)) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, extrinsics.size(2), &xu_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    for (b_i = 0; b_i < 3; b_i++) {
      extrinsics[4 * b_i + 16 * i] = poses[b_i + 16 * i];
      extrinsics[(4 * b_i + 16 * i) + 1] = poses[(b_i + 16 * i) + 4];
      extrinsics[(4 * b_i + 16 * i) + 2] = poses[(b_i + 16 * i) + 8];
      extrinsics[(b_i + 16 * i) + 12] = d_poses[b_i];
    }
    extrinsics[16 * i + 3] = 0.0;
    extrinsics[16 * i + 7] = 0.0;
    extrinsics[16 * i + 11] = 0.0;
    extrinsics[16 * i + 15] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 5, 0, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 5, 2);
  //  keep valid poses that have corresponding image with detected feature
  //  points
  end = valid_idx.size(0) - 1;
  loop_ub = 0;
  for (i = 0; i <= end; i++) {
    if (valid_idx[i]) {
      loop_ub++;
    }
  }
  r.set_size(&du_emlrtRTEI, sp, loop_ub);
  loop_ub = 0;
  for (i = 0; i <= end; i++) {
    if (valid_idx[i]) {
      r[loop_ub] = i + 1;
      loop_ub++;
    }
  }
  b_poses.set_size(&eu_emlrtRTEI, sp, 4, 4, r.size(0));
  loop_ub = r.size(0);
  for (end = 0; end < loop_ub; end++) {
    for (b_i = 0; b_i < 4; b_i++) {
      if (r[end] > poses.size(2)) {
        emlrtDynamicBoundsCheckR2012b(r[end], 1, poses.size(2), &av_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      b_poses[4 * b_i + 16 * end] = poses[4 * b_i + 16 * (r[end] - 1)];
      if (r[end] > poses.size(2)) {
        emlrtDynamicBoundsCheckR2012b(r[end], 1, poses.size(2), &av_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      b_poses[(4 * b_i + 16 * end) + 1] =
          poses[(4 * b_i + 16 * (r[end] - 1)) + 1];
      if (r[end] > poses.size(2)) {
        emlrtDynamicBoundsCheckR2012b(r[end], 1, poses.size(2), &av_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      b_poses[(4 * b_i + 16 * end) + 2] =
          poses[(4 * b_i + 16 * (r[end] - 1)) + 2];
      if (r[end] > poses.size(2)) {
        emlrtDynamicBoundsCheckR2012b(r[end], 1, poses.size(2), &av_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      b_poses[(4 * b_i + 16 * end) + 3] =
          poses[(4 * b_i + 16 * (r[end] - 1)) + 3];
    }
  }
  poses.set_size(&fu_emlrtRTEI, sp, 4, 4, b_poses.size(2));
  loop_ub = 16 * b_poses.size(2);
  for (end = 0; end < loop_ub; end++) {
    poses[end] = b_poses[end];
  }
  end = valid_idx.size(0) - 1;
  loop_ub = 0;
  for (i = 0; i <= end; i++) {
    if (valid_idx[i]) {
      loop_ub++;
    }
  }
  r1.set_size(&du_emlrtRTEI, sp, loop_ub);
  loop_ub = 0;
  for (i = 0; i <= end; i++) {
    if (valid_idx[i]) {
      r1[loop_ub] = i + 1;
      loop_ub++;
    }
  }
  b_poses.set_size(&gu_emlrtRTEI, sp, 4, 4, r1.size(0));
  loop_ub = r1.size(0);
  for (end = 0; end < loop_ub; end++) {
    for (b_i = 0; b_i < 4; b_i++) {
      if (r1[end] > extrinsics.size(2)) {
        emlrtDynamicBoundsCheckR2012b(r1[end], 1, extrinsics.size(2),
                                      &yu_emlrtBCI, (emlrtCTX)sp);
      }
      b_poses[4 * b_i + 16 * end] = extrinsics[4 * b_i + 16 * (r1[end] - 1)];
      if (r1[end] > extrinsics.size(2)) {
        emlrtDynamicBoundsCheckR2012b(r1[end], 1, extrinsics.size(2),
                                      &yu_emlrtBCI, (emlrtCTX)sp);
      }
      b_poses[(4 * b_i + 16 * end) + 1] =
          extrinsics[(4 * b_i + 16 * (r1[end] - 1)) + 1];
      if (r1[end] > extrinsics.size(2)) {
        emlrtDynamicBoundsCheckR2012b(r1[end], 1, extrinsics.size(2),
                                      &yu_emlrtBCI, (emlrtCTX)sp);
      }
      b_poses[(4 * b_i + 16 * end) + 2] =
          extrinsics[(4 * b_i + 16 * (r1[end] - 1)) + 2];
      if (r1[end] > extrinsics.size(2)) {
        emlrtDynamicBoundsCheckR2012b(r1[end], 1, extrinsics.size(2),
                                      &yu_emlrtBCI, (emlrtCTX)sp);
      }
      b_poses[(4 * b_i + 16 * end) + 3] =
          extrinsics[(4 * b_i + 16 * (r1[end] - 1)) + 3];
    }
  }
  extrinsics.set_size(&hu_emlrtRTEI, sp, 4, 4, b_poses.size(2));
  loop_ub = 16 * b_poses.size(2);
  for (end = 0; end < loop_ub; end++) {
    extrinsics[end] = b_poses[end];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

// End of code generation (readRobotPoses.cpp)
