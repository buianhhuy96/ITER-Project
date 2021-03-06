//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rot90.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

#ifndef ROT90_H
#define ROT90_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void b_rot90(const ::coder::array<double, 2U> &A,
             ::coder::array<double, 2U> &c_B);

void rot90(const ::coder::array<double, 2U> &A,
           ::coder::array<double, 2U> &c_B);

} // namespace coder

#endif
//
// File trailer for rot90.h
//
// [EOF]
//
