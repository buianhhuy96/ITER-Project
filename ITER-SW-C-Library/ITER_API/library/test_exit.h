//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: test_exit.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef TEST_EXIT_H
#define TEST_EXIT_H

// Include Files
#include "rtwtypes.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace ITER {
struct b_struct_T;

struct u_struct_T;

struct o_struct_T;

struct m_struct_T;

struct struct_T;

struct c_struct_T;

} // namespace ITER

// Function Declarations
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
void b_test_exit(c_struct_T *Flags, b_struct_T *memspace,
                 u_struct_T *MeritFunction, o_struct_T *WorkingSet,
                 m_struct_T *TrialState, struct_T *b_QRManager);

void test_exit(b_struct_T *memspace, u_struct_T *MeritFunction,
               o_struct_T *WorkingSet, m_struct_T *TrialState,
               struct_T *b_QRManager, bool *Flags_gradOK, bool *Flags_fevalOK,
               bool *Flags_done, bool *Flags_stepAccepted,
               bool *Flags_failedLineSearch, int *Flags_stepType);

} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for test_exit.h
//
// [EOF]
//
