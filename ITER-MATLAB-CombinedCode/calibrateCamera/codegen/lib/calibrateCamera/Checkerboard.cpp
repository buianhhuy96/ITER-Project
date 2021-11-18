//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Checkerboard.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "Checkerboard.h"
#include "calibrateCamera_rtwutil.h"
#include "combineVectorElements.h"
#include "eml_setop.h"
#include "find.h"
#include "isequal.h"
#include "mean.h"
#include "minOrMax.h"
#include "norm.h"
#include "polyfit.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "squeeze.h"
#include "coder_array.h"
#include <cmath>
#include <math.h>

// Function Declarations
namespace Codegen {
static real32_T rt_hypotf_snf(real32_T u0, real32_T u1);

}

// Function Definitions
//
// Arguments    : const ::coder::array<boolean_T, 2U> &arr
//                ::coder::array<real_T, 2U> &matchedIdx
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void b_Checkerboard::arrayFind(const ::coder::array<boolean_T, 2U> &arr,
                               ::coder::array<real_T, 2U> &matchedIdx)
{
  ::coder::array<int32_T, 2U> b_arr;
  ::coder::array<int8_T, 2U> matchArr;
  ::coder::array<boolean_T, 2U> b_matchArr;
  int32_T b_i;
  int32_T k;
  boolean_T b_x[3];
  matchArr.set_size(1, arr.size(1) - 2);
  b_i = arr.size(1);
  for (int32_T idx{0}; idx <= (b_i - 3); idx++) {
    boolean_T exitg1;
    boolean_T y;
    b_arr.set_size(1, 3);
    for (k = 0; k < 3; k++) {
      b_arr[k] = static_cast<int32_T>(arr[idx + k]);
    }
    b_x[0] = (b_arr[0] == 1);
    b_x[1] = (b_arr[1] == 1);
    b_x[2] = (b_arr[2] == 1);
    y = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!b_x[k]) {
        y = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    matchArr[idx] = static_cast<int8_T>(y);
  }
  b_matchArr.set_size(1, matchArr.size(1));
  k = matchArr.size(1);
  for (b_i = 0; b_i < k; b_i++) {
    b_matchArr[b_i] = (matchArr[b_i] == 1);
  }
  b_eml_find(b_matchArr, b_arr);
  matchedIdx.set_size(1, b_arr.size(1));
  k = b_arr.size(1);
  for (b_i = 0; b_i < k; b_i++) {
    matchedIdx[b_i] = static_cast<real_T>(b_arr[b_i]);
  }
}

//
// Arguments    : ::coder::array<real_T, 2U> &newIndices
// Return Type  : void
//
void b_Checkerboard::b_fitPolynomialIndices(
    ::coder::array<real_T, 2U> &newIndices) const
{
  ::coder::array<real_T, 2U> b_index;
  ::coder::array<real_T, 2U> b_this;
  ::coder::array<real_T, 2U> removedIdx;
  ::coder::array<real_T, 1U> b_x;
  ::coder::array<real_T, 1U> c_x;
  ::coder::array<int32_T, 2U> b_validIdx;
  ::coder::array<int32_T, 1U> r2;
  ::coder::array<int32_T, 1U> r3;
  ::coder::array<int32_T, 1U> r4;
  ::coder::array<int32_T, 1U> r5;
  ::coder::array<boolean_T, 1U> r;
  ::coder::array<boolean_T, 1U> r1;
  real_T currCurve_data[5];
  real_T coordsToUse[2];
  real_T currPt[2];
  int32_T currCurve_size[2];
  int32_T b_i;
  int32_T d_i;
  int32_T end;
  int32_T loop_ub;
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
  for (d_i = 0; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      loop_ub++;
    }
  }
  r2.set_size(loop_ub);
  loop_ub = 0;
  for (d_i = 0; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      r2[loop_ub] = d_i + 1;
      loop_ub++;
    }
  }
  end = r.size(0) - 1;
  loop_ub = 0;
  for (d_i = 0; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      loop_ub++;
    }
  }
  r3.set_size(loop_ub);
  loop_ub = 0;
  for (d_i = 0; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      r3[loop_ub] = d_i + 1;
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
  for (d_i = 0; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      loop_ub++;
    }
  }
  r4.set_size(loop_ub);
  loop_ub = 0;
  for (d_i = 0; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      r4[loop_ub] = d_i + 1;
      loop_ub++;
    }
  }
  end = r.size(0) - 1;
  loop_ub = 0;
  for (d_i = 0; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      loop_ub++;
    }
  }
  r5.set_size(loop_ub);
  loop_ub = 0;
  for (d_i = 0; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      r5[loop_ub] = d_i + 1;
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
               (static_cast<real_T>(b_x.size(0)))) >
      std::abs(combineVectorElements(c_x) /
               (static_cast<real_T>(c_x.size(0))))) {
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
  for (int32_T j{0}; j < b_i; j++) {
    int32_T i1;
    loop_ub = BoardCoords.size(1);
    b_index.set_size(1, loop_ub);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_index[i1] = BoardCoords[(j + (BoardCoords.size(0) * i1)) +
                                ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                 ((static_cast<int32_T>(coordsToUse[0])) - 1))];
    }
    c_eml_find(b_index, b_validIdx);
    if (b_validIdx.size(1) >= 2) {
      real_T coordDist;
      real_T coordDist_tmp;
      real_T currCoord;
      real_T currRad;
      int32_T g_n;
      int32_T i2;
      boolean_T exitg1;
      i1 = static_cast<int32_T>(coordsToUse[0]);
      coordDist_tmp =
          BoardCoords[(j + (BoardCoords.size(0) * (b_validIdx[0] - 1))) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * (i1 - 1))];
      d_i = b_validIdx[0];
      coordDist =
          (coordDist_tmp -
           BoardCoords[(j + (BoardCoords.size(0) * (b_validIdx[1] - 1))) +
                       ((BoardCoords.size(0) * BoardCoords.size(1)) *
                        (i1 - 1))]) /
          ((static_cast<real_T>(b_validIdx[1])) - (static_cast<real_T>(d_i)));
      g_n = 0;
      i2 = b_validIdx.size(1);
      b_x.set_size(b_validIdx.size(1));
      for (loop_ub = 0; loop_ub < i2; loop_ub++) {
        end = b_validIdx[loop_ub];
        if (end != 0) {
          g_n++;
        }
        b_x[loop_ub] = static_cast<real_T>(end);
      }
      b_index.set_size(1, b_x.size(0));
      loop_ub = b_x.size(0);
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_index[i2] =
            BoardCoords[(j + (BoardCoords.size(0) *
                              ((static_cast<int32_T>(b_x[i2])) - 1))) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) *
                         (i1 - 1))];
      }
      b_this.set_size(1, b_x.size(0));
      loop_ub = b_x.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_this[i1] =
            BoardCoords[(j + (BoardCoords.size(0) *
                              ((static_cast<int32_T>(b_x[i1])) - 1))) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) *
                         ((static_cast<int32_T>(coordsToUse[1])) - 1))];
      }
      if (g_n > 5) {
        g_n = 4;
      } else {
        g_n = 2;
      }
      b_polyfit(b_index, b_this, static_cast<real_T>(g_n), currCurve_data,
                currCurve_size);
      currRad = coordDist / 4.0;
      currCoord = currRad + coordDist_tmp;
      exitg1 = false;
      while ((!exitg1) &&
             (std::abs(currCoord - coordDist_tmp) <
              (((static_cast<real_T>(d_i)) * 1.5) * std::abs(coordDist)))) {
        currPt[0] = 1.0;
        currPt[1] = 2.0;
        if (isequal(coordsToUse, currPt)) {
          real_T y;
          y = currCurve_data[0];
          i1 = currCurve_size[1];
          for (loop_ub = 0; loop_ub <= (i1 - 2); loop_ub++) {
            y = (currCoord * y) + currCurve_data[loop_ub + 1];
          }
          currPt[0] = currCoord;
          currPt[1] = y;
        } else {
          real_T y;
          y = currCurve_data[0];
          i1 = currCurve_size[1];
          for (loop_ub = 0; loop_ub <= (i1 - 2); loop_ub++) {
            y = (currCoord * y) + currCurve_data[loop_ub + 1];
          }
          currPt[0] = y;
          currPt[1] = currCoord;
        }
        findClosestOnCurve(currPt, std::abs(currRad), currCurve_data,
                           currCurve_size, coordsToUse, removedIdx, b_index);
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
// Arguments    : const ::coder::array<real_T, 2U> &idx
//                ::coder::array<real_T, 2U> &newIndices
// Return Type  : void
//
void b_Checkerboard::b_fitPolynomialIndices(
    const ::coder::array<real_T, 2U> &idx,
    ::coder::array<real_T, 2U> &newIndices) const
{
  ::coder::array<real_T, 2U> b_this;
  ::coder::array<real_T, 2U> b_validIdx;
  ::coder::array<real_T, 2U> removedIdx;
  ::coder::array<real_T, 1U> b_x;
  ::coder::array<real_T, 1U> c_x;
  ::coder::array<int32_T, 2U> r6;
  ::coder::array<int32_T, 1U> r2;
  ::coder::array<int32_T, 1U> r3;
  ::coder::array<int32_T, 1U> r4;
  ::coder::array<int32_T, 1U> r5;
  ::coder::array<boolean_T, 1U> r;
  ::coder::array<boolean_T, 1U> r1;
  real_T currCurve_data[5];
  real_T coordsToUse[2];
  real_T currPt[2];
  int32_T currCurve_size[2];
  int32_T b_i;
  int32_T b_idx_tmp;
  int32_T end;
  int32_T idx_tmp;
  int32_T loop_ub;
  int32_T trueCount;
  idx_tmp = static_cast<int32_T>(idx[0]);
  loop_ub = BoardIdx.size(0);
  r.set_size(loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r[b_i] = (BoardIdx[b_i + (BoardIdx.size(0) * (idx_tmp - 1))] > 0.0);
  }
  b_idx_tmp = static_cast<int32_T>(idx[1]);
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
               (static_cast<real_T>(b_x.size(0)))) >
      std::abs(combineVectorElements(c_x) /
               (static_cast<real_T>(c_x.size(0))))) {
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
    int32_T i1;
    loop_ub = BoardCoords.size(1);
    b_validIdx.set_size(1, loop_ub);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_validIdx[i1] =
          BoardCoords[(b_idx_tmp + (BoardCoords.size(0) * i1)) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) *
                       ((static_cast<int32_T>(coordsToUse[0])) - 1))];
    }
    c_eml_find(b_validIdx, r6);
    b_validIdx.set_size(1, r6.size(1));
    loop_ub = r6.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_validIdx[i1] = static_cast<real_T>(r6[i1]);
    }
    if (b_validIdx.size(1) >= 2) {
      real_T coordDist;
      real_T currCoord;
      real_T currRad;
      real_T moveDistMultiplier;
      real_T refCoordValue;
      boolean_T exitg1;
      if (idx[0] == 1.0) {
        end = static_cast<int32_T>(b_validIdx[0]);
        moveDistMultiplier = static_cast<real_T>(end);
        trueCount = static_cast<int32_T>(b_validIdx[1]);
        i1 = static_cast<int32_T>(coordsToUse[0]);
        coordDist =
            (BoardCoords[(b_idx_tmp + (BoardCoords.size(0) * (end - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) *
                          (i1 - 1))] -
             BoardCoords[(b_idx_tmp + (BoardCoords.size(0) * (trueCount - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) *
                          (i1 - 1))]) /
            ((static_cast<real_T>(trueCount)) - (static_cast<real_T>(end)));
      } else {
        moveDistMultiplier = ((static_cast<real_T>(BoardCoords.size(1))) -
                              (static_cast<real_T>(static_cast<int32_T>(
                                  b_validIdx[b_validIdx.size(1) - 1])))) +
                             1.0;
        end = static_cast<int32_T>(b_validIdx[b_validIdx.size(1) - 1]);
        i1 = static_cast<int32_T>(coordsToUse[0]);
        coordDist =
            (BoardCoords
                 [(b_idx_tmp + (BoardCoords.size(0) *
                                ((static_cast<int32_T>(
                                     b_validIdx[b_validIdx.size(1) - 1])) -
                                 1))) +
                  ((BoardCoords.size(0) * BoardCoords.size(1)) * (i1 - 1))] -
             BoardCoords
                 [(b_idx_tmp + (BoardCoords.size(0) *
                                ((static_cast<int32_T>(
                                     b_validIdx[b_validIdx.size(1) - 2])) -
                                 1))) +
                  ((BoardCoords.size(0) * BoardCoords.size(1)) * (i1 - 1))]) /
            ((static_cast<real_T>(
                 static_cast<int32_T>(b_validIdx[b_validIdx.size(1) - 1]))) -
             (static_cast<real_T>(
                 static_cast<int32_T>(b_validIdx[b_validIdx.size(1) - 2]))));
      }
      trueCount = 0;
      i1 = b_validIdx.size(1);
      for (idx_tmp = 0; idx_tmp < i1; idx_tmp++) {
        if ((static_cast<int32_T>(b_validIdx[idx_tmp])) != 0) {
          trueCount++;
        }
      }
      b_x.set_size(b_validIdx.size(1));
      loop_ub = b_validIdx.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_x[i1] = b_validIdx[i1];
      }
      b_validIdx.set_size(1, b_x.size(0));
      loop_ub = b_x.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_validIdx[i1] =
            BoardCoords[(b_idx_tmp + (BoardCoords.size(0) *
                                      ((static_cast<int32_T>(b_x[i1])) - 1))) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) *
                         ((static_cast<int32_T>(coordsToUse[0])) - 1))];
      }
      b_this.set_size(1, b_x.size(0));
      loop_ub = b_x.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_this[i1] =
            BoardCoords[(b_idx_tmp + (BoardCoords.size(0) *
                                      ((static_cast<int32_T>(b_x[i1])) - 1))) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) *
                         ((static_cast<int32_T>(coordsToUse[1])) - 1))];
      }
      if (trueCount > 5) {
        trueCount = 4;
      } else {
        trueCount = 2;
      }
      b_polyfit(b_validIdx, b_this, static_cast<real_T>(trueCount),
                currCurve_data, currCurve_size);
      currRad = coordDist / 4.0;
      refCoordValue =
          BoardCoords[(b_idx_tmp + (BoardCoords.size(0) * (end - 1))) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) *
                       ((static_cast<int32_T>(coordsToUse[0])) - 1))];
      currCoord = currRad + refCoordValue;
      exitg1 = false;
      while ((!exitg1) &&
             (std::abs(currCoord - refCoordValue) <
              ((moveDistMultiplier * 1.5) * std::abs(coordDist)))) {
        currPt[0] = 1.0;
        currPt[1] = 2.0;
        if (isequal(coordsToUse, currPt)) {
          real_T y;
          y = currCurve_data[0];
          i1 = currCurve_size[1];
          for (idx_tmp = 0; idx_tmp <= (i1 - 2); idx_tmp++) {
            y = (currCoord * y) + currCurve_data[idx_tmp + 1];
          }
          currPt[0] = currCoord;
          currPt[1] = y;
        } else {
          real_T y;
          y = currCurve_data[0];
          i1 = currCurve_size[1];
          for (idx_tmp = 0; idx_tmp <= (i1 - 2); idx_tmp++) {
            y = (currCoord * y) + currCurve_data[idx_tmp + 1];
          }
          currPt[0] = y;
          currPt[1] = currCoord;
        }
        findClosestOnCurve(currPt, std::abs(currRad), currCurve_data,
                           currCurve_size, coordsToUse, removedIdx, b_validIdx);
        if (b_validIdx.size(1) != 0) {
          newIndices[b_idx_tmp] = b_validIdx[0];
          i1 = removedIdx.size(1);
          loop_ub = b_validIdx.size(1);
          removedIdx.set_size(removedIdx.size(0),
                              removedIdx.size(1) + b_validIdx.size(1));
          for (trueCount = 0; trueCount < loop_ub; trueCount++) {
            removedIdx[i1 + trueCount] = b_validIdx[trueCount];
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
// Arguments    : real32_T oldEnergy
// Return Type  : real32_T
//
real32_T b_Checkerboard::computeNewEnergyHorizontal(real32_T oldEnergy) const
{
  ::coder::array<real_T, 3U> c_this;
  ::coder::array<real_T, 3U> denom;
  ::coder::array<real_T, 3U> num;
  ::coder::array<real_T, 2U> b_denom;
  ::coder::array<real_T, 2U> b_num;
  ::coder::array<real_T, 2U> validNewColIdx;
  ::coder::array<real_T, 1U> c_r;
  ::coder::array<real_T, 1U> d_r;
  ::coder::array<int32_T, 1U> r2;
  ::coder::array<int32_T, 1U> r3;
  ::coder::array<int32_T, 1U> r4;
  ::coder::array<int32_T, 1U> r5;
  ::coder::array<int32_T, 1U> r6;
  ::coder::array<boolean_T, 2U> b_this;
  ::coder::array<boolean_T, 1U> b_x;
  ::coder::array<boolean_T, 1U> r;
  ::coder::array<boolean_T, 1U> r1;
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T d_i;
  int32_T h_N;
  int32_T k;
  int32_T loop_ub;
  real32_T newEnergy;
  boolean_T exitg1;
  boolean_T y;
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
    for (d_i = 0; d_i <= k; d_i++) {
      if ((r[d_i]) && (r1[d_i])) {
        h_N++;
      }
    }
    r2.set_size(h_N);
    h_N = 0;
    for (d_i = 0; d_i <= k; d_i++) {
      if ((r[d_i]) && (r1[d_i])) {
        r2[h_N] = d_i + 1;
        h_N++;
      }
    }
    k = r.size(0) - 1;
    h_N = 0;
    for (d_i = 0; d_i <= k; d_i++) {
      if ((r[d_i]) && (r1[d_i])) {
        h_N++;
      }
    }
    r3.set_size(h_N);
    h_N = 0;
    for (d_i = 0; d_i <= k; d_i++) {
      if ((r[d_i]) && (r1[d_i])) {
        r3[h_N] = d_i + 1;
        h_N++;
      }
    }
    k = r.size(0) - 1;
    h_N = 0;
    for (d_i = 0; d_i <= k; d_i++) {
      if ((r[d_i]) && (r1[d_i])) {
        h_N++;
      }
    }
    r4.set_size(h_N);
    h_N = 0;
    for (d_i = 0; d_i <= k; d_i++) {
      if ((r[d_i]) && (r1[d_i])) {
        r4[h_N] = d_i + 1;
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
    for (d_i = 0; d_i <= k; d_i++) {
      if ((r[d_i]) && (r1[d_i])) {
        h_N++;
      }
    }
    r5.set_size(h_N);
    h_N = 0;
    for (d_i = 0; d_i <= k; d_i++) {
      if ((r[d_i]) && (r1[d_i])) {
        r5[h_N] = d_i + 1;
        h_N++;
      }
    }
    k = r.size(0) - 1;
    h_N = 0;
    for (d_i = 0; d_i <= k; d_i++) {
      if ((r[d_i]) && (r1[d_i])) {
        h_N++;
      }
    }
    r6.set_size(h_N);
    h_N = 0;
    for (d_i = 0; d_i <= k; d_i++) {
      if ((r[d_i]) && (r1[d_i])) {
        r6[h_N] = d_i + 1;
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
      c_r.set_size(b_num.size(0));
      h_N = b_num.size(0);
      for (k = 0; k < h_N; k++) {
        c_r[k] = rt_hypotd_snf(b_num[k], b_num[k + b_num.size(0)]);
      }
      d_r.set_size(b_denom.size(0));
      h_N = b_denom.size(0);
      for (k = 0; k < h_N; k++) {
        d_r[k] = rt_hypotd_snf(b_denom[k], b_denom[k + b_denom.size(0)]);
      }
      loop_ub = c_r.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        c_r[b_i] = c_r[b_i] / d_r[b_i];
      }
      newEnergy = std::fmax(
          oldEnergy,
          static_cast<real32_T>(::Codegen::coder::internal::b_maximum(c_r)));
    } else {
      newEnergy =
          std::fmax(oldEnergy, static_cast<real32_T>(static_cast<real_T>(
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
    for (d_i = 0; d_i < b_i; d_i++) {
      real_T d;
      d = validNewColIdx[d_i];
      num.set_size(1, 1, loop_ub);
      for (h_N = 0; h_N < loop_ub; h_N++) {
        num[h_N] =
            (BoardCoords[((static_cast<int32_T>(d)) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                         1] +
             BoardCoords[((static_cast<int32_T>(static_cast<real_T>(d + 2.0))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                         1]) -
            (2.0 *
             BoardCoords[((static_cast<int32_T>(static_cast<real_T>(d + 1.0))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                         1]);
      }
      d = validNewColIdx[d_i];
      denom.set_size(1, 1, b_loop_ub);
      for (h_N = 0; h_N < b_loop_ub; h_N++) {
        denom[h_N] =
            BoardCoords[((static_cast<int32_T>(d)) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                        1] -
            BoardCoords[((static_cast<int32_T>(static_cast<real_T>(d + 2.0))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                        1];
      }
      if (newEnergy != 0.0F) {
        h_N = num.size(2);
        k = denom.size(2);
        c_r = num.reshape(h_N);
        d_r = denom.reshape(k);
        newEnergy =
            std::fmax(newEnergy, static_cast<real32_T>(static_cast<real_T>(
                                     b_norm(c_r) / b_norm(d_r))));
      } else {
        h_N = num.size(2);
        k = denom.size(2);
        c_r = num.reshape(h_N);
        d_r = denom.reshape(k);
        newEnergy =
            std::fmax(oldEnergy, static_cast<real32_T>(static_cast<real_T>(
                                     b_norm(c_r) / b_norm(d_r))));
      }
    }
  }
  if (newEnergy != 0.0F) {
    newEnergy = (newEnergy * (static_cast<real32_T>(static_cast<int32_T>(
                                 BoardIdx.size(0) * BoardIdx.size(1))))) -
                (static_cast<real32_T>(
                    static_cast<int32_T>(BoardIdx.size(0) * BoardIdx.size(1))));
  } else {
    newEnergy = rtInfF;
  }
  return newEnergy;
}

//
// Arguments    : const ::coder::array<real_T, 2U> &idx
//                real32_T oldEnergy
// Return Type  : real32_T
//
real32_T b_Checkerboard::computeNewEnergyHorizontal(
    const ::coder::array<real_T, 2U> &idx, real32_T oldEnergy) const
{
  ::coder::array<real_T, 3U> c_this;
  ::coder::array<real_T, 3U> denom;
  ::coder::array<real_T, 3U> num;
  ::coder::array<real_T, 2U> b_denom;
  ::coder::array<real_T, 2U> b_num;
  ::coder::array<real_T, 2U> validNewColIdx;
  ::coder::array<real_T, 1U> c_r;
  ::coder::array<real_T, 1U> d_r;
  ::coder::array<int32_T, 1U> r2;
  ::coder::array<int32_T, 1U> r3;
  ::coder::array<int32_T, 1U> r4;
  ::coder::array<int32_T, 1U> r5;
  ::coder::array<int32_T, 1U> r6;
  ::coder::array<boolean_T, 2U> b_this;
  ::coder::array<boolean_T, 1U> b_x;
  ::coder::array<boolean_T, 1U> r;
  ::coder::array<boolean_T, 1U> r1;
  int32_T b_i;
  int32_T b_idx_tmp;
  int32_T b_loop_ub;
  int32_T c_idx_tmp;
  int32_T d_i;
  int32_T h_N;
  int32_T idx_tmp;
  int32_T k;
  int32_T loop_ub;
  real32_T newEnergy;
  boolean_T exitg1;
  boolean_T y;
  idx_tmp = static_cast<int32_T>(idx[0]);
  b_idx_tmp = static_cast<int32_T>(idx[1]);
  loop_ub = BoardIdx.size(0);
  r.set_size(loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r[b_i] = ((BoardIdx[b_i + (BoardIdx.size(0) * (idx_tmp - 1))] > 0.0) &&
              (BoardIdx[b_i + (BoardIdx.size(0) * (b_idx_tmp - 1))] > 0.0));
  }
  c_idx_tmp = static_cast<int32_T>(idx[2]);
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
    for (d_i = 0; d_i <= k; d_i++) {
      if ((r[d_i]) && (r1[d_i])) {
        h_N++;
      }
    }
    r2.set_size(h_N);
    h_N = 0;
    for (d_i = 0; d_i <= k; d_i++) {
      if ((r[d_i]) && (r1[d_i])) {
        r2[h_N] = d_i + 1;
        h_N++;
      }
    }
    k = r.size(0) - 1;
    h_N = 0;
    for (d_i = 0; d_i <= k; d_i++) {
      if ((r[d_i]) && (r1[d_i])) {
        h_N++;
      }
    }
    r3.set_size(h_N);
    h_N = 0;
    for (d_i = 0; d_i <= k; d_i++) {
      if ((r[d_i]) && (r1[d_i])) {
        r3[h_N] = d_i + 1;
        h_N++;
      }
    }
    k = r.size(0) - 1;
    h_N = 0;
    for (d_i = 0; d_i <= k; d_i++) {
      if ((r[d_i]) && (r1[d_i])) {
        h_N++;
      }
    }
    r4.set_size(h_N);
    h_N = 0;
    for (d_i = 0; d_i <= k; d_i++) {
      if ((r[d_i]) && (r1[d_i])) {
        r4[h_N] = d_i + 1;
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
    for (d_i = 0; d_i <= k; d_i++) {
      if ((r[d_i]) && (r1[d_i])) {
        h_N++;
      }
    }
    r5.set_size(h_N);
    h_N = 0;
    for (d_i = 0; d_i <= k; d_i++) {
      if ((r[d_i]) && (r1[d_i])) {
        r5[h_N] = d_i + 1;
        h_N++;
      }
    }
    k = r.size(0) - 1;
    h_N = 0;
    for (d_i = 0; d_i <= k; d_i++) {
      if ((r[d_i]) && (r1[d_i])) {
        h_N++;
      }
    }
    r6.set_size(h_N);
    h_N = 0;
    for (d_i = 0; d_i <= k; d_i++) {
      if ((r[d_i]) && (r1[d_i])) {
        r6[h_N] = d_i + 1;
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
      c_r.set_size(b_num.size(0));
      h_N = b_num.size(0);
      for (k = 0; k < h_N; k++) {
        c_r[k] = rt_hypotd_snf(b_num[k], b_num[k + b_num.size(0)]);
      }
      d_r.set_size(b_denom.size(0));
      h_N = b_denom.size(0);
      for (k = 0; k < h_N; k++) {
        d_r[k] = rt_hypotd_snf(b_denom[k], b_denom[k + b_denom.size(0)]);
      }
      loop_ub = c_r.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        c_r[b_i] = c_r[b_i] / d_r[b_i];
      }
      newEnergy = std::fmax(
          oldEnergy,
          static_cast<real32_T>(::Codegen::coder::internal::b_maximum(c_r)));
    } else {
      newEnergy =
          std::fmax(oldEnergy, static_cast<real32_T>(static_cast<real_T>(
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
    for (d_i = 0; d_i < b_i; d_i++) {
      real_T d;
      d = validNewColIdx[d_i];
      num.set_size(1, 1, loop_ub);
      for (h_N = 0; h_N < loop_ub; h_N++) {
        num[h_N] =
            (BoardCoords[(((static_cast<int32_T>(d)) +
                           (BoardCoords.size(0) * (idx_tmp - 1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                         1] +
             BoardCoords[(((static_cast<int32_T>(
                               static_cast<real_T>(d + 2.0))) +
                           (BoardCoords.size(0) * (idx_tmp - 1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                         1]) -
            (2.0 *
             BoardCoords[(((static_cast<int32_T>(
                               static_cast<real_T>(d + 1.0))) +
                           (BoardCoords.size(0) * (idx_tmp - 1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                         1]);
      }
      d = validNewColIdx[d_i];
      denom.set_size(1, 1, b_loop_ub);
      for (h_N = 0; h_N < b_loop_ub; h_N++) {
        denom[h_N] =
            BoardCoords[(((static_cast<int32_T>(d)) +
                          (BoardCoords.size(0) * (idx_tmp - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                        1] -
            BoardCoords[(((static_cast<int32_T>(static_cast<real_T>(d + 2.0))) +
                          (BoardCoords.size(0) * (idx_tmp - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                        1];
      }
      if (newEnergy != 0.0F) {
        h_N = num.size(2);
        k = denom.size(2);
        c_r = num.reshape(h_N);
        d_r = denom.reshape(k);
        newEnergy =
            std::fmax(newEnergy, static_cast<real32_T>(static_cast<real_T>(
                                     b_norm(c_r) / b_norm(d_r))));
      } else {
        h_N = num.size(2);
        k = denom.size(2);
        c_r = num.reshape(h_N);
        d_r = denom.reshape(k);
        newEnergy =
            std::fmax(oldEnergy, static_cast<real32_T>(static_cast<real_T>(
                                     b_norm(c_r) / b_norm(d_r))));
      }
    }
  }
  if (newEnergy != 0.0F) {
    newEnergy = (newEnergy * (static_cast<real32_T>(static_cast<int32_T>(
                                 BoardIdx.size(0) * BoardIdx.size(1))))) -
                (static_cast<real32_T>(
                    static_cast<int32_T>(BoardIdx.size(0) * BoardIdx.size(1))));
  } else {
    newEnergy = rtInfF;
  }
  return newEnergy;
}

//
// Arguments    : real32_T oldEnergy
// Return Type  : real32_T
//
real32_T b_Checkerboard::computeNewEnergyVertical(real32_T oldEnergy) const
{
  ::coder::array<real_T, 3U> b;
  ::coder::array<real_T, 3U> denom;
  ::coder::array<real_T, 3U> num;
  ::coder::array<real_T, 3U> r2;
  ::coder::array<real_T, 3U> r4;
  ::coder::array<real_T, 2U> b_denom;
  ::coder::array<real_T, 2U> b_num;
  ::coder::array<real_T, 2U> validNewRowIdx;
  ::coder::array<real_T, 1U> c_r;
  ::coder::array<real_T, 1U> d_r;
  ::coder::array<int32_T, 2U> r1;
  ::coder::array<int32_T, 2U> r3;
  ::coder::array<int32_T, 2U> r5;
  ::coder::array<int32_T, 2U> r6;
  ::coder::array<int32_T, 2U> r7;
  ::coder::array<boolean_T, 2U> b_this;
  ::coder::array<boolean_T, 2U> b_x;
  ::coder::array<boolean_T, 2U> r;
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T d_i;
  int32_T h_N;
  int32_T k;
  int32_T loop_ub;
  real32_T newEnergy;
  boolean_T exitg1;
  boolean_T y;
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
    for (d_i = 0; d_i <= k; d_i++) {
      if ((b_this[d_i]) && (r[d_i])) {
        h_N++;
      }
    }
    r1.set_size(1, h_N);
    h_N = 0;
    for (d_i = 0; d_i <= k; d_i++) {
      if ((b_this[d_i]) && (r[d_i])) {
        r1[h_N] = d_i + 1;
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
    for (d_i = 0; d_i <= k; d_i++) {
      if ((b_this[d_i]) && (r[d_i])) {
        h_N++;
      }
    }
    r3.set_size(1, h_N);
    h_N = 0;
    for (d_i = 0; d_i <= k; d_i++) {
      if ((b_this[d_i]) && (r[d_i])) {
        r3[h_N] = d_i + 1;
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
    for (d_i = 0; d_i <= k; d_i++) {
      if ((b_this[d_i]) && (r[d_i])) {
        h_N++;
      }
    }
    r5.set_size(1, h_N);
    h_N = 0;
    for (d_i = 0; d_i <= k; d_i++) {
      if ((b_this[d_i]) && (r[d_i])) {
        r5[h_N] = d_i + 1;
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
    for (d_i = 0; d_i <= k; d_i++) {
      if ((b_this[d_i]) && (r[d_i])) {
        h_N++;
      }
    }
    r6.set_size(1, h_N);
    h_N = 0;
    for (d_i = 0; d_i <= k; d_i++) {
      if ((b_this[d_i]) && (r[d_i])) {
        r6[h_N] = d_i + 1;
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
    for (d_i = 0; d_i <= k; d_i++) {
      if ((b_this[d_i]) && (r[d_i])) {
        h_N++;
      }
    }
    r7.set_size(1, h_N);
    h_N = 0;
    for (d_i = 0; d_i <= k; d_i++) {
      if ((b_this[d_i]) && (r[d_i])) {
        r7[h_N] = d_i + 1;
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
      c_r.set_size(b_num.size(0));
      h_N = b_num.size(0);
      for (k = 0; k < h_N; k++) {
        c_r[k] = rt_hypotd_snf(b_num[k], b_num[k + b_num.size(0)]);
      }
      d_r.set_size(b_denom.size(0));
      h_N = b_denom.size(0);
      for (k = 0; k < h_N; k++) {
        d_r[k] = rt_hypotd_snf(b_denom[k], b_denom[k + b_denom.size(0)]);
      }
      loop_ub = c_r.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        c_r[b_i] = c_r[b_i] / d_r[b_i];
      }
      newEnergy = std::fmax(
          oldEnergy,
          static_cast<real32_T>(::Codegen::coder::internal::b_maximum(c_r)));
    } else {
      newEnergy =
          std::fmax(oldEnergy, static_cast<real32_T>(static_cast<real_T>(
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
    for (d_i = 0; d_i < b_i; d_i++) {
      real_T d;
      d = validNewRowIdx[d_i];
      num.set_size(1, 1, loop_ub);
      for (h_N = 0; h_N < loop_ub; h_N++) {
        num[h_N] =
            (BoardCoords[(BoardCoords.size(0) *
                          ((static_cast<int32_T>(d)) - 1)) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)] +
             BoardCoords
                 [(BoardCoords.size(0) *
                   ((static_cast<int32_T>(static_cast<real_T>(d + 2.0))) - 1)) +
                  ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)]) -
            (2.0 *
             BoardCoords
                 [(BoardCoords.size(0) *
                   ((static_cast<int32_T>(static_cast<real_T>(d + 1.0))) - 1)) +
                  ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)]);
      }
      d = validNewRowIdx[d_i];
      denom.set_size(1, 1, b_loop_ub);
      for (h_N = 0; h_N < b_loop_ub; h_N++) {
        denom[h_N] =
            BoardCoords[(BoardCoords.size(0) *
                         ((static_cast<int32_T>(d)) - 1)) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)] -
            BoardCoords[(BoardCoords.size(0) *
                         ((static_cast<int32_T>(static_cast<real_T>(d + 2.0))) -
                          1)) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)];
      }
      if (newEnergy != 0.0F) {
        h_N = num.size(2);
        k = denom.size(2);
        c_r = num.reshape(h_N);
        d_r = denom.reshape(k);
        newEnergy =
            std::fmax(newEnergy, static_cast<real32_T>(static_cast<real_T>(
                                     b_norm(c_r) / b_norm(d_r))));
      } else {
        h_N = num.size(2);
        k = denom.size(2);
        c_r = num.reshape(h_N);
        d_r = denom.reshape(k);
        newEnergy =
            std::fmax(oldEnergy, static_cast<real32_T>(static_cast<real_T>(
                                     b_norm(c_r) / b_norm(d_r))));
      }
    }
  }
  if (newEnergy != 0.0F) {
    newEnergy = (newEnergy * (static_cast<real32_T>(static_cast<int32_T>(
                                 BoardIdx.size(0) * BoardIdx.size(1))))) -
                (static_cast<real32_T>(
                    static_cast<int32_T>(BoardIdx.size(0) * BoardIdx.size(1))));
  } else {
    newEnergy = rtInfF;
  }
  return newEnergy;
}

//
// Arguments    : const ::coder::array<real_T, 2U> &idx
//                real32_T oldEnergy
// Return Type  : real32_T
//
real32_T
b_Checkerboard::computeNewEnergyVertical(const ::coder::array<real_T, 2U> &idx,
                                         real32_T oldEnergy) const
{
  ::coder::array<real_T, 3U> b;
  ::coder::array<real_T, 3U> denom;
  ::coder::array<real_T, 3U> num;
  ::coder::array<real_T, 3U> r2;
  ::coder::array<real_T, 3U> r4;
  ::coder::array<real_T, 2U> b_denom;
  ::coder::array<real_T, 2U> b_num;
  ::coder::array<real_T, 2U> validNewRowIdx;
  ::coder::array<real_T, 1U> c_r;
  ::coder::array<real_T, 1U> d_r;
  ::coder::array<int32_T, 2U> r1;
  ::coder::array<int32_T, 2U> r3;
  ::coder::array<int32_T, 2U> r5;
  ::coder::array<int32_T, 2U> r6;
  ::coder::array<int32_T, 2U> r7;
  ::coder::array<boolean_T, 2U> b_this;
  ::coder::array<boolean_T, 2U> b_x;
  ::coder::array<boolean_T, 2U> r;
  int32_T b_i;
  int32_T b_idx_tmp;
  int32_T b_loop_ub;
  int32_T c_idx_tmp;
  int32_T d_i;
  int32_T h_N;
  int32_T idx_tmp;
  int32_T k;
  int32_T loop_ub;
  real32_T newEnergy;
  boolean_T exitg1;
  boolean_T y;
  idx_tmp = static_cast<int32_T>(idx[0]);
  b_idx_tmp = static_cast<int32_T>(idx[1]);
  loop_ub = BoardIdx.size(1);
  b_this.set_size(1, loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_this[b_i] =
        ((BoardIdx[(idx_tmp + (BoardIdx.size(0) * b_i)) - 1] > 0.0) &&
         (BoardIdx[(b_idx_tmp + (BoardIdx.size(0) * b_i)) - 1] > 0.0));
  }
  c_idx_tmp = static_cast<int32_T>(idx[2]);
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
    for (d_i = 0; d_i <= k; d_i++) {
      if ((b_this[d_i]) && (r[d_i])) {
        h_N++;
      }
    }
    r1.set_size(1, h_N);
    h_N = 0;
    for (d_i = 0; d_i <= k; d_i++) {
      if ((b_this[d_i]) && (r[d_i])) {
        r1[h_N] = d_i + 1;
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
    for (d_i = 0; d_i <= k; d_i++) {
      if ((b_this[d_i]) && (r[d_i])) {
        h_N++;
      }
    }
    r3.set_size(1, h_N);
    h_N = 0;
    for (d_i = 0; d_i <= k; d_i++) {
      if ((b_this[d_i]) && (r[d_i])) {
        r3[h_N] = d_i + 1;
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
    for (d_i = 0; d_i <= k; d_i++) {
      if ((b_this[d_i]) && (r[d_i])) {
        h_N++;
      }
    }
    r5.set_size(1, h_N);
    h_N = 0;
    for (d_i = 0; d_i <= k; d_i++) {
      if ((b_this[d_i]) && (r[d_i])) {
        r5[h_N] = d_i + 1;
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
    for (d_i = 0; d_i <= k; d_i++) {
      if ((b_this[d_i]) && (r[d_i])) {
        h_N++;
      }
    }
    r6.set_size(1, h_N);
    h_N = 0;
    for (d_i = 0; d_i <= k; d_i++) {
      if ((b_this[d_i]) && (r[d_i])) {
        r6[h_N] = d_i + 1;
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
    for (d_i = 0; d_i <= k; d_i++) {
      if ((b_this[d_i]) && (r[d_i])) {
        h_N++;
      }
    }
    r7.set_size(1, h_N);
    h_N = 0;
    for (d_i = 0; d_i <= k; d_i++) {
      if ((b_this[d_i]) && (r[d_i])) {
        r7[h_N] = d_i + 1;
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
      c_r.set_size(b_num.size(0));
      h_N = b_num.size(0);
      for (k = 0; k < h_N; k++) {
        c_r[k] = rt_hypotd_snf(b_num[k], b_num[k + b_num.size(0)]);
      }
      d_r.set_size(b_denom.size(0));
      h_N = b_denom.size(0);
      for (k = 0; k < h_N; k++) {
        d_r[k] = rt_hypotd_snf(b_denom[k], b_denom[k + b_denom.size(0)]);
      }
      loop_ub = c_r.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        c_r[b_i] = c_r[b_i] / d_r[b_i];
      }
      newEnergy = std::fmax(
          oldEnergy,
          static_cast<real32_T>(::Codegen::coder::internal::b_maximum(c_r)));
    } else {
      newEnergy =
          std::fmax(oldEnergy, static_cast<real32_T>(static_cast<real_T>(
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
    for (d_i = 0; d_i < b_i; d_i++) {
      real_T d;
      d = validNewRowIdx[d_i];
      num.set_size(1, 1, loop_ub);
      for (h_N = 0; h_N < loop_ub; h_N++) {
        num[h_N] =
            (BoardCoords[((idx_tmp + (BoardCoords.size(0) *
                                      ((static_cast<int32_T>(d)) - 1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                         1] +
             BoardCoords[((idx_tmp + (BoardCoords.size(0) *
                                      ((static_cast<int32_T>(
                                           static_cast<real_T>(d + 2.0))) -
                                       1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                         1]) -
            (2.0 *
             BoardCoords[((idx_tmp + (BoardCoords.size(0) *
                                      ((static_cast<int32_T>(
                                           static_cast<real_T>(d + 1.0))) -
                                       1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                         1]);
      }
      d = validNewRowIdx[d_i];
      denom.set_size(1, 1, b_loop_ub);
      for (h_N = 0; h_N < b_loop_ub; h_N++) {
        denom[h_N] =
            BoardCoords[((idx_tmp + (BoardCoords.size(0) *
                                     ((static_cast<int32_T>(d)) - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                        1] -
            BoardCoords[((idx_tmp + (BoardCoords.size(0) *
                                     ((static_cast<int32_T>(
                                          static_cast<real_T>(d + 2.0))) -
                                      1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * h_N)) -
                        1];
      }
      if (newEnergy != 0.0F) {
        h_N = num.size(2);
        k = denom.size(2);
        c_r = num.reshape(h_N);
        d_r = denom.reshape(k);
        newEnergy =
            std::fmax(newEnergy, static_cast<real32_T>(static_cast<real_T>(
                                     b_norm(c_r) / b_norm(d_r))));
      } else {
        h_N = num.size(2);
        k = denom.size(2);
        c_r = num.reshape(h_N);
        d_r = denom.reshape(k);
        newEnergy =
            std::fmax(oldEnergy, static_cast<real32_T>(static_cast<real_T>(
                                     b_norm(c_r) / b_norm(d_r))));
      }
    }
  }
  if (newEnergy != 0.0F) {
    newEnergy = (newEnergy * (static_cast<real32_T>(static_cast<int32_T>(
                                 BoardIdx.size(0) * BoardIdx.size(1))))) -
                (static_cast<real32_T>(
                    static_cast<int32_T>(BoardIdx.size(0) * BoardIdx.size(1))));
  } else {
    newEnergy = rtInfF;
  }
  return newEnergy;
}

//
// Arguments    : const ::coder::array<real_T, 2U> &indices
//                ::coder::array<real_T, 2U> &newBoard
//                ::coder::array<real_T, 3U> &newBoardCoords
// Return Type  : void
//
void b_Checkerboard::expandBoardLeft(
    const ::coder::array<real_T, 2U> &indices,
    ::coder::array<real_T, 2U> &newBoard,
    ::coder::array<real_T, 3U> &newBoardCoords) const
{
  ::coder::array<real_T, 2U> r1;
  ::coder::array<int32_T, 2U> r;
  ::coder::array<int32_T, 2U> r2;
  int32_T b_i;
  int32_T i1;
  int32_T i2;
  int32_T this_idx_0;
  int32_T this_idx_1;
  int32_T this_idx_2;
  this_idx_0 = BoardIdx.size(0);
  this_idx_1 = BoardIdx.size(1) + 1;
  newBoard.set_size(this_idx_0, this_idx_1);
  for (b_i = 0; b_i < this_idx_1; b_i++) {
    for (i1 = 0; i1 < this_idx_0; i1++) {
      newBoard[i1 + (newBoard.size(0) * b_i)] = 0.0;
    }
  }
  this_idx_0 = BoardIdx.size(0);
  for (b_i = 0; b_i < this_idx_0; b_i++) {
    newBoard[b_i] = indices[b_i];
  }
  b_i = static_cast<int32_T>(2 <= newBoard.size(1));
  this_idx_0 = BoardIdx.size(1);
  for (i1 = 0; i1 < this_idx_0; i1++) {
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
  this_idx_1 = indices.size(1) - 1;
  this_idx_0 = 0;
  for (this_idx_2 = 0; this_idx_2 <= this_idx_1; this_idx_2++) {
    if (indices[this_idx_2] > 0.0) {
      this_idx_0++;
    }
  }
  r.set_size(1, this_idx_0);
  this_idx_0 = 0;
  for (this_idx_2 = 0; this_idx_2 <= this_idx_1; this_idx_2++) {
    if (indices[this_idx_2] > 0.0) {
      r[this_idx_0] = this_idx_2 + 1;
      this_idx_0++;
    }
  }
  this_idx_0 = Points.size(1);
  r1.set_size(r.size(1), this_idx_0);
  for (b_i = 0; b_i < this_idx_0; b_i++) {
    this_idx_1 = r.size(1);
    for (i1 = 0; i1 < this_idx_1; i1++) {
      r1[i1 + (r1.size(0) * b_i)] = static_cast<real_T>(
          Points[((static_cast<int32_T>(indices[r[i1] - 1])) +
                  (Points.size(0) * b_i)) -
                 1]);
    }
  }
  this_idx_1 = indices.size(1) - 1;
  this_idx_0 = 0;
  for (this_idx_2 = 0; this_idx_2 <= this_idx_1; this_idx_2++) {
    if (indices[this_idx_2] > 0.0) {
      this_idx_0++;
    }
  }
  r2.set_size(1, this_idx_0);
  this_idx_0 = 0;
  for (this_idx_2 = 0; this_idx_2 <= this_idx_1; this_idx_2++) {
    if (indices[this_idx_2] > 0.0) {
      r2[this_idx_0] = this_idx_2 + 1;
      this_idx_0++;
    }
  }
  this_idx_0 = r2.size(1);
  this_idx_2 = BoardCoords.size(2);
  for (b_i = 0; b_i < this_idx_2; b_i++) {
    for (i1 = 0; i1 < this_idx_0; i1++) {
      newBoardCoords[(r2[i1] +
                      ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                       b_i)) -
                     1] = r1[i1 + (this_idx_0 * b_i)];
    }
  }
  b_i = static_cast<int32_T>(2 <= newBoardCoords.size(1));
  this_idx_0 = BoardCoords.size(2);
  for (i1 = 0; i1 < this_idx_0; i1++) {
    this_idx_1 = BoardCoords.size(1);
    for (i2 = 0; i2 < this_idx_1; i2++) {
      this_idx_2 = BoardCoords.size(0);
      for (int32_T i3{0}; i3 < this_idx_2; i3++) {
        newBoardCoords[(i3 + (newBoardCoords.size(0) * (b_i + i2))) +
                       ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                        i1)] =
            BoardCoords[(i3 + (BoardCoords.size(0) * i2)) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) * i1)];
      }
    }
  }
}

//
// Arguments    : const ::coder::array<real_T, 2U> &indices
//                ::coder::array<real_T, 2U> &newBoard
//                ::coder::array<real_T, 3U> &newBoardCoords
// Return Type  : void
//
void b_Checkerboard::expandBoardRight(
    const ::coder::array<real_T, 2U> &indices,
    ::coder::array<real_T, 2U> &newBoard,
    ::coder::array<real_T, 3U> &newBoardCoords) const
{
  ::coder::array<real_T, 2U> r1;
  ::coder::array<int32_T, 2U> r;
  ::coder::array<int32_T, 2U> r2;
  int32_T b_i;
  int32_T b_this;
  int32_T i1;
  int32_T i2;
  int32_T this_idx_0;
  int32_T this_idx_1;
  int32_T this_idx_2;
  this_idx_0 = BoardIdx.size(0);
  this_idx_1 = BoardIdx.size(1) + 1;
  newBoard.set_size(this_idx_0, this_idx_1);
  for (b_i = 0; b_i < this_idx_1; b_i++) {
    for (i1 = 0; i1 < this_idx_0; i1++) {
      newBoard[i1 + (newBoard.size(0) * b_i)] = 0.0;
    }
  }
  b_this = BoardIdx.size(1);
  this_idx_0 = BoardIdx.size(0);
  for (b_i = 0; b_i < this_idx_0; b_i++) {
    newBoard[b_i + (newBoard.size(0) * b_this)] = indices[b_i];
  }
  this_idx_0 = BoardIdx.size(1);
  for (b_i = 0; b_i < this_idx_0; b_i++) {
    this_idx_1 = BoardIdx.size(0);
    for (i1 = 0; i1 < this_idx_1; i1++) {
      newBoard[i1 + (newBoard.size(0) * b_i)] =
          BoardIdx[i1 + (BoardIdx.size(0) * b_i)];
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
  b_this = indices.size(1) - 1;
  this_idx_1 = 0;
  for (this_idx_0 = 0; this_idx_0 <= b_this; this_idx_0++) {
    if (indices[this_idx_0] > 0.0) {
      this_idx_1++;
    }
  }
  r.set_size(1, this_idx_1);
  this_idx_1 = 0;
  for (this_idx_0 = 0; this_idx_0 <= b_this; this_idx_0++) {
    if (indices[this_idx_0] > 0.0) {
      r[this_idx_1] = this_idx_0 + 1;
      this_idx_1++;
    }
  }
  this_idx_0 = Points.size(1);
  r1.set_size(r.size(1), this_idx_0);
  for (b_i = 0; b_i < this_idx_0; b_i++) {
    this_idx_1 = r.size(1);
    for (i1 = 0; i1 < this_idx_1; i1++) {
      r1[i1 + (r1.size(0) * b_i)] = static_cast<real_T>(
          Points[((static_cast<int32_T>(indices[r[i1] - 1])) +
                  (Points.size(0) * b_i)) -
                 1]);
    }
  }
  b_this = indices.size(1) - 1;
  this_idx_1 = 0;
  for (this_idx_0 = 0; this_idx_0 <= b_this; this_idx_0++) {
    if (indices[this_idx_0] > 0.0) {
      this_idx_1++;
    }
  }
  r2.set_size(1, this_idx_1);
  this_idx_1 = 0;
  for (this_idx_0 = 0; this_idx_0 <= b_this; this_idx_0++) {
    if (indices[this_idx_0] > 0.0) {
      r2[this_idx_1] = this_idx_0 + 1;
      this_idx_1++;
    }
  }
  this_idx_0 = r2.size(1);
  this_idx_2 = BoardCoords.size(2);
  b_this = BoardCoords.size(1);
  for (b_i = 0; b_i < this_idx_2; b_i++) {
    for (i1 = 0; i1 < this_idx_0; i1++) {
      newBoardCoords[((r2[i1] + (newBoardCoords.size(0) * b_this)) +
                      ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                       b_i)) -
                     1] = r1[i1 + (this_idx_0 * b_i)];
    }
  }
  this_idx_0 = BoardCoords.size(2);
  for (b_i = 0; b_i < this_idx_0; b_i++) {
    this_idx_1 = BoardCoords.size(1);
    for (i1 = 0; i1 < this_idx_1; i1++) {
      b_this = BoardCoords.size(0);
      for (i2 = 0; i2 < b_this; i2++) {
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
// Arguments    : const ::coder::array<real_T, 2U> &indices
//                ::coder::array<real_T, 2U> &newBoard
//                ::coder::array<real_T, 3U> &newBoardCoords
// Return Type  : void
//
void b_Checkerboard::expandBoardUp(
    const ::coder::array<real_T, 2U> &indices,
    ::coder::array<real_T, 2U> &newBoard,
    ::coder::array<real_T, 3U> &newBoardCoords) const
{
  ::coder::array<real_T, 2U> r1;
  ::coder::array<int32_T, 2U> r;
  ::coder::array<int32_T, 2U> r2;
  int32_T b_i;
  int32_T i1;
  int32_T i2;
  int32_T this_idx_0;
  int32_T this_idx_1;
  int32_T this_idx_2;
  this_idx_0 = BoardIdx.size(0) + 1;
  this_idx_1 = BoardIdx.size(1);
  newBoard.set_size(this_idx_0, this_idx_1);
  for (b_i = 0; b_i < this_idx_1; b_i++) {
    for (i1 = 0; i1 < this_idx_0; i1++) {
      newBoard[i1 + (newBoard.size(0) * b_i)] = 0.0;
    }
  }
  this_idx_0 = indices.size(1);
  for (b_i = 0; b_i < this_idx_0; b_i++) {
    newBoard[newBoard.size(0) * b_i] = indices[b_i];
  }
  b_i = static_cast<int32_T>(2 <= newBoard.size(0));
  this_idx_0 = BoardIdx.size(1);
  for (i1 = 0; i1 < this_idx_0; i1++) {
    this_idx_1 = BoardIdx.size(0);
    for (i2 = 0; i2 < this_idx_1; i2++) {
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
  this_idx_1 = indices.size(1) - 1;
  this_idx_0 = 0;
  for (this_idx_2 = 0; this_idx_2 <= this_idx_1; this_idx_2++) {
    if (indices[this_idx_2] > 0.0) {
      this_idx_0++;
    }
  }
  r.set_size(1, this_idx_0);
  this_idx_0 = 0;
  for (this_idx_2 = 0; this_idx_2 <= this_idx_1; this_idx_2++) {
    if (indices[this_idx_2] > 0.0) {
      r[this_idx_0] = this_idx_2 + 1;
      this_idx_0++;
    }
  }
  this_idx_0 = Points.size(1);
  r1.set_size(r.size(1), this_idx_0);
  for (b_i = 0; b_i < this_idx_0; b_i++) {
    this_idx_1 = r.size(1);
    for (i1 = 0; i1 < this_idx_1; i1++) {
      r1[i1 + (r1.size(0) * b_i)] = static_cast<real_T>(
          Points[((static_cast<int32_T>(indices[r[i1] - 1])) +
                  (Points.size(0) * b_i)) -
                 1]);
    }
  }
  this_idx_1 = indices.size(1) - 1;
  this_idx_0 = 0;
  for (this_idx_2 = 0; this_idx_2 <= this_idx_1; this_idx_2++) {
    if (indices[this_idx_2] > 0.0) {
      this_idx_0++;
    }
  }
  r2.set_size(1, this_idx_0);
  this_idx_0 = 0;
  for (this_idx_2 = 0; this_idx_2 <= this_idx_1; this_idx_2++) {
    if (indices[this_idx_2] > 0.0) {
      r2[this_idx_0] = this_idx_2 + 1;
      this_idx_0++;
    }
  }
  this_idx_1 = r2.size(1);
  this_idx_2 = BoardCoords.size(2);
  for (b_i = 0; b_i < this_idx_2; b_i++) {
    for (i1 = 0; i1 < this_idx_1; i1++) {
      newBoardCoords[(newBoardCoords.size(0) * (r2[i1] - 1)) +
                     ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                      b_i)] = r1[i1 + (this_idx_1 * b_i)];
    }
  }
  b_i = static_cast<int32_T>(2 <= newBoardCoords.size(0));
  this_idx_0 = BoardCoords.size(2);
  for (i1 = 0; i1 < this_idx_0; i1++) {
    this_idx_1 = BoardCoords.size(1);
    for (i2 = 0; i2 < this_idx_1; i2++) {
      this_idx_2 = BoardCoords.size(0);
      for (int32_T i3{0}; i3 < this_idx_2; i3++) {
        newBoardCoords[((b_i + i3) + (newBoardCoords.size(0) * i2)) +
                       ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                        i1)] =
            BoardCoords[(i3 + (BoardCoords.size(0) * i2)) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) * i1)];
      }
    }
  }
}

//
// Arguments    : const ::coder::array<real_T, 2U> &predictedPoints
//                ::coder::array<real_T, 2U> &indices
// Return Type  : void
//
void b_Checkerboard::findClosestIndices(
    const ::coder::array<real_T, 2U> &predictedPoints,
    ::coder::array<real_T, 2U> &indices) const
{
  ::coder::array<real_T, 2U> remIdx;
  ::coder::array<real_T, 2U> y;
  ::coder::array<real_T, 1U> b_this;
  ::coder::array<real_T, 1U> ss;
  ::coder::array<int32_T, 2U> r;
  ::coder::array<int32_T, 1U> b_ii;
  ::coder::array<int32_T, 1U> b_ss;
  ::coder::array<real32_T, 2U> b_a;
  ::coder::array<real32_T, 2U> diffs;
  ::coder::array<real32_T, 1U> dists;
  ::coder::array<uint32_T, 1U> validPredictions;
  ::coder::array<boolean_T, 2U> distIdx;
  ::coder::array<boolean_T, 1U> b_x;
  int32_T b_i;
  int32_T exponent;
  int32_T i1;
  int32_T loop_ub;
  int32_T nx;
  real32_T ex;
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
      y[b_i] = (static_cast<real_T>(b_i)) + 1.0;
    }
  }
  nx = BoardIdx.size(0) * BoardIdx.size(1);
  b_this = BoardIdx.reshape(nx);
  do_vectors(y, b_this, remIdx, b_ii, &nx);
  if (remIdx.size(1) != 0) {
    int32_T idx;
    int32_T ilo;
    boolean_T exitg1;
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
    ilo = 0;
    exitg1 = false;
    while ((!exitg1) && (ilo <= (nx - 1))) {
      if (b_x[ilo]) {
        idx++;
        b_ii[idx - 1] = ilo + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          ilo++;
        }
      } else {
        ilo++;
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
      validPredictions[b_i] = static_cast<uint32_T>(b_ii[b_i]);
    }
    b_i = validPredictions.size(0);
    if (0 <= (validPredictions.size(0) - 1)) {
      loop_ub = Points.size(1);
      i1 = predictedPoints.size(1);
    }
    for (int32_T d_i{0}; d_i < b_i; d_i++) {
      real_T absx;
      int32_T acoef;
      int32_T i2;
      int32_T i3;
      int32_T k;
      int32_T na;
      int32_T pow2p;
      boolean_T guard1{false};
      b_a.set_size(remIdx.size(1), loop_ub);
      for (i2 = 0; i2 < loop_ub; i2++) {
        nx = remIdx.size(1);
        for (i3 = 0; i3 < nx; i3++) {
          b_a[i3 + (b_a.size(0) * i2)] =
              Points[((static_cast<int32_T>(remIdx[i3])) +
                      (Points.size(0) * i2)) -
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
        nx = static_cast<int32_T>(b_a.size(1) != 1);
        idx = static_cast<int32_T>(predictedPoints.size(1) != 1);
        i2--;
        for (k = 0; k <= i2; k++) {
          pow2p = nx * k;
          ilo = idx * k;
          acoef = static_cast<int32_T>(b_a.size(0) != 1);
          i3 = diffs.size(0) - 1;
          for (na = 0; na <= i3; na++) {
            diffs[na + (diffs.size(0) * k)] =
                b_a[(acoef * na) + (b_a.size(0) * pow2p)] -
                (static_cast<real32_T>(
                    predictedPoints[((static_cast<int32_T>(
                                         validPredictions[d_i])) +
                                     (predictedPoints.size(0) * ilo)) -
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
      for (pow2p = 0; pow2p <= idx; pow2p++) {
        if (indices[pow2p] > 0.0) {
          nx++;
        }
      }
      r.set_size(1, nx);
      nx = 0;
      for (pow2p = 0; pow2p <= idx; pow2p++) {
        if (indices[pow2p] > 0.0) {
          r[nx] = pow2p + 1;
          nx++;
        }
      }
      nx = r.size(1);
      y.set_size(1, r.size(1));
      for (i2 = 0; i2 < nx; i2++) {
        y[i2] = indices[r[i2] - 1];
      }
      na = remIdx.size(1) - 1;
      acoef = y.size(1);
      nx = remIdx.size(1);
      distIdx.set_size(1, remIdx.size(1));
      for (i2 = 0; i2 < nx; i2++) {
        distIdx[i2] = false;
      }
      guard1 = false;
      if (y.size(1) <= 4) {
        guard1 = true;
      } else {
        nx = 31;
        idx = 0;
        exitg1 = false;
        while ((!exitg1) && ((nx - idx) > 1)) {
          ilo = asr_s32(idx + nx, 1U);
          pow2p = ((static_cast<int32_T>(1)) << (static_cast<uint64_T>(ilo)));
          if (pow2p == acoef) {
            nx = ilo;
            exitg1 = true;
          } else if (pow2p > acoef) {
            nx = ilo;
          } else {
            idx = ilo;
          }
        }
        if (remIdx.size(1) <= (nx + 4)) {
          guard1 = true;
        } else {
          boolean_T b_y;
          b_y = true;
          k = 0;
          exitg1 = false;
          while ((!exitg1) && (k <= (y.size(1) - 2))) {
            absx = y[k + 1];
            if (y[k] <= absx) {
              k++;
            } else if (std::isnan(absx)) {
              k++;
            } else {
              b_y = false;
              exitg1 = true;
            }
          }
          if (!b_y) {
            ss.set_size(y.size(1));
            nx = y.size(1);
            for (i2 = 0; i2 < nx; i2++) {
              ss[i2] = y[i2];
            }
            ::Codegen::coder::internal::c_sort(ss, b_ss);
            for (k = 0; k <= na; k++) {
              absx = remIdx[k];
              nx = ss.size(0);
              idx = -1;
              ilo = 1;
              exitg1 = false;
              while ((!exitg1) && (nx >= ilo)) {
                pow2p = (asr_s32(ilo, 1U) + asr_s32(nx, 1U)) - 1;
                if (((ilo & 1) == 1) && ((nx & 1) == 1)) {
                  pow2p++;
                }
                if (absx == ss[pow2p]) {
                  idx = pow2p;
                  exitg1 = true;
                } else {
                  if (std::isnan(ss[pow2p])) {
                    b_y = !std::isnan(absx);
                  } else if (std::isnan(absx)) {
                    b_y = false;
                  } else {
                    b_y = (absx < ss[pow2p]);
                  }
                  if (b_y) {
                    nx = pow2p;
                  } else {
                    ilo = pow2p + 2;
                  }
                }
              }
              if ((idx + 1) > 0) {
                exitg1 = false;
                while ((!exitg1) && (idx > 0)) {
                  if (absx == ss[idx - 1]) {
                    idx--;
                  } else {
                    exitg1 = true;
                  }
                }
              }
              if ((idx + 1) > 0) {
                distIdx[k] = true;
              }
            }
          } else {
            for (k = 0; k <= na; k++) {
              absx = remIdx[k];
              nx = y.size(1);
              idx = -1;
              ilo = 1;
              exitg1 = false;
              while ((!exitg1) && (nx >= ilo)) {
                pow2p = (asr_s32(ilo, 1U) + asr_s32(nx, 1U)) - 1;
                if (((ilo & 1) == 1) && ((nx & 1) == 1)) {
                  pow2p++;
                }
                if (absx == y[pow2p]) {
                  idx = pow2p;
                  exitg1 = true;
                } else {
                  if (std::isnan(y[pow2p])) {
                    b_y = !std::isnan(absx);
                  } else if (std::isnan(absx)) {
                    b_y = false;
                  } else {
                    b_y = (absx < y[pow2p]);
                  }
                  if (b_y) {
                    nx = pow2p;
                  } else {
                    ilo = pow2p + 2;
                  }
                }
              }
              if ((idx + 1) > 0) {
                exitg1 = false;
                while ((!exitg1) && (idx > 0)) {
                  if (absx == y[idx - 1]) {
                    idx--;
                  } else {
                    exitg1 = true;
                  }
                }
              }
              if ((idx + 1) > 0) {
                distIdx[k] = true;
              }
            }
          }
        }
      }
      if (guard1) {
        for (nx = 0; nx <= na; nx++) {
          k = 0;
          exitg1 = false;
          while ((!exitg1) && (k <= (acoef - 1))) {
            real_T b;
            b = y[k];
            absx = std::abs(b / 2.0);
            if ((!std::isinf(absx)) && (!std::isnan(absx))) {
              if (absx <= 2.2250738585072014E-308) {
                absx = 4.94065645841247E-324;
              } else {
                (void)frexp(absx, &exponent);
                absx = std::ldexp(1.0, exponent - 53);
              }
            } else {
              absx = rtNaN;
            }
            if (std::abs(y[k] - remIdx[nx]) < absx) {
              distIdx[nx] = true;
              exitg1 = true;
            } else if (std::isinf(remIdx[nx])) {
              if (std::isinf(b)) {
                if ((remIdx[nx] > 0.0) == (y[k] > 0.0)) {
                  distIdx[nx] = true;
                  exitg1 = true;
                } else {
                  k++;
                }
              } else {
                k++;
              }
            } else {
              k++;
            }
          }
        }
      }
      idx = distIdx.size(1);
      for (pow2p = 0; pow2p < idx; pow2p++) {
        if (distIdx[pow2p]) {
          dists[pow2p] = rtInfF;
        }
      }
      ::Codegen::coder::internal::minimum(dists, &ex, &nx);
      indices[(static_cast<int32_T>(validPredictions[d_i])) - 1] =
          remIdx[nx - 1];
    }
  }
}

//
// Arguments    : const real_T predictedPoint[2]
//                real_T radius
//                const real_T curve_data[]
//                const int32_T curve_size[2]
//                const real_T coordsToUse[2]
//                const ::coder::array<real_T, 2U> &removedIdx
//                ::coder::array<real_T, 2U> &idx
// Return Type  : void
//
void b_Checkerboard::findClosestOnCurve(
    const real_T predictedPoint[2], real_T radius, const real_T curve_data[],
    const int32_T curve_size[2], const real_T coordsToUse[2],
    const ::coder::array<real_T, 2U> &removedIdx,
    ::coder::array<real_T, 2U> &idx) const
{
  ::coder::array<real_T, 2U> dataPts;
  ::coder::array<real_T, 2U> firstCoord;
  ::coder::array<real_T, 2U> remIdx;
  ::coder::array<real_T, 2U> y;
  ::coder::array<real_T, 1U> b_this;
  ::coder::array<real_T, 1U> dist;
  ::coder::array<int32_T, 1U> ia;
  ::coder::array<int32_T, 1U> r;
  ::coder::array<real32_T, 2U> currPt;
  ::coder::array<real32_T, 2U> diffs;
  ::coder::array<real32_T, 2U> queryPts;
  ::coder::array<real32_T, 2U> z1;
  ::coder::array<real32_T, 1U> b_y;
  ::coder::array<real32_T, 1U> dists;
  ::coder::array<boolean_T, 1U> s;
  real_T dv[2];
  real_T a_tmp;
  int32_T acoef;
  int32_T b_acoef;
  int32_T b_i;
  int32_T b_k;
  int32_T d_i;
  int32_T h_N;
  int32_T k;
  int32_T loop_ub;
  int32_T outsize_idx_0;
  int32_T outsize_idx_1;
  acoef = Points.size(0);
  if (acoef < 1) {
    y.set_size(1, 0);
  } else {
    y.set_size(1, acoef);
    b_acoef = acoef - 1;
    for (b_i = 0; b_i <= b_acoef; b_i++) {
      y[b_i] = (static_cast<real_T>(b_i)) + 1.0;
    }
  }
  h_N = BoardIdx.size(0) * BoardIdx.size(1);
  b_this = BoardIdx.reshape(h_N);
  do_vectors(y, b_this, remIdx, ia, &acoef);
  y.set_size(1, remIdx.size(1));
  b_acoef = remIdx.size(1) - 1;
  for (b_i = 0; b_i <= b_acoef; b_i++) {
    y[b_i] = remIdx[b_i];
  }
  b_do_vectors(y, removedIdx, remIdx, ia, &acoef);
  b_acoef = Points.size(1);
  queryPts.set_size(remIdx.size(1), b_acoef);
  for (b_i = 0; b_i < b_acoef; b_i++) {
    h_N = remIdx.size(1);
    for (k = 0; k < h_N; k++) {
      queryPts[k + (queryPts.size(0) * b_i)] =
          Points[((static_cast<int32_T>(remIdx[k])) + (Points.size(0) * b_i)) -
                 1];
    }
  }
  diffs.set_size(queryPts.size(0), 2);
  if (queryPts.size(0) != 0) {
    acoef = static_cast<int32_T>(queryPts.size(1) != 1);
    b_acoef = static_cast<int32_T>(queryPts.size(0) != 1);
    for (b_k = 0; b_k < 2; b_k++) {
      h_N = acoef * b_k;
      b_i = diffs.size(0) - 1;
      for (k = 0; k <= b_i; k++) {
        diffs[k + (diffs.size(0) * b_k)] =
            queryPts[(b_acoef * k) + (queryPts.size(0) * h_N)] -
            (static_cast<real32_T>(predictedPoint[b_k]));
      }
    }
  }
  dists.set_size(diffs.size(0));
  h_N = diffs.size(0);
  for (b_k = 0; b_k < h_N; b_k++) {
    dists[b_k] = rt_hypotf_snf(diffs[b_k], diffs[b_k + diffs.size(0)]);
  }
  s.set_size(dists.size(0));
  b_acoef = dists.size(0);
  for (b_i = 0; b_i < b_acoef; b_i++) {
    s[b_i] = ((static_cast<real_T>(dists[b_i])) < radius);
  }
  h_N = 0;
  b_i = s.size(0);
  for (b_k = 0; b_k < b_i; b_k++) {
    if (s[b_k]) {
      h_N++;
    }
  }
  if (h_N > 1) {
    real_T b_a;
    boolean_T exitg1;
    boolean_T guard1{false};
    boolean_T guard2{false};
    boolean_T guard3{false};
    a_tmp = predictedPoint[(static_cast<int32_T>(coordsToUse[0])) - 1];
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
        b_acoef = static_cast<int32_T>(std::floor(a_tmp - b_a));
        firstCoord.set_size(1, b_acoef + 1);
        for (b_i = 0; b_i <= b_acoef; b_i++) {
          firstCoord[b_i] = b_a + (static_cast<real_T>(b_i));
        }
      } else {
        real_T apnd;
        real_T cdiff;
        real_T ndbl;
        ndbl = std::floor((a_tmp - b_a) + 0.5);
        apnd = b_a + ndbl;
        cdiff = apnd - a_tmp;
        if (std::abs(cdiff) < (4.4408920985006262E-16 *
                               std::fmax(std::abs(b_a), std::abs(a_tmp)))) {
          ndbl++;
          apnd = a_tmp;
        } else if (cdiff > 0.0) {
          apnd = b_a + (ndbl - 1.0);
        } else {
          ndbl++;
        }
        if (ndbl >= 0.0) {
          h_N = static_cast<int32_T>(ndbl);
        } else {
          h_N = 0;
        }
        firstCoord.set_size(1, h_N);
        if (h_N > 0) {
          firstCoord[0] = b_a;
          if (h_N > 1) {
            firstCoord[h_N - 1] = apnd;
            acoef = (h_N - 1) / 2;
            for (b_k = 0; b_k <= (acoef - 2); b_k++) {
              firstCoord[b_k + 1] = b_a + ((static_cast<real_T>(b_k)) + 1.0);
              firstCoord[(h_N - b_k) - 2] =
                  apnd - ((static_cast<real_T>(b_k)) + 1.0);
            }
            if ((acoef * 2) == (h_N - 1)) {
              firstCoord[acoef] = (b_a + apnd) / 2.0;
            } else {
              firstCoord[acoef] = b_a + (static_cast<real_T>(acoef));
              firstCoord[acoef + 1] = apnd - (static_cast<real_T>(acoef));
            }
          }
        }
      }
    }
    dv[0] = 1.0;
    dv[1] = 2.0;
    if (isequal(coordsToUse, dv)) {
      y.set_size(1, firstCoord.size(1));
      if (firstCoord.size(1) != 0) {
        acoef = firstCoord.size(1);
        y.set_size(1, firstCoord.size(1));
        for (b_i = 0; b_i < acoef; b_i++) {
          y[b_i] = curve_data[0];
        }
        b_i = curve_size[1];
        if (0 <= (curve_size[1] - 2)) {
          d_i = firstCoord.size(1);
        }
        for (b_k = 0; b_k <= (b_i - 2); b_k++) {
          a_tmp = curve_data[b_k + 1];
          y.set_size(1, firstCoord.size(1));
          for (k = 0; k < d_i; k++) {
            y[k] = (firstCoord[k] * y[k]) + a_tmp;
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
        acoef = firstCoord.size(1);
        y.set_size(1, firstCoord.size(1));
        for (b_i = 0; b_i < acoef; b_i++) {
          y[b_i] = curve_data[0];
        }
        b_i = curve_size[1];
        if (0 <= (curve_size[1] - 2)) {
          d_i = firstCoord.size(1);
        }
        for (b_k = 0; b_k <= (b_i - 2); b_k++) {
          a_tmp = curve_data[b_k + 1];
          y.set_size(1, firstCoord.size(1));
          for (k = 0; k < d_i; k++) {
            y[k] = (firstCoord[k] * y[k]) + a_tmp;
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
    h_N = dists.size(0) - 1;
    acoef = 0;
    for (d_i = 0; d_i <= h_N; d_i++) {
      if ((static_cast<real_T>(dists[d_i])) < radius) {
        acoef++;
      }
    }
    r.set_size(acoef);
    acoef = 0;
    for (d_i = 0; d_i <= h_N; d_i++) {
      if ((static_cast<real_T>(dists[d_i])) < radius) {
        r[acoef] = d_i + 1;
        acoef++;
      }
    }
    b_acoef = Points.size(1);
    queryPts.set_size(r.size(0), b_acoef);
    for (b_i = 0; b_i < b_acoef; b_i++) {
      h_N = r.size(0);
      for (k = 0; k < h_N; k++) {
        queryPts[k + (queryPts.size(0) * b_i)] =
            Points[((static_cast<int32_T>(remIdx[r[k] - 1])) +
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
    for (d_i = 0; d_i < b_i; d_i++) {
      real32_T ex;
      currPt.set_size(outsize_idx_0, outsize_idx_1);
      if ((outsize_idx_0 != 0) && (outsize_idx_1 != 0)) {
        k = queryPts.size(1) - 1;
        for (b_k = 0; b_k <= k; b_k++) {
          h_N = dataPts.size(0) - 1;
          for (acoef = 0; acoef <= h_N; acoef++) {
            currPt[acoef + (currPt.size(0) * b_k)] =
                queryPts[d_i + (queryPts.size(0) * b_k)];
          }
        }
      }
      diffs.set_size(dataPts.size(0), 2);
      for (k = 0; k < 2; k++) {
        for (h_N = 0; h_N < loop_ub; h_N++) {
          diffs[h_N + (diffs.size(0) * k)] =
              (static_cast<real32_T>(dataPts[h_N + (dataPts.size(0) * k)])) -
              currPt[h_N + (currPt.size(0) * k)];
        }
      }
      z1.set_size(diffs.size(0), 2);
      for (b_k = 0; b_k < 2; b_k++) {
        h_N = z1.size(0);
        for (k = 0; k < h_N; k++) {
          z1[k + (z1.size(0) * b_k)] =
              rt_powf_snf(diffs[k + (diffs.size(0) * b_k)], 2.0F);
        }
      }
      k = z1.size(0);
      if (z1.size(0) == 0) {
        b_y.set_size(0);
      } else {
        b_y.set_size(z1.size(0));
        for (b_k = 0; b_k < k; b_k++) {
          b_y[b_k] = z1[b_k];
        }
        k = z1.size(0);
        for (b_k = 0; b_k < k; b_k++) {
          b_y[b_k] = b_y[b_k] + z1[b_k + z1.size(0)];
        }
      }
      acoef = b_y.size(0);
      if (b_y.size(0) <= 2) {
        if (b_y.size(0) == 1) {
          ex = b_y[0];
        } else if (b_y[0] > b_y[b_y.size(0) - 1]) {
          ex = b_y[b_y.size(0) - 1];
        } else if (std::isnan(b_y[0])) {
          if (!std::isnan(b_y[b_y.size(0) - 1])) {
            ex = b_y[b_y.size(0) - 1];
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
          b_k = 2;
          exitg1 = false;
          while ((!exitg1) && (b_k <= acoef)) {
            if (!std::isnan(b_y[b_k - 1])) {
              b_acoef = b_k;
              exitg1 = true;
            } else {
              b_k++;
            }
          }
        }
        if (b_acoef == 0) {
          ex = b_y[0];
        } else {
          ex = b_y[b_acoef - 1];
          k = b_acoef + 1;
          for (b_k = k; b_k <= acoef; b_k++) {
            real32_T f;
            f = b_y[b_k - 1];
            if (ex > f) {
              ex = f;
            }
          }
        }
      }
      ex = std::sqrt(ex);
      dist[d_i] = static_cast<real_T>(ex);
    }
    ::Codegen::coder::internal::b_minimum(dist, &a_tmp, &acoef);
    s.set_size(dists.size(0));
    b_acoef = dists.size(0);
    for (b_i = 0; b_i < b_acoef; b_i++) {
      s[b_i] = ((static_cast<real_T>(dists[b_i])) < radius);
    }
    h_N = s.size(0);
    if (acoef <= h_N) {
      h_N = acoef;
    }
    b_acoef = 0;
    ia.set_size(h_N);
    acoef = 0;
    exitg1 = false;
    while ((!exitg1) && (acoef <= (s.size(0) - 1))) {
      if (s[acoef]) {
        b_acoef++;
        ia[b_acoef - 1] = acoef + 1;
        if (b_acoef >= h_N) {
          exitg1 = true;
        } else {
          acoef++;
        }
      } else {
        acoef++;
      }
    }
    if (h_N == 1) {
      if (b_acoef == 0) {
        ia.set_size(0);
      }
    } else {
      if (1 > b_acoef) {
        b_acoef = 0;
      }
      ia.set_size(b_acoef);
    }
    dist.set_size(ia.size(0));
    b_acoef = ia.size(0);
    for (b_i = 0; b_i < b_acoef; b_i++) {
      dist[b_i] = static_cast<real_T>(ia[b_i]);
    }
    idx.set_size(1, 1);
    idx[0] = remIdx[(static_cast<int32_T>(dist[dist.size(0) - 1])) - 1];
  } else {
    s.set_size(dists.size(0));
    b_acoef = dists.size(0);
    for (b_i = 0; b_i < b_acoef; b_i++) {
      s[b_i] = ((static_cast<real_T>(dists[b_i])) < radius);
    }
    h_N = 0;
    b_i = s.size(0);
    for (b_k = 0; b_k < b_i; b_k++) {
      if (s[b_k]) {
        h_N++;
      }
    }
    if (h_N == 1) {
      h_N = dists.size(0) - 1;
      acoef = 0;
      for (d_i = 0; d_i <= h_N; d_i++) {
        if ((static_cast<real_T>(dists[d_i])) < radius) {
          acoef++;
        }
      }
      r.set_size(acoef);
      acoef = 0;
      for (d_i = 0; d_i <= h_N; d_i++) {
        if ((static_cast<real_T>(dists[d_i])) < radius) {
          r[acoef] = d_i + 1;
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
// Arguments    : const ::coder::array<real32_T, 2U> &pointVectors
//                const ::coder::array<real32_T, 1U> &euclideanDists
//                const real32_T b_v[2]
// Return Type  : real_T
//
real_T
b_Checkerboard::findNeighbor(const ::coder::array<real32_T, 2U> &pointVectors,
                             const ::coder::array<real32_T, 1U> &euclideanDists,
                             const real32_T b_v[2]) const
{
  ::coder::array<int32_T, 1U> r1;
  ::coder::array<int32_T, 1U> r2;
  ::coder::array<real32_T, 1U> angleCosines;
  ::coder::array<real32_T, 1U> dists;
  ::coder::array<boolean_T, 2U> r;
  real_T neighborIdx;
  int32_T b_i;
  int32_T inner;
  int32_T k;
  int32_T mc;
  real32_T b;
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
    r2[k] = static_cast<int32_T>(BoardIdx[r1[k] - 1]);
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
  neighborIdx = static_cast<real_T>(mc);
  if (std::isinf(b)) {
    neighborIdx = -1.0;
  }
  return neighborIdx;
}

//
// Arguments    : const ::coder::array<real32_T, 2U> &pointVectors
//                const ::coder::array<real32_T, 1U> &euclideanDists
//                const ::coder::array<real32_T, 2U> &b_v
// Return Type  : real_T
//
real_T
b_Checkerboard::findNeighbor(const ::coder::array<real32_T, 2U> &pointVectors,
                             const ::coder::array<real32_T, 1U> &euclideanDists,
                             const ::coder::array<real32_T, 2U> &b_v) const
{
  ::coder::array<int32_T, 1U> r1;
  ::coder::array<int32_T, 1U> r2;
  ::coder::array<real32_T, 1U> angleCosines;
  ::coder::array<real32_T, 1U> dists;
  ::coder::array<boolean_T, 2U> r;
  real_T neighborIdx;
  int32_T b_i;
  int32_T inner;
  int32_T k;
  int32_T mc;
  real32_T bkj;
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
    r2[k] = static_cast<int32_T>(BoardIdx[r1[k] - 1]);
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
  neighborIdx = static_cast<real_T>(mc);
  if (std::isinf(bkj)) {
    neighborIdx = -1.0;
  }
  return neighborIdx;
}

//
// Arguments    : ::coder::array<real_T, 2U> &newIndices
// Return Type  : void
//
void b_Checkerboard::fitPolynomialIndices(
    ::coder::array<real_T, 2U> &newIndices) const
{
  ::coder::array<real_T, 2U> b_index;
  ::coder::array<real_T, 2U> r5;
  ::coder::array<real_T, 2U> r7;
  ::coder::array<real_T, 2U> removedIdx;
  ::coder::array<real_T, 1U> b_this;
  ::coder::array<real_T, 1U> c_this;
  ::coder::array<int32_T, 2U> r2;
  ::coder::array<int32_T, 2U> r3;
  ::coder::array<int32_T, 2U> r4;
  ::coder::array<int32_T, 2U> r6;
  ::coder::array<int32_T, 1U> b_validIdx;
  ::coder::array<boolean_T, 2U> r;
  ::coder::array<boolean_T, 2U> r1;
  real_T currCurve_data[5];
  real_T coordsToUse[2];
  real_T currPt[2];
  int32_T currCurve_size[2];
  int32_T b_i;
  int32_T d_i;
  int32_T end;
  int32_T loop_ub;
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
  for (d_i = 0; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      loop_ub++;
    }
  }
  r2.set_size(1, loop_ub);
  loop_ub = 0;
  for (d_i = 0; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      r2[loop_ub] = d_i + 1;
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
  for (d_i = 0; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      loop_ub++;
    }
  }
  r3.set_size(1, loop_ub);
  loop_ub = 0;
  for (d_i = 0; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      r3[loop_ub] = d_i + 1;
      loop_ub++;
    }
  }
  b_index.set_size(1, r3.size(1));
  loop_ub = r3.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_index[b_i] = BoardCoords[BoardCoords.size(0) * (r3[b_i] - 1)];
  }
  end = r.size(1) - 1;
  loop_ub = 0;
  for (d_i = 0; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      loop_ub++;
    }
  }
  r4.set_size(1, loop_ub);
  loop_ub = 0;
  for (d_i = 0; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      r4[loop_ub] = d_i + 1;
      loop_ub++;
    }
  }
  r5.set_size(1, r4.size(1));
  loop_ub = r4.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r5[b_i] = BoardCoords[((BoardCoords.size(0) * (r4[b_i] - 1)) +
                           (BoardCoords.size(0) * BoardCoords.size(1))) +
                          1];
  }
  end = r.size(1) - 1;
  loop_ub = 0;
  for (d_i = 0; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      loop_ub++;
    }
  }
  r6.set_size(1, loop_ub);
  loop_ub = 0;
  for (d_i = 0; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      r6[loop_ub] = d_i + 1;
      loop_ub++;
    }
  }
  r7.set_size(1, r6.size(1));
  loop_ub = r6.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r7[b_i] = BoardCoords[(BoardCoords.size(0) * (r6[b_i] - 1)) +
                          (BoardCoords.size(0) * BoardCoords.size(1))];
  }
  removedIdx.set_size(1, removedIdx.size(1));
  loop_ub = removedIdx.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    removedIdx[b_i] = removedIdx[b_i] - b_index[b_i];
  }
  r5.set_size(1, r5.size(1));
  loop_ub = r5.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r5[b_i] = r5[b_i] - r7[b_i];
  }
  if (std::abs(mean(removedIdx)) > std::abs(mean(r5))) {
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
  for (d_i = 0; d_i < b_i; d_i++) {
    int32_T i1;
    loop_ub = BoardCoords.size(0);
    b_this.set_size(loop_ub);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_this[i1] = BoardCoords[(i1 + (BoardCoords.size(0) * d_i)) +
                               ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                ((static_cast<int32_T>(coordsToUse[0])) - 1))];
    }
    eml_find(b_this, b_validIdx);
    if (b_validIdx.size(0) >= 2) {
      real_T coordDist;
      real_T coordDist_tmp;
      real_T currCoord;
      real_T currRad;
      int32_T i2;
      boolean_T exitg1;
      i1 = static_cast<int32_T>(coordsToUse[0]);
      coordDist_tmp =
          BoardCoords[((b_validIdx[0] + (BoardCoords.size(0) * d_i)) +
                       ((BoardCoords.size(0) * BoardCoords.size(1)) *
                        (i1 - 1))) -
                      1];
      coordDist = (coordDist_tmp -
                   BoardCoords[((b_validIdx[1] + (BoardCoords.size(0) * d_i)) +
                                ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                 (i1 - 1))) -
                               1]) /
                  ((static_cast<real_T>(b_validIdx[1])) -
                   (static_cast<real_T>(b_validIdx[0])));
      end = 0;
      i2 = b_validIdx.size(0);
      b_this.set_size(b_validIdx.size(0));
      c_this.set_size(b_validIdx.size(0));
      for (loop_ub = 0; loop_ub < i2; loop_ub++) {
        if (b_validIdx[loop_ub] != 0) {
          end++;
        }
        b_this[loop_ub] =
            BoardCoords[((b_validIdx[loop_ub] + (BoardCoords.size(0) * d_i)) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) *
                          (i1 - 1))) -
                        1];
        c_this[loop_ub] =
            BoardCoords[((b_validIdx[loop_ub] + (BoardCoords.size(0) * d_i)) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) *
                          ((static_cast<int32_T>(coordsToUse[1])) - 1))) -
                        1];
      }
      if (end > 5) {
        end = 4;
      } else {
        end = 2;
      }
      polyfit(b_this, c_this, static_cast<real_T>(end), currCurve_data,
              currCurve_size);
      currRad = coordDist / 4.0;
      currCoord = currRad + coordDist_tmp;
      exitg1 = false;
      while ((!exitg1) && (std::abs(currCoord - coordDist_tmp) <
                           (((static_cast<real_T>(b_validIdx[0])) * 1.5) *
                            std::abs(coordDist)))) {
        currPt[0] = 1.0;
        currPt[1] = 2.0;
        if (isequal(coordsToUse, currPt)) {
          real_T y;
          y = currCurve_data[0];
          i1 = currCurve_size[1];
          for (loop_ub = 0; loop_ub <= (i1 - 2); loop_ub++) {
            y = (currCoord * y) + currCurve_data[loop_ub + 1];
          }
          currPt[0] = currCoord;
          currPt[1] = y;
        } else {
          real_T y;
          y = currCurve_data[0];
          i1 = currCurve_size[1];
          for (loop_ub = 0; loop_ub <= (i1 - 2); loop_ub++) {
            y = (currCoord * y) + currCurve_data[loop_ub + 1];
          }
          currPt[0] = y;
          currPt[1] = currCoord;
        }
        findClosestOnCurve(currPt, std::abs(currRad), currCurve_data,
                           currCurve_size, coordsToUse, removedIdx, b_index);
        if (b_index.size(1) != 0) {
          newIndices[d_i] = b_index[0];
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
// Arguments    : const ::coder::array<real_T, 2U> &idx
//                ::coder::array<real_T, 2U> &newIndices
// Return Type  : void
//
void b_Checkerboard::fitPolynomialIndices(
    const ::coder::array<real_T, 2U> &idx,
    ::coder::array<real_T, 2U> &newIndices) const
{
  ::coder::array<real_T, 2U> b_index;
  ::coder::array<real_T, 2U> r5;
  ::coder::array<real_T, 2U> r7;
  ::coder::array<real_T, 2U> removedIdx;
  ::coder::array<real_T, 1U> b_this;
  ::coder::array<real_T, 1U> c_this;
  ::coder::array<int32_T, 2U> r2;
  ::coder::array<int32_T, 2U> r3;
  ::coder::array<int32_T, 2U> r4;
  ::coder::array<int32_T, 2U> r6;
  ::coder::array<int32_T, 1U> b_validIdx;
  ::coder::array<boolean_T, 2U> r;
  ::coder::array<boolean_T, 2U> r1;
  real_T currCurve_data[5];
  real_T coordsToUse[2];
  real_T currPt[2];
  int32_T currCurve_size[2];
  int32_T b_i;
  int32_T b_idx_tmp;
  int32_T d_i;
  int32_T end;
  int32_T idx_tmp;
  int32_T loop_ub;
  idx_tmp = static_cast<int32_T>(idx[0]);
  loop_ub = BoardIdx.size(1);
  r.set_size(1, loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r[b_i] = (BoardIdx[(idx_tmp + (BoardIdx.size(0) * b_i)) - 1] > 0.0);
  }
  b_idx_tmp = static_cast<int32_T>(idx[1]);
  loop_ub = BoardIdx.size(1);
  r1.set_size(1, loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r1[b_i] = (BoardIdx[(b_idx_tmp + (BoardIdx.size(0) * b_i)) - 1] > 0.0);
  }
  end = r.size(1) - 1;
  loop_ub = 0;
  for (d_i = 0; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      loop_ub++;
    }
  }
  r2.set_size(1, loop_ub);
  loop_ub = 0;
  for (d_i = 0; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      r2[loop_ub] = d_i + 1;
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
  for (d_i = 0; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      loop_ub++;
    }
  }
  r3.set_size(1, loop_ub);
  loop_ub = 0;
  for (d_i = 0; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      r3[loop_ub] = d_i + 1;
      loop_ub++;
    }
  }
  b_index.set_size(1, r3.size(1));
  loop_ub = r3.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_index[b_i] =
        BoardCoords[(idx_tmp + (BoardCoords.size(0) * (r3[b_i] - 1))) - 1];
  }
  end = r.size(1) - 1;
  loop_ub = 0;
  for (d_i = 0; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      loop_ub++;
    }
  }
  r4.set_size(1, loop_ub);
  loop_ub = 0;
  for (d_i = 0; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      r4[loop_ub] = d_i + 1;
      loop_ub++;
    }
  }
  r5.set_size(1, r4.size(1));
  loop_ub = r4.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r5[b_i] = BoardCoords[((b_idx_tmp + (BoardCoords.size(0) * (r4[b_i] - 1))) +
                           (BoardCoords.size(0) * BoardCoords.size(1))) -
                          1];
  }
  end = r.size(1) - 1;
  loop_ub = 0;
  for (d_i = 0; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      loop_ub++;
    }
  }
  r6.set_size(1, loop_ub);
  loop_ub = 0;
  for (d_i = 0; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      r6[loop_ub] = d_i + 1;
      loop_ub++;
    }
  }
  r7.set_size(1, r6.size(1));
  loop_ub = r6.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r7[b_i] = BoardCoords[((idx_tmp + (BoardCoords.size(0) * (r6[b_i] - 1))) +
                           (BoardCoords.size(0) * BoardCoords.size(1))) -
                          1];
  }
  removedIdx.set_size(1, removedIdx.size(1));
  loop_ub = removedIdx.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    removedIdx[b_i] = removedIdx[b_i] - b_index[b_i];
  }
  r5.set_size(1, r5.size(1));
  loop_ub = r5.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r5[b_i] = r5[b_i] - r7[b_i];
  }
  if (std::abs(mean(removedIdx)) > std::abs(mean(r5))) {
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
    for (d_i = 0; d_i < loop_ub; d_i++) {
      b_this[d_i] = BoardCoords[(d_i + (BoardCoords.size(0) * b_idx_tmp)) +
                                ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                 ((static_cast<int32_T>(coordsToUse[0])) - 1))];
    }
    eml_find(b_this, b_validIdx);
    if (b_validIdx.size(0) >= 2) {
      real_T coordDist;
      real_T currCoord;
      real_T currRad;
      real_T moveDistMultiplier;
      real_T refCoordValue;
      int32_T i1;
      boolean_T exitg1;
      if (idx[0] == 1.0) {
        moveDistMultiplier = static_cast<real_T>(b_validIdx[0]);
        end = b_validIdx[0];
        d_i = static_cast<int32_T>(coordsToUse[0]);
        coordDist =
            (BoardCoords[((b_validIdx[0] + (BoardCoords.size(0) * b_idx_tmp)) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) *
                           (d_i - 1))) -
                         1] -
             BoardCoords[((b_validIdx[1] + (BoardCoords.size(0) * b_idx_tmp)) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) *
                           (d_i - 1))) -
                         1]) /
            ((static_cast<real_T>(b_validIdx[1])) -
             (static_cast<real_T>(b_validIdx[0])));
      } else {
        moveDistMultiplier =
            ((static_cast<real_T>(BoardCoords.size(0))) -
             (static_cast<real_T>(b_validIdx[b_validIdx.size(0) - 1]))) +
            1.0;
        end = b_validIdx[b_validIdx.size(0) - 1];
        d_i = static_cast<int32_T>(coordsToUse[0]);
        coordDist = (BoardCoords[((b_validIdx[b_validIdx.size(0) - 1] +
                                   (BoardCoords.size(0) * b_idx_tmp)) +
                                  ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                   (d_i - 1))) -
                                 1] -
                     BoardCoords[((b_validIdx[b_validIdx.size(0) - 2] +
                                   (BoardCoords.size(0) * b_idx_tmp)) +
                                  ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                   (d_i - 1))) -
                                 1]) /
                    ((static_cast<real_T>(b_validIdx[b_validIdx.size(0) - 1])) -
                     (static_cast<real_T>(b_validIdx[b_validIdx.size(0) - 2])));
      }
      loop_ub = 0;
      i1 = b_validIdx.size(0);
      b_this.set_size(b_validIdx.size(0));
      c_this.set_size(b_validIdx.size(0));
      for (idx_tmp = 0; idx_tmp < i1; idx_tmp++) {
        if (b_validIdx[idx_tmp] != 0) {
          loop_ub++;
        }
        b_this[idx_tmp] = BoardCoords
            [((b_validIdx[idx_tmp] + (BoardCoords.size(0) * b_idx_tmp)) +
              ((BoardCoords.size(0) * BoardCoords.size(1)) * (d_i - 1))) -
             1];
        c_this[idx_tmp] =
            BoardCoords[((b_validIdx[idx_tmp] +
                          (BoardCoords.size(0) * b_idx_tmp)) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) *
                          ((static_cast<int32_T>(coordsToUse[1])) - 1))) -
                        1];
      }
      if (loop_ub > 5) {
        loop_ub = 4;
      } else {
        loop_ub = 2;
      }
      polyfit(b_this, c_this, static_cast<real_T>(loop_ub), currCurve_data,
              currCurve_size);
      currRad = coordDist / 4.0;
      refCoordValue =
          BoardCoords[((end + (BoardCoords.size(0) * b_idx_tmp)) +
                       ((BoardCoords.size(0) * BoardCoords.size(1)) *
                        ((static_cast<int32_T>(coordsToUse[0])) - 1))) -
                      1];
      currCoord = currRad + refCoordValue;
      exitg1 = false;
      while ((!exitg1) &&
             (std::abs(currCoord - refCoordValue) <
              ((moveDistMultiplier * 1.5) * std::abs(coordDist)))) {
        currPt[0] = 1.0;
        currPt[1] = 2.0;
        if (isequal(coordsToUse, currPt)) {
          real_T y;
          y = currCurve_data[0];
          d_i = currCurve_size[1];
          for (idx_tmp = 0; idx_tmp <= (d_i - 2); idx_tmp++) {
            y = (currCoord * y) + currCurve_data[idx_tmp + 1];
          }
          currPt[0] = currCoord;
          currPt[1] = y;
        } else {
          real_T y;
          y = currCurve_data[0];
          d_i = currCurve_size[1];
          for (idx_tmp = 0; idx_tmp <= (d_i - 2); idx_tmp++) {
            y = (currCoord * y) + currCurve_data[idx_tmp + 1];
          }
          currPt[0] = y;
          currPt[1] = currCoord;
        }
        findClosestOnCurve(currPt, std::abs(currRad), currCurve_data,
                           currCurve_size, coordsToUse, removedIdx, b_index);
        if (b_index.size(1) != 0) {
          newIndices[b_idx_tmp] = b_index[0];
          d_i = removedIdx.size(1);
          loop_ub = b_index.size(1);
          removedIdx.set_size(removedIdx.size(0),
                              removedIdx.size(1) + b_index.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            removedIdx[d_i + i1] = b_index[i1];
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
// Arguments    : real32_T u0
//                real32_T u1
// Return Type  : real32_T
//
} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
static real32_T rt_hypotf_snf(real32_T u0, real32_T u1)
{
  real32_T b_a;
  real32_T y;
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
// Arguments    : real_T direction
// Return Type  : void
//
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void b_Checkerboard::expandBoardDirectionally(real_T direction)
{
  ::coder::array<real_T, 3U> b_this;
  ::coder::array<real_T, 3U> r;
  ::coder::array<real_T, 2U> idx;
  ::coder::array<real_T, 2U> newIndices;
  ::coder::array<real_T, 2U> newIndicesLinear;
  ::coder::array<real_T, 2U> p1;
  ::coder::array<real_T, 2U> p2;
  ::coder::array<int32_T, 2U> r1;
  ::coder::array<int32_T, 2U> r2;
  real32_T oldEnergy;
  oldEnergy = (Energy + (static_cast<real32_T>(static_cast<int32_T>(
                            BoardIdx.size(0) * BoardIdx.size(1))))) /
              (static_cast<real32_T>(
                  static_cast<int32_T>(BoardIdx.size(0) * BoardIdx.size(1))));
  switch (static_cast<int32_T>(direction)) {
  case 1: {
    int32_T b_i;
    int32_T b_loop_ub;
    int32_T i1;
    int32_T loop_ub;
    int32_T numCols;
    if (IsDistortionHigh) {
      boolean_T exitg1;
      boolean_T y;
      fitPolynomialIndices(newIndices);
      y = true;
      numCols = 0;
      exitg1 = false;
      while ((!exitg1) && (numCols <= (newIndices.size(1) - 1))) {
        if (newIndices[numCols] == 0.0) {
          y = false;
          exitg1 = true;
        } else {
          numCols++;
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
            real_T d;
            d = p2[i1 + (p2.size(0) * b_i)];
            d = (d + d) - p1[i1 + (p1.size(0) * b_i)];
            p2[i1 + (p2.size(0) * b_i)] = d;
          }
        }
        findClosestIndices(p2, newIndicesLinear);
        b_loop_ub = newIndices.size(1);
        for (int32_T d_i{0}; d_i < b_loop_ub; d_i++) {
          if (newIndices[d_i] == 0.0) {
            newIndices[d_i] = newIndicesLinear[d_i];
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
          real_T d;
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
        numCols = r.size(0);
        for (int32_T i2{0}; i2 < numCols; i2++) {
          BoardCoords[(i2 + (BoardCoords.size(0) * i1)) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)] =
              r[(i2 + (r.size(0) * i1)) + ((r.size(0) * r.size(1)) * b_i)];
        }
      }
    }
    oldEnergy = computeNewEnergyVertical(oldEnergy);
  } break;
  case 2: {
    int32_T b_i;
    int32_T b_loop_ub;
    int32_T d_i;
    int32_T i1;
    int32_T i2;
    int32_T loop_ub;
    int32_T numCols;
    numCols = BoardCoords.size(0);
    if ((static_cast<real_T>(numCols)) <
        ((static_cast<real_T>(numCols)) - 2.0)) {
      idx.set_size(1, 0);
    } else {
      loop_ub = static_cast<int32_T>(
          static_cast<real_T>(-(((static_cast<real_T>(numCols)) - 2.0) -
                                (static_cast<real_T>(numCols)))));
      idx.set_size(1, loop_ub + 1);
      for (b_i = 0; b_i <= loop_ub; b_i++) {
        idx[b_i] = (static_cast<real_T>(numCols)) - (static_cast<real_T>(b_i));
      }
    }
    if (IsDistortionHigh) {
      boolean_T exitg1;
      boolean_T y;
      fitPolynomialIndices(idx, newIndices);
      y = true;
      numCols = 0;
      exitg1 = false;
      while ((!exitg1) && (numCols <= (newIndices.size(1) - 1))) {
        if (newIndices[numCols] == 0.0) {
          y = false;
          exitg1 = true;
        } else {
          numCols++;
        }
      }
      if (!y) {
        numCols = static_cast<int32_T>(idx[1]);
        loop_ub = BoardCoords.size(1);
        b_loop_ub = BoardCoords.size(2);
        b_this.set_size(1, loop_ub, b_loop_ub);
        for (b_i = 0; b_i < b_loop_ub; b_i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_this[i1 + (b_this.size(1) * b_i)] =
                BoardCoords[((numCols + (BoardCoords.size(0) * i1)) +
                             ((BoardCoords.size(0) * BoardCoords.size(1)) *
                              b_i)) -
                            1];
          }
        }
        squeeze(b_this, p1);
        numCols = static_cast<int32_T>(idx[0]);
        loop_ub = BoardCoords.size(1);
        b_loop_ub = BoardCoords.size(2);
        b_this.set_size(1, loop_ub, b_loop_ub);
        for (b_i = 0; b_i < b_loop_ub; b_i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_this[i1 + (b_this.size(1) * b_i)] =
                BoardCoords[((numCols + (BoardCoords.size(0) * i1)) +
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
            real_T d;
            d = p2[i1 + (p2.size(0) * b_i)];
            d = (d + d) - p1[i1 + (p1.size(0) * b_i)];
            p2[i1 + (p2.size(0) * b_i)] = d;
          }
        }
        findClosestIndices(p2, newIndicesLinear);
        b_loop_ub = newIndices.size(1);
        for (d_i = 0; d_i < b_loop_ub; d_i++) {
          if (newIndices[d_i] == 0.0) {
            newIndices[d_i] = newIndicesLinear[d_i];
          }
        }
      }
    } else {
      numCols = static_cast<int32_T>(idx[1]);
      loop_ub = BoardCoords.size(1);
      b_loop_ub = BoardCoords.size(2);
      b_this.set_size(1, loop_ub, b_loop_ub);
      for (b_i = 0; b_i < b_loop_ub; b_i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_this[i1 + (b_this.size(1) * b_i)] =
              BoardCoords[((numCols + (BoardCoords.size(0) * i1)) +
                           ((BoardCoords.size(0) * BoardCoords.size(1)) *
                            b_i)) -
                          1];
        }
      }
      squeeze(b_this, p1);
      numCols = static_cast<int32_T>(idx[0]);
      loop_ub = BoardCoords.size(1);
      b_loop_ub = BoardCoords.size(2);
      b_this.set_size(1, loop_ub, b_loop_ub);
      for (b_i = 0; b_i < b_loop_ub; b_i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_this[i1 + (b_this.size(1) * b_i)] =
              BoardCoords[((numCols + (BoardCoords.size(0) * i1)) +
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
          real_T d;
          d = p2[i1 + (p2.size(0) * b_i)];
          d = (d + d) - p1[i1 + (p1.size(0) * b_i)];
          p2[i1 + (p2.size(0) * b_i)] = d;
        }
      }
      findClosestIndices(p2, newIndices);
    }
    numCols = BoardIdx.size(0) + 1;
    d_i = BoardIdx.size(1);
    p1.set_size(numCols, d_i);
    for (b_i = 0; b_i < d_i; b_i++) {
      for (i1 = 0; i1 < numCols; i1++) {
        p1[i1 + (p1.size(0) * b_i)] = 0.0;
      }
    }
    numCols = BoardIdx.size(0);
    loop_ub = newIndices.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      p1[numCols + (p1.size(0) * b_i)] = newIndices[b_i];
    }
    loop_ub = BoardIdx.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = BoardIdx.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        p1[i1 + (p1.size(0) * b_i)] = BoardIdx[i1 + (BoardIdx.size(0) * b_i)];
      }
    }
    numCols = BoardCoords.size(0) + 1;
    d_i = BoardCoords.size(1);
    b_loop_ub = BoardCoords.size(2);
    r.set_size(numCols, d_i, b_loop_ub);
    for (b_i = 0; b_i < b_loop_ub; b_i++) {
      for (i1 = 0; i1 < d_i; i1++) {
        for (i2 = 0; i2 < numCols; i2++) {
          r[(i2 + (r.size(0) * i1)) + ((r.size(0) * r.size(1)) * b_i)] = 0.0;
        }
      }
    }
    b_loop_ub = newIndices.size(1) - 1;
    numCols = 0;
    for (d_i = 0; d_i <= b_loop_ub; d_i++) {
      if (newIndices[d_i] > 0.0) {
        numCols++;
      }
    }
    r1.set_size(1, numCols);
    numCols = 0;
    for (d_i = 0; d_i <= b_loop_ub; d_i++) {
      if (newIndices[d_i] > 0.0) {
        r1[numCols] = d_i + 1;
        numCols++;
      }
    }
    loop_ub = Points.size(1);
    p2.set_size(r1.size(1), loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = r1.size(1);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        p2[i1 + (p2.size(0) * b_i)] = static_cast<real_T>(
            Points[((static_cast<int32_T>(newIndices[r1[i1] - 1])) +
                    (Points.size(0) * b_i)) -
                   1]);
      }
    }
    b_loop_ub = newIndices.size(1) - 1;
    numCols = 0;
    for (d_i = 0; d_i <= b_loop_ub; d_i++) {
      if (newIndices[d_i] > 0.0) {
        numCols++;
      }
    }
    r2.set_size(1, numCols);
    numCols = 0;
    for (d_i = 0; d_i <= b_loop_ub; d_i++) {
      if (newIndices[d_i] > 0.0) {
        r2[numCols] = d_i + 1;
        numCols++;
      }
    }
    d_i = r2.size(1);
    numCols = BoardCoords.size(0);
    loop_ub = BoardCoords.size(2);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      for (i1 = 0; i1 < d_i; i1++) {
        r[(numCols + (r.size(0) * (r2[i1] - 1))) +
          ((r.size(0) * r.size(1)) * b_i)] = p2[i1 + (d_i * b_i)];
      }
    }
    loop_ub = BoardCoords.size(2);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = BoardCoords.size(1);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        numCols = BoardCoords.size(0);
        for (i2 = 0; i2 < numCols; i2++) {
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
        numCols = r.size(0);
        for (i2 = 0; i2 < numCols; i2++) {
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
    int32_T b_i;
    int32_T b_loop_ub;
    int32_T i1;
    int32_T loop_ub;
    int32_T numCols;
    if (IsDistortionHigh) {
      boolean_T exitg1;
      boolean_T y;
      b_fitPolynomialIndices(newIndices);
      y = true;
      numCols = 0;
      exitg1 = false;
      while ((!exitg1) && (numCols <= (newIndices.size(1) - 1))) {
        if (newIndices[numCols] == 0.0) {
          y = false;
          exitg1 = true;
        } else {
          numCols++;
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
            real_T d;
            d = p2[i1 + (p2.size(0) * b_i)];
            d = (d + d) - p1[i1 + (p1.size(0) * b_i)];
            p2[i1 + (p2.size(0) * b_i)] = d;
          }
        }
        findClosestIndices(p2, newIndicesLinear);
        b_loop_ub = newIndices.size(1);
        for (int32_T d_i{0}; d_i < b_loop_ub; d_i++) {
          if (newIndices[d_i] == 0.0) {
            newIndices[d_i] = newIndicesLinear[d_i];
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
          real_T d;
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
        numCols = r.size(0);
        for (int32_T i2{0}; i2 < numCols; i2++) {
          BoardCoords[(i2 + (BoardCoords.size(0) * i1)) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)] =
              r[(i2 + (r.size(0) * i1)) + ((r.size(0) * r.size(1)) * b_i)];
        }
      }
    }
    oldEnergy = computeNewEnergyHorizontal(oldEnergy);
  } break;
  default: {
    int32_T b_i;
    int32_T b_loop_ub;
    int32_T i1;
    int32_T loop_ub;
    int32_T numCols;
    numCols = BoardCoords.size(1);
    if ((static_cast<real_T>(numCols)) <
        ((static_cast<real_T>(numCols)) - 2.0)) {
      idx.set_size(1, 0);
    } else {
      loop_ub = static_cast<int32_T>(
          static_cast<real_T>(-(((static_cast<real_T>(numCols)) - 2.0) -
                                (static_cast<real_T>(numCols)))));
      idx.set_size(1, loop_ub + 1);
      for (b_i = 0; b_i <= loop_ub; b_i++) {
        idx[b_i] = (static_cast<real_T>(numCols)) - (static_cast<real_T>(b_i));
      }
    }
    if (IsDistortionHigh) {
      boolean_T exitg1;
      boolean_T y;
      b_fitPolynomialIndices(idx, newIndices);
      y = true;
      numCols = 0;
      exitg1 = false;
      while ((!exitg1) && (numCols <= (newIndices.size(1) - 1))) {
        if (newIndices[numCols] == 0.0) {
          y = false;
          exitg1 = true;
        } else {
          numCols++;
        }
      }
      if (!y) {
        numCols = static_cast<int32_T>(idx[1]);
        loop_ub = BoardCoords.size(0);
        b_loop_ub = BoardCoords.size(2);
        b_this.set_size(loop_ub, 1, b_loop_ub);
        for (b_i = 0; b_i < b_loop_ub; b_i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_this[i1 + (b_this.size(0) * b_i)] =
                BoardCoords[(i1 + (BoardCoords.size(0) * (numCols - 1))) +
                            ((BoardCoords.size(0) * BoardCoords.size(1)) *
                             b_i)];
          }
        }
        b_squeeze(b_this, p1);
        numCols = static_cast<int32_T>(idx[0]);
        loop_ub = BoardCoords.size(0);
        b_loop_ub = BoardCoords.size(2);
        b_this.set_size(loop_ub, 1, b_loop_ub);
        for (b_i = 0; b_i < b_loop_ub; b_i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_this[i1 + (b_this.size(0) * b_i)] =
                BoardCoords[(i1 + (BoardCoords.size(0) * (numCols - 1))) +
                            ((BoardCoords.size(0) * BoardCoords.size(1)) *
                             b_i)];
          }
        }
        b_squeeze(b_this, p2);
        loop_ub = p2.size(1);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          b_loop_ub = p2.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            real_T d;
            d = p2[i1 + (p2.size(0) * b_i)];
            d = (d + d) - p1[i1 + (p1.size(0) * b_i)];
            p2[i1 + (p2.size(0) * b_i)] = d;
          }
        }
        findClosestIndices(p2, newIndicesLinear);
        b_loop_ub = newIndices.size(1);
        for (int32_T d_i{0}; d_i < b_loop_ub; d_i++) {
          if (newIndices[d_i] == 0.0) {
            newIndices[d_i] = newIndicesLinear[d_i];
          }
        }
      }
    } else {
      numCols = static_cast<int32_T>(idx[1]);
      loop_ub = BoardCoords.size(0);
      b_loop_ub = BoardCoords.size(2);
      b_this.set_size(loop_ub, 1, b_loop_ub);
      for (b_i = 0; b_i < b_loop_ub; b_i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_this[i1 + (b_this.size(0) * b_i)] =
              BoardCoords[(i1 + (BoardCoords.size(0) * (numCols - 1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)];
        }
      }
      b_squeeze(b_this, p1);
      numCols = static_cast<int32_T>(idx[0]);
      loop_ub = BoardCoords.size(0);
      b_loop_ub = BoardCoords.size(2);
      b_this.set_size(loop_ub, 1, b_loop_ub);
      for (b_i = 0; b_i < b_loop_ub; b_i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_this[i1 + (b_this.size(0) * b_i)] =
              BoardCoords[(i1 + (BoardCoords.size(0) * (numCols - 1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i)];
        }
      }
      b_squeeze(b_this, p2);
      loop_ub = p2.size(1);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b_loop_ub = p2.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          real_T d;
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
        numCols = r.size(0);
        for (int32_T i2{0}; i2 < numCols; i2++) {
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
  }
  Energy = oldEnergy;
}

//
// Arguments    : real_T seedIdx
//                const ::coder::array<real32_T, 2U> &b_points
//                const real32_T v1[2]
//                const real32_T v2[2]
// Return Type  : void
//
void b_Checkerboard::initialize(real_T seedIdx,
                                const ::coder::array<real32_T, 2U> &b_points,
                                const real32_T v1[2], const real32_T v2[2])
{
  ::coder::array<real_T, 2U> r1;
  ::coder::array<int32_T, 1U> r;
  ::coder::array<real32_T, 2U> b_u;
  ::coder::array<real32_T, 2U> c_r;
  ::coder::array<real32_T, 2U> center;
  ::coder::array<real32_T, 2U> col1;
  ::coder::array<real32_T, 2U> col2;
  ::coder::array<real32_T, 2U> d;
  ::coder::array<real32_T, 2U> k_l;
  ::coder::array<real32_T, 2U> pointVectors;
  ::coder::array<real32_T, 2U> row3;
  ::coder::array<real32_T, 1U> euclideanDists;
  ::coder::array<boolean_T, 1U> b_x;
  int32_T b_i;
  int32_T csz_idx_1;
  int32_T h_N;
  int32_T i1;
  int32_T k;
  int32_T loop_ub;
  real32_T b_z1[3];
  real32_T z1[3];
  real32_T b_v1[2];
  boolean_T exitg1;
  boolean_T y;
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
        Points[((static_cast<int32_T>(seedIdx)) + (Points.size(0) * b_i)) - 1];
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
                1] = static_cast<real_T>(center[b_i]);
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
    int32_T acoef;
    int32_T bcoef;
    acoef = static_cast<int32_T>(Points.size(1) != 1);
    bcoef = static_cast<int32_T>(center.size(1) != 1);
    b_i = csz_idx_1 - 1;
    for (k = 0; k <= b_i; k++) {
      h_N = acoef * k;
      loop_ub = bcoef * k;
      csz_idx_1 = static_cast<int32_T>(Points.size(0) != 1);
      i1 = pointVectors.size(0) - 1;
      for (int32_T b_k{0}; b_k <= i1; b_k++) {
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
      findNeighbor(pointVectors, euclideanDists, v1);
  b_v1[0] = -v1[0];
  b_v1[1] = -v1[1];
  BoardIdx[1] = findNeighbor(pointVectors, euclideanDists, b_v1);
  BoardIdx[BoardIdx.size(0) + 2] =
      findNeighbor(pointVectors, euclideanDists, v2);
  b_v1[0] = -v2[0];
  b_v1[1] = -v2[1];
  BoardIdx[BoardIdx.size(0)] = findNeighbor(pointVectors, euclideanDists, b_v1);
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
    h_N = static_cast<int32_T>(BoardIdx[(BoardIdx.size(0) * 2) + 1]);
    loop_ub = Points.size(1);
    c_r.set_size(1, loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      c_r[b_i] = Points[(h_N + (Points.size(0) * b_i)) - 1];
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
                  1] = static_cast<real_T>(c_r[b_i]);
    }
    h_N = static_cast<int32_T>(BoardIdx[1]);
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
          static_cast<real_T>(k_l[b_i]);
    }
    h_N = static_cast<int32_T>(BoardIdx[BoardIdx.size(0) + 2]);
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
                  2] = static_cast<real_T>(d[b_i]);
    }
    h_N = static_cast<int32_T>(BoardIdx[BoardIdx.size(0)]);
    loop_ub = Points.size(1);
    b_u.set_size(1, loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_u[b_i] = Points[(h_N + (Points.size(0) * b_i)) - 1];
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
          static_cast<real_T>(b_u[b_i]);
    }
    b_u.set_size(1, b_u.size(1));
    loop_ub = b_u.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_u[b_i] = b_u[b_i] - center[b_i];
    }
    d.set_size(1, d.size(1));
    loop_ub = d.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      d[b_i] = d[b_i] - center[b_i];
    }
    c_r.set_size(1, c_r.size(1));
    loop_ub = c_r.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      c_r[b_i] = c_r[b_i] - center[b_i];
    }
    k_l.set_size(1, k_l.size(1));
    loop_ub = k_l.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      k_l[b_i] = k_l[b_i] - center[b_i];
    }
    center.set_size(1, b_u.size(1));
    loop_ub = b_u.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      center[b_i] = b_u[b_i] + k_l[b_i];
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
      d[b_i] = d[b_i] + c_r[b_i];
    }
    BoardIdx[(BoardIdx.size(0) * 2) + 2] =
        findNeighbor(pointVectors, euclideanDists, d);
    b_u.set_size(1, b_u.size(1));
    loop_ub = b_u.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_u[b_i] = b_u[b_i] + c_r[b_i];
    }
    BoardIdx[BoardIdx.size(0) * 2] =
        findNeighbor(pointVectors, euclideanDists, b_u);
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
      real32_T z1_idx_0;
      loop_ub = BoardCoords.size(2);
      r.set_size(loop_ub);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        r[b_i] = b_i;
      }
      h_N = static_cast<int32_T>(BoardIdx[0]);
      loop_ub = Points.size(1);
      r1.set_size(1, loop_ub);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        r1[b_i] =
            static_cast<real_T>(Points[(h_N + (Points.size(0) * b_i)) - 1]);
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
      h_N = static_cast<int32_T>(BoardIdx[2]);
      loop_ub = Points.size(1);
      r1.set_size(1, loop_ub);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        r1[b_i] =
            static_cast<real_T>(Points[(h_N + (Points.size(0) * b_i)) - 1]);
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
      h_N = static_cast<int32_T>(BoardIdx[(BoardIdx.size(0) * 2) + 2]);
      loop_ub = Points.size(1);
      r1.set_size(1, loop_ub);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        r1[b_i] =
            static_cast<real_T>(Points[(h_N + (Points.size(0) * b_i)) - 1]);
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
      h_N = static_cast<int32_T>(BoardIdx[BoardIdx.size(0) * 2]);
      loop_ub = Points.size(1);
      r1.set_size(1, loop_ub);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        r1[b_i] =
            static_cast<real_T>(Points[(h_N + (Points.size(0) * b_i)) - 1]);
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
        real32_T z1_idx_1;
        real32_T z1_idx_2;
        loop_ub = Points.size(1);
        col1.set_size(3, loop_ub);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          col1[3 * b_i] = Points[((static_cast<int32_T>(BoardIdx[0])) +
                                  (Points.size(0) * b_i)) -
                                 1];
          col1[(3 * b_i) + 1] =
              Points[((static_cast<int32_T>(BoardIdx[BoardIdx.size(0)])) +
                      (Points.size(0) * b_i)) -
                     1];
          col1[(3 * b_i) + 2] =
              Points[((static_cast<int32_T>(BoardIdx[BoardIdx.size(0) * 2])) +
                      (Points.size(0) * b_i)) -
                     1];
        }
        loop_ub = Points.size(1);
        col2.set_size(3, loop_ub);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          col2[3 * b_i] = Points[((static_cast<int32_T>(BoardIdx[1])) +
                                  (Points.size(0) * b_i)) -
                                 1];
          col2[(3 * b_i) + 1] =
              Points[((static_cast<int32_T>(BoardIdx[BoardIdx.size(0) + 1])) +
                      (Points.size(0) * b_i)) -
                     1];
          col2[(3 * b_i) + 2] =
              Points[((static_cast<int32_T>(
                          BoardIdx[(BoardIdx.size(0) * 2) + 1])) +
                      (Points.size(0) * b_i)) -
                     1];
        }
        loop_ub = Points.size(1);
        row3.set_size(3, loop_ub);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          row3[3 * b_i] = Points[((static_cast<int32_T>(BoardIdx[2])) +
                                  (Points.size(0) * b_i)) -
                                 1];
          row3[(3 * b_i) + 1] =
              Points[((static_cast<int32_T>(BoardIdx[BoardIdx.size(0) + 2])) +
                      (Points.size(0) * b_i)) -
                     1];
          row3[(3 * b_i) + 2] =
              Points[((static_cast<int32_T>(
                          BoardIdx[(BoardIdx.size(0) * 2) + 2])) +
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
          col1[3 * b_i] = Points[((static_cast<int32_T>(BoardIdx[0])) +
                                  (Points.size(0) * b_i)) -
                                 1];
          col1[(3 * b_i) + 1] = Points[((static_cast<int32_T>(BoardIdx[1])) +
                                        (Points.size(0) * b_i)) -
                                       1];
          col1[(3 * b_i) + 2] = Points[((static_cast<int32_T>(BoardIdx[2])) +
                                        (Points.size(0) * b_i)) -
                                       1];
        }
        loop_ub = Points.size(1);
        col2.set_size(3, loop_ub);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          col2[3 * b_i] =
              Points[((static_cast<int32_T>(BoardIdx[BoardIdx.size(0)])) +
                      (Points.size(0) * b_i)) -
                     1];
          col2[(3 * b_i) + 1] =
              Points[((static_cast<int32_T>(BoardIdx[BoardIdx.size(0) + 1])) +
                      (Points.size(0) * b_i)) -
                     1];
          col2[(3 * b_i) + 2] =
              Points[((static_cast<int32_T>(BoardIdx[BoardIdx.size(0) + 2])) +
                      (Points.size(0) * b_i)) -
                     1];
        }
        loop_ub = Points.size(1);
        row3.set_size(3, loop_ub);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          row3[3 * b_i] =
              Points[((static_cast<int32_T>(BoardIdx[BoardIdx.size(0) * 2])) +
                      (Points.size(0) * b_i)) -
                     1];
          row3[(3 * b_i) + 1] =
              Points[((static_cast<int32_T>(
                          BoardIdx[(BoardIdx.size(0) * 2) + 1])) +
                      (Points.size(0) * b_i)) -
                     1];
          row3[(3 * b_i) + 2] =
              Points[((static_cast<int32_T>(
                          BoardIdx[(BoardIdx.size(0) * 2) + 2])) +
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
        real32_T boardSize;
        boardSize = static_cast<real32_T>(
            static_cast<int32_T>(BoardIdx.size(0) * BoardIdx.size(1)));
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
          ((static_cast<real_T>(Energy)) < (static_cast<real_T>(loop_ub)));
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
