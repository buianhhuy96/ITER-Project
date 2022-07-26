//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: MSERRegions.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef MSERREGIONS_H
#define MSERREGIONS_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace ITER {
namespace coder {
class MSERRegions {
public:
  ::coder::array<float, 2U> Centroid;
  ::coder::array<float, 2U> Axes;
  ::coder::array<float, 1U> Orientation;
  ::coder::array<int, 2U> PixelList;
  ::coder::array<int, 1U> Lengths;
};

} // namespace coder
} // namespace ITER

#endif
//
// File trailer for MSERRegions.h
//
// [EOF]
//
