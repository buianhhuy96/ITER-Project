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
#include "calibrateOneCamera_mex_data.h"
#include "calibrateOneCamera_mex_internal_types.h"
#include "computeFiniteDifferences.h"
#include "rt_nonfinite.h"
#include "validateattributes.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo qab_emlrtRSI{
    1,                          // lineNo
    "jacobianFiniteDifference", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\jacobianFiniteDifference.p" // pathName
};

static emlrtBCInfo pv_emlrtBCI{
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

static emlrtECInfo ce_emlrtECI{
    -1,                         // nDims
    1,                          // lineNo
    1,                          // colNo
    "jacobianFiniteDifference", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\jacobianFiniteDifference.p" // pName
};

static emlrtRTEInfo ws_emlrtRTEI{
    1,                          // lineNo
    1,                          // colNo
    "jacobianFiniteDifference", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\jacobianFiniteDifference.p" // pName
};

// Function Definitions
namespace Codegen {
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
    const e_struct_T *FiniteDifferences,
    const ::coder::array<real_T, 1U> &runTimeOptions_TypicalX,
    const ::coder::array<real_T, 1U> &c_runTimeOptions_FiniteDifferen)
{
  static const char_T b_cv[7]{'f', 'o', 'r', 'w', 'a', 'r', 'd'};
  static const char_T b_cv1[7]{'c', 'e', 'n', 't', 'r', 'a', 'l'};
  ::coder::array<real_T, 2U> JacCeqTrans;
  ::coder::array<real_T, 1U> a__3;
  e_struct_T b_FiniteDifferences;
  emlrtStack st;
  int32_T b_JacCeqTrans[2];
  int32_T t1_f2[2];
  int32_T exitg1;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  boolean_T b_bool;
  boolean_T evalOK;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  t1_f2[0] = fCurrent.size(0) + x.size(0);
  t1_f2[1] = x.size(0);
  st.site = &qab_emlrtRSI;
  validateattributes(&st, augJacobian, t1_f2);
  t1_f2[0] = x.size(0);
  t1_f2[1] = 1;
  st.site = &qab_emlrtRSI;
  validateattributes(&st, TypicalX, t1_f2);
  JacCeqTrans.set_size(&ws_emlrtRTEI, sp, x.size(0), fCurrent.size(0));
  a__3.set_size(&ws_emlrtRTEI, sp, x.size(0));
  loop_ub = x.size(0);
  for (i = 0; i < loop_ub; i++) {
    a__3[i] = x[i];
  }
  b_FiniteDifferences = *FiniteDifferences;
  st.site = &qab_emlrtRSI;
  evalOK = utils::FiniteDifferences::computeFiniteDifferences(
      &st, &b_FiniteDifferences, fCurrent, a__3, JacCeqTrans, x.size(0),
      runTimeOptions_TypicalX, c_runTimeOptions_FiniteDifferen);
  b_bool = false;
  loop_ub = 0;
  do {
    exitg1 = 0;
    if (loop_ub < 7) {
      if (cv3[static_cast<uint8_T>(options_FiniteDifferenceType[loop_ub])] !=
          cv3[static_cast<int32_T>(b_cv[loop_ub])]) {
        exitg1 = 1;
      } else {
        loop_ub++;
      }
    } else {
      b_bool = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  if (b_bool) {
    *funcCount += b_FiniteDifferences.numEvals;
  } else {
    b_bool = false;
    loop_ub = 0;
    do {
      exitg1 = 0;
      if (loop_ub < 7) {
        if (cv3[static_cast<uint8_T>(options_FiniteDifferenceType[loop_ub])] !=
            cv3[static_cast<int32_T>(b_cv1[loop_ub])]) {
          exitg1 = 1;
        } else {
          loop_ub++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
    if (b_bool) {
      *funcCount += b_FiniteDifferences.numEvals;
    }
  }
  if (1 > fCurrent.size(0)) {
    i1 = 0;
  } else {
    i = augJacobian.size(0);
    i1 = fCurrent.size(0);
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &pv_emlrtBCI, (emlrtCTX)sp);
    }
  }
  t1_f2[0] = i1;
  t1_f2[1] = augJacobian.size(1);
  b_JacCeqTrans[0] = JacCeqTrans.size(1);
  b_JacCeqTrans[1] = JacCeqTrans.size(0);
  emlrtSubAssignSizeCheckR2012b(&t1_f2[0], 2, &b_JacCeqTrans[0], 2,
                                &ce_emlrtECI, (emlrtCTX)sp);
  loop_ub = JacCeqTrans.size(0);
  for (i = 0; i < loop_ub; i++) {
    int32_T b_loop_ub;
    b_loop_ub = JacCeqTrans.size(1);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      augJacobian[i1 + augJacobian.size(0) * i] =
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
    const ::coder::array<real_T, 1U> &TypicalX, e_struct_T *FiniteDifferences,
    const ::coder::array<real_T, 1U> &runTimeOptions_TypicalX,
    const ::coder::array<real_T, 1U> &c_runTimeOptions_FiniteDifferen,
    int32_T *funcCount, boolean_T *evalOK)
{
  static const char_T b_cv[7]{'f', 'o', 'r', 'w', 'a', 'r', 'd'};
  static const char_T b_cv1[7]{'c', 'e', 'n', 't', 'r', 'a', 'l'};
  ::coder::array<real_T, 2U> JacCeqTrans;
  ::coder::array<real_T, 1U> a__3;
  emlrtStack st;
  int32_T b_JacCeqTrans[2];
  int32_T t5_f2[2];
  int32_T exitg1;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  boolean_T b_bool;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  *funcCount = 1;
  t5_f2[0] = fCurrent.size(0) + x.size(0);
  t5_f2[1] = x.size(0);
  st.site = &qab_emlrtRSI;
  validateattributes(&st, augJacobian, t5_f2);
  t5_f2[0] = x.size(0);
  t5_f2[1] = 1;
  st.site = &qab_emlrtRSI;
  validateattributes(&st, TypicalX, t5_f2);
  JacCeqTrans.set_size(&ws_emlrtRTEI, sp, x.size(0), fCurrent.size(0));
  a__3.set_size(&ws_emlrtRTEI, sp, x.size(0));
  loop_ub = x.size(0);
  for (i = 0; i < loop_ub; i++) {
    a__3[i] = x[i];
  }
  st.site = &qab_emlrtRSI;
  *evalOK = utils::FiniteDifferences::computeFiniteDifferences(
      &st, FiniteDifferences, fCurrent, a__3, JacCeqTrans, x.size(0),
      runTimeOptions_TypicalX, c_runTimeOptions_FiniteDifferen);
  b_bool = false;
  loop_ub = 0;
  do {
    exitg1 = 0;
    if (loop_ub < 7) {
      if (cv3[static_cast<uint8_T>(options_FiniteDifferenceType[loop_ub])] !=
          cv3[static_cast<int32_T>(b_cv[loop_ub])]) {
        exitg1 = 1;
      } else {
        loop_ub++;
      }
    } else {
      b_bool = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  if (b_bool) {
    *funcCount = FiniteDifferences->numEvals + 1;
  } else {
    b_bool = false;
    loop_ub = 0;
    do {
      exitg1 = 0;
      if (loop_ub < 7) {
        if (cv3[static_cast<uint8_T>(options_FiniteDifferenceType[loop_ub])] !=
            cv3[static_cast<int32_T>(b_cv1[loop_ub])]) {
          exitg1 = 1;
        } else {
          loop_ub++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
    if (b_bool) {
      *funcCount = FiniteDifferences->numEvals + 1;
    }
  }
  if (1 > fCurrent.size(0)) {
    i1 = 0;
  } else {
    i = augJacobian.size(0);
    i1 = fCurrent.size(0);
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &pv_emlrtBCI, (emlrtCTX)sp);
    }
  }
  t5_f2[0] = i1;
  t5_f2[1] = augJacobian.size(1);
  b_JacCeqTrans[0] = JacCeqTrans.size(1);
  b_JacCeqTrans[1] = JacCeqTrans.size(0);
  emlrtSubAssignSizeCheckR2012b(&t5_f2[0], 2, &b_JacCeqTrans[0], 2,
                                &ce_emlrtECI, (emlrtCTX)sp);
  loop_ub = JacCeqTrans.size(0);
  for (i = 0; i < loop_ub; i++) {
    int32_T b_loop_ub;
    b_loop_ub = JacCeqTrans.size(1);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      augJacobian[i1 + augJacobian.size(0) * i] =
          JacCeqTrans[i + JacCeqTrans.size(0) * i1];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace Codegen

// End of code generation (jacobianFiniteDifference.cpp)
