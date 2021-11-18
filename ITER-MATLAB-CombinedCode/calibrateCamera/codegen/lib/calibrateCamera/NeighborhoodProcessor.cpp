//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: NeighborhoodProcessor.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "NeighborhoodProcessor.h"
#include "rt_nonfinite.h"
#include <cfloat>
#include <cmath>

// Function Declarations
namespace Codegen {
static real_T rt_remd_snf(real_T u0, real_T u1);

}

// Function Definitions
//
// Arguments    : real_T u0
//                real_T u1
// Return Type  : real_T
//
namespace Codegen {
static real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (((std::isnan(u0)) || (std::isnan(u1))) || (std::isinf(u0))) {
    y = rtNaN;
  } else if (std::isinf(u1)) {
    y = u0;
  } else if ((u1 != 0.0) && (u1 != std::trunc(u1))) {
    real_T q;
    q = std::abs(u0 / u1);
    if (!(std::abs(q - std::floor(q + 0.5)) > (DBL_EPSILON * q))) {
      y = 0.0 * u0;
    } else {
      y = std::fmod(u0, u1);
    }
  } else {
    y = std::fmod(u0, u1);
  }
  return y;
}

//
// Arguments    : const int32_T imSize[2]
//                const boolean_T nhConn[3][3]
//                int32_T loffsets[9]
//                int32_T linds[9]
//                int32_T soffsets[2][9]
//                int32_T b_interiorStart[2]
//                int32_T b_interiorEnd[2]
// Return Type  : void
//
namespace coder {
namespace images {
namespace internal {
namespace coder {
void NeighborhoodProcessor::computeParameters(
    const int32_T imSize[2], const boolean_T nhConn[3][3], int32_T loffsets[9],
    int32_T linds[9], int32_T soffsets[2][9], int32_T b_interiorStart[2],
    int32_T b_interiorEnd[2])
{
  int32_T indx;
  int32_T k;
  int32_T pixelsPerImPage1_idx_1;
  pixelsPerImPage1_idx_1 = imSize[0];
  b_interiorStart[0] = 2;
  b_interiorEnd[0] = imSize[0] - 1;
  b_interiorStart[1] = 2;
  b_interiorEnd[1] = imSize[1] - 1;
  indx = static_cast<int32_T>((&nhConn[0][0])[0]);
  for (k = 0; k < 8; k++) {
    indx += static_cast<int32_T>((&nhConn[0][0])[k + 1]);
  }
  if (indx != 0) {
    real_T b;
    indx = 0;
    for (int32_T pind{0}; pind < 9; pind++) {
      if ((&nhConn[0][0])[pind]) {
        int32_T subs_idx_1_tmp;
        k = static_cast<int32_T>(
            rt_remd_snf(((static_cast<real_T>(pind)) + 1.0) - 1.0, 3.0));
        subs_idx_1_tmp = static_cast<int32_T>(static_cast<real_T>(
            ((static_cast<real_T>(static_cast<int32_T>((pind - k) - 1))) +
             1.0) /
            3.0));
        soffsets[0][indx] = k + 1;
        soffsets[1][indx] = subs_idx_1_tmp + 1;
        linds[indx] = (k + (subs_idx_1_tmp * 3)) + 1;
        loffsets[indx] = (k + (subs_idx_1_tmp * pixelsPerImPage1_idx_1)) + 1;
        indx++;
      }
    }
    b = (static_cast<real_T>(imSize[0])) + 2.0;
    for (indx = 0; indx < 9; indx++) {
      loffsets[indx] -= static_cast<int32_T>(b);
    }
    for (k = 0; k < 2; k++) {
      for (indx = 0; indx < 9; indx++) {
        soffsets[k][indx] -= 2;
      }
    }
  }
}

} // namespace coder
} // namespace internal
} // namespace images
} // namespace coder
} // namespace Codegen

//
// File trailer for NeighborhoodProcessor.cpp
//
// [EOF]
//
