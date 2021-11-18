//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// ImageTransformer.h
//
// Code generation for function 'ImageTransformer'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Definitions
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
class ImageTransformer {
};

class b_ImageTransformer {
public:
  void update(const emlrtStack *sp, const ::coder::array<uint8_T, 3U> &b_I,
              const real_T intrinsicMatrix[9], const real_T radialDist[3],
              const real_T tangentialDist[2], const real_T xBounds[2],
              const real_T yBounds[2]);
  void transformImage(const emlrtStack *sp,
                      const ::coder::array<uint8_T, 3U> &b_I,
                      const ::coder::array<uint8_T, 3U> &fillValues,
                      ::coder::array<uint8_T, 3U> &J,
                      real_T newOrigin[2]) const;
  array<real32_T, 2U> XmapSingle;
  array<real32_T, 2U> YmapSingle;
  array<real_T, 2U> SizeOfImage;
  array<char_T, 2U> ClassOfImage;
  array<char_T, 2U> OutputView;
  real_T XBounds[2];
  real_T YBounds[2];
};

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

// End of code generation (ImageTransformer.h)
