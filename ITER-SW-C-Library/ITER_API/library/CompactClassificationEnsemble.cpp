//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CompactClassificationEnsemble.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "CompactClassificationEnsemble.h"
#include "ITER_API_data.h"
#include "ITER_API_internal_types.h"
#include "aggregatePredict.h"
#include "invlogit.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &Xin
//                ::coder::array<double, 1U> &labels
//                ::coder::array<double, 2U> &score
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace classreg {
namespace learning {
namespace classif {
void CompactClassificationEnsemble::predict(
    const ::coder::array<double, 2U> &Xin, ::coder::array<double, 1U> &labels,
    ::coder::array<double, 2U> &score) const
{
  ::coder::array<double, 2U> scoreIn;
  ::coder::array<double, 1U> classnum;
  ::coder::array<bool, 2U> b;
  ::coder::array<bool, 2U> r;
  ::coder::array<bool, 1U> notNaN;
  ::coder::array<bool, 1U> y;
  double b_d1;
  int b_iindx;
  unsigned int b_u1;
  int i1;
  int i16;
  int i17;
  int i18;
  int i19;
  int i23;
  int i3;
  bool b_bv[100];
  if (Xin.size(0) == 0) {
    score.set_size(0, 2);
    labels.set_size(0);
  } else {
    int b_hi;
    int b_loop_ub;
    int g_loop_ub;
    int h_loop_ub;
    int i27;
    int i29;
    int i_loop_ub;
    int iindx;
    int j_loop_ub;
    int k_loop_ub;
    int loop_ub;
    int szy_idx_0;
    scoreIn.set_size(Xin.size(0), 2);
    loop_ub = Xin.size(0);
    if ((static_cast<int>((Xin.size(0) * 2) < 4)) != 0) {
      for (int b_i{0}; b_i < 2; b_i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          scoreIn[i1 + (scoreIn.size(0) * b_i)] = 0.0;
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1)

      for (int b_i = 0; b_i < 2; b_i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          scoreIn[i1 + (scoreIn.size(0) * b_i)] = 0.0;
        }
      }
    }
    r.set_size(Xin.size(0), 100);
    b_loop_ub = Xin.size(0);
    if ((static_cast<int>((100 * Xin.size(0)) < 4)) != 0) {
      for (int i2{0}; i2 < 100; i2++) {
        b_bv[i2] = true;
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          r[i3 + (r.size(0) * i2)] = true;
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3)

      for (int i2 = 0; i2 < 100; i2++) {
        b_bv[i2] = true;
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          r[i3 + (r.size(0) * i2)] = true;
        }
      }
    }
    coder::ensembleutils::aggregatePredict(Xin, scoreIn, LearnerWeights,
                                           IsCached, ClassNames,
                                           ClassLogicalIndices, b_bv, r);
    switch (ScoreTransform) {
    case coderutils::Logit: {
      int b_i8;
      int i4;
      score.set_size(scoreIn.size(0), 2);
      i4 = (scoreIn.size(0) * 2) - 1;
      b_i8 = i4;
      if ((static_cast<int>((i4 + 1) < 4)) != 0) {
        for (int c_i{0}; c_i <= i4; c_i++) {
          score[c_i] = 1.0 / (std::exp(-scoreIn[c_i]) + 1.0);
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int c_i = 0; c_i <= b_i8; c_i++) {
          score[c_i] = 1.0 / (std::exp(-scoreIn[c_i]) + 1.0);
        }
      }
    } break;
    case coderutils::Doublelogit: {
      int i5;
      int i9;
      score.set_size(scoreIn.size(0), 2);
      i5 = (scoreIn.size(0) * 2) - 1;
      i9 = i5;
      if ((static_cast<int>((i5 + 1) < 4)) != 0) {
        for (int d_i{0}; d_i <= i5; d_i++) {
          score[d_i] = 1.0 / (std::exp(-2.0 * scoreIn[d_i]) + 1.0);
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int d_i = 0; d_i <= i9; d_i++) {
          score[d_i] = 1.0 / (std::exp(-2.0 * scoreIn[d_i]) + 1.0);
        }
      }
    } break;
    case coderutils::Invlogit:
      coder::transform::b_invlogit(scoreIn, score);
      break;
    case coderutils::Ismax: {
      int d_loop_ub;
      int i21;
      score.set_size(scoreIn.size(0), 2);
      d_loop_ub = scoreIn.size(0);
      if ((static_cast<int>((scoreIn.size(0) * 2) < 4)) != 0) {
        for (int i13{0}; i13 < 2; i13++) {
          for (i17 = 0; i17 < d_loop_ub; i17++) {
            score[i17 + (score.size(0) * i13)] = 0.0;
          }
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i17)

        for (int i13 = 0; i13 < 2; i13++) {
          for (i17 = 0; i17 < d_loop_ub; i17++) {
            score[i17 + (score.size(0) * i13)] = 0.0;
          }
        }
      }
      i21 = scoreIn.size(0);
      for (int h_n{0}; h_n < i21; h_n++) {
        int inmaxind;
        inmaxind = 0;
        if (scoreIn[h_n + scoreIn.size(0)] > scoreIn[h_n]) {
          inmaxind = 1;
        }
        score[h_n + (score.size(0) * inmaxind)] = 1.0;
      }
    } break;
    case coderutils::b_Sign: {
      int i10;
      int i6;
      score.set_size(scoreIn.size(0), 2);
      i6 = (scoreIn.size(0) * 2) - 1;
      i10 = i6;
      if ((static_cast<int>((i6 + 1) < 4)) != 0) {
        for (int e_i{0}; e_i <= i6; e_i++) {
          if (scoreIn[e_i] < 0.0) {
            score[e_i] = -1.0;
          } else if (scoreIn[e_i] > 0.0) {
            score[e_i] = 1.0;
          } else {
            score[e_i] = 0.0;
          }
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int e_i = 0; e_i <= i10; e_i++) {
          if (scoreIn[e_i] < 0.0) {
            score[e_i] = -1.0;
          } else if (scoreIn[e_i] > 0.0) {
            score[e_i] = 1.0;
          } else {
            score[e_i] = 0.0;
          }
        }
      }
    } break;
    case coderutils::Symmetric: {
      int e_loop_ub;
      score.set_size(scoreIn.size(0), 2);
      e_loop_ub = scoreIn.size(0);
      if ((static_cast<int>((scoreIn.size(0) * 2) < 4)) != 0) {
        for (int i14{0}; i14 < 2; i14++) {
          for (i18 = 0; i18 < e_loop_ub; i18++) {
            score[i18 + (score.size(0) * i14)] =
                (2.0 * scoreIn[i18 + (scoreIn.size(0) * i14)]) - 1.0;
          }
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i18)

        for (int i14 = 0; i14 < 2; i14++) {
          for (i18 = 0; i18 < e_loop_ub; i18++) {
            score[i18 + (score.size(0) * i14)] =
                (2.0 * scoreIn[i18 + (scoreIn.size(0) * i14)]) - 1.0;
          }
        }
      }
    } break;
    case coderutils::Symmetricismax: {
      int f_loop_ub;
      int i22;
      score.set_size(scoreIn.size(0), 2);
      f_loop_ub = scoreIn.size(0);
      if ((static_cast<int>((scoreIn.size(0) * 2) < 4)) != 0) {
        for (int i15{0}; i15 < 2; i15++) {
          for (i19 = 0; i19 < f_loop_ub; i19++) {
            score[i19 + (score.size(0) * i15)] = -1.0;
          }
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i19)

        for (int i15 = 0; i15 < 2; i15++) {
          for (i19 = 0; i19 < f_loop_ub; i19++) {
            score[i19 + (score.size(0) * i15)] = -1.0;
          }
        }
      }
      i22 = scoreIn.size(0);
      for (int p_n{0}; p_n < i22; p_n++) {
        int b_inmaxind;
        b_inmaxind = 0;
        if (scoreIn[p_n + scoreIn.size(0)] > scoreIn[p_n]) {
          b_inmaxind = 1;
        }
        score[p_n + (score.size(0) * b_inmaxind)] = 1.0;
      }
    } break;
    case coderutils::Symmetriclogit: {
      int i11;
      int i7;
      score.set_size(scoreIn.size(0), 2);
      i7 = (scoreIn.size(0) * 2) - 1;
      i11 = i7;
      if ((static_cast<int>((i7 + 1) < 4)) != 0) {
        for (int g_i{0}; g_i <= i7; g_i++) {
          score[g_i] = (2.0 * (1.0 / (std::exp(-scoreIn[g_i]) + 1.0))) - 1.0;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int g_i = 0; g_i <= i11; g_i++) {
          score[g_i] = (2.0 * (1.0 / (std::exp(-scoreIn[g_i]) + 1.0))) - 1.0;
        }
      }
    } break;
    default: {
      int c_loop_ub;
      score.set_size(scoreIn.size(0), 2);
      c_loop_ub = scoreIn.size(0);
      if ((static_cast<int>((scoreIn.size(0) * 2) < 4)) != 0) {
        for (int i12{0}; i12 < 2; i12++) {
          for (i16 = 0; i16 < c_loop_ub; i16++) {
            score[i16 + (score.size(0) * i12)] =
                scoreIn[i16 + (scoreIn.size(0) * i12)];
          }
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i16)

        for (int i12 = 0; i12 < 2; i12++) {
          for (i16 = 0; i16 < c_loop_ub; i16++) {
            score[i16 + (score.size(0) * i12)] =
                scoreIn[i16 + (scoreIn.size(0) * i12)];
          }
        }
      }
    } break;
    }
    b.set_size(score.size(0), 2);
    g_loop_ub = score.size(0);
    if ((static_cast<int>((score.size(0) * 2) < 4)) != 0) {
      for (int i20{0}; i20 < 2; i20++) {
        for (i23 = 0; i23 < g_loop_ub; i23++) {
          b[i23 + (b.size(0) * i20)] =
              std::isnan(score[i23 + (score.size(0) * i20)]);
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i23)

      for (int i20 = 0; i20 < 2; i20++) {
        for (i23 = 0; i23 < g_loop_ub; i23++) {
          b[i23 + (b.size(0) * i20)] =
              std::isnan(score[i23 + (score.size(0) * i20)]);
        }
      }
    }
    szy_idx_0 = b.size(0);
    y.set_size(b.size(0));
    h_loop_ub = b.size(0);
    if ((static_cast<int>(b.size(0) < 4)) != 0) {
      for (int i24{0}; i24 < szy_idx_0; i24++) {
        y[i24] = false;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i24 = 0; i24 < h_loop_ub; i24++) {
        y[i24] = false;
      }
    }
    b_hi = b.size(0);
    for (int k{0}; k < b_hi; k++) {
      int b_k;
      bool exitg1;
      y[k] = true;
      b_k = 0;
      exitg1 = false;
      while ((!exitg1) && (b_k < 2)) {
        if (!b[k + (b.size(0) * b_k)]) {
          y[k] = false;
          exitg1 = true;
        } else {
          b_k++;
        }
      }
    }
    notNaN.set_size(y.size(0));
    i_loop_ub = y.size(0);
    if ((static_cast<int>(y.size(0) < 4)) != 0) {
      for (int i25{0}; i25 < i_loop_ub; i25++) {
        notNaN[i25] = !y[i25];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i25 = 0; i25 < i_loop_ub; i25++) {
        notNaN[i25] = !y[i25];
      }
    }
    if (Prior[0] < Prior[1]) {
      iindx = 1;
    } else if (std::isnan(Prior[0])) {
      if (!std::isnan(Prior[1])) {
        iindx = 1;
      } else {
        iindx = 0;
      }
    } else {
      iindx = 0;
    }
    classnum.set_size(score.size(0));
    j_loop_ub = score.size(0);
    if ((static_cast<int>(score.size(0) < 4)) != 0) {
      for (int i26{0}; i26 < j_loop_ub; i26++) {
        classnum[i26] = rtNaN;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i26 = 0; i26 < j_loop_ub; i26++) {
        classnum[i26] = rtNaN;
      }
    }
    i27 = notNaN.size(0);
    if ((static_cast<int>(notNaN.size(0) < 4)) != 0) {
      for (int idx{0}; idx < i27; idx++) {
        if (notNaN[idx]) {
          if (score[idx] < score[idx + score.size(0)]) {
            b_iindx = 2;
          } else if (std::isnan(score[idx])) {
            if (!std::isnan(score[idx + score.size(0)])) {
              b_iindx = 2;
            } else {
              b_iindx = 1;
            }
          } else {
            b_iindx = 1;
          }
          classnum[idx] = static_cast<double>(b_iindx);
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_iindx)

      for (int idx = 0; idx < i27; idx++) {
        if (notNaN[idx]) {
          if (score[idx] < score[idx + score.size(0)]) {
            b_iindx = 2;
          } else if (std::isnan(score[idx])) {
            if (!std::isnan(score[idx + score.size(0)])) {
              b_iindx = 2;
            } else {
              b_iindx = 1;
            }
          } else {
            b_iindx = 1;
          }
          classnum[idx] = static_cast<double>(b_iindx);
        }
      }
    }
    labels.set_size(score.size(0));
    k_loop_ub = score.size(0);
    if ((static_cast<int>(score.size(0) < 4)) != 0) {
      for (int i28{0}; i28 < k_loop_ub; i28++) {
        labels[i28] = ClassNames[iindx];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i28 = 0; i28 < k_loop_ub; i28++) {
        labels[i28] = ClassNames[iindx];
      }
    }
    i29 = notNaN.size(0);
    if ((static_cast<int>(notNaN.size(0) < 4)) != 0) {
      for (int b_idx{0}; b_idx < i29; b_idx++) {
        if (notNaN[b_idx]) {
          double d;
          unsigned int c_u;
          d = classnum[b_idx];
          if (d < 4.294967296E+9) {
            c_u = static_cast<unsigned int>(d);
          } else {
            c_u = 0U;
          }
          labels[b_idx] = ClassNames[(static_cast<int>(c_u)) - 1];
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_d1, b_u1)

      for (int b_idx = 0; b_idx < i29; b_idx++) {
        if (notNaN[b_idx]) {
          b_d1 = classnum[b_idx];
          if (b_d1 < 4.294967296E+9) {
            b_u1 = static_cast<unsigned int>(b_d1);
          } else {
            b_u1 = 0U;
          }
          labels[b_idx] = ClassNames[(static_cast<int>(b_u1)) - 1];
        }
      }
    }
  }
}

} // namespace classif
} // namespace learning
} // namespace classreg
} // namespace coder
} // namespace ITER

//
// File trailer for CompactClassificationEnsemble.cpp
//
// [EOF]
//
