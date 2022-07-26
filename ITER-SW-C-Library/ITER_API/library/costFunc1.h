//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: costFunc1.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef COSTFUNC1_H
#define COSTFUNC1_H

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
void d_binary_expand_op(::coder::array<double, 2U> &err,
                        const ::coder::array<double, 2U> &undist_imgMarkerPts,
                        const ::coder::array<double, 2U> &b_x);

}

#endif
//
// File trailer for costFunc1.h
//
// [EOF]
//
