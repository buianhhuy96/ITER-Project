//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fitgeotrans.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef FITGEOTRANS_H
#define FITGEOTRANS_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace ITER {
namespace coder {
class projective2d;

}
} // namespace ITER

// Function Declarations
namespace ITER {
namespace coder {
void fitgeotrans(const ::coder::array<double, 2U> &movingPoints,
                 const ::coder::array<double, 2U> &fixedPoints,
                 projective2d *tform);

}
} // namespace ITER

#endif
//
// File trailer for fitgeotrans.h
//
// [EOF]
//
