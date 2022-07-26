//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: step.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef STEP_H
#define STEP_H

// Include Files
#include "rtwtypes.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace ITER {
struct m_struct_T;

struct u_struct_T;

struct b_struct_T;

struct o_struct_T;

struct struct_T;

struct y_struct_T;

struct x_struct_T;

struct e_struct_T;

} // namespace ITER

// Function Declarations
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
bool b_step(int *b_STEP_TYPE, double Hessian[7][7], m_struct_T *TrialState,
            u_struct_T *MeritFunction, b_struct_T *memspace,
            o_struct_T *WorkingSet, struct_T *b_QRManager,
            y_struct_T *b_CholManager, x_struct_T *QPObjective,
            e_struct_T *qpoptions);

}
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for step.h
//
// [EOF]
//
