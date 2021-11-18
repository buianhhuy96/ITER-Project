//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: find.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef FIND_H
#define FIND_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace Codegen {
namespace coder {
void b_eml_find(const ::coder::array<boolean_T, 2U> &b_x,
                ::coder::array<int32_T, 2U> &b_i);

void c_eml_find(const ::coder::array<real_T, 2U> &b_x,
                ::coder::array<int32_T, 2U> &b_i);

void eml_find(const ::coder::array<real_T, 1U> &b_x,
              ::coder::array<int32_T, 1U> &b_i);

} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for find.h
//
// [EOF]
//
