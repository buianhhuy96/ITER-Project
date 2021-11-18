//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ITER_API_v2_terminate.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "ITER_API_v2_terminate.h"
#include "ITER_API_v2_data.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void ITER_API_v2_terminate()
{
  omp_destroy_nest_lock(&calibrateOneCamera_nestLockGlobal);
  isInitialized_ITER_API_v2 = false;
}

//
// File trailer for ITER_API_v2_terminate.cpp
//
// [EOF]
//
