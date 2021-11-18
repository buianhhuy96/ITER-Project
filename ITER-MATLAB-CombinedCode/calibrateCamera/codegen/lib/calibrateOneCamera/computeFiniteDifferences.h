//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeFiniteDifferences.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

#ifndef COMPUTEFINITEDIFFERENCES_H
#define COMPUTEFINITEDIFFERENCES_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace Codegen {
struct g_struct_T;

}

// Function Declarations
namespace Codegen {
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
bool computeFiniteDifferences(
    g_struct_T *obj, const ::coder::array<double, 1U> &cEqCurrent,
    ::coder::array<double, 1U> &xk, ::coder::array<double, 2U> &JacCeqTrans,
    int ldJE, const ::coder::array<double, 1U> &runTimeOptions_TypicalX,
    const ::coder::array<double, 1U> &runTimeOptions_FiniteDifferenceStepSize);

}
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for computeFiniteDifferences.h
//
// [EOF]
//
