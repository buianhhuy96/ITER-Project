//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// factoryConstruct.cpp
//
// Code generation for function 'factoryConstruct'
//

// Include files
#include "factoryConstruct.h"
#include "anonymous_function.h"
#include "calibrateOneCamera_mex_data.h"
#include "calibrateOneCamera_mex_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo pab_emlrtRSI{
    1,                  // lineNo
    "factoryConstruct", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\factoryConstruct.p" // pathName
};

static emlrtRTEInfo ur_emlrtRTEI{
    1,                  // lineNo
    1,                  // colNo
    "factoryConstruct", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\factoryConstruct.p" // pName
};

// Function Definitions
namespace Codegen {
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
void factoryConstruct(const emlrtStack *sp, const b_anonymous_function *nonlin,
                      int32_T nVar, int32_T mCeq,
                      const char_T options_FiniteDifferenceType[7],
                      e_struct_T *obj)
{
  static const char_T b_cv[7]{'f', 'o', 'r', 'w', 'a', 'r', 'd'};
  emlrtStack st;
  int32_T idx;
  boolean_T b_bool;
  st.prev = sp;
  st.tls = sp->tls;
  obj->nonlin = *nonlin;
  obj->f_1 = 0.0;
  obj->cEq_1.set_size(&ur_emlrtRTEI, sp, mCeq);
  obj->f_2 = 0.0;
  obj->cEq_2.set_size(&ur_emlrtRTEI, sp, mCeq);
  obj->nVar = nVar;
  obj->mIneq = 0;
  obj->mEq = mCeq;
  obj->numEvals = 0;
  obj->SpecifyObjectiveGradient = false;
  obj->SpecifyConstraintGradient = false;
  obj->isEmptyNonlcon = (mCeq == 0);
  obj->hasLB.set_size(&ur_emlrtRTEI, sp, nVar);
  obj->hasUB.set_size(&ur_emlrtRTEI, sp, nVar);
  b_bool = false;
  idx = 0;
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (idx < 7) {
      if (cv3[static_cast<uint8_T>(options_FiniteDifferenceType[idx])] !=
          cv3[static_cast<int32_T>(b_cv[idx])]) {
        exitg1 = 1;
      } else {
        idx++;
      }
    } else {
      b_bool = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  obj->FiniteDifferenceType = !b_bool;
  st.site = &pab_emlrtRSI;
  for (idx = 1; idx <= nVar; idx++) {
    if ((idx < 1) || (idx > obj->hasLB.size(0))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, obj->hasLB.size(0), &mt_emlrtBCI,
                                    &st);
    }
    obj->hasLB[idx - 1] = false;
    if (idx > obj->hasUB.size(0)) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, obj->hasUB.size(0), &mt_emlrtBCI,
                                    &st);
    }
    obj->hasUB[idx - 1] = false;
  }
  obj->hasBounds = false;
}

} // namespace FiniteDifferences
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace Codegen

// End of code generation (factoryConstruct.cpp)
