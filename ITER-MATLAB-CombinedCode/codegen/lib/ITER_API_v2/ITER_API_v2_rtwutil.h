//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ITER_API_v2_rtwutil.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

#ifndef ITER_API_V2_RTWUTIL_H
#define ITER_API_V2_RTWUTIL_H

// Include Files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern int asr_s32(int u, unsigned int h_n);

extern int div_s32(int numerator, int denominator);

extern double rt_hypotd_snf(double u0, double c_u1);

extern double rt_powd_snf(double u0, double c_u1);

extern float rt_powf_snf(float u0, float c_u1);

#endif
//
// File trailer for ITER_API_v2_rtwutil.h
//
// [EOF]
//
