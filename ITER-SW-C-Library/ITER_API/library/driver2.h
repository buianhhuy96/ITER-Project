//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: driver2.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef DRIVER2_H
#define DRIVER2_H

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

struct q_struct_T;

struct t_struct_T;

struct b_struct_T;

struct o_struct_T;

struct struct_T;

struct y_struct_T;

struct x_struct_T;

} // namespace ITER

// Function Declarations
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
void driver(m_struct_T *TrialState, u_struct_T *MeritFunction,
            const q_struct_T *FcnEvaluator, t_struct_T *FiniteDifferences,
            b_struct_T *memspace, o_struct_T *WorkingSet, double Hessian[7][7],
            struct_T *b_QRManager, y_struct_T *b_CholManager,
            x_struct_T *QPObjective);

}
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for driver2.h
//
// [EOF]
//
