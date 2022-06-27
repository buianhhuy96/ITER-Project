//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: test_exit.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef TEST_EXIT_H
#define TEST_EXIT_H

// Include Files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct b_struct_T;

struct p_struct_T;

struct j_struct_T;

struct i_struct_T;

struct struct_T;

struct c_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
void b_test_exit(c_struct_T *Flags, b_struct_T *memspace,
                 p_struct_T *MeritFunction, j_struct_T *WorkingSet,
                 i_struct_T *TrialState, struct_T *b_QRManager);

void test_exit(b_struct_T *memspace, p_struct_T *MeritFunction,
               j_struct_T *WorkingSet, i_struct_T *TrialState,
               struct_T *b_QRManager, bool *Flags_gradOK, bool *Flags_fevalOK,
               bool *Flags_done, bool *Flags_stepAccepted,
               bool *Flags_failedLineSearch, int *Flags_stepType);

} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

#endif
//
// File trailer for test_exit.h
//
// [EOF]
//
