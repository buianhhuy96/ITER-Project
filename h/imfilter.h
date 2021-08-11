//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: imfilter.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

#ifndef IMFILTER_H
#define IMFILTER_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void b_imfilter(::coder::array<float, 2U> &varargin_1);

void c_imfilter(::coder::array<float, 2U> &varargin_1);

void d_imfilter(::coder::array<float, 2U> &varargin_1);

void imfilter(::coder::array<float, 2U> &varargin_1);

void padImage(const ::coder::array<float, 2U> &a_tmp, const double pad[2],
              ::coder::array<float, 2U> &a);

} // namespace coder

#endif
//
// File trailer for imfilter.h
//
// [EOF]
//
