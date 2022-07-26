//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: linearLeastSquares.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef LINEARLEASTSQUARES_H
#define LINEARLEASTSQUARES_H

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
namespace optim {
namespace coder {
namespace levenbergMarquardt {
void b_linearLeastSquares(::coder::array<double, 2U> &lhs,
                          ::coder::array<double, 1U> &rhs, double b_dx[6],
                          int m);

void linearLeastSquares(::coder::array<double, 2U> &lhs,
                        ::coder::array<double, 1U> &rhs,
                        ::coder::array<double, 1U> &b_dx, int m, int h_n);

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for linearLeastSquares.h
//
// [EOF]
//
