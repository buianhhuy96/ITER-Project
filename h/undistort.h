//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: undistort.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

#ifndef UNDISTORT_H
#define UNDISTORT_H

// Include Files
#include "calibrateHandeye_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void undistort(coder::array<unsigned char, 4U> &b_images,
                      const struct0_T *camera_params);

#endif
//
// File trailer for undistort.h
//
// [EOF]
//
