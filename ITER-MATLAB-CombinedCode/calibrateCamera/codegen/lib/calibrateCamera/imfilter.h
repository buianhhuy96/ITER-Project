//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: imfilter.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef IMFILTER_H
#define IMFILTER_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace Codegen {
namespace coder {
void b_imfilter(::coder::array<real32_T, 2U> &varargin_1);

void c_imfilter(::coder::array<real32_T, 2U> &varargin_1);

void imfilter(::coder::array<real32_T, 2U> &varargin_1);

void padImage_outSize(const ::coder::array<real32_T, 2U> &a_tmp,
                      const real_T pad[2], ::coder::array<real32_T, 2U> &b_a);

} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for imfilter.h
//
// [EOF]
//
