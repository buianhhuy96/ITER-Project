//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: NeighborhoodProcessor.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "NeighborhoodProcessor.h"
#include "ITER_API_v2_internal_types.h"
#include "ITER_API_v2_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cfloat>
#include <cmath>

// Type Definitions
struct b_struct_T {
  coder::array<bool, 2U> bw;
  float pixel;
  int ind;
  int nhInds[9];
  int imnhInds[9];
};

// Function Declarations
static double rt_remd_snf(double u0, double c_u1);

// Function Definitions
//
// Arguments    : double u0
//                double c_u1
// Return Type  : double
//
static double rt_remd_snf(double u0, double c_u1)
{
  double y;
  if (((std::isnan(u0)) || (std::isnan(c_u1))) || (std::isinf(u0))) {
    y = rtNaN;
  } else if (std::isinf(c_u1)) {
    y = u0;
  } else if ((c_u1 != 0.0) && (c_u1 != std::trunc(c_u1))) {
    double q;
    q = std::abs(u0 / c_u1);
    if (!(std::abs(q - std::floor(q + 0.5)) > (DBL_EPSILON * q))) {
      y = 0.0 * u0;
    } else {
      y = std::fmod(u0, c_u1);
    }
  } else {
    y = std::fmod(u0, c_u1);
  }
  return y;
}

//
// Arguments    : const int imSize[2]
//                const bool nhConn[3][3]
//                int loffsets[9]
//                int linds[9]
//                int soffsets[2][9]
//                int b_interiorStart[2]
//                int b_interiorEnd[2]
// Return Type  : void
//
namespace coder {
namespace images {
namespace internal {
namespace coder {
void NeighborhoodProcessor::computeParameters(
    const int imSize[2], const bool nhConn[3][3], int loffsets[9], int linds[9],
    int soffsets[2][9], int b_interiorStart[2], int b_interiorEnd[2])
{
  int pixelsPerImPage1_idx_1;
  int y;
  pixelsPerImPage1_idx_1 = imSize[0];
  b_interiorStart[0] = 2;
  b_interiorEnd[0] = imSize[0] - 1;
  b_interiorStart[1] = 2;
  b_interiorEnd[1] = imSize[1] - 1;
  y = static_cast<int>((&nhConn[0][0])[0]);
  for (int k{0}; k < 8; k++) {
    y += static_cast<int>((&nhConn[0][0])[k + 1]);
  }
  if (y != 0) {
    double b;
    int indx;
    indx = 0;
    for (int pind{0}; pind < 9; pind++) {
      if ((&nhConn[0][0])[pind]) {
        int r_tmp;
        int weights_tmp_idx_1_tmp;
        r_tmp = (static_cast<int>(rt_remd_snf(
                    ((static_cast<double>(pind)) + 1.0) - 1.0, 3.0))) +
                1;
        weights_tmp_idx_1_tmp = static_cast<int>(static_cast<double>(
            ((static_cast<double>(static_cast<int>(pind - r_tmp))) + 1.0) /
            3.0));
        soffsets[0][indx] = r_tmp;
        soffsets[1][indx] = weights_tmp_idx_1_tmp + 1;
        linds[indx] = r_tmp + ((static_cast<int>(static_cast<signed char>(
                                   weights_tmp_idx_1_tmp))) *
                               3);
        loffsets[indx] = r_tmp + ((static_cast<int>(static_cast<signed char>(
                                      weights_tmp_idx_1_tmp))) *
                                  pixelsPerImPage1_idx_1);
        indx++;
      }
    }
    b = (static_cast<double>(imSize[0])) + 2.0;
    for (int b_i{0}; b_i < 9; b_i++) {
      loffsets[b_i] -= static_cast<int>(b);
    }
    for (int b_k{0}; b_k < 2; b_k++) {
      for (int c_k{0}; c_k < 9; c_k++) {
        soffsets[b_k][c_k] -= 2;
      }
    }
  }
}

//
// Arguments    : const ::coder::array<float, 2U> &b_in
//                ::coder::array<bool, 2U> &out
//                const struct_T *fparams
// Return Type  : void
//
void NeighborhoodProcessor::process2D(const ::coder::array<float, 2U> &b_in,
                                      ::coder::array<bool, 2U> &out,
                                      const struct_T *fparams) const
{
  array<float, 2U> b_imnh;
  array<float, 2U> imnh;
  array<float, 1U> c_in;
  array<int, 1U> c_imnhInds;
  array<int, 1U> d_imnhInds;
  array<int, 1U> e_imnhInds;
  array<int, 1U> f_imnhInds;
  array<signed char, 1U> e_r;
  array<signed char, 1U> r1;
  array<signed char, 1U> r2;
  array<signed char, 1U> r3;
  array<bool, 1U> b_out_;
  b_struct_T fparamsAugmented;
  int imnhSubs[2][9];
  int b_imnhInds_[9];
  int imnhInds[9];
  int firstIndRange[2];
  int pixelSub[2];
  int b_firstInd;
  int b_i;
  int e_i;
  int i1;
  int i2;
  int i3;
  int i4;
  int imageSize1;
  int lb_loop;
  int loop_ub;
  int pind;
  int pixelInd;
  int ub_loop;
  bool isInside[9];
  bool exitg1;
  firstIndRange[0] = InteriorStart[0];
  firstIndRange[1] = InteriorEnd[0];
  imageSize1 = ImageSize[0];
  lb_loop = InteriorStart[1];
  ub_loop = InteriorEnd[1];
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    b_out_, imnh, fparamsAugmented, imnhInds, pind, b_i, i1, b_firstInd,       \
    loop_ub, e_i, i4, pixelInd, exitg1, i3, i2)

  for (int secondInd = lb_loop; secondInd <= ub_loop; secondInd++) {
    b_out_.set_size(out.size(0));
    b_i = firstIndRange[0];
    i1 = firstIndRange[1];
    for (b_firstInd = b_i; b_firstInd <= i1; b_firstInd++) {
      //  Process pixels with full neighborhood
      pind = ((secondInd - 1) * imageSize1) + b_firstInd;
      for (e_i = 0; e_i < 9; e_i++) {
        imnhInds[e_i] = ImageNeighborLinearOffsets[e_i] + pind;
      }
      if (b_in.size(0) == 1) {
        imnh.set_size(1, 9);
        for (i4 = 0; i4 < 9; i4++) {
          imnh[imnh.size(0) * i4] = b_in[imnhInds[i4] - 1];
        }
      } else {
        imnh.set_size(9, 1);
        for (i3 = 0; i3 < 9; i3++) {
          imnh[i3] = b_in[imnhInds[i3] - 1];
        }
      }
      fparamsAugmented.pixel = b_in[pind - 1];
      b_out_[b_firstInd - 1] = fparams->bw[pind - 1];
      if (fparams->bw[pind - 1]) {
        //  Pixel has not already been set as non-max
        pixelInd = 0;
        exitg1 = false;
        while ((!exitg1) && (pixelInd <= ((imnh.size(0) * imnh.size(1)) - 1))) {
          if (imnh[pixelInd] > fparamsAugmented.pixel) {
            //  Set pixel to zero if any neighbor is greater
            b_out_[b_firstInd - 1] = false;
            exitg1 = true;
          } else if (imnh[pixelInd] == fparamsAugmented.pixel) {
            if (!fparams->bw[imnhInds[pixelInd] - 1]) {
              //  Set pixel to zero if any equal neighbor is already set to zero
              b_out_[b_firstInd - 1] = false;
              exitg1 = true;
            } else {
              pixelInd++;
            }
          } else {
            pixelInd++;
          }
        }
      }
    }
    loop_ub = b_out_.size(0);
    for (i2 = 0; i2 < loop_ub; i2++) {
      out[i2 + (out.size(0) * (secondInd - 1))] = b_out_[i2];
    }
  }
  if (ProcessBorder) {
    float padValue_tmp;
    int b_u0;
    int c_u1;
    int d_u1;
    int e_u1;
    int f_u1;
    int firstDimExtents_idx_0;
    int firstDimExtents_idx_1;
    int firstDimExtents_idx_1_tmp;
    int g_u1;
    int h_u1;
    int i5;
    int imnhInds_idx_0;
    int pixelSub_idx_0;
    int pixelSub_idx_1;
    int secondDimExtents_idx_0;
    int secondDimExtents_idx_1;
    int u0;
    secondDimExtents_idx_1 = InteriorStart[1] - 1;
    padValue_tmp = static_cast<float>(PadValue);
    u0 = ImageSize[0];
    c_u1 = ImageSize[0];
    if (u0 <= c_u1) {
      firstDimExtents_idx_1_tmp = u0;
    } else {
      firstDimExtents_idx_1_tmp = c_u1;
    }
    d_u1 = ImageSize[1];
    if (secondDimExtents_idx_1 > d_u1) {
      secondDimExtents_idx_1 = d_u1;
    }
    for (int b_secondInd{0}; b_secondInd < secondDimExtents_idx_1;
         b_secondInd++) {
      for (int firstInd{0}; firstInd < firstDimExtents_idx_1_tmp; firstInd++) {
        float fparamsAugmented_pixel;
        int b_pind;
        int b_x;
        int r;
        int z;
        //  Process pixels with partial neighborhood
        b_pind = (b_secondInd * ImageSize[0]) + firstInd;
        for (int c_i{0}; c_i < 9; c_i++) {
          b_imnhInds_[c_i] = (ImageNeighborLinearOffsets[c_i] + b_pind) + 1;
        }
        if (ImageSize[0] == 0) {
          r = 0;
        } else {
          r = b_pind - (ImageSize[0] * div_s32(b_pind, ImageSize[0]));
        }
        b_x = b_pind - r;
        if (ImageSize[0] == 0) {
          if (b_x == 0) {
            z = 0;
          } else if (b_x < 0) {
            z = MIN_int32_T;
          } else {
            z = MAX_int32_T;
          }
        } else if (ImageSize[0] == 1) {
          z = b_x;
        } else if (ImageSize[0] == -1) {
          z = -b_x;
        } else {
          int c_x;
          int y;
          if (b_x >= 0) {
            c_x = b_x;
          } else if (b_x == MIN_int32_T) {
            c_x = MIN_int32_T;
          } else {
            c_x = -b_x;
          }
          if (ImageSize[0] >= 0) {
            y = ImageSize[0];
          } else if (ImageSize[0] == MIN_int32_T) {
            y = MIN_int32_T;
          } else {
            y = -ImageSize[0];
          }
          z = div_s32(c_x, y);
          c_x -= z * y;
          if ((c_x > 0) && (c_x >= (asr_s32(y, 1U) + (y & 1)))) {
            z++;
          }
          if ((b_x < 0) != (ImageSize[0] < 0)) {
            z = -z;
          }
        }
        pixelSub[1] = z + 1;
        pixelSub[0] = r + 1;
        for (int k{0}; k < 2; k++) {
          for (int b_k{0}; b_k < 9; b_k++) {
            imnhSubs[k][b_k] = NeighborSubscriptOffsets[k][b_k] + pixelSub[k];
          }
        }
        for (int h_i{0}; h_i < 9; h_i++) {
          isInside[h_i] = true;
        }
        switch (static_cast<int>(Padding)) {
        case 1: {
          int partialTrueCount;
          int trueCount;
          trueCount = 0;
          for (int ind{0}; ind < 9; ind++) {
            int dimInd;
            dimInd = 0;
            exitg1 = false;
            while ((!exitg1) && (dimInd < 2)) {
              if ((imnhSubs[dimInd][ind] < 1) ||
                  (imnhSubs[dimInd][ind] > ImageSize[dimInd])) {
                isInside[ind] = false;
                exitg1 = true;
              } else {
                dimInd++;
              }
            }
            if (isInside[ind]) {
              trueCount++;
            }
          }
          c_imnhInds.set_size(trueCount);
          partialTrueCount = 0;
          for (int m_i{0}; m_i < 9; m_i++) {
            if (isInside[m_i]) {
              c_imnhInds[partialTrueCount] = b_imnhInds_[m_i];
              partialTrueCount++;
            }
          }
        } break;
        case 2: {
          c_imnhInds.set_size(9);
          for (int b_ind{0}; b_ind < 9; b_ind++) {
            int b_dimInd;
            c_imnhInds[b_ind] = b_imnhInds_[b_ind];
            b_dimInd = 0;
            exitg1 = false;
            while ((!exitg1) && (b_dimInd < 2)) {
              if ((imnhSubs[b_dimInd][b_ind] < 1) ||
                  (imnhSubs[b_dimInd][b_ind] > ImageSize[b_dimInd])) {
                isInside[b_ind] = false;
                c_imnhInds[b_ind] = 1;
                exitg1 = true;
              } else {
                b_dimInd++;
              }
            }
          }
        } break;
        case 3: {
          c_imnhInds.set_size(9);
          for (int i6{0}; i6 < 9; i6++) {
            c_imnhInds[i6] = b_imnhInds_[i6];
          }
          for (int c_ind{0}; c_ind < 9; c_ind++) {
            int i10;
            int i12;
            int i17;
            i10 = imnhSubs[0][c_ind];
            i12 = i10;
            pixelSub_idx_0 = i10;
            if (i10 < 1) {
              isInside[c_ind] = false;
              i12 = 1;
              pixelSub_idx_0 = 1;
            }
            if (i12 > ImageSize[0]) {
              isInside[c_ind] = false;
              pixelSub_idx_0 = ImageSize[0];
            }
            i17 = imnhSubs[1][c_ind];
            i12 = i17;
            pixelSub_idx_1 = i17;
            if (i17 < 1) {
              isInside[c_ind] = false;
              i12 = 1;
              pixelSub_idx_1 = 1;
            }
            if (i12 > ImageSize[1]) {
              isInside[c_ind] = false;
              pixelSub_idx_1 = ImageSize[1];
            }
            if (!isInside[c_ind]) {
              c_imnhInds[c_ind] =
                  pixelSub_idx_0 + ((pixelSub_idx_1 - 1) * ImageSize[0]);
            }
          }
        } break;
        case 4: {
          c_imnhInds.set_size(9);
          for (int i7{0}; i7 < 9; i7++) {
            c_imnhInds[i7] = b_imnhInds_[i7];
          }
          for (int d_ind{0}; d_ind < 9; d_ind++) {
            int i11;
            int i13;
            int i18;
            i11 = imnhSubs[0][d_ind];
            i13 = i11;
            pixelSub_idx_0 = i11;
            if (i11 < 1) {
              isInside[d_ind] = false;
              i13 = i11 + (ImageSize[0] * 2);
              pixelSub_idx_0 = i13;
            }
            if (i13 > ImageSize[0]) {
              isInside[d_ind] = false;
              i13 = ((ImageSize[0] * 2) - i13) + 1;
              pixelSub_idx_0 = i13;
            }
            i18 = imnhSubs[1][d_ind];
            i13 = i18;
            pixelSub_idx_1 = i18;
            if (i18 < 1) {
              isInside[d_ind] = false;
              i13 = i18 + (ImageSize[1] * 2);
              pixelSub_idx_1 = i13;
            }
            if (i13 > ImageSize[1]) {
              isInside[d_ind] = false;
              i13 = ((ImageSize[1] * 2) - i13) + 1;
              pixelSub_idx_1 = i13;
            }
            if (!isInside[d_ind]) {
              c_imnhInds[d_ind] =
                  pixelSub_idx_0 + ((pixelSub_idx_1 - 1) * ImageSize[0]);
            }
          }
        } break;
        default:
          /* no actions */
          break;
        }
        if (b_in.size(0) == 1) {
          int c_loop_ub;
          c_loop_ub = c_imnhInds.size(0);
          b_imnh.set_size(1, c_imnhInds.size(0));
          for (int i9{0}; i9 < c_loop_ub; i9++) {
            b_imnh[b_imnh.size(0) * i9] = b_in[c_imnhInds[i9] - 1];
          }
        } else {
          int b_loop_ub;
          b_loop_ub = c_imnhInds.size(0);
          c_in.set_size(c_imnhInds.size(0));
          for (int i8{0}; i8 < b_loop_ub; i8++) {
            c_in[i8] = b_in[c_imnhInds[i8] - 1];
          }
          imnhInds_idx_0 = c_imnhInds.size(0);
          b_imnh.set_size(c_imnhInds.size(0), 1);
          for (int i14{0}; i14 < imnhInds_idx_0; i14++) {
            b_imnh[i14] = c_in[i14];
          }
        }
        if (Padding == 2.0) {
          int b_partialTrueCount;
          int b_trueCount;
          int f_loop_ub;
          b_trueCount = 0;
          for (int p_i{0}; p_i < 9; p_i++) {
            if (!isInside[p_i]) {
              b_trueCount++;
            }
          }
          e_r.set_size(b_trueCount);
          b_partialTrueCount = 0;
          for (int s_i{0}; s_i < 9; s_i++) {
            if (!isInside[s_i]) {
              e_r[b_partialTrueCount] = static_cast<signed char>(s_i + 1);
              b_partialTrueCount++;
            }
          }
          f_loop_ub = e_r.size(0);
          for (int i25{0}; i25 < f_loop_ub; i25++) {
            b_imnh[(static_cast<int>(e_r[i25])) - 1] = padValue_tmp;
          }
        }
        fparamsAugmented_pixel = b_in[b_pind];
        out[b_pind] = fparams->bw[b_pind];
        if (fparams->bw[b_pind]) {
          int b_pixelInd;
          //  Pixel has not already been set as non-max
          b_pixelInd = 0;
          exitg1 = false;
          while ((!exitg1) &&
                 (b_pixelInd <= ((b_imnh.size(0) * b_imnh.size(1)) - 1))) {
            if (b_imnh[b_pixelInd] > fparamsAugmented_pixel) {
              //  Set pixel to zero if any neighbor is greater
              out[b_pind] = false;
              exitg1 = true;
            } else if (b_imnh[b_pixelInd] == fparamsAugmented_pixel) {
              if (!fparams->bw[c_imnhInds[b_pixelInd] - 1]) {
                //  Set pixel to zero if any equal neighbor is already set to
                //  zero
                out[b_pind] = false;
                exitg1 = true;
              } else {
                b_pixelInd++;
              }
            } else {
              b_pixelInd++;
            }
          }
        }
      }
    }
    secondDimExtents_idx_0 = InteriorEnd[1] + 1;
    secondDimExtents_idx_1 = ImageSize[1];
    if (secondDimExtents_idx_0 < 1) {
      secondDimExtents_idx_0 = 1;
    }
    e_u1 = ImageSize[1];
    if (secondDimExtents_idx_1 > e_u1) {
      secondDimExtents_idx_1 = e_u1;
    }
    for (int c_secondInd{secondDimExtents_idx_0};
         c_secondInd <= secondDimExtents_idx_1; c_secondInd++) {
      for (int c_firstInd{0}; c_firstInd < firstDimExtents_idx_1_tmp;
           c_firstInd++) {
        float b_fparamsAugmented_pixel;
        int b_r;
        int b_z;
        int c_pind;
        int d_x;
        //  Process pixels with partial neighborhood
        c_pind = ((c_secondInd - 1) * ImageSize[0]) + c_firstInd;
        for (int g_i{0}; g_i < 9; g_i++) {
          b_imnhInds_[g_i] = (ImageNeighborLinearOffsets[g_i] + c_pind) + 1;
        }
        if (ImageSize[0] == 0) {
          b_r = 0;
        } else {
          b_r = c_pind - (ImageSize[0] * div_s32(c_pind, ImageSize[0]));
        }
        d_x = c_pind - b_r;
        if (ImageSize[0] == 0) {
          if (d_x == 0) {
            b_z = 0;
          } else if (d_x < 0) {
            b_z = MIN_int32_T;
          } else {
            b_z = MAX_int32_T;
          }
        } else if (ImageSize[0] == 1) {
          b_z = d_x;
        } else if (ImageSize[0] == -1) {
          b_z = -d_x;
        } else {
          int b_y;
          int e_x;
          if (d_x >= 0) {
            e_x = d_x;
          } else if (d_x == MIN_int32_T) {
            e_x = MIN_int32_T;
          } else {
            e_x = -d_x;
          }
          if (ImageSize[0] >= 0) {
            b_y = ImageSize[0];
          } else if (ImageSize[0] == MIN_int32_T) {
            b_y = MIN_int32_T;
          } else {
            b_y = -ImageSize[0];
          }
          b_z = div_s32(e_x, b_y);
          e_x -= b_z * b_y;
          if ((e_x > 0) && (e_x >= (asr_s32(b_y, 1U) + (b_y & 1)))) {
            b_z++;
          }
          if ((d_x < 0) != (ImageSize[0] < 0)) {
            b_z = -b_z;
          }
        }
        pixelSub[1] = b_z + 1;
        pixelSub[0] = b_r + 1;
        for (int c_k{0}; c_k < 2; c_k++) {
          for (int d_k{0}; d_k < 9; d_k++) {
            imnhSubs[c_k][d_k] =
                NeighborSubscriptOffsets[c_k][d_k] + pixelSub[c_k];
          }
        }
        for (int o_i{0}; o_i < 9; o_i++) {
          isInside[o_i] = true;
        }
        switch (static_cast<int>(Padding)) {
        case 1: {
          int c_partialTrueCount;
          int c_trueCount;
          c_trueCount = 0;
          for (int e_ind{0}; e_ind < 9; e_ind++) {
            int c_dimInd;
            c_dimInd = 0;
            exitg1 = false;
            while ((!exitg1) && (c_dimInd < 2)) {
              if ((imnhSubs[c_dimInd][e_ind] < 1) ||
                  (imnhSubs[c_dimInd][e_ind] > ImageSize[c_dimInd])) {
                isInside[e_ind] = false;
                exitg1 = true;
              } else {
                c_dimInd++;
              }
            }
            if (isInside[e_ind]) {
              c_trueCount++;
            }
          }
          d_imnhInds.set_size(c_trueCount);
          c_partialTrueCount = 0;
          for (int t_i{0}; t_i < 9; t_i++) {
            if (isInside[t_i]) {
              d_imnhInds[c_partialTrueCount] = b_imnhInds_[t_i];
              c_partialTrueCount++;
            }
          }
        } break;
        case 2: {
          d_imnhInds.set_size(9);
          for (int f_ind{0}; f_ind < 9; f_ind++) {
            int d_dimInd;
            d_imnhInds[f_ind] = b_imnhInds_[f_ind];
            d_dimInd = 0;
            exitg1 = false;
            while ((!exitg1) && (d_dimInd < 2)) {
              if ((imnhSubs[d_dimInd][f_ind] < 1) ||
                  (imnhSubs[d_dimInd][f_ind] > ImageSize[d_dimInd])) {
                isInside[f_ind] = false;
                d_imnhInds[f_ind] = 1;
                exitg1 = true;
              } else {
                d_dimInd++;
              }
            }
          }
        } break;
        case 3: {
          d_imnhInds.set_size(9);
          for (int i15{0}; i15 < 9; i15++) {
            d_imnhInds[i15] = b_imnhInds_[i15];
          }
          for (int g_ind{0}; g_ind < 9; g_ind++) {
            int i21;
            int i23;
            int i29;
            i21 = imnhSubs[0][g_ind];
            i23 = i21;
            pixelSub_idx_0 = i21;
            if (i21 < 1) {
              isInside[g_ind] = false;
              i23 = 1;
              pixelSub_idx_0 = 1;
            }
            if (i23 > ImageSize[0]) {
              isInside[g_ind] = false;
              pixelSub_idx_0 = ImageSize[0];
            }
            i29 = imnhSubs[1][g_ind];
            i23 = i29;
            pixelSub_idx_1 = i29;
            if (i29 < 1) {
              isInside[g_ind] = false;
              i23 = 1;
              pixelSub_idx_1 = 1;
            }
            if (i23 > ImageSize[1]) {
              isInside[g_ind] = false;
              pixelSub_idx_1 = ImageSize[1];
            }
            if (!isInside[g_ind]) {
              d_imnhInds[g_ind] =
                  pixelSub_idx_0 + ((pixelSub_idx_1 - 1) * ImageSize[0]);
            }
          }
        } break;
        case 4: {
          d_imnhInds.set_size(9);
          for (int i16{0}; i16 < 9; i16++) {
            d_imnhInds[i16] = b_imnhInds_[i16];
          }
          for (int h_ind{0}; h_ind < 9; h_ind++) {
            int i22;
            int i24;
            int i30;
            i22 = imnhSubs[0][h_ind];
            i24 = i22;
            pixelSub_idx_0 = i22;
            if (i22 < 1) {
              isInside[h_ind] = false;
              i24 = i22 + (ImageSize[0] * 2);
              pixelSub_idx_0 = i24;
            }
            if (i24 > ImageSize[0]) {
              isInside[h_ind] = false;
              i24 = ((ImageSize[0] * 2) - i24) + 1;
              pixelSub_idx_0 = i24;
            }
            i30 = imnhSubs[1][h_ind];
            i24 = i30;
            pixelSub_idx_1 = i30;
            if (i30 < 1) {
              isInside[h_ind] = false;
              i24 = i30 + (ImageSize[1] * 2);
              pixelSub_idx_1 = i24;
            }
            if (i24 > ImageSize[1]) {
              isInside[h_ind] = false;
              i24 = ((ImageSize[1] * 2) - i24) + 1;
              pixelSub_idx_1 = i24;
            }
            if (!isInside[h_ind]) {
              d_imnhInds[h_ind] =
                  pixelSub_idx_0 + ((pixelSub_idx_1 - 1) * ImageSize[0]);
            }
          }
        } break;
        default:
          /* no actions */
          break;
        }
        if (b_in.size(0) == 1) {
          int e_loop_ub;
          e_loop_ub = d_imnhInds.size(0);
          b_imnh.set_size(1, d_imnhInds.size(0));
          for (int i20{0}; i20 < e_loop_ub; i20++) {
            b_imnh[b_imnh.size(0) * i20] = b_in[d_imnhInds[i20] - 1];
          }
        } else {
          int d_loop_ub;
          d_loop_ub = d_imnhInds.size(0);
          c_in.set_size(d_imnhInds.size(0));
          for (int i19{0}; i19 < d_loop_ub; i19++) {
            c_in[i19] = b_in[d_imnhInds[i19] - 1];
          }
          imnhInds_idx_0 = d_imnhInds.size(0);
          b_imnh.set_size(d_imnhInds.size(0), 1);
          for (int i26{0}; i26 < imnhInds_idx_0; i26++) {
            b_imnh[i26] = c_in[i26];
          }
        }
        if (Padding == 2.0) {
          int d_partialTrueCount;
          int d_trueCount;
          int i_loop_ub;
          d_trueCount = 0;
          for (int v_i{0}; v_i < 9; v_i++) {
            if (!isInside[v_i]) {
              d_trueCount++;
            }
          }
          r1.set_size(d_trueCount);
          d_partialTrueCount = 0;
          for (int eb_i{0}; eb_i < 9; eb_i++) {
            if (!isInside[eb_i]) {
              r1[d_partialTrueCount] = static_cast<signed char>(eb_i + 1);
              d_partialTrueCount++;
            }
          }
          i_loop_ub = r1.size(0);
          for (int i35{0}; i35 < i_loop_ub; i35++) {
            b_imnh[(static_cast<int>(r1[i35])) - 1] = padValue_tmp;
          }
        }
        b_fparamsAugmented_pixel = b_in[c_pind];
        out[c_pind] = fparams->bw[c_pind];
        if (fparams->bw[c_pind]) {
          int c_pixelInd;
          //  Pixel has not already been set as non-max
          c_pixelInd = 0;
          exitg1 = false;
          while ((!exitg1) &&
                 (c_pixelInd <= ((b_imnh.size(0) * b_imnh.size(1)) - 1))) {
            if (b_imnh[c_pixelInd] > b_fparamsAugmented_pixel) {
              //  Set pixel to zero if any neighbor is greater
              out[c_pind] = false;
              exitg1 = true;
            } else if (b_imnh[c_pixelInd] == b_fparamsAugmented_pixel) {
              if (!fparams->bw[d_imnhInds[c_pixelInd] - 1]) {
                //  Set pixel to zero if any equal neighbor is already set to
                //  zero
                out[c_pind] = false;
                exitg1 = true;
              } else {
                c_pixelInd++;
              }
            } else {
              c_pixelInd++;
            }
          }
        }
      }
    }
    firstDimExtents_idx_1 = InteriorStart[0] - 1;
    f_u1 = ImageSize[0];
    if (firstDimExtents_idx_1 > f_u1) {
      firstDimExtents_idx_1 = f_u1;
    }
    b_u0 = ImageSize[1];
    g_u1 = ImageSize[1];
    if (b_u0 <= g_u1) {
      i5 = b_u0;
    } else {
      i5 = g_u1;
    }
    for (int d_secondInd{1}; d_secondInd <= i5; d_secondInd++) {
      for (int d_firstInd{0}; d_firstInd < firstDimExtents_idx_1;
           d_firstInd++) {
        float c_fparamsAugmented_pixel;
        int c_r;
        int c_z;
        int d_pind;
        int k_x;
        //  Process pixels with partial neighborhood
        d_pind = ((d_secondInd - 1) * ImageSize[0]) + d_firstInd;
        for (int k_i{0}; k_i < 9; k_i++) {
          b_imnhInds_[k_i] = (ImageNeighborLinearOffsets[k_i] + d_pind) + 1;
        }
        if (ImageSize[0] == 0) {
          c_r = 0;
        } else {
          c_r = d_pind - (ImageSize[0] * div_s32(d_pind, ImageSize[0]));
        }
        k_x = d_pind - c_r;
        if (ImageSize[0] == 0) {
          if (k_x == 0) {
            c_z = 0;
          } else if (k_x < 0) {
            c_z = MIN_int32_T;
          } else {
            c_z = MAX_int32_T;
          }
        } else if (ImageSize[0] == 1) {
          c_z = k_x;
        } else if (ImageSize[0] == -1) {
          c_z = -k_x;
        } else {
          int d_y;
          int m_x;
          if (k_x >= 0) {
            m_x = k_x;
          } else if (k_x == MIN_int32_T) {
            m_x = MIN_int32_T;
          } else {
            m_x = -k_x;
          }
          if (ImageSize[0] >= 0) {
            d_y = ImageSize[0];
          } else if (ImageSize[0] == MIN_int32_T) {
            d_y = MIN_int32_T;
          } else {
            d_y = -ImageSize[0];
          }
          c_z = div_s32(m_x, d_y);
          m_x -= c_z * d_y;
          if ((m_x > 0) && (m_x >= (asr_s32(d_y, 1U) + (d_y & 1)))) {
            c_z++;
          }
          if ((k_x < 0) != (ImageSize[0] < 0)) {
            c_z = -c_z;
          }
        }
        pixelSub[1] = c_z + 1;
        pixelSub[0] = c_r + 1;
        for (int e_k{0}; e_k < 2; e_k++) {
          for (int f_k{0}; f_k < 9; f_k++) {
            imnhSubs[e_k][f_k] =
                NeighborSubscriptOffsets[e_k][f_k] + pixelSub[e_k];
          }
        }
        for (int u_i{0}; u_i < 9; u_i++) {
          isInside[u_i] = true;
        }
        switch (static_cast<int>(Padding)) {
        case 1: {
          int e_partialTrueCount;
          int e_trueCount;
          e_trueCount = 0;
          for (int i_ind{0}; i_ind < 9; i_ind++) {
            int e_dimInd;
            e_dimInd = 0;
            exitg1 = false;
            while ((!exitg1) && (e_dimInd < 2)) {
              if ((imnhSubs[e_dimInd][i_ind] < 1) ||
                  (imnhSubs[e_dimInd][i_ind] > ImageSize[e_dimInd])) {
                isInside[i_ind] = false;
                exitg1 = true;
              } else {
                e_dimInd++;
              }
            }
            if (isInside[i_ind]) {
              e_trueCount++;
            }
          }
          e_imnhInds.set_size(e_trueCount);
          e_partialTrueCount = 0;
          for (int fb_i{0}; fb_i < 9; fb_i++) {
            if (isInside[fb_i]) {
              e_imnhInds[e_partialTrueCount] = b_imnhInds_[fb_i];
              e_partialTrueCount++;
            }
          }
        } break;
        case 2: {
          e_imnhInds.set_size(9);
          for (int j_ind{0}; j_ind < 9; j_ind++) {
            int f_dimInd;
            e_imnhInds[j_ind] = b_imnhInds_[j_ind];
            f_dimInd = 0;
            exitg1 = false;
            while ((!exitg1) && (f_dimInd < 2)) {
              if ((imnhSubs[f_dimInd][j_ind] < 1) ||
                  (imnhSubs[f_dimInd][j_ind] > ImageSize[f_dimInd])) {
                isInside[j_ind] = false;
                e_imnhInds[j_ind] = 1;
                exitg1 = true;
              } else {
                f_dimInd++;
              }
            }
          }
        } break;
        case 3: {
          e_imnhInds.set_size(9);
          for (int i27{0}; i27 < 9; i27++) {
            e_imnhInds[i27] = b_imnhInds_[i27];
          }
          for (int k_ind{0}; k_ind < 9; k_ind++) {
            int i33;
            int i36;
            int i41;
            i33 = imnhSubs[0][k_ind];
            i36 = i33;
            pixelSub_idx_0 = i33;
            if (i33 < 1) {
              isInside[k_ind] = false;
              i36 = 1;
              pixelSub_idx_0 = 1;
            }
            if (i36 > ImageSize[0]) {
              isInside[k_ind] = false;
              pixelSub_idx_0 = ImageSize[0];
            }
            i41 = imnhSubs[1][k_ind];
            i36 = i41;
            pixelSub_idx_1 = i41;
            if (i41 < 1) {
              isInside[k_ind] = false;
              i36 = 1;
              pixelSub_idx_1 = 1;
            }
            if (i36 > ImageSize[1]) {
              isInside[k_ind] = false;
              pixelSub_idx_1 = ImageSize[1];
            }
            if (!isInside[k_ind]) {
              e_imnhInds[k_ind] =
                  pixelSub_idx_0 + ((pixelSub_idx_1 - 1) * ImageSize[0]);
            }
          }
        } break;
        case 4: {
          e_imnhInds.set_size(9);
          for (int i28{0}; i28 < 9; i28++) {
            e_imnhInds[i28] = b_imnhInds_[i28];
          }
          for (int m_ind{0}; m_ind < 9; m_ind++) {
            int i34;
            int i37;
            int i42;
            i34 = imnhSubs[0][m_ind];
            i37 = i34;
            pixelSub_idx_0 = i34;
            if (i34 < 1) {
              isInside[m_ind] = false;
              i37 = i34 + (ImageSize[0] * 2);
              pixelSub_idx_0 = i37;
            }
            if (i37 > ImageSize[0]) {
              isInside[m_ind] = false;
              i37 = ((ImageSize[0] * 2) - i37) + 1;
              pixelSub_idx_0 = i37;
            }
            i42 = imnhSubs[1][m_ind];
            i37 = i42;
            pixelSub_idx_1 = i42;
            if (i42 < 1) {
              isInside[m_ind] = false;
              i37 = i42 + (ImageSize[1] * 2);
              pixelSub_idx_1 = i37;
            }
            if (i37 > ImageSize[1]) {
              isInside[m_ind] = false;
              i37 = ((ImageSize[1] * 2) - i37) + 1;
              pixelSub_idx_1 = i37;
            }
            if (!isInside[m_ind]) {
              e_imnhInds[m_ind] =
                  pixelSub_idx_0 + ((pixelSub_idx_1 - 1) * ImageSize[0]);
            }
          }
        } break;
        default:
          /* no actions */
          break;
        }
        if (b_in.size(0) == 1) {
          int h_loop_ub;
          h_loop_ub = e_imnhInds.size(0);
          b_imnh.set_size(1, e_imnhInds.size(0));
          for (int i32{0}; i32 < h_loop_ub; i32++) {
            b_imnh[b_imnh.size(0) * i32] = b_in[e_imnhInds[i32] - 1];
          }
        } else {
          int g_loop_ub;
          g_loop_ub = e_imnhInds.size(0);
          c_in.set_size(e_imnhInds.size(0));
          for (int i31{0}; i31 < g_loop_ub; i31++) {
            c_in[i31] = b_in[e_imnhInds[i31] - 1];
          }
          imnhInds_idx_0 = e_imnhInds.size(0);
          b_imnh.set_size(e_imnhInds.size(0), 1);
          for (int i38{0}; i38 < imnhInds_idx_0; i38++) {
            b_imnh[i38] = c_in[i38];
          }
        }
        if (Padding == 2.0) {
          int f_partialTrueCount;
          int f_trueCount;
          int m_loop_ub;
          f_trueCount = 0;
          for (int hb_i{0}; hb_i < 9; hb_i++) {
            if (!isInside[hb_i]) {
              f_trueCount++;
            }
          }
          r2.set_size(f_trueCount);
          f_partialTrueCount = 0;
          for (int jb_i{0}; jb_i < 9; jb_i++) {
            if (!isInside[jb_i]) {
              r2[f_partialTrueCount] = static_cast<signed char>(jb_i + 1);
              f_partialTrueCount++;
            }
          }
          m_loop_ub = r2.size(0);
          for (int i49{0}; i49 < m_loop_ub; i49++) {
            b_imnh[(static_cast<int>(r2[i49])) - 1] = padValue_tmp;
          }
        }
        c_fparamsAugmented_pixel = b_in[d_pind];
        out[d_pind] = fparams->bw[d_pind];
        if (fparams->bw[d_pind]) {
          int d_pixelInd;
          //  Pixel has not already been set as non-max
          d_pixelInd = 0;
          exitg1 = false;
          while ((!exitg1) &&
                 (d_pixelInd <= ((b_imnh.size(0) * b_imnh.size(1)) - 1))) {
            if (b_imnh[d_pixelInd] > c_fparamsAugmented_pixel) {
              //  Set pixel to zero if any neighbor is greater
              out[d_pind] = false;
              exitg1 = true;
            } else if (b_imnh[d_pixelInd] == c_fparamsAugmented_pixel) {
              if (!fparams->bw[e_imnhInds[d_pixelInd] - 1]) {
                //  Set pixel to zero if any equal neighbor is already set to
                //  zero
                out[d_pind] = false;
                exitg1 = true;
              } else {
                d_pixelInd++;
              }
            } else {
              d_pixelInd++;
            }
          }
        }
      }
    }
    firstDimExtents_idx_0 = InteriorEnd[0] + 1;
    firstDimExtents_idx_1 = ImageSize[0];
    if (firstDimExtents_idx_0 < 1) {
      firstDimExtents_idx_0 = 1;
    }
    h_u1 = ImageSize[0];
    if (firstDimExtents_idx_1 > h_u1) {
      firstDimExtents_idx_1 = h_u1;
    }
    for (int e_secondInd{0}; e_secondInd < i5; e_secondInd++) {
      for (int e_firstInd{firstDimExtents_idx_0};
           e_firstInd <= firstDimExtents_idx_1; e_firstInd++) {
        float d_fparamsAugmented_pixel;
        int e_pind;
        int e_z;
        int f_r;
        int o_x;
        //  Process pixels with partial neighborhood
        e_pind = ((e_secondInd * ImageSize[0]) + e_firstInd) - 1;
        for (int q_i{0}; q_i < 9; q_i++) {
          b_imnhInds_[q_i] = (ImageNeighborLinearOffsets[q_i] + e_pind) + 1;
        }
        if (ImageSize[0] == 0) {
          f_r = 0;
        } else {
          f_r = e_pind - (ImageSize[0] * div_s32(e_pind, ImageSize[0]));
        }
        o_x = e_pind - f_r;
        if (ImageSize[0] == 0) {
          if (o_x == 0) {
            e_z = 0;
          } else if (o_x < 0) {
            e_z = MIN_int32_T;
          } else {
            e_z = MAX_int32_T;
          }
        } else if (ImageSize[0] == 1) {
          e_z = o_x;
        } else if (ImageSize[0] == -1) {
          e_z = -o_x;
        } else {
          int e_y;
          int p_x;
          if (o_x >= 0) {
            p_x = o_x;
          } else if (o_x == MIN_int32_T) {
            p_x = MIN_int32_T;
          } else {
            p_x = -o_x;
          }
          if (ImageSize[0] >= 0) {
            e_y = ImageSize[0];
          } else if (ImageSize[0] == MIN_int32_T) {
            e_y = MIN_int32_T;
          } else {
            e_y = -ImageSize[0];
          }
          e_z = div_s32(p_x, e_y);
          p_x -= e_z * e_y;
          if ((p_x > 0) && (p_x >= (asr_s32(e_y, 1U) + (e_y & 1)))) {
            e_z++;
          }
          if ((o_x < 0) != (ImageSize[0] < 0)) {
            e_z = -e_z;
          }
        }
        pixelSub[1] = e_z + 1;
        pixelSub[0] = f_r + 1;
        for (int g_k{0}; g_k < 2; g_k++) {
          for (int h_k{0}; h_k < 9; h_k++) {
            imnhSubs[g_k][h_k] =
                NeighborSubscriptOffsets[g_k][h_k] + pixelSub[g_k];
          }
        }
        for (int gb_i{0}; gb_i < 9; gb_i++) {
          isInside[gb_i] = true;
        }
        switch (static_cast<int>(Padding)) {
        case 1: {
          int g_partialTrueCount;
          int g_trueCount;
          g_trueCount = 0;
          for (int o_ind{0}; o_ind < 9; o_ind++) {
            int g_dimInd;
            g_dimInd = 0;
            exitg1 = false;
            while ((!exitg1) && (g_dimInd < 2)) {
              if ((imnhSubs[g_dimInd][o_ind] < 1) ||
                  (imnhSubs[g_dimInd][o_ind] > ImageSize[g_dimInd])) {
                isInside[o_ind] = false;
                exitg1 = true;
              } else {
                g_dimInd++;
              }
            }
            if (isInside[o_ind]) {
              g_trueCount++;
            }
          }
          f_imnhInds.set_size(g_trueCount);
          g_partialTrueCount = 0;
          for (int kb_i{0}; kb_i < 9; kb_i++) {
            if (isInside[kb_i]) {
              f_imnhInds[g_partialTrueCount] = b_imnhInds_[kb_i];
              g_partialTrueCount++;
            }
          }
        } break;
        case 2: {
          f_imnhInds.set_size(9);
          for (int q_ind{0}; q_ind < 9; q_ind++) {
            int h_dimInd;
            f_imnhInds[q_ind] = b_imnhInds_[q_ind];
            h_dimInd = 0;
            exitg1 = false;
            while ((!exitg1) && (h_dimInd < 2)) {
              if ((imnhSubs[h_dimInd][q_ind] < 1) ||
                  (imnhSubs[h_dimInd][q_ind] > ImageSize[h_dimInd])) {
                isInside[q_ind] = false;
                f_imnhInds[q_ind] = 1;
                exitg1 = true;
              } else {
                h_dimInd++;
              }
            }
          }
        } break;
        case 3: {
          f_imnhInds.set_size(9);
          for (int i39{0}; i39 < 9; i39++) {
            f_imnhInds[i39] = b_imnhInds_[i39];
          }
          for (int r_ind{0}; r_ind < 9; r_ind++) {
            int i45;
            int i47;
            int i51;
            i45 = imnhSubs[0][r_ind];
            i47 = i45;
            pixelSub_idx_0 = i45;
            if (i45 < 1) {
              isInside[r_ind] = false;
              i47 = 1;
              pixelSub_idx_0 = 1;
            }
            if (i47 > ImageSize[0]) {
              isInside[r_ind] = false;
              pixelSub_idx_0 = ImageSize[0];
            }
            i51 = imnhSubs[1][r_ind];
            i47 = i51;
            pixelSub_idx_1 = i51;
            if (i51 < 1) {
              isInside[r_ind] = false;
              i47 = 1;
              pixelSub_idx_1 = 1;
            }
            if (i47 > ImageSize[1]) {
              isInside[r_ind] = false;
              pixelSub_idx_1 = ImageSize[1];
            }
            if (!isInside[r_ind]) {
              f_imnhInds[r_ind] =
                  pixelSub_idx_0 + ((pixelSub_idx_1 - 1) * ImageSize[0]);
            }
          }
        } break;
        case 4: {
          f_imnhInds.set_size(9);
          for (int i40{0}; i40 < 9; i40++) {
            f_imnhInds[i40] = b_imnhInds_[i40];
          }
          for (int t_ind{0}; t_ind < 9; t_ind++) {
            int i46;
            int i48;
            int i52;
            i46 = imnhSubs[0][t_ind];
            i48 = i46;
            pixelSub_idx_0 = i46;
            if (i46 < 1) {
              isInside[t_ind] = false;
              i48 = i46 + (ImageSize[0] * 2);
              pixelSub_idx_0 = i48;
            }
            if (i48 > ImageSize[0]) {
              isInside[t_ind] = false;
              i48 = ((ImageSize[0] * 2) - i48) + 1;
              pixelSub_idx_0 = i48;
            }
            i52 = imnhSubs[1][t_ind];
            i48 = i52;
            pixelSub_idx_1 = i52;
            if (i52 < 1) {
              isInside[t_ind] = false;
              i48 = i52 + (ImageSize[1] * 2);
              pixelSub_idx_1 = i48;
            }
            if (i48 > ImageSize[1]) {
              isInside[t_ind] = false;
              i48 = ((ImageSize[1] * 2) - i48) + 1;
              pixelSub_idx_1 = i48;
            }
            if (!isInside[t_ind]) {
              f_imnhInds[t_ind] =
                  pixelSub_idx_0 + ((pixelSub_idx_1 - 1) * ImageSize[0]);
            }
          }
        } break;
        default:
          /* no actions */
          break;
        }
        if (b_in.size(0) == 1) {
          int k_loop_ub;
          k_loop_ub = f_imnhInds.size(0);
          b_imnh.set_size(1, f_imnhInds.size(0));
          for (int i44{0}; i44 < k_loop_ub; i44++) {
            b_imnh[b_imnh.size(0) * i44] = b_in[f_imnhInds[i44] - 1];
          }
        } else {
          int j_loop_ub;
          j_loop_ub = f_imnhInds.size(0);
          c_in.set_size(f_imnhInds.size(0));
          for (int i43{0}; i43 < j_loop_ub; i43++) {
            c_in[i43] = b_in[f_imnhInds[i43] - 1];
          }
          imnhInds_idx_0 = f_imnhInds.size(0);
          b_imnh.set_size(f_imnhInds.size(0), 1);
          for (int i50{0}; i50 < imnhInds_idx_0; i50++) {
            b_imnh[i50] = c_in[i50];
          }
        }
        if (Padding == 2.0) {
          int h_partialTrueCount;
          int h_trueCount;
          int o_loop_ub;
          h_trueCount = 0;
          for (int mb_i{0}; mb_i < 9; mb_i++) {
            if (!isInside[mb_i]) {
              h_trueCount++;
            }
          }
          r3.set_size(h_trueCount);
          h_partialTrueCount = 0;
          for (int ob_i{0}; ob_i < 9; ob_i++) {
            if (!isInside[ob_i]) {
              r3[h_partialTrueCount] = static_cast<signed char>(ob_i + 1);
              h_partialTrueCount++;
            }
          }
          o_loop_ub = r3.size(0);
          for (int i53{0}; i53 < o_loop_ub; i53++) {
            b_imnh[(static_cast<int>(r3[i53])) - 1] = padValue_tmp;
          }
        }
        d_fparamsAugmented_pixel = b_in[e_pind];
        out[e_pind] = fparams->bw[e_pind];
        if (fparams->bw[e_pind]) {
          int e_pixelInd;
          //  Pixel has not already been set as non-max
          e_pixelInd = 0;
          exitg1 = false;
          while ((!exitg1) &&
                 (e_pixelInd <= ((b_imnh.size(0) * b_imnh.size(1)) - 1))) {
            if (b_imnh[e_pixelInd] > d_fparamsAugmented_pixel) {
              //  Set pixel to zero if any neighbor is greater
              out[e_pind] = false;
              exitg1 = true;
            } else if (b_imnh[e_pixelInd] == d_fparamsAugmented_pixel) {
              if (!fparams->bw[f_imnhInds[e_pixelInd] - 1]) {
                //  Set pixel to zero if any equal neighbor is already set to
                //  zero
                out[e_pind] = false;
                exitg1 = true;
              } else {
                e_pixelInd++;
              }
            } else {
              e_pixelInd++;
            }
          }
        }
      }
    }
  }
}

} // namespace coder
} // namespace internal
} // namespace images
} // namespace coder

//
// File trailer for NeighborhoodProcessor.cpp
//
// [EOF]
//
