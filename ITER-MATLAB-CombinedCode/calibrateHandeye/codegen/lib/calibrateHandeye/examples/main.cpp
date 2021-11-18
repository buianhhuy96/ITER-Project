//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
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
#include "ComputeCamExtrinsics.h"
#include "HandeyeShah.h"
#include "calibrateHandeye_terminate.h"
#include "calibrateHandeye_types.h"
#include "computeErrors.h"
#include "preprocessImages.h"
#include "readRobotPoses.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
static void argInit_1x2_real_T(double result[2]);

static void argInit_1x3_real_T(double result[3]);

static void argInit_3x3_real_T(double result[3][3]);

static void argInit_3x4_real_T(double result[4][3]);

static void argInit_4x4_real_T(double result[4][4]);

static coder::array<double, 3U> argInit_4x4xUnbounded_real_T();

static coder::array<bool, 1U> argInit_Unboundedx1_boolean_T();

static coder::array<double, 2U> argInit_Unboundedx2_real_T();

static coder::array<double, 3U> argInit_Unboundedx2xUnbounded_real_T();

static coder::array<double, 2U> argInit_Unboundedx3_real_T();

static coder::array<bool, 2U> argInit_UnboundedxUnbounded_boolean_T();

static coder::array<unsigned char, 4U>
argInit_UnboundedxUnboundedx1xUnbounded_uint8_T();

static coder::array<unsigned char, 4U>
argInit_UnboundedxUnboundedxd3xUnbounded_uint8_T();

static bool argInit_boolean_T();

static char argInit_char_T();

static double argInit_real_T();

static void argInit_struct0_T(struct0_T *result);

static unsigned char argInit_uint8_T();

static void main_ComputeCamExtrinsics();

static void main_HandeyeShah();

static void main_computeErrors();

static void main_preprocessImages();

static void main_readRobotPoses();

// Function Definitions
//
// Arguments    : double result[2]
// Return Type  : void
//
static void argInit_1x2_real_T(double result[2])
{
  // Loop over the array to initialize each element.
  for (int idx1{0}; idx1 < 2; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
  }
}

//
// Arguments    : double result[3]
// Return Type  : void
//
static void argInit_1x3_real_T(double result[3])
{
  // Loop over the array to initialize each element.
  for (int idx1{0}; idx1 < 3; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
  }
}

//
// Arguments    : double result[3][3]
// Return Type  : void
//
static void argInit_3x3_real_T(double result[3][3])
{
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 3; idx0++) {
    for (int idx1{0}; idx1 < 3; idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx1][idx0] = argInit_real_T();
    }
  }
}

//
// Arguments    : double result[4][3]
// Return Type  : void
//
static void argInit_3x4_real_T(double result[4][3])
{
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 3; idx0++) {
    for (int idx1{0}; idx1 < 4; idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx1][idx0] = argInit_real_T();
    }
  }
}

//
// Arguments    : double result[4][4]
// Return Type  : void
//
static void argInit_4x4_real_T(double result[4][4])
{
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 4; idx0++) {
    for (int idx1{0}; idx1 < 4; idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx1][idx0] = argInit_real_T();
    }
  }
}

//
// Arguments    : void
// Return Type  : coder::array<double, 3U>
//
static coder::array<double, 3U> argInit_4x4xUnbounded_real_T()
{
  coder::array<double, 3U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(4, 4, 2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 4; idx0++) {
    for (int idx1{0}; idx1 < 4; idx1++) {
      for (int idx2{0}; idx2 < result.size(2); idx2++) {
        // Set the value of the array element.
        // Change this value to the value that the application requires.
        result[(idx0 + (4 * idx1)) + (16 * idx2)] = argInit_real_T();
      }
    }
  }
  return result;
}

//
// Arguments    : void
// Return Type  : coder::array<bool, 1U>
//
static coder::array<bool, 1U> argInit_Unboundedx1_boolean_T()
{
  coder::array<bool, 1U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < result.size(0); idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0] = argInit_boolean_T();
  }
  return result;
}

//
// Arguments    : void
// Return Type  : coder::array<double, 2U>
//
static coder::array<double, 2U> argInit_Unboundedx2_real_T()
{
  coder::array<double, 2U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(2, 2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < result.size(0); idx0++) {
    for (int idx1{0}; idx1 < 2; idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx0 + (result.size(0) * idx1)] = argInit_real_T();
    }
  }
  return result;
}

//
// Arguments    : void
// Return Type  : coder::array<double, 3U>
//
static coder::array<double, 3U> argInit_Unboundedx2xUnbounded_real_T()
{
  coder::array<double, 3U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(2, 2, 2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < result.size(0); idx0++) {
    for (int idx1{0}; idx1 < 2; idx1++) {
      for (int idx2{0}; idx2 < result.size(2); idx2++) {
        // Set the value of the array element.
        // Change this value to the value that the application requires.
        result[(idx0 + (result.size(0) * idx1)) +
               ((result.size(0) * 2) * idx2)] = argInit_real_T();
      }
    }
  }
  return result;
}

//
// Arguments    : void
// Return Type  : coder::array<double, 2U>
//
static coder::array<double, 2U> argInit_Unboundedx3_real_T()
{
  coder::array<double, 2U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(2, 3);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < result.size(0); idx0++) {
    for (int idx1{0}; idx1 < 3; idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx0 + (result.size(0) * idx1)] = argInit_real_T();
    }
  }
  return result;
}

//
// Arguments    : void
// Return Type  : coder::array<bool, 2U>
//
static coder::array<bool, 2U> argInit_UnboundedxUnbounded_boolean_T()
{
  coder::array<bool, 2U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(2, 2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < result.size(0); idx0++) {
    for (int idx1{0}; idx1 < result.size(1); idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx0 + (result.size(0) * idx1)] = argInit_boolean_T();
    }
  }
  return result;
}

//
// Arguments    : void
// Return Type  : coder::array<unsigned char, 4U>
//
static coder::array<unsigned char, 4U>
argInit_UnboundedxUnboundedx1xUnbounded_uint8_T()
{
  coder::array<unsigned char, 4U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(2, 2, 1, 2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < result.size(0); idx0++) {
    for (int idx1{0}; idx1 < result.size(1); idx1++) {
      for (int idx2{0}; idx2 < 1; idx2++) {
        for (int idx3{0}; idx3 < result.size(3); idx3++) {
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
// Return Type  : coder::array<unsigned char, 4U>
//
static coder::array<unsigned char, 4U>
argInit_UnboundedxUnboundedxd3xUnbounded_uint8_T()
{
  coder::array<unsigned char, 4U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(2, 2, 2, 2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < result.size(0); idx0++) {
    for (int idx1{0}; idx1 < result.size(1); idx1++) {
      for (int idx2{0}; idx2 < result.size(2); idx2++) {
        for (int idx3{0}; idx3 < result.size(3); idx3++) {
          // Set the value of the array element.
          // Change this value to the value that the application requires.
          result[((idx0 + (result.size(0) * idx1)) +
                  ((result.size(0) * result.size(1)) * idx2)) +
                 (((result.size(0) * result.size(1)) * result.size(2)) *
                  idx3)] = argInit_uint8_T();
        }
      }
    }
  }
  return result;
}

//
// Arguments    : void
// Return Type  : bool
//
static bool argInit_boolean_T()
{
  return false;
}

//
// Arguments    : void
// Return Type  : char
//
static char argInit_char_T()
{
  return '?';
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : struct0_T *result
// Return Type  : void
//
static void argInit_struct0_T(struct0_T *result)
{
  coder::array<double, 2U> b_result_tmp;
  bool result_tmp;
  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  argInit_1x2_real_T(result->TangentialDistortion);
  result_tmp = argInit_boolean_T();
  result->EstimateTangentialDistortion = result_tmp;
  argInit_1x3_real_T(result->RadialDistortion);
  result->WorldPoints = argInit_Unboundedx2_real_T();
  result->WorldUnits = argInit_char_T();
  result->EstimateSkew = result_tmp;
  result->NumRadialDistortionCoefficients = argInit_real_T();
  b_result_tmp = argInit_Unboundedx3_real_T();
  result->RotationVectors = b_result_tmp;
  result->TranslationVectors = b_result_tmp;
  result->ReprojectionErrors = argInit_Unboundedx2xUnbounded_real_T();
  argInit_3x3_real_T(result->IntrinsicMatrix);
  result->DetectedKeypoints = argInit_UnboundedxUnbounded_boolean_T();
  result->ImageSize[0] = result->TangentialDistortion[0];
  result->ImageSize[1] = result->TangentialDistortion[1];
}

//
// Arguments    : void
// Return Type  : unsigned char
//
static unsigned char argInit_uint8_T()
{
  return 0U;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_ComputeCamExtrinsics()
{
  coder::array<double, 3U> cam_extrinsics;
  coder::array<double, 3U> camera_poses;
  coder::array<double, 3U> image_points;
  coder::array<double, 2U> b_world_points;
  coder::array<unsigned char, 4U> images;
  coder::array<bool, 1U> valid_idx;
  struct0_T camera_params;
  int err;
  // Initialize function 'ComputeCamExtrinsics' input arguments.
  // Initialize function input argument 'images'.
  images = argInit_UnboundedxUnboundedx1xUnbounded_uint8_T();
  // Initialize function input argument 'camera_params'.
  argInit_struct0_T(&camera_params);
  // Call the entry-point 'ComputeCamExtrinsics'.
  ComputeCamExtrinsics(images, argInit_real_T(), &camera_params, image_points,
                       valid_idx, cam_extrinsics, camera_poses, b_world_points,
                       &err);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_HandeyeShah()
{
  coder::array<double, 3U> As_tmp;
  double d_X[4][4];
  double g_Y[4][4];
  int err;
  // Initialize function 'HandeyeShah' input arguments.
  // Initialize function input argument 'As'.
  As_tmp = argInit_4x4xUnbounded_real_T();
  // Initialize function input argument 'Bs'.
  // Call the entry-point 'HandeyeShah'.
  HandeyeShah(As_tmp, As_tmp, d_X, g_Y, &err);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_computeErrors()
{
  coder::array<double, 3U> Hhand2base_tmp;
  coder::array<double, 3U> imgPts;
  coder::array<double, 2U> Worldpts;
  double Hhand2eye_tmp[4][4];
  double dv[4][3];
  double errors[3];
  // Initialize function 'computeErrors' input arguments.
  // Initialize function input argument 'Hhand2base'.
  Hhand2base_tmp = argInit_4x4xUnbounded_real_T();
  // Initialize function input argument 'Hhand2eye'.
  argInit_4x4_real_T(Hhand2eye_tmp);
  // Initialize function input argument 'Hbase2grid'.
  // Initialize function input argument 'Hcam2grid'.
  // Initialize function input argument 'imgPts'.
  imgPts = argInit_Unboundedx2xUnbounded_real_T();
  // Initialize function input argument 'Worldpts'.
  Worldpts = argInit_Unboundedx2_real_T();
  // Initialize function input argument 'K'.
  // Call the entry-point 'computeErrors'.
  argInit_3x4_real_T(dv);
  computeErrors(Hhand2base_tmp, Hhand2eye_tmp, Hhand2eye_tmp, Hhand2base_tmp,
                imgPts, Worldpts, dv, errors);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_preprocessImages()
{
  coder::array<unsigned char, 4U> gray_images;
  coder::array<unsigned char, 4U> images;
  struct0_T camera_params;
  // Initialize function 'preprocessImages' input arguments.
  // Initialize function input argument 'images'.
  images = argInit_UnboundedxUnboundedxd3xUnbounded_uint8_T();
  // Initialize function input argument 'camera_params'.
  argInit_struct0_T(&camera_params);
  // Call the entry-point 'preprocessImages'.
  preprocessImages(images, &camera_params, gray_images);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_readRobotPoses()
{
  coder::array<double, 3U> extrinsics;
  coder::array<double, 3U> poses;
  coder::array<double, 3U> robot_poses_vec;
  coder::array<bool, 1U> valid_idx;
  // Initialize function 'readRobotPoses' input arguments.
  // Initialize function input argument 'robot_poses_vec'.
  robot_poses_vec = argInit_4x4xUnbounded_real_T();
  // Initialize function input argument 'valid_idx'.
  valid_idx = argInit_Unboundedx1_boolean_T();
  // Call the entry-point 'readRobotPoses'.
  readRobotPoses(robot_poses_vec, valid_idx, poses, extrinsics);
}

//
// Arguments    : int argc
//                char **argv
// Return Type  : int
//
int main(int, char **)
{
  // The initialize function is being called automatically from your entry-point
  // function. So, a call to initialize is not included here. Invoke the
  // entry-point functions.
  // You can call entry-point functions multiple times.
  main_ComputeCamExtrinsics();
  main_computeErrors();
  main_HandeyeShah();
  main_preprocessImages();
  main_readRobotPoses();
  // Terminate the application.
  // You do not need to do this more than one time.
  calibrateHandeye_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
