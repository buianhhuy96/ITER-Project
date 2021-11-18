//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rodriguesMatrixToVector.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

#ifndef RODRIGUESMATRIXTOVECTOR_H
#define RODRIGUESMATRIXTOVECTOR_H

// Include Files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
void rodriguesMatrixToVector(double rotationMatrix[3][3],
                             double rotationVector[3]);

}
} // namespace internal
} // namespace vision
} // namespace coder

#endif
//
// File trailer for rodriguesMatrixToVector.h
//
// [EOF]
//
