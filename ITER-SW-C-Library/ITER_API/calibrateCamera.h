#pragma once
#ifndef CALIBRATECAMERA_H
#define CALIBRATECAMERA_H

// Include Files
#include <map>
#include "common_definitions.h"
#include "./library/preprocessImages.h"
#include "./library/calibrateOneCamera.h"

namespace calibrateCamera_ns {

const int NUM_IMG_MIN = 3;
/* API Error List */
const std::map<int, char const*> API_error_codes = {
		{1,"Error 0001: Number of images is less than requirement."},
		{2,"Error 0002: Function only supports gray or RGB images."},
		{3,"Error 0003: There are images with different sizes."},
		{4,"Error 0004: Square size is not in valid range."},
		{5,"Error 0005: Board size is not valid (not asymmetric or negative)."},
		{6,"Error 0006: Calculation results contain inf or nan."},
		{101,"Error 0101: Cannot detect any checkerboard in images."},
		{201,"Error 0201: Not enough valid homographies."},
		{301,"Error 0301: Detected complex number in camera intrinsic matrix."}


};

void validateInputs(const std::vector<imageWrap> &images,
				      const calibrationPatternParameters &calibPatternParam);
}
void calibrateCamera(const std::vector<imageWrap> &calibrationImages,
				      const calibrationPatternParameters &calibPatternParam,
					  intrinsicParameters &camParam);

#endif
