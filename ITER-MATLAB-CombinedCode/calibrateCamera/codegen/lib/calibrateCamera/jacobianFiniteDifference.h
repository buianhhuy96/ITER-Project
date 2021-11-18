//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: jacobianFiniteDifference.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef JACOBIANFINITEDIFFERENCE_H
#define JACOBIANFINITEDIFFERENCE_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace Codegen {
struct c_struct_T;

}

// Function Declarations
namespace Codegen {
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
boolean_T
b_jacobianFiniteDifference(::coder::array<real_T, 2U> &augJacobian,
                           const ::coder::array<real_T, 1U> &fCurrent,
                           int32_T *funcCount,
                           const ::coder::array<real_T, 1U> &b_x,
                           const char_T options_FiniteDifferenceType[7],
                           const c_struct_T *FiniteDifferences);

void jacobianFiniteDifference(::coder::array<real_T, 2U> &augJacobian,
                              const ::coder::array<real_T, 1U> &fCurrent,
                              const ::coder::array<real_T, 1U> &b_x,
                              const char_T options_FiniteDifferenceType[7],
                              c_struct_T *FiniteDifferences, int32_T *funcCount,
                              boolean_T *evalOK);

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for jacobianFiniteDifference.h
//
// [EOF]
//
