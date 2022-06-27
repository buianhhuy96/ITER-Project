//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: costFunc1.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef COSTFUNC1_H
#define COSTFUNC1_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
void c_binary_expand_op(coder::array<double, 2U> &err,
                        const coder::array<double, 2U> &undist_imgMarkerPts,
                        const coder::array<double, 2U> &b_x);

#endif
//
// File trailer for costFunc1.h
//
// [EOF]
//
