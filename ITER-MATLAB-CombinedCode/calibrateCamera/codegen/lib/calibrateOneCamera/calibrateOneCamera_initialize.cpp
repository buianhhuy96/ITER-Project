//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calibrateOneCamera_initialize.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "calibrateOneCamera_initialize.h"
#include "calibrateOneCamera_data.h"
#include "rt_nonfinite.h"
#include "subPixelLocation.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
namespace Codegen {
void calibrateOneCamera_initialize()
{
  omp_init_nest_lock(&calibrateOneCamera_nestLockGlobal);
  subPixelLocationImpl_init();
  isInitialized_calibrateOneCamera = true;
}

} // namespace Codegen

//
// File trailer for calibrateOneCamera_initialize.cpp
//
// [EOF]
//
