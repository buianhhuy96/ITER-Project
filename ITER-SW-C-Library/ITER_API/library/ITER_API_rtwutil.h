//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ITER_API_rtwutil.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef ITER_API_RTWUTIL_H
#define ITER_API_RTWUTIL_H

// Include Files
#include "rtwtypes.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace ITER {
extern int asr_s32(int c_u, unsigned int h_n);

extern int div_s32(int numerator, int denominator);

extern int mul_s32_sat(int b_a, int b);

extern void mul_wide_s32(int in0, int in1, unsigned int *ptrOutBitsHi,
                         unsigned int *ptrOutBitsLo);

extern double rt_hypotd_snf(double u0, double b_u1);

extern float rt_hypotf_snf(float u0, float b_u1);

extern double rt_powd_snf(double u0, double b_u1);

extern float rt_powf_snf(float u0, float b_u1);

} // namespace ITER

#endif
//
// File trailer for ITER_API_rtwutil.h
//
// [EOF]
//
