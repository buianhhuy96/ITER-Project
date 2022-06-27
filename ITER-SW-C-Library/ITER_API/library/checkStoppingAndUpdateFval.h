//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: checkStoppingAndUpdateFval.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef CHECKSTOPPINGANDUPDATEFVAL_H
#define CHECKSTOPPINGANDUPDATEFVAL_H

// Include Files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct i_struct_T;

struct b_struct_T;

struct r_struct_T;

struct j_struct_T;

struct struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace stopping {
void checkStoppingAndUpdateFval(
    int *activeSetChangeID, const double f[8], i_struct_T *solution,
    b_struct_T *memspace, const r_struct_T *b_objective,
    const j_struct_T *d_workingset, struct_T *c_qrmanager,
    double options_ConstraintTolerance, double options_ObjectiveLimit,
    bool options_IterDisplayQP, int runTimeOptions_MaxIterations,
    double runTimeOptions_ConstrRelTolFactor, bool updateFval);

}
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

#endif
//
// File trailer for checkStoppingAndUpdateFval.h
//
// [EOF]
//
