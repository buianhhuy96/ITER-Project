//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ismember.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

#ifndef ISMEMBER_H
#define ISMEMBER_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void local_ismember(const ::coder::array<double, 2U> &a,
                    const ::coder::array<double, 2U> &s,
                    ::coder::array<boolean_T, 2U> &tf);

}

#endif
//
// File trailer for ismember.h
//
// [EOF]
//
