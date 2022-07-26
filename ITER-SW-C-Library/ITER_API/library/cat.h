//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: cat.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef CAT_H
#define CAT_H

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
void cat(const ::coder::array<double, 2U> &varargin_1,
         const ::coder::array<double, 2U> &varargin_2,
         ::coder::array<double, 3U> &y);

}
} // namespace ITER

#endif
//
// File trailer for cat.h
//
// [EOF]
//
