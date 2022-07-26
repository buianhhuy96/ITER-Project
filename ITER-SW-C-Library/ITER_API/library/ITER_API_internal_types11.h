//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ITER_API_internal_types11.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef ITER_API_INTERNAL_TYPES11_H
#define ITER_API_INTERNAL_TYPES11_H

// Include Files
#include "ITER_API_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace ITER {
namespace coder {
class cameraParameters;

}
} // namespace ITER

// Type Definitions
namespace ITER {
struct p_struct_T {
  ::coder::array<double, 2U> imagePointsTmp;
  ::coder::array<double, 2U> worldPointsTmp;
  coder::cameraParameters *cameraParams;
};

struct s_struct_T {
  k_struct_T initialParams;
  ::coder::array<double, 2U> b_world_points;
  ::coder::array<double, 3U> image_points;
};

} // namespace ITER

#endif
//
// File trailer for ITER_API_internal_types11.h
//
// [EOF]
//
