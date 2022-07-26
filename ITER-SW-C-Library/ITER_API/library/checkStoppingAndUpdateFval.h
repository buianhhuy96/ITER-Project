//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: checkStoppingAndUpdateFval.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef CHECKSTOPPINGANDUPDATEFVAL_H
#define CHECKSTOPPINGANDUPDATEFVAL_H

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

struct b_struct_T;

struct x_struct_T;

struct o_struct_T;

struct struct_T;

} // namespace ITER

// Function Declarations
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace stopping {
void checkStoppingAndUpdateFval(
    int *activeSetChangeID, const double f[8], m_struct_T *solution,
    b_struct_T *memspace, const x_struct_T *b_objective,
    const o_struct_T *d_workingset, struct_T *c_qrmanager,
    double options_ConstraintTolerance, double options_ObjectiveLimit,
    bool options_IterDisplayQP, int runTimeOptions_MaxIterations,
    double runTimeOptions_ConstrRelTolFactor, bool updateFval);

}
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for checkStoppingAndUpdateFval.h
//
// [EOF]
//
