//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: detectMSERFeatures.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef DETECTMSERFEATURES_H
#define DETECTMSERFEATURES_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace ITER {
namespace coder {
class MSERRegions;

}
} // namespace ITER

// Function Declarations
namespace ITER {
namespace coder {
void detectMSERFeatures(const ::coder::array<unsigned char, 2U> &o_I,
                        const double varargin_2[2], double varargin_4,
                        MSERRegions *regions);

}
} // namespace ITER

#endif
//
// File trailer for detectMSERFeatures.h
//
// [EOF]
//
