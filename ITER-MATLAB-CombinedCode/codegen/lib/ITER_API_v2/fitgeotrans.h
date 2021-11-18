//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fitgeotrans.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

#ifndef FITGEOTRANS_H
#define FITGEOTRANS_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class projective2d;

}

// Function Declarations
namespace coder {
void fitgeotrans(const ::coder::array<double, 2U> &movingPoints,
                 const ::coder::array<double, 2U> &fixedPoints,
                 projective2d *tform);

}

#endif
//
// File trailer for fitgeotrans.h
//
// [EOF]
//
