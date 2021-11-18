//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: cat.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

#ifndef CAT_H
#define CAT_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void b_cat(const ::coder::array<double, 1U> &varargin_1,
           const ::coder::array<double, 1U> &varargin_2,
           ::coder::array<double, 1U> &y);

void c_cat(const ::coder::array<double, 1U> &varargin_1,
           const double varargin_2[2], ::coder::array<double, 1U> &y);

void cat(const ::coder::array<double, 2U> &varargin_1,
         const ::coder::array<double, 2U> &varargin_2,
         ::coder::array<double, 3U> &y);

} // namespace coder

#endif
//
// File trailer for cat.h
//
// [EOF]
//
