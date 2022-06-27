//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ITER_API_initialize.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "ITER_API_initialize.h"
#include "ITER_API_data.h"
#include "rt_nonfinite.h"
#include "subPixelLocation.h"
#include <string.h>

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void ITER_API_initialize()
{
#if defined(_OPENMP)
  omp_init_nest_lock(&calibrateOneCamera_nestLockGlobal);
#endif
  subPixelLocationImpl_init();
  isInitialized_ITER_API = true;
}

//
// File trailer for ITER_API_initialize.cpp
//
// [EOF]
//
