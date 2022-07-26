//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ImageTransformer.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef IMAGETRANSFORMER_H
#define IMAGETRANSFORMER_H

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
namespace vision {
namespace internal {
namespace calibration {
class ImageTransformer {
public:
  ImageTransformer();
  ~ImageTransformer();
};

class b_ImageTransformer {
public:
  void update(const ::coder::array<unsigned char, 3U> &o_I,
              const double b_intrinsicMatrix[3][3], const double radialDist[3],
              const double tangentialDist[2], const double b_xBounds[2],
              const double b_yBounds[2]);
  ::coder::array<float, 2U> XmapSingle;
  ::coder::array<float, 2U> YmapSingle;
  ::coder::array<double, 2U> SizeOfImage;
  ::coder::array<char, 2U> ClassOfImage;
  ::coder::array<char, 2U> OutputView;
  double XBounds[2];
  double YBounds[2];
};

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for ImageTransformer.h
//
// [EOF]
//
