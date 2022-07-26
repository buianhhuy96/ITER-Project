//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: preprocessImages.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef PREPROCESSIMAGES_H
#define PREPROCESSIMAGES_H

// Include Files
#include "ITER_API_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace ITER {
extern void preprocessImages(const ::coder::array<unsigned char, 4U> &images,
                             const struct1_T *cameraParams, bool undistort,
                             ::coder::array<unsigned char, 4U> &gray_images);

}

#endif
//
// File trailer for preprocessImages.h
//
// [EOF]
//
