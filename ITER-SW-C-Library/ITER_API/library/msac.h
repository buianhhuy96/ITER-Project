//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: msac.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef MSAC_H
#define MSAC_H

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
namespace ransac {
void msac(const ::coder::array<double, 2U> &allPoints,
          const double varargin_1[3][3], bool *isFound,
          double bestModelParams_R[3][3], double bestModelParams_t[3],
          ::coder::array<bool, 1U> &inliers);

}
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for msac.h
//
// [EOF]
//
