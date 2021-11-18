#pragma once
#ifndef CALIBRATEHANDEYE_H
#define CALIBRATEHANDEYE_H

// Include Files
#include "common_definitions.h"

#include "./library/preprocessImages.h"
#include "./library/readRobotPoses.h"
#include "./library/ComputeCamExtrinsics.h"
#include "./library/computeErrors.h"
#include "./library/HandeyeShah.h"

void convertDataType4RobotPoses(const std::vector<double4x4> &robot_pose_vector,
                             coder::array<double, 3U> &robot_pose_array);

void validateInputs(const std::vector<imageWrap> &images,
                      const std::vector<double4x4> &robotPosesVec,
                      const calibrationPatternParameters &calibPatternParam,
                      const intrinsicParameters &camParam);

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
