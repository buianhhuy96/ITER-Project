//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: svd.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef SVD_H
#define SVD_H

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
void b_svd(const double A[3][3], double U[3][3], double c_S[3][3],
           double V[3][3]);

void svd(const double A[29][29], double U[29][29], double c_S[29][29],
         double V[29][29]);

} // namespace coder
} // namespace ITER

#endif
//
// File trailer for svd.h
//
// [EOF]
//
