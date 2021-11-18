//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Checkerboard.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "Checkerboard.h"
#include "calibrateOneCamera_rtwutil.h"
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
namespace Codegen {
static float rt_hypotf_snf(float u0, float u1);

}

// Function Definitions
//
// Arguments    : const ::coder::array<bool, 2U> &arr
//                ::coder::array<double, 2U> &matchedIdx
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void b_Checkerboard::arrayFind(const ::coder::array<bool, 2U> &arr,
                               ::coder::array<double, 2U> &matchedIdx)
{
  ::coder::array<int, 2U> c_ii;
  ::coder::array<signed char, 2U> matchArr;
  ::coder::array<bool, 2U> b_x;
  int b_ii;
  int idx;
  int nx;
  bool c_x[3];
  bool exitg1;
  matchArr.set_size(1, arr.size(1) - 2);
  b_ii = arr.size(1);
  for (idx = 0; idx <= (b_ii - 3); idx++) {
    bool y;
    c_ii.set_size(1, 3);
    for (nx = 0; nx < 3; nx++) {
      c_ii[nx] = static_cast<int>(arr[idx + nx]);
    }
    c_x[0] = (c_ii[0] == 1);
    c_x[1] = (c_ii[1] == 1);
    c_x[2] = (c_ii[2] == 1);
    y = true;
    nx = 0;
    exitg1 = false;
    while ((!exitg1) && (nx < 3)) {
      if (!c_x[nx]) {
        y = false;
        exitg1 = true;
      } else {
        nx++;
      }
    }
    matchArr[idx] = static_cast<signed char>(y);
  }
  b_x.set_size(1, matchArr.size(1));
  nx = matchArr.size(1);
  for (b_ii = 0; b_ii < nx; b_ii++) {
    b_x[b_ii] = (matchArr[b_ii] == 1);
  }
  nx = b_x.size(1);
  idx = 0;
  c_ii.set_size(1, b_x.size(1));
  b_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (b_ii <= (nx - 1))) {
    if (b_x[b_ii]) {
      idx++;
      c_ii[idx - 1] = b_ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        b_ii++;
      }
    } else {
      b_ii++;
    }
  }
  if (b_x.size(1) == 1) {
    if (idx == 0) {
      c_ii.set_size(1, 0);
    }
  } else {
    if (1 > idx) {
      idx = 0;
    }
    c_ii.set_size(c_ii.size(0), idx);
  }
  matchedIdx.set_size(1, c_ii.size(1));
  nx = c_ii.size(1);
  for (b_ii = 0; b_ii < nx; b_ii++) {
    matchedIdx[b_ii] = static_cast<double>(c_ii[b_ii]);
  }
}

//
// Arguments    : ::coder::array<double, 2U> &newIndices
// Return Type  : void
//
void b_Checkerboard::b_fitPolynomialIndices(
    ::coder::array<double, 2U> &newIndices) const
{
  ::coder::array<double, 2U> b_index;
  ::coder::array<double, 2U> b_this;
  ::coder::array<double, 2U> currCurve;
  ::coder::array<double, 2U> removedIdx;
  ::coder::array<double, 1U> b_x;
  ::coder::array<double, 1U> c_x;
  ::coder::array<int, 2U> b_ii;
  ::coder::array<int, 1U> r2;
  ::coder::array<int, 1U> r3;
  ::coder::array<int, 1U> r4;
  ::coder::array<int, 1U> r5;
  ::coder::array<bool, 1U> r;
  ::coder::array<bool, 1U> r1;
  double coordsToUse[2];
  double currPt[2];
  double y;
  int b_i;
  int c_i;
  int end;
  int loop_ub;
  loop_ub = BoardIdx.size(0);
  r.set_size(loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r[b_i] = (BoardIdx[b_i] > 0.0);
  }
  loop_ub = BoardIdx.size(0);
  r1.set_size(loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r1[b_i] = (BoardIdx[b_i + BoardIdx.size(0)] > 0.0);
  }
  end = r.size(0) - 1;
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      loop_ub++;
    }
  }
  r2.set_size(loop_ub);
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      r2[loop_ub] = c_i + 1;
      loop_ub++;
    }
  }
  end = r.size(0) - 1;
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      loop_ub++;
    }
  }
  r3.set_size(loop_ub);
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      r3[loop_ub] = c_i + 1;
      loop_ub++;
    }
  }
  b_x.set_size(r2.size(0));
  loop_ub = r2.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_x[b_i] = BoardCoords[(r2[b_i] + BoardCoords.size(0)) - 1] -
               BoardCoords[r3[b_i] - 1];
  }
  end = r.size(0) - 1;
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      loop_ub++;
    }
  }
  r4.set_size(loop_ub);
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      r4[loop_ub] = c_i + 1;
      loop_ub++;
    }
  }
  end = r.size(0) - 1;
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      loop_ub++;
    }
  }
  r5.set_size(loop_ub);
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      r5[loop_ub] = c_i + 1;
      loop_ub++;
    }
  }
  c_x.set_size(r4.size(0));
  loop_ub = r4.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    c_x[b_i] =
        BoardCoords[((r4[b_i] + BoardCoords.size(0)) +
                     (BoardCoords.size(0) * BoardCoords.size(1))) -
                    1] -
        BoardCoords[(r5[b_i] + (BoardCoords.size(0) * BoardCoords.size(1))) -
                    1];
  }
  if (std::abs(combineVectorElements(b_x) /
               (static_cast<double>(b_x.size(0)))) >
      std::abs(combineVectorElements(c_x) /
               (static_cast<double>(c_x.size(0))))) {
    coordsToUse[0] = 1.0;
    coordsToUse[1] = 2.0;
  } else {
    coordsToUse[0] = 2.0;
    coordsToUse[1] = 1.0;
  }
  loop_ub = BoardCoords.size(0);
  newIndices.set_size(1, loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    newIndices[b_i] = 0.0;
  }
  removedIdx.set_size(1, 0);
  b_i = BoardCoords.size(0);
  for (int j{0}; j < b_i; j++) {
    int i1;
    loop_ub = BoardCoords.size(1);
    b_index.set_size(1, loop_ub);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_index[i1] = BoardCoords[(j + (BoardCoords.size(0) * i1)) +
                                ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                 ((static_cast<int>(coordsToUse[0])) - 1))];
    }
    b_eml_find(b_index, b_ii);
    if (b_ii.size(1) >= 2) {
      double coordDist;
      double coordDist_tmp;
      double currCoord;
      double currRad;
      int i2;
      bool exitg1;
      i1 = static_cast<int>(coordsToUse[0]);
      coordDist_tmp =
          BoardCoords[(j + (BoardCoords.size(0) * (b_ii[0] - 1))) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * (i1 - 1))];
      end = b_ii[0];
      coordDist = (coordDist_tmp -
                   BoardCoords[(j + (BoardCoords.size(0) * (b_ii[1] - 1))) +
                               ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                (i1 - 1))]) /
                  ((static_cast<double>(b_ii[1])) - (static_cast<double>(end)));
      loop_ub = 0;
      i2 = b_ii.size(1);
      b_index.set_size(1, b_ii.size(1));
      b_this.set_size(1, b_ii.size(1));
      for (c_i = 0; c_i < i2; c_i++) {
        if (b_ii[c_i] != 0) {
          loop_ub++;
        }
        b_index[c_i] =
            BoardCoords[(j + (BoardCoords.size(0) * (b_ii[c_i] - 1))) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) *
                         (i1 - 1))];
        b_this[c_i] =
            BoardCoords[(j + (BoardCoords.size(0) * (b_ii[c_i] - 1))) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) *
                         ((static_cast<int>(coordsToUse[1])) - 1))];
      }
      if (loop_ub > 5) {
        loop_ub = 4;
      } else {
        loop_ub = 2;
      }
      b_polyfit(b_index, b_this, static_cast<double>(loop_ub), currCurve);
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
            for (c_i = 0; c_i <= (i1 - 2); c_i++) {
              y = (currCoord * y) + currCurve[c_i + 1];
            }
          }
          currPt[0] = currCoord;
          currPt[1] = y;
        } else {
          if (currCurve.size(1) != 0) {
            y = currCurve[0];
            i1 = currCurve.size(1);
            for (c_i = 0; c_i <= (i1 - 2); c_i++) {
              y = (currCoord * y) + currCurve[c_i + 1];
            }
          }
          currPt[0] = y;
          currPt[1] = currCoord;
        }
        findClosestOnCurve(currPt, std::abs(currRad), currCurve, coordsToUse,
                           removedIdx, b_index);
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
void b_Checkerboard::b_fitPolynomialIndices(
    const ::coder::array<double, 2U> &idx,
    ::coder::array<double, 2U> &newIndices) const
{
  ::coder::array<double, 2U> b_index;
  ::coder::array<double, 2U> b_this;
  ::coder::array<double, 2U> c_validIdx;
  ::coder::array<double, 2U> removedIdx;
  ::coder::array<double, 1U> b_x;
  ::coder::array<double, 1U> c_x;
  ::coder::array<int, 2U> b_ii;
  ::coder::array<int, 1U> r2;
  ::coder::array<int, 1U> r3;
  ::coder::array<int, 1U> r4;
  ::coder::array<int, 1U> r5;
  ::coder::array<bool, 1U> r;
  ::coder::array<bool, 1U> r1;
  double coordsToUse[2];
  double currPt[2];
  double y;
  int b_i;
  int b_idx_tmp;
  int end;
  int idx_tmp;
  int loop_ub;
  int trueCount;
  idx_tmp = static_cast<int>(idx[0]);
  loop_ub = BoardIdx.size(0);
  r.set_size(loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r[b_i] = (BoardIdx[b_i + (BoardIdx.size(0) * (idx_tmp - 1))] > 0.0);
  }
  b_idx_tmp = static_cast<int>(idx[1]);
  loop_ub = BoardIdx.size(0);
  r1.set_size(loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r1[b_i] = (BoardIdx[b_i + (BoardIdx.size(0) * (b_idx_tmp - 1))] > 0.0);
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
  b_x.set_size(r2.size(0));
  loop_ub = r2.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_x[b_i] =
        BoardCoords[(r2[b_i] + (BoardCoords.size(0) * (b_idx_tmp - 1))) - 1] -
        BoardCoords[(r3[b_i] + (BoardCoords.size(0) * (idx_tmp - 1))) - 1];
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
  c_x.set_size(r4.size(0));
  loop_ub = r4.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    c_x[b_i] =
        BoardCoords[((r4[b_i] + (BoardCoords.size(0) * (b_idx_tmp - 1))) +
                     (BoardCoords.size(0) * BoardCoords.size(1))) -
                    1] -
        BoardCoords[((r5[b_i] + (BoardCoords.size(0) * (idx_tmp - 1))) +
                     (BoardCoords.size(0) * BoardCoords.size(1))) -
                    1];
  }
  if (std::abs(combineVectorElements(b_x) /
               (static_cast<double>(b_x.size(0)))) >
      std::abs(combineVectorElements(c_x) /
               (static_cast<double>(c_x.size(0))))) {
    coordsToUse[0] = 1.0;
    coordsToUse[1] = 2.0;
  } else {
    coordsToUse[0] = 2.0;
    coordsToUse[1] = 1.0;
  }
  trueCount = BoardCoords.size(0);
  newIndices.set_size(1, trueCount);
  for (b_i = 0; b_i < trueCount; b_i++) {
    newIndices[b_i] = 0.0;
  }
  removedIdx.set_size(1, 0);
  b_i = BoardCoords.size(0);
  for (b_idx_tmp = 0; b_idx_tmp < b_i; b_idx_tmp++) {
    int i1;
    loop_ub = BoardCoords.size(1);
    b_index.set_size(1, loop_ub);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_index[i1] = BoardCoords[(b_idx_tmp + (BoardCoords.size(0) * i1)) +
                                ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                 ((static_cast<int>(coordsToUse[0])) - 1))];
    }
    b_eml_find(b_index, b_ii);
    c_validIdx.set_size(1, b_ii.size(1));
    loop_ub = b_ii.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      c_validIdx[i1] = static_cast<double>(b_ii[i1]);
    }
    if (c_validIdx.size(1) >= 2) {
      double coordDist;
      double currCoord;
      double currRad;
      double moveDistMultiplier;
      double refCoordValue;
      bool exitg1;
      if (idx[0] == 1.0) {
        end = static_cast<int>(c_validIdx[0]);
        moveDistMultiplier = static_cast<double>(end);
        trueCount = static_cast<int>(c_validIdx[1]);
        i1 = static_cast<int>(coordsToUse[0]);
        coordDist =
            (BoardCoords[(b_idx_tmp + (BoardCoords.size(0) * (end - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) *
                          (i1 - 1))] -
             BoardCoords[(b_idx_tmp + (BoardCoords.size(0) * (trueCount - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) *
                          (i1 - 1))]) /
            ((static_cast<double>(trueCount)) - (static_cast<double>(end)));
      } else {
        moveDistMultiplier = ((static_cast<double>(BoardCoords.size(1))) -
                              (static_cast<double>(static_cast<int>(
                                  c_validIdx[c_validIdx.size(1) - 1])))) +
                             1.0;
        end = static_cast<int>(c_validIdx[c_validIdx.size(1) - 1]);
        i1 = static_cast<int>(coordsToUse[0]);
        coordDist =
            (BoardCoords
                 [(b_idx_tmp +
                   (BoardCoords.size(0) *
                    ((static_cast<int>(c_validIdx[c_validIdx.size(1) - 1])) -
                     1))) +
                  ((BoardCoords.size(0) * BoardCoords.size(1)) * (i1 - 1))] -
             BoardCoords
                 [(b_idx_tmp +
                   (BoardCoords.size(0) *
                    ((static_cast<int>(c_validIdx[c_validIdx.size(1) - 2])) -
                     1))) +
                  ((BoardCoords.size(0) * BoardCoords.size(1)) * (i1 - 1))]) /
            ((static_cast<double>(
                 static_cast<int>(c_validIdx[c_validIdx.size(1) - 1]))) -
             (static_cast<double>(
                 static_cast<int>(c_validIdx[c_validIdx.size(1) - 2]))));
      }
      trueCount = 0;
      i1 = c_validIdx.size(1);
      for (idx_tmp = 0; idx_tmp < i1; idx_tmp++) {
        if ((static_cast<int>(c_validIdx[idx_tmp])) != 0) {
          trueCount++;
        }
      }
      b_index.set_size(1, c_validIdx.size(1));
      loop_ub = c_validIdx.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_index[i1] = BoardCoords[(b_idx_tmp +
                                   (BoardCoords.size(0) *
                                    ((static_cast<int>(c_validIdx[i1])) - 1))) +
                                  ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                   ((static_cast<int>(coordsToUse[0])) - 1))];
      }
      b_this.set_size(1, c_validIdx.size(1));
      loop_ub = c_validIdx.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_this[i1] = BoardCoords[(b_idx_tmp +
                                  (BoardCoords.size(0) *
                                   ((static_cast<int>(c_validIdx[i1])) - 1))) +
                                 ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                  ((static_cast<int>(coordsToUse[1])) - 1))];
      }
      if (trueCount > 5) {
        trueCount = 4;
      } else {
        trueCount = 2;
      }
      b_polyfit(b_index, b_this, static_cast<double>(trueCount), c_validIdx);
      currRad = coordDist / 4.0;
      refCoordValue =
          BoardCoords[(b_idx_tmp + (BoardCoords.size(0) * (end - 1))) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) *
                       ((static_cast<int>(coordsToUse[0])) - 1))];
      currCoord = currRad + refCoordValue;
      exitg1 = false;
      while ((!exitg1) &&
             (std::abs(currCoord - refCoordValue) <
              ((moveDistMultiplier * 1.5) * std::abs(coordDist)))) {
        currPt[0] = 1.0;
        currPt[1] = 2.0;
        if (isequal(coordsToUse, currPt)) {
          if (c_validIdx.size(1) != 0) {
            y = c_validIdx[0];
            i1 = c_validIdx.size(1);
            for (idx_tmp = 0; idx_tmp <= (i1 - 2); idx_tmp++) {
              y = (currCoord * y) + c_validIdx[idx_tmp + 1];
            }
          }
          currPt[0] = currCoord;
          currPt[1] = y;
        } else {
          if (c_validIdx.size(1) != 0) {
            y = c_validIdx[0];
            i1 = c_validIdx.size(1);
            for (idx_tmp = 0; idx_tmp <= (i1 - 2); idx_tmp++) {
              y = (currCoord * y) + c_validIdx[idx_tmp + 1];
            }
          }
          currPt[0] = y;
          currPt[1] = currCoord;
        }
        findClosestOnCurve(currPt, std::abs(currRad), c_validIdx, coordsToUse,
                           removedIdx, b_index);
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
float b_Checkerboard::computeNewEnergyHorizontal(float oldEnergy) const
{
  ::coder::array<double, 3U> c_this;
  ::coder::array<double, 3U> denom;
  ::coder::array<double, 3U> num;
  ::coder::array<double, 2U> b_denom;
  ::coder::array<double, 2U> b_num;
  ::coder::array<double, 2U> validNewColIdx;
  ::coder::array<double, 1U> b_y;
  ::coder::array<double, 1U> c_x;
  ::coder::array<int, 1U> r2;
  ::coder::array<int, 1U> r3;
  ::coder::array<int, 1U> r4;
  ::coder::array<int, 1U> r5;
  ::coder::array<int, 1U> r6;
  ::coder::array<bool, 2U> b_this;
  ::coder::array<bool, 1U> b_x;
  ::coder::array<bool, 1U> r;
  ::coder::array<bool, 1U> r1;
  float newEnergy;
  int b_i;
  int b_loop_ub;
  int c_i;
  int h_N;
  int k;
  int loop_ub;
  bool exitg1;
  bool y;
  loop_ub = BoardIdx.size(0);
  r.set_size(loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r[b_i] =
        ((BoardIdx[b_i] > 0.0) && (BoardIdx[b_i + BoardIdx.size(0)] > 0.0));
  }
  loop_ub = BoardIdx.size(0);
  r1.set_size(loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r1[b_i] = (BoardIdx[b_i + (BoardIdx.size(0) * 2)] > 0.0);
  }
  newEnergy = 0.0F;
  b_x.set_size(r.size(0));
  loop_ub = r.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_x[b_i] = ((r[b_i]) && (r1[b_i]));
  }
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= (b_x.size(0) - 1))) {
    if (b_x[k]) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (y) {
    k = r.size(0) - 1;
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((r[c_i]) && (r1[c_i])) {
        h_N++;
      }
    }
    r2.set_size(h_N);
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((r[c_i]) && (r1[c_i])) {
        r2[h_N] = c_i + 1;
        h_N++;
      }
    }
    k = r.size(0) - 1;
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((r[c_i]) && (r1[c_i])) {
        h_N++;
      }
    }
    r3.set_size(h_N);
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((r[c_i]) && (r1[c_i])) {
        r3[h_N] = c_i + 1;
        h_N++;
      }
    }
    k = r.size(0) - 1;
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((r[c_i]) && (r1[c_i])) {
        h_N++;
      }
    }
    r4.set_size(h_N);
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((r[c_i]) && (r1[c_i])) {
        r4[h_N] = c_i + 1;
        h_N++;
      }
    }
    loop_ub = BoardCoords.size(2);
    c_this.set_size(r2.size(0), 1, loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = r2.size(0);
      for (h_N = 0; h_N < b_loop_ub; h_N++) {
        c_this[h_N + (c_this.size(0) * b_i)] =
            (BoardCoords[(r2[h_N] +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)) -
                         1] +
             BoardCoords[((r3[h_N] + (BoardCoords.size(0) * 2)) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)) -
                         1]) -
            (2.0 *
             BoardCoords[((r4[h_N] + BoardCoords.size(0)) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)) -
                         1]);
      }
    }
    b_squeeze(c_this, b_num);
    k = r.size(0) - 1;
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((r[c_i]) && (r1[c_i])) {
        h_N++;
      }
    }
    r5.set_size(h_N);
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((r[c_i]) && (r1[c_i])) {
        r5[h_N] = c_i + 1;
        h_N++;
      }
    }
    k = r.size(0) - 1;
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((r[c_i]) && (r1[c_i])) {
        h_N++;
      }
    }
    r6.set_size(h_N);
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((r[c_i]) && (r1[c_i])) {
        r6[h_N] = c_i + 1;
        h_N++;
      }
    }
    loop_ub = BoardCoords.size(2);
    c_this.set_size(r5.size(0), 1, loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = r5.size(0);
      for (h_N = 0; h_N < b_loop_ub; h_N++) {
        c_this[h_N + (c_this.size(0) * b_i)] =
            BoardCoords[(r5[h_N] +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)) -
                        1] -
            BoardCoords[((r6[h_N] + (BoardCoords.size(0) * 2)) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)) -
                        1];
      }
    }
    b_squeeze(c_this, b_denom);
    if (b_num.size(1) > 1) {
      c_x.set_size(b_num.size(0));
      h_N = b_num.size(0);
      for (k = 0; k < h_N; k++) {
        c_x[k] = rt_hypotd_snf(b_num[k], b_num[k + b_num.size(0)]);
      }
      b_y.set_size(b_denom.size(0));
      h_N = b_denom.size(0);
      for (k = 0; k < h_N; k++) {
        b_y[k] = rt_hypotd_snf(b_denom[k], b_denom[k + b_denom.size(0)]);
      }
      loop_ub = c_x.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        c_x[b_i] = c_x[b_i] / b_y[b_i];
      }
      newEnergy = std::fmax(
          oldEnergy,
          static_cast<float>(::Codegen::coder::internal::b_maximum(c_x)));
    } else {
      newEnergy =
          std::fmax(oldEnergy, static_cast<float>(static_cast<double>(
                                   rt_hypotd_snf(b_num[0], b_num[1]) /
                                   rt_hypotd_snf(b_denom[0], b_denom[1]))));
    }
  }
  loop_ub = BoardIdx.size(0);
  b_this.set_size(1, loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_this[b_i] = (BoardIdx[b_i] > 0.0);
  }
  b_Checkerboard::arrayFind(b_this, validNewColIdx);
  if (validNewColIdx.size(1) != 0) {
    b_i = validNewColIdx.size(1);
    loop_ub = BoardCoords.size(2);
    b_loop_ub = BoardCoords.size(2);
    for (c_i = 0; c_i < b_i; c_i++) {
      double d;
      d = validNewColIdx[c_i];
      num.set_size(1, 1, loop_ub);
      for (h_N = 0; h_N < loop_ub; h_N++) {
        num[h_N] =
            (BoardCoords[((static_cast<int>(d)) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                         1] +
             BoardCoords[((static_cast<int>(static_cast<double>(d + 2.0))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                         1]) -
            (2.0 *
             BoardCoords[((static_cast<int>(static_cast<double>(d + 1.0))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                         1]);
      }
      d = validNewColIdx[c_i];
      denom.set_size(1, 1, b_loop_ub);
      for (h_N = 0; h_N < b_loop_ub; h_N++) {
        denom[h_N] =
            BoardCoords[((static_cast<int>(d)) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                        1] -
            BoardCoords[((static_cast<int>(static_cast<double>(d + 2.0))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                        1];
      }
      if (newEnergy != 0.0F) {
        h_N = num.size(2);
        k = denom.size(2);
        c_x = num.reshape(h_N);
        b_y = denom.reshape(k);
        newEnergy = std::fmax(newEnergy, static_cast<float>(static_cast<double>(
                                             b_norm(c_x) / b_norm(b_y))));
      } else {
        h_N = num.size(2);
        k = denom.size(2);
        c_x = num.reshape(h_N);
        b_y = denom.reshape(k);
        newEnergy = std::fmax(oldEnergy, static_cast<float>(static_cast<double>(
                                             b_norm(c_x) / b_norm(b_y))));
      }
    }
  }
  if (newEnergy != 0.0F) {
    newEnergy = (newEnergy * (static_cast<float>(static_cast<int>(
                                 BoardIdx.size(0) * BoardIdx.size(1))))) -
                (static_cast<float>(
                    static_cast<int>(BoardIdx.size(0) * BoardIdx.size(1))));
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
float b_Checkerboard::computeNewEnergyHorizontal(
    const ::coder::array<double, 2U> &idx, float oldEnergy) const
{
  ::coder::array<double, 3U> c_this;
  ::coder::array<double, 3U> denom;
  ::coder::array<double, 3U> num;
  ::coder::array<double, 2U> b_denom;
  ::coder::array<double, 2U> b_num;
  ::coder::array<double, 2U> validNewColIdx;
  ::coder::array<double, 1U> b_y;
  ::coder::array<double, 1U> c_x;
  ::coder::array<int, 1U> r2;
  ::coder::array<int, 1U> r3;
  ::coder::array<int, 1U> r4;
  ::coder::array<int, 1U> r5;
  ::coder::array<int, 1U> r6;
  ::coder::array<bool, 2U> b_this;
  ::coder::array<bool, 1U> b_x;
  ::coder::array<bool, 1U> r;
  ::coder::array<bool, 1U> r1;
  float newEnergy;
  int b_i;
  int b_idx_tmp;
  int b_loop_ub;
  int c_i;
  int c_idx_tmp;
  int h_N;
  int idx_tmp;
  int k;
  int loop_ub;
  bool exitg1;
  bool y;
  idx_tmp = static_cast<int>(idx[0]);
  b_idx_tmp = static_cast<int>(idx[1]);
  loop_ub = BoardIdx.size(0);
  r.set_size(loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r[b_i] = ((BoardIdx[b_i + (BoardIdx.size(0) * (idx_tmp - 1))] > 0.0) &&
              (BoardIdx[b_i + (BoardIdx.size(0) * (b_idx_tmp - 1))] > 0.0));
  }
  c_idx_tmp = static_cast<int>(idx[2]);
  loop_ub = BoardIdx.size(0);
  r1.set_size(loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r1[b_i] = (BoardIdx[b_i + (BoardIdx.size(0) * (c_idx_tmp - 1))] > 0.0);
  }
  newEnergy = 0.0F;
  b_x.set_size(r.size(0));
  loop_ub = r.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_x[b_i] = ((r[b_i]) && (r1[b_i]));
  }
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= (b_x.size(0) - 1))) {
    if (b_x[k]) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (y) {
    k = r.size(0) - 1;
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((r[c_i]) && (r1[c_i])) {
        h_N++;
      }
    }
    r2.set_size(h_N);
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((r[c_i]) && (r1[c_i])) {
        r2[h_N] = c_i + 1;
        h_N++;
      }
    }
    k = r.size(0) - 1;
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((r[c_i]) && (r1[c_i])) {
        h_N++;
      }
    }
    r3.set_size(h_N);
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((r[c_i]) && (r1[c_i])) {
        r3[h_N] = c_i + 1;
        h_N++;
      }
    }
    k = r.size(0) - 1;
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((r[c_i]) && (r1[c_i])) {
        h_N++;
      }
    }
    r4.set_size(h_N);
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((r[c_i]) && (r1[c_i])) {
        r4[h_N] = c_i + 1;
        h_N++;
      }
    }
    loop_ub = BoardCoords.size(2);
    c_this.set_size(r2.size(0), 1, loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = r2.size(0);
      for (h_N = 0; h_N < b_loop_ub; h_N++) {
        c_this[h_N + (c_this.size(0) * b_i)] =
            (BoardCoords[((r2[h_N] + (BoardCoords.size(0) * (idx_tmp - 1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)) -
                         1] +
             BoardCoords[((r3[h_N] + (BoardCoords.size(0) * (c_idx_tmp - 1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)) -
                         1]) -
            (2.0 *
             BoardCoords[((r4[h_N] + (BoardCoords.size(0) * (b_idx_tmp - 1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)) -
                         1]);
      }
    }
    b_squeeze(c_this, b_num);
    k = r.size(0) - 1;
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((r[c_i]) && (r1[c_i])) {
        h_N++;
      }
    }
    r5.set_size(h_N);
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((r[c_i]) && (r1[c_i])) {
        r5[h_N] = c_i + 1;
        h_N++;
      }
    }
    k = r.size(0) - 1;
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((r[c_i]) && (r1[c_i])) {
        h_N++;
      }
    }
    r6.set_size(h_N);
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((r[c_i]) && (r1[c_i])) {
        r6[h_N] = c_i + 1;
        h_N++;
      }
    }
    loop_ub = BoardCoords.size(2);
    c_this.set_size(r5.size(0), 1, loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = r5.size(0);
      for (h_N = 0; h_N < b_loop_ub; h_N++) {
        c_this[h_N + (c_this.size(0) * b_i)] =
            BoardCoords[((r5[h_N] + (BoardCoords.size(0) * (idx_tmp - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)) -
                        1] -
            BoardCoords[((r6[h_N] + (BoardCoords.size(0) * (c_idx_tmp - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)) -
                        1];
      }
    }
    b_squeeze(c_this, b_denom);
    if (b_num.size(1) > 1) {
      c_x.set_size(b_num.size(0));
      h_N = b_num.size(0);
      for (k = 0; k < h_N; k++) {
        c_x[k] = rt_hypotd_snf(b_num[k], b_num[k + b_num.size(0)]);
      }
      b_y.set_size(b_denom.size(0));
      h_N = b_denom.size(0);
      for (k = 0; k < h_N; k++) {
        b_y[k] = rt_hypotd_snf(b_denom[k], b_denom[k + b_denom.size(0)]);
      }
      loop_ub = c_x.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        c_x[b_i] = c_x[b_i] / b_y[b_i];
      }
      newEnergy = std::fmax(
          oldEnergy,
          static_cast<float>(::Codegen::coder::internal::b_maximum(c_x)));
    } else {
      newEnergy =
          std::fmax(oldEnergy, static_cast<float>(static_cast<double>(
                                   rt_hypotd_snf(b_num[0], b_num[1]) /
                                   rt_hypotd_snf(b_denom[0], b_denom[1]))));
    }
  }
  loop_ub = BoardIdx.size(0);
  b_this.set_size(1, loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_this[b_i] = (BoardIdx[b_i + (BoardIdx.size(0) * (idx_tmp - 1))] > 0.0);
  }
  b_Checkerboard::arrayFind(b_this, validNewColIdx);
  if (validNewColIdx.size(1) != 0) {
    b_i = validNewColIdx.size(1);
    loop_ub = BoardCoords.size(2);
    b_loop_ub = BoardCoords.size(2);
    for (c_i = 0; c_i < b_i; c_i++) {
      double d;
      d = validNewColIdx[c_i];
      num.set_size(1, 1, loop_ub);
      for (h_N = 0; h_N < loop_ub; h_N++) {
        num[h_N] =
            (BoardCoords[(((static_cast<int>(d)) +
                           (BoardCoords.size(0) * (idx_tmp - 1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                         1] +
             BoardCoords[(((static_cast<int>(static_cast<double>(d + 2.0))) +
                           (BoardCoords.size(0) * (idx_tmp - 1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                         1]) -
            (2.0 *
             BoardCoords[(((static_cast<int>(static_cast<double>(d + 1.0))) +
                           (BoardCoords.size(0) * (idx_tmp - 1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                         1]);
      }
      d = validNewColIdx[c_i];
      denom.set_size(1, 1, b_loop_ub);
      for (h_N = 0; h_N < b_loop_ub; h_N++) {
        denom[h_N] =
            BoardCoords[(((static_cast<int>(d)) +
                          (BoardCoords.size(0) * (idx_tmp - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                        1] -
            BoardCoords[(((static_cast<int>(static_cast<double>(d + 2.0))) +
                          (BoardCoords.size(0) * (idx_tmp - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                        1];
      }
      if (newEnergy != 0.0F) {
        h_N = num.size(2);
        k = denom.size(2);
        c_x = num.reshape(h_N);
        b_y = denom.reshape(k);
        newEnergy = std::fmax(newEnergy, static_cast<float>(static_cast<double>(
                                             b_norm(c_x) / b_norm(b_y))));
      } else {
        h_N = num.size(2);
        k = denom.size(2);
        c_x = num.reshape(h_N);
        b_y = denom.reshape(k);
        newEnergy = std::fmax(oldEnergy, static_cast<float>(static_cast<double>(
                                             b_norm(c_x) / b_norm(b_y))));
      }
    }
  }
  if (newEnergy != 0.0F) {
    newEnergy = (newEnergy * (static_cast<float>(static_cast<int>(
                                 BoardIdx.size(0) * BoardIdx.size(1))))) -
                (static_cast<float>(
                    static_cast<int>(BoardIdx.size(0) * BoardIdx.size(1))));
  } else {
    newEnergy = rtInfF;
  }
  return newEnergy;
}

//
// Arguments    : float oldEnergy
// Return Type  : float
//
float b_Checkerboard::computeNewEnergyVertical(float oldEnergy) const
{
  ::coder::array<double, 3U> b;
  ::coder::array<double, 3U> denom;
  ::coder::array<double, 3U> num;
  ::coder::array<double, 3U> r2;
  ::coder::array<double, 3U> r4;
  ::coder::array<double, 2U> b_denom;
  ::coder::array<double, 2U> b_num;
  ::coder::array<double, 2U> validNewRowIdx;
  ::coder::array<double, 1U> b_y;
  ::coder::array<double, 1U> c_x;
  ::coder::array<int, 2U> r1;
  ::coder::array<int, 2U> r3;
  ::coder::array<int, 2U> r5;
  ::coder::array<int, 2U> r6;
  ::coder::array<int, 2U> r7;
  ::coder::array<bool, 2U> b_this;
  ::coder::array<bool, 2U> b_x;
  ::coder::array<bool, 2U> r;
  float newEnergy;
  int b_i;
  int b_loop_ub;
  int c_i;
  int h_N;
  int k;
  int loop_ub;
  bool exitg1;
  bool y;
  loop_ub = BoardIdx.size(1);
  b_this.set_size(1, loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_this[b_i] = ((BoardIdx[BoardIdx.size(0) * b_i] > 0.0) &&
                   (BoardIdx[(BoardIdx.size(0) * b_i) + 1] > 0.0));
  }
  loop_ub = BoardIdx.size(1);
  r.set_size(1, loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r[b_i] = (BoardIdx[(BoardIdx.size(0) * b_i) + 2] > 0.0);
  }
  newEnergy = 0.0F;
  b_x.set_size(1, b_this.size(1));
  loop_ub = b_this.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_x[b_i] = ((b_this[b_i]) && (r[b_i]));
  }
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= (b_x.size(1) - 1))) {
    if (b_x[k]) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (y) {
    k = b_this.size(1) - 1;
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((b_this[c_i]) && (r[c_i])) {
        h_N++;
      }
    }
    r1.set_size(1, h_N);
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((b_this[c_i]) && (r[c_i])) {
        r1[h_N] = c_i + 1;
        h_N++;
      }
    }
    loop_ub = BoardCoords.size(2);
    r2.set_size(1, r1.size(1), loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = r1.size(1);
      for (h_N = 0; h_N < b_loop_ub; h_N++) {
        r2[h_N + (r2.size(1) * b_i)] =
            BoardCoords[(BoardCoords.size(0) * (r1[h_N] - 1)) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)];
      }
    }
    k = b_this.size(1) - 1;
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((b_this[c_i]) && (r[c_i])) {
        h_N++;
      }
    }
    r3.set_size(1, h_N);
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((b_this[c_i]) && (r[c_i])) {
        r3[h_N] = c_i + 1;
        h_N++;
      }
    }
    loop_ub = BoardCoords.size(2);
    r4.set_size(1, r3.size(1), loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = r3.size(1);
      for (h_N = 0; h_N < b_loop_ub; h_N++) {
        r4[h_N + (r4.size(1) * b_i)] =
            BoardCoords[((BoardCoords.size(0) * (r3[h_N] - 1)) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)) +
                        2];
      }
    }
    k = b_this.size(1) - 1;
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((b_this[c_i]) && (r[c_i])) {
        h_N++;
      }
    }
    r5.set_size(1, h_N);
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((b_this[c_i]) && (r[c_i])) {
        r5[h_N] = c_i + 1;
        h_N++;
      }
    }
    loop_ub = BoardCoords.size(2);
    b.set_size(1, r5.size(1), loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = r5.size(1);
      for (h_N = 0; h_N < b_loop_ub; h_N++) {
        b[h_N + (b.size(1) * b_i)] =
            BoardCoords[((BoardCoords.size(0) * (r5[h_N] - 1)) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)) +
                        1];
      }
    }
    r2.set_size(1, r2.size(1), r2.size(2));
    loop_ub = r2.size(2);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = r2.size(1);
      for (h_N = 0; h_N < b_loop_ub; h_N++) {
        r2[h_N + (r2.size(1) * b_i)] =
            (r2[h_N + (r2.size(1) * b_i)] + r4[h_N + (r4.size(1) * b_i)]) -
            (2.0 * b[h_N + (b.size(1) * b_i)]);
      }
    }
    squeeze(r2, b_num);
    k = b_this.size(1) - 1;
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((b_this[c_i]) && (r[c_i])) {
        h_N++;
      }
    }
    r6.set_size(1, h_N);
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((b_this[c_i]) && (r[c_i])) {
        r6[h_N] = c_i + 1;
        h_N++;
      }
    }
    loop_ub = BoardCoords.size(2);
    r2.set_size(1, r6.size(1), loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = r6.size(1);
      for (h_N = 0; h_N < b_loop_ub; h_N++) {
        r2[h_N + (r2.size(1) * b_i)] =
            BoardCoords[(BoardCoords.size(0) * (r6[h_N] - 1)) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)];
      }
    }
    k = b_this.size(1) - 1;
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((b_this[c_i]) && (r[c_i])) {
        h_N++;
      }
    }
    r7.set_size(1, h_N);
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((b_this[c_i]) && (r[c_i])) {
        r7[h_N] = c_i + 1;
        h_N++;
      }
    }
    loop_ub = BoardCoords.size(2);
    r4.set_size(1, r7.size(1), loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = r7.size(1);
      for (h_N = 0; h_N < b_loop_ub; h_N++) {
        r4[h_N + (r4.size(1) * b_i)] =
            BoardCoords[((BoardCoords.size(0) * (r7[h_N] - 1)) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)) +
                        2];
      }
    }
    r2.set_size(1, r2.size(1), r2.size(2));
    loop_ub = r2.size(2);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = r2.size(1);
      for (h_N = 0; h_N < b_loop_ub; h_N++) {
        r2[h_N + (r2.size(1) * b_i)] =
            r2[h_N + (r2.size(1) * b_i)] - r4[h_N + (r4.size(1) * b_i)];
      }
    }
    squeeze(r2, b_denom);
    if (b_num.size(1) > 1) {
      c_x.set_size(b_num.size(0));
      h_N = b_num.size(0);
      for (k = 0; k < h_N; k++) {
        c_x[k] = rt_hypotd_snf(b_num[k], b_num[k + b_num.size(0)]);
      }
      b_y.set_size(b_denom.size(0));
      h_N = b_denom.size(0);
      for (k = 0; k < h_N; k++) {
        b_y[k] = rt_hypotd_snf(b_denom[k], b_denom[k + b_denom.size(0)]);
      }
      loop_ub = c_x.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        c_x[b_i] = c_x[b_i] / b_y[b_i];
      }
      newEnergy = std::fmax(
          oldEnergy,
          static_cast<float>(::Codegen::coder::internal::b_maximum(c_x)));
    } else {
      newEnergy =
          std::fmax(oldEnergy, static_cast<float>(static_cast<double>(
                                   rt_hypotd_snf(b_num[0], b_num[1]) /
                                   rt_hypotd_snf(b_denom[0], b_denom[1]))));
    }
  }
  loop_ub = BoardIdx.size(1);
  b_this.set_size(1, loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_this[b_i] = (BoardIdx[BoardIdx.size(0) * b_i] > 0.0);
  }
  b_Checkerboard::arrayFind(b_this, validNewRowIdx);
  if (validNewRowIdx.size(1) != 0) {
    b_i = validNewRowIdx.size(1);
    loop_ub = BoardCoords.size(2);
    b_loop_ub = BoardCoords.size(2);
    for (c_i = 0; c_i < b_i; c_i++) {
      double d;
      d = validNewRowIdx[c_i];
      num.set_size(1, 1, loop_ub);
      for (h_N = 0; h_N < loop_ub; h_N++) {
        num[h_N] =
            (BoardCoords[(BoardCoords.size(0) * ((static_cast<int>(d)) - 1)) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)] +
             BoardCoords[(BoardCoords.size(0) *
                          ((static_cast<int>(static_cast<double>(d + 2.0))) -
                           1)) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)]) -
            (2.0 *
             BoardCoords[(BoardCoords.size(0) *
                          ((static_cast<int>(static_cast<double>(d + 1.0))) -
                           1)) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)]);
      }
      d = validNewRowIdx[c_i];
      denom.set_size(1, 1, b_loop_ub);
      for (h_N = 0; h_N < b_loop_ub; h_N++) {
        denom[h_N] =
            BoardCoords[(BoardCoords.size(0) * ((static_cast<int>(d)) - 1)) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)] -
            BoardCoords[(BoardCoords.size(0) *
                         ((static_cast<int>(static_cast<double>(d + 2.0))) -
                          1)) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)];
      }
      if (newEnergy != 0.0F) {
        h_N = num.size(2);
        k = denom.size(2);
        c_x = num.reshape(h_N);
        b_y = denom.reshape(k);
        newEnergy = std::fmax(newEnergy, static_cast<float>(static_cast<double>(
                                             b_norm(c_x) / b_norm(b_y))));
      } else {
        h_N = num.size(2);
        k = denom.size(2);
        c_x = num.reshape(h_N);
        b_y = denom.reshape(k);
        newEnergy = std::fmax(oldEnergy, static_cast<float>(static_cast<double>(
                                             b_norm(c_x) / b_norm(b_y))));
      }
    }
  }
  if (newEnergy != 0.0F) {
    newEnergy = (newEnergy * (static_cast<float>(static_cast<int>(
                                 BoardIdx.size(0) * BoardIdx.size(1))))) -
                (static_cast<float>(
                    static_cast<int>(BoardIdx.size(0) * BoardIdx.size(1))));
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
float b_Checkerboard::computeNewEnergyVertical(
    const ::coder::array<double, 2U> &idx, float oldEnergy) const
{
  ::coder::array<double, 3U> b;
  ::coder::array<double, 3U> denom;
  ::coder::array<double, 3U> num;
  ::coder::array<double, 3U> r2;
  ::coder::array<double, 3U> r4;
  ::coder::array<double, 2U> b_denom;
  ::coder::array<double, 2U> b_num;
  ::coder::array<double, 2U> validNewRowIdx;
  ::coder::array<double, 1U> b_y;
  ::coder::array<double, 1U> c_x;
  ::coder::array<int, 2U> r1;
  ::coder::array<int, 2U> r3;
  ::coder::array<int, 2U> r5;
  ::coder::array<int, 2U> r6;
  ::coder::array<int, 2U> r7;
  ::coder::array<bool, 2U> b_this;
  ::coder::array<bool, 2U> b_x;
  ::coder::array<bool, 2U> r;
  float newEnergy;
  int b_i;
  int b_idx_tmp;
  int b_loop_ub;
  int c_i;
  int c_idx_tmp;
  int h_N;
  int idx_tmp;
  int k;
  int loop_ub;
  bool exitg1;
  bool y;
  idx_tmp = static_cast<int>(idx[0]);
  b_idx_tmp = static_cast<int>(idx[1]);
  loop_ub = BoardIdx.size(1);
  b_this.set_size(1, loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_this[b_i] =
        ((BoardIdx[(idx_tmp + (BoardIdx.size(0) * b_i)) - 1] > 0.0) &&
         (BoardIdx[(b_idx_tmp + (BoardIdx.size(0) * b_i)) - 1] > 0.0));
  }
  c_idx_tmp = static_cast<int>(idx[2]);
  loop_ub = BoardIdx.size(1);
  r.set_size(1, loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r[b_i] = (BoardIdx[(c_idx_tmp + (BoardIdx.size(0) * b_i)) - 1] > 0.0);
  }
  newEnergy = 0.0F;
  b_x.set_size(1, b_this.size(1));
  loop_ub = b_this.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_x[b_i] = ((b_this[b_i]) && (r[b_i]));
  }
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= (b_x.size(1) - 1))) {
    if (b_x[k]) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (y) {
    k = b_this.size(1) - 1;
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((b_this[c_i]) && (r[c_i])) {
        h_N++;
      }
    }
    r1.set_size(1, h_N);
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((b_this[c_i]) && (r[c_i])) {
        r1[h_N] = c_i + 1;
        h_N++;
      }
    }
    loop_ub = BoardCoords.size(2);
    r2.set_size(1, r1.size(1), loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = r1.size(1);
      for (h_N = 0; h_N < b_loop_ub; h_N++) {
        r2[h_N + (r2.size(1) * b_i)] =
            BoardCoords[((idx_tmp + (BoardCoords.size(0) * (r1[h_N] - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)) -
                        1];
      }
    }
    k = b_this.size(1) - 1;
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((b_this[c_i]) && (r[c_i])) {
        h_N++;
      }
    }
    r3.set_size(1, h_N);
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((b_this[c_i]) && (r[c_i])) {
        r3[h_N] = c_i + 1;
        h_N++;
      }
    }
    loop_ub = BoardCoords.size(2);
    r4.set_size(1, r3.size(1), loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = r3.size(1);
      for (h_N = 0; h_N < b_loop_ub; h_N++) {
        r4[h_N + (r4.size(1) * b_i)] =
            BoardCoords[((c_idx_tmp + (BoardCoords.size(0) * (r3[h_N] - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)) -
                        1];
      }
    }
    k = b_this.size(1) - 1;
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((b_this[c_i]) && (r[c_i])) {
        h_N++;
      }
    }
    r5.set_size(1, h_N);
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((b_this[c_i]) && (r[c_i])) {
        r5[h_N] = c_i + 1;
        h_N++;
      }
    }
    loop_ub = BoardCoords.size(2);
    b.set_size(1, r5.size(1), loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = r5.size(1);
      for (h_N = 0; h_N < b_loop_ub; h_N++) {
        b[h_N + (b.size(1) * b_i)] =
            BoardCoords[((b_idx_tmp + (BoardCoords.size(0) * (r5[h_N] - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)) -
                        1];
      }
    }
    r2.set_size(1, r2.size(1), r2.size(2));
    loop_ub = r2.size(2);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = r2.size(1);
      for (h_N = 0; h_N < b_loop_ub; h_N++) {
        r2[h_N + (r2.size(1) * b_i)] =
            (r2[h_N + (r2.size(1) * b_i)] + r4[h_N + (r4.size(1) * b_i)]) -
            (2.0 * b[h_N + (b.size(1) * b_i)]);
      }
    }
    squeeze(r2, b_num);
    k = b_this.size(1) - 1;
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((b_this[c_i]) && (r[c_i])) {
        h_N++;
      }
    }
    r6.set_size(1, h_N);
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((b_this[c_i]) && (r[c_i])) {
        r6[h_N] = c_i + 1;
        h_N++;
      }
    }
    loop_ub = BoardCoords.size(2);
    r2.set_size(1, r6.size(1), loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = r6.size(1);
      for (h_N = 0; h_N < b_loop_ub; h_N++) {
        r2[h_N + (r2.size(1) * b_i)] =
            BoardCoords[((idx_tmp + (BoardCoords.size(0) * (r6[h_N] - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)) -
                        1];
      }
    }
    k = b_this.size(1) - 1;
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((b_this[c_i]) && (r[c_i])) {
        h_N++;
      }
    }
    r7.set_size(1, h_N);
    h_N = 0;
    for (c_i = 0; c_i <= k; c_i++) {
      if ((b_this[c_i]) && (r[c_i])) {
        r7[h_N] = c_i + 1;
        h_N++;
      }
    }
    loop_ub = BoardCoords.size(2);
    r4.set_size(1, r7.size(1), loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = r7.size(1);
      for (h_N = 0; h_N < b_loop_ub; h_N++) {
        r4[h_N + (r4.size(1) * b_i)] =
            BoardCoords[((c_idx_tmp + (BoardCoords.size(0) * (r7[h_N] - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)) -
                        1];
      }
    }
    r2.set_size(1, r2.size(1), r2.size(2));
    loop_ub = r2.size(2);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = r2.size(1);
      for (h_N = 0; h_N < b_loop_ub; h_N++) {
        r2[h_N + (r2.size(1) * b_i)] =
            r2[h_N + (r2.size(1) * b_i)] - r4[h_N + (r4.size(1) * b_i)];
      }
    }
    squeeze(r2, b_denom);
    if (b_num.size(1) > 1) {
      c_x.set_size(b_num.size(0));
      h_N = b_num.size(0);
      for (k = 0; k < h_N; k++) {
        c_x[k] = rt_hypotd_snf(b_num[k], b_num[k + b_num.size(0)]);
      }
      b_y.set_size(b_denom.size(0));
      h_N = b_denom.size(0);
      for (k = 0; k < h_N; k++) {
        b_y[k] = rt_hypotd_snf(b_denom[k], b_denom[k + b_denom.size(0)]);
      }
      loop_ub = c_x.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        c_x[b_i] = c_x[b_i] / b_y[b_i];
      }
      newEnergy = std::fmax(
          oldEnergy,
          static_cast<float>(::Codegen::coder::internal::b_maximum(c_x)));
    } else {
      newEnergy =
          std::fmax(oldEnergy, static_cast<float>(static_cast<double>(
                                   rt_hypotd_snf(b_num[0], b_num[1]) /
                                   rt_hypotd_snf(b_denom[0], b_denom[1]))));
    }
  }
  loop_ub = BoardIdx.size(1);
  b_this.set_size(1, loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_this[b_i] = (BoardIdx[(idx_tmp + (BoardIdx.size(0) * b_i)) - 1] > 0.0);
  }
  b_Checkerboard::arrayFind(b_this, validNewRowIdx);
  if (validNewRowIdx.size(1) != 0) {
    b_i = validNewRowIdx.size(1);
    loop_ub = BoardCoords.size(2);
    b_loop_ub = BoardCoords.size(2);
    for (c_i = 0; c_i < b_i; c_i++) {
      double d;
      d = validNewRowIdx[c_i];
      num.set_size(1, 1, loop_ub);
      for (h_N = 0; h_N < loop_ub; h_N++) {
        num[h_N] =
            (BoardCoords[((idx_tmp + (BoardCoords.size(0) *
                                      ((static_cast<int>(d)) - 1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                         1] +
             BoardCoords[((idx_tmp +
                           (BoardCoords.size(0) *
                            ((static_cast<int>(static_cast<double>(d + 2.0))) -
                             1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                         1]) -
            (2.0 *
             BoardCoords[((idx_tmp +
                           (BoardCoords.size(0) *
                            ((static_cast<int>(static_cast<double>(d + 1.0))) -
                             1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                         1]);
      }
      d = validNewRowIdx[c_i];
      denom.set_size(1, 1, b_loop_ub);
      for (h_N = 0; h_N < b_loop_ub; h_N++) {
        denom[h_N] =
            BoardCoords[((idx_tmp +
                          (BoardCoords.size(0) * ((static_cast<int>(d)) - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                        1] -
            BoardCoords[((idx_tmp +
                          (BoardCoords.size(0) *
                           ((static_cast<int>(static_cast<double>(d + 2.0))) -
                            1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                        1];
      }
      if (newEnergy != 0.0F) {
        h_N = num.size(2);
        k = denom.size(2);
        c_x = num.reshape(h_N);
        b_y = denom.reshape(k);
        newEnergy = std::fmax(newEnergy, static_cast<float>(static_cast<double>(
                                             b_norm(c_x) / b_norm(b_y))));
      } else {
        h_N = num.size(2);
        k = denom.size(2);
        c_x = num.reshape(h_N);
        b_y = denom.reshape(k);
        newEnergy = std::fmax(oldEnergy, static_cast<float>(static_cast<double>(
                                             b_norm(c_x) / b_norm(b_y))));
      }
    }
  }
  if (newEnergy != 0.0F) {
    newEnergy = (newEnergy * (static_cast<float>(static_cast<int>(
                                 BoardIdx.size(0) * BoardIdx.size(1))))) -
                (static_cast<float>(
                    static_cast<int>(BoardIdx.size(0) * BoardIdx.size(1))));
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
void b_Checkerboard::expandBoardLeft(
    const ::coder::array<double, 2U> &indices,
    ::coder::array<double, 2U> &newBoard,
    ::coder::array<double, 3U> &newBoardCoords) const
{
  ::coder::array<double, 2U> r2;
  ::coder::array<int, 2U> r1;
  ::coder::array<int, 2U> r3;
  ::coder::array<int, 1U> r;
  int b_i;
  int i1;
  int i2;
  int loop_ub;
  int this_idx_0;
  int this_idx_1;
  int this_idx_2;
  this_idx_0 = BoardIdx.size(0);
  this_idx_1 = BoardIdx.size(1) + 1;
  newBoard.set_size(this_idx_0, this_idx_1);
  for (b_i = 0; b_i < this_idx_1; b_i++) {
    for (i1 = 0; i1 < this_idx_0; i1++) {
      newBoard[i1 + (newBoard.size(0) * b_i)] = 0.0;
    }
  }
  loop_ub = BoardIdx.size(0);
  r.set_size(loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r[b_i] = b_i;
  }
  loop_ub = r.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    newBoard[r[b_i]] = indices[b_i];
  }
  b_i = static_cast<int>(2 <= newBoard.size(1));
  loop_ub = BoardIdx.size(1);
  for (i1 = 0; i1 < loop_ub; i1++) {
    this_idx_1 = BoardIdx.size(0);
    for (i2 = 0; i2 < this_idx_1; i2++) {
      newBoard[i2 + (newBoard.size(0) * (b_i + i1))] =
          BoardIdx[i2 + (BoardIdx.size(0) * i1)];
    }
  }
  this_idx_0 = BoardCoords.size(0);
  this_idx_1 = BoardCoords.size(1) + 1;
  this_idx_2 = BoardCoords.size(2);
  newBoardCoords.set_size(this_idx_0, this_idx_1, this_idx_2);
  for (b_i = 0; b_i < this_idx_2; b_i++) {
    for (i1 = 0; i1 < this_idx_1; i1++) {
      for (i2 = 0; i2 < this_idx_0; i2++) {
        newBoardCoords[(i2 + (newBoardCoords.size(0) * i1)) +
                       ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                        b_i)] = 0.0;
      }
    }
  }
  loop_ub = BoardCoords.size(2);
  r.set_size(loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r[b_i] = b_i;
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
  loop_ub = Points.size(1);
  r2.set_size(r1.size(1), loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    this_idx_1 = r1.size(1);
    for (i1 = 0; i1 < this_idx_1; i1++) {
      r2[i1 + (r2.size(0) * b_i)] =
          static_cast<double>(Points[((static_cast<int>(indices[r1[i1] - 1])) +
                                      (Points.size(0) * b_i)) -
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
  for (b_i = 0; b_i < loop_ub; b_i++) {
    for (i1 = 0; i1 < this_idx_0; i1++) {
      newBoardCoords[(r3[i1] +
                      ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                       r[b_i])) -
                     1] = r2[i1 + (this_idx_0 * b_i)];
    }
  }
  b_i = static_cast<int>(2 <= newBoardCoords.size(1));
  loop_ub = BoardCoords.size(2);
  for (i1 = 0; i1 < loop_ub; i1++) {
    this_idx_1 = BoardCoords.size(1);
    for (i2 = 0; i2 < this_idx_1; i2++) {
      this_idx_2 = BoardCoords.size(0);
      for (this_idx_0 = 0; this_idx_0 < this_idx_2; this_idx_0++) {
        newBoardCoords[(this_idx_0 + (newBoardCoords.size(0) * (b_i + i2))) +
                       ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                        i1)] =
            BoardCoords[(this_idx_0 + (BoardCoords.size(0) * i2)) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) * i1)];
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
void b_Checkerboard::expandBoardRight(
    const ::coder::array<double, 2U> &indices,
    ::coder::array<double, 2U> &newBoard,
    ::coder::array<double, 3U> &newBoardCoords) const
{
  ::coder::array<double, 2U> r2;
  ::coder::array<int, 2U> r1;
  ::coder::array<int, 2U> r3;
  ::coder::array<int, 1U> r;
  int b_i;
  int b_this;
  int i1;
  int i2;
  int loop_ub;
  int this_idx_0;
  int this_idx_1;
  this_idx_0 = BoardIdx.size(0);
  this_idx_1 = BoardIdx.size(1) + 1;
  newBoard.set_size(this_idx_0, this_idx_1);
  for (b_i = 0; b_i < this_idx_1; b_i++) {
    for (i1 = 0; i1 < this_idx_0; i1++) {
      newBoard[i1 + (newBoard.size(0) * b_i)] = 0.0;
    }
  }
  loop_ub = BoardIdx.size(0);
  r.set_size(loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r[b_i] = b_i;
  }
  b_this = BoardIdx.size(1);
  loop_ub = r.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    newBoard[r[b_i] + (newBoard.size(0) * b_this)] = indices[b_i];
  }
  loop_ub = BoardIdx.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_this = BoardIdx.size(0);
    for (i1 = 0; i1 < b_this; i1++) {
      newBoard[i1 + (newBoard.size(0) * b_i)] =
          BoardIdx[i1 + (BoardIdx.size(0) * b_i)];
    }
  }
  this_idx_0 = BoardCoords.size(0);
  this_idx_1 = BoardCoords.size(1) + 1;
  b_this = BoardCoords.size(2);
  newBoardCoords.set_size(this_idx_0, this_idx_1, b_this);
  for (b_i = 0; b_i < b_this; b_i++) {
    for (i1 = 0; i1 < this_idx_1; i1++) {
      for (i2 = 0; i2 < this_idx_0; i2++) {
        newBoardCoords[(i2 + (newBoardCoords.size(0) * i1)) +
                       ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                        b_i)] = 0.0;
      }
    }
  }
  loop_ub = BoardCoords.size(2);
  r.set_size(loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r[b_i] = b_i;
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
  loop_ub = Points.size(1);
  r2.set_size(r1.size(1), loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_this = r1.size(1);
    for (i1 = 0; i1 < b_this; i1++) {
      r2[i1 + (r2.size(0) * b_i)] =
          static_cast<double>(Points[((static_cast<int>(indices[r1[i1] - 1])) +
                                      (Points.size(0) * b_i)) -
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
  b_this = BoardCoords.size(1);
  loop_ub = r.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    for (i1 = 0; i1 < this_idx_0; i1++) {
      newBoardCoords[((r3[i1] + (newBoardCoords.size(0) * b_this)) +
                      ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                       r[b_i])) -
                     1] = r2[i1 + (this_idx_0 * b_i)];
    }
  }
  loop_ub = BoardCoords.size(2);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_this = BoardCoords.size(1);
    for (i1 = 0; i1 < b_this; i1++) {
      this_idx_1 = BoardCoords.size(0);
      for (i2 = 0; i2 < this_idx_1; i2++) {
        newBoardCoords[(i2 + (newBoardCoords.size(0) * i1)) +
                       ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                        b_i)] =
            BoardCoords[(i2 + (BoardCoords.size(0) * i1)) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)];
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
void b_Checkerboard::expandBoardUp(
    const ::coder::array<double, 2U> &indices,
    ::coder::array<double, 2U> &newBoard,
    ::coder::array<double, 3U> &newBoardCoords) const
{
  ::coder::array<double, 2U> r2;
  ::coder::array<int, 2U> r1;
  ::coder::array<int, 2U> r3;
  ::coder::array<int, 1U> r;
  int b_i;
  int i1;
  int i2;
  int loop_ub;
  int this_idx_0;
  int this_idx_1;
  int this_idx_2;
  this_idx_0 = BoardIdx.size(0) + 1;
  this_idx_1 = BoardIdx.size(1);
  newBoard.set_size(this_idx_0, this_idx_1);
  for (b_i = 0; b_i < this_idx_1; b_i++) {
    for (i1 = 0; i1 < this_idx_0; i1++) {
      newBoard[i1 + (newBoard.size(0) * b_i)] = 0.0;
    }
  }
  loop_ub = indices.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    newBoard[newBoard.size(0) * b_i] = indices[b_i];
  }
  b_i = static_cast<int>(2 <= newBoard.size(0));
  loop_ub = BoardIdx.size(1);
  for (i1 = 0; i1 < loop_ub; i1++) {
    this_idx_0 = BoardIdx.size(0);
    for (i2 = 0; i2 < this_idx_0; i2++) {
      newBoard[(b_i + i2) + (newBoard.size(0) * i1)] =
          BoardIdx[i2 + (BoardIdx.size(0) * i1)];
    }
  }
  this_idx_0 = BoardCoords.size(0) + 1;
  this_idx_1 = BoardCoords.size(1);
  this_idx_2 = BoardCoords.size(2);
  newBoardCoords.set_size(this_idx_0, this_idx_1, this_idx_2);
  for (b_i = 0; b_i < this_idx_2; b_i++) {
    for (i1 = 0; i1 < this_idx_1; i1++) {
      for (i2 = 0; i2 < this_idx_0; i2++) {
        newBoardCoords[(i2 + (newBoardCoords.size(0) * i1)) +
                       ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                        b_i)] = 0.0;
      }
    }
  }
  loop_ub = BoardCoords.size(2);
  r.set_size(loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r[b_i] = b_i;
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
  loop_ub = Points.size(1);
  r2.set_size(r1.size(1), loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    this_idx_0 = r1.size(1);
    for (i1 = 0; i1 < this_idx_0; i1++) {
      r2[i1 + (r2.size(0) * b_i)] =
          static_cast<double>(Points[((static_cast<int>(indices[r1[i1] - 1])) +
                                      (Points.size(0) * b_i)) -
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
  for (b_i = 0; b_i < loop_ub; b_i++) {
    for (i1 = 0; i1 < this_idx_1; i1++) {
      newBoardCoords[(newBoardCoords.size(0) * (r3[i1] - 1)) +
                     ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                      r[b_i])] = r2[i1 + (this_idx_1 * b_i)];
    }
  }
  b_i = static_cast<int>(2 <= newBoardCoords.size(0));
  loop_ub = BoardCoords.size(2);
  for (i1 = 0; i1 < loop_ub; i1++) {
    this_idx_0 = BoardCoords.size(1);
    for (i2 = 0; i2 < this_idx_0; i2++) {
      this_idx_2 = BoardCoords.size(0);
      for (this_idx_1 = 0; this_idx_1 < this_idx_2; this_idx_1++) {
        newBoardCoords[((b_i + this_idx_1) + (newBoardCoords.size(0) * i2)) +
                       ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                        i1)] =
            BoardCoords[(this_idx_1 + (BoardCoords.size(0) * i2)) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) * i1)];
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &predictedPoints
//                ::coder::array<double, 2U> &indices
// Return Type  : void
//
void b_Checkerboard::findClosestIndices(
    const ::coder::array<double, 2U> &predictedPoints,
    ::coder::array<double, 2U> &indices) const
{
  ::coder::array<double, 2U> remIdx;
  ::coder::array<double, 2U> y;
  ::coder::array<double, 1U> b_this;
  ::coder::array<float, 2U> b_a;
  ::coder::array<float, 2U> diffs;
  ::coder::array<float, 1U> dists;
  ::coder::array<int, 2U> r;
  ::coder::array<int, 1U> b_ii;
  ::coder::array<int, 1U> ib;
  ::coder::array<unsigned int, 1U> validPredictions;
  ::coder::array<bool, 2U> distIdx;
  ::coder::array<bool, 1U> b_x;
  float ex;
  int b_i;
  int i1;
  int loop_ub;
  int nx;
  indices.set_size(1, predictedPoints.size(0));
  nx = predictedPoints.size(0);
  for (b_i = 0; b_i < nx; b_i++) {
    indices[b_i] = 0.0;
  }
  nx = Points.size(0);
  if (nx < 1) {
    y.set_size(1, 0);
  } else {
    y.set_size(1, nx);
    nx--;
    for (b_i = 0; b_i <= nx; b_i++) {
      y[b_i] = (static_cast<double>(b_i)) + 1.0;
    }
  }
  nx = BoardIdx.size(0) * BoardIdx.size(1);
  b_this = BoardIdx.reshape(nx);
  do_vectors(y, b_this, remIdx, b_ii, ib);
  if (remIdx.size(1) != 0) {
    int c_ii;
    int idx;
    bool exitg1;
    nx = predictedPoints.size(0);
    b_x.set_size(predictedPoints.size(0));
    for (b_i = 0; b_i < nx; b_i++) {
      b_x[b_i] = std::isnan(predictedPoints[b_i]);
    }
    nx = b_x.size(0);
    for (b_i = 0; b_i < nx; b_i++) {
      b_x[b_i] = !b_x[b_i];
    }
    nx = b_x.size(0);
    idx = 0;
    b_ii.set_size(b_x.size(0));
    c_ii = 0;
    exitg1 = false;
    while ((!exitg1) && (c_ii <= (nx - 1))) {
      if (b_x[c_ii]) {
        idx++;
        b_ii[idx - 1] = c_ii + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          c_ii++;
        }
      } else {
        c_ii++;
      }
    }
    if (b_x.size(0) == 1) {
      if (idx == 0) {
        b_ii.set_size(0);
      }
    } else {
      if (1 > idx) {
        idx = 0;
      }
      b_ii.set_size(idx);
    }
    validPredictions.set_size(b_ii.size(0));
    nx = b_ii.size(0);
    for (b_i = 0; b_i < nx; b_i++) {
      validPredictions[b_i] = static_cast<unsigned int>(b_ii[b_i]);
    }
    b_i = validPredictions.size(0);
    if (0 <= (validPredictions.size(0) - 1)) {
      loop_ub = Points.size(1);
      i1 = predictedPoints.size(1);
    }
    for (int c_i{0}; c_i < b_i; c_i++) {
      int i2;
      int i3;
      int k;
      b_a.set_size(remIdx.size(1), loop_ub);
      for (i2 = 0; i2 < loop_ub; i2++) {
        nx = remIdx.size(1);
        for (i3 = 0; i3 < nx; i3++) {
          b_a[i3 + (b_a.size(0) * i2)] =
              Points[((static_cast<int>(remIdx[i3])) + (Points.size(0) * i2)) -
                     1];
        }
      }
      if (i1 == 1) {
        i2 = b_a.size(1);
      } else if (b_a.size(1) == 1) {
        i2 = predictedPoints.size(1);
      } else if (predictedPoints.size(1) == b_a.size(1)) {
        i2 = b_a.size(1);
      } else if (predictedPoints.size(1) < b_a.size(1)) {
        i2 = predictedPoints.size(1);
      } else {
        i2 = b_a.size(1);
      }
      diffs.set_size(b_a.size(0), i2);
      if (i2 != 0) {
        nx = static_cast<int>(b_a.size(1) != 1);
        idx = static_cast<int>(predictedPoints.size(1) != 1);
        i2--;
        for (k = 0; k <= i2; k++) {
          int acoef;
          int varargin_3;
          c_ii = nx * k;
          varargin_3 = idx * k;
          acoef = static_cast<int>(b_a.size(0) != 1);
          i3 = diffs.size(0) - 1;
          for (int b_k{0}; b_k <= i3; b_k++) {
            diffs[b_k + (diffs.size(0) * k)] =
                b_a[(acoef * b_k) + (b_a.size(0) * c_ii)] -
                (static_cast<float>(
                    predictedPoints[((static_cast<int>(validPredictions[c_i])) +
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
      for (c_ii = 0; c_ii <= idx; c_ii++) {
        if (indices[c_ii] > 0.0) {
          nx++;
        }
      }
      r.set_size(1, nx);
      nx = 0;
      for (c_ii = 0; c_ii <= idx; c_ii++) {
        if (indices[c_ii] > 0.0) {
          r[nx] = c_ii + 1;
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
      for (c_ii = 0; c_ii < idx; c_ii++) {
        if (distIdx[c_ii]) {
          dists[c_ii] = rtInfF;
        }
      }
      ::Codegen::coder::internal::minimum(dists, &ex, &nx);
      indices[(static_cast<int>(validPredictions[c_i])) - 1] = remIdx[nx - 1];
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
void b_Checkerboard::findClosestOnCurve(
    const double predictedPoint[2], double radius,
    const ::coder::array<double, 2U> &curve, const double coordsToUse[2],
    const ::coder::array<double, 2U> &removedIdx,
    ::coder::array<double, 2U> &idx) const
{
  ::coder::array<double, 2U> dataPts;
  ::coder::array<double, 2U> firstCoord;
  ::coder::array<double, 2U> remIdx;
  ::coder::array<double, 2U> y;
  ::coder::array<double, 1U> b_this;
  ::coder::array<double, 1U> dist;
  ::coder::array<float, 2U> currPt;
  ::coder::array<float, 2U> diffs;
  ::coder::array<float, 2U> queryPts;
  ::coder::array<float, 2U> z1;
  ::coder::array<float, 1U> b_y;
  ::coder::array<float, 1U> dists;
  ::coder::array<int, 1U> b_ii;
  ::coder::array<int, 1U> ib;
  ::coder::array<int, 1U> r;
  ::coder::array<bool, 1U> s;
  double dv[2];
  double a_tmp;
  int acoef;
  int b_acoef;
  int b_i;
  int b_idx;
  int b_k;
  int c_i;
  int k;
  int loop_ub;
  int outsize_idx_0;
  int outsize_idx_1;
  acoef = Points.size(0);
  if (acoef < 1) {
    y.set_size(1, 0);
  } else {
    y.set_size(1, acoef);
    b_acoef = acoef - 1;
    for (b_i = 0; b_i <= b_acoef; b_i++) {
      y[b_i] = (static_cast<double>(b_i)) + 1.0;
    }
  }
  b_acoef = BoardIdx.size(0) * BoardIdx.size(1);
  b_this = BoardIdx.reshape(b_acoef);
  do_vectors(y, b_this, remIdx, b_ii, ib);
  y.set_size(1, remIdx.size(1));
  b_acoef = remIdx.size(1) - 1;
  for (b_i = 0; b_i <= b_acoef; b_i++) {
    y[b_i] = remIdx[b_i];
  }
  b_do_vectors(y, removedIdx, remIdx, b_ii, ib);
  b_acoef = Points.size(1);
  queryPts.set_size(remIdx.size(1), b_acoef);
  for (b_i = 0; b_i < b_acoef; b_i++) {
    acoef = remIdx.size(1);
    for (b_idx = 0; b_idx < acoef; b_idx++) {
      queryPts[b_idx + (queryPts.size(0) * b_i)] =
          Points[((static_cast<int>(remIdx[b_idx])) + (Points.size(0) * b_i)) -
                 1];
    }
  }
  diffs.set_size(queryPts.size(0), 2);
  if (queryPts.size(0) != 0) {
    acoef = static_cast<int>(queryPts.size(1) != 1);
    b_acoef = static_cast<int>(queryPts.size(0) != 1);
    for (k = 0; k < 2; k++) {
      b_idx = acoef * k;
      b_i = diffs.size(0) - 1;
      for (b_k = 0; b_k <= b_i; b_k++) {
        diffs[b_k + (diffs.size(0) * k)] =
            queryPts[(b_acoef * b_k) + (queryPts.size(0) * b_idx)] -
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
  for (b_i = 0; b_i < b_acoef; b_i++) {
    s[b_i] = ((static_cast<double>(dists[b_i])) < radius);
  }
  acoef = 0;
  b_i = s.size(0);
  for (k = 0; k < b_i; k++) {
    if (s[k]) {
      acoef++;
    }
  }
  if (acoef > 1) {
    double b_a;
    bool exitg1;
    bool guard1{false};
    bool guard2{false};
    bool guard3{false};
    a_tmp = predictedPoint[(static_cast<int>(coordsToUse[0])) - 1];
    b_a = a_tmp - radius;
    a_tmp += radius;
    guard1 = false;
    guard2 = false;
    guard3 = false;
    if (std::isnan(b_a)) {
      guard2 = true;
    } else if (std::isnan(a_tmp)) {
      guard2 = true;
    } else if (a_tmp < b_a) {
      firstCoord.set_size(1, 0);
    } else if (std::isinf(b_a)) {
      guard3 = true;
    } else if (std::isinf(a_tmp)) {
      guard3 = true;
    } else {
      guard1 = true;
    }
    if (guard3) {
      if (b_a == a_tmp) {
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
      if (std::floor(b_a) == b_a) {
        b_acoef = static_cast<int>(std::floor(a_tmp - b_a));
        firstCoord.set_size(1, b_acoef + 1);
        for (b_i = 0; b_i <= b_acoef; b_i++) {
          firstCoord[b_i] = b_a + (static_cast<double>(b_i));
        }
      } else {
        eml_float_colon(b_a, a_tmp, firstCoord);
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
          for (b_i = 0; b_i < acoef; b_i++) {
            y[b_i] = curve[0];
          }
          b_i = curve.size(1);
          if (0 <= (curve.size(1) - 2)) {
            c_i = firstCoord.size(1);
          }
          for (k = 0; k <= (b_i - 2); k++) {
            a_tmp = curve[k + 1];
            y.set_size(1, firstCoord.size(1));
            for (b_idx = 0; b_idx < c_i; b_idx++) {
              y[b_idx] = (firstCoord[b_idx] * y[b_idx]) + a_tmp;
            }
          }
        }
      }
      dataPts.set_size(firstCoord.size(1), 2);
      b_acoef = firstCoord.size(1);
      for (b_i = 0; b_i < b_acoef; b_i++) {
        dataPts[b_i] = firstCoord[b_i];
      }
      b_acoef = y.size(1);
      for (b_i = 0; b_i < b_acoef; b_i++) {
        dataPts[b_i + dataPts.size(0)] = y[b_i];
      }
    } else {
      y.set_size(1, firstCoord.size(1));
      if (firstCoord.size(1) != 0) {
        if (curve.size(1) != 0) {
          acoef = firstCoord.size(1);
          y.set_size(1, firstCoord.size(1));
          for (b_i = 0; b_i < acoef; b_i++) {
            y[b_i] = curve[0];
          }
          b_i = curve.size(1);
          if (0 <= (curve.size(1) - 2)) {
            c_i = firstCoord.size(1);
          }
          for (k = 0; k <= (b_i - 2); k++) {
            a_tmp = curve[k + 1];
            y.set_size(1, firstCoord.size(1));
            for (b_idx = 0; b_idx < c_i; b_idx++) {
              y[b_idx] = (firstCoord[b_idx] * y[b_idx]) + a_tmp;
            }
          }
        }
      }
      dataPts.set_size(y.size(1), 2);
      b_acoef = y.size(1);
      for (b_i = 0; b_i < b_acoef; b_i++) {
        dataPts[b_i] = y[b_i];
      }
      b_acoef = firstCoord.size(1);
      for (b_i = 0; b_i < b_acoef; b_i++) {
        dataPts[b_i + dataPts.size(0)] = firstCoord[b_i];
      }
    }
    b_acoef = dists.size(0) - 1;
    acoef = 0;
    for (c_i = 0; c_i <= b_acoef; c_i++) {
      if ((static_cast<double>(dists[c_i])) < radius) {
        acoef++;
      }
    }
    r.set_size(acoef);
    acoef = 0;
    for (c_i = 0; c_i <= b_acoef; c_i++) {
      if ((static_cast<double>(dists[c_i])) < radius) {
        r[acoef] = c_i + 1;
        acoef++;
      }
    }
    b_acoef = Points.size(1);
    queryPts.set_size(r.size(0), b_acoef);
    for (b_i = 0; b_i < b_acoef; b_i++) {
      acoef = r.size(0);
      for (b_idx = 0; b_idx < acoef; b_idx++) {
        queryPts[b_idx + (queryPts.size(0) * b_i)] =
            Points[((static_cast<int>(remIdx[r[b_idx] - 1])) +
                    (Points.size(0) * b_i)) -
                   1];
      }
    }
    dist.set_size(queryPts.size(0));
    b_i = queryPts.size(0);
    if (0 <= (queryPts.size(0) - 1)) {
      outsize_idx_0 = dataPts.size(0);
      outsize_idx_1 = queryPts.size(1);
      loop_ub = dataPts.size(0);
    }
    for (c_i = 0; c_i < b_i; c_i++) {
      float ex;
      currPt.set_size(outsize_idx_0, outsize_idx_1);
      if ((outsize_idx_0 != 0) && (outsize_idx_1 != 0)) {
        b_acoef = queryPts.size(1) - 1;
        for (k = 0; k <= b_acoef; k++) {
          b_idx = dataPts.size(0) - 1;
          for (acoef = 0; acoef <= b_idx; acoef++) {
            currPt[acoef + (currPt.size(0) * k)] =
                queryPts[c_i + (queryPts.size(0) * k)];
          }
        }
      }
      diffs.set_size(dataPts.size(0), 2);
      for (b_idx = 0; b_idx < 2; b_idx++) {
        for (acoef = 0; acoef < loop_ub; acoef++) {
          diffs[acoef + (diffs.size(0) * b_idx)] =
              (static_cast<float>(dataPts[acoef + (dataPts.size(0) * b_idx)])) -
              currPt[acoef + (currPt.size(0) * b_idx)];
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
        b_idx = z1.size(0);
        for (k = 0; k < b_idx; k++) {
          b_y[k] = z1[k];
        }
        b_idx = z1.size(0);
        for (k = 0; k < b_idx; k++) {
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
          b_idx = 1;
        } else {
          b_idx = 0;
          k = 2;
          exitg1 = false;
          while ((!exitg1) && (k <= acoef)) {
            if (!std::isnan(b_y[k - 1])) {
              b_idx = k;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }
        if (b_idx == 0) {
          ex = b_y[0];
        } else {
          ex = b_y[b_idx - 1];
          b_idx++;
          for (k = b_idx; k <= acoef; k++) {
            float f;
            f = b_y[k - 1];
            if (ex > f) {
              ex = f;
            }
          }
        }
      }
      ex = std::sqrt(ex);
      dist[c_i] = static_cast<double>(ex);
    }
    ::Codegen::coder::internal::b_minimum(dist, &a_tmp, &acoef);
    s.set_size(dists.size(0));
    b_acoef = dists.size(0);
    for (b_i = 0; b_i < b_acoef; b_i++) {
      s[b_i] = ((static_cast<double>(dists[b_i])) < radius);
    }
    b_acoef = s.size(0);
    if (acoef <= b_acoef) {
      b_acoef = acoef;
    }
    b_idx = 0;
    b_ii.set_size(b_acoef);
    acoef = 0;
    exitg1 = false;
    while ((!exitg1) && (acoef <= (s.size(0) - 1))) {
      if (s[acoef]) {
        b_idx++;
        b_ii[b_idx - 1] = acoef + 1;
        if (b_idx >= b_acoef) {
          exitg1 = true;
        } else {
          acoef++;
        }
      } else {
        acoef++;
      }
    }
    if (b_acoef == 1) {
      if (b_idx == 0) {
        b_ii.set_size(0);
      }
    } else {
      if (1 > b_idx) {
        b_idx = 0;
      }
      b_ii.set_size(b_idx);
    }
    dist.set_size(b_ii.size(0));
    b_acoef = b_ii.size(0);
    for (b_i = 0; b_i < b_acoef; b_i++) {
      dist[b_i] = static_cast<double>(b_ii[b_i]);
    }
    idx.set_size(1, 1);
    idx[0] = remIdx[(static_cast<int>(dist[dist.size(0) - 1])) - 1];
  } else {
    s.set_size(dists.size(0));
    b_acoef = dists.size(0);
    for (b_i = 0; b_i < b_acoef; b_i++) {
      s[b_i] = ((static_cast<double>(dists[b_i])) < radius);
    }
    acoef = 0;
    b_i = s.size(0);
    for (k = 0; k < b_i; k++) {
      if (s[k]) {
        acoef++;
      }
    }
    if (acoef == 1) {
      b_acoef = dists.size(0) - 1;
      acoef = 0;
      for (c_i = 0; c_i <= b_acoef; c_i++) {
        if ((static_cast<double>(dists[c_i])) < radius) {
          acoef++;
        }
      }
      r.set_size(acoef);
      acoef = 0;
      for (c_i = 0; c_i <= b_acoef; c_i++) {
        if ((static_cast<double>(dists[c_i])) < radius) {
          r[acoef] = c_i + 1;
          acoef++;
        }
      }
      idx.set_size(1, r.size(0));
      b_acoef = r.size(0);
      for (b_i = 0; b_i < b_acoef; b_i++) {
        idx[b_i] = remIdx[r[b_i] - 1];
      }
    } else {
      idx.set_size(1, 0);
    }
  }
}

//
// Arguments    : const ::coder::array<float, 2U> &pointVectors
//                const ::coder::array<float, 1U> &euclideanDists
//                const float b_v[2]
// Return Type  : double
//
double
b_Checkerboard::findNeighbor(const ::coder::array<float, 2U> &pointVectors,
                             const ::coder::array<float, 1U> &euclideanDists,
                             const float b_v[2]) const
{
  ::coder::array<float, 1U> angleCosines;
  ::coder::array<float, 1U> dists;
  ::coder::array<int, 1U> r1;
  ::coder::array<int, 1U> r2;
  ::coder::array<bool, 2U> r;
  double neighborIdx;
  float b;
  int b_i;
  int inner;
  int k;
  int mc;
  mc = pointVectors.size(0) - 1;
  inner = pointVectors.size(1);
  angleCosines.set_size(pointVectors.size(0));
  for (b_i = 0; b_i <= mc; b_i++) {
    angleCosines[b_i] = 0.0F;
  }
  for (k = 0; k < inner; k++) {
    for (b_i = 0; b_i <= mc; b_i++) {
      angleCosines[b_i] =
          angleCosines[b_i] +
          (pointVectors[b_i + (pointVectors.size(0) * k)] * b_v[k]);
    }
  }
  b = rt_hypotf_snf(b_v[0], b_v[1]);
  mc = angleCosines.size(0);
  for (k = 0; k < mc; k++) {
    angleCosines[k] = angleCosines[k] / (euclideanDists[k] * b);
  }
  dists.set_size(euclideanDists.size(0));
  mc = euclideanDists.size(0);
  for (k = 0; k < mc; k++) {
    dists[k] = euclideanDists[k] +
               ((1.5F * euclideanDists[k]) * (1.0F - angleCosines[k]));
  }
  r.set_size(BoardIdx.size(0), BoardIdx.size(1));
  mc = BoardIdx.size(1);
  for (k = 0; k < mc; k++) {
    inner = BoardIdx.size(0);
    for (b_i = 0; b_i < inner; b_i++) {
      r[b_i + (r.size(0) * k)] = (BoardIdx[b_i + (BoardIdx.size(0) * k)] > 0.0);
    }
  }
  inner = (r.size(0) * r.size(1)) - 1;
  mc = 0;
  for (b_i = 0; b_i <= inner; b_i++) {
    if (r[b_i]) {
      mc++;
    }
  }
  r1.set_size(mc);
  mc = 0;
  for (b_i = 0; b_i <= inner; b_i++) {
    if (r[b_i]) {
      r1[mc] = b_i + 1;
      mc++;
    }
  }
  r2.set_size(r1.size(0));
  mc = r1.size(0);
  for (k = 0; k < mc; k++) {
    r2[k] = static_cast<int>(BoardIdx[r1[k] - 1]);
  }
  mc = r2.size(0);
  for (k = 0; k < mc; k++) {
    dists[r2[k] - 1] = rtInfF;
  }
  inner = angleCosines.size(0);
  for (b_i = 0; b_i < inner; b_i++) {
    if (angleCosines[b_i] < 0.0F) {
      dists[b_i] = rtInfF;
    }
  }
  ::Codegen::coder::internal::minimum(dists, &b, &mc);
  neighborIdx = static_cast<double>(mc);
  if (std::isinf(b)) {
    neighborIdx = -1.0;
  }
  return neighborIdx;
}

//
// Arguments    : const ::coder::array<float, 2U> &pointVectors
//                const ::coder::array<float, 1U> &euclideanDists
//                const ::coder::array<float, 2U> &b_v
// Return Type  : double
//
double
b_Checkerboard::findNeighbor(const ::coder::array<float, 2U> &pointVectors,
                             const ::coder::array<float, 1U> &euclideanDists,
                             const ::coder::array<float, 2U> &b_v) const
{
  ::coder::array<float, 1U> angleCosines;
  ::coder::array<float, 1U> dists;
  ::coder::array<int, 1U> r1;
  ::coder::array<int, 1U> r2;
  ::coder::array<bool, 2U> r;
  double neighborIdx;
  float bkj;
  int b_i;
  int inner;
  int k;
  int mc;
  mc = pointVectors.size(0) - 1;
  inner = pointVectors.size(1);
  angleCosines.set_size(pointVectors.size(0));
  for (b_i = 0; b_i <= mc; b_i++) {
    angleCosines[b_i] = 0.0F;
  }
  for (k = 0; k < inner; k++) {
    bkj = b_v[k];
    for (b_i = 0; b_i <= mc; b_i++) {
      angleCosines[b_i] =
          angleCosines[b_i] +
          (pointVectors[b_i + (pointVectors.size(0) * k)] * bkj);
    }
  }
  bkj = rt_hypotf_snf(b_v[0], b_v[1]);
  mc = angleCosines.size(0);
  for (k = 0; k < mc; k++) {
    angleCosines[k] = angleCosines[k] / (euclideanDists[k] * bkj);
  }
  dists.set_size(euclideanDists.size(0));
  mc = euclideanDists.size(0);
  for (k = 0; k < mc; k++) {
    dists[k] = euclideanDists[k] +
               ((1.5F * euclideanDists[k]) * (1.0F - angleCosines[k]));
  }
  r.set_size(BoardIdx.size(0), BoardIdx.size(1));
  mc = BoardIdx.size(1);
  for (k = 0; k < mc; k++) {
    inner = BoardIdx.size(0);
    for (b_i = 0; b_i < inner; b_i++) {
      r[b_i + (r.size(0) * k)] = (BoardIdx[b_i + (BoardIdx.size(0) * k)] > 0.0);
    }
  }
  inner = (r.size(0) * r.size(1)) - 1;
  mc = 0;
  for (b_i = 0; b_i <= inner; b_i++) {
    if (r[b_i]) {
      mc++;
    }
  }
  r1.set_size(mc);
  mc = 0;
  for (b_i = 0; b_i <= inner; b_i++) {
    if (r[b_i]) {
      r1[mc] = b_i + 1;
      mc++;
    }
  }
  r2.set_size(r1.size(0));
  mc = r1.size(0);
  for (k = 0; k < mc; k++) {
    r2[k] = static_cast<int>(BoardIdx[r1[k] - 1]);
  }
  mc = r2.size(0);
  for (k = 0; k < mc; k++) {
    dists[r2[k] - 1] = rtInfF;
  }
  inner = angleCosines.size(0);
  for (b_i = 0; b_i < inner; b_i++) {
    if (angleCosines[b_i] < 0.0F) {
      dists[b_i] = rtInfF;
    }
  }
  ::Codegen::coder::internal::minimum(dists, &bkj, &mc);
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
void b_Checkerboard::fitPolynomialIndices(
    ::coder::array<double, 2U> &newIndices) const
{
  ::coder::array<double, 2U> b_index;
  ::coder::array<double, 2U> currCurve;
  ::coder::array<double, 2U> r6;
  ::coder::array<double, 2U> removedIdx;
  ::coder::array<double, 1U> b_this;
  ::coder::array<double, 1U> c_this;
  ::coder::array<int, 2U> r2;
  ::coder::array<int, 2U> r3;
  ::coder::array<int, 2U> r4;
  ::coder::array<int, 2U> r5;
  ::coder::array<int, 1U> b_ii;
  ::coder::array<bool, 2U> r;
  ::coder::array<bool, 2U> r1;
  double coordsToUse[2];
  double currPt[2];
  double y;
  int b_i;
  int c_i;
  int end;
  int loop_ub;
  loop_ub = BoardIdx.size(1);
  r.set_size(1, loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r[b_i] = (BoardIdx[BoardIdx.size(0) * b_i] > 0.0);
  }
  loop_ub = BoardIdx.size(1);
  r1.set_size(1, loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r1[b_i] = (BoardIdx[(BoardIdx.size(0) * b_i) + 1] > 0.0);
  }
  end = r.size(1) - 1;
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      loop_ub++;
    }
  }
  r2.set_size(1, loop_ub);
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      r2[loop_ub] = c_i + 1;
      loop_ub++;
    }
  }
  removedIdx.set_size(1, r2.size(1));
  loop_ub = r2.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    removedIdx[b_i] = BoardCoords[(BoardCoords.size(0) * (r2[b_i] - 1)) + 1];
  }
  end = r.size(1) - 1;
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      loop_ub++;
    }
  }
  r3.set_size(1, loop_ub);
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      r3[loop_ub] = c_i + 1;
      loop_ub++;
    }
  }
  currCurve.set_size(1, r3.size(1));
  loop_ub = r3.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    currCurve[b_i] = BoardCoords[BoardCoords.size(0) * (r3[b_i] - 1)];
  }
  end = r.size(1) - 1;
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      loop_ub++;
    }
  }
  r4.set_size(1, loop_ub);
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      r4[loop_ub] = c_i + 1;
      loop_ub++;
    }
  }
  b_index.set_size(1, r4.size(1));
  loop_ub = r4.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_index[b_i] = BoardCoords[((BoardCoords.size(0) * (r4[b_i] - 1)) +
                                (BoardCoords.size(0) * BoardCoords.size(1))) +
                               1];
  }
  end = r.size(1) - 1;
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      loop_ub++;
    }
  }
  r5.set_size(1, loop_ub);
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      r5[loop_ub] = c_i + 1;
      loop_ub++;
    }
  }
  r6.set_size(1, r5.size(1));
  loop_ub = r5.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r6[b_i] = BoardCoords[(BoardCoords.size(0) * (r5[b_i] - 1)) +
                          (BoardCoords.size(0) * BoardCoords.size(1))];
  }
  removedIdx.set_size(1, removedIdx.size(1));
  loop_ub = removedIdx.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    removedIdx[b_i] = removedIdx[b_i] - currCurve[b_i];
  }
  b_index.set_size(1, b_index.size(1));
  loop_ub = b_index.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_index[b_i] = b_index[b_i] - r6[b_i];
  }
  if (std::abs(mean(removedIdx)) > std::abs(mean(b_index))) {
    coordsToUse[0] = 1.0;
    coordsToUse[1] = 2.0;
  } else {
    coordsToUse[0] = 2.0;
    coordsToUse[1] = 1.0;
  }
  loop_ub = BoardCoords.size(1);
  newIndices.set_size(1, loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    newIndices[b_i] = 0.0;
  }
  removedIdx.set_size(1, 0);
  b_i = BoardCoords.size(1);
  for (c_i = 0; c_i < b_i; c_i++) {
    int i1;
    loop_ub = BoardCoords.size(0);
    b_this.set_size(loop_ub);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_this[i1] = BoardCoords[(i1 + (BoardCoords.size(0) * c_i)) +
                               ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                ((static_cast<int>(coordsToUse[0])) - 1))];
    }
    eml_find(b_this, b_ii);
    if (b_ii.size(0) >= 2) {
      double coordDist;
      double coordDist_tmp;
      double currCoord;
      double currRad;
      int i2;
      bool exitg1;
      i1 = static_cast<int>(coordsToUse[0]);
      coordDist_tmp =
          BoardCoords[((b_ii[0] + (BoardCoords.size(0) * c_i)) +
                       ((BoardCoords.size(0) * BoardCoords.size(1)) *
                        (i1 - 1))) -
                      1];
      coordDist =
          (coordDist_tmp -
           BoardCoords[((b_ii[1] + (BoardCoords.size(0) * c_i)) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) *
                         (i1 - 1))) -
                       1]) /
          ((static_cast<double>(b_ii[1])) - (static_cast<double>(b_ii[0])));
      end = 0;
      i2 = b_ii.size(0);
      b_this.set_size(b_ii.size(0));
      c_this.set_size(b_ii.size(0));
      for (loop_ub = 0; loop_ub < i2; loop_ub++) {
        if (b_ii[loop_ub] != 0) {
          end++;
        }
        b_this[loop_ub] =
            BoardCoords[((b_ii[loop_ub] + (BoardCoords.size(0) * c_i)) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) *
                          (i1 - 1))) -
                        1];
        c_this[loop_ub] =
            BoardCoords[((b_ii[loop_ub] + (BoardCoords.size(0) * c_i)) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) *
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
              (((static_cast<double>(b_ii[0])) * 1.5) * std::abs(coordDist)))) {
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
        findClosestOnCurve(currPt, std::abs(currRad), currCurve, coordsToUse,
                           removedIdx, b_index);
        if (b_index.size(1) != 0) {
          newIndices[c_i] = b_index[0];
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
void b_Checkerboard::fitPolynomialIndices(
    const ::coder::array<double, 2U> &idx,
    ::coder::array<double, 2U> &newIndices) const
{
  ::coder::array<double, 2U> b_index;
  ::coder::array<double, 2U> currCurve;
  ::coder::array<double, 2U> r6;
  ::coder::array<double, 2U> removedIdx;
  ::coder::array<double, 1U> b_this;
  ::coder::array<double, 1U> c_this;
  ::coder::array<int, 2U> r2;
  ::coder::array<int, 2U> r3;
  ::coder::array<int, 2U> r4;
  ::coder::array<int, 2U> r5;
  ::coder::array<int, 1U> b_ii;
  ::coder::array<bool, 2U> r;
  ::coder::array<bool, 2U> r1;
  double coordsToUse[2];
  double currPt[2];
  double y;
  int b_i;
  int b_idx_tmp;
  int c_i;
  int end;
  int idx_tmp;
  int loop_ub;
  idx_tmp = static_cast<int>(idx[0]);
  loop_ub = BoardIdx.size(1);
  r.set_size(1, loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r[b_i] = (BoardIdx[(idx_tmp + (BoardIdx.size(0) * b_i)) - 1] > 0.0);
  }
  b_idx_tmp = static_cast<int>(idx[1]);
  loop_ub = BoardIdx.size(1);
  r1.set_size(1, loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r1[b_i] = (BoardIdx[(b_idx_tmp + (BoardIdx.size(0) * b_i)) - 1] > 0.0);
  }
  end = r.size(1) - 1;
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      loop_ub++;
    }
  }
  r2.set_size(1, loop_ub);
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      r2[loop_ub] = c_i + 1;
      loop_ub++;
    }
  }
  removedIdx.set_size(1, r2.size(1));
  loop_ub = r2.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    removedIdx[b_i] =
        BoardCoords[(b_idx_tmp + (BoardCoords.size(0) * (r2[b_i] - 1))) - 1];
  }
  end = r.size(1) - 1;
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      loop_ub++;
    }
  }
  r3.set_size(1, loop_ub);
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      r3[loop_ub] = c_i + 1;
      loop_ub++;
    }
  }
  currCurve.set_size(1, r3.size(1));
  loop_ub = r3.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    currCurve[b_i] =
        BoardCoords[(idx_tmp + (BoardCoords.size(0) * (r3[b_i] - 1))) - 1];
  }
  end = r.size(1) - 1;
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      loop_ub++;
    }
  }
  r4.set_size(1, loop_ub);
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      r4[loop_ub] = c_i + 1;
      loop_ub++;
    }
  }
  b_index.set_size(1, r4.size(1));
  loop_ub = r4.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_index[b_i] =
        BoardCoords[((b_idx_tmp + (BoardCoords.size(0) * (r4[b_i] - 1))) +
                     (BoardCoords.size(0) * BoardCoords.size(1))) -
                    1];
  }
  end = r.size(1) - 1;
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      loop_ub++;
    }
  }
  r5.set_size(1, loop_ub);
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      r5[loop_ub] = c_i + 1;
      loop_ub++;
    }
  }
  r6.set_size(1, r5.size(1));
  loop_ub = r5.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r6[b_i] = BoardCoords[((idx_tmp + (BoardCoords.size(0) * (r5[b_i] - 1))) +
                           (BoardCoords.size(0) * BoardCoords.size(1))) -
                          1];
  }
  removedIdx.set_size(1, removedIdx.size(1));
  loop_ub = removedIdx.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    removedIdx[b_i] = removedIdx[b_i] - currCurve[b_i];
  }
  b_index.set_size(1, b_index.size(1));
  loop_ub = b_index.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_index[b_i] = b_index[b_i] - r6[b_i];
  }
  if (std::abs(mean(removedIdx)) > std::abs(mean(b_index))) {
    coordsToUse[0] = 1.0;
    coordsToUse[1] = 2.0;
  } else {
    coordsToUse[0] = 2.0;
    coordsToUse[1] = 1.0;
  }
  loop_ub = BoardCoords.size(1);
  newIndices.set_size(1, loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    newIndices[b_i] = 0.0;
  }
  removedIdx.set_size(1, 0);
  b_i = BoardCoords.size(1);
  for (b_idx_tmp = 0; b_idx_tmp < b_i; b_idx_tmp++) {
    loop_ub = BoardCoords.size(0);
    b_this.set_size(loop_ub);
    for (c_i = 0; c_i < loop_ub; c_i++) {
      b_this[c_i] = BoardCoords[(c_i + (BoardCoords.size(0) * b_idx_tmp)) +
                                ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                 ((static_cast<int>(coordsToUse[0])) - 1))];
    }
    eml_find(b_this, b_ii);
    if (b_ii.size(0) >= 2) {
      double coordDist;
      double currCoord;
      double currRad;
      double moveDistMultiplier;
      double refCoordValue;
      int i1;
      bool exitg1;
      if (idx[0] == 1.0) {
        moveDistMultiplier = static_cast<double>(b_ii[0]);
        end = b_ii[0];
        c_i = static_cast<int>(coordsToUse[0]);
        coordDist =
            (BoardCoords[((b_ii[0] + (BoardCoords.size(0) * b_idx_tmp)) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) *
                           (c_i - 1))) -
                         1] -
             BoardCoords[((b_ii[1] + (BoardCoords.size(0) * b_idx_tmp)) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) *
                           (c_i - 1))) -
                         1]) /
            ((static_cast<double>(b_ii[1])) - (static_cast<double>(b_ii[0])));
      } else {
        moveDistMultiplier = ((static_cast<double>(BoardCoords.size(0))) -
                              (static_cast<double>(b_ii[b_ii.size(0) - 1]))) +
                             1.0;
        end = b_ii[b_ii.size(0) - 1];
        c_i = static_cast<int>(coordsToUse[0]);
        coordDist = (BoardCoords[((b_ii[b_ii.size(0) - 1] +
                                   (BoardCoords.size(0) * b_idx_tmp)) +
                                  ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                   (c_i - 1))) -
                                 1] -
                     BoardCoords[((b_ii[b_ii.size(0) - 2] +
                                   (BoardCoords.size(0) * b_idx_tmp)) +
                                  ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                   (c_i - 1))) -
                                 1]) /
                    ((static_cast<double>(b_ii[b_ii.size(0) - 1])) -
                     (static_cast<double>(b_ii[b_ii.size(0) - 2])));
      }
      loop_ub = 0;
      i1 = b_ii.size(0);
      b_this.set_size(b_ii.size(0));
      c_this.set_size(b_ii.size(0));
      for (idx_tmp = 0; idx_tmp < i1; idx_tmp++) {
        if (b_ii[idx_tmp] != 0) {
          loop_ub++;
        }
        b_this[idx_tmp] =
            BoardCoords[((b_ii[idx_tmp] + (BoardCoords.size(0) * b_idx_tmp)) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) *
                          (c_i - 1))) -
                        1];
        c_this[idx_tmp] =
            BoardCoords[((b_ii[idx_tmp] + (BoardCoords.size(0) * b_idx_tmp)) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) *
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
          BoardCoords[((end + (BoardCoords.size(0) * b_idx_tmp)) +
                       ((BoardCoords.size(0) * BoardCoords.size(1)) *
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
            c_i = currCurve.size(1);
            for (idx_tmp = 0; idx_tmp <= (c_i - 2); idx_tmp++) {
              y = (currCoord * y) + currCurve[idx_tmp + 1];
            }
          }
          currPt[0] = currCoord;
          currPt[1] = y;
        } else {
          if (currCurve.size(1) != 0) {
            y = currCurve[0];
            c_i = currCurve.size(1);
            for (idx_tmp = 0; idx_tmp <= (c_i - 2); idx_tmp++) {
              y = (currCoord * y) + currCurve[idx_tmp + 1];
            }
          }
          currPt[0] = y;
          currPt[1] = currCoord;
        }
        findClosestOnCurve(currPt, std::abs(currRad), currCurve, coordsToUse,
                           removedIdx, b_index);
        if (b_index.size(1) != 0) {
          newIndices[b_idx_tmp] = b_index[0];
          c_i = removedIdx.size(1);
          loop_ub = b_index.size(1);
          removedIdx.set_size(removedIdx.size(0),
                              removedIdx.size(1) + b_index.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            removedIdx[c_i + i1] = b_index[i1];
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
  float b_a;
  float y;
  b_a = std::abs(u0);
  y = std::abs(u1);
  if (b_a < y) {
    b_a /= y;
    y *= std::sqrt((b_a * b_a) + 1.0F);
  } else if (b_a > y) {
    y /= b_a;
    y = b_a * std::sqrt((y * y) + 1.0F);
  } else if (!std::isnan(y)) {
    y = b_a * 1.41421354F;
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
void b_Checkerboard::expandBoardDirectionally(double direction)
{
  ::coder::array<double, 3U> b_this;
  ::coder::array<double, 3U> r;
  ::coder::array<double, 2U> idx;
  ::coder::array<double, 2U> newIndices;
  ::coder::array<double, 2U> newIndicesLinear;
  ::coder::array<double, 2U> p1;
  ::coder::array<double, 2U> p2;
  ::coder::array<int, 2U> r2;
  ::coder::array<int, 2U> r3;
  ::coder::array<int, 1U> r1;
  float oldEnergy;
  oldEnergy = (Energy + (static_cast<float>(static_cast<int>(
                            BoardIdx.size(0) * BoardIdx.size(1))))) /
              (static_cast<float>(
                  static_cast<int>(BoardIdx.size(0) * BoardIdx.size(1))));
  switch (static_cast<int>(direction)) {
  case 1: {
    int b_i;
    int b_loop_ub;
    int i1;
    int loop_ub;
    int numRows;
    if (IsDistortionHigh) {
      bool exitg1;
      bool y;
      fitPolynomialIndices(newIndices);
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
        loop_ub = BoardCoords.size(1);
        b_loop_ub = BoardCoords.size(2);
        b_this.set_size(1, loop_ub, b_loop_ub);
        for (b_i = 0; b_i < b_loop_ub; b_i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_this[i1 + (b_this.size(1) * b_i)] =
                BoardCoords[((BoardCoords.size(0) * i1) +
                             ((BoardCoords.size(0) * BoardCoords.size(1)) *
                              b_i)) +
                            1];
          }
        }
        squeeze(b_this, p1);
        loop_ub = BoardCoords.size(1);
        b_loop_ub = BoardCoords.size(2);
        b_this.set_size(1, loop_ub, b_loop_ub);
        for (b_i = 0; b_i < b_loop_ub; b_i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_this[i1 + (b_this.size(1) * b_i)] =
                BoardCoords[(BoardCoords.size(0) * i1) +
                            ((BoardCoords.size(0) * BoardCoords.size(1)) *
                             b_i)];
          }
        }
        squeeze(b_this, p2);
        loop_ub = p2.size(1);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          b_loop_ub = p2.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            double d;
            d = p2[i1 + (p2.size(0) * b_i)];
            d = (d + d) - p1[i1 + (p1.size(0) * b_i)];
            p2[i1 + (p2.size(0) * b_i)] = d;
          }
        }
        findClosestIndices(p2, newIndicesLinear);
        b_loop_ub = newIndices.size(1);
        for (int c_i{0}; c_i < b_loop_ub; c_i++) {
          if (newIndices[c_i] == 0.0) {
            newIndices[c_i] = newIndicesLinear[c_i];
          }
        }
      }
    } else {
      loop_ub = BoardCoords.size(1);
      b_loop_ub = BoardCoords.size(2);
      b_this.set_size(1, loop_ub, b_loop_ub);
      for (b_i = 0; b_i < b_loop_ub; b_i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_this[i1 + (b_this.size(1) * b_i)] =
              BoardCoords[((BoardCoords.size(0) * i1) +
                           ((BoardCoords.size(0) * BoardCoords.size(1)) *
                            b_i)) +
                          1];
        }
      }
      squeeze(b_this, p1);
      loop_ub = BoardCoords.size(1);
      b_loop_ub = BoardCoords.size(2);
      b_this.set_size(1, loop_ub, b_loop_ub);
      for (b_i = 0; b_i < b_loop_ub; b_i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_this[i1 + (b_this.size(1) * b_i)] =
              BoardCoords[(BoardCoords.size(0) * i1) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)];
        }
      }
      squeeze(b_this, p2);
      loop_ub = p2.size(1);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b_loop_ub = p2.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          double d;
          d = p2[i1 + (p2.size(0) * b_i)];
          d = (d + d) - p1[i1 + (p1.size(0) * b_i)];
          p2[i1 + (p2.size(0) * b_i)] = d;
        }
      }
      findClosestIndices(p2, newIndices);
    }
    expandBoardUp(newIndices, p1, r);
    BoardIdx.set_size(p1.size(0), p1.size(1));
    loop_ub = p1.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = p1.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        BoardIdx[i1 + (BoardIdx.size(0) * b_i)] = p1[i1 + (p1.size(0) * b_i)];
      }
    }
    BoardCoords.set_size(r.size(0), r.size(1), r.size(2));
    loop_ub = r.size(2);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = r.size(1);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        numRows = r.size(0);
        for (int i2{0}; i2 < numRows; i2++) {
          BoardCoords[(i2 + (BoardCoords.size(0) * i1)) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)] =
              r[(i2 + (r.size(0) * i1)) + ((r.size(0) * r.size(1)) * b_i)];
        }
      }
    }
    oldEnergy = computeNewEnergyVertical(oldEnergy);
  } break;
  case 2: {
    int b_i;
    int b_loop_ub;
    int c_i;
    int i1;
    int i2;
    int loop_ub;
    int numRows;
    numRows = BoardCoords.size(0);
    if ((static_cast<double>(numRows)) <
        ((static_cast<double>(numRows)) - 2.0)) {
      idx.set_size(1, 0);
    } else {
      loop_ub = static_cast<int>(
          static_cast<double>(-(((static_cast<double>(numRows)) - 2.0) -
                                (static_cast<double>(numRows)))));
      idx.set_size(1, loop_ub + 1);
      for (b_i = 0; b_i <= loop_ub; b_i++) {
        idx[b_i] = (static_cast<double>(numRows)) - (static_cast<double>(b_i));
      }
    }
    if (IsDistortionHigh) {
      bool exitg1;
      bool y;
      fitPolynomialIndices(idx, newIndices);
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
        loop_ub = BoardCoords.size(1);
        b_loop_ub = BoardCoords.size(2);
        b_this.set_size(1, loop_ub, b_loop_ub);
        for (b_i = 0; b_i < b_loop_ub; b_i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_this[i1 + (b_this.size(1) * b_i)] =
                BoardCoords[((numRows + (BoardCoords.size(0) * i1)) +
                             ((BoardCoords.size(0) * BoardCoords.size(1)) *
                              b_i)) -
                            1];
          }
        }
        squeeze(b_this, p1);
        numRows = static_cast<int>(idx[0]);
        loop_ub = BoardCoords.size(1);
        b_loop_ub = BoardCoords.size(2);
        b_this.set_size(1, loop_ub, b_loop_ub);
        for (b_i = 0; b_i < b_loop_ub; b_i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_this[i1 + (b_this.size(1) * b_i)] =
                BoardCoords[((numRows + (BoardCoords.size(0) * i1)) +
                             ((BoardCoords.size(0) * BoardCoords.size(1)) *
                              b_i)) -
                            1];
          }
        }
        squeeze(b_this, p2);
        loop_ub = p2.size(1);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          b_loop_ub = p2.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            double d;
            d = p2[i1 + (p2.size(0) * b_i)];
            d = (d + d) - p1[i1 + (p1.size(0) * b_i)];
            p2[i1 + (p2.size(0) * b_i)] = d;
          }
        }
        findClosestIndices(p2, newIndicesLinear);
        b_loop_ub = newIndices.size(1);
        for (c_i = 0; c_i < b_loop_ub; c_i++) {
          if (newIndices[c_i] == 0.0) {
            newIndices[c_i] = newIndicesLinear[c_i];
          }
        }
      }
    } else {
      numRows = static_cast<int>(idx[1]);
      loop_ub = BoardCoords.size(1);
      b_loop_ub = BoardCoords.size(2);
      b_this.set_size(1, loop_ub, b_loop_ub);
      for (b_i = 0; b_i < b_loop_ub; b_i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_this[i1 + (b_this.size(1) * b_i)] =
              BoardCoords[((numRows + (BoardCoords.size(0) * i1)) +
                           ((BoardCoords.size(0) * BoardCoords.size(1)) *
                            b_i)) -
                          1];
        }
      }
      squeeze(b_this, p1);
      numRows = static_cast<int>(idx[0]);
      loop_ub = BoardCoords.size(1);
      b_loop_ub = BoardCoords.size(2);
      b_this.set_size(1, loop_ub, b_loop_ub);
      for (b_i = 0; b_i < b_loop_ub; b_i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_this[i1 + (b_this.size(1) * b_i)] =
              BoardCoords[((numRows + (BoardCoords.size(0) * i1)) +
                           ((BoardCoords.size(0) * BoardCoords.size(1)) *
                            b_i)) -
                          1];
        }
      }
      squeeze(b_this, p2);
      loop_ub = p2.size(1);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b_loop_ub = p2.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          double d;
          d = p2[i1 + (p2.size(0) * b_i)];
          d = (d + d) - p1[i1 + (p1.size(0) * b_i)];
          p2[i1 + (p2.size(0) * b_i)] = d;
        }
      }
      findClosestIndices(p2, newIndices);
    }
    numRows = BoardIdx.size(0) + 1;
    c_i = BoardIdx.size(1);
    p1.set_size(numRows, c_i);
    for (b_i = 0; b_i < c_i; b_i++) {
      for (i1 = 0; i1 < numRows; i1++) {
        p1[i1 + (p1.size(0) * b_i)] = 0.0;
      }
    }
    numRows = BoardIdx.size(0);
    loop_ub = newIndices.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      p1[numRows + (p1.size(0) * b_i)] = newIndices[b_i];
    }
    loop_ub = BoardIdx.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = BoardIdx.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        p1[i1 + (p1.size(0) * b_i)] = BoardIdx[i1 + (BoardIdx.size(0) * b_i)];
      }
    }
    numRows = BoardCoords.size(0) + 1;
    c_i = BoardCoords.size(1);
    b_loop_ub = BoardCoords.size(2);
    r.set_size(numRows, c_i, b_loop_ub);
    for (b_i = 0; b_i < b_loop_ub; b_i++) {
      for (i1 = 0; i1 < c_i; i1++) {
        for (i2 = 0; i2 < numRows; i2++) {
          r[(i2 + (r.size(0) * i1)) + ((r.size(0) * r.size(1)) * b_i)] = 0.0;
        }
      }
    }
    loop_ub = BoardCoords.size(2);
    r1.set_size(loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      r1[b_i] = b_i;
    }
    b_loop_ub = newIndices.size(1) - 1;
    numRows = 0;
    for (c_i = 0; c_i <= b_loop_ub; c_i++) {
      if (newIndices[c_i] > 0.0) {
        numRows++;
      }
    }
    r2.set_size(1, numRows);
    numRows = 0;
    for (c_i = 0; c_i <= b_loop_ub; c_i++) {
      if (newIndices[c_i] > 0.0) {
        r2[numRows] = c_i + 1;
        numRows++;
      }
    }
    loop_ub = Points.size(1);
    p2.set_size(r2.size(1), loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = r2.size(1);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        p2[i1 + (p2.size(0) * b_i)] = static_cast<double>(
            Points[((static_cast<int>(newIndices[r2[i1] - 1])) +
                    (Points.size(0) * b_i)) -
                   1]);
      }
    }
    b_loop_ub = newIndices.size(1) - 1;
    numRows = 0;
    for (c_i = 0; c_i <= b_loop_ub; c_i++) {
      if (newIndices[c_i] > 0.0) {
        numRows++;
      }
    }
    r3.set_size(1, numRows);
    numRows = 0;
    for (c_i = 0; c_i <= b_loop_ub; c_i++) {
      if (newIndices[c_i] > 0.0) {
        r3[numRows] = c_i + 1;
        numRows++;
      }
    }
    c_i = r3.size(1);
    numRows = BoardCoords.size(0);
    loop_ub = r1.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      for (i1 = 0; i1 < c_i; i1++) {
        r[(numRows + (r.size(0) * (r3[i1] - 1))) +
          ((r.size(0) * r.size(1)) * r1[b_i])] = p2[i1 + (c_i * b_i)];
      }
    }
    loop_ub = BoardCoords.size(2);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = BoardCoords.size(1);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        numRows = BoardCoords.size(0);
        for (i2 = 0; i2 < numRows; i2++) {
          r[(i2 + (r.size(0) * i1)) + ((r.size(0) * r.size(1)) * b_i)] =
              BoardCoords[(i2 + (BoardCoords.size(0) * i1)) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)];
        }
      }
    }
    BoardIdx.set_size(p1.size(0), p1.size(1));
    loop_ub = p1.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = p1.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        BoardIdx[i1 + (BoardIdx.size(0) * b_i)] = p1[i1 + (p1.size(0) * b_i)];
      }
    }
    BoardCoords.set_size(r.size(0), r.size(1), r.size(2));
    loop_ub = r.size(2);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = r.size(1);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        numRows = r.size(0);
        for (i2 = 0; i2 < numRows; i2++) {
          BoardCoords[(i2 + (BoardCoords.size(0) * i1)) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)] =
              r[(i2 + (r.size(0) * i1)) + ((r.size(0) * r.size(1)) * b_i)];
        }
      }
    }
    idx.set_size(1, idx.size(1));
    loop_ub = idx.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      idx[b_i] = idx[b_i] + 1.0;
    }
    oldEnergy = computeNewEnergyVertical(idx, oldEnergy);
  } break;
  case 3: {
    int b_i;
    int b_loop_ub;
    int i1;
    int loop_ub;
    int numRows;
    if (IsDistortionHigh) {
      bool exitg1;
      bool y;
      b_fitPolynomialIndices(newIndices);
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
        loop_ub = BoardCoords.size(0);
        b_loop_ub = BoardCoords.size(2);
        b_this.set_size(loop_ub, 1, b_loop_ub);
        for (b_i = 0; b_i < b_loop_ub; b_i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_this[i1 + (b_this.size(0) * b_i)] =
                BoardCoords[(i1 + BoardCoords.size(0)) +
                            ((BoardCoords.size(0) * BoardCoords.size(1)) *
                             b_i)];
          }
        }
        b_squeeze(b_this, p1);
        loop_ub = BoardCoords.size(0);
        b_loop_ub = BoardCoords.size(2);
        b_this.set_size(loop_ub, 1, b_loop_ub);
        for (b_i = 0; b_i < b_loop_ub; b_i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_this[i1 + (b_this.size(0) * b_i)] =
                BoardCoords[i1 + ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                  b_i)];
          }
        }
        b_squeeze(b_this, p2);
        loop_ub = p2.size(1);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          b_loop_ub = p2.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            double d;
            d = p2[i1 + (p2.size(0) * b_i)];
            d = (d + d) - p1[i1 + (p1.size(0) * b_i)];
            p2[i1 + (p2.size(0) * b_i)] = d;
          }
        }
        findClosestIndices(p2, newIndicesLinear);
        b_loop_ub = newIndices.size(1);
        for (int c_i{0}; c_i < b_loop_ub; c_i++) {
          if (newIndices[c_i] == 0.0) {
            newIndices[c_i] = newIndicesLinear[c_i];
          }
        }
      }
    } else {
      loop_ub = BoardCoords.size(0);
      b_loop_ub = BoardCoords.size(2);
      b_this.set_size(loop_ub, 1, b_loop_ub);
      for (b_i = 0; b_i < b_loop_ub; b_i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_this[i1 + (b_this.size(0) * b_i)] =
              BoardCoords[(i1 + BoardCoords.size(0)) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)];
        }
      }
      b_squeeze(b_this, p1);
      loop_ub = BoardCoords.size(0);
      b_loop_ub = BoardCoords.size(2);
      b_this.set_size(loop_ub, 1, b_loop_ub);
      for (b_i = 0; b_i < b_loop_ub; b_i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_this[i1 + (b_this.size(0) * b_i)] =
              BoardCoords[i1 +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)];
        }
      }
      b_squeeze(b_this, p2);
      loop_ub = p2.size(1);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b_loop_ub = p2.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          double d;
          d = p2[i1 + (p2.size(0) * b_i)];
          d = (d + d) - p1[i1 + (p1.size(0) * b_i)];
          p2[i1 + (p2.size(0) * b_i)] = d;
        }
      }
      findClosestIndices(p2, newIndices);
    }
    expandBoardLeft(newIndices, p1, r);
    BoardIdx.set_size(p1.size(0), p1.size(1));
    loop_ub = p1.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = p1.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        BoardIdx[i1 + (BoardIdx.size(0) * b_i)] = p1[i1 + (p1.size(0) * b_i)];
      }
    }
    BoardCoords.set_size(r.size(0), r.size(1), r.size(2));
    loop_ub = r.size(2);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = r.size(1);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        numRows = r.size(0);
        for (int i2{0}; i2 < numRows; i2++) {
          BoardCoords[(i2 + (BoardCoords.size(0) * i1)) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)] =
              r[(i2 + (r.size(0) * i1)) + ((r.size(0) * r.size(1)) * b_i)];
        }
      }
    }
    oldEnergy = computeNewEnergyHorizontal(oldEnergy);
  } break;
  case 4: {
    int b_i;
    int b_loop_ub;
    int i1;
    int loop_ub;
    int numRows;
    numRows = BoardCoords.size(1);
    if ((static_cast<double>(numRows)) <
        ((static_cast<double>(numRows)) - 2.0)) {
      idx.set_size(1, 0);
    } else {
      loop_ub = static_cast<int>(
          static_cast<double>(-(((static_cast<double>(numRows)) - 2.0) -
                                (static_cast<double>(numRows)))));
      idx.set_size(1, loop_ub + 1);
      for (b_i = 0; b_i <= loop_ub; b_i++) {
        idx[b_i] = (static_cast<double>(numRows)) - (static_cast<double>(b_i));
      }
    }
    if (IsDistortionHigh) {
      bool exitg1;
      bool y;
      b_fitPolynomialIndices(idx, newIndices);
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
        loop_ub = BoardCoords.size(0);
        b_loop_ub = BoardCoords.size(2);
        b_this.set_size(loop_ub, 1, b_loop_ub);
        for (b_i = 0; b_i < b_loop_ub; b_i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_this[i1 + (b_this.size(0) * b_i)] =
                BoardCoords[(i1 + (BoardCoords.size(0) * (numRows - 1))) +
                            ((BoardCoords.size(0) * BoardCoords.size(1)) *
                             b_i)];
          }
        }
        b_squeeze(b_this, p1);
        numRows = static_cast<int>(idx[0]);
        loop_ub = BoardCoords.size(0);
        b_loop_ub = BoardCoords.size(2);
        b_this.set_size(loop_ub, 1, b_loop_ub);
        for (b_i = 0; b_i < b_loop_ub; b_i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_this[i1 + (b_this.size(0) * b_i)] =
                BoardCoords[(i1 + (BoardCoords.size(0) * (numRows - 1))) +
                            ((BoardCoords.size(0) * BoardCoords.size(1)) *
                             b_i)];
          }
        }
        b_squeeze(b_this, p2);
        loop_ub = p2.size(1);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          b_loop_ub = p2.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            double d;
            d = p2[i1 + (p2.size(0) * b_i)];
            d = (d + d) - p1[i1 + (p1.size(0) * b_i)];
            p2[i1 + (p2.size(0) * b_i)] = d;
          }
        }
        findClosestIndices(p2, newIndicesLinear);
        b_loop_ub = newIndices.size(1);
        for (int c_i{0}; c_i < b_loop_ub; c_i++) {
          if (newIndices[c_i] == 0.0) {
            newIndices[c_i] = newIndicesLinear[c_i];
          }
        }
      }
    } else {
      numRows = static_cast<int>(idx[1]);
      loop_ub = BoardCoords.size(0);
      b_loop_ub = BoardCoords.size(2);
      b_this.set_size(loop_ub, 1, b_loop_ub);
      for (b_i = 0; b_i < b_loop_ub; b_i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_this[i1 + (b_this.size(0) * b_i)] =
              BoardCoords[(i1 + (BoardCoords.size(0) * (numRows - 1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)];
        }
      }
      b_squeeze(b_this, p1);
      numRows = static_cast<int>(idx[0]);
      loop_ub = BoardCoords.size(0);
      b_loop_ub = BoardCoords.size(2);
      b_this.set_size(loop_ub, 1, b_loop_ub);
      for (b_i = 0; b_i < b_loop_ub; b_i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_this[i1 + (b_this.size(0) * b_i)] =
              BoardCoords[(i1 + (BoardCoords.size(0) * (numRows - 1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)];
        }
      }
      b_squeeze(b_this, p2);
      loop_ub = p2.size(1);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b_loop_ub = p2.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          double d;
          d = p2[i1 + (p2.size(0) * b_i)];
          d = (d + d) - p1[i1 + (p1.size(0) * b_i)];
          p2[i1 + (p2.size(0) * b_i)] = d;
        }
      }
      findClosestIndices(p2, newIndices);
    }
    expandBoardRight(newIndices, p1, r);
    BoardIdx.set_size(p1.size(0), p1.size(1));
    loop_ub = p1.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = p1.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        BoardIdx[i1 + (BoardIdx.size(0) * b_i)] = p1[i1 + (p1.size(0) * b_i)];
      }
    }
    BoardCoords.set_size(r.size(0), r.size(1), r.size(2));
    loop_ub = r.size(2);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = r.size(1);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        numRows = r.size(0);
        for (int i2{0}; i2 < numRows; i2++) {
          BoardCoords[(i2 + (BoardCoords.size(0) * i1)) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)] =
              r[(i2 + (r.size(0) * i1)) + ((r.size(0) * r.size(1)) * b_i)];
        }
      }
    }
    idx.set_size(1, idx.size(1));
    loop_ub = idx.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      idx[b_i] = idx[b_i] + 1.0;
    }
    oldEnergy = computeNewEnergyHorizontal(idx, oldEnergy);
  } break;
  default:
    oldEnergy = rtInfF;
    break;
  }
  Energy = oldEnergy;
}

//
// Arguments    : double seedIdx
//                const ::coder::array<float, 2U> &b_points
//                const float b_v1[2]
//                const float v2[2]
// Return Type  : void
//
void b_Checkerboard::initialize(double seedIdx,
                                const ::coder::array<float, 2U> &b_points,
                                const float b_v1[2], const float v2[2])
{
  ::coder::array<double, 2U> r1;
  ::coder::array<float, 2U> b_r;
  ::coder::array<float, 2U> center;
  ::coder::array<float, 2U> col1;
  ::coder::array<float, 2U> col2;
  ::coder::array<float, 2U> d;
  ::coder::array<float, 2U> k_l;
  ::coder::array<float, 2U> pointVectors;
  ::coder::array<float, 2U> row3;
  ::coder::array<float, 2U> u;
  ::coder::array<float, 1U> euclideanDists;
  ::coder::array<int, 1U> r;
  ::coder::array<bool, 1U> b_x;
  float b_z1[3];
  float z1[3];
  float c_v1[2];
  int b_i;
  int csz_idx_1;
  int h_N;
  int i1;
  int k;
  int loop_ub;
  bool exitg1;
  bool y;
  BoardIdx.set_size(1, 1);
  BoardIdx[0] = 0.0;
  BoardIdx.set_size(3, 3);
  for (b_i = 0; b_i < 3; b_i++) {
    BoardIdx[BoardIdx.size(0) * b_i] = 0.0;
    BoardIdx[(BoardIdx.size(0) * b_i) + 1] = 0.0;
    BoardIdx[(BoardIdx.size(0) * b_i) + 2] = 0.0;
  }
  IsDirectionBad[0] = false;
  IsDirectionBad[1] = false;
  IsDirectionBad[2] = false;
  IsDirectionBad[3] = false;
  BoardCoords.set_size(1, 1, 1);
  BoardCoords[0] = 0.0;
  BoardCoords.set_size(3, 3, 2);
  Points.set_size(b_points.size(0), 2);
  loop_ub = b_points.size(0);
  for (b_i = 0; b_i < 2; b_i++) {
    for (i1 = 0; i1 < 3; i1++) {
      BoardCoords[(BoardCoords.size(0) * i1) +
                  ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)] = 0.0;
      BoardCoords[((BoardCoords.size(0) * i1) +
                   ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)) +
                  1] = 0.0;
      BoardCoords[((BoardCoords.size(0) * i1) +
                   ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)) +
                  2] = 0.0;
    }
    for (i1 = 0; i1 < loop_ub; i1++) {
      Points[i1 + (Points.size(0) * b_i)] =
          b_points[i1 + (b_points.size(0) * b_i)];
    }
  }
  loop_ub = Points.size(1);
  center.set_size(1, loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    center[b_i] =
        Points[((static_cast<int>(seedIdx)) + (Points.size(0) * b_i)) - 1];
  }
  BoardIdx[BoardIdx.size(0) + 1] = seedIdx;
  loop_ub = BoardCoords.size(2);
  r.set_size(loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r[b_i] = b_i;
  }
  loop_ub = r.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    BoardCoords[(BoardCoords.size(0) +
                 ((BoardCoords.size(0) * BoardCoords.size(1)) * r[b_i])) +
                1] = static_cast<double>(center[b_i]);
  }
  LastExpandDirection = 1.0;
  PreviousEnergy = rtInfF;
  isValid = false;
  h_N = center.size(1);
  loop_ub = Points.size(1);
  if (h_N <= loop_ub) {
    loop_ub = h_N;
  }
  if (center.size(1) == 1) {
    csz_idx_1 = Points.size(1);
  } else if (Points.size(1) == 1) {
    csz_idx_1 = center.size(1);
  } else if (Points.size(1) == center.size(1)) {
    csz_idx_1 = Points.size(1);
  } else {
    csz_idx_1 = loop_ub;
  }
  h_N = center.size(1);
  loop_ub = Points.size(1);
  if (h_N <= loop_ub) {
    loop_ub = h_N;
  }
  if (center.size(1) == 1) {
    loop_ub = Points.size(1);
  } else if (Points.size(1) == 1) {
    loop_ub = center.size(1);
  } else if (Points.size(1) == center.size(1)) {
    loop_ub = Points.size(1);
  } else {
    /* no actions */
  }
  pointVectors.set_size(Points.size(0), loop_ub);
  if ((Points.size(0) != 0) && (csz_idx_1 != 0)) {
    int acoef;
    int bcoef;
    acoef = static_cast<int>(Points.size(1) != 1);
    bcoef = static_cast<int>(center.size(1) != 1);
    b_i = csz_idx_1 - 1;
    for (k = 0; k <= b_i; k++) {
      h_N = acoef * k;
      loop_ub = bcoef * k;
      csz_idx_1 = static_cast<int>(Points.size(0) != 1);
      i1 = pointVectors.size(0) - 1;
      for (int b_k{0}; b_k <= i1; b_k++) {
        pointVectors[b_k + (pointVectors.size(0) * k)] =
            Points[(csz_idx_1 * b_k) + (Points.size(0) * h_N)] -
            center[loop_ub];
      }
    }
  }
  euclideanDists.set_size(pointVectors.size(0));
  h_N = pointVectors.size(0);
  for (k = 0; k < h_N; k++) {
    euclideanDists[k] =
        rt_hypotf_snf(pointVectors[k], pointVectors[k + pointVectors.size(0)]);
  }
  BoardIdx[(BoardIdx.size(0) * 2) + 1] =
      findNeighbor(pointVectors, euclideanDists, b_v1);
  c_v1[0] = -b_v1[0];
  c_v1[1] = -b_v1[1];
  BoardIdx[1] = findNeighbor(pointVectors, euclideanDists, c_v1);
  BoardIdx[BoardIdx.size(0) + 2] =
      findNeighbor(pointVectors, euclideanDists, v2);
  c_v1[0] = -v2[0];
  c_v1[1] = -v2[1];
  BoardIdx[BoardIdx.size(0)] = findNeighbor(pointVectors, euclideanDists, c_v1);
  h_N = BoardIdx.size(0) * BoardIdx.size(1);
  b_x.set_size(h_N);
  for (b_i = 0; b_i < h_N; b_i++) {
    b_x[b_i] = (BoardIdx[b_i] < 0.0);
  }
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= (b_x.size(0) - 1))) {
    if (b_x[k]) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (y) {
    isValid = false;
  } else {
    h_N = static_cast<int>(BoardIdx[(BoardIdx.size(0) * 2) + 1]);
    loop_ub = Points.size(1);
    b_r.set_size(1, loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_r[b_i] = Points[(h_N + (Points.size(0) * b_i)) - 1];
    }
    loop_ub = BoardCoords.size(2);
    r.set_size(loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      r[b_i] = b_i;
    }
    loop_ub = r.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      BoardCoords[((BoardCoords.size(0) * 2) +
                   ((BoardCoords.size(0) * BoardCoords.size(1)) * r[b_i])) +
                  1] = static_cast<double>(b_r[b_i]);
    }
    h_N = static_cast<int>(BoardIdx[1]);
    loop_ub = Points.size(1);
    k_l.set_size(1, loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      k_l[b_i] = Points[(h_N + (Points.size(0) * b_i)) - 1];
    }
    loop_ub = BoardCoords.size(2);
    r.set_size(loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      r[b_i] = b_i;
    }
    loop_ub = r.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      BoardCoords[((BoardCoords.size(0) * BoardCoords.size(1)) * r[b_i]) + 1] =
          static_cast<double>(k_l[b_i]);
    }
    h_N = static_cast<int>(BoardIdx[BoardIdx.size(0) + 2]);
    loop_ub = Points.size(1);
    d.set_size(1, loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      d[b_i] = Points[(h_N + (Points.size(0) * b_i)) - 1];
    }
    loop_ub = BoardCoords.size(2);
    r.set_size(loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      r[b_i] = b_i;
    }
    loop_ub = r.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      BoardCoords[(BoardCoords.size(0) +
                   ((BoardCoords.size(0) * BoardCoords.size(1)) * r[b_i])) +
                  2] = static_cast<double>(d[b_i]);
    }
    h_N = static_cast<int>(BoardIdx[BoardIdx.size(0)]);
    loop_ub = Points.size(1);
    u.set_size(1, loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      u[b_i] = Points[(h_N + (Points.size(0) * b_i)) - 1];
    }
    loop_ub = BoardCoords.size(2);
    r.set_size(loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      r[b_i] = b_i;
    }
    loop_ub = r.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      BoardCoords[BoardCoords.size(0) +
                  ((BoardCoords.size(0) * BoardCoords.size(1)) * r[b_i])] =
          static_cast<double>(u[b_i]);
    }
    u.set_size(1, u.size(1));
    loop_ub = u.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      u[b_i] = u[b_i] - center[b_i];
    }
    d.set_size(1, d.size(1));
    loop_ub = d.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      d[b_i] = d[b_i] - center[b_i];
    }
    b_r.set_size(1, b_r.size(1));
    loop_ub = b_r.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_r[b_i] = b_r[b_i] - center[b_i];
    }
    k_l.set_size(1, k_l.size(1));
    loop_ub = k_l.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      k_l[b_i] = k_l[b_i] - center[b_i];
    }
    center.set_size(1, u.size(1));
    loop_ub = u.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      center[b_i] = u[b_i] + k_l[b_i];
    }
    BoardIdx[0] = findNeighbor(pointVectors, euclideanDists, center);
    k_l.set_size(1, d.size(1));
    loop_ub = d.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      k_l[b_i] = d[b_i] + k_l[b_i];
    }
    BoardIdx[2] = findNeighbor(pointVectors, euclideanDists, k_l);
    d.set_size(1, d.size(1));
    loop_ub = d.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      d[b_i] = d[b_i] + b_r[b_i];
    }
    BoardIdx[(BoardIdx.size(0) * 2) + 2] =
        findNeighbor(pointVectors, euclideanDists, d);
    u.set_size(1, u.size(1));
    loop_ub = u.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      u[b_i] = u[b_i] + b_r[b_i];
    }
    BoardIdx[BoardIdx.size(0) * 2] =
        findNeighbor(pointVectors, euclideanDists, u);
    h_N = BoardIdx.size(0) * BoardIdx.size(1);
    b_x.set_size(h_N);
    for (b_i = 0; b_i < h_N; b_i++) {
      b_x[b_i] = (BoardIdx[b_i] > 0.0);
    }
    isValid = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= (b_x.size(0) - 1))) {
      if (!b_x[k]) {
        isValid = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (isValid) {
      float z1_idx_0;
      loop_ub = BoardCoords.size(2);
      r.set_size(loop_ub);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        r[b_i] = b_i;
      }
      h_N = static_cast<int>(BoardIdx[0]);
      loop_ub = Points.size(1);
      r1.set_size(1, loop_ub);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        r1[b_i] =
            static_cast<double>(Points[(h_N + (Points.size(0) * b_i)) - 1]);
      }
      loop_ub = r.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        BoardCoords[(BoardCoords.size(0) * BoardCoords.size(1)) * r[b_i]] =
            r1[b_i];
      }
      loop_ub = BoardCoords.size(2);
      r.set_size(loop_ub);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        r[b_i] = b_i;
      }
      h_N = static_cast<int>(BoardIdx[2]);
      loop_ub = Points.size(1);
      r1.set_size(1, loop_ub);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        r1[b_i] =
            static_cast<double>(Points[(h_N + (Points.size(0) * b_i)) - 1]);
      }
      loop_ub = r.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        BoardCoords[((BoardCoords.size(0) * BoardCoords.size(1)) * r[b_i]) +
                    2] = r1[b_i];
      }
      loop_ub = BoardCoords.size(2);
      r.set_size(loop_ub);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        r[b_i] = b_i;
      }
      h_N = static_cast<int>(BoardIdx[(BoardIdx.size(0) * 2) + 2]);
      loop_ub = Points.size(1);
      r1.set_size(1, loop_ub);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        r1[b_i] =
            static_cast<double>(Points[(h_N + (Points.size(0) * b_i)) - 1]);
      }
      loop_ub = r.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        BoardCoords[((BoardCoords.size(0) * 2) +
                     ((BoardCoords.size(0) * BoardCoords.size(1)) * r[b_i])) +
                    2] = r1[b_i];
      }
      loop_ub = BoardCoords.size(2);
      r.set_size(loop_ub);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        r[b_i] = b_i;
      }
      h_N = static_cast<int>(BoardIdx[BoardIdx.size(0) * 2]);
      loop_ub = Points.size(1);
      r1.set_size(1, loop_ub);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        r1[b_i] =
            static_cast<double>(Points[(h_N + (Points.size(0) * b_i)) - 1]);
      }
      loop_ub = r.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        BoardCoords[(BoardCoords.size(0) * 2) +
                    ((BoardCoords.size(0) * BoardCoords.size(1)) * r[b_i])] =
            r1[b_i];
      }
      h_N = BoardIdx.size(0) * BoardIdx.size(1);
      b_x.set_size(h_N);
      for (b_i = 0; b_i < h_N; b_i++) {
        b_x[b_i] = (BoardIdx[b_i] < 0.0);
      }
      y = false;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= (b_x.size(0) - 1))) {
        if (b_x[k]) {
          y = true;
          exitg1 = true;
        } else {
          k++;
        }
      }
      if (y) {
        z1_idx_0 = rtInfF;
      } else {
        float z1_idx_1;
        float z1_idx_2;
        loop_ub = Points.size(1);
        col1.set_size(3, loop_ub);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          col1[3 * b_i] = Points[((static_cast<int>(BoardIdx[0])) +
                                  (Points.size(0) * b_i)) -
                                 1];
          col1[(3 * b_i) + 1] =
              Points[((static_cast<int>(BoardIdx[BoardIdx.size(0)])) +
                      (Points.size(0) * b_i)) -
                     1];
          col1[(3 * b_i) + 2] =
              Points[((static_cast<int>(BoardIdx[BoardIdx.size(0) * 2])) +
                      (Points.size(0) * b_i)) -
                     1];
        }
        loop_ub = Points.size(1);
        col2.set_size(3, loop_ub);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          col2[3 * b_i] = Points[((static_cast<int>(BoardIdx[1])) +
                                  (Points.size(0) * b_i)) -
                                 1];
          col2[(3 * b_i) + 1] =
              Points[((static_cast<int>(BoardIdx[BoardIdx.size(0) + 1])) +
                      (Points.size(0) * b_i)) -
                     1];
          col2[(3 * b_i) + 2] =
              Points[((static_cast<int>(BoardIdx[(BoardIdx.size(0) * 2) + 1])) +
                      (Points.size(0) * b_i)) -
                     1];
        }
        loop_ub = Points.size(1);
        row3.set_size(3, loop_ub);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          row3[3 * b_i] = Points[((static_cast<int>(BoardIdx[2])) +
                                  (Points.size(0) * b_i)) -
                                 1];
          row3[(3 * b_i) + 1] =
              Points[((static_cast<int>(BoardIdx[BoardIdx.size(0) + 2])) +
                      (Points.size(0) * b_i)) -
                     1];
          row3[(3 * b_i) + 2] =
              Points[((static_cast<int>(BoardIdx[(BoardIdx.size(0) * 2) + 2])) +
                      (Points.size(0) * b_i)) -
                     1];
        }
        col2.set_size(3, col1.size(1));
        loop_ub = col1.size(1);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          col2[3 * b_i] =
              (col1[3 * b_i] + row3[3 * b_i]) - (2.0F * col2[3 * b_i]);
          col2[(3 * b_i) + 1] = (col1[(3 * b_i) + 1] + row3[(3 * b_i) + 1]) -
                                (2.0F * col2[(3 * b_i) + 1]);
          col2[(3 * b_i) + 2] = (col1[(3 * b_i) + 2] + row3[(3 * b_i) + 2]) -
                                (2.0F * col2[(3 * b_i) + 2]);
        }
        col1.set_size(3, col1.size(1));
        loop_ub = col1.size(1);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          col1[3 * b_i] = col1[3 * b_i] - row3[3 * b_i];
          col1[(3 * b_i) + 1] = col1[(3 * b_i) + 1] - row3[(3 * b_i) + 1];
          col1[(3 * b_i) + 2] = col1[(3 * b_i) + 2] - row3[(3 * b_i) + 2];
        }
        z1[0] = rt_hypotf_snf(col2[0], col2[3]);
        z1_idx_0 = rt_hypotf_snf(col1[0], col1[3]);
        z1[1] = rt_hypotf_snf(col2[1], col2[4]);
        z1_idx_1 = rt_hypotf_snf(col1[1], col1[4]);
        z1[2] = rt_hypotf_snf(col2[2], col2[5]);
        z1_idx_2 = rt_hypotf_snf(col1[2], col1[5]);
        loop_ub = Points.size(1);
        col1.set_size(3, loop_ub);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          col1[3 * b_i] = Points[((static_cast<int>(BoardIdx[0])) +
                                  (Points.size(0) * b_i)) -
                                 1];
          col1[(3 * b_i) + 1] = Points[((static_cast<int>(BoardIdx[1])) +
                                        (Points.size(0) * b_i)) -
                                       1];
          col1[(3 * b_i) + 2] = Points[((static_cast<int>(BoardIdx[2])) +
                                        (Points.size(0) * b_i)) -
                                       1];
        }
        loop_ub = Points.size(1);
        col2.set_size(3, loop_ub);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          col2[3 * b_i] =
              Points[((static_cast<int>(BoardIdx[BoardIdx.size(0)])) +
                      (Points.size(0) * b_i)) -
                     1];
          col2[(3 * b_i) + 1] =
              Points[((static_cast<int>(BoardIdx[BoardIdx.size(0) + 1])) +
                      (Points.size(0) * b_i)) -
                     1];
          col2[(3 * b_i) + 2] =
              Points[((static_cast<int>(BoardIdx[BoardIdx.size(0) + 2])) +
                      (Points.size(0) * b_i)) -
                     1];
        }
        loop_ub = Points.size(1);
        row3.set_size(3, loop_ub);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          row3[3 * b_i] =
              Points[((static_cast<int>(BoardIdx[BoardIdx.size(0) * 2])) +
                      (Points.size(0) * b_i)) -
                     1];
          row3[(3 * b_i) + 1] =
              Points[((static_cast<int>(BoardIdx[(BoardIdx.size(0) * 2) + 1])) +
                      (Points.size(0) * b_i)) -
                     1];
          row3[(3 * b_i) + 2] =
              Points[((static_cast<int>(BoardIdx[(BoardIdx.size(0) * 2) + 2])) +
                      (Points.size(0) * b_i)) -
                     1];
        }
        col2.set_size(3, col1.size(1));
        loop_ub = col1.size(1);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          col2[3 * b_i] =
              (col1[3 * b_i] + row3[3 * b_i]) - (2.0F * col2[3 * b_i]);
          col2[(3 * b_i) + 1] = (col1[(3 * b_i) + 1] + row3[(3 * b_i) + 1]) -
                                (2.0F * col2[(3 * b_i) + 1]);
          col2[(3 * b_i) + 2] = (col1[(3 * b_i) + 2] + row3[(3 * b_i) + 2]) -
                                (2.0F * col2[(3 * b_i) + 2]);
        }
        col1.set_size(3, col1.size(1));
        loop_ub = col1.size(1);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          col1[3 * b_i] = col1[3 * b_i] - row3[3 * b_i];
          col1[(3 * b_i) + 1] = col1[(3 * b_i) + 1] - row3[(3 * b_i) + 1];
          col1[(3 * b_i) + 2] = col1[(3 * b_i) + 2] - row3[(3 * b_i) + 2];
        }
        float boardSize;
        boardSize = static_cast<float>(
            static_cast<int>(BoardIdx.size(0) * BoardIdx.size(1)));
        z1[0] /= z1_idx_0;
        b_z1[0] =
            rt_hypotf_snf(col2[0], col2[3]) / rt_hypotf_snf(col1[0], col1[3]);
        z1[1] /= z1_idx_1;
        b_z1[1] =
            rt_hypotf_snf(col2[1], col2[4]) / rt_hypotf_snf(col1[1], col1[4]);
        z1[2] /= z1_idx_2;
        b_z1[2] =
            rt_hypotf_snf(col2[2], col2[5]) / rt_hypotf_snf(col1[2], col1[5]);
        z1_idx_0 =
            (boardSize *
             std::fmax(std::fmax(0.0F, ::Codegen::coder::internal::maximum(z1)),
                       ::Codegen::coder::internal::maximum(b_z1))) -
            boardSize;
      }
      Energy = z1_idx_0;
      if (IsDistortionHigh) {
        loop_ub = -5;
      } else {
        loop_ub = -7;
      }
      isValid =
          ((static_cast<double>(Energy)) < (static_cast<double>(loop_ub)));
    }
  }
}

} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace Codegen

//
// File trailer for Checkerboard.cpp
//
// [EOF]
//
