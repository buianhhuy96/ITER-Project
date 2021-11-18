//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rodriguesVectorToMatrix.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

#ifndef RODRIGUESVECTORTOMATRIX_H
#define RODRIGUESVECTORTOMATRIX_H

// Include Files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace Codegen {
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
} // namespace Codegen

#endif
//
// File trailer for rodriguesVectorToMatrix.h
//
// [EOF]
//
