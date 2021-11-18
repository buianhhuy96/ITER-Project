//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// ComputeCamExtrinsics.h
//
// Code generation for function 'ComputeCamExtrinsics'
//

#pragma once

// Include files
#include "ComputeCamExtrinsics_mex_types.h"
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
void ComputeCamExtrinsics(const emlrtStack *sp,
                          const coder::array<uint8_T, 4U> &images,
                          real_T square_size, const struct0_T *camera_params,
                          coder::array<real_T, 3U> &image_points,
                          coder::array<boolean_T, 1U> &valid_idx,
                          coder::array<real_T, 3U> &cam_extrinsics,
                          coder::array<real_T, 3U> &camera_poses,
                          coder::array<real_T, 2U> &world_points, int32_T *err);

// End of code generation (ComputeCamExtrinsics.h)
