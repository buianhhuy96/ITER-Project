//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: inv.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef INV_H
#define INV_H

// Include Files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void b_inv(const double b_x[4][4], double y[4][4]);

void inv(const double b_x[3][3], double y[3][3]);

} // namespace coder

#endif
//
// File trailer for inv.h
//
// [EOF]
//
