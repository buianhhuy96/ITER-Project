//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rodriguesVectorToMatrix.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef RODRIGUESVECTORTOMATRIX_H
#define RODRIGUESVECTORTOMATRIX_H

// Include Files
#include "rtwtypes.h"
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
void rodriguesVectorToMatrix(const double rotationVector[3],
                             double rotationMatrix[3][3]);

}
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for rodriguesVectorToMatrix.h
//
// [EOF]
//
