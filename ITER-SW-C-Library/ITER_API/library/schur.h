//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: schur.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef SCHUR_H
#define SCHUR_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace ITER {
namespace coder {
void b_schur(const double A[4][4], double V[4][4], double T[4][4]);

void schur(const ::coder::array<double, 2U> &A, ::coder::array<double, 2U> &V);

} // namespace coder
} // namespace ITER

#endif
//
// File trailer for schur.h
//
// [EOF]
//
