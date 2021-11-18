//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Checkerboard.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef CHECKERBOARD_H
#define CHECKERBOARD_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace Codegen {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
class b_Checkerboard {
public:
  void initialize(real_T seedIdx, const ::coder::array<real32_T, 2U> &b_points,
                  const real32_T v1[2], const real32_T v2[2]);
  void expandBoardDirectionally(real_T direction);
  static void arrayFind(const ::coder::array<boolean_T, 2U> &arr,
                        ::coder::array<real_T, 2U> &matchedIdx);

private:
  real_T findNeighbor(const ::coder::array<real32_T, 2U> &pointVectors,
                      const ::coder::array<real32_T, 1U> &euclideanDists,
                      const real32_T b_v[2]) const;
  real_T findNeighbor(const ::coder::array<real32_T, 2U> &pointVectors,
                      const ::coder::array<real32_T, 1U> &euclideanDists,
                      const ::coder::array<real32_T, 2U> &b_v) const;
  void fitPolynomialIndices(::coder::array<real_T, 2U> &newIndices) const;
  void findClosestOnCurve(const real_T predictedPoint[2], real_T radius,
                          const real_T curve_data[],
                          const int32_T curve_size[2],
                          const real_T coordsToUse[2],
                          const ::coder::array<real_T, 2U> &removedIdx,
                          ::coder::array<real_T, 2U> &idx) const;
  void findClosestIndices(const ::coder::array<real_T, 2U> &predictedPoints,
                          ::coder::array<real_T, 2U> &indices) const;
  void expandBoardUp(const ::coder::array<real_T, 2U> &indices,
                     ::coder::array<real_T, 2U> &newBoard,
                     ::coder::array<real_T, 3U> &newBoardCoords) const;
  real32_T computeNewEnergyVertical(real32_T oldEnergy) const;
  void fitPolynomialIndices(const ::coder::array<real_T, 2U> &idx,
                            ::coder::array<real_T, 2U> &newIndices) const;
  real32_T computeNewEnergyVertical(const ::coder::array<real_T, 2U> &idx,
                                    real32_T oldEnergy) const;
  void b_fitPolynomialIndices(::coder::array<real_T, 2U> &newIndices) const;
  void expandBoardLeft(const ::coder::array<real_T, 2U> &indices,
                       ::coder::array<real_T, 2U> &newBoard,
                       ::coder::array<real_T, 3U> &newBoardCoords) const;
  real32_T computeNewEnergyHorizontal(real32_T oldEnergy) const;
  void b_fitPolynomialIndices(const ::coder::array<real_T, 2U> &idx,
                              ::coder::array<real_T, 2U> &newIndices) const;
  void expandBoardRight(const ::coder::array<real_T, 2U> &indices,
                        ::coder::array<real_T, 2U> &newBoard,
                        ::coder::array<real_T, 3U> &newBoardCoords) const;
  real32_T computeNewEnergyHorizontal(const ::coder::array<real_T, 2U> &idx,
                                      real32_T oldEnergy) const;

public:
  boolean_T isValid;
  real32_T Energy;
  ::coder::array<real_T, 3U> BoardCoords;
  ::coder::array<real_T, 2U> BoardIdx;
  ::coder::array<real32_T, 2U> Points;
  boolean_T IsDirectionBad[4];
  real_T LastExpandDirection;
  real32_T PreviousEnergy;
  boolean_T IsDistortionHigh;
};

} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for Checkerboard.h
//
// [EOF]
//
