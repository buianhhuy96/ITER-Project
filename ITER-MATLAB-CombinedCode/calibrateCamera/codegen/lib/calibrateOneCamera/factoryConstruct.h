//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: factoryConstruct.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

#ifndef FACTORYCONSTRUCT_H
#define FACTORYCONSTRUCT_H

// Include Files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace Codegen {
namespace coder {
class b_anonymous_function;

}
struct g_struct_T;

} // namespace Codegen

// Function Declarations
namespace Codegen {
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
void factoryConstruct(const b_anonymous_function *nonlin, int nVar, int mCeq,
                      const char options_FiniteDifferenceType[7],
                      g_struct_T *obj);

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
