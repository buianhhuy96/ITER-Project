//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: algbwmorph.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef ALGBWMORPH_H
#define ALGBWMORPH_H

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
namespace images {
namespace internal {
void bwmorphApplyOnce(::coder::array<bool, 2U> &b_bw);

}
} // namespace images
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for algbwmorph.h
//
// [EOF]
//
