//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rotm2quat.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef ROTM2QUAT_H
#define ROTM2QUAT_H

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
void rotm2quat(const double b_R[3][3], double quat[4]);

}
} // namespace ITER

#endif
//
// File trailer for rotm2quat.h
//
// [EOF]
//
