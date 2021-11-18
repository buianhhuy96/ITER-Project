//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

/*************************************************************************/
/* This automatically generated example C++ main file shows how to call  */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

// Include Files
#include "main.h"
#include "calibrateCamera.h"
#include "calibrateCamera_terminate.h"
#include "calibrateCamera_types.h"
#include "rt_nonfinite.h"
#include "string1.h"
#include "coder_array.h"

// Function Declarations
static void argInit_1x2_real_T(real_T result[2]);

static coder::array<uint8_T, 4U>
argInit_UnboundedxUnboundedx1xUnbounded_uint8_T();

static real_T argInit_real_T();

static uint8_T argInit_uint8_T();

static void main_calibrateCamera();

// Function Definitions
//
// Arguments    : real_T result[2]
// Return Type  : void
//
static void argInit_1x2_real_T(real_T result[2])
{
  // Loop over the array to initialize each element.
  for (int32_T idx1{0}; idx1 < 2; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
  }
}

//
// Arguments    : void
// Return Type  : coder::array<uint8_T, 4U>
//
static coder::array<uint8_T, 4U>
argInit_UnboundedxUnboundedx1xUnbounded_uint8_T()
{
  coder::array<uint8_T, 4U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(2, 2, 1, 2);
  // Loop over the array to initialize each element.
  for (int32_T idx0{0}; idx0 < result.size(0); idx0++) {
    for (int32_T idx1{0}; idx1 < result.size(1); idx1++) {
      for (int32_T idx2{0}; idx2 < 1; idx2++) {
        for (int32_T idx3{0}; idx3 < result.size(3); idx3++) {
          // Set the value of the array element.
          // Change this value to the value that the application requires.
          result[(idx0 + (result.size(0) * idx1)) +
                 ((result.size(0) * result.size(1)) * idx3)] =
              argInit_uint8_T();
        }
      }
    }
  }
  return result;
}

//
// Arguments    : void
// Return Type  : real_T
//
static real_T argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : void
// Return Type  : uint8_T
//
static uint8_T argInit_uint8_T()
{
  return 0U;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_calibrateCamera()
{
  Codegen::coder::rtString err;
  coder::array<uint8_T, 4U> images;
  Codegen::struct0_T calibrationOptimized;
  real_T dv[2];
  // Initialize function 'calibrateCamera' input arguments.
  // Initialize function input argument 'images'.
  images = argInit_UnboundedxUnboundedx1xUnbounded_uint8_T();
  // Initialize function input argument 'boardSize'.
  // Call the entry-point 'calibrateCamera'.
  argInit_1x2_real_T(dv);
  Codegen::calibrateCamera(images, argInit_real_T(), dv, &calibrationOptimized,
                           &err);
}

//
// Arguments    : int32_T argc
//                char **argv
// Return Type  : int32_T
//
int32_T main(int32_T, char **)
{
  // The initialize function is being called automatically from your entry-point
  // function. So, a call to initialize is not included here. Invoke the
  // entry-point functions.
  // You can call entry-point functions multiple times.
  main_calibrateCamera();
  // Terminate the application.
  // You do not need to do this more than one time.
  Codegen::calibrateCamera_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
