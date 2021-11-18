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
#include "calibrateOneCamera_v2_data.h"
#include "calibrateOneCamera_v2_internal_types.h"
#include "hasFiniteBounds.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo oeb_emlrtRSI{
    1,                  // lineNo
    "factoryConstruct", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\factoryConstruct.p" // pathName
};

static emlrtDCInfo xg_emlrtDCI{
    1,                  // lineNo
    1,                  // colNo
    "factoryConstruct", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\factoryConstruct.p", // pName
    4                                        // checkKind
};

static emlrtRTEInfo wu_emlrtRTEI{
    1,                  // lineNo
    1,                  // colNo
    "factoryConstruct", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "FiniteDifferences\\factoryConstruct.p" // pName
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
void factoryConstruct(const emlrtStack *sp, const b_anonymous_function *nonlin,
                      int32_T nVar, int32_T mCeq,
                      const char_T options_FiniteDifferenceType[7],
                      d_struct_T *obj)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  obj->nonlin = *nonlin;
  obj->f_1 = 0.0;
  if (mCeq < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(mCeq), &xg_emlrtDCI,
                                (emlrtCTX)sp);
  }
  obj->cEq_1.set_size(&wu_emlrtRTEI, sp, mCeq);
  obj->f_2 = 0.0;
  obj->cEq_2.set_size(&wu_emlrtRTEI, sp, mCeq);
  obj->nVar = nVar;
  obj->mIneq = 0;
  obj->mEq = mCeq;
  obj->numEvals = 0;
  obj->SpecifyObjectiveGradient = false;
  obj->SpecifyConstraintGradient = false;
  obj->isEmptyNonlcon = (mCeq == 0);
  if (nVar < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(nVar), &xg_emlrtDCI,
                                (emlrtCTX)sp);
  }
  obj->hasLB.set_size(&wu_emlrtRTEI, sp, nVar);
  obj->hasUB.set_size(&wu_emlrtRTEI, sp, nVar);
  st.site = &oeb_emlrtRSI;
  if (::coder::internal::b_strcmp(&st, options_FiniteDifferenceType)) {
    obj->FiniteDifferenceType = 0;
  } else {
    obj->FiniteDifferenceType = 1;
  }
  st.site = &oeb_emlrtRSI;
  obj->hasBounds = hasFiniteBounds(&st, nVar, obj->hasLB, obj->hasUB);
}

} // namespace FiniteDifferences
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (factoryConstruct.cpp)
