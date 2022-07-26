//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzlarf.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef XZLARF_H
#define XZLARF_H

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
namespace internal {
namespace reflapack {
void b_xzlarf(int m, int h_n, int iv0, double tau,
              ::coder::array<double, 2U> &c_C, int ic0, int ldc,
              double work[6]);

void c_xzlarf(int m, int h_n, int iv0, double tau, double c_C[4][4], int ic0,
              double work[4]);

void d_xzlarf(int m, int h_n, int iv0, double tau, double c_C[15][15], int ic0,
              double work[15]);

void xzlarf(int m, int h_n, int iv0, double tau,
            ::coder::array<double, 2U> &c_C, int ic0, int ldc,
            ::coder::array<double, 1U> &work);

} // namespace reflapack
} // namespace internal
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for xzlarf.h
//
// [EOF]
//
