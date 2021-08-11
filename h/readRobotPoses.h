//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: readRobotPoses.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

#ifndef READROBOTPOSES_H
#define READROBOTPOSES_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void readRobotPoses(const coder::array<double, 3U> &robot_poses_vec,
                           const coder::array<boolean_T, 2U> &valid_idx,
                           coder::array<double, 3U> &poses,
                           coder::array<double, 3U> &extrinsics);

#endif
//
// File trailer for readRobotPoses.h
//
// [EOF]
//
