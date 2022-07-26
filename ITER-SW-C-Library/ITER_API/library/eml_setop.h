//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: eml_setop.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef EML_SETOP_H
#define EML_SETOP_H

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
void b_do_vectors(const ::coder::array<double, 2U> &b_a,
                  const ::coder::array<double, 2U> &b,
                  ::coder::array<double, 2U> &c, ::coder::array<int, 1U> &ia,
                  ::coder::array<int, 1U> &c_ib);

void do_rows(const ::coder::array<int, 2U> &b_a,
             const ::coder::array<int, 2U> &b, ::coder::array<int, 2U> &c,
             ::coder::array<int, 1U> &ia, ::coder::array<int, 1U> &c_ib);

void do_vectors(const ::coder::array<double, 2U> &b_a,
                const ::coder::array<double, 1U> &b,
                ::coder::array<double, 2U> &c, ::coder::array<int, 1U> &ia,
                ::coder::array<int, 1U> &c_ib);

} // namespace coder
} // namespace ITER

#endif
//
// File trailer for eml_setop.h
//
// [EOF]
//
