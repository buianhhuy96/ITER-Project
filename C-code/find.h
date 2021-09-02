//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: find.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

#ifndef FIND_H
#define FIND_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void eml_find(const ::coder::array<double, 1U> &x, ::coder::array<int, 1U> &i);

void eml_find(const ::coder::array<double, 2U> &x, ::coder::array<int, 2U> &i);

} // namespace coder

#endif
//
// File trailer for find.h
//
// [EOF]
//
