//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: subPixelLocation.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef SUBPIXELLOCATION_H
#define SUBPIXELLOCATION_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace ITER {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void subPixelLocation(const ::coder::array<float, 2U> &metric,
                      ::coder::array<double, 2U> &loc);

}
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
void subPixelLocationImpl_init();

} // namespace ITER

#endif
//
// File trailer for subPixelLocation.h
//
// [EOF]
//
