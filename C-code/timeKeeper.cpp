//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: timeKeeper.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

// Include Files
#include "timeKeeper.h"
#include "calibrateHandeye_data.h"
#include "rt_nonfinite.h"
#include "coder_posix_time.h"

// Variable Definitions
static coderTimespec savedTime;

static bool savedTime_not_empty;

// Function Definitions
//
// Arguments    : double newTime_tv_sec
//                double newTime_tv_nsec
// Return Type  : void
//
namespace coder {
namespace internal {
namespace time {
namespace impl {
void timeKeeper(double newTime_tv_sec, double newTime_tv_nsec)
{
  if (!savedTime_not_empty) {
    if (!freq_not_empty) {
      freq_not_empty = true;
      (void)coderInitTimeFunctions(&freq);
    }
    (void)coderTimeClockGettimeMonotonic(&savedTime, freq);
    savedTime_not_empty = true;
  }
  savedTime.tv_sec = newTime_tv_sec;
  savedTime.tv_nsec = newTime_tv_nsec;
}

//
// Arguments    : double *outTime_tv_sec
//                double *outTime_tv_nsec
// Return Type  : void
//
void timeKeeper(double *outTime_tv_sec, double *outTime_tv_nsec)
{
  *outTime_tv_sec = savedTime.tv_sec;
  *outTime_tv_nsec = savedTime.tv_nsec;
}

//
// Arguments    : void
// Return Type  : void
//
} // namespace impl
} // namespace time
} // namespace internal
} // namespace coder
void savedTime_not_empty_init()
{
  savedTime_not_empty = false;
}

//
// File trailer for timeKeeper.cpp
//
// [EOF]
//