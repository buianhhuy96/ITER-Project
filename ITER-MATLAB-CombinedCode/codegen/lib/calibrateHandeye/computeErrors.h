//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeErrors.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 14:44:26
//

#ifndef COMPUTEERRORS_H
#define COMPUTEERRORS_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void computeErrors(const coder::array<double, 3U> &Hhand2base,
                          const double Hhand2eye[4][4],
                          const double Hbase2grid[4][4],
                          const coder::array<double, 3U> &Hcam2grid,
                          const coder::array<double, 3U> &imgPts,
                          const coder::array<double, 2U> &Worldpts,
                          const double e_K[4][3], double errors[3]);

#endif
//
// File trailer for computeErrors.h
//
// [EOF]
//
