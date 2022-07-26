//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: unsafeSxfun.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef UNSAFESXFUN_H
#define UNSAFESXFUN_H

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
void b_binary_expand_op(::coder::array<double, 2U> &r,
                        const ::coder::array<double, 3U> &imgPts, int j,
                        const ::coder::array<double, 2U> &b_x);

void binary_expand_op(
    ::coder::array<double, 2U> &r,
    const ::coder::array<double, 2U> &distortedNormalizedPoints,
    const double f_K[3][3], const ::coder::array<double, 3U> &e_ImagePoints,
    int h_n);

} // namespace ITER

#endif
//
// File trailer for unsafeSxfun.h
//
// [EOF]
//
