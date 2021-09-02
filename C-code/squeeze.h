//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: squeeze.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

#ifndef SQUEEZE_H
#define SQUEEZE_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void b_squeeze(const ::coder::array<double, 3U> &a,
               ::coder::array<double, 2U> &b);

void squeeze(const ::coder::array<double, 3U> &a,
             ::coder::array<double, 2U> &b);

} // namespace coder

#endif
//
// File trailer for squeeze.h
//
// [EOF]
//
