//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: deleteColMoveEnd.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef DELETECOLMOVEEND_H
#define DELETECOLMOVEEND_H

// Include Files
#include "rtwtypes.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace ITER {
struct struct_T;

}

// Function Declarations
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace QRManager {
void deleteColMoveEnd(struct_T *obj, int idx);

}
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for deleteColMoveEnd.h
//
// [EOF]
//
