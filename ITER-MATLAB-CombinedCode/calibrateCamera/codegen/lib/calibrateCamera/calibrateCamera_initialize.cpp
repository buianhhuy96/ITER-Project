//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calibrateCamera_initialize.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "calibrateCamera_initialize.h"
#include "calibrateCamera_data.h"
#include "rt_nonfinite.h"
#include "subPixelLocation.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
namespace Codegen {
void calibrateCamera_initialize()
{
  subPixelLocationImpl_init();
  isInitialized_calibrateCamera = true;
}

} // namespace Codegen

//
// File trailer for calibrateCamera_initialize.cpp
//
// [EOF]
//
