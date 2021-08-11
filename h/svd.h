//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: svd.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

#ifndef SVD_H
#define SVD_H

// Include Files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void b_svd(const double A[3][3], double U[3][3], double S[3][3],
           double V[3][3]);

void svd(const double A[29][29], double U[29][29], double S[29][29],
         double V[29][29]);

} // namespace coder

#endif
//
// File trailer for svd.h
//
// [EOF]
//
