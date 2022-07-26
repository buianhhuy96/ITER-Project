//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: addBoundToActiveSetMatrix_.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef ADDBOUNDTOACTIVESETMATRIX__H
#define ADDBOUNDTOACTIVESETMATRIX__H

// Include Files
#include "rtwtypes.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace ITER {
struct o_struct_T;

}

// Function Declarations
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
void addBoundToActiveSetMatrix_(o_struct_T *obj, int TYPE, int idx_local);

}
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for addBoundToActiveSetMatrix_.h
//
// [EOF]
//
