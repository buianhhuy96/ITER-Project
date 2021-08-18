//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: tic.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

// Include Files
#include "tic.h"
#include "calibrateHandeye_data.h"
#include "rt_nonfinite.h"
#include "timeKeeper.h"
#include "coder_posix_time.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
namespace coder {
void tic()
{
  coderTimespec b_timespec;
  if (!freq_not_empty) {
    freq_not_empty = true;
    (void)coderInitTimeFunctions(&freq);
  }
  (void)coderTimeClockGettimeMonotonic(&b_timespec, freq);
  internal::time::impl::timeKeeper(b_timespec.tv_sec, b_timespec.tv_nsec);
}

} // namespace coder

//
// File trailer for tic.cpp
//
// [EOF]
//
