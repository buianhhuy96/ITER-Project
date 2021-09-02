//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: preprocessImages.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

#ifndef PREPROCESSIMAGES_H
#define PREPROCESSIMAGES_H

// Include Files
#include "calibrateHandeye_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void preprocessImages(const coder::array<unsigned char, 4U> &b_images,
                             const struct1_T *camera_params,
                             coder::array<unsigned char, 4U> &gray_images);

#endif
//
// File trailer for preprocessImages.h
//
// [EOF]
//
