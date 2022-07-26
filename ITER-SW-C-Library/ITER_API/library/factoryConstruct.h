//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: factoryConstruct.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef FACTORYCONSTRUCT_H
#define FACTORYCONSTRUCT_H

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
namespace coder {
class e_anonymous_function;

}
struct ab_struct_T;

} // namespace ITER

// Function Declarations
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
void factoryConstruct(const e_anonymous_function *nonlin, int nVar, int mCeq,
                      const ::coder::array<double, 1U> &lb,
                      const ::coder::array<double, 1U> &ub,
                      const char options_FiniteDifferenceType[7],
                      ab_struct_T *obj);

}
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for factoryConstruct.h
//
// [EOF]
//
