//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeInitialParameterEstimate.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef COMPUTEINITIALPARAMETERESTIMATE_H
#define COMPUTEINITIALPARAMETERESTIMATE_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace Codegen {
struct struct1_T;

namespace coder {
class rtString;

}
} // namespace Codegen

// Function Declarations
namespace Codegen {
void computeInitialParameterEstimate(
    const ::coder::array<real_T, 2U> &d_worldPoints,
    const ::coder::array<real_T, 3U> &b_imagePoints, struct1_T *iniltialParams,
    ::coder::array<boolean_T, 1U> &b_validIdx, coder::rtString *err);

}

#endif
//
// File trailer for computeInitialParameterEstimate.h
//
// [EOF]
//
