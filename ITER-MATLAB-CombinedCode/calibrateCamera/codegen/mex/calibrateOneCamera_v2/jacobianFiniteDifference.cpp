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
#include "calibrateOneCamera_v2_data.h"
#include "calibrateOneCamera_v2_internal_types.h"
#include "computeFiniteDifferences.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "validateattributes.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo web_emlrtRSI{
    1,                          // lineNo
    "jacobianFiniteDifference", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\jacobianFiniteDifference.p" // pathName
};

static emlrtBCInfo ex_emlrtBCI{
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

static emlrtBCInfo fx_emlrtBCI{
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

static emlrtECInfo ee_emlrtECI{
    -1,                         // nDims
    1,                          // lineNo
    1,                          // colNo
    "jacobianFiniteDifference", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\jacobianFiniteDifference.p" // pName
};

static emlrtDCInfo hh_emlrtDCI{
    1,                          // lineNo
    1,                          // colNo
    "jacobianFiniteDifference", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\jacobianFiniteDifference.p", // pName
    4                                                 // checkKind
};

static emlrtRTEInfo ow_emlrtRTEI{
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
  int32_T t3_f2[2];
  int32_T i;
  int32_T loop_ub;
  boolean_T evalOK;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  i = fCurrent.size(0);
  if (i < 0) {
    emlrtDynamicBoundsCheckR2012b(i, 0, MAX_int32_T, &ex_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  t3_f2[0] = fCurrent.size(0) + x.size(0);
  t3_f2[1] = x.size(0);
  st.site = &web_emlrtRSI;
  validateattributes(&st, augJacobian, t3_f2);
  t3_f2[0] = x.size(0);
  t3_f2[1] = 1;
  st.site = &web_emlrtRSI;
  validateattributes(&st, TypicalX, t3_f2);
  JacCeqTrans.set_size(&ow_emlrtRTEI, sp, x.size(0), JacCeqTrans.size(1));
  i = fCurrent.size(0);
  if (i < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &hh_emlrtDCI,
                                (emlrtCTX)sp);
  }
  JacCeqTrans.set_size(&ow_emlrtRTEI, sp, JacCeqTrans.size(0), i);
  a__3.set_size(&ow_emlrtRTEI, sp, x.size(0));
  loop_ub = x.size(0);
  for (i = 0; i < loop_ub; i++) {
    a__3[i] = x[i];
  }
  b_FiniteDifferences = *FiniteDifferences;
  st.site = &web_emlrtRSI;
  evalOK = utils::FiniteDifferences::computeFiniteDifferences(
      &st, &b_FiniteDifferences, fCurrent, a__3, JacCeqTrans, x.size(0),
      runTimeOptions_TypicalX, c_runTimeOptions_FiniteDifferen);
  st.site = &web_emlrtRSI;
  if (internal::b_strcmp(&st, options_FiniteDifferenceType)) {
    *funcCount += b_FiniteDifferences.numEvals;
  } else {
    st.site = &web_emlrtRSI;
    if (internal::c_strcmp(&st, options_FiniteDifferenceType)) {
      *funcCount += b_FiniteDifferences.numEvals;
    }
  }
  if (1 > fCurrent.size(0)) {
    loop_ub = 0;
  } else {
    i = augJacobian.size(0);
    if (1 > i) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i, &fx_emlrtBCI, (emlrtCTX)sp);
    }
    i = augJacobian.size(0);
    loop_ub = fCurrent.size(0);
    if ((loop_ub < 1) || (loop_ub > i)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i, &fx_emlrtBCI, (emlrtCTX)sp);
    }
  }
  r.set_size(&ow_emlrtRTEI, sp, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r[i] = i;
  }
  loop_ub = augJacobian.size(1);
  r1.set_size(&ow_emlrtRTEI, sp, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r1[i] = i;
  }
  t3_f2[0] = r.size(0);
  t3_f2[1] = r1.size(0);
  b_JacCeqTrans[0] = JacCeqTrans.size(1);
  b_JacCeqTrans[1] = JacCeqTrans.size(0);
  emlrtSubAssignSizeCheckR2012b(&t3_f2[0], 2, &b_JacCeqTrans[0], 2,
                                &ee_emlrtECI, (emlrtCTX)sp);
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
  int32_T t7_f2[2];
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  *funcCount = 1;
  i = fCurrent.size(0);
  if (i < 0) {
    emlrtDynamicBoundsCheckR2012b(i, 0, MAX_int32_T, &ex_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  t7_f2[0] = fCurrent.size(0) + x.size(0);
  t7_f2[1] = x.size(0);
  st.site = &web_emlrtRSI;
  validateattributes(&st, augJacobian, t7_f2);
  t7_f2[0] = x.size(0);
  t7_f2[1] = 1;
  st.site = &web_emlrtRSI;
  validateattributes(&st, TypicalX, t7_f2);
  JacCeqTrans.set_size(&ow_emlrtRTEI, sp, x.size(0), JacCeqTrans.size(1));
  i = fCurrent.size(0);
  if (i < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &hh_emlrtDCI,
                                (emlrtCTX)sp);
  }
  JacCeqTrans.set_size(&ow_emlrtRTEI, sp, JacCeqTrans.size(0), i);
  a__3.set_size(&ow_emlrtRTEI, sp, x.size(0));
  loop_ub = x.size(0);
  for (i = 0; i < loop_ub; i++) {
    a__3[i] = x[i];
  }
  st.site = &web_emlrtRSI;
  *evalOK = utils::FiniteDifferences::computeFiniteDifferences(
      &st, FiniteDifferences, fCurrent, a__3, JacCeqTrans, x.size(0),
      runTimeOptions_TypicalX, c_runTimeOptions_FiniteDifferen);
  st.site = &web_emlrtRSI;
  if (internal::b_strcmp(&st, options_FiniteDifferenceType)) {
    *funcCount = FiniteDifferences->numEvals + 1;
  } else {
    st.site = &web_emlrtRSI;
    if (internal::c_strcmp(&st, options_FiniteDifferenceType)) {
      *funcCount = FiniteDifferences->numEvals + 1;
    }
  }
  if (1 > fCurrent.size(0)) {
    loop_ub = 0;
  } else {
    i = augJacobian.size(0);
    if (1 > i) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i, &fx_emlrtBCI, (emlrtCTX)sp);
    }
    i = augJacobian.size(0);
    loop_ub = fCurrent.size(0);
    if ((loop_ub < 1) || (loop_ub > i)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i, &fx_emlrtBCI, (emlrtCTX)sp);
    }
  }
  r.set_size(&ow_emlrtRTEI, sp, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r[i] = i;
  }
  loop_ub = augJacobian.size(1);
  r1.set_size(&ow_emlrtRTEI, sp, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r1[i] = i;
  }
  t7_f2[0] = r.size(0);
  t7_f2[1] = r1.size(0);
  b_JacCeqTrans[0] = JacCeqTrans.size(1);
  b_JacCeqTrans[1] = JacCeqTrans.size(0);
  emlrtSubAssignSizeCheckR2012b(&t7_f2[0], 2, &b_JacCeqTrans[0], 2,
                                &ee_emlrtECI, (emlrtCTX)sp);
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
