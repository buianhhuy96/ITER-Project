//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: horzcatStructList.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef HORZCATSTRUCTLIST_H
#define HORZCATSTRUCTLIST_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace ITER {
struct f_struct_T;

}

// Function Declarations
namespace ITER {
namespace coder {
namespace internal {
void horzcatStructList(const ::coder::array<f_struct_T, 1U> &structure,
                       ::coder::array<double, 2U> &result);

}
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for horzcatStructList.h
//
// [EOF]
//
