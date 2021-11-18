//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeInitialParameterEstimate.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
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
namespace Codegen {
struct struct1_T;

}

// Function Declarations
namespace Codegen {
void computeInitialParameterEstimate(
    const ::coder::array<double, 2U> &c_worldPoints,
    const ::coder::array<double, 3U> &b_imagePoints,
    const double b_imageSize[2], struct1_T *initialParams,
    ::coder::array<bool, 1U> &c_validIdx, int *err);

}

#endif
//
// File trailer for computeInitialParameterEstimate.h
//
// [EOF]
//
