//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzlarf.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "xzlarf.h"
#include "ITER_API_rtwutil.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "xgerc.h"
#include "coder_array.h"
#include <cstring>
#include <string.h>

// Function Declarations
namespace ITER {
static int div_nde_s32_floor(int numerator);

}

// Function Definitions
//
// Arguments    : int numerator
// Return Type  : int
//
namespace ITER {
static int div_nde_s32_floor(int numerator)
{
  int b_numerator;
  if ((numerator < 0) && ((numerator % 15) != 0)) {
    b_numerator = -1;
  } else {
    b_numerator = 0;
  }
  return (numerator / 15) + b_numerator;
}

//
// Arguments    : int m
//                int h_n
//                int iv0
//                double tau
//                ::coder::array<double, 2U> &c_C
//                int ic0
//                int ldc
//                double work[6]
// Return Type  : void
//
namespace coder {
namespace internal {
namespace reflapack {
void b_xzlarf(int m, int h_n, int iv0, double tau,
              ::coder::array<double, 2U> &c_C, int ic0, int ldc, double work[6])
{
  int lastc;
  int lastv;
  if (tau != 0.0) {
    int b_i;
    int b_lastc;
    bool exitg1;
    lastv = m;
    b_i = iv0 + m;
    exitg1 = false;
    while ((!exitg1) && (lastv > 0)) {
      if (c_C[b_i - 2] == 0.0) {
        lastv--;
        b_i--;
      } else {
        exitg1 = true;
      }
    }
    b_lastc = h_n - 1;
    exitg1 = false;
    while ((!exitg1) && ((b_lastc + 1) > 0)) {
      int coltop;
      int exitg2;
      int ia;
      coltop = ic0 + (b_lastc * ldc);
      ia = coltop;
      do {
        exitg2 = 0;
        if (ia <= ((coltop + lastv) - 1)) {
          if (c_C[ia - 1] != 0.0) {
            exitg2 = 1;
          } else {
            ia++;
          }
        } else {
          b_lastc--;
          exitg2 = 2;
        }
      } while (exitg2 == 0);
      if (exitg2 == 1) {
        exitg1 = true;
      }
    }
    lastc = b_lastc;
  } else {
    lastv = 0;
    lastc = -1;
  }
  if (lastv > 0) {
    if ((lastc + 1) != 0) {
      int c_i;
      int c_iy;
      int iac;
      if ((static_cast<int>((lastc + 1) < 4)) != 0) {
        if (0 <= lastc) {
          (void)std::memset(
              &work[0], 0,
              (static_cast<unsigned int>(static_cast<int>(lastc + 1))) *
                  (sizeof(double)));
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int b_iy = 0; b_iy <= lastc; b_iy++) {
          work[b_iy] = 0.0;
        }
      }
      c_iy = 0;
      c_i = ic0 + (ldc * lastc);
      iac = ic0;
      while (((ldc > 0) && (iac <= c_i)) || ((ldc < 0) && (iac >= c_i))) {
        double c;
        int i2;
        c = 0.0;
        i2 = (iac + lastv) - 1;
        for (int b_ia{iac}; b_ia <= i2; b_ia++) {
          c += c_C[b_ia - 1] * c_C[((iv0 + b_ia) - iac) - 1];
        }
        work[c_iy] += c;
        c_iy++;
        iac += ldc;
      }
    }
    if (!((-tau) == 0.0)) {
      int b_jA;
      b_jA = ic0;
      for (int j{0}; j <= lastc; j++) {
        if (work[j] != 0.0) {
          double temp;
          int i1;
          temp = work[j] * (-tau);
          i1 = lastv + b_jA;
          for (int ijA{b_jA}; ijA < i1; ijA++) {
            c_C[ijA - 1] =
                c_C[ijA - 1] + (c_C[((iv0 + ijA) - b_jA) - 1] * temp);
          }
        }
        b_jA += ldc;
      }
    }
  }
}

//
// Arguments    : int m
//                int h_n
//                int iv0
//                double tau
//                double c_C[4][4]
//                int ic0
//                double work[4]
// Return Type  : void
//
void c_xzlarf(int m, int h_n, int iv0, double tau, double c_C[4][4], int ic0,
              double work[4])
{
  int lastc;
  int lastv;
  if (tau != 0.0) {
    int b_i;
    int b_lastc;
    bool exitg2;
    lastv = m;
    b_i = iv0 + m;
    while ((lastv > 0) && ((&c_C[0][0])[b_i - 2] == 0.0)) {
      lastv--;
      b_i--;
    }
    b_lastc = h_n - 1;
    exitg2 = false;
    while ((!exitg2) && ((b_lastc + 1) > 0)) {
      int coltop;
      int exitg1;
      int ia;
      coltop = ic0 + (b_lastc * 4);
      ia = coltop;
      do {
        exitg1 = 0;
        if (ia <= ((coltop + lastv) - 1)) {
          if ((&c_C[0][0])[ia - 1] != 0.0) {
            exitg1 = 1;
          } else {
            ia++;
          }
        } else {
          b_lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);
      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
    lastc = b_lastc;
  } else {
    lastv = 0;
    lastc = -1;
  }
  if (lastv > 0) {
    if ((lastc + 1) != 0) {
      int c_i;
      if ((static_cast<int>((lastc + 1) < 4)) != 0) {
        if (0 <= lastc) {
          (void)std::memset(
              &work[0], 0,
              (static_cast<unsigned int>(static_cast<int>(lastc + 1))) *
                  (sizeof(double)));
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int b_iy = 0; b_iy <= lastc; b_iy++) {
          work[b_iy] = 0.0;
        }
      }
      c_i = ic0 + (lastc * 4);
      for (int iac{ic0}; iac <= c_i; iac += 4) {
        double c;
        int i2;
        c = 0.0;
        i2 = (iac + lastv) - 1;
        for (int b_ia{iac}; b_ia <= i2; b_ia++) {
          c += (&c_C[0][0])[b_ia - 1] * (&c_C[0][0])[((iv0 + b_ia) - iac) - 1];
        }
        int i3;
        i3 = asr_s32(iac - ic0, 2U);
        work[i3] += c;
      }
    }
    if (!((-tau) == 0.0)) {
      int b_jA;
      b_jA = ic0;
      for (int j{0}; j <= lastc; j++) {
        if (work[j] != 0.0) {
          double temp;
          int i1;
          temp = work[j] * (-tau);
          i1 = lastv + b_jA;
          for (int ijA{b_jA}; ijA < i1; ijA++) {
            (&c_C[0][0])[ijA - 1] +=
                (&c_C[0][0])[((iv0 + ijA) - b_jA) - 1] * temp;
          }
        }
        b_jA += 4;
      }
    }
  }
}

//
// Arguments    : int m
//                int h_n
//                int iv0
//                double tau
//                double c_C[15][15]
//                int ic0
//                double work[15]
// Return Type  : void
//
void d_xzlarf(int m, int h_n, int iv0, double tau, double c_C[15][15], int ic0,
              double work[15])
{
  int lastc;
  int lastv;
  if (tau != 0.0) {
    int b_i;
    int b_lastc;
    bool exitg2;
    lastv = m;
    b_i = iv0 + m;
    while ((lastv > 0) && ((&c_C[0][0])[b_i - 2] == 0.0)) {
      lastv--;
      b_i--;
    }
    b_lastc = h_n - 1;
    exitg2 = false;
    while ((!exitg2) && ((b_lastc + 1) > 0)) {
      int coltop;
      int exitg1;
      int ia;
      coltop = ic0 + (b_lastc * 15);
      ia = coltop;
      do {
        exitg1 = 0;
        if (ia <= ((coltop + lastv) - 1)) {
          if ((&c_C[0][0])[ia - 1] != 0.0) {
            exitg1 = 1;
          } else {
            ia++;
          }
        } else {
          b_lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);
      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
    lastc = b_lastc;
  } else {
    lastv = 0;
    lastc = -1;
  }
  if (lastv > 0) {
    if ((lastc + 1) != 0) {
      int c_i;
      if ((static_cast<int>((lastc + 1) < 4)) != 0) {
        if (0 <= lastc) {
          (void)std::memset(
              &work[0], 0,
              (static_cast<unsigned int>(static_cast<int>(lastc + 1))) *
                  (sizeof(double)));
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int b_iy = 0; b_iy <= lastc; b_iy++) {
          work[b_iy] = 0.0;
        }
      }
      c_i = ic0 + (15 * lastc);
      for (int iac{ic0}; iac <= c_i; iac += 15) {
        double c;
        int i2;
        c = 0.0;
        i2 = (iac + lastv) - 1;
        for (int b_ia{iac}; b_ia <= i2; b_ia++) {
          c += (&c_C[0][0])[b_ia - 1] * (&c_C[0][0])[((iv0 + b_ia) - iac) - 1];
        }
        int i3;
        i3 = div_nde_s32_floor(iac - ic0);
        work[i3] += c;
      }
    }
    if (!((-tau) == 0.0)) {
      int b_jA;
      b_jA = ic0;
      for (int j{0}; j <= lastc; j++) {
        if (work[j] != 0.0) {
          double temp;
          int i1;
          temp = work[j] * (-tau);
          i1 = lastv + b_jA;
          for (int ijA{b_jA}; ijA < i1; ijA++) {
            (&c_C[0][0])[ijA - 1] +=
                (&c_C[0][0])[((iv0 + ijA) - b_jA) - 1] * temp;
          }
        }
        b_jA += 15;
      }
    }
  }
}

//
// Arguments    : int m
//                int h_n
//                int iv0
//                double tau
//                ::coder::array<double, 2U> &c_C
//                int ic0
//                int ldc
//                ::coder::array<double, 1U> &work
// Return Type  : void
//
void xzlarf(int m, int h_n, int iv0, double tau,
            ::coder::array<double, 2U> &c_C, int ic0, int ldc,
            ::coder::array<double, 1U> &work)
{
  int lastc;
  int lastv;
  if (tau != 0.0) {
    int b_i;
    int b_lastc;
    bool exitg1;
    lastv = m;
    b_i = iv0 + m;
    exitg1 = false;
    while ((!exitg1) && (lastv > 0)) {
      if (c_C[b_i - 2] == 0.0) {
        lastv--;
        b_i--;
      } else {
        exitg1 = true;
      }
    }
    b_lastc = h_n;
    exitg1 = false;
    while ((!exitg1) && (b_lastc > 0)) {
      int coltop;
      int exitg2;
      int ia;
      coltop = ic0 + ((b_lastc - 1) * ldc);
      ia = coltop;
      do {
        exitg2 = 0;
        if (ia <= ((coltop + lastv) - 1)) {
          if (c_C[ia - 1] != 0.0) {
            exitg2 = 1;
          } else {
            ia++;
          }
        } else {
          b_lastc--;
          exitg2 = 2;
        }
      } while (exitg2 == 0);
      if (exitg2 == 1) {
        exitg1 = true;
      }
    }
    lastc = b_lastc;
  } else {
    lastv = 0;
    lastc = 0;
  }
  if (lastv > 0) {
    blas::xgemv(lastv, lastc, c_C, ic0, ldc, c_C, iv0, work);
    blas::xgerc(lastv, lastc, -tau, iv0, work, c_C, ic0, ldc);
  }
}

} // namespace reflapack
} // namespace internal
} // namespace coder
} // namespace ITER

//
// File trailer for xzlarf.cpp
//
// [EOF]
//
