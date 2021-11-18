//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// jacobianFiniteDifference.cpp
//
// Code generation for function 'jacobianFiniteDifference'
//

// Include files
#include "jacobianFiniteDifference.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "calibrateOneCamera_v2_mex_internal_types.h"
#include "computeFiniteDifferences.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "validateattributes.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo veb_emlrtRSI{
    1,                          // lineNo
    "jacobianFiniteDifference", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\jacobianFiniteDifference.p" // pathName
};

static emlrtBCInfo yy_emlrtBCI{
    0,                          // iFirst
    MAX_int32_T,                // iLast
    1,                          // lineNo
    1,                          // colNo
    "",                         // aName
    "jacobianFiniteDifference", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\jacobianFiniteDifference.p", // pName
    0                                                 // checkKind
};

static emlrtBCInfo aab_emlrtBCI{
    -1,                         // iFirst
    -1,                         // iLast
    1,                          // lineNo
    1,                          // colNo
    "",                         // aName
    "jacobianFiniteDifference", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\jacobianFiniteDifference.p", // pName
    0                                                 // checkKind
};

static emlrtECInfo oe_emlrtECI{
    -1,                         // nDims
    1,                          // lineNo
    1,                          // colNo
    "jacobianFiniteDifference", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\jacobianFiniteDifference.p" // pName
};

static emlrtDCInfo oh_emlrtDCI{
    1,                          // lineNo
    1,                          // colNo
    "jacobianFiniteDifference", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\jacobianFiniteDifference.p", // pName
    4                                                 // checkKind
};

static emlrtRTEInfo pab_emlrtRTEI{
    1,                          // lineNo
    1,                          // colNo
    "jacobianFiniteDifference", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\jacobianFiniteDifference.p" // pName
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
boolean_T b_jacobianFiniteDifference(
    const emlrtStack *sp, ::coder::array<real_T, 2U> &augJacobian,
    const ::coder::array<real_T, 1U> &fCurrent, int32_T *funcCount,
    const ::coder::array<real_T, 1U> &x,
    const char_T options_FiniteDifferenceType[7],
    const ::coder::array<real_T, 1U> &TypicalX,
    const d_struct_T *FiniteDifferences,
    const ::coder::array<real_T, 1U> &runTimeOptions_TypicalX,
    const ::coder::array<real_T, 1U> &c_runTimeOptions_FiniteDifferen)
{
  array<real_T, 2U> JacCeqTrans;
  array<real_T, 1U> a__3;
  array<int32_T, 1U> r;
  array<int32_T, 1U> r1;
  d_struct_T b_FiniteDifferences;
  emlrtStack st;
  int32_T b_JacCeqTrans[2];
  int32_T t2_f2[2];
  int32_T i;
  int32_T loop_ub;
  boolean_T evalOK;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  i = fCurrent.size(0);
  if (i < 0) {
    emlrtDynamicBoundsCheckR2012b(i, 0, MAX_int32_T, &yy_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  t2_f2[0] = fCurrent.size(0) + x.size(0);
  t2_f2[1] = x.size(0);
  st.site = &veb_emlrtRSI;
  validateattributes(&st, augJacobian, t2_f2);
  t2_f2[0] = x.size(0);
  t2_f2[1] = 1;
  st.site = &veb_emlrtRSI;
  validateattributes(&st, TypicalX, t2_f2);
  JacCeqTrans.set_size(&pab_emlrtRTEI, sp, x.size(0), JacCeqTrans.size(1));
  i = fCurrent.size(0);
  if (i < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &oh_emlrtDCI,
                                (emlrtCTX)sp);
  }
  JacCeqTrans.set_size(&pab_emlrtRTEI, sp, JacCeqTrans.size(0), i);
  a__3.set_size(&pab_emlrtRTEI, sp, x.size(0));
  loop_ub = x.size(0);
  for (i = 0; i < loop_ub; i++) {
    a__3[i] = x[i];
  }
  b_FiniteDifferences = *FiniteDifferences;
  st.site = &veb_emlrtRSI;
  evalOK = utils::FiniteDifferences::computeFiniteDifferences(
      &st, &b_FiniteDifferences, fCurrent, a__3, JacCeqTrans, x.size(0),
      runTimeOptions_TypicalX, c_runTimeOptions_FiniteDifferen);
  st.site = &veb_emlrtRSI;
  if (internal::b_strcmp(&st, options_FiniteDifferenceType)) {
    *funcCount += b_FiniteDifferences.numEvals;
  } else {
    st.site = &veb_emlrtRSI;
    if (internal::c_strcmp(&st, options_FiniteDifferenceType)) {
      *funcCount += b_FiniteDifferences.numEvals;
    }
  }
  if (1 > fCurrent.size(0)) {
    loop_ub = 0;
  } else {
    i = augJacobian.size(0);
    if (1 > i) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i, &aab_emlrtBCI, (emlrtCTX)sp);
    }
    i = augJacobian.size(0);
    loop_ub = fCurrent.size(0);
    if ((loop_ub < 1) || (loop_ub > i)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i, &aab_emlrtBCI, (emlrtCTX)sp);
    }
  }
  r.set_size(&pab_emlrtRTEI, sp, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r[i] = i;
  }
  loop_ub = augJacobian.size(1);
  r1.set_size(&pab_emlrtRTEI, sp, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r1[i] = i;
  }
  t2_f2[0] = r.size(0);
  t2_f2[1] = r1.size(0);
  b_JacCeqTrans[0] = JacCeqTrans.size(1);
  b_JacCeqTrans[1] = JacCeqTrans.size(0);
  emlrtSubAssignSizeCheckR2012b(&t2_f2[0], 2, &b_JacCeqTrans[0], 2,
                                &oe_emlrtECI, (emlrtCTX)sp);
  loop_ub = JacCeqTrans.size(0);
  for (i = 0; i < loop_ub; i++) {
    int32_T b_loop_ub;
    b_loop_ub = JacCeqTrans.size(1);
    for (int32_T i1{0}; i1 < b_loop_ub; i1++) {
      augJacobian[r[i1] + augJacobian.size(0) * r1[i]] =
          JacCeqTrans[i + JacCeqTrans.size(0) * i1];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return evalOK;
}

void jacobianFiniteDifference(
    const emlrtStack *sp, ::coder::array<real_T, 2U> &augJacobian,
    const ::coder::array<real_T, 1U> &fCurrent,
    const ::coder::array<real_T, 1U> &x,
    const char_T options_FiniteDifferenceType[7],
    const ::coder::array<real_T, 1U> &TypicalX, d_struct_T *FiniteDifferences,
    const ::coder::array<real_T, 1U> &runTimeOptions_TypicalX,
    const ::coder::array<real_T, 1U> &c_runTimeOptions_FiniteDifferen,
    int32_T *funcCount, boolean_T *evalOK)
{
  array<real_T, 2U> JacCeqTrans;
  array<real_T, 1U> a__3;
  array<int32_T, 1U> r;
  array<int32_T, 1U> r1;
  emlrtStack st;
  int32_T b_JacCeqTrans[2];
  int32_T t6_f2[2];
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  *funcCount = 1;
  i = fCurrent.size(0);
  if (i < 0) {
    emlrtDynamicBoundsCheckR2012b(i, 0, MAX_int32_T, &yy_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  t6_f2[0] = fCurrent.size(0) + x.size(0);
  t6_f2[1] = x.size(0);
  st.site = &veb_emlrtRSI;
  validateattributes(&st, augJacobian, t6_f2);
  t6_f2[0] = x.size(0);
  t6_f2[1] = 1;
  st.site = &veb_emlrtRSI;
  validateattributes(&st, TypicalX, t6_f2);
  JacCeqTrans.set_size(&pab_emlrtRTEI, sp, x.size(0), JacCeqTrans.size(1));
  i = fCurrent.size(0);
  if (i < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &oh_emlrtDCI,
                                (emlrtCTX)sp);
  }
  JacCeqTrans.set_size(&pab_emlrtRTEI, sp, JacCeqTrans.size(0), i);
  a__3.set_size(&pab_emlrtRTEI, sp, x.size(0));
  loop_ub = x.size(0);
  for (i = 0; i < loop_ub; i++) {
    a__3[i] = x[i];
  }
  st.site = &veb_emlrtRSI;
  *evalOK = utils::FiniteDifferences::computeFiniteDifferences(
      &st, FiniteDifferences, fCurrent, a__3, JacCeqTrans, x.size(0),
      runTimeOptions_TypicalX, c_runTimeOptions_FiniteDifferen);
  st.site = &veb_emlrtRSI;
  if (internal::b_strcmp(&st, options_FiniteDifferenceType)) {
    *funcCount = FiniteDifferences->numEvals + 1;
  } else {
    st.site = &veb_emlrtRSI;
    if (internal::c_strcmp(&st, options_FiniteDifferenceType)) {
      *funcCount = FiniteDifferences->numEvals + 1;
    }
  }
  if (1 > fCurrent.size(0)) {
    loop_ub = 0;
  } else {
    i = augJacobian.size(0);
    if (1 > i) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i, &aab_emlrtBCI, (emlrtCTX)sp);
    }
    i = augJacobian.size(0);
    loop_ub = fCurrent.size(0);
    if ((loop_ub < 1) || (loop_ub > i)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i, &aab_emlrtBCI, (emlrtCTX)sp);
    }
  }
  r.set_size(&pab_emlrtRTEI, sp, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r[i] = i;
  }
  loop_ub = augJacobian.size(1);
  r1.set_size(&pab_emlrtRTEI, sp, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r1[i] = i;
  }
  t6_f2[0] = r.size(0);
  t6_f2[1] = r1.size(0);
  b_JacCeqTrans[0] = JacCeqTrans.size(1);
  b_JacCeqTrans[1] = JacCeqTrans.size(0);
  emlrtSubAssignSizeCheckR2012b(&t6_f2[0], 2, &b_JacCeqTrans[0], 2,
                                &oe_emlrtECI, (emlrtCTX)sp);
  loop_ub = JacCeqTrans.size(0);
  for (i = 0; i < loop_ub; i++) {
    int32_T b_loop_ub;
    b_loop_ub = JacCeqTrans.size(1);
    for (int32_T i1{0}; i1 < b_loop_ub; i1++) {
      augJacobian[r[i1] + augJacobian.size(0) * r1[i]] =
          JacCeqTrans[i + JacCeqTrans.size(0) * i1];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (jacobianFiniteDifference.cpp)
