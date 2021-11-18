//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: distortPoints.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

#ifndef DISTORTPOINTS_H
#define DISTORTPOINTS_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
void distortPoints(const ::coder::array<double, 2U> &b_points,
                   const double b_intrinsicMatrix[3][3],
                   const double b_radialDistortion[3],
                   const double b_tangentialDistortion[2],
                   ::coder::array<double, 2U> &distortedPoints);

}
} // namespace internal
} // namespace vision
} // namespace coder

#endif
//
// File trailer for distortPoints.h
//
// [EOF]
//
