//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calculateReprErr.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef CALCULATEREPRERR_H
#define CALCULATEREPRERR_H

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
void c_binary_expand_op(::coder::array<double, 2U> &b_x,
                        const ::coder::array<double, 2U> &projectedPoints_Cam1,
                        const ::coder::array<double, 2U> &imagePointsTmp);

}

#endif
//
// File trailer for calculateReprErr.h
//
// [EOF]
//
