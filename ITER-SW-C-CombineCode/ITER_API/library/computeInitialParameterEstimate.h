//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeInitialParameterEstimate.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

#ifndef COMPUTEINITIALPARAMETERESTIMATE_H
#define COMPUTEINITIALPARAMETERESTIMATE_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct c_struct_T;

// Function Declarations
void computeInitialParameterEstimate(
    const coder::array<double, 2U> &c_worldPoints,
    const coder::array<double, 3U> &b_imagePoints, const double c_imageSize[2],
    c_struct_T *initialParams, coder::array<bool, 1U> &validIdx, int *err);

#endif
//
// File trailer for computeInitialParameterEstimate.h
//
// [EOF]
//
