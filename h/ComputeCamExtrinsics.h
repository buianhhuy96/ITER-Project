//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ComputeCamExtrinsics.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

#ifndef COMPUTECAMEXTRINSICS_H
#define COMPUTECAMEXTRINSICS_H

// Include Files
#include "calibrateHandeye_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void
ComputeCamExtrinsics(const coder::array<unsigned char, 4U> &b_images,
                     double square_size, const struct0_T *camera_params,
                     coder::array<double, 3U> &image_points,
                     coder::array<boolean_T, 1U> &valid_idx,
                     coder::array<double, 3U> &cam_extrinsics,
                     coder::array<double, 3U> &camera_poses,
                     coder::array<double, 2U> &world_points);

#endif
//
// File trailer for ComputeCamExtrinsics.h
//
// [EOF]
//
