//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: squareQ_appendCol.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef SQUAREQ_APPENDCOL_H
#define SQUAREQ_APPENDCOL_H

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
void squareQ_appendCol(struct_T *obj, const double vec[120], int iv0);

}
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for squareQ_appendCol.h
//
// [EOF]
//
