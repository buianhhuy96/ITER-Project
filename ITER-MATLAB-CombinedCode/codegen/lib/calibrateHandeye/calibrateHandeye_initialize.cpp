//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calibrateHandeye_initialize.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 14:44:26
//

// Include Files
#include "calibrateHandeye_initialize.h"
#include "calibrateHandeye_data.h"
#include "rt_nonfinite.h"
#include "subPixelLocation.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void calibrateHandeye_initialize()
{
  omp_init_nest_lock(&ComputeCamExtrinsics_nestLockGlobal);
  subPixelLocationImpl_init();
  isInitialized_calibrateHandeye = true;
}

//
// File trailer for calibrateHandeye_initialize.cpp
//
// [EOF]
//
