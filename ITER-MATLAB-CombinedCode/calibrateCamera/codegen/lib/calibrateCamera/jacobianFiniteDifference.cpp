//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: jacobianFiniteDifference.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "jacobianFiniteDifference.h"
#include "calibrateCamera_data.h"
#include "calibrateCamera_internal_types.h"
#include "computeFiniteDifferences.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : ::coder::array<real_T, 2U> &augJacobian
//                const ::coder::array<real_T, 1U> &fCurrent
//                int32_T *funcCount
//                const ::coder::array<real_T, 1U> &b_x
//                const char_T options_FiniteDifferenceType[7]
//                const c_struct_T *FiniteDifferences
// Return Type  : boolean_T
//
namespace Codegen {
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
boolean_T
b_jacobianFiniteDifference(::coder::array<real_T, 2U> &augJacobian,
                           const ::coder::array<real_T, 1U> &fCurrent,
                           int32_T *funcCount,
                           const ::coder::array<real_T, 1U> &b_x,
                           const char_T options_FiniteDifferenceType[7],
                           const c_struct_T *FiniteDifferences)
{
  static const char_T b_cv[7]{'f', 'o', 'r', 'w', 'a', 'r', 'd'};
  static const char_T cv1[7]{'c', 'e', 'n', 't', 'r', 'a', 'l'};
  ::coder::array<real_T, 2U> JacCeqTrans;
  ::coder::array<real_T, 1U> a__3;
  c_struct_T b_FiniteDifferences;
  int32_T b_i;
  int32_T exitg1;
  int32_T loop_ub;
  boolean_T b_bool;
  boolean_T evalOK;
  JacCeqTrans.set_size(b_x.size(0), fCurrent.size(0));
  a__3.set_size(b_x.size(0));
  loop_ub = b_x.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    a__3[b_i] = b_x[b_i];
  }
  b_FiniteDifferences = *FiniteDifferences;
  evalOK = utils::FiniteDifferences::computeFiniteDifferences(
      &b_FiniteDifferences, fCurrent, a__3, JacCeqTrans, b_x.size(0));
  b_bool = false;
  loop_ub = 0;
  do {
    exitg1 = 0;
    if (loop_ub < 7) {
      if (cv[static_cast<uint8_T>(options_FiniteDifferenceType[loop_ub])] !=
          cv[static_cast<int32_T>(b_cv[loop_ub])]) {
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
        if (cv[static_cast<uint8_T>(options_FiniteDifferenceType[loop_ub])] !=
            cv[static_cast<int32_T>(cv1[loop_ub])]) {
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
    int32_T b_loop_ub;
    b_loop_ub = JacCeqTrans.size(1);
    for (int32_T i1{0}; i1 < b_loop_ub; i1++) {
      augJacobian[i1 + (augJacobian.size(0) * b_i)] =
          JacCeqTrans[b_i + (JacCeqTrans.size(0) * i1)];
    }
  }
  return evalOK;
}

//
// Arguments    : ::coder::array<real_T, 2U> &augJacobian
//                const ::coder::array<real_T, 1U> &fCurrent
//                const ::coder::array<real_T, 1U> &b_x
//                const char_T options_FiniteDifferenceType[7]
//                c_struct_T *FiniteDifferences
//                int32_T *funcCount
//                boolean_T *evalOK
// Return Type  : void
//
void jacobianFiniteDifference(::coder::array<real_T, 2U> &augJacobian,
                              const ::coder::array<real_T, 1U> &fCurrent,
                              const ::coder::array<real_T, 1U> &b_x,
                              const char_T options_FiniteDifferenceType[7],
                              c_struct_T *FiniteDifferences, int32_T *funcCount,
                              boolean_T *evalOK)
{
  static const char_T b_cv[7]{'f', 'o', 'r', 'w', 'a', 'r', 'd'};
  static const char_T cv1[7]{'c', 'e', 'n', 't', 'r', 'a', 'l'};
  ::coder::array<real_T, 2U> JacCeqTrans;
  ::coder::array<real_T, 1U> a__3;
  int32_T b_i;
  int32_T exitg1;
  int32_T loop_ub;
  boolean_T b_bool;
  *funcCount = 1;
  JacCeqTrans.set_size(b_x.size(0), fCurrent.size(0));
  a__3.set_size(b_x.size(0));
  loop_ub = b_x.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    a__3[b_i] = b_x[b_i];
  }
  *evalOK = utils::FiniteDifferences::computeFiniteDifferences(
      FiniteDifferences, fCurrent, a__3, JacCeqTrans, b_x.size(0));
  b_bool = false;
  loop_ub = 0;
  do {
    exitg1 = 0;
    if (loop_ub < 7) {
      if (cv[static_cast<uint8_T>(options_FiniteDifferenceType[loop_ub])] !=
          cv[static_cast<int32_T>(b_cv[loop_ub])]) {
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
        if (cv[static_cast<uint8_T>(options_FiniteDifferenceType[loop_ub])] !=
            cv[static_cast<int32_T>(cv1[loop_ub])]) {
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
    int32_T b_loop_ub;
    b_loop_ub = JacCeqTrans.size(1);
    for (int32_T i1{0}; i1 < b_loop_ub; i1++) {
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
