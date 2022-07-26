//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: driver1.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef DRIVER1_H
#define DRIVER1_H

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
namespace qpactiveset {
void driver(const double H[7][7], const double f[8], m_struct_T *solution,
            b_struct_T *memspace, o_struct_T *d_workingset,
            struct_T *c_qrmanager, y_struct_T *c_cholmanager,
            x_struct_T *b_objective, const e_struct_T *options,
            e_struct_T *runTimeOptions);

}
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for driver1.h
//
// [EOF]
//
