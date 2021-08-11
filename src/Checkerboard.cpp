//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Checkerboard.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

// Include Files
#include "Checkerboard.h"
#include "calibrateHandeye_rtwutil.h"
#include "colon.h"
#include "combineVectorElements.h"
#include "eml_setop.h"
#include "find.h"
#include "isequal.h"
#include "ismember.h"
#include "mean.h"
#include "minOrMax.h"
#include "norm.h"
#include "polyfit.h"
#include "rt_nonfinite.h"
#include "squeeze.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
static float rt_hypotf_snf(float u0, float u1);

// Function Definitions
//
// Arguments    : const ::coder::array<boolean_T, 2U> &arr
//                const double pattern[3]
//                ::coder::array<double, 2U> &matchedIdx
// Return Type  : void
//
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void Checkerboard::arrayFind(const ::coder::array<boolean_T, 2U> &arr,
                             const double pattern[3],
                             ::coder::array<double, 2U> &matchedIdx)
{
  array<double, 2U> b_arr;
  array<int, 2U> b_ii;
  array<signed char, 2U> matchArr;
  array<boolean_T, 2U> x;
  int idx;
  int ii;
  int nx;
  boolean_T b_x[3];
  boolean_T exitg1;
  matchArr.set_size(1, arr.size(1) - 2);
  ii = arr.size(1);
  for (idx = 0; idx <= (ii - 3); idx++) {
    boolean_T y;
    b_arr.set_size(1, 3);
    for (nx = 0; nx < 3; nx++) {
      b_arr[nx] = static_cast<double>(arr[idx + nx]);
    }
    b_x[0] = (b_arr[0] == pattern[0]);
    b_x[1] = (b_arr[1] == pattern[1]);
    b_x[2] = (b_arr[2] == pattern[2]);
    y = true;
    nx = 0;
    exitg1 = false;
    while ((!exitg1) && (nx < 3)) {
      if (!b_x[nx]) {
        y = false;
        exitg1 = true;
      } else {
        nx++;
      }
    }
    matchArr[idx] = static_cast<signed char>(y);
  }
  x.set_size(1, matchArr.size(1));
  nx = matchArr.size(1);
  for (ii = 0; ii < nx; ii++) {
    x[ii] = (matchArr[ii] == 1);
  }
  nx = x.size(1);
  idx = 0;
  b_ii.set_size(1, x.size(1));
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= (nx - 1))) {
    if (x[ii]) {
      idx++;
      b_ii[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (x.size(1) == 1) {
    if (idx == 0) {
      b_ii.set_size(1, 0);
    }
  } else {
    if (1 > idx) {
      idx = 0;
    }
    b_ii.set_size(b_ii.size(0), idx);
  }
  matchedIdx.set_size(1, b_ii.size(1));
  nx = b_ii.size(1);
  for (ii = 0; ii < nx; ii++) {
    matchedIdx[ii] = static_cast<double>(b_ii[ii]);
  }
}

//
// Arguments    : ::coder::array<double, 2U> &newIndices
// Return Type  : void
//
void Checkerboard::b_fitPolynomialIndices(
    ::coder::array<double, 2U> &newIndices) const
{
  array<double, 2U> b_index;
  array<double, 2U> b_this;
  array<double, 2U> currCurve;
  array<double, 2U> removedIdx;
  array<double, 1U> b_x;
  array<double, 1U> x;
  array<int, 2U> ii;
  array<int, 1U> r2;
  array<int, 1U> r3;
  array<int, 1U> r4;
  array<int, 1U> r5;
  array<boolean_T, 1U> r;
  array<boolean_T, 1U> r1;
  double coordsToUse[2];
  double currPt[2];
  double y;
  int b_i;
  int end;
  int i;
  int loop_ub;
  loop_ub = this->BoardIdx.size(0);
  r.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r[i] = (this->BoardIdx[i] > 0.0);
  }
  loop_ub = this->BoardIdx.size(0);
  r1.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r1[i] = (this->BoardIdx[i + this->BoardIdx.size(0)] > 0.0);
  }
  end = r.size(0) - 1;
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if ((r[b_i]) && (r1[b_i])) {
      loop_ub++;
    }
  }
  r2.set_size(loop_ub);
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if ((r[b_i]) && (r1[b_i])) {
      r2[loop_ub] = b_i + 1;
      loop_ub++;
    }
  }
  end = r.size(0) - 1;
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if ((r[b_i]) && (r1[b_i])) {
      loop_ub++;
    }
  }
  r3.set_size(loop_ub);
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if ((r[b_i]) && (r1[b_i])) {
      r3[loop_ub] = b_i + 1;
      loop_ub++;
    }
  }
  x.set_size(r2.size(0));
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    x[i] = this->BoardCoords[(r2[i] + this->BoardCoords.size(0)) - 1] -
           this->BoardCoords[r3[i] - 1];
  }
  end = r.size(0) - 1;
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if ((r[b_i]) && (r1[b_i])) {
      loop_ub++;
    }
  }
  r4.set_size(loop_ub);
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if ((r[b_i]) && (r1[b_i])) {
      r4[loop_ub] = b_i + 1;
      loop_ub++;
    }
  }
  end = r.size(0) - 1;
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if ((r[b_i]) && (r1[b_i])) {
      loop_ub++;
    }
  }
  r5.set_size(loop_ub);
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if ((r[b_i]) && (r1[b_i])) {
      r5[loop_ub] = b_i + 1;
      loop_ub++;
    }
  }
  b_x.set_size(r4.size(0));
  loop_ub = r4.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_x[i] = this->BoardCoords[((r4[i] + this->BoardCoords.size(0)) +
                                (this->BoardCoords.size(0) *
                                 this->BoardCoords.size(1))) -
                               1] -
             this->BoardCoords[(r5[i] + (this->BoardCoords.size(0) *
                                         this->BoardCoords.size(1))) -
                               1];
  }
  if (std::abs(combineVectorElements(x) / (static_cast<double>(x.size(0)))) >
      std::abs(combineVectorElements(b_x) /
               (static_cast<double>(b_x.size(0))))) {
    coordsToUse[0] = 1.0;
    coordsToUse[1] = 2.0;
  } else {
    coordsToUse[0] = 2.0;
    coordsToUse[1] = 1.0;
  }
  loop_ub = this->BoardCoords.size(0);
  newIndices.set_size(1, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    newIndices[i] = 0.0;
  }
  removedIdx.set_size(1, 0);
  i = this->BoardCoords.size(0);
  for (int j{0}; j < i; j++) {
    int i1;
    loop_ub = this->BoardCoords.size(1);
    b_index.set_size(1, loop_ub);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_index[i1] =
          this->BoardCoords[(j + (this->BoardCoords.size(0) * i1)) +
                            ((this->BoardCoords.size(0) *
                              this->BoardCoords.size(1)) *
                             ((static_cast<int>(coordsToUse[0])) - 1))];
    }
    eml_find(b_index, ii);
    if (ii.size(1) >= 2) {
      double coordDist;
      double coordDist_tmp;
      double currCoord;
      double currRad;
      int i2;
      boolean_T exitg1;
      i1 = static_cast<int>(coordsToUse[0]);
      coordDist_tmp =
          this->BoardCoords[(j + (this->BoardCoords.size(0) * (ii[0] - 1))) +
                            ((this->BoardCoords.size(0) *
                              this->BoardCoords.size(1)) *
                             (i1 - 1))];
      end = ii[0];
      coordDist =
          (coordDist_tmp -
           this->BoardCoords[(j + (this->BoardCoords.size(0) * (ii[1] - 1))) +
                             ((this->BoardCoords.size(0) *
                               this->BoardCoords.size(1)) *
                              (i1 - 1))]) /
          ((static_cast<double>(ii[1])) - (static_cast<double>(end)));
      loop_ub = 0;
      i2 = ii.size(1);
      b_index.set_size(1, ii.size(1));
      b_this.set_size(1, ii.size(1));
      for (b_i = 0; b_i < i2; b_i++) {
        if (ii[b_i] != 0) {
          loop_ub++;
        }
        b_index[b_i] =
            this->BoardCoords
                [(j + (this->BoardCoords.size(0) * (ii[b_i] - 1))) +
                 ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                  (i1 - 1))];
        b_this[b_i] =
            this->BoardCoords
                [(j + (this->BoardCoords.size(0) * (ii[b_i] - 1))) +
                 ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                  ((static_cast<int>(coordsToUse[1])) - 1))];
      }
      if (loop_ub > 5) {
        loop_ub = 4;
      } else {
        loop_ub = 2;
      }
      polyfit(b_index, b_this, static_cast<double>(loop_ub), currCurve);
      currRad = coordDist / 4.0;
      currCoord = currRad + coordDist_tmp;
      exitg1 = false;
      while ((!exitg1) &&
             (std::abs(currCoord - coordDist_tmp) <
              (((static_cast<double>(end)) * 1.5) * std::abs(coordDist)))) {
        currPt[0] = 1.0;
        currPt[1] = 2.0;
        if (isequal(coordsToUse, currPt)) {
          if (currCurve.size(1) != 0) {
            y = currCurve[0];
            i1 = currCurve.size(1);
            for (b_i = 0; b_i <= (i1 - 2); b_i++) {
              y = (currCoord * y) + currCurve[b_i + 1];
            }
          }
          currPt[0] = currCoord;
          currPt[1] = y;
        } else {
          if (currCurve.size(1) != 0) {
            y = currCurve[0];
            i1 = currCurve.size(1);
            for (b_i = 0; b_i <= (i1 - 2); b_i++) {
              y = (currCoord * y) + currCurve[b_i + 1];
            }
          }
          currPt[0] = y;
          currPt[1] = currCoord;
        }
        this->findClosestOnCurve(currPt, std::abs(currRad), currCurve,
                                 coordsToUse, removedIdx, b_index);
        if (b_index.size(1) != 0) {
          newIndices[j] = b_index[0];
          i1 = removedIdx.size(1);
          loop_ub = b_index.size(1);
          removedIdx.set_size(removedIdx.size(0),
                              removedIdx.size(1) + b_index.size(1));
          for (i2 = 0; i2 < loop_ub; i2++) {
            removedIdx[i1 + i2] = b_index[i2];
          }
          exitg1 = true;
        } else {
          currCoord += currRad;
        }
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &idx
//                ::coder::array<double, 2U> &newIndices
// Return Type  : void
//
void Checkerboard::b_fitPolynomialIndices(
    const ::coder::array<double, 2U> &idx,
    ::coder::array<double, 2U> &newIndices) const
{
  array<double, 2U> b_index;
  array<double, 2U> b_this;
  array<double, 2U> removedIdx;
  array<double, 2U> validIdx;
  array<double, 1U> b_x;
  array<double, 1U> x;
  array<int, 2U> ii;
  array<int, 1U> r2;
  array<int, 1U> r3;
  array<int, 1U> r4;
  array<int, 1U> r5;
  array<boolean_T, 1U> r;
  array<boolean_T, 1U> r1;
  double coordsToUse[2];
  double currPt[2];
  double y;
  int b_idx_tmp;
  int end;
  int i;
  int idx_tmp;
  int loop_ub;
  int trueCount;
  idx_tmp = static_cast<int>(idx[0]);
  loop_ub = this->BoardIdx.size(0);
  r.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r[i] = (this->BoardIdx[i + (this->BoardIdx.size(0) * (idx_tmp - 1))] > 0.0);
  }
  b_idx_tmp = static_cast<int>(idx[1]);
  loop_ub = this->BoardIdx.size(0);
  r1.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r1[i] =
        (this->BoardIdx[i + (this->BoardIdx.size(0) * (b_idx_tmp - 1))] > 0.0);
  }
  end = r.size(0) - 1;
  trueCount = 0;
  for (loop_ub = 0; loop_ub <= end; loop_ub++) {
    if ((r[loop_ub]) && (r1[loop_ub])) {
      trueCount++;
    }
  }
  r2.set_size(trueCount);
  trueCount = 0;
  for (loop_ub = 0; loop_ub <= end; loop_ub++) {
    if ((r[loop_ub]) && (r1[loop_ub])) {
      r2[trueCount] = loop_ub + 1;
      trueCount++;
    }
  }
  end = r.size(0) - 1;
  trueCount = 0;
  for (loop_ub = 0; loop_ub <= end; loop_ub++) {
    if ((r[loop_ub]) && (r1[loop_ub])) {
      trueCount++;
    }
  }
  r3.set_size(trueCount);
  trueCount = 0;
  for (loop_ub = 0; loop_ub <= end; loop_ub++) {
    if ((r[loop_ub]) && (r1[loop_ub])) {
      r3[trueCount] = loop_ub + 1;
      trueCount++;
    }
  }
  x.set_size(r2.size(0));
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    x[i] = this->BoardCoords[(r2[i] +
                              (this->BoardCoords.size(0) * (b_idx_tmp - 1))) -
                             1] -
           this->BoardCoords[(r3[i] +
                              (this->BoardCoords.size(0) * (idx_tmp - 1))) -
                             1];
  }
  end = r.size(0) - 1;
  trueCount = 0;
  for (loop_ub = 0; loop_ub <= end; loop_ub++) {
    if ((r[loop_ub]) && (r1[loop_ub])) {
      trueCount++;
    }
  }
  r4.set_size(trueCount);
  trueCount = 0;
  for (loop_ub = 0; loop_ub <= end; loop_ub++) {
    if ((r[loop_ub]) && (r1[loop_ub])) {
      r4[trueCount] = loop_ub + 1;
      trueCount++;
    }
  }
  end = r.size(0) - 1;
  trueCount = 0;
  for (loop_ub = 0; loop_ub <= end; loop_ub++) {
    if ((r[loop_ub]) && (r1[loop_ub])) {
      trueCount++;
    }
  }
  r5.set_size(trueCount);
  trueCount = 0;
  for (loop_ub = 0; loop_ub <= end; loop_ub++) {
    if ((r[loop_ub]) && (r1[loop_ub])) {
      r5[trueCount] = loop_ub + 1;
      trueCount++;
    }
  }
  b_x.set_size(r4.size(0));
  loop_ub = r4.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_x[i] = this->BoardCoords
                 [((r4[i] + (this->BoardCoords.size(0) * (b_idx_tmp - 1))) +
                   (this->BoardCoords.size(0) * this->BoardCoords.size(1))) -
                  1] -
             this->BoardCoords
                 [((r5[i] + (this->BoardCoords.size(0) * (idx_tmp - 1))) +
                   (this->BoardCoords.size(0) * this->BoardCoords.size(1))) -
                  1];
  }
  if (std::abs(combineVectorElements(x) / (static_cast<double>(x.size(0)))) >
      std::abs(combineVectorElements(b_x) /
               (static_cast<double>(b_x.size(0))))) {
    coordsToUse[0] = 1.0;
    coordsToUse[1] = 2.0;
  } else {
    coordsToUse[0] = 2.0;
    coordsToUse[1] = 1.0;
  }
  trueCount = this->BoardCoords.size(0);
  newIndices.set_size(1, trueCount);
  for (i = 0; i < trueCount; i++) {
    newIndices[i] = 0.0;
  }
  removedIdx.set_size(1, 0);
  i = this->BoardCoords.size(0);
  for (b_idx_tmp = 0; b_idx_tmp < i; b_idx_tmp++) {
    int i1;
    loop_ub = this->BoardCoords.size(1);
    b_index.set_size(1, loop_ub);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_index[i1] =
          this->BoardCoords[(b_idx_tmp + (this->BoardCoords.size(0) * i1)) +
                            ((this->BoardCoords.size(0) *
                              this->BoardCoords.size(1)) *
                             ((static_cast<int>(coordsToUse[0])) - 1))];
    }
    eml_find(b_index, ii);
    validIdx.set_size(1, ii.size(1));
    loop_ub = ii.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      validIdx[i1] = static_cast<double>(ii[i1]);
    }
    if (validIdx.size(1) >= 2) {
      double coordDist;
      double currCoord;
      double currRad;
      double moveDistMultiplier;
      double refCoordValue;
      boolean_T exitg1;
      if (idx[0] == 1.0) {
        end = static_cast<int>(validIdx[0]);
        moveDistMultiplier = static_cast<double>(end);
        trueCount = static_cast<int>(validIdx[1]);
        i1 = static_cast<int>(coordsToUse[0]);
        coordDist =
            (this->BoardCoords
                 [(b_idx_tmp + (this->BoardCoords.size(0) * (end - 1))) +
                  ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                   (i1 - 1))] -
             this->BoardCoords
                 [(b_idx_tmp + (this->BoardCoords.size(0) * (trueCount - 1))) +
                  ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                   (i1 - 1))]) /
            ((static_cast<double>(trueCount)) - (static_cast<double>(end)));
      } else {
        moveDistMultiplier = ((static_cast<double>(this->BoardCoords.size(1))) -
                              (static_cast<double>(static_cast<int>(
                                  validIdx[validIdx.size(1) - 1])))) +
                             1.0;
        end = static_cast<int>(validIdx[validIdx.size(1) - 1]);
        i1 = static_cast<int>(coordsToUse[0]);
        coordDist =
            (this->BoardCoords
                 [(b_idx_tmp +
                   (this->BoardCoords.size(0) *
                    ((static_cast<int>(validIdx[validIdx.size(1) - 1])) - 1))) +
                  ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                   (i1 - 1))] -
             this->BoardCoords
                 [(b_idx_tmp +
                   (this->BoardCoords.size(0) *
                    ((static_cast<int>(validIdx[validIdx.size(1) - 2])) - 1))) +
                  ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                   (i1 - 1))]) /
            ((static_cast<double>(
                 static_cast<int>(validIdx[validIdx.size(1) - 1]))) -
             (static_cast<double>(
                 static_cast<int>(validIdx[validIdx.size(1) - 2]))));
      }
      trueCount = 0;
      i1 = validIdx.size(1);
      for (idx_tmp = 0; idx_tmp < i1; idx_tmp++) {
        if ((static_cast<int>(validIdx[idx_tmp])) != 0) {
          trueCount++;
        }
      }
      b_index.set_size(1, validIdx.size(1));
      loop_ub = validIdx.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_index[i1] =
            this->BoardCoords
                [(b_idx_tmp + (this->BoardCoords.size(0) *
                               ((static_cast<int>(validIdx[i1])) - 1))) +
                 ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                  ((static_cast<int>(coordsToUse[0])) - 1))];
      }
      b_this.set_size(1, validIdx.size(1));
      loop_ub = validIdx.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_this[i1] =
            this->BoardCoords
                [(b_idx_tmp + (this->BoardCoords.size(0) *
                               ((static_cast<int>(validIdx[i1])) - 1))) +
                 ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                  ((static_cast<int>(coordsToUse[1])) - 1))];
      }
      if (trueCount > 5) {
        trueCount = 4;
      } else {
        trueCount = 2;
      }
      polyfit(b_index, b_this, static_cast<double>(trueCount), validIdx);
      currRad = coordDist / 4.0;
      refCoordValue =
          this->BoardCoords
              [(b_idx_tmp + (this->BoardCoords.size(0) * (end - 1))) +
               ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                ((static_cast<int>(coordsToUse[0])) - 1))];
      currCoord = currRad + refCoordValue;
      exitg1 = false;
      while ((!exitg1) &&
             (std::abs(currCoord - refCoordValue) <
              ((moveDistMultiplier * 1.5) * std::abs(coordDist)))) {
        currPt[0] = 1.0;
        currPt[1] = 2.0;
        if (isequal(coordsToUse, currPt)) {
          if (validIdx.size(1) != 0) {
            y = validIdx[0];
            i1 = validIdx.size(1);
            for (idx_tmp = 0; idx_tmp <= (i1 - 2); idx_tmp++) {
              y = (currCoord * y) + validIdx[idx_tmp + 1];
            }
          }
          currPt[0] = currCoord;
          currPt[1] = y;
        } else {
          if (validIdx.size(1) != 0) {
            y = validIdx[0];
            i1 = validIdx.size(1);
            for (idx_tmp = 0; idx_tmp <= (i1 - 2); idx_tmp++) {
              y = (currCoord * y) + validIdx[idx_tmp + 1];
            }
          }
          currPt[0] = y;
          currPt[1] = currCoord;
        }
        this->findClosestOnCurve(currPt, std::abs(currRad), validIdx,
                                 coordsToUse, removedIdx, b_index);
        if (b_index.size(1) != 0) {
          newIndices[b_idx_tmp] = b_index[0];
          i1 = removedIdx.size(1);
          loop_ub = b_index.size(1);
          removedIdx.set_size(removedIdx.size(0),
                              removedIdx.size(1) + b_index.size(1));
          for (trueCount = 0; trueCount < loop_ub; trueCount++) {
            removedIdx[i1 + trueCount] = b_index[trueCount];
          }
          exitg1 = true;
        } else {
          currCoord += currRad;
        }
      }
    }
  }
}

//
// Arguments    : float oldEnergy
// Return Type  : float
//
float Checkerboard::computeNewEnergyHorizontal(float oldEnergy) const
{
  array<double, 3U> c_this;
  array<double, 3U> denom;
  array<double, 3U> num;
  array<double, 2U> b_denom;
  array<double, 2U> b_num;
  array<double, 2U> validNewColIdx;
  array<double, 1U> b_x;
  array<double, 1U> b_y;
  array<int, 1U> r2;
  array<int, 1U> r3;
  array<int, 1U> r4;
  array<int, 1U> r5;
  array<int, 1U> r6;
  array<boolean_T, 2U> b_this;
  array<boolean_T, 1U> r;
  array<boolean_T, 1U> r1;
  array<boolean_T, 1U> x;
  double dv[3];
  float newEnergy;
  int N;
  int b_i;
  int b_loop_ub;
  int i;
  int k;
  int loop_ub;
  boolean_T exitg1;
  boolean_T y;
  loop_ub = this->BoardIdx.size(0);
  r.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r[i] = ((this->BoardIdx[i] > 0.0) &&
            (this->BoardIdx[i + this->BoardIdx.size(0)] > 0.0));
  }
  loop_ub = this->BoardIdx.size(0);
  r1.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r1[i] = (this->BoardIdx[i + (this->BoardIdx.size(0) * 2)] > 0.0);
  }
  newEnergy = 0.0F;
  x.set_size(r.size(0));
  loop_ub = r.size(0);
  for (i = 0; i < loop_ub; i++) {
    x[i] = ((r[i]) && (r1[i]));
  }
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= (x.size(0) - 1))) {
    if (!x[k]) {
      k++;
    } else {
      y = true;
      exitg1 = true;
    }
  }
  if (y) {
    k = r.size(0) - 1;
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((r[b_i]) && (r1[b_i])) {
        N++;
      }
    }
    r2.set_size(N);
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((r[b_i]) && (r1[b_i])) {
        r2[N] = b_i + 1;
        N++;
      }
    }
    k = r.size(0) - 1;
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((r[b_i]) && (r1[b_i])) {
        N++;
      }
    }
    r3.set_size(N);
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((r[b_i]) && (r1[b_i])) {
        r3[N] = b_i + 1;
        N++;
      }
    }
    k = r.size(0) - 1;
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((r[b_i]) && (r1[b_i])) {
        N++;
      }
    }
    r4.set_size(N);
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((r[b_i]) && (r1[b_i])) {
        r4[N] = b_i + 1;
        N++;
      }
    }
    loop_ub = this->BoardCoords.size(2);
    c_this.set_size(r2.size(0), 1, loop_ub);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r2.size(0);
      for (N = 0; N < b_loop_ub; N++) {
        c_this[N + (c_this.size(0) * i)] =
            (this->BoardCoords[(r2[N] + ((this->BoardCoords.size(0) *
                                          this->BoardCoords.size(1)) *
                                         i)) -
                               1] +
             this->BoardCoords[((r3[N] + (this->BoardCoords.size(0) * 2)) +
                                ((this->BoardCoords.size(0) *
                                  this->BoardCoords.size(1)) *
                                 i)) -
                               1]) -
            (2.0 * this->BoardCoords[((r4[N] + this->BoardCoords.size(0)) +
                                      ((this->BoardCoords.size(0) *
                                        this->BoardCoords.size(1)) *
                                       i)) -
                                     1]);
      }
    }
    b_squeeze(c_this, b_num);
    k = r.size(0) - 1;
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((r[b_i]) && (r1[b_i])) {
        N++;
      }
    }
    r5.set_size(N);
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((r[b_i]) && (r1[b_i])) {
        r5[N] = b_i + 1;
        N++;
      }
    }
    k = r.size(0) - 1;
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((r[b_i]) && (r1[b_i])) {
        N++;
      }
    }
    r6.set_size(N);
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((r[b_i]) && (r1[b_i])) {
        r6[N] = b_i + 1;
        N++;
      }
    }
    loop_ub = this->BoardCoords.size(2);
    c_this.set_size(r5.size(0), 1, loop_ub);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r5.size(0);
      for (N = 0; N < b_loop_ub; N++) {
        c_this[N + (c_this.size(0) * i)] =
            this->BoardCoords[(r5[N] + ((this->BoardCoords.size(0) *
                                         this->BoardCoords.size(1)) *
                                        i)) -
                              1] -
            this->BoardCoords[((r6[N] + (this->BoardCoords.size(0) * 2)) +
                               ((this->BoardCoords.size(0) *
                                 this->BoardCoords.size(1)) *
                                i)) -
                              1];
      }
    }
    b_squeeze(c_this, b_denom);
    if (b_num.size(1) > 1) {
      b_x.set_size(b_num.size(0));
      N = b_num.size(0);
      for (k = 0; k < N; k++) {
        b_x[k] = rt_hypotd_snf(b_num[k], b_num[k + b_num.size(0)]);
      }
      b_y.set_size(b_denom.size(0));
      N = b_denom.size(0);
      for (k = 0; k < N; k++) {
        b_y[k] = rt_hypotd_snf(b_denom[k], b_denom[k + b_denom.size(0)]);
      }
      loop_ub = b_x.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_x[i] = b_x[i] / b_y[i];
      }
      newEnergy = std::fmax(
          oldEnergy, static_cast<float>(::coder::internal::maximum(b_x)));
    } else {
      newEnergy =
          std::fmax(oldEnergy, static_cast<float>(static_cast<double>(
                                   rt_hypotd_snf(b_num[0], b_num[1]) /
                                   rt_hypotd_snf(b_denom[0], b_denom[1]))));
    }
  }
  loop_ub = this->BoardIdx.size(0);
  b_this.set_size(1, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    b_this[i] = (this->BoardIdx[i] > 0.0);
  }
  dv[0] = 1.0;
  dv[1] = 1.0;
  dv[2] = 1.0;
  Checkerboard::arrayFind(b_this, dv, validNewColIdx);
  if (validNewColIdx.size(1) != 0) {
    i = validNewColIdx.size(1);
    loop_ub = this->BoardCoords.size(2);
    b_loop_ub = this->BoardCoords.size(2);
    for (b_i = 0; b_i < i; b_i++) {
      double d;
      d = validNewColIdx[b_i];
      num.set_size(1, 1, loop_ub);
      for (N = 0; N < loop_ub; N++) {
        num[N] =
            (this->BoardCoords[((static_cast<int>(d)) +
                                ((this->BoardCoords.size(0) *
                                  this->BoardCoords.size(1)) *
                                 N)) -
                               1] +
             this->BoardCoords
                 [((static_cast<int>(static_cast<double>(d + 2.0))) +
                   ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                    N)) -
                  1]) -
            (2.0 *
             this->BoardCoords
                 [((static_cast<int>(static_cast<double>(d + 1.0))) +
                   ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                    N)) -
                  1]);
      }
      d = validNewColIdx[b_i];
      denom.set_size(1, 1, b_loop_ub);
      for (N = 0; N < b_loop_ub; N++) {
        denom[N] =
            this->BoardCoords[((static_cast<int>(d)) +
                               ((this->BoardCoords.size(0) *
                                 this->BoardCoords.size(1)) *
                                N)) -
                              1] -
            this->BoardCoords
                [((static_cast<int>(static_cast<double>(d + 2.0))) +
                  ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                   N)) -
                 1];
      }
      if (newEnergy != 0.0F) {
        N = num.size(2);
        k = denom.size(2);
        b_x = num.reshape(N);
        b_y = denom.reshape(k);
        newEnergy = std::fmax(newEnergy, static_cast<float>(static_cast<double>(
                                             b_norm(b_x) / b_norm(b_y))));
      } else {
        N = num.size(2);
        k = denom.size(2);
        b_x = num.reshape(N);
        b_y = denom.reshape(k);
        newEnergy = std::fmax(oldEnergy, static_cast<float>(static_cast<double>(
                                             b_norm(b_x) / b_norm(b_y))));
      }
    }
  }
  if (newEnergy != 0.0F) {
    newEnergy =
        (newEnergy * (static_cast<float>(static_cast<int>(
                         this->BoardIdx.size(0) * this->BoardIdx.size(1))))) -
        (static_cast<float>(
            static_cast<int>(this->BoardIdx.size(0) * this->BoardIdx.size(1))));
  } else {
    newEnergy = rtInfF;
  }
  return newEnergy;
}

//
// Arguments    : const ::coder::array<double, 2U> &idx
//                float oldEnergy
// Return Type  : float
//
float Checkerboard::computeNewEnergyHorizontal(
    const ::coder::array<double, 2U> &idx, float oldEnergy) const
{
  array<double, 3U> c_this;
  array<double, 3U> denom;
  array<double, 3U> num;
  array<double, 2U> b_denom;
  array<double, 2U> b_num;
  array<double, 2U> validNewColIdx;
  array<double, 1U> b_x;
  array<double, 1U> b_y;
  array<int, 1U> r2;
  array<int, 1U> r3;
  array<int, 1U> r4;
  array<int, 1U> r5;
  array<int, 1U> r6;
  array<boolean_T, 2U> b_this;
  array<boolean_T, 1U> r;
  array<boolean_T, 1U> r1;
  array<boolean_T, 1U> x;
  double dv[3];
  float newEnergy;
  int N;
  int b_i;
  int b_idx_tmp;
  int b_loop_ub;
  int c_idx_tmp;
  int i;
  int idx_tmp;
  int k;
  int loop_ub;
  boolean_T exitg1;
  boolean_T y;
  idx_tmp = static_cast<int>(idx[0]);
  b_idx_tmp = static_cast<int>(idx[1]);
  loop_ub = this->BoardIdx.size(0);
  r.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r[i] =
        ((this->BoardIdx[i + (this->BoardIdx.size(0) * (idx_tmp - 1))] > 0.0) &&
         (this->BoardIdx[i + (this->BoardIdx.size(0) * (b_idx_tmp - 1))] >
          0.0));
  }
  c_idx_tmp = static_cast<int>(idx[2]);
  loop_ub = this->BoardIdx.size(0);
  r1.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r1[i] =
        (this->BoardIdx[i + (this->BoardIdx.size(0) * (c_idx_tmp - 1))] > 0.0);
  }
  newEnergy = 0.0F;
  x.set_size(r.size(0));
  loop_ub = r.size(0);
  for (i = 0; i < loop_ub; i++) {
    x[i] = ((r[i]) && (r1[i]));
  }
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= (x.size(0) - 1))) {
    if (!x[k]) {
      k++;
    } else {
      y = true;
      exitg1 = true;
    }
  }
  if (y) {
    k = r.size(0) - 1;
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((r[b_i]) && (r1[b_i])) {
        N++;
      }
    }
    r2.set_size(N);
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((r[b_i]) && (r1[b_i])) {
        r2[N] = b_i + 1;
        N++;
      }
    }
    k = r.size(0) - 1;
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((r[b_i]) && (r1[b_i])) {
        N++;
      }
    }
    r3.set_size(N);
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((r[b_i]) && (r1[b_i])) {
        r3[N] = b_i + 1;
        N++;
      }
    }
    k = r.size(0) - 1;
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((r[b_i]) && (r1[b_i])) {
        N++;
      }
    }
    r4.set_size(N);
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((r[b_i]) && (r1[b_i])) {
        r4[N] = b_i + 1;
        N++;
      }
    }
    loop_ub = this->BoardCoords.size(2);
    c_this.set_size(r2.size(0), 1, loop_ub);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r2.size(0);
      for (N = 0; N < b_loop_ub; N++) {
        c_this[N + (c_this.size(0) * i)] =
            (this->BoardCoords
                 [((r2[N] + (this->BoardCoords.size(0) * (idx_tmp - 1))) +
                   ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                    i)) -
                  1] +
             this->BoardCoords
                 [((r3[N] + (this->BoardCoords.size(0) * (c_idx_tmp - 1))) +
                   ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                    i)) -
                  1]) -
            (2.0 *
             this->BoardCoords
                 [((r4[N] + (this->BoardCoords.size(0) * (b_idx_tmp - 1))) +
                   ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                    i)) -
                  1]);
      }
    }
    b_squeeze(c_this, b_num);
    k = r.size(0) - 1;
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((r[b_i]) && (r1[b_i])) {
        N++;
      }
    }
    r5.set_size(N);
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((r[b_i]) && (r1[b_i])) {
        r5[N] = b_i + 1;
        N++;
      }
    }
    k = r.size(0) - 1;
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((r[b_i]) && (r1[b_i])) {
        N++;
      }
    }
    r6.set_size(N);
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((r[b_i]) && (r1[b_i])) {
        r6[N] = b_i + 1;
        N++;
      }
    }
    loop_ub = this->BoardCoords.size(2);
    c_this.set_size(r5.size(0), 1, loop_ub);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r5.size(0);
      for (N = 0; N < b_loop_ub; N++) {
        c_this[N + (c_this.size(0) * i)] =
            this->BoardCoords
                [((r5[N] + (this->BoardCoords.size(0) * (idx_tmp - 1))) +
                  ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                   i)) -
                 1] -
            this->BoardCoords
                [((r6[N] + (this->BoardCoords.size(0) * (c_idx_tmp - 1))) +
                  ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                   i)) -
                 1];
      }
    }
    b_squeeze(c_this, b_denom);
    if (b_num.size(1) > 1) {
      b_x.set_size(b_num.size(0));
      N = b_num.size(0);
      for (k = 0; k < N; k++) {
        b_x[k] = rt_hypotd_snf(b_num[k], b_num[k + b_num.size(0)]);
      }
      b_y.set_size(b_denom.size(0));
      N = b_denom.size(0);
      for (k = 0; k < N; k++) {
        b_y[k] = rt_hypotd_snf(b_denom[k], b_denom[k + b_denom.size(0)]);
      }
      loop_ub = b_x.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_x[i] = b_x[i] / b_y[i];
      }
      newEnergy = std::fmax(
          oldEnergy, static_cast<float>(::coder::internal::maximum(b_x)));
    } else {
      newEnergy =
          std::fmax(oldEnergy, static_cast<float>(static_cast<double>(
                                   rt_hypotd_snf(b_num[0], b_num[1]) /
                                   rt_hypotd_snf(b_denom[0], b_denom[1]))));
    }
  }
  loop_ub = this->BoardIdx.size(0);
  b_this.set_size(1, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    b_this[i] =
        (this->BoardIdx[i + (this->BoardIdx.size(0) * (idx_tmp - 1))] > 0.0);
  }
  dv[0] = 1.0;
  dv[1] = 1.0;
  dv[2] = 1.0;
  Checkerboard::arrayFind(b_this, dv, validNewColIdx);
  if (validNewColIdx.size(1) != 0) {
    i = validNewColIdx.size(1);
    loop_ub = this->BoardCoords.size(2);
    b_loop_ub = this->BoardCoords.size(2);
    for (b_i = 0; b_i < i; b_i++) {
      double d;
      d = validNewColIdx[b_i];
      num.set_size(1, 1, loop_ub);
      for (N = 0; N < loop_ub; N++) {
        num[N] =
            (this->BoardCoords[(((static_cast<int>(d)) +
                                 (this->BoardCoords.size(0) * (idx_tmp - 1))) +
                                ((this->BoardCoords.size(0) *
                                  this->BoardCoords.size(1)) *
                                 N)) -
                               1] +
             this->BoardCoords
                 [(((static_cast<int>(static_cast<double>(d + 2.0))) +
                    (this->BoardCoords.size(0) * (idx_tmp - 1))) +
                   ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                    N)) -
                  1]) -
            (2.0 *
             this->BoardCoords
                 [(((static_cast<int>(static_cast<double>(d + 1.0))) +
                    (this->BoardCoords.size(0) * (idx_tmp - 1))) +
                   ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                    N)) -
                  1]);
      }
      d = validNewColIdx[b_i];
      denom.set_size(1, 1, b_loop_ub);
      for (N = 0; N < b_loop_ub; N++) {
        denom[N] =
            this->BoardCoords[(((static_cast<int>(d)) +
                                (this->BoardCoords.size(0) * (idx_tmp - 1))) +
                               ((this->BoardCoords.size(0) *
                                 this->BoardCoords.size(1)) *
                                N)) -
                              1] -
            this->BoardCoords
                [(((static_cast<int>(static_cast<double>(d + 2.0))) +
                   (this->BoardCoords.size(0) * (idx_tmp - 1))) +
                  ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                   N)) -
                 1];
      }
      if (newEnergy != 0.0F) {
        N = num.size(2);
        k = denom.size(2);
        b_x = num.reshape(N);
        b_y = denom.reshape(k);
        newEnergy = std::fmax(newEnergy, static_cast<float>(static_cast<double>(
                                             b_norm(b_x) / b_norm(b_y))));
      } else {
        N = num.size(2);
        k = denom.size(2);
        b_x = num.reshape(N);
        b_y = denom.reshape(k);
        newEnergy = std::fmax(oldEnergy, static_cast<float>(static_cast<double>(
                                             b_norm(b_x) / b_norm(b_y))));
      }
    }
  }
  if (newEnergy != 0.0F) {
    newEnergy =
        (newEnergy * (static_cast<float>(static_cast<int>(
                         this->BoardIdx.size(0) * this->BoardIdx.size(1))))) -
        (static_cast<float>(
            static_cast<int>(this->BoardIdx.size(0) * this->BoardIdx.size(1))));
  } else {
    newEnergy = rtInfF;
  }
  return newEnergy;
}

//
// Arguments    : float oldEnergy
// Return Type  : float
//
float Checkerboard::computeNewEnergyVertical(float oldEnergy) const
{
  array<double, 3U> b;
  array<double, 3U> denom;
  array<double, 3U> num;
  array<double, 3U> r2;
  array<double, 3U> r4;
  array<double, 2U> b_denom;
  array<double, 2U> b_num;
  array<double, 2U> validNewRowIdx;
  array<double, 1U> b_x;
  array<double, 1U> b_y;
  array<int, 2U> r1;
  array<int, 2U> r3;
  array<int, 2U> r5;
  array<int, 2U> r6;
  array<int, 2U> r7;
  array<boolean_T, 2U> b_this;
  array<boolean_T, 2U> r;
  array<boolean_T, 2U> x;
  double dv[3];
  float newEnergy;
  int N;
  int b_i;
  int b_loop_ub;
  int i;
  int k;
  int loop_ub;
  boolean_T exitg1;
  boolean_T y;
  loop_ub = this->BoardIdx.size(1);
  b_this.set_size(1, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    b_this[i] = ((this->BoardIdx[this->BoardIdx.size(0) * i] > 0.0) &&
                 (this->BoardIdx[(this->BoardIdx.size(0) * i) + 1] > 0.0));
  }
  loop_ub = this->BoardIdx.size(1);
  r.set_size(1, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r[i] = (this->BoardIdx[(this->BoardIdx.size(0) * i) + 2] > 0.0);
  }
  newEnergy = 0.0F;
  x.set_size(1, b_this.size(1));
  loop_ub = b_this.size(1);
  for (i = 0; i < loop_ub; i++) {
    x[i] = ((b_this[i]) && (r[i]));
  }
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= (x.size(1) - 1))) {
    if (!x[k]) {
      k++;
    } else {
      y = true;
      exitg1 = true;
    }
  }
  if (y) {
    k = b_this.size(1) - 1;
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((b_this[b_i]) && (r[b_i])) {
        N++;
      }
    }
    r1.set_size(1, N);
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((b_this[b_i]) && (r[b_i])) {
        r1[N] = b_i + 1;
        N++;
      }
    }
    loop_ub = this->BoardCoords.size(2);
    r2.set_size(1, r1.size(1), loop_ub);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r1.size(1);
      for (N = 0; N < b_loop_ub; N++) {
        r2[N + (r2.size(1) * i)] =
            this->BoardCoords
                [(this->BoardCoords.size(0) * (r1[N] - 1)) +
                 ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) * i)];
      }
    }
    k = b_this.size(1) - 1;
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((b_this[b_i]) && (r[b_i])) {
        N++;
      }
    }
    r3.set_size(1, N);
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((b_this[b_i]) && (r[b_i])) {
        r3[N] = b_i + 1;
        N++;
      }
    }
    loop_ub = this->BoardCoords.size(2);
    r4.set_size(1, r3.size(1), loop_ub);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r3.size(1);
      for (N = 0; N < b_loop_ub; N++) {
        r4[N + (r4.size(1) * i)] =
            this->BoardCoords[((this->BoardCoords.size(0) * (r3[N] - 1)) +
                               ((this->BoardCoords.size(0) *
                                 this->BoardCoords.size(1)) *
                                i)) +
                              2];
      }
    }
    k = b_this.size(1) - 1;
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((b_this[b_i]) && (r[b_i])) {
        N++;
      }
    }
    r5.set_size(1, N);
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((b_this[b_i]) && (r[b_i])) {
        r5[N] = b_i + 1;
        N++;
      }
    }
    loop_ub = this->BoardCoords.size(2);
    b.set_size(1, r5.size(1), loop_ub);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r5.size(1);
      for (N = 0; N < b_loop_ub; N++) {
        b[N + (b.size(1) * i)] =
            this->BoardCoords[((this->BoardCoords.size(0) * (r5[N] - 1)) +
                               ((this->BoardCoords.size(0) *
                                 this->BoardCoords.size(1)) *
                                i)) +
                              1];
      }
    }
    r2.set_size(1, r2.size(1), r2.size(2));
    loop_ub = r2.size(2);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r2.size(1);
      for (N = 0; N < b_loop_ub; N++) {
        r2[N + (r2.size(1) * i)] =
            (r2[N + (r2.size(1) * i)] + r4[N + (r4.size(1) * i)]) -
            (2.0 * b[N + (b.size(1) * i)]);
      }
    }
    squeeze(r2, b_num);
    k = b_this.size(1) - 1;
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((b_this[b_i]) && (r[b_i])) {
        N++;
      }
    }
    r6.set_size(1, N);
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((b_this[b_i]) && (r[b_i])) {
        r6[N] = b_i + 1;
        N++;
      }
    }
    loop_ub = this->BoardCoords.size(2);
    r2.set_size(1, r6.size(1), loop_ub);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r6.size(1);
      for (N = 0; N < b_loop_ub; N++) {
        r2[N + (r2.size(1) * i)] =
            this->BoardCoords
                [(this->BoardCoords.size(0) * (r6[N] - 1)) +
                 ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) * i)];
      }
    }
    k = b_this.size(1) - 1;
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((b_this[b_i]) && (r[b_i])) {
        N++;
      }
    }
    r7.set_size(1, N);
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((b_this[b_i]) && (r[b_i])) {
        r7[N] = b_i + 1;
        N++;
      }
    }
    loop_ub = this->BoardCoords.size(2);
    r4.set_size(1, r7.size(1), loop_ub);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r7.size(1);
      for (N = 0; N < b_loop_ub; N++) {
        r4[N + (r4.size(1) * i)] =
            this->BoardCoords[((this->BoardCoords.size(0) * (r7[N] - 1)) +
                               ((this->BoardCoords.size(0) *
                                 this->BoardCoords.size(1)) *
                                i)) +
                              2];
      }
    }
    r2.set_size(1, r2.size(1), r2.size(2));
    loop_ub = r2.size(2);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r2.size(1);
      for (N = 0; N < b_loop_ub; N++) {
        r2[N + (r2.size(1) * i)] =
            r2[N + (r2.size(1) * i)] - r4[N + (r4.size(1) * i)];
      }
    }
    squeeze(r2, b_denom);
    if (b_num.size(1) > 1) {
      b_x.set_size(b_num.size(0));
      N = b_num.size(0);
      for (k = 0; k < N; k++) {
        b_x[k] = rt_hypotd_snf(b_num[k], b_num[k + b_num.size(0)]);
      }
      b_y.set_size(b_denom.size(0));
      N = b_denom.size(0);
      for (k = 0; k < N; k++) {
        b_y[k] = rt_hypotd_snf(b_denom[k], b_denom[k + b_denom.size(0)]);
      }
      loop_ub = b_x.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_x[i] = b_x[i] / b_y[i];
      }
      newEnergy = std::fmax(
          oldEnergy, static_cast<float>(::coder::internal::maximum(b_x)));
    } else {
      newEnergy =
          std::fmax(oldEnergy, static_cast<float>(static_cast<double>(
                                   rt_hypotd_snf(b_num[0], b_num[1]) /
                                   rt_hypotd_snf(b_denom[0], b_denom[1]))));
    }
  }
  loop_ub = this->BoardIdx.size(1);
  b_this.set_size(1, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    b_this[i] = (this->BoardIdx[this->BoardIdx.size(0) * i] > 0.0);
  }
  dv[0] = 1.0;
  dv[1] = 1.0;
  dv[2] = 1.0;
  Checkerboard::arrayFind(b_this, dv, validNewRowIdx);
  if (validNewRowIdx.size(1) != 0) {
    i = validNewRowIdx.size(1);
    loop_ub = this->BoardCoords.size(2);
    b_loop_ub = this->BoardCoords.size(2);
    for (b_i = 0; b_i < i; b_i++) {
      double d;
      d = validNewRowIdx[b_i];
      num.set_size(1, 1, loop_ub);
      for (N = 0; N < loop_ub; N++) {
        num[N] =
            (this->BoardCoords
                 [(this->BoardCoords.size(0) * ((static_cast<int>(d)) - 1)) +
                  ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                   N)] +
             this->BoardCoords
                 [(this->BoardCoords.size(0) *
                   ((static_cast<int>(static_cast<double>(d + 2.0))) - 1)) +
                  ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                   N)]) -
            (2.0 *
             this->BoardCoords
                 [(this->BoardCoords.size(0) *
                   ((static_cast<int>(static_cast<double>(d + 1.0))) - 1)) +
                  ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                   N)]);
      }
      d = validNewRowIdx[b_i];
      denom.set_size(1, 1, b_loop_ub);
      for (N = 0; N < b_loop_ub; N++) {
        denom[N] =
            this->BoardCoords
                [(this->BoardCoords.size(0) * ((static_cast<int>(d)) - 1)) +
                 ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                  N)] -
            this->BoardCoords
                [(this->BoardCoords.size(0) *
                  ((static_cast<int>(static_cast<double>(d + 2.0))) - 1)) +
                 ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) * N)];
      }
      if (newEnergy != 0.0F) {
        N = num.size(2);
        k = denom.size(2);
        b_x = num.reshape(N);
        b_y = denom.reshape(k);
        newEnergy = std::fmax(newEnergy, static_cast<float>(static_cast<double>(
                                             b_norm(b_x) / b_norm(b_y))));
      } else {
        N = num.size(2);
        k = denom.size(2);
        b_x = num.reshape(N);
        b_y = denom.reshape(k);
        newEnergy = std::fmax(oldEnergy, static_cast<float>(static_cast<double>(
                                             b_norm(b_x) / b_norm(b_y))));
      }
    }
  }
  if (newEnergy != 0.0F) {
    newEnergy =
        (newEnergy * (static_cast<float>(static_cast<int>(
                         this->BoardIdx.size(0) * this->BoardIdx.size(1))))) -
        (static_cast<float>(
            static_cast<int>(this->BoardIdx.size(0) * this->BoardIdx.size(1))));
  } else {
    newEnergy = rtInfF;
  }
  return newEnergy;
}

//
// Arguments    : const ::coder::array<double, 2U> &idx
//                float oldEnergy
// Return Type  : float
//
float Checkerboard::computeNewEnergyVertical(
    const ::coder::array<double, 2U> &idx, float oldEnergy) const
{
  array<double, 3U> b;
  array<double, 3U> denom;
  array<double, 3U> num;
  array<double, 3U> r2;
  array<double, 3U> r4;
  array<double, 2U> b_denom;
  array<double, 2U> b_num;
  array<double, 2U> validNewRowIdx;
  array<double, 1U> b_x;
  array<double, 1U> b_y;
  array<int, 2U> r1;
  array<int, 2U> r3;
  array<int, 2U> r5;
  array<int, 2U> r6;
  array<int, 2U> r7;
  array<boolean_T, 2U> b_this;
  array<boolean_T, 2U> r;
  array<boolean_T, 2U> x;
  double dv[3];
  float newEnergy;
  int N;
  int b_i;
  int b_idx_tmp;
  int b_loop_ub;
  int c_idx_tmp;
  int i;
  int idx_tmp;
  int k;
  int loop_ub;
  boolean_T exitg1;
  boolean_T y;
  idx_tmp = static_cast<int>(idx[0]);
  b_idx_tmp = static_cast<int>(idx[1]);
  loop_ub = this->BoardIdx.size(1);
  b_this.set_size(1, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    b_this[i] =
        ((this->BoardIdx[(idx_tmp + (this->BoardIdx.size(0) * i)) - 1] > 0.0) &&
         (this->BoardIdx[(b_idx_tmp + (this->BoardIdx.size(0) * i)) - 1] >
          0.0));
  }
  c_idx_tmp = static_cast<int>(idx[2]);
  loop_ub = this->BoardIdx.size(1);
  r.set_size(1, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r[i] =
        (this->BoardIdx[(c_idx_tmp + (this->BoardIdx.size(0) * i)) - 1] > 0.0);
  }
  newEnergy = 0.0F;
  x.set_size(1, b_this.size(1));
  loop_ub = b_this.size(1);
  for (i = 0; i < loop_ub; i++) {
    x[i] = ((b_this[i]) && (r[i]));
  }
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= (x.size(1) - 1))) {
    if (!x[k]) {
      k++;
    } else {
      y = true;
      exitg1 = true;
    }
  }
  if (y) {
    k = b_this.size(1) - 1;
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((b_this[b_i]) && (r[b_i])) {
        N++;
      }
    }
    r1.set_size(1, N);
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((b_this[b_i]) && (r[b_i])) {
        r1[N] = b_i + 1;
        N++;
      }
    }
    loop_ub = this->BoardCoords.size(2);
    r2.set_size(1, r1.size(1), loop_ub);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r1.size(1);
      for (N = 0; N < b_loop_ub; N++) {
        r2[N + (r2.size(1) * i)] =
            this->BoardCoords
                [((idx_tmp + (this->BoardCoords.size(0) * (r1[N] - 1))) +
                  ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                   i)) -
                 1];
      }
    }
    k = b_this.size(1) - 1;
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((b_this[b_i]) && (r[b_i])) {
        N++;
      }
    }
    r3.set_size(1, N);
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((b_this[b_i]) && (r[b_i])) {
        r3[N] = b_i + 1;
        N++;
      }
    }
    loop_ub = this->BoardCoords.size(2);
    r4.set_size(1, r3.size(1), loop_ub);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r3.size(1);
      for (N = 0; N < b_loop_ub; N++) {
        r4[N + (r4.size(1) * i)] =
            this->BoardCoords
                [((c_idx_tmp + (this->BoardCoords.size(0) * (r3[N] - 1))) +
                  ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                   i)) -
                 1];
      }
    }
    k = b_this.size(1) - 1;
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((b_this[b_i]) && (r[b_i])) {
        N++;
      }
    }
    r5.set_size(1, N);
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((b_this[b_i]) && (r[b_i])) {
        r5[N] = b_i + 1;
        N++;
      }
    }
    loop_ub = this->BoardCoords.size(2);
    b.set_size(1, r5.size(1), loop_ub);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r5.size(1);
      for (N = 0; N < b_loop_ub; N++) {
        b[N + (b.size(1) * i)] =
            this->BoardCoords
                [((b_idx_tmp + (this->BoardCoords.size(0) * (r5[N] - 1))) +
                  ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                   i)) -
                 1];
      }
    }
    r2.set_size(1, r2.size(1), r2.size(2));
    loop_ub = r2.size(2);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r2.size(1);
      for (N = 0; N < b_loop_ub; N++) {
        r2[N + (r2.size(1) * i)] =
            (r2[N + (r2.size(1) * i)] + r4[N + (r4.size(1) * i)]) -
            (2.0 * b[N + (b.size(1) * i)]);
      }
    }
    squeeze(r2, b_num);
    k = b_this.size(1) - 1;
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((b_this[b_i]) && (r[b_i])) {
        N++;
      }
    }
    r6.set_size(1, N);
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((b_this[b_i]) && (r[b_i])) {
        r6[N] = b_i + 1;
        N++;
      }
    }
    loop_ub = this->BoardCoords.size(2);
    r2.set_size(1, r6.size(1), loop_ub);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r6.size(1);
      for (N = 0; N < b_loop_ub; N++) {
        r2[N + (r2.size(1) * i)] =
            this->BoardCoords
                [((idx_tmp + (this->BoardCoords.size(0) * (r6[N] - 1))) +
                  ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                   i)) -
                 1];
      }
    }
    k = b_this.size(1) - 1;
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((b_this[b_i]) && (r[b_i])) {
        N++;
      }
    }
    r7.set_size(1, N);
    N = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if ((b_this[b_i]) && (r[b_i])) {
        r7[N] = b_i + 1;
        N++;
      }
    }
    loop_ub = this->BoardCoords.size(2);
    r4.set_size(1, r7.size(1), loop_ub);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r7.size(1);
      for (N = 0; N < b_loop_ub; N++) {
        r4[N + (r4.size(1) * i)] =
            this->BoardCoords
                [((c_idx_tmp + (this->BoardCoords.size(0) * (r7[N] - 1))) +
                  ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                   i)) -
                 1];
      }
    }
    r2.set_size(1, r2.size(1), r2.size(2));
    loop_ub = r2.size(2);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r2.size(1);
      for (N = 0; N < b_loop_ub; N++) {
        r2[N + (r2.size(1) * i)] =
            r2[N + (r2.size(1) * i)] - r4[N + (r4.size(1) * i)];
      }
    }
    squeeze(r2, b_denom);
    if (b_num.size(1) > 1) {
      b_x.set_size(b_num.size(0));
      N = b_num.size(0);
      for (k = 0; k < N; k++) {
        b_x[k] = rt_hypotd_snf(b_num[k], b_num[k + b_num.size(0)]);
      }
      b_y.set_size(b_denom.size(0));
      N = b_denom.size(0);
      for (k = 0; k < N; k++) {
        b_y[k] = rt_hypotd_snf(b_denom[k], b_denom[k + b_denom.size(0)]);
      }
      loop_ub = b_x.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_x[i] = b_x[i] / b_y[i];
      }
      newEnergy = std::fmax(
          oldEnergy, static_cast<float>(::coder::internal::maximum(b_x)));
    } else {
      newEnergy =
          std::fmax(oldEnergy, static_cast<float>(static_cast<double>(
                                   rt_hypotd_snf(b_num[0], b_num[1]) /
                                   rt_hypotd_snf(b_denom[0], b_denom[1]))));
    }
  }
  loop_ub = this->BoardIdx.size(1);
  b_this.set_size(1, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    b_this[i] =
        (this->BoardIdx[(idx_tmp + (this->BoardIdx.size(0) * i)) - 1] > 0.0);
  }
  dv[0] = 1.0;
  dv[1] = 1.0;
  dv[2] = 1.0;
  Checkerboard::arrayFind(b_this, dv, validNewRowIdx);
  if (validNewRowIdx.size(1) != 0) {
    i = validNewRowIdx.size(1);
    loop_ub = this->BoardCoords.size(2);
    b_loop_ub = this->BoardCoords.size(2);
    for (b_i = 0; b_i < i; b_i++) {
      double d;
      d = validNewRowIdx[b_i];
      num.set_size(1, 1, loop_ub);
      for (N = 0; N < loop_ub; N++) {
        num[N] =
            (this->BoardCoords[((idx_tmp + (this->BoardCoords.size(0) *
                                            ((static_cast<int>(d)) - 1))) +
                                ((this->BoardCoords.size(0) *
                                  this->BoardCoords.size(1)) *
                                 N)) -
                               1] +
             this->BoardCoords
                 [((idx_tmp +
                    (this->BoardCoords.size(0) *
                     ((static_cast<int>(static_cast<double>(d + 2.0))) - 1))) +
                   ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                    N)) -
                  1]) -
            (2.0 *
             this->BoardCoords
                 [((idx_tmp +
                    (this->BoardCoords.size(0) *
                     ((static_cast<int>(static_cast<double>(d + 1.0))) - 1))) +
                   ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                    N)) -
                  1]);
      }
      d = validNewRowIdx[b_i];
      denom.set_size(1, 1, b_loop_ub);
      for (N = 0; N < b_loop_ub; N++) {
        denom[N] =
            this->BoardCoords[((idx_tmp + (this->BoardCoords.size(0) *
                                           ((static_cast<int>(d)) - 1))) +
                               ((this->BoardCoords.size(0) *
                                 this->BoardCoords.size(1)) *
                                N)) -
                              1] -
            this->BoardCoords
                [((idx_tmp +
                   (this->BoardCoords.size(0) *
                    ((static_cast<int>(static_cast<double>(d + 2.0))) - 1))) +
                  ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                   N)) -
                 1];
      }
      if (newEnergy != 0.0F) {
        N = num.size(2);
        k = denom.size(2);
        b_x = num.reshape(N);
        b_y = denom.reshape(k);
        newEnergy = std::fmax(newEnergy, static_cast<float>(static_cast<double>(
                                             b_norm(b_x) / b_norm(b_y))));
      } else {
        N = num.size(2);
        k = denom.size(2);
        b_x = num.reshape(N);
        b_y = denom.reshape(k);
        newEnergy = std::fmax(oldEnergy, static_cast<float>(static_cast<double>(
                                             b_norm(b_x) / b_norm(b_y))));
      }
    }
  }
  if (newEnergy != 0.0F) {
    newEnergy =
        (newEnergy * (static_cast<float>(static_cast<int>(
                         this->BoardIdx.size(0) * this->BoardIdx.size(1))))) -
        (static_cast<float>(
            static_cast<int>(this->BoardIdx.size(0) * this->BoardIdx.size(1))));
  } else {
    newEnergy = rtInfF;
  }
  return newEnergy;
}

//
// Arguments    : const ::coder::array<double, 2U> &indices
//                ::coder::array<double, 2U> &newBoard
//                ::coder::array<double, 3U> &newBoardCoords
// Return Type  : void
//
void Checkerboard::expandBoardLeft(
    const ::coder::array<double, 2U> &indices,
    ::coder::array<double, 2U> &newBoard,
    ::coder::array<double, 3U> &newBoardCoords) const
{
  array<double, 2U> r2;
  array<int, 2U> r1;
  array<int, 2U> r3;
  array<int, 1U> r;
  int i;
  int i1;
  int i2;
  int loop_ub;
  int this_idx_0;
  int this_idx_1;
  int this_idx_2;
  this_idx_0 = this->BoardIdx.size(0);
  this_idx_1 = this->BoardIdx.size(1) + 1;
  newBoard.set_size(this_idx_0, this_idx_1);
  for (i = 0; i < this_idx_1; i++) {
    for (i1 = 0; i1 < this_idx_0; i1++) {
      newBoard[i1 + (newBoard.size(0) * i)] = 0.0;
    }
  }
  loop_ub = this->BoardIdx.size(0);
  r.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r[i] = i;
  }
  loop_ub = r.size(0);
  for (i = 0; i < loop_ub; i++) {
    newBoard[r[i]] = indices[i];
  }
  i = (2 <= newBoard.size(1));
  loop_ub = this->BoardIdx.size(1);
  for (i1 = 0; i1 < loop_ub; i1++) {
    this_idx_1 = this->BoardIdx.size(0);
    for (i2 = 0; i2 < this_idx_1; i2++) {
      newBoard[i2 + (newBoard.size(0) * (i + i1))] =
          this->BoardIdx[i2 + (this->BoardIdx.size(0) * i1)];
    }
  }
  this_idx_0 = this->BoardCoords.size(0);
  this_idx_1 = this->BoardCoords.size(1) + 1;
  this_idx_2 = this->BoardCoords.size(2);
  newBoardCoords.set_size(this_idx_0, this_idx_1, this_idx_2);
  for (i = 0; i < this_idx_2; i++) {
    for (i1 = 0; i1 < this_idx_1; i1++) {
      for (i2 = 0; i2 < this_idx_0; i2++) {
        newBoardCoords[(i2 + (newBoardCoords.size(0) * i1)) +
                       ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                        i)] = 0.0;
      }
    }
  }
  loop_ub = this->BoardCoords.size(2);
  r.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r[i] = i;
  }
  this_idx_2 = indices.size(1) - 1;
  this_idx_1 = 0;
  for (this_idx_0 = 0; this_idx_0 <= this_idx_2; this_idx_0++) {
    if (indices[this_idx_0] > 0.0) {
      this_idx_1++;
    }
  }
  r1.set_size(1, this_idx_1);
  this_idx_1 = 0;
  for (this_idx_0 = 0; this_idx_0 <= this_idx_2; this_idx_0++) {
    if (indices[this_idx_0] > 0.0) {
      r1[this_idx_1] = this_idx_0 + 1;
      this_idx_1++;
    }
  }
  loop_ub = this->Points.size(1);
  r2.set_size(r1.size(1), loop_ub);
  for (i = 0; i < loop_ub; i++) {
    this_idx_1 = r1.size(1);
    for (i1 = 0; i1 < this_idx_1; i1++) {
      r2[i1 + (r2.size(0) * i)] = static_cast<double>(
          this->Points[((static_cast<int>(indices[r1[i1] - 1])) +
                        (this->Points.size(0) * i)) -
                       1]);
    }
  }
  this_idx_2 = indices.size(1) - 1;
  this_idx_1 = 0;
  for (this_idx_0 = 0; this_idx_0 <= this_idx_2; this_idx_0++) {
    if (indices[this_idx_0] > 0.0) {
      this_idx_1++;
    }
  }
  r3.set_size(1, this_idx_1);
  this_idx_1 = 0;
  for (this_idx_0 = 0; this_idx_0 <= this_idx_2; this_idx_0++) {
    if (indices[this_idx_0] > 0.0) {
      r3[this_idx_1] = this_idx_0 + 1;
      this_idx_1++;
    }
  }
  this_idx_0 = r3.size(1);
  loop_ub = r.size(0);
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < this_idx_0; i1++) {
      newBoardCoords[(r3[i1] +
                      ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                       r[i])) -
                     1] = r2[i1 + (this_idx_0 * i)];
    }
  }
  i = (2 <= newBoardCoords.size(1));
  loop_ub = this->BoardCoords.size(2);
  for (i1 = 0; i1 < loop_ub; i1++) {
    this_idx_1 = this->BoardCoords.size(1);
    for (i2 = 0; i2 < this_idx_1; i2++) {
      this_idx_2 = this->BoardCoords.size(0);
      for (this_idx_0 = 0; this_idx_0 < this_idx_2; this_idx_0++) {
        newBoardCoords[(this_idx_0 + (newBoardCoords.size(0) * (i + i2))) +
                       ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                        i1)] =
            this->BoardCoords[(this_idx_0 + (this->BoardCoords.size(0) * i2)) +
                              ((this->BoardCoords.size(0) *
                                this->BoardCoords.size(1)) *
                               i1)];
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &indices
//                ::coder::array<double, 2U> &newBoard
//                ::coder::array<double, 3U> &newBoardCoords
// Return Type  : void
//
void Checkerboard::expandBoardRight(
    const ::coder::array<double, 2U> &indices,
    ::coder::array<double, 2U> &newBoard,
    ::coder::array<double, 3U> &newBoardCoords) const
{
  array<double, 2U> r2;
  array<int, 2U> r1;
  array<int, 2U> r3;
  array<int, 1U> r;
  int b_this;
  int i;
  int i1;
  int i2;
  int loop_ub;
  int this_idx_0;
  int this_idx_1;
  this_idx_0 = this->BoardIdx.size(0);
  this_idx_1 = this->BoardIdx.size(1) + 1;
  newBoard.set_size(this_idx_0, this_idx_1);
  for (i = 0; i < this_idx_1; i++) {
    for (i1 = 0; i1 < this_idx_0; i1++) {
      newBoard[i1 + (newBoard.size(0) * i)] = 0.0;
    }
  }
  loop_ub = this->BoardIdx.size(0);
  r.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r[i] = i;
  }
  b_this = this->BoardIdx.size(1);
  loop_ub = r.size(0);
  for (i = 0; i < loop_ub; i++) {
    newBoard[r[i] + (newBoard.size(0) * b_this)] = indices[i];
  }
  loop_ub = this->BoardIdx.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_this = this->BoardIdx.size(0);
    for (i1 = 0; i1 < b_this; i1++) {
      newBoard[i1 + (newBoard.size(0) * i)] =
          this->BoardIdx[i1 + (this->BoardIdx.size(0) * i)];
    }
  }
  this_idx_0 = this->BoardCoords.size(0);
  this_idx_1 = this->BoardCoords.size(1) + 1;
  b_this = this->BoardCoords.size(2);
  newBoardCoords.set_size(this_idx_0, this_idx_1, b_this);
  for (i = 0; i < b_this; i++) {
    for (i1 = 0; i1 < this_idx_1; i1++) {
      for (i2 = 0; i2 < this_idx_0; i2++) {
        newBoardCoords[(i2 + (newBoardCoords.size(0) * i1)) +
                       ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                        i)] = 0.0;
      }
    }
  }
  loop_ub = this->BoardCoords.size(2);
  r.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r[i] = i;
  }
  this_idx_1 = indices.size(1) - 1;
  b_this = 0;
  for (this_idx_0 = 0; this_idx_0 <= this_idx_1; this_idx_0++) {
    if (indices[this_idx_0] > 0.0) {
      b_this++;
    }
  }
  r1.set_size(1, b_this);
  b_this = 0;
  for (this_idx_0 = 0; this_idx_0 <= this_idx_1; this_idx_0++) {
    if (indices[this_idx_0] > 0.0) {
      r1[b_this] = this_idx_0 + 1;
      b_this++;
    }
  }
  loop_ub = this->Points.size(1);
  r2.set_size(r1.size(1), loop_ub);
  for (i = 0; i < loop_ub; i++) {
    b_this = r1.size(1);
    for (i1 = 0; i1 < b_this; i1++) {
      r2[i1 + (r2.size(0) * i)] = static_cast<double>(
          this->Points[((static_cast<int>(indices[r1[i1] - 1])) +
                        (this->Points.size(0) * i)) -
                       1]);
    }
  }
  this_idx_1 = indices.size(1) - 1;
  b_this = 0;
  for (this_idx_0 = 0; this_idx_0 <= this_idx_1; this_idx_0++) {
    if (indices[this_idx_0] > 0.0) {
      b_this++;
    }
  }
  r3.set_size(1, b_this);
  b_this = 0;
  for (this_idx_0 = 0; this_idx_0 <= this_idx_1; this_idx_0++) {
    if (indices[this_idx_0] > 0.0) {
      r3[b_this] = this_idx_0 + 1;
      b_this++;
    }
  }
  this_idx_0 = r3.size(1);
  b_this = this->BoardCoords.size(1);
  loop_ub = r.size(0);
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < this_idx_0; i1++) {
      newBoardCoords[((r3[i1] + (newBoardCoords.size(0) * b_this)) +
                      ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                       r[i])) -
                     1] = r2[i1 + (this_idx_0 * i)];
    }
  }
  loop_ub = this->BoardCoords.size(2);
  for (i = 0; i < loop_ub; i++) {
    b_this = this->BoardCoords.size(1);
    for (i1 = 0; i1 < b_this; i1++) {
      this_idx_1 = this->BoardCoords.size(0);
      for (i2 = 0; i2 < this_idx_1; i2++) {
        newBoardCoords[(i2 + (newBoardCoords.size(0) * i1)) +
                       ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                        i)] =
            this->BoardCoords
                [(i2 + (this->BoardCoords.size(0) * i1)) +
                 ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) * i)];
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &indices
//                ::coder::array<double, 2U> &newBoard
//                ::coder::array<double, 3U> &newBoardCoords
// Return Type  : void
//
void Checkerboard::expandBoardUp(
    const ::coder::array<double, 2U> &indices,
    ::coder::array<double, 2U> &newBoard,
    ::coder::array<double, 3U> &newBoardCoords) const
{
  array<double, 2U> r2;
  array<int, 2U> r1;
  array<int, 2U> r3;
  array<int, 1U> r;
  int i;
  int i1;
  int i2;
  int loop_ub;
  int this_idx_0;
  int this_idx_1;
  int this_idx_2;
  this_idx_0 = this->BoardIdx.size(0) + 1;
  this_idx_1 = this->BoardIdx.size(1);
  newBoard.set_size(this_idx_0, this_idx_1);
  for (i = 0; i < this_idx_1; i++) {
    for (i1 = 0; i1 < this_idx_0; i1++) {
      newBoard[i1 + (newBoard.size(0) * i)] = 0.0;
    }
  }
  loop_ub = indices.size(1);
  for (i = 0; i < loop_ub; i++) {
    newBoard[newBoard.size(0) * i] = indices[i];
  }
  i = (2 <= newBoard.size(0));
  loop_ub = this->BoardIdx.size(1);
  for (i1 = 0; i1 < loop_ub; i1++) {
    this_idx_0 = this->BoardIdx.size(0);
    for (i2 = 0; i2 < this_idx_0; i2++) {
      newBoard[(i + i2) + (newBoard.size(0) * i1)] =
          this->BoardIdx[i2 + (this->BoardIdx.size(0) * i1)];
    }
  }
  this_idx_0 = this->BoardCoords.size(0) + 1;
  this_idx_1 = this->BoardCoords.size(1);
  this_idx_2 = this->BoardCoords.size(2);
  newBoardCoords.set_size(this_idx_0, this_idx_1, this_idx_2);
  for (i = 0; i < this_idx_2; i++) {
    for (i1 = 0; i1 < this_idx_1; i1++) {
      for (i2 = 0; i2 < this_idx_0; i2++) {
        newBoardCoords[(i2 + (newBoardCoords.size(0) * i1)) +
                       ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                        i)] = 0.0;
      }
    }
  }
  loop_ub = this->BoardCoords.size(2);
  r.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r[i] = i;
  }
  this_idx_2 = indices.size(1) - 1;
  this_idx_0 = 0;
  for (this_idx_1 = 0; this_idx_1 <= this_idx_2; this_idx_1++) {
    if (indices[this_idx_1] > 0.0) {
      this_idx_0++;
    }
  }
  r1.set_size(1, this_idx_0);
  this_idx_0 = 0;
  for (this_idx_1 = 0; this_idx_1 <= this_idx_2; this_idx_1++) {
    if (indices[this_idx_1] > 0.0) {
      r1[this_idx_0] = this_idx_1 + 1;
      this_idx_0++;
    }
  }
  loop_ub = this->Points.size(1);
  r2.set_size(r1.size(1), loop_ub);
  for (i = 0; i < loop_ub; i++) {
    this_idx_0 = r1.size(1);
    for (i1 = 0; i1 < this_idx_0; i1++) {
      r2[i1 + (r2.size(0) * i)] = static_cast<double>(
          this->Points[((static_cast<int>(indices[r1[i1] - 1])) +
                        (this->Points.size(0) * i)) -
                       1]);
    }
  }
  this_idx_2 = indices.size(1) - 1;
  this_idx_0 = 0;
  for (this_idx_1 = 0; this_idx_1 <= this_idx_2; this_idx_1++) {
    if (indices[this_idx_1] > 0.0) {
      this_idx_0++;
    }
  }
  r3.set_size(1, this_idx_0);
  this_idx_0 = 0;
  for (this_idx_1 = 0; this_idx_1 <= this_idx_2; this_idx_1++) {
    if (indices[this_idx_1] > 0.0) {
      r3[this_idx_0] = this_idx_1 + 1;
      this_idx_0++;
    }
  }
  this_idx_1 = r3.size(1);
  loop_ub = r.size(0);
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < this_idx_1; i1++) {
      newBoardCoords[(newBoardCoords.size(0) * (r3[i1] - 1)) +
                     ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                      r[i])] = r2[i1 + (this_idx_1 * i)];
    }
  }
  i = (2 <= newBoardCoords.size(0));
  loop_ub = this->BoardCoords.size(2);
  for (i1 = 0; i1 < loop_ub; i1++) {
    this_idx_0 = this->BoardCoords.size(1);
    for (i2 = 0; i2 < this_idx_0; i2++) {
      this_idx_2 = this->BoardCoords.size(0);
      for (this_idx_1 = 0; this_idx_1 < this_idx_2; this_idx_1++) {
        newBoardCoords[((i + this_idx_1) + (newBoardCoords.size(0) * i2)) +
                       ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                        i1)] =
            this->BoardCoords[(this_idx_1 + (this->BoardCoords.size(0) * i2)) +
                              ((this->BoardCoords.size(0) *
                                this->BoardCoords.size(1)) *
                               i1)];
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &predictedPoints
//                ::coder::array<double, 2U> &indices
// Return Type  : void
//
void Checkerboard::findClosestIndices(
    const ::coder::array<double, 2U> &predictedPoints,
    ::coder::array<double, 2U> &indices) const
{
  array<double, 2U> remIdx;
  array<double, 2U> y;
  array<double, 1U> b_this;
  array<float, 2U> a;
  array<float, 2U> diffs;
  array<float, 1U> dists;
  array<int, 2U> r;
  array<int, 1U> ib;
  array<int, 1U> ii;
  array<unsigned int, 1U> validPredictions;
  array<boolean_T, 2U> distIdx;
  array<boolean_T, 1U> x;
  float ex;
  int i;
  int i1;
  int loop_ub;
  int nx;
  indices.set_size(1, predictedPoints.size(0));
  nx = predictedPoints.size(0);
  for (i = 0; i < nx; i++) {
    indices[i] = 0.0;
  }
  nx = this->Points.size(0);
  if (nx < 1) {
    y.set_size(1, 0);
  } else {
    y.set_size(1, nx);
    nx--;
    for (i = 0; i <= nx; i++) {
      y[i] = (static_cast<double>(i)) + 1.0;
    }
  }
  nx = this->BoardIdx.size(0) * this->BoardIdx.size(1);
  b_this = this->BoardIdx.reshape(nx);
  do_vectors(y, b_this, remIdx, ii, ib);
  if (remIdx.size(1) != 0) {
    int b_ii;
    int idx;
    boolean_T exitg1;
    nx = predictedPoints.size(0);
    x.set_size(predictedPoints.size(0));
    for (i = 0; i < nx; i++) {
      x[i] = std::isnan(predictedPoints[i]);
    }
    nx = x.size(0);
    for (i = 0; i < nx; i++) {
      x[i] = !x[i];
    }
    nx = x.size(0);
    idx = 0;
    ii.set_size(x.size(0));
    b_ii = 0;
    exitg1 = false;
    while ((!exitg1) && (b_ii <= (nx - 1))) {
      if (x[b_ii]) {
        idx++;
        ii[idx - 1] = b_ii + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          b_ii++;
        }
      } else {
        b_ii++;
      }
    }
    if (x.size(0) == 1) {
      if (idx == 0) {
        ii.set_size(0);
      }
    } else {
      if (1 > idx) {
        idx = 0;
      }
      ii.set_size(idx);
    }
    validPredictions.set_size(ii.size(0));
    nx = ii.size(0);
    for (i = 0; i < nx; i++) {
      validPredictions[i] = static_cast<unsigned int>(ii[i]);
    }
    i = validPredictions.size(0);
    if (0 <= (validPredictions.size(0) - 1)) {
      loop_ub = this->Points.size(1);
      i1 = predictedPoints.size(1);
    }
    for (int b_i{0}; b_i < i; b_i++) {
      int i2;
      int i3;
      int k;
      a.set_size(remIdx.size(1), loop_ub);
      for (i2 = 0; i2 < loop_ub; i2++) {
        nx = remIdx.size(1);
        for (i3 = 0; i3 < nx; i3++) {
          a[i3 + (a.size(0) * i2)] =
              this->Points[((static_cast<int>(remIdx[i3])) +
                            (this->Points.size(0) * i2)) -
                           1];
        }
      }
      if (i1 == 1) {
        i2 = a.size(1);
      } else if (a.size(1) == 1) {
        i2 = predictedPoints.size(1);
      } else if (predictedPoints.size(1) == a.size(1)) {
        i2 = a.size(1);
      } else if (predictedPoints.size(1) < a.size(1)) {
        i2 = predictedPoints.size(1);
      } else {
        i2 = a.size(1);
      }
      diffs.set_size(a.size(0), i2);
      if (i2 != 0) {
        nx = (a.size(1) != 1);
        idx = (predictedPoints.size(1) != 1);
        i2--;
        for (k = 0; k <= i2; k++) {
          int acoef;
          int varargin_3;
          b_ii = nx * k;
          varargin_3 = idx * k;
          acoef = (a.size(0) != 1);
          i3 = diffs.size(0) - 1;
          for (int b_k{0}; b_k <= i3; b_k++) {
            diffs[b_k + (diffs.size(0) * k)] =
                a[(acoef * b_k) + (a.size(0) * b_ii)] -
                (static_cast<float>(
                    predictedPoints[((static_cast<int>(validPredictions[b_i])) +
                                     (predictedPoints.size(0) * varargin_3)) -
                                    1]));
          }
        }
      }
      dists.set_size(diffs.size(0));
      nx = diffs.size(0);
      for (k = 0; k < nx; k++) {
        dists[k] = rt_hypotf_snf(diffs[k], diffs[k + diffs.size(0)]);
      }
      idx = indices.size(1) - 1;
      nx = 0;
      for (b_ii = 0; b_ii <= idx; b_ii++) {
        if (indices[b_ii] > 0.0) {
          nx++;
        }
      }
      r.set_size(1, nx);
      nx = 0;
      for (b_ii = 0; b_ii <= idx; b_ii++) {
        if (indices[b_ii] > 0.0) {
          r[nx] = b_ii + 1;
          nx++;
        }
      }
      nx = r.size(1);
      y.set_size(1, r.size(1));
      for (i2 = 0; i2 < nx; i2++) {
        y[i2] = indices[r[i2] - 1];
      }
      local_ismember(remIdx, y, distIdx);
      idx = distIdx.size(1);
      for (b_ii = 0; b_ii < idx; b_ii++) {
        if (distIdx[b_ii]) {
          dists[b_ii] = rtInfF;
        }
      }
      ::coder::internal::minimum(dists, &ex, &nx);
      indices[(static_cast<int>(validPredictions[b_i])) - 1] = remIdx[nx - 1];
    }
  }
}

//
// Arguments    : const double predictedPoint[2]
//                double radius
//                const ::coder::array<double, 2U> &curve
//                const double coordsToUse[2]
//                const ::coder::array<double, 2U> &removedIdx
//                ::coder::array<double, 2U> &idx
// Return Type  : void
//
void Checkerboard::findClosestOnCurve(
    const double predictedPoint[2], double radius,
    const ::coder::array<double, 2U> &curve, const double coordsToUse[2],
    const ::coder::array<double, 2U> &removedIdx,
    ::coder::array<double, 2U> &idx) const
{
  array<double, 2U> dataPts;
  array<double, 2U> firstCoord;
  array<double, 2U> remIdx;
  array<double, 2U> y;
  array<double, 1U> b_this;
  array<double, 1U> dist;
  array<float, 2U> currPt;
  array<float, 2U> diffs;
  array<float, 2U> queryPts;
  array<float, 2U> z1;
  array<float, 1U> b_y;
  array<float, 1U> dists;
  array<int, 1U> ib;
  array<int, 1U> ii;
  array<int, 1U> r;
  array<boolean_T, 1U> s;
  double dv[2];
  double a_tmp;
  int acoef;
  int b_acoef;
  int b_i;
  int b_k;
  int i;
  int k;
  int loop_ub;
  int outsize_idx_0;
  int outsize_idx_1;
  int varargin_2;
  acoef = this->Points.size(0);
  if (acoef < 1) {
    y.set_size(1, 0);
  } else {
    y.set_size(1, acoef);
    b_acoef = acoef - 1;
    for (i = 0; i <= b_acoef; i++) {
      y[i] = (static_cast<double>(i)) + 1.0;
    }
  }
  acoef = this->BoardIdx.size(0) * this->BoardIdx.size(1);
  b_this = this->BoardIdx.reshape(acoef);
  do_vectors(y, b_this, remIdx, ii, ib);
  y.set_size(1, remIdx.size(1));
  b_acoef = remIdx.size(1) - 1;
  for (i = 0; i <= b_acoef; i++) {
    y[i] = remIdx[i];
  }
  do_vectors(y, removedIdx, remIdx, ii, ib);
  b_acoef = this->Points.size(1);
  queryPts.set_size(remIdx.size(1), b_acoef);
  for (i = 0; i < b_acoef; i++) {
    acoef = remIdx.size(1);
    for (varargin_2 = 0; varargin_2 < acoef; varargin_2++) {
      queryPts[varargin_2 + (queryPts.size(0) * i)] =
          this->Points[((static_cast<int>(remIdx[varargin_2])) +
                        (this->Points.size(0) * i)) -
                       1];
    }
  }
  diffs.set_size(queryPts.size(0), 2);
  if (queryPts.size(0) != 0) {
    acoef = (queryPts.size(1) != 1);
    b_acoef = (queryPts.size(0) != 1);
    for (k = 0; k < 2; k++) {
      varargin_2 = acoef * k;
      i = diffs.size(0) - 1;
      for (b_k = 0; b_k <= i; b_k++) {
        diffs[b_k + (diffs.size(0) * k)] =
            queryPts[(b_acoef * b_k) + (queryPts.size(0) * varargin_2)] -
            (static_cast<float>(predictedPoint[k]));
      }
    }
  }
  dists.set_size(diffs.size(0));
  acoef = diffs.size(0);
  for (k = 0; k < acoef; k++) {
    dists[k] = rt_hypotf_snf(diffs[k], diffs[k + diffs.size(0)]);
  }
  s.set_size(dists.size(0));
  b_acoef = dists.size(0);
  for (i = 0; i < b_acoef; i++) {
    s[i] = ((static_cast<double>(dists[i])) < radius);
  }
  acoef = 0;
  i = s.size(0);
  for (k = 0; k < i; k++) {
    if (s[k]) {
      acoef++;
    }
  }
  if (acoef > 1) {
    double a;
    boolean_T exitg1;
    boolean_T guard1{false};
    boolean_T guard2{false};
    boolean_T guard3{false};
    a_tmp = predictedPoint[(static_cast<int>(coordsToUse[0])) - 1];
    a = a_tmp - radius;
    a_tmp += radius;
    guard1 = false;
    guard2 = false;
    guard3 = false;
    if (std::isnan(a)) {
      guard2 = true;
    } else if (std::isnan(a_tmp)) {
      guard2 = true;
    } else if (a_tmp < a) {
      firstCoord.set_size(1, 0);
    } else if (std::isinf(a)) {
      guard3 = true;
    } else if (std::isinf(a_tmp)) {
      guard3 = true;
    } else {
      guard1 = true;
    }
    if (guard3) {
      if (a == a_tmp) {
        firstCoord.set_size(1, 1);
        firstCoord[0] = rtNaN;
      } else {
        guard1 = true;
      }
    }
    if (guard2) {
      firstCoord.set_size(1, 1);
      firstCoord[0] = rtNaN;
    }
    if (guard1) {
      if (std::floor(a) == a) {
        b_acoef = static_cast<int>(std::floor(a_tmp - a));
        firstCoord.set_size(1, b_acoef + 1);
        for (i = 0; i <= b_acoef; i++) {
          firstCoord[i] = a + (static_cast<double>(i));
        }
      } else {
        eml_float_colon(a, a_tmp, firstCoord);
      }
    }
    dv[0] = 1.0;
    dv[1] = 2.0;
    if (isequal(coordsToUse, dv)) {
      y.set_size(1, firstCoord.size(1));
      if (firstCoord.size(1) != 0) {
        if (curve.size(1) != 0) {
          acoef = firstCoord.size(1);
          y.set_size(1, firstCoord.size(1));
          for (i = 0; i < acoef; i++) {
            y[i] = curve[0];
          }
          i = curve.size(1);
          if (0 <= (curve.size(1) - 2)) {
            b_i = firstCoord.size(1);
          }
          for (k = 0; k <= (i - 2); k++) {
            a_tmp = curve[k + 1];
            y.set_size(1, firstCoord.size(1));
            for (varargin_2 = 0; varargin_2 < b_i; varargin_2++) {
              y[varargin_2] = (firstCoord[varargin_2] * y[varargin_2]) + a_tmp;
            }
          }
        }
      }
      dataPts.set_size(firstCoord.size(1), 2);
      b_acoef = firstCoord.size(1);
      for (i = 0; i < b_acoef; i++) {
        dataPts[i] = firstCoord[i];
      }
      b_acoef = y.size(1);
      for (i = 0; i < b_acoef; i++) {
        dataPts[i + dataPts.size(0)] = y[i];
      }
    } else {
      y.set_size(1, firstCoord.size(1));
      if (firstCoord.size(1) != 0) {
        if (curve.size(1) != 0) {
          acoef = firstCoord.size(1);
          y.set_size(1, firstCoord.size(1));
          for (i = 0; i < acoef; i++) {
            y[i] = curve[0];
          }
          i = curve.size(1);
          if (0 <= (curve.size(1) - 2)) {
            b_i = firstCoord.size(1);
          }
          for (k = 0; k <= (i - 2); k++) {
            a_tmp = curve[k + 1];
            y.set_size(1, firstCoord.size(1));
            for (varargin_2 = 0; varargin_2 < b_i; varargin_2++) {
              y[varargin_2] = (firstCoord[varargin_2] * y[varargin_2]) + a_tmp;
            }
          }
        }
      }
      dataPts.set_size(y.size(1), 2);
      b_acoef = y.size(1);
      for (i = 0; i < b_acoef; i++) {
        dataPts[i] = y[i];
      }
      b_acoef = firstCoord.size(1);
      for (i = 0; i < b_acoef; i++) {
        dataPts[i + dataPts.size(0)] = firstCoord[i];
      }
    }
    b_acoef = dists.size(0) - 1;
    acoef = 0;
    for (b_i = 0; b_i <= b_acoef; b_i++) {
      if ((static_cast<double>(dists[b_i])) < radius) {
        acoef++;
      }
    }
    r.set_size(acoef);
    acoef = 0;
    for (b_i = 0; b_i <= b_acoef; b_i++) {
      if ((static_cast<double>(dists[b_i])) < radius) {
        r[acoef] = b_i + 1;
        acoef++;
      }
    }
    b_acoef = this->Points.size(1);
    queryPts.set_size(r.size(0), b_acoef);
    for (i = 0; i < b_acoef; i++) {
      acoef = r.size(0);
      for (varargin_2 = 0; varargin_2 < acoef; varargin_2++) {
        queryPts[varargin_2 + (queryPts.size(0) * i)] =
            this->Points[((static_cast<int>(remIdx[r[varargin_2] - 1])) +
                          (this->Points.size(0) * i)) -
                         1];
      }
    }
    dist.set_size(queryPts.size(0));
    i = queryPts.size(0);
    if (0 <= (queryPts.size(0) - 1)) {
      outsize_idx_0 = dataPts.size(0);
      outsize_idx_1 = queryPts.size(1);
      loop_ub = dataPts.size(0);
    }
    for (b_i = 0; b_i < i; b_i++) {
      float ex;
      currPt.set_size(outsize_idx_0, outsize_idx_1);
      if ((outsize_idx_0 != 0) && (outsize_idx_1 != 0)) {
        b_acoef = queryPts.size(1) - 1;
        for (k = 0; k <= b_acoef; k++) {
          varargin_2 = dataPts.size(0) - 1;
          for (acoef = 0; acoef <= varargin_2; acoef++) {
            currPt[acoef + (currPt.size(0) * k)] =
                queryPts[b_i + (queryPts.size(0) * k)];
          }
        }
      }
      diffs.set_size(dataPts.size(0), 2);
      for (varargin_2 = 0; varargin_2 < 2; varargin_2++) {
        for (acoef = 0; acoef < loop_ub; acoef++) {
          diffs[acoef + (diffs.size(0) * varargin_2)] =
              (static_cast<float>(
                  dataPts[acoef + (dataPts.size(0) * varargin_2)])) -
              currPt[acoef + (currPt.size(0) * varargin_2)];
        }
      }
      z1.set_size(diffs.size(0), 2);
      for (k = 0; k < 2; k++) {
        acoef = z1.size(0);
        for (b_k = 0; b_k < acoef; b_k++) {
          z1[b_k + (z1.size(0) * k)] =
              rt_powf_snf(diffs[b_k + (diffs.size(0) * k)], 2.0F);
        }
      }
      if (z1.size(0) == 0) {
        b_y.set_size(0);
      } else {
        b_y.set_size(z1.size(0));
        varargin_2 = z1.size(0);
        for (k = 0; k < varargin_2; k++) {
          b_y[k] = z1[k];
        }
        varargin_2 = z1.size(0);
        for (k = 0; k < varargin_2; k++) {
          b_y[k] = b_y[k] + z1[k + z1.size(0)];
        }
      }
      acoef = b_y.size(0);
      if (b_y.size(0) <= 2) {
        if (b_y.size(0) == 0) {
          ex = rtNaNF;
        } else if (b_y.size(0) == 1) {
          ex = b_y[0];
        } else if (b_y[0] > b_y[1]) {
          ex = b_y[1];
        } else if (std::isnan(b_y[0])) {
          if (!std::isnan(b_y[1])) {
            ex = b_y[1];
          } else {
            ex = b_y[0];
          }
        } else {
          ex = b_y[0];
        }
      } else {
        if (!std::isnan(b_y[0])) {
          b_acoef = 1;
        } else {
          b_acoef = 0;
          k = 2;
          exitg1 = false;
          while ((!exitg1) && (k <= acoef)) {
            if (!std::isnan(b_y[k - 1])) {
              b_acoef = k;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }
        if (b_acoef == 0) {
          ex = b_y[0];
        } else {
          ex = b_y[b_acoef - 1];
          varargin_2 = b_acoef + 1;
          for (k = varargin_2; k <= acoef; k++) {
            float f;
            f = b_y[k - 1];
            if (ex > f) {
              ex = f;
            }
          }
        }
      }
      ex = std::sqrt(ex);
      dist[b_i] = static_cast<double>(ex);
    }
    ::coder::internal::minimum(dist, &a_tmp, &acoef);
    s.set_size(dists.size(0));
    b_acoef = dists.size(0);
    for (i = 0; i < b_acoef; i++) {
      s[i] = ((static_cast<double>(dists[i])) < radius);
    }
    if (acoef <= s.size(0)) {
      k = acoef;
    } else {
      k = s.size(0);
    }
    b_acoef = 0;
    ii.set_size(k);
    acoef = 0;
    exitg1 = false;
    while ((!exitg1) && (acoef <= (s.size(0) - 1))) {
      if (s[acoef]) {
        b_acoef++;
        ii[b_acoef - 1] = acoef + 1;
        if (b_acoef >= k) {
          exitg1 = true;
        } else {
          acoef++;
        }
      } else {
        acoef++;
      }
    }
    if (k == 1) {
      if (b_acoef == 0) {
        ii.set_size(0);
      }
    } else {
      if (1 > b_acoef) {
        b_acoef = 0;
      }
      ii.set_size(b_acoef);
    }
    dist.set_size(ii.size(0));
    b_acoef = ii.size(0);
    for (i = 0; i < b_acoef; i++) {
      dist[i] = static_cast<double>(ii[i]);
    }
    idx.set_size(1, 1);
    idx[0] = remIdx[(static_cast<int>(dist[dist.size(0) - 1])) - 1];
  } else {
    s.set_size(dists.size(0));
    b_acoef = dists.size(0);
    for (i = 0; i < b_acoef; i++) {
      s[i] = ((static_cast<double>(dists[i])) < radius);
    }
    acoef = 0;
    i = s.size(0);
    for (k = 0; k < i; k++) {
      if (s[k]) {
        acoef++;
      }
    }
    if (acoef == 1) {
      b_acoef = dists.size(0) - 1;
      acoef = 0;
      for (b_i = 0; b_i <= b_acoef; b_i++) {
        if ((static_cast<double>(dists[b_i])) < radius) {
          acoef++;
        }
      }
      r.set_size(acoef);
      acoef = 0;
      for (b_i = 0; b_i <= b_acoef; b_i++) {
        if ((static_cast<double>(dists[b_i])) < radius) {
          r[acoef] = b_i + 1;
          acoef++;
        }
      }
      idx.set_size(1, r.size(0));
      b_acoef = r.size(0);
      for (i = 0; i < b_acoef; i++) {
        idx[i] = remIdx[r[i] - 1];
      }
    } else {
      idx.set_size(1, 0);
    }
  }
}

//
// Arguments    : const ::coder::array<float, 2U> &pointVectors
//                const ::coder::array<float, 1U> &euclideanDists
//                const float v[2]
// Return Type  : double
//
double
Checkerboard::findNeighbor(const ::coder::array<float, 2U> &pointVectors,
                           const ::coder::array<float, 1U> &euclideanDists,
                           const float v[2]) const
{
  array<float, 1U> angleCosines;
  array<float, 1U> dists;
  array<int, 1U> r1;
  array<int, 1U> r2;
  array<boolean_T, 2U> r;
  double neighborIdx;
  float b;
  int i;
  int inner;
  int k;
  int mc;
  mc = pointVectors.size(0) - 1;
  inner = pointVectors.size(1);
  angleCosines.set_size(pointVectors.size(0));
  for (i = 0; i <= mc; i++) {
    angleCosines[i] = 0.0F;
  }
  for (k = 0; k < inner; k++) {
    for (i = 0; i <= mc; i++) {
      angleCosines[i] = angleCosines[i] +
                        (pointVectors[i + (pointVectors.size(0) * k)] * v[k]);
    }
  }
  b = rt_hypotf_snf(v[0], v[1]);
  dists.set_size(euclideanDists.size(0));
  mc = euclideanDists.size(0);
  for (k = 0; k < mc; k++) {
    dists[k] = euclideanDists[k] * b;
  }
  mc = angleCosines.size(0);
  for (k = 0; k < mc; k++) {
    angleCosines[k] = angleCosines[k] / dists[k];
  }
  dists.set_size(euclideanDists.size(0));
  mc = euclideanDists.size(0);
  for (k = 0; k < mc; k++) {
    dists[k] = euclideanDists[k] +
               ((1.5F * euclideanDists[k]) * (1.0F - angleCosines[k]));
  }
  r.set_size(this->BoardIdx.size(0), this->BoardIdx.size(1));
  mc = this->BoardIdx.size(1);
  for (k = 0; k < mc; k++) {
    inner = this->BoardIdx.size(0);
    for (i = 0; i < inner; i++) {
      r[i + (r.size(0) * k)] =
          (this->BoardIdx[i + (this->BoardIdx.size(0) * k)] > 0.0);
    }
  }
  inner = (r.size(0) * r.size(1)) - 1;
  mc = 0;
  for (i = 0; i <= inner; i++) {
    if (r[i]) {
      mc++;
    }
  }
  r1.set_size(mc);
  mc = 0;
  for (i = 0; i <= inner; i++) {
    if (r[i]) {
      r1[mc] = i + 1;
      mc++;
    }
  }
  r2.set_size(r1.size(0));
  mc = r1.size(0);
  for (k = 0; k < mc; k++) {
    r2[k] = static_cast<int>(this->BoardIdx[r1[k] - 1]);
  }
  mc = r2.size(0);
  for (k = 0; k < mc; k++) {
    dists[r2[k] - 1] = rtInfF;
  }
  inner = angleCosines.size(0);
  for (i = 0; i < inner; i++) {
    if (angleCosines[i] < 0.0F) {
      dists[i] = rtInfF;
    }
  }
  ::coder::internal::minimum(dists, &b, &mc);
  neighborIdx = static_cast<double>(mc);
  if (std::isinf(b)) {
    neighborIdx = -1.0;
  }
  return neighborIdx;
}

//
// Arguments    : const ::coder::array<float, 2U> &pointVectors
//                const ::coder::array<float, 1U> &euclideanDists
//                const ::coder::array<float, 2U> &v
// Return Type  : double
//
double
Checkerboard::findNeighbor(const ::coder::array<float, 2U> &pointVectors,
                           const ::coder::array<float, 1U> &euclideanDists,
                           const ::coder::array<float, 2U> &v) const
{
  array<float, 1U> angleCosines;
  array<float, 1U> dists;
  array<int, 1U> r1;
  array<int, 1U> r2;
  array<boolean_T, 2U> r;
  double neighborIdx;
  float bkj;
  int i;
  int inner;
  int k;
  int mc;
  mc = pointVectors.size(0) - 1;
  inner = pointVectors.size(1);
  angleCosines.set_size(pointVectors.size(0));
  for (i = 0; i <= mc; i++) {
    angleCosines[i] = 0.0F;
  }
  for (k = 0; k < inner; k++) {
    bkj = v[k];
    for (i = 0; i <= mc; i++) {
      angleCosines[i] = angleCosines[i] +
                        (pointVectors[i + (pointVectors.size(0) * k)] * bkj);
    }
  }
  bkj = rt_hypotf_snf(v[0], v[1]);
  dists.set_size(euclideanDists.size(0));
  mc = euclideanDists.size(0);
  for (k = 0; k < mc; k++) {
    dists[k] = euclideanDists[k] * bkj;
  }
  mc = angleCosines.size(0);
  for (k = 0; k < mc; k++) {
    angleCosines[k] = angleCosines[k] / dists[k];
  }
  dists.set_size(euclideanDists.size(0));
  mc = euclideanDists.size(0);
  for (k = 0; k < mc; k++) {
    dists[k] = euclideanDists[k] +
               ((1.5F * euclideanDists[k]) * (1.0F - angleCosines[k]));
  }
  r.set_size(this->BoardIdx.size(0), this->BoardIdx.size(1));
  mc = this->BoardIdx.size(1);
  for (k = 0; k < mc; k++) {
    inner = this->BoardIdx.size(0);
    for (i = 0; i < inner; i++) {
      r[i + (r.size(0) * k)] =
          (this->BoardIdx[i + (this->BoardIdx.size(0) * k)] > 0.0);
    }
  }
  inner = (r.size(0) * r.size(1)) - 1;
  mc = 0;
  for (i = 0; i <= inner; i++) {
    if (r[i]) {
      mc++;
    }
  }
  r1.set_size(mc);
  mc = 0;
  for (i = 0; i <= inner; i++) {
    if (r[i]) {
      r1[mc] = i + 1;
      mc++;
    }
  }
  r2.set_size(r1.size(0));
  mc = r1.size(0);
  for (k = 0; k < mc; k++) {
    r2[k] = static_cast<int>(this->BoardIdx[r1[k] - 1]);
  }
  mc = r2.size(0);
  for (k = 0; k < mc; k++) {
    dists[r2[k] - 1] = rtInfF;
  }
  inner = angleCosines.size(0);
  for (i = 0; i < inner; i++) {
    if (angleCosines[i] < 0.0F) {
      dists[i] = rtInfF;
    }
  }
  ::coder::internal::minimum(dists, &bkj, &mc);
  neighborIdx = static_cast<double>(mc);
  if (std::isinf(bkj)) {
    neighborIdx = -1.0;
  }
  return neighborIdx;
}

//
// Arguments    : ::coder::array<double, 2U> &newIndices
// Return Type  : void
//
void Checkerboard::fitPolynomialIndices(
    ::coder::array<double, 2U> &newIndices) const
{
  array<double, 2U> b_index;
  array<double, 2U> currCurve;
  array<double, 2U> r6;
  array<double, 2U> removedIdx;
  array<double, 1U> b_this;
  array<double, 1U> c_this;
  array<int, 2U> r2;
  array<int, 2U> r3;
  array<int, 2U> r4;
  array<int, 2U> r5;
  array<int, 1U> ii;
  array<boolean_T, 2U> r;
  array<boolean_T, 2U> r1;
  double coordsToUse[2];
  double currPt[2];
  double y;
  int b_i;
  int end;
  int i;
  int loop_ub;
  loop_ub = this->BoardIdx.size(1);
  r.set_size(1, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r[i] = (this->BoardIdx[this->BoardIdx.size(0) * i] > 0.0);
  }
  loop_ub = this->BoardIdx.size(1);
  r1.set_size(1, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r1[i] = (this->BoardIdx[(this->BoardIdx.size(0) * i) + 1] > 0.0);
  }
  end = r.size(1) - 1;
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if ((r[b_i]) && (r1[b_i])) {
      loop_ub++;
    }
  }
  r2.set_size(1, loop_ub);
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if ((r[b_i]) && (r1[b_i])) {
      r2[loop_ub] = b_i + 1;
      loop_ub++;
    }
  }
  removedIdx.set_size(1, r2.size(1));
  loop_ub = r2.size(1);
  for (i = 0; i < loop_ub; i++) {
    removedIdx[i] =
        this->BoardCoords[(this->BoardCoords.size(0) * (r2[i] - 1)) + 1];
  }
  end = r.size(1) - 1;
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if ((r[b_i]) && (r1[b_i])) {
      loop_ub++;
    }
  }
  r3.set_size(1, loop_ub);
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if ((r[b_i]) && (r1[b_i])) {
      r3[loop_ub] = b_i + 1;
      loop_ub++;
    }
  }
  currCurve.set_size(1, r3.size(1));
  loop_ub = r3.size(1);
  for (i = 0; i < loop_ub; i++) {
    currCurve[i] = this->BoardCoords[this->BoardCoords.size(0) * (r3[i] - 1)];
  }
  end = r.size(1) - 1;
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if ((r[b_i]) && (r1[b_i])) {
      loop_ub++;
    }
  }
  r4.set_size(1, loop_ub);
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if ((r[b_i]) && (r1[b_i])) {
      r4[loop_ub] = b_i + 1;
      loop_ub++;
    }
  }
  b_index.set_size(1, r4.size(1));
  loop_ub = r4.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_index[i] = this->BoardCoords[((this->BoardCoords.size(0) * (r4[i] - 1)) +
                                    (this->BoardCoords.size(0) *
                                     this->BoardCoords.size(1))) +
                                   1];
  }
  end = r.size(1) - 1;
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if ((r[b_i]) && (r1[b_i])) {
      loop_ub++;
    }
  }
  r5.set_size(1, loop_ub);
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if ((r[b_i]) && (r1[b_i])) {
      r5[loop_ub] = b_i + 1;
      loop_ub++;
    }
  }
  r6.set_size(1, r5.size(1));
  loop_ub = r5.size(1);
  for (i = 0; i < loop_ub; i++) {
    r6[i] = this->BoardCoords[(this->BoardCoords.size(0) * (r5[i] - 1)) +
                              (this->BoardCoords.size(0) *
                               this->BoardCoords.size(1))];
  }
  removedIdx.set_size(1, removedIdx.size(1));
  loop_ub = removedIdx.size(1);
  for (i = 0; i < loop_ub; i++) {
    removedIdx[i] = removedIdx[i] - currCurve[i];
  }
  b_index.set_size(1, b_index.size(1));
  loop_ub = b_index.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_index[i] = b_index[i] - r6[i];
  }
  if (std::abs(mean(removedIdx)) > std::abs(mean(b_index))) {
    coordsToUse[0] = 1.0;
    coordsToUse[1] = 2.0;
  } else {
    coordsToUse[0] = 2.0;
    coordsToUse[1] = 1.0;
  }
  loop_ub = this->BoardCoords.size(1);
  newIndices.set_size(1, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    newIndices[i] = 0.0;
  }
  removedIdx.set_size(1, 0);
  i = this->BoardCoords.size(1);
  for (b_i = 0; b_i < i; b_i++) {
    int i1;
    loop_ub = this->BoardCoords.size(0);
    b_this.set_size(loop_ub);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_this[i1] =
          this->BoardCoords[(i1 + (this->BoardCoords.size(0) * b_i)) +
                            ((this->BoardCoords.size(0) *
                              this->BoardCoords.size(1)) *
                             ((static_cast<int>(coordsToUse[0])) - 1))];
    }
    eml_find(b_this, ii);
    if (ii.size(0) >= 2) {
      double coordDist;
      double coordDist_tmp;
      double currCoord;
      double currRad;
      int i2;
      boolean_T exitg1;
      i1 = static_cast<int>(coordsToUse[0]);
      coordDist_tmp =
          this->BoardCoords[((ii[0] + (this->BoardCoords.size(0) * b_i)) +
                             ((this->BoardCoords.size(0) *
                               this->BoardCoords.size(1)) *
                              (i1 - 1))) -
                            1];
      coordDist =
          (coordDist_tmp -
           this->BoardCoords[((ii[1] + (this->BoardCoords.size(0) * b_i)) +
                              ((this->BoardCoords.size(0) *
                                this->BoardCoords.size(1)) *
                               (i1 - 1))) -
                             1]) /
          ((static_cast<double>(ii[1])) - (static_cast<double>(ii[0])));
      end = 0;
      i2 = ii.size(0);
      b_this.set_size(ii.size(0));
      c_this.set_size(ii.size(0));
      for (loop_ub = 0; loop_ub < i2; loop_ub++) {
        if (ii[loop_ub] != 0) {
          end++;
        }
        b_this[loop_ub] =
            this->BoardCoords
                [((ii[loop_ub] + (this->BoardCoords.size(0) * b_i)) +
                  ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                   (i1 - 1))) -
                 1];
        c_this[loop_ub] =
            this->BoardCoords
                [((ii[loop_ub] + (this->BoardCoords.size(0) * b_i)) +
                  ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                   ((static_cast<int>(coordsToUse[1])) - 1))) -
                 1];
      }
      if (end > 5) {
        end = 4;
      } else {
        end = 2;
      }
      polyfit(b_this, c_this, static_cast<double>(end), currCurve);
      currRad = coordDist / 4.0;
      currCoord = currRad + coordDist_tmp;
      exitg1 = false;
      while ((!exitg1) &&
             (std::abs(currCoord - coordDist_tmp) <
              (((static_cast<double>(ii[0])) * 1.5) * std::abs(coordDist)))) {
        currPt[0] = 1.0;
        currPt[1] = 2.0;
        if (isequal(coordsToUse, currPt)) {
          if (currCurve.size(1) != 0) {
            y = currCurve[0];
            i1 = currCurve.size(1);
            for (loop_ub = 0; loop_ub <= (i1 - 2); loop_ub++) {
              y = (currCoord * y) + currCurve[loop_ub + 1];
            }
          }
          currPt[0] = currCoord;
          currPt[1] = y;
        } else {
          if (currCurve.size(1) != 0) {
            y = currCurve[0];
            i1 = currCurve.size(1);
            for (loop_ub = 0; loop_ub <= (i1 - 2); loop_ub++) {
              y = (currCoord * y) + currCurve[loop_ub + 1];
            }
          }
          currPt[0] = y;
          currPt[1] = currCoord;
        }
        this->findClosestOnCurve(currPt, std::abs(currRad), currCurve,
                                 coordsToUse, removedIdx, b_index);
        if (b_index.size(1) != 0) {
          newIndices[b_i] = b_index[0];
          i1 = removedIdx.size(1);
          loop_ub = b_index.size(1);
          removedIdx.set_size(removedIdx.size(0),
                              removedIdx.size(1) + b_index.size(1));
          for (i2 = 0; i2 < loop_ub; i2++) {
            removedIdx[i1 + i2] = b_index[i2];
          }
          exitg1 = true;
        } else {
          currCoord += currRad;
        }
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &idx
//                ::coder::array<double, 2U> &newIndices
// Return Type  : void
//
void Checkerboard::fitPolynomialIndices(
    const ::coder::array<double, 2U> &idx,
    ::coder::array<double, 2U> &newIndices) const
{
  array<double, 2U> b_index;
  array<double, 2U> currCurve;
  array<double, 2U> r6;
  array<double, 2U> removedIdx;
  array<double, 1U> b_this;
  array<double, 1U> c_this;
  array<int, 2U> r2;
  array<int, 2U> r3;
  array<int, 2U> r4;
  array<int, 2U> r5;
  array<int, 1U> ii;
  array<boolean_T, 2U> r;
  array<boolean_T, 2U> r1;
  double coordsToUse[2];
  double currPt[2];
  double y;
  int b_i;
  int b_idx_tmp;
  int end;
  int i;
  int idx_tmp;
  int loop_ub;
  idx_tmp = static_cast<int>(idx[0]);
  loop_ub = this->BoardIdx.size(1);
  r.set_size(1, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r[i] = (this->BoardIdx[(idx_tmp + (this->BoardIdx.size(0) * i)) - 1] > 0.0);
  }
  b_idx_tmp = static_cast<int>(idx[1]);
  loop_ub = this->BoardIdx.size(1);
  r1.set_size(1, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r1[i] =
        (this->BoardIdx[(b_idx_tmp + (this->BoardIdx.size(0) * i)) - 1] > 0.0);
  }
  end = r.size(1) - 1;
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if ((r[b_i]) && (r1[b_i])) {
      loop_ub++;
    }
  }
  r2.set_size(1, loop_ub);
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if ((r[b_i]) && (r1[b_i])) {
      r2[loop_ub] = b_i + 1;
      loop_ub++;
    }
  }
  removedIdx.set_size(1, r2.size(1));
  loop_ub = r2.size(1);
  for (i = 0; i < loop_ub; i++) {
    removedIdx[i] = this->BoardCoords[(b_idx_tmp + (this->BoardCoords.size(0) *
                                                    (r2[i] - 1))) -
                                      1];
  }
  end = r.size(1) - 1;
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if ((r[b_i]) && (r1[b_i])) {
      loop_ub++;
    }
  }
  r3.set_size(1, loop_ub);
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if ((r[b_i]) && (r1[b_i])) {
      r3[loop_ub] = b_i + 1;
      loop_ub++;
    }
  }
  currCurve.set_size(1, r3.size(1));
  loop_ub = r3.size(1);
  for (i = 0; i < loop_ub; i++) {
    currCurve[i] = this->BoardCoords[(idx_tmp + (this->BoardCoords.size(0) *
                                                 (r3[i] - 1))) -
                                     1];
  }
  end = r.size(1) - 1;
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if ((r[b_i]) && (r1[b_i])) {
      loop_ub++;
    }
  }
  r4.set_size(1, loop_ub);
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if ((r[b_i]) && (r1[b_i])) {
      r4[loop_ub] = b_i + 1;
      loop_ub++;
    }
  }
  b_index.set_size(1, r4.size(1));
  loop_ub = r4.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_index[i] =
        this->BoardCoords
            [((b_idx_tmp + (this->BoardCoords.size(0) * (r4[i] - 1))) +
              (this->BoardCoords.size(0) * this->BoardCoords.size(1))) -
             1];
  }
  end = r.size(1) - 1;
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if ((r[b_i]) && (r1[b_i])) {
      loop_ub++;
    }
  }
  r5.set_size(1, loop_ub);
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if ((r[b_i]) && (r1[b_i])) {
      r5[loop_ub] = b_i + 1;
      loop_ub++;
    }
  }
  r6.set_size(1, r5.size(1));
  loop_ub = r5.size(1);
  for (i = 0; i < loop_ub; i++) {
    r6[i] = this->BoardCoords
                [((idx_tmp + (this->BoardCoords.size(0) * (r5[i] - 1))) +
                  (this->BoardCoords.size(0) * this->BoardCoords.size(1))) -
                 1];
  }
  removedIdx.set_size(1, removedIdx.size(1));
  loop_ub = removedIdx.size(1);
  for (i = 0; i < loop_ub; i++) {
    removedIdx[i] = removedIdx[i] - currCurve[i];
  }
  b_index.set_size(1, b_index.size(1));
  loop_ub = b_index.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_index[i] = b_index[i] - r6[i];
  }
  if (std::abs(mean(removedIdx)) > std::abs(mean(b_index))) {
    coordsToUse[0] = 1.0;
    coordsToUse[1] = 2.0;
  } else {
    coordsToUse[0] = 2.0;
    coordsToUse[1] = 1.0;
  }
  loop_ub = this->BoardCoords.size(1);
  newIndices.set_size(1, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    newIndices[i] = 0.0;
  }
  removedIdx.set_size(1, 0);
  i = this->BoardCoords.size(1);
  for (b_idx_tmp = 0; b_idx_tmp < i; b_idx_tmp++) {
    loop_ub = this->BoardCoords.size(0);
    b_this.set_size(loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_this[b_i] =
          this->BoardCoords[(b_i + (this->BoardCoords.size(0) * b_idx_tmp)) +
                            ((this->BoardCoords.size(0) *
                              this->BoardCoords.size(1)) *
                             ((static_cast<int>(coordsToUse[0])) - 1))];
    }
    eml_find(b_this, ii);
    if (ii.size(0) >= 2) {
      double coordDist;
      double currCoord;
      double currRad;
      double moveDistMultiplier;
      double refCoordValue;
      int i1;
      boolean_T exitg1;
      if (idx[0] == 1.0) {
        moveDistMultiplier = static_cast<double>(ii[0]);
        end = ii[0];
        b_i = static_cast<int>(coordsToUse[0]);
        coordDist =
            (this->BoardCoords
                 [((ii[0] + (this->BoardCoords.size(0) * b_idx_tmp)) +
                   ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                    (b_i - 1))) -
                  1] -
             this->BoardCoords
                 [((ii[1] + (this->BoardCoords.size(0) * b_idx_tmp)) +
                   ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                    (b_i - 1))) -
                  1]) /
            ((static_cast<double>(ii[1])) - (static_cast<double>(ii[0])));
      } else {
        moveDistMultiplier = ((static_cast<double>(this->BoardCoords.size(0))) -
                              (static_cast<double>(ii[ii.size(0) - 1]))) +
                             1.0;
        end = ii[ii.size(0) - 1];
        b_i = static_cast<int>(coordsToUse[0]);
        coordDist =
            (this->BoardCoords[((ii[ii.size(0) - 1] +
                                 (this->BoardCoords.size(0) * b_idx_tmp)) +
                                ((this->BoardCoords.size(0) *
                                  this->BoardCoords.size(1)) *
                                 (b_i - 1))) -
                               1] -
             this->BoardCoords[((ii[ii.size(0) - 2] +
                                 (this->BoardCoords.size(0) * b_idx_tmp)) +
                                ((this->BoardCoords.size(0) *
                                  this->BoardCoords.size(1)) *
                                 (b_i - 1))) -
                               1]) /
            ((static_cast<double>(ii[ii.size(0) - 1])) -
             (static_cast<double>(ii[ii.size(0) - 2])));
      }
      loop_ub = 0;
      i1 = ii.size(0);
      b_this.set_size(ii.size(0));
      c_this.set_size(ii.size(0));
      for (idx_tmp = 0; idx_tmp < i1; idx_tmp++) {
        if (ii[idx_tmp] != 0) {
          loop_ub++;
        }
        b_this[idx_tmp] =
            this->BoardCoords
                [((ii[idx_tmp] + (this->BoardCoords.size(0) * b_idx_tmp)) +
                  ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                   (b_i - 1))) -
                 1];
        c_this[idx_tmp] =
            this->BoardCoords
                [((ii[idx_tmp] + (this->BoardCoords.size(0) * b_idx_tmp)) +
                  ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                   ((static_cast<int>(coordsToUse[1])) - 1))) -
                 1];
      }
      if (loop_ub > 5) {
        loop_ub = 4;
      } else {
        loop_ub = 2;
      }
      polyfit(b_this, c_this, static_cast<double>(loop_ub), currCurve);
      currRad = coordDist / 4.0;
      refCoordValue =
          this->BoardCoords[((end + (this->BoardCoords.size(0) * b_idx_tmp)) +
                             ((this->BoardCoords.size(0) *
                               this->BoardCoords.size(1)) *
                              ((static_cast<int>(coordsToUse[0])) - 1))) -
                            1];
      currCoord = currRad + refCoordValue;
      exitg1 = false;
      while ((!exitg1) &&
             (std::abs(currCoord - refCoordValue) <
              ((moveDistMultiplier * 1.5) * std::abs(coordDist)))) {
        currPt[0] = 1.0;
        currPt[1] = 2.0;
        if (isequal(coordsToUse, currPt)) {
          if (currCurve.size(1) != 0) {
            y = currCurve[0];
            b_i = currCurve.size(1);
            for (idx_tmp = 0; idx_tmp <= (b_i - 2); idx_tmp++) {
              y = (currCoord * y) + currCurve[idx_tmp + 1];
            }
          }
          currPt[0] = currCoord;
          currPt[1] = y;
        } else {
          if (currCurve.size(1) != 0) {
            y = currCurve[0];
            b_i = currCurve.size(1);
            for (idx_tmp = 0; idx_tmp <= (b_i - 2); idx_tmp++) {
              y = (currCoord * y) + currCurve[idx_tmp + 1];
            }
          }
          currPt[0] = y;
          currPt[1] = currCoord;
        }
        this->findClosestOnCurve(currPt, std::abs(currRad), currCurve,
                                 coordsToUse, removedIdx, b_index);
        if (b_index.size(1) != 0) {
          newIndices[b_idx_tmp] = b_index[0];
          b_i = removedIdx.size(1);
          loop_ub = b_index.size(1);
          removedIdx.set_size(removedIdx.size(0),
                              removedIdx.size(1) + b_index.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            removedIdx[b_i + i1] = b_index[i1];
          }
          exitg1 = true;
        } else {
          currCoord += currRad;
        }
      }
    }
  }
}

//
// Arguments    : float u0
//                float u1
// Return Type  : float
//
} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
static float rt_hypotf_snf(float u0, float u1)
{
  float a;
  float y;
  a = std::abs(u0);
  y = std::abs(u1);
  if (a < y) {
    a /= y;
    y *= std::sqrt((a * a) + 1.0F);
  } else if (a > y) {
    y /= a;
    y = a * std::sqrt((y * y) + 1.0F);
  } else if (!std::isnan(y)) {
    y = a * 1.41421354F;
  } else {
    /* no actions */
  }
  return y;
}

//
// Arguments    : double direction
// Return Type  : void
//
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void Checkerboard::expandBoardDirectionally(double direction)
{
  array<double, 3U> b_this;
  array<double, 3U> r;
  array<double, 2U> idx;
  array<double, 2U> newIndices;
  array<double, 2U> newIndicesLinear;
  array<double, 2U> p1;
  array<double, 2U> p2;
  array<int, 2U> r2;
  array<int, 2U> r3;
  array<int, 1U> r1;
  float oldEnergy;
  oldEnergy =
      (this->Energy + (static_cast<float>(static_cast<int>(
                          this->BoardIdx.size(0) * this->BoardIdx.size(1))))) /
      (static_cast<float>(
          static_cast<int>(this->BoardIdx.size(0) * this->BoardIdx.size(1))));
  switch (static_cast<int>(direction)) {
  case 1: {
    int b_loop_ub;
    int i;
    int i1;
    int loop_ub;
    int numRows;
    if (this->IsDistortionHigh) {
      boolean_T exitg1;
      boolean_T y;
      this->fitPolynomialIndices(newIndices);
      y = true;
      numRows = 0;
      exitg1 = false;
      while ((!exitg1) && (numRows <= (newIndices.size(1) - 1))) {
        if (newIndices[numRows] == 0.0) {
          y = false;
          exitg1 = true;
        } else {
          numRows++;
        }
      }
      if (!y) {
        loop_ub = this->BoardCoords.size(1);
        b_loop_ub = this->BoardCoords.size(2);
        b_this.set_size(1, loop_ub, b_loop_ub);
        for (i = 0; i < b_loop_ub; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_this[i1 + (b_this.size(1) * i)] =
                this->BoardCoords[((this->BoardCoords.size(0) * i1) +
                                   ((this->BoardCoords.size(0) *
                                     this->BoardCoords.size(1)) *
                                    i)) +
                                  1];
          }
        }
        squeeze(b_this, p1);
        loop_ub = this->BoardCoords.size(1);
        b_loop_ub = this->BoardCoords.size(2);
        b_this.set_size(1, loop_ub, b_loop_ub);
        for (i = 0; i < b_loop_ub; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_this[i1 + (b_this.size(1) * i)] =
                this->BoardCoords[(this->BoardCoords.size(0) * i1) +
                                  ((this->BoardCoords.size(0) *
                                    this->BoardCoords.size(1)) *
                                   i)];
          }
        }
        squeeze(b_this, p2);
        loop_ub = p2.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = p2.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            double d;
            d = p2[i1 + (p2.size(0) * i)];
            d = (d + d) - p1[i1 + (p1.size(0) * i)];
            p2[i1 + (p2.size(0) * i)] = d;
          }
        }
        this->findClosestIndices(p2, newIndicesLinear);
        b_loop_ub = newIndices.size(1);
        for (int b_i{0}; b_i < b_loop_ub; b_i++) {
          if (newIndices[b_i] == 0.0) {
            newIndices[b_i] = newIndicesLinear[b_i];
          }
        }
      }
    } else {
      loop_ub = this->BoardCoords.size(1);
      b_loop_ub = this->BoardCoords.size(2);
      b_this.set_size(1, loop_ub, b_loop_ub);
      for (i = 0; i < b_loop_ub; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_this[i1 + (b_this.size(1) * i)] =
              this->BoardCoords[((this->BoardCoords.size(0) * i1) +
                                 ((this->BoardCoords.size(0) *
                                   this->BoardCoords.size(1)) *
                                  i)) +
                                1];
        }
      }
      squeeze(b_this, p1);
      loop_ub = this->BoardCoords.size(1);
      b_loop_ub = this->BoardCoords.size(2);
      b_this.set_size(1, loop_ub, b_loop_ub);
      for (i = 0; i < b_loop_ub; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_this[i1 + (b_this.size(1) * i)] =
              this->BoardCoords[(this->BoardCoords.size(0) * i1) +
                                ((this->BoardCoords.size(0) *
                                  this->BoardCoords.size(1)) *
                                 i)];
        }
      }
      squeeze(b_this, p2);
      loop_ub = p2.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = p2.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          double d;
          d = p2[i1 + (p2.size(0) * i)];
          d = (d + d) - p1[i1 + (p1.size(0) * i)];
          p2[i1 + (p2.size(0) * i)] = d;
        }
      }
      this->findClosestIndices(p2, newIndices);
    }
    this->expandBoardUp(newIndices, p1, r);
    this->BoardIdx.set_size(p1.size(0), p1.size(1));
    loop_ub = p1.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = p1.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        this->BoardIdx[i1 + (this->BoardIdx.size(0) * i)] =
            p1[i1 + (p1.size(0) * i)];
      }
    }
    this->BoardCoords.set_size(r.size(0), r.size(1), r.size(2));
    loop_ub = r.size(2);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r.size(1);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        numRows = r.size(0);
        for (int i2{0}; i2 < numRows; i2++) {
          this->BoardCoords
              [(i2 + (this->BoardCoords.size(0) * i1)) +
               ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) * i)] =
              r[(i2 + (r.size(0) * i1)) + ((r.size(0) * r.size(1)) * i)];
        }
      }
    }
    oldEnergy = this->computeNewEnergyVertical(oldEnergy);
  } break;
  case 2: {
    int b_i;
    int b_loop_ub;
    int i;
    int i1;
    int i2;
    int loop_ub;
    int numRows;
    numRows = this->BoardCoords.size(0);
    if ((static_cast<double>(numRows)) <
        ((static_cast<double>(numRows)) - 2.0)) {
      idx.set_size(1, 0);
    } else {
      loop_ub = static_cast<int>(
          static_cast<double>(-(((static_cast<double>(numRows)) - 2.0) -
                                (static_cast<double>(numRows)))));
      idx.set_size(1, loop_ub + 1);
      for (i = 0; i <= loop_ub; i++) {
        idx[i] = (static_cast<double>(numRows)) - (static_cast<double>(i));
      }
    }
    if (this->IsDistortionHigh) {
      boolean_T exitg1;
      boolean_T y;
      this->fitPolynomialIndices(idx, newIndices);
      y = true;
      numRows = 0;
      exitg1 = false;
      while ((!exitg1) && (numRows <= (newIndices.size(1) - 1))) {
        if (newIndices[numRows] == 0.0) {
          y = false;
          exitg1 = true;
        } else {
          numRows++;
        }
      }
      if (!y) {
        numRows = static_cast<int>(idx[1]);
        loop_ub = this->BoardCoords.size(1);
        b_loop_ub = this->BoardCoords.size(2);
        b_this.set_size(1, loop_ub, b_loop_ub);
        for (i = 0; i < b_loop_ub; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_this[i1 + (b_this.size(1) * i)] =
                this->BoardCoords
                    [((numRows + (this->BoardCoords.size(0) * i1)) +
                      ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                       i)) -
                     1];
          }
        }
        squeeze(b_this, p1);
        numRows = static_cast<int>(idx[0]);
        loop_ub = this->BoardCoords.size(1);
        b_loop_ub = this->BoardCoords.size(2);
        b_this.set_size(1, loop_ub, b_loop_ub);
        for (i = 0; i < b_loop_ub; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_this[i1 + (b_this.size(1) * i)] =
                this->BoardCoords
                    [((numRows + (this->BoardCoords.size(0) * i1)) +
                      ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                       i)) -
                     1];
          }
        }
        squeeze(b_this, p2);
        loop_ub = p2.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = p2.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            double d;
            d = p2[i1 + (p2.size(0) * i)];
            d = (d + d) - p1[i1 + (p1.size(0) * i)];
            p2[i1 + (p2.size(0) * i)] = d;
          }
        }
        this->findClosestIndices(p2, newIndicesLinear);
        b_loop_ub = newIndices.size(1);
        for (b_i = 0; b_i < b_loop_ub; b_i++) {
          if (newIndices[b_i] == 0.0) {
            newIndices[b_i] = newIndicesLinear[b_i];
          }
        }
      }
    } else {
      numRows = static_cast<int>(idx[1]);
      loop_ub = this->BoardCoords.size(1);
      b_loop_ub = this->BoardCoords.size(2);
      b_this.set_size(1, loop_ub, b_loop_ub);
      for (i = 0; i < b_loop_ub; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_this[i1 + (b_this.size(1) * i)] =
              this->BoardCoords[((numRows + (this->BoardCoords.size(0) * i1)) +
                                 ((this->BoardCoords.size(0) *
                                   this->BoardCoords.size(1)) *
                                  i)) -
                                1];
        }
      }
      squeeze(b_this, p1);
      numRows = static_cast<int>(idx[0]);
      loop_ub = this->BoardCoords.size(1);
      b_loop_ub = this->BoardCoords.size(2);
      b_this.set_size(1, loop_ub, b_loop_ub);
      for (i = 0; i < b_loop_ub; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_this[i1 + (b_this.size(1) * i)] =
              this->BoardCoords[((numRows + (this->BoardCoords.size(0) * i1)) +
                                 ((this->BoardCoords.size(0) *
                                   this->BoardCoords.size(1)) *
                                  i)) -
                                1];
        }
      }
      squeeze(b_this, p2);
      loop_ub = p2.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = p2.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          double d;
          d = p2[i1 + (p2.size(0) * i)];
          d = (d + d) - p1[i1 + (p1.size(0) * i)];
          p2[i1 + (p2.size(0) * i)] = d;
        }
      }
      this->findClosestIndices(p2, newIndices);
    }
    numRows = this->BoardIdx.size(0) + 1;
    b_i = this->BoardIdx.size(1);
    p1.set_size(numRows, b_i);
    for (i = 0; i < b_i; i++) {
      for (i1 = 0; i1 < numRows; i1++) {
        p1[i1 + (p1.size(0) * i)] = 0.0;
      }
    }
    numRows = this->BoardIdx.size(0);
    loop_ub = newIndices.size(1);
    for (i = 0; i < loop_ub; i++) {
      p1[numRows + (p1.size(0) * i)] = newIndices[i];
    }
    loop_ub = this->BoardIdx.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = this->BoardIdx.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        p1[i1 + (p1.size(0) * i)] =
            this->BoardIdx[i1 + (this->BoardIdx.size(0) * i)];
      }
    }
    numRows = this->BoardCoords.size(0) + 1;
    b_i = this->BoardCoords.size(1);
    b_loop_ub = this->BoardCoords.size(2);
    r.set_size(numRows, b_i, b_loop_ub);
    for (i = 0; i < b_loop_ub; i++) {
      for (i1 = 0; i1 < b_i; i1++) {
        for (i2 = 0; i2 < numRows; i2++) {
          r[(i2 + (r.size(0) * i1)) + ((r.size(0) * r.size(1)) * i)] = 0.0;
        }
      }
    }
    loop_ub = this->BoardCoords.size(2);
    r1.set_size(loop_ub);
    for (i = 0; i < loop_ub; i++) {
      r1[i] = i;
    }
    b_loop_ub = newIndices.size(1) - 1;
    numRows = 0;
    for (b_i = 0; b_i <= b_loop_ub; b_i++) {
      if (newIndices[b_i] > 0.0) {
        numRows++;
      }
    }
    r2.set_size(1, numRows);
    numRows = 0;
    for (b_i = 0; b_i <= b_loop_ub; b_i++) {
      if (newIndices[b_i] > 0.0) {
        r2[numRows] = b_i + 1;
        numRows++;
      }
    }
    loop_ub = this->Points.size(1);
    p2.set_size(r2.size(1), loop_ub);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r2.size(1);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        p2[i1 + (p2.size(0) * i)] = static_cast<double>(
            this->Points[((static_cast<int>(newIndices[r2[i1] - 1])) +
                          (this->Points.size(0) * i)) -
                         1]);
      }
    }
    b_loop_ub = newIndices.size(1) - 1;
    numRows = 0;
    for (b_i = 0; b_i <= b_loop_ub; b_i++) {
      if (newIndices[b_i] > 0.0) {
        numRows++;
      }
    }
    r3.set_size(1, numRows);
    numRows = 0;
    for (b_i = 0; b_i <= b_loop_ub; b_i++) {
      if (newIndices[b_i] > 0.0) {
        r3[numRows] = b_i + 1;
        numRows++;
      }
    }
    b_i = r3.size(1);
    numRows = this->BoardCoords.size(0);
    loop_ub = r1.size(0);
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < b_i; i1++) {
        r[(numRows + (r.size(0) * (r3[i1] - 1))) +
          ((r.size(0) * r.size(1)) * r1[i])] = p2[i1 + (b_i * i)];
      }
    }
    loop_ub = this->BoardCoords.size(2);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = this->BoardCoords.size(1);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        numRows = this->BoardCoords.size(0);
        for (i2 = 0; i2 < numRows; i2++) {
          r[(i2 + (r.size(0) * i1)) + ((r.size(0) * r.size(1)) * i)] =
              this->BoardCoords[(i2 + (this->BoardCoords.size(0) * i1)) +
                                ((this->BoardCoords.size(0) *
                                  this->BoardCoords.size(1)) *
                                 i)];
        }
      }
    }
    this->BoardIdx.set_size(p1.size(0), p1.size(1));
    loop_ub = p1.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = p1.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        this->BoardIdx[i1 + (this->BoardIdx.size(0) * i)] =
            p1[i1 + (p1.size(0) * i)];
      }
    }
    this->BoardCoords.set_size(r.size(0), r.size(1), r.size(2));
    loop_ub = r.size(2);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r.size(1);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        numRows = r.size(0);
        for (i2 = 0; i2 < numRows; i2++) {
          this->BoardCoords
              [(i2 + (this->BoardCoords.size(0) * i1)) +
               ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) * i)] =
              r[(i2 + (r.size(0) * i1)) + ((r.size(0) * r.size(1)) * i)];
        }
      }
    }
    idx.set_size(1, idx.size(1));
    loop_ub = idx.size(1);
    for (i = 0; i < loop_ub; i++) {
      idx[i] = idx[i] + 1.0;
    }
    oldEnergy = this->computeNewEnergyVertical(idx, oldEnergy);
  } break;
  case 3: {
    int b_loop_ub;
    int i;
    int i1;
    int loop_ub;
    int numRows;
    if (this->IsDistortionHigh) {
      boolean_T exitg1;
      boolean_T y;
      this->b_fitPolynomialIndices(newIndices);
      y = true;
      numRows = 0;
      exitg1 = false;
      while ((!exitg1) && (numRows <= (newIndices.size(1) - 1))) {
        if (newIndices[numRows] == 0.0) {
          y = false;
          exitg1 = true;
        } else {
          numRows++;
        }
      }
      if (!y) {
        loop_ub = this->BoardCoords.size(0);
        b_loop_ub = this->BoardCoords.size(2);
        b_this.set_size(loop_ub, 1, b_loop_ub);
        for (i = 0; i < b_loop_ub; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_this[i1 + (b_this.size(0) * i)] =
                this->BoardCoords[(i1 + this->BoardCoords.size(0)) +
                                  ((this->BoardCoords.size(0) *
                                    this->BoardCoords.size(1)) *
                                   i)];
          }
        }
        b_squeeze(b_this, p1);
        loop_ub = this->BoardCoords.size(0);
        b_loop_ub = this->BoardCoords.size(2);
        b_this.set_size(loop_ub, 1, b_loop_ub);
        for (i = 0; i < b_loop_ub; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_this[i1 + (b_this.size(0) * i)] =
                this->BoardCoords[i1 + ((this->BoardCoords.size(0) *
                                         this->BoardCoords.size(1)) *
                                        i)];
          }
        }
        b_squeeze(b_this, p2);
        loop_ub = p2.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = p2.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            double d;
            d = p2[i1 + (p2.size(0) * i)];
            d = (d + d) - p1[i1 + (p1.size(0) * i)];
            p2[i1 + (p2.size(0) * i)] = d;
          }
        }
        this->findClosestIndices(p2, newIndicesLinear);
        b_loop_ub = newIndices.size(1);
        for (int b_i{0}; b_i < b_loop_ub; b_i++) {
          if (newIndices[b_i] == 0.0) {
            newIndices[b_i] = newIndicesLinear[b_i];
          }
        }
      }
    } else {
      loop_ub = this->BoardCoords.size(0);
      b_loop_ub = this->BoardCoords.size(2);
      b_this.set_size(loop_ub, 1, b_loop_ub);
      for (i = 0; i < b_loop_ub; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_this[i1 + (b_this.size(0) * i)] =
              this->BoardCoords[(i1 + this->BoardCoords.size(0)) +
                                ((this->BoardCoords.size(0) *
                                  this->BoardCoords.size(1)) *
                                 i)];
        }
      }
      b_squeeze(b_this, p1);
      loop_ub = this->BoardCoords.size(0);
      b_loop_ub = this->BoardCoords.size(2);
      b_this.set_size(loop_ub, 1, b_loop_ub);
      for (i = 0; i < b_loop_ub; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_this[i1 + (b_this.size(0) * i)] =
              this->BoardCoords[i1 + ((this->BoardCoords.size(0) *
                                       this->BoardCoords.size(1)) *
                                      i)];
        }
      }
      b_squeeze(b_this, p2);
      loop_ub = p2.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = p2.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          double d;
          d = p2[i1 + (p2.size(0) * i)];
          d = (d + d) - p1[i1 + (p1.size(0) * i)];
          p2[i1 + (p2.size(0) * i)] = d;
        }
      }
      this->findClosestIndices(p2, newIndices);
    }
    this->expandBoardLeft(newIndices, p1, r);
    this->BoardIdx.set_size(p1.size(0), p1.size(1));
    loop_ub = p1.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = p1.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        this->BoardIdx[i1 + (this->BoardIdx.size(0) * i)] =
            p1[i1 + (p1.size(0) * i)];
      }
    }
    this->BoardCoords.set_size(r.size(0), r.size(1), r.size(2));
    loop_ub = r.size(2);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r.size(1);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        numRows = r.size(0);
        for (int i2{0}; i2 < numRows; i2++) {
          this->BoardCoords
              [(i2 + (this->BoardCoords.size(0) * i1)) +
               ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) * i)] =
              r[(i2 + (r.size(0) * i1)) + ((r.size(0) * r.size(1)) * i)];
        }
      }
    }
    oldEnergy = this->computeNewEnergyHorizontal(oldEnergy);
  } break;
  case 4: {
    int b_loop_ub;
    int i;
    int i1;
    int loop_ub;
    int numRows;
    numRows = this->BoardCoords.size(1);
    if ((static_cast<double>(numRows)) <
        ((static_cast<double>(numRows)) - 2.0)) {
      idx.set_size(1, 0);
    } else {
      loop_ub = static_cast<int>(
          static_cast<double>(-(((static_cast<double>(numRows)) - 2.0) -
                                (static_cast<double>(numRows)))));
      idx.set_size(1, loop_ub + 1);
      for (i = 0; i <= loop_ub; i++) {
        idx[i] = (static_cast<double>(numRows)) - (static_cast<double>(i));
      }
    }
    if (this->IsDistortionHigh) {
      boolean_T exitg1;
      boolean_T y;
      this->b_fitPolynomialIndices(idx, newIndices);
      y = true;
      numRows = 0;
      exitg1 = false;
      while ((!exitg1) && (numRows <= (newIndices.size(1) - 1))) {
        if (newIndices[numRows] == 0.0) {
          y = false;
          exitg1 = true;
        } else {
          numRows++;
        }
      }
      if (!y) {
        numRows = static_cast<int>(idx[1]);
        loop_ub = this->BoardCoords.size(0);
        b_loop_ub = this->BoardCoords.size(2);
        b_this.set_size(loop_ub, 1, b_loop_ub);
        for (i = 0; i < b_loop_ub; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_this[i1 + (b_this.size(0) * i)] =
                this->BoardCoords
                    [(i1 + (this->BoardCoords.size(0) * (numRows - 1))) +
                     ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                      i)];
          }
        }
        b_squeeze(b_this, p1);
        numRows = static_cast<int>(idx[0]);
        loop_ub = this->BoardCoords.size(0);
        b_loop_ub = this->BoardCoords.size(2);
        b_this.set_size(loop_ub, 1, b_loop_ub);
        for (i = 0; i < b_loop_ub; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_this[i1 + (b_this.size(0) * i)] =
                this->BoardCoords
                    [(i1 + (this->BoardCoords.size(0) * (numRows - 1))) +
                     ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                      i)];
          }
        }
        b_squeeze(b_this, p2);
        loop_ub = p2.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = p2.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            double d;
            d = p2[i1 + (p2.size(0) * i)];
            d = (d + d) - p1[i1 + (p1.size(0) * i)];
            p2[i1 + (p2.size(0) * i)] = d;
          }
        }
        this->findClosestIndices(p2, newIndicesLinear);
        b_loop_ub = newIndices.size(1);
        for (int b_i{0}; b_i < b_loop_ub; b_i++) {
          if (newIndices[b_i] == 0.0) {
            newIndices[b_i] = newIndicesLinear[b_i];
          }
        }
      }
    } else {
      numRows = static_cast<int>(idx[1]);
      loop_ub = this->BoardCoords.size(0);
      b_loop_ub = this->BoardCoords.size(2);
      b_this.set_size(loop_ub, 1, b_loop_ub);
      for (i = 0; i < b_loop_ub; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_this[i1 + (b_this.size(0) * i)] =
              this->BoardCoords
                  [(i1 + (this->BoardCoords.size(0) * (numRows - 1))) +
                   ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                    i)];
        }
      }
      b_squeeze(b_this, p1);
      numRows = static_cast<int>(idx[0]);
      loop_ub = this->BoardCoords.size(0);
      b_loop_ub = this->BoardCoords.size(2);
      b_this.set_size(loop_ub, 1, b_loop_ub);
      for (i = 0; i < b_loop_ub; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_this[i1 + (b_this.size(0) * i)] =
              this->BoardCoords
                  [(i1 + (this->BoardCoords.size(0) * (numRows - 1))) +
                   ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) *
                    i)];
        }
      }
      b_squeeze(b_this, p2);
      loop_ub = p2.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = p2.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          double d;
          d = p2[i1 + (p2.size(0) * i)];
          d = (d + d) - p1[i1 + (p1.size(0) * i)];
          p2[i1 + (p2.size(0) * i)] = d;
        }
      }
      this->findClosestIndices(p2, newIndices);
    }
    this->expandBoardRight(newIndices, p1, r);
    this->BoardIdx.set_size(p1.size(0), p1.size(1));
    loop_ub = p1.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = p1.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        this->BoardIdx[i1 + (this->BoardIdx.size(0) * i)] =
            p1[i1 + (p1.size(0) * i)];
      }
    }
    this->BoardCoords.set_size(r.size(0), r.size(1), r.size(2));
    loop_ub = r.size(2);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r.size(1);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        numRows = r.size(0);
        for (int i2{0}; i2 < numRows; i2++) {
          this->BoardCoords
              [(i2 + (this->BoardCoords.size(0) * i1)) +
               ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) * i)] =
              r[(i2 + (r.size(0) * i1)) + ((r.size(0) * r.size(1)) * i)];
        }
      }
    }
    idx.set_size(1, idx.size(1));
    loop_ub = idx.size(1);
    for (i = 0; i < loop_ub; i++) {
      idx[i] = idx[i] + 1.0;
    }
    oldEnergy = this->computeNewEnergyHorizontal(idx, oldEnergy);
  } break;
  default:
    oldEnergy = rtInfF;
    break;
  }
  this->Energy = oldEnergy;
}

//
// Arguments    : double seedIdx
//                const ::coder::array<float, 2U> &points
//                const float v1[2]
//                const float v2[2]
// Return Type  : void
//
void Checkerboard::initialize(double seedIdx,
                              const ::coder::array<float, 2U> &points,
                              const float v1[2], const float v2[2])
{
  array<double, 2U> r1;
  array<float, 2U> b_r;
  array<float, 2U> center;
  array<float, 2U> col1;
  array<float, 2U> col2;
  array<float, 2U> d;
  array<float, 2U> l;
  array<float, 2U> pointVectors;
  array<float, 2U> row3;
  array<float, 2U> u;
  array<float, 1U> euclideanDists;
  array<int, 1U> r;
  array<boolean_T, 1U> x;
  float b_z1[3];
  float z1[3];
  float b_v1[2];
  int N;
  int csz_idx_1;
  int i;
  int i1;
  int k;
  int loop_ub;
  boolean_T exitg1;
  boolean_T y;
  this->BoardIdx.set_size(1, 1);
  this->BoardIdx[0] = 0.0;
  this->BoardIdx.set_size(3, 3);
  for (i = 0; i < 3; i++) {
    this->BoardIdx[this->BoardIdx.size(0) * i] = 0.0;
    this->BoardIdx[(this->BoardIdx.size(0) * i) + 1] = 0.0;
    this->BoardIdx[(this->BoardIdx.size(0) * i) + 2] = 0.0;
  }
  this->IsDirectionBad[0] = false;
  this->IsDirectionBad[1] = false;
  this->IsDirectionBad[2] = false;
  this->IsDirectionBad[3] = false;
  this->BoardCoords.set_size(1, 1, 1);
  this->BoardCoords[0] = 0.0;
  this->BoardCoords.set_size(3, 3, 2);
  this->Points.set_size(points.size(0), 2);
  loop_ub = points.size(0);
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < 3; i1++) {
      this->BoardCoords
          [(this->BoardCoords.size(0) * i1) +
           ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) * i)] = 0.0;
      this->BoardCoords
          [((this->BoardCoords.size(0) * i1) +
            ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) * i)) +
           1] = 0.0;
      this->BoardCoords
          [((this->BoardCoords.size(0) * i1) +
            ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) * i)) +
           2] = 0.0;
    }
    for (i1 = 0; i1 < loop_ub; i1++) {
      this->Points[i1 + (this->Points.size(0) * i)] =
          points[i1 + (points.size(0) * i)];
    }
  }
  loop_ub = this->Points.size(1);
  center.set_size(1, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    center[i] = this->Points[((static_cast<int>(seedIdx)) +
                              (this->Points.size(0) * i)) -
                             1];
  }
  this->BoardIdx[this->BoardIdx.size(0) + 1] = seedIdx;
  loop_ub = this->BoardCoords.size(2);
  r.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r[i] = i;
  }
  loop_ub = r.size(0);
  for (i = 0; i < loop_ub; i++) {
    this->BoardCoords
        [(this->BoardCoords.size(0) +
          ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) * r[i])) +
         1] = static_cast<double>(center[i]);
  }
  this->LastExpandDirection = 1.0;
  this->PreviousEnergy = rtInfF;
  this->isValid = false;
  N = center.size(1);
  loop_ub = this->Points.size(1);
  if (N < loop_ub) {
    loop_ub = N;
  }
  if (center.size(1) == 1) {
    csz_idx_1 = this->Points.size(1);
  } else if (this->Points.size(1) == 1) {
    csz_idx_1 = center.size(1);
  } else if (this->Points.size(1) == center.size(1)) {
    csz_idx_1 = this->Points.size(1);
  } else {
    csz_idx_1 = loop_ub;
  }
  N = center.size(1);
  loop_ub = this->Points.size(1);
  if (N < loop_ub) {
    loop_ub = N;
  }
  if (center.size(1) == 1) {
    loop_ub = this->Points.size(1);
  } else if (this->Points.size(1) == 1) {
    loop_ub = center.size(1);
  } else if (this->Points.size(1) == center.size(1)) {
    loop_ub = this->Points.size(1);
  } else {
    /* no actions */
  }
  pointVectors.set_size(this->Points.size(0), loop_ub);
  if ((this->Points.size(0) != 0) && (csz_idx_1 != 0)) {
    int acoef;
    int bcoef;
    acoef = (this->Points.size(1) != 1);
    bcoef = (center.size(1) != 1);
    i = csz_idx_1 - 1;
    for (k = 0; k <= i; k++) {
      N = acoef * k;
      loop_ub = bcoef * k;
      csz_idx_1 = (this->Points.size(0) != 1);
      i1 = pointVectors.size(0) - 1;
      for (int b_k{0}; b_k <= i1; b_k++) {
        pointVectors[b_k + (pointVectors.size(0) * k)] =
            this->Points[(csz_idx_1 * b_k) + (this->Points.size(0) * N)] -
            center[loop_ub];
      }
    }
  }
  euclideanDists.set_size(pointVectors.size(0));
  N = pointVectors.size(0);
  for (k = 0; k < N; k++) {
    euclideanDists[k] =
        rt_hypotf_snf(pointVectors[k], pointVectors[k + pointVectors.size(0)]);
  }
  this->BoardIdx[(this->BoardIdx.size(0) * 2) + 1] =
      this->findNeighbor(pointVectors, euclideanDists, v1);
  b_v1[0] = -v1[0];
  b_v1[1] = -v1[1];
  this->BoardIdx[1] = this->findNeighbor(pointVectors, euclideanDists, b_v1);
  this->BoardIdx[this->BoardIdx.size(0) + 2] =
      this->findNeighbor(pointVectors, euclideanDists, v2);
  b_v1[0] = -v2[0];
  b_v1[1] = -v2[1];
  this->BoardIdx[this->BoardIdx.size(0)] =
      this->findNeighbor(pointVectors, euclideanDists, b_v1);
  N = this->BoardIdx.size(0) * this->BoardIdx.size(1);
  x.set_size(N);
  for (i = 0; i < N; i++) {
    x[i] = (this->BoardIdx[i] < 0.0);
  }
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= (x.size(0) - 1))) {
    if (!x[k]) {
      k++;
    } else {
      y = true;
      exitg1 = true;
    }
  }
  if (y) {
    this->isValid = false;
  } else {
    N = static_cast<int>(this->BoardIdx[(this->BoardIdx.size(0) * 2) + 1]);
    loop_ub = this->Points.size(1);
    b_r.set_size(1, loop_ub);
    for (i = 0; i < loop_ub; i++) {
      b_r[i] = this->Points[(N + (this->Points.size(0) * i)) - 1];
    }
    loop_ub = this->BoardCoords.size(2);
    r.set_size(loop_ub);
    for (i = 0; i < loop_ub; i++) {
      r[i] = i;
    }
    loop_ub = r.size(0);
    for (i = 0; i < loop_ub; i++) {
      this->BoardCoords
          [((this->BoardCoords.size(0) * 2) +
            ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) * r[i])) +
           1] = static_cast<double>(b_r[i]);
    }
    N = static_cast<int>(this->BoardIdx[1]);
    loop_ub = this->Points.size(1);
    l.set_size(1, loop_ub);
    for (i = 0; i < loop_ub; i++) {
      l[i] = this->Points[(N + (this->Points.size(0) * i)) - 1];
    }
    loop_ub = this->BoardCoords.size(2);
    r.set_size(loop_ub);
    for (i = 0; i < loop_ub; i++) {
      r[i] = i;
    }
    loop_ub = r.size(0);
    for (i = 0; i < loop_ub; i++) {
      this->BoardCoords
          [((this->BoardCoords.size(0) * this->BoardCoords.size(1)) * r[i]) +
           1] = static_cast<double>(l[i]);
    }
    N = static_cast<int>(this->BoardIdx[this->BoardIdx.size(0) + 2]);
    loop_ub = this->Points.size(1);
    d.set_size(1, loop_ub);
    for (i = 0; i < loop_ub; i++) {
      d[i] = this->Points[(N + (this->Points.size(0) * i)) - 1];
    }
    loop_ub = this->BoardCoords.size(2);
    r.set_size(loop_ub);
    for (i = 0; i < loop_ub; i++) {
      r[i] = i;
    }
    loop_ub = r.size(0);
    for (i = 0; i < loop_ub; i++) {
      this->BoardCoords
          [(this->BoardCoords.size(0) +
            ((this->BoardCoords.size(0) * this->BoardCoords.size(1)) * r[i])) +
           2] = static_cast<double>(d[i]);
    }
    N = static_cast<int>(this->BoardIdx[this->BoardIdx.size(0)]);
    loop_ub = this->Points.size(1);
    u.set_size(1, loop_ub);
    for (i = 0; i < loop_ub; i++) {
      u[i] = this->Points[(N + (this->Points.size(0) * i)) - 1];
    }
    loop_ub = this->BoardCoords.size(2);
    r.set_size(loop_ub);
    for (i = 0; i < loop_ub; i++) {
      r[i] = i;
    }
    loop_ub = r.size(0);
    for (i = 0; i < loop_ub; i++) {
      this->BoardCoords[this->BoardCoords.size(0) +
                        ((this->BoardCoords.size(0) *
                          this->BoardCoords.size(1)) *
                         r[i])] = static_cast<double>(u[i]);
    }
    u.set_size(1, u.size(1));
    loop_ub = u.size(1);
    for (i = 0; i < loop_ub; i++) {
      u[i] = u[i] - center[i];
    }
    d.set_size(1, d.size(1));
    loop_ub = d.size(1);
    for (i = 0; i < loop_ub; i++) {
      d[i] = d[i] - center[i];
    }
    b_r.set_size(1, b_r.size(1));
    loop_ub = b_r.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_r[i] = b_r[i] - center[i];
    }
    l.set_size(1, l.size(1));
    loop_ub = l.size(1);
    for (i = 0; i < loop_ub; i++) {
      l[i] = l[i] - center[i];
    }
    center.set_size(1, u.size(1));
    loop_ub = u.size(1);
    for (i = 0; i < loop_ub; i++) {
      center[i] = u[i] + l[i];
    }
    this->BoardIdx[0] =
        this->findNeighbor(pointVectors, euclideanDists, center);
    l.set_size(1, d.size(1));
    loop_ub = d.size(1);
    for (i = 0; i < loop_ub; i++) {
      l[i] = d[i] + l[i];
    }
    this->BoardIdx[2] = this->findNeighbor(pointVectors, euclideanDists, l);
    d.set_size(1, d.size(1));
    loop_ub = d.size(1);
    for (i = 0; i < loop_ub; i++) {
      d[i] = d[i] + b_r[i];
    }
    this->BoardIdx[(this->BoardIdx.size(0) * 2) + 2] =
        this->findNeighbor(pointVectors, euclideanDists, d);
    u.set_size(1, u.size(1));
    loop_ub = u.size(1);
    for (i = 0; i < loop_ub; i++) {
      u[i] = u[i] + b_r[i];
    }
    this->BoardIdx[this->BoardIdx.size(0) * 2] =
        this->findNeighbor(pointVectors, euclideanDists, u);
    N = this->BoardIdx.size(0) * this->BoardIdx.size(1);
    x.set_size(N);
    for (i = 0; i < N; i++) {
      x[i] = (this->BoardIdx[i] > 0.0);
    }
    this->isValid = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= (x.size(0) - 1))) {
      if (!x[k]) {
        this->isValid = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (this->isValid) {
      float z1_idx_0;
      loop_ub = this->BoardCoords.size(2);
      r.set_size(loop_ub);
      for (i = 0; i < loop_ub; i++) {
        r[i] = i;
      }
      N = static_cast<int>(this->BoardIdx[0]);
      loop_ub = this->Points.size(1);
      r1.set_size(1, loop_ub);
      for (i = 0; i < loop_ub; i++) {
        r1[i] = static_cast<double>(
            this->Points[(N + (this->Points.size(0) * i)) - 1]);
      }
      loop_ub = r.size(0);
      for (i = 0; i < loop_ub; i++) {
        this->BoardCoords[(this->BoardCoords.size(0) *
                           this->BoardCoords.size(1)) *
                          r[i]] = r1[i];
      }
      loop_ub = this->BoardCoords.size(2);
      r.set_size(loop_ub);
      for (i = 0; i < loop_ub; i++) {
        r[i] = i;
      }
      N = static_cast<int>(this->BoardIdx[2]);
      loop_ub = this->Points.size(1);
      r1.set_size(1, loop_ub);
      for (i = 0; i < loop_ub; i++) {
        r1[i] = static_cast<double>(
            this->Points[(N + (this->Points.size(0) * i)) - 1]);
      }
      loop_ub = r.size(0);
      for (i = 0; i < loop_ub; i++) {
        this->BoardCoords
            [((this->BoardCoords.size(0) * this->BoardCoords.size(1)) * r[i]) +
             2] = r1[i];
      }
      loop_ub = this->BoardCoords.size(2);
      r.set_size(loop_ub);
      for (i = 0; i < loop_ub; i++) {
        r[i] = i;
      }
      N = static_cast<int>(this->BoardIdx[(this->BoardIdx.size(0) * 2) + 2]);
      loop_ub = this->Points.size(1);
      r1.set_size(1, loop_ub);
      for (i = 0; i < loop_ub; i++) {
        r1[i] = static_cast<double>(
            this->Points[(N + (this->Points.size(0) * i)) - 1]);
      }
      loop_ub = r.size(0);
      for (i = 0; i < loop_ub; i++) {
        this->BoardCoords[((this->BoardCoords.size(0) * 2) +
                           ((this->BoardCoords.size(0) *
                             this->BoardCoords.size(1)) *
                            r[i])) +
                          2] = r1[i];
      }
      loop_ub = this->BoardCoords.size(2);
      r.set_size(loop_ub);
      for (i = 0; i < loop_ub; i++) {
        r[i] = i;
      }
      N = static_cast<int>(this->BoardIdx[this->BoardIdx.size(0) * 2]);
      loop_ub = this->Points.size(1);
      r1.set_size(1, loop_ub);
      for (i = 0; i < loop_ub; i++) {
        r1[i] = static_cast<double>(
            this->Points[(N + (this->Points.size(0) * i)) - 1]);
      }
      loop_ub = r.size(0);
      for (i = 0; i < loop_ub; i++) {
        this->BoardCoords[(this->BoardCoords.size(0) * 2) +
                          ((this->BoardCoords.size(0) *
                            this->BoardCoords.size(1)) *
                           r[i])] = r1[i];
      }
      N = this->BoardIdx.size(0) * this->BoardIdx.size(1);
      x.set_size(N);
      for (i = 0; i < N; i++) {
        x[i] = (this->BoardIdx[i] < 0.0);
      }
      y = false;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= (x.size(0) - 1))) {
        if (!x[k]) {
          k++;
        } else {
          y = true;
          exitg1 = true;
        }
      }
      if (y) {
        z1_idx_0 = rtInfF;
      } else {
        float z1_idx_1;
        float z1_idx_2;
        loop_ub = this->Points.size(1);
        col1.set_size(3, loop_ub);
        for (i = 0; i < loop_ub; i++) {
          col1[3 * i] = this->Points[((static_cast<int>(this->BoardIdx[0])) +
                                      (this->Points.size(0) * i)) -
                                     1];
          col1[(3 * i) + 1] =
              this->Points[((static_cast<int>(
                                this->BoardIdx[this->BoardIdx.size(0)])) +
                            (this->Points.size(0) * i)) -
                           1];
          col1[(3 * i) + 2] =
              this->Points[((static_cast<int>(
                                this->BoardIdx[this->BoardIdx.size(0) * 2])) +
                            (this->Points.size(0) * i)) -
                           1];
        }
        loop_ub = this->Points.size(1);
        col2.set_size(3, loop_ub);
        for (i = 0; i < loop_ub; i++) {
          col2[3 * i] = this->Points[((static_cast<int>(this->BoardIdx[1])) +
                                      (this->Points.size(0) * i)) -
                                     1];
          col2[(3 * i) + 1] =
              this->Points[((static_cast<int>(
                                this->BoardIdx[this->BoardIdx.size(0) + 1])) +
                            (this->Points.size(0) * i)) -
                           1];
          col2[(3 * i) + 2] =
              this->Points[((static_cast<int>(
                                this->BoardIdx[(this->BoardIdx.size(0) * 2) +
                                               1])) +
                            (this->Points.size(0) * i)) -
                           1];
        }
        loop_ub = this->Points.size(1);
        row3.set_size(3, loop_ub);
        for (i = 0; i < loop_ub; i++) {
          row3[3 * i] = this->Points[((static_cast<int>(this->BoardIdx[2])) +
                                      (this->Points.size(0) * i)) -
                                     1];
          row3[(3 * i) + 1] =
              this->Points[((static_cast<int>(
                                this->BoardIdx[this->BoardIdx.size(0) + 2])) +
                            (this->Points.size(0) * i)) -
                           1];
          row3[(3 * i) + 2] =
              this->Points[((static_cast<int>(
                                this->BoardIdx[(this->BoardIdx.size(0) * 2) +
                                               2])) +
                            (this->Points.size(0) * i)) -
                           1];
        }
        col2.set_size(3, col1.size(1));
        loop_ub = col1.size(1);
        for (i = 0; i < loop_ub; i++) {
          col2[3 * i] = (col1[3 * i] + row3[3 * i]) - (2.0F * col2[3 * i]);
          col2[(3 * i) + 1] = (col1[(3 * i) + 1] + row3[(3 * i) + 1]) -
                              (2.0F * col2[(3 * i) + 1]);
          col2[(3 * i) + 2] = (col1[(3 * i) + 2] + row3[(3 * i) + 2]) -
                              (2.0F * col2[(3 * i) + 2]);
        }
        col1.set_size(3, col1.size(1));
        loop_ub = col1.size(1);
        for (i = 0; i < loop_ub; i++) {
          col1[3 * i] = col1[3 * i] - row3[3 * i];
          col1[(3 * i) + 1] = col1[(3 * i) + 1] - row3[(3 * i) + 1];
          col1[(3 * i) + 2] = col1[(3 * i) + 2] - row3[(3 * i) + 2];
        }
        z1[0] = rt_hypotf_snf(col2[0], col2[3]);
        z1_idx_0 = rt_hypotf_snf(col1[0], col1[3]);
        z1[1] = rt_hypotf_snf(col2[1], col2[4]);
        z1_idx_1 = rt_hypotf_snf(col1[1], col1[4]);
        z1[2] = rt_hypotf_snf(col2[2], col2[5]);
        z1_idx_2 = rt_hypotf_snf(col1[2], col1[5]);
        loop_ub = this->Points.size(1);
        col1.set_size(3, loop_ub);
        for (i = 0; i < loop_ub; i++) {
          col1[3 * i] = this->Points[((static_cast<int>(this->BoardIdx[0])) +
                                      (this->Points.size(0) * i)) -
                                     1];
          col1[(3 * i) + 1] =
              this->Points[((static_cast<int>(this->BoardIdx[1])) +
                            (this->Points.size(0) * i)) -
                           1];
          col1[(3 * i) + 2] =
              this->Points[((static_cast<int>(this->BoardIdx[2])) +
                            (this->Points.size(0) * i)) -
                           1];
        }
        loop_ub = this->Points.size(1);
        col2.set_size(3, loop_ub);
        for (i = 0; i < loop_ub; i++) {
          col2[3 * i] =
              this->Points[((static_cast<int>(
                                this->BoardIdx[this->BoardIdx.size(0)])) +
                            (this->Points.size(0) * i)) -
                           1];
          col2[(3 * i) + 1] =
              this->Points[((static_cast<int>(
                                this->BoardIdx[this->BoardIdx.size(0) + 1])) +
                            (this->Points.size(0) * i)) -
                           1];
          col2[(3 * i) + 2] =
              this->Points[((static_cast<int>(
                                this->BoardIdx[this->BoardIdx.size(0) + 2])) +
                            (this->Points.size(0) * i)) -
                           1];
        }
        loop_ub = this->Points.size(1);
        row3.set_size(3, loop_ub);
        for (i = 0; i < loop_ub; i++) {
          row3[3 * i] =
              this->Points[((static_cast<int>(
                                this->BoardIdx[this->BoardIdx.size(0) * 2])) +
                            (this->Points.size(0) * i)) -
                           1];
          row3[(3 * i) + 1] =
              this->Points[((static_cast<int>(
                                this->BoardIdx[(this->BoardIdx.size(0) * 2) +
                                               1])) +
                            (this->Points.size(0) * i)) -
                           1];
          row3[(3 * i) + 2] =
              this->Points[((static_cast<int>(
                                this->BoardIdx[(this->BoardIdx.size(0) * 2) +
                                               2])) +
                            (this->Points.size(0) * i)) -
                           1];
        }
        col2.set_size(3, col1.size(1));
        loop_ub = col1.size(1);
        for (i = 0; i < loop_ub; i++) {
          col2[3 * i] = (col1[3 * i] + row3[3 * i]) - (2.0F * col2[3 * i]);
          col2[(3 * i) + 1] = (col1[(3 * i) + 1] + row3[(3 * i) + 1]) -
                              (2.0F * col2[(3 * i) + 1]);
          col2[(3 * i) + 2] = (col1[(3 * i) + 2] + row3[(3 * i) + 2]) -
                              (2.0F * col2[(3 * i) + 2]);
        }
        col1.set_size(3, col1.size(1));
        loop_ub = col1.size(1);
        for (i = 0; i < loop_ub; i++) {
          col1[3 * i] = col1[3 * i] - row3[3 * i];
          col1[(3 * i) + 1] = col1[(3 * i) + 1] - row3[(3 * i) + 1];
          col1[(3 * i) + 2] = col1[(3 * i) + 2] - row3[(3 * i) + 2];
        }
        float boardSize;
        boardSize = static_cast<float>(
            static_cast<int>(this->BoardIdx.size(0) * this->BoardIdx.size(1)));
        z1[0] /= z1_idx_0;
        b_z1[0] =
            rt_hypotf_snf(col2[0], col2[3]) / rt_hypotf_snf(col1[0], col1[3]);
        z1[1] /= z1_idx_1;
        b_z1[1] =
            rt_hypotf_snf(col2[1], col2[4]) / rt_hypotf_snf(col1[1], col1[4]);
        z1[2] /= z1_idx_2;
        b_z1[2] =
            rt_hypotf_snf(col2[2], col2[5]) / rt_hypotf_snf(col1[2], col1[5]);
        z1_idx_0 = (boardSize *
                    std::fmax(std::fmax(0.0F, ::coder::internal::maximum(z1)),
                              ::coder::internal::maximum(b_z1))) -
                   boardSize;
      }
      this->Energy = z1_idx_0;
      if (this->IsDistortionHigh) {
        loop_ub = -5;
      } else {
        loop_ub = -7;
      }
      this->isValid = ((static_cast<double>(this->Energy)) <
                       (static_cast<double>(loop_ub)));
    }
  }
}

} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

//
// File trailer for Checkerboard.cpp
//
// [EOF]
//
