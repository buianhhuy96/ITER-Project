//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: aggregatePredict.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "aggregatePredict.h"
#include "CompactClassificationTree.h"
#include "predictOneWithCache.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &d_X
//                ::coder::array<double, 2U> &score
//                const double b_learnerWeights[100]
//                const bool b_isCached[100]
//                const double b_classNames[2]
//                const bool b_classlogicalindices[2]
//                const bool learners[100]
//                const ::coder::array<bool, 2U> &useObsForLearner
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace classreg {
namespace learning {
namespace coder {
namespace ensembleutils {
void aggregatePredict(const ::coder::array<double, 2U> &d_X,
                      ::coder::array<double, 2U> &score,
                      const double b_learnerWeights[100],
                      const bool b_isCached[100], const double b_classNames[2],
                      const bool b_classlogicalindices[2],
                      const bool learners[100],
                      const ::coder::array<bool, 2U> &useObsForLearner)
{
  static const char combiner[15]{'W', 'e', 'i', 'g', 'h', 't', 'e', 'd',
                                 'A', 'v', 'e', 'r', 'a', 'g', 'e'};
  ::ITER::coder::classreg::learning::classif::CompactClassificationTree
      weak_learner;
  ::ITER::coder::classreg::learning::classif::b_CompactClassificationTree
      b_weak_learner;
  ::ITER::coder::classreg::learning::classif::c_CompactClassificationTree
      c_weak_learner;
  ::ITER::coder::classreg::learning::classif::d_CompactClassificationTree
      d_weak_learner;
  ::ITER::coder::classreg::learning::classif::e_CompactClassificationTree
      e_weak_learner;
  ::ITER::coder::classreg::learning::classif::f_CompactClassificationTree
      f_weak_learner;
  ::ITER::coder::classreg::learning::classif::g_CompactClassificationTree
      g_weak_learner;
  ::ITER::coder::classreg::learning::classif::h_CompactClassificationTree
      h_weak_learner;
  ::ITER::coder::classreg::learning::classif::i_CompactClassificationTree
      i_weak_learner;
  ::ITER::coder::classreg::learning::classif::j_CompactClassificationTree
      j_weak_learner;
  ::ITER::coder::classreg::learning::classif::k_CompactClassificationTree
      k_weak_learner;
  ::coder::array<double, 2U> cachedScore;
  ::coder::array<double, 1U> cachedWeights;
  ::coder::array<bool, 1U> b_useObsForLearner;
  int b_loop_ub;
  int i1;
  int loop_ub;
  int score_idx_0;
  bool b;
  bool firstCache;
  bool initCache;
  cachedScore.set_size(score.size(0), 2);
  loop_ub = score.size(0);
  if ((static_cast<int>((loop_ub * 2) < 4)) != 0) {
    for (int b_i{0}; b_i < 2; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        cachedScore[i1 + (cachedScore.size(0) * b_i)] =
            score[i1 + (score.size(0) * b_i)];
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1)

    for (int b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        cachedScore[i1 + (cachedScore.size(0) * b_i)] =
            score[i1 + (score.size(0) * b_i)];
      }
    }
  }
  score_idx_0 = score.size(0);
  cachedWeights.set_size(score_idx_0);
  b_loop_ub = score_idx_0;
  if ((static_cast<int>(score_idx_0 < 4)) != 0) {
    for (int i2{0}; i2 < score_idx_0; i2++) {
      cachedWeights[i2] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i2 = 0; i2 < b_loop_ub; i2++) {
      cachedWeights[i2] = 0.0;
    }
  }
  firstCache = true;
  if (learners[0]) {
    int c_loop_ub;
    int d_loop_ub;
    firstCache = false;
    weak_learner.init();
    b = b_isCached[0];
    c_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    d_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i3{0}; i3 < c_loop_ub; i3++) {
        b_useObsForLearner[i3] = useObsForLearner[i3];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i3 = 0; i3 < d_loop_ub; i3++) {
        b_useObsForLearner[i3] = useObsForLearner[i3];
      }
    }
    predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                        &weak_learner, b_learnerWeights[0], &b, b_classNames,
                        b_classlogicalindices, b_useObsForLearner, true, score);
  }
  if (learners[1]) {
    int e_loop_ub;
    int g_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b_weak_learner.init();
    b = b_isCached[1];
    e_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    g_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i4{0}; i4 < e_loop_ub; i4++) {
        b_useObsForLearner[i4] =
            useObsForLearner[i4 + useObsForLearner.size(0)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i4 = 0; i4 < g_loop_ub; i4++) {
        b_useObsForLearner[i4] =
            useObsForLearner[i4 + useObsForLearner.size(0)];
      }
    }
    b_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &b_weak_learner, b_learnerWeights[1], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[2]) {
    int f_loop_ub;
    int i_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    c_weak_learner.init();
    b = b_isCached[2];
    f_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    i_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i5{0}; i5 < f_loop_ub; i5++) {
        b_useObsForLearner[i5] =
            useObsForLearner[i5 + (useObsForLearner.size(0) * 2)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i5 = 0; i5 < i_loop_ub; i5++) {
        b_useObsForLearner[i5] =
            useObsForLearner[i5 + (useObsForLearner.size(0) * 2)];
      }
    }
    c_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &c_weak_learner, b_learnerWeights[2], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[3]) {
    int h_loop_ub;
    int k_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b_weak_learner.b_init();
    b = b_isCached[3];
    h_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    k_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i6{0}; i6 < h_loop_ub; i6++) {
        b_useObsForLearner[i6] =
            useObsForLearner[i6 + (useObsForLearner.size(0) * 3)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i6 = 0; i6 < k_loop_ub; i6++) {
        b_useObsForLearner[i6] =
            useObsForLearner[i6 + (useObsForLearner.size(0) * 3)];
      }
    }
    b_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &b_weak_learner, b_learnerWeights[3], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[4]) {
    int j_loop_ub;
    int o_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b_weak_learner.c_init();
    b = b_isCached[4];
    j_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    o_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i7{0}; i7 < j_loop_ub; i7++) {
        b_useObsForLearner[i7] =
            useObsForLearner[i7 + (useObsForLearner.size(0) * 4)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i7 = 0; i7 < o_loop_ub; i7++) {
        b_useObsForLearner[i7] =
            useObsForLearner[i7 + (useObsForLearner.size(0) * 4)];
      }
    }
    b_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &b_weak_learner, b_learnerWeights[4], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[5]) {
    int m_loop_ub;
    int q_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    d_weak_learner.init();
    b = b_isCached[5];
    m_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    q_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int b_i8{0}; b_i8 < m_loop_ub; b_i8++) {
        b_useObsForLearner[b_i8] =
            useObsForLearner[b_i8 + (useObsForLearner.size(0) * 5)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int b_i8 = 0; b_i8 < q_loop_ub; b_i8++) {
        b_useObsForLearner[b_i8] =
            useObsForLearner[b_i8 + (useObsForLearner.size(0) * 5)];
      }
    }
    d_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &d_weak_learner, b_learnerWeights[5], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[6]) {
    int p_loop_ub;
    int s_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    e_weak_learner.init();
    b = b_isCached[6];
    p_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    s_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i9{0}; i9 < p_loop_ub; i9++) {
        b_useObsForLearner[i9] =
            useObsForLearner[i9 + (useObsForLearner.size(0) * 6)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i9 = 0; i9 < s_loop_ub; i9++) {
        b_useObsForLearner[i9] =
            useObsForLearner[i9 + (useObsForLearner.size(0) * 6)];
      }
    }
    e_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &e_weak_learner, b_learnerWeights[6], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[7]) {
    int r_loop_ub;
    int u_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    d_weak_learner.b_init();
    b = b_isCached[7];
    r_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    u_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i10{0}; i10 < r_loop_ub; i10++) {
        b_useObsForLearner[i10] =
            useObsForLearner[i10 + (useObsForLearner.size(0) * 7)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i10 = 0; i10 < u_loop_ub; i10++) {
        b_useObsForLearner[i10] =
            useObsForLearner[i10 + (useObsForLearner.size(0) * 7)];
      }
    }
    d_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &d_weak_learner, b_learnerWeights[7], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[8]) {
    int t_loop_ub;
    int w_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    f_weak_learner.init();
    b = b_isCached[8];
    t_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    w_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i11{0}; i11 < t_loop_ub; i11++) {
        b_useObsForLearner[i11] =
            useObsForLearner[i11 + (useObsForLearner.size(0) * 8)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i11 = 0; i11 < w_loop_ub; i11++) {
        b_useObsForLearner[i11] =
            useObsForLearner[i11 + (useObsForLearner.size(0) * 8)];
      }
    }
    f_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &f_weak_learner, b_learnerWeights[8], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[9]) {
    int v_loop_ub;
    int y_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    c_weak_learner.b_init();
    b = b_isCached[9];
    v_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    y_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i12{0}; i12 < v_loop_ub; i12++) {
        b_useObsForLearner[i12] =
            useObsForLearner[i12 + (useObsForLearner.size(0) * 9)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i12 = 0; i12 < y_loop_ub; i12++) {
        b_useObsForLearner[i12] =
            useObsForLearner[i12 + (useObsForLearner.size(0) * 9)];
      }
    }
    c_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &c_weak_learner, b_learnerWeights[9], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[10]) {
    int bb_loop_ub;
    int x_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    e_weak_learner.b_init();
    b = b_isCached[10];
    x_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    bb_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i13{0}; i13 < x_loop_ub; i13++) {
        b_useObsForLearner[i13] =
            useObsForLearner[i13 + (useObsForLearner.size(0) * 10)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i13 = 0; i13 < bb_loop_ub; i13++) {
        b_useObsForLearner[i13] =
            useObsForLearner[i13 + (useObsForLearner.size(0) * 10)];
      }
    }
    e_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &e_weak_learner, b_learnerWeights[10], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[11]) {
    int ab_loop_ub;
    int db_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    d_weak_learner.c_init();
    b = b_isCached[11];
    ab_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    db_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i14{0}; i14 < ab_loop_ub; i14++) {
        b_useObsForLearner[i14] =
            useObsForLearner[i14 + (useObsForLearner.size(0) * 11)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i14 = 0; i14 < db_loop_ub; i14++) {
        b_useObsForLearner[i14] =
            useObsForLearner[i14 + (useObsForLearner.size(0) * 11)];
      }
    }
    d_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &d_weak_learner, b_learnerWeights[11], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[12]) {
    int cb_loop_ub;
    int fb_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b_weak_learner.d_init();
    b = b_isCached[12];
    cb_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    fb_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i15{0}; i15 < cb_loop_ub; i15++) {
        b_useObsForLearner[i15] =
            useObsForLearner[i15 + (useObsForLearner.size(0) * 12)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i15 = 0; i15 < fb_loop_ub; i15++) {
        b_useObsForLearner[i15] =
            useObsForLearner[i15 + (useObsForLearner.size(0) * 12)];
      }
    }
    b_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &b_weak_learner, b_learnerWeights[12], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[13]) {
    int eb_loop_ub;
    int hb_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b_weak_learner.e_init();
    b = b_isCached[13];
    eb_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    hb_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i16{0}; i16 < eb_loop_ub; i16++) {
        b_useObsForLearner[i16] =
            useObsForLearner[i16 + (useObsForLearner.size(0) * 13)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i16 = 0; i16 < hb_loop_ub; i16++) {
        b_useObsForLearner[i16] =
            useObsForLearner[i16 + (useObsForLearner.size(0) * 13)];
      }
    }
    b_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &b_weak_learner, b_learnerWeights[13], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[14]) {
    int gb_loop_ub;
    int jb_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    g_weak_learner.init();
    b = b_isCached[14];
    gb_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    jb_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i17{0}; i17 < gb_loop_ub; i17++) {
        b_useObsForLearner[i17] =
            useObsForLearner[i17 + (useObsForLearner.size(0) * 14)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i17 = 0; i17 < jb_loop_ub; i17++) {
        b_useObsForLearner[i17] =
            useObsForLearner[i17 + (useObsForLearner.size(0) * 14)];
      }
    }
    g_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &g_weak_learner, b_learnerWeights[14], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[15]) {
    int ib_loop_ub;
    int mb_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b_weak_learner.f_init();
    b = b_isCached[15];
    ib_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    mb_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i18{0}; i18 < ib_loop_ub; i18++) {
        b_useObsForLearner[i18] =
            useObsForLearner[i18 + (useObsForLearner.size(0) * 15)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i18 = 0; i18 < mb_loop_ub; i18++) {
        b_useObsForLearner[i18] =
            useObsForLearner[i18 + (useObsForLearner.size(0) * 15)];
      }
    }
    b_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &b_weak_learner, b_learnerWeights[15], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[16]) {
    int kb_loop_ub;
    int pb_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    d_weak_learner.d_init();
    b = b_isCached[16];
    kb_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    pb_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i19{0}; i19 < kb_loop_ub; i19++) {
        b_useObsForLearner[i19] =
            useObsForLearner[i19 + (useObsForLearner.size(0) * 16)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i19 = 0; i19 < pb_loop_ub; i19++) {
        b_useObsForLearner[i19] =
            useObsForLearner[i19 + (useObsForLearner.size(0) * 16)];
      }
    }
    d_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &d_weak_learner, b_learnerWeights[16], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[17]) {
    int ob_loop_ub;
    int rb_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    c_weak_learner.c_init();
    b = b_isCached[17];
    ob_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    rb_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i20{0}; i20 < ob_loop_ub; i20++) {
        b_useObsForLearner[i20] =
            useObsForLearner[i20 + (useObsForLearner.size(0) * 17)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i20 = 0; i20 < rb_loop_ub; i20++) {
        b_useObsForLearner[i20] =
            useObsForLearner[i20 + (useObsForLearner.size(0) * 17)];
      }
    }
    c_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &c_weak_learner, b_learnerWeights[17], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[18]) {
    int qb_loop_ub;
    int tb_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    g_weak_learner.b_init();
    b = b_isCached[18];
    qb_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    tb_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i21{0}; i21 < qb_loop_ub; i21++) {
        b_useObsForLearner[i21] =
            useObsForLearner[i21 + (useObsForLearner.size(0) * 18)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i21 = 0; i21 < tb_loop_ub; i21++) {
        b_useObsForLearner[i21] =
            useObsForLearner[i21 + (useObsForLearner.size(0) * 18)];
      }
    }
    g_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &g_weak_learner, b_learnerWeights[18], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[19]) {
    int sb_loop_ub;
    int vb_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b_weak_learner.g_init();
    b = b_isCached[19];
    sb_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    vb_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i22{0}; i22 < sb_loop_ub; i22++) {
        b_useObsForLearner[i22] =
            useObsForLearner[i22 + (useObsForLearner.size(0) * 19)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i22 = 0; i22 < vb_loop_ub; i22++) {
        b_useObsForLearner[i22] =
            useObsForLearner[i22 + (useObsForLearner.size(0) * 19)];
      }
    }
    b_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &b_weak_learner, b_learnerWeights[19], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[20]) {
    int ub_loop_ub;
    int xb_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    weak_learner.b_init();
    b = b_isCached[20];
    ub_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    xb_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i23{0}; i23 < ub_loop_ub; i23++) {
        b_useObsForLearner[i23] =
            useObsForLearner[i23 + (useObsForLearner.size(0) * 20)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i23 = 0; i23 < xb_loop_ub; i23++) {
        b_useObsForLearner[i23] =
            useObsForLearner[i23 + (useObsForLearner.size(0) * 20)];
      }
    }
    predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                        &weak_learner, b_learnerWeights[20], &b, b_classNames,
                        b_classlogicalindices, b_useObsForLearner, initCache,
                        score);
  }
  if (learners[21]) {
    int ac_loop_ub;
    int wb_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    h_weak_learner.init();
    b = b_isCached[21];
    wb_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    ac_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i24{0}; i24 < wb_loop_ub; i24++) {
        b_useObsForLearner[i24] =
            useObsForLearner[i24 + (useObsForLearner.size(0) * 21)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i24 = 0; i24 < ac_loop_ub; i24++) {
        b_useObsForLearner[i24] =
            useObsForLearner[i24 + (useObsForLearner.size(0) * 21)];
      }
    }
    h_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &h_weak_learner, b_learnerWeights[21], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[22]) {
    int cc_loop_ub;
    int yb_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b_weak_learner.h_init();
    b = b_isCached[22];
    yb_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    cc_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i25{0}; i25 < yb_loop_ub; i25++) {
        b_useObsForLearner[i25] =
            useObsForLearner[i25 + (useObsForLearner.size(0) * 22)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i25 = 0; i25 < cc_loop_ub; i25++) {
        b_useObsForLearner[i25] =
            useObsForLearner[i25 + (useObsForLearner.size(0) * 22)];
      }
    }
    b_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &b_weak_learner, b_learnerWeights[22], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[23]) {
    int bc_loop_ub;
    int ec_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    d_weak_learner.e_init();
    b = b_isCached[23];
    bc_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    ec_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i26{0}; i26 < bc_loop_ub; i26++) {
        b_useObsForLearner[i26] =
            useObsForLearner[i26 + (useObsForLearner.size(0) * 23)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i26 = 0; i26 < ec_loop_ub; i26++) {
        b_useObsForLearner[i26] =
            useObsForLearner[i26 + (useObsForLearner.size(0) * 23)];
      }
    }
    d_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &d_weak_learner, b_learnerWeights[23], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[24]) {
    int dc_loop_ub;
    int gc_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    c_weak_learner.d_init();
    b = b_isCached[24];
    dc_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    gc_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i27{0}; i27 < dc_loop_ub; i27++) {
        b_useObsForLearner[i27] =
            useObsForLearner[i27 + (useObsForLearner.size(0) * 24)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i27 = 0; i27 < gc_loop_ub; i27++) {
        b_useObsForLearner[i27] =
            useObsForLearner[i27 + (useObsForLearner.size(0) * 24)];
      }
    }
    c_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &c_weak_learner, b_learnerWeights[24], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[25]) {
    int fc_loop_ub;
    int ic_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    e_weak_learner.c_init();
    b = b_isCached[25];
    fc_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    ic_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i28{0}; i28 < fc_loop_ub; i28++) {
        b_useObsForLearner[i28] =
            useObsForLearner[i28 + (useObsForLearner.size(0) * 25)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i28 = 0; i28 < ic_loop_ub; i28++) {
        b_useObsForLearner[i28] =
            useObsForLearner[i28 + (useObsForLearner.size(0) * 25)];
      }
    }
    e_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &e_weak_learner, b_learnerWeights[25], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[26]) {
    int hc_loop_ub;
    int kc_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b_weak_learner.i_init();
    b = b_isCached[26];
    hc_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    kc_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i29{0}; i29 < hc_loop_ub; i29++) {
        b_useObsForLearner[i29] =
            useObsForLearner[i29 + (useObsForLearner.size(0) * 26)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i29 = 0; i29 < kc_loop_ub; i29++) {
        b_useObsForLearner[i29] =
            useObsForLearner[i29 + (useObsForLearner.size(0) * 26)];
      }
    }
    b_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &b_weak_learner, b_learnerWeights[26], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[27]) {
    int jc_loop_ub;
    int oc_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    c_weak_learner.e_init();
    b = b_isCached[27];
    jc_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    oc_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i30{0}; i30 < jc_loop_ub; i30++) {
        b_useObsForLearner[i30] =
            useObsForLearner[i30 + (useObsForLearner.size(0) * 27)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i30 = 0; i30 < oc_loop_ub; i30++) {
        b_useObsForLearner[i30] =
            useObsForLearner[i30 + (useObsForLearner.size(0) * 27)];
      }
    }
    c_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &c_weak_learner, b_learnerWeights[27], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[28]) {
    int mc_loop_ub;
    int qc_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    c_weak_learner.f_init();
    b = b_isCached[28];
    mc_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    qc_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i31{0}; i31 < mc_loop_ub; i31++) {
        b_useObsForLearner[i31] =
            useObsForLearner[i31 + (useObsForLearner.size(0) * 28)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i31 = 0; i31 < qc_loop_ub; i31++) {
        b_useObsForLearner[i31] =
            useObsForLearner[i31 + (useObsForLearner.size(0) * 28)];
      }
    }
    c_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &c_weak_learner, b_learnerWeights[28], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[29]) {
    int pc_loop_ub;
    int sc_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    d_weak_learner.f_init();
    b = b_isCached[29];
    pc_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    sc_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i32{0}; i32 < pc_loop_ub; i32++) {
        b_useObsForLearner[i32] =
            useObsForLearner[i32 + (useObsForLearner.size(0) * 29)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i32 = 0; i32 < sc_loop_ub; i32++) {
        b_useObsForLearner[i32] =
            useObsForLearner[i32 + (useObsForLearner.size(0) * 29)];
      }
    }
    d_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &d_weak_learner, b_learnerWeights[29], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[30]) {
    int rc_loop_ub;
    int uc_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    c_weak_learner.g_init();
    b = b_isCached[30];
    rc_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    uc_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i33{0}; i33 < rc_loop_ub; i33++) {
        b_useObsForLearner[i33] =
            useObsForLearner[i33 + (useObsForLearner.size(0) * 30)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i33 = 0; i33 < uc_loop_ub; i33++) {
        b_useObsForLearner[i33] =
            useObsForLearner[i33 + (useObsForLearner.size(0) * 30)];
      }
    }
    c_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &c_weak_learner, b_learnerWeights[30], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[31]) {
    int tc_loop_ub;
    int wc_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    weak_learner.c_init();
    b = b_isCached[31];
    tc_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    wc_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i34{0}; i34 < tc_loop_ub; i34++) {
        b_useObsForLearner[i34] =
            useObsForLearner[i34 + (useObsForLearner.size(0) * 31)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i34 = 0; i34 < wc_loop_ub; i34++) {
        b_useObsForLearner[i34] =
            useObsForLearner[i34 + (useObsForLearner.size(0) * 31)];
      }
    }
    predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                        &weak_learner, b_learnerWeights[31], &b, b_classNames,
                        b_classlogicalindices, b_useObsForLearner, initCache,
                        score);
  }
  if (learners[32]) {
    int vc_loop_ub;
    int yc_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    g_weak_learner.c_init();
    b = b_isCached[32];
    vc_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    yc_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i35{0}; i35 < vc_loop_ub; i35++) {
        b_useObsForLearner[i35] =
            useObsForLearner[i35 + (useObsForLearner.size(0) * 32)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i35 = 0; i35 < yc_loop_ub; i35++) {
        b_useObsForLearner[i35] =
            useObsForLearner[i35 + (useObsForLearner.size(0) * 32)];
      }
    }
    g_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &g_weak_learner, b_learnerWeights[32], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[33]) {
    int bd_loop_ub;
    int xc_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    c_weak_learner.h_init();
    b = b_isCached[33];
    xc_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    bd_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i36{0}; i36 < xc_loop_ub; i36++) {
        b_useObsForLearner[i36] =
            useObsForLearner[i36 + (useObsForLearner.size(0) * 33)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i36 = 0; i36 < bd_loop_ub; i36++) {
        b_useObsForLearner[i36] =
            useObsForLearner[i36 + (useObsForLearner.size(0) * 33)];
      }
    }
    c_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &c_weak_learner, b_learnerWeights[33], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[34]) {
    int ad_loop_ub;
    int dd_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b_weak_learner.j_init();
    b = b_isCached[34];
    ad_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    dd_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i37{0}; i37 < ad_loop_ub; i37++) {
        b_useObsForLearner[i37] =
            useObsForLearner[i37 + (useObsForLearner.size(0) * 34)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i37 = 0; i37 < dd_loop_ub; i37++) {
        b_useObsForLearner[i37] =
            useObsForLearner[i37 + (useObsForLearner.size(0) * 34)];
      }
    }
    b_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &b_weak_learner, b_learnerWeights[34], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[35]) {
    int cd_loop_ub;
    int fd_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    g_weak_learner.d_init();
    b = b_isCached[35];
    cd_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    fd_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i38{0}; i38 < cd_loop_ub; i38++) {
        b_useObsForLearner[i38] =
            useObsForLearner[i38 + (useObsForLearner.size(0) * 35)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i38 = 0; i38 < fd_loop_ub; i38++) {
        b_useObsForLearner[i38] =
            useObsForLearner[i38 + (useObsForLearner.size(0) * 35)];
      }
    }
    g_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &g_weak_learner, b_learnerWeights[35], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[36]) {
    int ed_loop_ub;
    int hd_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    d_weak_learner.g_init();
    b = b_isCached[36];
    ed_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    hd_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i39{0}; i39 < ed_loop_ub; i39++) {
        b_useObsForLearner[i39] =
            useObsForLearner[i39 + (useObsForLearner.size(0) * 36)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i39 = 0; i39 < hd_loop_ub; i39++) {
        b_useObsForLearner[i39] =
            useObsForLearner[i39 + (useObsForLearner.size(0) * 36)];
      }
    }
    d_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &d_weak_learner, b_learnerWeights[36], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[37]) {
    int gd_loop_ub;
    int jd_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b_weak_learner.k_init();
    b = b_isCached[37];
    gd_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    jd_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i40{0}; i40 < gd_loop_ub; i40++) {
        b_useObsForLearner[i40] =
            useObsForLearner[i40 + (useObsForLearner.size(0) * 37)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i40 = 0; i40 < jd_loop_ub; i40++) {
        b_useObsForLearner[i40] =
            useObsForLearner[i40 + (useObsForLearner.size(0) * 37)];
      }
    }
    b_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &b_weak_learner, b_learnerWeights[37], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[38]) {
    int id_loop_ub;
    int md_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    g_weak_learner.e_init();
    b = b_isCached[38];
    id_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    md_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i41{0}; i41 < id_loop_ub; i41++) {
        b_useObsForLearner[i41] =
            useObsForLearner[i41 + (useObsForLearner.size(0) * 38)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i41 = 0; i41 < md_loop_ub; i41++) {
        b_useObsForLearner[i41] =
            useObsForLearner[i41 + (useObsForLearner.size(0) * 38)];
      }
    }
    g_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &g_weak_learner, b_learnerWeights[38], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[39]) {
    int kd_loop_ub;
    int pd_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    e_weak_learner.d_init();
    b = b_isCached[39];
    kd_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    pd_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i42{0}; i42 < kd_loop_ub; i42++) {
        b_useObsForLearner[i42] =
            useObsForLearner[i42 + (useObsForLearner.size(0) * 39)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i42 = 0; i42 < pd_loop_ub; i42++) {
        b_useObsForLearner[i42] =
            useObsForLearner[i42 + (useObsForLearner.size(0) * 39)];
      }
    }
    e_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &e_weak_learner, b_learnerWeights[39], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[40]) {
    int od_loop_ub;
    int rd_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    h_weak_learner.b_init();
    b = b_isCached[40];
    od_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    rd_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i43{0}; i43 < od_loop_ub; i43++) {
        b_useObsForLearner[i43] =
            useObsForLearner[i43 + (useObsForLearner.size(0) * 40)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i43 = 0; i43 < rd_loop_ub; i43++) {
        b_useObsForLearner[i43] =
            useObsForLearner[i43 + (useObsForLearner.size(0) * 40)];
      }
    }
    h_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &h_weak_learner, b_learnerWeights[40], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[41]) {
    int qd_loop_ub;
    int td_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    weak_learner.d_init();
    b = b_isCached[41];
    qd_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    td_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i44{0}; i44 < qd_loop_ub; i44++) {
        b_useObsForLearner[i44] =
            useObsForLearner[i44 + (useObsForLearner.size(0) * 41)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i44 = 0; i44 < td_loop_ub; i44++) {
        b_useObsForLearner[i44] =
            useObsForLearner[i44 + (useObsForLearner.size(0) * 41)];
      }
    }
    predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                        &weak_learner, b_learnerWeights[41], &b, b_classNames,
                        b_classlogicalindices, b_useObsForLearner, initCache,
                        score);
  }
  if (learners[42]) {
    int sd_loop_ub;
    int vd_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    d_weak_learner.h_init();
    b = b_isCached[42];
    sd_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    vd_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i45{0}; i45 < sd_loop_ub; i45++) {
        b_useObsForLearner[i45] =
            useObsForLearner[i45 + (useObsForLearner.size(0) * 42)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i45 = 0; i45 < vd_loop_ub; i45++) {
        b_useObsForLearner[i45] =
            useObsForLearner[i45 + (useObsForLearner.size(0) * 42)];
      }
    }
    d_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &d_weak_learner, b_learnerWeights[42], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[43]) {
    int ud_loop_ub;
    int xd_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    h_weak_learner.c_init();
    b = b_isCached[43];
    ud_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    xd_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i46{0}; i46 < ud_loop_ub; i46++) {
        b_useObsForLearner[i46] =
            useObsForLearner[i46 + (useObsForLearner.size(0) * 43)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i46 = 0; i46 < xd_loop_ub; i46++) {
        b_useObsForLearner[i46] =
            useObsForLearner[i46 + (useObsForLearner.size(0) * 43)];
      }
    }
    h_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &h_weak_learner, b_learnerWeights[43], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[44]) {
    int ae_loop_ub;
    int wd_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b_weak_learner.m_init();
    b = b_isCached[44];
    wd_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    ae_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i47{0}; i47 < wd_loop_ub; i47++) {
        b_useObsForLearner[i47] =
            useObsForLearner[i47 + (useObsForLearner.size(0) * 44)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i47 = 0; i47 < ae_loop_ub; i47++) {
        b_useObsForLearner[i47] =
            useObsForLearner[i47 + (useObsForLearner.size(0) * 44)];
      }
    }
    b_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &b_weak_learner, b_learnerWeights[44], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[45]) {
    int ce_loop_ub;
    int yd_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b_weak_learner.o_init();
    b = b_isCached[45];
    yd_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    ce_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i48{0}; i48 < yd_loop_ub; i48++) {
        b_useObsForLearner[i48] =
            useObsForLearner[i48 + (useObsForLearner.size(0) * 45)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i48 = 0; i48 < ce_loop_ub; i48++) {
        b_useObsForLearner[i48] =
            useObsForLearner[i48 + (useObsForLearner.size(0) * 45)];
      }
    }
    b_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &b_weak_learner, b_learnerWeights[45], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[46]) {
    int be_loop_ub;
    int ee_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    i_weak_learner.init();
    b = b_isCached[46];
    be_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    ee_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i49{0}; i49 < be_loop_ub; i49++) {
        b_useObsForLearner[i49] =
            useObsForLearner[i49 + (useObsForLearner.size(0) * 46)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i49 = 0; i49 < ee_loop_ub; i49++) {
        b_useObsForLearner[i49] =
            useObsForLearner[i49 + (useObsForLearner.size(0) * 46)];
      }
    }
    i_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &i_weak_learner, b_learnerWeights[46], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[47]) {
    int de_loop_ub;
    int ge_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    j_weak_learner.init();
    b = b_isCached[47];
    de_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    ge_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i50{0}; i50 < de_loop_ub; i50++) {
        b_useObsForLearner[i50] =
            useObsForLearner[i50 + (useObsForLearner.size(0) * 47)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i50 = 0; i50 < ge_loop_ub; i50++) {
        b_useObsForLearner[i50] =
            useObsForLearner[i50 + (useObsForLearner.size(0) * 47)];
      }
    }
    j_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &j_weak_learner, b_learnerWeights[47], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[48]) {
    int fe_loop_ub;
    int ie_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    k_weak_learner.init();
    b = b_isCached[48];
    fe_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    ie_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i51{0}; i51 < fe_loop_ub; i51++) {
        b_useObsForLearner[i51] =
            useObsForLearner[i51 + (useObsForLearner.size(0) * 48)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i51 = 0; i51 < ie_loop_ub; i51++) {
        b_useObsForLearner[i51] =
            useObsForLearner[i51 + (useObsForLearner.size(0) * 48)];
      }
    }
    k_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &k_weak_learner, b_learnerWeights[48], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[49]) {
    int he_loop_ub;
    int ke_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    c_weak_learner.i_init();
    b = b_isCached[49];
    he_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    ke_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i52{0}; i52 < he_loop_ub; i52++) {
        b_useObsForLearner[i52] =
            useObsForLearner[i52 + (useObsForLearner.size(0) * 49)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i52 = 0; i52 < ke_loop_ub; i52++) {
        b_useObsForLearner[i52] =
            useObsForLearner[i52 + (useObsForLearner.size(0) * 49)];
      }
    }
    c_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &c_weak_learner, b_learnerWeights[49], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[50]) {
    int je_loop_ub;
    int oe_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b_weak_learner.p_init();
    b = b_isCached[50];
    je_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    oe_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i53{0}; i53 < je_loop_ub; i53++) {
        b_useObsForLearner[i53] =
            useObsForLearner[i53 + (useObsForLearner.size(0) * 50)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i53 = 0; i53 < oe_loop_ub; i53++) {
        b_useObsForLearner[i53] =
            useObsForLearner[i53 + (useObsForLearner.size(0) * 50)];
      }
    }
    b_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &b_weak_learner, b_learnerWeights[50], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[51]) {
    int me_loop_ub;
    int qe_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    c_weak_learner.j_init();
    b = b_isCached[51];
    me_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    qe_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i54{0}; i54 < me_loop_ub; i54++) {
        b_useObsForLearner[i54] =
            useObsForLearner[i54 + (useObsForLearner.size(0) * 51)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i54 = 0; i54 < qe_loop_ub; i54++) {
        b_useObsForLearner[i54] =
            useObsForLearner[i54 + (useObsForLearner.size(0) * 51)];
      }
    }
    c_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &c_weak_learner, b_learnerWeights[51], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[52]) {
    int pe_loop_ub;
    int se_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b_weak_learner.q_init();
    b = b_isCached[52];
    pe_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    se_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i55{0}; i55 < pe_loop_ub; i55++) {
        b_useObsForLearner[i55] =
            useObsForLearner[i55 + (useObsForLearner.size(0) * 52)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i55 = 0; i55 < se_loop_ub; i55++) {
        b_useObsForLearner[i55] =
            useObsForLearner[i55 + (useObsForLearner.size(0) * 52)];
      }
    }
    b_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &b_weak_learner, b_learnerWeights[52], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[53]) {
    int re_loop_ub;
    int ue_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b_weak_learner.r_init();
    b = b_isCached[53];
    re_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    ue_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i56{0}; i56 < re_loop_ub; i56++) {
        b_useObsForLearner[i56] =
            useObsForLearner[i56 + (useObsForLearner.size(0) * 53)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i56 = 0; i56 < ue_loop_ub; i56++) {
        b_useObsForLearner[i56] =
            useObsForLearner[i56 + (useObsForLearner.size(0) * 53)];
      }
    }
    b_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &b_weak_learner, b_learnerWeights[53], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[54]) {
    int te_loop_ub;
    int we_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    c_weak_learner.k_init();
    b = b_isCached[54];
    te_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    we_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i57{0}; i57 < te_loop_ub; i57++) {
        b_useObsForLearner[i57] =
            useObsForLearner[i57 + (useObsForLearner.size(0) * 54)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i57 = 0; i57 < we_loop_ub; i57++) {
        b_useObsForLearner[i57] =
            useObsForLearner[i57 + (useObsForLearner.size(0) * 54)];
      }
    }
    c_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &c_weak_learner, b_learnerWeights[54], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[55]) {
    int ve_loop_ub;
    int ye_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    h_weak_learner.d_init();
    b = b_isCached[55];
    ve_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    ye_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i58{0}; i58 < ve_loop_ub; i58++) {
        b_useObsForLearner[i58] =
            useObsForLearner[i58 + (useObsForLearner.size(0) * 55)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i58 = 0; i58 < ye_loop_ub; i58++) {
        b_useObsForLearner[i58] =
            useObsForLearner[i58 + (useObsForLearner.size(0) * 55)];
      }
    }
    h_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &h_weak_learner, b_learnerWeights[55], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[56]) {
    int bf_loop_ub;
    int xe_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    e_weak_learner.e_init();
    b = b_isCached[56];
    xe_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    bf_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i59{0}; i59 < xe_loop_ub; i59++) {
        b_useObsForLearner[i59] =
            useObsForLearner[i59 + (useObsForLearner.size(0) * 56)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i59 = 0; i59 < bf_loop_ub; i59++) {
        b_useObsForLearner[i59] =
            useObsForLearner[i59 + (useObsForLearner.size(0) * 56)];
      }
    }
    e_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &e_weak_learner, b_learnerWeights[56], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[57]) {
    int af_loop_ub;
    int df_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b_weak_learner.s_init();
    b = b_isCached[57];
    af_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    df_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i60{0}; i60 < af_loop_ub; i60++) {
        b_useObsForLearner[i60] =
            useObsForLearner[i60 + (useObsForLearner.size(0) * 57)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i60 = 0; i60 < df_loop_ub; i60++) {
        b_useObsForLearner[i60] =
            useObsForLearner[i60 + (useObsForLearner.size(0) * 57)];
      }
    }
    b_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &b_weak_learner, b_learnerWeights[57], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[58]) {
    int cf_loop_ub;
    int ff_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    e_weak_learner.f_init();
    b = b_isCached[58];
    cf_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    ff_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i61{0}; i61 < cf_loop_ub; i61++) {
        b_useObsForLearner[i61] =
            useObsForLearner[i61 + (useObsForLearner.size(0) * 58)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i61 = 0; i61 < ff_loop_ub; i61++) {
        b_useObsForLearner[i61] =
            useObsForLearner[i61 + (useObsForLearner.size(0) * 58)];
      }
    }
    e_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &e_weak_learner, b_learnerWeights[58], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[59]) {
    int ef_loop_ub;
    int hf_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    weak_learner.e_init();
    b = b_isCached[59];
    ef_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    hf_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i62{0}; i62 < ef_loop_ub; i62++) {
        b_useObsForLearner[i62] =
            useObsForLearner[i62 + (useObsForLearner.size(0) * 59)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i62 = 0; i62 < hf_loop_ub; i62++) {
        b_useObsForLearner[i62] =
            useObsForLearner[i62 + (useObsForLearner.size(0) * 59)];
      }
    }
    predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                        &weak_learner, b_learnerWeights[59], &b, b_classNames,
                        b_classlogicalindices, b_useObsForLearner, initCache,
                        score);
  }
  if (learners[60]) {
    int gf_loop_ub;
    int jf_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    i_weak_learner.b_init();
    b = b_isCached[60];
    gf_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    jf_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i63{0}; i63 < gf_loop_ub; i63++) {
        b_useObsForLearner[i63] =
            useObsForLearner[i63 + (useObsForLearner.size(0) * 60)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i63 = 0; i63 < jf_loop_ub; i63++) {
        b_useObsForLearner[i63] =
            useObsForLearner[i63 + (useObsForLearner.size(0) * 60)];
      }
    }
    i_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &i_weak_learner, b_learnerWeights[60], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[61]) {
    int if_loop_ub;
    int mf_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    c_weak_learner.m_init();
    b = b_isCached[61];
    if_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    mf_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i64{0}; i64 < if_loop_ub; i64++) {
        b_useObsForLearner[i64] =
            useObsForLearner[i64 + (useObsForLearner.size(0) * 61)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i64 = 0; i64 < mf_loop_ub; i64++) {
        b_useObsForLearner[i64] =
            useObsForLearner[i64 + (useObsForLearner.size(0) * 61)];
      }
    }
    c_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &c_weak_learner, b_learnerWeights[61], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[62]) {
    int kf_loop_ub;
    int pf_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    g_weak_learner.f_init();
    b = b_isCached[62];
    kf_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    pf_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i65{0}; i65 < kf_loop_ub; i65++) {
        b_useObsForLearner[i65] =
            useObsForLearner[i65 + (useObsForLearner.size(0) * 62)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i65 = 0; i65 < pf_loop_ub; i65++) {
        b_useObsForLearner[i65] =
            useObsForLearner[i65 + (useObsForLearner.size(0) * 62)];
      }
    }
    g_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &g_weak_learner, b_learnerWeights[62], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[63]) {
    int of_loop_ub;
    int rf_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    e_weak_learner.g_init();
    b = b_isCached[63];
    of_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    rf_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i66{0}; i66 < of_loop_ub; i66++) {
        b_useObsForLearner[i66] =
            useObsForLearner[i66 + (useObsForLearner.size(0) * 63)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i66 = 0; i66 < rf_loop_ub; i66++) {
        b_useObsForLearner[i66] =
            useObsForLearner[i66 + (useObsForLearner.size(0) * 63)];
      }
    }
    e_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &e_weak_learner, b_learnerWeights[63], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[64]) {
    int qf_loop_ub;
    int tf_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    e_weak_learner.h_init();
    b = b_isCached[64];
    qf_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    tf_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i67{0}; i67 < qf_loop_ub; i67++) {
        b_useObsForLearner[i67] =
            useObsForLearner[i67 + (useObsForLearner.size(0) * 64)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i67 = 0; i67 < tf_loop_ub; i67++) {
        b_useObsForLearner[i67] =
            useObsForLearner[i67 + (useObsForLearner.size(0) * 64)];
      }
    }
    e_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &e_weak_learner, b_learnerWeights[64], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[65]) {
    int sf_loop_ub;
    int vf_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    c_weak_learner.o_init();
    b = b_isCached[65];
    sf_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    vf_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i68{0}; i68 < sf_loop_ub; i68++) {
        b_useObsForLearner[i68] =
            useObsForLearner[i68 + (useObsForLearner.size(0) * 65)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i68 = 0; i68 < vf_loop_ub; i68++) {
        b_useObsForLearner[i68] =
            useObsForLearner[i68 + (useObsForLearner.size(0) * 65)];
      }
    }
    c_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &c_weak_learner, b_learnerWeights[65], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[66]) {
    int uf_loop_ub;
    int xf_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    k_weak_learner.b_init();
    b = b_isCached[66];
    uf_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    xf_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i69{0}; i69 < uf_loop_ub; i69++) {
        b_useObsForLearner[i69] =
            useObsForLearner[i69 + (useObsForLearner.size(0) * 66)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i69 = 0; i69 < xf_loop_ub; i69++) {
        b_useObsForLearner[i69] =
            useObsForLearner[i69 + (useObsForLearner.size(0) * 66)];
      }
    }
    k_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &k_weak_learner, b_learnerWeights[66], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[67]) {
    int ag_loop_ub;
    int wf_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    d_weak_learner.i_init();
    b = b_isCached[67];
    wf_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    ag_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i70{0}; i70 < wf_loop_ub; i70++) {
        b_useObsForLearner[i70] =
            useObsForLearner[i70 + (useObsForLearner.size(0) * 67)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i70 = 0; i70 < ag_loop_ub; i70++) {
        b_useObsForLearner[i70] =
            useObsForLearner[i70 + (useObsForLearner.size(0) * 67)];
      }
    }
    d_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &d_weak_learner, b_learnerWeights[67], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[68]) {
    int cg_loop_ub;
    int yf_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b_weak_learner.t_init();
    b = b_isCached[68];
    yf_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    cg_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i71{0}; i71 < yf_loop_ub; i71++) {
        b_useObsForLearner[i71] =
            useObsForLearner[i71 + (useObsForLearner.size(0) * 68)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i71 = 0; i71 < cg_loop_ub; i71++) {
        b_useObsForLearner[i71] =
            useObsForLearner[i71 + (useObsForLearner.size(0) * 68)];
      }
    }
    b_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &b_weak_learner, b_learnerWeights[68], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[69]) {
    int bg_loop_ub;
    int eg_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    c_weak_learner.p_init();
    b = b_isCached[69];
    bg_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    eg_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i72{0}; i72 < bg_loop_ub; i72++) {
        b_useObsForLearner[i72] =
            useObsForLearner[i72 + (useObsForLearner.size(0) * 69)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i72 = 0; i72 < eg_loop_ub; i72++) {
        b_useObsForLearner[i72] =
            useObsForLearner[i72 + (useObsForLearner.size(0) * 69)];
      }
    }
    c_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &c_weak_learner, b_learnerWeights[69], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[70]) {
    int dg_loop_ub;
    int gg_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    i_weak_learner.c_init();
    b = b_isCached[70];
    dg_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    gg_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i73{0}; i73 < dg_loop_ub; i73++) {
        b_useObsForLearner[i73] =
            useObsForLearner[i73 + (useObsForLearner.size(0) * 70)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i73 = 0; i73 < gg_loop_ub; i73++) {
        b_useObsForLearner[i73] =
            useObsForLearner[i73 + (useObsForLearner.size(0) * 70)];
      }
    }
    i_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &i_weak_learner, b_learnerWeights[70], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[71]) {
    int fg_loop_ub;
    int ig_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    g_weak_learner.g_init();
    b = b_isCached[71];
    fg_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    ig_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i74{0}; i74 < fg_loop_ub; i74++) {
        b_useObsForLearner[i74] =
            useObsForLearner[i74 + (useObsForLearner.size(0) * 71)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i74 = 0; i74 < ig_loop_ub; i74++) {
        b_useObsForLearner[i74] =
            useObsForLearner[i74 + (useObsForLearner.size(0) * 71)];
      }
    }
    g_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &g_weak_learner, b_learnerWeights[71], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[72]) {
    int hg_loop_ub;
    int kg_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    c_weak_learner.q_init();
    b = b_isCached[72];
    hg_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    kg_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i75{0}; i75 < hg_loop_ub; i75++) {
        b_useObsForLearner[i75] =
            useObsForLearner[i75 + (useObsForLearner.size(0) * 72)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i75 = 0; i75 < kg_loop_ub; i75++) {
        b_useObsForLearner[i75] =
            useObsForLearner[i75 + (useObsForLearner.size(0) * 72)];
      }
    }
    c_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &c_weak_learner, b_learnerWeights[72], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[73]) {
    int jg_loop_ub;
    int og_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    c_weak_learner.r_init();
    b = b_isCached[73];
    jg_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    og_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i76{0}; i76 < jg_loop_ub; i76++) {
        b_useObsForLearner[i76] =
            useObsForLearner[i76 + (useObsForLearner.size(0) * 73)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i76 = 0; i76 < og_loop_ub; i76++) {
        b_useObsForLearner[i76] =
            useObsForLearner[i76 + (useObsForLearner.size(0) * 73)];
      }
    }
    c_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &c_weak_learner, b_learnerWeights[73], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[74]) {
    int mg_loop_ub;
    int qg_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    weak_learner.f_init();
    b = b_isCached[74];
    mg_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    qg_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i77{0}; i77 < mg_loop_ub; i77++) {
        b_useObsForLearner[i77] =
            useObsForLearner[i77 + (useObsForLearner.size(0) * 74)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i77 = 0; i77 < qg_loop_ub; i77++) {
        b_useObsForLearner[i77] =
            useObsForLearner[i77 + (useObsForLearner.size(0) * 74)];
      }
    }
    predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                        &weak_learner, b_learnerWeights[74], &b, b_classNames,
                        b_classlogicalindices, b_useObsForLearner, initCache,
                        score);
  }
  if (learners[75]) {
    int pg_loop_ub;
    int sg_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    e_weak_learner.i_init();
    b = b_isCached[75];
    pg_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    sg_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i78{0}; i78 < pg_loop_ub; i78++) {
        b_useObsForLearner[i78] =
            useObsForLearner[i78 + (useObsForLearner.size(0) * 75)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i78 = 0; i78 < sg_loop_ub; i78++) {
        b_useObsForLearner[i78] =
            useObsForLearner[i78 + (useObsForLearner.size(0) * 75)];
      }
    }
    e_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &e_weak_learner, b_learnerWeights[75], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[76]) {
    int rg_loop_ub;
    int ug_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    e_weak_learner.j_init();
    b = b_isCached[76];
    rg_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    ug_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i79{0}; i79 < rg_loop_ub; i79++) {
        b_useObsForLearner[i79] =
            useObsForLearner[i79 + (useObsForLearner.size(0) * 76)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i79 = 0; i79 < ug_loop_ub; i79++) {
        b_useObsForLearner[i79] =
            useObsForLearner[i79 + (useObsForLearner.size(0) * 76)];
      }
    }
    e_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &e_weak_learner, b_learnerWeights[76], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[77]) {
    int tg_loop_ub;
    int wg_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    j_weak_learner.b_init();
    b = b_isCached[77];
    tg_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    wg_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i80{0}; i80 < tg_loop_ub; i80++) {
        b_useObsForLearner[i80] =
            useObsForLearner[i80 + (useObsForLearner.size(0) * 77)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i80 = 0; i80 < wg_loop_ub; i80++) {
        b_useObsForLearner[i80] =
            useObsForLearner[i80 + (useObsForLearner.size(0) * 77)];
      }
    }
    j_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &j_weak_learner, b_learnerWeights[77], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[78]) {
    int vg_loop_ub;
    int yg_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b_weak_learner.u_init();
    b = b_isCached[78];
    vg_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    yg_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i81{0}; i81 < vg_loop_ub; i81++) {
        b_useObsForLearner[i81] =
            useObsForLearner[i81 + (useObsForLearner.size(0) * 78)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i81 = 0; i81 < yg_loop_ub; i81++) {
        b_useObsForLearner[i81] =
            useObsForLearner[i81 + (useObsForLearner.size(0) * 78)];
      }
    }
    b_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &b_weak_learner, b_learnerWeights[78], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[79]) {
    int bh_loop_ub;
    int xg_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b_weak_learner.v_init();
    b = b_isCached[79];
    xg_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    bh_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i82{0}; i82 < xg_loop_ub; i82++) {
        b_useObsForLearner[i82] =
            useObsForLearner[i82 + (useObsForLearner.size(0) * 79)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i82 = 0; i82 < bh_loop_ub; i82++) {
        b_useObsForLearner[i82] =
            useObsForLearner[i82 + (useObsForLearner.size(0) * 79)];
      }
    }
    b_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &b_weak_learner, b_learnerWeights[79], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[80]) {
    int ah_loop_ub;
    int dh_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    d_weak_learner.j_init();
    b = b_isCached[80];
    ah_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    dh_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i83{0}; i83 < ah_loop_ub; i83++) {
        b_useObsForLearner[i83] =
            useObsForLearner[i83 + (useObsForLearner.size(0) * 80)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i83 = 0; i83 < dh_loop_ub; i83++) {
        b_useObsForLearner[i83] =
            useObsForLearner[i83 + (useObsForLearner.size(0) * 80)];
      }
    }
    d_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &d_weak_learner, b_learnerWeights[80], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[81]) {
    int ch_loop_ub;
    int fh_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    d_weak_learner.k_init();
    b = b_isCached[81];
    ch_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    fh_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i84{0}; i84 < ch_loop_ub; i84++) {
        b_useObsForLearner[i84] =
            useObsForLearner[i84 + (useObsForLearner.size(0) * 81)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i84 = 0; i84 < fh_loop_ub; i84++) {
        b_useObsForLearner[i84] =
            useObsForLearner[i84 + (useObsForLearner.size(0) * 81)];
      }
    }
    d_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &d_weak_learner, b_learnerWeights[81], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[82]) {
    int eh_loop_ub;
    int hh_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b_weak_learner.w_init();
    b = b_isCached[82];
    eh_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    hh_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i85{0}; i85 < eh_loop_ub; i85++) {
        b_useObsForLearner[i85] =
            useObsForLearner[i85 + (useObsForLearner.size(0) * 82)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i85 = 0; i85 < hh_loop_ub; i85++) {
        b_useObsForLearner[i85] =
            useObsForLearner[i85 + (useObsForLearner.size(0) * 82)];
      }
    }
    b_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &b_weak_learner, b_learnerWeights[82], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[83]) {
    int gh_loop_ub;
    int jh_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b_weak_learner.x_init();
    b = b_isCached[83];
    gh_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    jh_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i86{0}; i86 < gh_loop_ub; i86++) {
        b_useObsForLearner[i86] =
            useObsForLearner[i86 + (useObsForLearner.size(0) * 83)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i86 = 0; i86 < jh_loop_ub; i86++) {
        b_useObsForLearner[i86] =
            useObsForLearner[i86 + (useObsForLearner.size(0) * 83)];
      }
    }
    b_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &b_weak_learner, b_learnerWeights[83], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[84]) {
    int ih_loop_ub;
    int mh_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    g_weak_learner.h_init();
    b = b_isCached[84];
    ih_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    mh_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i87{0}; i87 < ih_loop_ub; i87++) {
        b_useObsForLearner[i87] =
            useObsForLearner[i87 + (useObsForLearner.size(0) * 84)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i87 = 0; i87 < mh_loop_ub; i87++) {
        b_useObsForLearner[i87] =
            useObsForLearner[i87 + (useObsForLearner.size(0) * 84)];
      }
    }
    g_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &g_weak_learner, b_learnerWeights[84], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[85]) {
    int kh_loop_ub;
    int ph_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    weak_learner.g_init();
    b = b_isCached[85];
    kh_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    ph_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i88{0}; i88 < kh_loop_ub; i88++) {
        b_useObsForLearner[i88] =
            useObsForLearner[i88 + (useObsForLearner.size(0) * 85)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i88 = 0; i88 < ph_loop_ub; i88++) {
        b_useObsForLearner[i88] =
            useObsForLearner[i88 + (useObsForLearner.size(0) * 85)];
      }
    }
    predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                        &weak_learner, b_learnerWeights[85], &b, b_classNames,
                        b_classlogicalindices, b_useObsForLearner, initCache,
                        score);
  }
  if (learners[86]) {
    int oh_loop_ub;
    int sh_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    weak_learner.h_init();
    b = b_isCached[86];
    oh_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    sh_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i89{0}; i89 < oh_loop_ub; i89++) {
        b_useObsForLearner[i89] =
            useObsForLearner[i89 + (useObsForLearner.size(0) * 86)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i89 = 0; i89 < sh_loop_ub; i89++) {
        b_useObsForLearner[i89] =
            useObsForLearner[i89 + (useObsForLearner.size(0) * 86)];
      }
    }
    predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                        &weak_learner, b_learnerWeights[86], &b, b_classNames,
                        b_classlogicalindices, b_useObsForLearner, initCache,
                        score);
  }
  if (learners[87]) {
    int qh_loop_ub;
    int uh_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    h_weak_learner.e_init();
    b = b_isCached[87];
    qh_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    uh_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i90{0}; i90 < qh_loop_ub; i90++) {
        b_useObsForLearner[i90] =
            useObsForLearner[i90 + (useObsForLearner.size(0) * 87)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i90 = 0; i90 < uh_loop_ub; i90++) {
        b_useObsForLearner[i90] =
            useObsForLearner[i90 + (useObsForLearner.size(0) * 87)];
      }
    }
    h_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &h_weak_learner, b_learnerWeights[87], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[88]) {
    int th_loop_ub;
    int wh_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    weak_learner.i_init();
    b = b_isCached[88];
    th_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    wh_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i91{0}; i91 < th_loop_ub; i91++) {
        b_useObsForLearner[i91] =
            useObsForLearner[i91 + (useObsForLearner.size(0) * 88)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i91 = 0; i91 < wh_loop_ub; i91++) {
        b_useObsForLearner[i91] =
            useObsForLearner[i91 + (useObsForLearner.size(0) * 88)];
      }
    }
    predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                        &weak_learner, b_learnerWeights[88], &b, b_classNames,
                        b_classlogicalindices, b_useObsForLearner, initCache,
                        score);
  }
  if (learners[89]) {
    int vh_loop_ub;
    int yh_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    i_weak_learner.d_init();
    b = b_isCached[89];
    vh_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    yh_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i92{0}; i92 < vh_loop_ub; i92++) {
        b_useObsForLearner[i92] =
            useObsForLearner[i92 + (useObsForLearner.size(0) * 89)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i92 = 0; i92 < yh_loop_ub; i92++) {
        b_useObsForLearner[i92] =
            useObsForLearner[i92 + (useObsForLearner.size(0) * 89)];
      }
    }
    i_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &i_weak_learner, b_learnerWeights[89], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[90]) {
    int bi_loop_ub;
    int xh_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    d_weak_learner.m_init();
    b = b_isCached[90];
    xh_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    bi_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i93{0}; i93 < xh_loop_ub; i93++) {
        b_useObsForLearner[i93] =
            useObsForLearner[i93 + (useObsForLearner.size(0) * 90)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i93 = 0; i93 < bi_loop_ub; i93++) {
        b_useObsForLearner[i93] =
            useObsForLearner[i93 + (useObsForLearner.size(0) * 90)];
      }
    }
    d_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &d_weak_learner, b_learnerWeights[90], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[91]) {
    int ai_loop_ub;
    int di_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    c_weak_learner.s_init();
    b = b_isCached[91];
    ai_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    di_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i94{0}; i94 < ai_loop_ub; i94++) {
        b_useObsForLearner[i94] =
            useObsForLearner[i94 + (useObsForLearner.size(0) * 91)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i94 = 0; i94 < di_loop_ub; i94++) {
        b_useObsForLearner[i94] =
            useObsForLearner[i94 + (useObsForLearner.size(0) * 91)];
      }
    }
    c_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &c_weak_learner, b_learnerWeights[91], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[92]) {
    int ci_loop_ub;
    int fi_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    weak_learner.j_init();
    b = b_isCached[92];
    ci_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    fi_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i95{0}; i95 < ci_loop_ub; i95++) {
        b_useObsForLearner[i95] =
            useObsForLearner[i95 + (useObsForLearner.size(0) * 92)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i95 = 0; i95 < fi_loop_ub; i95++) {
        b_useObsForLearner[i95] =
            useObsForLearner[i95 + (useObsForLearner.size(0) * 92)];
      }
    }
    predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                        &weak_learner, b_learnerWeights[92], &b, b_classNames,
                        b_classlogicalindices, b_useObsForLearner, initCache,
                        score);
  }
  if (learners[93]) {
    int ei_loop_ub;
    int hi_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    i_weak_learner.e_init();
    b = b_isCached[93];
    ei_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    hi_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i96{0}; i96 < ei_loop_ub; i96++) {
        b_useObsForLearner[i96] =
            useObsForLearner[i96 + (useObsForLearner.size(0) * 93)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i96 = 0; i96 < hi_loop_ub; i96++) {
        b_useObsForLearner[i96] =
            useObsForLearner[i96 + (useObsForLearner.size(0) * 93)];
      }
    }
    i_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &i_weak_learner, b_learnerWeights[93], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[94]) {
    int gi_loop_ub;
    int ji_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    weak_learner.k_init();
    b = b_isCached[94];
    gi_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    ji_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i97{0}; i97 < gi_loop_ub; i97++) {
        b_useObsForLearner[i97] =
            useObsForLearner[i97 + (useObsForLearner.size(0) * 94)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i97 = 0; i97 < ji_loop_ub; i97++) {
        b_useObsForLearner[i97] =
            useObsForLearner[i97 + (useObsForLearner.size(0) * 94)];
      }
    }
    predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                        &weak_learner, b_learnerWeights[94], &b, b_classNames,
                        b_classlogicalindices, b_useObsForLearner, initCache,
                        score);
  }
  if (learners[95]) {
    int ii_loop_ub;
    int mi_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b_weak_learner.y_init();
    b = b_isCached[95];
    ii_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    mi_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i98{0}; i98 < ii_loop_ub; i98++) {
        b_useObsForLearner[i98] =
            useObsForLearner[i98 + (useObsForLearner.size(0) * 95)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i98 = 0; i98 < mi_loop_ub; i98++) {
        b_useObsForLearner[i98] =
            useObsForLearner[i98 + (useObsForLearner.size(0) * 95)];
      }
    }
    b_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &b_weak_learner, b_learnerWeights[95], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[96]) {
    int ki_loop_ub;
    int pi_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    e_weak_learner.k_init();
    b = b_isCached[96];
    ki_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    pi_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i99{0}; i99 < ki_loop_ub; i99++) {
        b_useObsForLearner[i99] =
            useObsForLearner[i99 + (useObsForLearner.size(0) * 96)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i99 = 0; i99 < pi_loop_ub; i99++) {
        b_useObsForLearner[i99] =
            useObsForLearner[i99 + (useObsForLearner.size(0) * 96)];
      }
    }
    e_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &e_weak_learner, b_learnerWeights[96], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[97]) {
    int oi_loop_ub;
    int si_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    d_weak_learner.o_init();
    b = b_isCached[97];
    oi_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    si_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i100{0}; i100 < oi_loop_ub; i100++) {
        b_useObsForLearner[i100] =
            useObsForLearner[i100 + (useObsForLearner.size(0) * 97)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i100 = 0; i100 < si_loop_ub; i100++) {
        b_useObsForLearner[i100] =
            useObsForLearner[i100 + (useObsForLearner.size(0) * 97)];
      }
    }
    d_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &d_weak_learner, b_learnerWeights[97], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[98]) {
    int ri_loop_ub;
    int ui_loop_ub;
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    h_weak_learner.f_init();
    b = b_isCached[98];
    ri_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    ui_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i102{0}; i102 < ri_loop_ub; i102++) {
        b_useObsForLearner[i102] =
            useObsForLearner[i102 + (useObsForLearner.size(0) * 98)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i102 = 0; i102 < ui_loop_ub; i102++) {
        b_useObsForLearner[i102] =
            useObsForLearner[i102 + (useObsForLearner.size(0) * 98)];
      }
    }
    h_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &h_weak_learner, b_learnerWeights[98], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[99]) {
    int qi_loop_ub;
    int ti_loop_ub;
    initCache = firstCache;
    c_weak_learner.t_init();
    b = b_isCached[99];
    qi_loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    ti_loop_ub = useObsForLearner.size(0);
    if ((static_cast<int>(useObsForLearner.size(0) < 4)) != 0) {
      for (int i101{0}; i101 < qi_loop_ub; i101++) {
        b_useObsForLearner[i101] =
            useObsForLearner[i101 + (useObsForLearner.size(0) * 99)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i101 = 0; i101 < ti_loop_ub; i101++) {
        b_useObsForLearner[i101] =
            useObsForLearner[i101 + (useObsForLearner.size(0) * 99)];
      }
    }
    c_predictOneWithCache(d_X, cachedScore, cachedWeights, combiner,
                          &c_weak_learner, b_learnerWeights[99], &b,
                          b_classNames, b_classlogicalindices,
                          b_useObsForLearner, initCache, score);
  }
}

} // namespace ensembleutils
} // namespace coder
} // namespace learning
} // namespace classreg
} // namespace coder
} // namespace ITER

//
// File trailer for aggregatePredict.cpp
//
// [EOF]
//
