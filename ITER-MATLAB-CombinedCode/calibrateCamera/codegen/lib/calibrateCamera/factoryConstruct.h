//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: factoryConstruct.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef FACTORYCONSTRUCT_H
#define FACTORYCONSTRUCT_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace Codegen {
namespace coder {
class b_anonymous_function;

}
struct c_struct_T;

} // namespace Codegen

// Function Declarations
namespace Codegen {
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
void factoryConstruct(const b_anonymous_function *nonlin, int32_T nVar,
                      int32_T mCeq,
                      const char_T options_FiniteDifferenceType[7],
                      c_struct_T *obj);

}
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for factoryConstruct.h
//
// [EOF]
//
