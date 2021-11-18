//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: NeighborhoodProcessor.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef NEIGHBORHOODPROCESSOR_H
#define NEIGHBORHOODPROCESSOR_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace Codegen {
namespace coder {
namespace images {
namespace internal {
namespace coder {
class NeighborhoodProcessor {
public:
  static void computeParameters(const int32_T imSize[2],
                                const boolean_T nhConn[3][3],
                                int32_T loffsets[9], int32_T linds[9],
                                int32_T soffsets[2][9],
                                int32_T b_interiorStart[2],
                                int32_T b_interiorEnd[2]);
  boolean_T Neighborhood[3][3];
  int32_T ImageSize[2];
  int32_T InteriorStart[2];
  int32_T InteriorEnd[2];
  int32_T ImageNeighborLinearOffsets[9];
  real_T Padding;
  real_T PadValue;
  boolean_T ProcessBorder;
  real_T NeighborhoodCenter;
  int32_T NeighborLinearIndices[9];
  int32_T NeighborSubscriptOffsets[2][9];
};

} // namespace coder
} // namespace internal
} // namespace images
} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for NeighborhoodProcessor.h
//
// [EOF]
//
