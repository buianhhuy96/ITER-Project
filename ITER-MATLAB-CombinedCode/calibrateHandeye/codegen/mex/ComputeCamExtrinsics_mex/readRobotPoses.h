//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// readRobotPoses.h
//
// Code generation for function 'readRobotPoses'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
void readRobotPoses(const emlrtStack *sp,
                    const coder::array<real_T, 3U> &robot_poses_vec,
                    const coder::array<boolean_T, 1U> &valid_idx,
                    coder::array<real_T, 3U> &poses,
                    coder::array<real_T, 3U> &extrinsics);

// End of code generation (readRobotPoses.h)
