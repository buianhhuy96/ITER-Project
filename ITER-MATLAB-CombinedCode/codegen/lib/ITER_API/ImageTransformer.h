//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ImageTransformer.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

#ifndef IMAGETRANSFORMER_H
#define IMAGETRANSFORMER_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
class ImageTransformer {
};

class b_ImageTransformer {
public:
  void update(const ::coder::array<unsigned char, 3U> &o_I,
              const double b_intrinsicMatrix[3][3], const double radialDist[3],
              const double tangentialDist[2], const double b_xBounds[2],
              const double b_yBounds[2]);
  array<float, 2U> XmapSingle;
  array<float, 2U> YmapSingle;
  array<double, 2U> SizeOfImage;
  array<char, 2U> ClassOfImage;
  array<char, 2U> OutputView;
  double XBounds[2];
  double YBounds[2];
};

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

#endif
//
// File trailer for ImageTransformer.h
//
// [EOF]
//
