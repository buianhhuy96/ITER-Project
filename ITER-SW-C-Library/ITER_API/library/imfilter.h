//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: imfilter.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef IMFILTER_H
#define IMFILTER_H

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
void b_imfilter(::coder::array<float, 2U> &varargin_1);

void c_imfilter(::coder::array<float, 2U> &varargin_1);

void d_imfilter(::coder::array<float, 2U> &varargin_1);

void imfilter(::coder::array<float, 2U> &varargin_1);

void padImage(const ::coder::array<float, 2U> &a_tmp, const double pad[2],
              ::coder::array<float, 2U> &b_a);

} // namespace coder
} // namespace ITER

#endif
//
// File trailer for imfilter.h
//
// [EOF]
//
