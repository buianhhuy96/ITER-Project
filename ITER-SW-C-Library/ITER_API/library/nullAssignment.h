//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: nullAssignment.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 18-Jul-2022 16:59:00
//

#ifndef NULLASSIGNMENT_H
#define NULLASSIGNMENT_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace ITER {
namespace coder {
namespace internal {
void nullAssignment(::coder::array<double, 2U> &b_x,
                    const ::coder::array<int, 1U> &idx);

}
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for nullAssignment.h
//
// [EOF]
//
