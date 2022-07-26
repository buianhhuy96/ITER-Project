//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: find.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef FIND_H
#define FIND_H

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
void b_eml_find(const ::coder::array<bool, 1U> &b_x,
                ::coder::array<int, 1U> &b_i);

void c_eml_find(const ::coder::array<double, 2U> &b_x,
                ::coder::array<int, 2U> &b_i);

void eml_find(const ::coder::array<double, 1U> &b_x,
              ::coder::array<int, 1U> &b_i);

} // namespace coder
} // namespace ITER

#endif
//
// File trailer for find.h
//
// [EOF]
//
