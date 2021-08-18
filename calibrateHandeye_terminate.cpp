//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calibrateHandeye_terminate.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

// Include Files
#include "calibrateHandeye_terminate.h"
#include "calibrateHandeye_data.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void calibrateHandeye_terminate()
{
  omp_destroy_nest_lock(&emlrtNestLockGlobal);
  isInitialized_calibrateHandeye = false;
}

//
// File trailer for calibrateHandeye_terminate.cpp
//
// [EOF]
//
