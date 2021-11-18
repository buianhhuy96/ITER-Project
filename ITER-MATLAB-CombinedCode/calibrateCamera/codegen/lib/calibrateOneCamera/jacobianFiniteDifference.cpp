//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: jacobianFiniteDifference.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "jacobianFiniteDifference.h"
#include "calibrateOneCamera_data.h"
#include "calibrateOneCamera_internal_types.h"
#include "computeFiniteDifferences.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : ::coder::array<double, 2U> &augJacobian
//                const ::coder::array<double, 1U> &fCurrent
//                int *funcCount
//                const ::coder::array<double, 1U> &b_x
//                const char options_FiniteDifferenceType[7]
//                const g_struct_T *FiniteDifferences
//                const ::coder::array<double, 1U> &runTimeOptions_TypicalX
//                const ::coder::array<double, 1U>
//                &runTimeOptions_FiniteDifferenceStepSize
// Return Type  : bool
//
namespace Codegen {
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
bool b_jacobianFiniteDifference(
    ::coder::array<double, 2U> &augJacobian,
    const ::coder::array<double, 1U> &fCurrent, int *funcCount,
    const ::coder::array<double, 1U> &b_x,
    const char options_FiniteDifferenceType[7],
    const g_struct_T *FiniteDifferences,
    const ::coder::array<double, 1U> &runTimeOptions_TypicalX,
    const ::coder::array<double, 1U> &runTimeOptions_FiniteDifferenceStepSize)
{
  static const char b_cv[7]{'f', 'o', 'r', 'w', 'a', 'r', 'd'};
  static const char b_cv1[7]{'c', 'e', 'n', 't', 'r', 'a', 'l'};
  ::coder::array<double, 2U> JacCeqTrans;
  ::coder::array<double, 1U> a__3;
  g_struct_T b_FiniteDifferences;
  int b_i;
  int exitg1;
  int loop_ub;
  bool b_bool;
  bool evalOK;
  JacCeqTrans.set_size(b_x.size(0), fCurrent.size(0));
  a__3.set_size(b_x.size(0));
  loop_ub = b_x.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    a__3[b_i] = b_x[b_i];
  }
  b_FiniteDifferences = *FiniteDifferences;
  evalOK = utils::FiniteDifferences::computeFiniteDifferences(
      &b_FiniteDifferences, fCurrent, a__3, JacCeqTrans, b_x.size(0),
      runTimeOptions_TypicalX, runTimeOptions_FiniteDifferenceStepSize);
  b_bool = false;
  loop_ub = 0;
  do {
    exitg1 = 0;
    if (loop_ub < 7) {
      if (cv[(static_cast<unsigned char>(
                 options_FiniteDifferenceType[loop_ub])) &
             (static_cast<unsigned char>(127))] !=
          cv[static_cast<int>(b_cv[loop_ub])]) {
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
        if (cv[(static_cast<unsigned char>(
                   options_FiniteDifferenceType[loop_ub])) &
               (static_cast<unsigned char>(127))] !=
            cv[static_cast<int>(b_cv1[loop_ub])]) {
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
  loop_ub = JacCeqTrans.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    int b_loop_ub;
    b_loop_ub = JacCeqTrans.size(1);
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      augJacobian[i1 + (augJacobian.size(0) * b_i)] =
          JacCeqTrans[b_i + (JacCeqTrans.size(0) * i1)];
    }
  }
  return evalOK;
}

//
// Arguments    : ::coder::array<double, 2U> &augJacobian
//                const ::coder::array<double, 1U> &fCurrent
//                const ::coder::array<double, 1U> &b_x
//                const char options_FiniteDifferenceType[7]
//                g_struct_T *FiniteDifferences
//                const ::coder::array<double, 1U> &runTimeOptions_TypicalX
//                const ::coder::array<double, 1U>
//                &runTimeOptions_FiniteDifferenceStepSize int *funcCount bool
//                *evalOK
// Return Type  : void
//
void jacobianFiniteDifference(
    ::coder::array<double, 2U> &augJacobian,
    const ::coder::array<double, 1U> &fCurrent,
    const ::coder::array<double, 1U> &b_x,
    const char options_FiniteDifferenceType[7], g_struct_T *FiniteDifferences,
    const ::coder::array<double, 1U> &runTimeOptions_TypicalX,
    const ::coder::array<double, 1U> &runTimeOptions_FiniteDifferenceStepSize,
    int *funcCount, bool *evalOK)
{
  static const char b_cv[7]{'f', 'o', 'r', 'w', 'a', 'r', 'd'};
  static const char b_cv1[7]{'c', 'e', 'n', 't', 'r', 'a', 'l'};
  ::coder::array<double, 2U> JacCeqTrans;
  ::coder::array<double, 1U> a__3;
  int b_i;
  int exitg1;
  int loop_ub;
  bool b_bool;
  *funcCount = 1;
  JacCeqTrans.set_size(b_x.size(0), fCurrent.size(0));
  a__3.set_size(b_x.size(0));
  loop_ub = b_x.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    a__3[b_i] = b_x[b_i];
  }
  *evalOK = utils::FiniteDifferences::computeFiniteDifferences(
      FiniteDifferences, fCurrent, a__3, JacCeqTrans, b_x.size(0),
      runTimeOptions_TypicalX, runTimeOptions_FiniteDifferenceStepSize);
  b_bool = false;
  loop_ub = 0;
  do {
    exitg1 = 0;
    if (loop_ub < 7) {
      if (cv[(static_cast<unsigned char>(
                 options_FiniteDifferenceType[loop_ub])) &
             (static_cast<unsigned char>(127))] !=
          cv[static_cast<int>(b_cv[loop_ub])]) {
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
        if (cv[(static_cast<unsigned char>(
                   options_FiniteDifferenceType[loop_ub])) &
               (static_cast<unsigned char>(127))] !=
            cv[static_cast<int>(b_cv1[loop_ub])]) {
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
  loop_ub = JacCeqTrans.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    int b_loop_ub;
    b_loop_ub = JacCeqTrans.size(1);
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      augJacobian[i1 + (augJacobian.size(0) * b_i)] =
          JacCeqTrans[b_i + (JacCeqTrans.size(0) * i1)];
    }
  }
}

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace Codegen

//
// File trailer for jacobianFiniteDifference.cpp
//
// [EOF]
//
