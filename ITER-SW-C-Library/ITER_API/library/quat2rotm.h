//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: quat2rotm.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef QUAT2ROTM_H
#define QUAT2ROTM_H

// Include Files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void quat2rotm(const double b_q[4], double c_R[3][3]);

}

#endif
//
// File trailer for quat2rotm.h
//
// [EOF]
//
