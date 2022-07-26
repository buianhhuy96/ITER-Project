//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: repmat.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef REPMAT_H
#define REPMAT_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace ITER {
struct h_struct_T;

struct f_struct_T;

} // namespace ITER

// Function Declarations
namespace ITER {
namespace coder {
void b_repmat(double varargin_1, ::coder::array<f_struct_T, 1U> &b);

void repmat(const h_struct_T *b_a, double varargin_1,
            ::coder::array<h_struct_T, 1U> &b);

} // namespace coder
} // namespace ITER

#endif
//
// File trailer for repmat.h
//
// [EOF]
//
