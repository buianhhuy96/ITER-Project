//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: updateCache.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "updateCache.h"
#include "ITER_API_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &learnerscore
//                ::coder::array<double, 2U> &cachedScore
//                ::coder::array<double, 1U> &cachedWeights
//                bool *cached
//                double learnerWeight
//                const char combinerName[15]
//                const ::coder::array<bool, 1U> &obsIndices
//                ::coder::array<double, 2U> &score
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace classreg {
namespace learning {
namespace coder {
namespace ensembleutils {
void updateCache(const ::coder::array<double, 2U> &learnerscore,
                 ::coder::array<double, 2U> &cachedScore,
                 ::coder::array<double, 1U> &cachedWeights, bool *cached,
                 double learnerWeight, const char combinerName[15],
                 const ::coder::array<bool, 1U> &obsIndices,
                 ::coder::array<double, 2U> &score)
{
  static const char b_cv[15]{'w', 'e', 'i', 'g', 'h', 't', 'e', 'd',
                             'a', 'v', 'e', 'r', 'a', 'g', 'e'};
  ::coder::array<double, 2U> b_cachedScore;
  ::coder::array<double, 1U> b_cachedWeights;
  ::coder::array<int, 1U> r;
  ::coder::array<int, 1U> r1;
  ::coder::array<int, 1U> r2;
  int i1;
  int i3;
  int loop_ub;
  bool b_x[2];
  score.set_size(cachedScore.size(0), 2);
  loop_ub = cachedScore.size(0);
  if ((static_cast<int>((loop_ub * 2) < 4)) != 0) {
    for (int b_i{0}; b_i < 2; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        score[i1 + (score.size(0) * b_i)] =
            cachedScore[i1 + (cachedScore.size(0) * b_i)];
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1)

    for (int b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        score[i1 + (score.size(0) * b_i)] =
            cachedScore[i1 + (cachedScore.size(0) * b_i)];
      }
    }
  }
  if ((!(*cached)) && (!(learnerWeight <= 0.0))) {
    int b_end;
    int b_loop_ub;
    int b_partialTrueCount;
    int b_trueCount;
    int c_end;
    int c_loop_ub;
    int c_partialTrueCount;
    int c_trueCount;
    int d_loop_ub;
    int e_loop_ub;
    int end;
    int kstr;
    int partialTrueCount;
    int trueCount;
    bool b_bool;
    *cached = true;
    end = obsIndices.size(0) - 1;
    trueCount = 0;
    for (int c_i{0}; c_i <= end; c_i++) {
      if (obsIndices[c_i]) {
        trueCount++;
      }
    }
    r.set_size(trueCount);
    partialTrueCount = 0;
    for (int d_i{0}; d_i <= end; d_i++) {
      if (obsIndices[d_i]) {
        r[partialTrueCount] = d_i + 1;
        partialTrueCount++;
      }
    }
    b_end = obsIndices.size(0) - 1;
    b_trueCount = 0;
    for (int e_i{0}; e_i <= b_end; e_i++) {
      if (obsIndices[e_i]) {
        b_trueCount++;
      }
    }
    r1.set_size(b_trueCount);
    b_partialTrueCount = 0;
    for (int g_i{0}; g_i <= b_end; g_i++) {
      if (obsIndices[g_i]) {
        r1[b_partialTrueCount] = g_i + 1;
        b_partialTrueCount++;
      }
    }
    b_cachedScore.set_size(r1.size(0), 2);
    b_loop_ub = r1.size(0);
    if ((static_cast<int>((r1.size(0) * 2) < 4)) != 0) {
      for (int i2{0}; i2 < 2; i2++) {
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          b_cachedScore[i3 + (b_cachedScore.size(0) * i2)] =
              cachedScore[(r1[i3] + (cachedScore.size(0) * i2)) - 1] +
              (learnerscore[(r[i3] + (learnerscore.size(0) * i2)) - 1] *
               learnerWeight);
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3)

      for (int i2 = 0; i2 < 2; i2++) {
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          b_cachedScore[i3 + (b_cachedScore.size(0) * i2)] =
              cachedScore[(r1[i3] + (cachedScore.size(0) * i2)) - 1] +
              (learnerscore[(r[i3] + (learnerscore.size(0) * i2)) - 1] *
               learnerWeight);
        }
      }
    }
    c_loop_ub = b_cachedScore.size(0);
    for (int i4{0}; i4 < 2; i4++) {
      for (int i5{0}; i5 < c_loop_ub; i5++) {
        cachedScore[(r1[i5] + (cachedScore.size(0) * i4)) - 1] =
            b_cachedScore[i5 + (b_cachedScore.size(0) * i4)];
      }
    }
    c_end = obsIndices.size(0) - 1;
    c_trueCount = 0;
    for (int h_i{0}; h_i <= c_end; h_i++) {
      if (obsIndices[h_i]) {
        c_trueCount++;
      }
    }
    r2.set_size(c_trueCount);
    c_partialTrueCount = 0;
    for (int k_i{0}; k_i <= c_end; k_i++) {
      if (obsIndices[k_i]) {
        r2[c_partialTrueCount] = k_i + 1;
        c_partialTrueCount++;
      }
    }
    b_cachedWeights.set_size(r2.size(0));
    d_loop_ub = r2.size(0);
    if ((static_cast<int>(r2.size(0) < 4)) != 0) {
      for (int i6{0}; i6 < d_loop_ub; i6++) {
        b_cachedWeights[i6] = cachedWeights[r2[i6] - 1] + learnerWeight;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i6 = 0; i6 < d_loop_ub; i6++) {
        b_cachedWeights[i6] = cachedWeights[r2[i6] - 1] + learnerWeight;
      }
    }
    e_loop_ub = b_cachedWeights.size(0);
    for (int i7{0}; i7 < e_loop_ub; i7++) {
      cachedWeights[r2[i7] - 1] = b_cachedWeights[i7];
    }
    b_bool = false;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 15) {
        if (cv1[(static_cast<unsigned char>(combinerName[kstr])) &
                (static_cast<unsigned char>(127))] !=
            cv1[static_cast<int>(b_cv[kstr])]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
    if (b_bool) {
      int i9;
      i9 = cachedScore.size(0);
      for (int m_i{0}; m_i < i9; m_i++) {
        if (cachedWeights[m_i] == 0.0) {
          int k;
          bool exitg2;
          bool y;
          b_x[0] = (cachedScore[m_i] == 0.0);
          b_x[1] = (cachedScore[m_i + cachedScore.size(0)] == 0.0);
          y = true;
          k = 0;
          exitg2 = false;
          while ((!exitg2) && (k < 2)) {
            if (!b_x[k]) {
              y = false;
              exitg2 = true;
            } else {
              k++;
            }
          }
          if (y) {
            score[m_i] = rtNaN;
            score[m_i + score.size(0)] = rtNaN;
          } else {
            int b_k;
            bool b_y;
            b_x[0] = (cachedScore[m_i] < 0.0);
            b_x[1] = (cachedScore[m_i + cachedScore.size(0)] < 0.0);
            b_y = true;
            b_k = 0;
            exitg2 = false;
            while ((!exitg2) && (b_k < 2)) {
              if (!b_x[b_k]) {
                b_y = false;
                exitg2 = true;
              } else {
                b_k++;
              }
            }
            if (b_y) {
              score[m_i] = rtMinusInf;
              score[m_i + score.size(0)] = rtMinusInf;
            } else {
              score[m_i] = rtInf;
              score[m_i + score.size(0)] = rtInf;
            }
          }
        } else {
          score[m_i] = cachedScore[m_i] / cachedWeights[m_i];
          score[m_i + score.size(0)] =
              cachedScore[m_i + cachedScore.size(0)] / cachedWeights[m_i];
        }
      }
    } else {
      int b_i8;
      b_i8 = cachedScore.size(0);
      if ((static_cast<int>((b_i8 * 2) < 4)) != 0) {
        for (int q_i{0}; q_i < b_i8; q_i++) {
          score[q_i] = cachedScore[q_i];
          score[q_i + score.size(0)] = cachedScore[q_i + cachedScore.size(0)];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int q_i = 0; q_i < b_i8; q_i++) {
          score[q_i] = cachedScore[q_i];
          score[q_i + score.size(0)] = cachedScore[q_i + cachedScore.size(0)];
        }
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
// File trailer for updateCache.cpp
//
// [EOF]
//
