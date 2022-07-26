//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ismember.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef ISMEMBER_H
#define ISMEMBER_H

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
void b_local_ismember(const double b_a[2], const double s[2], bool tf[2],
                      int loc[2]);

void local_ismember(const ::coder::array<double, 2U> &b_a,
                    const ::coder::array<double, 2U> &s,
                    ::coder::array<bool, 2U> &tf);

} // namespace coder
} // namespace ITER

#endif
//
// File trailer for ismember.h
//
// [EOF]
//
