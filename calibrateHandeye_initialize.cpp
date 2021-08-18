//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calibrateHandeye_initialize.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

// Include Files
#include "calibrateHandeye_initialize.h"
#include "CoderTimeAPI.h"
#include "calibrateHandeye_data.h"
#include "rt_nonfinite.h"
#include "subPixelLocation.h"
#include "timeKeeper.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void calibrateHandeye_initialize()
{
  omp_init_nest_lock(&emlrtNestLockGlobal);
  savedTime_not_empty_init();
  freq_not_empty_init();
  subPixelLocationImpl_init();
  isInitialized_calibrateHandeye = true;
}

//
// File trailer for calibrateHandeye_initialize.cpp
//
// [EOF]
//
