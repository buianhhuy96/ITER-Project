//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rot90.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef ROT90_H
#define ROT90_H

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
void b_rot90(const ::coder::array<double, 2U> &A,
             ::coder::array<double, 2U> &e_B);

void rot90(const ::coder::array<double, 2U> &A,
           ::coder::array<double, 2U> &e_B);

} // namespace coder
} // namespace ITER

#endif
//
// File trailer for rot90.h
//
// [EOF]
//
