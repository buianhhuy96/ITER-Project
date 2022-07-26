//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: combineVectorElements.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef COMBINEVECTORELEMENTS_H
#define COMBINEVECTORELEMENTS_H

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
double b_combineVectorElements(const ::coder::array<double, 1U> &b_x);

double c_combineVectorElements(const ::coder::array<int, 1U> &b_x);

double combineVectorElements(const ::coder::array<double, 2U> &b_x);

double d_combineVectorElements(const ::coder::array<unsigned char, 1U> &b_x);

} // namespace coder
} // namespace ITER

#endif
//
// File trailer for combineVectorElements.h
//
// [EOF]
//
