//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: worldToImage.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

#ifndef WORLDTOIMAGE_H
#define WORLDTOIMAGE_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class c_cameraParameters;

}

// Function Declarations
namespace coder {
void worldToImage(const c_cameraParameters *intrinsics,
                  const double varargin_1[3][3],
                  const ::coder::array<double, 2U> &varargin_2,
                  const ::coder::array<double, 2U> &varargin_3,
                  ::coder::array<double, 2U> &varargout_1);

}

#endif
//
// File trailer for worldToImage.h
//
// [EOF]
//
