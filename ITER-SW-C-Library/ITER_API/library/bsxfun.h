//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bsxfun.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef BSXFUN_H
#define BSXFUN_H

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
void b_bsxfun(const ::coder::array<double, 2U> &b_a,
              const ::coder::array<double, 1U> &b,
              ::coder::array<double, 2U> &c);

void bsxfun(const ::coder::array<float, 2U> &b_a,
            const ::coder::array<double, 2U> &b, ::coder::array<float, 2U> &c);

void c_bsxfun(const ::coder::array<double, 2U> &b_a,
              const ::coder::array<double, 2U> &b,
              ::coder::array<double, 2U> &c);

} // namespace coder
} // namespace ITER

#endif
//
// File trailer for bsxfun.h
//
// [EOF]
//
