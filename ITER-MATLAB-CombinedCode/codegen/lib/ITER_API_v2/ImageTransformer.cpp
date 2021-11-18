//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ImageTransformer.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "ImageTransformer.h"
#include "interp2.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<unsigned char, 3U> &w_I
//                const ::coder::array<unsigned char, 3U> &fillValues
//                ::coder::array<unsigned char, 3U> &j_J
//                double newOrigin[2]
// Return Type  : void
//
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
void b_ImageTransformer::transformImage(
    const ::coder::array<unsigned char, 3U> &w_I,
    const ::coder::array<unsigned char, 3U> &fillValues,
    ::coder::array<unsigned char, 3U> &j_J, double newOrigin[2]) const
{
  array<double, 2U> y;
  array<float, 3U> outputImage;
  array<float, 2U> XIntrinsic;
  array<float, 2U> YIntrinsic;
  array<float, 2U> ab_I;
  array<float, 2U> r;
  array<unsigned char, 3U> fill;
  int e_P;
  int h_loop_ub;
  int i11;
  int j_loop_ub;
  int k_loop_ub;
  int m_loop_ub;
  int o_loop_ub;
  if (fillValues.size(2) == 1) {
    fill.set_size(w_I.size(2), 1, 1);
    if (w_I.size(2) != 0) {
      int i1;
      i1 = w_I.size(2) - 1;
      for (int b_t{0}; b_t <= i1; b_t++) {
        fill[b_t] = fillValues[0];
      }
    }
  } else {
    int loop_ub;
    fill.set_size(1, 1, fillValues.size(2));
    loop_ub = fillValues.size(2);
    for (int b_i{0}; b_i < loop_ub; b_i++) {
      fill[fill.size(0) * b_i] = fillValues[b_i];
    }
  }
  if (w_I.size(2) == 1) {
    unsigned int b_unnamed_idx_0;
    unsigned int b_unnamed_idx_1;
    int c_loop_ub;
    e_P = 0;
    b_unnamed_idx_0 = static_cast<unsigned int>(XmapSingle.size(0));
    b_unnamed_idx_1 = static_cast<unsigned int>(XmapSingle.size(1));
    outputImage.set_size(static_cast<int>(b_unnamed_idx_0),
                         static_cast<int>(b_unnamed_idx_1), 1);
    c_loop_ub = static_cast<int>(b_unnamed_idx_1);
    for (int i3{0}; i3 < c_loop_ub; i3++) {
      int e_loop_ub;
      e_loop_ub = static_cast<int>(b_unnamed_idx_0);
      for (int i5{0}; i5 < e_loop_ub; i5++) {
        outputImage[i5 + (outputImage.size(0) * i3)] = 0.0F;
      }
    }
  } else {
    int b_loop_ub;
    unsigned int unnamed_idx_0;
    unsigned int unnamed_idx_1;
    e_P = w_I.size(2) - 1;
    unnamed_idx_0 = static_cast<unsigned int>(XmapSingle.size(0));
    unnamed_idx_1 = static_cast<unsigned int>(XmapSingle.size(1));
    outputImage.set_size(static_cast<int>(unnamed_idx_0),
                         static_cast<int>(unnamed_idx_1), w_I.size(2));
    b_loop_ub = w_I.size(2);
    for (int i2{0}; i2 < b_loop_ub; i2++) {
      int d_loop_ub;
      d_loop_ub = static_cast<int>(unnamed_idx_1);
      for (int i4{0}; i4 < d_loop_ub; i4++) {
        int g_loop_ub;
        g_loop_ub = static_cast<int>(unnamed_idx_0);
        for (int i7{0}; i7 < g_loop_ub; i7++) {
          outputImage[(i7 + (outputImage.size(0) * i4)) +
                      ((outputImage.size(0) * outputImage.size(1)) * i2)] =
              0.0F;
        }
      }
    }
  }
  if (w_I.size(1) < 1) {
    y.set_size(1, 0);
  } else {
    int f_loop_ub;
    y.set_size(1, w_I.size(1));
    f_loop_ub = w_I.size(1) - 1;
    for (int i6{0}; i6 <= f_loop_ub; i6++) {
      y[i6] = (static_cast<double>(i6)) + 1.0;
    }
  }
  XIntrinsic.set_size(1, y.size(1));
  h_loop_ub = y.size(1);
  for (int i8{0}; i8 < h_loop_ub; i8++) {
    XIntrinsic[i8] = static_cast<float>(y[i8]);
  }
  if (w_I.size(0) < 1) {
    y.set_size(1, 0);
  } else {
    int i_loop_ub;
    y.set_size(1, w_I.size(0));
    i_loop_ub = w_I.size(0) - 1;
    for (int i9{0}; i9 <= i_loop_ub; i9++) {
      y[i9] = (static_cast<double>(i9)) + 1.0;
    }
  }
  YIntrinsic.set_size(1, y.size(1));
  j_loop_ub = y.size(1);
  for (int i10{0}; i10 < j_loop_ub; i10++) {
    YIntrinsic[i10] = static_cast<float>(y[i10]);
  }
  if (0 <= e_P) {
    k_loop_ub = w_I.size(0);
    i11 = w_I.size(1);
    m_loop_ub = w_I.size(1);
  }
  for (int plane{0}; plane <= e_P; plane++) {
    int q_loop_ub;
    ab_I.set_size(k_loop_ub, i11);
    for (int i12{0}; i12 < m_loop_ub; i12++) {
      for (int i14{0}; i14 < k_loop_ub; i14++) {
        ab_I[i14 + (ab_I.size(0) * i12)] =
            static_cast<float>(w_I[(i14 + (w_I.size(0) * i12)) +
                                   ((w_I.size(0) * w_I.size(1)) * plane)]);
      }
    }
    images::internal::coder::interp2_local(ab_I, XmapSingle, YmapSingle,
                                           static_cast<float>(fill[plane]),
                                           XIntrinsic, YIntrinsic, r);
    q_loop_ub = r.size(1);
    for (int i16{0}; i16 < q_loop_ub; i16++) {
      int s_loop_ub;
      s_loop_ub = r.size(0);
      for (int i18{0}; i18 < s_loop_ub; i18++) {
        outputImage[(i18 + (outputImage.size(0) * i16)) +
                    ((outputImage.size(0) * outputImage.size(1)) * plane)] =
            r[i18 + (r.size(0) * i16)];
      }
    }
  }
  j_J.set_size(outputImage.size(0), outputImage.size(1), outputImage.size(2));
  o_loop_ub = outputImage.size(2);
  for (int i13{0}; i13 < o_loop_ub; i13++) {
    int p_loop_ub;
    p_loop_ub = outputImage.size(1);
    for (int i15{0}; i15 < p_loop_ub; i15++) {
      int r_loop_ub;
      r_loop_ub = outputImage.size(0);
      for (int i17{0}; i17 < r_loop_ub; i17++) {
        float f;
        unsigned char u;
        f = std::round(
            outputImage[(i17 + (outputImage.size(0) * i15)) +
                        ((outputImage.size(0) * outputImage.size(1)) * i13)]);
        if (f < 256.0F) {
          if (f >= 0.0F) {
            u = static_cast<unsigned char>(f);
          } else {
            u = 0U;
          }
        } else if (f >= 256.0F) {
          u = MAX_uint8_T;
        } else {
          u = 0U;
        }
        j_J[(i17 + (j_J.size(0) * i15)) + ((j_J.size(0) * j_J.size(1)) * i13)] =
            u;
      }
    }
  }
  newOrigin[0] = XBounds[0] - 1.0;
  newOrigin[1] = YBounds[0] - 1.0;
}

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

//
// File trailer for ImageTransformer.cpp
//
// [EOF]
//
