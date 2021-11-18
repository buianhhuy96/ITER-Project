//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: unsafeSxfun.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

#ifndef UNSAFESXFUN_H
#define UNSAFESXFUN_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
void b_binary_expand_op(coder::array<double, 2U> &r,
                        const coder::array<double, 3U> &imgPts, int j,
                        const coder::array<double, 2U> &b_x);

void binary_expand_op(coder::array<double, 2U> &r,
                      const coder::array<double, 2U> &projectedPoints,
                      const coder::array<double, 3U> &e_ImagePoints, int h_n);

#endif
//
// File trailer for unsafeSxfun.h
//
// [EOF]
//
