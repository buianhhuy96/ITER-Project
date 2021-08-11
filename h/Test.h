#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "calibrateHandEye.h"
#include "linalg.h"
#include "mat.h"
#include <filesystem>
#include <math.h>
const string test_directory = "TestData";
std::vector<std::string> get_directories(const std::string& s);



class testReadRobotPoses
{
public:
	testReadRobotPoses(string test_directory);
	~testReadRobotPoses();
	void operator()();
private:
	string test_directory_;
	bool readInputMat(string file, coder::array<double, 3U> &robotPoses, coder::array<boolean_T, 2U> &validIdx);
	bool readExpectedOutputMat(string file, coder::array<double, 3U> &Poses, coder::array<double, 3U> &Extrinsics);
};


class testComputeCamExtrinsics
{
public:
	testComputeCamExtrinsics(string test_directory);
	~testComputeCamExtrinsics();
	void operator()();
private:
	string test_directory_;
    bool readInputMat(string file, coder::array<uint8_T, 4U> &images, double &squareSize, struct0_T &cameraParams);
    bool readExpectedOutputMat(string file, coder::array<double, 3U> &image_points,
    		coder::array<boolean_T, 1U> &valid_idx,
    		coder::array<double, 3U> &cam_extrinsics,
    		coder::array<double, 3U> &camera_poses,
    		coder::array<double, 2U> &world_points);
};

class testHandeyeShah
{
public:
	testHandeyeShah(string test_directory);
	~testHandeyeShah();
	void operator()();
private:
	string test_directory_;
    bool readInputMat(string file, coder::array<double, 3U> &extrinsics, coder::array<double, 3U> &cam_extrinsics);
    bool readExpectedOutputMat(string file, double base2grid[4][4], double hand_eye_HT[4][4]);
};

class testComputeErrors
{
public:
	testComputeErrors(string test_directory);
	~testComputeErrors();
	void operator()();
private:
	string test_directory_;
	bool readInputMat(string file, coder::array<double, 3U> &extrinsics,
	        double hand_eye_HT[4][4], double base2grid[4][4],
	        coder::array<double, 3U> &cam_extrinsics,
	        coder::array<double, 3U> &image_points,
	        coder::array<double, 2U> &world_points,
	         double KM[4][3]);
	bool readExpectedOutputMat(string file, double errors[5]);
};
