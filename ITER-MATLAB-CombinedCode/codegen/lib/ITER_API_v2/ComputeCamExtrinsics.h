//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ComputeCamExtrinsics.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

#ifndef COMPUTECAMEXTRINSICS_H
#define COMPUTECAMEXTRINSICS_H

// Include Files
#include "ITER_API_v2_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void ComputeCamExtrinsics(const coder::array<unsigned char, 4U> &images,
                                 double b_square_size,
                                 const struct1_T *camera_params,
                                 coder::array<double, 3U> &e_image_points,
                                 coder::array<bool, 1U> &b_valid_idx,
                                 coder::array<double, 3U> &cam_extrinsics,
                                 coder::array<double, 3U> &camera_poses,
                                 coder::array<double, 2U> &b_world_points,
                                 int *err);

#endif
//
// File trailer for ComputeCamExtrinsics.h
//
// [EOF]
//
