//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: HandeyeShah.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

#ifndef HANDEYESHAH_H
#define HANDEYESHAH_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void HandeyeShah(const coder::array<double, 3U> &As,
                        const coder::array<double, 3U> &Bs, double b_X[4][4],
                        double Y[4][4], double *b_time);

#endif
//
// File trailer for HandeyeShah.h
//
// [EOF]
//
