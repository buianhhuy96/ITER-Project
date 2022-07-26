#pragma once
#ifndef ESTIMATEPOSEREFLECTIVE_H
#define ESTIMATEPOSEREFLECTIVE_H

// Include Files
#include "common_definitions.h"

#include "./library/preprocessImages.h"
#include "./library/RRDetectionKnuckle.h"
#include "./library/estimateKnucklePose.h"

#include "pitagDetector.h"

namespace estimatePoseReflective_ns {

const double MIN_AREA_L = 1;
const double THRESHOLD_DELTA_L = 0.0001;
const double THRESHOLD_DELTA_H = 100;

typedef ITER::struct2_T KnuckleParams;

struct paramInfo{
	std::string name;
	double min;
	double max;
};

const std::map<int, char const*> API_error_codes = {
		{1,"Error 0001: Function only supports gray or RGB images"},
		{2,"Error 0002: RobotPose is not a homogeneous transformation matrix."},
		{3,"Error 0003: HandEyeEstimate is not a homogeneous transformation matrix."},
		{4,"Error 0004: Invalid syntax/structure of json file: "},
		{5,"Error 0005: World points not found in constellation."},
		{6,"Error 0006: Invalid size of world points."},
		{7,"Error 0007: Algorithm parameters missings: "},
		{8,"Error 0008: Algorithm parameters out of valid range: "},
		{9,"Error 0009: Calculation results contain inf or nan."},
		
		{101,"Error 0101: Cannot detect valid pattern in the image."},
		{201,"Error 0201: Number of detected markers is less than minimum."},
		{202,"Error 0202: Number of detected markers and world points are different."},
		{203,"Error 0202: Could not find enough inliers in detechted marker points and world points."}


};

const std::vector<paramInfo> algorithmParamInfo = {
			{ "minArea", 1, 10 },
			{ "maxArea", 10, 1000 },
			{ "ThresholdDelta", 0.1, 5 } };



}
void estimatePoseReflective(const imageWrap &inputImage, const double4x4 &robotPose,
		const std::string &constellation, const intrinsicParameters &camParam,
		const double4x4 &handEyeCalibration,
		const std::string &algorithmParameters,

		std::vector<double2> &targetLocImage2D, double4x4 &targetPoseCamera,
				double4x4 &targetPoseRobot, double &confidence);

#endif
