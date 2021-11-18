//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: cat.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
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
namespace Codegen {
namespace coder {
void b_cat(const ::coder::array<double, 1U> &varargin_1,
           const double varargin_2[2], ::coder::array<double, 1U> &y);

void cat(const ::coder::array<double, 2U> &varargin_1,
         const ::coder::array<double, 2U> &varargin_2,
         ::coder::array<double, 3U> &y);

} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for cat.h
//
// [EOF]
//
