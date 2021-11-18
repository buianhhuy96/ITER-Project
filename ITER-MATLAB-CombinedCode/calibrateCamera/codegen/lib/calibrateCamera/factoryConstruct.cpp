//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: factoryConstruct.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "factoryConstruct.h"
#include "anonymous_function.h"
#include "calibrateCamera_data.h"
#include "calibrateCamera_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const b_anonymous_function *nonlin
//                int32_T nVar
//                int32_T mCeq
//                const char_T options_FiniteDifferenceType[7]
//                c_struct_T *obj
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
void factoryConstruct(const b_anonymous_function *nonlin, int32_T nVar,
                      int32_T mCeq,
                      const char_T options_FiniteDifferenceType[7],
                      c_struct_T *obj)
{
  static const char_T b_cv[7]{'f', 'o', 'r', 'w', 'a', 'r', 'd'};
  int32_T idx;
  boolean_T b_bool;
  obj->nonlin = *nonlin;
  obj->b_f_1 = 0.0;
  obj->cEq_1.set_size(mCeq);
  obj->f_2 = 0.0;
  obj->cEq_2.set_size(mCeq);
  obj->nVar = nVar;
  obj->mIneq = 0;
  obj->mEq = mCeq;
  obj->numEvals = 0;
  obj->SpecifyObjectiveGradient = false;
  obj->SpecifyConstraintGradient = false;
  obj->isEmptyNonlcon = (mCeq == 0);
  obj->hasLB.set_size(nVar);
  obj->hasUB.set_size(nVar);
  b_bool = false;
  idx = 0;
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (idx < 7) {
      if (cv[static_cast<uint8_T>(options_FiniteDifferenceType[idx])] !=
          cv[static_cast<int32_T>(b_cv[idx])]) {
        exitg1 = 1;
      } else {
        idx++;
      }
    } else {
      b_bool = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  obj->FiniteDifferenceType = static_cast<int32_T>(!b_bool);
  idx = 0;
  while ((idx + 1) <= nVar) {
    obj->hasLB[idx] = false;
    obj->hasUB[idx] = false;
    idx++;
  }
  obj->hasBounds = false;
}

} // namespace FiniteDifferences
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace Codegen

//
// File trailer for factoryConstruct.cpp
//
// [EOF]
//
