//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: imregionalmax.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "imregionalmax.h"
#include "NeighborhoodProcessor.h"
#include "calibrateCamera_rtwutil.h"
#include "isequal.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <algorithm>

// Function Definitions
//
// Arguments    : const ::coder::array<real32_T, 2U> &varargin_1
//                ::coder::array<boolean_T, 2U> &BW
// Return Type  : void
//
namespace Codegen {
namespace coder {
void imregionalmax(const ::coder::array<real32_T, 2U> &varargin_1,
                   ::coder::array<boolean_T, 2U> &BW)
{
  images::internal::coder::NeighborhoodProcessor np;
  ::coder::array<boolean_T, 2U> bwpre;
  ::coder::array<boolean_T, 1U> out_;
  int32_T imnhSubs[2][9];
  int32_T b_imnhInds_data[9];
  int32_T c_imnhInds_data[9];
  int32_T d_imnhInds_data[9];
  int32_T imnhInds[9];
  int32_T imnhInds_data[9];
  int32_T iv[2];
  int32_T iv1[2];
  int32_T pixelSub[2];
  int32_T b_i;
  int32_T d_i;
  int32_T loop_ub;
  int32_T secondDimExtents_idx_0;
  real32_T imnh_data[81];
  real32_T varargin_1_data[9];
  uint32_T uv[2];
  boolean_T b_bv[3][3];
  boolean_T isInside[9];
  boolean_T continuePropagation;
  np.ImageSize[0] = varargin_1.size(0);
  np.ImageSize[1] = varargin_1.size(1);
  for (b_i = 0; b_i < 9; b_i++) {
    np.ImageNeighborLinearOffsets[b_i] = 0;
    np.NeighborLinearIndices[b_i] = 0;
  }
  for (d_i = 0; d_i < 2; d_i++) {
    for (secondDimExtents_idx_0 = 0; secondDimExtents_idx_0 < 9;
         secondDimExtents_idx_0++) {
      np.NeighborSubscriptOffsets[d_i][secondDimExtents_idx_0] = 0;
    }
    uv[d_i] = static_cast<uint32_T>(varargin_1.size(d_i));
  }
  BW.set_size(static_cast<int32_T>(uv[0]), static_cast<int32_T>(uv[1]));
  b_i = static_cast<int32_T>(uv[1]);
  for (d_i = 0; d_i < b_i; d_i++) {
    loop_ub = static_cast<int32_T>(uv[0]);
    for (secondDimExtents_idx_0 = 0; secondDimExtents_idx_0 < loop_ub;
         secondDimExtents_idx_0++) {
      BW[secondDimExtents_idx_0 + (BW.size(0) * d_i)] = true;
    }
  }
  for (d_i = 0; d_i < 3; d_i++) {
    b_bv[d_i][0] = true;
    b_bv[d_i][1] = true;
    b_bv[d_i][2] = true;
  }
  continuePropagation = true;
  while (continuePropagation) {
    int32_T firstInd;
    int32_T imnh_size_idx_0;
    int32_T imnh_size_idx_1;
    int32_T ind;
    int32_T pind;
    int32_T secondDimExtents_idx_1;
    int32_T secondInd;
    int32_T u1;
    int32_T z;
    real32_T fparamsAugmented_pixel;
    boolean_T exitg1;
    bwpre.set_size(BW.size(0), BW.size(1));
    b_i = BW.size(1);
    for (d_i = 0; d_i < b_i; d_i++) {
      loop_ub = BW.size(0);
      for (secondDimExtents_idx_0 = 0; secondDimExtents_idx_0 < loop_ub;
           secondDimExtents_idx_0++) {
        bwpre[secondDimExtents_idx_0 + (bwpre.size(0) * d_i)] =
            BW[secondDimExtents_idx_0 + (BW.size(0) * d_i)];
      }
    }
    for (b_i = 0; b_i < 9; b_i++) {
      imnhInds[b_i] = np.NeighborLinearIndices[b_i];
    }
    images::internal::coder::NeighborhoodProcessor::computeParameters(
        np.ImageSize, b_bv, np.ImageNeighborLinearOffsets, imnhInds,
        np.NeighborSubscriptOffsets, iv, iv1);
    for (b_i = 0; b_i < 9; b_i++) {
      np.NeighborLinearIndices[b_i] = imnhInds[b_i];
    }
    d_i = iv[1];
    secondDimExtents_idx_0 = iv1[1];
    for (secondInd = d_i; secondInd <= secondDimExtents_idx_0; secondInd++) {
      out_.set_size(BW.size(0));
      z = iv[0];
      loop_ub = iv1[0];
      for (firstInd = z; firstInd <= loop_ub; firstInd++) {
        //  Process pixels with full neighborhood
        pind = (((secondInd - 1) * np.ImageSize[0]) + firstInd) - 1;
        for (b_i = 0; b_i < 9; b_i++) {
          imnhInds[b_i] = (np.ImageNeighborLinearOffsets[b_i] + pind) + 1;
        }
        if (varargin_1.size(0) == 1) {
          imnh_size_idx_0 = 1;
          imnh_size_idx_1 = 9;
          for (b_i = 0; b_i < 9; b_i++) {
            imnh_data[b_i] = varargin_1[imnhInds[b_i] - 1];
          }
        } else {
          imnh_size_idx_0 = 9;
          imnh_size_idx_1 = 1;
          for (b_i = 0; b_i < 9; b_i++) {
            imnh_data[b_i] = varargin_1[imnhInds[b_i] - 1];
          }
        }
        fparamsAugmented_pixel = varargin_1[pind];
        out_[firstInd - 1] = bwpre[pind];
        if (bwpre[pind]) {
          //  Pixel has not already been set as non-max
          ind = 0;
          exitg1 = false;
          while ((!exitg1) &&
                 (ind <= ((imnh_size_idx_0 * imnh_size_idx_1) - 1))) {
            if (imnh_data[ind] > fparamsAugmented_pixel) {
              //  Set pixel to zero if any neighbor is greater
              out_[firstInd - 1] = false;
              exitg1 = true;
            } else if (imnh_data[ind] == fparamsAugmented_pixel) {
              if (!bwpre[imnhInds[ind] - 1]) {
                //  Set pixel to zero if any equal neighbor is already set to
                //  zero
                out_[firstInd - 1] = false;
                exitg1 = true;
              } else {
                ind++;
              }
            } else {
              ind++;
            }
          }
        }
      }
      b_i = out_.size(0);
      for (z = 0; z < b_i; z++) {
        BW[z + (BW.size(0) * (secondInd - 1))] = out_[z];
      }
    }
    secondDimExtents_idx_1 = iv[1] - 1;
    loop_ub = np.ImageSize[0];
    u1 = np.ImageSize[0];
    if (loop_ub <= u1) {
      u1 = loop_ub;
    }
    if ((iv[1] - 1) > np.ImageSize[1]) {
      secondDimExtents_idx_1 = np.ImageSize[1];
    }
    for (secondInd = 0; secondInd < secondDimExtents_idx_1; secondInd++) {
      for (firstInd = 0; firstInd < u1; firstInd++) {
        //  Process pixels with partial neighborhood
        pind = (secondInd * np.ImageSize[0]) + firstInd;
        for (b_i = 0; b_i < 9; b_i++) {
          imnhInds[b_i] = (np.ImageNeighborLinearOffsets[b_i] + pind) + 1;
        }
        if (np.ImageSize[0] == 0) {
          loop_ub = 0;
        } else {
          loop_ub = pind - (np.ImageSize[0] * div_s32(pind, np.ImageSize[0]));
        }
        b_i = pind - loop_ub;
        if (np.ImageSize[0] == 0) {
          if (b_i == 0) {
            z = 0;
          } else if (b_i < 0) {
            z = MIN_int32_T;
          } else {
            z = MAX_int32_T;
          }
        } else if (np.ImageSize[0] == 1) {
          z = b_i;
        } else {
          if (b_i >= 0) {
            ind = b_i;
          } else if (b_i == MIN_int32_T) {
            ind = MAX_int32_T;
          } else {
            ind = -b_i;
          }
          z = div_s32(ind, np.ImageSize[0]);
          ind -= z * np.ImageSize[0];
          if ((ind > 0) &&
              (ind >= (asr_s32(np.ImageSize[0], 1U) + (np.ImageSize[0] & 1)))) {
            z++;
          }
          if (b_i < 0) {
            z = -z;
          }
        }
        pixelSub[1] = z + 1;
        pixelSub[0] = loop_ub + 1;
        for (loop_ub = 0; loop_ub < 2; loop_ub++) {
          for (b_i = 0; b_i < 9; b_i++) {
            imnhSubs[loop_ub][b_i] =
                np.NeighborSubscriptOffsets[loop_ub][b_i] + pixelSub[loop_ub];
          }
        }
        z = 0;
        loop_ub = 0;
        for (ind = 0; ind < 9; ind++) {
          isInside[ind] = true;
          b_i = 0;
          exitg1 = false;
          while ((!exitg1) && (b_i < 2)) {
            if ((imnhSubs[b_i][ind] < 1) ||
                (imnhSubs[b_i][ind] > np.ImageSize[b_i])) {
              isInside[ind] = false;
              exitg1 = true;
            } else {
              b_i++;
            }
          }
          if (isInside[ind]) {
            z++;
            imnhInds_data[loop_ub] = imnhInds[ind];
            loop_ub++;
          }
        }
        if (varargin_1.size(0) == 1) {
          imnh_size_idx_0 = 1;
          imnh_size_idx_1 = z;
          for (d_i = 0; d_i < z; d_i++) {
            imnh_data[d_i] = varargin_1[imnhInds_data[d_i] - 1];
          }
        } else {
          for (d_i = 0; d_i < z; d_i++) {
            varargin_1_data[d_i] = varargin_1[imnhInds_data[d_i] - 1];
          }
          imnh_size_idx_0 = z;
          imnh_size_idx_1 = 1;
          if (0 <= (z - 1)) {
            (void)std::copy(&varargin_1_data[0], &varargin_1_data[z],
                            &imnh_data[0]);
          }
        }
        fparamsAugmented_pixel = varargin_1[pind];
        BW[pind] = bwpre[pind];
        if (bwpre[pind]) {
          //  Pixel has not already been set as non-max
          ind = 0;
          exitg1 = false;
          while ((!exitg1) &&
                 (ind <= ((imnh_size_idx_0 * imnh_size_idx_1) - 1))) {
            if (imnh_data[ind] > fparamsAugmented_pixel) {
              //  Set pixel to zero if any neighbor is greater
              BW[pind] = false;
              exitg1 = true;
            } else if (imnh_data[ind] == fparamsAugmented_pixel) {
              if (!bwpre[imnhInds_data[ind] - 1]) {
                //  Set pixel to zero if any equal neighbor is already set to
                //  zero
                BW[pind] = false;
                exitg1 = true;
              } else {
                ind++;
              }
            } else {
              ind++;
            }
          }
        }
      }
    }
    secondDimExtents_idx_0 = iv1[1] + 1;
    secondDimExtents_idx_1 = np.ImageSize[1];
    if ((iv1[1] + 1) < 1) {
      secondDimExtents_idx_0 = 1;
    }
    for (secondInd = secondDimExtents_idx_0;
         secondInd <= secondDimExtents_idx_1; secondInd++) {
      for (firstInd = 0; firstInd < u1; firstInd++) {
        //  Process pixels with partial neighborhood
        pind = ((secondInd - 1) * np.ImageSize[0]) + firstInd;
        for (b_i = 0; b_i < 9; b_i++) {
          imnhInds[b_i] = (np.ImageNeighborLinearOffsets[b_i] + pind) + 1;
        }
        if (np.ImageSize[0] == 0) {
          loop_ub = 0;
        } else {
          loop_ub = pind - (np.ImageSize[0] * div_s32(pind, np.ImageSize[0]));
        }
        b_i = pind - loop_ub;
        if (np.ImageSize[0] == 0) {
          if (b_i == 0) {
            z = 0;
          } else if (b_i < 0) {
            z = MIN_int32_T;
          } else {
            z = MAX_int32_T;
          }
        } else if (np.ImageSize[0] == 1) {
          z = b_i;
        } else {
          if (b_i >= 0) {
            ind = b_i;
          } else if (b_i == MIN_int32_T) {
            ind = MAX_int32_T;
          } else {
            ind = -b_i;
          }
          z = div_s32(ind, np.ImageSize[0]);
          ind -= z * np.ImageSize[0];
          if ((ind > 0) &&
              (ind >= (asr_s32(np.ImageSize[0], 1U) + (np.ImageSize[0] & 1)))) {
            z++;
          }
          if (b_i < 0) {
            z = -z;
          }
        }
        pixelSub[1] = z + 1;
        pixelSub[0] = loop_ub + 1;
        for (loop_ub = 0; loop_ub < 2; loop_ub++) {
          for (b_i = 0; b_i < 9; b_i++) {
            imnhSubs[loop_ub][b_i] =
                np.NeighborSubscriptOffsets[loop_ub][b_i] + pixelSub[loop_ub];
          }
        }
        z = 0;
        loop_ub = 0;
        for (ind = 0; ind < 9; ind++) {
          isInside[ind] = true;
          b_i = 0;
          exitg1 = false;
          while ((!exitg1) && (b_i < 2)) {
            if ((imnhSubs[b_i][ind] < 1) ||
                (imnhSubs[b_i][ind] > np.ImageSize[b_i])) {
              isInside[ind] = false;
              exitg1 = true;
            } else {
              b_i++;
            }
          }
          if (isInside[ind]) {
            z++;
            b_imnhInds_data[loop_ub] = imnhInds[ind];
            loop_ub++;
          }
        }
        if (varargin_1.size(0) == 1) {
          imnh_size_idx_0 = 1;
          imnh_size_idx_1 = z;
          for (d_i = 0; d_i < z; d_i++) {
            imnh_data[d_i] = varargin_1[b_imnhInds_data[d_i] - 1];
          }
        } else {
          for (d_i = 0; d_i < z; d_i++) {
            varargin_1_data[d_i] = varargin_1[b_imnhInds_data[d_i] - 1];
          }
          imnh_size_idx_0 = z;
          imnh_size_idx_1 = 1;
          if (0 <= (z - 1)) {
            (void)std::copy(&varargin_1_data[0], &varargin_1_data[z],
                            &imnh_data[0]);
          }
        }
        fparamsAugmented_pixel = varargin_1[pind];
        BW[pind] = bwpre[pind];
        if (bwpre[pind]) {
          //  Pixel has not already been set as non-max
          ind = 0;
          exitg1 = false;
          while ((!exitg1) &&
                 (ind <= ((imnh_size_idx_0 * imnh_size_idx_1) - 1))) {
            if (imnh_data[ind] > fparamsAugmented_pixel) {
              //  Set pixel to zero if any neighbor is greater
              BW[pind] = false;
              exitg1 = true;
            } else if (imnh_data[ind] == fparamsAugmented_pixel) {
              if (!bwpre[b_imnhInds_data[ind] - 1]) {
                //  Set pixel to zero if any equal neighbor is already set to
                //  zero
                BW[pind] = false;
                exitg1 = true;
              } else {
                ind++;
              }
            } else {
              ind++;
            }
          }
        }
      }
    }
    secondDimExtents_idx_1 = iv[0] - 1;
    if ((iv[0] - 1) > np.ImageSize[0]) {
      secondDimExtents_idx_1 = np.ImageSize[0];
    }
    loop_ub = np.ImageSize[1];
    u1 = np.ImageSize[1];
    if (loop_ub <= u1) {
      u1 = loop_ub;
    }
    for (secondInd = 1; secondInd <= u1; secondInd++) {
      for (firstInd = 0; firstInd < secondDimExtents_idx_1; firstInd++) {
        //  Process pixels with partial neighborhood
        pind = ((secondInd - 1) * np.ImageSize[0]) + firstInd;
        for (b_i = 0; b_i < 9; b_i++) {
          imnhInds[b_i] = (np.ImageNeighborLinearOffsets[b_i] + pind) + 1;
        }
        if (np.ImageSize[0] == 0) {
          loop_ub = 0;
        } else {
          loop_ub = pind - (np.ImageSize[0] * div_s32(pind, np.ImageSize[0]));
        }
        b_i = pind - loop_ub;
        if (np.ImageSize[0] == 0) {
          if (b_i == 0) {
            z = 0;
          } else if (b_i < 0) {
            z = MIN_int32_T;
          } else {
            z = MAX_int32_T;
          }
        } else if (np.ImageSize[0] == 1) {
          z = b_i;
        } else {
          if (b_i >= 0) {
            ind = b_i;
          } else if (b_i == MIN_int32_T) {
            ind = MAX_int32_T;
          } else {
            ind = -b_i;
          }
          z = div_s32(ind, np.ImageSize[0]);
          ind -= z * np.ImageSize[0];
          if ((ind > 0) &&
              (ind >= (asr_s32(np.ImageSize[0], 1U) + (np.ImageSize[0] & 1)))) {
            z++;
          }
          if (b_i < 0) {
            z = -z;
          }
        }
        pixelSub[1] = z + 1;
        pixelSub[0] = loop_ub + 1;
        for (loop_ub = 0; loop_ub < 2; loop_ub++) {
          for (b_i = 0; b_i < 9; b_i++) {
            imnhSubs[loop_ub][b_i] =
                np.NeighborSubscriptOffsets[loop_ub][b_i] + pixelSub[loop_ub];
          }
        }
        z = 0;
        loop_ub = 0;
        for (ind = 0; ind < 9; ind++) {
          isInside[ind] = true;
          b_i = 0;
          exitg1 = false;
          while ((!exitg1) && (b_i < 2)) {
            if ((imnhSubs[b_i][ind] < 1) ||
                (imnhSubs[b_i][ind] > np.ImageSize[b_i])) {
              isInside[ind] = false;
              exitg1 = true;
            } else {
              b_i++;
            }
          }
          if (isInside[ind]) {
            z++;
            c_imnhInds_data[loop_ub] = imnhInds[ind];
            loop_ub++;
          }
        }
        if (varargin_1.size(0) == 1) {
          imnh_size_idx_0 = 1;
          imnh_size_idx_1 = z;
          for (d_i = 0; d_i < z; d_i++) {
            imnh_data[d_i] = varargin_1[c_imnhInds_data[d_i] - 1];
          }
        } else {
          for (d_i = 0; d_i < z; d_i++) {
            varargin_1_data[d_i] = varargin_1[c_imnhInds_data[d_i] - 1];
          }
          imnh_size_idx_0 = z;
          imnh_size_idx_1 = 1;
          if (0 <= (z - 1)) {
            (void)std::copy(&varargin_1_data[0], &varargin_1_data[z],
                            &imnh_data[0]);
          }
        }
        fparamsAugmented_pixel = varargin_1[pind];
        BW[pind] = bwpre[pind];
        if (bwpre[pind]) {
          //  Pixel has not already been set as non-max
          ind = 0;
          exitg1 = false;
          while ((!exitg1) &&
                 (ind <= ((imnh_size_idx_0 * imnh_size_idx_1) - 1))) {
            if (imnh_data[ind] > fparamsAugmented_pixel) {
              //  Set pixel to zero if any neighbor is greater
              BW[pind] = false;
              exitg1 = true;
            } else if (imnh_data[ind] == fparamsAugmented_pixel) {
              if (!bwpre[c_imnhInds_data[ind] - 1]) {
                //  Set pixel to zero if any equal neighbor is already set to
                //  zero
                BW[pind] = false;
                exitg1 = true;
              } else {
                ind++;
              }
            } else {
              ind++;
            }
          }
        }
      }
    }
    secondDimExtents_idx_0 = iv1[0] + 1;
    secondDimExtents_idx_1 = np.ImageSize[0];
    if ((iv1[0] + 1) < 1) {
      secondDimExtents_idx_0 = 1;
    }
    for (secondInd = 0; secondInd < u1; secondInd++) {
      for (firstInd = secondDimExtents_idx_0;
           firstInd <= secondDimExtents_idx_1; firstInd++) {
        //  Process pixels with partial neighborhood
        pind = ((secondInd * np.ImageSize[0]) + firstInd) - 1;
        for (b_i = 0; b_i < 9; b_i++) {
          imnhInds[b_i] = (np.ImageNeighborLinearOffsets[b_i] + pind) + 1;
        }
        if (np.ImageSize[0] == 0) {
          loop_ub = 0;
        } else {
          loop_ub = pind - (np.ImageSize[0] * div_s32(pind, np.ImageSize[0]));
        }
        b_i = pind - loop_ub;
        if (np.ImageSize[0] == 0) {
          if (b_i == 0) {
            z = 0;
          } else if (b_i < 0) {
            z = MIN_int32_T;
          } else {
            z = MAX_int32_T;
          }
        } else if (np.ImageSize[0] == 1) {
          z = b_i;
        } else {
          if (b_i >= 0) {
            ind = b_i;
          } else if (b_i == MIN_int32_T) {
            ind = MAX_int32_T;
          } else {
            ind = -b_i;
          }
          z = div_s32(ind, np.ImageSize[0]);
          ind -= z * np.ImageSize[0];
          if ((ind > 0) &&
              (ind >= (asr_s32(np.ImageSize[0], 1U) + (np.ImageSize[0] & 1)))) {
            z++;
          }
          if (b_i < 0) {
            z = -z;
          }
        }
        pixelSub[1] = z + 1;
        pixelSub[0] = loop_ub + 1;
        for (loop_ub = 0; loop_ub < 2; loop_ub++) {
          for (b_i = 0; b_i < 9; b_i++) {
            imnhSubs[loop_ub][b_i] =
                np.NeighborSubscriptOffsets[loop_ub][b_i] + pixelSub[loop_ub];
          }
        }
        z = 0;
        loop_ub = 0;
        for (ind = 0; ind < 9; ind++) {
          isInside[ind] = true;
          b_i = 0;
          exitg1 = false;
          while ((!exitg1) && (b_i < 2)) {
            if ((imnhSubs[b_i][ind] < 1) ||
                (imnhSubs[b_i][ind] > np.ImageSize[b_i])) {
              isInside[ind] = false;
              exitg1 = true;
            } else {
              b_i++;
            }
          }
          if (isInside[ind]) {
            z++;
            d_imnhInds_data[loop_ub] = imnhInds[ind];
            loop_ub++;
          }
        }
        if (varargin_1.size(0) == 1) {
          imnh_size_idx_0 = 1;
          imnh_size_idx_1 = z;
          for (d_i = 0; d_i < z; d_i++) {
            imnh_data[d_i] = varargin_1[d_imnhInds_data[d_i] - 1];
          }
        } else {
          for (d_i = 0; d_i < z; d_i++) {
            varargin_1_data[d_i] = varargin_1[d_imnhInds_data[d_i] - 1];
          }
          imnh_size_idx_0 = z;
          imnh_size_idx_1 = 1;
          if (0 <= (z - 1)) {
            (void)std::copy(&varargin_1_data[0], &varargin_1_data[z],
                            &imnh_data[0]);
          }
        }
        fparamsAugmented_pixel = varargin_1[pind];
        BW[pind] = bwpre[pind];
        if (bwpre[pind]) {
          //  Pixel has not already been set as non-max
          ind = 0;
          exitg1 = false;
          while ((!exitg1) &&
                 (ind <= ((imnh_size_idx_0 * imnh_size_idx_1) - 1))) {
            if (imnh_data[ind] > fparamsAugmented_pixel) {
              //  Set pixel to zero if any neighbor is greater
              BW[pind] = false;
              exitg1 = true;
            } else if (imnh_data[ind] == fparamsAugmented_pixel) {
              if (!bwpre[d_imnhInds_data[ind] - 1]) {
                //  Set pixel to zero if any equal neighbor is already set to
                //  zero
                BW[pind] = false;
                exitg1 = true;
              } else {
                ind++;
              }
            } else {
              ind++;
            }
          }
        }
      }
    }
    continuePropagation = !b_isequal(bwpre, BW);
  }
}

} // namespace coder
} // namespace Codegen

//
// File trailer for imregionalmax.cpp
//
// [EOF]
//
