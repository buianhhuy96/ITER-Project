//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: jacobianFiniteDifference.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef JACOBIANFINITEDIFFERENCE_H
#define JACOBIANFINITEDIFFERENCE_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace ITER {
struct ab_struct_T;

}

// Function Declarations
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
bool b_jacobianFiniteDifference(
    ::coder::array<double, 2U> &augJacobian,
    const ::coder::array<double, 1U> &fCurrent, int *funcCount,
    const ::coder::array<double, 1U> &b_x, const ::coder::array<double, 1U> &lb,
    const ::coder::array<double, 1U> &ub,
    const char options_FiniteDifferenceType[7],
    const ab_struct_T *FiniteDifferences,
    const ::coder::array<double, 1U> &runTimeOptions_TypicalX,
    const ::coder::array<double, 1U> &runTimeOptions_FiniteDifferenceStepSize);

void jacobianFiniteDifference(
    ::coder::array<double, 2U> &augJacobian,
    const ::coder::array<double, 1U> &fCurrent,
    const ::coder::array<double, 1U> &b_x, const ::coder::array<double, 1U> &lb,
    const ::coder::array<double, 1U> &ub,
    const char options_FiniteDifferenceType[7], ab_struct_T *FiniteDifferences,
    const ::coder::array<double, 1U> &runTimeOptions_TypicalX,
    const ::coder::array<double, 1U> &runTimeOptions_FiniteDifferenceStepSize,
    int *funcCount, bool *evalOK);

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for jacobianFiniteDifference.h
//
// [EOF]
//
