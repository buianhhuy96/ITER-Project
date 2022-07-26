//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rand.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "rand.h"
#include "ITER_API_data.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Arguments    : void
// Return Type  : double
//
namespace ITER {
namespace coder {
double b_rand()
{
  static unsigned int d_state[625];
  double r;
  unsigned int d_u[2];
  if (method == 4U) {
    unsigned int b;
    unsigned int b_a;
    int b_hi;
    unsigned int c_state;
    b_hi = static_cast<int>(static_cast<unsigned int>(state / 127773U));
    b_a = 16807U * (state - ((static_cast<unsigned int>(b_hi)) * 127773U));
    b = 2836U * (static_cast<unsigned int>(b_hi));
    if (b_a < b) {
      c_state = (~(b - b_a)) & 2147483647U;
    } else {
      c_state = b_a - b;
    }
    r = (static_cast<double>(c_state)) * 4.6566128752457969E-10;
    state = c_state;
  } else if (method == 5U) {
    unsigned int b_u1;
    unsigned int c_u;
    c_u = (69069U * b_state[0]) + 1234567U;
    b_u1 = b_state[1] ^ (b_state[1] << 13U);
    b_u1 ^= (b_u1 >> 17U);
    b_u1 ^= (b_u1 << 5U);
    b_state[0] = c_u;
    b_state[1] = b_u1;
    r = (static_cast<double>(static_cast<unsigned int>(c_u + b_u1))) *
        2.328306436538696E-10;
  } else {
    double d_r;
    if (!state_not_empty) {
      unsigned int c_r;
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int b_i = 0; b_i < 625; b_i++) {
        d_state[b_i] = 0U;
      }
      c_r = 5489U;
      d_state[0] = 5489U;
      for (int mti{0}; mti < 623; mti++) {
        c_r = (((c_r ^ (c_r >> 30U)) * 1812433253U) +
               (static_cast<unsigned int>(mti))) +
              1U;
        d_state[mti + 1] = c_r;
      }
      d_state[624] = 624U;
      state_not_empty = true;
    }
    // ========================= COPYRIGHT NOTICE ============================
    //  This is a uniform (0,1) pseudorandom number generator based on:
    //
    //  A C-program for MT19937, with initialization improved 2002/1/26.
    //  Coded by Takuji Nishimura and Makoto Matsumoto.
    //
    //  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
    //  All rights reserved.
    //
    //  Redistribution and use in source and binary forms, with or without
    //  modification, are permitted provided that the following conditions
    //  are met:
    //
    //    1. Redistributions of source code must retain the above copyright
    //       notice, this list of conditions and the following disclaimer.
    //
    //    2. Redistributions in binary form must reproduce the above copyright
    //       notice, this list of conditions and the following disclaimer
    //       in the documentation and/or other materials provided with the
    //       distribution.
    //
    //    3. The names of its contributors may not be used to endorse or
    //       promote products derived from this software without specific
    //       prior written permission.
    //
    //  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
    //  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
    //  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
    //  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT
    //  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    //  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
    //  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
    //  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
    //  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    //  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    //  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
    //
    // =============================   END   =================================
    do {
      for (int j{0}; j < 2; j++) {
        unsigned int b_mti;
        unsigned int y;
        b_mti = d_state[624] + 1U;
        if ((d_state[624] + 1U) >= 625U) {
          unsigned int c_y;
          for (int b_kk{0}; b_kk < 227; b_kk++) {
            unsigned int b_y;
            b_y = (d_state[b_kk] & 2147483648U) |
                  (d_state[b_kk + 1] & 2147483647U);
            if ((b_y & 1U) == 0U) {
              b_y >>= 1U;
            } else {
              b_y = (b_y >> 1U) ^ 2567483615U;
            }
            d_state[b_kk] = d_state[b_kk + 397] ^ b_y;
          }
          for (int c_kk{0}; c_kk < 396; c_kk++) {
            unsigned int d_y;
            d_y = (d_state[c_kk + 227] & 2147483648U) |
                  (d_state[c_kk + 228] & 2147483647U);
            if ((d_y & 1U) == 0U) {
              d_y >>= 1U;
            } else {
              d_y = (d_y >> 1U) ^ 2567483615U;
            }
            d_state[c_kk + 227] = d_state[c_kk] ^ d_y;
          }
          c_y = (d_state[623] & 2147483648U) | (d_state[0] & 2147483647U);
          if ((c_y & 1U) == 0U) {
            c_y >>= 1U;
          } else {
            c_y = (c_y >> 1U) ^ 2567483615U;
          }
          d_state[623] = d_state[396] ^ c_y;
          b_mti = 1U;
        }
        y = d_state[(static_cast<int>(b_mti)) - 1];
        d_state[624] = b_mti;
        y ^= (y >> 11U);
        y ^= (y << 7U) & 2636928640U;
        y ^= (y << 15U) & 4022730752U;
        d_u[j] = y ^ (y >> 18U);
      }
      d_r = 1.1102230246251565E-16 *
            (((static_cast<double>(static_cast<unsigned int>(d_u[0] >> 5U))) *
              6.7108864E+7) +
             (static_cast<double>(static_cast<unsigned int>(d_u[1] >> 6U))));
    } while (d_r == 0.0);
    r = d_r;
  }
  return r;
}

} // namespace coder
} // namespace ITER

//
// File trailer for rand.cpp
//
// [EOF]
//
