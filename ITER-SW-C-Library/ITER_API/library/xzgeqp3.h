//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzgeqp3.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef XZGEQP3_H
#define XZGEQP3_H

// Include Files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace reflapack {
void qrf(double A[15][15], int b_m, int h_n, int nfxd, double tau[15]);

}
} // namespace internal
} // namespace coder

#endif
//
// File trailer for xzgeqp3.h
//
// [EOF]
//
