//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calibrateHandeye_rtwutil.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

#ifndef CALIBRATEHANDEYE_RTWUTIL_H
#define CALIBRATEHANDEYE_RTWUTIL_H

// Include Files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern int asr_s32(int u, unsigned int n);

extern int div_s32(int numerator, int denominator);

extern double rt_hypotd_snf(double u0, double u1);

extern double rt_powd_snf(double u0, double u1);

extern float rt_powf_snf(float u0, float u1);

#endif
//
// File trailer for calibrateHandeye_rtwutil.h
//
// [EOF]
//
