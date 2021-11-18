//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ITER_API_rtwutil.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

#ifndef ITER_API_RTWUTIL_H
#define ITER_API_RTWUTIL_H

// Include Files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern int asr_s32(int c_u, unsigned int h_n);

extern int div_s32(int numerator, int denominator);

extern double rt_hypotd_snf(double u0, double b_u1);

extern double rt_powd_snf(double u0, double b_u1);

extern float rt_powf_snf(float u0, float b_u1);

#endif
//
// File trailer for ITER_API_rtwutil.h
//
// [EOF]
//
