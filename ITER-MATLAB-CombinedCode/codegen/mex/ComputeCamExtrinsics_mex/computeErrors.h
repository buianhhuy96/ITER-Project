//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeErrors.h
//
// Code generation for function 'computeErrors'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
void computeErrors(const emlrtStack *sp,
                   const coder::array<real_T, 3U> &Hhand2base,
                   const real_T Hhand2eye[16], const real_T Hbase2grid[16],
                   const coder::array<real_T, 3U> &Hcam2grid,
                   const coder::array<real_T, 3U> &imgPts,
                   const coder::array<real_T, 2U> &Worldpts, const real_T K[12],
                   real_T errors[3]);

// End of code generation (computeErrors.h)
