//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeErrors.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef COMPUTEERRORS_H
#define COMPUTEERRORS_H

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
extern void computeErrors(const ::coder::array<double, 3U> &Hhand2base,
                          const double Hhand2eye[4][4],
                          const double Hbase2grid[4][4],
                          const ::coder::array<double, 3U> &Hcam2grid,
                          const ::coder::array<double, 3U> &imgPts,
                          const ::coder::array<double, 2U> &Worldpts,
                          const double f_K[4][3], double errors[3]);

}

#endif
//
// File trailer for computeErrors.h
//
// [EOF]
//
