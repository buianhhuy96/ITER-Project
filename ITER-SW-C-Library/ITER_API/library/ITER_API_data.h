//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ITER_API_data.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef ITER_API_DATA_H
#define ITER_API_DATA_H

// Include Files
#include "ITER_API_internal_types.h"
#include "rtwtypes.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Variable Declarations
namespace ITER {
extern unsigned int method;
extern unsigned int state;
extern unsigned int b_state[2];
extern bool state_not_empty;
#if defined(_OPENMP)
extern omp_nest_lock_t calibrateOneCamera_nestLockGlobal;
#endif
extern const signed char iv[3][3];
extern const double dv[2];
extern const char cv[19];
extern const char cv1[128];
extern bool isInitialized_ITER_API;
} // namespace ITER

#endif
//
// File trailer for ITER_API_data.h
//
// [EOF]
//
