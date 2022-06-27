//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: jacobianFiniteDifference.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "jacobianFiniteDifference.h"
#include "ITER_API_data.h"
#include "ITER_API_internal_types.h"
#include "computeFiniteDifferences.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : ::coder::array<double, 2U> &augJacobian
//                const ::coder::array<double, 1U> &fCurrent
//                int *funcCount
//                const ::coder::array<double, 1U> &b_x
//                const ::coder::array<double, 1U> &lb
//                const ::coder::array<double, 1U> &ub
//                const char options_FiniteDifferenceType[7]
//                const t_struct_T *FiniteDifferences
//                const ::coder::array<double, 1U> &runTimeOptions_TypicalX
//                const ::coder::array<double, 1U>
//                &runTimeOptions_FiniteDifferenceStepSize
// Return Type  : bool
//
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
bool b_jacobianFiniteDifference(
    ::coder::array<double, 2U> &augJacobian,
    const ::coder::array<double, 1U> &fCurrent, int *funcCount,
    const ::coder::array<double, 1U> &b_x, const ::coder::array<double, 1U> &lb,
    const ::coder::array<double, 1U> &ub,
    const char options_FiniteDifferenceType[7],
    const t_struct_T *FiniteDifferences,
    const ::coder::array<double, 1U> &runTimeOptions_TypicalX,
    const ::coder::array<double, 1U> &runTimeOptions_FiniteDifferenceStepSize)
{
  static const char b_cv[7]{'f', 'o', 'r', 'w', 'a', 'r', 'd'};
  static const char cv1[7]{'c', 'e', 'n', 't', 'r', 'a', 'l'};
  array<double, 2U> JacCeqTrans;
  array<double, 1U> a__3;
  t_struct_T b_FiniteDifferences;
  int b_loop_ub;
  int c_loop_ub;
  int exitg1;
  int i2;
  int kstr;
  int loop_ub;
  bool b_bool;
  bool evalOK;
  JacCeqTrans.set_size(b_x.size(0), fCurrent.size(0));
  a__3.set_size(b_x.size(0));
  loop_ub = b_x.size(0);
  if ((static_cast<int>(b_x.size(0) < 4)) != 0) {
    for (int b_i{0}; b_i < loop_ub; b_i++) {
      a__3[b_i] = b_x[b_i];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i = 0; b_i < loop_ub; b_i++) {
      a__3[b_i] = b_x[b_i];
    }
  }
  b_FiniteDifferences = *FiniteDifferences;
  evalOK = utils::FiniteDifferences::computeFiniteDifferences(
      &b_FiniteDifferences, fCurrent, a__3, JacCeqTrans, b_x.size(0), lb, ub,
      runTimeOptions_TypicalX, runTimeOptions_FiniteDifferenceStepSize);
  b_bool = false;
  kstr = 0;
  do {
    exitg1 = 0;
    if (kstr < 7) {
      if (cv[(static_cast<unsigned char>(options_FiniteDifferenceType[kstr])) &
             (static_cast<unsigned char>(127))] !=
          cv[static_cast<int>(b_cv[kstr])]) {
        exitg1 = 1;
      } else {
        kstr++;
      }
    } else {
      b_bool = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  if (b_bool) {
    *funcCount += b_FiniteDifferences.numEvals;
  } else {
    int b_kstr;
    bool c_bool;
    c_bool = false;
    b_kstr = 0;
    do {
      exitg1 = 0;
      if (b_kstr < 7) {
        if (cv[(static_cast<unsigned char>(
                   options_FiniteDifferenceType[b_kstr])) &
               (static_cast<unsigned char>(127))] !=
            cv[static_cast<int>(cv1[b_kstr])]) {
          exitg1 = 1;
        } else {
          b_kstr++;
        }
      } else {
        c_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
    if (c_bool) {
      *funcCount += b_FiniteDifferences.numEvals;
    }
  }
  b_loop_ub = JacCeqTrans.size(0);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i2,        \
                                                                    c_loop_ub)

  for (int i1 = 0; i1 < b_loop_ub; i1++) {
    c_loop_ub = JacCeqTrans.size(1);
    for (i2 = 0; i2 < c_loop_ub; i2++) {
      augJacobian[i2 + (augJacobian.size(0) * i1)] =
          JacCeqTrans[i1 + (JacCeqTrans.size(0) * i2)];
    }
  }
  return evalOK;
}

//
// Arguments    : ::coder::array<double, 2U> &augJacobian
//                const ::coder::array<double, 1U> &fCurrent
//                const ::coder::array<double, 1U> &b_x
//                const ::coder::array<double, 1U> &lb
//                const ::coder::array<double, 1U> &ub
//                const char options_FiniteDifferenceType[7]
//                t_struct_T *FiniteDifferences
//                const ::coder::array<double, 1U> &runTimeOptions_TypicalX
//                const ::coder::array<double, 1U>
//                &runTimeOptions_FiniteDifferenceStepSize int *funcCount bool
//                *evalOK
// Return Type  : void
//
void jacobianFiniteDifference(
    ::coder::array<double, 2U> &augJacobian,
    const ::coder::array<double, 1U> &fCurrent,
    const ::coder::array<double, 1U> &b_x, const ::coder::array<double, 1U> &lb,
    const ::coder::array<double, 1U> &ub,
    const char options_FiniteDifferenceType[7], t_struct_T *FiniteDifferences,
    const ::coder::array<double, 1U> &runTimeOptions_TypicalX,
    const ::coder::array<double, 1U> &runTimeOptions_FiniteDifferenceStepSize,
    int *funcCount, bool *evalOK)
{
  static const char b_cv[7]{'f', 'o', 'r', 'w', 'a', 'r', 'd'};
  static const char cv1[7]{'c', 'e', 'n', 't', 'r', 'a', 'l'};
  array<double, 2U> JacCeqTrans;
  array<double, 1U> a__3;
  int b_loop_ub;
  int c_loop_ub;
  int exitg1;
  int i2;
  int kstr;
  int loop_ub;
  bool b_bool;
  *funcCount = 1;
  JacCeqTrans.set_size(b_x.size(0), fCurrent.size(0));
  a__3.set_size(b_x.size(0));
  loop_ub = b_x.size(0);
  if ((static_cast<int>(b_x.size(0) < 4)) != 0) {
    for (int b_i{0}; b_i < loop_ub; b_i++) {
      a__3[b_i] = b_x[b_i];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i = 0; b_i < loop_ub; b_i++) {
      a__3[b_i] = b_x[b_i];
    }
  }
  *evalOK = utils::FiniteDifferences::computeFiniteDifferences(
      FiniteDifferences, fCurrent, a__3, JacCeqTrans, b_x.size(0), lb, ub,
      runTimeOptions_TypicalX, runTimeOptions_FiniteDifferenceStepSize);
  b_bool = false;
  kstr = 0;
  do {
    exitg1 = 0;
    if (kstr < 7) {
      if (cv[(static_cast<unsigned char>(options_FiniteDifferenceType[kstr])) &
             (static_cast<unsigned char>(127))] !=
          cv[static_cast<int>(b_cv[kstr])]) {
        exitg1 = 1;
      } else {
        kstr++;
      }
    } else {
      b_bool = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  if (b_bool) {
    *funcCount = FiniteDifferences->numEvals + 1;
  } else {
    int b_kstr;
    bool c_bool;
    c_bool = false;
    b_kstr = 0;
    do {
      exitg1 = 0;
      if (b_kstr < 7) {
        if (cv[(static_cast<unsigned char>(
                   options_FiniteDifferenceType[b_kstr])) &
               (static_cast<unsigned char>(127))] !=
            cv[static_cast<int>(cv1[b_kstr])]) {
          exitg1 = 1;
        } else {
          b_kstr++;
        }
      } else {
        c_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
    if (c_bool) {
      *funcCount = FiniteDifferences->numEvals + 1;
    }
  }
  b_loop_ub = JacCeqTrans.size(0);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i2,        \
                                                                    c_loop_ub)

  for (int i1 = 0; i1 < b_loop_ub; i1++) {
    c_loop_ub = JacCeqTrans.size(1);
    for (i2 = 0; i2 < c_loop_ub; i2++) {
      augJacobian[i2 + (augJacobian.size(0) * i1)] =
          JacCeqTrans[i1 + (JacCeqTrans.size(0) * i2)];
    }
  }
}

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for jacobianFiniteDifference.cpp
//
// [EOF]
//
