//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Checkerboard.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "Checkerboard.h"
#include "ITER_API_rtwutil.h"
#include "bsxfun.h"
#include "colon.h"
#include "combineVectorElements.h"
#include "eml_setop.h"
#include "find.h"
#include "hypot.h"
#include "isequal.h"
#include "ismember.h"
#include "minOrMax.h"
#include "norm.h"
#include "polyfit.h"
#include "rt_nonfinite.h"
#include "squeeze.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<bool, 2U> &arr
//                ::coder::array<double, 2U> &matchedIdx
// Return Type  : void
//
namespace ITER
{
  namespace coder
  {
    namespace vision
    {
      namespace internal
      {
        namespace calibration
        {
          namespace checkerboard
          {
            void b_Checkerboard::arrayFind(const ::coder::array<bool, 2U> &arr, ::
              coder::array<double, 2U> &matchedIdx)
            {
              ::coder::array<int, 2U> b_arr;
              ::coder::array<int, 2U> c_ii;
              ::coder::array<signed char, 2U> matchArr;
              ::coder::array<bool, 2U> b_x;
              int b_i;
              int b_idx;
              int b_loop_ub;
              int b_nx;
              int e_ii;
              int i1;
              int k;
              int loop_ub;
              bool e_x[3];
              bool exitg1;
              bool y;
              matchArr.set_size(1, arr.size(1) - 2);
              b_i = arr.size(1);

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(b_arr,i1,k,y,e_x,exitg1)

              for (int idx = 0; idx <= (b_i - 3); idx++) {
                b_arr.set_size(1, 3);
                for (i1 = 0; i1 < 3; i1++) {
                  b_arr[i1] = static_cast<int>(arr[idx + i1]);
                }

                e_x[0] = (b_arr[0] == 1);
                e_x[1] = (b_arr[1] == 1);
                e_x[2] = (b_arr[2] == 1);
                y = true;
                k = 0;
                exitg1 = false;
                while ((!exitg1) && (k < 3)) {
                  if (!e_x[k]) {
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
              if ((static_cast<int>(matchArr.size(1) < 4)) != 0) {
                for (int i2{0}; i2 < loop_ub; i2++) {
                  b_x[i2] = (matchArr[i2] == 1);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i2 = 0; i2 < loop_ub; i2++) {
                  b_x[i2] = (matchArr[i2] == 1);
                }
              }

              b_nx = b_x.size(1);
              b_idx = 0;
              c_ii.set_size(1, b_x.size(1));
              e_ii = 0;
              exitg1 = false;
              while ((!exitg1) && (e_ii <= (b_nx - 1))) {
                if (b_x[e_ii]) {
                  b_idx++;
                  c_ii[b_idx - 1] = e_ii + 1;
                  if (b_idx >= b_nx) {
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
              if ((static_cast<int>(c_ii.size(1) < 4)) != 0) {
                for (int i4{0}; i4 < b_loop_ub; i4++) {
                  matchedIdx[i4] = static_cast<double>(c_ii[i4]);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i4 = 0; i4 < b_loop_ub; i4++) {
                  matchedIdx[i4] = static_cast<double>(c_ii[i4]);
                }
              }
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &predictedPoints
            //                ::coder::array<double, 2U> &indices
            // Return Type  : void
            //
            void b_Checkerboard::b_findClosestIndices(const ::coder::array<
              double, 2U> &predictedPoints, ::coder::array<double, 2U> &indices)
              const
            {
              ::coder::array<double, 2U> b_indices;
              ::coder::array<double, 2U> p;
              ::coder::array<double, 2U> remIdx;
              ::coder::array<double, 2U> y;
              ::coder::array<double, 1U> c_this;
              ::coder::array<double, 1U> s;
              ::coder::array<double, 1U> validBoardIdx;
              ::coder::array<float, 2U> diffs;
              ::coder::array<float, 2U> e_this;
              ::coder::array<float, 1U> b_diffs;
              ::coder::array<float, 1U> c_diffs;
              ::coder::array<float, 1U> dists;
              ::coder::array<float, 1U> r2;
              ::coder::array<int, 2U> r1;
              ::coder::array<int, 1U> c_ib;
              ::coder::array<int, 1U> c_ii;
              ::coder::array<int, 1U> ia;
              ::coder::array<bool, 2U> distIdx;
              ::coder::array<bool, 1U> r;
              float minDist;
              int b;
              int b_this;
              int f_loop_ub;
              int g_loop_ub;
              int h_loop_ub;
              int i5;
              int i6;
              int i9;
              int i_loop_ub;
              int iindx;
              int loop_ub;
              indices.set_size(1, predictedPoints.size(0));
              loop_ub = predictedPoints.size(0);
              if ((static_cast<int>(predictedPoints.size(0) < 4)) != 0) {
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  indices[b_i] = 0.0;
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i = 0; b_i < loop_ub; b_i++) {
                  indices[b_i] = 0.0;
                }
              }

              b = Points.size(0);
              if (b < 1) {
                y.set_size(1, 0);
              } else {
                int b_loop_ub;
                y.set_size(1, b);
                b_loop_ub = b - 1;
                if ((static_cast<int>(b < 4)) != 0) {
                  for (int i1{0}; i1 <= b_loop_ub; i1++) {
                    y[i1] = (static_cast<double>(i1)) + 1.0;
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int i1 = 0; i1 <= b_loop_ub; i1++) {
                    y[i1] = (static_cast<double>(i1)) + 1.0;
                  }
                }
              }

              b_this = BoardIdx.size(0) * BoardIdx.size(1);
              c_this = BoardIdx.reshape(b_this);
              do_vectors(y, c_this, remIdx, ia, c_ib);
              if (remIdx.size(1) != 0) {
                int c_loop_ub;
                int d_loop_ub;
                int e_loop_ub;
                int h_n;
                int i4;
                int i7;
                c_loop_ub = predictedPoints.size(0);
                r.set_size(predictedPoints.size(0));
                d_loop_ub = predictedPoints.size(0);
                if ((static_cast<int>(predictedPoints.size(0) < 4)) != 0) {
                  for (int i2{0}; i2 < c_loop_ub; i2++) {
                    r[i2] = std::isnan(predictedPoints[i2]);
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int i2 = 0; i2 < d_loop_ub; i2++) {
                    r[i2] = std::isnan(predictedPoints[i2]);
                  }
                }

                e_loop_ub = r.size(0);
                if ((static_cast<int>(r.size(0) < 4)) != 0) {
                  for (int i3{0}; i3 < e_loop_ub; i3++) {
                    r[i3] = !r[i3];
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int i3 = 0; i3 < e_loop_ub; i3++) {
                    r[i3] = !r[i3];
                  }
                }

                b_eml_find(r, c_ii);
                i4 = c_ii.size(0);
                if (0 <= (c_ii.size(0) - 1)) {
                  i5 = predictedPoints.size(1);
                  f_loop_ub = predictedPoints.size(1);
                  i6 = Points.size(1);
                  g_loop_ub = i6;
                  b_this = BoardIdx.size(0) * BoardIdx.size(1);
                  h_loop_ub = b_this;
                  i9 = Points.size(1);
                  i_loop_ub = i9;
                }

                for (int c_i{0}; c_i < i4; c_i++) {
                  int b_end;
                  int c_end;
                  int i15;
                  int k_i;
                  int k_loop_ub;
                  int m_loop_ub;
                  int p_loop_ub;
                  int p_n;
                  int partialTrueCount;
                  int q_n;
                  int trueCount;
                  p.set_size(1, i5);
                  for (int b_i8{0}; b_i8 < f_loop_ub; b_i8++) {
                    p[b_i8] = predictedPoints[(c_ii[c_i] + (predictedPoints.size
                      (0) * b_i8)) - 1];
                  }

                  e_this.set_size(remIdx.size(1), i6);
                  for (int i10{0}; i10 < g_loop_ub; i10++) {
                    int j_loop_ub;
                    j_loop_ub = remIdx.size(1);
                    for (int i11{0}; i11 < j_loop_ub; i11++) {
                      e_this[i11 + (e_this.size(0) * i10)] = Points[((
                        static_cast<int>(remIdx[i11])) + (Points.size(0) * i10))
                        - 1];
                    }
                  }

                  bsxfun(e_this, p, diffs);
                  k_loop_ub = diffs.size(0);
                  b_diffs.set_size(diffs.size(0));
                  c_diffs.set_size(diffs.size(0));
                  for (int i12{0}; i12 < k_loop_ub; i12++) {
                    b_diffs[i12] = diffs[i12];
                    c_diffs[i12] = diffs[i12 + diffs.size(0)];
                  }

                  b_hypot(b_diffs, c_diffs, dists);
                  b_end = indices.size(1) - 1;
                  trueCount = 0;
                  for (int e_i{0}; e_i <= b_end; e_i++) {
                    if (indices[e_i] > 0.0) {
                      trueCount++;
                    }
                  }

                  r1.set_size(1, trueCount);
                  partialTrueCount = 0;
                  for (int g_i{0}; g_i <= b_end; g_i++) {
                    if (indices[g_i] > 0.0) {
                      r1[partialTrueCount] = g_i + 1;
                      partialTrueCount++;
                    }
                  }

                  m_loop_ub = r1.size(1);
                  b_indices.set_size(1, r1.size(1));
                  for (int i13{0}; i13 < m_loop_ub; i13++) {
                    b_indices[i13] = indices[r1[i13] - 1];
                  }

                  local_ismember(remIdx, b_indices, distIdx);
                  c_end = distIdx.size(1);
                  for (int h_i{0}; h_i < c_end; h_i++) {
                    if (distIdx[h_i]) {
                      dists[h_i] = rtInfF;
                    }
                  }

                  ::ITER::coder::internal::minimum(dists, &minDist, &iindx);
                  s.set_size(b_this);
                  for (int i14{0}; i14 < h_loop_ub; i14++) {
                    s[i14] = BoardIdx[i14];
                  }

                  p_n = s.size(0);
                  q_n = 0;
                  i15 = s.size(0);
                  for (int b_k{0}; b_k < i15; b_k++) {
                    if (s[b_k] != 0.0) {
                      q_n++;
                    }
                  }

                  validBoardIdx.set_size(q_n);
                  k_i = -1;
                  for (int c_k{0}; c_k < p_n; c_k++) {
                    if (s[c_k] != 0.0) {
                      k_i++;
                      validBoardIdx[k_i] = s[c_k];
                    }
                  }

                  e_this.set_size(validBoardIdx.size(0), i9);
                  for (int i16{0}; i16 < i_loop_ub; i16++) {
                    int o_loop_ub;
                    o_loop_ub = validBoardIdx.size(0);
                    for (int i17{0}; i17 < o_loop_ub; i17++) {
                      e_this[i17 + (e_this.size(0) * i16)] = Points[((
                        static_cast<int>(validBoardIdx[i17])) + (Points.size(0) *
                        i16)) - 1];
                    }
                  }

                  bsxfun(e_this, p, diffs);
                  p_loop_ub = diffs.size(0);
                  b_diffs.set_size(diffs.size(0));
                  c_diffs.set_size(diffs.size(0));
                  for (int i18{0}; i18 < p_loop_ub; i18++) {
                    b_diffs[i18] = diffs[i18];
                    c_diffs[i18] = diffs[i18 + diffs.size(0)];
                  }

                  b_hypot(b_diffs, c_diffs, r2);
                  if (minDist < (::ITER::coder::internal::b_minimum(r2) / 2.0F))
                  {
                    indices[c_ii[c_i] - 1] = remIdx[iindx - 1];
                  }
                }

                h_n = 0;
                i7 = indices.size(1);
                for (int k{0}; k < i7; k++) {
                  if (indices[k] != 0.0) {
                    h_n++;
                  }
                }

                if (h_n < 4) {
                  int end;
                  end = indices.size(1);
                  if ((static_cast<int>(indices.size(1) < 4)) != 0) {
                    for (int d_i{0}; d_i < end; d_i++) {
                      if (indices[d_i] > 0.0) {
                        indices[d_i] = 0.0;
                      }
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int d_i = 0; d_i < end; d_i++) {
                      if (indices[d_i] > 0.0) {
                        indices[d_i] = 0.0;
                      }
                    }
                  }
                }
              }
            }

            //
            // Arguments    : double coordsToUse[2]
            // Return Type  : void
            //
            void b_Checkerboard::b_findIndependentVar(double coordsToUse[2])
              const
            {
              ::coder::array<double, 1U> b_x;
              ::coder::array<double, 1U> e_x;
              ::coder::array<int, 1U> r2;
              ::coder::array<int, 1U> r3;
              ::coder::array<int, 1U> r4;
              ::coder::array<int, 1U> r5;
              ::coder::array<bool, 1U> r;
              ::coder::array<bool, 1U> r1;
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
              int loop_ub;
              int partialTrueCount;
              int trueCount;
              loop_ub = BoardIdx.size(0);
              r.set_size(loop_ub);
              b_loop_ub = loop_ub;
              if ((static_cast<int>(loop_ub < 4)) != 0) {
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  r[b_i] = (BoardIdx[b_i] > 0.0);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i = 0; b_i < b_loop_ub; b_i++) {
                  r[b_i] = (BoardIdx[b_i] > 0.0);
                }
              }

              c_loop_ub = BoardIdx.size(0);
              r1.set_size(c_loop_ub);
              d_loop_ub = c_loop_ub;
              if ((static_cast<int>(c_loop_ub < 4)) != 0) {
                for (int i1{0}; i1 < c_loop_ub; i1++) {
                  r1[i1] = (BoardIdx[i1 + BoardIdx.size(0)] > 0.0);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i1 = 0; i1 < d_loop_ub; i1++) {
                  r1[i1] = (BoardIdx[i1 + BoardIdx.size(0)] > 0.0);
                }
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
              e_loop_ub = r2.size(0);
              if ((static_cast<int>(r2.size(0) < 4)) != 0) {
                for (int i2{0}; i2 < e_loop_ub; i2++) {
                  b_x[i2] = BoardCoords[(r2[i2] + BoardCoords.size(0)) - 1] -
                    BoardCoords[r3[i2] - 1];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i2 = 0; i2 < e_loop_ub; i2++) {
                  b_x[i2] = BoardCoords[(r2[i2] + BoardCoords.size(0)) - 1] -
                    BoardCoords[r3[i2] - 1];
                }
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
              for (int k_i{0}; k_i <= c_end; k_i++) {
                if ((r[k_i]) && (r1[k_i])) {
                  r4[c_partialTrueCount] = k_i + 1;
                  c_partialTrueCount++;
                }
              }

              d_end = r.size(0) - 1;
              d_trueCount = 0;
              for (int m_i{0}; m_i <= d_end; m_i++) {
                if ((r[m_i]) && (r1[m_i])) {
                  d_trueCount++;
                }
              }

              r5.set_size(d_trueCount);
              d_partialTrueCount = 0;
              for (int q_i{0}; q_i <= d_end; q_i++) {
                if ((r[q_i]) && (r1[q_i])) {
                  r5[d_partialTrueCount] = q_i + 1;
                  d_partialTrueCount++;
                }
              }

              e_x.set_size(r4.size(0));
              f_loop_ub = r4.size(0);
              if ((static_cast<int>(r4.size(0) < 4)) != 0) {
                for (int i3{0}; i3 < f_loop_ub; i3++) {
                  e_x[i3] = BoardCoords[((r4[i3] + BoardCoords.size(0)) +
                    (BoardCoords.size(0) * BoardCoords.size(1))) - 1] -
                    BoardCoords[(r5[i3] + (BoardCoords.size(0) *
                    BoardCoords.size(1))) - 1];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i3 = 0; i3 < f_loop_ub; i3++) {
                  e_x[i3] = BoardCoords[((r4[i3] + BoardCoords.size(0)) +
                    (BoardCoords.size(0) * BoardCoords.size(1))) - 1] -
                    BoardCoords[(r5[i3] + (BoardCoords.size(0) *
                    BoardCoords.size(1))) - 1];
                }
              }

              if (std::abs(b_combineVectorElements(b_x) / (static_cast<double>
                    (b_x.size(0)))) > std::abs(b_combineVectorElements(e_x) / (
                    static_cast<double>(e_x.size(0))))) {
                coordsToUse[0] = 1.0;
                coordsToUse[1] = 2.0;
              } else {
                coordsToUse[0] = 2.0;
                coordsToUse[1] = 1.0;
              }
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &idx
            //                double coordsToUse[2]
            // Return Type  : void
            //
            void b_Checkerboard::b_findIndependentVar(const ::coder::array<
              double, 2U> &idx, double coordsToUse[2]) const
            {
              ::coder::array<double, 1U> b_x;
              ::coder::array<double, 1U> e_x;
              ::coder::array<int, 1U> r2;
              ::coder::array<int, 1U> r3;
              ::coder::array<int, 1U> r4;
              ::coder::array<int, 1U> r5;
              ::coder::array<bool, 1U> r;
              ::coder::array<bool, 1U> r1;
              int b_end;
              int b_idx;
              int b_idx_tmp;
              int b_loop_ub;
              int b_partialTrueCount;
              int b_trueCount;
              int c_end;
              int c_idx;
              int c_loop_ub;
              int c_partialTrueCount;
              int c_trueCount;
              int d_end;
              int d_idx;
              int d_loop_ub;
              int d_partialTrueCount;
              int d_trueCount;
              int e_idx;
              int e_loop_ub;
              int end;
              int f_idx;
              int f_loop_ub;
              int g_idx;
              int h_idx;
              int idx_tmp;
              int j_idx;
              int loop_ub;
              int m_idx;
              int o_idx;
              int partialTrueCount;
              int trueCount;
              idx_tmp = static_cast<int>(idx[0]);
              b_idx = idx_tmp;
              loop_ub = BoardIdx.size(0);
              r.set_size(loop_ub);
              b_loop_ub = loop_ub;
              if ((static_cast<int>(loop_ub < 4)) != 0) {
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  r[b_i] = (BoardIdx[b_i + (BoardIdx.size(0) * (idx_tmp - 1))] >
                            0.0);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i = 0; b_i < b_loop_ub; b_i++) {
                  r[b_i] = (BoardIdx[b_i + (BoardIdx.size(0) * (b_idx - 1))] >
                            0.0);
                }
              }

              b_idx_tmp = static_cast<int>(idx[1]);
              c_idx = b_idx_tmp;
              c_loop_ub = BoardIdx.size(0);
              r1.set_size(c_loop_ub);
              d_loop_ub = c_loop_ub;
              if ((static_cast<int>(c_loop_ub < 4)) != 0) {
                for (int i1{0}; i1 < c_loop_ub; i1++) {
                  r1[i1] = (BoardIdx[i1 + (BoardIdx.size(0) * (b_idx_tmp - 1))] >
                            0.0);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i1 = 0; i1 < d_loop_ub; i1++) {
                  r1[i1] = (BoardIdx[i1 + (BoardIdx.size(0) * (c_idx - 1))] >
                            0.0);
                }
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

              d_idx = static_cast<int>(idx[1]);
              e_idx = d_idx;
              f_idx = static_cast<int>(idx[0]);
              g_idx = f_idx;
              b_x.set_size(r2.size(0));
              e_loop_ub = r2.size(0);
              if ((static_cast<int>(r2.size(0) < 4)) != 0) {
                for (int i2{0}; i2 < e_loop_ub; i2++) {
                  b_x[i2] = BoardCoords[(r2[i2] + (BoardCoords.size(0) * (d_idx
                    - 1))) - 1] - BoardCoords[(r3[i2] + (BoardCoords.size(0) *
                    (f_idx - 1))) - 1];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i2 = 0; i2 < e_loop_ub; i2++) {
                  b_x[i2] = BoardCoords[(r2[i2] + (BoardCoords.size(0) * (e_idx
                    - 1))) - 1] - BoardCoords[(r3[i2] + (BoardCoords.size(0) *
                    (g_idx - 1))) - 1];
                }
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
              for (int k_i{0}; k_i <= c_end; k_i++) {
                if ((r[k_i]) && (r1[k_i])) {
                  r4[c_partialTrueCount] = k_i + 1;
                  c_partialTrueCount++;
                }
              }

              d_end = r.size(0) - 1;
              d_trueCount = 0;
              for (int m_i{0}; m_i <= d_end; m_i++) {
                if ((r[m_i]) && (r1[m_i])) {
                  d_trueCount++;
                }
              }

              r5.set_size(d_trueCount);
              d_partialTrueCount = 0;
              for (int q_i{0}; q_i <= d_end; q_i++) {
                if ((r[q_i]) && (r1[q_i])) {
                  r5[d_partialTrueCount] = q_i + 1;
                  d_partialTrueCount++;
                }
              }

              h_idx = static_cast<int>(idx[1]);
              j_idx = h_idx;
              m_idx = static_cast<int>(idx[0]);
              o_idx = m_idx;
              e_x.set_size(r4.size(0));
              f_loop_ub = r4.size(0);
              if ((static_cast<int>(r4.size(0) < 4)) != 0) {
                for (int i3{0}; i3 < f_loop_ub; i3++) {
                  e_x[i3] = BoardCoords[((r4[i3] + (BoardCoords.size(0) * (h_idx
                    - 1))) + (BoardCoords.size(0) * BoardCoords.size(1))) - 1] -
                    BoardCoords[((r5[i3] + (BoardCoords.size(0) * (m_idx - 1)))
                                 + (BoardCoords.size(0) * BoardCoords.size(1)))
                    - 1];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i3 = 0; i3 < f_loop_ub; i3++) {
                  e_x[i3] = BoardCoords[((r4[i3] + (BoardCoords.size(0) * (j_idx
                    - 1))) + (BoardCoords.size(0) * BoardCoords.size(1))) - 1] -
                    BoardCoords[((r5[i3] + (BoardCoords.size(0) * (o_idx - 1)))
                                 + (BoardCoords.size(0) * BoardCoords.size(1)))
                    - 1];
                }
              }

              if (std::abs(b_combineVectorElements(b_x) / (static_cast<double>
                    (b_x.size(0)))) > std::abs(b_combineVectorElements(e_x) / (
                    static_cast<double>(e_x.size(0))))) {
                coordsToUse[0] = 1.0;
                coordsToUse[1] = 2.0;
              } else {
                coordsToUse[0] = 2.0;
                coordsToUse[1] = 1.0;
              }
            }

            //
            // Arguments    : ::coder::array<double, 2U> &newIndices
            // Return Type  : void
            //
            void b_Checkerboard::b_fitPolynomialIndices(::coder::array<double,
              2U> &newIndices) const
            {
              ::coder::array<double, 2U> b_index;
              ::coder::array<double, 2U> b_this;
              ::coder::array<double, 2U> b_x;
              ::coder::array<double, 2U> c_this;
              ::coder::array<double, 2U> currCurve;
              ::coder::array<double, 2U> removedIdx;
              ::coder::array<int, 2U> c_ii;
              double b_dv[2];
              double coordsToUse[2];
              double currPt[2];
              double b_y;
              double y;
              int h_n;
              int i1;
              int i2;
              int loop_ub;
              int unnamed_idx_1;
              b_findIndependentVar(coordsToUse);
              unnamed_idx_1 = BoardCoords.size(0);
              newIndices.set_size(1, unnamed_idx_1);
              loop_ub = unnamed_idx_1;
              if ((static_cast<int>(unnamed_idx_1 < 4)) != 0) {
                for (int b_i{0}; b_i < unnamed_idx_1; b_i++) {
                  newIndices[b_i] = 0.0;
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i = 0; b_i < loop_ub; b_i++) {
                  newIndices[b_i] = 0.0;
                }
              }

              removedIdx.set_size(1, 0);
              i1 = newIndices.size(1);
              for (int j{0}; j < i1; j++) {
                int b_loop_ub;
                b_loop_ub = BoardCoords.size(1);
                b_x.set_size(1, b_loop_ub);
                for (int i3{0}; i3 < b_loop_ub; i3++) {
                  b_x[i3] = BoardCoords[(j + (BoardCoords.size(0) * i3)) +
                    ((BoardCoords.size(0) * BoardCoords.size(1)) * ((
                       static_cast<int>(coordsToUse[0])) - 1))];
                }

                c_eml_find(b_x, c_ii);
                if (c_ii.size(1) >= 2) {
                  double coordDist;
                  double currCoord;
                  double currRad;
                  double refCoordValue;
                  int coordDist_tmp;
                  int i4;
                  int p_n;
                  int q_n;
                  bool exitg1;
                  coordDist_tmp = c_ii[0];
                  coordDist = (BoardCoords[(j + (BoardCoords.size(0) * (c_ii[0]
                    - 1))) + ((BoardCoords.size(0) * BoardCoords.size(1)) * ((
                    static_cast<int>(coordsToUse[0])) - 1))] - BoardCoords[(j +
                    (BoardCoords.size(0) * (c_ii[1] - 1))) + ((BoardCoords.size
                    (0) * BoardCoords.size(1)) * ((static_cast<int>(coordsToUse
                    [0])) - 1))]) / ((static_cast<double>(c_ii[1])) - (
                    static_cast<double>(coordDist_tmp)));
                  p_n = 0;
                  i4 = c_ii.size(1);
                  b_this.set_size(1, c_ii.size(1));
                  c_this.set_size(1, c_ii.size(1));
                  for (int b_k{0}; b_k < i4; b_k++) {
                    if (c_ii[b_k] != 0) {
                      p_n++;
                    }

                    b_this[b_k] = BoardCoords[(j + (BoardCoords.size(0) *
                      (c_ii[b_k] - 1))) + ((BoardCoords.size(0) *
                      BoardCoords.size(1)) * ((static_cast<int>(coordsToUse[0]))
                      - 1))];
                    c_this[b_k] = BoardCoords[(j + (BoardCoords.size(0) *
                      (c_ii[b_k] - 1))) + ((BoardCoords.size(0) *
                      BoardCoords.size(1)) * ((static_cast<int>(coordsToUse[1]))
                      - 1))];
                  }

                  if (p_n > 5) {
                    q_n = 4;
                  } else {
                    q_n = 2;
                  }

                  b_polyfit(b_this, c_this, static_cast<double>(q_n), currCurve);
                  currRad = coordDist / 4.0;
                  refCoordValue = BoardCoords[(j + (BoardCoords.size(0) * (c_ii
                    [0] - 1))) + ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                  ((static_cast<int>(coordsToUse[0])) - 1))];
                  currCoord = currRad + refCoordValue;
                  exitg1 = false;
                  while ((!exitg1) && (std::abs(currCoord - refCoordValue) < (((
                             static_cast<double>(coordDist_tmp)) * 1.5) * std::
                           abs(coordDist)))) {
                    b_dv[0] = 1.0;
                    b_dv[1] = 2.0;
                    if (isequal(coordsToUse, b_dv)) {
                      if (currCurve.size(1) != 0) {
                        int i6;
                        b_y = currCurve[0];
                        i6 = currCurve.size(1);
                        for (int d_k{0}; d_k <= (i6 - 2); d_k++) {
                          b_y = (currCoord * b_y) + currCurve[d_k + 1];
                        }
                      }

                      currPt[0] = currCoord;
                      currPt[1] = b_y;
                    } else {
                      if (currCurve.size(1) != 0) {
                        int i5;
                        y = currCurve[0];
                        i5 = currCurve.size(1);
                        for (int c_k{0}; c_k <= (i5 - 2); c_k++) {
                          y = (currCoord * y) + currCurve[c_k + 1];
                        }
                      }

                      currPt[0] = y;
                      currPt[1] = currCoord;
                    }

                    findClosestOnCurve(currPt, std::abs(currRad), currCurve,
                                       coordsToUse, removedIdx, b_index);
                    if (b_index.size(1) != 0) {
                      int c_loop_ub;
                      int i7;
                      newIndices[j] = b_index[0];
                      i7 = removedIdx.size(1);
                      c_loop_ub = b_index.size(1);
                      removedIdx.set_size(removedIdx.size(0), removedIdx.size(1)
                                          + b_index.size(1));
                      for (int b_i8{0}; b_i8 < c_loop_ub; b_i8++) {
                        removedIdx[i7 + b_i8] = b_index[b_i8];
                      }

                      exitg1 = true;
                    } else {
                      currCoord += currRad;
                    }
                  }
                }
              }

              h_n = 0;
              i2 = newIndices.size(1);
              for (int k{0}; k < i2; k++) {
                if (newIndices[k] != 0.0) {
                  h_n++;
                }
              }

              if (h_n < 4) {
                int end;
                end = newIndices.size(1);
                if ((static_cast<int>(newIndices.size(1) < 4)) != 0) {
                  for (int c_i{0}; c_i < end; c_i++) {
                    if (newIndices[c_i] > 0.0) {
                      newIndices[c_i] = 0.0;
                    }
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int c_i = 0; c_i < end; c_i++) {
                    if (newIndices[c_i] > 0.0) {
                      newIndices[c_i] = 0.0;
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
            void b_Checkerboard::b_fitPolynomialIndices(const ::coder::array<
              double, 2U> &idx, ::coder::array<double, 2U> &newIndices) const
            {
              ::coder::array<double, 2U> b_index;
              ::coder::array<double, 2U> b_this;
              ::coder::array<double, 2U> c_this;
              ::coder::array<double, 2U> currCurve;
              ::coder::array<double, 2U> removedIdx;
              ::coder::array<double, 2U> validIdx;
              ::coder::array<int, 2U> c_ii;
              double b_dv[2];
              double coordsToUse[2];
              double currPt[2];
              double b_y;
              double coordDist;
              double firstValidIdx;
              double moveDistMultiplier;
              double y;
              int i1;
              int loop_ub;
              int unnamed_idx_1;
              b_findIndependentVar(idx, coordsToUse);
              unnamed_idx_1 = BoardCoords.size(0);
              newIndices.set_size(1, unnamed_idx_1);
              loop_ub = unnamed_idx_1;
              if ((static_cast<int>(unnamed_idx_1 < 4)) != 0) {
                for (int b_i{0}; b_i < unnamed_idx_1; b_i++) {
                  newIndices[b_i] = 0.0;
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i = 0; b_i < loop_ub; b_i++) {
                  newIndices[b_i] = 0.0;
                }
              }

              removedIdx.set_size(1, 0);
              i1 = BoardCoords.size(0);
              for (int j{0}; j < i1; j++) {
                int b_loop_ub;
                int c_loop_ub;
                b_loop_ub = BoardCoords.size(1);
                b_this.set_size(1, b_loop_ub);
                for (int i2{0}; i2 < b_loop_ub; i2++) {
                  b_this[i2] = BoardCoords[(j + (BoardCoords.size(0) * i2)) +
                    ((BoardCoords.size(0) * BoardCoords.size(1)) * ((
                       static_cast<int>(coordsToUse[0])) - 1))];
                }

                c_eml_find(b_this, c_ii);
                validIdx.set_size(1, c_ii.size(1));
                c_loop_ub = c_ii.size(1);
                for (int i3{0}; i3 < c_loop_ub; i3++) {
                  validIdx[i3] = static_cast<double>(c_ii[i3]);
                }

                if (validIdx.size(1) >= 2) {
                  double currCoord;
                  double currRad;
                  double refCoordValue;
                  int d_loop_ub;
                  int e_loop_ub;
                  int h_n;
                  int i4;
                  int p_n;
                  bool exitg1;
                  findSearchParams(idx, validIdx, (static_cast<double>(j)) + 1.0,
                                   coordsToUse, &coordDist, &moveDistMultiplier,
                                   &firstValidIdx);
                  h_n = 0;
                  i4 = validIdx.size(1);
                  for (int k{0}; k < i4; k++) {
                    if ((static_cast<int>(validIdx[k])) != 0) {
                      h_n++;
                    }
                  }

                  b_this.set_size(1, validIdx.size(1));
                  d_loop_ub = validIdx.size(1);
                  for (int i5{0}; i5 < d_loop_ub; i5++) {
                    b_this[i5] = BoardCoords[(j + (BoardCoords.size(0) * ((
                      static_cast<int>(validIdx[i5])) - 1))) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * ((
                         static_cast<int>(coordsToUse[0])) - 1))];
                  }

                  c_this.set_size(1, validIdx.size(1));
                  e_loop_ub = validIdx.size(1);
                  for (int i6{0}; i6 < e_loop_ub; i6++) {
                    c_this[i6] = BoardCoords[(j + (BoardCoords.size(0) * ((
                      static_cast<int>(validIdx[i6])) - 1))) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * ((
                         static_cast<int>(coordsToUse[1])) - 1))];
                  }

                  if (h_n > 5) {
                    p_n = 4;
                  } else {
                    p_n = 2;
                  }

                  b_polyfit(b_this, c_this, static_cast<double>(p_n), currCurve);
                  currRad = coordDist / 4.0;
                  refCoordValue = BoardCoords[(j + (BoardCoords.size(0) * ((
                    static_cast<int>(firstValidIdx)) - 1))) + ((BoardCoords.size
                    (0) * BoardCoords.size(1)) * ((static_cast<int>(coordsToUse
                    [0])) - 1))];
                  currCoord = currRad + refCoordValue;
                  exitg1 = false;
                  while ((!exitg1) && (std::abs(currCoord - refCoordValue) <
                                       ((moveDistMultiplier * 1.5) * std::abs
                                        (coordDist)))) {
                    b_dv[0] = 1.0;
                    b_dv[1] = 2.0;
                    if (isequal(coordsToUse, b_dv)) {
                      if (currCurve.size(1) != 0) {
                        int b_i8;
                        b_y = currCurve[0];
                        b_i8 = currCurve.size(1);
                        for (int c_k{0}; c_k <= (b_i8 - 2); c_k++) {
                          b_y = (currCoord * b_y) + currCurve[c_k + 1];
                        }
                      }

                      currPt[0] = currCoord;
                      currPt[1] = b_y;
                    } else {
                      if (currCurve.size(1) != 0) {
                        int i7;
                        y = currCurve[0];
                        i7 = currCurve.size(1);
                        for (int b_k{0}; b_k <= (i7 - 2); b_k++) {
                          y = (currCoord * y) + currCurve[b_k + 1];
                        }
                      }

                      currPt[0] = y;
                      currPt[1] = currCoord;
                    }

                    findClosestOnCurve(currPt, std::abs(currRad), currCurve,
                                       coordsToUse, removedIdx, b_index);
                    if (b_index.size(1) != 0) {
                      int f_loop_ub;
                      int i9;
                      newIndices[j] = b_index[0];
                      i9 = removedIdx.size(1);
                      f_loop_ub = b_index.size(1);
                      removedIdx.set_size(removedIdx.size(0), removedIdx.size(1)
                                          + b_index.size(1));
                      for (int i10{0}; i10 < f_loop_ub; i10++) {
                        removedIdx[i9 + i10] = b_index[i10];
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
            void b_Checkerboard::c_fitPolynomialIndices(const ::coder::array<
              double, 2U> &idx, ::coder::array<double, 2U> &newIndices) const
            {
              ::coder::array<double, 2U> b_index;
              ::coder::array<double, 2U> currCurve;
              ::coder::array<double, 2U> removedIdx;
              ::coder::array<double, 1U> b_this;
              ::coder::array<double, 1U> c_this;
              ::coder::array<double, 1U> validIdx;
              ::coder::array<int, 1U> c_ii;
              double b_dv[2];
              double coordsToUse[2];
              double currPt[2];
              double b_y;
              double coordDist;
              double firstValidIdx;
              double moveDistMultiplier;
              double y;
              int h_n;
              int i1;
              int i2;
              int loop_ub;
              int unnamed_idx_1;
              findIndependentVar(idx, coordsToUse);
              unnamed_idx_1 = BoardCoords.size(1);
              newIndices.set_size(1, unnamed_idx_1);
              loop_ub = unnamed_idx_1;
              if ((static_cast<int>(unnamed_idx_1 < 4)) != 0) {
                for (int b_i{0}; b_i < unnamed_idx_1; b_i++) {
                  newIndices[b_i] = 0.0;
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i = 0; b_i < loop_ub; b_i++) {
                  newIndices[b_i] = 0.0;
                }
              }

              removedIdx.set_size(1, 0);
              i1 = BoardCoords.size(1);
              for (int j{0}; j < i1; j++) {
                int b_loop_ub;
                int c_loop_ub;
                b_loop_ub = BoardCoords.size(0);
                b_this.set_size(b_loop_ub);
                for (int i3{0}; i3 < b_loop_ub; i3++) {
                  b_this[i3] = BoardCoords[(i3 + (BoardCoords.size(0) * j)) +
                    ((BoardCoords.size(0) * BoardCoords.size(1)) * ((
                       static_cast<int>(coordsToUse[0])) - 1))];
                }

                eml_find(b_this, c_ii);
                validIdx.set_size(c_ii.size(0));
                c_loop_ub = c_ii.size(0);
                for (int i4{0}; i4 < c_loop_ub; i4++) {
                  validIdx[i4] = static_cast<double>(c_ii[i4]);
                }

                if (validIdx.size(0) >= 2) {
                  double currCoord;
                  double currRad;
                  double refCoordValue;
                  int d_loop_ub;
                  int e_loop_ub;
                  int i5;
                  int p_n;
                  int q_n;
                  bool exitg1;
                  findSearchParams(idx, validIdx, (static_cast<double>(j)) + 1.0,
                                   coordsToUse, &coordDist, &moveDistMultiplier,
                                   &firstValidIdx);
                  p_n = 0;
                  i5 = validIdx.size(0);
                  for (int b_k{0}; b_k < i5; b_k++) {
                    if (validIdx[b_k] != 0.0) {
                      p_n++;
                    }
                  }

                  b_this.set_size(validIdx.size(0));
                  d_loop_ub = validIdx.size(0);
                  for (int i6{0}; i6 < d_loop_ub; i6++) {
                    b_this[i6] = BoardCoords[(((static_cast<int>(validIdx[i6]))
                      + (BoardCoords.size(0) * j)) + ((BoardCoords.size(0) *
                      BoardCoords.size(1)) * ((static_cast<int>(coordsToUse[0]))
                      - 1))) - 1];
                  }

                  c_this.set_size(validIdx.size(0));
                  e_loop_ub = validIdx.size(0);
                  for (int i7{0}; i7 < e_loop_ub; i7++) {
                    c_this[i7] = BoardCoords[(((static_cast<int>(validIdx[i7]))
                      + (BoardCoords.size(0) * j)) + ((BoardCoords.size(0) *
                      BoardCoords.size(1)) * ((static_cast<int>(coordsToUse[1]))
                      - 1))) - 1];
                  }

                  if (p_n > 5) {
                    q_n = 4;
                  } else {
                    q_n = 2;
                  }

                  polyfit(b_this, c_this, static_cast<double>(q_n), currCurve);
                  currRad = coordDist / 4.0;
                  refCoordValue = BoardCoords[(((static_cast<int>(firstValidIdx))
                    + (BoardCoords.size(0) * j)) + ((BoardCoords.size(0) *
                    BoardCoords.size(1)) * ((static_cast<int>(coordsToUse[0])) -
                    1))) - 1];
                  currCoord = currRad + refCoordValue;
                  exitg1 = false;
                  while ((!exitg1) && (std::abs(currCoord - refCoordValue) <
                                       ((moveDistMultiplier * 1.5) * std::abs
                                        (coordDist)))) {
                    b_dv[0] = 1.0;
                    b_dv[1] = 2.0;
                    if (isequal(coordsToUse, b_dv)) {
                      if (currCurve.size(1) != 0) {
                        int i9;
                        b_y = currCurve[0];
                        i9 = currCurve.size(1);
                        for (int d_k{0}; d_k <= (i9 - 2); d_k++) {
                          b_y = (currCoord * b_y) + currCurve[d_k + 1];
                        }
                      }

                      currPt[0] = currCoord;
                      currPt[1] = b_y;
                    } else {
                      if (currCurve.size(1) != 0) {
                        int b_i8;
                        y = currCurve[0];
                        b_i8 = currCurve.size(1);
                        for (int c_k{0}; c_k <= (b_i8 - 2); c_k++) {
                          y = (currCoord * y) + currCurve[c_k + 1];
                        }
                      }

                      currPt[0] = y;
                      currPt[1] = currCoord;
                    }

                    findClosestOnCurve(currPt, std::abs(currRad), currCurve,
                                       coordsToUse, removedIdx, b_index);
                    if (b_index.size(1) != 0) {
                      int f_loop_ub;
                      int i10;
                      newIndices[j] = b_index[0];
                      i10 = removedIdx.size(1);
                      f_loop_ub = b_index.size(1);
                      removedIdx.set_size(removedIdx.size(0), removedIdx.size(1)
                                          + b_index.size(1));
                      for (int i11{0}; i11 < f_loop_ub; i11++) {
                        removedIdx[i10 + i11] = b_index[i11];
                      }

                      exitg1 = true;
                    } else {
                      currCoord += currRad;
                    }
                  }
                }
              }

              h_n = 0;
              i2 = newIndices.size(1);
              for (int k{0}; k < i2; k++) {
                if (newIndices[k] != 0.0) {
                  h_n++;
                }
              }

              if (h_n < 4) {
                int end;
                end = newIndices.size(1);
                if ((static_cast<int>(newIndices.size(1) < 4)) != 0) {
                  for (int c_i{0}; c_i < end; c_i++) {
                    if (newIndices[c_i] > 0.0) {
                      newIndices[c_i] = 0.0;
                    }
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int c_i = 0; c_i < end; c_i++) {
                    if (newIndices[c_i] > 0.0) {
                      newIndices[c_i] = 0.0;
                    }
                  }
                }
              }
            }

            //
            // Arguments    : float oldEnergy
            // Return Type  : float
            //
            float b_Checkerboard::computeNewEnergyHorizontal(float oldEnergy)
              const
            {
              ::coder::array<double, 3U> c_this;
              ::coder::array<double, 3U> denom;
              ::coder::array<double, 3U> num;
              ::coder::array<double, 2U> e_denom;
              ::coder::array<double, 2U> f_num;
              ::coder::array<double, 2U> validNewColIdx;
              ::coder::array<double, 1U> e_x;
              ::coder::array<double, 1U> f_denom;
              ::coder::array<double, 1U> g_denom;
              ::coder::array<double, 1U> g_num;
              ::coder::array<double, 1U> h_num;
              ::coder::array<double, 1U> y;
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
              int b_loop_ub;
              int c_loop_ub;
              int d_loop_ub;
              int e_loop_ub;
              int f_loop_ub;
              int g_loop_ub;
              int i12;
              int i9;
              int k;
              int k_loop_ub;
              int loop_ub;
              int q_loop_ub;
              bool exitg1;
              bool varargout_1;
              loop_ub = BoardIdx.size(0);
              r.set_size(loop_ub);
              b_loop_ub = loop_ub;
              if ((static_cast<int>(loop_ub < 4)) != 0) {
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  r[b_i] = ((BoardIdx[b_i] > 0.0) && (BoardIdx[b_i +
                             BoardIdx.size(0)] > 0.0));
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i = 0; b_i < b_loop_ub; b_i++) {
                  r[b_i] = ((BoardIdx[b_i] > 0.0) && (BoardIdx[b_i +
                             BoardIdx.size(0)] > 0.0));
                }
              }

              c_loop_ub = BoardIdx.size(0);
              r1.set_size(c_loop_ub);
              d_loop_ub = c_loop_ub;
              if ((static_cast<int>(c_loop_ub < 4)) != 0) {
                for (int i1{0}; i1 < c_loop_ub; i1++) {
                  r1[i1] = (BoardIdx[i1 + (BoardIdx.size(0) * 2)] > 0.0);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i1 = 0; i1 < d_loop_ub; i1++) {
                  r1[i1] = (BoardIdx[i1 + (BoardIdx.size(0) * 2)] > 0.0);
                }
              }

              newEnergy = 0.0F;
              b_x.set_size(r.size(0));
              e_loop_ub = r.size(0);
              if ((static_cast<int>(r.size(0) < 4)) != 0) {
                for (int i2{0}; i2 < e_loop_ub; i2++) {
                  b_x[i2] = ((r[i2]) && (r1[i2]));
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i2 = 0; i2 < e_loop_ub; i2++) {
                  b_x[i2] = ((r[i2]) && (r1[i2]));
                }
              }

              varargout_1 = false;
              k = 0;
              exitg1 = false;
              while ((!exitg1) && (k <= (b_x.size(0) - 1))) {
                if (b_x[k]) {
                  varargout_1 = true;
                  exitg1 = true;
                } else {
                  k++;
                }
              }

              if (varargout_1) {
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
                int j_loop_ub;
                int m_loop_ub;
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
                for (int e_i{0}; e_i <= b_end; e_i++) {
                  if ((r[e_i]) && (r1[e_i])) {
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
                for (int k_i{0}; k_i <= c_end; k_i++) {
                  if ((r[k_i]) && (r1[k_i])) {
                    c_trueCount++;
                  }
                }

                r4.set_size(c_trueCount);
                c_partialTrueCount = 0;
                for (int m_i{0}; m_i <= c_end; m_i++) {
                  if ((r[m_i]) && (r1[m_i])) {
                    r4[c_partialTrueCount] = m_i + 1;
                    c_partialTrueCount++;
                  }
                }

                int i7;
                i7 = BoardCoords.size(2);
                c_this.set_size(r2.size(0), 1, i7);
                j_loop_ub = i7;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i9,k_loop_ub)

                for (int b_i8 = 0; b_i8 < j_loop_ub; b_i8++) {
                  k_loop_ub = r2.size(0);
                  for (i9 = 0; i9 < k_loop_ub; i9++) {
                    c_this[i9 + (c_this.size(0) * b_i8)] = (BoardCoords[(r2[i9]
                      + ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i8)) -
                      1] + BoardCoords[((r3[i9] + (BoardCoords.size(0) * 2)) +
                                        ((BoardCoords.size(0) * BoardCoords.size
                                          (1)) * b_i8)) - 1]) - (2.0 *
                      BoardCoords[((r4[i9] + BoardCoords.size(0)) +
                                   ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                    b_i8)) - 1]);
                  }
                }

                b_squeeze(c_this, f_num);
                d_end = r.size(0) - 1;
                d_trueCount = 0;
                for (int q_i{0}; q_i <= d_end; q_i++) {
                  if ((r[q_i]) && (r1[q_i])) {
                    d_trueCount++;
                  }
                }

                r5.set_size(d_trueCount);
                d_partialTrueCount = 0;
                for (int t_i{0}; t_i <= d_end; t_i++) {
                  if ((r[t_i]) && (r1[t_i])) {
                    r5[d_partialTrueCount] = t_i + 1;
                    d_partialTrueCount++;
                  }
                }

                e_end = r.size(0) - 1;
                e_trueCount = 0;
                for (int w_i{0}; w_i <= e_end; w_i++) {
                  if ((r[w_i]) && (r1[w_i])) {
                    e_trueCount++;
                  }
                }

                r6.set_size(e_trueCount);
                e_partialTrueCount = 0;
                for (int gb_i{0}; gb_i <= e_end; gb_i++) {
                  if ((r[gb_i]) && (r1[gb_i])) {
                    r6[e_partialTrueCount] = gb_i + 1;
                    e_partialTrueCount++;
                  }
                }

                int i10;
                i10 = BoardCoords.size(2);
                c_this.set_size(r5.size(0), 1, i10);
                m_loop_ub = i10;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i12,q_loop_ub)

                for (int i11 = 0; i11 < m_loop_ub; i11++) {
                  q_loop_ub = r5.size(0);
                  for (i12 = 0; i12 < q_loop_ub; i12++) {
                    c_this[i12 + (c_this.size(0) * i11)] = BoardCoords[(r5[i12]
                      + ((BoardCoords.size(0) * BoardCoords.size(1)) * i11)) - 1]
                      - BoardCoords[((r6[i12] + (BoardCoords.size(0) * 2)) +
                                     ((BoardCoords.size(0) * BoardCoords.size(1))
                                      * i11)) - 1];
                  }
                }

                b_squeeze(c_this, e_denom);
                if (f_num.size(1) > 1) {
                  int o_loop_ub;
                  int p_loop_ub;
                  int r_loop_ub;
                  int s_loop_ub;
                  int t_loop_ub;
                  int u_loop_ub;
                  int v_loop_ub;
                  int w_loop_ub;
                  int x_loop_ub;
                  o_loop_ub = f_num.size(0);
                  g_num.set_size(f_num.size(0));
                  p_loop_ub = f_num.size(0);
                  if ((static_cast<int>(f_num.size(0) < 4)) != 0) {
                    for (int i13{0}; i13 < o_loop_ub; i13++) {
                      g_num[i13] = f_num[i13];
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i13 = 0; i13 < p_loop_ub; i13++) {
                      g_num[i13] = f_num[i13];
                    }
                  }

                  r_loop_ub = f_num.size(0);
                  h_num.set_size(f_num.size(0));
                  s_loop_ub = f_num.size(0);
                  if ((static_cast<int>(f_num.size(0) < 4)) != 0) {
                    for (int i14{0}; i14 < r_loop_ub; i14++) {
                      h_num[i14] = f_num[i14 + f_num.size(0)];
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i14 = 0; i14 < s_loop_ub; i14++) {
                      h_num[i14] = f_num[i14 + f_num.size(0)];
                    }
                  }

                  c_hypot(g_num, h_num, e_x);
                  t_loop_ub = e_denom.size(0);
                  f_denom.set_size(e_denom.size(0));
                  u_loop_ub = e_denom.size(0);
                  if ((static_cast<int>(e_denom.size(0) < 4)) != 0) {
                    for (int i15{0}; i15 < t_loop_ub; i15++) {
                      f_denom[i15] = e_denom[i15];
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i15 = 0; i15 < u_loop_ub; i15++) {
                      f_denom[i15] = e_denom[i15];
                    }
                  }

                  v_loop_ub = e_denom.size(0);
                  g_denom.set_size(e_denom.size(0));
                  w_loop_ub = e_denom.size(0);
                  if ((static_cast<int>(e_denom.size(0) < 4)) != 0) {
                    for (int i16{0}; i16 < v_loop_ub; i16++) {
                      g_denom[i16] = e_denom[i16 + e_denom.size(0)];
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i16 = 0; i16 < w_loop_ub; i16++) {
                      g_denom[i16] = e_denom[i16 + e_denom.size(0)];
                    }
                  }

                  c_hypot(f_denom, g_denom, y);
                  x_loop_ub = e_x.size(0);
                  if ((static_cast<int>(e_x.size(0) < 4)) != 0) {
                    for (int i17{0}; i17 < x_loop_ub; i17++) {
                      e_x[i17] = e_x[i17] / y[i17];
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i17 = 0; i17 < x_loop_ub; i17++) {
                      e_x[i17] = e_x[i17] / y[i17];
                    }
                  }

                  newEnergy = std::fmax(oldEnergy, static_cast<float>(::ITER::
                    coder::internal::b_maximum(e_x)));
                } else {
                  newEnergy = std::fmax(oldEnergy, static_cast<float>(
                    static_cast<double>(rt_hypotd_snf(f_num[0], f_num[1]) /
                                        rt_hypotd_snf(e_denom[0], e_denom[1]))));
                }
              }

              f_loop_ub = BoardIdx.size(0);
              b_this.set_size(1, f_loop_ub);
              g_loop_ub = f_loop_ub;
              if ((static_cast<int>(f_loop_ub < 4)) != 0) {
                for (int i3{0}; i3 < f_loop_ub; i3++) {
                  b_this[i3] = (BoardIdx[i3] > 0.0);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i3 = 0; i3 < g_loop_ub; i3++) {
                  b_this[i3] = (BoardIdx[i3] > 0.0);
                }
              }

              b_Checkerboard::arrayFind(b_this, validNewColIdx);
              if (validNewColIdx.size(1) != 0) {
                int i4;
                i4 = validNewColIdx.size(1);
                for (int g_i{0}; g_i < i4; g_i++) {
                  double b_d1;
                  double d;
                  int h_loop_ub;
                  int i_loop_ub;
                  d = validNewColIdx[g_i];
                  h_loop_ub = BoardCoords.size(2);
                  num.set_size(1, 1, h_loop_ub);
                  for (int i5{0}; i5 < h_loop_ub; i5++) {
                    num[i5] = (BoardCoords[((static_cast<int>(d)) +
                                ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                 i5)) - 1] + BoardCoords[((static_cast<int>(
                      static_cast<double>(d + 2.0))) + ((BoardCoords.size(0) *
                      BoardCoords.size(1)) * i5)) - 1]) - (2.0 * BoardCoords[((
                      static_cast<int>(static_cast<double>(d + 1.0))) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * i5)) - 1]);
                  }

                  b_d1 = validNewColIdx[g_i];
                  i_loop_ub = BoardCoords.size(2);
                  denom.set_size(1, 1, i_loop_ub);
                  for (int i6{0}; i6 < i_loop_ub; i6++) {
                    denom[i6] = BoardCoords[((static_cast<int>(b_d1)) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * i6)) - 1] -
                      BoardCoords[((static_cast<int>(static_cast<double>(b_d1 +
                      2.0))) + ((BoardCoords.size(0) * BoardCoords.size(1)) * i6))
                      - 1];
                  }

                  if (newEnergy != 0.0F) {
                    ::coder::array<double, 1U> d_denom;
                    ::coder::array<double, 1U> d_num;
                    int b_denom;
                    int b_num;
                    b_num = num.size(2);
                    b_denom = denom.size(2);
                    d_num = num.reshape(b_num);
                    d_denom = denom.reshape(b_denom);
                    newEnergy = std::fmax(newEnergy, static_cast<float>(
                      static_cast<double>(b_norm(d_num) / b_norm(d_denom))));
                  } else {
                    ::coder::array<double, 1U> c_denom;
                    ::coder::array<double, 1U> c_num;
                    int b_denom;
                    int b_num;
                    b_num = num.size(2);
                    b_denom = denom.size(2);
                    c_num = num.reshape(b_num);
                    c_denom = denom.reshape(b_denom);
                    newEnergy = std::fmax(oldEnergy, static_cast<float>(
                      static_cast<double>(b_norm(c_num) / b_norm(c_denom))));
                  }
                }
              }

              if (newEnergy != 0.0F) {
                newEnergy = (newEnergy * (static_cast<float>(static_cast<int>
                  (BoardIdx.size(0) * BoardIdx.size(1))))) - (static_cast<float>
                  (static_cast<int>(BoardIdx.size(0) * BoardIdx.size(1))));
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
            float b_Checkerboard::computeNewEnergyHorizontal(const ::coder::
              array<double, 2U> &idx, float oldEnergy) const
            {
              ::coder::array<double, 3U> c_this;
              ::coder::array<double, 3U> denom;
              ::coder::array<double, 3U> num;
              ::coder::array<double, 2U> e_denom;
              ::coder::array<double, 2U> f_num;
              ::coder::array<double, 2U> validNewColIdx;
              ::coder::array<double, 1U> e_x;
              ::coder::array<double, 1U> f_denom;
              ::coder::array<double, 1U> g_denom;
              ::coder::array<double, 1U> g_num;
              ::coder::array<double, 1U> h_num;
              ::coder::array<double, 1U> y;
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
              int b_idx;
              int b_idx_tmp;
              int b_loop_ub;
              int c_idx;
              int c_idx_tmp;
              int c_loop_ub;
              int d_idx;
              int d_loop_ub;
              int e_idx;
              int e_loop_ub;
              int f_idx;
              int f_loop_ub;
              int g_loop_ub;
              int i12;
              int i9;
              int idx_tmp;
              int k;
              int k_loop_ub;
              int loop_ub;
              int q_loop_ub;
              bool exitg1;
              bool varargout_1;
              idx_tmp = static_cast<int>(idx[0]);
              b_idx = idx_tmp;
              b_idx_tmp = static_cast<int>(idx[1]);
              c_idx = b_idx_tmp;
              loop_ub = BoardIdx.size(0);
              r.set_size(loop_ub);
              b_loop_ub = loop_ub;
              if ((static_cast<int>(loop_ub < 4)) != 0) {
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  r[b_i] = ((BoardIdx[b_i + (BoardIdx.size(0) * (idx_tmp - 1))] >
                             0.0) && (BoardIdx[b_i + (BoardIdx.size(0) *
                              (b_idx_tmp - 1))] > 0.0));
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i = 0; b_i < b_loop_ub; b_i++) {
                  r[b_i] = ((BoardIdx[b_i + (BoardIdx.size(0) * (b_idx - 1))] >
                             0.0) && (BoardIdx[b_i + (BoardIdx.size(0) * (c_idx
                    - 1))] > 0.0));
                }
              }

              c_idx_tmp = static_cast<int>(idx[2]);
              d_idx = c_idx_tmp;
              c_loop_ub = BoardIdx.size(0);
              r1.set_size(c_loop_ub);
              d_loop_ub = c_loop_ub;
              if ((static_cast<int>(c_loop_ub < 4)) != 0) {
                for (int i1{0}; i1 < c_loop_ub; i1++) {
                  r1[i1] = (BoardIdx[i1 + (BoardIdx.size(0) * (c_idx_tmp - 1))] >
                            0.0);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i1 = 0; i1 < d_loop_ub; i1++) {
                  r1[i1] = (BoardIdx[i1 + (BoardIdx.size(0) * (d_idx - 1))] >
                            0.0);
                }
              }

              newEnergy = 0.0F;
              b_x.set_size(r.size(0));
              e_loop_ub = r.size(0);
              if ((static_cast<int>(r.size(0) < 4)) != 0) {
                for (int i2{0}; i2 < e_loop_ub; i2++) {
                  b_x[i2] = ((r[i2]) && (r1[i2]));
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i2 = 0; i2 < e_loop_ub; i2++) {
                  b_x[i2] = ((r[i2]) && (r1[i2]));
                }
              }

              varargout_1 = false;
              k = 0;
              exitg1 = false;
              while ((!exitg1) && (k <= (b_x.size(0) - 1))) {
                if (b_x[k]) {
                  varargout_1 = true;
                  exitg1 = true;
                } else {
                  k++;
                }
              }

              if (varargout_1) {
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
                int g_idx;
                int h_idx;
                int j_idx;
                int j_loop_ub;
                int m_idx;
                int m_loop_ub;
                int o_idx;
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
                for (int e_i{0}; e_i <= b_end; e_i++) {
                  if ((r[e_i]) && (r1[e_i])) {
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
                for (int k_i{0}; k_i <= c_end; k_i++) {
                  if ((r[k_i]) && (r1[k_i])) {
                    c_trueCount++;
                  }
                }

                r4.set_size(c_trueCount);
                c_partialTrueCount = 0;
                for (int m_i{0}; m_i <= c_end; m_i++) {
                  if ((r[m_i]) && (r1[m_i])) {
                    r4[c_partialTrueCount] = m_i + 1;
                    c_partialTrueCount++;
                  }
                }

                int i7;
                g_idx = static_cast<int>(idx[0]);
                h_idx = static_cast<int>(idx[2]);
                j_idx = static_cast<int>(idx[1]);
                i7 = BoardCoords.size(2);
                c_this.set_size(r2.size(0), 1, i7);
                j_loop_ub = i7;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i9,k_loop_ub)

                for (int b_i8 = 0; b_i8 < j_loop_ub; b_i8++) {
                  k_loop_ub = r2.size(0);
                  for (i9 = 0; i9 < k_loop_ub; i9++) {
                    c_this[i9 + (c_this.size(0) * b_i8)] = (BoardCoords[((r2[i9]
                      + (BoardCoords.size(0) * (g_idx - 1))) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i8)) - 1]
                      + BoardCoords[((r3[i9] + (BoardCoords.size(0) * (h_idx - 1)))
                                     + ((BoardCoords.size(0) * BoardCoords.size
                                         (1)) * b_i8)) - 1]) - (2.0 *
                      BoardCoords[((r4[i9] + (BoardCoords.size(0) * (j_idx - 1)))
                                   + ((BoardCoords.size(0) * BoardCoords.size(1))
                                      * b_i8)) - 1]);
                  }
                }

                b_squeeze(c_this, f_num);
                d_end = r.size(0) - 1;
                d_trueCount = 0;
                for (int q_i{0}; q_i <= d_end; q_i++) {
                  if ((r[q_i]) && (r1[q_i])) {
                    d_trueCount++;
                  }
                }

                r5.set_size(d_trueCount);
                d_partialTrueCount = 0;
                for (int t_i{0}; t_i <= d_end; t_i++) {
                  if ((r[t_i]) && (r1[t_i])) {
                    r5[d_partialTrueCount] = t_i + 1;
                    d_partialTrueCount++;
                  }
                }

                e_end = r.size(0) - 1;
                e_trueCount = 0;
                for (int w_i{0}; w_i <= e_end; w_i++) {
                  if ((r[w_i]) && (r1[w_i])) {
                    e_trueCount++;
                  }
                }

                r6.set_size(e_trueCount);
                e_partialTrueCount = 0;
                for (int gb_i{0}; gb_i <= e_end; gb_i++) {
                  if ((r[gb_i]) && (r1[gb_i])) {
                    r6[e_partialTrueCount] = gb_i + 1;
                    e_partialTrueCount++;
                  }
                }

                int i10;
                m_idx = static_cast<int>(idx[0]);
                o_idx = static_cast<int>(idx[2]);
                i10 = BoardCoords.size(2);
                c_this.set_size(r5.size(0), 1, i10);
                m_loop_ub = i10;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i12,q_loop_ub)

                for (int i11 = 0; i11 < m_loop_ub; i11++) {
                  q_loop_ub = r5.size(0);
                  for (i12 = 0; i12 < q_loop_ub; i12++) {
                    c_this[i12 + (c_this.size(0) * i11)] = BoardCoords[((r5[i12]
                      + (BoardCoords.size(0) * (m_idx - 1))) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * i11)) - 1]
                      - BoardCoords[((r6[i12] + (BoardCoords.size(0) * (o_idx -
                      1))) + ((BoardCoords.size(0) * BoardCoords.size(1)) * i11))
                      - 1];
                  }
                }

                b_squeeze(c_this, e_denom);
                if (f_num.size(1) > 1) {
                  int o_loop_ub;
                  int p_loop_ub;
                  int r_loop_ub;
                  int s_loop_ub;
                  int t_loop_ub;
                  int u_loop_ub;
                  int v_loop_ub;
                  int w_loop_ub;
                  int x_loop_ub;
                  o_loop_ub = f_num.size(0);
                  g_num.set_size(f_num.size(0));
                  p_loop_ub = f_num.size(0);
                  if ((static_cast<int>(f_num.size(0) < 4)) != 0) {
                    for (int i13{0}; i13 < o_loop_ub; i13++) {
                      g_num[i13] = f_num[i13];
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i13 = 0; i13 < p_loop_ub; i13++) {
                      g_num[i13] = f_num[i13];
                    }
                  }

                  r_loop_ub = f_num.size(0);
                  h_num.set_size(f_num.size(0));
                  s_loop_ub = f_num.size(0);
                  if ((static_cast<int>(f_num.size(0) < 4)) != 0) {
                    for (int i14{0}; i14 < r_loop_ub; i14++) {
                      h_num[i14] = f_num[i14 + f_num.size(0)];
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i14 = 0; i14 < s_loop_ub; i14++) {
                      h_num[i14] = f_num[i14 + f_num.size(0)];
                    }
                  }

                  c_hypot(g_num, h_num, e_x);
                  t_loop_ub = e_denom.size(0);
                  f_denom.set_size(e_denom.size(0));
                  u_loop_ub = e_denom.size(0);
                  if ((static_cast<int>(e_denom.size(0) < 4)) != 0) {
                    for (int i15{0}; i15 < t_loop_ub; i15++) {
                      f_denom[i15] = e_denom[i15];
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i15 = 0; i15 < u_loop_ub; i15++) {
                      f_denom[i15] = e_denom[i15];
                    }
                  }

                  v_loop_ub = e_denom.size(0);
                  g_denom.set_size(e_denom.size(0));
                  w_loop_ub = e_denom.size(0);
                  if ((static_cast<int>(e_denom.size(0) < 4)) != 0) {
                    for (int i16{0}; i16 < v_loop_ub; i16++) {
                      g_denom[i16] = e_denom[i16 + e_denom.size(0)];
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i16 = 0; i16 < w_loop_ub; i16++) {
                      g_denom[i16] = e_denom[i16 + e_denom.size(0)];
                    }
                  }

                  c_hypot(f_denom, g_denom, y);
                  x_loop_ub = e_x.size(0);
                  if ((static_cast<int>(e_x.size(0) < 4)) != 0) {
                    for (int i17{0}; i17 < x_loop_ub; i17++) {
                      e_x[i17] = e_x[i17] / y[i17];
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i17 = 0; i17 < x_loop_ub; i17++) {
                      e_x[i17] = e_x[i17] / y[i17];
                    }
                  }

                  newEnergy = std::fmax(oldEnergy, static_cast<float>(::ITER::
                    coder::internal::b_maximum(e_x)));
                } else {
                  newEnergy = std::fmax(oldEnergy, static_cast<float>(
                    static_cast<double>(rt_hypotd_snf(f_num[0], f_num[1]) /
                                        rt_hypotd_snf(e_denom[0], e_denom[1]))));
                }
              }

              e_idx = static_cast<int>(idx[0]);
              f_idx = e_idx;
              f_loop_ub = BoardIdx.size(0);
              b_this.set_size(1, f_loop_ub);
              g_loop_ub = f_loop_ub;
              if ((static_cast<int>(f_loop_ub < 4)) != 0) {
                for (int i3{0}; i3 < f_loop_ub; i3++) {
                  b_this[i3] = (BoardIdx[i3 + (BoardIdx.size(0) * (e_idx - 1))] >
                                0.0);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i3 = 0; i3 < g_loop_ub; i3++) {
                  b_this[i3] = (BoardIdx[i3 + (BoardIdx.size(0) * (f_idx - 1))] >
                                0.0);
                }
              }

              b_Checkerboard::arrayFind(b_this, validNewColIdx);
              if (validNewColIdx.size(1) != 0) {
                int i4;
                i4 = validNewColIdx.size(1);
                for (int g_i{0}; g_i < i4; g_i++) {
                  double b_d1;
                  double d;
                  double d2;
                  double d3;
                  int h_loop_ub;
                  int i_loop_ub;
                  d = validNewColIdx[g_i];
                  b_d1 = idx[0];
                  h_loop_ub = BoardCoords.size(2);
                  num.set_size(1, 1, h_loop_ub);
                  for (int i5{0}; i5 < h_loop_ub; i5++) {
                    num[i5] = (BoardCoords[(((static_cast<int>(d)) +
                      (BoardCoords.size(0) * ((static_cast<int>(b_d1)) - 1))) +
                                ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                 i5)) - 1] + BoardCoords[(((static_cast<int>(
                      static_cast<double>(d + 2.0))) + (BoardCoords.size(0) * ((
                      static_cast<int>(b_d1)) - 1))) + ((BoardCoords.size(0) *
                      BoardCoords.size(1)) * i5)) - 1]) - (2.0 * BoardCoords[(((
                      static_cast<int>(static_cast<double>(d + 1.0))) +
                      (BoardCoords.size(0) * ((static_cast<int>(b_d1)) - 1))) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * i5)) - 1]);
                  }

                  d2 = validNewColIdx[g_i];
                  d3 = idx[0];
                  i_loop_ub = BoardCoords.size(2);
                  denom.set_size(1, 1, i_loop_ub);
                  for (int i6{0}; i6 < i_loop_ub; i6++) {
                    denom[i6] = BoardCoords[(((static_cast<int>(d2)) +
                      (BoardCoords.size(0) * ((static_cast<int>(d3)) - 1))) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * i6)) - 1] -
                      BoardCoords[(((static_cast<int>(static_cast<double>(d2 +
                      2.0))) + (BoardCoords.size(0) * ((static_cast<int>(d3)) -
                      1))) + ((BoardCoords.size(0) * BoardCoords.size(1)) * i6))
                      - 1];
                  }

                  if (newEnergy != 0.0F) {
                    ::coder::array<double, 1U> d_denom;
                    ::coder::array<double, 1U> d_num;
                    int b_denom;
                    int b_num;
                    b_num = num.size(2);
                    b_denom = denom.size(2);
                    d_num = num.reshape(b_num);
                    d_denom = denom.reshape(b_denom);
                    newEnergy = std::fmax(newEnergy, static_cast<float>(
                      static_cast<double>(b_norm(d_num) / b_norm(d_denom))));
                  } else {
                    ::coder::array<double, 1U> c_denom;
                    ::coder::array<double, 1U> c_num;
                    int b_denom;
                    int b_num;
                    b_num = num.size(2);
                    b_denom = denom.size(2);
                    c_num = num.reshape(b_num);
                    c_denom = denom.reshape(b_denom);
                    newEnergy = std::fmax(oldEnergy, static_cast<float>(
                      static_cast<double>(b_norm(c_num) / b_norm(c_denom))));
                  }
                }
              }

              if (newEnergy != 0.0F) {
                newEnergy = (newEnergy * (static_cast<float>(static_cast<int>
                  (BoardIdx.size(0) * BoardIdx.size(1))))) - (static_cast<float>
                  (static_cast<int>(BoardIdx.size(0) * BoardIdx.size(1))));
              } else {
                newEnergy = rtInfF;
              }

              return newEnergy;
            }

            //
            // Arguments    : float oldEnergy
            // Return Type  : float
            //
            float b_Checkerboard::computeNewEnergyVertical(float oldEnergy)
              const
            {
              ::coder::array<double, 3U> b;
              ::coder::array<double, 3U> denom;
              ::coder::array<double, 3U> num;
              ::coder::array<double, 3U> r3;
              ::coder::array<double, 3U> r5;
              ::coder::array<double, 2U> e_denom;
              ::coder::array<double, 2U> f_num;
              ::coder::array<double, 2U> validNewRowIdx;
              ::coder::array<double, 1U> b_y;
              ::coder::array<double, 1U> e_x;
              ::coder::array<double, 1U> f_denom;
              ::coder::array<double, 1U> g_denom;
              ::coder::array<double, 1U> g_num;
              ::coder::array<double, 1U> h_num;
              ::coder::array<int, 2U> r2;
              ::coder::array<int, 2U> r4;
              ::coder::array<int, 2U> r6;
              ::coder::array<int, 2U> r7;
              ::coder::array<int, 2U> r8;
              ::coder::array<bool, 2U> b_this;
              ::coder::array<bool, 2U> b_x;
              ::coder::array<bool, 2U> r;
              ::coder::array<bool, 2U> r1;
              float newEnergy;
              int ab_loop_ub;
              int b_loop_ub;
              int c_loop_ub;
              int d_loop_ub;
              int e_loop_ub;
              int f_loop_ub;
              int g_loop_ub;
              int i12;
              int i16;
              int i17;
              int i20;
              int i24;
              int i25;
              int i7;
              int j_loop_ub;
              int k;
              int loop_ub;
              int o_loop_ub;
              int r_loop_ub;
              int s_loop_ub;
              int u_loop_ub;
              int x_loop_ub;
              bool exitg1;
              bool y;
              loop_ub = BoardIdx.size(1);
              r.set_size(1, loop_ub);
              b_loop_ub = loop_ub;
              if ((static_cast<int>(loop_ub < 4)) != 0) {
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  r[b_i] = ((BoardIdx[BoardIdx.size(0) * b_i] > 0.0) &&
                            (BoardIdx[(BoardIdx.size(0) * b_i) + 1] > 0.0));
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i = 0; b_i < b_loop_ub; b_i++) {
                  r[b_i] = ((BoardIdx[BoardIdx.size(0) * b_i] > 0.0) &&
                            (BoardIdx[(BoardIdx.size(0) * b_i) + 1] > 0.0));
                }
              }

              c_loop_ub = BoardIdx.size(1);
              r1.set_size(1, c_loop_ub);
              d_loop_ub = c_loop_ub;
              if ((static_cast<int>(c_loop_ub < 4)) != 0) {
                for (int i1{0}; i1 < c_loop_ub; i1++) {
                  r1[i1] = (BoardIdx[(BoardIdx.size(0) * i1) + 2] > 0.0);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i1 = 0; i1 < d_loop_ub; i1++) {
                  r1[i1] = (BoardIdx[(BoardIdx.size(0) * i1) + 2] > 0.0);
                }
              }

              newEnergy = 0.0F;
              b_x.set_size(1, r.size(1));
              e_loop_ub = r.size(1);
              if ((static_cast<int>(r.size(1) < 4)) != 0) {
                for (int i2{0}; i2 < e_loop_ub; i2++) {
                  b_x[i2] = ((r[i2]) && (r1[i2]));
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i2 = 0; i2 < e_loop_ub; i2++) {
                  b_x[i2] = ((r[i2]) && (r1[i2]));
                }
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
                int e_partialTrueCount;
                int e_trueCount;
                int end;
                int h_loop_ub;
                int m_loop_ub;
                int p_loop_ub;
                int partialTrueCount;
                int q_loop_ub;
                int t_loop_ub;
                int trueCount;
                int v_loop_ub;
                int w_loop_ub;
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

                int i4;
                i4 = BoardCoords.size(2);
                r3.set_size(1, r2.size(1), i4);
                h_loop_ub = i4;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i7,j_loop_ub)

                for (int i6 = 0; i6 < h_loop_ub; i6++) {
                  j_loop_ub = r2.size(1);
                  for (i7 = 0; i7 < j_loop_ub; i7++) {
                    r3[i7 + (r3.size(1) * i6)] = BoardCoords[(BoardCoords.size(0)
                      * (r2[i7] - 1)) + ((BoardCoords.size(0) * BoardCoords.size
                                          (1)) * i6)];
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

                int i10;
                i10 = BoardCoords.size(2);
                r5.set_size(1, r4.size(1), i10);
                m_loop_ub = i10;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i12,o_loop_ub)

                for (int i11 = 0; i11 < m_loop_ub; i11++) {
                  o_loop_ub = r4.size(1);
                  for (i12 = 0; i12 < o_loop_ub; i12++) {
                    r5[i12 + (r5.size(1) * i11)] = BoardCoords
                      [((BoardCoords.size(0) * (r4[i12] - 1)) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) * i11)) + 2];
                  }
                }

                c_end = r.size(1) - 1;
                c_trueCount = 0;
                for (int k_i{0}; k_i <= c_end; k_i++) {
                  if ((r[k_i]) && (r1[k_i])) {
                    c_trueCount++;
                  }
                }

                r6.set_size(1, c_trueCount);
                c_partialTrueCount = 0;
                for (int m_i{0}; m_i <= c_end; m_i++) {
                  if ((r[m_i]) && (r1[m_i])) {
                    r6[c_partialTrueCount] = m_i + 1;
                    c_partialTrueCount++;
                  }
                }

                int i13;
                i13 = BoardCoords.size(2);
                b.set_size(1, r6.size(1), i13);
                p_loop_ub = i13;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i16,r_loop_ub)

                for (int i14 = 0; i14 < p_loop_ub; i14++) {
                  r_loop_ub = r6.size(1);
                  for (i16 = 0; i16 < r_loop_ub; i16++) {
                    b[i16 + (b.size(1) * i14)] = BoardCoords[((BoardCoords.size
                      (0) * (r6[i16] - 1)) + ((BoardCoords.size(0) *
                      BoardCoords.size(1)) * i14)) + 1];
                  }
                }

                r3.set_size(1, r3.size(1), r3.size(2));
                q_loop_ub = r3.size(2);

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i17,s_loop_ub)

                for (int i15 = 0; i15 < q_loop_ub; i15++) {
                  s_loop_ub = r3.size(1);
                  for (i17 = 0; i17 < s_loop_ub; i17++) {
                    r3[i17 + (r3.size(1) * i15)] = (r3[i17 + (r3.size(1) * i15)]
                      + r5[i17 + (r5.size(1) * i15)]) - (2.0 * b[i17 + (b.size(1)
                      * i15)]);
                  }
                }

                squeeze(r3, f_num);
                d_end = r.size(1) - 1;
                d_trueCount = 0;
                for (int q_i{0}; q_i <= d_end; q_i++) {
                  if ((r[q_i]) && (r1[q_i])) {
                    d_trueCount++;
                  }
                }

                r7.set_size(1, d_trueCount);
                d_partialTrueCount = 0;
                for (int t_i{0}; t_i <= d_end; t_i++) {
                  if ((r[t_i]) && (r1[t_i])) {
                    r7[d_partialTrueCount] = t_i + 1;
                    d_partialTrueCount++;
                  }
                }

                int i18;
                i18 = BoardCoords.size(2);
                r3.set_size(1, r7.size(1), i18);
                t_loop_ub = i18;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i20,u_loop_ub)

                for (int i19 = 0; i19 < t_loop_ub; i19++) {
                  u_loop_ub = r7.size(1);
                  for (i20 = 0; i20 < u_loop_ub; i20++) {
                    r3[i20 + (r3.size(1) * i19)] = BoardCoords[(BoardCoords.size
                      (0) * (r7[i20] - 1)) + ((BoardCoords.size(0) *
                      BoardCoords.size(1)) * i19)];
                  }
                }

                e_end = r.size(1) - 1;
                e_trueCount = 0;
                for (int w_i{0}; w_i <= e_end; w_i++) {
                  if ((r[w_i]) && (r1[w_i])) {
                    e_trueCount++;
                  }
                }

                r8.set_size(1, e_trueCount);
                e_partialTrueCount = 0;
                for (int gb_i{0}; gb_i <= e_end; gb_i++) {
                  if ((r[gb_i]) && (r1[gb_i])) {
                    r8[e_partialTrueCount] = gb_i + 1;
                    e_partialTrueCount++;
                  }
                }

                int i21;
                i21 = BoardCoords.size(2);
                r5.set_size(1, r8.size(1), i21);
                v_loop_ub = i21;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i24,x_loop_ub)

                for (int i22 = 0; i22 < v_loop_ub; i22++) {
                  x_loop_ub = r8.size(1);
                  for (i24 = 0; i24 < x_loop_ub; i24++) {
                    r5[i24 + (r5.size(1) * i22)] = BoardCoords
                      [((BoardCoords.size(0) * (r8[i24] - 1)) +
                        ((BoardCoords.size(0) * BoardCoords.size(1)) * i22)) + 2];
                  }
                }

                r3.set_size(1, r3.size(1), r3.size(2));
                w_loop_ub = r3.size(2);

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i25,ab_loop_ub)

                for (int i23 = 0; i23 < w_loop_ub; i23++) {
                  ab_loop_ub = r3.size(1);
                  for (i25 = 0; i25 < ab_loop_ub; i25++) {
                    r3[i25 + (r3.size(1) * i23)] = r3[i25 + (r3.size(1) * i23)]
                      - r5[i25 + (r5.size(1) * i23)];
                  }
                }

                squeeze(r3, e_denom);
                if (f_num.size(1) > 1) {
                  int bb_loop_ub;
                  int cb_loop_ub;
                  int db_loop_ub;
                  int eb_loop_ub;
                  int fb_loop_ub;
                  int gb_loop_ub;
                  int hb_loop_ub;
                  int ib_loop_ub;
                  int y_loop_ub;
                  y_loop_ub = f_num.size(0);
                  g_num.set_size(f_num.size(0));
                  bb_loop_ub = f_num.size(0);
                  if ((static_cast<int>(f_num.size(0) < 4)) != 0) {
                    for (int i26{0}; i26 < y_loop_ub; i26++) {
                      g_num[i26] = f_num[i26];
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i26 = 0; i26 < bb_loop_ub; i26++) {
                      g_num[i26] = f_num[i26];
                    }
                  }

                  cb_loop_ub = f_num.size(0);
                  h_num.set_size(f_num.size(0));
                  db_loop_ub = f_num.size(0);
                  if ((static_cast<int>(f_num.size(0) < 4)) != 0) {
                    for (int i27{0}; i27 < cb_loop_ub; i27++) {
                      h_num[i27] = f_num[i27 + f_num.size(0)];
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i27 = 0; i27 < db_loop_ub; i27++) {
                      h_num[i27] = f_num[i27 + f_num.size(0)];
                    }
                  }

                  c_hypot(g_num, h_num, e_x);
                  eb_loop_ub = e_denom.size(0);
                  f_denom.set_size(e_denom.size(0));
                  fb_loop_ub = e_denom.size(0);
                  if ((static_cast<int>(e_denom.size(0) < 4)) != 0) {
                    for (int i28{0}; i28 < eb_loop_ub; i28++) {
                      f_denom[i28] = e_denom[i28];
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i28 = 0; i28 < fb_loop_ub; i28++) {
                      f_denom[i28] = e_denom[i28];
                    }
                  }

                  gb_loop_ub = e_denom.size(0);
                  g_denom.set_size(e_denom.size(0));
                  hb_loop_ub = e_denom.size(0);
                  if ((static_cast<int>(e_denom.size(0) < 4)) != 0) {
                    for (int i29{0}; i29 < gb_loop_ub; i29++) {
                      g_denom[i29] = e_denom[i29 + e_denom.size(0)];
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i29 = 0; i29 < hb_loop_ub; i29++) {
                      g_denom[i29] = e_denom[i29 + e_denom.size(0)];
                    }
                  }

                  c_hypot(f_denom, g_denom, b_y);
                  ib_loop_ub = e_x.size(0);
                  if ((static_cast<int>(e_x.size(0) < 4)) != 0) {
                    for (int i30{0}; i30 < ib_loop_ub; i30++) {
                      e_x[i30] = e_x[i30] / b_y[i30];
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i30 = 0; i30 < ib_loop_ub; i30++) {
                      e_x[i30] = e_x[i30] / b_y[i30];
                    }
                  }

                  newEnergy = std::fmax(oldEnergy, static_cast<float>(::ITER::
                    coder::internal::b_maximum(e_x)));
                } else {
                  newEnergy = std::fmax(oldEnergy, static_cast<float>(
                    static_cast<double>(rt_hypotd_snf(f_num[0], f_num[1]) /
                                        rt_hypotd_snf(e_denom[0], e_denom[1]))));
                }
              }

              f_loop_ub = BoardIdx.size(1);
              b_this.set_size(1, f_loop_ub);
              g_loop_ub = f_loop_ub;
              if ((static_cast<int>(f_loop_ub < 4)) != 0) {
                for (int i3{0}; i3 < f_loop_ub; i3++) {
                  b_this[i3] = (BoardIdx[BoardIdx.size(0) * i3] > 0.0);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i3 = 0; i3 < g_loop_ub; i3++) {
                  b_this[i3] = (BoardIdx[BoardIdx.size(0) * i3] > 0.0);
                }
              }

              b_Checkerboard::arrayFind(b_this, validNewRowIdx);
              if (validNewRowIdx.size(1) != 0) {
                int i5;
                i5 = validNewRowIdx.size(1);
                for (int e_i{0}; e_i < i5; e_i++) {
                  double b_d1;
                  double d;
                  int i_loop_ub;
                  int k_loop_ub;
                  d = validNewRowIdx[e_i];
                  i_loop_ub = BoardCoords.size(2);
                  num.set_size(1, 1, i_loop_ub);
                  for (int b_i8{0}; b_i8 < i_loop_ub; b_i8++) {
                    num[b_i8] = (BoardCoords[(BoardCoords.size(0) * ((
                      static_cast<int>(d)) - 1)) + ((BoardCoords.size(0) *
                      BoardCoords.size(1)) * b_i8)] + BoardCoords
                                 [(BoardCoords.size(0) * ((static_cast<int>(
                      static_cast<double>(d + 2.0))) - 1)) + ((BoardCoords.size
                      (0) * BoardCoords.size(1)) * b_i8)]) - (2.0 * BoardCoords
                      [(BoardCoords.size(0) * ((static_cast<int>(static_cast<
                      double>(d + 1.0))) - 1)) + ((BoardCoords.size(0) *
                      BoardCoords.size(1)) * b_i8)]);
                  }

                  b_d1 = validNewRowIdx[e_i];
                  k_loop_ub = BoardCoords.size(2);
                  denom.set_size(1, 1, k_loop_ub);
                  for (int i9{0}; i9 < k_loop_ub; i9++) {
                    denom[i9] = BoardCoords[(BoardCoords.size(0) * ((
                      static_cast<int>(b_d1)) - 1)) + ((BoardCoords.size(0) *
                      BoardCoords.size(1)) * i9)] - BoardCoords
                      [(BoardCoords.size(0) * ((static_cast<int>(static_cast<
                           double>(b_d1 + 2.0))) - 1)) + ((BoardCoords.size(0) *
                      BoardCoords.size(1)) * i9)];
                  }

                  if (newEnergy != 0.0F) {
                    ::coder::array<double, 1U> d_denom;
                    ::coder::array<double, 1U> d_num;
                    int b_denom;
                    int b_num;
                    b_num = num.size(2);
                    b_denom = denom.size(2);
                    d_num = num.reshape(b_num);
                    d_denom = denom.reshape(b_denom);
                    newEnergy = std::fmax(newEnergy, static_cast<float>(
                      static_cast<double>(b_norm(d_num) / b_norm(d_denom))));
                  } else {
                    ::coder::array<double, 1U> c_denom;
                    ::coder::array<double, 1U> c_num;
                    int b_denom;
                    int b_num;
                    b_num = num.size(2);
                    b_denom = denom.size(2);
                    c_num = num.reshape(b_num);
                    c_denom = denom.reshape(b_denom);
                    newEnergy = std::fmax(oldEnergy, static_cast<float>(
                      static_cast<double>(b_norm(c_num) / b_norm(c_denom))));
                  }
                }
              }

              if (newEnergy != 0.0F) {
                newEnergy = (newEnergy * (static_cast<float>(static_cast<int>
                  (BoardIdx.size(0) * BoardIdx.size(1))))) - (static_cast<float>
                  (static_cast<int>(BoardIdx.size(0) * BoardIdx.size(1))));
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
            float b_Checkerboard::computeNewEnergyVertical(const ::coder::array<
              double, 2U> &idx, float oldEnergy) const
            {
              ::coder::array<double, 3U> b;
              ::coder::array<double, 3U> denom;
              ::coder::array<double, 3U> num;
              ::coder::array<double, 3U> r3;
              ::coder::array<double, 3U> r5;
              ::coder::array<double, 2U> e_denom;
              ::coder::array<double, 2U> f_num;
              ::coder::array<double, 2U> validNewRowIdx;
              ::coder::array<double, 1U> b_y;
              ::coder::array<double, 1U> e_x;
              ::coder::array<double, 1U> f_denom;
              ::coder::array<double, 1U> g_denom;
              ::coder::array<double, 1U> g_num;
              ::coder::array<double, 1U> h_num;
              ::coder::array<int, 2U> r2;
              ::coder::array<int, 2U> r4;
              ::coder::array<int, 2U> r6;
              ::coder::array<int, 2U> r7;
              ::coder::array<int, 2U> r8;
              ::coder::array<bool, 2U> b_this;
              ::coder::array<bool, 2U> b_x;
              ::coder::array<bool, 2U> r;
              ::coder::array<bool, 2U> r1;
              float newEnergy;
              int ab_loop_ub;
              int b_idx;
              int b_idx_tmp;
              int b_loop_ub;
              int c_idx;
              int c_idx_tmp;
              int c_loop_ub;
              int d_idx;
              int d_loop_ub;
              int e_idx;
              int e_loop_ub;
              int f_idx;
              int f_loop_ub;
              int g_loop_ub;
              int i12;
              int i16;
              int i17;
              int i20;
              int i24;
              int i25;
              int i7;
              int idx_tmp;
              int j_loop_ub;
              int k;
              int loop_ub;
              int o_loop_ub;
              int r_loop_ub;
              int s_loop_ub;
              int u_loop_ub;
              int x_loop_ub;
              bool exitg1;
              bool y;
              idx_tmp = static_cast<int>(idx[0]);
              b_idx = idx_tmp;
              b_idx_tmp = static_cast<int>(idx[1]);
              c_idx = b_idx_tmp;
              loop_ub = BoardIdx.size(1);
              r.set_size(1, loop_ub);
              b_loop_ub = loop_ub;
              if ((static_cast<int>(loop_ub < 4)) != 0) {
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  r[b_i] = ((BoardIdx[(idx_tmp + (BoardIdx.size(0) * b_i)) - 1] >
                             0.0) && (BoardIdx[(b_idx_tmp + (BoardIdx.size(0) *
                    b_i)) - 1] > 0.0));
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i = 0; b_i < b_loop_ub; b_i++) {
                  r[b_i] = ((BoardIdx[(b_idx + (BoardIdx.size(0) * b_i)) - 1] >
                             0.0) && (BoardIdx[(c_idx + (BoardIdx.size(0) * b_i))
                                      - 1] > 0.0));
                }
              }

              c_idx_tmp = static_cast<int>(idx[2]);
              d_idx = c_idx_tmp;
              c_loop_ub = BoardIdx.size(1);
              r1.set_size(1, c_loop_ub);
              d_loop_ub = c_loop_ub;
              if ((static_cast<int>(c_loop_ub < 4)) != 0) {
                for (int i1{0}; i1 < c_loop_ub; i1++) {
                  r1[i1] = (BoardIdx[(c_idx_tmp + (BoardIdx.size(0) * i1)) - 1] >
                            0.0);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i1 = 0; i1 < d_loop_ub; i1++) {
                  r1[i1] = (BoardIdx[(d_idx + (BoardIdx.size(0) * i1)) - 1] >
                            0.0);
                }
              }

              newEnergy = 0.0F;
              b_x.set_size(1, r.size(1));
              e_loop_ub = r.size(1);
              if ((static_cast<int>(r.size(1) < 4)) != 0) {
                for (int i2{0}; i2 < e_loop_ub; i2++) {
                  b_x[i2] = ((r[i2]) && (r1[i2]));
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i2 = 0; i2 < e_loop_ub; i2++) {
                  b_x[i2] = ((r[i2]) && (r1[i2]));
                }
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
                int e_partialTrueCount;
                int e_trueCount;
                int end;
                int g_idx;
                int h_idx;
                int h_loop_ub;
                int j_idx;
                int m_idx;
                int m_loop_ub;
                int o_idx;
                int p_loop_ub;
                int partialTrueCount;
                int q_loop_ub;
                int t_loop_ub;
                int trueCount;
                int v_loop_ub;
                int w_loop_ub;
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

                int i4;
                g_idx = static_cast<int>(idx[0]);
                i4 = BoardCoords.size(2);
                r3.set_size(1, r2.size(1), i4);
                h_loop_ub = i4;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i7,j_loop_ub)

                for (int i6 = 0; i6 < h_loop_ub; i6++) {
                  j_loop_ub = r2.size(1);
                  for (i7 = 0; i7 < j_loop_ub; i7++) {
                    r3[i7 + (r3.size(1) * i6)] = BoardCoords[((g_idx +
                      (BoardCoords.size(0) * (r2[i7] - 1))) + ((BoardCoords.size
                      (0) * BoardCoords.size(1)) * i6)) - 1];
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

                int i9;
                h_idx = static_cast<int>(idx[2]);
                i9 = BoardCoords.size(2);
                r5.set_size(1, r4.size(1), i9);
                m_loop_ub = i9;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i12,o_loop_ub)

                for (int i11 = 0; i11 < m_loop_ub; i11++) {
                  o_loop_ub = r4.size(1);
                  for (i12 = 0; i12 < o_loop_ub; i12++) {
                    r5[i12 + (r5.size(1) * i11)] = BoardCoords[((h_idx +
                      (BoardCoords.size(0) * (r4[i12] - 1))) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * i11)) - 1];
                  }
                }

                c_end = r.size(1) - 1;
                c_trueCount = 0;
                for (int k_i{0}; k_i <= c_end; k_i++) {
                  if ((r[k_i]) && (r1[k_i])) {
                    c_trueCount++;
                  }
                }

                r6.set_size(1, c_trueCount);
                c_partialTrueCount = 0;
                for (int m_i{0}; m_i <= c_end; m_i++) {
                  if ((r[m_i]) && (r1[m_i])) {
                    r6[c_partialTrueCount] = m_i + 1;
                    c_partialTrueCount++;
                  }
                }

                int i13;
                j_idx = static_cast<int>(idx[1]);
                i13 = BoardCoords.size(2);
                b.set_size(1, r6.size(1), i13);
                p_loop_ub = i13;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i16,r_loop_ub)

                for (int i14 = 0; i14 < p_loop_ub; i14++) {
                  r_loop_ub = r6.size(1);
                  for (i16 = 0; i16 < r_loop_ub; i16++) {
                    b[i16 + (b.size(1) * i14)] = BoardCoords[((j_idx +
                      (BoardCoords.size(0) * (r6[i16] - 1))) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * i14)) - 1];
                  }
                }

                r3.set_size(1, r3.size(1), r3.size(2));
                q_loop_ub = r3.size(2);

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i17,s_loop_ub)

                for (int i15 = 0; i15 < q_loop_ub; i15++) {
                  s_loop_ub = r3.size(1);
                  for (i17 = 0; i17 < s_loop_ub; i17++) {
                    r3[i17 + (r3.size(1) * i15)] = (r3[i17 + (r3.size(1) * i15)]
                      + r5[i17 + (r5.size(1) * i15)]) - (2.0 * b[i17 + (b.size(1)
                      * i15)]);
                  }
                }

                squeeze(r3, f_num);
                d_end = r.size(1) - 1;
                d_trueCount = 0;
                for (int q_i{0}; q_i <= d_end; q_i++) {
                  if ((r[q_i]) && (r1[q_i])) {
                    d_trueCount++;
                  }
                }

                r7.set_size(1, d_trueCount);
                d_partialTrueCount = 0;
                for (int t_i{0}; t_i <= d_end; t_i++) {
                  if ((r[t_i]) && (r1[t_i])) {
                    r7[d_partialTrueCount] = t_i + 1;
                    d_partialTrueCount++;
                  }
                }

                int i18;
                m_idx = static_cast<int>(idx[0]);
                i18 = BoardCoords.size(2);
                r3.set_size(1, r7.size(1), i18);
                t_loop_ub = i18;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i20,u_loop_ub)

                for (int i19 = 0; i19 < t_loop_ub; i19++) {
                  u_loop_ub = r7.size(1);
                  for (i20 = 0; i20 < u_loop_ub; i20++) {
                    r3[i20 + (r3.size(1) * i19)] = BoardCoords[((m_idx +
                      (BoardCoords.size(0) * (r7[i20] - 1))) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * i19)) - 1];
                  }
                }

                e_end = r.size(1) - 1;
                e_trueCount = 0;
                for (int w_i{0}; w_i <= e_end; w_i++) {
                  if ((r[w_i]) && (r1[w_i])) {
                    e_trueCount++;
                  }
                }

                r8.set_size(1, e_trueCount);
                e_partialTrueCount = 0;
                for (int gb_i{0}; gb_i <= e_end; gb_i++) {
                  if ((r[gb_i]) && (r1[gb_i])) {
                    r8[e_partialTrueCount] = gb_i + 1;
                    e_partialTrueCount++;
                  }
                }

                int i21;
                o_idx = static_cast<int>(idx[2]);
                i21 = BoardCoords.size(2);
                r5.set_size(1, r8.size(1), i21);
                v_loop_ub = i21;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i24,x_loop_ub)

                for (int i22 = 0; i22 < v_loop_ub; i22++) {
                  x_loop_ub = r8.size(1);
                  for (i24 = 0; i24 < x_loop_ub; i24++) {
                    r5[i24 + (r5.size(1) * i22)] = BoardCoords[((o_idx +
                      (BoardCoords.size(0) * (r8[i24] - 1))) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * i22)) - 1];
                  }
                }

                r3.set_size(1, r3.size(1), r3.size(2));
                w_loop_ub = r3.size(2);

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i25,ab_loop_ub)

                for (int i23 = 0; i23 < w_loop_ub; i23++) {
                  ab_loop_ub = r3.size(1);
                  for (i25 = 0; i25 < ab_loop_ub; i25++) {
                    r3[i25 + (r3.size(1) * i23)] = r3[i25 + (r3.size(1) * i23)]
                      - r5[i25 + (r5.size(1) * i23)];
                  }
                }

                squeeze(r3, e_denom);
                if (f_num.size(1) > 1) {
                  int bb_loop_ub;
                  int cb_loop_ub;
                  int db_loop_ub;
                  int eb_loop_ub;
                  int fb_loop_ub;
                  int gb_loop_ub;
                  int hb_loop_ub;
                  int ib_loop_ub;
                  int y_loop_ub;
                  y_loop_ub = f_num.size(0);
                  g_num.set_size(f_num.size(0));
                  bb_loop_ub = f_num.size(0);
                  if ((static_cast<int>(f_num.size(0) < 4)) != 0) {
                    for (int i26{0}; i26 < y_loop_ub; i26++) {
                      g_num[i26] = f_num[i26];
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i26 = 0; i26 < bb_loop_ub; i26++) {
                      g_num[i26] = f_num[i26];
                    }
                  }

                  cb_loop_ub = f_num.size(0);
                  h_num.set_size(f_num.size(0));
                  db_loop_ub = f_num.size(0);
                  if ((static_cast<int>(f_num.size(0) < 4)) != 0) {
                    for (int i27{0}; i27 < cb_loop_ub; i27++) {
                      h_num[i27] = f_num[i27 + f_num.size(0)];
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i27 = 0; i27 < db_loop_ub; i27++) {
                      h_num[i27] = f_num[i27 + f_num.size(0)];
                    }
                  }

                  c_hypot(g_num, h_num, e_x);
                  eb_loop_ub = e_denom.size(0);
                  f_denom.set_size(e_denom.size(0));
                  fb_loop_ub = e_denom.size(0);
                  if ((static_cast<int>(e_denom.size(0) < 4)) != 0) {
                    for (int i28{0}; i28 < eb_loop_ub; i28++) {
                      f_denom[i28] = e_denom[i28];
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i28 = 0; i28 < fb_loop_ub; i28++) {
                      f_denom[i28] = e_denom[i28];
                    }
                  }

                  gb_loop_ub = e_denom.size(0);
                  g_denom.set_size(e_denom.size(0));
                  hb_loop_ub = e_denom.size(0);
                  if ((static_cast<int>(e_denom.size(0) < 4)) != 0) {
                    for (int i29{0}; i29 < gb_loop_ub; i29++) {
                      g_denom[i29] = e_denom[i29 + e_denom.size(0)];
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i29 = 0; i29 < hb_loop_ub; i29++) {
                      g_denom[i29] = e_denom[i29 + e_denom.size(0)];
                    }
                  }

                  c_hypot(f_denom, g_denom, b_y);
                  ib_loop_ub = e_x.size(0);
                  if ((static_cast<int>(e_x.size(0) < 4)) != 0) {
                    for (int i30{0}; i30 < ib_loop_ub; i30++) {
                      e_x[i30] = e_x[i30] / b_y[i30];
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i30 = 0; i30 < ib_loop_ub; i30++) {
                      e_x[i30] = e_x[i30] / b_y[i30];
                    }
                  }

                  newEnergy = std::fmax(oldEnergy, static_cast<float>(::ITER::
                    coder::internal::b_maximum(e_x)));
                } else {
                  newEnergy = std::fmax(oldEnergy, static_cast<float>(
                    static_cast<double>(rt_hypotd_snf(f_num[0], f_num[1]) /
                                        rt_hypotd_snf(e_denom[0], e_denom[1]))));
                }
              }

              e_idx = static_cast<int>(idx[0]);
              f_idx = e_idx;
              f_loop_ub = BoardIdx.size(1);
              b_this.set_size(1, f_loop_ub);
              g_loop_ub = f_loop_ub;
              if ((static_cast<int>(f_loop_ub < 4)) != 0) {
                for (int i3{0}; i3 < f_loop_ub; i3++) {
                  b_this[i3] = (BoardIdx[(e_idx + (BoardIdx.size(0) * i3)) - 1] >
                                0.0);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i3 = 0; i3 < g_loop_ub; i3++) {
                  b_this[i3] = (BoardIdx[(f_idx + (BoardIdx.size(0) * i3)) - 1] >
                                0.0);
                }
              }

              b_Checkerboard::arrayFind(b_this, validNewRowIdx);
              if (validNewRowIdx.size(1) != 0) {
                int i5;
                i5 = validNewRowIdx.size(1);
                for (int e_i{0}; e_i < i5; e_i++) {
                  double b_d1;
                  double d;
                  double d2;
                  double d3;
                  int i_loop_ub;
                  int k_loop_ub;
                  d = idx[0];
                  b_d1 = validNewRowIdx[e_i];
                  i_loop_ub = BoardCoords.size(2);
                  num.set_size(1, 1, i_loop_ub);
                  for (int b_i8{0}; b_i8 < i_loop_ub; b_i8++) {
                    num[b_i8] = (BoardCoords[(((static_cast<int>(d)) +
                      (BoardCoords.size(0) * ((static_cast<int>(b_d1)) - 1))) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i8)) - 1]
                                 + BoardCoords[(((static_cast<int>(d)) +
                      (BoardCoords.size(0) * ((static_cast<int>(static_cast<
                      double>(b_d1 + 2.0))) - 1))) + ((BoardCoords.size(0) *
                      BoardCoords.size(1)) * b_i8)) - 1]) - (2.0 * BoardCoords
                      [(((static_cast<int>(d)) + (BoardCoords.size(0) * ((
                      static_cast<int>(static_cast<double>(b_d1 + 1.0))) - 1)))
                        + ((BoardCoords.size(0) * BoardCoords.size(1)) * b_i8))
                      - 1]);
                  }

                  d2 = idx[0];
                  d3 = validNewRowIdx[e_i];
                  k_loop_ub = BoardCoords.size(2);
                  denom.set_size(1, 1, k_loop_ub);
                  for (int i10{0}; i10 < k_loop_ub; i10++) {
                    denom[i10] = BoardCoords[(((static_cast<int>(d2)) +
                      (BoardCoords.size(0) * ((static_cast<int>(d3)) - 1))) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * i10)) - 1]
                      - BoardCoords[(((static_cast<int>(d2)) + (BoardCoords.size
                      (0) * ((static_cast<int>(static_cast<double>(d3 + 2.0))) -
                             1))) + ((BoardCoords.size(0) * BoardCoords.size(1))
                                     * i10)) - 1];
                  }

                  if (newEnergy != 0.0F) {
                    ::coder::array<double, 1U> d_denom;
                    ::coder::array<double, 1U> d_num;
                    int b_denom;
                    int b_num;
                    b_num = num.size(2);
                    b_denom = denom.size(2);
                    d_num = num.reshape(b_num);
                    d_denom = denom.reshape(b_denom);
                    newEnergy = std::fmax(newEnergy, static_cast<float>(
                      static_cast<double>(b_norm(d_num) / b_norm(d_denom))));
                  } else {
                    ::coder::array<double, 1U> c_denom;
                    ::coder::array<double, 1U> c_num;
                    int b_denom;
                    int b_num;
                    b_num = num.size(2);
                    b_denom = denom.size(2);
                    c_num = num.reshape(b_num);
                    c_denom = denom.reshape(b_denom);
                    newEnergy = std::fmax(oldEnergy, static_cast<float>(
                      static_cast<double>(b_norm(c_num) / b_norm(c_denom))));
                  }
                }
              }

              if (newEnergy != 0.0F) {
                newEnergy = (newEnergy * (static_cast<float>(static_cast<int>
                  (BoardIdx.size(0) * BoardIdx.size(1))))) - (static_cast<float>
                  (static_cast<int>(BoardIdx.size(0) * BoardIdx.size(1))));
              } else {
                newEnergy = rtInfF;
              }

              return newEnergy;
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &idx
            //                ::coder::array<double, 2U> &newIndices
            // Return Type  : void
            //
            void b_Checkerboard::d_fitPolynomialIndices(const ::coder::array<
              double, 2U> &idx, ::coder::array<double, 2U> &newIndices) const
            {
              ::coder::array<double, 2U> b_index;
              ::coder::array<double, 2U> b_this;
              ::coder::array<double, 2U> c_this;
              ::coder::array<double, 2U> currCurve;
              ::coder::array<double, 2U> removedIdx;
              ::coder::array<double, 2U> validIdx;
              ::coder::array<int, 2U> c_ii;
              double b_dv[2];
              double coordsToUse[2];
              double currPt[2];
              double b_y;
              double coordDist;
              double firstValidIdx;
              double moveDistMultiplier;
              double y;
              int h_n;
              int i1;
              int i2;
              int loop_ub;
              int unnamed_idx_1;
              b_findIndependentVar(idx, coordsToUse);
              unnamed_idx_1 = BoardCoords.size(0);
              newIndices.set_size(1, unnamed_idx_1);
              loop_ub = unnamed_idx_1;
              if ((static_cast<int>(unnamed_idx_1 < 4)) != 0) {
                for (int b_i{0}; b_i < unnamed_idx_1; b_i++) {
                  newIndices[b_i] = 0.0;
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i = 0; b_i < loop_ub; b_i++) {
                  newIndices[b_i] = 0.0;
                }
              }

              removedIdx.set_size(1, 0);
              i1 = BoardCoords.size(0);
              for (int j{0}; j < i1; j++) {
                int b_loop_ub;
                int c_loop_ub;
                b_loop_ub = BoardCoords.size(1);
                b_this.set_size(1, b_loop_ub);
                for (int i3{0}; i3 < b_loop_ub; i3++) {
                  b_this[i3] = BoardCoords[(j + (BoardCoords.size(0) * i3)) +
                    ((BoardCoords.size(0) * BoardCoords.size(1)) * ((
                       static_cast<int>(coordsToUse[0])) - 1))];
                }

                c_eml_find(b_this, c_ii);
                validIdx.set_size(1, c_ii.size(1));
                c_loop_ub = c_ii.size(1);
                for (int i4{0}; i4 < c_loop_ub; i4++) {
                  validIdx[i4] = static_cast<double>(c_ii[i4]);
                }

                if (validIdx.size(1) >= 2) {
                  double currCoord;
                  double currRad;
                  double refCoordValue;
                  int d_loop_ub;
                  int e_loop_ub;
                  int i5;
                  int p_n;
                  int q_n;
                  bool exitg1;
                  findSearchParams(idx, validIdx, (static_cast<double>(j)) + 1.0,
                                   coordsToUse, &coordDist, &moveDistMultiplier,
                                   &firstValidIdx);
                  p_n = 0;
                  i5 = validIdx.size(1);
                  for (int b_k{0}; b_k < i5; b_k++) {
                    if ((static_cast<int>(validIdx[b_k])) != 0) {
                      p_n++;
                    }
                  }

                  b_this.set_size(1, validIdx.size(1));
                  d_loop_ub = validIdx.size(1);
                  for (int i6{0}; i6 < d_loop_ub; i6++) {
                    b_this[i6] = BoardCoords[(j + (BoardCoords.size(0) * ((
                      static_cast<int>(validIdx[i6])) - 1))) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * ((
                         static_cast<int>(coordsToUse[0])) - 1))];
                  }

                  c_this.set_size(1, validIdx.size(1));
                  e_loop_ub = validIdx.size(1);
                  for (int i7{0}; i7 < e_loop_ub; i7++) {
                    c_this[i7] = BoardCoords[(j + (BoardCoords.size(0) * ((
                      static_cast<int>(validIdx[i7])) - 1))) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * ((
                         static_cast<int>(coordsToUse[1])) - 1))];
                  }

                  if (p_n > 5) {
                    q_n = 4;
                  } else {
                    q_n = 2;
                  }

                  b_polyfit(b_this, c_this, static_cast<double>(q_n), currCurve);
                  currRad = coordDist / 4.0;
                  refCoordValue = BoardCoords[(j + (BoardCoords.size(0) * ((
                    static_cast<int>(firstValidIdx)) - 1))) + ((BoardCoords.size
                    (0) * BoardCoords.size(1)) * ((static_cast<int>(coordsToUse
                    [0])) - 1))];
                  currCoord = currRad + refCoordValue;
                  exitg1 = false;
                  while ((!exitg1) && (std::abs(currCoord - refCoordValue) <
                                       ((moveDistMultiplier * 1.5) * std::abs
                                        (coordDist)))) {
                    b_dv[0] = 1.0;
                    b_dv[1] = 2.0;
                    if (isequal(coordsToUse, b_dv)) {
                      if (currCurve.size(1) != 0) {
                        int i9;
                        b_y = currCurve[0];
                        i9 = currCurve.size(1);
                        for (int d_k{0}; d_k <= (i9 - 2); d_k++) {
                          b_y = (currCoord * b_y) + currCurve[d_k + 1];
                        }
                      }

                      currPt[0] = currCoord;
                      currPt[1] = b_y;
                    } else {
                      if (currCurve.size(1) != 0) {
                        int b_i8;
                        y = currCurve[0];
                        b_i8 = currCurve.size(1);
                        for (int c_k{0}; c_k <= (b_i8 - 2); c_k++) {
                          y = (currCoord * y) + currCurve[c_k + 1];
                        }
                      }

                      currPt[0] = y;
                      currPt[1] = currCoord;
                    }

                    findClosestOnCurve(currPt, std::abs(currRad), currCurve,
                                       coordsToUse, removedIdx, b_index);
                    if (b_index.size(1) != 0) {
                      int f_loop_ub;
                      int i10;
                      newIndices[j] = b_index[0];
                      i10 = removedIdx.size(1);
                      f_loop_ub = b_index.size(1);
                      removedIdx.set_size(removedIdx.size(0), removedIdx.size(1)
                                          + b_index.size(1));
                      for (int i11{0}; i11 < f_loop_ub; i11++) {
                        removedIdx[i10 + i11] = b_index[i11];
                      }

                      exitg1 = true;
                    } else {
                      currCoord += currRad;
                    }
                  }
                }
              }

              h_n = 0;
              i2 = newIndices.size(1);
              for (int k{0}; k < i2; k++) {
                if (newIndices[k] != 0.0) {
                  h_n++;
                }
              }

              if (h_n < 4) {
                int end;
                end = newIndices.size(1);
                if ((static_cast<int>(newIndices.size(1) < 4)) != 0) {
                  for (int c_i{0}; c_i < end; c_i++) {
                    if (newIndices[c_i] > 0.0) {
                      newIndices[c_i] = 0.0;
                    }
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int c_i = 0; c_i < end; c_i++) {
                    if (newIndices[c_i] > 0.0) {
                      newIndices[c_i] = 0.0;
                    }
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
            void b_Checkerboard::expandBoardDown(const ::coder::array<double, 2U>
              &indices, ::coder::array<double, 2U> &newBoard, ::coder::array<
              double, 3U> &newBoardCoords) const
            {
              ::coder::array<double, 2U> r2;
              ::coder::array<int, 2U> r1;
              ::coder::array<int, 2U> r3;
              ::coder::array<int, 1U> r;
              int e_this[3];
              int b_this[2];
              int b_end;
              int b_loop_ub;
              int b_partialTrueCount;
              int b_trueCount;
              int c_loop_ub;
              int c_this;
              int d_loop_ub;
              int e_loop_ub;
              int end;
              int f_loop_ub;
              int f_this;
              int g_loop_ub;
              int h_loop_ub;
              int i1;
              int i11;
              int i15;
              int i16;
              int i4;
              int i6;
              int i7;
              int i_loop_ub;
              int j_loop_ub;
              int k_loop_ub;
              int loop_ub;
              int m_loop_ub;
              int o_loop_ub;
              int p_loop_ub;
              int partialTrueCount;
              int q_loop_ub;
              int r_loop_ub;
              int trueCount;
              int unnamed_idx_1;
              b_this[0] = BoardIdx.size(0) + 1;
              b_this[1] = BoardIdx.size(1);
              newBoard.set_size(b_this[0], b_this[1]);
              loop_ub = b_this[1];

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i1,c_loop_ub)

              for (int b_i = 0; b_i < loop_ub; b_i++) {
                c_loop_ub = b_this[0];
                for (i1 = 0; i1 < c_loop_ub; i1++) {
                  newBoard[i1 + (newBoard.size(0) * b_i)] = 0.0;
                }
              }

              c_this = BoardIdx.size(0);
              b_loop_ub = indices.size(1);
              if ((static_cast<int>(indices.size(1) < 4)) != 0) {
                for (int i2{0}; i2 < b_loop_ub; i2++) {
                  newBoard[c_this + (newBoard.size(0) * i2)] = indices[i2];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i2 = 0; i2 < b_loop_ub; i2++) {
                  newBoard[c_this + (newBoard.size(0) * i2)] = indices[i2];
                }
              }

              d_loop_ub = BoardIdx.size(1);

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i4,e_loop_ub)

              for (int i3 = 0; i3 < d_loop_ub; i3++) {
                e_loop_ub = BoardIdx.size(0);
                for (i4 = 0; i4 < e_loop_ub; i4++) {
                  newBoard[i4 + (newBoard.size(0) * i3)] = BoardIdx[i4 +
                    (BoardIdx.size(0) * i3)];
                }
              }

              e_this[0] = BoardCoords.size(0) + 1;
              e_this[1] = BoardCoords.size(1);
              e_this[2] = BoardCoords.size(2);
              newBoardCoords.set_size(e_this[0], e_this[1], e_this[2]);
              f_loop_ub = e_this[2];

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i6,i_loop_ub,i7,j_loop_ub)

              for (int i5 = 0; i5 < f_loop_ub; i5++) {
                j_loop_ub = e_this[1];
                for (i7 = 0; i7 < j_loop_ub; i7++) {
                  i_loop_ub = e_this[0];
                  for (i6 = 0; i6 < i_loop_ub; i6++) {
                    newBoardCoords[(i6 + (newBoardCoords.size(0) * i7)) +
                      ((newBoardCoords.size(0) * newBoardCoords.size(1)) * i5)] =
                      0.0;
                  }
                }
              }

              g_loop_ub = BoardCoords.size(2);
              r.set_size(g_loop_ub);
              h_loop_ub = g_loop_ub;
              if ((static_cast<int>(g_loop_ub < 4)) != 0) {
                for (int b_i8{0}; b_i8 < g_loop_ub; b_i8++) {
                  r[b_i8] = b_i8;
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i8 = 0; b_i8 < h_loop_ub; b_i8++) {
                  r[b_i8] = b_i8;
                }
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

              int i9;
              i9 = Points.size(1);
              r2.set_size(r1.size(1), i9);
              k_loop_ub = i9;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i11,m_loop_ub)

              for (int i10 = 0; i10 < k_loop_ub; i10++) {
                m_loop_ub = r1.size(1);
                for (i11 = 0; i11 < m_loop_ub; i11++) {
                  r2[i11 + (r2.size(0) * i10)] = static_cast<double>(Points[((
                    static_cast<int>(indices[r1[i11] - 1])) + (Points.size(0) *
                    i10)) - 1]);
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
              f_this = BoardCoords.size(0);
              o_loop_ub = r.size(0);
              for (int i12{0}; i12 < o_loop_ub; i12++) {
                for (int i13{0}; i13 < unnamed_idx_1; i13++) {
                  newBoardCoords[(f_this + (newBoardCoords.size(0) * (r3[i13] -
                    1))) + ((newBoardCoords.size(0) * newBoardCoords.size(1)) *
                            r[i12])] = r2[i13 + (unnamed_idx_1 * i12)];
                }
              }

              p_loop_ub = BoardCoords.size(2);

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i15,q_loop_ub,i16,r_loop_ub)

              for (int i14 = 0; i14 < p_loop_ub; i14++) {
                r_loop_ub = BoardCoords.size(1);
                for (i16 = 0; i16 < r_loop_ub; i16++) {
                  q_loop_ub = BoardCoords.size(0);
                  for (i15 = 0; i15 < q_loop_ub; i15++) {
                    newBoardCoords[(i15 + (newBoardCoords.size(0) * i16)) +
                      ((newBoardCoords.size(0) * newBoardCoords.size(1)) * i14)]
                      = BoardCoords[(i15 + (BoardCoords.size(0) * i16)) +
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
            void b_Checkerboard::expandBoardLeft(const ::coder::array<double, 2U>
              &indices, ::coder::array<double, 2U> &newBoard, ::coder::array<
              double, 3U> &newBoardCoords) const
            {
              ::coder::array<double, 2U> r2;
              ::coder::array<int, 2U> r1;
              ::coder::array<int, 2U> r3;
              ::coder::array<int, 1U> r;
              int c_this[3];
              int b_this[2];
              int b_end;
              int b_i8;
              int b_loop_ub;
              int b_partialTrueCount;
              int b_trueCount;
              int c_loop_ub;
              int d_loop_ub;
              int e_loop_ub;
              int end;
              int f_loop_ub;
              int g_loop_ub;
              int h_loop_ub;
              int i1;
              int i13;
              int i15;
              int i18;
              int i19;
              int i4;
              int i6;
              int i9;
              int i_loop_ub;
              int j_loop_ub;
              int k_loop_ub;
              int loop_ub;
              int m_loop_ub;
              int o_loop_ub;
              int p_loop_ub;
              int partialTrueCount;
              int q_loop_ub;
              int r_loop_ub;
              int s_loop_ub;
              int t_loop_ub;
              int trueCount;
              int unnamed_idx_0;
              b_this[0] = BoardIdx.size(0);
              b_this[1] = BoardIdx.size(1) + 1;
              newBoard.set_size(b_this[0], b_this[1]);
              loop_ub = b_this[1];

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i1,d_loop_ub)

              for (int b_i = 0; b_i < loop_ub; b_i++) {
                d_loop_ub = b_this[0];
                for (i1 = 0; i1 < d_loop_ub; i1++) {
                  newBoard[i1 + (newBoard.size(0) * b_i)] = 0.0;
                }
              }

              b_loop_ub = BoardIdx.size(0);
              r.set_size(b_loop_ub);
              c_loop_ub = b_loop_ub;
              if ((static_cast<int>(b_loop_ub < 4)) != 0) {
                for (int i2{0}; i2 < b_loop_ub; i2++) {
                  r[i2] = i2;
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i2 = 0; i2 < c_loop_ub; i2++) {
                  r[i2] = i2;
                }
              }

              e_loop_ub = r.size(0);
              for (int i3{0}; i3 < e_loop_ub; i3++) {
                newBoard[r[i3]] = indices[i3];
              }

              i4 = static_cast<int>(2 <= newBoard.size(1));
              f_loop_ub = BoardIdx.size(1);

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i6,h_loop_ub)

              for (int i5 = 0; i5 < f_loop_ub; i5++) {
                h_loop_ub = BoardIdx.size(0);
                for (i6 = 0; i6 < h_loop_ub; i6++) {
                  newBoard[i6 + (newBoard.size(0) * (i4 + i5))] = BoardIdx[i6 +
                    (BoardIdx.size(0) * i5)];
                }
              }

              c_this[0] = BoardCoords.size(0);
              c_this[1] = BoardCoords.size(1) + 1;
              c_this[2] = BoardCoords.size(2);
              newBoardCoords.set_size(c_this[0], c_this[1], c_this[2]);
              g_loop_ub = c_this[2];

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(b_i8,k_loop_ub,i9,m_loop_ub)

              for (int i7 = 0; i7 < g_loop_ub; i7++) {
                m_loop_ub = c_this[1];
                for (i9 = 0; i9 < m_loop_ub; i9++) {
                  k_loop_ub = c_this[0];
                  for (b_i8 = 0; b_i8 < k_loop_ub; b_i8++) {
                    newBoardCoords[(b_i8 + (newBoardCoords.size(0) * i9)) +
                      ((newBoardCoords.size(0) * newBoardCoords.size(1)) * i7)] =
                      0.0;
                  }
                }
              }

              i_loop_ub = BoardCoords.size(2);
              r.set_size(i_loop_ub);
              j_loop_ub = i_loop_ub;
              if ((static_cast<int>(i_loop_ub < 4)) != 0) {
                for (int i10{0}; i10 < i_loop_ub; i10++) {
                  r[i10] = i10;
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i10 = 0; i10 < j_loop_ub; i10++) {
                  r[i10] = i10;
                }
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

              int i11;
              i11 = Points.size(1);
              r2.set_size(r1.size(1), i11);
              o_loop_ub = i11;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i13,p_loop_ub)

              for (int i12 = 0; i12 < o_loop_ub; i12++) {
                p_loop_ub = r1.size(1);
                for (i13 = 0; i13 < p_loop_ub; i13++) {
                  r2[i13 + (r2.size(0) * i12)] = static_cast<double>(Points[((
                    static_cast<int>(indices[r1[i13] - 1])) + (Points.size(0) *
                    i12)) - 1]);
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
              q_loop_ub = r.size(0);
              for (int i14{0}; i14 < q_loop_ub; i14++) {
                for (int i16{0}; i16 < unnamed_idx_0; i16++) {
                  newBoardCoords[(r3[i16] + ((newBoardCoords.size(0) *
                    newBoardCoords.size(1)) * r[i14])) - 1] = r2[i16 +
                    (unnamed_idx_0 * i14)];
                }
              }

              i15 = static_cast<int>(2 <= newBoardCoords.size(1));
              r_loop_ub = BoardCoords.size(2);

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i18,s_loop_ub,i19,t_loop_ub)

              for (int i17 = 0; i17 < r_loop_ub; i17++) {
                t_loop_ub = BoardCoords.size(1);
                for (i19 = 0; i19 < t_loop_ub; i19++) {
                  s_loop_ub = BoardCoords.size(0);
                  for (i18 = 0; i18 < s_loop_ub; i18++) {
                    newBoardCoords[(i18 + (newBoardCoords.size(0) * (i15 + i19)))
                      + ((newBoardCoords.size(0) * newBoardCoords.size(1)) * i17)]
                      = BoardCoords[(i18 + (BoardCoords.size(0) * i19)) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * i17)];
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
            void b_Checkerboard::expandBoardRight(const ::coder::array<double,
              2U> &indices, ::coder::array<double, 2U> &newBoard, ::coder::array<
              double, 3U> &newBoardCoords) const
            {
              ::coder::array<double, 2U> r2;
              ::coder::array<int, 2U> r1;
              ::coder::array<int, 2U> r3;
              ::coder::array<int, 1U> r;
              int e_this[3];
              int b_this[2];
              int b_end;
              int b_i8;
              int b_loop_ub;
              int b_partialTrueCount;
              int b_trueCount;
              int c_loop_ub;
              int c_this;
              int d_loop_ub;
              int e_loop_ub;
              int end;
              int f_loop_ub;
              int f_this;
              int g_loop_ub;
              int h_loop_ub;
              int i1;
              int i12;
              int i16;
              int i17;
              int i5;
              int i7;
              int i_loop_ub;
              int j_loop_ub;
              int k_loop_ub;
              int loop_ub;
              int m_loop_ub;
              int o_loop_ub;
              int p_loop_ub;
              int partialTrueCount;
              int q_loop_ub;
              int r_loop_ub;
              int s_loop_ub;
              int t_loop_ub;
              int trueCount;
              int unnamed_idx_0;
              b_this[0] = BoardIdx.size(0);
              b_this[1] = BoardIdx.size(1) + 1;
              newBoard.set_size(b_this[0], b_this[1]);
              loop_ub = b_this[1];

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i1,d_loop_ub)

              for (int b_i = 0; b_i < loop_ub; b_i++) {
                d_loop_ub = b_this[0];
                for (i1 = 0; i1 < d_loop_ub; i1++) {
                  newBoard[i1 + (newBoard.size(0) * b_i)] = 0.0;
                }
              }

              b_loop_ub = BoardIdx.size(0);
              r.set_size(b_loop_ub);
              c_loop_ub = b_loop_ub;
              if ((static_cast<int>(b_loop_ub < 4)) != 0) {
                for (int i2{0}; i2 < b_loop_ub; i2++) {
                  r[i2] = i2;
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i2 = 0; i2 < c_loop_ub; i2++) {
                  r[i2] = i2;
                }
              }

              c_this = BoardIdx.size(1);
              e_loop_ub = r.size(0);
              for (int i3{0}; i3 < e_loop_ub; i3++) {
                newBoard[r[i3] + (newBoard.size(0) * c_this)] = indices[i3];
              }

              f_loop_ub = BoardIdx.size(1);

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i5,g_loop_ub)

              for (int i4 = 0; i4 < f_loop_ub; i4++) {
                g_loop_ub = BoardIdx.size(0);
                for (i5 = 0; i5 < g_loop_ub; i5++) {
                  newBoard[i5 + (newBoard.size(0) * i4)] = BoardIdx[i5 +
                    (BoardIdx.size(0) * i4)];
                }
              }

              e_this[0] = BoardCoords.size(0);
              e_this[1] = BoardCoords.size(1) + 1;
              e_this[2] = BoardCoords.size(2);
              newBoardCoords.set_size(e_this[0], e_this[1], e_this[2]);
              h_loop_ub = e_this[2];

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i7,k_loop_ub,b_i8,m_loop_ub)

              for (int i6 = 0; i6 < h_loop_ub; i6++) {
                m_loop_ub = e_this[1];
                for (b_i8 = 0; b_i8 < m_loop_ub; b_i8++) {
                  k_loop_ub = e_this[0];
                  for (i7 = 0; i7 < k_loop_ub; i7++) {
                    newBoardCoords[(i7 + (newBoardCoords.size(0) * b_i8)) +
                      ((newBoardCoords.size(0) * newBoardCoords.size(1)) * i6)] =
                      0.0;
                  }
                }
              }

              i_loop_ub = BoardCoords.size(2);
              r.set_size(i_loop_ub);
              j_loop_ub = i_loop_ub;
              if ((static_cast<int>(i_loop_ub < 4)) != 0) {
                for (int i9{0}; i9 < i_loop_ub; i9++) {
                  r[i9] = i9;
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i9 = 0; i9 < j_loop_ub; i9++) {
                  r[i9] = i9;
                }
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

              int i10;
              i10 = Points.size(1);
              r2.set_size(r1.size(1), i10);
              o_loop_ub = i10;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i12,p_loop_ub)

              for (int i11 = 0; i11 < o_loop_ub; i11++) {
                p_loop_ub = r1.size(1);
                for (i12 = 0; i12 < p_loop_ub; i12++) {
                  r2[i12 + (r2.size(0) * i11)] = static_cast<double>(Points[((
                    static_cast<int>(indices[r1[i12] - 1])) + (Points.size(0) *
                    i11)) - 1]);
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
              f_this = BoardCoords.size(1);
              q_loop_ub = r.size(0);
              for (int i13{0}; i13 < q_loop_ub; i13++) {
                for (int i14{0}; i14 < unnamed_idx_0; i14++) {
                  newBoardCoords[((r3[i14] + (newBoardCoords.size(0) * f_this))
                                  + ((newBoardCoords.size(0) *
                                      newBoardCoords.size(1)) * r[i13])) - 1] =
                    r2[i14 + (unnamed_idx_0 * i13)];
                }
              }

              r_loop_ub = BoardCoords.size(2);

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i16,s_loop_ub,i17,t_loop_ub)

              for (int i15 = 0; i15 < r_loop_ub; i15++) {
                t_loop_ub = BoardCoords.size(1);
                for (i17 = 0; i17 < t_loop_ub; i17++) {
                  s_loop_ub = BoardCoords.size(0);
                  for (i16 = 0; i16 < s_loop_ub; i16++) {
                    newBoardCoords[(i16 + (newBoardCoords.size(0) * i17)) +
                      ((newBoardCoords.size(0) * newBoardCoords.size(1)) * i15)]
                      = BoardCoords[(i16 + (BoardCoords.size(0) * i17)) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * i15)];
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
            void b_Checkerboard::expandBoardUp(const ::coder::array<double, 2U>
              &indices, ::coder::array<double, 2U> &newBoard, ::coder::array<
              double, 3U> &newBoardCoords) const
            {
              ::coder::array<double, 2U> r2;
              ::coder::array<int, 2U> r1;
              ::coder::array<int, 2U> r3;
              ::coder::array<int, 1U> r;
              int c_this[3];
              int b_this[2];
              int b_end;
              int b_i8;
              int b_loop_ub;
              int b_partialTrueCount;
              int b_trueCount;
              int c_loop_ub;
              int d_loop_ub;
              int e_loop_ub;
              int end;
              int f_loop_ub;
              int g_loop_ub;
              int h_loop_ub;
              int i1;
              int i12;
              int i14;
              int i17;
              int i18;
              int i3;
              int i5;
              int i7;
              int i_loop_ub;
              int j_loop_ub;
              int k_loop_ub;
              int loop_ub;
              int m_loop_ub;
              int o_loop_ub;
              int p_loop_ub;
              int partialTrueCount;
              int q_loop_ub;
              int r_loop_ub;
              int trueCount;
              int unnamed_idx_1;
              b_this[0] = BoardIdx.size(0) + 1;
              b_this[1] = BoardIdx.size(1);
              newBoard.set_size(b_this[0], b_this[1]);
              loop_ub = b_this[1];

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i1,c_loop_ub)

              for (int b_i = 0; b_i < loop_ub; b_i++) {
                c_loop_ub = b_this[0];
                for (i1 = 0; i1 < c_loop_ub; i1++) {
                  newBoard[i1 + (newBoard.size(0) * b_i)] = 0.0;
                }
              }

              b_loop_ub = indices.size(1);
              if ((static_cast<int>(indices.size(1) < 4)) != 0) {
                for (int i2{0}; i2 < b_loop_ub; i2++) {
                  newBoard[newBoard.size(0) * i2] = indices[i2];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i2 = 0; i2 < b_loop_ub; i2++) {
                  newBoard[newBoard.size(0) * i2] = indices[i2];
                }
              }

              i3 = static_cast<int>(2 <= newBoard.size(0));
              d_loop_ub = BoardIdx.size(1);

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i5,f_loop_ub)

              for (int i4 = 0; i4 < d_loop_ub; i4++) {
                f_loop_ub = BoardIdx.size(0);
                for (i5 = 0; i5 < f_loop_ub; i5++) {
                  newBoard[(i3 + i5) + (newBoard.size(0) * i4)] = BoardIdx[i5 +
                    (BoardIdx.size(0) * i4)];
                }
              }

              c_this[0] = BoardCoords.size(0) + 1;
              c_this[1] = BoardCoords.size(1);
              c_this[2] = BoardCoords.size(2);
              newBoardCoords.set_size(c_this[0], c_this[1], c_this[2]);
              e_loop_ub = c_this[2];

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i7,i_loop_ub,b_i8,j_loop_ub)

              for (int i6 = 0; i6 < e_loop_ub; i6++) {
                j_loop_ub = c_this[1];
                for (b_i8 = 0; b_i8 < j_loop_ub; b_i8++) {
                  i_loop_ub = c_this[0];
                  for (i7 = 0; i7 < i_loop_ub; i7++) {
                    newBoardCoords[(i7 + (newBoardCoords.size(0) * b_i8)) +
                      ((newBoardCoords.size(0) * newBoardCoords.size(1)) * i6)] =
                      0.0;
                  }
                }
              }

              g_loop_ub = BoardCoords.size(2);
              r.set_size(g_loop_ub);
              h_loop_ub = g_loop_ub;
              if ((static_cast<int>(g_loop_ub < 4)) != 0) {
                for (int i9{0}; i9 < g_loop_ub; i9++) {
                  r[i9] = i9;
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i9 = 0; i9 < h_loop_ub; i9++) {
                  r[i9] = i9;
                }
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

              int i10;
              i10 = Points.size(1);
              r2.set_size(r1.size(1), i10);
              k_loop_ub = i10;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i12,m_loop_ub)

              for (int i11 = 0; i11 < k_loop_ub; i11++) {
                m_loop_ub = r1.size(1);
                for (i12 = 0; i12 < m_loop_ub; i12++) {
                  r2[i12 + (r2.size(0) * i11)] = static_cast<double>(Points[((
                    static_cast<int>(indices[r1[i12] - 1])) + (Points.size(0) *
                    i11)) - 1]);
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
              o_loop_ub = r.size(0);
              for (int i13{0}; i13 < o_loop_ub; i13++) {
                for (int i15{0}; i15 < unnamed_idx_1; i15++) {
                  newBoardCoords[(newBoardCoords.size(0) * (r3[i15] - 1)) +
                    ((newBoardCoords.size(0) * newBoardCoords.size(1)) * r[i13])]
                    = r2[i15 + (unnamed_idx_1 * i13)];
                }
              }

              i14 = static_cast<int>(2 <= newBoardCoords.size(0));
              p_loop_ub = BoardCoords.size(2);

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i17,q_loop_ub,i18,r_loop_ub)

              for (int i16 = 0; i16 < p_loop_ub; i16++) {
                r_loop_ub = BoardCoords.size(1);
                for (i18 = 0; i18 < r_loop_ub; i18++) {
                  q_loop_ub = BoardCoords.size(0);
                  for (i17 = 0; i17 < q_loop_ub; i17++) {
                    newBoardCoords[((i14 + i17) + (newBoardCoords.size(0) * i18))
                      + ((newBoardCoords.size(0) * newBoardCoords.size(1)) * i16)]
                      = BoardCoords[(i17 + (BoardCoords.size(0) * i18)) +
                      ((BoardCoords.size(0) * BoardCoords.size(1)) * i16)];
                  }
                }
              }
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &predictedPoints
            //                ::coder::array<double, 2U> &indices
            // Return Type  : void
            //
            void b_Checkerboard::findClosestIndices(const ::coder::array<double,
              2U> &predictedPoints, ::coder::array<double, 2U> &indices) const
            {
              ::coder::array<double, 2U> b_indices;
              ::coder::array<double, 2U> b_predictedPoints;
              ::coder::array<double, 2U> remIdx;
              ::coder::array<double, 2U> y;
              ::coder::array<double, 1U> c_this;
              ::coder::array<float, 2U> diffs;
              ::coder::array<float, 2U> e_this;
              ::coder::array<float, 1U> b_diffs;
              ::coder::array<float, 1U> c_diffs;
              ::coder::array<float, 1U> dists;
              ::coder::array<int, 2U> r1;
              ::coder::array<int, 1U> c_ib;
              ::coder::array<int, 1U> c_ii;
              ::coder::array<int, 1U> ia;
              ::coder::array<bool, 2U> distIdx;
              ::coder::array<bool, 1U> r;
              float b_ex;
              int b;
              int b_this;
              int iindx;
              int loop_ub;
              indices.set_size(1, predictedPoints.size(0));
              loop_ub = predictedPoints.size(0);
              if ((static_cast<int>(predictedPoints.size(0) < 4)) != 0) {
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  indices[b_i] = 0.0;
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i = 0; b_i < loop_ub; b_i++) {
                  indices[b_i] = 0.0;
                }
              }

              b = Points.size(0);
              if (b < 1) {
                y.set_size(1, 0);
              } else {
                int b_loop_ub;
                y.set_size(1, b);
                b_loop_ub = b - 1;
                if ((static_cast<int>(b < 4)) != 0) {
                  for (int i1{0}; i1 <= b_loop_ub; i1++) {
                    y[i1] = (static_cast<double>(i1)) + 1.0;
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int i1 = 0; i1 <= b_loop_ub; i1++) {
                    y[i1] = (static_cast<double>(i1)) + 1.0;
                  }
                }
              }

              b_this = BoardIdx.size(0) * BoardIdx.size(1);
              c_this = BoardIdx.reshape(b_this);
              do_vectors(y, c_this, remIdx, ia, c_ib);
              if (remIdx.size(1) != 0) {
                int c_loop_ub;
                int d_loop_ub;
                int e_loop_ub;
                int i4;
                c_loop_ub = predictedPoints.size(0);
                r.set_size(predictedPoints.size(0));
                d_loop_ub = predictedPoints.size(0);
                if ((static_cast<int>(predictedPoints.size(0) < 4)) != 0) {
                  for (int i2{0}; i2 < c_loop_ub; i2++) {
                    r[i2] = std::isnan(predictedPoints[i2]);
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int i2 = 0; i2 < d_loop_ub; i2++) {
                    r[i2] = std::isnan(predictedPoints[i2]);
                  }
                }

                e_loop_ub = r.size(0);
                if ((static_cast<int>(r.size(0) < 4)) != 0) {
                  for (int i3{0}; i3 < e_loop_ub; i3++) {
                    r[i3] = !r[i3];
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int i3 = 0; i3 < e_loop_ub; i3++) {
                    r[i3] = !r[i3];
                  }
                }

                b_eml_find(r, c_ii);
                i4 = c_ii.size(0);
                for (int c_i{0}; c_i < i4; c_i++) {
                  int b_end;
                  int end;
                  int f_loop_ub;
                  int g_loop_ub;
                  int i_loop_ub;
                  int j_loop_ub;
                  int partialTrueCount;
                  int trueCount;
                  f_loop_ub = Points.size(1);
                  e_this.set_size(remIdx.size(1), f_loop_ub);
                  for (int i5{0}; i5 < f_loop_ub; i5++) {
                    int h_loop_ub;
                    h_loop_ub = remIdx.size(1);
                    for (int i6{0}; i6 < h_loop_ub; i6++) {
                      e_this[i6 + (e_this.size(0) * i5)] = Points[((static_cast<
                        int>(remIdx[i6])) + (Points.size(0) * i5)) - 1];
                    }
                  }

                  g_loop_ub = predictedPoints.size(1);
                  b_predictedPoints.set_size(1, predictedPoints.size(1));
                  for (int i7{0}; i7 < g_loop_ub; i7++) {
                    b_predictedPoints[i7] = predictedPoints[(c_ii[c_i] +
                      (predictedPoints.size(0) * i7)) - 1];
                  }

                  bsxfun(e_this, b_predictedPoints, diffs);
                  i_loop_ub = diffs.size(0);
                  b_diffs.set_size(diffs.size(0));
                  c_diffs.set_size(diffs.size(0));
                  for (int b_i8{0}; b_i8 < i_loop_ub; b_i8++) {
                    b_diffs[b_i8] = diffs[b_i8];
                    c_diffs[b_i8] = diffs[b_i8 + diffs.size(0)];
                  }

                  b_hypot(b_diffs, c_diffs, dists);
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
                  for (int i9{0}; i9 < j_loop_ub; i9++) {
                    b_indices[i9] = indices[r1[i9] - 1];
                  }

                  local_ismember(remIdx, b_indices, distIdx);
                  b_end = distIdx.size(1);
                  for (int g_i{0}; g_i < b_end; g_i++) {
                    if (distIdx[g_i]) {
                      dists[g_i] = rtInfF;
                    }
                  }

                  ::ITER::coder::internal::minimum(dists, &b_ex, &iindx);
                  indices[c_ii[c_i] - 1] = remIdx[iindx - 1];
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
            void b_Checkerboard::findClosestOnCurve(const double predictedPoint
              [2], double radius, const ::coder::array<double, 2U> &curve, const
              double coordsToUse[2], const ::coder::array<double, 2U>
              &removedIdx, ::coder::array<double, 2U> &idx) const
            {
              ::coder::array<double, 2U> b_remIdx;
              ::coder::array<double, 2U> dataPts;
              ::coder::array<double, 2U> firstCoord;
              ::coder::array<double, 2U> remIdx;
              ::coder::array<double, 2U> y;
              ::coder::array<double, 1U> c_this;
              ::coder::array<double, 1U> dist;
              ::coder::array<float, 2U> b_a;
              ::coder::array<float, 2U> currPt;
              ::coder::array<float, 2U> d_a;
              ::coder::array<float, 2U> diffs;
              ::coder::array<float, 2U> queryPts;
              ::coder::array<float, 2U> z1;
              ::coder::array<float, 1U> b_diffs;
              ::coder::array<float, 1U> b_y;
              ::coder::array<float, 1U> c_diffs;
              ::coder::array<float, 1U> dists;
              ::coder::array<int, 1U> c_ib;
              ::coder::array<unsigned int, 1U> c_idx;
              ::coder::array<int, 1U> c_ii;
              ::coder::array<int, 1U> ia;
              ::coder::array<int, 1U> r;
              ::coder::array<bool, 1U> b_x;
              ::coder::array<bool, 1U> s;
              double b_dv[2];
              double b_ex;
              int outsize[2];
              int ab_loop_ub;
              int b;
              int b_k;
              int b_loop_ub;
              int b_t;
              int b_this;
              int c_loop_ub;
              int d_loop_ub;
              int e_loop_ub;
              int f_loop_ub;
              int g_loop_ub;
              int h_k;
              int h_loop_ub;
              int h_n;
              int i27;
              int i29;
              int i30;
              int i31;
              int i32;
              int i33;
              int i36;
              int i4;
              int i6;
              int i9;
              int i_N;
              int i_k;
              int i_loop_ub;
              int iindx;
              int j_k;
              int k_k;
              int o_k;
              int varargin_2;
              int y_loop_ub;
              b = Points.size(0);
              if (b < 1) {
                y.set_size(1, 0);
              } else {
                int loop_ub;
                y.set_size(1, b);
                loop_ub = b - 1;
                if ((static_cast<int>(b < 4)) != 0) {
                  for (int b_i{0}; b_i <= loop_ub; b_i++) {
                    y[b_i] = (static_cast<double>(b_i)) + 1.0;
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int b_i = 0; b_i <= loop_ub; b_i++) {
                    y[b_i] = (static_cast<double>(b_i)) + 1.0;
                  }
                }
              }

              b_this = BoardIdx.size(0) * BoardIdx.size(1);
              c_this = BoardIdx.reshape(b_this);
              do_vectors(y, c_this, remIdx, ia, c_ib);
              b_remIdx.set_size(1, remIdx.size(1));
              b_loop_ub = remIdx.size(1) - 1;
              for (int i1{0}; i1 <= b_loop_ub; i1++) {
                b_remIdx[i1] = remIdx[i1];
              }

              int i2;
              b_do_vectors(b_remIdx, removedIdx, remIdx, ia, c_ib);
              i2 = Points.size(1);
              b_a.set_size(remIdx.size(1), i2);
              c_loop_ub = i2;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i4,e_loop_ub)

              for (int i3 = 0; i3 < c_loop_ub; i3++) {
                e_loop_ub = remIdx.size(1);
                for (i4 = 0; i4 < e_loop_ub; i4++) {
                  b_a[i4 + (b_a.size(0) * i3)] = Points[((static_cast<int>
                    (remIdx[i4])) + (Points.size(0) * i3)) - 1];
                }
              }

              diffs.set_size(b_a.size(0), 2);
              if (b_a.size(0) != 0) {
                int acoef;
                int b_acoef;
                acoef = static_cast<int>(b_a.size(1) != 1);
                b_acoef = static_cast<int>(b_a.size(0) != 1);

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(b_k,i6,varargin_2)

                for (int k = 0; k < 2; k++) {
                  varargin_2 = acoef * k;
                  i6 = diffs.size(0) - 1;
                  for (b_k = 0; b_k <= i6; b_k++) {
                    diffs[b_k + (diffs.size(0) * k)] = b_a[(b_acoef * b_k) +
                      (b_a.size(0) * varargin_2)] - (static_cast<float>
                      (predictedPoint[k]));
                  }
                }
              }

              d_loop_ub = diffs.size(0);
              b_diffs.set_size(diffs.size(0));
              f_loop_ub = diffs.size(0);
              if ((static_cast<int>(diffs.size(0) < 4)) != 0) {
                for (int i5{0}; i5 < d_loop_ub; i5++) {
                  b_diffs[i5] = diffs[i5];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i5 = 0; i5 < f_loop_ub; i5++) {
                  b_diffs[i5] = diffs[i5];
                }
              }

              g_loop_ub = diffs.size(0);
              c_diffs.set_size(diffs.size(0));
              h_loop_ub = diffs.size(0);
              if ((static_cast<int>(diffs.size(0) < 4)) != 0) {
                for (int i7{0}; i7 < g_loop_ub; i7++) {
                  c_diffs[i7] = diffs[i7 + diffs.size(0)];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i7 = 0; i7 < h_loop_ub; i7++) {
                  c_diffs[i7] = diffs[i7 + diffs.size(0)];
                }
              }

              b_hypot(b_diffs, c_diffs, dists);
              s.set_size(dists.size(0));
              i_loop_ub = dists.size(0);
              if ((static_cast<int>(dists.size(0) < 4)) != 0) {
                for (int b_i8{0}; b_i8 < i_loop_ub; b_i8++) {
                  s[b_i8] = ((static_cast<double>(dists[b_i8])) < radius);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i8 = 0; b_i8 < i_loop_ub; b_i8++) {
                  s[b_i8] = ((static_cast<double>(dists[b_i8])) < radius);
                }
              }

              h_n = 0;
              i9 = s.size(0);
              for (int c_k{0}; c_k < i9; c_k++) {
                if (s[c_k]) {
                  h_n++;
                }
              }

              if (h_n > 1) {
                double a_tmp;
                double b_b;
                double c_a;
                int b_end;
                int b_idx;
                int b_partialTrueCount;
                int b_trueCount;
                int b_u1;
                int bb_loop_ub;
                int cb_loop_ub;
                int e_ii;
                int i26;
                int m_k;
                int numDataPts;
                int x_loop_ub;
                bool exitg1;
                bool guard1{ false };

                bool guard2{ false };

                bool guard3{ false };

                a_tmp = predictedPoint[(static_cast<int>(coordsToUse[0])) - 1];
                c_a = a_tmp - radius;
                b_b = a_tmp + radius;
                guard1 = false;
                guard2 = false;
                guard3 = false;
                if (std::isnan(c_a)) {
                  guard2 = true;
                } else if (std::isnan(b_b)) {
                  guard2 = true;
                } else if (b_b < c_a) {
                  firstCoord.set_size(1, 0);
                } else if (std::isinf(c_a)) {
                  guard3 = true;
                } else if (std::isinf(b_b)) {
                  guard3 = true;
                } else {
                  guard1 = true;
                }

                if (guard3) {
                  if (c_a == b_b) {
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
                    int k_loop_ub;
                    int m_loop_ub;
                    k_loop_ub = static_cast<int>(std::floor(b_b - c_a));
                    firstCoord.set_size(1, k_loop_ub + 1);
                    m_loop_ub = k_loop_ub;
                    if ((static_cast<int>((k_loop_ub + 1) < 4)) != 0) {
                      for (int i12{0}; i12 <= k_loop_ub; i12++) {
                        firstCoord[i12] = c_a + (static_cast<double>(i12));
                      }
                    } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                      for (int i12 = 0; i12 <= m_loop_ub; i12++) {
                        firstCoord[i12] = c_a + (static_cast<double>(i12));
                      }
                    }
                  } else {
                    eml_float_colon(c_a, b_b, firstCoord);
                  }
                }

                b_dv[0] = 1.0;
                b_dv[1] = 2.0;
                if (isequal(coordsToUse, b_dv)) {
                  int q_loop_ub;
                  int u_loop_ub;
                  y.set_size(1, firstCoord.size(1));
                  if (firstCoord.size(1) != 0) {
                    if (curve.size(1) != 0) {
                      int i19;
                      int s_loop_ub;
                      int y_idx_1;
                      y_idx_1 = firstCoord.size(1);
                      y.set_size(1, firstCoord.size(1));
                      s_loop_ub = firstCoord.size(1);
                      if ((static_cast<int>(firstCoord.size(1) < 4)) != 0) {
                        for (int i17{0}; i17 < y_idx_1; i17++) {
                          y[i17] = curve[0];
                        }
                      } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                        for (int i17 = 0; i17 < s_loop_ub; i17++) {
                          y[i17] = curve[0];
                        }
                      }

                      i19 = curve.size(1);
                      for (int g_k{0}; g_k <= (i19 - 2); g_k++) {
                        double c_curve;
                        int w_loop_ub;
                        c_curve = curve[g_k + 1];
                        w_loop_ub = firstCoord.size(1);
                        y.set_size(1, firstCoord.size(1));
                        for (int i23{0}; i23 < w_loop_ub; i23++) {
                          y[i23] = (firstCoord[i23] * y[i23]) + c_curve;
                        }
                      }
                    }
                  }

                  dataPts.set_size(firstCoord.size(1), 2);
                  q_loop_ub = firstCoord.size(1);
                  if ((static_cast<int>(firstCoord.size(1) < 4)) != 0) {
                    for (int i15{0}; i15 < q_loop_ub; i15++) {
                      dataPts[i15] = firstCoord[i15];
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i15 = 0; i15 < q_loop_ub; i15++) {
                      dataPts[i15] = firstCoord[i15];
                    }
                  }

                  u_loop_ub = y.size(1);
                  if ((static_cast<int>(y.size(1) < 4)) != 0) {
                    for (int i21{0}; i21 < u_loop_ub; i21++) {
                      dataPts[i21 + dataPts.size(0)] = y[i21];
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i21 = 0; i21 < u_loop_ub; i21++) {
                      dataPts[i21 + dataPts.size(0)] = y[i21];
                    }
                  }
                } else {
                  int p_loop_ub;
                  int t_loop_ub;
                  y.set_size(1, firstCoord.size(1));
                  if (firstCoord.size(1) != 0) {
                    if (curve.size(1) != 0) {
                      int i18;
                      int r_loop_ub;
                      int y_idx_1;
                      y_idx_1 = firstCoord.size(1);
                      y.set_size(1, firstCoord.size(1));
                      r_loop_ub = firstCoord.size(1);
                      if ((static_cast<int>(firstCoord.size(1) < 4)) != 0) {
                        for (int i16{0}; i16 < y_idx_1; i16++) {
                          y[i16] = curve[0];
                        }
                      } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                        for (int i16 = 0; i16 < r_loop_ub; i16++) {
                          y[i16] = curve[0];
                        }
                      }

                      i18 = curve.size(1);
                      for (int e_k{0}; e_k <= (i18 - 2); e_k++) {
                        double b_curve;
                        int v_loop_ub;
                        b_curve = curve[e_k + 1];
                        v_loop_ub = firstCoord.size(1);
                        y.set_size(1, firstCoord.size(1));
                        for (int i22{0}; i22 < v_loop_ub; i22++) {
                          y[i22] = (firstCoord[i22] * y[i22]) + b_curve;
                        }
                      }
                    }
                  }

                  dataPts.set_size(y.size(1), 2);
                  p_loop_ub = y.size(1);
                  if ((static_cast<int>(y.size(1) < 4)) != 0) {
                    for (int i14{0}; i14 < p_loop_ub; i14++) {
                      dataPts[i14] = y[i14];
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i14 = 0; i14 < p_loop_ub; i14++) {
                      dataPts[i14] = y[i14];
                    }
                  }

                  t_loop_ub = firstCoord.size(1);
                  if ((static_cast<int>(firstCoord.size(1) < 4)) != 0) {
                    for (int i20{0}; i20 < t_loop_ub; i20++) {
                      dataPts[i20 + dataPts.size(0)] = firstCoord[i20];
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i20 = 0; i20 < t_loop_ub; i20++) {
                      dataPts[i20 + dataPts.size(0)] = firstCoord[i20];
                    }
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

                int i24;
                i24 = Points.size(1);
                queryPts.set_size(r.size(0), i24);
                x_loop_ub = i24;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i27,y_loop_ub)

                for (int i25 = 0; i25 < x_loop_ub; i25++) {
                  y_loop_ub = r.size(0);
                  for (i27 = 0; i27 < y_loop_ub; i27++) {
                    queryPts[i27 + (queryPts.size(0) * i25)] = Points[((
                      static_cast<int>(remIdx[r[i27] - 1])) + (Points.size(0) *
                      i25)) - 1];
                  }
                }

                numDataPts = dataPts.size(0);
                dist.set_size(queryPts.size(0));
                i26 = queryPts.size(0);
                if (0 <= (queryPts.size(0) - 1)) {
                  outsize[0] = dataPts.size(0);
                  outsize[1] = queryPts.size(1);
                  ab_loop_ub = dataPts.size(0);
                }

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(currPt,d_a,z1,b_y,h_k,i_k,j_k,i_N,k_k,i29,i30,b_t,i31,o_k,i32,i33,i36)

                for (int h_i = 0; h_i < i26; h_i++) {
                  currPt.set_size(outsize[0], outsize[1]);
                  if ((outsize[0] != 0) && (outsize[1] != 0)) {
                    i36 = queryPts.size(1) - 1;
                    for (o_k = 0; o_k <= i36; o_k++) {
                      i31 = numDataPts - 1;
                      for (b_t = 0; b_t <= i31; b_t++) {
                        currPt[b_t + (currPt.size(0) * o_k)] = queryPts[h_i +
                          (queryPts.size(0) * o_k)];
                      }
                    }
                  }

                  d_a.set_size(dataPts.size(0), 2);
                  for (i30 = 0; i30 < 2; i30++) {
                    for (i29 = 0; i29 < ab_loop_ub; i29++) {
                      d_a[i29 + (d_a.size(0) * i30)] = (static_cast<float>
                        (dataPts[i29 + (dataPts.size(0) * i30)])) - currPt[i29 +
                        (currPt.size(0) * i30)];
                    }
                  }

                  z1.set_size(d_a.size(0), 2);
                  for (k_k = 0; k_k < 2; k_k++) {
                    i_N = z1.size(0);
                    for (j_k = 0; j_k < i_N; j_k++) {
                      z1[j_k + (z1.size(0) * k_k)] = rt_powf_snf(d_a[j_k +
                        (d_a.size(0) * k_k)], 2.0F);
                    }
                  }

                  if (z1.size(0) == 0) {
                    b_y.set_size(0);
                  } else {
                    b_y.set_size(z1.size(0));
                    i33 = z1.size(0);
                    for (i_k = 0; i_k < i33; i_k++) {
                      b_y[i_k] = z1[i_k];
                    }

                    i32 = z1.size(0);
                    for (h_k = 0; h_k < i32; h_k++) {
                      b_y[h_k] = b_y[h_k] + z1[h_k + z1.size(0)];
                    }
                  }

                  dist[h_i] = static_cast<double>(std::sqrt(::ITER::coder::
                    internal::b_minimum(b_y)));
                }

                ::ITER::coder::internal::c_minimum(dist, &b_ex, &iindx);
                b_x.set_size(dists.size(0));
                bb_loop_ub = dists.size(0);
                if ((static_cast<int>(dists.size(0) < 4)) != 0) {
                  for (int i28{0}; i28 < bb_loop_ub; i28++) {
                    b_x[i28] = ((static_cast<double>(dists[i28])) < radius);
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int i28 = 0; i28 < bb_loop_ub; i28++) {
                    b_x[i28] = ((static_cast<double>(dists[i28])) < radius);
                  }
                }

                b_u1 = b_x.size(0);
                if (iindx <= b_u1) {
                  m_k = iindx;
                } else {
                  m_k = b_u1;
                }

                b_idx = 0;
                c_ii.set_size(m_k);
                e_ii = 0;
                exitg1 = false;
                while ((!exitg1) && (e_ii <= (b_x.size(0) - 1))) {
                  if (b_x[e_ii]) {
                    b_idx++;
                    c_ii[b_idx - 1] = e_ii + 1;
                    if (b_idx >= m_k) {
                      exitg1 = true;
                    } else {
                      e_ii++;
                    }
                  } else {
                    e_ii++;
                  }
                }

                if (m_k == 1) {
                  if (b_idx == 0) {
                    c_ii.set_size(0);
                  }
                } else {
                  int i34;
                  if (1 > b_idx) {
                    i34 = 0;
                  } else {
                    i34 = b_idx;
                  }

                  c_ii.set_size(i34);
                }

                c_idx.set_size(c_ii.size(0));
                cb_loop_ub = c_ii.size(0);
                if ((static_cast<int>(c_ii.size(0) < 4)) != 0) {
                  for (int i35{0}; i35 < cb_loop_ub; i35++) {
                    c_idx[i35] = static_cast<unsigned int>(c_ii[i35]);
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int i35 = 0; i35 < cb_loop_ub; i35++) {
                    c_idx[i35] = static_cast<unsigned int>(c_ii[i35]);
                  }
                }

                idx.set_size(1, 1);
                idx[0] = remIdx[(static_cast<int>(c_idx[c_idx.size(0) - 1])) - 1];
              } else {
                int i11;
                int j_loop_ub;
                int p_n;
                s.set_size(dists.size(0));
                j_loop_ub = dists.size(0);
                if ((static_cast<int>(dists.size(0) < 4)) != 0) {
                  for (int i10{0}; i10 < j_loop_ub; i10++) {
                    s[i10] = ((static_cast<double>(dists[i10])) < radius);
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int i10 = 0; i10 < j_loop_ub; i10++) {
                    s[i10] = ((static_cast<double>(dists[i10])) < radius);
                  }
                }

                p_n = 0;
                i11 = s.size(0);
                for (int d_k{0}; d_k < i11; d_k++) {
                  if (s[d_k]) {
                    p_n++;
                  }
                }

                if (p_n == 1) {
                  int end;
                  int o_loop_ub;
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
                  o_loop_ub = r.size(0);
                  if ((static_cast<int>(r.size(0) < 4)) != 0) {
                    for (int i13{0}; i13 < o_loop_ub; i13++) {
                      idx[i13] = remIdx[r[i13] - 1];
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i13 = 0; i13 < o_loop_ub; i13++) {
                      idx[i13] = remIdx[r[i13] - 1];
                    }
                  }
                } else {
                  idx.set_size(1, 0);
                }
              }
            }

            //
            // Arguments    : double coordsToUse[2]
            // Return Type  : void
            //
            void b_Checkerboard::findIndependentVar(double coordsToUse[2]) const
            {
              ::coder::array<double, 2U> b_x;
              ::coder::array<double, 2U> e_x;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 2U> r5;
              ::coder::array<int, 2U> r2;
              ::coder::array<int, 2U> r4;
              ::coder::array<int, 2U> r6;
              ::coder::array<int, 2U> r7;
              ::coder::array<bool, 2U> r;
              ::coder::array<bool, 2U> r1;
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
              int i_loop_ub;
              int j_loop_ub;
              int loop_ub;
              int partialTrueCount;
              int trueCount;
              loop_ub = BoardIdx.size(1);
              r.set_size(1, loop_ub);
              b_loop_ub = loop_ub;
              if ((static_cast<int>(loop_ub < 4)) != 0) {
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  r[b_i] = (BoardIdx[BoardIdx.size(0) * b_i] > 0.0);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i = 0; b_i < b_loop_ub; b_i++) {
                  r[b_i] = (BoardIdx[BoardIdx.size(0) * b_i] > 0.0);
                }
              }

              c_loop_ub = BoardIdx.size(1);
              r1.set_size(1, c_loop_ub);
              d_loop_ub = c_loop_ub;
              if ((static_cast<int>(c_loop_ub < 4)) != 0) {
                for (int i1{0}; i1 < c_loop_ub; i1++) {
                  r1[i1] = (BoardIdx[(BoardIdx.size(0) * i1) + 1] > 0.0);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i1 = 0; i1 < d_loop_ub; i1++) {
                  r1[i1] = (BoardIdx[(BoardIdx.size(0) * i1) + 1] > 0.0);
                }
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
              e_loop_ub = r2.size(1);
              if ((static_cast<int>(r2.size(1) < 4)) != 0) {
                for (int i2{0}; i2 < e_loop_ub; i2++) {
                  r3[i2] = BoardCoords[(BoardCoords.size(0) * (r2[i2] - 1)) + 1];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i2 = 0; i2 < e_loop_ub; i2++) {
                  r3[i2] = BoardCoords[(BoardCoords.size(0) * (r2[i2] - 1)) + 1];
                }
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
              f_loop_ub = r4.size(1);
              if ((static_cast<int>(r4.size(1) < 4)) != 0) {
                for (int i3{0}; i3 < f_loop_ub; i3++) {
                  r5[i3] = BoardCoords[BoardCoords.size(0) * (r4[i3] - 1)];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i3 = 0; i3 < f_loop_ub; i3++) {
                  r5[i3] = BoardCoords[BoardCoords.size(0) * (r4[i3] - 1)];
                }
              }

              b_x.set_size(1, r3.size(1));
              g_loop_ub = r3.size(1);
              if ((static_cast<int>(r3.size(1) < 4)) != 0) {
                for (int i4{0}; i4 < g_loop_ub; i4++) {
                  b_x[i4] = r3[i4] - r5[i4];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i4 = 0; i4 < g_loop_ub; i4++) {
                  b_x[i4] = r3[i4] - r5[i4];
                }
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
              for (int k_i{0}; k_i <= c_end; k_i++) {
                if ((r[k_i]) && (r1[k_i])) {
                  r6[c_partialTrueCount] = k_i + 1;
                  c_partialTrueCount++;
                }
              }

              r3.set_size(1, r6.size(1));
              h_loop_ub = r6.size(1);
              if ((static_cast<int>(r6.size(1) < 4)) != 0) {
                for (int i5{0}; i5 < h_loop_ub; i5++) {
                  r3[i5] = BoardCoords[((BoardCoords.size(0) * (r6[i5] - 1)) +
                                        (BoardCoords.size(0) * BoardCoords.size
                    (1))) + 1];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i5 = 0; i5 < h_loop_ub; i5++) {
                  r3[i5] = BoardCoords[((BoardCoords.size(0) * (r6[i5] - 1)) +
                                        (BoardCoords.size(0) * BoardCoords.size
                    (1))) + 1];
                }
              }

              d_end = r.size(1) - 1;
              d_trueCount = 0;
              for (int m_i{0}; m_i <= d_end; m_i++) {
                if ((r[m_i]) && (r1[m_i])) {
                  d_trueCount++;
                }
              }

              r7.set_size(1, d_trueCount);
              d_partialTrueCount = 0;
              for (int q_i{0}; q_i <= d_end; q_i++) {
                if ((r[q_i]) && (r1[q_i])) {
                  r7[d_partialTrueCount] = q_i + 1;
                  d_partialTrueCount++;
                }
              }

              r5.set_size(1, r7.size(1));
              i_loop_ub = r7.size(1);
              if ((static_cast<int>(r7.size(1) < 4)) != 0) {
                for (int i6{0}; i6 < i_loop_ub; i6++) {
                  r5[i6] = BoardCoords[(BoardCoords.size(0) * (r7[i6] - 1)) +
                    (BoardCoords.size(0) * BoardCoords.size(1))];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i6 = 0; i6 < i_loop_ub; i6++) {
                  r5[i6] = BoardCoords[(BoardCoords.size(0) * (r7[i6] - 1)) +
                    (BoardCoords.size(0) * BoardCoords.size(1))];
                }
              }

              e_x.set_size(1, r3.size(1));
              j_loop_ub = r3.size(1);
              if ((static_cast<int>(r3.size(1) < 4)) != 0) {
                for (int i7{0}; i7 < j_loop_ub; i7++) {
                  e_x[i7] = r3[i7] - r5[i7];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i7 = 0; i7 < j_loop_ub; i7++) {
                  e_x[i7] = r3[i7] - r5[i7];
                }
              }

              if (std::abs(combineVectorElements(b_x) / (static_cast<double>
                    (b_x.size(1)))) > std::abs(combineVectorElements(e_x) / (
                    static_cast<double>(e_x.size(1))))) {
                coordsToUse[0] = 1.0;
                coordsToUse[1] = 2.0;
              } else {
                coordsToUse[0] = 2.0;
                coordsToUse[1] = 1.0;
              }
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &idx
            //                double coordsToUse[2]
            // Return Type  : void
            //
            void b_Checkerboard::findIndependentVar(const ::coder::array<double,
              2U> &idx, double coordsToUse[2]) const
            {
              ::coder::array<double, 2U> b_x;
              ::coder::array<double, 2U> e_x;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 2U> r5;
              ::coder::array<int, 2U> r2;
              ::coder::array<int, 2U> r4;
              ::coder::array<int, 2U> r6;
              ::coder::array<int, 2U> r7;
              ::coder::array<bool, 2U> r;
              ::coder::array<bool, 2U> r1;
              int b_end;
              int b_idx;
              int b_idx_tmp;
              int b_loop_ub;
              int b_partialTrueCount;
              int b_trueCount;
              int c_end;
              int c_idx;
              int c_loop_ub;
              int c_partialTrueCount;
              int c_trueCount;
              int d_end;
              int d_idx;
              int d_loop_ub;
              int d_partialTrueCount;
              int d_trueCount;
              int e_idx;
              int e_loop_ub;
              int end;
              int f_idx;
              int f_loop_ub;
              int g_idx;
              int g_loop_ub;
              int h_idx;
              int h_loop_ub;
              int i_loop_ub;
              int idx_tmp;
              int j_idx;
              int j_loop_ub;
              int loop_ub;
              int m_idx;
              int o_idx;
              int partialTrueCount;
              int trueCount;
              idx_tmp = static_cast<int>(idx[0]);
              b_idx = idx_tmp;
              loop_ub = BoardIdx.size(1);
              r.set_size(1, loop_ub);
              b_loop_ub = loop_ub;
              if ((static_cast<int>(loop_ub < 4)) != 0) {
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  r[b_i] = (BoardIdx[(idx_tmp + (BoardIdx.size(0) * b_i)) - 1] >
                            0.0);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i = 0; b_i < b_loop_ub; b_i++) {
                  r[b_i] = (BoardIdx[(b_idx + (BoardIdx.size(0) * b_i)) - 1] >
                            0.0);
                }
              }

              b_idx_tmp = static_cast<int>(idx[1]);
              c_idx = b_idx_tmp;
              c_loop_ub = BoardIdx.size(1);
              r1.set_size(1, c_loop_ub);
              d_loop_ub = c_loop_ub;
              if ((static_cast<int>(c_loop_ub < 4)) != 0) {
                for (int i1{0}; i1 < c_loop_ub; i1++) {
                  r1[i1] = (BoardIdx[(b_idx_tmp + (BoardIdx.size(0) * i1)) - 1] >
                            0.0);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i1 = 0; i1 < d_loop_ub; i1++) {
                  r1[i1] = (BoardIdx[(c_idx + (BoardIdx.size(0) * i1)) - 1] >
                            0.0);
                }
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

              d_idx = static_cast<int>(idx[1]);
              e_idx = d_idx;
              r3.set_size(1, r2.size(1));
              e_loop_ub = r2.size(1);
              if ((static_cast<int>(r2.size(1) < 4)) != 0) {
                for (int i2{0}; i2 < e_loop_ub; i2++) {
                  r3[i2] = BoardCoords[(d_idx + (BoardCoords.size(0) * (r2[i2] -
                    1))) - 1];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i2 = 0; i2 < e_loop_ub; i2++) {
                  r3[i2] = BoardCoords[(e_idx + (BoardCoords.size(0) * (r2[i2] -
                    1))) - 1];
                }
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

              f_idx = static_cast<int>(idx[0]);
              g_idx = f_idx;
              r5.set_size(1, r4.size(1));
              f_loop_ub = r4.size(1);
              if ((static_cast<int>(r4.size(1) < 4)) != 0) {
                for (int i3{0}; i3 < f_loop_ub; i3++) {
                  r5[i3] = BoardCoords[(f_idx + (BoardCoords.size(0) * (r4[i3] -
                    1))) - 1];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i3 = 0; i3 < f_loop_ub; i3++) {
                  r5[i3] = BoardCoords[(g_idx + (BoardCoords.size(0) * (r4[i3] -
                    1))) - 1];
                }
              }

              b_x.set_size(1, r3.size(1));
              g_loop_ub = r3.size(1);
              if ((static_cast<int>(r3.size(1) < 4)) != 0) {
                for (int i4{0}; i4 < g_loop_ub; i4++) {
                  b_x[i4] = r3[i4] - r5[i4];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i4 = 0; i4 < g_loop_ub; i4++) {
                  b_x[i4] = r3[i4] - r5[i4];
                }
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
              for (int k_i{0}; k_i <= c_end; k_i++) {
                if ((r[k_i]) && (r1[k_i])) {
                  r6[c_partialTrueCount] = k_i + 1;
                  c_partialTrueCount++;
                }
              }

              h_idx = static_cast<int>(idx[1]);
              j_idx = h_idx;
              r3.set_size(1, r6.size(1));
              h_loop_ub = r6.size(1);
              if ((static_cast<int>(r6.size(1) < 4)) != 0) {
                for (int i5{0}; i5 < h_loop_ub; i5++) {
                  r3[i5] = BoardCoords[((h_idx + (BoardCoords.size(0) * (r6[i5]
                    - 1))) + (BoardCoords.size(0) * BoardCoords.size(1))) - 1];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i5 = 0; i5 < h_loop_ub; i5++) {
                  r3[i5] = BoardCoords[((j_idx + (BoardCoords.size(0) * (r6[i5]
                    - 1))) + (BoardCoords.size(0) * BoardCoords.size(1))) - 1];
                }
              }

              d_end = r.size(1) - 1;
              d_trueCount = 0;
              for (int m_i{0}; m_i <= d_end; m_i++) {
                if ((r[m_i]) && (r1[m_i])) {
                  d_trueCount++;
                }
              }

              r7.set_size(1, d_trueCount);
              d_partialTrueCount = 0;
              for (int q_i{0}; q_i <= d_end; q_i++) {
                if ((r[q_i]) && (r1[q_i])) {
                  r7[d_partialTrueCount] = q_i + 1;
                  d_partialTrueCount++;
                }
              }

              m_idx = static_cast<int>(idx[0]);
              o_idx = m_idx;
              r5.set_size(1, r7.size(1));
              i_loop_ub = r7.size(1);
              if ((static_cast<int>(r7.size(1) < 4)) != 0) {
                for (int i6{0}; i6 < i_loop_ub; i6++) {
                  r5[i6] = BoardCoords[((m_idx + (BoardCoords.size(0) * (r7[i6]
                    - 1))) + (BoardCoords.size(0) * BoardCoords.size(1))) - 1];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i6 = 0; i6 < i_loop_ub; i6++) {
                  r5[i6] = BoardCoords[((o_idx + (BoardCoords.size(0) * (r7[i6]
                    - 1))) + (BoardCoords.size(0) * BoardCoords.size(1))) - 1];
                }
              }

              e_x.set_size(1, r3.size(1));
              j_loop_ub = r3.size(1);
              if ((static_cast<int>(r3.size(1) < 4)) != 0) {
                for (int i7{0}; i7 < j_loop_ub; i7++) {
                  e_x[i7] = r3[i7] - r5[i7];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i7 = 0; i7 < j_loop_ub; i7++) {
                  e_x[i7] = r3[i7] - r5[i7];
                }
              }

              if (std::abs(combineVectorElements(b_x) / (static_cast<double>
                    (b_x.size(1)))) > std::abs(combineVectorElements(e_x) / (
                    static_cast<double>(e_x.size(1))))) {
                coordsToUse[0] = 1.0;
                coordsToUse[1] = 2.0;
              } else {
                coordsToUse[0] = 2.0;
                coordsToUse[1] = 1.0;
              }
            }

            //
            // Arguments    : const ::coder::array<float, 2U> &pointVectors
            //                const ::coder::array<float, 1U> &euclideanDists
            //                const float e_v[2]
            // Return Type  : double
            //
            double b_Checkerboard::findNeighbor(const ::coder::array<float, 2U>
              &pointVectors, const ::coder::array<float, 1U> &euclideanDists,
              const float e_v[2]) const
            {
              ::coder::array<float, 1U> angleCosines;
              ::coder::array<float, 1U> dists;
              ::coder::array<float, 1U> y;
              ::coder::array<int, 1U> r1;
              ::coder::array<int, 1U> r2;
              ::coder::array<bool, 2U> r;
              double neighborIdx;
              float b;
              float b_x;
              int b_end;
              int b_loop_ub;
              int c_loop_ub;
              int d_loop_ub;
              int e_loop_ub;
              int end;
              int f_loop_ub;
              int i3;
              int iindx;
              int inner;
              int loop_ub;
              int mc;
              int partialTrueCount;
              int trueCount;
              mc = pointVectors.size(0) - 1;
              inner = pointVectors.size(1);
              y.set_size(pointVectors.size(0));
              if ((static_cast<int>(pointVectors.size(0) < 4)) != 0) {
                for (int b_i{0}; b_i <= mc; b_i++) {
                  y[b_i] = 0.0F;
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i = 0; b_i <= mc; b_i++) {
                  y[b_i] = 0.0F;
                }
              }

              for (int k{0}; k < inner; k++) {
                for (int c_i{0}; c_i <= mc; c_i++) {
                  y[c_i] = y[c_i] + (pointVectors[c_i + (pointVectors.size(0) *
                    k)] * e_v[k]);
                }
              }

              b = rt_hypotf_snf(e_v[0], e_v[1]);
              angleCosines.set_size(y.size(0));
              loop_ub = y.size(0);
              if ((static_cast<int>(y.size(0) < 4)) != 0) {
                for (int d_i{0}; d_i < loop_ub; d_i++) {
                  angleCosines[d_i] = y[d_i] / (euclideanDists[d_i] * b);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int d_i = 0; d_i < loop_ub; d_i++) {
                  angleCosines[d_i] = y[d_i] / (euclideanDists[d_i] * b);
                }
              }

              dists.set_size(euclideanDists.size(0));
              b_loop_ub = euclideanDists.size(0);
              if ((static_cast<int>(euclideanDists.size(0) < 4)) != 0) {
                for (int i1{0}; i1 < b_loop_ub; i1++) {
                  dists[i1] = euclideanDists[i1] + ((1.5F * euclideanDists[i1]) *
                    (1.0F - angleCosines[i1]));
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i1 = 0; i1 < b_loop_ub; i1++) {
                  dists[i1] = euclideanDists[i1] + ((1.5F * euclideanDists[i1]) *
                    (1.0F - angleCosines[i1]));
                }
              }

              r.set_size(BoardIdx.size(0), BoardIdx.size(1));
              c_loop_ub = BoardIdx.size(1);

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i3,d_loop_ub)

              for (int i2 = 0; i2 < c_loop_ub; i2++) {
                d_loop_ub = BoardIdx.size(0);
                for (i3 = 0; i3 < d_loop_ub; i3++) {
                  r[i3 + (r.size(0) * i2)] = (BoardIdx[i3 + (BoardIdx.size(0) *
                    i2)] > 0.0);
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
              if ((static_cast<int>(r1.size(0) < 4)) != 0) {
                for (int i4{0}; i4 < e_loop_ub; i4++) {
                  r2[i4] = static_cast<int>(BoardIdx[r1[i4] - 1]);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i4 = 0; i4 < e_loop_ub; i4++) {
                  r2[i4] = static_cast<int>(BoardIdx[r1[i4] - 1]);
                }
              }

              f_loop_ub = r2.size(0);
              for (int i5{0}; i5 < f_loop_ub; i5++) {
                dists[r2[i5] - 1] = rtInfF;
              }

              b_end = angleCosines.size(0);
              if ((static_cast<int>(angleCosines.size(0) < 4)) != 0) {
                for (int h_i{0}; h_i < b_end; h_i++) {
                  if (angleCosines[h_i] < 0.0F) {
                    dists[h_i] = rtInfF;
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int h_i = 0; h_i < b_end; h_i++) {
                  if (angleCosines[h_i] < 0.0F) {
                    dists[h_i] = rtInfF;
                  }
                }
              }

              ::ITER::coder::internal::minimum(dists, &b_x, &iindx);
              neighborIdx = static_cast<double>(iindx);
              if (std::isinf(b_x)) {
                neighborIdx = -1.0;
              }

              return neighborIdx;
            }

            //
            // Arguments    : const ::coder::array<float, 2U> &pointVectors
            //                const ::coder::array<float, 1U> &euclideanDists
            //                const ::coder::array<float, 2U> &e_v
            // Return Type  : double
            //
            double b_Checkerboard::findNeighbor(const ::coder::array<float, 2U>
              &pointVectors, const ::coder::array<float, 1U> &euclideanDists,
              const ::coder::array<float, 2U> &e_v) const
            {
              ::coder::array<float, 1U> angleCosines;
              ::coder::array<float, 1U> dists;
              ::coder::array<float, 1U> y;
              ::coder::array<int, 1U> r1;
              ::coder::array<int, 1U> r2;
              ::coder::array<bool, 2U> r;
              double neighborIdx;
              float b;
              float b_x;
              int b_end;
              int b_loop_ub;
              int c_loop_ub;
              int d_loop_ub;
              int e_loop_ub;
              int end;
              int f_loop_ub;
              int i3;
              int iindx;
              int inner;
              int loop_ub;
              int mc;
              int partialTrueCount;
              int trueCount;
              mc = pointVectors.size(0) - 1;
              inner = pointVectors.size(1);
              y.set_size(pointVectors.size(0));
              if ((static_cast<int>(pointVectors.size(0) < 4)) != 0) {
                for (int b_i{0}; b_i <= mc; b_i++) {
                  y[b_i] = 0.0F;
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i = 0; b_i <= mc; b_i++) {
                  y[b_i] = 0.0F;
                }
              }

              for (int k{0}; k < inner; k++) {
                float bkj;
                bkj = e_v[k];
                for (int c_i{0}; c_i <= mc; c_i++) {
                  y[c_i] = y[c_i] + (pointVectors[c_i + (pointVectors.size(0) *
                    k)] * bkj);
                }
              }

              b = rt_hypotf_snf(e_v[0], e_v[1]);
              angleCosines.set_size(y.size(0));
              loop_ub = y.size(0);
              if ((static_cast<int>(y.size(0) < 4)) != 0) {
                for (int d_i{0}; d_i < loop_ub; d_i++) {
                  angleCosines[d_i] = y[d_i] / (euclideanDists[d_i] * b);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int d_i = 0; d_i < loop_ub; d_i++) {
                  angleCosines[d_i] = y[d_i] / (euclideanDists[d_i] * b);
                }
              }

              dists.set_size(euclideanDists.size(0));
              b_loop_ub = euclideanDists.size(0);
              if ((static_cast<int>(euclideanDists.size(0) < 4)) != 0) {
                for (int i1{0}; i1 < b_loop_ub; i1++) {
                  dists[i1] = euclideanDists[i1] + ((1.5F * euclideanDists[i1]) *
                    (1.0F - angleCosines[i1]));
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i1 = 0; i1 < b_loop_ub; i1++) {
                  dists[i1] = euclideanDists[i1] + ((1.5F * euclideanDists[i1]) *
                    (1.0F - angleCosines[i1]));
                }
              }

              r.set_size(BoardIdx.size(0), BoardIdx.size(1));
              c_loop_ub = BoardIdx.size(1);

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i3,d_loop_ub)

              for (int i2 = 0; i2 < c_loop_ub; i2++) {
                d_loop_ub = BoardIdx.size(0);
                for (i3 = 0; i3 < d_loop_ub; i3++) {
                  r[i3 + (r.size(0) * i2)] = (BoardIdx[i3 + (BoardIdx.size(0) *
                    i2)] > 0.0);
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
              if ((static_cast<int>(r1.size(0) < 4)) != 0) {
                for (int i4{0}; i4 < e_loop_ub; i4++) {
                  r2[i4] = static_cast<int>(BoardIdx[r1[i4] - 1]);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i4 = 0; i4 < e_loop_ub; i4++) {
                  r2[i4] = static_cast<int>(BoardIdx[r1[i4] - 1]);
                }
              }

              f_loop_ub = r2.size(0);
              for (int i5{0}; i5 < f_loop_ub; i5++) {
                dists[r2[i5] - 1] = rtInfF;
              }

              b_end = angleCosines.size(0);
              if ((static_cast<int>(angleCosines.size(0) < 4)) != 0) {
                for (int h_i{0}; h_i < b_end; h_i++) {
                  if (angleCosines[h_i] < 0.0F) {
                    dists[h_i] = rtInfF;
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int h_i = 0; h_i < b_end; h_i++) {
                  if (angleCosines[h_i] < 0.0F) {
                    dists[h_i] = rtInfF;
                  }
                }
              }

              ::ITER::coder::internal::minimum(dists, &b_x, &iindx);
              neighborIdx = static_cast<double>(iindx);
              if (std::isinf(b_x)) {
                neighborIdx = -1.0;
              }

              return neighborIdx;
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &idx
            //                const ::coder::array<double, 2U> &validIdx
            //                double currIdx
            //                const double coordsToUse[2]
            //                double *coordDist
            //                double *moveMultiplier
            //                double *firstValidIdx
            // Return Type  : void
            //
            void b_Checkerboard::findSearchParams(const ::coder::array<double,
              2U> &idx, const ::coder::array<double, 2U> &validIdx, double
              currIdx, const double coordsToUse[2], double *coordDist, double
              *moveMultiplier, double *firstValidIdx) const
            {
              if (idx[0] == 1.0) {
                *moveMultiplier = validIdx[0];
                *firstValidIdx = validIdx[0];
                *coordDist = (BoardCoords[(((static_cast<int>(currIdx)) +
                  (BoardCoords.size(0) * ((static_cast<int>(validIdx[0])) - 1)))
                  + ((BoardCoords.size(0) * BoardCoords.size(1)) * ((
                  static_cast<int>(coordsToUse[0])) - 1))) - 1] - BoardCoords
                              [(((static_cast<int>(currIdx)) + (BoardCoords.size
                  (0) * ((static_cast<int>(validIdx[1])) - 1))) +
                                ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                 ((static_cast<int>(coordsToUse[0])) - 1))) - 1])
                  / (validIdx[1] - validIdx[0]);
              } else {
                *moveMultiplier = ((static_cast<double>(BoardCoords.size(1))) -
                                   validIdx[validIdx.size(1) - 1]) + 1.0;
                *firstValidIdx = validIdx[validIdx.size(1) - 1];
                *coordDist = (BoardCoords[(((static_cast<int>(currIdx)) +
                  (BoardCoords.size(0) * ((static_cast<int>
                  (validIdx[validIdx.size(1) - 1])) - 1))) + ((BoardCoords.size
                  (0) * BoardCoords.size(1)) * ((static_cast<int>(coordsToUse[0]))
                  - 1))) - 1] - BoardCoords[(((static_cast<int>(currIdx)) +
                  (BoardCoords.size(0) * ((static_cast<int>
                  (validIdx[validIdx.size(1) - 2])) - 1))) + ((BoardCoords.size
                  (0) * BoardCoords.size(1)) * ((static_cast<int>(coordsToUse[0]))
                  - 1))) - 1]) / (validIdx[validIdx.size(1) - 1] -
                                  validIdx[validIdx.size(1) - 2]);
              }
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &idx
            //                const ::coder::array<double, 1U> &validIdx
            //                double currIdx
            //                const double coordsToUse[2]
            //                double *coordDist
            //                double *moveMultiplier
            //                double *firstValidIdx
            // Return Type  : void
            //
            void b_Checkerboard::findSearchParams(const ::coder::array<double,
              2U> &idx, const ::coder::array<double, 1U> &validIdx, double
              currIdx, const double coordsToUse[2], double *coordDist, double
              *moveMultiplier, double *firstValidIdx) const
            {
              if (idx[0] == 1.0) {
                *moveMultiplier = validIdx[0];
                *firstValidIdx = validIdx[0];
                *coordDist = (BoardCoords[(((static_cast<int>(validIdx[0])) +
                  (BoardCoords.size(0) * ((static_cast<int>(currIdx)) - 1))) +
                  ((BoardCoords.size(0) * BoardCoords.size(1)) * ((static_cast<
                  int>(coordsToUse[0])) - 1))) - 1] - BoardCoords[(((
                  static_cast<int>(validIdx[1])) + (BoardCoords.size(0) * ((
                  static_cast<int>(currIdx)) - 1))) + ((BoardCoords.size(0) *
                  BoardCoords.size(1)) * ((static_cast<int>(coordsToUse[0])) - 1)))
                              - 1]) / (validIdx[1] - validIdx[0]);
              } else {
                *moveMultiplier = ((static_cast<double>(BoardCoords.size(0))) -
                                   validIdx[validIdx.size(0) - 1]) + 1.0;
                *firstValidIdx = validIdx[validIdx.size(0) - 1];
                *coordDist = (BoardCoords[(((static_cast<int>
                  (validIdx[validIdx.size(0) - 1])) + (BoardCoords.size(0) * ((
                  static_cast<int>(currIdx)) - 1))) + ((BoardCoords.size(0) *
                  BoardCoords.size(1)) * ((static_cast<int>(coordsToUse[0])) - 1)))
                              - 1] - BoardCoords[(((static_cast<int>
                  (validIdx[validIdx.size(0) - 2])) + (BoardCoords.size(0) * ((
                  static_cast<int>(currIdx)) - 1))) + ((BoardCoords.size(0) *
                  BoardCoords.size(1)) * ((static_cast<int>(coordsToUse[0])) - 1)))
                              - 1]) / (validIdx[validIdx.size(0) - 1] -
                  validIdx[validIdx.size(0) - 2]);
              }
            }

            //
            // Arguments    : ::coder::array<double, 2U> &newIndices
            // Return Type  : void
            //
            void b_Checkerboard::fitPolynomialIndices(::coder::array<double, 2U>
              &newIndices) const
            {
              ::coder::array<double, 2U> b_index;
              ::coder::array<double, 2U> b_this;
              ::coder::array<double, 2U> b_x;
              ::coder::array<double, 2U> c_this;
              ::coder::array<double, 2U> currCurve;
              ::coder::array<double, 2U> removedIdx;
              ::coder::array<int, 2U> c_ii;
              double b_dv[2];
              double coordsToUse[2];
              double currPt[2];
              double b_y;
              double y;
              int i1;
              int loop_ub;
              int unnamed_idx_1;
              b_findIndependentVar(coordsToUse);
              unnamed_idx_1 = BoardCoords.size(0);
              newIndices.set_size(1, unnamed_idx_1);
              loop_ub = unnamed_idx_1;
              if ((static_cast<int>(unnamed_idx_1 < 4)) != 0) {
                for (int b_i{0}; b_i < unnamed_idx_1; b_i++) {
                  newIndices[b_i] = 0.0;
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i = 0; b_i < loop_ub; b_i++) {
                  newIndices[b_i] = 0.0;
                }
              }

              removedIdx.set_size(1, 0);
              i1 = newIndices.size(1);
              for (int j{0}; j < i1; j++) {
                int b_loop_ub;
                b_loop_ub = BoardCoords.size(1);
                b_x.set_size(1, b_loop_ub);
                for (int i2{0}; i2 < b_loop_ub; i2++) {
                  b_x[i2] = BoardCoords[(j + (BoardCoords.size(0) * i2)) +
                    ((BoardCoords.size(0) * BoardCoords.size(1)) * ((
                       static_cast<int>(coordsToUse[0])) - 1))];
                }

                c_eml_find(b_x, c_ii);
                if (c_ii.size(1) >= 2) {
                  double coordDist;
                  double currCoord;
                  double currRad;
                  double refCoordValue;
                  int coordDist_tmp;
                  int h_n;
                  int i3;
                  int p_n;
                  bool exitg1;
                  coordDist_tmp = c_ii[0];
                  coordDist = (BoardCoords[(j + (BoardCoords.size(0) * (c_ii[0]
                    - 1))) + ((BoardCoords.size(0) * BoardCoords.size(1)) * ((
                    static_cast<int>(coordsToUse[0])) - 1))] - BoardCoords[(j +
                    (BoardCoords.size(0) * (c_ii[1] - 1))) + ((BoardCoords.size
                    (0) * BoardCoords.size(1)) * ((static_cast<int>(coordsToUse
                    [0])) - 1))]) / ((static_cast<double>(c_ii[1])) - (
                    static_cast<double>(coordDist_tmp)));
                  h_n = 0;
                  i3 = c_ii.size(1);
                  b_this.set_size(1, c_ii.size(1));
                  c_this.set_size(1, c_ii.size(1));
                  for (int k{0}; k < i3; k++) {
                    if (c_ii[k] != 0) {
                      h_n++;
                    }

                    b_this[k] = BoardCoords[(j + (BoardCoords.size(0) * (c_ii[k]
                      - 1))) + ((BoardCoords.size(0) * BoardCoords.size(1)) * ((
                      static_cast<int>(coordsToUse[0])) - 1))];
                    c_this[k] = BoardCoords[(j + (BoardCoords.size(0) * (c_ii[k]
                      - 1))) + ((BoardCoords.size(0) * BoardCoords.size(1)) * ((
                      static_cast<int>(coordsToUse[1])) - 1))];
                  }

                  if (h_n > 5) {
                    p_n = 4;
                  } else {
                    p_n = 2;
                  }

                  b_polyfit(b_this, c_this, static_cast<double>(p_n), currCurve);
                  currRad = coordDist / 4.0;
                  refCoordValue = BoardCoords[(j + (BoardCoords.size(0) * (c_ii
                    [0] - 1))) + ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                  ((static_cast<int>(coordsToUse[0])) - 1))];
                  currCoord = currRad + refCoordValue;
                  exitg1 = false;
                  while ((!exitg1) && (std::abs(currCoord - refCoordValue) < (((
                             static_cast<double>(coordDist_tmp)) * 1.5) * std::
                           abs(coordDist)))) {
                    b_dv[0] = 1.0;
                    b_dv[1] = 2.0;
                    if (isequal(coordsToUse, b_dv)) {
                      if (currCurve.size(1) != 0) {
                        int i5;
                        b_y = currCurve[0];
                        i5 = currCurve.size(1);
                        for (int c_k{0}; c_k <= (i5 - 2); c_k++) {
                          b_y = (currCoord * b_y) + currCurve[c_k + 1];
                        }
                      }

                      currPt[0] = currCoord;
                      currPt[1] = b_y;
                    } else {
                      if (currCurve.size(1) != 0) {
                        int i4;
                        y = currCurve[0];
                        i4 = currCurve.size(1);
                        for (int b_k{0}; b_k <= (i4 - 2); b_k++) {
                          y = (currCoord * y) + currCurve[b_k + 1];
                        }
                      }

                      currPt[0] = y;
                      currPt[1] = currCoord;
                    }

                    findClosestOnCurve(currPt, std::abs(currRad), currCurve,
                                       coordsToUse, removedIdx, b_index);
                    if (b_index.size(1) != 0) {
                      int c_loop_ub;
                      int i6;
                      newIndices[j] = b_index[0];
                      i6 = removedIdx.size(1);
                      c_loop_ub = b_index.size(1);
                      removedIdx.set_size(removedIdx.size(0), removedIdx.size(1)
                                          + b_index.size(1));
                      for (int i7{0}; i7 < c_loop_ub; i7++) {
                        removedIdx[i6 + i7] = b_index[i7];
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
            void b_Checkerboard::fitPolynomialIndices(const ::coder::array<
              double, 2U> &idx, ::coder::array<double, 2U> &newIndices) const
            {
              ::coder::array<double, 2U> b_index;
              ::coder::array<double, 2U> currCurve;
              ::coder::array<double, 2U> removedIdx;
              ::coder::array<double, 1U> b_this;
              ::coder::array<double, 1U> c_this;
              ::coder::array<double, 1U> validIdx;
              ::coder::array<int, 1U> c_ii;
              double b_dv[2];
              double coordsToUse[2];
              double currPt[2];
              double b_y;
              double coordDist;
              double firstValidIdx;
              double moveDistMultiplier;
              double y;
              int i1;
              int loop_ub;
              int unnamed_idx_1;
              findIndependentVar(idx, coordsToUse);
              unnamed_idx_1 = BoardCoords.size(1);
              newIndices.set_size(1, unnamed_idx_1);
              loop_ub = unnamed_idx_1;
              if ((static_cast<int>(unnamed_idx_1 < 4)) != 0) {
                for (int b_i{0}; b_i < unnamed_idx_1; b_i++) {
                  newIndices[b_i] = 0.0;
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i = 0; b_i < loop_ub; b_i++) {
                  newIndices[b_i] = 0.0;
                }
              }

              removedIdx.set_size(1, 0);
              i1 = BoardCoords.size(1);
              for (int j{0}; j < i1; j++) {
                int b_loop_ub;
                int c_loop_ub;
                b_loop_ub = BoardCoords.size(0);
                b_this.set_size(b_loop_ub);
                for (int i2{0}; i2 < b_loop_ub; i2++) {
                  b_this[i2] = BoardCoords[(i2 + (BoardCoords.size(0) * j)) +
                    ((BoardCoords.size(0) * BoardCoords.size(1)) * ((
                       static_cast<int>(coordsToUse[0])) - 1))];
                }

                eml_find(b_this, c_ii);
                validIdx.set_size(c_ii.size(0));
                c_loop_ub = c_ii.size(0);
                for (int i3{0}; i3 < c_loop_ub; i3++) {
                  validIdx[i3] = static_cast<double>(c_ii[i3]);
                }

                if (validIdx.size(0) >= 2) {
                  double currCoord;
                  double currRad;
                  double refCoordValue;
                  int d_loop_ub;
                  int e_loop_ub;
                  int h_n;
                  int i4;
                  int p_n;
                  bool exitg1;
                  findSearchParams(idx, validIdx, (static_cast<double>(j)) + 1.0,
                                   coordsToUse, &coordDist, &moveDistMultiplier,
                                   &firstValidIdx);
                  h_n = 0;
                  i4 = validIdx.size(0);
                  for (int k{0}; k < i4; k++) {
                    if (validIdx[k] != 0.0) {
                      h_n++;
                    }
                  }

                  b_this.set_size(validIdx.size(0));
                  d_loop_ub = validIdx.size(0);
                  for (int i5{0}; i5 < d_loop_ub; i5++) {
                    b_this[i5] = BoardCoords[(((static_cast<int>(validIdx[i5]))
                      + (BoardCoords.size(0) * j)) + ((BoardCoords.size(0) *
                      BoardCoords.size(1)) * ((static_cast<int>(coordsToUse[0]))
                      - 1))) - 1];
                  }

                  c_this.set_size(validIdx.size(0));
                  e_loop_ub = validIdx.size(0);
                  for (int i6{0}; i6 < e_loop_ub; i6++) {
                    c_this[i6] = BoardCoords[(((static_cast<int>(validIdx[i6]))
                      + (BoardCoords.size(0) * j)) + ((BoardCoords.size(0) *
                      BoardCoords.size(1)) * ((static_cast<int>(coordsToUse[1]))
                      - 1))) - 1];
                  }

                  if (h_n > 5) {
                    p_n = 4;
                  } else {
                    p_n = 2;
                  }

                  polyfit(b_this, c_this, static_cast<double>(p_n), currCurve);
                  currRad = coordDist / 4.0;
                  refCoordValue = BoardCoords[(((static_cast<int>(firstValidIdx))
                    + (BoardCoords.size(0) * j)) + ((BoardCoords.size(0) *
                    BoardCoords.size(1)) * ((static_cast<int>(coordsToUse[0])) -
                    1))) - 1];
                  currCoord = currRad + refCoordValue;
                  exitg1 = false;
                  while ((!exitg1) && (std::abs(currCoord - refCoordValue) <
                                       ((moveDistMultiplier * 1.5) * std::abs
                                        (coordDist)))) {
                    b_dv[0] = 1.0;
                    b_dv[1] = 2.0;
                    if (isequal(coordsToUse, b_dv)) {
                      if (currCurve.size(1) != 0) {
                        int b_i8;
                        b_y = currCurve[0];
                        b_i8 = currCurve.size(1);
                        for (int c_k{0}; c_k <= (b_i8 - 2); c_k++) {
                          b_y = (currCoord * b_y) + currCurve[c_k + 1];
                        }
                      }

                      currPt[0] = currCoord;
                      currPt[1] = b_y;
                    } else {
                      if (currCurve.size(1) != 0) {
                        int i7;
                        y = currCurve[0];
                        i7 = currCurve.size(1);
                        for (int b_k{0}; b_k <= (i7 - 2); b_k++) {
                          y = (currCoord * y) + currCurve[b_k + 1];
                        }
                      }

                      currPt[0] = y;
                      currPt[1] = currCoord;
                    }

                    findClosestOnCurve(currPt, std::abs(currRad), currCurve,
                                       coordsToUse, removedIdx, b_index);
                    if (b_index.size(1) != 0) {
                      int f_loop_ub;
                      int i9;
                      newIndices[j] = b_index[0];
                      i9 = removedIdx.size(1);
                      f_loop_ub = b_index.size(1);
                      removedIdx.set_size(removedIdx.size(0), removedIdx.size(1)
                                          + b_index.size(1));
                      for (int i10{0}; i10 < f_loop_ub; i10++) {
                        removedIdx[i9 + i10] = b_index[i10];
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
            // Arguments    : void
            // Return Type  : void
            //
            void b_Checkerboard::undoLastExpansion()
            {
              Energy = PreviousEnergy;
              switch (static_cast<int>(LastExpandDirection)) {
               case 1:
                {
                  int b_i;
                  int e_this;
                  int i15;
                  int i19;
                  int i21;
                  int i4;
                  int i6;
                  int i_loop_ub;
                  int j_this;
                  int m_this;
                  b_i = BoardIdx.size(0);
                  if (2 > b_i) {
                    i4 = -1;
                    i6 = -1;
                  } else {
                    i4 = 0;
                    i6 = b_i - 1;
                  }

                  e_this = BoardIdx.size(1) - 1;
                  for (int i9{0}; i9 <= e_this; i9++) {
                    int b_loop_ub_tmp;
                    b_loop_ub_tmp = i6 - i4;
                    for (int i16{0}; i16 < b_loop_ub_tmp; i16++) {
                      BoardIdx[i16 + (b_loop_ub_tmp * i9)] = BoardIdx[((i4 + i16)
                        + (BoardIdx.size(0) * i9)) + 1];
                    }
                  }

                  BoardIdx.set_size(i6 - i4, e_this + 1);
                  i15 = BoardCoords.size(0);
                  if (2 > i15) {
                    i19 = -1;
                    i21 = -1;
                  } else {
                    i19 = 0;
                    i21 = i15 - 1;
                  }

                  j_this = BoardCoords.size(1) - 1;
                  m_this = BoardCoords.size(2) - 1;
                  i_loop_ub = BoardCoords.size(1);
                  for (int i26{0}; i26 <= m_this; i26++) {
                    for (int i29{0}; i29 < i_loop_ub; i29++) {
                      int c_loop_ub_tmp;
                      c_loop_ub_tmp = i21 - i19;
                      for (int i33{0}; i33 < c_loop_ub_tmp; i33++) {
                        BoardCoords[(i33 + (c_loop_ub_tmp * i29)) +
                          ((c_loop_ub_tmp * (j_this + 1)) * i26)] = BoardCoords
                          [(((i19 + i33) + (BoardCoords.size(0) * i29)) +
                            ((BoardCoords.size(0) * BoardCoords.size(1)) * i26))
                          + 1];
                      }
                    }
                  }

                  BoardCoords.set_size(i21 - i19, j_this + 1, m_this + 1);
                }
                break;

               case 2:
                {
                  int b_this;
                  int e_loop_ub;
                  int g_loop_ub;
                  int g_this;
                  int h_this;
                  int i1;
                  int i12;
                  int loop_ub;
                  i1 = BoardIdx.size(0) - 2;
                  if (1 > (i1 + 1)) {
                    loop_ub = 0;
                  } else {
                    loop_ub = i1 + 1;
                  }

                  b_this = BoardIdx.size(1) - 1;
                  for (int b_i8{0}; b_i8 <= b_this; b_i8++) {
                    for (int i11{0}; i11 < loop_ub; i11++) {
                      BoardIdx[i11 + (loop_ub * b_i8)] = BoardIdx[i11 +
                        (BoardIdx.size(0) * b_i8)];
                    }
                  }

                  BoardIdx.set_size(loop_ub, b_this + 1);
                  i12 = BoardCoords.size(0) - 2;
                  if (1 > (i12 + 1)) {
                    e_loop_ub = 0;
                  } else {
                    e_loop_ub = i12 + 1;
                  }

                  g_this = BoardCoords.size(1) - 1;
                  h_this = BoardCoords.size(2) - 1;
                  g_loop_ub = BoardCoords.size(1);
                  for (int i24{0}; i24 <= h_this; i24++) {
                    for (int i27{0}; i27 < g_loop_ub; i27++) {
                      for (int i30{0}; i30 < e_loop_ub; i30++) {
                        BoardCoords[(i30 + (e_loop_ub * i27)) + ((e_loop_ub *
                          (g_this + 1)) * i24)] = BoardCoords[(i30 +
                          (BoardCoords.size(0) * i27)) + ((BoardCoords.size(0) *
                          BoardCoords.size(1)) * i24)];
                      }
                    }
                  }

                  BoardCoords.set_size(e_loop_ub, g_this + 1, h_this + 1);
                }
                break;

               case 3:
                {
                  int d_loop_ub;
                  int f_this;
                  int i2;
                  int i20;
                  int i22;
                  int i23;
                  int i5;
                  int i7;
                  int j_loop_ub;
                  int loop_ub_tmp;
                  int o_this;
                  int p_this;
                  i2 = BoardIdx.size(1);
                  if (2 > i2) {
                    i5 = 0;
                    i7 = 0;
                  } else {
                    i5 = 1;
                    i7 = i2;
                  }

                  f_this = BoardIdx.size(0) - 1;
                  d_loop_ub = BoardIdx.size(0);
                  loop_ub_tmp = i7 - i5;
                  for (int i13{0}; i13 < loop_ub_tmp; i13++) {
                    for (int i18{0}; i18 < d_loop_ub; i18++) {
                      BoardIdx[i18 + ((f_this + 1) * i13)] = BoardIdx[i18 +
                        (BoardIdx.size(0) * (i5 + i13))];
                    }
                  }

                  BoardIdx.set_size(f_this + 1, loop_ub_tmp);
                  i20 = BoardCoords.size(1);
                  if (2 > i20) {
                    i22 = -1;
                    i23 = -1;
                  } else {
                    i22 = 0;
                    i23 = i20 - 1;
                  }

                  o_this = BoardCoords.size(0) - 1;
                  p_this = BoardCoords.size(2) - 1;
                  j_loop_ub = BoardCoords.size(0);
                  for (int i31{0}; i31 <= p_this; i31++) {
                    int d_loop_ub_tmp;
                    d_loop_ub_tmp = i23 - i22;
                    for (int i34{0}; i34 < d_loop_ub_tmp; i34++) {
                      for (int i35{0}; i35 < j_loop_ub; i35++) {
                        BoardCoords[(i35 + ((o_this + 1) * i34)) + (((o_this + 1)
                          * d_loop_ub_tmp) * i31)] = BoardCoords[(i35 +
                          (BoardCoords.size(0) * ((i22 + i34) + 1))) +
                          ((BoardCoords.size(0) * BoardCoords.size(1)) * i31)];
                      }
                    }
                  }

                  BoardCoords.set_size(o_this + 1, i23 - i22, p_this + 1);
                }
                break;

               case 4:
                {
                  int b_loop_ub;
                  int c_loop_ub;
                  int c_this;
                  int f_loop_ub;
                  int h_loop_ub;
                  int i17;
                  int i3;
                  int i_this;
                  int k_this;
                  i3 = BoardIdx.size(1) - 2;
                  if (1 > (i3 + 1)) {
                    b_loop_ub = -1;
                  } else {
                    b_loop_ub = i3;
                  }

                  c_this = BoardIdx.size(0) - 1;
                  c_loop_ub = BoardIdx.size(0);
                  for (int i10{0}; i10 <= b_loop_ub; i10++) {
                    for (int i14{0}; i14 < c_loop_ub; i14++) {
                      BoardIdx[i14 + ((c_this + 1) * i10)] = BoardIdx[i14 +
                        (BoardIdx.size(0) * i10)];
                    }
                  }

                  BoardIdx.set_size(c_this + 1, b_loop_ub + 1);
                  i17 = BoardCoords.size(1) - 2;
                  if (1 > (i17 + 1)) {
                    f_loop_ub = 0;
                  } else {
                    f_loop_ub = i17 + 1;
                  }

                  i_this = BoardCoords.size(0) - 1;
                  k_this = BoardCoords.size(2) - 1;
                  h_loop_ub = BoardCoords.size(0);
                  for (int i25{0}; i25 <= k_this; i25++) {
                    for (int i28{0}; i28 < f_loop_ub; i28++) {
                      for (int i32{0}; i32 < h_loop_ub; i32++) {
                        BoardCoords[(i32 + ((i_this + 1) * i28)) + (((i_this + 1)
                          * f_loop_ub) * i25)] = BoardCoords[(i32 +
                          (BoardCoords.size(0) * i28)) + ((BoardCoords.size(0) *
                          BoardCoords.size(1)) * i25)];
                      }
                    }
                  }

                  BoardCoords.set_size(i_this + 1, f_loop_ub, k_this + 1);
                }
                break;

               default:
                /* no actions */
                break;
              }
            }

            //
            // Arguments    : void
            // Return Type  : bool
            //
            bool b_Checkerboard::expandBoardOnce()
            {
              ::coder::array<double, 3U> b_this;
              ::coder::array<double, 3U> c_this;
              ::coder::array<double, 3U> r1;
              ::coder::array<double, 2U> b_index;
              ::coder::array<double, 2U> b_p1;
              ::coder::array<double, 2U> currCurve;
              ::coder::array<double, 2U> idx;
              ::coder::array<double, 2U> newIndices;
              ::coder::array<double, 2U> newIndicesLinear;
              ::coder::array<double, 2U> p2;
              ::coder::array<double, 2U> r;
              ::coder::array<double, 2U> removedIdx;
              ::coder::array<double, 1U> b_x;
              ::coder::array<double, 1U> e_this;
              ::coder::array<double, 1U> f_this;
              ::coder::array<int, 1U> c_ii;
              double b_dv[2];
              double coordsToUse[2];
              double currPt[2];
              double e_y;
              double k_y;
              int b_i;
              bool success;
              PreviousEnergy = Energy;
              b_i = 0;
              int exitg1;
              do {
                exitg1 = 0;
                if (b_i < 4) {
                  if (!IsDirectionBad[b_i]) {
                    float newEnergy;
                    float oldEnergy;
                    LastExpandDirection = (static_cast<double>(b_i)) + 1.0;
                    oldEnergy = (Energy + (static_cast<float>(static_cast<int>
                      (BoardIdx.size(0) * BoardIdx.size(1))))) / (static_cast<
                      float>(static_cast<int>(BoardIdx.size(0) * BoardIdx.size(1))));
                    switch (b_i + 1) {
                     case 1:
                      {
                        int rc_loop_ub;
                        int yb_loop_ub;
                        if (IsDistortionHigh) {
                          int d_k;
                          int i7;
                          int unnamed_idx_1;
                          bool d_y;
                          bool exitg2;
                          findIndependentVar(coordsToUse);
                          unnamed_idx_1 = BoardCoords.size(1);
                          newIndices.set_size(1, unnamed_idx_1);
                          for (int i2{0}; i2 < unnamed_idx_1; i2++) {
                            newIndices[i2] = 0.0;
                          }

                          removedIdx.set_size(1, 0);
                          i7 = newIndices.size(1);
                          for (int j{0}; j < i7; j++) {
                            int s_loop_ub;
                            s_loop_ub = BoardCoords.size(0);
                            b_x.set_size(s_loop_ub);
                            for (int i16{0}; i16 < s_loop_ub; i16++) {
                              b_x[i16] = BoardCoords[(i16 + (BoardCoords.size(0)
                                * j)) + ((BoardCoords.size(0) * BoardCoords.size
                                          (1)) * ((static_cast<int>(coordsToUse
                                [0])) - 1))];
                            }

                            eml_find(b_x, c_ii);
                            if (c_ii.size(0) >= 2) {
                              double coordDist;
                              double coordDist_tmp;
                              double currCoord;
                              double currRad;
                              double d;
                              int h_n;
                              int i41;
                              int p_n;
                              d = coordsToUse[0];
                              coordDist_tmp = BoardCoords[((c_ii[0] +
                                (BoardCoords.size(0) * j)) + ((BoardCoords.size
                                (0) * BoardCoords.size(1)) * ((static_cast<int>
                                (coordsToUse[0])) - 1))) - 1];
                              coordDist = (coordDist_tmp - BoardCoords[((c_ii[1]
                                + (BoardCoords.size(0) * j)) +
                                ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                 ((static_cast<int>(coordsToUse[0])) - 1))) - 1])
                                / ((static_cast<double>(c_ii[1])) - (
                                    static_cast<double>(c_ii[0])));
                              h_n = 0;
                              i41 = c_ii.size(0);
                              e_this.set_size(c_ii.size(0));
                              f_this.set_size(c_ii.size(0));
                              for (int e_k{0}; e_k < i41; e_k++) {
                                if (c_ii[e_k] != 0) {
                                  h_n++;
                                }

                                e_this[e_k] = BoardCoords[((c_ii[e_k] +
                                  (BoardCoords.size(0) * j)) +
                                  ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                   ((static_cast<int>(d)) - 1))) - 1];
                                f_this[e_k] = BoardCoords[((c_ii[e_k] +
                                  (BoardCoords.size(0) * j)) +
                                  ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                   ((static_cast<int>(coordsToUse[1])) - 1))) -
                                  1];
                              }

                              if (h_n > 5) {
                                p_n = 4;
                              } else {
                                p_n = 2;
                              }

                              polyfit(e_this, f_this, static_cast<double>(p_n),
                                      currCurve);
                              currRad = coordDist / 4.0;
                              currCoord = currRad + coordDist_tmp;
                              exitg2 = false;
                              while ((!exitg2) && (std::abs(currCoord -
                                       coordDist_tmp) < (((static_cast<double>
                                         (c_ii[0])) * 1.5) * std::abs(coordDist))))
                              {
                                b_dv[0] = 1.0;
                                b_dv[1] = 2.0;
                                if (isequal(coordsToUse, b_dv)) {
                                  if (currCurve.size(1) != 0) {
                                    int i77;
                                    k_y = currCurve[0];
                                    i77 = currCurve.size(1);
                                    for (int h_k{0}; h_k <= (i77 - 2); h_k++) {
                                      k_y = (currCoord * k_y) + currCurve[h_k +
                                        1];
                                    }
                                  }

                                  currPt[0] = currCoord;
                                  currPt[1] = k_y;
                                } else {
                                  if (currCurve.size(1) != 0) {
                                    int i76;
                                    e_y = currCurve[0];
                                    i76 = currCurve.size(1);
                                    for (int g_k{0}; g_k <= (i76 - 2); g_k++) {
                                      e_y = (currCoord * e_y) + currCurve[g_k +
                                        1];
                                    }
                                  }

                                  currPt[0] = e_y;
                                  currPt[1] = currCoord;
                                }

                                findClosestOnCurve(currPt, std::abs(currRad),
                                                   currCurve, coordsToUse,
                                                   removedIdx, b_index);
                                if (b_index.size(1) != 0) {
                                  int ed_loop_ub;
                                  int i78;
                                  newIndices[j] = b_index[0];
                                  i78 = removedIdx.size(1);
                                  ed_loop_ub = b_index.size(1);
                                  removedIdx.set_size(removedIdx.size(0),
                                                      removedIdx.size(1) +
                                                      b_index.size(1));
                                  for (int i79{0}; i79 < ed_loop_ub; i79++) {
                                    removedIdx[i78 + i79] = b_index[i79];
                                  }

                                  exitg2 = true;
                                } else {
                                  currCoord += currRad;
                                }
                              }
                            }
                          }

                          d_y = true;
                          d_k = 0;
                          exitg2 = false;
                          while ((!exitg2) && (d_k <= (newIndices.size(1) - 1)))
                          {
                            if (newIndices[d_k] == 0.0) {
                              d_y = false;
                              exitg2 = true;
                            } else {
                              d_k++;
                            }
                          }

                          if (!d_y) {
                            int d_end;
                            int gc_loop_ub;
                            int kb_loop_ub;
                            int mc_loop_ub;
                            int qb_loop_ub;
                            int yc_loop_ub;
                            kb_loop_ub = BoardCoords.size(1);
                            qb_loop_ub = BoardCoords.size(2);
                            b_this.set_size(1, kb_loop_ub, qb_loop_ub);
                            for (int i37{0}; i37 < qb_loop_ub; i37++) {
                              for (int i47{0}; i47 < kb_loop_ub; i47++) {
                                b_this[i47 + (b_this.size(1) * i37)] =
                                  BoardCoords[((BoardCoords.size(0) * i47) +
                                               ((BoardCoords.size(0) *
                                                 BoardCoords.size(1)) * i37)) +
                                  1];
                              }
                            }

                            squeeze(b_this, b_p1);
                            gc_loop_ub = BoardCoords.size(1);
                            mc_loop_ub = BoardCoords.size(2);
                            b_this.set_size(1, gc_loop_ub, mc_loop_ub);
                            for (int i62{0}; i62 < mc_loop_ub; i62++) {
                              for (int i67{0}; i67 < gc_loop_ub; i67++) {
                                b_this[i67 + (b_this.size(1) * i62)] =
                                  BoardCoords[(BoardCoords.size(0) * i67) +
                                  ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                   i62)];
                              }
                            }

                            squeeze(b_this, p2);
                            yc_loop_ub = p2.size(1);
                            for (int i71{0}; i71 < yc_loop_ub; i71++) {
                              int dd_loop_ub;
                              dd_loop_ub = p2.size(0);
                              for (int i75{0}; i75 < dd_loop_ub; i75++) {
                                double d8;
                                d8 = p2[i75 + (p2.size(0) * i71)];
                                d8 = (d8 + d8) - b_p1[i75 + (b_p1.size(0) * i71)];
                                p2[i75 + (p2.size(0) * i71)] = d8;
                              }
                            }

                            findClosestIndices(p2, newIndicesLinear);
                            d_end = newIndices.size(1);
                            for (int h_i{0}; h_i < d_end; h_i++) {
                              if (newIndices[h_i] == 0.0) {
                                newIndices[h_i] = newIndicesLinear[h_i];
                              }
                            }
                          }
                        } else {
                          int d_loop_ub;
                          int j_loop_ub;
                          int loop_ub;
                          int o_loop_ub;
                          int w_loop_ub;
                          loop_ub = BoardCoords.size(1);
                          d_loop_ub = BoardCoords.size(2);
                          b_this.set_size(1, loop_ub, d_loop_ub);
                          for (int i1{0}; i1 < d_loop_ub; i1++) {
                            for (int i5{0}; i5 < loop_ub; i5++) {
                              b_this[i5 + (b_this.size(1) * i1)] = BoardCoords
                                [((BoardCoords.size(0) * i5) +
                                  ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                   i1)) + 1];
                            }
                          }

                          squeeze(b_this, b_p1);
                          j_loop_ub = BoardCoords.size(1);
                          o_loop_ub = BoardCoords.size(2);
                          b_this.set_size(1, j_loop_ub, o_loop_ub);
                          for (int i10{0}; i10 < o_loop_ub; i10++) {
                            for (int i15{0}; i15 < j_loop_ub; i15++) {
                              b_this[i15 + (b_this.size(1) * i10)] =
                                BoardCoords[(BoardCoords.size(0) * i15) +
                                ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                 i10)];
                            }
                          }

                          squeeze(b_this, p2);
                          w_loop_ub = p2.size(1);
                          for (int i20{0}; i20 < w_loop_ub; i20++) {
                            int jb_loop_ub;
                            jb_loop_ub = p2.size(0);
                            for (int i28{0}; i28 < jb_loop_ub; i28++) {
                              double b_d1;
                              b_d1 = p2[i28 + (p2.size(0) * i20)];
                              b_d1 = (b_d1 + b_d1) - b_p1[i28 + (b_p1.size(0) *
                                i20)];
                              p2[i28 + (p2.size(0) * i20)] = b_d1;
                            }
                          }

                          findClosestIndices(p2, newIndices);
                        }

                        expandBoardUp(newIndices, r, r1);
                        BoardIdx.set_size(r.size(0), r.size(1));
                        yb_loop_ub = r.size(1);
                        for (int i46{0}; i46 < yb_loop_ub; i46++) {
                          int kc_loop_ub;
                          kc_loop_ub = r.size(0);
                          for (int i56{0}; i56 < kc_loop_ub; i56++) {
                            BoardIdx[i56 + (BoardIdx.size(0) * i46)] = r[i56 +
                              (r.size(0) * i46)];
                          }
                        }

                        BoardCoords.set_size(r1.size(0), r1.size(1), r1.size(2));
                        rc_loop_ub = r1.size(2);
                        for (int i61{0}; i61 < rc_loop_ub; i61++) {
                          int xc_loop_ub;
                          xc_loop_ub = r1.size(1);
                          for (int i70{0}; i70 < xc_loop_ub; i70++) {
                            int cd_loop_ub;
                            cd_loop_ub = r1.size(0);
                            for (int i74{0}; i74 < cd_loop_ub; i74++) {
                              BoardCoords[(i74 + (BoardCoords.size(0) * i70)) +
                                ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                 i61)] = r1[(i74 + (r1.size(0) * i70)) +
                                ((r1.size(0) * r1.size(1)) * i61)];
                            }
                          }
                        }

                        newEnergy = computeNewEnergyVertical(oldEnergy);
                      }
                      break;

                     case 2:
                      {
                        int ac_loop_ub;
                        int mb_loop_ub;
                        int numRows;
                        int sc_loop_ub;
                        numRows = BoardCoords.size(0);
                        if ((static_cast<double>(numRows)) < ((static_cast<
                              double>(numRows)) - 2.0)) {
                          idx.set_size(1, 0);
                        } else {
                          int e_loop_ub;
                          e_loop_ub = static_cast<int>(static_cast<double>(-(((
                            static_cast<double>(numRows)) - 2.0) - (static_cast<
                            double>(numRows)))));
                          idx.set_size(1, e_loop_ub + 1);
                          for (int i3{0}; i3 <= e_loop_ub; i3++) {
                            idx[i3] = (static_cast<double>(numRows)) - (
                              static_cast<double>(i3));
                          }
                        }

                        if (IsDistortionHigh) {
                          int c_k;
                          bool c_y;
                          bool exitg2;
                          fitPolynomialIndices(idx, newIndices);
                          c_y = true;
                          c_k = 0;
                          exitg2 = false;
                          while ((!exitg2) && (c_k <= (newIndices.size(1) - 1)))
                          {
                            if (newIndices[c_k] == 0.0) {
                              c_y = false;
                              exitg2 = true;
                            } else {
                              c_k++;
                            }
                          }

                          if (!c_y) {
                            int bc_loop_ub;
                            int c_end;
                            int eb_loop_ub;
                            int ec_loop_ub;
                            int g_idx;
                            int j_idx;
                            int wc_loop_ub;
                            int y_loop_ub;
                            g_idx = static_cast<int>(idx[1]);
                            y_loop_ub = BoardCoords.size(1);
                            eb_loop_ub = BoardCoords.size(2);
                            b_this.set_size(1, y_loop_ub, eb_loop_ub);
                            for (int i25{0}; i25 < eb_loop_ub; i25++) {
                              for (int i36{0}; i36 < y_loop_ub; i36++) {
                                b_this[i36 + (b_this.size(1) * i25)] =
                                  BoardCoords[((g_idx + (BoardCoords.size(0) *
                                  i36)) + ((BoardCoords.size(0) *
                                            BoardCoords.size(1)) * i25)) - 1];
                              }
                            }

                            squeeze(b_this, b_p1);
                            j_idx = static_cast<int>(idx[0]);
                            bc_loop_ub = BoardCoords.size(1);
                            ec_loop_ub = BoardCoords.size(2);
                            b_this.set_size(1, bc_loop_ub, ec_loop_ub);
                            for (int i53{0}; i53 < ec_loop_ub; i53++) {
                              for (int i64{0}; i64 < bc_loop_ub; i64++) {
                                b_this[i64 + (b_this.size(1) * i53)] =
                                  BoardCoords[((j_idx + (BoardCoords.size(0) *
                                  i64)) + ((BoardCoords.size(0) *
                                            BoardCoords.size(1)) * i53)) - 1];
                              }
                            }

                            squeeze(b_this, p2);
                            wc_loop_ub = p2.size(1);
                            for (int i69{0}; i69 < wc_loop_ub; i69++) {
                              int bd_loop_ub;
                              bd_loop_ub = p2.size(0);
                              for (int i73{0}; i73 < bd_loop_ub; i73++) {
                                double d7;
                                d7 = p2[i73 + (p2.size(0) * i69)];
                                d7 = (d7 + d7) - b_p1[i73 + (b_p1.size(0) * i69)];
                                p2[i73 + (p2.size(0) * i69)] = d7;
                              }
                            }

                            findClosestIndices(p2, newIndicesLinear);
                            c_end = newIndices.size(1);
                            for (int g_i{0}; g_i < c_end; g_i++) {
                              if (newIndices[g_i] == 0.0) {
                                newIndices[g_i] = newIndicesLinear[g_i];
                              }
                            }
                          }
                        } else {
                          int c_idx;
                          int db_loop_ub;
                          int f_idx;
                          int h_loop_ub;
                          int k_loop_ub;
                          int tb_loop_ub;
                          int x_loop_ub;
                          c_idx = static_cast<int>(idx[1]);
                          h_loop_ub = BoardCoords.size(1);
                          k_loop_ub = BoardCoords.size(2);
                          b_this.set_size(1, h_loop_ub, k_loop_ub);
                          for (int i9{0}; i9 < k_loop_ub; i9++) {
                            for (int i13{0}; i13 < h_loop_ub; i13++) {
                              b_this[i13 + (b_this.size(1) * i9)] = BoardCoords
                                [((c_idx + (BoardCoords.size(0) * i13)) +
                                  ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                   i9)) - 1];
                            }
                          }

                          squeeze(b_this, b_p1);
                          f_idx = static_cast<int>(idx[0]);
                          x_loop_ub = BoardCoords.size(1);
                          db_loop_ub = BoardCoords.size(2);
                          b_this.set_size(1, x_loop_ub, db_loop_ub);
                          for (int i24{0}; i24 < db_loop_ub; i24++) {
                            for (int i35{0}; i35 < x_loop_ub; i35++) {
                              b_this[i35 + (b_this.size(1) * i24)] =
                                BoardCoords[((f_idx + (BoardCoords.size(0) * i35))
                                             + ((BoardCoords.size(0) *
                                                 BoardCoords.size(1)) * i24)) -
                                1];
                            }
                          }

                          squeeze(b_this, p2);
                          tb_loop_ub = p2.size(1);
                          for (int i42{0}; i42 < tb_loop_ub; i42++) {
                            int hc_loop_ub;
                            hc_loop_ub = p2.size(0);
                            for (int i52{0}; i52 < hc_loop_ub; i52++) {
                              double d4;
                              d4 = p2[i52 + (p2.size(0) * i42)];
                              d4 = (d4 + d4) - b_p1[i52 + (b_p1.size(0) * i42)];
                              p2[i52 + (p2.size(0) * i42)] = d4;
                            }
                          }

                          findClosestIndices(p2, newIndices);
                        }

                        expandBoardDown(newIndices, r, r1);
                        BoardIdx.set_size(r.size(0), r.size(1));
                        mb_loop_ub = r.size(1);
                        for (int i29{0}; i29 < mb_loop_ub; i29++) {
                          int ub_loop_ub;
                          ub_loop_ub = r.size(0);
                          for (int i43{0}; i43 < ub_loop_ub; i43++) {
                            BoardIdx[i43 + (BoardIdx.size(0) * i29)] = r[i43 +
                              (r.size(0) * i29)];
                          }
                        }

                        BoardCoords.set_size(r1.size(0), r1.size(1), r1.size(2));
                        ac_loop_ub = r1.size(2);
                        for (int i48{0}; i48 < ac_loop_ub; i48++) {
                          int oc_loop_ub;
                          oc_loop_ub = r1.size(1);
                          for (int i57{0}; i57 < oc_loop_ub; i57++) {
                            int vc_loop_ub;
                            vc_loop_ub = r1.size(0);
                            for (int i68{0}; i68 < vc_loop_ub; i68++) {
                              BoardCoords[(i68 + (BoardCoords.size(0) * i57)) +
                                ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                 i48)] = r1[(i68 + (r1.size(0) * i57)) +
                                ((r1.size(0) * r1.size(1)) * i48)];
                            }
                          }
                        }

                        idx.set_size(1, idx.size(1));
                        sc_loop_ub = idx.size(1);
                        for (int i63{0}; i63 < sc_loop_ub; i63++) {
                          idx[i63] = idx[i63] + 1.0;
                        }

                        newEnergy = computeNewEnergyVertical(idx, oldEnergy);
                      }
                      break;

                     case 3:
                      {
                        int pb_loop_ub;
                        int t_loop_ub;
                        if (IsDistortionHigh) {
                          int k;
                          bool exitg2;
                          bool y;
                          fitPolynomialIndices(newIndices);
                          y = true;
                          k = 0;
                          exitg2 = false;
                          while ((!exitg2) && (k <= (newIndices.size(1) - 1))) {
                            if (newIndices[k] == 0.0) {
                              y = false;
                              exitg2 = true;
                            } else {
                              k++;
                            }
                          }

                          if (!y) {
                            int cc_loop_ub;
                            int end;
                            int fb_loop_ub;
                            int hb_loop_ub;
                            int q_loop_ub;
                            int r_loop_ub;
                            q_loop_ub = BoardCoords.size(0);
                            r_loop_ub = BoardCoords.size(2);
                            c_this.set_size(q_loop_ub, 1, r_loop_ub);
                            for (int i14{0}; i14 < r_loop_ub; i14++) {
                              for (int i19{0}; i19 < q_loop_ub; i19++) {
                                c_this[i19 + (c_this.size(0) * i14)] =
                                  BoardCoords[(i19 + BoardCoords.size(0)) +
                                  ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                   i14)];
                              }
                            }

                            b_squeeze(c_this, b_p1);
                            fb_loop_ub = BoardCoords.size(0);
                            hb_loop_ub = BoardCoords.size(2);
                            c_this.set_size(fb_loop_ub, 1, hb_loop_ub);
                            for (int i32{0}; i32 < hb_loop_ub; i32++) {
                              for (int i38{0}; i38 < fb_loop_ub; i38++) {
                                c_this[i38 + (c_this.size(0) * i32)] =
                                  BoardCoords[i38 + ((BoardCoords.size(0) *
                                                      BoardCoords.size(1)) * i32)];
                              }
                            }

                            b_squeeze(c_this, p2);
                            cc_loop_ub = p2.size(1);
                            for (int i49{0}; i49 < cc_loop_ub; i49++) {
                              int pc_loop_ub;
                              pc_loop_ub = p2.size(0);
                              for (int i58{0}; i58 < pc_loop_ub; i58++) {
                                double d5;
                                d5 = p2[i58 + (p2.size(0) * i49)];
                                d5 = (d5 + d5) - b_p1[i58 + (b_p1.size(0) * i49)];
                                p2[i58 + (p2.size(0) * i49)] = d5;
                              }
                            }

                            findClosestIndices(p2, newIndicesLinear);
                            end = newIndices.size(1);
                            for (int d_i{0}; d_i < end; d_i++) {
                              if (newIndices[d_i] == 0.0) {
                                newIndices[d_i] = newIndicesLinear[d_i];
                              }
                            }
                          }
                        } else {
                          int ab_loop_ub;
                          int b_loop_ub;
                          int f_loop_ub;
                          int m_loop_ub;
                          int p_loop_ub;
                          b_loop_ub = BoardCoords.size(0);
                          f_loop_ub = BoardCoords.size(2);
                          c_this.set_size(b_loop_ub, 1, f_loop_ub);
                          for (int i4{0}; i4 < f_loop_ub; i4++) {
                            for (int i6{0}; i6 < b_loop_ub; i6++) {
                              c_this[i6 + (c_this.size(0) * i4)] = BoardCoords
                                [(i6 + BoardCoords.size(0)) + ((BoardCoords.size
                                (0) * BoardCoords.size(1)) * i4)];
                            }
                          }

                          b_squeeze(c_this, b_p1);
                          m_loop_ub = BoardCoords.size(0);
                          p_loop_ub = BoardCoords.size(2);
                          c_this.set_size(m_loop_ub, 1, p_loop_ub);
                          for (int i11{0}; i11 < p_loop_ub; i11++) {
                            for (int i17{0}; i17 < m_loop_ub; i17++) {
                              c_this[i17 + (c_this.size(0) * i11)] =
                                BoardCoords[i17 + ((BoardCoords.size(0) *
                                                    BoardCoords.size(1)) * i11)];
                            }
                          }

                          b_squeeze(c_this, p2);
                          ab_loop_ub = p2.size(1);
                          for (int i21{0}; i21 < ab_loop_ub; i21++) {
                            int ob_loop_ub;
                            ob_loop_ub = p2.size(0);
                            for (int i30{0}; i30 < ob_loop_ub; i30++) {
                              double d2;
                              d2 = p2[i30 + (p2.size(0) * i21)];
                              d2 = (d2 + d2) - b_p1[i30 + (b_p1.size(0) * i21)];
                              p2[i30 + (p2.size(0) * i21)] = d2;
                            }
                          }

                          findClosestIndices(p2, newIndices);
                        }

                        expandBoardLeft(newIndices, r, r1);
                        BoardIdx.set_size(r.size(0), r.size(1));
                        t_loop_ub = r.size(1);
                        for (int i18{0}; i18 < t_loop_ub; i18++) {
                          int gb_loop_ub;
                          gb_loop_ub = r.size(0);
                          for (int i26{0}; i26 < gb_loop_ub; i26++) {
                            BoardIdx[i26 + (BoardIdx.size(0) * i18)] = r[i26 +
                              (r.size(0) * i18)];
                          }
                        }

                        BoardCoords.set_size(r1.size(0), r1.size(1), r1.size(2));
                        pb_loop_ub = r1.size(2);
                        for (int i31{0}; i31 < pb_loop_ub; i31++) {
                          int vb_loop_ub;
                          vb_loop_ub = r1.size(1);
                          for (int i44{0}; i44 < vb_loop_ub; i44++) {
                            int ic_loop_ub;
                            ic_loop_ub = r1.size(0);
                            for (int i54{0}; i54 < ic_loop_ub; i54++) {
                              BoardCoords[(i54 + (BoardCoords.size(0) * i44)) +
                                ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                 i31)] = r1[(i54 + (r1.size(0) * i44)) +
                                ((r1.size(0) * r1.size(1)) * i31)];
                            }
                          }
                        }

                        newEnergy = computeNewEnergyHorizontal(oldEnergy);
                      }
                      break;

                     default:
                      {
                        int ib_loop_ub;
                        int numCols;
                        int qc_loop_ub;
                        int wb_loop_ub;
                        numCols = BoardCoords.size(1);
                        if ((static_cast<double>(numCols)) < ((static_cast<
                              double>(numCols)) - 2.0)) {
                          idx.set_size(1, 0);
                        } else {
                          int c_loop_ub;
                          c_loop_ub = static_cast<int>(static_cast<double>(-(((
                            static_cast<double>(numCols)) - 2.0) - (static_cast<
                            double>(numCols)))));
                          idx.set_size(1, c_loop_ub + 1);
                          for (int c_i{0}; c_i <= c_loop_ub; c_i++) {
                            idx[c_i] = (static_cast<double>(numCols)) - (
                              static_cast<double>(c_i));
                          }
                        }

                        if (IsDistortionHigh) {
                          int b_k;
                          bool b_y;
                          bool exitg2;
                          b_fitPolynomialIndices(idx, newIndices);
                          b_y = true;
                          b_k = 0;
                          exitg2 = false;
                          while ((!exitg2) && (b_k <= (newIndices.size(1) - 1)))
                          {
                            if (newIndices[b_k] == 0.0) {
                              b_y = false;
                              exitg2 = true;
                            } else {
                              b_k++;
                            }
                          }

                          if (!b_y) {
                            int b_end;
                            int cb_loop_ub;
                            int dc_loop_ub;
                            int e_idx;
                            int h_idx;
                            int uc_loop_ub;
                            int v_loop_ub;
                            int xb_loop_ub;
                            e_idx = static_cast<int>(idx[1]);
                            v_loop_ub = BoardCoords.size(0);
                            cb_loop_ub = BoardCoords.size(2);
                            c_this.set_size(v_loop_ub, 1, cb_loop_ub);
                            for (int i23{0}; i23 < cb_loop_ub; i23++) {
                              for (int i34{0}; i34 < v_loop_ub; i34++) {
                                c_this[i34 + (c_this.size(0) * i23)] =
                                  BoardCoords[(i34 + (BoardCoords.size(0) *
                                                      (e_idx - 1))) +
                                  ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                   i23)];
                              }
                            }

                            b_squeeze(c_this, b_p1);
                            h_idx = static_cast<int>(idx[0]);
                            xb_loop_ub = BoardCoords.size(0);
                            dc_loop_ub = BoardCoords.size(2);
                            c_this.set_size(xb_loop_ub, 1, dc_loop_ub);
                            for (int i51{0}; i51 < dc_loop_ub; i51++) {
                              for (int i60{0}; i60 < xb_loop_ub; i60++) {
                                c_this[i60 + (c_this.size(0) * i51)] =
                                  BoardCoords[(i60 + (BoardCoords.size(0) *
                                                      (h_idx - 1))) +
                                  ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                   i51)];
                              }
                            }

                            b_squeeze(c_this, p2);
                            uc_loop_ub = p2.size(1);
                            for (int i66{0}; i66 < uc_loop_ub; i66++) {
                              int ad_loop_ub;
                              ad_loop_ub = p2.size(0);
                              for (int i72{0}; i72 < ad_loop_ub; i72++) {
                                double d6;
                                d6 = p2[i72 + (p2.size(0) * i66)];
                                d6 = (d6 + d6) - b_p1[i72 + (b_p1.size(0) * i66)];
                                p2[i72 + (p2.size(0) * i66)] = d6;
                              }
                            }

                            findClosestIndices(p2, newIndicesLinear);
                            b_end = newIndices.size(1);
                            for (int e_i{0}; e_i < b_end; e_i++) {
                              if (newIndices[e_i] == 0.0) {
                                newIndices[e_i] = newIndicesLinear[e_i];
                              }
                            }
                          }
                        } else {
                          int b_idx;
                          int bb_loop_ub;
                          int d_idx;
                          int g_loop_ub;
                          int i_loop_ub;
                          int rb_loop_ub;
                          int u_loop_ub;
                          b_idx = static_cast<int>(idx[1]);
                          g_loop_ub = BoardCoords.size(0);
                          i_loop_ub = BoardCoords.size(2);
                          c_this.set_size(g_loop_ub, 1, i_loop_ub);
                          for (int b_i8{0}; b_i8 < i_loop_ub; b_i8++) {
                            for (int i12{0}; i12 < g_loop_ub; i12++) {
                              c_this[i12 + (c_this.size(0) * b_i8)] =
                                BoardCoords[(i12 + (BoardCoords.size(0) * (b_idx
                                - 1))) + ((BoardCoords.size(0) *
                                           BoardCoords.size(1)) * b_i8)];
                            }
                          }

                          b_squeeze(c_this, b_p1);
                          d_idx = static_cast<int>(idx[0]);
                          u_loop_ub = BoardCoords.size(0);
                          bb_loop_ub = BoardCoords.size(2);
                          c_this.set_size(u_loop_ub, 1, bb_loop_ub);
                          for (int i22{0}; i22 < bb_loop_ub; i22++) {
                            for (int i33{0}; i33 < u_loop_ub; i33++) {
                              c_this[i33 + (c_this.size(0) * i22)] =
                                BoardCoords[(i33 + (BoardCoords.size(0) * (d_idx
                                - 1))) + ((BoardCoords.size(0) *
                                           BoardCoords.size(1)) * i22)];
                            }
                          }

                          b_squeeze(c_this, p2);
                          rb_loop_ub = p2.size(1);
                          for (int i39{0}; i39 < rb_loop_ub; i39++) {
                            int fc_loop_ub;
                            fc_loop_ub = p2.size(0);
                            for (int i50{0}; i50 < fc_loop_ub; i50++) {
                              double d3;
                              d3 = p2[i50 + (p2.size(0) * i39)];
                              d3 = (d3 + d3) - b_p1[i50 + (b_p1.size(0) * i39)];
                              p2[i50 + (p2.size(0) * i39)] = d3;
                            }
                          }

                          findClosestIndices(p2, newIndices);
                        }

                        expandBoardRight(newIndices, r, r1);
                        BoardIdx.set_size(r.size(0), r.size(1));
                        ib_loop_ub = r.size(1);
                        for (int i27{0}; i27 < ib_loop_ub; i27++) {
                          int sb_loop_ub;
                          sb_loop_ub = r.size(0);
                          for (int i40{0}; i40 < sb_loop_ub; i40++) {
                            BoardIdx[i40 + (BoardIdx.size(0) * i27)] = r[i40 +
                              (r.size(0) * i27)];
                          }
                        }

                        BoardCoords.set_size(r1.size(0), r1.size(1), r1.size(2));
                        wb_loop_ub = r1.size(2);
                        for (int i45{0}; i45 < wb_loop_ub; i45++) {
                          int jc_loop_ub;
                          jc_loop_ub = r1.size(1);
                          for (int i55{0}; i55 < jc_loop_ub; i55++) {
                            int tc_loop_ub;
                            tc_loop_ub = r1.size(0);
                            for (int i65{0}; i65 < tc_loop_ub; i65++) {
                              BoardCoords[(i65 + (BoardCoords.size(0) * i55)) +
                                ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                 i45)] = r1[(i65 + (r1.size(0) * i55)) +
                                ((r1.size(0) * r1.size(1)) * i45)];
                            }
                          }
                        }

                        idx.set_size(1, idx.size(1));
                        qc_loop_ub = idx.size(1);
                        for (int i59{0}; i59 < qc_loop_ub; i59++) {
                          idx[i59] = idx[i59] + 1.0;
                        }

                        newEnergy = computeNewEnergyHorizontal(idx, oldEnergy);
                      }
                      break;
                    }

                    Energy = newEnergy;
                    if (Energy < PreviousEnergy) {
                      success = true;
                      exitg1 = 1;
                    } else {
                      undoLastExpansion();
                      IsDirectionBad[b_i] = true;
                      b_i++;
                    }
                  } else {
                    b_i++;
                  }
                } else {
                  success = false;
                  exitg1 = 1;
                }
              } while (exitg1 == 0);

              return success;
            }

            //
            // Arguments    : void
            // Return Type  : void
            //
            void b_Checkerboard::expandPartialBoard()
            {
              ::coder::array<double, 3U> b_this;
              ::coder::array<double, 3U> c_this;
              ::coder::array<double, 3U> r1;
              ::coder::array<double, 2U> b_index;
              ::coder::array<double, 2U> b_p1;
              ::coder::array<double, 2U> currCurve;
              ::coder::array<double, 2U> idx;
              ::coder::array<double, 2U> newIndices;
              ::coder::array<double, 2U> p2;
              ::coder::array<double, 2U> predictedPoints;
              ::coder::array<double, 2U> r;
              ::coder::array<double, 2U> removedIdx;
              ::coder::array<double, 1U> b_x;
              ::coder::array<double, 1U> e_this;
              ::coder::array<double, 1U> f_this;
              ::coder::array<int, 1U> c_ii;
              ::coder::array<int, 1U> r4;
              ::coder::array<int, 1U> r5;
              ::coder::array<int, 1U> r6;
              ::coder::array<int, 1U> r7;
              ::coder::array<bool, 1U> r2;
              ::coder::array<bool, 1U> r3;
              double b_dv[2];
              double coordsToUse[2];
              double currPt[2];
              double b_y;
              double y;
              bool hasExpanded;
              for (int b_i{0}; b_i < 4; b_i++) {
                IsDirectionBad[b_i] = false;
              }

              hasExpanded = true;
              while (hasExpanded) {
                int c_i;
                PreviousEnergy = Energy;
                c_i = 0;
                int exitg1;
                do {
                  exitg1 = 0;
                  if (c_i < 4) {
                    if (!IsDirectionBad[c_i]) {
                      float newEnergy;
                      float oldEnergy;
                      LastExpandDirection = (static_cast<double>(c_i)) + 1.0;
                      oldEnergy = (Energy + (static_cast<float>(static_cast<int>
                        (BoardIdx.size(0) * BoardIdx.size(1))))) / (static_cast<
                        float>(static_cast<int>(BoardIdx.size(0) * BoardIdx.size
                        (1))));
                      switch (c_i + 1) {
                       case 1:
                        {
                          int ec_loop_ub;
                          int ub_loop_ub;
                          if (IsDistortionHigh) {
                            int h_n;
                            int i19;
                            int i9;
                            int unnamed_idx_1;
                            findIndependentVar(coordsToUse);
                            unnamed_idx_1 = BoardCoords.size(1);
                            newIndices.set_size(1, unnamed_idx_1);
                            for (int i3{0}; i3 < unnamed_idx_1; i3++) {
                              newIndices[i3] = 0.0;
                            }

                            removedIdx.set_size(1, 0);
                            i9 = newIndices.size(1);
                            for (int j{0}; j < i9; j++) {
                              int v_loop_ub;
                              v_loop_ub = BoardCoords.size(0);
                              b_x.set_size(v_loop_ub);
                              for (int i22{0}; i22 < v_loop_ub; i22++) {
                                b_x[i22] = BoardCoords[(i22 + (BoardCoords.size
                                  (0) * j)) + ((BoardCoords.size(0) *
                                                BoardCoords.size(1)) * ((
                                  static_cast<int>(coordsToUse[0])) - 1))];
                              }

                              eml_find(b_x, c_ii);
                              if (c_ii.size(0) >= 2) {
                                double coordDist;
                                double coordDist_tmp;
                                double currCoord;
                                double currRad;
                                double d;
                                int i46;
                                int p_n;
                                int q_n;
                                bool exitg2;
                                d = coordsToUse[0];
                                coordDist_tmp = BoardCoords[((c_ii[0] +
                                  (BoardCoords.size(0) * j)) +
                                  ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                   ((static_cast<int>(coordsToUse[0])) - 1))) -
                                  1];
                                coordDist = (coordDist_tmp - BoardCoords[((c_ii
                                  [1] + (BoardCoords.size(0) * j)) +
                                  ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                   ((static_cast<int>(coordsToUse[0])) - 1))) -
                                             1]) / ((static_cast<double>(c_ii[1]))
                                                    - (static_cast<double>(c_ii
                                  [0])));
                                p_n = 0;
                                i46 = c_ii.size(0);
                                e_this.set_size(c_ii.size(0));
                                f_this.set_size(c_ii.size(0));
                                for (int b_k{0}; b_k < i46; b_k++) {
                                  if (c_ii[b_k] != 0) {
                                    p_n++;
                                  }

                                  e_this[b_k] = BoardCoords[((c_ii[b_k] +
                                    (BoardCoords.size(0) * j)) +
                                    ((BoardCoords.size(0) * BoardCoords.size(1))
                                     * ((static_cast<int>(d)) - 1))) - 1];
                                  f_this[b_k] = BoardCoords[((c_ii[b_k] +
                                    (BoardCoords.size(0) * j)) +
                                    ((BoardCoords.size(0) * BoardCoords.size(1))
                                     * ((static_cast<int>(coordsToUse[1])) - 1)))
                                    - 1];
                                }

                                if (p_n > 5) {
                                  q_n = 4;
                                } else {
                                  q_n = 2;
                                }

                                polyfit(e_this, f_this, static_cast<double>(q_n),
                                        currCurve);
                                currRad = coordDist / 4.0;
                                currCoord = currRad + coordDist_tmp;
                                exitg2 = false;
                                while ((!exitg2) && (std::abs(currCoord -
                                         coordDist_tmp) < (((static_cast<double>
                                    (c_ii[0])) * 1.5) * std::abs(coordDist)))) {
                                  b_dv[0] = 1.0;
                                  b_dv[1] = 2.0;
                                  if (isequal(coordsToUse, b_dv)) {
                                    if (currCurve.size(1) != 0) {
                                      int i67;
                                      b_y = currCurve[0];
                                      i67 = currCurve.size(1);
                                      for (int d_k{0}; d_k <= (i67 - 2); d_k++)
                                      {
                                        b_y = (currCoord * b_y) + currCurve[d_k
                                          + 1];
                                      }
                                    }

                                    currPt[0] = currCoord;
                                    currPt[1] = b_y;
                                  } else {
                                    if (currCurve.size(1) != 0) {
                                      int i66;
                                      y = currCurve[0];
                                      i66 = currCurve.size(1);
                                      for (int c_k{0}; c_k <= (i66 - 2); c_k++)
                                      {
                                        y = (currCoord * y) + currCurve[c_k + 1];
                                      }
                                    }

                                    currPt[0] = y;
                                    currPt[1] = currCoord;
                                  }

                                  findClosestOnCurve(currPt, std::abs(currRad),
                                                     currCurve, coordsToUse,
                                                     removedIdx, b_index);
                                  if (b_index.size(1) != 0) {
                                    int i72;
                                    int vc_loop_ub;
                                    newIndices[j] = b_index[0];
                                    i72 = removedIdx.size(1);
                                    vc_loop_ub = b_index.size(1);
                                    removedIdx.set_size(removedIdx.size(0),
                                                        removedIdx.size(1) +
                                                        b_index.size(1));
                                    for (int i73{0}; i73 < vc_loop_ub; i73++) {
                                      removedIdx[i72 + i73] = b_index[i73];
                                    }

                                    exitg2 = true;
                                  } else {
                                    currCoord += currRad;
                                  }
                                }
                              }
                            }

                            h_n = 0;
                            i19 = newIndices.size(1);
                            for (int k{0}; k < i19; k++) {
                              if (newIndices[k] != 0.0) {
                                h_n++;
                              }
                            }

                            if (h_n < 4) {
                              int end;
                              end = newIndices.size(1);
                              for (int d_i{0}; d_i < end; d_i++) {
                                if (newIndices[d_i] > 0.0) {
                                  newIndices[d_i] = 0.0;
                                }
                              }
                            }
                          } else {
                            int b_end;
                            int d_loop_ub;
                            int fb_loop_ub;
                            int k_loop_ub;
                            int loop_ub;
                            int mc_loop_ub;
                            int ob_loop_ub;
                            int p_loop_ub;
                            int partialTrueCount;
                            int trueCount;
                            int yb_loop_ub;
                            loop_ub = BoardCoords.size(1);
                            d_loop_ub = BoardCoords.size(2);
                            b_this.set_size(1, loop_ub, d_loop_ub);
                            for (int i2{0}; i2 < d_loop_ub; i2++) {
                              for (int i6{0}; i6 < loop_ub; i6++) {
                                b_this[i6 + (b_this.size(1) * i2)] =
                                  BoardCoords[((BoardCoords.size(0) * i6) +
                                               ((BoardCoords.size(0) *
                                                 BoardCoords.size(1)) * i2)) + 1];
                              }
                            }

                            squeeze(b_this, b_p1);
                            k_loop_ub = BoardCoords.size(1);
                            p_loop_ub = BoardCoords.size(2);
                            b_this.set_size(1, k_loop_ub, p_loop_ub);
                            for (int i14{0}; i14 < p_loop_ub; i14++) {
                              for (int i21{0}; i21 < k_loop_ub; i21++) {
                                b_this[i21 + (b_this.size(1) * i14)] =
                                  BoardCoords[(BoardCoords.size(0) * i21) +
                                  ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                   i14)];
                              }
                            }

                            squeeze(b_this, p2);
                            predictedPoints.set_size(p2.size(0), p2.size(1));
                            fb_loop_ub = p2.size(1);
                            for (int i29{0}; i29 < fb_loop_ub; i29++) {
                              int pb_loop_ub;
                              pb_loop_ub = p2.size(0);
                              for (int i38{0}; i38 < pb_loop_ub; i38++) {
                                double b_d1;
                                b_d1 = p2[i38 + (p2.size(0) * i29)];
                                predictedPoints[i38 + (predictedPoints.size(0) *
                                  i29)] = (b_d1 + b_d1) - b_p1[i38 + (b_p1.size
                                  (0) * i29)];
                              }
                            }

                            ob_loop_ub = b_p1.size(0);
                            r2.set_size(b_p1.size(0));
                            for (int i42{0}; i42 < ob_loop_ub; i42++) {
                              r2[i42] = (b_p1[i42] == 0.0);
                            }

                            yb_loop_ub = p2.size(0);
                            r3.set_size(p2.size(0));
                            for (int i50{0}; i50 < yb_loop_ub; i50++) {
                              r3[i50] = (p2[i50] == 0.0);
                            }

                            b_end = r2.size(0) - 1;
                            trueCount = 0;
                            for (int e_i{0}; e_i <= b_end; e_i++) {
                              if ((r2[e_i]) || (r3[e_i])) {
                                trueCount++;
                              }
                            }

                            r4.set_size(trueCount);
                            partialTrueCount = 0;
                            for (int h_i{0}; h_i <= b_end; h_i++) {
                              if ((r2[h_i]) || (r3[h_i])) {
                                r4[partialTrueCount] = h_i + 1;
                                partialTrueCount++;
                              }
                            }

                            mc_loop_ub = predictedPoints.size(1);
                            for (int i62{0}; i62 < mc_loop_ub; i62++) {
                              int pc_loop_ub;
                              pc_loop_ub = r4.size(0);
                              for (int i64{0}; i64 < pc_loop_ub; i64++) {
                                predictedPoints[(r4[i64] + (predictedPoints.size
                                  (0) * i62)) - 1] = rtNaN;
                              }
                            }

                            b_findClosestIndices(predictedPoints, newIndices);
                          }

                          expandBoardUp(newIndices, r, r1);
                          BoardIdx.set_size(r.size(0), r.size(1));
                          ub_loop_ub = r.size(1);
                          for (int i45{0}; i45 < ub_loop_ub; i45++) {
                            int bc_loop_ub;
                            bc_loop_ub = r.size(0);
                            for (int i51{0}; i51 < bc_loop_ub; i51++) {
                              BoardIdx[i51 + (BoardIdx.size(0) * i45)] = r[i51 +
                                (r.size(0) * i45)];
                            }
                          }

                          BoardCoords.set_size(r1.size(0), r1.size(1), r1.size(2));
                          ec_loop_ub = r1.size(2);
                          for (int i54{0}; i54 < ec_loop_ub; i54++) {
                            int hc_loop_ub;
                            hc_loop_ub = r1.size(1);
                            for (int i58{0}; i58 < hc_loop_ub; i58++) {
                              int kc_loop_ub;
                              kc_loop_ub = r1.size(0);
                              for (int i61{0}; i61 < kc_loop_ub; i61++) {
                                BoardCoords[(i61 + (BoardCoords.size(0) * i58))
                                  + ((BoardCoords.size(0) * BoardCoords.size(1))
                                     * i54)] = r1[(i61 + (r1.size(0) * i58)) +
                                  ((r1.size(0) * r1.size(1)) * i54)];
                              }
                            }
                          }

                          newEnergy = computeNewEnergyVertical(oldEnergy);
                        }
                        break;

                       case 2:
                        {
                          int db_loop_ub;
                          int numRows;
                          int qb_loop_ub;
                          int t_loop_ub;
                          numRows = BoardCoords.size(0);
                          if ((static_cast<double>(numRows)) < ((static_cast<
                                double>(numRows)) - 2.0)) {
                            idx.set_size(1, 0);
                          } else {
                            int e_loop_ub;
                            e_loop_ub = static_cast<int>(static_cast<double>
                              (-(((static_cast<double>(numRows)) - 2.0) - (
                              static_cast<double>(numRows)))));
                            idx.set_size(1, e_loop_ub + 1);
                            for (int i4{0}; i4 <= e_loop_ub; i4++) {
                              idx[i4] = (static_cast<double>(numRows)) - (
                                static_cast<double>(i4));
                            }
                          }

                          if (IsDistortionHigh) {
                            c_fitPolynomialIndices(idx, newIndices);
                          } else {
                            int c_idx;
                            int cb_loop_ub;
                            int d_partialTrueCount;
                            int d_trueCount;
                            int e_end;
                            int e_idx;
                            int fc_loop_ub;
                            int gb_loop_ub;
                            int i_loop_ub;
                            int jc_loop_ub;
                            int m_loop_ub;
                            int sc_loop_ub;
                            int xb_loop_ub;
                            c_idx = static_cast<int>(idx[1]);
                            i_loop_ub = BoardCoords.size(1);
                            m_loop_ub = BoardCoords.size(2);
                            b_this.set_size(1, i_loop_ub, m_loop_ub);
                            for (int i11{0}; i11 < m_loop_ub; i11++) {
                              for (int i20{0}; i20 < i_loop_ub; i20++) {
                                b_this[i20 + (b_this.size(1) * i11)] =
                                  BoardCoords[((c_idx + (BoardCoords.size(0) *
                                  i20)) + ((BoardCoords.size(0) *
                                            BoardCoords.size(1)) * i11)) - 1];
                              }
                            }

                            squeeze(b_this, b_p1);
                            e_idx = static_cast<int>(idx[0]);
                            cb_loop_ub = BoardCoords.size(1);
                            gb_loop_ub = BoardCoords.size(2);
                            b_this.set_size(1, cb_loop_ub, gb_loop_ub);
                            for (int i32{0}; i32 < gb_loop_ub; i32++) {
                              for (int i39{0}; i39 < cb_loop_ub; i39++) {
                                b_this[i39 + (b_this.size(1) * i32)] =
                                  BoardCoords[((e_idx + (BoardCoords.size(0) *
                                  i39)) + ((BoardCoords.size(0) *
                                            BoardCoords.size(1)) * i32)) - 1];
                              }
                            }

                            squeeze(b_this, p2);
                            predictedPoints.set_size(p2.size(0), p2.size(1));
                            xb_loop_ub = p2.size(1);
                            for (int i49{0}; i49 < xb_loop_ub; i49++) {
                              int gc_loop_ub;
                              gc_loop_ub = p2.size(0);
                              for (int i55{0}; i55 < gc_loop_ub; i55++) {
                                double d4;
                                d4 = p2[i55 + (p2.size(0) * i49)];
                                predictedPoints[i55 + (predictedPoints.size(0) *
                                  i49)] = (d4 + d4) - b_p1[i55 + (b_p1.size(0) *
                                  i49)];
                              }
                            }

                            fc_loop_ub = b_p1.size(0);
                            r2.set_size(b_p1.size(0));
                            for (int i57{0}; i57 < fc_loop_ub; i57++) {
                              r2[i57] = (b_p1[i57] == 0.0);
                            }

                            jc_loop_ub = p2.size(0);
                            r3.set_size(p2.size(0));
                            for (int i60{0}; i60 < jc_loop_ub; i60++) {
                              r3[i60] = (p2[i60] == 0.0);
                            }

                            e_end = r2.size(0) - 1;
                            d_trueCount = 0;
                            for (int q_i{0}; q_i <= e_end; q_i++) {
                              if ((r2[q_i]) || (r3[q_i])) {
                                d_trueCount++;
                              }
                            }

                            r7.set_size(d_trueCount);
                            d_partialTrueCount = 0;
                            for (int w_i{0}; w_i <= e_end; w_i++) {
                              if ((r2[w_i]) || (r3[w_i])) {
                                r7[d_partialTrueCount] = w_i + 1;
                                d_partialTrueCount++;
                              }
                            }

                            sc_loop_ub = predictedPoints.size(1);
                            for (int i69{0}; i69 < sc_loop_ub; i69++) {
                              int uc_loop_ub;
                              uc_loop_ub = r7.size(0);
                              for (int i71{0}; i71 < uc_loop_ub; i71++) {
                                predictedPoints[(r7[i71] + (predictedPoints.size
                                  (0) * i69)) - 1] = rtNaN;
                              }
                            }

                            b_findClosestIndices(predictedPoints, newIndices);
                          }

                          expandBoardDown(newIndices, r, r1);
                          BoardIdx.set_size(r.size(0), r.size(1));
                          t_loop_ub = r.size(1);
                          for (int i15{0}; i15 < t_loop_ub; i15++) {
                            int x_loop_ub;
                            x_loop_ub = r.size(0);
                            for (int i25{0}; i25 < x_loop_ub; i25++) {
                              BoardIdx[i25 + (BoardIdx.size(0) * i15)] = r[i25 +
                                (r.size(0) * i15)];
                            }
                          }

                          BoardCoords.set_size(r1.size(0), r1.size(1), r1.size(2));
                          db_loop_ub = r1.size(2);
                          for (int i28{0}; i28 < db_loop_ub; i28++) {
                            int kb_loop_ub;
                            kb_loop_ub = r1.size(1);
                            for (int i35{0}; i35 < kb_loop_ub; i35++) {
                              int vb_loop_ub;
                              vb_loop_ub = r1.size(0);
                              for (int i47{0}; i47 < vb_loop_ub; i47++) {
                                BoardCoords[(i47 + (BoardCoords.size(0) * i35))
                                  + ((BoardCoords.size(0) * BoardCoords.size(1))
                                     * i28)] = r1[(i47 + (r1.size(0) * i35)) +
                                  ((r1.size(0) * r1.size(1)) * i28)];
                              }
                            }
                          }

                          idx.set_size(1, idx.size(1));
                          qb_loop_ub = idx.size(1);
                          for (int i40{0}; i40 < qb_loop_ub; i40++) {
                            idx[i40] = idx[i40] + 1.0;
                          }

                          newEnergy = computeNewEnergyVertical(idx, oldEnergy);
                        }
                        break;

                       case 3:
                        {
                          int g_loop_ub;
                          int u_loop_ub;
                          if (IsDistortionHigh) {
                            b_fitPolynomialIndices(newIndices);
                          } else {
                            int ac_loop_ub;
                            int b_loop_ub;
                            int b_partialTrueCount;
                            int b_trueCount;
                            int c_end;
                            int f_loop_ub;
                            int hb_loop_ub;
                            int o_loop_ub;
                            int oc_loop_ub;
                            int q_loop_ub;
                            int rb_loop_ub;
                            b_loop_ub = BoardCoords.size(0);
                            f_loop_ub = BoardCoords.size(2);
                            c_this.set_size(b_loop_ub, 1, f_loop_ub);
                            for (int i5{0}; i5 < f_loop_ub; i5++) {
                              for (int i7{0}; i7 < b_loop_ub; i7++) {
                                c_this[i7 + (c_this.size(0) * i5)] =
                                  BoardCoords[(i7 + BoardCoords.size(0)) +
                                  ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                   i5)];
                              }
                            }

                            b_squeeze(c_this, b_p1);
                            o_loop_ub = BoardCoords.size(0);
                            q_loop_ub = BoardCoords.size(2);
                            c_this.set_size(o_loop_ub, 1, q_loop_ub);
                            for (int i16{0}; i16 < q_loop_ub; i16++) {
                              for (int i23{0}; i23 < o_loop_ub; i23++) {
                                c_this[i23 + (c_this.size(0) * i16)] =
                                  BoardCoords[i23 + ((BoardCoords.size(0) *
                                                      BoardCoords.size(1)) * i16)];
                              }
                            }

                            b_squeeze(c_this, p2);
                            predictedPoints.set_size(p2.size(0), p2.size(1));
                            hb_loop_ub = p2.size(1);
                            for (int i30{0}; i30 < hb_loop_ub; i30++) {
                              int sb_loop_ub;
                              sb_loop_ub = p2.size(0);
                              for (int i41{0}; i41 < sb_loop_ub; i41++) {
                                double d2;
                                d2 = p2[i41 + (p2.size(0) * i30)];
                                predictedPoints[i41 + (predictedPoints.size(0) *
                                  i30)] = (d2 + d2) - b_p1[i41 + (b_p1.size(0) *
                                  i30)];
                              }
                            }

                            rb_loop_ub = b_p1.size(0);
                            r2.set_size(b_p1.size(0));
                            for (int i43{0}; i43 < rb_loop_ub; i43++) {
                              r2[i43] = (b_p1[i43] == 0.0);
                            }

                            ac_loop_ub = p2.size(0);
                            r3.set_size(p2.size(0));
                            for (int i52{0}; i52 < ac_loop_ub; i52++) {
                              r3[i52] = (p2[i52] == 0.0);
                            }

                            c_end = r2.size(0) - 1;
                            b_trueCount = 0;
                            for (int g_i{0}; g_i <= c_end; g_i++) {
                              if ((r2[g_i]) || (r3[g_i])) {
                                b_trueCount++;
                              }
                            }

                            r5.set_size(b_trueCount);
                            b_partialTrueCount = 0;
                            for (int k_i{0}; k_i <= c_end; k_i++) {
                              if ((r2[k_i]) || (r3[k_i])) {
                                r5[b_partialTrueCount] = k_i + 1;
                                b_partialTrueCount++;
                              }
                            }

                            oc_loop_ub = predictedPoints.size(1);
                            for (int i63{0}; i63 < oc_loop_ub; i63++) {
                              int qc_loop_ub;
                              qc_loop_ub = r5.size(0);
                              for (int i65{0}; i65 < qc_loop_ub; i65++) {
                                predictedPoints[(r5[i65] + (predictedPoints.size
                                  (0) * i63)) - 1] = rtNaN;
                              }
                            }

                            b_findClosestIndices(predictedPoints, newIndices);
                          }

                          expandBoardLeft(newIndices, r, r1);
                          BoardIdx.set_size(r.size(0), r.size(1));
                          g_loop_ub = r.size(1);
                          for (int b_i8{0}; b_i8 < g_loop_ub; b_i8++) {
                            int r_loop_ub;
                            r_loop_ub = r.size(0);
                            for (int i12{0}; i12 < r_loop_ub; i12++) {
                              BoardIdx[i12 + (BoardIdx.size(0) * b_i8)] = r[i12
                                + (r.size(0) * b_i8)];
                            }
                          }

                          BoardCoords.set_size(r1.size(0), r1.size(1), r1.size(2));
                          u_loop_ub = r1.size(2);
                          for (int i17{0}; i17 < u_loop_ub; i17++) {
                            int y_loop_ub;
                            y_loop_ub = r1.size(1);
                            for (int i26{0}; i26 < y_loop_ub; i26++) {
                              int ib_loop_ub;
                              ib_loop_ub = r1.size(0);
                              for (int i33{0}; i33 < ib_loop_ub; i33++) {
                                BoardCoords[(i33 + (BoardCoords.size(0) * i26))
                                  + ((BoardCoords.size(0) * BoardCoords.size(1))
                                     * i17)] = r1[(i33 + (r1.size(0) * i26)) +
                                  ((r1.size(0) * r1.size(1)) * i17)];
                              }
                            }
                          }

                          newEnergy = computeNewEnergyHorizontal(oldEnergy);
                        }
                        break;

                       default:
                        {
                          int bb_loop_ub;
                          int mb_loop_ub;
                          int numCols;
                          int s_loop_ub;
                          numCols = BoardCoords.size(1);
                          if ((static_cast<double>(numCols)) < ((static_cast<
                                double>(numCols)) - 2.0)) {
                            idx.set_size(1, 0);
                          } else {
                            int c_loop_ub;
                            c_loop_ub = static_cast<int>(static_cast<double>
                              (-(((static_cast<double>(numCols)) - 2.0) - (
                              static_cast<double>(numCols)))));
                            idx.set_size(1, c_loop_ub + 1);
                            for (int i1{0}; i1 <= c_loop_ub; i1++) {
                              idx[i1] = (static_cast<double>(numCols)) - (
                                static_cast<double>(i1));
                            }
                          }

                          if (IsDistortionHigh) {
                            d_fitPolynomialIndices(idx, newIndices);
                          } else {
                            int ab_loop_ub;
                            int b_idx;
                            int c_partialTrueCount;
                            int c_trueCount;
                            int cc_loop_ub;
                            int d_end;
                            int d_idx;
                            int eb_loop_ub;
                            int h_loop_ub;
                            int ic_loop_ub;
                            int j_loop_ub;
                            int rc_loop_ub;
                            int wb_loop_ub;
                            b_idx = static_cast<int>(idx[1]);
                            h_loop_ub = BoardCoords.size(0);
                            j_loop_ub = BoardCoords.size(2);
                            c_this.set_size(h_loop_ub, 1, j_loop_ub);
                            for (int i10{0}; i10 < j_loop_ub; i10++) {
                              for (int i18{0}; i18 < h_loop_ub; i18++) {
                                c_this[i18 + (c_this.size(0) * i10)] =
                                  BoardCoords[(i18 + (BoardCoords.size(0) *
                                                      (b_idx - 1))) +
                                  ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                   i10)];
                              }
                            }

                            b_squeeze(c_this, b_p1);
                            d_idx = static_cast<int>(idx[0]);
                            ab_loop_ub = BoardCoords.size(0);
                            eb_loop_ub = BoardCoords.size(2);
                            c_this.set_size(ab_loop_ub, 1, eb_loop_ub);
                            for (int i31{0}; i31 < eb_loop_ub; i31++) {
                              for (int i36{0}; i36 < ab_loop_ub; i36++) {
                                c_this[i36 + (c_this.size(0) * i31)] =
                                  BoardCoords[(i36 + (BoardCoords.size(0) *
                                                      (d_idx - 1))) +
                                  ((BoardCoords.size(0) * BoardCoords.size(1)) *
                                   i31)];
                              }
                            }

                            b_squeeze(c_this, p2);
                            predictedPoints.set_size(p2.size(0), p2.size(1));
                            wb_loop_ub = p2.size(1);
                            for (int i48{0}; i48 < wb_loop_ub; i48++) {
                              int dc_loop_ub;
                              dc_loop_ub = p2.size(0);
                              for (int i53{0}; i53 < dc_loop_ub; i53++) {
                                double d3;
                                d3 = p2[i53 + (p2.size(0) * i48)];
                                predictedPoints[i53 + (predictedPoints.size(0) *
                                  i48)] = (d3 + d3) - b_p1[i53 + (b_p1.size(0) *
                                  i48)];
                              }
                            }

                            cc_loop_ub = b_p1.size(0);
                            r2.set_size(b_p1.size(0));
                            for (int i56{0}; i56 < cc_loop_ub; i56++) {
                              r2[i56] = (b_p1[i56] == 0.0);
                            }

                            ic_loop_ub = p2.size(0);
                            r3.set_size(p2.size(0));
                            for (int i59{0}; i59 < ic_loop_ub; i59++) {
                              r3[i59] = (p2[i59] == 0.0);
                            }

                            d_end = r2.size(0) - 1;
                            c_trueCount = 0;
                            for (int m_i{0}; m_i <= d_end; m_i++) {
                              if ((r2[m_i]) || (r3[m_i])) {
                                c_trueCount++;
                              }
                            }

                            r6.set_size(c_trueCount);
                            c_partialTrueCount = 0;
                            for (int t_i{0}; t_i <= d_end; t_i++) {
                              if ((r2[t_i]) || (r3[t_i])) {
                                r6[c_partialTrueCount] = t_i + 1;
                                c_partialTrueCount++;
                              }
                            }

                            rc_loop_ub = predictedPoints.size(1);
                            for (int i68{0}; i68 < rc_loop_ub; i68++) {
                              int tc_loop_ub;
                              tc_loop_ub = r6.size(0);
                              for (int i70{0}; i70 < tc_loop_ub; i70++) {
                                predictedPoints[(r6[i70] + (predictedPoints.size
                                  (0) * i68)) - 1] = rtNaN;
                              }
                            }

                            b_findClosestIndices(predictedPoints, newIndices);
                          }

                          expandBoardRight(newIndices, r, r1);
                          BoardIdx.set_size(r.size(0), r.size(1));
                          s_loop_ub = r.size(1);
                          for (int i13{0}; i13 < s_loop_ub; i13++) {
                            int w_loop_ub;
                            w_loop_ub = r.size(0);
                            for (int i24{0}; i24 < w_loop_ub; i24++) {
                              BoardIdx[i24 + (BoardIdx.size(0) * i13)] = r[i24 +
                                (r.size(0) * i13)];
                            }
                          }

                          BoardCoords.set_size(r1.size(0), r1.size(1), r1.size(2));
                          bb_loop_ub = r1.size(2);
                          for (int i27{0}; i27 < bb_loop_ub; i27++) {
                            int jb_loop_ub;
                            jb_loop_ub = r1.size(1);
                            for (int i34{0}; i34 < jb_loop_ub; i34++) {
                              int tb_loop_ub;
                              tb_loop_ub = r1.size(0);
                              for (int i44{0}; i44 < tb_loop_ub; i44++) {
                                BoardCoords[(i44 + (BoardCoords.size(0) * i34))
                                  + ((BoardCoords.size(0) * BoardCoords.size(1))
                                     * i27)] = r1[(i44 + (r1.size(0) * i34)) +
                                  ((r1.size(0) * r1.size(1)) * i27)];
                              }
                            }
                          }

                          idx.set_size(1, idx.size(1));
                          mb_loop_ub = idx.size(1);
                          for (int i37{0}; i37 < mb_loop_ub; i37++) {
                            idx[i37] = idx[i37] + 1.0;
                          }

                          newEnergy = computeNewEnergyHorizontal(idx, oldEnergy);
                        }
                        break;
                      }

                      Energy = newEnergy;
                      if (Energy < PreviousEnergy) {
                        exitg1 = 1;
                      } else {
                        undoLastExpansion();
                        IsDirectionBad[c_i] = true;
                        c_i++;
                      }
                    } else {
                      c_i++;
                    }
                  } else {
                    hasExpanded = false;
                    exitg1 = 1;
                  }
                } while (exitg1 == 0);
              }
            }

            //
            // Arguments    : double seedIdx
            //                const ::coder::array<float, 2U> &b_points
            //                const float e_v1[2]
            //                const float v2[2]
            // Return Type  : void
            //
            void b_Checkerboard::initialize(double seedIdx, const ::coder::array<
              float, 2U> &b_points, const float e_v1[2], const float v2[2])
            {
              ::coder::array<double, 2U> r1;
              ::coder::array<float, 2U> b_down;
              ::coder::array<float, 2U> b_up;
              ::coder::array<float, 2U> c_r;
              ::coder::array<float, 2U> c_u;
              ::coder::array<float, 2U> center;
              ::coder::array<float, 2U> col1;
              ::coder::array<float, 2U> col2;
              ::coder::array<float, 2U> col3;
              ::coder::array<float, 2U> d;
              ::coder::array<float, 2U> denom;
              ::coder::array<float, 2U> down;
              ::coder::array<float, 2U> fb_l;
              ::coder::array<float, 2U> left;
              ::coder::array<float, 2U> num;
              ::coder::array<float, 2U> pointVectors;
              ::coder::array<float, 2U> right;
              ::coder::array<float, 2U> row1;
              ::coder::array<float, 2U> row2;
              ::coder::array<float, 2U> row3;
              ::coder::array<float, 2U> up;
              ::coder::array<float, 1U> b_pointVectors;
              ::coder::array<float, 1U> c_pointVectors;
              ::coder::array<float, 1U> euclideanDists;
              ::coder::array<int, 1U> r;
              ::coder::array<bool, 1U> b_x;
              float b_z1[3];
              float z1[3];
              float c_v2[2];
              float f_v1[2];
              int b_acoef;
              int b_i8;
              int b_k;
              int b_loop_ub;
              int b_seedIdx;
              int b_this;
              int b_u0;
              int b_u1;
              int b_y;
              int c_k;
              int c_loop_ub;
              int c_u1;
              int csz_idx_1;
              int d_loop_ub;
              int e_loop_ub;
              int f_loop_ub;
              int g_loop_ub;
              int h_loop_ub;
              int i11;
              int i_loop_ub;
              int j_loop_ub;
              int k_loop_ub;
              int loop_ub;
              int u0;
              int varargin_2;
              int varargin_3;
              int y;
              bool exitg1;
              bool varargout_1;
              BoardIdx.set_size(1, 1);
              BoardIdx[0] = 0.0;
              BoardIdx.set_size(3, 3);

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

              for (int b_i = 0; b_i < 3; b_i++) {
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
                  BoardCoords[(BoardCoords.size(0) * i3) + ((BoardCoords.size(0)
                    * BoardCoords.size(1)) * i2)] = 0.0;
                  BoardCoords[((BoardCoords.size(0) * i3) + ((BoardCoords.size(0)
                    * BoardCoords.size(1)) * i2)) + 1] = 0.0;
                  BoardCoords[((BoardCoords.size(0) * i3) + ((BoardCoords.size(0)
                    * BoardCoords.size(1)) * i2)) + 2] = 0.0;
                }

                for (int i4{0}; i4 < loop_ub; i4++) {
                  Points[i4 + (Points.size(0) * i2)] = b_points[i4 +
                    (b_points.size(0) * i2)];
                }
              }

              b_seedIdx = static_cast<int>(seedIdx);
              b_loop_ub = Points.size(1);
              center.set_size(1, b_loop_ub);
              c_loop_ub = b_loop_ub;
              if ((static_cast<int>(b_loop_ub < 4)) != 0) {
                for (int i5{0}; i5 < b_loop_ub; i5++) {
                  center[i5] = Points[((static_cast<int>(seedIdx)) +
                                       (Points.size(0) * i5)) - 1];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i5 = 0; i5 < c_loop_ub; i5++) {
                  center[i5] = Points[(b_seedIdx + (Points.size(0) * i5)) - 1];
                }
              }

              BoardIdx[BoardIdx.size(0) + 1] = seedIdx;
              d_loop_ub = BoardCoords.size(2);
              r.set_size(d_loop_ub);
              e_loop_ub = d_loop_ub;
              if ((static_cast<int>(d_loop_ub < 4)) != 0) {
                for (int i6{0}; i6 < d_loop_ub; i6++) {
                  r[i6] = i6;
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i6 = 0; i6 < e_loop_ub; i6++) {
                  r[i6] = i6;
                }
              }

              f_loop_ub = r.size(0);
              for (int i7{0}; i7 < f_loop_ub; i7++) {
                BoardCoords[(BoardCoords.size(0) + ((BoardCoords.size(0) *
                  BoardCoords.size(1)) * r[i7])) + 1] = static_cast<double>
                  (center[i7]);
              }

              LastExpandDirection = 1.0;
              PreviousEnergy = rtInfF;
              isValid = false;
              u0 = center.size(1);
              b_u1 = Points.size(1);
              if (u0 <= b_u1) {
                y = u0;
              } else {
                y = b_u1;
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
              c_u1 = Points.size(1);
              if (b_u0 <= c_u1) {
                b_y = b_u0;
              } else {
                b_y = c_u1;
              }

              if (center.size(1) == 1) {
                b_i8 = Points.size(1);
              } else if (Points.size(1) == 1) {
                b_i8 = center.size(1);
              } else if (Points.size(1) == center.size(1)) {
                b_i8 = Points.size(1);
              } else {
                b_i8 = b_y;
              }

              pointVectors.set_size(Points.size(0), b_i8);
              if ((Points.size(0) != 0) && (csz_idx_1 != 0)) {
                int acoef;
                int bcoef;
                int i9;
                acoef = static_cast<int>(Points.size(1) != 1);
                bcoef = static_cast<int>(center.size(1) != 1);
                i9 = csz_idx_1 - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(b_k,i11,b_acoef,varargin_3,varargin_2)

                for (int k = 0; k <= i9; k++) {
                  varargin_2 = acoef * k;
                  varargin_3 = bcoef * k;
                  b_acoef = static_cast<int>(Points.size(0) != 1);
                  i11 = pointVectors.size(0) - 1;
                  for (b_k = 0; b_k <= i11; b_k++) {
                    pointVectors[b_k + (pointVectors.size(0) * k)] = Points
                      [(b_acoef * b_k) + (Points.size(0) * varargin_2)] -
                      center[varargin_3];
                  }
                }
              }

              g_loop_ub = pointVectors.size(0);
              b_pointVectors.set_size(pointVectors.size(0));
              h_loop_ub = pointVectors.size(0);
              if ((static_cast<int>(pointVectors.size(0) < 4)) != 0) {
                for (int i10{0}; i10 < g_loop_ub; i10++) {
                  b_pointVectors[i10] = pointVectors[i10];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i10 = 0; i10 < h_loop_ub; i10++) {
                  b_pointVectors[i10] = pointVectors[i10];
                }
              }

              i_loop_ub = pointVectors.size(0);
              c_pointVectors.set_size(pointVectors.size(0));
              j_loop_ub = pointVectors.size(0);
              if ((static_cast<int>(pointVectors.size(0) < 4)) != 0) {
                for (int i12{0}; i12 < i_loop_ub; i12++) {
                  c_pointVectors[i12] = pointVectors[i12 + pointVectors.size(0)];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i12 = 0; i12 < j_loop_ub; i12++) {
                  c_pointVectors[i12] = pointVectors[i12 + pointVectors.size(0)];
                }
              }

              b_hypot(b_pointVectors, c_pointVectors, euclideanDists);
              BoardIdx[(BoardIdx.size(0) * 2) + 1] = findNeighbor(pointVectors,
                euclideanDists, e_v1);
              f_v1[0] = -e_v1[0];
              f_v1[1] = -e_v1[1];
              BoardIdx[1] = findNeighbor(pointVectors, euclideanDists, f_v1);
              BoardIdx[BoardIdx.size(0) + 2] = findNeighbor(pointVectors,
                euclideanDists, v2);
              c_v2[0] = -v2[0];
              c_v2[1] = -v2[1];
              BoardIdx[BoardIdx.size(0)] = findNeighbor(pointVectors,
                euclideanDists, c_v2);
              b_this = BoardIdx.size(0) * BoardIdx.size(1);
              b_x.set_size(b_this);
              k_loop_ub = b_this;
              if ((static_cast<int>(b_this < 4)) != 0) {
                for (int i13{0}; i13 < b_this; i13++) {
                  b_x[i13] = (BoardIdx[i13] < 0.0);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i13 = 0; i13 < k_loop_ub; i13++) {
                  b_x[i13] = (BoardIdx[i13] < 0.0);
                }
              }

              varargout_1 = false;
              c_k = 0;
              exitg1 = false;
              while ((!exitg1) && (c_k <= (b_x.size(0) - 1))) {
                if (b_x[c_k]) {
                  varargout_1 = true;
                  exitg1 = true;
                } else {
                  c_k++;
                }
              }

              if (varargout_1) {
                isValid = false;
              } else {
                int ab_loop_ub;
                int bb_loop_ub;
                int c_this;
                int cb_loop_ub;
                int d_k;
                int db_loop_ub;
                int e_this;
                int eb_loop_ub;
                int f_this;
                int fb_loop_ub;
                int g_this;
                int gb_loop_ub;
                int hb_loop_ub;
                int ib_loop_ub;
                int jb_loop_ub;
                int kb_loop_ub;
                int m_loop_ub;
                int mb_loop_ub;
                int o_loop_ub;
                int ob_loop_ub;
                int p_loop_ub;
                int pb_loop_ub;
                int q_loop_ub;
                int qb_loop_ub;
                int r_loop_ub;
                int rb_loop_ub;
                int s_loop_ub;
                int sb_loop_ub;
                int t_loop_ub;
                int u_loop_ub;
                int v_loop_ub;
                int w_loop_ub;
                int x_loop_ub;
                int y_loop_ub;
                c_this = static_cast<int>(BoardIdx[(BoardIdx.size(0) * 2) + 1]);
                m_loop_ub = Points.size(1);
                c_r.set_size(1, m_loop_ub);
                o_loop_ub = m_loop_ub;
                if ((static_cast<int>(m_loop_ub < 4)) != 0) {
                  for (int i14{0}; i14 < m_loop_ub; i14++) {
                    c_r[i14] = Points[(c_this + (Points.size(0) * i14)) - 1];
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int i14 = 0; i14 < o_loop_ub; i14++) {
                    c_r[i14] = Points[(c_this + (Points.size(0) * i14)) - 1];
                  }
                }

                p_loop_ub = BoardCoords.size(2);
                r.set_size(p_loop_ub);
                q_loop_ub = p_loop_ub;
                if ((static_cast<int>(p_loop_ub < 4)) != 0) {
                  for (int i15{0}; i15 < p_loop_ub; i15++) {
                    r[i15] = i15;
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int i15 = 0; i15 < q_loop_ub; i15++) {
                    r[i15] = i15;
                  }
                }

                r_loop_ub = r.size(0);
                for (int i16{0}; i16 < r_loop_ub; i16++) {
                  BoardCoords[((BoardCoords.size(0) * 2) + ((BoardCoords.size(0)
                    * BoardCoords.size(1)) * r[i16])) + 1] = static_cast<double>
                    (c_r[i16]);
                }

                e_this = static_cast<int>(BoardIdx[1]);
                s_loop_ub = Points.size(1);
                fb_l.set_size(1, s_loop_ub);
                t_loop_ub = s_loop_ub;
                if ((static_cast<int>(s_loop_ub < 4)) != 0) {
                  for (int i17{0}; i17 < s_loop_ub; i17++) {
                    fb_l[i17] = Points[(e_this + (Points.size(0) * i17)) - 1];
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int i17 = 0; i17 < t_loop_ub; i17++) {
                    fb_l[i17] = Points[(e_this + (Points.size(0) * i17)) - 1];
                  }
                }

                u_loop_ub = BoardCoords.size(2);
                r.set_size(u_loop_ub);
                v_loop_ub = u_loop_ub;
                if ((static_cast<int>(u_loop_ub < 4)) != 0) {
                  for (int i18{0}; i18 < u_loop_ub; i18++) {
                    r[i18] = i18;
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int i18 = 0; i18 < v_loop_ub; i18++) {
                    r[i18] = i18;
                  }
                }

                w_loop_ub = r.size(0);
                for (int i19{0}; i19 < w_loop_ub; i19++) {
                  BoardCoords[((BoardCoords.size(0) * BoardCoords.size(1)) *
                               r[i19]) + 1] = static_cast<double>(fb_l[i19]);
                }

                f_this = static_cast<int>(BoardIdx[BoardIdx.size(0) + 2]);
                x_loop_ub = Points.size(1);
                d.set_size(1, x_loop_ub);
                y_loop_ub = x_loop_ub;
                if ((static_cast<int>(x_loop_ub < 4)) != 0) {
                  for (int i20{0}; i20 < x_loop_ub; i20++) {
                    d[i20] = Points[(f_this + (Points.size(0) * i20)) - 1];
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int i20 = 0; i20 < y_loop_ub; i20++) {
                    d[i20] = Points[(f_this + (Points.size(0) * i20)) - 1];
                  }
                }

                ab_loop_ub = BoardCoords.size(2);
                r.set_size(ab_loop_ub);
                bb_loop_ub = ab_loop_ub;
                if ((static_cast<int>(ab_loop_ub < 4)) != 0) {
                  for (int i21{0}; i21 < ab_loop_ub; i21++) {
                    r[i21] = i21;
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int i21 = 0; i21 < bb_loop_ub; i21++) {
                    r[i21] = i21;
                  }
                }

                cb_loop_ub = r.size(0);
                for (int i22{0}; i22 < cb_loop_ub; i22++) {
                  BoardCoords[(BoardCoords.size(0) + ((BoardCoords.size(0) *
                    BoardCoords.size(1)) * r[i22])) + 2] = static_cast<double>
                    (d[i22]);
                }

                g_this = static_cast<int>(BoardIdx[BoardIdx.size(0)]);
                db_loop_ub = Points.size(1);
                c_u.set_size(1, db_loop_ub);
                eb_loop_ub = db_loop_ub;
                if ((static_cast<int>(db_loop_ub < 4)) != 0) {
                  for (int i23{0}; i23 < db_loop_ub; i23++) {
                    c_u[i23] = Points[(g_this + (Points.size(0) * i23)) - 1];
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int i23 = 0; i23 < eb_loop_ub; i23++) {
                    c_u[i23] = Points[(g_this + (Points.size(0) * i23)) - 1];
                  }
                }

                fb_loop_ub = BoardCoords.size(2);
                r.set_size(fb_loop_ub);
                gb_loop_ub = fb_loop_ub;
                if ((static_cast<int>(fb_loop_ub < 4)) != 0) {
                  for (int i24{0}; i24 < fb_loop_ub; i24++) {
                    r[i24] = i24;
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int i24 = 0; i24 < gb_loop_ub; i24++) {
                    r[i24] = i24;
                  }
                }

                hb_loop_ub = r.size(0);
                for (int i25{0}; i25 < hb_loop_ub; i25++) {
                  BoardCoords[BoardCoords.size(0) + ((BoardCoords.size(0) *
                    BoardCoords.size(1)) * r[i25])] = static_cast<double>
                    (c_u[i25]);
                }

                up.set_size(1, c_u.size(1));
                ib_loop_ub = c_u.size(1);
                if ((static_cast<int>(c_u.size(1) < 4)) != 0) {
                  for (int i26{0}; i26 < ib_loop_ub; i26++) {
                    up[i26] = c_u[i26] - center[i26];
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int i26 = 0; i26 < ib_loop_ub; i26++) {
                    up[i26] = c_u[i26] - center[i26];
                  }
                }

                down.set_size(1, d.size(1));
                jb_loop_ub = d.size(1);
                if ((static_cast<int>(d.size(1) < 4)) != 0) {
                  for (int i27{0}; i27 < jb_loop_ub; i27++) {
                    down[i27] = d[i27] - center[i27];
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int i27 = 0; i27 < jb_loop_ub; i27++) {
                    down[i27] = d[i27] - center[i27];
                  }
                }

                right.set_size(1, c_r.size(1));
                kb_loop_ub = c_r.size(1);
                if ((static_cast<int>(c_r.size(1) < 4)) != 0) {
                  for (int i28{0}; i28 < kb_loop_ub; i28++) {
                    right[i28] = c_r[i28] - center[i28];
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int i28 = 0; i28 < kb_loop_ub; i28++) {
                    right[i28] = c_r[i28] - center[i28];
                  }
                }

                left.set_size(1, fb_l.size(1));
                mb_loop_ub = fb_l.size(1);
                if ((static_cast<int>(fb_l.size(1) < 4)) != 0) {
                  for (int i29{0}; i29 < mb_loop_ub; i29++) {
                    left[i29] = fb_l[i29] - center[i29];
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int i29 = 0; i29 < mb_loop_ub; i29++) {
                    left[i29] = fb_l[i29] - center[i29];
                  }
                }

                b_up.set_size(1, up.size(1));
                ob_loop_ub = up.size(1);
                if ((static_cast<int>(up.size(1) < 4)) != 0) {
                  for (int i30{0}; i30 < ob_loop_ub; i30++) {
                    b_up[i30] = up[i30] + left[i30];
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int i30 = 0; i30 < ob_loop_ub; i30++) {
                    b_up[i30] = up[i30] + left[i30];
                  }
                }

                BoardIdx[0] = findNeighbor(pointVectors, euclideanDists, b_up);
                b_down.set_size(1, down.size(1));
                pb_loop_ub = down.size(1);
                if ((static_cast<int>(down.size(1) < 4)) != 0) {
                  for (int i31{0}; i31 < pb_loop_ub; i31++) {
                    b_down[i31] = down[i31] + left[i31];
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int i31 = 0; i31 < pb_loop_ub; i31++) {
                    b_down[i31] = down[i31] + left[i31];
                  }
                }

                BoardIdx[2] = findNeighbor(pointVectors, euclideanDists, b_down);
                down.set_size(1, down.size(1));
                qb_loop_ub = down.size(1);
                if ((static_cast<int>(down.size(1) < 4)) != 0) {
                  for (int i32{0}; i32 < qb_loop_ub; i32++) {
                    down[i32] = down[i32] + right[i32];
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int i32 = 0; i32 < qb_loop_ub; i32++) {
                    down[i32] = down[i32] + right[i32];
                  }
                }

                BoardIdx[(BoardIdx.size(0) * 2) + 2] = findNeighbor(pointVectors,
                  euclideanDists, down);
                up.set_size(1, up.size(1));
                rb_loop_ub = up.size(1);
                if ((static_cast<int>(up.size(1) < 4)) != 0) {
                  for (int i33{0}; i33 < rb_loop_ub; i33++) {
                    up[i33] = up[i33] + right[i33];
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int i33 = 0; i33 < rb_loop_ub; i33++) {
                    up[i33] = up[i33] + right[i33];
                  }
                }

                BoardIdx[BoardIdx.size(0) * 2] = findNeighbor(pointVectors,
                  euclideanDists, up);
                b_this = BoardIdx.size(0) * BoardIdx.size(1);
                b_x.set_size(b_this);
                sb_loop_ub = b_this;
                if ((static_cast<int>(b_this < 4)) != 0) {
                  for (int i34{0}; i34 < b_this; i34++) {
                    b_x[i34] = (BoardIdx[i34] > 0.0);
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int i34 = 0; i34 < sb_loop_ub; i34++) {
                    b_x[i34] = (BoardIdx[i34] > 0.0);
                  }
                }

                isValid = true;
                d_k = 0;
                exitg1 = false;
                while ((!exitg1) && (d_k <= (b_x.size(0) - 1))) {
                  if (!b_x[d_k]) {
                    isValid = false;
                    exitg1 = true;
                  } else {
                    d_k++;
                  }
                }

                if (isValid) {
                  float e;
                  int ac_loop_ub;
                  int bc_loop_ub;
                  int cc_loop_ub;
                  int dc_loop_ub;
                  int e_k;
                  int ec_loop_ub;
                  int fc_loop_ub;
                  int gc_loop_ub;
                  int h_this;
                  int hc_loop_ub;
                  int i_this;
                  int ic_loop_ub;
                  int j_this;
                  int jc_loop_ub;
                  int k_this;
                  int kc_loop_ub;
                  int m_this;
                  int mc_loop_ub;
                  int oc_loop_ub;
                  int pc_loop_ub;
                  int qc_loop_ub;
                  int tb_loop_ub;
                  int ub_loop_ub;
                  int vb_loop_ub;
                  int wb_loop_ub;
                  int xb_loop_ub;
                  int yb_loop_ub;
                  bool b_varargout_1;
                  tb_loop_ub = BoardCoords.size(2);
                  r.set_size(tb_loop_ub);
                  ub_loop_ub = tb_loop_ub;
                  if ((static_cast<int>(tb_loop_ub < 4)) != 0) {
                    for (int i35{0}; i35 < tb_loop_ub; i35++) {
                      r[i35] = i35;
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i35 = 0; i35 < ub_loop_ub; i35++) {
                      r[i35] = i35;
                    }
                  }

                  h_this = static_cast<int>(BoardIdx[0]);
                  vb_loop_ub = Points.size(1);
                  r1.set_size(1, vb_loop_ub);
                  wb_loop_ub = vb_loop_ub;
                  if ((static_cast<int>(vb_loop_ub < 4)) != 0) {
                    for (int i36{0}; i36 < vb_loop_ub; i36++) {
                      r1[i36] = static_cast<double>(Points[(h_this +
                        (Points.size(0) * i36)) - 1]);
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i36 = 0; i36 < wb_loop_ub; i36++) {
                      r1[i36] = static_cast<double>(Points[(h_this +
                        (Points.size(0) * i36)) - 1]);
                    }
                  }

                  xb_loop_ub = r.size(0);
                  for (int i37{0}; i37 < xb_loop_ub; i37++) {
                    BoardCoords[(BoardCoords.size(0) * BoardCoords.size(1)) *
                      r[i37]] = r1[i37];
                  }

                  yb_loop_ub = BoardCoords.size(2);
                  r.set_size(yb_loop_ub);
                  ac_loop_ub = yb_loop_ub;
                  if ((static_cast<int>(yb_loop_ub < 4)) != 0) {
                    for (int i38{0}; i38 < yb_loop_ub; i38++) {
                      r[i38] = i38;
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i38 = 0; i38 < ac_loop_ub; i38++) {
                      r[i38] = i38;
                    }
                  }

                  i_this = static_cast<int>(BoardIdx[2]);
                  bc_loop_ub = Points.size(1);
                  r1.set_size(1, bc_loop_ub);
                  cc_loop_ub = bc_loop_ub;
                  if ((static_cast<int>(bc_loop_ub < 4)) != 0) {
                    for (int i39{0}; i39 < bc_loop_ub; i39++) {
                      r1[i39] = static_cast<double>(Points[(i_this +
                        (Points.size(0) * i39)) - 1]);
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i39 = 0; i39 < cc_loop_ub; i39++) {
                      r1[i39] = static_cast<double>(Points[(i_this +
                        (Points.size(0) * i39)) - 1]);
                    }
                  }

                  dc_loop_ub = r.size(0);
                  for (int i40{0}; i40 < dc_loop_ub; i40++) {
                    BoardCoords[((BoardCoords.size(0) * BoardCoords.size(1)) *
                                 r[i40]) + 2] = r1[i40];
                  }

                  ec_loop_ub = BoardCoords.size(2);
                  r.set_size(ec_loop_ub);
                  fc_loop_ub = ec_loop_ub;
                  if ((static_cast<int>(ec_loop_ub < 4)) != 0) {
                    for (int i41{0}; i41 < ec_loop_ub; i41++) {
                      r[i41] = i41;
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i41 = 0; i41 < fc_loop_ub; i41++) {
                      r[i41] = i41;
                    }
                  }

                  j_this = static_cast<int>(BoardIdx[(BoardIdx.size(0) * 2) + 2]);
                  gc_loop_ub = Points.size(1);
                  r1.set_size(1, gc_loop_ub);
                  hc_loop_ub = gc_loop_ub;
                  if ((static_cast<int>(gc_loop_ub < 4)) != 0) {
                    for (int i42{0}; i42 < gc_loop_ub; i42++) {
                      r1[i42] = static_cast<double>(Points[(j_this +
                        (Points.size(0) * i42)) - 1]);
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i42 = 0; i42 < hc_loop_ub; i42++) {
                      r1[i42] = static_cast<double>(Points[(j_this +
                        (Points.size(0) * i42)) - 1]);
                    }
                  }

                  ic_loop_ub = r.size(0);
                  for (int i43{0}; i43 < ic_loop_ub; i43++) {
                    BoardCoords[((BoardCoords.size(0) * 2) + ((BoardCoords.size
                      (0) * BoardCoords.size(1)) * r[i43])) + 2] = r1[i43];
                  }

                  jc_loop_ub = BoardCoords.size(2);
                  r.set_size(jc_loop_ub);
                  kc_loop_ub = jc_loop_ub;
                  if ((static_cast<int>(jc_loop_ub < 4)) != 0) {
                    for (int i44{0}; i44 < jc_loop_ub; i44++) {
                      r[i44] = i44;
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i44 = 0; i44 < kc_loop_ub; i44++) {
                      r[i44] = i44;
                    }
                  }

                  k_this = static_cast<int>(BoardIdx[BoardIdx.size(0) * 2]);
                  mc_loop_ub = Points.size(1);
                  r1.set_size(1, mc_loop_ub);
                  oc_loop_ub = mc_loop_ub;
                  if ((static_cast<int>(mc_loop_ub < 4)) != 0) {
                    for (int i45{0}; i45 < mc_loop_ub; i45++) {
                      r1[i45] = static_cast<double>(Points[(k_this +
                        (Points.size(0) * i45)) - 1]);
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i45 = 0; i45 < oc_loop_ub; i45++) {
                      r1[i45] = static_cast<double>(Points[(k_this +
                        (Points.size(0) * i45)) - 1]);
                    }
                  }

                  pc_loop_ub = r.size(0);
                  for (int i46{0}; i46 < pc_loop_ub; i46++) {
                    BoardCoords[(BoardCoords.size(0) * 2) + ((BoardCoords.size(0)
                      * BoardCoords.size(1)) * r[i46])] = r1[i46];
                  }

                  b_this = BoardIdx.size(0) * BoardIdx.size(1);
                  b_x.set_size(b_this);
                  qc_loop_ub = b_this;
                  if ((static_cast<int>(b_this < 4)) != 0) {
                    for (int i47{0}; i47 < b_this; i47++) {
                      b_x[i47] = (BoardIdx[i47] < 0.0);
                    }
                  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                    for (int i47 = 0; i47 < qc_loop_ub; i47++) {
                      b_x[i47] = (BoardIdx[i47] < 0.0);
                    }
                  }

                  b_varargout_1 = false;
                  e_k = 0;
                  exitg1 = false;
                  while ((!exitg1) && (e_k <= (b_x.size(0) - 1))) {
                    if (b_x[e_k]) {
                      b_varargout_1 = true;
                      exitg1 = true;
                    } else {
                      e_k++;
                    }
                  }

                  if (b_varargout_1) {
                    e = rtInfF;
                  } else {
                    float boardSize;
                    float z1_idx_0;
                    float z1_idx_1;
                    float z1_idx_2;
                    int ad_loop_ub;
                    int bd_loop_ub;
                    int cd_loop_ub;
                    int dd_loop_ub;
                    int ed_loop_ub;
                    int fd_loop_ub;
                    int gd_loop_ub;
                    int hd_loop_ub;
                    int rc_loop_ub;
                    int sc_loop_ub;
                    int tc_loop_ub;
                    int uc_loop_ub;
                    int vc_loop_ub;
                    int wc_loop_ub;
                    int xc_loop_ub;
                    int yc_loop_ub;
                    rc_loop_ub = Points.size(1);
                    row1.set_size(3, rc_loop_ub);
                    sc_loop_ub = rc_loop_ub;
                    if ((static_cast<int>((rc_loop_ub * 3) < 4)) != 0) {
                      for (int i48{0}; i48 < rc_loop_ub; i48++) {
                        row1[3 * i48] = Points[((static_cast<int>(BoardIdx[0]))
                          + (Points.size(0) * i48)) - 1];
                        row1[(3 * i48) + 1] = Points[((static_cast<int>
                          (BoardIdx[BoardIdx.size(0)])) + (Points.size(0) * i48))
                          - 1];
                        row1[(3 * i48) + 2] = Points[((static_cast<int>
                          (BoardIdx[BoardIdx.size(0) * 2])) + (Points.size(0) *
                          i48)) - 1];
                      }
                    } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                      for (int i48 = 0; i48 < sc_loop_ub; i48++) {
                        row1[3 * i48] = Points[((static_cast<int>(BoardIdx[0]))
                          + (Points.size(0) * i48)) - 1];
                        row1[(3 * i48) + 1] = Points[((static_cast<int>
                          (BoardIdx[BoardIdx.size(0)])) + (Points.size(0) * i48))
                          - 1];
                        row1[(3 * i48) + 2] = Points[((static_cast<int>
                          (BoardIdx[BoardIdx.size(0) * 2])) + (Points.size(0) *
                          i48)) - 1];
                      }
                    }

                    tc_loop_ub = Points.size(1);
                    row2.set_size(3, tc_loop_ub);
                    uc_loop_ub = tc_loop_ub;
                    if ((static_cast<int>((tc_loop_ub * 3) < 4)) != 0) {
                      for (int i49{0}; i49 < tc_loop_ub; i49++) {
                        row2[3 * i49] = Points[((static_cast<int>(BoardIdx[1]))
                          + (Points.size(0) * i49)) - 1];
                        row2[(3 * i49) + 1] = Points[((static_cast<int>
                          (BoardIdx[BoardIdx.size(0) + 1])) + (Points.size(0) *
                          i49)) - 1];
                        row2[(3 * i49) + 2] = Points[((static_cast<int>
                          (BoardIdx[(BoardIdx.size(0) * 2) + 1])) + (Points.size
                          (0) * i49)) - 1];
                      }
                    } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                      for (int i49 = 0; i49 < uc_loop_ub; i49++) {
                        row2[3 * i49] = Points[((static_cast<int>(BoardIdx[1]))
                          + (Points.size(0) * i49)) - 1];
                        row2[(3 * i49) + 1] = Points[((static_cast<int>
                          (BoardIdx[BoardIdx.size(0) + 1])) + (Points.size(0) *
                          i49)) - 1];
                        row2[(3 * i49) + 2] = Points[((static_cast<int>
                          (BoardIdx[(BoardIdx.size(0) * 2) + 1])) + (Points.size
                          (0) * i49)) - 1];
                      }
                    }

                    vc_loop_ub = Points.size(1);
                    row3.set_size(3, vc_loop_ub);
                    wc_loop_ub = vc_loop_ub;
                    if ((static_cast<int>((vc_loop_ub * 3) < 4)) != 0) {
                      for (int i50{0}; i50 < vc_loop_ub; i50++) {
                        row3[3 * i50] = Points[((static_cast<int>(BoardIdx[2]))
                          + (Points.size(0) * i50)) - 1];
                        row3[(3 * i50) + 1] = Points[((static_cast<int>
                          (BoardIdx[BoardIdx.size(0) + 2])) + (Points.size(0) *
                          i50)) - 1];
                        row3[(3 * i50) + 2] = Points[((static_cast<int>
                          (BoardIdx[(BoardIdx.size(0) * 2) + 2])) + (Points.size
                          (0) * i50)) - 1];
                      }
                    } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                      for (int i50 = 0; i50 < wc_loop_ub; i50++) {
                        row3[3 * i50] = Points[((static_cast<int>(BoardIdx[2]))
                          + (Points.size(0) * i50)) - 1];
                        row3[(3 * i50) + 1] = Points[((static_cast<int>
                          (BoardIdx[BoardIdx.size(0) + 2])) + (Points.size(0) *
                          i50)) - 1];
                        row3[(3 * i50) + 2] = Points[((static_cast<int>
                          (BoardIdx[(BoardIdx.size(0) * 2) + 2])) + (Points.size
                          (0) * i50)) - 1];
                      }
                    }

                    num.set_size(3, row1.size(1));
                    xc_loop_ub = row1.size(1);
                    if ((static_cast<int>((row1.size(1) * 3) < 4)) != 0) {
                      for (int i51{0}; i51 < xc_loop_ub; i51++) {
                        num[3 * i51] = (row1[3 * i51] + row3[3 * i51]) - (2.0F *
                          row2[3 * i51]);
                        num[(3 * i51) + 1] = (row1[(3 * i51) + 1] + row3[(3 *
                          i51) + 1]) - (2.0F * row2[(3 * i51) + 1]);
                        num[(3 * i51) + 2] = (row1[(3 * i51) + 2] + row3[(3 *
                          i51) + 2]) - (2.0F * row2[(3 * i51) + 2]);
                      }
                    } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                      for (int i51 = 0; i51 < xc_loop_ub; i51++) {
                        num[3 * i51] = (row1[3 * i51] + row3[3 * i51]) - (2.0F *
                          row2[3 * i51]);
                        num[(3 * i51) + 1] = (row1[(3 * i51) + 1] + row3[(3 *
                          i51) + 1]) - (2.0F * row2[(3 * i51) + 1]);
                        num[(3 * i51) + 2] = (row1[(3 * i51) + 2] + row3[(3 *
                          i51) + 2]) - (2.0F * row2[(3 * i51) + 2]);
                      }
                    }

                    denom.set_size(3, row1.size(1));
                    yc_loop_ub = row1.size(1);
                    if ((static_cast<int>((row1.size(1) * 3) < 4)) != 0) {
                      for (int i52{0}; i52 < yc_loop_ub; i52++) {
                        denom[3 * i52] = row1[3 * i52] - row3[3 * i52];
                        denom[(3 * i52) + 1] = row1[(3 * i52) + 1] - row3[(3 *
                          i52) + 1];
                        denom[(3 * i52) + 2] = row1[(3 * i52) + 2] - row3[(3 *
                          i52) + 2];
                      }
                    } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                      for (int i52 = 0; i52 < yc_loop_ub; i52++) {
                        denom[3 * i52] = row1[3 * i52] - row3[3 * i52];
                        denom[(3 * i52) + 1] = row1[(3 * i52) + 1] - row3[(3 *
                          i52) + 1];
                        denom[(3 * i52) + 2] = row1[(3 * i52) + 2] - row3[(3 *
                          i52) + 2];
                      }
                    }

                    z1[0] = rt_hypotf_snf(num[0], num[3]);
                    z1_idx_0 = rt_hypotf_snf(denom[0], denom[3]);
                    z1[1] = rt_hypotf_snf(num[1], num[4]);
                    z1_idx_1 = rt_hypotf_snf(denom[1], denom[4]);
                    z1[2] = rt_hypotf_snf(num[2], num[5]);
                    z1_idx_2 = rt_hypotf_snf(denom[2], denom[5]);
                    ad_loop_ub = Points.size(1);
                    col1.set_size(3, ad_loop_ub);
                    bd_loop_ub = ad_loop_ub;
                    if ((static_cast<int>((ad_loop_ub * 3) < 4)) != 0) {
                      for (int i53{0}; i53 < ad_loop_ub; i53++) {
                        col1[3 * i53] = Points[((static_cast<int>(BoardIdx[0]))
                          + (Points.size(0) * i53)) - 1];
                        col1[(3 * i53) + 1] = Points[((static_cast<int>
                          (BoardIdx[1])) + (Points.size(0) * i53)) - 1];
                        col1[(3 * i53) + 2] = Points[((static_cast<int>
                          (BoardIdx[2])) + (Points.size(0) * i53)) - 1];
                      }
                    } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                      for (int i53 = 0; i53 < bd_loop_ub; i53++) {
                        col1[3 * i53] = Points[((static_cast<int>(BoardIdx[0]))
                          + (Points.size(0) * i53)) - 1];
                        col1[(3 * i53) + 1] = Points[((static_cast<int>
                          (BoardIdx[1])) + (Points.size(0) * i53)) - 1];
                        col1[(3 * i53) + 2] = Points[((static_cast<int>
                          (BoardIdx[2])) + (Points.size(0) * i53)) - 1];
                      }
                    }

                    cd_loop_ub = Points.size(1);
                    col2.set_size(3, cd_loop_ub);
                    dd_loop_ub = cd_loop_ub;
                    if ((static_cast<int>((cd_loop_ub * 3) < 4)) != 0) {
                      for (int i54{0}; i54 < cd_loop_ub; i54++) {
                        col2[3 * i54] = Points[((static_cast<int>
                          (BoardIdx[BoardIdx.size(0)])) + (Points.size(0) * i54))
                          - 1];
                        col2[(3 * i54) + 1] = Points[((static_cast<int>
                          (BoardIdx[BoardIdx.size(0) + 1])) + (Points.size(0) *
                          i54)) - 1];
                        col2[(3 * i54) + 2] = Points[((static_cast<int>
                          (BoardIdx[BoardIdx.size(0) + 2])) + (Points.size(0) *
                          i54)) - 1];
                      }
                    } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                      for (int i54 = 0; i54 < dd_loop_ub; i54++) {
                        col2[3 * i54] = Points[((static_cast<int>
                          (BoardIdx[BoardIdx.size(0)])) + (Points.size(0) * i54))
                          - 1];
                        col2[(3 * i54) + 1] = Points[((static_cast<int>
                          (BoardIdx[BoardIdx.size(0) + 1])) + (Points.size(0) *
                          i54)) - 1];
                        col2[(3 * i54) + 2] = Points[((static_cast<int>
                          (BoardIdx[BoardIdx.size(0) + 2])) + (Points.size(0) *
                          i54)) - 1];
                      }
                    }

                    ed_loop_ub = Points.size(1);
                    col3.set_size(3, ed_loop_ub);
                    fd_loop_ub = ed_loop_ub;
                    if ((static_cast<int>((ed_loop_ub * 3) < 4)) != 0) {
                      for (int i55{0}; i55 < ed_loop_ub; i55++) {
                        col3[3 * i55] = Points[((static_cast<int>
                          (BoardIdx[BoardIdx.size(0) * 2])) + (Points.size(0) *
                          i55)) - 1];
                        col3[(3 * i55) + 1] = Points[((static_cast<int>
                          (BoardIdx[(BoardIdx.size(0) * 2) + 1])) + (Points.size
                          (0) * i55)) - 1];
                        col3[(3 * i55) + 2] = Points[((static_cast<int>
                          (BoardIdx[(BoardIdx.size(0) * 2) + 2])) + (Points.size
                          (0) * i55)) - 1];
                      }
                    } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                      for (int i55 = 0; i55 < fd_loop_ub; i55++) {
                        col3[3 * i55] = Points[((static_cast<int>
                          (BoardIdx[BoardIdx.size(0) * 2])) + (Points.size(0) *
                          i55)) - 1];
                        col3[(3 * i55) + 1] = Points[((static_cast<int>
                          (BoardIdx[(BoardIdx.size(0) * 2) + 1])) + (Points.size
                          (0) * i55)) - 1];
                        col3[(3 * i55) + 2] = Points[((static_cast<int>
                          (BoardIdx[(BoardIdx.size(0) * 2) + 2])) + (Points.size
                          (0) * i55)) - 1];
                      }
                    }

                    num.set_size(3, col1.size(1));
                    gd_loop_ub = col1.size(1);
                    if ((static_cast<int>((col1.size(1) * 3) < 4)) != 0) {
                      for (int i56{0}; i56 < gd_loop_ub; i56++) {
                        num[3 * i56] = (col1[3 * i56] + col3[3 * i56]) - (2.0F *
                          col2[3 * i56]);
                        num[(3 * i56) + 1] = (col1[(3 * i56) + 1] + col3[(3 *
                          i56) + 1]) - (2.0F * col2[(3 * i56) + 1]);
                        num[(3 * i56) + 2] = (col1[(3 * i56) + 2] + col3[(3 *
                          i56) + 2]) - (2.0F * col2[(3 * i56) + 2]);
                      }
                    } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                      for (int i56 = 0; i56 < gd_loop_ub; i56++) {
                        num[3 * i56] = (col1[3 * i56] + col3[3 * i56]) - (2.0F *
                          col2[3 * i56]);
                        num[(3 * i56) + 1] = (col1[(3 * i56) + 1] + col3[(3 *
                          i56) + 1]) - (2.0F * col2[(3 * i56) + 1]);
                        num[(3 * i56) + 2] = (col1[(3 * i56) + 2] + col3[(3 *
                          i56) + 2]) - (2.0F * col2[(3 * i56) + 2]);
                      }
                    }

                    denom.set_size(3, col1.size(1));
                    hd_loop_ub = col1.size(1);
                    if ((static_cast<int>((col1.size(1) * 3) < 4)) != 0) {
                      for (int i57{0}; i57 < hd_loop_ub; i57++) {
                        denom[3 * i57] = col1[3 * i57] - col3[3 * i57];
                        denom[(3 * i57) + 1] = col1[(3 * i57) + 1] - col3[(3 *
                          i57) + 1];
                        denom[(3 * i57) + 2] = col1[(3 * i57) + 2] - col3[(3 *
                          i57) + 2];
                      }
                    } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                      for (int i57 = 0; i57 < hd_loop_ub; i57++) {
                        denom[3 * i57] = col1[3 * i57] - col3[3 * i57];
                        denom[(3 * i57) + 1] = col1[(3 * i57) + 1] - col3[(3 *
                          i57) + 1];
                        denom[(3 * i57) + 2] = col1[(3 * i57) + 2] - col3[(3 *
                          i57) + 2];
                      }
                    }

                    boardSize = static_cast<float>(static_cast<int>
                      (BoardIdx.size(0) * BoardIdx.size(1)));
                    z1[0] /= z1_idx_0;
                    b_z1[0] = rt_hypotf_snf(num[0], num[3]) / rt_hypotf_snf
                      (denom[0], denom[3]);
                    z1[1] /= z1_idx_1;
                    b_z1[1] = rt_hypotf_snf(num[1], num[4]) / rt_hypotf_snf
                      (denom[1], denom[4]);
                    z1[2] /= z1_idx_2;
                    b_z1[2] = rt_hypotf_snf(num[2], num[5]) / rt_hypotf_snf
                      (denom[2], denom[5]);
                    e = (boardSize * std::fmax(std::fmax(0.0F, ::ITER::coder::
                           internal::maximum(z1)), ::ITER::coder::internal::
                          maximum(b_z1))) - boardSize;
                  }

                  Energy = e;
                  if (IsDistortionHigh) {
                    m_this = -5;
                  } else {
                    m_this = -7;
                  }

                  isValid = ((static_cast<double>(Energy)) < (static_cast<double>
                              (m_this)));
                }
              }
            }
          }
        }
      }
    }
  }
}

//
// File trailer for Checkerboard.cpp
//
// [EOF]
//
