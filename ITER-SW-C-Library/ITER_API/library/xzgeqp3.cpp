//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzgeqp3.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "xzgeqp3.h"
#include "rt_nonfinite.h"
#include "xzlarf.h"
#include "xzlarfg.h"
#include <string.h>

// Function Definitions
//
// Arguments    : double A[15][15]
//                int m
//                int h_n
//                int nfxd
//                double tau[15]
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace internal {
namespace reflapack {
void qrf(double A[15][15], int m, int h_n, int nfxd, double tau[15])
{
  double work[15];
  double d_atmp;
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int b_i = 0; b_i < 15; b_i++) {
    tau[b_i] = 0.0;
    work[b_i] = 0.0;
  }
  for (int c_i{0}; c_i < nfxd; c_i++) {
    double d;
    int b_mmi;
    int c_ii;
    c_ii = (c_i * 15) + c_i;
    b_mmi = m - c_i;
    if ((c_i + 1) < m) {
      d_atmp = (&A[0][0])[c_ii];
      d = c_xzlarfg(b_mmi, &d_atmp, A, c_ii + 2);
      tau[c_i] = d;
      (&A[0][0])[c_ii] = d_atmp;
    } else {
      d = 0.0;
      tau[c_i] = 0.0;
    }
    if ((c_i + 1) < h_n) {
      double e_atmp;
      e_atmp = (&A[0][0])[c_ii];
      (&A[0][0])[c_ii] = 1.0;
      d_xzlarf(b_mmi, (h_n - c_i) - 1, c_ii + 1, d, A, c_ii + 16, work);
      (&A[0][0])[c_ii] = e_atmp;
    }
  }
}

} // namespace reflapack
} // namespace internal
} // namespace coder
} // namespace ITER

//
// File trailer for xzgeqp3.cpp
//
// [EOF]
//
