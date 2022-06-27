//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: NeighborhoodProcessor.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef NEIGHBORHOODPROCESSOR_H
#define NEIGHBORHOODPROCESSOR_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct e_struct_T;

// Type Definitions
namespace coder {
namespace images {
namespace internal {
namespace coder {
class NeighborhoodProcessor {
public:
  static void computeParameters(const int imSize[2], const bool nhConn[3][3],
                                int loffsets[9], int linds[9],
                                int soffsets[2][9], int b_interiorStart[2],
                                int b_interiorEnd[2]);
  void process2D(const ::coder::array<float, 2U> &b_in,
                 ::coder::array<bool, 2U> &out,
                 const e_struct_T *fparams) const;
  bool Neighborhood[3][3];
  int ImageSize[2];
  int InteriorStart[2];
  int InteriorEnd[2];
  int ImageNeighborLinearOffsets[9];
  double Padding;
  double PadValue;
  bool ProcessBorder;
  double NeighborhoodCenter;
  int NeighborLinearIndices[9];
  int NeighborSubscriptOffsets[2][9];
};

} // namespace coder
} // namespace internal
} // namespace images
} // namespace coder

#endif
//
// File trailer for NeighborhoodProcessor.h
//
// [EOF]
//
