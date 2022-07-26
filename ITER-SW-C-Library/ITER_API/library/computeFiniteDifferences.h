//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeFiniteDifferences.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef COMPUTEFINITEDIFFERENCES_H
#define COMPUTEFINITEDIFFERENCES_H

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
struct w_struct_T;

struct ab_struct_T;

} // namespace ITER

// Function Declarations
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
bool b_computeFiniteDifferences(
    ab_struct_T *obj, const ::coder::array<double, 1U> &cEqCurrent,
    ::coder::array<double, 1U> &b_xk, ::coder::array<double, 2U> &JacCeqTrans,
    int ldJE, const ::coder::array<double, 1U> &lb,
    const ::coder::array<double, 1U> &ub,
    const ::coder::array<double, 1U> &runTimeOptions_TypicalX,
    const ::coder::array<double, 1U> &runTimeOptions_FiniteDifferenceStepSize);

bool computeFiniteDifferences(w_struct_T *obj,
                              const ::coder::array<double, 2U> &cEqCurrent,
                              double b_xk[6],
                              ::coder::array<double, 2U> &JacCeqTrans);

} // namespace FiniteDifferences
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for computeFiniteDifferences.h
//
// [EOF]
//
