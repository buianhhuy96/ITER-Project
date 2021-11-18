#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <filesystem>
#include "./ITER_API/calibrateHandEye.h"
#include <math.h>
#include "fileHandler.h"


class testHandeyeCalibration
{
public:
	testHandeyeCalibration(string test_directory, bool trigger_error);
	~testHandeyeCalibration();
	void operator()();
private:
	string test_directory_;
	bool trigger_error_;
	string input_ = "Input.mat";
	string output_ = "Output.mat";
	bool readInputMat(std::vector<imageWrap> &images,
					  std::vector<double4x4> &robotPosesVec,
				      calibrationPatternParameters &calibPatternParam,
					  intrinsicParameters &camParam);
	bool readExpectedOutputMat(double4x4 &handEyeCalibration,
					  int &usedImages,
					  double &reprojectionError,
					  double &rotationError,
					  double &translationError);
};


class testCameraCalibration
{
public:
	testCameraCalibration(string test_directory, bool trigger_error);
	~testCameraCalibration();
	void operator()();
private:
	string test_directory_;
	bool trigger_error_;
	string input_ = "Input.mat";
	string output_ = "Output.mat";
	bool readInputMat(std::vector<imageWrap> &images,
				      calibrationPatternParameters &calibPatternParam);
	bool readExpectedOutputMat(intrinsicParameters &camParam);
};
