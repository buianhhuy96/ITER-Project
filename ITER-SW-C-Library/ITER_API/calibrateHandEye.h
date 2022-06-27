#pragma once
#ifndef CALIBRATEHANDEYE_H
#define CALIBRATEHANDEYE_H

// Include Files
#include <map>
#include "common_definitions.h"
#include "./library/preprocessImages.h"
#include "./library/readRobotPoses.h"
#include "./library/ComputeCamExtrinsics.h"
#include "./library/computeErrors.h"
#include "./library/HandeyeShah.h"

namespace calibrateHandEye_ns {

const int NUM_IMG_MIN = 3;
	/* API Error List */
const std::map<int, char const*> API_error_codes = {
		{1,"Error 0001: Number of images is less than requirement"},
		{2,"Error 0002: Function only supports gray or RGB images"},
		{3,"Error 0003: There are images with different sizes."},
		{4,"Error 0004: Square size is not in valid range."},
		{5,"Error 0005: Detect NaN in camera parameters."},
		{6,"Error 0006: Difference in number of images and robot poses can cause wrong calculation."},
		{7,"Error 0007: Robot pose is NaN."},
		{8,"Error 0008: Calculation results contain inf or nan."},
		{101,"Error 0101: Cannot detect any checkerboard in images."},
		{102,"Error 0102: Detected different size of checkerboards."},
		{201,"Error 0201: Not enough valid homographies."}
};

void convertDataType4RobotPoses(const std::vector<double4x4> &robot_pose_vector,
                             coder::array<double, 3U> &robot_pose_array);

void validateInputs(const std::vector<imageWrap> &images,
                      const std::vector<double4x4> &robotPosesVec,
                      const calibrationPatternParameters &calibPatternParam,
                      const intrinsicParameters &camParam);
}
void calibrateHandEye(const std::vector<imageWrap> &images,
					  const std::vector<double4x4> &robotPosesVec,
				      const calibrationPatternParameters &calibPatternParam,
					  const intrinsicParameters &camParam,

					  double4x4 &handEyeCalibration,
					  int &usedImages,
					  double &reprojectionError,
					  double &rotationError,
					  double &translationError);

#endif
