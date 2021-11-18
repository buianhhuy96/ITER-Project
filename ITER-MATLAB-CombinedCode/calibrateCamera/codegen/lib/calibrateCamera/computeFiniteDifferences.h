//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeFiniteDifferences.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef COMPUTEFINITEDIFFERENCES_H
#define COMPUTEFINITEDIFFERENCES_H

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
namespace utils {
namespace FiniteDifferences {
boolean_T computeFiniteDifferences(c_struct_T *obj,
                                   const ::coder::array<real_T, 1U> &cEqCurrent,
                                   ::coder::array<real_T, 1U> &xk,
                                   ::coder::array<real_T, 2U> &JacCeqTrans,
                                   int32_T ldJE);

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
