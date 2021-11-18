//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: eml_setop.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef EML_SETOP_H
#define EML_SETOP_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace Codegen {
namespace coder {
void b_do_vectors(const ::coder::array<real_T, 2U> &b_a,
                  const ::coder::array<real_T, 2U> &b,
                  ::coder::array<real_T, 2U> &c,
                  ::coder::array<int32_T, 1U> &ia, int32_T *ib_size);

void do_vectors(const ::coder::array<real_T, 2U> &b_a,
                const ::coder::array<real_T, 1U> &b,
                ::coder::array<real_T, 2U> &c, ::coder::array<int32_T, 1U> &ia,
                int32_T *ib_size);

} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for eml_setop.h
//
// [EOF]
//
