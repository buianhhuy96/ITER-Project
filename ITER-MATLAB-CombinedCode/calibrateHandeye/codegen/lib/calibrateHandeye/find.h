//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: find.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
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
void b_eml_find(const ::coder::array<double, 2U> &b_x,
                ::coder::array<int, 2U> &b_i);

void eml_find(const ::coder::array<double, 1U> &b_x,
              ::coder::array<int, 1U> &b_i);

} // namespace coder

#endif
//
// File trailer for find.h
//
// [EOF]
//
