//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: step.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef STEP_H
#define STEP_H

// Include Files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct i_struct_T;

struct p_struct_T;

struct b_struct_T;

struct j_struct_T;

struct struct_T;

struct s_struct_T;

struct r_struct_T;

struct d_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
bool b_step(int *b_STEP_TYPE, double Hessian[7][7], i_struct_T *TrialState,
            p_struct_T *MeritFunction, b_struct_T *memspace,
            j_struct_T *WorkingSet, struct_T *b_QRManager,
            s_struct_T *b_CholManager, r_struct_T *QPObjective,
            d_struct_T *qpoptions);

}
} // namespace coder
} // namespace optim
} // namespace coder

#endif
//
// File trailer for step.h
//
// [EOF]
//
