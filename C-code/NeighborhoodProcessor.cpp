//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: NeighborhoodProcessor.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

// Include Files
#include "NeighborhoodProcessor.h"
#include "calibrateHandeye_internal_types.h"
#include "calibrateHandeye_rtwutil.h"
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
static double rt_remd_snf(double u0, double u1);

// Function Definitions
//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_remd_snf(double u0, double u1)
{
  double y;
  if (((std::isnan(u0)) || (std::isnan(u1))) || (std::isinf(u0))) {
    y = rtNaN;
  } else if (std::isinf(u1)) {
    y = u0;
  } else if ((u1 != 0.0) && (u1 != std::trunc(u1))) {
    double q;
    q = std::abs(u0 / u1);
    if (!(std::abs(q - std::floor(q + 0.5)) > (DBL_EPSILON * q))) {
      y = 0.0 * u0;
    } else {
      y = std::fmod(u0, u1);
    }
  } else {
    y = std::fmod(u0, u1);
  }
  return y;
}

//
// Arguments    : const int imSize[2]
//                const bool nhConn[3][3]
//                int loffsets[9]
//                int linds[9]
//                int soffsets[2][9]
//                int interiorStart[2]
//                int interiorEnd[2]
// Return Type  : void
//
namespace coder {
namespace images {
namespace internal {
namespace coder {
void NeighborhoodProcessor::computeParameters(
    const int imSize[2], const bool nhConn[3][3], int loffsets[9], int linds[9],
    int soffsets[2][9], int interiorStart[2], int interiorEnd[2])
{
  int indx;
  int k;
  int pixelsPerImPage1_idx_1;
  pixelsPerImPage1_idx_1 = imSize[0];
  interiorStart[0] = 2;
  interiorEnd[0] = imSize[0] - 1;
  interiorStart[1] = 2;
  interiorEnd[1] = imSize[1] - 1;
  indx = static_cast<int>((&nhConn[0][0])[0]);
  for (k = 0; k < 8; k++) {
    indx += static_cast<int>((&nhConn[0][0])[k + 1]);
  }
  if (indx != 0) {
    double b;
    indx = 0;
    for (int pind{0}; pind < 9; pind++) {
      if ((&nhConn[0][0])[pind]) {
        int subs_idx_1_tmp;
        k = static_cast<int>(
            rt_remd_snf(((static_cast<double>(pind)) + 1.0) - 1.0, 3.0));
        subs_idx_1_tmp = static_cast<int>(static_cast<double>(
            ((static_cast<double>(static_cast<int>((pind - k) - 1))) + 1.0) /
            3.0));
        soffsets[0][indx] = k + 1;
        soffsets[1][indx] = subs_idx_1_tmp + 1;
        linds[indx] = (k + (subs_idx_1_tmp * 3)) + 1;
        loffsets[indx] = (k + (subs_idx_1_tmp * pixelsPerImPage1_idx_1)) + 1;
        indx++;
      }
    }
    b = (static_cast<double>(imSize[0])) + 2.0;
    for (indx = 0; indx < 9; indx++) {
      loffsets[indx] -= static_cast<int>(b);
    }
    for (k = 0; k < 2; k++) {
      for (indx = 0; indx < 9; indx++) {
        soffsets[k][indx] -= 2;
      }
    }
  }
}

//
// Arguments    : const ::coder::array<float, 2U> &in
//                ::coder::array<bool, 2U> &out
//                const struct_T *fparams
// Return Type  : void
//
void NeighborhoodProcessor::process2D(const ::coder::array<float, 2U> &in,
                                      ::coder::array<bool, 2U> &out,
                                      const struct_T *fparams) const
{
  array<float, 2U> b_imnh;
  array<float, 2U> imnh;
  array<float, 1U> b_in;
  array<int, 1U> b_imnhInds;
  array<int, 1U> c_imnhInds;
  array<int, 1U> d_imnhInds;
  array<int, 1U> e_imnhInds;
  array<signed char, 1U> r;
  array<signed char, 1U> r1;
  array<signed char, 1U> r2;
  array<signed char, 1U> r3;
  array<bool, 1U> out_;
  b_struct_T fparamsAugmented;
  int imnhSubs[2][9];
  int imageNeighborLinearOffsets[9];
  int imnhInds[9];
  int pixelSub[2];
  int b_firstInd;
  int b_i;
  int c_i;
  int i;
  int i1;
  int imageSize1;
  int lb_loop;
  int pind;
  bool isInside[9];
  bool exitg1;
  pixelSub[0] = this->InteriorStart[0];
  pixelSub[1] = this->InteriorEnd[0];
  for (i = 0; i < 9; i++) {
    imageNeighborLinearOffsets[i] = this->ImageNeighborLinearOffsets[i];
  }
  imageSize1 = this->ImageSize[0];
  lb_loop = this->InteriorStart[1];
  i = this->InteriorEnd[1];
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    out_, imnh, fparamsAugmented, imnhInds, pind, b_i, i1, b_firstInd, c_i,    \
    exitg1)

  for (int secondInd = lb_loop; secondInd <= i; secondInd++) {
    out_.set_size(out.size(0));
    b_i = pixelSub[0];
    i1 = pixelSub[1];
    for (b_firstInd = b_i; b_firstInd <= i1; b_firstInd++) {
      //  Process pixels with full neighborhood
      pind = ((secondInd - 1) * imageSize1) + b_firstInd;
      for (c_i = 0; c_i < 9; c_i++) {
        imnhInds[c_i] = imageNeighborLinearOffsets[c_i] + pind;
      }
      if (in.size(0) == 1) {
        imnh.set_size(1, 9);
        for (c_i = 0; c_i < 9; c_i++) {
          imnh[imnh.size(0) * c_i] = in[imnhInds[c_i] - 1];
        }
      } else {
        imnh.set_size(9, 1);
        for (c_i = 0; c_i < 9; c_i++) {
          imnh[c_i] = in[imnhInds[c_i] - 1];
        }
      }
      fparamsAugmented.pixel = in[pind - 1];
      out_[b_firstInd - 1] = fparams->bw[pind - 1];
      if (fparams->bw[pind - 1]) {
        //  Pixel has not already been set as non-max
        pind = 0;
        exitg1 = false;
        while ((!exitg1) && (pind <= ((imnh.size(0) * imnh.size(1)) - 1))) {
          if (imnh[pind] > fparamsAugmented.pixel) {
            //  Set pixel to zero if any neighbor is greater
            out_[b_firstInd - 1] = false;
            exitg1 = true;
          } else if (imnh[pind] == fparamsAugmented.pixel) {
            if (!fparams->bw[imnhInds[pind] - 1]) {
              //  Set pixel to zero if any equal neighbor is already set to zero
              out_[b_firstInd - 1] = false;
              exitg1 = true;
            } else {
              pind++;
            }
          } else {
            pind++;
          }
        }
      }
    }
    pind = out_.size(0);
    for (b_i = 0; b_i < pind; b_i++) {
      out[b_i + (out.size(0) * (secondInd - 1))] = out_[b_i];
    }
  }
  if (this->ProcessBorder) {
    float fparamsAugmented_pixel;
    float padValue_tmp;
    int b_pind;
    int b_secondInd;
    int firstInd;
    int secondDimExtents_idx_0;
    int secondDimExtents_idx_1;
    int u1;
    int x;
    int y;
    secondDimExtents_idx_1 = this->InteriorStart[1] - 1;
    padValue_tmp = static_cast<float>(this->PadValue);
    imageSize1 = this->ImageSize[0];
    u1 = this->ImageSize[0];
    if (imageSize1 < u1) {
      u1 = imageSize1;
    }
    imageSize1 = this->ImageSize[1];
    if (secondDimExtents_idx_1 >= imageSize1) {
      secondDimExtents_idx_1 = imageSize1;
    }
    for (b_secondInd = 1; b_secondInd <= secondDimExtents_idx_1;
         b_secondInd++) {
      for (firstInd = 1; firstInd <= u1; firstInd++) {
        //  Process pixels with partial neighborhood
        b_pind = (((b_secondInd - 1) * this->ImageSize[0]) + firstInd) - 1;
        for (i = 0; i < 9; i++) {
          imageNeighborLinearOffsets[i] =
              (this->ImageNeighborLinearOffsets[i] + b_pind) + 1;
        }
        pixelSub[0] = this->ImageSize[0];
        if (pixelSub[0] == 0) {
          imageSize1 = 0;
        } else {
          imageSize1 = b_pind - (pixelSub[0] * div_s32(b_pind, pixelSub[0]));
        }
        lb_loop = b_pind - imageSize1;
        if (pixelSub[0] == 0) {
          if (lb_loop == 0) {
            i = 0;
          } else if (lb_loop < 0) {
            i = MIN_int32_T;
          } else {
            i = MAX_int32_T;
          }
        } else if (pixelSub[0] == 1) {
          i = lb_loop;
        } else if (pixelSub[0] == -1) {
          i = -lb_loop;
        } else {
          if (lb_loop >= 0) {
            x = lb_loop;
          } else if (lb_loop == MIN_int32_T) {
            x = MIN_int32_T;
          } else {
            x = -lb_loop;
          }
          if (pixelSub[0] >= 0) {
            y = pixelSub[0];
          } else if (pixelSub[0] == MIN_int32_T) {
            y = MIN_int32_T;
          } else {
            y = -pixelSub[0];
          }
          i = div_s32(x, y);
          x -= i * y;
          if ((x > 0) && (x >= (asr_s32(y, 1U) + (y & 1)))) {
            i++;
          }
          if ((lb_loop < 0) != (pixelSub[0] < 0)) {
            i = -i;
          }
        }
        pixelSub[1] = i + 1;
        pixelSub[0] = imageSize1 + 1;
        for (imageSize1 = 0; imageSize1 < 2; imageSize1++) {
          for (lb_loop = 0; lb_loop < 9; lb_loop++) {
            imnhSubs[imageSize1][lb_loop] =
                this->NeighborSubscriptOffsets[imageSize1][lb_loop] +
                pixelSub[imageSize1];
          }
        }
        for (i = 0; i < 9; i++) {
          isInside[i] = true;
        }
        switch (static_cast<int>(this->Padding)) {
        case 1:
          lb_loop = 0;
          for (x = 0; x < 9; x++) {
            imageSize1 = 0;
            exitg1 = false;
            while ((!exitg1) && (imageSize1 < 2)) {
              if ((imnhSubs[imageSize1][x] < 1) ||
                  (imnhSubs[imageSize1][x] > this->ImageSize[imageSize1])) {
                isInside[x] = false;
                exitg1 = true;
              } else {
                imageSize1++;
              }
            }
            if (isInside[x]) {
              lb_loop++;
            }
          }
          b_imnhInds.set_size(lb_loop);
          imageSize1 = 0;
          for (i = 0; i < 9; i++) {
            if (isInside[i]) {
              b_imnhInds[imageSize1] = imageNeighborLinearOffsets[i];
              imageSize1++;
            }
          }
          break;
        case 2:
          b_imnhInds.set_size(9);
          for (x = 0; x < 9; x++) {
            b_imnhInds[x] = imageNeighborLinearOffsets[x];
            imageSize1 = 0;
            exitg1 = false;
            while ((!exitg1) && (imageSize1 < 2)) {
              if ((imnhSubs[imageSize1][x] < 1) ||
                  (imnhSubs[imageSize1][x] > this->ImageSize[imageSize1])) {
                isInside[x] = false;
                b_imnhInds[x] = 1;
                exitg1 = true;
              } else {
                imageSize1++;
              }
            }
          }
          break;
        case 3:
          b_imnhInds.set_size(9);
          for (y = 0; y < 9; y++) {
            b_imnhInds[y] = imageNeighborLinearOffsets[y];
          }
          for (x = 0; x < 9; x++) {
            y = imnhSubs[0][x];
            pixelSub[0] = y;
            if (y < 1) {
              isInside[x] = false;
              y = 1;
              pixelSub[0] = 1;
            }
            if (y > this->ImageSize[0]) {
              isInside[x] = false;
              pixelSub[0] = this->ImageSize[0];
            }
            y = imnhSubs[1][x];
            pixelSub[1] = y;
            if (y < 1) {
              isInside[x] = false;
              y = 1;
              pixelSub[1] = 1;
            }
            if (y > this->ImageSize[1]) {
              isInside[x] = false;
              pixelSub[1] = this->ImageSize[1];
            }
            if (!isInside[x]) {
              b_imnhInds[x] =
                  pixelSub[0] + ((pixelSub[1] - 1) * this->ImageSize[0]);
            }
          }
          break;
        case 4:
          b_imnhInds.set_size(9);
          for (y = 0; y < 9; y++) {
            b_imnhInds[y] = imageNeighborLinearOffsets[y];
          }
          for (x = 0; x < 9; x++) {
            y = imnhSubs[0][x];
            pixelSub[0] = y;
            if (y < 1) {
              isInside[x] = false;
              y += this->ImageSize[0] * 2;
              pixelSub[0] = y;
            }
            if (y > this->ImageSize[0]) {
              isInside[x] = false;
              y = ((this->ImageSize[0] * 2) - y) + 1;
              pixelSub[0] = y;
            }
            y = imnhSubs[1][x];
            pixelSub[1] = y;
            if (y < 1) {
              isInside[x] = false;
              y += this->ImageSize[1] * 2;
              pixelSub[1] = y;
            }
            if (y > this->ImageSize[1]) {
              isInside[x] = false;
              y = ((this->ImageSize[1] * 2) - y) + 1;
              pixelSub[1] = y;
            }
            if (!isInside[x]) {
              b_imnhInds[x] =
                  pixelSub[0] + ((pixelSub[1] - 1) * this->ImageSize[0]);
            }
          }
          break;
        default:
          /* no actions */
          break;
        }
        if (in.size(0) == 1) {
          imageSize1 = b_imnhInds.size(0);
          b_imnh.set_size(1, b_imnhInds.size(0));
          for (y = 0; y < imageSize1; y++) {
            b_imnh[b_imnh.size(0) * y] = in[b_imnhInds[y] - 1];
          }
        } else {
          imageSize1 = b_imnhInds.size(0);
          b_in.set_size(b_imnhInds.size(0));
          for (y = 0; y < imageSize1; y++) {
            b_in[y] = in[b_imnhInds[y] - 1];
          }
          imageSize1 = b_imnhInds.size(0);
          b_imnh.set_size(b_imnhInds.size(0), 1);
          for (y = 0; y < 1; y++) {
            for (lb_loop = 0; lb_loop < imageSize1; lb_loop++) {
              b_imnh[lb_loop] = b_in[lb_loop];
            }
          }
        }
        if (this->Padding == 2.0) {
          lb_loop = 0;
          for (i = 0; i < 9; i++) {
            if (!isInside[i]) {
              lb_loop++;
            }
          }
          r.set_size(lb_loop);
          imageSize1 = 0;
          for (i = 0; i < 9; i++) {
            if (!isInside[i]) {
              r[imageSize1] = static_cast<signed char>(i + 1);
              imageSize1++;
            }
          }
          imageSize1 = r.size(0);
          for (y = 0; y < imageSize1; y++) {
            b_imnh[(static_cast<int>(r[y])) - 1] = padValue_tmp;
          }
        }
        fparamsAugmented_pixel = in[b_pind];
        out[b_pind] = fparams->bw[b_pind];
        if (fparams->bw[b_pind]) {
          //  Pixel has not already been set as non-max
          imageSize1 = 0;
          exitg1 = false;
          while ((!exitg1) &&
                 (imageSize1 <= ((b_imnh.size(0) * b_imnh.size(1)) - 1))) {
            if (b_imnh[imageSize1] > fparamsAugmented_pixel) {
              //  Set pixel to zero if any neighbor is greater
              out[b_pind] = false;
              exitg1 = true;
            } else if (b_imnh[imageSize1] == fparamsAugmented_pixel) {
              if (!fparams->bw[b_imnhInds[imageSize1] - 1]) {
                //  Set pixel to zero if any equal neighbor is already set to
                //  zero
                out[b_pind] = false;
                exitg1 = true;
              } else {
                imageSize1++;
              }
            } else {
              imageSize1++;
            }
          }
        }
      }
    }
    secondDimExtents_idx_0 = this->InteriorEnd[1] + 1;
    secondDimExtents_idx_1 = this->ImageSize[1];
    if (secondDimExtents_idx_0 < 1) {
      secondDimExtents_idx_0 = 1;
    }
    imageSize1 = this->ImageSize[1];
    if (secondDimExtents_idx_1 >= imageSize1) {
      secondDimExtents_idx_1 = imageSize1;
    }
    for (b_secondInd = secondDimExtents_idx_0;
         b_secondInd <= secondDimExtents_idx_1; b_secondInd++) {
      for (firstInd = 1; firstInd <= u1; firstInd++) {
        //  Process pixels with partial neighborhood
        b_pind = (((b_secondInd - 1) * this->ImageSize[0]) + firstInd) - 1;
        for (i = 0; i < 9; i++) {
          imageNeighborLinearOffsets[i] =
              (this->ImageNeighborLinearOffsets[i] + b_pind) + 1;
        }
        pixelSub[0] = this->ImageSize[0];
        if (pixelSub[0] == 0) {
          imageSize1 = 0;
        } else {
          imageSize1 = b_pind - (pixelSub[0] * div_s32(b_pind, pixelSub[0]));
        }
        lb_loop = b_pind - imageSize1;
        if (pixelSub[0] == 0) {
          if (lb_loop == 0) {
            i = 0;
          } else if (lb_loop < 0) {
            i = MIN_int32_T;
          } else {
            i = MAX_int32_T;
          }
        } else if (pixelSub[0] == 1) {
          i = lb_loop;
        } else if (pixelSub[0] == -1) {
          i = -lb_loop;
        } else {
          if (lb_loop >= 0) {
            x = lb_loop;
          } else if (lb_loop == MIN_int32_T) {
            x = MIN_int32_T;
          } else {
            x = -lb_loop;
          }
          if (pixelSub[0] >= 0) {
            y = pixelSub[0];
          } else if (pixelSub[0] == MIN_int32_T) {
            y = MIN_int32_T;
          } else {
            y = -pixelSub[0];
          }
          i = div_s32(x, y);
          x -= i * y;
          if ((x > 0) && (x >= (asr_s32(y, 1U) + (y & 1)))) {
            i++;
          }
          if ((lb_loop < 0) != (pixelSub[0] < 0)) {
            i = -i;
          }
        }
        pixelSub[1] = i + 1;
        pixelSub[0] = imageSize1 + 1;
        for (imageSize1 = 0; imageSize1 < 2; imageSize1++) {
          for (lb_loop = 0; lb_loop < 9; lb_loop++) {
            imnhSubs[imageSize1][lb_loop] =
                this->NeighborSubscriptOffsets[imageSize1][lb_loop] +
                pixelSub[imageSize1];
          }
        }
        for (i = 0; i < 9; i++) {
          isInside[i] = true;
        }
        switch (static_cast<int>(this->Padding)) {
        case 1:
          lb_loop = 0;
          for (x = 0; x < 9; x++) {
            imageSize1 = 0;
            exitg1 = false;
            while ((!exitg1) && (imageSize1 < 2)) {
              if ((imnhSubs[imageSize1][x] < 1) ||
                  (imnhSubs[imageSize1][x] > this->ImageSize[imageSize1])) {
                isInside[x] = false;
                exitg1 = true;
              } else {
                imageSize1++;
              }
            }
            if (isInside[x]) {
              lb_loop++;
            }
          }
          c_imnhInds.set_size(lb_loop);
          imageSize1 = 0;
          for (i = 0; i < 9; i++) {
            if (isInside[i]) {
              c_imnhInds[imageSize1] = imageNeighborLinearOffsets[i];
              imageSize1++;
            }
          }
          break;
        case 2:
          c_imnhInds.set_size(9);
          for (x = 0; x < 9; x++) {
            c_imnhInds[x] = imageNeighborLinearOffsets[x];
            imageSize1 = 0;
            exitg1 = false;
            while ((!exitg1) && (imageSize1 < 2)) {
              if ((imnhSubs[imageSize1][x] < 1) ||
                  (imnhSubs[imageSize1][x] > this->ImageSize[imageSize1])) {
                isInside[x] = false;
                c_imnhInds[x] = 1;
                exitg1 = true;
              } else {
                imageSize1++;
              }
            }
          }
          break;
        case 3:
          c_imnhInds.set_size(9);
          for (y = 0; y < 9; y++) {
            c_imnhInds[y] = imageNeighborLinearOffsets[y];
          }
          for (x = 0; x < 9; x++) {
            y = imnhSubs[0][x];
            pixelSub[0] = y;
            if (y < 1) {
              isInside[x] = false;
              y = 1;
              pixelSub[0] = 1;
            }
            if (y > this->ImageSize[0]) {
              isInside[x] = false;
              pixelSub[0] = this->ImageSize[0];
            }
            y = imnhSubs[1][x];
            pixelSub[1] = y;
            if (y < 1) {
              isInside[x] = false;
              y = 1;
              pixelSub[1] = 1;
            }
            if (y > this->ImageSize[1]) {
              isInside[x] = false;
              pixelSub[1] = this->ImageSize[1];
            }
            if (!isInside[x]) {
              c_imnhInds[x] =
                  pixelSub[0] + ((pixelSub[1] - 1) * this->ImageSize[0]);
            }
          }
          break;
        case 4:
          c_imnhInds.set_size(9);
          for (y = 0; y < 9; y++) {
            c_imnhInds[y] = imageNeighborLinearOffsets[y];
          }
          for (x = 0; x < 9; x++) {
            y = imnhSubs[0][x];
            pixelSub[0] = y;
            if (y < 1) {
              isInside[x] = false;
              y += this->ImageSize[0] * 2;
              pixelSub[0] = y;
            }
            if (y > this->ImageSize[0]) {
              isInside[x] = false;
              y = ((this->ImageSize[0] * 2) - y) + 1;
              pixelSub[0] = y;
            }
            y = imnhSubs[1][x];
            pixelSub[1] = y;
            if (y < 1) {
              isInside[x] = false;
              y += this->ImageSize[1] * 2;
              pixelSub[1] = y;
            }
            if (y > this->ImageSize[1]) {
              isInside[x] = false;
              y = ((this->ImageSize[1] * 2) - y) + 1;
              pixelSub[1] = y;
            }
            if (!isInside[x]) {
              c_imnhInds[x] =
                  pixelSub[0] + ((pixelSub[1] - 1) * this->ImageSize[0]);
            }
          }
          break;
        default:
          /* no actions */
          break;
        }
        if (in.size(0) == 1) {
          imageSize1 = c_imnhInds.size(0);
          b_imnh.set_size(1, c_imnhInds.size(0));
          for (y = 0; y < imageSize1; y++) {
            b_imnh[b_imnh.size(0) * y] = in[c_imnhInds[y] - 1];
          }
        } else {
          imageSize1 = c_imnhInds.size(0);
          b_in.set_size(c_imnhInds.size(0));
          for (y = 0; y < imageSize1; y++) {
            b_in[y] = in[c_imnhInds[y] - 1];
          }
          imageSize1 = c_imnhInds.size(0);
          b_imnh.set_size(c_imnhInds.size(0), 1);
          for (y = 0; y < 1; y++) {
            for (lb_loop = 0; lb_loop < imageSize1; lb_loop++) {
              b_imnh[lb_loop] = b_in[lb_loop];
            }
          }
        }
        if (this->Padding == 2.0) {
          lb_loop = 0;
          for (i = 0; i < 9; i++) {
            if (!isInside[i]) {
              lb_loop++;
            }
          }
          r1.set_size(lb_loop);
          imageSize1 = 0;
          for (i = 0; i < 9; i++) {
            if (!isInside[i]) {
              r1[imageSize1] = static_cast<signed char>(i + 1);
              imageSize1++;
            }
          }
          imageSize1 = r1.size(0);
          for (y = 0; y < imageSize1; y++) {
            b_imnh[(static_cast<int>(r1[y])) - 1] = padValue_tmp;
          }
        }
        fparamsAugmented_pixel = in[b_pind];
        out[b_pind] = fparams->bw[b_pind];
        if (fparams->bw[b_pind]) {
          //  Pixel has not already been set as non-max
          imageSize1 = 0;
          exitg1 = false;
          while ((!exitg1) &&
                 (imageSize1 <= ((b_imnh.size(0) * b_imnh.size(1)) - 1))) {
            if (b_imnh[imageSize1] > fparamsAugmented_pixel) {
              //  Set pixel to zero if any neighbor is greater
              out[b_pind] = false;
              exitg1 = true;
            } else if (b_imnh[imageSize1] == fparamsAugmented_pixel) {
              if (!fparams->bw[c_imnhInds[imageSize1] - 1]) {
                //  Set pixel to zero if any equal neighbor is already set to
                //  zero
                out[b_pind] = false;
                exitg1 = true;
              } else {
                imageSize1++;
              }
            } else {
              imageSize1++;
            }
          }
        }
      }
    }
    secondDimExtents_idx_1 = this->InteriorStart[0] - 1;
    u1 = this->ImageSize[0];
    if (secondDimExtents_idx_1 >= u1) {
      secondDimExtents_idx_1 = u1;
    }
    imageSize1 = this->ImageSize[1];
    u1 = this->ImageSize[1];
    if (imageSize1 < u1) {
      u1 = imageSize1;
    }
    for (b_secondInd = 1; b_secondInd <= u1; b_secondInd++) {
      for (firstInd = 1; firstInd <= secondDimExtents_idx_1; firstInd++) {
        //  Process pixels with partial neighborhood
        b_pind = (((b_secondInd - 1) * this->ImageSize[0]) + firstInd) - 1;
        for (i = 0; i < 9; i++) {
          imageNeighborLinearOffsets[i] =
              (this->ImageNeighborLinearOffsets[i] + b_pind) + 1;
        }
        pixelSub[0] = this->ImageSize[0];
        if (pixelSub[0] == 0) {
          imageSize1 = 0;
        } else {
          imageSize1 = b_pind - (pixelSub[0] * div_s32(b_pind, pixelSub[0]));
        }
        lb_loop = b_pind - imageSize1;
        if (pixelSub[0] == 0) {
          if (lb_loop == 0) {
            i = 0;
          } else if (lb_loop < 0) {
            i = MIN_int32_T;
          } else {
            i = MAX_int32_T;
          }
        } else if (pixelSub[0] == 1) {
          i = lb_loop;
        } else if (pixelSub[0] == -1) {
          i = -lb_loop;
        } else {
          if (lb_loop >= 0) {
            x = lb_loop;
          } else if (lb_loop == MIN_int32_T) {
            x = MIN_int32_T;
          } else {
            x = -lb_loop;
          }
          if (pixelSub[0] >= 0) {
            y = pixelSub[0];
          } else if (pixelSub[0] == MIN_int32_T) {
            y = MIN_int32_T;
          } else {
            y = -pixelSub[0];
          }
          i = div_s32(x, y);
          x -= i * y;
          if ((x > 0) && (x >= (asr_s32(y, 1U) + (y & 1)))) {
            i++;
          }
          if ((lb_loop < 0) != (pixelSub[0] < 0)) {
            i = -i;
          }
        }
        pixelSub[1] = i + 1;
        pixelSub[0] = imageSize1 + 1;
        for (imageSize1 = 0; imageSize1 < 2; imageSize1++) {
          for (lb_loop = 0; lb_loop < 9; lb_loop++) {
            imnhSubs[imageSize1][lb_loop] =
                this->NeighborSubscriptOffsets[imageSize1][lb_loop] +
                pixelSub[imageSize1];
          }
        }
        for (i = 0; i < 9; i++) {
          isInside[i] = true;
        }
        switch (static_cast<int>(this->Padding)) {
        case 1:
          lb_loop = 0;
          for (x = 0; x < 9; x++) {
            imageSize1 = 0;
            exitg1 = false;
            while ((!exitg1) && (imageSize1 < 2)) {
              if ((imnhSubs[imageSize1][x] < 1) ||
                  (imnhSubs[imageSize1][x] > this->ImageSize[imageSize1])) {
                isInside[x] = false;
                exitg1 = true;
              } else {
                imageSize1++;
              }
            }
            if (isInside[x]) {
              lb_loop++;
            }
          }
          d_imnhInds.set_size(lb_loop);
          imageSize1 = 0;
          for (i = 0; i < 9; i++) {
            if (isInside[i]) {
              d_imnhInds[imageSize1] = imageNeighborLinearOffsets[i];
              imageSize1++;
            }
          }
          break;
        case 2:
          d_imnhInds.set_size(9);
          for (x = 0; x < 9; x++) {
            d_imnhInds[x] = imageNeighborLinearOffsets[x];
            imageSize1 = 0;
            exitg1 = false;
            while ((!exitg1) && (imageSize1 < 2)) {
              if ((imnhSubs[imageSize1][x] < 1) ||
                  (imnhSubs[imageSize1][x] > this->ImageSize[imageSize1])) {
                isInside[x] = false;
                d_imnhInds[x] = 1;
                exitg1 = true;
              } else {
                imageSize1++;
              }
            }
          }
          break;
        case 3:
          d_imnhInds.set_size(9);
          for (y = 0; y < 9; y++) {
            d_imnhInds[y] = imageNeighborLinearOffsets[y];
          }
          for (x = 0; x < 9; x++) {
            y = imnhSubs[0][x];
            pixelSub[0] = y;
            if (y < 1) {
              isInside[x] = false;
              y = 1;
              pixelSub[0] = 1;
            }
            if (y > this->ImageSize[0]) {
              isInside[x] = false;
              pixelSub[0] = this->ImageSize[0];
            }
            y = imnhSubs[1][x];
            pixelSub[1] = y;
            if (y < 1) {
              isInside[x] = false;
              y = 1;
              pixelSub[1] = 1;
            }
            if (y > this->ImageSize[1]) {
              isInside[x] = false;
              pixelSub[1] = this->ImageSize[1];
            }
            if (!isInside[x]) {
              d_imnhInds[x] =
                  pixelSub[0] + ((pixelSub[1] - 1) * this->ImageSize[0]);
            }
          }
          break;
        case 4:
          d_imnhInds.set_size(9);
          for (y = 0; y < 9; y++) {
            d_imnhInds[y] = imageNeighborLinearOffsets[y];
          }
          for (x = 0; x < 9; x++) {
            y = imnhSubs[0][x];
            pixelSub[0] = y;
            if (y < 1) {
              isInside[x] = false;
              y += this->ImageSize[0] * 2;
              pixelSub[0] = y;
            }
            if (y > this->ImageSize[0]) {
              isInside[x] = false;
              y = ((this->ImageSize[0] * 2) - y) + 1;
              pixelSub[0] = y;
            }
            y = imnhSubs[1][x];
            pixelSub[1] = y;
            if (y < 1) {
              isInside[x] = false;
              y += this->ImageSize[1] * 2;
              pixelSub[1] = y;
            }
            if (y > this->ImageSize[1]) {
              isInside[x] = false;
              y = ((this->ImageSize[1] * 2) - y) + 1;
              pixelSub[1] = y;
            }
            if (!isInside[x]) {
              d_imnhInds[x] =
                  pixelSub[0] + ((pixelSub[1] - 1) * this->ImageSize[0]);
            }
          }
          break;
        default:
          /* no actions */
          break;
        }
        if (in.size(0) == 1) {
          imageSize1 = d_imnhInds.size(0);
          b_imnh.set_size(1, d_imnhInds.size(0));
          for (y = 0; y < imageSize1; y++) {
            b_imnh[b_imnh.size(0) * y] = in[d_imnhInds[y] - 1];
          }
        } else {
          imageSize1 = d_imnhInds.size(0);
          b_in.set_size(d_imnhInds.size(0));
          for (y = 0; y < imageSize1; y++) {
            b_in[y] = in[d_imnhInds[y] - 1];
          }
          imageSize1 = d_imnhInds.size(0);
          b_imnh.set_size(d_imnhInds.size(0), 1);
          for (y = 0; y < 1; y++) {
            for (lb_loop = 0; lb_loop < imageSize1; lb_loop++) {
              b_imnh[lb_loop] = b_in[lb_loop];
            }
          }
        }
        if (this->Padding == 2.0) {
          lb_loop = 0;
          for (i = 0; i < 9; i++) {
            if (!isInside[i]) {
              lb_loop++;
            }
          }
          r2.set_size(lb_loop);
          imageSize1 = 0;
          for (i = 0; i < 9; i++) {
            if (!isInside[i]) {
              r2[imageSize1] = static_cast<signed char>(i + 1);
              imageSize1++;
            }
          }
          imageSize1 = r2.size(0);
          for (y = 0; y < imageSize1; y++) {
            b_imnh[(static_cast<int>(r2[y])) - 1] = padValue_tmp;
          }
        }
        fparamsAugmented_pixel = in[b_pind];
        out[b_pind] = fparams->bw[b_pind];
        if (fparams->bw[b_pind]) {
          //  Pixel has not already been set as non-max
          imageSize1 = 0;
          exitg1 = false;
          while ((!exitg1) &&
                 (imageSize1 <= ((b_imnh.size(0) * b_imnh.size(1)) - 1))) {
            if (b_imnh[imageSize1] > fparamsAugmented_pixel) {
              //  Set pixel to zero if any neighbor is greater
              out[b_pind] = false;
              exitg1 = true;
            } else if (b_imnh[imageSize1] == fparamsAugmented_pixel) {
              if (!fparams->bw[d_imnhInds[imageSize1] - 1]) {
                //  Set pixel to zero if any equal neighbor is already set to
                //  zero
                out[b_pind] = false;
                exitg1 = true;
              } else {
                imageSize1++;
              }
            } else {
              imageSize1++;
            }
          }
        }
      }
    }
    secondDimExtents_idx_0 = this->InteriorEnd[0] + 1;
    secondDimExtents_idx_1 = this->ImageSize[0];
    if (secondDimExtents_idx_0 < 1) {
      secondDimExtents_idx_0 = 1;
    }
    imageSize1 = this->ImageSize[0];
    if (secondDimExtents_idx_1 >= imageSize1) {
      secondDimExtents_idx_1 = imageSize1;
    }
    for (b_secondInd = 1; b_secondInd <= u1; b_secondInd++) {
      for (firstInd = secondDimExtents_idx_0;
           firstInd <= secondDimExtents_idx_1; firstInd++) {
        //  Process pixels with partial neighborhood
        b_pind = (((b_secondInd - 1) * this->ImageSize[0]) + firstInd) - 1;
        for (i = 0; i < 9; i++) {
          imageNeighborLinearOffsets[i] =
              (this->ImageNeighborLinearOffsets[i] + b_pind) + 1;
        }
        pixelSub[0] = this->ImageSize[0];
        if (pixelSub[0] == 0) {
          imageSize1 = 0;
        } else {
          imageSize1 = b_pind - (pixelSub[0] * div_s32(b_pind, pixelSub[0]));
        }
        lb_loop = b_pind - imageSize1;
        if (pixelSub[0] == 0) {
          if (lb_loop == 0) {
            i = 0;
          } else if (lb_loop < 0) {
            i = MIN_int32_T;
          } else {
            i = MAX_int32_T;
          }
        } else if (pixelSub[0] == 1) {
          i = lb_loop;
        } else if (pixelSub[0] == -1) {
          i = -lb_loop;
        } else {
          if (lb_loop >= 0) {
            x = lb_loop;
          } else if (lb_loop == MIN_int32_T) {
            x = MIN_int32_T;
          } else {
            x = -lb_loop;
          }
          if (pixelSub[0] >= 0) {
            y = pixelSub[0];
          } else if (pixelSub[0] == MIN_int32_T) {
            y = MIN_int32_T;
          } else {
            y = -pixelSub[0];
          }
          i = div_s32(x, y);
          x -= i * y;
          if ((x > 0) && (x >= (asr_s32(y, 1U) + (y & 1)))) {
            i++;
          }
          if ((lb_loop < 0) != (pixelSub[0] < 0)) {
            i = -i;
          }
        }
        pixelSub[1] = i + 1;
        pixelSub[0] = imageSize1 + 1;
        for (imageSize1 = 0; imageSize1 < 2; imageSize1++) {
          for (lb_loop = 0; lb_loop < 9; lb_loop++) {
            imnhSubs[imageSize1][lb_loop] =
                this->NeighborSubscriptOffsets[imageSize1][lb_loop] +
                pixelSub[imageSize1];
          }
        }
        for (i = 0; i < 9; i++) {
          isInside[i] = true;
        }
        switch (static_cast<int>(this->Padding)) {
        case 1:
          lb_loop = 0;
          for (x = 0; x < 9; x++) {
            imageSize1 = 0;
            exitg1 = false;
            while ((!exitg1) && (imageSize1 < 2)) {
              if ((imnhSubs[imageSize1][x] < 1) ||
                  (imnhSubs[imageSize1][x] > this->ImageSize[imageSize1])) {
                isInside[x] = false;
                exitg1 = true;
              } else {
                imageSize1++;
              }
            }
            if (isInside[x]) {
              lb_loop++;
            }
          }
          e_imnhInds.set_size(lb_loop);
          imageSize1 = 0;
          for (i = 0; i < 9; i++) {
            if (isInside[i]) {
              e_imnhInds[imageSize1] = imageNeighborLinearOffsets[i];
              imageSize1++;
            }
          }
          break;
        case 2:
          e_imnhInds.set_size(9);
          for (x = 0; x < 9; x++) {
            e_imnhInds[x] = imageNeighborLinearOffsets[x];
            imageSize1 = 0;
            exitg1 = false;
            while ((!exitg1) && (imageSize1 < 2)) {
              if ((imnhSubs[imageSize1][x] < 1) ||
                  (imnhSubs[imageSize1][x] > this->ImageSize[imageSize1])) {
                isInside[x] = false;
                e_imnhInds[x] = 1;
                exitg1 = true;
              } else {
                imageSize1++;
              }
            }
          }
          break;
        case 3:
          e_imnhInds.set_size(9);
          for (y = 0; y < 9; y++) {
            e_imnhInds[y] = imageNeighborLinearOffsets[y];
          }
          for (x = 0; x < 9; x++) {
            y = imnhSubs[0][x];
            pixelSub[0] = y;
            if (y < 1) {
              isInside[x] = false;
              y = 1;
              pixelSub[0] = 1;
            }
            if (y > this->ImageSize[0]) {
              isInside[x] = false;
              pixelSub[0] = this->ImageSize[0];
            }
            y = imnhSubs[1][x];
            pixelSub[1] = y;
            if (y < 1) {
              isInside[x] = false;
              y = 1;
              pixelSub[1] = 1;
            }
            if (y > this->ImageSize[1]) {
              isInside[x] = false;
              pixelSub[1] = this->ImageSize[1];
            }
            if (!isInside[x]) {
              e_imnhInds[x] =
                  pixelSub[0] + ((pixelSub[1] - 1) * this->ImageSize[0]);
            }
          }
          break;
        case 4:
          e_imnhInds.set_size(9);
          for (y = 0; y < 9; y++) {
            e_imnhInds[y] = imageNeighborLinearOffsets[y];
          }
          for (x = 0; x < 9; x++) {
            y = imnhSubs[0][x];
            pixelSub[0] = y;
            if (y < 1) {
              isInside[x] = false;
              y += this->ImageSize[0] * 2;
              pixelSub[0] = y;
            }
            if (y > this->ImageSize[0]) {
              isInside[x] = false;
              y = ((this->ImageSize[0] * 2) - y) + 1;
              pixelSub[0] = y;
            }
            y = imnhSubs[1][x];
            pixelSub[1] = y;
            if (y < 1) {
              isInside[x] = false;
              y += this->ImageSize[1] * 2;
              pixelSub[1] = y;
            }
            if (y > this->ImageSize[1]) {
              isInside[x] = false;
              y = ((this->ImageSize[1] * 2) - y) + 1;
              pixelSub[1] = y;
            }
            if (!isInside[x]) {
              e_imnhInds[x] =
                  pixelSub[0] + ((pixelSub[1] - 1) * this->ImageSize[0]);
            }
          }
          break;
        default:
          /* no actions */
          break;
        }
        if (in.size(0) == 1) {
          imageSize1 = e_imnhInds.size(0);
          b_imnh.set_size(1, e_imnhInds.size(0));
          for (y = 0; y < imageSize1; y++) {
            b_imnh[b_imnh.size(0) * y] = in[e_imnhInds[y] - 1];
          }
        } else {
          imageSize1 = e_imnhInds.size(0);
          b_in.set_size(e_imnhInds.size(0));
          for (y = 0; y < imageSize1; y++) {
            b_in[y] = in[e_imnhInds[y] - 1];
          }
          imageSize1 = e_imnhInds.size(0);
          b_imnh.set_size(e_imnhInds.size(0), 1);
          for (y = 0; y < 1; y++) {
            for (lb_loop = 0; lb_loop < imageSize1; lb_loop++) {
              b_imnh[lb_loop] = b_in[lb_loop];
            }
          }
        }
        if (this->Padding == 2.0) {
          lb_loop = 0;
          for (i = 0; i < 9; i++) {
            if (!isInside[i]) {
              lb_loop++;
            }
          }
          r3.set_size(lb_loop);
          imageSize1 = 0;
          for (i = 0; i < 9; i++) {
            if (!isInside[i]) {
              r3[imageSize1] = static_cast<signed char>(i + 1);
              imageSize1++;
            }
          }
          imageSize1 = r3.size(0);
          for (y = 0; y < imageSize1; y++) {
            b_imnh[(static_cast<int>(r3[y])) - 1] = padValue_tmp;
          }
        }
        fparamsAugmented_pixel = in[b_pind];
        out[b_pind] = fparams->bw[b_pind];
        if (fparams->bw[b_pind]) {
          //  Pixel has not already been set as non-max
          imageSize1 = 0;
          exitg1 = false;
          while ((!exitg1) &&
                 (imageSize1 <= ((b_imnh.size(0) * b_imnh.size(1)) - 1))) {
            if (b_imnh[imageSize1] > fparamsAugmented_pixel) {
              //  Set pixel to zero if any neighbor is greater
              out[b_pind] = false;
              exitg1 = true;
            } else if (b_imnh[imageSize1] == fparamsAugmented_pixel) {
              if (!fparams->bw[e_imnhInds[imageSize1] - 1]) {
                //  Set pixel to zero if any equal neighbor is already set to
                //  zero
                out[b_pind] = false;
                exitg1 = true;
              } else {
                imageSize1++;
              }
            } else {
              imageSize1++;
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
