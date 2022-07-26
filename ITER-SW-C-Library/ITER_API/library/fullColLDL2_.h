//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fullColLDL2_.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef FULLCOLLDL2__H
#define FULLCOLLDL2__H

// Include Files
#include "rtwtypes.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace ITER {
struct y_struct_T;

}

// Function Declarations
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace DynamicRegCholManager {
void fullColLDL2_(y_struct_T *obj, int NColsRemain, double REG_PRIMAL);

}
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for fullColLDL2_.h
//
// [EOF]
//
