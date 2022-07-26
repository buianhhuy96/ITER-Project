//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: regionprops.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef REGIONPROPS_H
#define REGIONPROPS_H

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
void b_regionprops(const ::coder::array<bool, 2U> &varargin_1,
                   const ::coder::array<unsigned char, 2U> &varargin_2,
                   ::coder::array<f_struct_T, 1U> &outstats);

void regionprops(const ::coder::array<bool, 2U> &varargin_1,
                 ::coder::array<h_struct_T, 1U> &outstats);

} // namespace coder
} // namespace ITER

#endif
//
// File trailer for regionprops.h
//
// [EOF]
//
