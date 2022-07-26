//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: unique.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef UNIQUE_H
#define UNIQUE_H

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
void unique_vector(const ::coder::array<double, 1U> &b_a,
                   ::coder::array<double, 1U> &b);

}
} // namespace ITER

#endif
//
// File trailer for unique.h
//
// [EOF]
//
