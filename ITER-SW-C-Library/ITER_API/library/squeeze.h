//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: squeeze.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef SQUEEZE_H
#define SQUEEZE_H

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
void b_squeeze(const ::coder::array<double, 3U> &b_a,
               ::coder::array<double, 2U> &b);

void squeeze(const ::coder::array<double, 3U> &b_a,
             ::coder::array<double, 2U> &b);

} // namespace coder
} // namespace ITER

#endif
//
// File trailer for squeeze.h
//
// [EOF]
//
