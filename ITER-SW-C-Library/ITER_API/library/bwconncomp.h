//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bwconncomp.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef BWCONNCOMP_H
#define BWCONNCOMP_H

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
void bwconncomp(const ::coder::array<bool, 2U> &varargin_1,
                double *CC_Connectivity, double CC_ImageSize[2],
                double *CC_NumObjects,
                ::coder::array<double, 1U> &CC_RegionIndices,
                ::coder::array<int, 1U> &CC_RegionLengths);

}
} // namespace ITER

#endif
//
// File trailer for bwconncomp.h
//
// [EOF]
//
