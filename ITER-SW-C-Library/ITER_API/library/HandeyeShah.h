//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: HandeyeShah.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
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
                        const coder::array<double, 3U> &b_Bs, double d_X[4][4],
                        double g_Y[4][4], int *err);

#endif
//
// File trailer for HandeyeShah.h
//
// [EOF]
//
