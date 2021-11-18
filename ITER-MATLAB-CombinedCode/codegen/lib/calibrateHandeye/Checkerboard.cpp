//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Checkerboard.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 14:44:26
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
// Arguments    : const ::coder::array<bool, 2U> &arr
//                ::coder::array<double, 2U> &matchedIdx
// Return Type  : void
//
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void b_Checkerboard::arrayFind(const ::coder::array<bool, 2U> &arr,
                               ::coder::array<double, 2U> &matchedIdx)
{
  array<int, 2U> b_arr;
  array<int, 2U> c_ii;
  array<signed char, 2U> matchArr;
  array<bool, 2U> b_x;
  int b_i;
  int b_idx;
  int b_loop_ub;
  int e_ii;
  int loop_ub;
  int nx;
  bool c_x[3];
  bool exitg1;
  matchArr.set_size(1, arr.size(1) - 2);
  b_i = arr.size(1);
  for (int idx{0}; idx <= (b_i - 3); idx++) {
    int k;
    bool y;
    b_arr.set_size(1, 3);
    for (int i1{0}; i1 < 3; i1++) {
      b_arr[i1] = static_cast<int>(arr[idx + i1]);
    }
    c_x[0] = (b_arr[0] == 1);
    c_x[1] = (b_arr[1] == 1);
    c_x[2] = (b_arr[2] == 1);
    y = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!c_x[k]) {
        y = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    matchArr[idx] = static_cast<signed char>(y);
  }
  b_x.set_size(1, matchArr.size(1));
  loop_ub = matchArr.size(1);
  for (int i2{0}; i2 < loop_ub; i2++) {
    b_x[i2] = (matchArr[i2] == 1);
  }
  nx = b_x.size(1);
  b_idx = 0;
  c_ii.set_size(1, b_x.size(1));
  e_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (e_ii <= (nx - 1))) {
    if (b_x[e_ii]) {
      b_idx++;
      c_ii[b_idx - 1] = e_ii + 1;
      if (b_idx >= nx) {
        exitg1 = true;
      } else {
        e_ii++;
      }
    } else {
      e_ii++;
    }
  }
  if (b_x.size(1) == 1) {
    if (b_idx == 0) {
      c_ii.set_size(1, 0);
    }
  } else {
    int i3;
    if (1 > b_idx) {
      i3 = 0;
    } else {
      i3 = b_idx;
    }
    c_ii.set_size(c_ii.size(0), i3);
  }
  matchedIdx.set_size(1, c_ii.size(1));
  b_loop_ub = c_ii.size(1);
  for (int i4{0}; i4 < b_loop_ub; i4++) {
    matchedIdx[i4] = static_cast<double>(c_ii[i4]);
  }
}

//
// Arguments    : ::coder::array<double, 2U> &newIndices
// Return Type  : void
//
void b_Checkerboard::b_fitPolynomialIndices(
    ::coder::array<double, 2U> &newIndices) const
{
  array<double, 2U> b_index;
  array<double, 2U> b_this;
  array<double, 2U> c_this;
  array<double, 2U> currCurve;
  array<double, 2U> removedIdx;
  array<double, 1U> b_x;
  array<double, 1U> c_x;
  array<int, 2U> c_ii;
  array<int, 1U> r2;
  array<int, 1U> r3;
  array<int, 1U> r4;
  array<int, 1U> r5;
  array<bool, 1U> r;
  array<bool, 1U> r1;
  double coordsToUse[2];
  double currPt[2];
  double dv[2];
  double b_y;
  double y;
  int b_end;
  int b_loop_ub;
  int b_partialTrueCount;
  int b_trueCount;
  int c_end;
  int c_loop_ub;
  int c_partialTrueCount;
  int c_trueCount;
  int d_end;
  int d_loop_ub;
  int d_partialTrueCount;
  int d_trueCount;
  int end;
  int i5;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  int unnamed_idx_1;
  loop_ub = BoardIdx.size(0);
  r.set_size(loop_ub);
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    r[b_i] = (BoardIdx[b_i] > 0.0);
  }
  b_loop_ub = BoardIdx.size(0);
  r1.set_size(b_loop_ub);
  for (int i1{0}; i1 < b_loop_ub; i1++) {
    r1[i1] = (BoardIdx[i1 + BoardIdx.size(0)] > 0.0);
  }
  end = r.size(0) - 1;
  trueCount = 0;
  for (int c_i{0}; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      trueCount++;
    }
  }
  r2.set_size(trueCount);
  partialTrueCount = 0;
  for (int d_i{0}; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      r2[partialTrueCount] = d_i + 1;
      partialTrueCount++;
    }
  }
  b_end = r.size(0) - 1;
  b_trueCount = 0;
  for (int e_i{0}; e_i <= b_end; e_i++) {
    if ((r[e_i]) && (r1[e_i])) {
      b_trueCount++;
    }
  }
  r3.set_size(b_trueCount);
  b_partialTrueCount = 0;
  for (int g_i{0}; g_i <= b_end; g_i++) {
    if ((r[g_i]) && (r1[g_i])) {
      r3[b_partialTrueCount] = g_i + 1;
      b_partialTrueCount++;
    }
  }
  b_x.set_size(r2.size(0));
  c_loop_ub = r2.size(0);
  for (int i2{0}; i2 < c_loop_ub; i2++) {
    b_x[i2] = BoardCoords[(r2[i2] + BoardCoords.size(0)) - 1] -
              BoardCoords[r3[i2] - 1];
  }
  c_end = r.size(0) - 1;
  c_trueCount = 0;
  for (int h_i{0}; h_i <= c_end; h_i++) {
    if ((r[h_i]) && (r1[h_i])) {
      c_trueCount++;
    }
  }
  r4.set_size(c_trueCount);
  c_partialTrueCount = 0;
  for (int o_i{0}; o_i <= c_end; o_i++) {
    if ((r[o_i]) && (r1[o_i])) {
      r4[c_partialTrueCount] = o_i + 1;
      c_partialTrueCount++;
    }
  }
  d_end = r.size(0) - 1;
  d_trueCount = 0;
  for (int q_i{0}; q_i <= d_end; q_i++) {
    if ((r[q_i]) && (r1[q_i])) {
      d_trueCount++;
    }
  }
  r5.set_size(d_trueCount);
  d_partialTrueCount = 0;
  for (int w_i{0}; w_i <= d_end; w_i++) {
    if ((r[w_i]) && (r1[w_i])) {
      r5[d_partialTrueCount] = w_i + 1;
      d_partialTrueCount++;
    }
  }
  c_x.set_size(r4.size(0));
  d_loop_ub = r4.size(0);
  for (int i3{0}; i3 < d_loop_ub; i3++) {
    c_x[i3] =
        BoardCoords[((r4[i3] + BoardCoords.size(0)) +
                     (BoardCoords.size(0) * BoardCoords.size(1))) -
                    1] -
        BoardCoords[(r5[i3] + (BoardCoords.size(0) * BoardCoords.size(1))) - 1];
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
  unnamed_idx_1 = BoardCoords.size(0);
  newIndices.set_size(1, unnamed_idx_1);
  for (int i4{0}; i4 < unnamed_idx_1; i4++) {
    newIndices[i4] = 0.0;
  }
  removedIdx.set_size(1, 0);
  i5 = BoardCoords.size(0);
  for (int j{0}; j < i5; j++) {
    int e_loop_ub;
    e_loop_ub = BoardCoords.size(1);
    b_this.set_size(1, e_loop_ub);
    for (int i6{0}; i6 < e_loop_ub; i6++) {
      b_this[i6] = BoardCoords[(j + (BoardCoords.size(0) * i6)) +
                               ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                ((static_cast<int>(coordsToUse[0])) - 1))];
    }
    b_eml_find(b_this, c_ii);
    if (c_ii.size(1) >= 2) {
      double coordDist;
      double coordDist_tmp;
      double currCoord;
      double currRad;
      int b_coordDist_tmp;
      int c_n;
      int d_n;
      int i7;
      int i8;
      bool exitg1;
      i7 = static_cast<int>(coordsToUse[0]);
      coordDist_tmp =
          BoardCoords[(j + (BoardCoords.size(0) * (c_ii[0] - 1))) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * (i7 - 1))];
      b_coordDist_tmp = c_ii[0];
      coordDist = (coordDist_tmp -
                   BoardCoords[(j + (BoardCoords.size(0) * (c_ii[1] - 1))) +
                               ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                (i7 - 1))]) /
                  ((static_cast<double>(c_ii[1])) -
                   (static_cast<double>(b_coordDist_tmp)));
      c_n = 0;
      i8 = c_ii.size(1);
      b_this.set_size(1, c_ii.size(1));
      c_this.set_size(1, c_ii.size(1));
      for (int k{0}; k < i8; k++) {
        if (c_ii[k] != 0) {
          c_n++;
        }
        b_this[k] = BoardCoords[(j + (BoardCoords.size(0) * (c_ii[k] - 1))) +
                                ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                 (i7 - 1))];
        c_this[k] = BoardCoords[(j + (BoardCoords.size(0) * (c_ii[k] - 1))) +
                                ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                 ((static_cast<int>(coordsToUse[1])) - 1))];
      }
      if (c_n > 5) {
        d_n = 4;
      } else {
        d_n = 2;
      }
      b_polyfit(b_this, c_this, static_cast<double>(d_n), currCurve);
      currRad = coordDist / 4.0;
      currCoord = currRad + coordDist_tmp;
      exitg1 = false;
      while ((!exitg1) && (std::abs(currCoord - coordDist_tmp) <
                           (((static_cast<double>(b_coordDist_tmp)) * 1.5) *
                            std::abs(coordDist)))) {
        dv[0] = 1.0;
        dv[1] = 2.0;
        if (isequal(coordsToUse, dv)) {
          if (currCurve.size(1) != 0) {
            int i10;
            b_y = currCurve[0];
            i10 = currCurve.size(1);
            for (int c_k{0}; c_k <= (i10 - 2); c_k++) {
              b_y = (currCoord * b_y) + currCurve[c_k + 1];
            }
          }
          currPt[0] = currCoord;
          currPt[1] = b_y;
        } else {
          if (currCurve.size(1) != 0) {
            int i9;
            y = currCurve[0];
            i9 = currCurve.size(1);
            for (int b_k{0}; b_k <= (i9 - 2); b_k++) {
              y = (currCoord * y) + currCurve[b_k + 1];
            }
          }
          currPt[0] = y;
          currPt[1] = currCoord;
        }
        findClosestOnCurve(currPt, std::abs(currRad), currCurve, coordsToUse,
                           removedIdx, b_index);
        if (b_index.size(1) != 0) {
          int f_loop_ub;
          int i11;
          newIndices[j] = b_index[0];
          i11 = removedIdx.size(1);
          f_loop_ub = b_index.size(1);
          removedIdx.set_size(removedIdx.size(0),
                              removedIdx.size(1) + b_index.size(1));
          for (int i12{0}; i12 < f_loop_ub; i12++) {
            removedIdx[i11 + i12] = b_index[i12];
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
  array<double, 2U> b_index;
  array<double, 2U> b_this;
  array<double, 2U> c_this;
  array<double, 2U> currCurve;
  array<double, 2U> removedIdx;
  array<double, 1U> b_x;
  array<double, 1U> c_x;
  array<int, 2U> c_ii;
  array<int, 1U> r2;
  array<int, 1U> r3;
  array<int, 1U> r4;
  array<int, 1U> r5;
  array<bool, 1U> r;
  array<bool, 1U> r1;
  double coordsToUse[2];
  double currPt[2];
  double dv[2];
  double b_y;
  double y;
  int b_end;
  int b_idx_tmp;
  int b_loop_ub;
  int b_partialTrueCount;
  int b_trueCount;
  int c_end;
  int c_loop_ub;
  int c_partialTrueCount;
  int c_trueCount;
  int d_end;
  int d_loop_ub;
  int d_partialTrueCount;
  int d_trueCount;
  int end;
  int i5;
  int idx_tmp;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  int unnamed_idx_1;
  idx_tmp = static_cast<int>(idx[0]);
  loop_ub = BoardIdx.size(0);
  r.set_size(loop_ub);
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    r[b_i] = (BoardIdx[b_i + (BoardIdx.size(0) * (idx_tmp - 1))] > 0.0);
  }
  b_idx_tmp = static_cast<int>(idx[1]);
  b_loop_ub = BoardIdx.size(0);
  r1.set_size(b_loop_ub);
  for (int i1{0}; i1 < b_loop_ub; i1++) {
    r1[i1] = (BoardIdx[i1 + (BoardIdx.size(0) * (b_idx_tmp - 1))] > 0.0);
  }
  end = r.size(0) - 1;
  trueCount = 0;
  for (int c_i{0}; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      trueCount++;
    }
  }
  r2.set_size(trueCount);
  partialTrueCount = 0;
  for (int d_i{0}; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      r2[partialTrueCount] = d_i + 1;
      partialTrueCount++;
    }
  }
  b_end = r.size(0) - 1;
  b_trueCount = 0;
  for (int e_i{0}; e_i <= b_end; e_i++) {
    if ((r[e_i]) && (r1[e_i])) {
      b_trueCount++;
    }
  }
  r3.set_size(b_trueCount);
  b_partialTrueCount = 0;
  for (int g_i{0}; g_i <= b_end; g_i++) {
    if ((r[g_i]) && (r1[g_i])) {
      r3[b_partialTrueCount] = g_i + 1;
      b_partialTrueCount++;
    }
  }
  b_x.set_size(r2.size(0));
  c_loop_ub = r2.size(0);
  for (int i2{0}; i2 < c_loop_ub; i2++) {
    b_x[i2] =
        BoardCoords[(r2[i2] + (BoardCoords.size(0) * (b_idx_tmp - 1))) - 1] -
        BoardCoords[(r3[i2] + (BoardCoords.size(0) * (idx_tmp - 1))) - 1];
  }
  c_end = r.size(0) - 1;
  c_trueCount = 0;
  for (int h_i{0}; h_i <= c_end; h_i++) {
    if ((r[h_i]) && (r1[h_i])) {
      c_trueCount++;
    }
  }
  r4.set_size(c_trueCount);
  c_partialTrueCount = 0;
  for (int o_i{0}; o_i <= c_end; o_i++) {
    if ((r[o_i]) && (r1[o_i])) {
      r4[c_partialTrueCount] = o_i + 1;
      c_partialTrueCount++;
    }
  }
  d_end = r.size(0) - 1;
  d_trueCount = 0;
  for (int q_i{0}; q_i <= d_end; q_i++) {
    if ((r[q_i]) && (r1[q_i])) {
      d_trueCount++;
    }
  }
  r5.set_size(d_trueCount);
  d_partialTrueCount = 0;
  for (int w_i{0}; w_i <= d_end; w_i++) {
    if ((r[w_i]) && (r1[w_i])) {
      r5[d_partialTrueCount] = w_i + 1;
      d_partialTrueCount++;
    }
  }
  c_x.set_size(r4.size(0));
  d_loop_ub = r4.size(0);
  for (int i3{0}; i3 < d_loop_ub; i3++) {
    c_x[i3] = BoardCoords[((r4[i3] + (BoardCoords.size(0) * (b_idx_tmp - 1))) +
                           (BoardCoords.size(0) * BoardCoords.size(1))) -
                          1] -
              BoardCoords[((r5[i3] + (BoardCoords.size(0) * (idx_tmp - 1))) +
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
  unnamed_idx_1 = BoardCoords.size(0);
  newIndices.set_size(1, unnamed_idx_1);
  for (int i4{0}; i4 < unnamed_idx_1; i4++) {
    newIndices[i4] = 0.0;
  }
  removedIdx.set_size(1, 0);
  i5 = BoardCoords.size(0);
  for (int j{0}; j < i5; j++) {
    int e_loop_ub;
    e_loop_ub = BoardCoords.size(1);
    b_this.set_size(1, e_loop_ub);
    for (int i6{0}; i6 < e_loop_ub; i6++) {
      b_this[i6] = BoardCoords[(j + (BoardCoords.size(0) * i6)) +
                               ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                ((static_cast<int>(coordsToUse[0])) - 1))];
    }
    b_eml_find(b_this, c_ii);
    if (c_ii.size(1) >= 2) {
      double coordDist;
      double currCoord;
      double currRad;
      double moveDistMultiplier;
      double refCoordValue;
      int c_n;
      int d_n;
      int firstValidIdx;
      int i8;
      int i9;
      bool exitg1;
      if (idx[0] == 1.0) {
        int i7;
        int moveDistMultiplier_tmp;
        moveDistMultiplier_tmp = c_ii[0];
        moveDistMultiplier = static_cast<double>(moveDistMultiplier_tmp);
        firstValidIdx = c_ii[0];
        i7 = static_cast<int>(coordsToUse[0]);
        i8 = i7;
        coordDist = (BoardCoords[(j + (BoardCoords.size(0) * (c_ii[0] - 1))) +
                                 ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                  (i7 - 1))] -
                     BoardCoords[(j + (BoardCoords.size(0) * (c_ii[1] - 1))) +
                                 ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                  (i7 - 1))]) /
                    ((static_cast<double>(c_ii[1])) -
                     (static_cast<double>(moveDistMultiplier_tmp)));
      } else {
        int i7;
        moveDistMultiplier = ((static_cast<double>(BoardCoords.size(1))) -
                              (static_cast<double>(c_ii[c_ii.size(1) - 1]))) +
                             1.0;
        firstValidIdx = c_ii[c_ii.size(1) - 1];
        i7 = static_cast<int>(coordsToUse[0]);
        i8 = i7;
        coordDist =
            (BoardCoords
                 [(j + (BoardCoords.size(0) * (c_ii[c_ii.size(1) - 1] - 1))) +
                  ((BoardCoords.size(0) * BoardCoords.size(1)) * (i7 - 1))] -
             BoardCoords
                 [(j + (BoardCoords.size(0) * (c_ii[c_ii.size(1) - 2] - 1))) +
                  ((BoardCoords.size(0) * BoardCoords.size(1)) * (i7 - 1))]) /
            ((static_cast<double>(c_ii[c_ii.size(1) - 1])) -
             (static_cast<double>(c_ii[c_ii.size(1) - 2])));
      }
      c_n = 0;
      i9 = c_ii.size(1);
      b_this.set_size(1, c_ii.size(1));
      c_this.set_size(1, c_ii.size(1));
      for (int k{0}; k < i9; k++) {
        if (c_ii[k] != 0) {
          c_n++;
        }
        b_this[k] = BoardCoords[(j + (BoardCoords.size(0) * (c_ii[k] - 1))) +
                                ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                 (i8 - 1))];
        c_this[k] = BoardCoords[(j + (BoardCoords.size(0) * (c_ii[k] - 1))) +
                                ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                 ((static_cast<int>(coordsToUse[1])) - 1))];
      }
      if (c_n > 5) {
        d_n = 4;
      } else {
        d_n = 2;
      }
      b_polyfit(b_this, c_this, static_cast<double>(d_n), currCurve);
      currRad = coordDist / 4.0;
      refCoordValue =
          BoardCoords[(j + (BoardCoords.size(0) * (firstValidIdx - 1))) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) *
                       ((static_cast<int>(coordsToUse[0])) - 1))];
      currCoord = currRad + refCoordValue;
      exitg1 = false;
      while ((!exitg1) &&
             (std::abs(currCoord - refCoordValue) <
              ((moveDistMultiplier * 1.5) * std::abs(coordDist)))) {
        dv[0] = 1.0;
        dv[1] = 2.0;
        if (isequal(coordsToUse, dv)) {
          if (currCurve.size(1) != 0) {
            int i11;
            b_y = currCurve[0];
            i11 = currCurve.size(1);
            for (int c_k{0}; c_k <= (i11 - 2); c_k++) {
              b_y = (currCoord * b_y) + currCurve[c_k + 1];
            }
          }
          currPt[0] = currCoord;
          currPt[1] = b_y;
        } else {
          if (currCurve.size(1) != 0) {
            int i10;
            y = currCurve[0];
            i10 = currCurve.size(1);
            for (int b_k{0}; b_k <= (i10 - 2); b_k++) {
              y = (currCoord * y) + currCurve[b_k + 1];
            }
          }
          currPt[0] = y;
          currPt[1] = currCoord;
        }
        findClosestOnCurve(currPt, std::abs(currRad), currCurve, coordsToUse,
                           removedIdx, b_index);
        if (b_index.size(1) != 0) {
          int f_loop_ub;
          int i12;
          newIndices[j] = b_index[0];
          i12 = removedIdx.size(1);
          f_loop_ub = b_index.size(1);
          removedIdx.set_size(removedIdx.size(0),
                              removedIdx.size(1) + b_index.size(1));
          for (int i13{0}; i13 < f_loop_ub; i13++) {
            removedIdx[i12 + i13] = b_index[i13];
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
  array<double, 3U> c_this;
  array<double, 3U> denom;
  array<double, 3U> num;
  array<double, 2U> e_denom;
  array<double, 2U> f_num;
  array<double, 2U> validNewColIdx;
  array<double, 1U> b_y;
  array<double, 1U> c_x;
  array<double, 1U> f_denom;
  array<double, 1U> g_denom;
  array<double, 1U> g_num;
  array<double, 1U> h_num;
  array<int, 1U> r2;
  array<int, 1U> r3;
  array<int, 1U> r4;
  array<int, 1U> r5;
  array<int, 1U> r6;
  array<bool, 2U> b_this;
  array<bool, 1U> b_x;
  array<bool, 1U> r;
  array<bool, 1U> r1;
  float newEnergy;
  int b_loop_ub;
  int c_loop_ub;
  int d_loop_ub;
  int k;
  int loop_ub;
  bool exitg1;
  bool y;
  loop_ub = BoardIdx.size(0);
  r.set_size(loop_ub);
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    r[b_i] =
        ((BoardIdx[b_i] > 0.0) && (BoardIdx[b_i + BoardIdx.size(0)] > 0.0));
  }
  b_loop_ub = BoardIdx.size(0);
  r1.set_size(b_loop_ub);
  for (int i1{0}; i1 < b_loop_ub; i1++) {
    r1[i1] = (BoardIdx[i1 + (BoardIdx.size(0) * 2)] > 0.0);
  }
  newEnergy = 0.0F;
  b_x.set_size(r.size(0));
  c_loop_ub = r.size(0);
  for (int i2{0}; i2 < c_loop_ub; i2++) {
    b_x[i2] = ((r[i2]) && (r1[i2]));
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
    int b_end;
    int b_partialTrueCount;
    int b_trueCount;
    int c_end;
    int c_partialTrueCount;
    int c_trueCount;
    int d_end;
    int d_partialTrueCount;
    int d_trueCount;
    int e_end;
    int e_partialTrueCount;
    int e_trueCount;
    int end;
    int g_loop_ub;
    int i_loop_ub;
    int partialTrueCount;
    int trueCount;
    end = r.size(0) - 1;
    trueCount = 0;
    for (int c_i{0}; c_i <= end; c_i++) {
      if ((r[c_i]) && (r1[c_i])) {
        trueCount++;
      }
    }
    r2.set_size(trueCount);
    partialTrueCount = 0;
    for (int d_i{0}; d_i <= end; d_i++) {
      if ((r[d_i]) && (r1[d_i])) {
        r2[partialTrueCount] = d_i + 1;
        partialTrueCount++;
      }
    }
    b_end = r.size(0) - 1;
    b_trueCount = 0;
    for (int g_i{0}; g_i <= b_end; g_i++) {
      if ((r[g_i]) && (r1[g_i])) {
        b_trueCount++;
      }
    }
    r3.set_size(b_trueCount);
    b_partialTrueCount = 0;
    for (int h_i{0}; h_i <= b_end; h_i++) {
      if ((r[h_i]) && (r1[h_i])) {
        r3[b_partialTrueCount] = h_i + 1;
        b_partialTrueCount++;
      }
    }
    c_end = r.size(0) - 1;
    c_trueCount = 0;
    for (int o_i{0}; o_i <= c_end; o_i++) {
      if ((r[o_i]) && (r1[o_i])) {
        c_trueCount++;
      }
    }
    r4.set_size(c_trueCount);
    c_partialTrueCount = 0;
    for (int q_i{0}; q_i <= c_end; q_i++) {
      if ((r[q_i]) && (r1[q_i])) {
        r4[c_partialTrueCount] = q_i + 1;
        c_partialTrueCount++;
      }
    }
    g_loop_ub = BoardCoords.size(2);
    c_this.set_size(r2.size(0), 1, g_loop_ub);
    for (int i7{0}; i7 < g_loop_ub; i7++) {
      int h_loop_ub;
      h_loop_ub = r2.size(0);
      for (int i8{0}; i8 < h_loop_ub; i8++) {
        c_this[i8 + (c_this.size(0) * i7)] =
            (BoardCoords[(r2[i8] +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * i7)) -
                         1] +
             BoardCoords[((r3[i8] + (BoardCoords.size(0) * 2)) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * i7)) -
                         1]) -
            (2.0 *
             BoardCoords[((r4[i8] + BoardCoords.size(0)) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * i7)) -
                         1]);
      }
    }
    b_squeeze(c_this, f_num);
    d_end = r.size(0) - 1;
    d_trueCount = 0;
    for (int w_i{0}; w_i <= d_end; w_i++) {
      if ((r[w_i]) && (r1[w_i])) {
        d_trueCount++;
      }
    }
    r5.set_size(d_trueCount);
    d_partialTrueCount = 0;
    for (int ab_i{0}; ab_i <= d_end; ab_i++) {
      if ((r[ab_i]) && (r1[ab_i])) {
        r5[d_partialTrueCount] = ab_i + 1;
        d_partialTrueCount++;
      }
    }
    e_end = r.size(0) - 1;
    e_trueCount = 0;
    for (int cb_i{0}; cb_i <= e_end; cb_i++) {
      if ((r[cb_i]) && (r1[cb_i])) {
        e_trueCount++;
      }
    }
    r6.set_size(e_trueCount);
    e_partialTrueCount = 0;
    for (int db_i{0}; db_i <= e_end; db_i++) {
      if ((r[db_i]) && (r1[db_i])) {
        r6[e_partialTrueCount] = db_i + 1;
        e_partialTrueCount++;
      }
    }
    i_loop_ub = BoardCoords.size(2);
    c_this.set_size(r5.size(0), 1, i_loop_ub);
    for (int i9{0}; i9 < i_loop_ub; i9++) {
      int j_loop_ub;
      j_loop_ub = r5.size(0);
      for (int i10{0}; i10 < j_loop_ub; i10++) {
        c_this[i10 + (c_this.size(0) * i9)] =
            BoardCoords[(r5[i10] +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * i9)) -
                        1] -
            BoardCoords[((r6[i10] + (BoardCoords.size(0) * 2)) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * i9)) -
                        1];
      }
    }
    b_squeeze(c_this, e_denom);
    if (f_num.size(1) > 1) {
      int b_csz_idx_0;
      int b_u0;
      int b_u1;
      int csz_idx_0;
      int k_loop_ub;
      int m_loop_ub;
      int o_loop_ub;
      int p_loop_ub;
      int q_loop_ub;
      int u0;
      int u1;
      k_loop_ub = f_num.size(0);
      g_num.set_size(f_num.size(0));
      for (int i11{0}; i11 < k_loop_ub; i11++) {
        g_num[i11] = f_num[i11];
      }
      m_loop_ub = f_num.size(0);
      h_num.set_size(f_num.size(0));
      for (int i12{0}; i12 < m_loop_ub; i12++) {
        h_num[i12] = f_num[i12 + f_num.size(0)];
      }
      u0 = g_num.size(0);
      u1 = h_num.size(0);
      if (u0 <= u1) {
        csz_idx_0 = u0;
      } else {
        csz_idx_0 = u1;
      }
      c_x.set_size(csz_idx_0);
      for (int b_k{0}; b_k < csz_idx_0; b_k++) {
        c_x[b_k] = rt_hypotd_snf(g_num[b_k], h_num[b_k]);
      }
      o_loop_ub = e_denom.size(0);
      f_denom.set_size(e_denom.size(0));
      for (int i13{0}; i13 < o_loop_ub; i13++) {
        f_denom[i13] = e_denom[i13];
      }
      p_loop_ub = e_denom.size(0);
      g_denom.set_size(e_denom.size(0));
      for (int i14{0}; i14 < p_loop_ub; i14++) {
        g_denom[i14] = e_denom[i14 + e_denom.size(0)];
      }
      b_u0 = f_denom.size(0);
      b_u1 = g_denom.size(0);
      if (b_u0 <= b_u1) {
        b_csz_idx_0 = b_u0;
      } else {
        b_csz_idx_0 = b_u1;
      }
      b_y.set_size(b_csz_idx_0);
      for (int c_k{0}; c_k < b_csz_idx_0; c_k++) {
        b_y[c_k] = rt_hypotd_snf(f_denom[c_k], g_denom[c_k]);
      }
      q_loop_ub = c_x.size(0);
      for (int i15{0}; i15 < q_loop_ub; i15++) {
        c_x[i15] = c_x[i15] / b_y[i15];
      }
      newEnergy = std::fmax(
          oldEnergy, static_cast<float>(::coder::internal::b_maximum(c_x)));
    } else {
      newEnergy =
          std::fmax(oldEnergy, static_cast<float>(static_cast<double>(
                                   rt_hypotd_snf(f_num[0], f_num[1]) /
                                   rt_hypotd_snf(e_denom[0], e_denom[1]))));
    }
  }
  d_loop_ub = BoardIdx.size(0);
  b_this.set_size(1, d_loop_ub);
  for (int i3{0}; i3 < d_loop_ub; i3++) {
    b_this[i3] = (BoardIdx[i3] > 0.0);
  }
  b_Checkerboard::arrayFind(b_this, validNewColIdx);
  if (validNewColIdx.size(1) != 0) {
    int i4;
    i4 = validNewColIdx.size(1);
    for (int e_i{0}; e_i < i4; e_i++) {
      double b_d1;
      double d;
      int e_loop_ub;
      int f_loop_ub;
      d = validNewColIdx[e_i];
      e_loop_ub = BoardCoords.size(2);
      num.set_size(1, 1, e_loop_ub);
      for (int i5{0}; i5 < e_loop_ub; i5++) {
        num[i5] =
            (BoardCoords[((static_cast<int>(d)) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * i5)) -
                         1] +
             BoardCoords[((static_cast<int>(static_cast<double>(d + 2.0))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * i5)) -
                         1]) -
            (2.0 *
             BoardCoords[((static_cast<int>(static_cast<double>(d + 1.0))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * i5)) -
                         1]);
      }
      b_d1 = validNewColIdx[e_i];
      f_loop_ub = BoardCoords.size(2);
      denom.set_size(1, 1, f_loop_ub);
      for (int i6{0}; i6 < f_loop_ub; i6++) {
        denom[i6] =
            BoardCoords[((static_cast<int>(b_d1)) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * i6)) -
                        1] -
            BoardCoords[((static_cast<int>(static_cast<double>(b_d1 + 2.0))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * i6)) -
                        1];
      }
      if (newEnergy != 0.0F) {
        array<double, 1U> d_denom;
        array<double, 1U> d_num;
        int b_denom;
        int b_num;
        b_num = num.size(2);
        b_denom = denom.size(2);
        d_num = num.reshape(b_num);
        d_denom = denom.reshape(b_denom);
        newEnergy = std::fmax(newEnergy, static_cast<float>(static_cast<double>(
                                             b_norm(d_num) / b_norm(d_denom))));
      } else {
        array<double, 1U> c_denom;
        array<double, 1U> c_num;
        int b_denom;
        int b_num;
        b_num = num.size(2);
        b_denom = denom.size(2);
        c_num = num.reshape(b_num);
        c_denom = denom.reshape(b_denom);
        newEnergy = std::fmax(oldEnergy, static_cast<float>(static_cast<double>(
                                             b_norm(c_num) / b_norm(c_denom))));
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
  array<double, 3U> c_this;
  array<double, 3U> denom;
  array<double, 3U> num;
  array<double, 2U> e_denom;
  array<double, 2U> f_num;
  array<double, 2U> validNewColIdx;
  array<double, 1U> b_y;
  array<double, 1U> c_x;
  array<double, 1U> f_denom;
  array<double, 1U> g_denom;
  array<double, 1U> g_num;
  array<double, 1U> h_num;
  array<int, 1U> r2;
  array<int, 1U> r3;
  array<int, 1U> r4;
  array<int, 1U> r5;
  array<int, 1U> r6;
  array<bool, 2U> b_this;
  array<bool, 1U> b_x;
  array<bool, 1U> r;
  array<bool, 1U> r1;
  float newEnergy;
  int b_idx_tmp;
  int b_loop_ub;
  int c_idx_tmp;
  int c_loop_ub;
  int d_loop_ub;
  int idx_tmp;
  int k;
  int loop_ub;
  bool exitg1;
  bool y;
  idx_tmp = static_cast<int>(idx[0]);
  b_idx_tmp = static_cast<int>(idx[1]);
  loop_ub = BoardIdx.size(0);
  r.set_size(loop_ub);
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    r[b_i] = ((BoardIdx[b_i + (BoardIdx.size(0) * (idx_tmp - 1))] > 0.0) &&
              (BoardIdx[b_i + (BoardIdx.size(0) * (b_idx_tmp - 1))] > 0.0));
  }
  c_idx_tmp = static_cast<int>(idx[2]);
  b_loop_ub = BoardIdx.size(0);
  r1.set_size(b_loop_ub);
  for (int i1{0}; i1 < b_loop_ub; i1++) {
    r1[i1] = (BoardIdx[i1 + (BoardIdx.size(0) * (c_idx_tmp - 1))] > 0.0);
  }
  newEnergy = 0.0F;
  b_x.set_size(r.size(0));
  c_loop_ub = r.size(0);
  for (int i2{0}; i2 < c_loop_ub; i2++) {
    b_x[i2] = ((r[i2]) && (r1[i2]));
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
    int b_end;
    int b_partialTrueCount;
    int b_trueCount;
    int c_end;
    int c_partialTrueCount;
    int c_trueCount;
    int d_end;
    int d_partialTrueCount;
    int d_trueCount;
    int e_end;
    int e_partialTrueCount;
    int e_trueCount;
    int end;
    int g_loop_ub;
    int i_loop_ub;
    int partialTrueCount;
    int trueCount;
    end = r.size(0) - 1;
    trueCount = 0;
    for (int c_i{0}; c_i <= end; c_i++) {
      if ((r[c_i]) && (r1[c_i])) {
        trueCount++;
      }
    }
    r2.set_size(trueCount);
    partialTrueCount = 0;
    for (int d_i{0}; d_i <= end; d_i++) {
      if ((r[d_i]) && (r1[d_i])) {
        r2[partialTrueCount] = d_i + 1;
        partialTrueCount++;
      }
    }
    b_end = r.size(0) - 1;
    b_trueCount = 0;
    for (int g_i{0}; g_i <= b_end; g_i++) {
      if ((r[g_i]) && (r1[g_i])) {
        b_trueCount++;
      }
    }
    r3.set_size(b_trueCount);
    b_partialTrueCount = 0;
    for (int h_i{0}; h_i <= b_end; h_i++) {
      if ((r[h_i]) && (r1[h_i])) {
        r3[b_partialTrueCount] = h_i + 1;
        b_partialTrueCount++;
      }
    }
    c_end = r.size(0) - 1;
    c_trueCount = 0;
    for (int o_i{0}; o_i <= c_end; o_i++) {
      if ((r[o_i]) && (r1[o_i])) {
        c_trueCount++;
      }
    }
    r4.set_size(c_trueCount);
    c_partialTrueCount = 0;
    for (int q_i{0}; q_i <= c_end; q_i++) {
      if ((r[q_i]) && (r1[q_i])) {
        r4[c_partialTrueCount] = q_i + 1;
        c_partialTrueCount++;
      }
    }
    g_loop_ub = BoardCoords.size(2);
    c_this.set_size(r2.size(0), 1, g_loop_ub);
    for (int i7{0}; i7 < g_loop_ub; i7++) {
      int h_loop_ub;
      h_loop_ub = r2.size(0);
      for (int i8{0}; i8 < h_loop_ub; i8++) {
        c_this[i8 + (c_this.size(0) * i7)] =
            (BoardCoords[((r2[i8] + (BoardCoords.size(0) * (idx_tmp - 1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * i7)) -
                         1] +
             BoardCoords[((r3[i8] + (BoardCoords.size(0) * (c_idx_tmp - 1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * i7)) -
                         1]) -
            (2.0 *
             BoardCoords[((r4[i8] + (BoardCoords.size(0) * (b_idx_tmp - 1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * i7)) -
                         1]);
      }
    }
    b_squeeze(c_this, f_num);
    d_end = r.size(0) - 1;
    d_trueCount = 0;
    for (int w_i{0}; w_i <= d_end; w_i++) {
      if ((r[w_i]) && (r1[w_i])) {
        d_trueCount++;
      }
    }
    r5.set_size(d_trueCount);
    d_partialTrueCount = 0;
    for (int ab_i{0}; ab_i <= d_end; ab_i++) {
      if ((r[ab_i]) && (r1[ab_i])) {
        r5[d_partialTrueCount] = ab_i + 1;
        d_partialTrueCount++;
      }
    }
    e_end = r.size(0) - 1;
    e_trueCount = 0;
    for (int cb_i{0}; cb_i <= e_end; cb_i++) {
      if ((r[cb_i]) && (r1[cb_i])) {
        e_trueCount++;
      }
    }
    r6.set_size(e_trueCount);
    e_partialTrueCount = 0;
    for (int db_i{0}; db_i <= e_end; db_i++) {
      if ((r[db_i]) && (r1[db_i])) {
        r6[e_partialTrueCount] = db_i + 1;
        e_partialTrueCount++;
      }
    }
    i_loop_ub = BoardCoords.size(2);
    c_this.set_size(r5.size(0), 1, i_loop_ub);
    for (int i9{0}; i9 < i_loop_ub; i9++) {
      int j_loop_ub;
      j_loop_ub = r5.size(0);
      for (int i10{0}; i10 < j_loop_ub; i10++) {
        c_this[i10 + (c_this.size(0) * i9)] =
            BoardCoords[((r5[i10] + (BoardCoords.size(0) * (idx_tmp - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * i9)) -
                        1] -
            BoardCoords[((r6[i10] + (BoardCoords.size(0) * (c_idx_tmp - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * i9)) -
                        1];
      }
    }
    b_squeeze(c_this, e_denom);
    if (f_num.size(1) > 1) {
      int b_csz_idx_0;
      int b_u0;
      int b_u1;
      int csz_idx_0;
      int k_loop_ub;
      int m_loop_ub;
      int o_loop_ub;
      int p_loop_ub;
      int q_loop_ub;
      int u0;
      int u1;
      k_loop_ub = f_num.size(0);
      g_num.set_size(f_num.size(0));
      for (int i11{0}; i11 < k_loop_ub; i11++) {
        g_num[i11] = f_num[i11];
      }
      m_loop_ub = f_num.size(0);
      h_num.set_size(f_num.size(0));
      for (int i12{0}; i12 < m_loop_ub; i12++) {
        h_num[i12] = f_num[i12 + f_num.size(0)];
      }
      u0 = g_num.size(0);
      u1 = h_num.size(0);
      if (u0 <= u1) {
        csz_idx_0 = u0;
      } else {
        csz_idx_0 = u1;
      }
      c_x.set_size(csz_idx_0);
      for (int b_k{0}; b_k < csz_idx_0; b_k++) {
        c_x[b_k] = rt_hypotd_snf(g_num[b_k], h_num[b_k]);
      }
      o_loop_ub = e_denom.size(0);
      f_denom.set_size(e_denom.size(0));
      for (int i13{0}; i13 < o_loop_ub; i13++) {
        f_denom[i13] = e_denom[i13];
      }
      p_loop_ub = e_denom.size(0);
      g_denom.set_size(e_denom.size(0));
      for (int i14{0}; i14 < p_loop_ub; i14++) {
        g_denom[i14] = e_denom[i14 + e_denom.size(0)];
      }
      b_u0 = f_denom.size(0);
      b_u1 = g_denom.size(0);
      if (b_u0 <= b_u1) {
        b_csz_idx_0 = b_u0;
      } else {
        b_csz_idx_0 = b_u1;
      }
      b_y.set_size(b_csz_idx_0);
      for (int c_k{0}; c_k < b_csz_idx_0; c_k++) {
        b_y[c_k] = rt_hypotd_snf(f_denom[c_k], g_denom[c_k]);
      }
      q_loop_ub = c_x.size(0);
      for (int i15{0}; i15 < q_loop_ub; i15++) {
        c_x[i15] = c_x[i15] / b_y[i15];
      }
      newEnergy = std::fmax(
          oldEnergy, static_cast<float>(::coder::internal::b_maximum(c_x)));
    } else {
      newEnergy =
          std::fmax(oldEnergy, static_cast<float>(static_cast<double>(
                                   rt_hypotd_snf(f_num[0], f_num[1]) /
                                   rt_hypotd_snf(e_denom[0], e_denom[1]))));
    }
  }
  d_loop_ub = BoardIdx.size(0);
  b_this.set_size(1, d_loop_ub);
  for (int i3{0}; i3 < d_loop_ub; i3++) {
    b_this[i3] = (BoardIdx[i3 + (BoardIdx.size(0) * (idx_tmp - 1))] > 0.0);
  }
  b_Checkerboard::arrayFind(b_this, validNewColIdx);
  if (validNewColIdx.size(1) != 0) {
    int i4;
    i4 = validNewColIdx.size(1);
    for (int e_i{0}; e_i < i4; e_i++) {
      double b_d1;
      double d;
      double d2;
      double d3;
      int e_loop_ub;
      int f_loop_ub;
      d = validNewColIdx[e_i];
      b_d1 = idx[0];
      e_loop_ub = BoardCoords.size(2);
      num.set_size(1, 1, e_loop_ub);
      for (int i5{0}; i5 < e_loop_ub; i5++) {
        num[i5] =
            (BoardCoords[(((static_cast<int>(d)) +
                           (BoardCoords.size(0) *
                            ((static_cast<int>(b_d1)) - 1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * i5)) -
                         1] +
             BoardCoords[(((static_cast<int>(static_cast<double>(d + 2.0))) +
                           (BoardCoords.size(0) *
                            ((static_cast<int>(b_d1)) - 1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * i5)) -
                         1]) -
            (2.0 *
             BoardCoords[(((static_cast<int>(static_cast<double>(d + 1.0))) +
                           (BoardCoords.size(0) *
                            ((static_cast<int>(b_d1)) - 1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * i5)) -
                         1]);
      }
      d2 = validNewColIdx[e_i];
      d3 = idx[0];
      f_loop_ub = BoardCoords.size(2);
      denom.set_size(1, 1, f_loop_ub);
      for (int i6{0}; i6 < f_loop_ub; i6++) {
        denom[i6] =
            BoardCoords[(((static_cast<int>(d2)) +
                          (BoardCoords.size(0) *
                           ((static_cast<int>(d3)) - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * i6)) -
                        1] -
            BoardCoords[(((static_cast<int>(static_cast<double>(d2 + 2.0))) +
                          (BoardCoords.size(0) *
                           ((static_cast<int>(d3)) - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * i6)) -
                        1];
      }
      if (newEnergy != 0.0F) {
        array<double, 1U> d_denom;
        array<double, 1U> d_num;
        int b_denom;
        int b_num;
        b_num = num.size(2);
        b_denom = denom.size(2);
        d_num = num.reshape(b_num);
        d_denom = denom.reshape(b_denom);
        newEnergy = std::fmax(newEnergy, static_cast<float>(static_cast<double>(
                                             b_norm(d_num) / b_norm(d_denom))));
      } else {
        array<double, 1U> c_denom;
        array<double, 1U> c_num;
        int b_denom;
        int b_num;
        b_num = num.size(2);
        b_denom = denom.size(2);
        c_num = num.reshape(b_num);
        c_denom = denom.reshape(b_denom);
        newEnergy = std::fmax(oldEnergy, static_cast<float>(static_cast<double>(
                                             b_norm(c_num) / b_norm(c_denom))));
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
  array<double, 3U> b;
  array<double, 3U> denom;
  array<double, 3U> num;
  array<double, 3U> r3;
  array<double, 3U> r5;
  array<double, 2U> e_denom;
  array<double, 2U> f_num;
  array<double, 2U> validNewRowIdx;
  array<double, 1U> b_y;
  array<double, 1U> c_x;
  array<double, 1U> f_denom;
  array<double, 1U> g_denom;
  array<double, 1U> g_num;
  array<double, 1U> h_num;
  array<int, 2U> r2;
  array<int, 2U> r4;
  array<int, 2U> r6;
  array<int, 2U> r7;
  array<int, 2U> r8;
  array<bool, 2U> b_this;
  array<bool, 2U> b_x;
  array<bool, 2U> r;
  array<bool, 2U> r1;
  float newEnergy;
  int b_loop_ub;
  int c_loop_ub;
  int d_loop_ub;
  int k;
  int loop_ub;
  bool exitg1;
  bool y;
  loop_ub = BoardIdx.size(1);
  r.set_size(1, loop_ub);
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    r[b_i] = ((BoardIdx[BoardIdx.size(0) * b_i] > 0.0) &&
              (BoardIdx[(BoardIdx.size(0) * b_i) + 1] > 0.0));
  }
  b_loop_ub = BoardIdx.size(1);
  r1.set_size(1, b_loop_ub);
  for (int i1{0}; i1 < b_loop_ub; i1++) {
    r1[i1] = (BoardIdx[(BoardIdx.size(0) * i1) + 2] > 0.0);
  }
  newEnergy = 0.0F;
  b_x.set_size(1, r.size(1));
  c_loop_ub = r.size(1);
  for (int i2{0}; i2 < c_loop_ub; i2++) {
    b_x[i2] = ((r[i2]) && (r1[i2]));
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
    int b_end;
    int b_partialTrueCount;
    int b_trueCount;
    int c_end;
    int c_partialTrueCount;
    int c_trueCount;
    int d_end;
    int d_partialTrueCount;
    int d_trueCount;
    int e_end;
    int e_loop_ub;
    int e_partialTrueCount;
    int e_trueCount;
    int end;
    int i_loop_ub;
    int k_loop_ub;
    int o_loop_ub;
    int partialTrueCount;
    int q_loop_ub;
    int s_loop_ub;
    int trueCount;
    int u_loop_ub;
    end = r.size(1) - 1;
    trueCount = 0;
    for (int c_i{0}; c_i <= end; c_i++) {
      if ((r[c_i]) && (r1[c_i])) {
        trueCount++;
      }
    }
    r2.set_size(1, trueCount);
    partialTrueCount = 0;
    for (int d_i{0}; d_i <= end; d_i++) {
      if ((r[d_i]) && (r1[d_i])) {
        r2[partialTrueCount] = d_i + 1;
        partialTrueCount++;
      }
    }
    e_loop_ub = BoardCoords.size(2);
    r3.set_size(1, r2.size(1), e_loop_ub);
    for (int i5{0}; i5 < e_loop_ub; i5++) {
      int g_loop_ub;
      g_loop_ub = r2.size(1);
      for (int i7{0}; i7 < g_loop_ub; i7++) {
        r3[i7 + (r3.size(1) * i5)] =
            BoardCoords[(BoardCoords.size(0) * (r2[i7] - 1)) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) * i5)];
      }
    }
    b_end = r.size(1) - 1;
    b_trueCount = 0;
    for (int g_i{0}; g_i <= b_end; g_i++) {
      if ((r[g_i]) && (r1[g_i])) {
        b_trueCount++;
      }
    }
    r4.set_size(1, b_trueCount);
    b_partialTrueCount = 0;
    for (int h_i{0}; h_i <= b_end; h_i++) {
      if ((r[h_i]) && (r1[h_i])) {
        r4[b_partialTrueCount] = h_i + 1;
        b_partialTrueCount++;
      }
    }
    i_loop_ub = BoardCoords.size(2);
    r5.set_size(1, r4.size(1), i_loop_ub);
    for (int i9{0}; i9 < i_loop_ub; i9++) {
      int j_loop_ub;
      j_loop_ub = r4.size(1);
      for (int i10{0}; i10 < j_loop_ub; i10++) {
        r5[i10 + (r5.size(1) * i9)] =
            BoardCoords[((BoardCoords.size(0) * (r4[i10] - 1)) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * i9)) +
                        2];
      }
    }
    c_end = r.size(1) - 1;
    c_trueCount = 0;
    for (int o_i{0}; o_i <= c_end; o_i++) {
      if ((r[o_i]) && (r1[o_i])) {
        c_trueCount++;
      }
    }
    r6.set_size(1, c_trueCount);
    c_partialTrueCount = 0;
    for (int q_i{0}; q_i <= c_end; q_i++) {
      if ((r[q_i]) && (r1[q_i])) {
        r6[c_partialTrueCount] = q_i + 1;
        c_partialTrueCount++;
      }
    }
    k_loop_ub = BoardCoords.size(2);
    b.set_size(1, r6.size(1), k_loop_ub);
    for (int i11{0}; i11 < k_loop_ub; i11++) {
      int m_loop_ub;
      m_loop_ub = r6.size(1);
      for (int i12{0}; i12 < m_loop_ub; i12++) {
        b[i12 + (b.size(1) * i11)] =
            BoardCoords[((BoardCoords.size(0) * (r6[i12] - 1)) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * i11)) +
                        1];
      }
    }
    r3.set_size(1, r3.size(1), r3.size(2));
    o_loop_ub = r3.size(2);
    for (int i13{0}; i13 < o_loop_ub; i13++) {
      int p_loop_ub;
      p_loop_ub = r3.size(1);
      for (int i14{0}; i14 < p_loop_ub; i14++) {
        r3[i14 + (r3.size(1) * i13)] =
            (r3[i14 + (r3.size(1) * i13)] + r5[i14 + (r5.size(1) * i13)]) -
            (2.0 * b[i14 + (b.size(1) * i13)]);
      }
    }
    squeeze(r3, f_num);
    d_end = r.size(1) - 1;
    d_trueCount = 0;
    for (int w_i{0}; w_i <= d_end; w_i++) {
      if ((r[w_i]) && (r1[w_i])) {
        d_trueCount++;
      }
    }
    r7.set_size(1, d_trueCount);
    d_partialTrueCount = 0;
    for (int ab_i{0}; ab_i <= d_end; ab_i++) {
      if ((r[ab_i]) && (r1[ab_i])) {
        r7[d_partialTrueCount] = ab_i + 1;
        d_partialTrueCount++;
      }
    }
    q_loop_ub = BoardCoords.size(2);
    r3.set_size(1, r7.size(1), q_loop_ub);
    for (int i15{0}; i15 < q_loop_ub; i15++) {
      int r_loop_ub;
      r_loop_ub = r7.size(1);
      for (int i16{0}; i16 < r_loop_ub; i16++) {
        r3[i16 + (r3.size(1) * i15)] =
            BoardCoords[(BoardCoords.size(0) * (r7[i16] - 1)) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) * i15)];
      }
    }
    e_end = r.size(1) - 1;
    e_trueCount = 0;
    for (int cb_i{0}; cb_i <= e_end; cb_i++) {
      if ((r[cb_i]) && (r1[cb_i])) {
        e_trueCount++;
      }
    }
    r8.set_size(1, e_trueCount);
    e_partialTrueCount = 0;
    for (int db_i{0}; db_i <= e_end; db_i++) {
      if ((r[db_i]) && (r1[db_i])) {
        r8[e_partialTrueCount] = db_i + 1;
        e_partialTrueCount++;
      }
    }
    s_loop_ub = BoardCoords.size(2);
    r5.set_size(1, r8.size(1), s_loop_ub);
    for (int i17{0}; i17 < s_loop_ub; i17++) {
      int t_loop_ub;
      t_loop_ub = r8.size(1);
      for (int i18{0}; i18 < t_loop_ub; i18++) {
        r5[i18 + (r5.size(1) * i17)] =
            BoardCoords[((BoardCoords.size(0) * (r8[i18] - 1)) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * i17)) +
                        2];
      }
    }
    r3.set_size(1, r3.size(1), r3.size(2));
    u_loop_ub = r3.size(2);
    for (int i19{0}; i19 < u_loop_ub; i19++) {
      int v_loop_ub;
      v_loop_ub = r3.size(1);
      for (int i20{0}; i20 < v_loop_ub; i20++) {
        r3[i20 + (r3.size(1) * i19)] =
            r3[i20 + (r3.size(1) * i19)] - r5[i20 + (r5.size(1) * i19)];
      }
    }
    squeeze(r3, e_denom);
    if (f_num.size(1) > 1) {
      int ab_loop_ub;
      int b_csz_idx_0;
      int b_u0;
      int b_u1;
      int bb_loop_ub;
      int csz_idx_0;
      int u0;
      int u1;
      int w_loop_ub;
      int x_loop_ub;
      int y_loop_ub;
      w_loop_ub = f_num.size(0);
      g_num.set_size(f_num.size(0));
      for (int i21{0}; i21 < w_loop_ub; i21++) {
        g_num[i21] = f_num[i21];
      }
      x_loop_ub = f_num.size(0);
      h_num.set_size(f_num.size(0));
      for (int i22{0}; i22 < x_loop_ub; i22++) {
        h_num[i22] = f_num[i22 + f_num.size(0)];
      }
      u0 = g_num.size(0);
      u1 = h_num.size(0);
      if (u0 <= u1) {
        csz_idx_0 = u0;
      } else {
        csz_idx_0 = u1;
      }
      c_x.set_size(csz_idx_0);
      for (int b_k{0}; b_k < csz_idx_0; b_k++) {
        c_x[b_k] = rt_hypotd_snf(g_num[b_k], h_num[b_k]);
      }
      y_loop_ub = e_denom.size(0);
      f_denom.set_size(e_denom.size(0));
      for (int i23{0}; i23 < y_loop_ub; i23++) {
        f_denom[i23] = e_denom[i23];
      }
      ab_loop_ub = e_denom.size(0);
      g_denom.set_size(e_denom.size(0));
      for (int i24{0}; i24 < ab_loop_ub; i24++) {
        g_denom[i24] = e_denom[i24 + e_denom.size(0)];
      }
      b_u0 = f_denom.size(0);
      b_u1 = g_denom.size(0);
      if (b_u0 <= b_u1) {
        b_csz_idx_0 = b_u0;
      } else {
        b_csz_idx_0 = b_u1;
      }
      b_y.set_size(b_csz_idx_0);
      for (int c_k{0}; c_k < b_csz_idx_0; c_k++) {
        b_y[c_k] = rt_hypotd_snf(f_denom[c_k], g_denom[c_k]);
      }
      bb_loop_ub = c_x.size(0);
      for (int i25{0}; i25 < bb_loop_ub; i25++) {
        c_x[i25] = c_x[i25] / b_y[i25];
      }
      newEnergy = std::fmax(
          oldEnergy, static_cast<float>(::coder::internal::b_maximum(c_x)));
    } else {
      newEnergy =
          std::fmax(oldEnergy, static_cast<float>(static_cast<double>(
                                   rt_hypotd_snf(f_num[0], f_num[1]) /
                                   rt_hypotd_snf(e_denom[0], e_denom[1]))));
    }
  }
  d_loop_ub = BoardIdx.size(1);
  b_this.set_size(1, d_loop_ub);
  for (int i3{0}; i3 < d_loop_ub; i3++) {
    b_this[i3] = (BoardIdx[BoardIdx.size(0) * i3] > 0.0);
  }
  b_Checkerboard::arrayFind(b_this, validNewRowIdx);
  if (validNewRowIdx.size(1) != 0) {
    int i4;
    i4 = validNewRowIdx.size(1);
    for (int e_i{0}; e_i < i4; e_i++) {
      double b_d1;
      double d;
      int f_loop_ub;
      int h_loop_ub;
      d = validNewRowIdx[e_i];
      f_loop_ub = BoardCoords.size(2);
      num.set_size(1, 1, f_loop_ub);
      for (int i6{0}; i6 < f_loop_ub; i6++) {
        num[i6] =
            (BoardCoords[(BoardCoords.size(0) * ((static_cast<int>(d)) - 1)) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * i6)] +
             BoardCoords[(BoardCoords.size(0) *
                          ((static_cast<int>(static_cast<double>(d + 2.0))) -
                           1)) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * i6)]) -
            (2.0 *
             BoardCoords[(BoardCoords.size(0) *
                          ((static_cast<int>(static_cast<double>(d + 1.0))) -
                           1)) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * i6)]);
      }
      b_d1 = validNewRowIdx[e_i];
      h_loop_ub = BoardCoords.size(2);
      denom.set_size(1, 1, h_loop_ub);
      for (int i8{0}; i8 < h_loop_ub; i8++) {
        denom[i8] =
            BoardCoords[(BoardCoords.size(0) * ((static_cast<int>(b_d1)) - 1)) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) * i8)] -
            BoardCoords[(BoardCoords.size(0) *
                         ((static_cast<int>(static_cast<double>(b_d1 + 2.0))) -
                          1)) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) * i8)];
      }
      if (newEnergy != 0.0F) {
        array<double, 1U> d_denom;
        array<double, 1U> d_num;
        int b_denom;
        int b_num;
        b_num = num.size(2);
        b_denom = denom.size(2);
        d_num = num.reshape(b_num);
        d_denom = denom.reshape(b_denom);
        newEnergy = std::fmax(newEnergy, static_cast<float>(static_cast<double>(
                                             b_norm(d_num) / b_norm(d_denom))));
      } else {
        array<double, 1U> c_denom;
        array<double, 1U> c_num;
        int b_denom;
        int b_num;
        b_num = num.size(2);
        b_denom = denom.size(2);
        c_num = num.reshape(b_num);
        c_denom = denom.reshape(b_denom);
        newEnergy = std::fmax(oldEnergy, static_cast<float>(static_cast<double>(
                                             b_norm(c_num) / b_norm(c_denom))));
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
  array<double, 3U> b;
  array<double, 3U> denom;
  array<double, 3U> num;
  array<double, 3U> r3;
  array<double, 3U> r5;
  array<double, 2U> e_denom;
  array<double, 2U> f_num;
  array<double, 2U> validNewRowIdx;
  array<double, 1U> b_y;
  array<double, 1U> c_x;
  array<double, 1U> f_denom;
  array<double, 1U> g_denom;
  array<double, 1U> g_num;
  array<double, 1U> h_num;
  array<int, 2U> r2;
  array<int, 2U> r4;
  array<int, 2U> r6;
  array<int, 2U> r7;
  array<int, 2U> r8;
  array<bool, 2U> b_this;
  array<bool, 2U> b_x;
  array<bool, 2U> r;
  array<bool, 2U> r1;
  float newEnergy;
  int b_idx_tmp;
  int b_loop_ub;
  int c_idx_tmp;
  int c_loop_ub;
  int d_loop_ub;
  int idx_tmp;
  int k;
  int loop_ub;
  bool exitg1;
  bool y;
  idx_tmp = static_cast<int>(idx[0]);
  b_idx_tmp = static_cast<int>(idx[1]);
  loop_ub = BoardIdx.size(1);
  r.set_size(1, loop_ub);
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    r[b_i] = ((BoardIdx[(idx_tmp + (BoardIdx.size(0) * b_i)) - 1] > 0.0) &&
              (BoardIdx[(b_idx_tmp + (BoardIdx.size(0) * b_i)) - 1] > 0.0));
  }
  c_idx_tmp = static_cast<int>(idx[2]);
  b_loop_ub = BoardIdx.size(1);
  r1.set_size(1, b_loop_ub);
  for (int i1{0}; i1 < b_loop_ub; i1++) {
    r1[i1] = (BoardIdx[(c_idx_tmp + (BoardIdx.size(0) * i1)) - 1] > 0.0);
  }
  newEnergy = 0.0F;
  b_x.set_size(1, r.size(1));
  c_loop_ub = r.size(1);
  for (int i2{0}; i2 < c_loop_ub; i2++) {
    b_x[i2] = ((r[i2]) && (r1[i2]));
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
    int b_end;
    int b_partialTrueCount;
    int b_trueCount;
    int c_end;
    int c_partialTrueCount;
    int c_trueCount;
    int d_end;
    int d_partialTrueCount;
    int d_trueCount;
    int e_end;
    int e_loop_ub;
    int e_partialTrueCount;
    int e_trueCount;
    int end;
    int i_loop_ub;
    int k_loop_ub;
    int o_loop_ub;
    int partialTrueCount;
    int q_loop_ub;
    int s_loop_ub;
    int trueCount;
    int u_loop_ub;
    end = r.size(1) - 1;
    trueCount = 0;
    for (int c_i{0}; c_i <= end; c_i++) {
      if ((r[c_i]) && (r1[c_i])) {
        trueCount++;
      }
    }
    r2.set_size(1, trueCount);
    partialTrueCount = 0;
    for (int d_i{0}; d_i <= end; d_i++) {
      if ((r[d_i]) && (r1[d_i])) {
        r2[partialTrueCount] = d_i + 1;
        partialTrueCount++;
      }
    }
    e_loop_ub = BoardCoords.size(2);
    r3.set_size(1, r2.size(1), e_loop_ub);
    for (int i5{0}; i5 < e_loop_ub; i5++) {
      int g_loop_ub;
      g_loop_ub = r2.size(1);
      for (int i6{0}; i6 < g_loop_ub; i6++) {
        r3[i6 + (r3.size(1) * i5)] =
            BoardCoords[((idx_tmp + (BoardCoords.size(0) * (r2[i6] - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * i5)) -
                        1];
      }
    }
    b_end = r.size(1) - 1;
    b_trueCount = 0;
    for (int g_i{0}; g_i <= b_end; g_i++) {
      if ((r[g_i]) && (r1[g_i])) {
        b_trueCount++;
      }
    }
    r4.set_size(1, b_trueCount);
    b_partialTrueCount = 0;
    for (int h_i{0}; h_i <= b_end; h_i++) {
      if ((r[h_i]) && (r1[h_i])) {
        r4[b_partialTrueCount] = h_i + 1;
        b_partialTrueCount++;
      }
    }
    i_loop_ub = BoardCoords.size(2);
    r5.set_size(1, r4.size(1), i_loop_ub);
    for (int i9{0}; i9 < i_loop_ub; i9++) {
      int j_loop_ub;
      j_loop_ub = r4.size(1);
      for (int i10{0}; i10 < j_loop_ub; i10++) {
        r5[i10 + (r5.size(1) * i9)] =
            BoardCoords[((c_idx_tmp + (BoardCoords.size(0) * (r4[i10] - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * i9)) -
                        1];
      }
    }
    c_end = r.size(1) - 1;
    c_trueCount = 0;
    for (int o_i{0}; o_i <= c_end; o_i++) {
      if ((r[o_i]) && (r1[o_i])) {
        c_trueCount++;
      }
    }
    r6.set_size(1, c_trueCount);
    c_partialTrueCount = 0;
    for (int q_i{0}; q_i <= c_end; q_i++) {
      if ((r[q_i]) && (r1[q_i])) {
        r6[c_partialTrueCount] = q_i + 1;
        c_partialTrueCount++;
      }
    }
    k_loop_ub = BoardCoords.size(2);
    b.set_size(1, r6.size(1), k_loop_ub);
    for (int i11{0}; i11 < k_loop_ub; i11++) {
      int m_loop_ub;
      m_loop_ub = r6.size(1);
      for (int i12{0}; i12 < m_loop_ub; i12++) {
        b[i12 + (b.size(1) * i11)] =
            BoardCoords[((b_idx_tmp + (BoardCoords.size(0) * (r6[i12] - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * i11)) -
                        1];
      }
    }
    r3.set_size(1, r3.size(1), r3.size(2));
    o_loop_ub = r3.size(2);
    for (int i13{0}; i13 < o_loop_ub; i13++) {
      int p_loop_ub;
      p_loop_ub = r3.size(1);
      for (int i14{0}; i14 < p_loop_ub; i14++) {
        r3[i14 + (r3.size(1) * i13)] =
            (r3[i14 + (r3.size(1) * i13)] + r5[i14 + (r5.size(1) * i13)]) -
            (2.0 * b[i14 + (b.size(1) * i13)]);
      }
    }
    squeeze(r3, f_num);
    d_end = r.size(1) - 1;
    d_trueCount = 0;
    for (int w_i{0}; w_i <= d_end; w_i++) {
      if ((r[w_i]) && (r1[w_i])) {
        d_trueCount++;
      }
    }
    r7.set_size(1, d_trueCount);
    d_partialTrueCount = 0;
    for (int ab_i{0}; ab_i <= d_end; ab_i++) {
      if ((r[ab_i]) && (r1[ab_i])) {
        r7[d_partialTrueCount] = ab_i + 1;
        d_partialTrueCount++;
      }
    }
    q_loop_ub = BoardCoords.size(2);
    r3.set_size(1, r7.size(1), q_loop_ub);
    for (int i15{0}; i15 < q_loop_ub; i15++) {
      int r_loop_ub;
      r_loop_ub = r7.size(1);
      for (int i16{0}; i16 < r_loop_ub; i16++) {
        r3[i16 + (r3.size(1) * i15)] =
            BoardCoords[((idx_tmp + (BoardCoords.size(0) * (r7[i16] - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * i15)) -
                        1];
      }
    }
    e_end = r.size(1) - 1;
    e_trueCount = 0;
    for (int cb_i{0}; cb_i <= e_end; cb_i++) {
      if ((r[cb_i]) && (r1[cb_i])) {
        e_trueCount++;
      }
    }
    r8.set_size(1, e_trueCount);
    e_partialTrueCount = 0;
    for (int db_i{0}; db_i <= e_end; db_i++) {
      if ((r[db_i]) && (r1[db_i])) {
        r8[e_partialTrueCount] = db_i + 1;
        e_partialTrueCount++;
      }
    }
    s_loop_ub = BoardCoords.size(2);
    r5.set_size(1, r8.size(1), s_loop_ub);
    for (int i17{0}; i17 < s_loop_ub; i17++) {
      int t_loop_ub;
      t_loop_ub = r8.size(1);
      for (int i18{0}; i18 < t_loop_ub; i18++) {
        r5[i18 + (r5.size(1) * i17)] =
            BoardCoords[((c_idx_tmp + (BoardCoords.size(0) * (r8[i18] - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * i17)) -
                        1];
      }
    }
    r3.set_size(1, r3.size(1), r3.size(2));
    u_loop_ub = r3.size(2);
    for (int i19{0}; i19 < u_loop_ub; i19++) {
      int v_loop_ub;
      v_loop_ub = r3.size(1);
      for (int i20{0}; i20 < v_loop_ub; i20++) {
        r3[i20 + (r3.size(1) * i19)] =
            r3[i20 + (r3.size(1) * i19)] - r5[i20 + (r5.size(1) * i19)];
      }
    }
    squeeze(r3, e_denom);
    if (f_num.size(1) > 1) {
      int ab_loop_ub;
      int b_csz_idx_0;
      int b_u0;
      int b_u1;
      int bb_loop_ub;
      int csz_idx_0;
      int u0;
      int u1;
      int w_loop_ub;
      int x_loop_ub;
      int y_loop_ub;
      w_loop_ub = f_num.size(0);
      g_num.set_size(f_num.size(0));
      for (int i21{0}; i21 < w_loop_ub; i21++) {
        g_num[i21] = f_num[i21];
      }
      x_loop_ub = f_num.size(0);
      h_num.set_size(f_num.size(0));
      for (int i22{0}; i22 < x_loop_ub; i22++) {
        h_num[i22] = f_num[i22 + f_num.size(0)];
      }
      u0 = g_num.size(0);
      u1 = h_num.size(0);
      if (u0 <= u1) {
        csz_idx_0 = u0;
      } else {
        csz_idx_0 = u1;
      }
      c_x.set_size(csz_idx_0);
      for (int b_k{0}; b_k < csz_idx_0; b_k++) {
        c_x[b_k] = rt_hypotd_snf(g_num[b_k], h_num[b_k]);
      }
      y_loop_ub = e_denom.size(0);
      f_denom.set_size(e_denom.size(0));
      for (int i23{0}; i23 < y_loop_ub; i23++) {
        f_denom[i23] = e_denom[i23];
      }
      ab_loop_ub = e_denom.size(0);
      g_denom.set_size(e_denom.size(0));
      for (int i24{0}; i24 < ab_loop_ub; i24++) {
        g_denom[i24] = e_denom[i24 + e_denom.size(0)];
      }
      b_u0 = f_denom.size(0);
      b_u1 = g_denom.size(0);
      if (b_u0 <= b_u1) {
        b_csz_idx_0 = b_u0;
      } else {
        b_csz_idx_0 = b_u1;
      }
      b_y.set_size(b_csz_idx_0);
      for (int c_k{0}; c_k < b_csz_idx_0; c_k++) {
        b_y[c_k] = rt_hypotd_snf(f_denom[c_k], g_denom[c_k]);
      }
      bb_loop_ub = c_x.size(0);
      for (int i25{0}; i25 < bb_loop_ub; i25++) {
        c_x[i25] = c_x[i25] / b_y[i25];
      }
      newEnergy = std::fmax(
          oldEnergy, static_cast<float>(::coder::internal::b_maximum(c_x)));
    } else {
      newEnergy =
          std::fmax(oldEnergy, static_cast<float>(static_cast<double>(
                                   rt_hypotd_snf(f_num[0], f_num[1]) /
                                   rt_hypotd_snf(e_denom[0], e_denom[1]))));
    }
  }
  d_loop_ub = BoardIdx.size(1);
  b_this.set_size(1, d_loop_ub);
  for (int i3{0}; i3 < d_loop_ub; i3++) {
    b_this[i3] = (BoardIdx[(idx_tmp + (BoardIdx.size(0) * i3)) - 1] > 0.0);
  }
  b_Checkerboard::arrayFind(b_this, validNewRowIdx);
  if (validNewRowIdx.size(1) != 0) {
    int i4;
    i4 = validNewRowIdx.size(1);
    for (int e_i{0}; e_i < i4; e_i++) {
      double b_d1;
      double d;
      double d2;
      double d3;
      int f_loop_ub;
      int h_loop_ub;
      d = idx[0];
      b_d1 = validNewRowIdx[e_i];
      f_loop_ub = BoardCoords.size(2);
      num.set_size(1, 1, f_loop_ub);
      for (int i7{0}; i7 < f_loop_ub; i7++) {
        num[i7] =
            (BoardCoords[(((static_cast<int>(d)) +
                           (BoardCoords.size(0) *
                            ((static_cast<int>(b_d1)) - 1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * i7)) -
                         1] +
             BoardCoords[(((static_cast<int>(d)) +
                           (BoardCoords.size(0) *
                            ((static_cast<int>(
                                 static_cast<double>(b_d1 + 2.0))) -
                             1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * i7)) -
                         1]) -
            (2.0 *
             BoardCoords[(((static_cast<int>(d)) +
                           (BoardCoords.size(0) *
                            ((static_cast<int>(
                                 static_cast<double>(b_d1 + 1.0))) -
                             1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * i7)) -
                         1]);
      }
      d2 = idx[0];
      d3 = validNewRowIdx[e_i];
      h_loop_ub = BoardCoords.size(2);
      denom.set_size(1, 1, h_loop_ub);
      for (int i8{0}; i8 < h_loop_ub; i8++) {
        denom[i8] =
            BoardCoords[(((static_cast<int>(d2)) +
                          (BoardCoords.size(0) *
                           ((static_cast<int>(d3)) - 1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * i8)) -
                        1] -
            BoardCoords[(((static_cast<int>(d2)) +
                          (BoardCoords.size(0) *
                           ((static_cast<int>(static_cast<double>(d3 + 2.0))) -
                            1))) +
                         ((BoardCoords.size(0) * BoardCoords.size(1)) * i8)) -
                        1];
      }
      if (newEnergy != 0.0F) {
        array<double, 1U> d_denom;
        array<double, 1U> d_num;
        int b_denom;
        int b_num;
        b_num = num.size(2);
        b_denom = denom.size(2);
        d_num = num.reshape(b_num);
        d_denom = denom.reshape(b_denom);
        newEnergy = std::fmax(newEnergy, static_cast<float>(static_cast<double>(
                                             b_norm(d_num) / b_norm(d_denom))));
      } else {
        array<double, 1U> c_denom;
        array<double, 1U> c_num;
        int b_denom;
        int b_num;
        b_num = num.size(2);
        b_denom = denom.size(2);
        c_num = num.reshape(b_num);
        c_denom = denom.reshape(b_denom);
        newEnergy = std::fmax(oldEnergy, static_cast<float>(static_cast<double>(
                                             b_norm(c_num) / b_norm(c_denom))));
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
  array<double, 2U> r2;
  array<int, 2U> r1;
  array<int, 2U> r3;
  array<int, 1U> r;
  int b_end;
  int b_loop_ub;
  int b_partialTrueCount;
  int b_this_idx_0;
  int b_this_idx_1;
  int b_trueCount;
  int c_loop_ub;
  int e_loop_ub;
  int end;
  int f_loop_ub;
  int h_loop_ub;
  int i14;
  int i4;
  int i_loop_ub;
  int loop_ub;
  int partialTrueCount;
  int this_idx_0;
  int this_idx_1;
  int this_idx_2;
  int trueCount;
  int unnamed_idx_0;
  this_idx_0 = BoardIdx.size(0);
  this_idx_1 = BoardIdx.size(1) + 1;
  newBoard.set_size(this_idx_0, this_idx_1);
  for (int b_i{0}; b_i < this_idx_1; b_i++) {
    for (int i1{0}; i1 < this_idx_0; i1++) {
      newBoard[i1 + (newBoard.size(0) * b_i)] = 0.0;
    }
  }
  loop_ub = BoardIdx.size(0);
  r.set_size(loop_ub);
  for (int i2{0}; i2 < loop_ub; i2++) {
    r[i2] = i2;
  }
  b_loop_ub = r.size(0);
  for (int i3{0}; i3 < b_loop_ub; i3++) {
    newBoard[r[i3]] = indices[i3];
  }
  i4 = static_cast<int>(2 <= newBoard.size(1));
  c_loop_ub = BoardIdx.size(1);
  for (int i5{0}; i5 < c_loop_ub; i5++) {
    int d_loop_ub;
    d_loop_ub = BoardIdx.size(0);
    for (int i6{0}; i6 < d_loop_ub; i6++) {
      newBoard[i6 + (newBoard.size(0) * (i4 + i5))] =
          BoardIdx[i6 + (BoardIdx.size(0) * i5)];
    }
  }
  b_this_idx_0 = BoardCoords.size(0);
  b_this_idx_1 = BoardCoords.size(1) + 1;
  this_idx_2 = BoardCoords.size(2);
  newBoardCoords.set_size(b_this_idx_0, b_this_idx_1, this_idx_2);
  for (int i7{0}; i7 < this_idx_2; i7++) {
    for (int i8{0}; i8 < b_this_idx_1; i8++) {
      for (int i10{0}; i10 < b_this_idx_0; i10++) {
        newBoardCoords[(i10 + (newBoardCoords.size(0) * i8)) +
                       ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                        i7)] = 0.0;
      }
    }
  }
  e_loop_ub = BoardCoords.size(2);
  r.set_size(e_loop_ub);
  for (int i9{0}; i9 < e_loop_ub; i9++) {
    r[i9] = i9;
  }
  end = indices.size(1) - 1;
  trueCount = 0;
  for (int c_i{0}; c_i <= end; c_i++) {
    if (indices[c_i] > 0.0) {
      trueCount++;
    }
  }
  r1.set_size(1, trueCount);
  partialTrueCount = 0;
  for (int d_i{0}; d_i <= end; d_i++) {
    if (indices[d_i] > 0.0) {
      r1[partialTrueCount] = d_i + 1;
      partialTrueCount++;
    }
  }
  f_loop_ub = Points.size(1);
  r2.set_size(r1.size(1), f_loop_ub);
  for (int i11{0}; i11 < f_loop_ub; i11++) {
    int g_loop_ub;
    g_loop_ub = r1.size(1);
    for (int i12{0}; i12 < g_loop_ub; i12++) {
      r2[i12 + (r2.size(0) * i11)] =
          static_cast<double>(Points[((static_cast<int>(indices[r1[i12] - 1])) +
                                      (Points.size(0) * i11)) -
                                     1]);
    }
  }
  b_end = indices.size(1) - 1;
  b_trueCount = 0;
  for (int e_i{0}; e_i <= b_end; e_i++) {
    if (indices[e_i] > 0.0) {
      b_trueCount++;
    }
  }
  r3.set_size(1, b_trueCount);
  b_partialTrueCount = 0;
  for (int g_i{0}; g_i <= b_end; g_i++) {
    if (indices[g_i] > 0.0) {
      r3[b_partialTrueCount] = g_i + 1;
      b_partialTrueCount++;
    }
  }
  unnamed_idx_0 = r3.size(1);
  h_loop_ub = r.size(0);
  for (int i13{0}; i13 < h_loop_ub; i13++) {
    for (int i15{0}; i15 < unnamed_idx_0; i15++) {
      newBoardCoords[(r3[i15] +
                      ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                       r[i13])) -
                     1] = r2[i15 + (unnamed_idx_0 * i13)];
    }
  }
  i14 = static_cast<int>(2 <= newBoardCoords.size(1));
  i_loop_ub = BoardCoords.size(2);
  for (int i16{0}; i16 < i_loop_ub; i16++) {
    int j_loop_ub;
    j_loop_ub = BoardCoords.size(1);
    for (int i17{0}; i17 < j_loop_ub; i17++) {
      int k_loop_ub;
      k_loop_ub = BoardCoords.size(0);
      for (int i18{0}; i18 < k_loop_ub; i18++) {
        newBoardCoords[(i18 + (newBoardCoords.size(0) * (i14 + i17))) +
                       ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                        i16)] =
            BoardCoords[(i18 + (BoardCoords.size(0) * i17)) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) * i16)];
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
  array<double, 2U> r2;
  array<int, 2U> r1;
  array<int, 2U> r3;
  array<int, 1U> r;
  int b_end;
  int b_loop_ub;
  int b_partialTrueCount;
  int b_this;
  int b_this_idx_0;
  int b_this_idx_1;
  int b_trueCount;
  int c_loop_ub;
  int c_this;
  int e_loop_ub;
  int end;
  int f_loop_ub;
  int h_loop_ub;
  int i_loop_ub;
  int loop_ub;
  int partialTrueCount;
  int this_idx_0;
  int this_idx_1;
  int this_idx_2;
  int trueCount;
  int unnamed_idx_0;
  this_idx_0 = BoardIdx.size(0);
  this_idx_1 = BoardIdx.size(1) + 1;
  newBoard.set_size(this_idx_0, this_idx_1);
  for (int b_i{0}; b_i < this_idx_1; b_i++) {
    for (int i1{0}; i1 < this_idx_0; i1++) {
      newBoard[i1 + (newBoard.size(0) * b_i)] = 0.0;
    }
  }
  loop_ub = BoardIdx.size(0);
  r.set_size(loop_ub);
  for (int i2{0}; i2 < loop_ub; i2++) {
    r[i2] = i2;
  }
  b_this = BoardIdx.size(1);
  b_loop_ub = r.size(0);
  for (int i3{0}; i3 < b_loop_ub; i3++) {
    newBoard[r[i3] + (newBoard.size(0) * b_this)] = indices[i3];
  }
  c_loop_ub = BoardIdx.size(1);
  for (int i4{0}; i4 < c_loop_ub; i4++) {
    int d_loop_ub;
    d_loop_ub = BoardIdx.size(0);
    for (int i5{0}; i5 < d_loop_ub; i5++) {
      newBoard[i5 + (newBoard.size(0) * i4)] =
          BoardIdx[i5 + (BoardIdx.size(0) * i4)];
    }
  }
  b_this_idx_0 = BoardCoords.size(0);
  b_this_idx_1 = BoardCoords.size(1) + 1;
  this_idx_2 = BoardCoords.size(2);
  newBoardCoords.set_size(b_this_idx_0, b_this_idx_1, this_idx_2);
  for (int i6{0}; i6 < this_idx_2; i6++) {
    for (int i7{0}; i7 < b_this_idx_1; i7++) {
      for (int i9{0}; i9 < b_this_idx_0; i9++) {
        newBoardCoords[(i9 + (newBoardCoords.size(0) * i7)) +
                       ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                        i6)] = 0.0;
      }
    }
  }
  e_loop_ub = BoardCoords.size(2);
  r.set_size(e_loop_ub);
  for (int i8{0}; i8 < e_loop_ub; i8++) {
    r[i8] = i8;
  }
  end = indices.size(1) - 1;
  trueCount = 0;
  for (int c_i{0}; c_i <= end; c_i++) {
    if (indices[c_i] > 0.0) {
      trueCount++;
    }
  }
  r1.set_size(1, trueCount);
  partialTrueCount = 0;
  for (int d_i{0}; d_i <= end; d_i++) {
    if (indices[d_i] > 0.0) {
      r1[partialTrueCount] = d_i + 1;
      partialTrueCount++;
    }
  }
  f_loop_ub = Points.size(1);
  r2.set_size(r1.size(1), f_loop_ub);
  for (int i10{0}; i10 < f_loop_ub; i10++) {
    int g_loop_ub;
    g_loop_ub = r1.size(1);
    for (int i11{0}; i11 < g_loop_ub; i11++) {
      r2[i11 + (r2.size(0) * i10)] =
          static_cast<double>(Points[((static_cast<int>(indices[r1[i11] - 1])) +
                                      (Points.size(0) * i10)) -
                                     1]);
    }
  }
  b_end = indices.size(1) - 1;
  b_trueCount = 0;
  for (int e_i{0}; e_i <= b_end; e_i++) {
    if (indices[e_i] > 0.0) {
      b_trueCount++;
    }
  }
  r3.set_size(1, b_trueCount);
  b_partialTrueCount = 0;
  for (int g_i{0}; g_i <= b_end; g_i++) {
    if (indices[g_i] > 0.0) {
      r3[b_partialTrueCount] = g_i + 1;
      b_partialTrueCount++;
    }
  }
  unnamed_idx_0 = r3.size(1);
  c_this = BoardCoords.size(1);
  h_loop_ub = r.size(0);
  for (int i12{0}; i12 < h_loop_ub; i12++) {
    for (int i13{0}; i13 < unnamed_idx_0; i13++) {
      newBoardCoords[((r3[i13] + (newBoardCoords.size(0) * c_this)) +
                      ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                       r[i12])) -
                     1] = r2[i13 + (unnamed_idx_0 * i12)];
    }
  }
  i_loop_ub = BoardCoords.size(2);
  for (int i14{0}; i14 < i_loop_ub; i14++) {
    int j_loop_ub;
    j_loop_ub = BoardCoords.size(1);
    for (int i15{0}; i15 < j_loop_ub; i15++) {
      int k_loop_ub;
      k_loop_ub = BoardCoords.size(0);
      for (int i16{0}; i16 < k_loop_ub; i16++) {
        newBoardCoords[(i16 + (newBoardCoords.size(0) * i15)) +
                       ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                        i14)] =
            BoardCoords[(i16 + (BoardCoords.size(0) * i15)) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) * i14)];
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
  array<double, 2U> r2;
  array<int, 2U> r1;
  array<int, 2U> r3;
  array<int, 1U> r;
  int b_end;
  int b_loop_ub;
  int b_partialTrueCount;
  int b_this_idx_0;
  int b_this_idx_1;
  int b_trueCount;
  int d_loop_ub;
  int e_loop_ub;
  int end;
  int g_loop_ub;
  int h_loop_ub;
  int i13;
  int i3;
  int loop_ub;
  int partialTrueCount;
  int this_idx_0;
  int this_idx_1;
  int this_idx_2;
  int trueCount;
  int unnamed_idx_1;
  this_idx_0 = BoardIdx.size(0) + 1;
  this_idx_1 = BoardIdx.size(1);
  newBoard.set_size(this_idx_0, this_idx_1);
  for (int b_i{0}; b_i < this_idx_1; b_i++) {
    for (int i1{0}; i1 < this_idx_0; i1++) {
      newBoard[i1 + (newBoard.size(0) * b_i)] = 0.0;
    }
  }
  loop_ub = indices.size(1);
  for (int i2{0}; i2 < loop_ub; i2++) {
    newBoard[newBoard.size(0) * i2] = indices[i2];
  }
  i3 = static_cast<int>(2 <= newBoard.size(0));
  b_loop_ub = BoardIdx.size(1);
  for (int i4{0}; i4 < b_loop_ub; i4++) {
    int c_loop_ub;
    c_loop_ub = BoardIdx.size(0);
    for (int i5{0}; i5 < c_loop_ub; i5++) {
      newBoard[(i3 + i5) + (newBoard.size(0) * i4)] =
          BoardIdx[i5 + (BoardIdx.size(0) * i4)];
    }
  }
  b_this_idx_0 = BoardCoords.size(0) + 1;
  b_this_idx_1 = BoardCoords.size(1);
  this_idx_2 = BoardCoords.size(2);
  newBoardCoords.set_size(b_this_idx_0, b_this_idx_1, this_idx_2);
  for (int i6{0}; i6 < this_idx_2; i6++) {
    for (int i7{0}; i7 < b_this_idx_1; i7++) {
      for (int i9{0}; i9 < b_this_idx_0; i9++) {
        newBoardCoords[(i9 + (newBoardCoords.size(0) * i7)) +
                       ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                        i6)] = 0.0;
      }
    }
  }
  d_loop_ub = BoardCoords.size(2);
  r.set_size(d_loop_ub);
  for (int i8{0}; i8 < d_loop_ub; i8++) {
    r[i8] = i8;
  }
  end = indices.size(1) - 1;
  trueCount = 0;
  for (int c_i{0}; c_i <= end; c_i++) {
    if (indices[c_i] > 0.0) {
      trueCount++;
    }
  }
  r1.set_size(1, trueCount);
  partialTrueCount = 0;
  for (int d_i{0}; d_i <= end; d_i++) {
    if (indices[d_i] > 0.0) {
      r1[partialTrueCount] = d_i + 1;
      partialTrueCount++;
    }
  }
  e_loop_ub = Points.size(1);
  r2.set_size(r1.size(1), e_loop_ub);
  for (int i10{0}; i10 < e_loop_ub; i10++) {
    int f_loop_ub;
    f_loop_ub = r1.size(1);
    for (int i11{0}; i11 < f_loop_ub; i11++) {
      r2[i11 + (r2.size(0) * i10)] =
          static_cast<double>(Points[((static_cast<int>(indices[r1[i11] - 1])) +
                                      (Points.size(0) * i10)) -
                                     1]);
    }
  }
  b_end = indices.size(1) - 1;
  b_trueCount = 0;
  for (int e_i{0}; e_i <= b_end; e_i++) {
    if (indices[e_i] > 0.0) {
      b_trueCount++;
    }
  }
  r3.set_size(1, b_trueCount);
  b_partialTrueCount = 0;
  for (int g_i{0}; g_i <= b_end; g_i++) {
    if (indices[g_i] > 0.0) {
      r3[b_partialTrueCount] = g_i + 1;
      b_partialTrueCount++;
    }
  }
  unnamed_idx_1 = r3.size(1);
  g_loop_ub = r.size(0);
  for (int i12{0}; i12 < g_loop_ub; i12++) {
    for (int i14{0}; i14 < unnamed_idx_1; i14++) {
      newBoardCoords[(newBoardCoords.size(0) * (r3[i14] - 1)) +
                     ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                      r[i12])] = r2[i14 + (unnamed_idx_1 * i12)];
    }
  }
  i13 = static_cast<int>(2 <= newBoardCoords.size(0));
  h_loop_ub = BoardCoords.size(2);
  for (int i15{0}; i15 < h_loop_ub; i15++) {
    int i_loop_ub;
    i_loop_ub = BoardCoords.size(1);
    for (int i16{0}; i16 < i_loop_ub; i16++) {
      int j_loop_ub;
      j_loop_ub = BoardCoords.size(0);
      for (int i17{0}; i17 < j_loop_ub; i17++) {
        newBoardCoords[((i13 + i17) + (newBoardCoords.size(0) * i16)) +
                       ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                        i15)] =
            BoardCoords[(i17 + (BoardCoords.size(0) * i16)) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) * i15)];
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
  array<double, 2U> b_indices;
  array<double, 2U> remIdx;
  array<double, 2U> y;
  array<double, 1U> c_this;
  array<float, 2U> b_a;
  array<float, 2U> diffs;
  array<float, 1U> b_diffs;
  array<float, 1U> c_diffs;
  array<float, 1U> dists;
  array<int, 2U> r1;
  array<int, 1U> b_ib;
  array<int, 1U> c_ii;
  array<int, 1U> ia;
  array<unsigned int, 1U> validPredictions;
  array<bool, 2U> distIdx;
  array<bool, 1U> b_x;
  array<bool, 1U> r;
  float b_ex;
  int b;
  int b_this;
  int iindx;
  int loop_ub;
  indices.set_size(1, predictedPoints.size(0));
  loop_ub = predictedPoints.size(0);
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    indices[b_i] = 0.0;
  }
  b = Points.size(0);
  if (b < 1) {
    y.set_size(1, 0);
  } else {
    int b_loop_ub;
    y.set_size(1, b);
    b_loop_ub = b - 1;
    for (int i1{0}; i1 <= b_loop_ub; i1++) {
      y[i1] = (static_cast<double>(i1)) + 1.0;
    }
  }
  b_this = BoardIdx.size(0) * BoardIdx.size(1);
  c_this = BoardIdx.reshape(b_this);
  do_vectors(y, c_this, remIdx, ia, b_ib);
  if (remIdx.size(1) != 0) {
    int c_loop_ub;
    int d_loop_ub;
    int e_ii;
    int e_loop_ub;
    int i6;
    int idx;
    int nx;
    bool exitg1;
    c_loop_ub = predictedPoints.size(0);
    r.set_size(predictedPoints.size(0));
    for (int i2{0}; i2 < c_loop_ub; i2++) {
      r[i2] = std::isnan(predictedPoints[i2]);
    }
    b_x.set_size(r.size(0));
    d_loop_ub = r.size(0);
    for (int i3{0}; i3 < d_loop_ub; i3++) {
      b_x[i3] = !r[i3];
    }
    nx = b_x.size(0);
    idx = 0;
    c_ii.set_size(b_x.size(0));
    e_ii = 0;
    exitg1 = false;
    while ((!exitg1) && (e_ii <= (nx - 1))) {
      if (b_x[e_ii]) {
        idx++;
        c_ii[idx - 1] = e_ii + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          e_ii++;
        }
      } else {
        e_ii++;
      }
    }
    if (b_x.size(0) == 1) {
      if (idx == 0) {
        c_ii.set_size(0);
      }
    } else {
      int i4;
      if (1 > idx) {
        i4 = 0;
      } else {
        i4 = idx;
      }
      c_ii.set_size(i4);
    }
    validPredictions.set_size(c_ii.size(0));
    e_loop_ub = c_ii.size(0);
    for (int i5{0}; i5 < e_loop_ub; i5++) {
      validPredictions[i5] = static_cast<unsigned int>(c_ii[i5]);
    }
    i6 = validPredictions.size(0);
    for (int c_i{0}; c_i < i6; c_i++) {
      int b_end;
      int csz_idx_0;
      int end;
      int f_loop_ub;
      int h_loop_ub;
      int i8;
      int i_loop_ub;
      int j_loop_ub;
      int partialTrueCount;
      int trueCount;
      int u0;
      int u1;
      f_loop_ub = Points.size(1);
      b_a.set_size(remIdx.size(1), f_loop_ub);
      for (int i7{0}; i7 < f_loop_ub; i7++) {
        int g_loop_ub;
        g_loop_ub = remIdx.size(1);
        for (int i9{0}; i9 < g_loop_ub; i9++) {
          b_a[i9 + (b_a.size(0) * i7)] =
              Points[((static_cast<int>(remIdx[i9])) + (Points.size(0) * i7)) -
                     1];
        }
      }
      if (predictedPoints.size(1) == 1) {
        i8 = b_a.size(1);
      } else if (b_a.size(1) == 1) {
        i8 = predictedPoints.size(1);
      } else if (predictedPoints.size(1) == b_a.size(1)) {
        i8 = b_a.size(1);
      } else if (predictedPoints.size(1) < b_a.size(1)) {
        i8 = predictedPoints.size(1);
      } else {
        i8 = b_a.size(1);
      }
      diffs.set_size(b_a.size(0), i8);
      if (i8 != 0) {
        int acoef;
        int bcoef;
        int i10;
        acoef = static_cast<int>(b_a.size(1) != 1);
        bcoef = static_cast<int>(predictedPoints.size(1) != 1);
        i10 = i8 - 1;
        for (int k{0}; k <= i10; k++) {
          int b_acoef;
          int i13;
          int varargin_2;
          int varargin_3;
          varargin_2 = acoef * k;
          varargin_3 = bcoef * k;
          b_acoef = static_cast<int>(b_a.size(0) != 1);
          i13 = diffs.size(0) - 1;
          for (int b_k{0}; b_k <= i13; b_k++) {
            diffs[b_k + (diffs.size(0) * k)] =
                b_a[(b_acoef * b_k) + (b_a.size(0) * varargin_2)] -
                (static_cast<float>(
                    predictedPoints[((static_cast<int>(validPredictions[c_i])) +
                                     (predictedPoints.size(0) * varargin_3)) -
                                    1]));
          }
        }
      }
      h_loop_ub = diffs.size(0);
      b_diffs.set_size(diffs.size(0));
      for (int i11{0}; i11 < h_loop_ub; i11++) {
        b_diffs[i11] = diffs[i11];
      }
      i_loop_ub = diffs.size(0);
      c_diffs.set_size(diffs.size(0));
      for (int i12{0}; i12 < i_loop_ub; i12++) {
        c_diffs[i12] = diffs[i12 + diffs.size(0)];
      }
      u0 = b_diffs.size(0);
      u1 = c_diffs.size(0);
      if (u0 <= u1) {
        csz_idx_0 = u0;
      } else {
        csz_idx_0 = u1;
      }
      dists.set_size(csz_idx_0);
      for (int c_k{0}; c_k < csz_idx_0; c_k++) {
        dists[c_k] = rt_hypotf_snf(b_diffs[c_k], c_diffs[c_k]);
      }
      end = indices.size(1) - 1;
      trueCount = 0;
      for (int d_i{0}; d_i <= end; d_i++) {
        if (indices[d_i] > 0.0) {
          trueCount++;
        }
      }
      r1.set_size(1, trueCount);
      partialTrueCount = 0;
      for (int e_i{0}; e_i <= end; e_i++) {
        if (indices[e_i] > 0.0) {
          r1[partialTrueCount] = e_i + 1;
          partialTrueCount++;
        }
      }
      j_loop_ub = r1.size(1);
      b_indices.set_size(1, r1.size(1));
      for (int i14{0}; i14 < j_loop_ub; i14++) {
        b_indices[i14] = indices[r1[i14] - 1];
      }
      local_ismember(remIdx, b_indices, distIdx);
      b_end = distIdx.size(1);
      for (int g_i{0}; g_i < b_end; g_i++) {
        if (distIdx[g_i]) {
          dists[g_i] = rtInfF;
        }
      }
      ::coder::internal::minimum(dists, &b_ex, &iindx);
      indices[(static_cast<int>(validPredictions[c_i])) - 1] =
          remIdx[iindx - 1];
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
  array<double, 2U> b_remIdx;
  array<double, 2U> dataPts;
  array<double, 2U> firstCoord;
  array<double, 2U> remIdx;
  array<double, 2U> y;
  array<double, 1U> c_this;
  array<double, 1U> dist;
  array<float, 2U> b_a;
  array<float, 2U> currPt;
  array<float, 2U> d_a;
  array<float, 2U> diffs;
  array<float, 2U> queryPts;
  array<float, 2U> z1;
  array<float, 1U> b_diffs;
  array<float, 1U> b_y;
  array<float, 1U> c_diffs;
  array<float, 1U> dists;
  array<int, 1U> b_ib;
  array<int, 1U> c_ii;
  array<unsigned int, 1U> d_idx;
  array<int, 1U> ia;
  array<int, 1U> r;
  array<bool, 1U> b_x;
  array<bool, 1U> s;
  double dv[2];
  double b_ex;
  int b;
  int b_loop_ub;
  int b_this;
  int c_loop_ub;
  int c_n;
  int csz_idx_0;
  int e_loop_ub;
  int f_loop_ub;
  int g_loop_ub;
  int i8;
  int iindx;
  int outsize_idx_0;
  int outsize_idx_1;
  int u0;
  int u1;
  int u_loop_ub;
  b = Points.size(0);
  if (b < 1) {
    y.set_size(1, 0);
  } else {
    int loop_ub;
    y.set_size(1, b);
    loop_ub = b - 1;
    for (int b_i{0}; b_i <= loop_ub; b_i++) {
      y[b_i] = (static_cast<double>(b_i)) + 1.0;
    }
  }
  b_this = BoardIdx.size(0) * BoardIdx.size(1);
  c_this = BoardIdx.reshape(b_this);
  do_vectors(y, c_this, remIdx, ia, b_ib);
  b_remIdx.set_size(1, remIdx.size(1));
  b_loop_ub = remIdx.size(1) - 1;
  for (int i1{0}; i1 <= b_loop_ub; i1++) {
    b_remIdx[i1] = remIdx[i1];
  }
  b_do_vectors(b_remIdx, removedIdx, remIdx, ia, b_ib);
  c_loop_ub = Points.size(1);
  b_a.set_size(remIdx.size(1), c_loop_ub);
  for (int i2{0}; i2 < c_loop_ub; i2++) {
    int d_loop_ub;
    d_loop_ub = remIdx.size(1);
    for (int i3{0}; i3 < d_loop_ub; i3++) {
      b_a[i3 + (b_a.size(0) * i2)] =
          Points[((static_cast<int>(remIdx[i3])) + (Points.size(0) * i2)) - 1];
    }
  }
  diffs.set_size(b_a.size(0), 2);
  if (b_a.size(0) != 0) {
    int acoef;
    int b_acoef;
    acoef = static_cast<int>(b_a.size(1) != 1);
    b_acoef = static_cast<int>(b_a.size(0) != 1);
    for (int k{0}; k < 2; k++) {
      int i5;
      int varargin_2;
      varargin_2 = acoef * k;
      i5 = diffs.size(0) - 1;
      for (int b_k{0}; b_k <= i5; b_k++) {
        diffs[b_k + (diffs.size(0) * k)] =
            b_a[(b_acoef * b_k) + (b_a.size(0) * varargin_2)] -
            (static_cast<float>(predictedPoint[k]));
      }
    }
  }
  e_loop_ub = diffs.size(0);
  b_diffs.set_size(diffs.size(0));
  for (int i4{0}; i4 < e_loop_ub; i4++) {
    b_diffs[i4] = diffs[i4];
  }
  f_loop_ub = diffs.size(0);
  c_diffs.set_size(diffs.size(0));
  for (int i6{0}; i6 < f_loop_ub; i6++) {
    c_diffs[i6] = diffs[i6 + diffs.size(0)];
  }
  u0 = b_diffs.size(0);
  u1 = c_diffs.size(0);
  if (u0 <= u1) {
    csz_idx_0 = u0;
  } else {
    csz_idx_0 = u1;
  }
  dists.set_size(csz_idx_0);
  for (int c_k{0}; c_k < csz_idx_0; c_k++) {
    dists[c_k] = rt_hypotf_snf(b_diffs[c_k], c_diffs[c_k]);
  }
  s.set_size(dists.size(0));
  g_loop_ub = dists.size(0);
  for (int i7{0}; i7 < g_loop_ub; i7++) {
    s[i7] = ((static_cast<double>(dists[i7])) < radius);
  }
  c_n = 0;
  i8 = s.size(0);
  for (int d_k{0}; d_k < i8; d_k++) {
    if (s[d_k]) {
      c_n++;
    }
  }
  if (c_n > 1) {
    double a_tmp;
    double c_a;
    double c_b;
    int b_end;
    int b_idx;
    int b_partialTrueCount;
    int b_trueCount;
    int b_u1;
    int e_ii;
    int i24;
    int j_k;
    int s_loop_ub;
    int v_loop_ub;
    int w_loop_ub;
    bool exitg1;
    bool guard1{false};
    bool guard2{false};
    bool guard3{false};
    a_tmp = predictedPoint[(static_cast<int>(coordsToUse[0])) - 1];
    c_a = a_tmp - radius;
    c_b = a_tmp + radius;
    guard1 = false;
    guard2 = false;
    guard3 = false;
    if (std::isnan(c_a)) {
      guard2 = true;
    } else if (std::isnan(c_b)) {
      guard2 = true;
    } else if (c_b < c_a) {
      firstCoord.set_size(1, 0);
    } else if (std::isinf(c_a)) {
      guard3 = true;
    } else if (std::isinf(c_b)) {
      guard3 = true;
    } else {
      guard1 = true;
    }
    if (guard3) {
      if (c_a == c_b) {
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
      if (std::floor(c_a) == c_a) {
        int i_loop_ub;
        i_loop_ub = static_cast<int>(std::floor(c_b - c_a));
        firstCoord.set_size(1, i_loop_ub + 1);
        for (int i11{0}; i11 <= i_loop_ub; i11++) {
          firstCoord[i11] = c_a + (static_cast<double>(i11));
        }
      } else {
        eml_float_colon(c_a, c_b, firstCoord);
      }
    }
    dv[0] = 1.0;
    dv[1] = 2.0;
    if (isequal(coordsToUse, dv)) {
      int m_loop_ub;
      int p_loop_ub;
      y.set_size(1, firstCoord.size(1));
      if (firstCoord.size(1) != 0) {
        if (curve.size(1) != 0) {
          int i18;
          int y_idx_1;
          y_idx_1 = firstCoord.size(1);
          y.set_size(1, firstCoord.size(1));
          for (int i16{0}; i16 < y_idx_1; i16++) {
            y[i16] = curve[0];
          }
          i18 = curve.size(1);
          for (int h_k{0}; h_k <= (i18 - 2); h_k++) {
            double c_curve;
            int r_loop_ub;
            c_curve = curve[h_k + 1];
            r_loop_ub = firstCoord.size(1);
            y.set_size(1, firstCoord.size(1));
            for (int i22{0}; i22 < r_loop_ub; i22++) {
              y[i22] = (firstCoord[i22] * y[i22]) + c_curve;
            }
          }
        }
      }
      dataPts.set_size(firstCoord.size(1), 2);
      m_loop_ub = firstCoord.size(1);
      for (int i15{0}; i15 < m_loop_ub; i15++) {
        dataPts[i15] = firstCoord[i15];
      }
      p_loop_ub = y.size(1);
      for (int i20{0}; i20 < p_loop_ub; i20++) {
        dataPts[i20 + dataPts.size(0)] = y[i20];
      }
    } else {
      int k_loop_ub;
      int o_loop_ub;
      y.set_size(1, firstCoord.size(1));
      if (firstCoord.size(1) != 0) {
        if (curve.size(1) != 0) {
          int i17;
          int y_idx_1;
          y_idx_1 = firstCoord.size(1);
          y.set_size(1, firstCoord.size(1));
          for (int i14{0}; i14 < y_idx_1; i14++) {
            y[i14] = curve[0];
          }
          i17 = curve.size(1);
          for (int g_k{0}; g_k <= (i17 - 2); g_k++) {
            double b_curve;
            int q_loop_ub;
            b_curve = curve[g_k + 1];
            q_loop_ub = firstCoord.size(1);
            y.set_size(1, firstCoord.size(1));
            for (int i21{0}; i21 < q_loop_ub; i21++) {
              y[i21] = (firstCoord[i21] * y[i21]) + b_curve;
            }
          }
        }
      }
      dataPts.set_size(y.size(1), 2);
      k_loop_ub = y.size(1);
      for (int i13{0}; i13 < k_loop_ub; i13++) {
        dataPts[i13] = y[i13];
      }
      o_loop_ub = firstCoord.size(1);
      for (int i19{0}; i19 < o_loop_ub; i19++) {
        dataPts[i19 + dataPts.size(0)] = firstCoord[i19];
      }
    }
    b_end = dists.size(0) - 1;
    b_trueCount = 0;
    for (int e_i{0}; e_i <= b_end; e_i++) {
      if ((static_cast<double>(dists[e_i])) < radius) {
        b_trueCount++;
      }
    }
    r.set_size(b_trueCount);
    b_partialTrueCount = 0;
    for (int g_i{0}; g_i <= b_end; g_i++) {
      if ((static_cast<double>(dists[g_i])) < radius) {
        r[b_partialTrueCount] = g_i + 1;
        b_partialTrueCount++;
      }
    }
    s_loop_ub = Points.size(1);
    queryPts.set_size(r.size(0), s_loop_ub);
    for (int i23{0}; i23 < s_loop_ub; i23++) {
      int t_loop_ub;
      t_loop_ub = r.size(0);
      for (int i25{0}; i25 < t_loop_ub; i25++) {
        queryPts[i25 + (queryPts.size(0) * i23)] =
            Points[((static_cast<int>(remIdx[r[i25] - 1])) +
                    (Points.size(0) * i23)) -
                   1];
      }
    }
    dist.set_size(queryPts.size(0));
    i24 = queryPts.size(0);
    if (0 <= (queryPts.size(0) - 1)) {
      outsize_idx_0 = dataPts.size(0);
      outsize_idx_1 = queryPts.size(1);
      u_loop_ub = dataPts.size(0);
    }
    for (int h_i{0}; h_i < i24; h_i++) {
      float c_x;
      int last;
      currPt.set_size(outsize_idx_0, outsize_idx_1);
      if ((outsize_idx_0 != 0) && (outsize_idx_1 != 0)) {
        int na;
        na = queryPts.size(1) - 1;
        for (int i_k{0}; i_k <= na; i_k++) {
          int i28;
          i28 = dataPts.size(0) - 1;
          for (int b_t{0}; b_t <= i28; b_t++) {
            currPt[b_t + (currPt.size(0) * i_k)] =
                queryPts[h_i + (queryPts.size(0) * i_k)];
          }
        }
      }
      d_a.set_size(dataPts.size(0), 2);
      for (int i27{0}; i27 < 2; i27++) {
        for (int i29{0}; i29 < u_loop_ub; i29++) {
          d_a[i29 + (d_a.size(0) * i27)] =
              (static_cast<float>(dataPts[i29 + (dataPts.size(0) * i27)])) -
              currPt[i29 + (currPt.size(0) * i27)];
        }
      }
      z1.set_size(d_a.size(0), 2);
      for (int k_k{0}; k_k < 2; k_k++) {
        int f_N;
        f_N = z1.size(0);
        for (int m_k{0}; m_k < f_N; m_k++) {
          z1[m_k + (z1.size(0) * k_k)] =
              rt_powf_snf(d_a[m_k + (d_a.size(0) * k_k)], 2.0F);
        }
      }
      if (z1.size(0) == 0) {
        b_y.set_size(0);
      } else {
        int i30;
        int i31;
        b_y.set_size(z1.size(0));
        i30 = z1.size(0);
        for (int o_k{0}; o_k < i30; o_k++) {
          b_y[o_k] = z1[o_k];
        }
        i31 = z1.size(0);
        for (int p_k{0}; p_k < i31; p_k++) {
          b_y[p_k] = b_y[p_k] + z1[p_k + z1.size(0)];
        }
      }
      last = b_y.size(0);
      if (b_y.size(0) <= 2) {
        if (b_y.size(0) == 0) {
          c_x = rtNaNF;
        } else if (b_y.size(0) == 1) {
          c_x = b_y[0];
        } else if (b_y[0] > b_y[1]) {
          c_x = b_y[1];
        } else if (std::isnan(b_y[0])) {
          if (!std::isnan(b_y[1])) {
            c_x = b_y[1];
          } else {
            c_x = b_y[0];
          }
        } else {
          c_x = b_y[0];
        }
      } else {
        int c_idx;
        if (!std::isnan(b_y[0])) {
          c_idx = 1;
        } else {
          int q_k;
          c_idx = 0;
          q_k = 2;
          exitg1 = false;
          while ((!exitg1) && (q_k <= last)) {
            if (!std::isnan(b_y[q_k - 1])) {
              c_idx = q_k;
              exitg1 = true;
            } else {
              q_k++;
            }
          }
        }
        if (c_idx == 0) {
          c_x = b_y[0];
        } else {
          float c_ex;
          int i33;
          c_ex = b_y[c_idx - 1];
          i33 = c_idx + 1;
          for (int r_k{i33}; r_k <= last; r_k++) {
            float f;
            f = b_y[r_k - 1];
            if (c_ex > f) {
              c_ex = f;
            }
          }
          c_x = c_ex;
        }
      }
      c_x = std::sqrt(c_x);
      dist[h_i] = static_cast<double>(c_x);
    }
    ::coder::internal::b_minimum(dist, &b_ex, &iindx);
    b_x.set_size(dists.size(0));
    v_loop_ub = dists.size(0);
    for (int i26{0}; i26 < v_loop_ub; i26++) {
      b_x[i26] = ((static_cast<double>(dists[i26])) < radius);
    }
    b_u1 = b_x.size(0);
    if (iindx <= b_u1) {
      j_k = iindx;
    } else {
      j_k = b_u1;
    }
    b_idx = 0;
    c_ii.set_size(j_k);
    e_ii = 0;
    exitg1 = false;
    while ((!exitg1) && (e_ii <= (b_x.size(0) - 1))) {
      if (b_x[e_ii]) {
        b_idx++;
        c_ii[b_idx - 1] = e_ii + 1;
        if (b_idx >= j_k) {
          exitg1 = true;
        } else {
          e_ii++;
        }
      } else {
        e_ii++;
      }
    }
    if (j_k == 1) {
      if (b_idx == 0) {
        c_ii.set_size(0);
      }
    } else {
      int i32;
      if (1 > b_idx) {
        i32 = 0;
      } else {
        i32 = b_idx;
      }
      c_ii.set_size(i32);
    }
    d_idx.set_size(c_ii.size(0));
    w_loop_ub = c_ii.size(0);
    for (int i34{0}; i34 < w_loop_ub; i34++) {
      d_idx[i34] = static_cast<unsigned int>(c_ii[i34]);
    }
    idx.set_size(1, 1);
    idx[0] = remIdx[(static_cast<int>(d_idx[d_idx.size(0) - 1])) - 1];
  } else {
    int d_n;
    int h_loop_ub;
    int i10;
    s.set_size(dists.size(0));
    h_loop_ub = dists.size(0);
    for (int i9{0}; i9 < h_loop_ub; i9++) {
      s[i9] = ((static_cast<double>(dists[i9])) < radius);
    }
    d_n = 0;
    i10 = s.size(0);
    for (int f_k{0}; f_k < i10; f_k++) {
      if (s[f_k]) {
        d_n++;
      }
    }
    if (d_n == 1) {
      int end;
      int j_loop_ub;
      int partialTrueCount;
      int trueCount;
      end = dists.size(0) - 1;
      trueCount = 0;
      for (int c_i{0}; c_i <= end; c_i++) {
        if ((static_cast<double>(dists[c_i])) < radius) {
          trueCount++;
        }
      }
      r.set_size(trueCount);
      partialTrueCount = 0;
      for (int d_i{0}; d_i <= end; d_i++) {
        if ((static_cast<double>(dists[d_i])) < radius) {
          r[partialTrueCount] = d_i + 1;
          partialTrueCount++;
        }
      }
      idx.set_size(1, r.size(0));
      j_loop_ub = r.size(0);
      for (int i12{0}; i12 < j_loop_ub; i12++) {
        idx[i12] = remIdx[r[i12] - 1];
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
  array<float, 1U> angleCosines;
  array<float, 1U> dists;
  array<float, 1U> y;
  array<int, 1U> r1;
  array<int, 1U> r2;
  array<bool, 2U> r;
  double neighborIdx;
  float b;
  float b_x;
  int b_end;
  int b_loop_ub;
  int c_loop_ub;
  int e_loop_ub;
  int end;
  int f_loop_ub;
  int iindx;
  int inner;
  int loop_ub;
  int mc;
  int partialTrueCount;
  int trueCount;
  mc = pointVectors.size(0) - 1;
  inner = pointVectors.size(1);
  y.set_size(pointVectors.size(0));
  for (int b_i{0}; b_i <= mc; b_i++) {
    y[b_i] = 0.0F;
  }
  for (int k{0}; k < inner; k++) {
    for (int c_i{0}; c_i <= mc; c_i++) {
      y[c_i] =
          y[c_i] + (pointVectors[c_i + (pointVectors.size(0) * k)] * b_v[k]);
    }
  }
  b = rt_hypotf_snf(b_v[0], b_v[1]);
  angleCosines.set_size(y.size(0));
  loop_ub = y.size(0);
  for (int d_i{0}; d_i < loop_ub; d_i++) {
    angleCosines[d_i] = y[d_i] / (euclideanDists[d_i] * b);
  }
  dists.set_size(euclideanDists.size(0));
  b_loop_ub = euclideanDists.size(0);
  for (int i1{0}; i1 < b_loop_ub; i1++) {
    dists[i1] = euclideanDists[i1] +
                ((1.5F * euclideanDists[i1]) * (1.0F - angleCosines[i1]));
  }
  r.set_size(BoardIdx.size(0), BoardIdx.size(1));
  c_loop_ub = BoardIdx.size(1);
  for (int i2{0}; i2 < c_loop_ub; i2++) {
    int d_loop_ub;
    d_loop_ub = BoardIdx.size(0);
    for (int i3{0}; i3 < d_loop_ub; i3++) {
      r[i3 + (r.size(0) * i2)] = (BoardIdx[i3 + (BoardIdx.size(0) * i2)] > 0.0);
    }
  }
  end = (r.size(0) * r.size(1)) - 1;
  trueCount = 0;
  for (int e_i{0}; e_i <= end; e_i++) {
    if (r[e_i]) {
      trueCount++;
    }
  }
  r1.set_size(trueCount);
  partialTrueCount = 0;
  for (int g_i{0}; g_i <= end; g_i++) {
    if (r[g_i]) {
      r1[partialTrueCount] = g_i + 1;
      partialTrueCount++;
    }
  }
  r2.set_size(r1.size(0));
  e_loop_ub = r1.size(0);
  for (int i4{0}; i4 < e_loop_ub; i4++) {
    r2[i4] = static_cast<int>(BoardIdx[r1[i4] - 1]);
  }
  f_loop_ub = r2.size(0);
  for (int i5{0}; i5 < f_loop_ub; i5++) {
    dists[r2[i5] - 1] = rtInfF;
  }
  b_end = angleCosines.size(0);
  for (int h_i{0}; h_i < b_end; h_i++) {
    if (angleCosines[h_i] < 0.0F) {
      dists[h_i] = rtInfF;
    }
  }
  ::coder::internal::minimum(dists, &b_x, &iindx);
  neighborIdx = static_cast<double>(iindx);
  if (std::isinf(b_x)) {
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
  array<float, 1U> angleCosines;
  array<float, 1U> dists;
  array<float, 1U> y;
  array<int, 1U> r1;
  array<int, 1U> r2;
  array<bool, 2U> r;
  double neighborIdx;
  float b;
  float b_x;
  int b_end;
  int b_loop_ub;
  int c_loop_ub;
  int e_loop_ub;
  int end;
  int f_loop_ub;
  int iindx;
  int inner;
  int loop_ub;
  int mc;
  int partialTrueCount;
  int trueCount;
  mc = pointVectors.size(0) - 1;
  inner = pointVectors.size(1);
  y.set_size(pointVectors.size(0));
  for (int b_i{0}; b_i <= mc; b_i++) {
    y[b_i] = 0.0F;
  }
  for (int k{0}; k < inner; k++) {
    float bkj;
    bkj = b_v[k];
    for (int c_i{0}; c_i <= mc; c_i++) {
      y[c_i] = y[c_i] + (pointVectors[c_i + (pointVectors.size(0) * k)] * bkj);
    }
  }
  b = rt_hypotf_snf(b_v[0], b_v[1]);
  angleCosines.set_size(y.size(0));
  loop_ub = y.size(0);
  for (int d_i{0}; d_i < loop_ub; d_i++) {
    angleCosines[d_i] = y[d_i] / (euclideanDists[d_i] * b);
  }
  dists.set_size(euclideanDists.size(0));
  b_loop_ub = euclideanDists.size(0);
  for (int i1{0}; i1 < b_loop_ub; i1++) {
    dists[i1] = euclideanDists[i1] +
                ((1.5F * euclideanDists[i1]) * (1.0F - angleCosines[i1]));
  }
  r.set_size(BoardIdx.size(0), BoardIdx.size(1));
  c_loop_ub = BoardIdx.size(1);
  for (int i2{0}; i2 < c_loop_ub; i2++) {
    int d_loop_ub;
    d_loop_ub = BoardIdx.size(0);
    for (int i3{0}; i3 < d_loop_ub; i3++) {
      r[i3 + (r.size(0) * i2)] = (BoardIdx[i3 + (BoardIdx.size(0) * i2)] > 0.0);
    }
  }
  end = (r.size(0) * r.size(1)) - 1;
  trueCount = 0;
  for (int e_i{0}; e_i <= end; e_i++) {
    if (r[e_i]) {
      trueCount++;
    }
  }
  r1.set_size(trueCount);
  partialTrueCount = 0;
  for (int g_i{0}; g_i <= end; g_i++) {
    if (r[g_i]) {
      r1[partialTrueCount] = g_i + 1;
      partialTrueCount++;
    }
  }
  r2.set_size(r1.size(0));
  e_loop_ub = r1.size(0);
  for (int i4{0}; i4 < e_loop_ub; i4++) {
    r2[i4] = static_cast<int>(BoardIdx[r1[i4] - 1]);
  }
  f_loop_ub = r2.size(0);
  for (int i5{0}; i5 < f_loop_ub; i5++) {
    dists[r2[i5] - 1] = rtInfF;
  }
  b_end = angleCosines.size(0);
  for (int h_i{0}; h_i < b_end; h_i++) {
    if (angleCosines[h_i] < 0.0F) {
      dists[h_i] = rtInfF;
    }
  }
  ::coder::internal::minimum(dists, &b_x, &iindx);
  neighborIdx = static_cast<double>(iindx);
  if (std::isinf(b_x)) {
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
  array<double, 2U> b_index;
  array<double, 2U> currCurve;
  array<double, 2U> r3;
  array<double, 2U> r5;
  array<double, 2U> r7;
  array<double, 2U> r9;
  array<double, 2U> removedIdx;
  array<double, 1U> b_this;
  array<double, 1U> c_this;
  array<int, 2U> r2;
  array<int, 2U> r4;
  array<int, 2U> r6;
  array<int, 2U> r8;
  array<int, 1U> c_ii;
  array<bool, 2U> r;
  array<bool, 2U> r1;
  double coordsToUse[2];
  double currPt[2];
  double dv[2];
  double b_y;
  double y;
  int b_end;
  int b_loop_ub;
  int b_partialTrueCount;
  int b_trueCount;
  int c_end;
  int c_loop_ub;
  int c_partialTrueCount;
  int c_trueCount;
  int d_end;
  int d_loop_ub;
  int d_partialTrueCount;
  int d_trueCount;
  int e_loop_ub;
  int end;
  int f_loop_ub;
  int g_loop_ub;
  int h_loop_ub;
  int i9;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  int unnamed_idx_1;
  loop_ub = BoardIdx.size(1);
  r.set_size(1, loop_ub);
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    r[b_i] = (BoardIdx[BoardIdx.size(0) * b_i] > 0.0);
  }
  b_loop_ub = BoardIdx.size(1);
  r1.set_size(1, b_loop_ub);
  for (int i1{0}; i1 < b_loop_ub; i1++) {
    r1[i1] = (BoardIdx[(BoardIdx.size(0) * i1) + 1] > 0.0);
  }
  end = r.size(1) - 1;
  trueCount = 0;
  for (int c_i{0}; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      trueCount++;
    }
  }
  r2.set_size(1, trueCount);
  partialTrueCount = 0;
  for (int d_i{0}; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      r2[partialTrueCount] = d_i + 1;
      partialTrueCount++;
    }
  }
  r3.set_size(1, r2.size(1));
  c_loop_ub = r2.size(1);
  for (int i2{0}; i2 < c_loop_ub; i2++) {
    r3[i2] = BoardCoords[(BoardCoords.size(0) * (r2[i2] - 1)) + 1];
  }
  b_end = r.size(1) - 1;
  b_trueCount = 0;
  for (int e_i{0}; e_i <= b_end; e_i++) {
    if ((r[e_i]) && (r1[e_i])) {
      b_trueCount++;
    }
  }
  r4.set_size(1, b_trueCount);
  b_partialTrueCount = 0;
  for (int g_i{0}; g_i <= b_end; g_i++) {
    if ((r[g_i]) && (r1[g_i])) {
      r4[b_partialTrueCount] = g_i + 1;
      b_partialTrueCount++;
    }
  }
  r5.set_size(1, r4.size(1));
  d_loop_ub = r4.size(1);
  for (int i3{0}; i3 < d_loop_ub; i3++) {
    r5[i3] = BoardCoords[BoardCoords.size(0) * (r4[i3] - 1)];
  }
  c_end = r.size(1) - 1;
  c_trueCount = 0;
  for (int h_i{0}; h_i <= c_end; h_i++) {
    if ((r[h_i]) && (r1[h_i])) {
      c_trueCount++;
    }
  }
  r6.set_size(1, c_trueCount);
  c_partialTrueCount = 0;
  for (int o_i{0}; o_i <= c_end; o_i++) {
    if ((r[o_i]) && (r1[o_i])) {
      r6[c_partialTrueCount] = o_i + 1;
      c_partialTrueCount++;
    }
  }
  r7.set_size(1, r6.size(1));
  e_loop_ub = r6.size(1);
  for (int i4{0}; i4 < e_loop_ub; i4++) {
    r7[i4] = BoardCoords[((BoardCoords.size(0) * (r6[i4] - 1)) +
                          (BoardCoords.size(0) * BoardCoords.size(1))) +
                         1];
  }
  d_end = r.size(1) - 1;
  d_trueCount = 0;
  for (int q_i{0}; q_i <= d_end; q_i++) {
    if ((r[q_i]) && (r1[q_i])) {
      d_trueCount++;
    }
  }
  r8.set_size(1, d_trueCount);
  d_partialTrueCount = 0;
  for (int w_i{0}; w_i <= d_end; w_i++) {
    if ((r[w_i]) && (r1[w_i])) {
      r8[d_partialTrueCount] = w_i + 1;
      d_partialTrueCount++;
    }
  }
  r9.set_size(1, r8.size(1));
  f_loop_ub = r8.size(1);
  for (int i5{0}; i5 < f_loop_ub; i5++) {
    r9[i5] = BoardCoords[(BoardCoords.size(0) * (r8[i5] - 1)) +
                         (BoardCoords.size(0) * BoardCoords.size(1))];
  }
  r3.set_size(1, r3.size(1));
  g_loop_ub = r3.size(1);
  for (int i6{0}; i6 < g_loop_ub; i6++) {
    r3[i6] = r3[i6] - r5[i6];
  }
  r7.set_size(1, r7.size(1));
  h_loop_ub = r7.size(1);
  for (int i7{0}; i7 < h_loop_ub; i7++) {
    r7[i7] = r7[i7] - r9[i7];
  }
  if (std::abs(mean(r3)) > std::abs(mean(r7))) {
    coordsToUse[0] = 1.0;
    coordsToUse[1] = 2.0;
  } else {
    coordsToUse[0] = 2.0;
    coordsToUse[1] = 1.0;
  }
  unnamed_idx_1 = BoardCoords.size(1);
  newIndices.set_size(1, unnamed_idx_1);
  for (int i8{0}; i8 < unnamed_idx_1; i8++) {
    newIndices[i8] = 0.0;
  }
  removedIdx.set_size(1, 0);
  i9 = BoardCoords.size(1);
  for (int j{0}; j < i9; j++) {
    int i_loop_ub;
    i_loop_ub = BoardCoords.size(0);
    b_this.set_size(i_loop_ub);
    for (int i10{0}; i10 < i_loop_ub; i10++) {
      b_this[i10] = BoardCoords[(i10 + (BoardCoords.size(0) * j)) +
                                ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                 ((static_cast<int>(coordsToUse[0])) - 1))];
    }
    eml_find(b_this, c_ii);
    if (c_ii.size(0) >= 2) {
      double coordDist;
      double coordDist_tmp;
      double currCoord;
      double currRad;
      int c_n;
      int d_n;
      int i11;
      int i12;
      bool exitg1;
      i11 = static_cast<int>(coordsToUse[0]);
      coordDist_tmp =
          BoardCoords[((c_ii[0] + (BoardCoords.size(0) * j)) +
                       ((BoardCoords.size(0) * BoardCoords.size(1)) *
                        (i11 - 1))) -
                      1];
      coordDist =
          (coordDist_tmp -
           BoardCoords[((c_ii[1] + (BoardCoords.size(0) * j)) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) *
                         (i11 - 1))) -
                       1]) /
          ((static_cast<double>(c_ii[1])) - (static_cast<double>(c_ii[0])));
      c_n = 0;
      i12 = c_ii.size(0);
      b_this.set_size(c_ii.size(0));
      c_this.set_size(c_ii.size(0));
      for (int k{0}; k < i12; k++) {
        if (c_ii[k] != 0) {
          c_n++;
        }
        b_this[k] = BoardCoords[((c_ii[k] + (BoardCoords.size(0) * j)) +
                                 ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                  (i11 - 1))) -
                                1];
        c_this[k] = BoardCoords[((c_ii[k] + (BoardCoords.size(0) * j)) +
                                 ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                  ((static_cast<int>(coordsToUse[1])) - 1))) -
                                1];
      }
      if (c_n > 5) {
        d_n = 4;
      } else {
        d_n = 2;
      }
      polyfit(b_this, c_this, static_cast<double>(d_n), currCurve);
      currRad = coordDist / 4.0;
      currCoord = currRad + coordDist_tmp;
      exitg1 = false;
      while ((!exitg1) &&
             (std::abs(currCoord - coordDist_tmp) <
              (((static_cast<double>(c_ii[0])) * 1.5) * std::abs(coordDist)))) {
        dv[0] = 1.0;
        dv[1] = 2.0;
        if (isequal(coordsToUse, dv)) {
          if (currCurve.size(1) != 0) {
            int i14;
            b_y = currCurve[0];
            i14 = currCurve.size(1);
            for (int c_k{0}; c_k <= (i14 - 2); c_k++) {
              b_y = (currCoord * b_y) + currCurve[c_k + 1];
            }
          }
          currPt[0] = currCoord;
          currPt[1] = b_y;
        } else {
          if (currCurve.size(1) != 0) {
            int i13;
            y = currCurve[0];
            i13 = currCurve.size(1);
            for (int b_k{0}; b_k <= (i13 - 2); b_k++) {
              y = (currCoord * y) + currCurve[b_k + 1];
            }
          }
          currPt[0] = y;
          currPt[1] = currCoord;
        }
        findClosestOnCurve(currPt, std::abs(currRad), currCurve, coordsToUse,
                           removedIdx, b_index);
        if (b_index.size(1) != 0) {
          int i15;
          int j_loop_ub;
          newIndices[j] = b_index[0];
          i15 = removedIdx.size(1);
          j_loop_ub = b_index.size(1);
          removedIdx.set_size(removedIdx.size(0),
                              removedIdx.size(1) + b_index.size(1));
          for (int i16{0}; i16 < j_loop_ub; i16++) {
            removedIdx[i15 + i16] = b_index[i16];
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
  array<double, 2U> b_index;
  array<double, 2U> currCurve;
  array<double, 2U> r3;
  array<double, 2U> r5;
  array<double, 2U> r7;
  array<double, 2U> r9;
  array<double, 2U> removedIdx;
  array<double, 1U> b_this;
  array<double, 1U> c_this;
  array<int, 2U> r2;
  array<int, 2U> r4;
  array<int, 2U> r6;
  array<int, 2U> r8;
  array<int, 1U> c_ii;
  array<bool, 2U> r;
  array<bool, 2U> r1;
  double coordsToUse[2];
  double currPt[2];
  double dv[2];
  double b_y;
  double y;
  int b_end;
  int b_idx_tmp;
  int b_loop_ub;
  int b_partialTrueCount;
  int b_trueCount;
  int c_end;
  int c_loop_ub;
  int c_partialTrueCount;
  int c_trueCount;
  int d_end;
  int d_loop_ub;
  int d_partialTrueCount;
  int d_trueCount;
  int e_loop_ub;
  int end;
  int f_loop_ub;
  int g_loop_ub;
  int h_loop_ub;
  int i9;
  int idx_tmp;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  int unnamed_idx_1;
  idx_tmp = static_cast<int>(idx[0]);
  loop_ub = BoardIdx.size(1);
  r.set_size(1, loop_ub);
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    r[b_i] = (BoardIdx[(idx_tmp + (BoardIdx.size(0) * b_i)) - 1] > 0.0);
  }
  b_idx_tmp = static_cast<int>(idx[1]);
  b_loop_ub = BoardIdx.size(1);
  r1.set_size(1, b_loop_ub);
  for (int i1{0}; i1 < b_loop_ub; i1++) {
    r1[i1] = (BoardIdx[(b_idx_tmp + (BoardIdx.size(0) * i1)) - 1] > 0.0);
  }
  end = r.size(1) - 1;
  trueCount = 0;
  for (int c_i{0}; c_i <= end; c_i++) {
    if ((r[c_i]) && (r1[c_i])) {
      trueCount++;
    }
  }
  r2.set_size(1, trueCount);
  partialTrueCount = 0;
  for (int d_i{0}; d_i <= end; d_i++) {
    if ((r[d_i]) && (r1[d_i])) {
      r2[partialTrueCount] = d_i + 1;
      partialTrueCount++;
    }
  }
  r3.set_size(1, r2.size(1));
  c_loop_ub = r2.size(1);
  for (int i2{0}; i2 < c_loop_ub; i2++) {
    r3[i2] =
        BoardCoords[(b_idx_tmp + (BoardCoords.size(0) * (r2[i2] - 1))) - 1];
  }
  b_end = r.size(1) - 1;
  b_trueCount = 0;
  for (int e_i{0}; e_i <= b_end; e_i++) {
    if ((r[e_i]) && (r1[e_i])) {
      b_trueCount++;
    }
  }
  r4.set_size(1, b_trueCount);
  b_partialTrueCount = 0;
  for (int g_i{0}; g_i <= b_end; g_i++) {
    if ((r[g_i]) && (r1[g_i])) {
      r4[b_partialTrueCount] = g_i + 1;
      b_partialTrueCount++;
    }
  }
  r5.set_size(1, r4.size(1));
  d_loop_ub = r4.size(1);
  for (int i3{0}; i3 < d_loop_ub; i3++) {
    r5[i3] = BoardCoords[(idx_tmp + (BoardCoords.size(0) * (r4[i3] - 1))) - 1];
  }
  c_end = r.size(1) - 1;
  c_trueCount = 0;
  for (int h_i{0}; h_i <= c_end; h_i++) {
    if ((r[h_i]) && (r1[h_i])) {
      c_trueCount++;
    }
  }
  r6.set_size(1, c_trueCount);
  c_partialTrueCount = 0;
  for (int o_i{0}; o_i <= c_end; o_i++) {
    if ((r[o_i]) && (r1[o_i])) {
      r6[c_partialTrueCount] = o_i + 1;
      c_partialTrueCount++;
    }
  }
  r7.set_size(1, r6.size(1));
  e_loop_ub = r6.size(1);
  for (int i4{0}; i4 < e_loop_ub; i4++) {
    r7[i4] = BoardCoords[((b_idx_tmp + (BoardCoords.size(0) * (r6[i4] - 1))) +
                          (BoardCoords.size(0) * BoardCoords.size(1))) -
                         1];
  }
  d_end = r.size(1) - 1;
  d_trueCount = 0;
  for (int q_i{0}; q_i <= d_end; q_i++) {
    if ((r[q_i]) && (r1[q_i])) {
      d_trueCount++;
    }
  }
  r8.set_size(1, d_trueCount);
  d_partialTrueCount = 0;
  for (int w_i{0}; w_i <= d_end; w_i++) {
    if ((r[w_i]) && (r1[w_i])) {
      r8[d_partialTrueCount] = w_i + 1;
      d_partialTrueCount++;
    }
  }
  r9.set_size(1, r8.size(1));
  f_loop_ub = r8.size(1);
  for (int i5{0}; i5 < f_loop_ub; i5++) {
    r9[i5] = BoardCoords[((idx_tmp + (BoardCoords.size(0) * (r8[i5] - 1))) +
                          (BoardCoords.size(0) * BoardCoords.size(1))) -
                         1];
  }
  r3.set_size(1, r3.size(1));
  g_loop_ub = r3.size(1);
  for (int i6{0}; i6 < g_loop_ub; i6++) {
    r3[i6] = r3[i6] - r5[i6];
  }
  r7.set_size(1, r7.size(1));
  h_loop_ub = r7.size(1);
  for (int i7{0}; i7 < h_loop_ub; i7++) {
    r7[i7] = r7[i7] - r9[i7];
  }
  if (std::abs(mean(r3)) > std::abs(mean(r7))) {
    coordsToUse[0] = 1.0;
    coordsToUse[1] = 2.0;
  } else {
    coordsToUse[0] = 2.0;
    coordsToUse[1] = 1.0;
  }
  unnamed_idx_1 = BoardCoords.size(1);
  newIndices.set_size(1, unnamed_idx_1);
  for (int i8{0}; i8 < unnamed_idx_1; i8++) {
    newIndices[i8] = 0.0;
  }
  removedIdx.set_size(1, 0);
  i9 = BoardCoords.size(1);
  for (int j{0}; j < i9; j++) {
    int i_loop_ub;
    i_loop_ub = BoardCoords.size(0);
    b_this.set_size(i_loop_ub);
    for (int i10{0}; i10 < i_loop_ub; i10++) {
      b_this[i10] = BoardCoords[(i10 + (BoardCoords.size(0) * j)) +
                                ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                 ((static_cast<int>(coordsToUse[0])) - 1))];
    }
    eml_find(b_this, c_ii);
    if (c_ii.size(0) >= 2) {
      double coordDist;
      double currCoord;
      double currRad;
      double moveDistMultiplier;
      double refCoordValue;
      int c_n;
      int d_n;
      int firstValidIdx;
      int i12;
      int i13;
      bool exitg1;
      if (idx[0] == 1.0) {
        int i11;
        moveDistMultiplier = static_cast<double>(c_ii[0]);
        firstValidIdx = c_ii[0];
        i11 = static_cast<int>(coordsToUse[0]);
        i12 = i11;
        coordDist =
            (BoardCoords[((c_ii[0] + (BoardCoords.size(0) * j)) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) *
                           (i11 - 1))) -
                         1] -
             BoardCoords[((c_ii[1] + (BoardCoords.size(0) * j)) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) *
                           (i11 - 1))) -
                         1]) /
            ((static_cast<double>(c_ii[1])) - (static_cast<double>(c_ii[0])));
      } else {
        int i11;
        moveDistMultiplier = ((static_cast<double>(BoardCoords.size(0))) -
                              (static_cast<double>(c_ii[c_ii.size(0) - 1]))) +
                             1.0;
        firstValidIdx = c_ii[c_ii.size(0) - 1];
        i11 = static_cast<int>(coordsToUse[0]);
        i12 = i11;
        coordDist =
            (BoardCoords[((c_ii[c_ii.size(0) - 1] + (BoardCoords.size(0) * j)) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) *
                           (i11 - 1))) -
                         1] -
             BoardCoords[((c_ii[c_ii.size(0) - 2] + (BoardCoords.size(0) * j)) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) *
                           (i11 - 1))) -
                         1]) /
            ((static_cast<double>(c_ii[c_ii.size(0) - 1])) -
             (static_cast<double>(c_ii[c_ii.size(0) - 2])));
      }
      c_n = 0;
      i13 = c_ii.size(0);
      b_this.set_size(c_ii.size(0));
      c_this.set_size(c_ii.size(0));
      for (int k{0}; k < i13; k++) {
        if (c_ii[k] != 0) {
          c_n++;
        }
        b_this[k] = BoardCoords[((c_ii[k] + (BoardCoords.size(0) * j)) +
                                 ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                  (i12 - 1))) -
                                1];
        c_this[k] = BoardCoords[((c_ii[k] + (BoardCoords.size(0) * j)) +
                                 ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                  ((static_cast<int>(coordsToUse[1])) - 1))) -
                                1];
      }
      if (c_n > 5) {
        d_n = 4;
      } else {
        d_n = 2;
      }
      polyfit(b_this, c_this, static_cast<double>(d_n), currCurve);
      currRad = coordDist / 4.0;
      refCoordValue =
          BoardCoords[((firstValidIdx + (BoardCoords.size(0) * j)) +
                       ((BoardCoords.size(0) * BoardCoords.size(1)) *
                        ((static_cast<int>(coordsToUse[0])) - 1))) -
                      1];
      currCoord = currRad + refCoordValue;
      exitg1 = false;
      while ((!exitg1) &&
             (std::abs(currCoord - refCoordValue) <
              ((moveDistMultiplier * 1.5) * std::abs(coordDist)))) {
        dv[0] = 1.0;
        dv[1] = 2.0;
        if (isequal(coordsToUse, dv)) {
          if (currCurve.size(1) != 0) {
            int i15;
            b_y = currCurve[0];
            i15 = currCurve.size(1);
            for (int c_k{0}; c_k <= (i15 - 2); c_k++) {
              b_y = (currCoord * b_y) + currCurve[c_k + 1];
            }
          }
          currPt[0] = currCoord;
          currPt[1] = b_y;
        } else {
          if (currCurve.size(1) != 0) {
            int i14;
            y = currCurve[0];
            i14 = currCurve.size(1);
            for (int b_k{0}; b_k <= (i14 - 2); b_k++) {
              y = (currCoord * y) + currCurve[b_k + 1];
            }
          }
          currPt[0] = y;
          currPt[1] = currCoord;
        }
        findClosestOnCurve(currPt, std::abs(currRad), currCurve, coordsToUse,
                           removedIdx, b_index);
        if (b_index.size(1) != 0) {
          int i16;
          int j_loop_ub;
          newIndices[j] = b_index[0];
          i16 = removedIdx.size(1);
          j_loop_ub = b_index.size(1);
          removedIdx.set_size(removedIdx.size(0),
                              removedIdx.size(1) + b_index.size(1));
          for (int i17{0}; i17 < j_loop_ub; i17++) {
            removedIdx[i16 + i17] = b_index[i17];
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
  float b;
  float b_a;
  float y;
  b_a = std::abs(u0);
  b = std::abs(u1);
  if (b_a < b) {
    b_a /= b;
    y = b * std::sqrt((b_a * b_a) + 1.0F);
  } else if (b_a > b) {
    b /= b_a;
    y = b_a * std::sqrt((b * b) + 1.0F);
  } else if (std::isnan(b)) {
    y = b;
  } else {
    y = b_a * 1.41421354F;
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
  array<double, 3U> b_this;
  array<double, 3U> c_this;
  array<double, 3U> r1;
  array<double, 2U> idx;
  array<double, 2U> newIndices;
  array<double, 2U> newIndicesLinear;
  array<double, 2U> p1;
  array<double, 2U> p2;
  array<double, 2U> r;
  array<double, 2U> r4;
  array<int, 2U> r3;
  array<int, 2U> r5;
  array<int, 1U> r2;
  float newEnergy;
  float oldEnergy;
  oldEnergy = (Energy + (static_cast<float>(static_cast<int>(
                            BoardIdx.size(0) * BoardIdx.size(1))))) /
              (static_cast<float>(
                  static_cast<int>(BoardIdx.size(0) * BoardIdx.size(1))));
  switch (static_cast<int>(direction)) {
  case 1: {
    int qb_loop_ub;
    int u_loop_ub;
    if (IsDistortionHigh) {
      int k;
      bool exitg1;
      bool y;
      fitPolynomialIndices(newIndices);
      y = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= (newIndices.size(1) - 1))) {
        if (newIndices[k] == 0.0) {
          y = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
      if (!y) {
        int ac_loop_ub;
        int db_loop_ub;
        int end;
        int kb_loop_ub;
        int p_loop_ub;
        int s_loop_ub;
        p_loop_ub = BoardCoords.size(1);
        s_loop_ub = BoardCoords.size(2);
        b_this.set_size(1, p_loop_ub, s_loop_ub);
        for (int i10{0}; i10 < s_loop_ub; i10++) {
          for (int i17{0}; i17 < p_loop_ub; i17++) {
            b_this[i17 + (b_this.size(1) * i10)] =
                BoardCoords[((BoardCoords.size(0) * i17) +
                             ((BoardCoords.size(0) * BoardCoords.size(1)) *
                              i10)) +
                            1];
          }
        }
        squeeze(b_this, p1);
        db_loop_ub = BoardCoords.size(1);
        kb_loop_ub = BoardCoords.size(2);
        b_this.set_size(1, db_loop_ub, kb_loop_ub);
        for (int i30{0}; i30 < kb_loop_ub; i30++) {
          for (int i40{0}; i40 < db_loop_ub; i40++) {
            b_this[i40 + (b_this.size(1) * i30)] =
                BoardCoords[(BoardCoords.size(0) * i40) +
                            ((BoardCoords.size(0) * BoardCoords.size(1)) *
                             i30)];
          }
        }
        squeeze(b_this, p2);
        ac_loop_ub = p2.size(1);
        for (int i48{0}; i48 < ac_loop_ub; i48++) {
          int oc_loop_ub;
          oc_loop_ub = p2.size(0);
          for (int i58{0}; i58 < oc_loop_ub; i58++) {
            double d4;
            d4 = p2[i58 + (p2.size(0) * i48)];
            d4 = (d4 + d4) - p1[i58 + (p1.size(0) * i48)];
            p2[i58 + (p2.size(0) * i48)] = d4;
          }
        }
        findClosestIndices(p2, newIndicesLinear);
        end = newIndices.size(1);
        for (int c_i{0}; c_i < end; c_i++) {
          if (newIndices[c_i] == 0.0) {
            newIndices[c_i] = newIndicesLinear[c_i];
          }
        }
      }
    } else {
      int c_loop_ub;
      int i_loop_ub;
      int loop_ub;
      int o_loop_ub;
      int w_loop_ub;
      loop_ub = BoardCoords.size(1);
      c_loop_ub = BoardCoords.size(2);
      b_this.set_size(1, loop_ub, c_loop_ub);
      for (int b_i{0}; b_i < c_loop_ub; b_i++) {
        for (int i4{0}; i4 < loop_ub; i4++) {
          b_this[i4 + (b_this.size(1) * b_i)] =
              BoardCoords[((BoardCoords.size(0) * i4) +
                           ((BoardCoords.size(0) * BoardCoords.size(1)) *
                            b_i)) +
                          1];
        }
      }
      squeeze(b_this, p1);
      i_loop_ub = BoardCoords.size(1);
      o_loop_ub = BoardCoords.size(2);
      b_this.set_size(1, i_loop_ub, o_loop_ub);
      for (int i8{0}; i8 < o_loop_ub; i8++) {
        for (int i14{0}; i14 < i_loop_ub; i14++) {
          b_this[i14 + (b_this.size(1) * i8)] =
              BoardCoords[(BoardCoords.size(0) * i14) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * i8)];
        }
      }
      squeeze(b_this, p2);
      w_loop_ub = p2.size(1);
      for (int i20{0}; i20 < w_loop_ub; i20++) {
        int pb_loop_ub;
        pb_loop_ub = p2.size(0);
        for (int i28{0}; i28 < pb_loop_ub; i28++) {
          double d;
          d = p2[i28 + (p2.size(0) * i20)];
          d = (d + d) - p1[i28 + (p1.size(0) * i20)];
          p2[i28 + (p2.size(0) * i20)] = d;
        }
      }
      findClosestIndices(p2, newIndices);
    }
    expandBoardUp(newIndices, r, r1);
    BoardIdx.set_size(r.size(0), r.size(1));
    u_loop_ub = r.size(1);
    for (int i16{0}; i16 < u_loop_ub; i16++) {
      int jb_loop_ub;
      jb_loop_ub = r.size(0);
      for (int i22{0}; i22 < jb_loop_ub; i22++) {
        BoardIdx[i22 + (BoardIdx.size(0) * i16)] = r[i22 + (r.size(0) * i16)];
      }
    }
    BoardCoords.set_size(r1.size(0), r1.size(1), r1.size(2));
    qb_loop_ub = r1.size(2);
    for (int i29{0}; i29 < qb_loop_ub; i29++) {
      int ub_loop_ub;
      ub_loop_ub = r1.size(1);
      for (int i43{0}; i43 < ub_loop_ub; i43++) {
        int ic_loop_ub;
        ic_loop_ub = r1.size(0);
        for (int i52{0}; i52 < ic_loop_ub; i52++) {
          BoardCoords[(i52 + (BoardCoords.size(0) * i43)) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * i29)] =
              r1[(i52 + (r1.size(0) * i43)) +
                 ((r1.size(0) * r1.size(1)) * i29)];
        }
      }
    }
    newEnergy = computeNewEnergyVertical(oldEnergy);
  } break;
  case 2: {
    int ad_loop_ub;
    int b_partialTrueCount;
    int b_this_idx_0;
    int b_this_idx_1;
    int b_trueCount;
    int bc_loop_ub;
    int bd_loop_ub;
    int d_this;
    int dd_loop_ub;
    int e_end;
    int e_this;
    int ed_loop_ub;
    int f_end;
    int gd_loop_ub;
    int jd_loop_ub;
    int md_loop_ub;
    int numRows;
    int partialTrueCount;
    int pc_loop_ub;
    int this_idx_0;
    int this_idx_1;
    int this_idx_2;
    int trueCount;
    int unnamed_idx_1;
    numRows = BoardCoords.size(0);
    if ((static_cast<double>(numRows)) <
        ((static_cast<double>(numRows)) - 2.0)) {
      idx.set_size(1, 0);
    } else {
      int d_loop_ub;
      d_loop_ub = static_cast<int>(
          static_cast<double>(-(((static_cast<double>(numRows)) - 2.0) -
                                (static_cast<double>(numRows)))));
      idx.set_size(1, d_loop_ub + 1);
      for (int i1{0}; i1 <= d_loop_ub; i1++) {
        idx[i1] = (static_cast<double>(numRows)) - (static_cast<double>(i1));
      }
    }
    if (IsDistortionHigh) {
      int c_k;
      bool c_y;
      bool exitg1;
      fitPolynomialIndices(idx, newIndices);
      c_y = true;
      c_k = 0;
      exitg1 = false;
      while ((!exitg1) && (c_k <= (newIndices.size(1) - 1))) {
        if (newIndices[c_k] == 0.0) {
          c_y = false;
          exitg1 = true;
        } else {
          c_k++;
        }
      }
      if (!c_y) {
        int c_end;
        int cc_loop_ub;
        int e_idx;
        int fb_loop_ub;
        int gc_loop_ub;
        int h_idx;
        int uc_loop_ub;
        int y_loop_ub;
        e_idx = static_cast<int>(idx[1]);
        y_loop_ub = BoardCoords.size(1);
        fb_loop_ub = BoardCoords.size(2);
        b_this.set_size(1, y_loop_ub, fb_loop_ub);
        for (int i24{0}; i24 < fb_loop_ub; i24++) {
          for (int i37{0}; i37 < y_loop_ub; i37++) {
            b_this[i37 + (b_this.size(1) * i24)] =
                BoardCoords[((e_idx + (BoardCoords.size(0) * i37)) +
                             ((BoardCoords.size(0) * BoardCoords.size(1)) *
                              i24)) -
                            1];
          }
        }
        squeeze(b_this, p1);
        h_idx = static_cast<int>(idx[0]);
        cc_loop_ub = BoardCoords.size(1);
        gc_loop_ub = BoardCoords.size(2);
        b_this.set_size(1, cc_loop_ub, gc_loop_ub);
        for (int i54{0}; i54 < gc_loop_ub; i54++) {
          for (int i62{0}; i62 < cc_loop_ub; i62++) {
            b_this[i62 + (b_this.size(1) * i54)] =
                BoardCoords[((h_idx + (BoardCoords.size(0) * i62)) +
                             ((BoardCoords.size(0) * BoardCoords.size(1)) *
                              i54)) -
                            1];
          }
        }
        squeeze(b_this, p2);
        uc_loop_ub = p2.size(1);
        for (int i66{0}; i66 < uc_loop_ub; i66++) {
          int xc_loop_ub;
          xc_loop_ub = p2.size(0);
          for (int i70{0}; i70 < xc_loop_ub; i70++) {
            double d6;
            d6 = p2[i70 + (p2.size(0) * i66)];
            d6 = (d6 + d6) - p1[i70 + (p1.size(0) * i66)];
            p2[i70 + (p2.size(0) * i66)] = d6;
          }
        }
        findClosestIndices(p2, newIndicesLinear);
        c_end = newIndices.size(1);
        for (int e_i{0}; e_i < c_end; e_i++) {
          if (newIndices[e_i] == 0.0) {
            newIndices[e_i] = newIndicesLinear[e_i];
          }
        }
      }
    } else {
      int b_idx;
      int d_idx;
      int eb_loop_ub;
      int g_loop_ub;
      int j_loop_ub;
      int vb_loop_ub;
      int x_loop_ub;
      b_idx = static_cast<int>(idx[1]);
      g_loop_ub = BoardCoords.size(1);
      j_loop_ub = BoardCoords.size(2);
      b_this.set_size(1, g_loop_ub, j_loop_ub);
      for (int i6{0}; i6 < j_loop_ub; i6++) {
        for (int i11{0}; i11 < g_loop_ub; i11++) {
          b_this[i11 + (b_this.size(1) * i6)] =
              BoardCoords[((b_idx + (BoardCoords.size(0) * i11)) +
                           ((BoardCoords.size(0) * BoardCoords.size(1)) * i6)) -
                          1];
        }
      }
      squeeze(b_this, p1);
      d_idx = static_cast<int>(idx[0]);
      x_loop_ub = BoardCoords.size(1);
      eb_loop_ub = BoardCoords.size(2);
      b_this.set_size(1, x_loop_ub, eb_loop_ub);
      for (int i23{0}; i23 < eb_loop_ub; i23++) {
        for (int i36{0}; i36 < x_loop_ub; i36++) {
          b_this[i36 + (b_this.size(1) * i23)] =
              BoardCoords[((d_idx + (BoardCoords.size(0) * i36)) +
                           ((BoardCoords.size(0) * BoardCoords.size(1)) *
                            i23)) -
                          1];
        }
      }
      squeeze(b_this, p2);
      vb_loop_ub = p2.size(1);
      for (int i44{0}; i44 < vb_loop_ub; i44++) {
        int jc_loop_ub;
        jc_loop_ub = p2.size(0);
        for (int i53{0}; i53 < jc_loop_ub; i53++) {
          double d2;
          d2 = p2[i53 + (p2.size(0) * i44)];
          d2 = (d2 + d2) - p1[i53 + (p1.size(0) * i44)];
          p2[i53 + (p2.size(0) * i44)] = d2;
        }
      }
      findClosestIndices(p2, newIndices);
    }
    this_idx_0 = BoardIdx.size(0) + 1;
    this_idx_1 = BoardIdx.size(1);
    r.set_size(this_idx_0, this_idx_1);
    for (int i31{0}; i31 < this_idx_1; i31++) {
      for (int i41{0}; i41 < this_idx_0; i41++) {
        r[i41 + (r.size(0) * i31)] = 0.0;
      }
    }
    d_this = BoardIdx.size(0);
    bc_loop_ub = newIndices.size(1);
    for (int i49{0}; i49 < bc_loop_ub; i49++) {
      r[d_this + (r.size(0) * i49)] = newIndices[i49];
    }
    pc_loop_ub = BoardIdx.size(1);
    for (int i59{0}; i59 < pc_loop_ub; i59++) {
      int tc_loop_ub;
      tc_loop_ub = BoardIdx.size(0);
      for (int i65{0}; i65 < tc_loop_ub; i65++) {
        r[i65 + (r.size(0) * i59)] = BoardIdx[i65 + (BoardIdx.size(0) * i59)];
      }
    }
    b_this_idx_0 = BoardCoords.size(0) + 1;
    b_this_idx_1 = BoardCoords.size(1);
    this_idx_2 = BoardCoords.size(2);
    r1.set_size(b_this_idx_0, b_this_idx_1, this_idx_2);
    for (int i69{0}; i69 < this_idx_2; i69++) {
      for (int i72{0}; i72 < b_this_idx_1; i72++) {
        for (int i74{0}; i74 < b_this_idx_0; i74++) {
          r1[(i74 + (r1.size(0) * i72)) + ((r1.size(0) * r1.size(1)) * i69)] =
              0.0;
        }
      }
    }
    ad_loop_ub = BoardCoords.size(2);
    r2.set_size(ad_loop_ub);
    for (int i73{0}; i73 < ad_loop_ub; i73++) {
      r2[i73] = i73;
    }
    e_end = newIndices.size(1) - 1;
    trueCount = 0;
    for (int h_i{0}; h_i <= e_end; h_i++) {
      if (newIndices[h_i] > 0.0) {
        trueCount++;
      }
    }
    r3.set_size(1, trueCount);
    partialTrueCount = 0;
    for (int o_i{0}; o_i <= e_end; o_i++) {
      if (newIndices[o_i] > 0.0) {
        r3[partialTrueCount] = o_i + 1;
        partialTrueCount++;
      }
    }
    bd_loop_ub = Points.size(1);
    r4.set_size(r3.size(1), bd_loop_ub);
    for (int i75{0}; i75 < bd_loop_ub; i75++) {
      int cd_loop_ub;
      cd_loop_ub = r3.size(1);
      for (int i76{0}; i76 < cd_loop_ub; i76++) {
        r4[i76 + (r4.size(0) * i75)] = static_cast<double>(
            Points[((static_cast<int>(newIndices[r3[i76] - 1])) +
                    (Points.size(0) * i75)) -
                   1]);
      }
    }
    f_end = newIndices.size(1) - 1;
    b_trueCount = 0;
    for (int q_i{0}; q_i <= f_end; q_i++) {
      if (newIndices[q_i] > 0.0) {
        b_trueCount++;
      }
    }
    r5.set_size(1, b_trueCount);
    b_partialTrueCount = 0;
    for (int w_i{0}; w_i <= f_end; w_i++) {
      if (newIndices[w_i] > 0.0) {
        r5[b_partialTrueCount] = w_i + 1;
        b_partialTrueCount++;
      }
    }
    unnamed_idx_1 = r5.size(1);
    e_this = BoardCoords.size(0);
    dd_loop_ub = r2.size(0);
    for (int i77{0}; i77 < dd_loop_ub; i77++) {
      for (int i78{0}; i78 < unnamed_idx_1; i78++) {
        r1[(e_this + (r1.size(0) * (r5[i78] - 1))) +
           ((r1.size(0) * r1.size(1)) * r2[i77])] =
            r4[i78 + (unnamed_idx_1 * i77)];
      }
    }
    ed_loop_ub = BoardCoords.size(2);
    for (int i79{0}; i79 < ed_loop_ub; i79++) {
      int fd_loop_ub;
      fd_loop_ub = BoardCoords.size(1);
      for (int i80{0}; i80 < fd_loop_ub; i80++) {
        int hd_loop_ub;
        hd_loop_ub = BoardCoords.size(0);
        for (int i82{0}; i82 < hd_loop_ub; i82++) {
          r1[(i82 + (r1.size(0) * i80)) + ((r1.size(0) * r1.size(1)) * i79)] =
              BoardCoords[(i82 + (BoardCoords.size(0) * i80)) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * i79)];
        }
      }
    }
    BoardIdx.set_size(r.size(0), r.size(1));
    gd_loop_ub = r.size(1);
    for (int i81{0}; i81 < gd_loop_ub; i81++) {
      int id_loop_ub;
      id_loop_ub = r.size(0);
      for (int i83{0}; i83 < id_loop_ub; i83++) {
        BoardIdx[i83 + (BoardIdx.size(0) * i81)] = r[i83 + (r.size(0) * i81)];
      }
    }
    BoardCoords.set_size(r1.size(0), r1.size(1), r1.size(2));
    jd_loop_ub = r1.size(2);
    for (int i84{0}; i84 < jd_loop_ub; i84++) {
      int kd_loop_ub;
      kd_loop_ub = r1.size(1);
      for (int i85{0}; i85 < kd_loop_ub; i85++) {
        int od_loop_ub;
        od_loop_ub = r1.size(0);
        for (int i87{0}; i87 < od_loop_ub; i87++) {
          BoardCoords[(i87 + (BoardCoords.size(0) * i85)) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * i84)] =
              r1[(i87 + (r1.size(0) * i85)) +
                 ((r1.size(0) * r1.size(1)) * i84)];
        }
      }
    }
    idx.set_size(1, idx.size(1));
    md_loop_ub = idx.size(1);
    for (int i86{0}; i86 < md_loop_ub; i86++) {
      idx[i86] = idx[i86] + 1.0;
    }
    newEnergy = computeNewEnergyVertical(idx, oldEnergy);
  } break;
  case 3: {
    int sb_loop_ub;
    int v_loop_ub;
    if (IsDistortionHigh) {
      int b_k;
      bool b_y;
      bool exitg1;
      b_fitPolynomialIndices(newIndices);
      b_y = true;
      b_k = 0;
      exitg1 = false;
      while ((!exitg1) && (b_k <= (newIndices.size(1) - 1))) {
        if (newIndices[b_k] == 0.0) {
          b_y = false;
          exitg1 = true;
        } else {
          b_k++;
        }
      }
      if (!b_y) {
        int b_end;
        int dc_loop_ub;
        int gb_loop_ub;
        int ob_loop_ub;
        int r_loop_ub;
        int t_loop_ub;
        r_loop_ub = BoardCoords.size(0);
        t_loop_ub = BoardCoords.size(2);
        c_this.set_size(r_loop_ub, 1, t_loop_ub);
        for (int i12{0}; i12 < t_loop_ub; i12++) {
          for (int i19{0}; i19 < r_loop_ub; i19++) {
            c_this[i19 + (c_this.size(0) * i12)] =
                BoardCoords[(i19 + BoardCoords.size(0)) +
                            ((BoardCoords.size(0) * BoardCoords.size(1)) *
                             i12)];
          }
        }
        b_squeeze(c_this, p1);
        gb_loop_ub = BoardCoords.size(0);
        ob_loop_ub = BoardCoords.size(2);
        c_this.set_size(gb_loop_ub, 1, ob_loop_ub);
        for (int i34{0}; i34 < ob_loop_ub; i34++) {
          for (int i42{0}; i42 < gb_loop_ub; i42++) {
            c_this[i42 + (c_this.size(0) * i34)] =
                BoardCoords[i42 + ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                   i34)];
          }
        }
        b_squeeze(c_this, p2);
        dc_loop_ub = p2.size(1);
        for (int i50{0}; i50 < dc_loop_ub; i50++) {
          int qc_loop_ub;
          qc_loop_ub = p2.size(0);
          for (int i60{0}; i60 < qc_loop_ub; i60++) {
            double d5;
            d5 = p2[i60 + (p2.size(0) * i50)];
            d5 = (d5 + d5) - p1[i60 + (p1.size(0) * i50)];
            p2[i60 + (p2.size(0) * i50)] = d5;
          }
        }
        findClosestIndices(p2, newIndicesLinear);
        b_end = newIndices.size(1);
        for (int d_i{0}; d_i < b_end; d_i++) {
          if (newIndices[d_i] == 0.0) {
            newIndices[d_i] = newIndicesLinear[d_i];
          }
        }
      }
    } else {
      int ab_loop_ub;
      int b_loop_ub;
      int e_loop_ub;
      int k_loop_ub;
      int q_loop_ub;
      b_loop_ub = BoardCoords.size(0);
      e_loop_ub = BoardCoords.size(2);
      c_this.set_size(b_loop_ub, 1, e_loop_ub);
      for (int i2{0}; i2 < e_loop_ub; i2++) {
        for (int i5{0}; i5 < b_loop_ub; i5++) {
          c_this[i5 + (c_this.size(0) * i2)] =
              BoardCoords[(i5 + BoardCoords.size(0)) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * i2)];
        }
      }
      b_squeeze(c_this, p1);
      k_loop_ub = BoardCoords.size(0);
      q_loop_ub = BoardCoords.size(2);
      c_this.set_size(k_loop_ub, 1, q_loop_ub);
      for (int i9{0}; i9 < q_loop_ub; i9++) {
        for (int i15{0}; i15 < k_loop_ub; i15++) {
          c_this[i15 + (c_this.size(0) * i9)] =
              BoardCoords[i15 +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * i9)];
        }
      }
      b_squeeze(c_this, p2);
      ab_loop_ub = p2.size(1);
      for (int i21{0}; i21 < ab_loop_ub; i21++) {
        int rb_loop_ub;
        rb_loop_ub = p2.size(0);
        for (int i32{0}; i32 < rb_loop_ub; i32++) {
          double b_d1;
          b_d1 = p2[i32 + (p2.size(0) * i21)];
          b_d1 = (b_d1 + b_d1) - p1[i32 + (p1.size(0) * i21)];
          p2[i32 + (p2.size(0) * i21)] = b_d1;
        }
      }
      findClosestIndices(p2, newIndices);
    }
    expandBoardLeft(newIndices, r, r1);
    BoardIdx.set_size(r.size(0), r.size(1));
    v_loop_ub = r.size(1);
    for (int i18{0}; i18 < v_loop_ub; i18++) {
      int mb_loop_ub;
      mb_loop_ub = r.size(0);
      for (int i25{0}; i25 < mb_loop_ub; i25++) {
        BoardIdx[i25 + (BoardIdx.size(0) * i18)] = r[i25 + (r.size(0) * i18)];
      }
    }
    BoardCoords.set_size(r1.size(0), r1.size(1), r1.size(2));
    sb_loop_ub = r1.size(2);
    for (int i33{0}; i33 < sb_loop_ub; i33++) {
      int wb_loop_ub;
      wb_loop_ub = r1.size(1);
      for (int i45{0}; i45 < wb_loop_ub; i45++) {
        int kc_loop_ub;
        kc_loop_ub = r1.size(0);
        for (int i55{0}; i55 < kc_loop_ub; i55++) {
          BoardCoords[(i55 + (BoardCoords.size(0) * i45)) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * i33)] =
              r1[(i55 + (r1.size(0) * i45)) +
                 ((r1.size(0) * r1.size(1)) * i33)];
        }
      }
    }
    newEnergy = computeNewEnergyHorizontal(oldEnergy);
  } break;
  case 4: {
    int ec_loop_ub;
    int numCols;
    int sc_loop_ub;
    int tb_loop_ub;
    numCols = BoardCoords.size(1);
    if ((static_cast<double>(numCols)) <
        ((static_cast<double>(numCols)) - 2.0)) {
      idx.set_size(1, 0);
    } else {
      int f_loop_ub;
      f_loop_ub = static_cast<int>(
          static_cast<double>(-(((static_cast<double>(numCols)) - 2.0) -
                                (static_cast<double>(numCols)))));
      idx.set_size(1, f_loop_ub + 1);
      for (int i3{0}; i3 <= f_loop_ub; i3++) {
        idx[i3] = (static_cast<double>(numCols)) - (static_cast<double>(i3));
      }
    }
    if (IsDistortionHigh) {
      int d_k;
      bool d_y;
      bool exitg1;
      b_fitPolynomialIndices(idx, newIndices);
      d_y = true;
      d_k = 0;
      exitg1 = false;
      while ((!exitg1) && (d_k <= (newIndices.size(1) - 1))) {
        if (newIndices[d_k] == 0.0) {
          d_y = false;
          exitg1 = true;
        } else {
          d_k++;
        }
      }
      if (!d_y) {
        int cb_loop_ub;
        int d_end;
        int fc_loop_ub;
        int g_idx;
        int hc_loop_ub;
        int ib_loop_ub;
        int j_idx;
        int wc_loop_ub;
        g_idx = static_cast<int>(idx[1]);
        cb_loop_ub = BoardCoords.size(0);
        ib_loop_ub = BoardCoords.size(2);
        c_this.set_size(cb_loop_ub, 1, ib_loop_ub);
        for (int i27{0}; i27 < ib_loop_ub; i27++) {
          for (int i39{0}; i39 < cb_loop_ub; i39++) {
            c_this[i39 + (c_this.size(0) * i27)] =
                BoardCoords[(i39 + (BoardCoords.size(0) * (g_idx - 1))) +
                            ((BoardCoords.size(0) * BoardCoords.size(1)) *
                             i27)];
          }
        }
        b_squeeze(c_this, p1);
        j_idx = static_cast<int>(idx[0]);
        fc_loop_ub = BoardCoords.size(0);
        hc_loop_ub = BoardCoords.size(2);
        c_this.set_size(fc_loop_ub, 1, hc_loop_ub);
        for (int i57{0}; i57 < hc_loop_ub; i57++) {
          for (int i64{0}; i64 < fc_loop_ub; i64++) {
            c_this[i64 + (c_this.size(0) * i57)] =
                BoardCoords[(i64 + (BoardCoords.size(0) * (j_idx - 1))) +
                            ((BoardCoords.size(0) * BoardCoords.size(1)) *
                             i57)];
          }
        }
        b_squeeze(c_this, p2);
        wc_loop_ub = p2.size(1);
        for (int i68{0}; i68 < wc_loop_ub; i68++) {
          int yc_loop_ub;
          yc_loop_ub = p2.size(0);
          for (int i71{0}; i71 < yc_loop_ub; i71++) {
            double d7;
            d7 = p2[i71 + (p2.size(0) * i68)];
            d7 = (d7 + d7) - p1[i71 + (p1.size(0) * i68)];
            p2[i71 + (p2.size(0) * i68)] = d7;
          }
        }
        findClosestIndices(p2, newIndicesLinear);
        d_end = newIndices.size(1);
        for (int g_i{0}; g_i < d_end; g_i++) {
          if (newIndices[g_i] == 0.0) {
            newIndices[g_i] = newIndicesLinear[g_i];
          }
        }
      }
    } else {
      int bb_loop_ub;
      int c_idx;
      int f_idx;
      int h_loop_ub;
      int hb_loop_ub;
      int m_loop_ub;
      int xb_loop_ub;
      c_idx = static_cast<int>(idx[1]);
      h_loop_ub = BoardCoords.size(0);
      m_loop_ub = BoardCoords.size(2);
      c_this.set_size(h_loop_ub, 1, m_loop_ub);
      for (int i7{0}; i7 < m_loop_ub; i7++) {
        for (int i13{0}; i13 < h_loop_ub; i13++) {
          c_this[i13 + (c_this.size(0) * i7)] =
              BoardCoords[(i13 + (BoardCoords.size(0) * (c_idx - 1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * i7)];
        }
      }
      b_squeeze(c_this, p1);
      f_idx = static_cast<int>(idx[0]);
      bb_loop_ub = BoardCoords.size(0);
      hb_loop_ub = BoardCoords.size(2);
      c_this.set_size(bb_loop_ub, 1, hb_loop_ub);
      for (int i26{0}; i26 < hb_loop_ub; i26++) {
        for (int i38{0}; i38 < bb_loop_ub; i38++) {
          c_this[i38 + (c_this.size(0) * i26)] =
              BoardCoords[(i38 + (BoardCoords.size(0) * (f_idx - 1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * i26)];
        }
      }
      b_squeeze(c_this, p2);
      xb_loop_ub = p2.size(1);
      for (int i46{0}; i46 < xb_loop_ub; i46++) {
        int mc_loop_ub;
        mc_loop_ub = p2.size(0);
        for (int i56{0}; i56 < mc_loop_ub; i56++) {
          double d3;
          d3 = p2[i56 + (p2.size(0) * i46)];
          d3 = (d3 + d3) - p1[i56 + (p1.size(0) * i46)];
          p2[i56 + (p2.size(0) * i46)] = d3;
        }
      }
      findClosestIndices(p2, newIndices);
    }
    expandBoardRight(newIndices, r, r1);
    BoardIdx.set_size(r.size(0), r.size(1));
    tb_loop_ub = r.size(1);
    for (int i35{0}; i35 < tb_loop_ub; i35++) {
      int yb_loop_ub;
      yb_loop_ub = r.size(0);
      for (int i47{0}; i47 < yb_loop_ub; i47++) {
        BoardIdx[i47 + (BoardIdx.size(0) * i35)] = r[i47 + (r.size(0) * i35)];
      }
    }
    BoardCoords.set_size(r1.size(0), r1.size(1), r1.size(2));
    ec_loop_ub = r1.size(2);
    for (int i51{0}; i51 < ec_loop_ub; i51++) {
      int rc_loop_ub;
      rc_loop_ub = r1.size(1);
      for (int i61{0}; i61 < rc_loop_ub; i61++) {
        int vc_loop_ub;
        vc_loop_ub = r1.size(0);
        for (int i67{0}; i67 < vc_loop_ub; i67++) {
          BoardCoords[(i67 + (BoardCoords.size(0) * i61)) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * i51)] =
              r1[(i67 + (r1.size(0) * i61)) +
                 ((r1.size(0) * r1.size(1)) * i51)];
        }
      }
    }
    idx.set_size(1, idx.size(1));
    sc_loop_ub = idx.size(1);
    for (int i63{0}; i63 < sc_loop_ub; i63++) {
      idx[i63] = idx[i63] + 1.0;
    }
    newEnergy = computeNewEnergyHorizontal(idx, oldEnergy);
  } break;
  default:
    newEnergy = rtInfF;
    break;
  }
  Energy = newEnergy;
}

//
// Arguments    : double seedIdx
//                const ::coder::array<float, 2U> &b_points
//                const float v1[2]
//                const float v2[2]
// Return Type  : void
//
void b_Checkerboard::initialize(double seedIdx,
                                const ::coder::array<float, 2U> &b_points,
                                const float v1[2], const float v2[2])
{
  array<double, 2U> r1;
  array<float, 2U> b_down;
  array<float, 2U> b_r;
  array<float, 2U> b_u;
  array<float, 2U> b_up;
  array<float, 2U> center;
  array<float, 2U> col1;
  array<float, 2U> col2;
  array<float, 2U> col3;
  array<float, 2U> d;
  array<float, 2U> denom;
  array<float, 2U> down;
  array<float, 2U> left;
  array<float, 2U> num;
  array<float, 2U> pointVectors;
  array<float, 2U> right;
  array<float, 2U> row1;
  array<float, 2U> row2;
  array<float, 2U> row3;
  array<float, 2U> s_l;
  array<float, 2U> up;
  array<float, 1U> b_pointVectors;
  array<float, 1U> c_pointVectors;
  array<float, 1U> euclideanDists;
  array<int, 1U> r;
  array<bool, 1U> b_x;
  float b_z1[3];
  float z1[3];
  float b_v1[2];
  float b_v2[2];
  int b_loop_ub;
  int b_this;
  int b_u0;
  int b_u1;
  int b_y;
  int c_loop_ub;
  int c_u0;
  int c_u1;
  int csz_idx_0;
  int csz_idx_1;
  int d_k;
  int d_loop_ub;
  int e_loop_ub;
  int f_loop_ub;
  int i8;
  int loop_ub;
  int u0;
  int u1;
  int y;
  bool c_y;
  bool exitg1;
  BoardIdx.set_size(1, 1);
  BoardIdx[0] = 0.0;
  BoardIdx.set_size(3, 3);
  for (int b_i{0}; b_i < 3; b_i++) {
    BoardIdx[BoardIdx.size(0) * b_i] = 0.0;
    BoardIdx[(BoardIdx.size(0) * b_i) + 1] = 0.0;
    BoardIdx[(BoardIdx.size(0) * b_i) + 2] = 0.0;
  }
  for (int i1{0}; i1 < 4; i1++) {
    IsDirectionBad[i1] = false;
  }
  BoardCoords.set_size(1, 1, 1);
  BoardCoords[0] = 0.0;
  BoardCoords.set_size(3, 3, 2);
  Points.set_size(b_points.size(0), 2);
  loop_ub = b_points.size(0);
  for (int i2{0}; i2 < 2; i2++) {
    for (int i3{0}; i3 < 3; i3++) {
      BoardCoords[(BoardCoords.size(0) * i3) +
                  ((BoardCoords.size(0) * BoardCoords.size(1)) * i2)] = 0.0;
      BoardCoords[((BoardCoords.size(0) * i3) +
                   ((BoardCoords.size(0) * BoardCoords.size(1)) * i2)) +
                  1] = 0.0;
      BoardCoords[((BoardCoords.size(0) * i3) +
                   ((BoardCoords.size(0) * BoardCoords.size(1)) * i2)) +
                  2] = 0.0;
    }
    for (int i5{0}; i5 < loop_ub; i5++) {
      Points[i5 + (Points.size(0) * i2)] =
          b_points[i5 + (b_points.size(0) * i2)];
    }
  }
  b_loop_ub = Points.size(1);
  center.set_size(1, b_loop_ub);
  for (int i4{0}; i4 < b_loop_ub; i4++) {
    center[i4] =
        Points[((static_cast<int>(seedIdx)) + (Points.size(0) * i4)) - 1];
  }
  BoardIdx[BoardIdx.size(0) + 1] = seedIdx;
  c_loop_ub = BoardCoords.size(2);
  r.set_size(c_loop_ub);
  for (int i6{0}; i6 < c_loop_ub; i6++) {
    r[i6] = i6;
  }
  d_loop_ub = r.size(0);
  for (int i7{0}; i7 < d_loop_ub; i7++) {
    BoardCoords[(BoardCoords.size(0) +
                 ((BoardCoords.size(0) * BoardCoords.size(1)) * r[i7])) +
                1] = static_cast<double>(center[i7]);
  }
  LastExpandDirection = 1.0;
  PreviousEnergy = rtInfF;
  isValid = false;
  u0 = center.size(1);
  u1 = Points.size(1);
  if (u0 <= u1) {
    y = u0;
  } else {
    y = u1;
  }
  if (center.size(1) == 1) {
    csz_idx_1 = Points.size(1);
  } else if (Points.size(1) == 1) {
    csz_idx_1 = center.size(1);
  } else if (Points.size(1) == center.size(1)) {
    csz_idx_1 = Points.size(1);
  } else {
    csz_idx_1 = y;
  }
  b_u0 = center.size(1);
  b_u1 = Points.size(1);
  if (b_u0 <= b_u1) {
    b_y = b_u0;
  } else {
    b_y = b_u1;
  }
  if (center.size(1) == 1) {
    i8 = Points.size(1);
  } else if (Points.size(1) == 1) {
    i8 = center.size(1);
  } else if (Points.size(1) == center.size(1)) {
    i8 = Points.size(1);
  } else {
    i8 = b_y;
  }
  pointVectors.set_size(Points.size(0), i8);
  if ((Points.size(0) != 0) && (csz_idx_1 != 0)) {
    int acoef;
    int bcoef;
    int i9;
    acoef = static_cast<int>(Points.size(1) != 1);
    bcoef = static_cast<int>(center.size(1) != 1);
    i9 = csz_idx_1 - 1;
    for (int k{0}; k <= i9; k++) {
      int b_acoef;
      int i12;
      int varargin_2;
      int varargin_3;
      varargin_2 = acoef * k;
      varargin_3 = bcoef * k;
      b_acoef = static_cast<int>(Points.size(0) != 1);
      i12 = pointVectors.size(0) - 1;
      for (int b_k{0}; b_k <= i12; b_k++) {
        pointVectors[b_k + (pointVectors.size(0) * k)] =
            Points[(b_acoef * b_k) + (Points.size(0) * varargin_2)] -
            center[varargin_3];
      }
    }
  }
  e_loop_ub = pointVectors.size(0);
  b_pointVectors.set_size(pointVectors.size(0));
  for (int i10{0}; i10 < e_loop_ub; i10++) {
    b_pointVectors[i10] = pointVectors[i10];
  }
  f_loop_ub = pointVectors.size(0);
  c_pointVectors.set_size(pointVectors.size(0));
  for (int i11{0}; i11 < f_loop_ub; i11++) {
    c_pointVectors[i11] = pointVectors[i11 + pointVectors.size(0)];
  }
  c_u0 = b_pointVectors.size(0);
  c_u1 = c_pointVectors.size(0);
  if (c_u0 <= c_u1) {
    csz_idx_0 = c_u0;
  } else {
    csz_idx_0 = c_u1;
  }
  euclideanDists.set_size(csz_idx_0);
  for (int c_k{0}; c_k < csz_idx_0; c_k++) {
    euclideanDists[c_k] =
        rt_hypotf_snf(b_pointVectors[c_k], c_pointVectors[c_k]);
  }
  BoardIdx[(BoardIdx.size(0) * 2) + 1] =
      findNeighbor(pointVectors, euclideanDists, v1);
  b_v1[0] = -v1[0];
  b_v1[1] = -v1[1];
  BoardIdx[1] = findNeighbor(pointVectors, euclideanDists, b_v1);
  BoardIdx[BoardIdx.size(0) + 2] =
      findNeighbor(pointVectors, euclideanDists, v2);
  b_v2[0] = -v2[0];
  b_v2[1] = -v2[1];
  BoardIdx[BoardIdx.size(0)] = findNeighbor(pointVectors, euclideanDists, b_v2);
  b_this = BoardIdx.size(0) * BoardIdx.size(1);
  b_x.set_size(b_this);
  for (int i13{0}; i13 < b_this; i13++) {
    b_x[i13] = (BoardIdx[i13] < 0.0);
  }
  c_y = false;
  d_k = 0;
  exitg1 = false;
  while ((!exitg1) && (d_k <= (b_x.size(0) - 1))) {
    if (b_x[d_k]) {
      c_y = true;
      exitg1 = true;
    } else {
      d_k++;
    }
  }
  if (c_y) {
    isValid = false;
  } else {
    int ab_loop_ub;
    int bb_loop_ub;
    int c_this;
    int cb_loop_ub;
    int d_this;
    int e_this;
    int f_k;
    int f_this;
    int g_loop_ub;
    int h_loop_ub;
    int i_loop_ub;
    int j_loop_ub;
    int k_loop_ub;
    int m_loop_ub;
    int o_loop_ub;
    int p_loop_ub;
    int q_loop_ub;
    int r_loop_ub;
    int s_loop_ub;
    int t_loop_ub;
    int u_loop_ub;
    int v_loop_ub;
    int w_loop_ub;
    int x_loop_ub;
    int y_loop_ub;
    c_this = static_cast<int>(BoardIdx[(BoardIdx.size(0) * 2) + 1]);
    g_loop_ub = Points.size(1);
    b_r.set_size(1, g_loop_ub);
    for (int i14{0}; i14 < g_loop_ub; i14++) {
      b_r[i14] = Points[(c_this + (Points.size(0) * i14)) - 1];
    }
    h_loop_ub = BoardCoords.size(2);
    r.set_size(h_loop_ub);
    for (int i15{0}; i15 < h_loop_ub; i15++) {
      r[i15] = i15;
    }
    i_loop_ub = r.size(0);
    for (int i16{0}; i16 < i_loop_ub; i16++) {
      BoardCoords[((BoardCoords.size(0) * 2) +
                   ((BoardCoords.size(0) * BoardCoords.size(1)) * r[i16])) +
                  1] = static_cast<double>(b_r[i16]);
    }
    d_this = static_cast<int>(BoardIdx[1]);
    j_loop_ub = Points.size(1);
    s_l.set_size(1, j_loop_ub);
    for (int i17{0}; i17 < j_loop_ub; i17++) {
      s_l[i17] = Points[(d_this + (Points.size(0) * i17)) - 1];
    }
    k_loop_ub = BoardCoords.size(2);
    r.set_size(k_loop_ub);
    for (int i18{0}; i18 < k_loop_ub; i18++) {
      r[i18] = i18;
    }
    m_loop_ub = r.size(0);
    for (int i19{0}; i19 < m_loop_ub; i19++) {
      BoardCoords[((BoardCoords.size(0) * BoardCoords.size(1)) * r[i19]) + 1] =
          static_cast<double>(s_l[i19]);
    }
    e_this = static_cast<int>(BoardIdx[BoardIdx.size(0) + 2]);
    o_loop_ub = Points.size(1);
    d.set_size(1, o_loop_ub);
    for (int i20{0}; i20 < o_loop_ub; i20++) {
      d[i20] = Points[(e_this + (Points.size(0) * i20)) - 1];
    }
    p_loop_ub = BoardCoords.size(2);
    r.set_size(p_loop_ub);
    for (int i21{0}; i21 < p_loop_ub; i21++) {
      r[i21] = i21;
    }
    q_loop_ub = r.size(0);
    for (int i22{0}; i22 < q_loop_ub; i22++) {
      BoardCoords[(BoardCoords.size(0) +
                   ((BoardCoords.size(0) * BoardCoords.size(1)) * r[i22])) +
                  2] = static_cast<double>(d[i22]);
    }
    f_this = static_cast<int>(BoardIdx[BoardIdx.size(0)]);
    r_loop_ub = Points.size(1);
    b_u.set_size(1, r_loop_ub);
    for (int i23{0}; i23 < r_loop_ub; i23++) {
      b_u[i23] = Points[(f_this + (Points.size(0) * i23)) - 1];
    }
    s_loop_ub = BoardCoords.size(2);
    r.set_size(s_loop_ub);
    for (int i24{0}; i24 < s_loop_ub; i24++) {
      r[i24] = i24;
    }
    t_loop_ub = r.size(0);
    for (int i25{0}; i25 < t_loop_ub; i25++) {
      BoardCoords[BoardCoords.size(0) +
                  ((BoardCoords.size(0) * BoardCoords.size(1)) * r[i25])] =
          static_cast<double>(b_u[i25]);
    }
    up.set_size(1, b_u.size(1));
    u_loop_ub = b_u.size(1);
    for (int i26{0}; i26 < u_loop_ub; i26++) {
      up[i26] = b_u[i26] - center[i26];
    }
    down.set_size(1, d.size(1));
    v_loop_ub = d.size(1);
    for (int i27{0}; i27 < v_loop_ub; i27++) {
      down[i27] = d[i27] - center[i27];
    }
    right.set_size(1, b_r.size(1));
    w_loop_ub = b_r.size(1);
    for (int i28{0}; i28 < w_loop_ub; i28++) {
      right[i28] = b_r[i28] - center[i28];
    }
    left.set_size(1, s_l.size(1));
    x_loop_ub = s_l.size(1);
    for (int i29{0}; i29 < x_loop_ub; i29++) {
      left[i29] = s_l[i29] - center[i29];
    }
    b_up.set_size(1, up.size(1));
    y_loop_ub = up.size(1);
    for (int i30{0}; i30 < y_loop_ub; i30++) {
      b_up[i30] = up[i30] + left[i30];
    }
    BoardIdx[0] = findNeighbor(pointVectors, euclideanDists, b_up);
    b_down.set_size(1, down.size(1));
    ab_loop_ub = down.size(1);
    for (int i31{0}; i31 < ab_loop_ub; i31++) {
      b_down[i31] = down[i31] + left[i31];
    }
    BoardIdx[2] = findNeighbor(pointVectors, euclideanDists, b_down);
    down.set_size(1, down.size(1));
    bb_loop_ub = down.size(1);
    for (int i32{0}; i32 < bb_loop_ub; i32++) {
      down[i32] = down[i32] + right[i32];
    }
    BoardIdx[(BoardIdx.size(0) * 2) + 2] =
        findNeighbor(pointVectors, euclideanDists, down);
    up.set_size(1, up.size(1));
    cb_loop_ub = up.size(1);
    for (int i33{0}; i33 < cb_loop_ub; i33++) {
      up[i33] = up[i33] + right[i33];
    }
    BoardIdx[BoardIdx.size(0) * 2] =
        findNeighbor(pointVectors, euclideanDists, up);
    b_this = BoardIdx.size(0) * BoardIdx.size(1);
    b_x.set_size(b_this);
    for (int i34{0}; i34 < b_this; i34++) {
      b_x[i34] = (BoardIdx[i34] > 0.0);
    }
    isValid = true;
    f_k = 0;
    exitg1 = false;
    while ((!exitg1) && (f_k <= (b_x.size(0) - 1))) {
      if (!b_x[f_k]) {
        isValid = false;
        exitg1 = true;
      } else {
        f_k++;
      }
    }
    if (isValid) {
      float e;
      int db_loop_ub;
      int eb_loop_ub;
      int fb_loop_ub;
      int g_k;
      int g_this;
      int gb_loop_ub;
      int h_this;
      int hb_loop_ub;
      int i_this;
      int ib_loop_ub;
      int j_this;
      int jb_loop_ub;
      int k_this;
      int kb_loop_ub;
      int mb_loop_ub;
      int ob_loop_ub;
      int pb_loop_ub;
      int qb_loop_ub;
      bool d_y;
      db_loop_ub = BoardCoords.size(2);
      r.set_size(db_loop_ub);
      for (int i35{0}; i35 < db_loop_ub; i35++) {
        r[i35] = i35;
      }
      g_this = static_cast<int>(BoardIdx[0]);
      eb_loop_ub = Points.size(1);
      r1.set_size(1, eb_loop_ub);
      for (int i36{0}; i36 < eb_loop_ub; i36++) {
        r1[i36] =
            static_cast<double>(Points[(g_this + (Points.size(0) * i36)) - 1]);
      }
      fb_loop_ub = r.size(0);
      for (int i37{0}; i37 < fb_loop_ub; i37++) {
        BoardCoords[(BoardCoords.size(0) * BoardCoords.size(1)) * r[i37]] =
            r1[i37];
      }
      gb_loop_ub = BoardCoords.size(2);
      r.set_size(gb_loop_ub);
      for (int i38{0}; i38 < gb_loop_ub; i38++) {
        r[i38] = i38;
      }
      h_this = static_cast<int>(BoardIdx[2]);
      hb_loop_ub = Points.size(1);
      r1.set_size(1, hb_loop_ub);
      for (int i39{0}; i39 < hb_loop_ub; i39++) {
        r1[i39] =
            static_cast<double>(Points[(h_this + (Points.size(0) * i39)) - 1]);
      }
      ib_loop_ub = r.size(0);
      for (int i40{0}; i40 < ib_loop_ub; i40++) {
        BoardCoords[((BoardCoords.size(0) * BoardCoords.size(1)) * r[i40]) +
                    2] = r1[i40];
      }
      jb_loop_ub = BoardCoords.size(2);
      r.set_size(jb_loop_ub);
      for (int i41{0}; i41 < jb_loop_ub; i41++) {
        r[i41] = i41;
      }
      i_this = static_cast<int>(BoardIdx[(BoardIdx.size(0) * 2) + 2]);
      kb_loop_ub = Points.size(1);
      r1.set_size(1, kb_loop_ub);
      for (int i42{0}; i42 < kb_loop_ub; i42++) {
        r1[i42] =
            static_cast<double>(Points[(i_this + (Points.size(0) * i42)) - 1]);
      }
      mb_loop_ub = r.size(0);
      for (int i43{0}; i43 < mb_loop_ub; i43++) {
        BoardCoords[((BoardCoords.size(0) * 2) +
                     ((BoardCoords.size(0) * BoardCoords.size(1)) * r[i43])) +
                    2] = r1[i43];
      }
      ob_loop_ub = BoardCoords.size(2);
      r.set_size(ob_loop_ub);
      for (int i44{0}; i44 < ob_loop_ub; i44++) {
        r[i44] = i44;
      }
      j_this = static_cast<int>(BoardIdx[BoardIdx.size(0) * 2]);
      pb_loop_ub = Points.size(1);
      r1.set_size(1, pb_loop_ub);
      for (int i45{0}; i45 < pb_loop_ub; i45++) {
        r1[i45] =
            static_cast<double>(Points[(j_this + (Points.size(0) * i45)) - 1]);
      }
      qb_loop_ub = r.size(0);
      for (int i46{0}; i46 < qb_loop_ub; i46++) {
        BoardCoords[(BoardCoords.size(0) * 2) +
                    ((BoardCoords.size(0) * BoardCoords.size(1)) * r[i46])] =
            r1[i46];
      }
      b_this = BoardIdx.size(0) * BoardIdx.size(1);
      b_x.set_size(b_this);
      for (int i47{0}; i47 < b_this; i47++) {
        b_x[i47] = (BoardIdx[i47] < 0.0);
      }
      d_y = false;
      g_k = 0;
      exitg1 = false;
      while ((!exitg1) && (g_k <= (b_x.size(0) - 1))) {
        if (b_x[g_k]) {
          d_y = true;
          exitg1 = true;
        } else {
          g_k++;
        }
      }
      if (d_y) {
        e = rtInfF;
      } else {
        float z1_idx_0;
        float z1_idx_1;
        float z1_idx_2;
        int ac_loop_ub;
        int bc_loop_ub;
        int rb_loop_ub;
        int sb_loop_ub;
        int tb_loop_ub;
        int ub_loop_ub;
        int vb_loop_ub;
        int wb_loop_ub;
        int xb_loop_ub;
        int yb_loop_ub;
        rb_loop_ub = Points.size(1);
        row1.set_size(3, rb_loop_ub);
        for (int i48{0}; i48 < rb_loop_ub; i48++) {
          row1[3 * i48] = Points[((static_cast<int>(BoardIdx[0])) +
                                  (Points.size(0) * i48)) -
                                 1];
          row1[(3 * i48) + 1] =
              Points[((static_cast<int>(BoardIdx[BoardIdx.size(0)])) +
                      (Points.size(0) * i48)) -
                     1];
          row1[(3 * i48) + 2] =
              Points[((static_cast<int>(BoardIdx[BoardIdx.size(0) * 2])) +
                      (Points.size(0) * i48)) -
                     1];
        }
        sb_loop_ub = Points.size(1);
        row2.set_size(3, sb_loop_ub);
        for (int i49{0}; i49 < sb_loop_ub; i49++) {
          row2[3 * i49] = Points[((static_cast<int>(BoardIdx[1])) +
                                  (Points.size(0) * i49)) -
                                 1];
          row2[(3 * i49) + 1] =
              Points[((static_cast<int>(BoardIdx[BoardIdx.size(0) + 1])) +
                      (Points.size(0) * i49)) -
                     1];
          row2[(3 * i49) + 2] =
              Points[((static_cast<int>(BoardIdx[(BoardIdx.size(0) * 2) + 1])) +
                      (Points.size(0) * i49)) -
                     1];
        }
        tb_loop_ub = Points.size(1);
        row3.set_size(3, tb_loop_ub);
        for (int i50{0}; i50 < tb_loop_ub; i50++) {
          row3[3 * i50] = Points[((static_cast<int>(BoardIdx[2])) +
                                  (Points.size(0) * i50)) -
                                 1];
          row3[(3 * i50) + 1] =
              Points[((static_cast<int>(BoardIdx[BoardIdx.size(0) + 2])) +
                      (Points.size(0) * i50)) -
                     1];
          row3[(3 * i50) + 2] =
              Points[((static_cast<int>(BoardIdx[(BoardIdx.size(0) * 2) + 2])) +
                      (Points.size(0) * i50)) -
                     1];
        }
        num.set_size(3, row1.size(1));
        ub_loop_ub = row1.size(1);
        for (int i51{0}; i51 < ub_loop_ub; i51++) {
          num[3 * i51] =
              (row1[3 * i51] + row3[3 * i51]) - (2.0F * row2[3 * i51]);
          num[(3 * i51) + 1] = (row1[(3 * i51) + 1] + row3[(3 * i51) + 1]) -
                               (2.0F * row2[(3 * i51) + 1]);
          num[(3 * i51) + 2] = (row1[(3 * i51) + 2] + row3[(3 * i51) + 2]) -
                               (2.0F * row2[(3 * i51) + 2]);
        }
        denom.set_size(3, row1.size(1));
        vb_loop_ub = row1.size(1);
        for (int i52{0}; i52 < vb_loop_ub; i52++) {
          denom[3 * i52] = row1[3 * i52] - row3[3 * i52];
          denom[(3 * i52) + 1] = row1[(3 * i52) + 1] - row3[(3 * i52) + 1];
          denom[(3 * i52) + 2] = row1[(3 * i52) + 2] - row3[(3 * i52) + 2];
        }
        z1[0] = rt_hypotf_snf(num[0], num[3]);
        z1_idx_0 = rt_hypotf_snf(denom[0], denom[3]);
        z1[1] = rt_hypotf_snf(num[1], num[4]);
        z1_idx_1 = rt_hypotf_snf(denom[1], denom[4]);
        z1[2] = rt_hypotf_snf(num[2], num[5]);
        z1_idx_2 = rt_hypotf_snf(denom[2], denom[5]);
        wb_loop_ub = Points.size(1);
        col1.set_size(3, wb_loop_ub);
        for (int i53{0}; i53 < wb_loop_ub; i53++) {
          col1[3 * i53] = Points[((static_cast<int>(BoardIdx[0])) +
                                  (Points.size(0) * i53)) -
                                 1];
          col1[(3 * i53) + 1] = Points[((static_cast<int>(BoardIdx[1])) +
                                        (Points.size(0) * i53)) -
                                       1];
          col1[(3 * i53) + 2] = Points[((static_cast<int>(BoardIdx[2])) +
                                        (Points.size(0) * i53)) -
                                       1];
        }
        xb_loop_ub = Points.size(1);
        col2.set_size(3, xb_loop_ub);
        for (int i54{0}; i54 < xb_loop_ub; i54++) {
          col2[3 * i54] =
              Points[((static_cast<int>(BoardIdx[BoardIdx.size(0)])) +
                      (Points.size(0) * i54)) -
                     1];
          col2[(3 * i54) + 1] =
              Points[((static_cast<int>(BoardIdx[BoardIdx.size(0) + 1])) +
                      (Points.size(0) * i54)) -
                     1];
          col2[(3 * i54) + 2] =
              Points[((static_cast<int>(BoardIdx[BoardIdx.size(0) + 2])) +
                      (Points.size(0) * i54)) -
                     1];
        }
        yb_loop_ub = Points.size(1);
        col3.set_size(3, yb_loop_ub);
        for (int i55{0}; i55 < yb_loop_ub; i55++) {
          col3[3 * i55] =
              Points[((static_cast<int>(BoardIdx[BoardIdx.size(0) * 2])) +
                      (Points.size(0) * i55)) -
                     1];
          col3[(3 * i55) + 1] =
              Points[((static_cast<int>(BoardIdx[(BoardIdx.size(0) * 2) + 1])) +
                      (Points.size(0) * i55)) -
                     1];
          col3[(3 * i55) + 2] =
              Points[((static_cast<int>(BoardIdx[(BoardIdx.size(0) * 2) + 2])) +
                      (Points.size(0) * i55)) -
                     1];
        }
        num.set_size(3, col1.size(1));
        ac_loop_ub = col1.size(1);
        for (int i56{0}; i56 < ac_loop_ub; i56++) {
          num[3 * i56] =
              (col1[3 * i56] + col3[3 * i56]) - (2.0F * col2[3 * i56]);
          num[(3 * i56) + 1] = (col1[(3 * i56) + 1] + col3[(3 * i56) + 1]) -
                               (2.0F * col2[(3 * i56) + 1]);
          num[(3 * i56) + 2] = (col1[(3 * i56) + 2] + col3[(3 * i56) + 2]) -
                               (2.0F * col2[(3 * i56) + 2]);
        }
        denom.set_size(3, col1.size(1));
        bc_loop_ub = col1.size(1);
        for (int i57{0}; i57 < bc_loop_ub; i57++) {
          denom[3 * i57] = col1[3 * i57] - col3[3 * i57];
          denom[(3 * i57) + 1] = col1[(3 * i57) + 1] - col3[(3 * i57) + 1];
          denom[(3 * i57) + 2] = col1[(3 * i57) + 2] - col3[(3 * i57) + 2];
        }
        float boardSize;
        boardSize = static_cast<float>(
            static_cast<int>(BoardIdx.size(0) * BoardIdx.size(1)));
        z1[0] /= z1_idx_0;
        b_z1[0] =
            rt_hypotf_snf(num[0], num[3]) / rt_hypotf_snf(denom[0], denom[3]);
        z1[1] /= z1_idx_1;
        b_z1[1] =
            rt_hypotf_snf(num[1], num[4]) / rt_hypotf_snf(denom[1], denom[4]);
        z1[2] /= z1_idx_2;
        b_z1[2] =
            rt_hypotf_snf(num[2], num[5]) / rt_hypotf_snf(denom[2], denom[5]);
        e = (boardSize *
             std::fmax(std::fmax(0.0F, ::coder::internal::maximum(z1)),
                       ::coder::internal::maximum(b_z1))) -
            boardSize;
      }
      Energy = e;
      if (IsDistortionHigh) {
        k_this = -5;
      } else {
        k_this = -7;
      }
      isValid = ((static_cast<double>(Energy)) < (static_cast<double>(k_this)));
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
