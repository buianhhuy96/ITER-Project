//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: factoryConstruct.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "factoryConstruct.h"
#include "ITER_API_data.h"
#include "ITER_API_internal_types.h"
#include "anonymous_function.h"
#include "hasFiniteBounds.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const e_anonymous_function *nonlin
//                int nVar
//                int mCeq
//                const ::coder::array<double, 1U> &lb
//                const ::coder::array<double, 1U> &ub
//                const char options_FiniteDifferenceType[7]
//                ab_struct_T *obj
// Return Type  : void
//
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
                      ab_struct_T *obj)
{
  static const char b_cv[7]{'f', 'o', 'r', 'w', 'a', 'r', 'd'};
  int kstr;
  bool b_bool;
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
  kstr = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (kstr < 7) {
      if (cv1[(static_cast<unsigned char>(options_FiniteDifferenceType[kstr])) &
              (static_cast<unsigned char>(127))] !=
          cv1[static_cast<int>(b_cv[kstr])]) {
        exitg1 = 1;
      } else {
        kstr++;
      }
    } else {
      b_bool = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  obj->FiniteDifferenceType = static_cast<int>(!b_bool);
  obj->hasBounds = b_hasFiniteBounds(nVar, obj->hasLB, obj->hasUB, lb, ub);
}

} // namespace FiniteDifferences
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

//
// File trailer for factoryConstruct.cpp
//
// [EOF]
//
