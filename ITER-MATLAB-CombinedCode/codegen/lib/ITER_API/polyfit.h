//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: polyfit.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

#ifndef POLYFIT_H
#define POLYFIT_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void b_polyfit(const ::coder::array<double, 2U> &b_x,
               const ::coder::array<double, 2U> &y, double h_n,
               ::coder::array<double, 2U> &p);

void polyfit(const ::coder::array<double, 1U> &b_x,
             const ::coder::array<double, 1U> &y, double h_n,
             ::coder::array<double, 2U> &p);

} // namespace coder

#endif
//
// File trailer for polyfit.h
//
// [EOF]
//
