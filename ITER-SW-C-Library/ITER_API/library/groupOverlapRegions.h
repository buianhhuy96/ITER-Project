//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: groupOverlapRegions.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef GROUPOVERLAPREGIONS_H
#define GROUPOVERLAPREGIONS_H

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
void groupOverlapRegions(const coder::MSERRegions *regions,
                         const ::coder::array<unsigned char, 2U> &ImgVGA,
                         ::coder::array<int, 2U> &uniqueRegions_PixelList,
                         ::coder::array<double, 2U> &uniqueRegions_Lengths);

}

#endif
//
// File trailer for groupOverlapRegions.h
//
// [EOF]
//
