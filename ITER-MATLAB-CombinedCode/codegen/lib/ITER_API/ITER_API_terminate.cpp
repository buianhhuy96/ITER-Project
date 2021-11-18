//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ITER_API_terminate.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

// Include Files
#include "ITER_API_terminate.h"
#include "ITER_API_data.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void ITER_API_terminate()
{
  omp_destroy_nest_lock(&calibrateOneCamera_v2_nestLockGlobal);
  isInitialized_ITER_API = false;
}

//
// File trailer for ITER_API_terminate.cpp
//
// [EOF]
//
