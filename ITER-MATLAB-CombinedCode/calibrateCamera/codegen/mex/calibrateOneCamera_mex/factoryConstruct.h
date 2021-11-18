//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// factoryConstruct.h
//
// Code generation for function 'factoryConstruct'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include "omp.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Declarations
namespace Codegen {
namespace coder {
class b_anonymous_function;

}
struct e_struct_T;

} // namespace Codegen

// Function Declarations
namespace Codegen {
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
void factoryConstruct(const emlrtStack *sp, const b_anonymous_function *nonlin,
                      int32_T nVar, int32_T mCeq,
                      const char_T options_FiniteDifferenceType[7],
                      e_struct_T *obj);

}
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace Codegen

// End of code generation (factoryConstruct.h)
