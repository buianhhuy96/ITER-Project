//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ITER_API_v2_initialize.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "ITER_API_v2_initialize.h"
#include "ITER_API_v2_data.h"
#include "rt_nonfinite.h"
#include "subPixelLocation.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void ITER_API_v2_initialize()
{
  omp_init_nest_lock(&calibrateOneCamera_nestLockGlobal);
  subPixelLocationImpl_init();
  isInitialized_ITER_API_v2 = true;
}

//
// File trailer for ITER_API_v2_initialize.cpp
//
// [EOF]
//
