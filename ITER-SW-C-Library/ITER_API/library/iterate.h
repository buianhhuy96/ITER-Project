//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: iterate.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef ITERATE_H
#define ITERATE_H

// Include Files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct i_struct_T;

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
namespace qpactiveset {
void iterate(const double H[7][7], const double f[8], i_struct_T *solution,
             b_struct_T *memspace, j_struct_T *d_workingset,
             struct_T *c_qrmanager, s_struct_T *c_cholmanager,
             r_struct_T *b_objective, const char options_SolverName[7],
             double options_StepTolerance, double options_ConstraintTolerance,
             double options_ObjectiveLimit, double options_PricingTolerance,
             bool options_IterDisplayQP, const d_struct_T *runTimeOptions);

}
} // namespace coder
} // namespace optim
} // namespace coder

#endif
//
// File trailer for iterate.h
//
// [EOF]
//
