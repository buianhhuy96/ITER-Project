//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// Checkerboard.h
//
// Code generation for function 'Checkerboard'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Definitions
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
class Checkerboard {
public:
  void initialize(const emlrtStack *sp, real_T seedIdx,
                  const ::coder::array<real32_T, 2U> &points,
                  const real32_T v1[2], const real32_T v2[2]);
  void expandBoardFully(const emlrtStack *sp);
  Checkerboard *init(const emlrtStack *sp);
  static void arrayFind(const emlrtStack *sp,
                        const ::coder::array<boolean_T, 2U> &arr,
                        ::coder::array<real_T, 2U> &matchedIdx);

private:
  real_T findNeighbor(const emlrtStack *sp,
                      const ::coder::array<real32_T, 2U> &pointVectors,
                      const ::coder::array<real32_T, 1U> &euclideanDists,
                      const real32_T v[2]) const;
  real_T findNeighbor(const emlrtStack *sp,
                      const ::coder::array<real32_T, 2U> &pointVectors,
                      const ::coder::array<real32_T, 1U> &euclideanDists,
                      const ::coder::array<real32_T, 2U> &v) const;
  real32_T computeInitialEnergy(const emlrtStack *sp) const;
  void expandBoardDirectionally(const emlrtStack *sp, real_T direction);
  void fitPolynomialIndices(const emlrtStack *sp,
                            ::coder::array<real_T, 2U> &newIndices) const;
  void fitPolyCurve(const emlrtStack *sp,
                    const ::coder::array<real_T, 1U> &validIdx, real_T currIdx,
                    const real_T coordsToUse[2],
                    ::coder::array<real_T, 2U> &curveCoeff) const;
  void findClosestOnCurve(const emlrtStack *sp, const real_T predictedPoint[2],
                          real_T radius,
                          const ::coder::array<real_T, 2U> &curve,
                          const real_T coordsToUse[2],
                          const ::coder::array<real_T, 2U> &removedIdx,
                          ::coder::array<real_T, 2U> &idx) const;
  void findClosestIndices(const emlrtStack *sp,
                          const ::coder::array<real_T, 2U> &predictedPoints,
                          ::coder::array<real_T, 2U> &indices) const;
  void expandBoardUp(const emlrtStack *sp,
                     const ::coder::array<real_T, 2U> &indices,
                     ::coder::array<real_T, 2U> &newBoard,
                     ::coder::array<real_T, 3U> &newBoardCoords) const;
  real32_T computeNewEnergyVertical(const emlrtStack *sp,
                                    real32_T oldEnergy) const;
  void fitPolynomialIndices(const emlrtStack *sp,
                            const ::coder::array<real_T, 2U> &idx,
                            ::coder::array<real_T, 2U> &newIndices) const;
  void expandBoardDown(const emlrtStack *sp,
                       const ::coder::array<real_T, 2U> &indices,
                       ::coder::array<real_T, 2U> &newBoard,
                       ::coder::array<real_T, 3U> &newBoardCoords) const;
  real32_T computeNewEnergyVertical(const emlrtStack *sp,
                                    const ::coder::array<real_T, 2U> &idx,
                                    real32_T oldEnergy) const;
  void b_fitPolynomialIndices(const emlrtStack *sp,
                              ::coder::array<real_T, 2U> &newIndices) const;
  void fitPolyCurve(const emlrtStack *sp,
                    const ::coder::array<real_T, 2U> &validIdx, real_T currIdx,
                    const real_T coordsToUse[2],
                    ::coder::array<real_T, 2U> &curveCoeff) const;
  void expandBoardLeft(const emlrtStack *sp,
                       const ::coder::array<real_T, 2U> &indices,
                       ::coder::array<real_T, 2U> &newBoard,
                       ::coder::array<real_T, 3U> &newBoardCoords) const;
  real32_T computeNewEnergyHorizontal(const emlrtStack *sp,
                                      real32_T oldEnergy) const;
  void b_fitPolynomialIndices(const emlrtStack *sp,
                              const ::coder::array<real_T, 2U> &idx,
                              ::coder::array<real_T, 2U> &newIndices) const;
  void expandBoardRight(const emlrtStack *sp,
                        const ::coder::array<real_T, 2U> &indices,
                        ::coder::array<real_T, 2U> &newBoard,
                        ::coder::array<real_T, 3U> &newBoardCoords) const;
  real32_T computeNewEnergyHorizontal(const emlrtStack *sp,
                                      const ::coder::array<real_T, 2U> &idx,
                                      real32_T oldEnergy) const;

public:
  boolean_T isValid;
  real32_T Energy;
  array<real_T, 3U> BoardCoords;
  array<real_T, 2U> BoardIdx;
  array<real32_T, 2U> Points;
  boolean_T IsDistortionHigh;

private:
  boolean_T IsDirectionBad[4];
  real_T LastExpandDirection;
  real32_T PreviousEnergy;
};

} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

// End of code generation (Checkerboard.h)
