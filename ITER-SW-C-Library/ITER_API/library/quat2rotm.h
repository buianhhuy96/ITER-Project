//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: quat2rotm.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef QUAT2ROTM_H
#define QUAT2ROTM_H

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
void quat2rotm(const double b_q[4], double b_R[3][3]);

}
} // namespace ITER

#endif
//
// File trailer for quat2rotm.h
//
// [EOF]
//
