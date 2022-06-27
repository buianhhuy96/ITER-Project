//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rotm2quat.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef ROTM2QUAT_H
#define ROTM2QUAT_H

// Include Files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void rotm2quat(const double c_R[3][3], double quat[4]);

}

#endif
//
// File trailer for rotm2quat.h
//
// [EOF]
//
