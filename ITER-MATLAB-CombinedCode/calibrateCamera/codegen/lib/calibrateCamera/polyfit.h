//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: polyfit.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef POLYFIT_H
#define POLYFIT_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace Codegen {
namespace coder {
void b_polyfit(const ::coder::array<real_T, 2U> &b_x,
               const ::coder::array<real_T, 2U> &y, real_T g_n, real_T p_data[],
               int32_T p_size[2]);

void polyfit(const ::coder::array<real_T, 1U> &b_x,
             const ::coder::array<real_T, 1U> &y, real_T g_n, real_T p_data[],
             int32_T p_size[2]);

} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for polyfit.h
//
// [EOF]
//
