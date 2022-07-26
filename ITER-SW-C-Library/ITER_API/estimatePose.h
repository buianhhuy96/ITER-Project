#pragma once
#ifndef ESTIMATEPOSE_H
#define ESTIMATEPOSE_H

// Include Files
#include "common_definitions.h"

#include "./library/preprocessImages.h"
#include "./library/estimatePitagPose.h"

#include "pitagDetector.h"




namespace estimatePose_ns {

const int NUM_POINTS = 12;

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
		{5,"Error 0005: Algorithm parameters missing: "},
		{6,"Error 0006: Algorithm parameters out of valid range: "},
		{7,"Error 0007: API supports only 1 tag at a time."},
		{8,"Error 0008: \"PI\" tag missing: "},
		{9,"Error 0009: Calculation results contain inf or nan."},
		
		{101,"Error 0101: No valid fiducials."},
		{102,"Error 0102: No valid tags detected."}


};

const std::map<std::string, std::vector<paramInfo>> algorithmParamInfo = {
		{ "Blob_det",{
			{ "delta", 1, 10 },
			{ "min_area_pixel", 10, 1000 },
			{ "max_area_percentage", 0.1, 5 },
			{ "max_variation", 0.01, 0.25 } } },
		{ "Blob_filter", {
			{ "min_aspect_ratio", 0.1, 1 },
			{ "max_aspect_ratio", 1, 5 },
			{ "solidity", 0.1, 1 },
			{ "min_extent", 0, 1 },
			{ "max_extent", 0, 1 },
			{ "max_Subregions", 1, 10 } } },
		{ "ellipse_fit", {
			{ "min_size", 1, 50 },
			{ "max_aspect_ratio", 1, 15 } } },
		{ "TaglenAng", {
			{ "minAng", 10, 80 },
			{ "maxAng", 100, 150 },
			{ "minRatio", 0.1, 1 },
			{ "maxRatio", 1, 8 } } } };

const std::vector<std::string> tagElement = {{
	"CrossRatioLine0AB",
	"CrossRatioLine0AC",
	"CrossRatioLine1AB",
	"CrossRatioLine1AC"}
};



}
void estimatePose(const imageWrap &inputImage, const double4x4 &robotPose,
		const std::string &constellation, const intrinsicParameters &camParam,
		const double4x4 &handEyeCalibration,
		const std::string &algorithmParameters,

		std::vector<double2> &targetLocImage2D, double4x4 &targetPoseCamera,
				double4x4 &targetPoseRobot, double &confidence);

#endif
