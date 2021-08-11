//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fitgeotrans.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
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
void findProjectiveTransform(const ::coder::array<double, 2U> &uv,
                             const ::coder::array<double, 2U> &xy,
                             projective2d *tform);

}

#endif
//
// File trailer for fitgeotrans.h
//
// [EOF]
//
