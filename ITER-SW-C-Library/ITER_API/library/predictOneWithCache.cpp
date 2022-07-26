//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: predictOneWithCache.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "predictOneWithCache.h"
#include "CompactClassificationTree.h"
#include "ismember.h"
#include "rt_nonfinite.h"
#include "updateCache.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &d_X
//                ::coder::array<double, 2U> &cachedScore
//                ::coder::array<double, 1U> &cachedWeights
//                const char combiner[15]
//                const
//                ::ITER::coder::classreg::learning::classif::b_CompactClassificationTree
//                *weak_learner double b_learnerWeights bool *cached const
//                double c_classnames[2] const bool b_classlogicalindices[2]
//                const ::coder::array<bool, 1U> &useObsForLearner
//                bool initCache
//                ::coder::array<double, 2U> &score
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace classreg {
namespace learning {
namespace coder {
namespace ensembleutils {
void b_predictOneWithCache(const ::coder::array<double, 2U> &d_X,
                           ::coder::array<double, 2U> &cachedScore,
                           ::coder::array<double, 1U> &cachedWeights,
                           const char combiner[15],
                           const ::ITER::coder::classreg::learning::classif::
                               b_CompactClassificationTree *weak_learner,
                           double b_learnerWeights, bool *cached,
                           const double c_classnames[2],
                           const bool b_classlogicalindices[2],
                           const ::coder::array<bool, 1U> &useObsForLearner,
                           bool initCache, ::coder::array<double, 2U> &score)
{
  ::coder::array<double, 2U> j_X;
  ::coder::array<double, 2U> learnerscore;
  ::coder::array<double, 2U> r3;
  ::coder::array<double, 1U> a__2;
  ::coder::array<int, 1U> r;
  ::coder::array<int, 1U> r1;
  ::coder::array<int, 1U> r4;
  ::coder::array<bool, 2U> b_tf;
  ::coder::array<bool, 2U> r2;
  int iloc[2];
  int b_i8;
  int c_k;
  int cachedScore_idx_0;
  int e_loop_ub;
  int i1;
  int i3;
  int i7;
  int k;
  int loop_ub;
  bool tf[2];
  bool exitg1;
  bool varargout_1;
  cachedScore_idx_0 = cachedScore.size(0);
  learnerscore.set_size(cachedScore_idx_0, 2);
  loop_ub = cachedScore_idx_0;
  if ((static_cast<int>((cachedScore_idx_0 * 2) < 4)) != 0) {
    for (int b_i{0}; b_i < 2; b_i++) {
      for (i1 = 0; i1 < cachedScore_idx_0; i1++) {
        learnerscore[i1 + (learnerscore.size(0) * b_i)] = rtNaN;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1)

    for (int b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        learnerscore[i1 + (learnerscore.size(0) * b_i)] = rtNaN;
      }
    }
  }
  b_local_ismember(weak_learner->ClassNames, c_classnames, tf, iloc);
  varargout_1 = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= (useObsForLearner.size(0) - 1))) {
    if (useObsForLearner[k]) {
      varargout_1 = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (varargout_1) {
    int c_end;
    int c_loop_ub;
    int c_partialTrueCount;
    int c_trueCount;
    int end;
    int f_loop_ub;
    int partialTrueCount;
    int trueCount;
    end = useObsForLearner.size(0) - 1;
    trueCount = 0;
    for (int c_i{0}; c_i <= end; c_i++) {
      if (useObsForLearner[c_i]) {
        trueCount++;
      }
    }
    r.set_size(trueCount);
    partialTrueCount = 0;
    for (int e_i{0}; e_i <= end; e_i++) {
      if (useObsForLearner[e_i]) {
        r[partialTrueCount] = e_i + 1;
        partialTrueCount++;
      }
    }
    j_X.set_size(r.size(0), 8);
    c_loop_ub = r.size(0);
    if ((static_cast<int>((r.size(0) * 8) < 4)) != 0) {
      for (int i5{0}; i5 < 8; i5++) {
        for (i7 = 0; i7 < c_loop_ub; i7++) {
          j_X[i7 + (j_X.size(0) * i5)] = d_X[(r[i7] + (d_X.size(0) * i5)) - 1];
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i7)

      for (int i5 = 0; i5 < 8; i5++) {
        for (i7 = 0; i7 < c_loop_ub; i7++) {
          j_X[i7 + (j_X.size(0) * i5)] = d_X[(r[i7] + (d_X.size(0) * i5)) - 1];
        }
      }
    }
    weak_learner->predict(j_X, a__2, r3);
    c_end = useObsForLearner.size(0) - 1;
    c_trueCount = 0;
    for (int h_i{0}; h_i <= c_end; h_i++) {
      if (useObsForLearner[h_i]) {
        c_trueCount++;
      }
    }
    r4.set_size(c_trueCount);
    c_partialTrueCount = 0;
    for (int m_i{0}; m_i <= c_end; m_i++) {
      if (useObsForLearner[m_i]) {
        r4[c_partialTrueCount] = m_i + 1;
        c_partialTrueCount++;
      }
    }
    f_loop_ub = r3.size(0);
    for (int i9{0}; i9 < 2; i9++) {
      for (int i11{0}; i11 < f_loop_ub; i11++) {
        learnerscore[(r4[i11] + (learnerscore.size(0) * (iloc[i9] - 1))) - 1] =
            r3[i11 + (r3.size(0) * i9)];
      }
    }
  }
  if (initCache) {
    int b_end;
    int b_partialTrueCount;
    int b_trueCount;
    int d_loop_ub;
    b_end = useObsForLearner.size(0) - 1;
    b_trueCount = 0;
    for (int d_i{0}; d_i <= b_end; d_i++) {
      if (useObsForLearner[d_i]) {
        b_trueCount++;
      }
    }
    r1.set_size(b_trueCount);
    b_partialTrueCount = 0;
    for (int g_i{0}; g_i <= b_end; g_i++) {
      if (useObsForLearner[g_i]) {
        r1[b_partialTrueCount] = g_i + 1;
        b_partialTrueCount++;
      }
    }
    d_loop_ub = r1.size(0);
    for (int i4{0}; i4 < 2; i4++) {
      for (int i6{0}; i6 < d_loop_ub; i6++) {
        cachedScore[(r1[i6] + (cachedScore.size(0) * i4)) - 1] = 0.0;
      }
    }
  } else {
    int b_k;
    int b_loop_ub;
    bool b_varargout_1;
    b_tf.set_size(cachedScore.size(0), 2);
    b_loop_ub = cachedScore.size(0);
    if ((static_cast<int>((b_loop_ub * 2) < 4)) != 0) {
      for (int i2{0}; i2 < 2; i2++) {
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          b_tf[i3 + (b_tf.size(0) * i2)] =
              std::isnan(cachedScore[i3 + (cachedScore.size(0) * i2)]);
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3)

      for (int i2 = 0; i2 < 2; i2++) {
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          b_tf[i3 + (b_tf.size(0) * i2)] =
              std::isnan(cachedScore[i3 + (cachedScore.size(0) * i2)]);
        }
      }
    }
    b_varargout_1 = false;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k <= ((b_tf.size(0) * 2) - 1))) {
      if (b_tf[b_k]) {
        b_varargout_1 = true;
        exitg1 = true;
      } else {
        b_k++;
      }
    }
    if (b_varargout_1) {
      int d_end;
      int d_partialTrueCount;
      int d_trueCount;
      int g_loop_ub;
      r2.set_size(useObsForLearner.size(0), 2);
      if (useObsForLearner.size(0) != 0) {
        int na;
        na = useObsForLearner.size(0);
        if ((static_cast<int>((useObsForLearner.size(0) * 2) < 4)) != 0) {
          for (int b_t{0}; b_t < 2; b_t++) {
            for (c_k = 0; c_k < na; c_k++) {
              r2[c_k + (r2.size(0) * b_t)] = useObsForLearner[c_k];
            }
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(c_k)

          for (int b_t = 0; b_t < 2; b_t++) {
            for (c_k = 0; c_k < na; c_k++) {
              r2[c_k + (r2.size(0) * b_t)] = useObsForLearner[c_k];
            }
          }
        }
      }
      d_end = (b_tf.size(0) * 2) - 1;
      d_trueCount = 0;
      for (int k_i{0}; k_i <= d_end; k_i++) {
        if ((b_tf[k_i]) && (r2[k_i])) {
          d_trueCount++;
        }
      }
      r1.set_size(d_trueCount);
      d_partialTrueCount = 0;
      for (int q_i{0}; q_i <= d_end; q_i++) {
        if ((b_tf[q_i]) && (r2[q_i])) {
          r1[d_partialTrueCount] = q_i + 1;
          d_partialTrueCount++;
        }
      }
      g_loop_ub = r1.size(0);
      for (int i10{0}; i10 < g_loop_ub; i10++) {
        cachedScore[r1[i10] - 1] = 0.0;
      }
    }
  }
  updateCache(learnerscore, cachedScore, cachedWeights, cached,
              b_learnerWeights, combiner, useObsForLearner, score);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i8,      \
                                                                    e_loop_ub)

  for (int c_ii = 0; c_ii < 2; c_ii++) {
    if (!b_classlogicalindices[c_ii]) {
      e_loop_ub = score.size(0);
      for (b_i8 = 0; b_i8 < e_loop_ub; b_i8++) {
        score[b_i8 + (score.size(0) * c_ii)] = rtNaN;
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &d_X
//                ::coder::array<double, 2U> &cachedScore
//                ::coder::array<double, 1U> &cachedWeights
//                const char combiner[15]
//                const
//                ::ITER::coder::classreg::learning::classif::c_CompactClassificationTree
//                *weak_learner double b_learnerWeights bool *cached const
//                double c_classnames[2] const bool b_classlogicalindices[2]
//                const ::coder::array<bool, 1U> &useObsForLearner
//                bool initCache
//                ::coder::array<double, 2U> &score
// Return Type  : void
//
void c_predictOneWithCache(const ::coder::array<double, 2U> &d_X,
                           ::coder::array<double, 2U> &cachedScore,
                           ::coder::array<double, 1U> &cachedWeights,
                           const char combiner[15],
                           const ::ITER::coder::classreg::learning::classif::
                               c_CompactClassificationTree *weak_learner,
                           double b_learnerWeights, bool *cached,
                           const double c_classnames[2],
                           const bool b_classlogicalindices[2],
                           const ::coder::array<bool, 1U> &useObsForLearner,
                           bool initCache, ::coder::array<double, 2U> &score)
{
  ::coder::array<double, 2U> j_X;
  ::coder::array<double, 2U> learnerscore;
  ::coder::array<double, 2U> r3;
  ::coder::array<double, 1U> a__2;
  ::coder::array<int, 1U> r;
  ::coder::array<int, 1U> r1;
  ::coder::array<int, 1U> r4;
  ::coder::array<bool, 2U> b_tf;
  ::coder::array<bool, 2U> r2;
  int iloc[2];
  int b_i8;
  int c_k;
  int cachedScore_idx_0;
  int e_loop_ub;
  int i1;
  int i3;
  int i7;
  int k;
  int loop_ub;
  bool tf[2];
  bool exitg1;
  bool varargout_1;
  cachedScore_idx_0 = cachedScore.size(0);
  learnerscore.set_size(cachedScore_idx_0, 2);
  loop_ub = cachedScore_idx_0;
  if ((static_cast<int>((cachedScore_idx_0 * 2) < 4)) != 0) {
    for (int b_i{0}; b_i < 2; b_i++) {
      for (i1 = 0; i1 < cachedScore_idx_0; i1++) {
        learnerscore[i1 + (learnerscore.size(0) * b_i)] = rtNaN;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1)

    for (int b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        learnerscore[i1 + (learnerscore.size(0) * b_i)] = rtNaN;
      }
    }
  }
  b_local_ismember(weak_learner->ClassNames, c_classnames, tf, iloc);
  varargout_1 = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= (useObsForLearner.size(0) - 1))) {
    if (useObsForLearner[k]) {
      varargout_1 = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (varargout_1) {
    int c_end;
    int c_loop_ub;
    int c_partialTrueCount;
    int c_trueCount;
    int end;
    int f_loop_ub;
    int partialTrueCount;
    int trueCount;
    end = useObsForLearner.size(0) - 1;
    trueCount = 0;
    for (int c_i{0}; c_i <= end; c_i++) {
      if (useObsForLearner[c_i]) {
        trueCount++;
      }
    }
    r.set_size(trueCount);
    partialTrueCount = 0;
    for (int e_i{0}; e_i <= end; e_i++) {
      if (useObsForLearner[e_i]) {
        r[partialTrueCount] = e_i + 1;
        partialTrueCount++;
      }
    }
    j_X.set_size(r.size(0), 8);
    c_loop_ub = r.size(0);
    if ((static_cast<int>((r.size(0) * 8) < 4)) != 0) {
      for (int i5{0}; i5 < 8; i5++) {
        for (i7 = 0; i7 < c_loop_ub; i7++) {
          j_X[i7 + (j_X.size(0) * i5)] = d_X[(r[i7] + (d_X.size(0) * i5)) - 1];
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i7)

      for (int i5 = 0; i5 < 8; i5++) {
        for (i7 = 0; i7 < c_loop_ub; i7++) {
          j_X[i7 + (j_X.size(0) * i5)] = d_X[(r[i7] + (d_X.size(0) * i5)) - 1];
        }
      }
    }
    weak_learner->predict(j_X, a__2, r3);
    c_end = useObsForLearner.size(0) - 1;
    c_trueCount = 0;
    for (int h_i{0}; h_i <= c_end; h_i++) {
      if (useObsForLearner[h_i]) {
        c_trueCount++;
      }
    }
    r4.set_size(c_trueCount);
    c_partialTrueCount = 0;
    for (int m_i{0}; m_i <= c_end; m_i++) {
      if (useObsForLearner[m_i]) {
        r4[c_partialTrueCount] = m_i + 1;
        c_partialTrueCount++;
      }
    }
    f_loop_ub = r3.size(0);
    for (int i9{0}; i9 < 2; i9++) {
      for (int i11{0}; i11 < f_loop_ub; i11++) {
        learnerscore[(r4[i11] + (learnerscore.size(0) * (iloc[i9] - 1))) - 1] =
            r3[i11 + (r3.size(0) * i9)];
      }
    }
  }
  if (initCache) {
    int b_end;
    int b_partialTrueCount;
    int b_trueCount;
    int d_loop_ub;
    b_end = useObsForLearner.size(0) - 1;
    b_trueCount = 0;
    for (int d_i{0}; d_i <= b_end; d_i++) {
      if (useObsForLearner[d_i]) {
        b_trueCount++;
      }
    }
    r1.set_size(b_trueCount);
    b_partialTrueCount = 0;
    for (int g_i{0}; g_i <= b_end; g_i++) {
      if (useObsForLearner[g_i]) {
        r1[b_partialTrueCount] = g_i + 1;
        b_partialTrueCount++;
      }
    }
    d_loop_ub = r1.size(0);
    for (int i4{0}; i4 < 2; i4++) {
      for (int i6{0}; i6 < d_loop_ub; i6++) {
        cachedScore[(r1[i6] + (cachedScore.size(0) * i4)) - 1] = 0.0;
      }
    }
  } else {
    int b_k;
    int b_loop_ub;
    bool b_varargout_1;
    b_tf.set_size(cachedScore.size(0), 2);
    b_loop_ub = cachedScore.size(0);
    if ((static_cast<int>((b_loop_ub * 2) < 4)) != 0) {
      for (int i2{0}; i2 < 2; i2++) {
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          b_tf[i3 + (b_tf.size(0) * i2)] =
              std::isnan(cachedScore[i3 + (cachedScore.size(0) * i2)]);
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3)

      for (int i2 = 0; i2 < 2; i2++) {
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          b_tf[i3 + (b_tf.size(0) * i2)] =
              std::isnan(cachedScore[i3 + (cachedScore.size(0) * i2)]);
        }
      }
    }
    b_varargout_1 = false;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k <= ((b_tf.size(0) * 2) - 1))) {
      if (b_tf[b_k]) {
        b_varargout_1 = true;
        exitg1 = true;
      } else {
        b_k++;
      }
    }
    if (b_varargout_1) {
      int d_end;
      int d_partialTrueCount;
      int d_trueCount;
      int g_loop_ub;
      r2.set_size(useObsForLearner.size(0), 2);
      if (useObsForLearner.size(0) != 0) {
        int na;
        na = useObsForLearner.size(0);
        if ((static_cast<int>((useObsForLearner.size(0) * 2) < 4)) != 0) {
          for (int b_t{0}; b_t < 2; b_t++) {
            for (c_k = 0; c_k < na; c_k++) {
              r2[c_k + (r2.size(0) * b_t)] = useObsForLearner[c_k];
            }
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(c_k)

          for (int b_t = 0; b_t < 2; b_t++) {
            for (c_k = 0; c_k < na; c_k++) {
              r2[c_k + (r2.size(0) * b_t)] = useObsForLearner[c_k];
            }
          }
        }
      }
      d_end = (b_tf.size(0) * 2) - 1;
      d_trueCount = 0;
      for (int k_i{0}; k_i <= d_end; k_i++) {
        if ((b_tf[k_i]) && (r2[k_i])) {
          d_trueCount++;
        }
      }
      r1.set_size(d_trueCount);
      d_partialTrueCount = 0;
      for (int q_i{0}; q_i <= d_end; q_i++) {
        if ((b_tf[q_i]) && (r2[q_i])) {
          r1[d_partialTrueCount] = q_i + 1;
          d_partialTrueCount++;
        }
      }
      g_loop_ub = r1.size(0);
      for (int i10{0}; i10 < g_loop_ub; i10++) {
        cachedScore[r1[i10] - 1] = 0.0;
      }
    }
  }
  updateCache(learnerscore, cachedScore, cachedWeights, cached,
              b_learnerWeights, combiner, useObsForLearner, score);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i8,      \
                                                                    e_loop_ub)

  for (int c_ii = 0; c_ii < 2; c_ii++) {
    if (!b_classlogicalindices[c_ii]) {
      e_loop_ub = score.size(0);
      for (b_i8 = 0; b_i8 < e_loop_ub; b_i8++) {
        score[b_i8 + (score.size(0) * c_ii)] = rtNaN;
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &d_X
//                ::coder::array<double, 2U> &cachedScore
//                ::coder::array<double, 1U> &cachedWeights
//                const char combiner[15]
//                const
//                ::ITER::coder::classreg::learning::classif::d_CompactClassificationTree
//                *weak_learner double b_learnerWeights bool *cached const
//                double c_classnames[2] const bool b_classlogicalindices[2]
//                const ::coder::array<bool, 1U> &useObsForLearner
//                bool initCache
//                ::coder::array<double, 2U> &score
// Return Type  : void
//
void d_predictOneWithCache(const ::coder::array<double, 2U> &d_X,
                           ::coder::array<double, 2U> &cachedScore,
                           ::coder::array<double, 1U> &cachedWeights,
                           const char combiner[15],
                           const ::ITER::coder::classreg::learning::classif::
                               d_CompactClassificationTree *weak_learner,
                           double b_learnerWeights, bool *cached,
                           const double c_classnames[2],
                           const bool b_classlogicalindices[2],
                           const ::coder::array<bool, 1U> &useObsForLearner,
                           bool initCache, ::coder::array<double, 2U> &score)
{
  ::coder::array<double, 2U> j_X;
  ::coder::array<double, 2U> learnerscore;
  ::coder::array<double, 2U> r3;
  ::coder::array<double, 1U> a__2;
  ::coder::array<int, 1U> r;
  ::coder::array<int, 1U> r1;
  ::coder::array<int, 1U> r4;
  ::coder::array<bool, 2U> b_tf;
  ::coder::array<bool, 2U> r2;
  int iloc[2];
  int b_i8;
  int c_k;
  int cachedScore_idx_0;
  int e_loop_ub;
  int i1;
  int i3;
  int i7;
  int k;
  int loop_ub;
  bool tf[2];
  bool exitg1;
  bool varargout_1;
  cachedScore_idx_0 = cachedScore.size(0);
  learnerscore.set_size(cachedScore_idx_0, 2);
  loop_ub = cachedScore_idx_0;
  if ((static_cast<int>((cachedScore_idx_0 * 2) < 4)) != 0) {
    for (int b_i{0}; b_i < 2; b_i++) {
      for (i1 = 0; i1 < cachedScore_idx_0; i1++) {
        learnerscore[i1 + (learnerscore.size(0) * b_i)] = rtNaN;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1)

    for (int b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        learnerscore[i1 + (learnerscore.size(0) * b_i)] = rtNaN;
      }
    }
  }
  b_local_ismember(weak_learner->ClassNames, c_classnames, tf, iloc);
  varargout_1 = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= (useObsForLearner.size(0) - 1))) {
    if (useObsForLearner[k]) {
      varargout_1 = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (varargout_1) {
    int c_end;
    int c_loop_ub;
    int c_partialTrueCount;
    int c_trueCount;
    int end;
    int f_loop_ub;
    int partialTrueCount;
    int trueCount;
    end = useObsForLearner.size(0) - 1;
    trueCount = 0;
    for (int c_i{0}; c_i <= end; c_i++) {
      if (useObsForLearner[c_i]) {
        trueCount++;
      }
    }
    r.set_size(trueCount);
    partialTrueCount = 0;
    for (int e_i{0}; e_i <= end; e_i++) {
      if (useObsForLearner[e_i]) {
        r[partialTrueCount] = e_i + 1;
        partialTrueCount++;
      }
    }
    j_X.set_size(r.size(0), 8);
    c_loop_ub = r.size(0);
    if ((static_cast<int>((r.size(0) * 8) < 4)) != 0) {
      for (int i5{0}; i5 < 8; i5++) {
        for (i7 = 0; i7 < c_loop_ub; i7++) {
          j_X[i7 + (j_X.size(0) * i5)] = d_X[(r[i7] + (d_X.size(0) * i5)) - 1];
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i7)

      for (int i5 = 0; i5 < 8; i5++) {
        for (i7 = 0; i7 < c_loop_ub; i7++) {
          j_X[i7 + (j_X.size(0) * i5)] = d_X[(r[i7] + (d_X.size(0) * i5)) - 1];
        }
      }
    }
    weak_learner->predict(j_X, a__2, r3);
    c_end = useObsForLearner.size(0) - 1;
    c_trueCount = 0;
    for (int h_i{0}; h_i <= c_end; h_i++) {
      if (useObsForLearner[h_i]) {
        c_trueCount++;
      }
    }
    r4.set_size(c_trueCount);
    c_partialTrueCount = 0;
    for (int m_i{0}; m_i <= c_end; m_i++) {
      if (useObsForLearner[m_i]) {
        r4[c_partialTrueCount] = m_i + 1;
        c_partialTrueCount++;
      }
    }
    f_loop_ub = r3.size(0);
    for (int i9{0}; i9 < 2; i9++) {
      for (int i11{0}; i11 < f_loop_ub; i11++) {
        learnerscore[(r4[i11] + (learnerscore.size(0) * (iloc[i9] - 1))) - 1] =
            r3[i11 + (r3.size(0) * i9)];
      }
    }
  }
  if (initCache) {
    int b_end;
    int b_partialTrueCount;
    int b_trueCount;
    int d_loop_ub;
    b_end = useObsForLearner.size(0) - 1;
    b_trueCount = 0;
    for (int d_i{0}; d_i <= b_end; d_i++) {
      if (useObsForLearner[d_i]) {
        b_trueCount++;
      }
    }
    r1.set_size(b_trueCount);
    b_partialTrueCount = 0;
    for (int g_i{0}; g_i <= b_end; g_i++) {
      if (useObsForLearner[g_i]) {
        r1[b_partialTrueCount] = g_i + 1;
        b_partialTrueCount++;
      }
    }
    d_loop_ub = r1.size(0);
    for (int i4{0}; i4 < 2; i4++) {
      for (int i6{0}; i6 < d_loop_ub; i6++) {
        cachedScore[(r1[i6] + (cachedScore.size(0) * i4)) - 1] = 0.0;
      }
    }
  } else {
    int b_k;
    int b_loop_ub;
    bool b_varargout_1;
    b_tf.set_size(cachedScore.size(0), 2);
    b_loop_ub = cachedScore.size(0);
    if ((static_cast<int>((b_loop_ub * 2) < 4)) != 0) {
      for (int i2{0}; i2 < 2; i2++) {
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          b_tf[i3 + (b_tf.size(0) * i2)] =
              std::isnan(cachedScore[i3 + (cachedScore.size(0) * i2)]);
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3)

      for (int i2 = 0; i2 < 2; i2++) {
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          b_tf[i3 + (b_tf.size(0) * i2)] =
              std::isnan(cachedScore[i3 + (cachedScore.size(0) * i2)]);
        }
      }
    }
    b_varargout_1 = false;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k <= ((b_tf.size(0) * 2) - 1))) {
      if (b_tf[b_k]) {
        b_varargout_1 = true;
        exitg1 = true;
      } else {
        b_k++;
      }
    }
    if (b_varargout_1) {
      int d_end;
      int d_partialTrueCount;
      int d_trueCount;
      int g_loop_ub;
      r2.set_size(useObsForLearner.size(0), 2);
      if (useObsForLearner.size(0) != 0) {
        int na;
        na = useObsForLearner.size(0);
        if ((static_cast<int>((useObsForLearner.size(0) * 2) < 4)) != 0) {
          for (int b_t{0}; b_t < 2; b_t++) {
            for (c_k = 0; c_k < na; c_k++) {
              r2[c_k + (r2.size(0) * b_t)] = useObsForLearner[c_k];
            }
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(c_k)

          for (int b_t = 0; b_t < 2; b_t++) {
            for (c_k = 0; c_k < na; c_k++) {
              r2[c_k + (r2.size(0) * b_t)] = useObsForLearner[c_k];
            }
          }
        }
      }
      d_end = (b_tf.size(0) * 2) - 1;
      d_trueCount = 0;
      for (int k_i{0}; k_i <= d_end; k_i++) {
        if ((b_tf[k_i]) && (r2[k_i])) {
          d_trueCount++;
        }
      }
      r1.set_size(d_trueCount);
      d_partialTrueCount = 0;
      for (int q_i{0}; q_i <= d_end; q_i++) {
        if ((b_tf[q_i]) && (r2[q_i])) {
          r1[d_partialTrueCount] = q_i + 1;
          d_partialTrueCount++;
        }
      }
      g_loop_ub = r1.size(0);
      for (int i10{0}; i10 < g_loop_ub; i10++) {
        cachedScore[r1[i10] - 1] = 0.0;
      }
    }
  }
  updateCache(learnerscore, cachedScore, cachedWeights, cached,
              b_learnerWeights, combiner, useObsForLearner, score);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i8,      \
                                                                    e_loop_ub)

  for (int c_ii = 0; c_ii < 2; c_ii++) {
    if (!b_classlogicalindices[c_ii]) {
      e_loop_ub = score.size(0);
      for (b_i8 = 0; b_i8 < e_loop_ub; b_i8++) {
        score[b_i8 + (score.size(0) * c_ii)] = rtNaN;
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &d_X
//                ::coder::array<double, 2U> &cachedScore
//                ::coder::array<double, 1U> &cachedWeights
//                const char combiner[15]
//                const
//                ::ITER::coder::classreg::learning::classif::e_CompactClassificationTree
//                *weak_learner double b_learnerWeights bool *cached const
//                double c_classnames[2] const bool b_classlogicalindices[2]
//                const ::coder::array<bool, 1U> &useObsForLearner
//                bool initCache
//                ::coder::array<double, 2U> &score
// Return Type  : void
//
void e_predictOneWithCache(const ::coder::array<double, 2U> &d_X,
                           ::coder::array<double, 2U> &cachedScore,
                           ::coder::array<double, 1U> &cachedWeights,
                           const char combiner[15],
                           const ::ITER::coder::classreg::learning::classif::
                               e_CompactClassificationTree *weak_learner,
                           double b_learnerWeights, bool *cached,
                           const double c_classnames[2],
                           const bool b_classlogicalindices[2],
                           const ::coder::array<bool, 1U> &useObsForLearner,
                           bool initCache, ::coder::array<double, 2U> &score)
{
  ::coder::array<double, 2U> j_X;
  ::coder::array<double, 2U> learnerscore;
  ::coder::array<double, 2U> r3;
  ::coder::array<double, 1U> a__2;
  ::coder::array<int, 1U> r;
  ::coder::array<int, 1U> r1;
  ::coder::array<int, 1U> r4;
  ::coder::array<bool, 2U> b_tf;
  ::coder::array<bool, 2U> r2;
  int iloc[2];
  int b_i8;
  int c_k;
  int cachedScore_idx_0;
  int e_loop_ub;
  int i1;
  int i3;
  int i7;
  int k;
  int loop_ub;
  bool tf[2];
  bool exitg1;
  bool varargout_1;
  cachedScore_idx_0 = cachedScore.size(0);
  learnerscore.set_size(cachedScore_idx_0, 2);
  loop_ub = cachedScore_idx_0;
  if ((static_cast<int>((cachedScore_idx_0 * 2) < 4)) != 0) {
    for (int b_i{0}; b_i < 2; b_i++) {
      for (i1 = 0; i1 < cachedScore_idx_0; i1++) {
        learnerscore[i1 + (learnerscore.size(0) * b_i)] = rtNaN;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1)

    for (int b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        learnerscore[i1 + (learnerscore.size(0) * b_i)] = rtNaN;
      }
    }
  }
  b_local_ismember(weak_learner->ClassNames, c_classnames, tf, iloc);
  varargout_1 = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= (useObsForLearner.size(0) - 1))) {
    if (useObsForLearner[k]) {
      varargout_1 = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (varargout_1) {
    int c_end;
    int c_loop_ub;
    int c_partialTrueCount;
    int c_trueCount;
    int end;
    int f_loop_ub;
    int partialTrueCount;
    int trueCount;
    end = useObsForLearner.size(0) - 1;
    trueCount = 0;
    for (int c_i{0}; c_i <= end; c_i++) {
      if (useObsForLearner[c_i]) {
        trueCount++;
      }
    }
    r.set_size(trueCount);
    partialTrueCount = 0;
    for (int e_i{0}; e_i <= end; e_i++) {
      if (useObsForLearner[e_i]) {
        r[partialTrueCount] = e_i + 1;
        partialTrueCount++;
      }
    }
    j_X.set_size(r.size(0), 8);
    c_loop_ub = r.size(0);
    if ((static_cast<int>((r.size(0) * 8) < 4)) != 0) {
      for (int i5{0}; i5 < 8; i5++) {
        for (i7 = 0; i7 < c_loop_ub; i7++) {
          j_X[i7 + (j_X.size(0) * i5)] = d_X[(r[i7] + (d_X.size(0) * i5)) - 1];
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i7)

      for (int i5 = 0; i5 < 8; i5++) {
        for (i7 = 0; i7 < c_loop_ub; i7++) {
          j_X[i7 + (j_X.size(0) * i5)] = d_X[(r[i7] + (d_X.size(0) * i5)) - 1];
        }
      }
    }
    weak_learner->predict(j_X, a__2, r3);
    c_end = useObsForLearner.size(0) - 1;
    c_trueCount = 0;
    for (int h_i{0}; h_i <= c_end; h_i++) {
      if (useObsForLearner[h_i]) {
        c_trueCount++;
      }
    }
    r4.set_size(c_trueCount);
    c_partialTrueCount = 0;
    for (int m_i{0}; m_i <= c_end; m_i++) {
      if (useObsForLearner[m_i]) {
        r4[c_partialTrueCount] = m_i + 1;
        c_partialTrueCount++;
      }
    }
    f_loop_ub = r3.size(0);
    for (int i9{0}; i9 < 2; i9++) {
      for (int i11{0}; i11 < f_loop_ub; i11++) {
        learnerscore[(r4[i11] + (learnerscore.size(0) * (iloc[i9] - 1))) - 1] =
            r3[i11 + (r3.size(0) * i9)];
      }
    }
  }
  if (initCache) {
    int b_end;
    int b_partialTrueCount;
    int b_trueCount;
    int d_loop_ub;
    b_end = useObsForLearner.size(0) - 1;
    b_trueCount = 0;
    for (int d_i{0}; d_i <= b_end; d_i++) {
      if (useObsForLearner[d_i]) {
        b_trueCount++;
      }
    }
    r1.set_size(b_trueCount);
    b_partialTrueCount = 0;
    for (int g_i{0}; g_i <= b_end; g_i++) {
      if (useObsForLearner[g_i]) {
        r1[b_partialTrueCount] = g_i + 1;
        b_partialTrueCount++;
      }
    }
    d_loop_ub = r1.size(0);
    for (int i4{0}; i4 < 2; i4++) {
      for (int i6{0}; i6 < d_loop_ub; i6++) {
        cachedScore[(r1[i6] + (cachedScore.size(0) * i4)) - 1] = 0.0;
      }
    }
  } else {
    int b_k;
    int b_loop_ub;
    bool b_varargout_1;
    b_tf.set_size(cachedScore.size(0), 2);
    b_loop_ub = cachedScore.size(0);
    if ((static_cast<int>((b_loop_ub * 2) < 4)) != 0) {
      for (int i2{0}; i2 < 2; i2++) {
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          b_tf[i3 + (b_tf.size(0) * i2)] =
              std::isnan(cachedScore[i3 + (cachedScore.size(0) * i2)]);
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3)

      for (int i2 = 0; i2 < 2; i2++) {
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          b_tf[i3 + (b_tf.size(0) * i2)] =
              std::isnan(cachedScore[i3 + (cachedScore.size(0) * i2)]);
        }
      }
    }
    b_varargout_1 = false;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k <= ((b_tf.size(0) * 2) - 1))) {
      if (b_tf[b_k]) {
        b_varargout_1 = true;
        exitg1 = true;
      } else {
        b_k++;
      }
    }
    if (b_varargout_1) {
      int d_end;
      int d_partialTrueCount;
      int d_trueCount;
      int g_loop_ub;
      r2.set_size(useObsForLearner.size(0), 2);
      if (useObsForLearner.size(0) != 0) {
        int na;
        na = useObsForLearner.size(0);
        if ((static_cast<int>((useObsForLearner.size(0) * 2) < 4)) != 0) {
          for (int b_t{0}; b_t < 2; b_t++) {
            for (c_k = 0; c_k < na; c_k++) {
              r2[c_k + (r2.size(0) * b_t)] = useObsForLearner[c_k];
            }
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(c_k)

          for (int b_t = 0; b_t < 2; b_t++) {
            for (c_k = 0; c_k < na; c_k++) {
              r2[c_k + (r2.size(0) * b_t)] = useObsForLearner[c_k];
            }
          }
        }
      }
      d_end = (b_tf.size(0) * 2) - 1;
      d_trueCount = 0;
      for (int k_i{0}; k_i <= d_end; k_i++) {
        if ((b_tf[k_i]) && (r2[k_i])) {
          d_trueCount++;
        }
      }
      r1.set_size(d_trueCount);
      d_partialTrueCount = 0;
      for (int q_i{0}; q_i <= d_end; q_i++) {
        if ((b_tf[q_i]) && (r2[q_i])) {
          r1[d_partialTrueCount] = q_i + 1;
          d_partialTrueCount++;
        }
      }
      g_loop_ub = r1.size(0);
      for (int i10{0}; i10 < g_loop_ub; i10++) {
        cachedScore[r1[i10] - 1] = 0.0;
      }
    }
  }
  updateCache(learnerscore, cachedScore, cachedWeights, cached,
              b_learnerWeights, combiner, useObsForLearner, score);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i8,      \
                                                                    e_loop_ub)

  for (int c_ii = 0; c_ii < 2; c_ii++) {
    if (!b_classlogicalindices[c_ii]) {
      e_loop_ub = score.size(0);
      for (b_i8 = 0; b_i8 < e_loop_ub; b_i8++) {
        score[b_i8 + (score.size(0) * c_ii)] = rtNaN;
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &d_X
//                ::coder::array<double, 2U> &cachedScore
//                ::coder::array<double, 1U> &cachedWeights
//                const char combiner[15]
//                const
//                ::ITER::coder::classreg::learning::classif::f_CompactClassificationTree
//                *weak_learner double b_learnerWeights bool *cached const
//                double c_classnames[2] const bool b_classlogicalindices[2]
//                const ::coder::array<bool, 1U> &useObsForLearner
//                bool initCache
//                ::coder::array<double, 2U> &score
// Return Type  : void
//
void f_predictOneWithCache(const ::coder::array<double, 2U> &d_X,
                           ::coder::array<double, 2U> &cachedScore,
                           ::coder::array<double, 1U> &cachedWeights,
                           const char combiner[15],
                           const ::ITER::coder::classreg::learning::classif::
                               f_CompactClassificationTree *weak_learner,
                           double b_learnerWeights, bool *cached,
                           const double c_classnames[2],
                           const bool b_classlogicalindices[2],
                           const ::coder::array<bool, 1U> &useObsForLearner,
                           bool initCache, ::coder::array<double, 2U> &score)
{
  ::coder::array<double, 2U> j_X;
  ::coder::array<double, 2U> learnerscore;
  ::coder::array<double, 2U> r3;
  ::coder::array<double, 1U> a__2;
  ::coder::array<int, 1U> r;
  ::coder::array<int, 1U> r1;
  ::coder::array<int, 1U> r4;
  ::coder::array<bool, 2U> b_tf;
  ::coder::array<bool, 2U> r2;
  int iloc[2];
  int b_i8;
  int c_k;
  int cachedScore_idx_0;
  int e_loop_ub;
  int i1;
  int i3;
  int i7;
  int k;
  int loop_ub;
  bool tf[2];
  bool exitg1;
  bool varargout_1;
  cachedScore_idx_0 = cachedScore.size(0);
  learnerscore.set_size(cachedScore_idx_0, 2);
  loop_ub = cachedScore_idx_0;
  if ((static_cast<int>((cachedScore_idx_0 * 2) < 4)) != 0) {
    for (int b_i{0}; b_i < 2; b_i++) {
      for (i1 = 0; i1 < cachedScore_idx_0; i1++) {
        learnerscore[i1 + (learnerscore.size(0) * b_i)] = rtNaN;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1)

    for (int b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        learnerscore[i1 + (learnerscore.size(0) * b_i)] = rtNaN;
      }
    }
  }
  b_local_ismember(weak_learner->ClassNames, c_classnames, tf, iloc);
  varargout_1 = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= (useObsForLearner.size(0) - 1))) {
    if (useObsForLearner[k]) {
      varargout_1 = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (varargout_1) {
    int c_end;
    int c_loop_ub;
    int c_partialTrueCount;
    int c_trueCount;
    int end;
    int f_loop_ub;
    int partialTrueCount;
    int trueCount;
    end = useObsForLearner.size(0) - 1;
    trueCount = 0;
    for (int c_i{0}; c_i <= end; c_i++) {
      if (useObsForLearner[c_i]) {
        trueCount++;
      }
    }
    r.set_size(trueCount);
    partialTrueCount = 0;
    for (int e_i{0}; e_i <= end; e_i++) {
      if (useObsForLearner[e_i]) {
        r[partialTrueCount] = e_i + 1;
        partialTrueCount++;
      }
    }
    j_X.set_size(r.size(0), 8);
    c_loop_ub = r.size(0);
    if ((static_cast<int>((r.size(0) * 8) < 4)) != 0) {
      for (int i5{0}; i5 < 8; i5++) {
        for (i7 = 0; i7 < c_loop_ub; i7++) {
          j_X[i7 + (j_X.size(0) * i5)] = d_X[(r[i7] + (d_X.size(0) * i5)) - 1];
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i7)

      for (int i5 = 0; i5 < 8; i5++) {
        for (i7 = 0; i7 < c_loop_ub; i7++) {
          j_X[i7 + (j_X.size(0) * i5)] = d_X[(r[i7] + (d_X.size(0) * i5)) - 1];
        }
      }
    }
    weak_learner->predict(j_X, a__2, r3);
    c_end = useObsForLearner.size(0) - 1;
    c_trueCount = 0;
    for (int h_i{0}; h_i <= c_end; h_i++) {
      if (useObsForLearner[h_i]) {
        c_trueCount++;
      }
    }
    r4.set_size(c_trueCount);
    c_partialTrueCount = 0;
    for (int m_i{0}; m_i <= c_end; m_i++) {
      if (useObsForLearner[m_i]) {
        r4[c_partialTrueCount] = m_i + 1;
        c_partialTrueCount++;
      }
    }
    f_loop_ub = r3.size(0);
    for (int i9{0}; i9 < 2; i9++) {
      for (int i11{0}; i11 < f_loop_ub; i11++) {
        learnerscore[(r4[i11] + (learnerscore.size(0) * (iloc[i9] - 1))) - 1] =
            r3[i11 + (r3.size(0) * i9)];
      }
    }
  }
  if (initCache) {
    int b_end;
    int b_partialTrueCount;
    int b_trueCount;
    int d_loop_ub;
    b_end = useObsForLearner.size(0) - 1;
    b_trueCount = 0;
    for (int d_i{0}; d_i <= b_end; d_i++) {
      if (useObsForLearner[d_i]) {
        b_trueCount++;
      }
    }
    r1.set_size(b_trueCount);
    b_partialTrueCount = 0;
    for (int g_i{0}; g_i <= b_end; g_i++) {
      if (useObsForLearner[g_i]) {
        r1[b_partialTrueCount] = g_i + 1;
        b_partialTrueCount++;
      }
    }
    d_loop_ub = r1.size(0);
    for (int i4{0}; i4 < 2; i4++) {
      for (int i6{0}; i6 < d_loop_ub; i6++) {
        cachedScore[(r1[i6] + (cachedScore.size(0) * i4)) - 1] = 0.0;
      }
    }
  } else {
    int b_k;
    int b_loop_ub;
    bool b_varargout_1;
    b_tf.set_size(cachedScore.size(0), 2);
    b_loop_ub = cachedScore.size(0);
    if ((static_cast<int>((b_loop_ub * 2) < 4)) != 0) {
      for (int i2{0}; i2 < 2; i2++) {
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          b_tf[i3 + (b_tf.size(0) * i2)] =
              std::isnan(cachedScore[i3 + (cachedScore.size(0) * i2)]);
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3)

      for (int i2 = 0; i2 < 2; i2++) {
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          b_tf[i3 + (b_tf.size(0) * i2)] =
              std::isnan(cachedScore[i3 + (cachedScore.size(0) * i2)]);
        }
      }
    }
    b_varargout_1 = false;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k <= ((b_tf.size(0) * 2) - 1))) {
      if (b_tf[b_k]) {
        b_varargout_1 = true;
        exitg1 = true;
      } else {
        b_k++;
      }
    }
    if (b_varargout_1) {
      int d_end;
      int d_partialTrueCount;
      int d_trueCount;
      int g_loop_ub;
      r2.set_size(useObsForLearner.size(0), 2);
      if (useObsForLearner.size(0) != 0) {
        int na;
        na = useObsForLearner.size(0);
        if ((static_cast<int>((useObsForLearner.size(0) * 2) < 4)) != 0) {
          for (int b_t{0}; b_t < 2; b_t++) {
            for (c_k = 0; c_k < na; c_k++) {
              r2[c_k + (r2.size(0) * b_t)] = useObsForLearner[c_k];
            }
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(c_k)

          for (int b_t = 0; b_t < 2; b_t++) {
            for (c_k = 0; c_k < na; c_k++) {
              r2[c_k + (r2.size(0) * b_t)] = useObsForLearner[c_k];
            }
          }
        }
      }
      d_end = (b_tf.size(0) * 2) - 1;
      d_trueCount = 0;
      for (int k_i{0}; k_i <= d_end; k_i++) {
        if ((b_tf[k_i]) && (r2[k_i])) {
          d_trueCount++;
        }
      }
      r1.set_size(d_trueCount);
      d_partialTrueCount = 0;
      for (int q_i{0}; q_i <= d_end; q_i++) {
        if ((b_tf[q_i]) && (r2[q_i])) {
          r1[d_partialTrueCount] = q_i + 1;
          d_partialTrueCount++;
        }
      }
      g_loop_ub = r1.size(0);
      for (int i10{0}; i10 < g_loop_ub; i10++) {
        cachedScore[r1[i10] - 1] = 0.0;
      }
    }
  }
  updateCache(learnerscore, cachedScore, cachedWeights, cached,
              b_learnerWeights, combiner, useObsForLearner, score);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i8,      \
                                                                    e_loop_ub)

  for (int c_ii = 0; c_ii < 2; c_ii++) {
    if (!b_classlogicalindices[c_ii]) {
      e_loop_ub = score.size(0);
      for (b_i8 = 0; b_i8 < e_loop_ub; b_i8++) {
        score[b_i8 + (score.size(0) * c_ii)] = rtNaN;
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &d_X
//                ::coder::array<double, 2U> &cachedScore
//                ::coder::array<double, 1U> &cachedWeights
//                const char combiner[15]
//                const
//                ::ITER::coder::classreg::learning::classif::g_CompactClassificationTree
//                *weak_learner double b_learnerWeights bool *cached const
//                double c_classnames[2] const bool b_classlogicalindices[2]
//                const ::coder::array<bool, 1U> &useObsForLearner
//                bool initCache
//                ::coder::array<double, 2U> &score
// Return Type  : void
//
void g_predictOneWithCache(const ::coder::array<double, 2U> &d_X,
                           ::coder::array<double, 2U> &cachedScore,
                           ::coder::array<double, 1U> &cachedWeights,
                           const char combiner[15],
                           const ::ITER::coder::classreg::learning::classif::
                               g_CompactClassificationTree *weak_learner,
                           double b_learnerWeights, bool *cached,
                           const double c_classnames[2],
                           const bool b_classlogicalindices[2],
                           const ::coder::array<bool, 1U> &useObsForLearner,
                           bool initCache, ::coder::array<double, 2U> &score)
{
  ::coder::array<double, 2U> j_X;
  ::coder::array<double, 2U> learnerscore;
  ::coder::array<double, 2U> r3;
  ::coder::array<double, 1U> a__2;
  ::coder::array<int, 1U> r;
  ::coder::array<int, 1U> r1;
  ::coder::array<int, 1U> r4;
  ::coder::array<bool, 2U> b_tf;
  ::coder::array<bool, 2U> r2;
  int iloc[2];
  int b_i8;
  int c_k;
  int cachedScore_idx_0;
  int e_loop_ub;
  int i1;
  int i3;
  int i7;
  int k;
  int loop_ub;
  bool tf[2];
  bool exitg1;
  bool varargout_1;
  cachedScore_idx_0 = cachedScore.size(0);
  learnerscore.set_size(cachedScore_idx_0, 2);
  loop_ub = cachedScore_idx_0;
  if ((static_cast<int>((cachedScore_idx_0 * 2) < 4)) != 0) {
    for (int b_i{0}; b_i < 2; b_i++) {
      for (i1 = 0; i1 < cachedScore_idx_0; i1++) {
        learnerscore[i1 + (learnerscore.size(0) * b_i)] = rtNaN;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1)

    for (int b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        learnerscore[i1 + (learnerscore.size(0) * b_i)] = rtNaN;
      }
    }
  }
  b_local_ismember(weak_learner->ClassNames, c_classnames, tf, iloc);
  varargout_1 = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= (useObsForLearner.size(0) - 1))) {
    if (useObsForLearner[k]) {
      varargout_1 = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (varargout_1) {
    int c_end;
    int c_loop_ub;
    int c_partialTrueCount;
    int c_trueCount;
    int end;
    int f_loop_ub;
    int partialTrueCount;
    int trueCount;
    end = useObsForLearner.size(0) - 1;
    trueCount = 0;
    for (int c_i{0}; c_i <= end; c_i++) {
      if (useObsForLearner[c_i]) {
        trueCount++;
      }
    }
    r.set_size(trueCount);
    partialTrueCount = 0;
    for (int e_i{0}; e_i <= end; e_i++) {
      if (useObsForLearner[e_i]) {
        r[partialTrueCount] = e_i + 1;
        partialTrueCount++;
      }
    }
    j_X.set_size(r.size(0), 8);
    c_loop_ub = r.size(0);
    if ((static_cast<int>((r.size(0) * 8) < 4)) != 0) {
      for (int i5{0}; i5 < 8; i5++) {
        for (i7 = 0; i7 < c_loop_ub; i7++) {
          j_X[i7 + (j_X.size(0) * i5)] = d_X[(r[i7] + (d_X.size(0) * i5)) - 1];
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i7)

      for (int i5 = 0; i5 < 8; i5++) {
        for (i7 = 0; i7 < c_loop_ub; i7++) {
          j_X[i7 + (j_X.size(0) * i5)] = d_X[(r[i7] + (d_X.size(0) * i5)) - 1];
        }
      }
    }
    weak_learner->predict(j_X, a__2, r3);
    c_end = useObsForLearner.size(0) - 1;
    c_trueCount = 0;
    for (int h_i{0}; h_i <= c_end; h_i++) {
      if (useObsForLearner[h_i]) {
        c_trueCount++;
      }
    }
    r4.set_size(c_trueCount);
    c_partialTrueCount = 0;
    for (int m_i{0}; m_i <= c_end; m_i++) {
      if (useObsForLearner[m_i]) {
        r4[c_partialTrueCount] = m_i + 1;
        c_partialTrueCount++;
      }
    }
    f_loop_ub = r3.size(0);
    for (int i9{0}; i9 < 2; i9++) {
      for (int i11{0}; i11 < f_loop_ub; i11++) {
        learnerscore[(r4[i11] + (learnerscore.size(0) * (iloc[i9] - 1))) - 1] =
            r3[i11 + (r3.size(0) * i9)];
      }
    }
  }
  if (initCache) {
    int b_end;
    int b_partialTrueCount;
    int b_trueCount;
    int d_loop_ub;
    b_end = useObsForLearner.size(0) - 1;
    b_trueCount = 0;
    for (int d_i{0}; d_i <= b_end; d_i++) {
      if (useObsForLearner[d_i]) {
        b_trueCount++;
      }
    }
    r1.set_size(b_trueCount);
    b_partialTrueCount = 0;
    for (int g_i{0}; g_i <= b_end; g_i++) {
      if (useObsForLearner[g_i]) {
        r1[b_partialTrueCount] = g_i + 1;
        b_partialTrueCount++;
      }
    }
    d_loop_ub = r1.size(0);
    for (int i4{0}; i4 < 2; i4++) {
      for (int i6{0}; i6 < d_loop_ub; i6++) {
        cachedScore[(r1[i6] + (cachedScore.size(0) * i4)) - 1] = 0.0;
      }
    }
  } else {
    int b_k;
    int b_loop_ub;
    bool b_varargout_1;
    b_tf.set_size(cachedScore.size(0), 2);
    b_loop_ub = cachedScore.size(0);
    if ((static_cast<int>((b_loop_ub * 2) < 4)) != 0) {
      for (int i2{0}; i2 < 2; i2++) {
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          b_tf[i3 + (b_tf.size(0) * i2)] =
              std::isnan(cachedScore[i3 + (cachedScore.size(0) * i2)]);
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3)

      for (int i2 = 0; i2 < 2; i2++) {
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          b_tf[i3 + (b_tf.size(0) * i2)] =
              std::isnan(cachedScore[i3 + (cachedScore.size(0) * i2)]);
        }
      }
    }
    b_varargout_1 = false;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k <= ((b_tf.size(0) * 2) - 1))) {
      if (b_tf[b_k]) {
        b_varargout_1 = true;
        exitg1 = true;
      } else {
        b_k++;
      }
    }
    if (b_varargout_1) {
      int d_end;
      int d_partialTrueCount;
      int d_trueCount;
      int g_loop_ub;
      r2.set_size(useObsForLearner.size(0), 2);
      if (useObsForLearner.size(0) != 0) {
        int na;
        na = useObsForLearner.size(0);
        if ((static_cast<int>((useObsForLearner.size(0) * 2) < 4)) != 0) {
          for (int b_t{0}; b_t < 2; b_t++) {
            for (c_k = 0; c_k < na; c_k++) {
              r2[c_k + (r2.size(0) * b_t)] = useObsForLearner[c_k];
            }
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(c_k)

          for (int b_t = 0; b_t < 2; b_t++) {
            for (c_k = 0; c_k < na; c_k++) {
              r2[c_k + (r2.size(0) * b_t)] = useObsForLearner[c_k];
            }
          }
        }
      }
      d_end = (b_tf.size(0) * 2) - 1;
      d_trueCount = 0;
      for (int k_i{0}; k_i <= d_end; k_i++) {
        if ((b_tf[k_i]) && (r2[k_i])) {
          d_trueCount++;
        }
      }
      r1.set_size(d_trueCount);
      d_partialTrueCount = 0;
      for (int q_i{0}; q_i <= d_end; q_i++) {
        if ((b_tf[q_i]) && (r2[q_i])) {
          r1[d_partialTrueCount] = q_i + 1;
          d_partialTrueCount++;
        }
      }
      g_loop_ub = r1.size(0);
      for (int i10{0}; i10 < g_loop_ub; i10++) {
        cachedScore[r1[i10] - 1] = 0.0;
      }
    }
  }
  updateCache(learnerscore, cachedScore, cachedWeights, cached,
              b_learnerWeights, combiner, useObsForLearner, score);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i8,      \
                                                                    e_loop_ub)

  for (int c_ii = 0; c_ii < 2; c_ii++) {
    if (!b_classlogicalindices[c_ii]) {
      e_loop_ub = score.size(0);
      for (b_i8 = 0; b_i8 < e_loop_ub; b_i8++) {
        score[b_i8 + (score.size(0) * c_ii)] = rtNaN;
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &d_X
//                ::coder::array<double, 2U> &cachedScore
//                ::coder::array<double, 1U> &cachedWeights
//                const char combiner[15]
//                const
//                ::ITER::coder::classreg::learning::classif::h_CompactClassificationTree
//                *weak_learner double b_learnerWeights bool *cached const
//                double c_classnames[2] const bool b_classlogicalindices[2]
//                const ::coder::array<bool, 1U> &useObsForLearner
//                bool initCache
//                ::coder::array<double, 2U> &score
// Return Type  : void
//
void h_predictOneWithCache(const ::coder::array<double, 2U> &d_X,
                           ::coder::array<double, 2U> &cachedScore,
                           ::coder::array<double, 1U> &cachedWeights,
                           const char combiner[15],
                           const ::ITER::coder::classreg::learning::classif::
                               h_CompactClassificationTree *weak_learner,
                           double b_learnerWeights, bool *cached,
                           const double c_classnames[2],
                           const bool b_classlogicalindices[2],
                           const ::coder::array<bool, 1U> &useObsForLearner,
                           bool initCache, ::coder::array<double, 2U> &score)
{
  ::coder::array<double, 2U> j_X;
  ::coder::array<double, 2U> learnerscore;
  ::coder::array<double, 2U> r3;
  ::coder::array<double, 1U> a__2;
  ::coder::array<int, 1U> r;
  ::coder::array<int, 1U> r1;
  ::coder::array<int, 1U> r4;
  ::coder::array<bool, 2U> b_tf;
  ::coder::array<bool, 2U> r2;
  int iloc[2];
  int b_i8;
  int c_k;
  int cachedScore_idx_0;
  int e_loop_ub;
  int i1;
  int i3;
  int i7;
  int k;
  int loop_ub;
  bool tf[2];
  bool exitg1;
  bool varargout_1;
  cachedScore_idx_0 = cachedScore.size(0);
  learnerscore.set_size(cachedScore_idx_0, 2);
  loop_ub = cachedScore_idx_0;
  if ((static_cast<int>((cachedScore_idx_0 * 2) < 4)) != 0) {
    for (int b_i{0}; b_i < 2; b_i++) {
      for (i1 = 0; i1 < cachedScore_idx_0; i1++) {
        learnerscore[i1 + (learnerscore.size(0) * b_i)] = rtNaN;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1)

    for (int b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        learnerscore[i1 + (learnerscore.size(0) * b_i)] = rtNaN;
      }
    }
  }
  b_local_ismember(weak_learner->ClassNames, c_classnames, tf, iloc);
  varargout_1 = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= (useObsForLearner.size(0) - 1))) {
    if (useObsForLearner[k]) {
      varargout_1 = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (varargout_1) {
    int c_end;
    int c_loop_ub;
    int c_partialTrueCount;
    int c_trueCount;
    int end;
    int f_loop_ub;
    int partialTrueCount;
    int trueCount;
    end = useObsForLearner.size(0) - 1;
    trueCount = 0;
    for (int c_i{0}; c_i <= end; c_i++) {
      if (useObsForLearner[c_i]) {
        trueCount++;
      }
    }
    r.set_size(trueCount);
    partialTrueCount = 0;
    for (int e_i{0}; e_i <= end; e_i++) {
      if (useObsForLearner[e_i]) {
        r[partialTrueCount] = e_i + 1;
        partialTrueCount++;
      }
    }
    j_X.set_size(r.size(0), 8);
    c_loop_ub = r.size(0);
    if ((static_cast<int>((r.size(0) * 8) < 4)) != 0) {
      for (int i5{0}; i5 < 8; i5++) {
        for (i7 = 0; i7 < c_loop_ub; i7++) {
          j_X[i7 + (j_X.size(0) * i5)] = d_X[(r[i7] + (d_X.size(0) * i5)) - 1];
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i7)

      for (int i5 = 0; i5 < 8; i5++) {
        for (i7 = 0; i7 < c_loop_ub; i7++) {
          j_X[i7 + (j_X.size(0) * i5)] = d_X[(r[i7] + (d_X.size(0) * i5)) - 1];
        }
      }
    }
    weak_learner->predict(j_X, a__2, r3);
    c_end = useObsForLearner.size(0) - 1;
    c_trueCount = 0;
    for (int h_i{0}; h_i <= c_end; h_i++) {
      if (useObsForLearner[h_i]) {
        c_trueCount++;
      }
    }
    r4.set_size(c_trueCount);
    c_partialTrueCount = 0;
    for (int m_i{0}; m_i <= c_end; m_i++) {
      if (useObsForLearner[m_i]) {
        r4[c_partialTrueCount] = m_i + 1;
        c_partialTrueCount++;
      }
    }
    f_loop_ub = r3.size(0);
    for (int i9{0}; i9 < 2; i9++) {
      for (int i11{0}; i11 < f_loop_ub; i11++) {
        learnerscore[(r4[i11] + (learnerscore.size(0) * (iloc[i9] - 1))) - 1] =
            r3[i11 + (r3.size(0) * i9)];
      }
    }
  }
  if (initCache) {
    int b_end;
    int b_partialTrueCount;
    int b_trueCount;
    int d_loop_ub;
    b_end = useObsForLearner.size(0) - 1;
    b_trueCount = 0;
    for (int d_i{0}; d_i <= b_end; d_i++) {
      if (useObsForLearner[d_i]) {
        b_trueCount++;
      }
    }
    r1.set_size(b_trueCount);
    b_partialTrueCount = 0;
    for (int g_i{0}; g_i <= b_end; g_i++) {
      if (useObsForLearner[g_i]) {
        r1[b_partialTrueCount] = g_i + 1;
        b_partialTrueCount++;
      }
    }
    d_loop_ub = r1.size(0);
    for (int i4{0}; i4 < 2; i4++) {
      for (int i6{0}; i6 < d_loop_ub; i6++) {
        cachedScore[(r1[i6] + (cachedScore.size(0) * i4)) - 1] = 0.0;
      }
    }
  } else {
    int b_k;
    int b_loop_ub;
    bool b_varargout_1;
    b_tf.set_size(cachedScore.size(0), 2);
    b_loop_ub = cachedScore.size(0);
    if ((static_cast<int>((b_loop_ub * 2) < 4)) != 0) {
      for (int i2{0}; i2 < 2; i2++) {
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          b_tf[i3 + (b_tf.size(0) * i2)] =
              std::isnan(cachedScore[i3 + (cachedScore.size(0) * i2)]);
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3)

      for (int i2 = 0; i2 < 2; i2++) {
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          b_tf[i3 + (b_tf.size(0) * i2)] =
              std::isnan(cachedScore[i3 + (cachedScore.size(0) * i2)]);
        }
      }
    }
    b_varargout_1 = false;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k <= ((b_tf.size(0) * 2) - 1))) {
      if (b_tf[b_k]) {
        b_varargout_1 = true;
        exitg1 = true;
      } else {
        b_k++;
      }
    }
    if (b_varargout_1) {
      int d_end;
      int d_partialTrueCount;
      int d_trueCount;
      int g_loop_ub;
      r2.set_size(useObsForLearner.size(0), 2);
      if (useObsForLearner.size(0) != 0) {
        int na;
        na = useObsForLearner.size(0);
        if ((static_cast<int>((useObsForLearner.size(0) * 2) < 4)) != 0) {
          for (int b_t{0}; b_t < 2; b_t++) {
            for (c_k = 0; c_k < na; c_k++) {
              r2[c_k + (r2.size(0) * b_t)] = useObsForLearner[c_k];
            }
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(c_k)

          for (int b_t = 0; b_t < 2; b_t++) {
            for (c_k = 0; c_k < na; c_k++) {
              r2[c_k + (r2.size(0) * b_t)] = useObsForLearner[c_k];
            }
          }
        }
      }
      d_end = (b_tf.size(0) * 2) - 1;
      d_trueCount = 0;
      for (int k_i{0}; k_i <= d_end; k_i++) {
        if ((b_tf[k_i]) && (r2[k_i])) {
          d_trueCount++;
        }
      }
      r1.set_size(d_trueCount);
      d_partialTrueCount = 0;
      for (int q_i{0}; q_i <= d_end; q_i++) {
        if ((b_tf[q_i]) && (r2[q_i])) {
          r1[d_partialTrueCount] = q_i + 1;
          d_partialTrueCount++;
        }
      }
      g_loop_ub = r1.size(0);
      for (int i10{0}; i10 < g_loop_ub; i10++) {
        cachedScore[r1[i10] - 1] = 0.0;
      }
    }
  }
  updateCache(learnerscore, cachedScore, cachedWeights, cached,
              b_learnerWeights, combiner, useObsForLearner, score);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i8,      \
                                                                    e_loop_ub)

  for (int c_ii = 0; c_ii < 2; c_ii++) {
    if (!b_classlogicalindices[c_ii]) {
      e_loop_ub = score.size(0);
      for (b_i8 = 0; b_i8 < e_loop_ub; b_i8++) {
        score[b_i8 + (score.size(0) * c_ii)] = rtNaN;
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &d_X
//                ::coder::array<double, 2U> &cachedScore
//                ::coder::array<double, 1U> &cachedWeights
//                const char combiner[15]
//                const
//                ::ITER::coder::classreg::learning::classif::i_CompactClassificationTree
//                *weak_learner double b_learnerWeights bool *cached const
//                double c_classnames[2] const bool b_classlogicalindices[2]
//                const ::coder::array<bool, 1U> &useObsForLearner
//                bool initCache
//                ::coder::array<double, 2U> &score
// Return Type  : void
//
void i_predictOneWithCache(const ::coder::array<double, 2U> &d_X,
                           ::coder::array<double, 2U> &cachedScore,
                           ::coder::array<double, 1U> &cachedWeights,
                           const char combiner[15],
                           const ::ITER::coder::classreg::learning::classif::
                               i_CompactClassificationTree *weak_learner,
                           double b_learnerWeights, bool *cached,
                           const double c_classnames[2],
                           const bool b_classlogicalindices[2],
                           const ::coder::array<bool, 1U> &useObsForLearner,
                           bool initCache, ::coder::array<double, 2U> &score)
{
  ::coder::array<double, 2U> j_X;
  ::coder::array<double, 2U> learnerscore;
  ::coder::array<double, 2U> r3;
  ::coder::array<double, 1U> a__2;
  ::coder::array<int, 1U> r;
  ::coder::array<int, 1U> r1;
  ::coder::array<int, 1U> r4;
  ::coder::array<bool, 2U> b_tf;
  ::coder::array<bool, 2U> r2;
  int iloc[2];
  int b_i8;
  int c_k;
  int cachedScore_idx_0;
  int e_loop_ub;
  int i1;
  int i3;
  int i7;
  int k;
  int loop_ub;
  bool tf[2];
  bool exitg1;
  bool varargout_1;
  cachedScore_idx_0 = cachedScore.size(0);
  learnerscore.set_size(cachedScore_idx_0, 2);
  loop_ub = cachedScore_idx_0;
  if ((static_cast<int>((cachedScore_idx_0 * 2) < 4)) != 0) {
    for (int b_i{0}; b_i < 2; b_i++) {
      for (i1 = 0; i1 < cachedScore_idx_0; i1++) {
        learnerscore[i1 + (learnerscore.size(0) * b_i)] = rtNaN;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1)

    for (int b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        learnerscore[i1 + (learnerscore.size(0) * b_i)] = rtNaN;
      }
    }
  }
  b_local_ismember(weak_learner->ClassNames, c_classnames, tf, iloc);
  varargout_1 = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= (useObsForLearner.size(0) - 1))) {
    if (useObsForLearner[k]) {
      varargout_1 = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (varargout_1) {
    int c_end;
    int c_loop_ub;
    int c_partialTrueCount;
    int c_trueCount;
    int end;
    int f_loop_ub;
    int partialTrueCount;
    int trueCount;
    end = useObsForLearner.size(0) - 1;
    trueCount = 0;
    for (int c_i{0}; c_i <= end; c_i++) {
      if (useObsForLearner[c_i]) {
        trueCount++;
      }
    }
    r.set_size(trueCount);
    partialTrueCount = 0;
    for (int e_i{0}; e_i <= end; e_i++) {
      if (useObsForLearner[e_i]) {
        r[partialTrueCount] = e_i + 1;
        partialTrueCount++;
      }
    }
    j_X.set_size(r.size(0), 8);
    c_loop_ub = r.size(0);
    if ((static_cast<int>((r.size(0) * 8) < 4)) != 0) {
      for (int i5{0}; i5 < 8; i5++) {
        for (i7 = 0; i7 < c_loop_ub; i7++) {
          j_X[i7 + (j_X.size(0) * i5)] = d_X[(r[i7] + (d_X.size(0) * i5)) - 1];
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i7)

      for (int i5 = 0; i5 < 8; i5++) {
        for (i7 = 0; i7 < c_loop_ub; i7++) {
          j_X[i7 + (j_X.size(0) * i5)] = d_X[(r[i7] + (d_X.size(0) * i5)) - 1];
        }
      }
    }
    weak_learner->predict(j_X, a__2, r3);
    c_end = useObsForLearner.size(0) - 1;
    c_trueCount = 0;
    for (int h_i{0}; h_i <= c_end; h_i++) {
      if (useObsForLearner[h_i]) {
        c_trueCount++;
      }
    }
    r4.set_size(c_trueCount);
    c_partialTrueCount = 0;
    for (int m_i{0}; m_i <= c_end; m_i++) {
      if (useObsForLearner[m_i]) {
        r4[c_partialTrueCount] = m_i + 1;
        c_partialTrueCount++;
      }
    }
    f_loop_ub = r3.size(0);
    for (int i9{0}; i9 < 2; i9++) {
      for (int i11{0}; i11 < f_loop_ub; i11++) {
        learnerscore[(r4[i11] + (learnerscore.size(0) * (iloc[i9] - 1))) - 1] =
            r3[i11 + (r3.size(0) * i9)];
      }
    }
  }
  if (initCache) {
    int b_end;
    int b_partialTrueCount;
    int b_trueCount;
    int d_loop_ub;
    b_end = useObsForLearner.size(0) - 1;
    b_trueCount = 0;
    for (int d_i{0}; d_i <= b_end; d_i++) {
      if (useObsForLearner[d_i]) {
        b_trueCount++;
      }
    }
    r1.set_size(b_trueCount);
    b_partialTrueCount = 0;
    for (int g_i{0}; g_i <= b_end; g_i++) {
      if (useObsForLearner[g_i]) {
        r1[b_partialTrueCount] = g_i + 1;
        b_partialTrueCount++;
      }
    }
    d_loop_ub = r1.size(0);
    for (int i4{0}; i4 < 2; i4++) {
      for (int i6{0}; i6 < d_loop_ub; i6++) {
        cachedScore[(r1[i6] + (cachedScore.size(0) * i4)) - 1] = 0.0;
      }
    }
  } else {
    int b_k;
    int b_loop_ub;
    bool b_varargout_1;
    b_tf.set_size(cachedScore.size(0), 2);
    b_loop_ub = cachedScore.size(0);
    if ((static_cast<int>((b_loop_ub * 2) < 4)) != 0) {
      for (int i2{0}; i2 < 2; i2++) {
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          b_tf[i3 + (b_tf.size(0) * i2)] =
              std::isnan(cachedScore[i3 + (cachedScore.size(0) * i2)]);
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3)

      for (int i2 = 0; i2 < 2; i2++) {
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          b_tf[i3 + (b_tf.size(0) * i2)] =
              std::isnan(cachedScore[i3 + (cachedScore.size(0) * i2)]);
        }
      }
    }
    b_varargout_1 = false;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k <= ((b_tf.size(0) * 2) - 1))) {
      if (b_tf[b_k]) {
        b_varargout_1 = true;
        exitg1 = true;
      } else {
        b_k++;
      }
    }
    if (b_varargout_1) {
      int d_end;
      int d_partialTrueCount;
      int d_trueCount;
      int g_loop_ub;
      r2.set_size(useObsForLearner.size(0), 2);
      if (useObsForLearner.size(0) != 0) {
        int na;
        na = useObsForLearner.size(0);
        if ((static_cast<int>((useObsForLearner.size(0) * 2) < 4)) != 0) {
          for (int b_t{0}; b_t < 2; b_t++) {
            for (c_k = 0; c_k < na; c_k++) {
              r2[c_k + (r2.size(0) * b_t)] = useObsForLearner[c_k];
            }
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(c_k)

          for (int b_t = 0; b_t < 2; b_t++) {
            for (c_k = 0; c_k < na; c_k++) {
              r2[c_k + (r2.size(0) * b_t)] = useObsForLearner[c_k];
            }
          }
        }
      }
      d_end = (b_tf.size(0) * 2) - 1;
      d_trueCount = 0;
      for (int k_i{0}; k_i <= d_end; k_i++) {
        if ((b_tf[k_i]) && (r2[k_i])) {
          d_trueCount++;
        }
      }
      r1.set_size(d_trueCount);
      d_partialTrueCount = 0;
      for (int q_i{0}; q_i <= d_end; q_i++) {
        if ((b_tf[q_i]) && (r2[q_i])) {
          r1[d_partialTrueCount] = q_i + 1;
          d_partialTrueCount++;
        }
      }
      g_loop_ub = r1.size(0);
      for (int i10{0}; i10 < g_loop_ub; i10++) {
        cachedScore[r1[i10] - 1] = 0.0;
      }
    }
  }
  updateCache(learnerscore, cachedScore, cachedWeights, cached,
              b_learnerWeights, combiner, useObsForLearner, score);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i8,      \
                                                                    e_loop_ub)

  for (int c_ii = 0; c_ii < 2; c_ii++) {
    if (!b_classlogicalindices[c_ii]) {
      e_loop_ub = score.size(0);
      for (b_i8 = 0; b_i8 < e_loop_ub; b_i8++) {
        score[b_i8 + (score.size(0) * c_ii)] = rtNaN;
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &d_X
//                ::coder::array<double, 2U> &cachedScore
//                ::coder::array<double, 1U> &cachedWeights
//                const char combiner[15]
//                const
//                ::ITER::coder::classreg::learning::classif::j_CompactClassificationTree
//                *weak_learner double b_learnerWeights bool *cached const
//                double c_classnames[2] const bool b_classlogicalindices[2]
//                const ::coder::array<bool, 1U> &useObsForLearner
//                bool initCache
//                ::coder::array<double, 2U> &score
// Return Type  : void
//
void j_predictOneWithCache(const ::coder::array<double, 2U> &d_X,
                           ::coder::array<double, 2U> &cachedScore,
                           ::coder::array<double, 1U> &cachedWeights,
                           const char combiner[15],
                           const ::ITER::coder::classreg::learning::classif::
                               j_CompactClassificationTree *weak_learner,
                           double b_learnerWeights, bool *cached,
                           const double c_classnames[2],
                           const bool b_classlogicalindices[2],
                           const ::coder::array<bool, 1U> &useObsForLearner,
                           bool initCache, ::coder::array<double, 2U> &score)
{
  ::coder::array<double, 2U> j_X;
  ::coder::array<double, 2U> learnerscore;
  ::coder::array<double, 2U> r3;
  ::coder::array<double, 1U> a__2;
  ::coder::array<int, 1U> r;
  ::coder::array<int, 1U> r1;
  ::coder::array<int, 1U> r4;
  ::coder::array<bool, 2U> b_tf;
  ::coder::array<bool, 2U> r2;
  int iloc[2];
  int b_i8;
  int c_k;
  int cachedScore_idx_0;
  int e_loop_ub;
  int i1;
  int i3;
  int i7;
  int k;
  int loop_ub;
  bool tf[2];
  bool exitg1;
  bool varargout_1;
  cachedScore_idx_0 = cachedScore.size(0);
  learnerscore.set_size(cachedScore_idx_0, 2);
  loop_ub = cachedScore_idx_0;
  if ((static_cast<int>((cachedScore_idx_0 * 2) < 4)) != 0) {
    for (int b_i{0}; b_i < 2; b_i++) {
      for (i1 = 0; i1 < cachedScore_idx_0; i1++) {
        learnerscore[i1 + (learnerscore.size(0) * b_i)] = rtNaN;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1)

    for (int b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        learnerscore[i1 + (learnerscore.size(0) * b_i)] = rtNaN;
      }
    }
  }
  b_local_ismember(weak_learner->ClassNames, c_classnames, tf, iloc);
  varargout_1 = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= (useObsForLearner.size(0) - 1))) {
    if (useObsForLearner[k]) {
      varargout_1 = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (varargout_1) {
    int c_end;
    int c_loop_ub;
    int c_partialTrueCount;
    int c_trueCount;
    int end;
    int f_loop_ub;
    int partialTrueCount;
    int trueCount;
    end = useObsForLearner.size(0) - 1;
    trueCount = 0;
    for (int c_i{0}; c_i <= end; c_i++) {
      if (useObsForLearner[c_i]) {
        trueCount++;
      }
    }
    r.set_size(trueCount);
    partialTrueCount = 0;
    for (int e_i{0}; e_i <= end; e_i++) {
      if (useObsForLearner[e_i]) {
        r[partialTrueCount] = e_i + 1;
        partialTrueCount++;
      }
    }
    j_X.set_size(r.size(0), 8);
    c_loop_ub = r.size(0);
    if ((static_cast<int>((r.size(0) * 8) < 4)) != 0) {
      for (int i5{0}; i5 < 8; i5++) {
        for (i7 = 0; i7 < c_loop_ub; i7++) {
          j_X[i7 + (j_X.size(0) * i5)] = d_X[(r[i7] + (d_X.size(0) * i5)) - 1];
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i7)

      for (int i5 = 0; i5 < 8; i5++) {
        for (i7 = 0; i7 < c_loop_ub; i7++) {
          j_X[i7 + (j_X.size(0) * i5)] = d_X[(r[i7] + (d_X.size(0) * i5)) - 1];
        }
      }
    }
    weak_learner->predict(j_X, a__2, r3);
    c_end = useObsForLearner.size(0) - 1;
    c_trueCount = 0;
    for (int h_i{0}; h_i <= c_end; h_i++) {
      if (useObsForLearner[h_i]) {
        c_trueCount++;
      }
    }
    r4.set_size(c_trueCount);
    c_partialTrueCount = 0;
    for (int m_i{0}; m_i <= c_end; m_i++) {
      if (useObsForLearner[m_i]) {
        r4[c_partialTrueCount] = m_i + 1;
        c_partialTrueCount++;
      }
    }
    f_loop_ub = r3.size(0);
    for (int i9{0}; i9 < 2; i9++) {
      for (int i11{0}; i11 < f_loop_ub; i11++) {
        learnerscore[(r4[i11] + (learnerscore.size(0) * (iloc[i9] - 1))) - 1] =
            r3[i11 + (r3.size(0) * i9)];
      }
    }
  }
  if (initCache) {
    int b_end;
    int b_partialTrueCount;
    int b_trueCount;
    int d_loop_ub;
    b_end = useObsForLearner.size(0) - 1;
    b_trueCount = 0;
    for (int d_i{0}; d_i <= b_end; d_i++) {
      if (useObsForLearner[d_i]) {
        b_trueCount++;
      }
    }
    r1.set_size(b_trueCount);
    b_partialTrueCount = 0;
    for (int g_i{0}; g_i <= b_end; g_i++) {
      if (useObsForLearner[g_i]) {
        r1[b_partialTrueCount] = g_i + 1;
        b_partialTrueCount++;
      }
    }
    d_loop_ub = r1.size(0);
    for (int i4{0}; i4 < 2; i4++) {
      for (int i6{0}; i6 < d_loop_ub; i6++) {
        cachedScore[(r1[i6] + (cachedScore.size(0) * i4)) - 1] = 0.0;
      }
    }
  } else {
    int b_k;
    int b_loop_ub;
    bool b_varargout_1;
    b_tf.set_size(cachedScore.size(0), 2);
    b_loop_ub = cachedScore.size(0);
    if ((static_cast<int>((b_loop_ub * 2) < 4)) != 0) {
      for (int i2{0}; i2 < 2; i2++) {
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          b_tf[i3 + (b_tf.size(0) * i2)] =
              std::isnan(cachedScore[i3 + (cachedScore.size(0) * i2)]);
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3)

      for (int i2 = 0; i2 < 2; i2++) {
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          b_tf[i3 + (b_tf.size(0) * i2)] =
              std::isnan(cachedScore[i3 + (cachedScore.size(0) * i2)]);
        }
      }
    }
    b_varargout_1 = false;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k <= ((b_tf.size(0) * 2) - 1))) {
      if (b_tf[b_k]) {
        b_varargout_1 = true;
        exitg1 = true;
      } else {
        b_k++;
      }
    }
    if (b_varargout_1) {
      int d_end;
      int d_partialTrueCount;
      int d_trueCount;
      int g_loop_ub;
      r2.set_size(useObsForLearner.size(0), 2);
      if (useObsForLearner.size(0) != 0) {
        int na;
        na = useObsForLearner.size(0);
        if ((static_cast<int>((useObsForLearner.size(0) * 2) < 4)) != 0) {
          for (int b_t{0}; b_t < 2; b_t++) {
            for (c_k = 0; c_k < na; c_k++) {
              r2[c_k + (r2.size(0) * b_t)] = useObsForLearner[c_k];
            }
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(c_k)

          for (int b_t = 0; b_t < 2; b_t++) {
            for (c_k = 0; c_k < na; c_k++) {
              r2[c_k + (r2.size(0) * b_t)] = useObsForLearner[c_k];
            }
          }
        }
      }
      d_end = (b_tf.size(0) * 2) - 1;
      d_trueCount = 0;
      for (int k_i{0}; k_i <= d_end; k_i++) {
        if ((b_tf[k_i]) && (r2[k_i])) {
          d_trueCount++;
        }
      }
      r1.set_size(d_trueCount);
      d_partialTrueCount = 0;
      for (int q_i{0}; q_i <= d_end; q_i++) {
        if ((b_tf[q_i]) && (r2[q_i])) {
          r1[d_partialTrueCount] = q_i + 1;
          d_partialTrueCount++;
        }
      }
      g_loop_ub = r1.size(0);
      for (int i10{0}; i10 < g_loop_ub; i10++) {
        cachedScore[r1[i10] - 1] = 0.0;
      }
    }
  }
  updateCache(learnerscore, cachedScore, cachedWeights, cached,
              b_learnerWeights, combiner, useObsForLearner, score);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i8,      \
                                                                    e_loop_ub)

  for (int c_ii = 0; c_ii < 2; c_ii++) {
    if (!b_classlogicalindices[c_ii]) {
      e_loop_ub = score.size(0);
      for (b_i8 = 0; b_i8 < e_loop_ub; b_i8++) {
        score[b_i8 + (score.size(0) * c_ii)] = rtNaN;
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &d_X
//                ::coder::array<double, 2U> &cachedScore
//                ::coder::array<double, 1U> &cachedWeights
//                const char combiner[15]
//                const
//                ::ITER::coder::classreg::learning::classif::k_CompactClassificationTree
//                *weak_learner double b_learnerWeights bool *cached const
//                double c_classnames[2] const bool b_classlogicalindices[2]
//                const ::coder::array<bool, 1U> &useObsForLearner
//                bool initCache
//                ::coder::array<double, 2U> &score
// Return Type  : void
//
void k_predictOneWithCache(const ::coder::array<double, 2U> &d_X,
                           ::coder::array<double, 2U> &cachedScore,
                           ::coder::array<double, 1U> &cachedWeights,
                           const char combiner[15],
                           const ::ITER::coder::classreg::learning::classif::
                               k_CompactClassificationTree *weak_learner,
                           double b_learnerWeights, bool *cached,
                           const double c_classnames[2],
                           const bool b_classlogicalindices[2],
                           const ::coder::array<bool, 1U> &useObsForLearner,
                           bool initCache, ::coder::array<double, 2U> &score)
{
  ::coder::array<double, 2U> j_X;
  ::coder::array<double, 2U> learnerscore;
  ::coder::array<double, 2U> r3;
  ::coder::array<double, 1U> a__2;
  ::coder::array<int, 1U> r;
  ::coder::array<int, 1U> r1;
  ::coder::array<int, 1U> r4;
  ::coder::array<bool, 2U> b_tf;
  ::coder::array<bool, 2U> r2;
  int iloc[2];
  int b_i8;
  int c_k;
  int cachedScore_idx_0;
  int e_loop_ub;
  int i1;
  int i3;
  int i7;
  int k;
  int loop_ub;
  bool tf[2];
  bool exitg1;
  bool varargout_1;
  cachedScore_idx_0 = cachedScore.size(0);
  learnerscore.set_size(cachedScore_idx_0, 2);
  loop_ub = cachedScore_idx_0;
  if ((static_cast<int>((cachedScore_idx_0 * 2) < 4)) != 0) {
    for (int b_i{0}; b_i < 2; b_i++) {
      for (i1 = 0; i1 < cachedScore_idx_0; i1++) {
        learnerscore[i1 + (learnerscore.size(0) * b_i)] = rtNaN;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1)

    for (int b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        learnerscore[i1 + (learnerscore.size(0) * b_i)] = rtNaN;
      }
    }
  }
  b_local_ismember(weak_learner->ClassNames, c_classnames, tf, iloc);
  varargout_1 = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= (useObsForLearner.size(0) - 1))) {
    if (useObsForLearner[k]) {
      varargout_1 = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (varargout_1) {
    int c_end;
    int c_loop_ub;
    int c_partialTrueCount;
    int c_trueCount;
    int end;
    int f_loop_ub;
    int partialTrueCount;
    int trueCount;
    end = useObsForLearner.size(0) - 1;
    trueCount = 0;
    for (int c_i{0}; c_i <= end; c_i++) {
      if (useObsForLearner[c_i]) {
        trueCount++;
      }
    }
    r.set_size(trueCount);
    partialTrueCount = 0;
    for (int e_i{0}; e_i <= end; e_i++) {
      if (useObsForLearner[e_i]) {
        r[partialTrueCount] = e_i + 1;
        partialTrueCount++;
      }
    }
    j_X.set_size(r.size(0), 8);
    c_loop_ub = r.size(0);
    if ((static_cast<int>((r.size(0) * 8) < 4)) != 0) {
      for (int i5{0}; i5 < 8; i5++) {
        for (i7 = 0; i7 < c_loop_ub; i7++) {
          j_X[i7 + (j_X.size(0) * i5)] = d_X[(r[i7] + (d_X.size(0) * i5)) - 1];
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i7)

      for (int i5 = 0; i5 < 8; i5++) {
        for (i7 = 0; i7 < c_loop_ub; i7++) {
          j_X[i7 + (j_X.size(0) * i5)] = d_X[(r[i7] + (d_X.size(0) * i5)) - 1];
        }
      }
    }
    weak_learner->predict(j_X, a__2, r3);
    c_end = useObsForLearner.size(0) - 1;
    c_trueCount = 0;
    for (int h_i{0}; h_i <= c_end; h_i++) {
      if (useObsForLearner[h_i]) {
        c_trueCount++;
      }
    }
    r4.set_size(c_trueCount);
    c_partialTrueCount = 0;
    for (int m_i{0}; m_i <= c_end; m_i++) {
      if (useObsForLearner[m_i]) {
        r4[c_partialTrueCount] = m_i + 1;
        c_partialTrueCount++;
      }
    }
    f_loop_ub = r3.size(0);
    for (int i9{0}; i9 < 2; i9++) {
      for (int i11{0}; i11 < f_loop_ub; i11++) {
        learnerscore[(r4[i11] + (learnerscore.size(0) * (iloc[i9] - 1))) - 1] =
            r3[i11 + (r3.size(0) * i9)];
      }
    }
  }
  if (initCache) {
    int b_end;
    int b_partialTrueCount;
    int b_trueCount;
    int d_loop_ub;
    b_end = useObsForLearner.size(0) - 1;
    b_trueCount = 0;
    for (int d_i{0}; d_i <= b_end; d_i++) {
      if (useObsForLearner[d_i]) {
        b_trueCount++;
      }
    }
    r1.set_size(b_trueCount);
    b_partialTrueCount = 0;
    for (int g_i{0}; g_i <= b_end; g_i++) {
      if (useObsForLearner[g_i]) {
        r1[b_partialTrueCount] = g_i + 1;
        b_partialTrueCount++;
      }
    }
    d_loop_ub = r1.size(0);
    for (int i4{0}; i4 < 2; i4++) {
      for (int i6{0}; i6 < d_loop_ub; i6++) {
        cachedScore[(r1[i6] + (cachedScore.size(0) * i4)) - 1] = 0.0;
      }
    }
  } else {
    int b_k;
    int b_loop_ub;
    bool b_varargout_1;
    b_tf.set_size(cachedScore.size(0), 2);
    b_loop_ub = cachedScore.size(0);
    if ((static_cast<int>((b_loop_ub * 2) < 4)) != 0) {
      for (int i2{0}; i2 < 2; i2++) {
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          b_tf[i3 + (b_tf.size(0) * i2)] =
              std::isnan(cachedScore[i3 + (cachedScore.size(0) * i2)]);
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3)

      for (int i2 = 0; i2 < 2; i2++) {
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          b_tf[i3 + (b_tf.size(0) * i2)] =
              std::isnan(cachedScore[i3 + (cachedScore.size(0) * i2)]);
        }
      }
    }
    b_varargout_1 = false;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k <= ((b_tf.size(0) * 2) - 1))) {
      if (b_tf[b_k]) {
        b_varargout_1 = true;
        exitg1 = true;
      } else {
        b_k++;
      }
    }
    if (b_varargout_1) {
      int d_end;
      int d_partialTrueCount;
      int d_trueCount;
      int g_loop_ub;
      r2.set_size(useObsForLearner.size(0), 2);
      if (useObsForLearner.size(0) != 0) {
        int na;
        na = useObsForLearner.size(0);
        if ((static_cast<int>((useObsForLearner.size(0) * 2) < 4)) != 0) {
          for (int b_t{0}; b_t < 2; b_t++) {
            for (c_k = 0; c_k < na; c_k++) {
              r2[c_k + (r2.size(0) * b_t)] = useObsForLearner[c_k];
            }
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(c_k)

          for (int b_t = 0; b_t < 2; b_t++) {
            for (c_k = 0; c_k < na; c_k++) {
              r2[c_k + (r2.size(0) * b_t)] = useObsForLearner[c_k];
            }
          }
        }
      }
      d_end = (b_tf.size(0) * 2) - 1;
      d_trueCount = 0;
      for (int k_i{0}; k_i <= d_end; k_i++) {
        if ((b_tf[k_i]) && (r2[k_i])) {
          d_trueCount++;
        }
      }
      r1.set_size(d_trueCount);
      d_partialTrueCount = 0;
      for (int q_i{0}; q_i <= d_end; q_i++) {
        if ((b_tf[q_i]) && (r2[q_i])) {
          r1[d_partialTrueCount] = q_i + 1;
          d_partialTrueCount++;
        }
      }
      g_loop_ub = r1.size(0);
      for (int i10{0}; i10 < g_loop_ub; i10++) {
        cachedScore[r1[i10] - 1] = 0.0;
      }
    }
  }
  updateCache(learnerscore, cachedScore, cachedWeights, cached,
              b_learnerWeights, combiner, useObsForLearner, score);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i8,      \
                                                                    e_loop_ub)

  for (int c_ii = 0; c_ii < 2; c_ii++) {
    if (!b_classlogicalindices[c_ii]) {
      e_loop_ub = score.size(0);
      for (b_i8 = 0; b_i8 < e_loop_ub; b_i8++) {
        score[b_i8 + (score.size(0) * c_ii)] = rtNaN;
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &d_X
//                ::coder::array<double, 2U> &cachedScore
//                ::coder::array<double, 1U> &cachedWeights
//                const char combiner[15]
//                const
//                ::ITER::coder::classreg::learning::classif::CompactClassificationTree
//                *weak_learner double b_learnerWeights bool *cached const
//                double c_classnames[2] const bool b_classlogicalindices[2]
//                const ::coder::array<bool, 1U> &useObsForLearner
//                bool initCache
//                ::coder::array<double, 2U> &score
// Return Type  : void
//
void predictOneWithCache(
    const ::coder::array<double, 2U> &d_X,
    ::coder::array<double, 2U> &cachedScore,
    ::coder::array<double, 1U> &cachedWeights, const char combiner[15],
    const ::ITER::coder::classreg::learning::classif::CompactClassificationTree
        *weak_learner,
    double b_learnerWeights, bool *cached, const double c_classnames[2],
    const bool b_classlogicalindices[2],
    const ::coder::array<bool, 1U> &useObsForLearner, bool initCache,
    ::coder::array<double, 2U> &score)
{
  ::coder::array<double, 2U> j_X;
  ::coder::array<double, 2U> learnerscore;
  ::coder::array<double, 2U> r3;
  ::coder::array<double, 1U> a__2;
  ::coder::array<int, 1U> r;
  ::coder::array<int, 1U> r1;
  ::coder::array<int, 1U> r4;
  ::coder::array<bool, 2U> b_tf;
  ::coder::array<bool, 2U> r2;
  int iloc[2];
  int b_i8;
  int c_k;
  int cachedScore_idx_0;
  int e_loop_ub;
  int i1;
  int i3;
  int i7;
  int k;
  int loop_ub;
  bool tf[2];
  bool exitg1;
  bool varargout_1;
  cachedScore_idx_0 = cachedScore.size(0);
  learnerscore.set_size(cachedScore_idx_0, 2);
  loop_ub = cachedScore_idx_0;
  if ((static_cast<int>((cachedScore_idx_0 * 2) < 4)) != 0) {
    for (int b_i{0}; b_i < 2; b_i++) {
      for (i1 = 0; i1 < cachedScore_idx_0; i1++) {
        learnerscore[i1 + (learnerscore.size(0) * b_i)] = rtNaN;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1)

    for (int b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        learnerscore[i1 + (learnerscore.size(0) * b_i)] = rtNaN;
      }
    }
  }
  b_local_ismember(weak_learner->ClassNames, c_classnames, tf, iloc);
  varargout_1 = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= (useObsForLearner.size(0) - 1))) {
    if (useObsForLearner[k]) {
      varargout_1 = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (varargout_1) {
    int c_end;
    int c_loop_ub;
    int c_partialTrueCount;
    int c_trueCount;
    int end;
    int f_loop_ub;
    int partialTrueCount;
    int trueCount;
    end = useObsForLearner.size(0) - 1;
    trueCount = 0;
    for (int c_i{0}; c_i <= end; c_i++) {
      if (useObsForLearner[c_i]) {
        trueCount++;
      }
    }
    r.set_size(trueCount);
    partialTrueCount = 0;
    for (int e_i{0}; e_i <= end; e_i++) {
      if (useObsForLearner[e_i]) {
        r[partialTrueCount] = e_i + 1;
        partialTrueCount++;
      }
    }
    j_X.set_size(r.size(0), 8);
    c_loop_ub = r.size(0);
    if ((static_cast<int>((r.size(0) * 8) < 4)) != 0) {
      for (int i5{0}; i5 < 8; i5++) {
        for (i7 = 0; i7 < c_loop_ub; i7++) {
          j_X[i7 + (j_X.size(0) * i5)] = d_X[(r[i7] + (d_X.size(0) * i5)) - 1];
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i7)

      for (int i5 = 0; i5 < 8; i5++) {
        for (i7 = 0; i7 < c_loop_ub; i7++) {
          j_X[i7 + (j_X.size(0) * i5)] = d_X[(r[i7] + (d_X.size(0) * i5)) - 1];
        }
      }
    }
    weak_learner->predict(j_X, a__2, r3);
    c_end = useObsForLearner.size(0) - 1;
    c_trueCount = 0;
    for (int h_i{0}; h_i <= c_end; h_i++) {
      if (useObsForLearner[h_i]) {
        c_trueCount++;
      }
    }
    r4.set_size(c_trueCount);
    c_partialTrueCount = 0;
    for (int m_i{0}; m_i <= c_end; m_i++) {
      if (useObsForLearner[m_i]) {
        r4[c_partialTrueCount] = m_i + 1;
        c_partialTrueCount++;
      }
    }
    f_loop_ub = r3.size(0);
    for (int i9{0}; i9 < 2; i9++) {
      for (int i11{0}; i11 < f_loop_ub; i11++) {
        learnerscore[(r4[i11] + (learnerscore.size(0) * (iloc[i9] - 1))) - 1] =
            r3[i11 + (r3.size(0) * i9)];
      }
    }
  }
  if (initCache) {
    int b_end;
    int b_partialTrueCount;
    int b_trueCount;
    int d_loop_ub;
    b_end = useObsForLearner.size(0) - 1;
    b_trueCount = 0;
    for (int d_i{0}; d_i <= b_end; d_i++) {
      if (useObsForLearner[d_i]) {
        b_trueCount++;
      }
    }
    r1.set_size(b_trueCount);
    b_partialTrueCount = 0;
    for (int g_i{0}; g_i <= b_end; g_i++) {
      if (useObsForLearner[g_i]) {
        r1[b_partialTrueCount] = g_i + 1;
        b_partialTrueCount++;
      }
    }
    d_loop_ub = r1.size(0);
    for (int i4{0}; i4 < 2; i4++) {
      for (int i6{0}; i6 < d_loop_ub; i6++) {
        cachedScore[(r1[i6] + (cachedScore.size(0) * i4)) - 1] = 0.0;
      }
    }
  } else {
    int b_k;
    int b_loop_ub;
    bool b_varargout_1;
    b_tf.set_size(cachedScore.size(0), 2);
    b_loop_ub = cachedScore.size(0);
    if ((static_cast<int>((b_loop_ub * 2) < 4)) != 0) {
      for (int i2{0}; i2 < 2; i2++) {
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          b_tf[i3 + (b_tf.size(0) * i2)] =
              std::isnan(cachedScore[i3 + (cachedScore.size(0) * i2)]);
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3)

      for (int i2 = 0; i2 < 2; i2++) {
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          b_tf[i3 + (b_tf.size(0) * i2)] =
              std::isnan(cachedScore[i3 + (cachedScore.size(0) * i2)]);
        }
      }
    }
    b_varargout_1 = false;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k <= ((b_tf.size(0) * 2) - 1))) {
      if (b_tf[b_k]) {
        b_varargout_1 = true;
        exitg1 = true;
      } else {
        b_k++;
      }
    }
    if (b_varargout_1) {
      int d_end;
      int d_partialTrueCount;
      int d_trueCount;
      int g_loop_ub;
      r2.set_size(useObsForLearner.size(0), 2);
      if (useObsForLearner.size(0) != 0) {
        int na;
        na = useObsForLearner.size(0);
        if ((static_cast<int>((useObsForLearner.size(0) * 2) < 4)) != 0) {
          for (int b_t{0}; b_t < 2; b_t++) {
            for (c_k = 0; c_k < na; c_k++) {
              r2[c_k + (r2.size(0) * b_t)] = useObsForLearner[c_k];
            }
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(c_k)

          for (int b_t = 0; b_t < 2; b_t++) {
            for (c_k = 0; c_k < na; c_k++) {
              r2[c_k + (r2.size(0) * b_t)] = useObsForLearner[c_k];
            }
          }
        }
      }
      d_end = (b_tf.size(0) * 2) - 1;
      d_trueCount = 0;
      for (int k_i{0}; k_i <= d_end; k_i++) {
        if ((b_tf[k_i]) && (r2[k_i])) {
          d_trueCount++;
        }
      }
      r1.set_size(d_trueCount);
      d_partialTrueCount = 0;
      for (int q_i{0}; q_i <= d_end; q_i++) {
        if ((b_tf[q_i]) && (r2[q_i])) {
          r1[d_partialTrueCount] = q_i + 1;
          d_partialTrueCount++;
        }
      }
      g_loop_ub = r1.size(0);
      for (int i10{0}; i10 < g_loop_ub; i10++) {
        cachedScore[r1[i10] - 1] = 0.0;
      }
    }
  }
  updateCache(learnerscore, cachedScore, cachedWeights, cached,
              b_learnerWeights, combiner, useObsForLearner, score);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i8,      \
                                                                    e_loop_ub)

  for (int c_ii = 0; c_ii < 2; c_ii++) {
    if (!b_classlogicalindices[c_ii]) {
      e_loop_ub = score.size(0);
      for (b_i8 = 0; b_i8 < e_loop_ub; b_i8++) {
        score[b_i8 + (score.size(0) * c_ii)] = rtNaN;
      }
    }
  }
}

} // namespace ensembleutils
} // namespace coder
} // namespace learning
} // namespace classreg
} // namespace coder
} // namespace ITER

//
// File trailer for predictOneWithCache.cpp
//
// [EOF]
//
