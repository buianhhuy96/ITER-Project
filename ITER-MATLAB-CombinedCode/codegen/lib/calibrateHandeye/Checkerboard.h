//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Checkerboard.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 14:44:26
//

#ifndef CHECKERBOARD_H
#define CHECKERBOARD_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
class b_Checkerboard {
public:
  void initialize(double seedIdx, const ::coder::array<float, 2U> &b_points,
                  const float v1[2], const float v2[2]);
  void expandBoardDirectionally(double direction);
  static void arrayFind(const ::coder::array<bool, 2U> &arr,
                        ::coder::array<double, 2U> &matchedIdx);

private:
  double findNeighbor(const ::coder::array<float, 2U> &pointVectors,
                      const ::coder::array<float, 1U> &euclideanDists,
                      const float b_v[2]) const;
  double findNeighbor(const ::coder::array<float, 2U> &pointVectors,
                      const ::coder::array<float, 1U> &euclideanDists,
                      const ::coder::array<float, 2U> &b_v) const;
  void fitPolynomialIndices(::coder::array<double, 2U> &newIndices) const;
  void findClosestOnCurve(const double predictedPoint[2], double radius,
                          const ::coder::array<double, 2U> &curve,
                          const double coordsToUse[2],
                          const ::coder::array<double, 2U> &removedIdx,
                          ::coder::array<double, 2U> &idx) const;
  void findClosestIndices(const ::coder::array<double, 2U> &predictedPoints,
                          ::coder::array<double, 2U> &indices) const;
  void expandBoardUp(const ::coder::array<double, 2U> &indices,
                     ::coder::array<double, 2U> &newBoard,
                     ::coder::array<double, 3U> &newBoardCoords) const;
  float computeNewEnergyVertical(float oldEnergy) const;
  void fitPolynomialIndices(const ::coder::array<double, 2U> &idx,
                            ::coder::array<double, 2U> &newIndices) const;
  float computeNewEnergyVertical(const ::coder::array<double, 2U> &idx,
                                 float oldEnergy) const;
  void b_fitPolynomialIndices(::coder::array<double, 2U> &newIndices) const;
  void expandBoardLeft(const ::coder::array<double, 2U> &indices,
                       ::coder::array<double, 2U> &newBoard,
                       ::coder::array<double, 3U> &newBoardCoords) const;
  float computeNewEnergyHorizontal(float oldEnergy) const;
  void b_fitPolynomialIndices(const ::coder::array<double, 2U> &idx,
                              ::coder::array<double, 2U> &newIndices) const;
  void expandBoardRight(const ::coder::array<double, 2U> &indices,
                        ::coder::array<double, 2U> &newBoard,
                        ::coder::array<double, 3U> &newBoardCoords) const;
  float computeNewEnergyHorizontal(const ::coder::array<double, 2U> &idx,
                                   float oldEnergy) const;

public:
  bool isValid;
  float Energy;
  array<double, 3U> BoardCoords;
  array<double, 2U> BoardIdx;
  array<float, 2U> Points;
  bool IsDirectionBad[4];
  double LastExpandDirection;
  float PreviousEnergy;
  bool IsDistortionHigh;
};

} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

#endif
//
// File trailer for Checkerboard.h
//
// [EOF]
//
