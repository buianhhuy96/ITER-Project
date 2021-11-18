#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <filesystem>
#include "./ITER_API/calibrateHandEye.h"
#include <math.h>
#include "fileHandler.h"

class testPreprocessImages
{
public:
	testPreprocessImages(string test_directory, bool trigger_error);
	~testPreprocessImages();
	void operator()();
private:
	string test_directory_;
	bool trigger_error_;
	string input_ = "Input-preprocessImages.mat";
	string output_ = "Output-preprocessImages.mat";
	bool readInputMat(coder::array<unsigned char, 4U> &images, cam_struct_t &camera_params);
	bool readExpectedOutputMat(coder::array<unsigned char, 4U> &gray_images);
};

class testReadRobotPoses
{
public:
	testReadRobotPoses(string test_directory, bool trigger_error);
	~testReadRobotPoses();
	void operator()();
private:
	string test_directory_;
	bool trigger_error_;
	string input_ = "Input-RobotPoses.mat";
	string output_ = "Output-RobotPoses.mat";
	bool readInputMat(coder::array<double, 3U> &robotPoses);
	bool readExpectedOutputMat(coder::array<double, 3U> &Poses, coder::array<double, 3U> &Extrinsics);
};


class testComputeCamExtrinsics
{
public:
	testComputeCamExtrinsics(string test_directory, bool trigger_error);
	~testComputeCamExtrinsics();
	void operator()();
private:
	string test_directory_;
	bool trigger_error_;
	string input_ = "Input-ComputeCamExtrinsics.mat";
	string output_ = "Output-ComputeCamExtrinsics.mat";

    bool readInputMat(coder::array<uint8_T, 4U> &images, double &squareSize, cam_struct_t &cameraParams);
    bool readExpectedOutputMat(coder::array<double, 3U> &image_points,
    		coder::array<boolean_T, 1U> &valid_idx,
    		coder::array<double, 3U> &cam_extrinsics,
    		coder::array<double, 3U> &camera_poses,
    		coder::array<double, 2U> &world_points);
};

class testHandeyeShah
{
public:
	testHandeyeShah(string test_directory, bool trigger_error);
	~testHandeyeShah();
	void operator()();
private:
	string test_directory_;
	bool trigger_error_;
	string input_ = "Input-HandeyeShah.mat";
	string output_ = "Output-HandeyeShah.mat";

    bool readInputMat(coder::array<double, 3U> &extrinsics, coder::array<double, 3U> &cam_extrinsics);
    bool readExpectedOutputMat(double base2grid[4][4], double hand_eye_HT[4][4]);
};

class testComputeErrors
{
public:
	testComputeErrors(string test_directory, bool trigger_error);
	~testComputeErrors();
	void operator()();
private:
	string test_directory_;
	bool trigger_error_;
	string input_ = "Input-ComputeErrors.mat";
	string output_ = "Output-ComputeErrors.mat";

	bool readInputMat(coder::array<double, 3U> &extrinsics,
	        double hand_eye_HT[4][4], double base2grid[4][4],
	        coder::array<double, 3U> &cam_extrinsics,
	        coder::array<double, 3U> &image_points,
	        coder::array<double, 2U> &world_points,
	         double KM[4][3]);
	bool readExpectedOutputMat(double errors[5]);
};
