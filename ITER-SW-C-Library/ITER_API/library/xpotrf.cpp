//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xpotrf.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "xpotrf.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : int h_n
//                double A[15][15]
//                int d_lda
// Return Type  : int
//
namespace ITER {
namespace coder {
namespace internal {
namespace lapack {
int xpotrf(int h_n, double A[15][15], int d_lda)
{
  int info;
  int j;
  bool exitg1;
  info = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j <= (h_n - 1))) {
    double ajj;
    double ssq;
    int idxA1j;
    int idxAjj;
    idxA1j = j * d_lda;
    idxAjj = idxA1j + j;
    ssq = 0.0;
    if (j >= 1) {
      for (int k{0}; k < j; k++) {
        double ssq_tmp;
        ssq_tmp = (&A[0][0])[idxA1j + k];
        ssq += ssq_tmp * ssq_tmp;
      }
    }
    ajj = (&A[0][0])[idxAjj] - ssq;
    if (ajj > 0.0) {
      ajj = std::sqrt(ajj);
      (&A[0][0])[idxAjj] = ajj;
      if ((j + 1) < h_n) {
        double b_a;
        int ia0;
        int idxAjjp1;
        int nmj;
        nmj = (h_n - j) - 2;
        ia0 = (idxA1j + d_lda) + 1;
        idxAjjp1 = idxAjj + d_lda;
        if ((j != 0) && ((nmj + 1) != 0)) {
          int b_i;
          int b_iy;
          int iac;
          b_iy = idxAjjp1;
          b_i = ia0 + (d_lda * nmj);
          iac = ia0;
          while (((d_lda > 0) && (iac <= b_i)) ||
                 ((d_lda < 0) && (iac >= b_i))) {
            double c;
            int i2;
            c = 0.0;
            i2 = (iac + j) - 1;
            for (int ia{iac}; ia <= i2; ia++) {
              c += (&A[0][0])[ia - 1] * (&A[0][0])[(idxA1j + ia) - iac];
            }
            (&A[0][0])[b_iy] += -c;
            b_iy += d_lda;
            iac += d_lda;
          }
        }
        b_a = 1.0 / ajj;
        if (d_lda >= 1) {
          int b_k;
          int i1;
          i1 = (idxAjjp1 + (d_lda * nmj)) + 1;
          b_k = idxAjjp1 + 1;
          while (((d_lda > 0) && (b_k <= i1)) || ((d_lda < 0) && (b_k >= i1))) {
            (&A[0][0])[b_k - 1] *= b_a;
            b_k += d_lda;
          }
        }
      }
      j++;
    } else {
      (&A[0][0])[idxAjj] = ajj;
      info = j + 1;
      exitg1 = true;
    }
  }
  return info;
}

} // namespace lapack
} // namespace internal
} // namespace coder
} // namespace ITER

//
// File trailer for xpotrf.cpp
//
// [EOF]
//
