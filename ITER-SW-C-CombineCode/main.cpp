
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "./ITER_API/calibrateHandEye.h"
#include "./ITER_API/library/linalg.h"
#include "fileHandler.h"
#include "Unit_Test.h"
#include "API_Test.h"

std::map<std::string, std::string> shared_test_directories =
		{
				{ "preprocessImages",
						"TestData/Unit_Test/shared/preprocessImages" }

		};

std::map<std::string, std::string> unit_test_directories =
		{
				{ "readRobotPoses",
						"TestData/Unit_Test/readRobotPoses" },
				{ "ComputeCamExtrinsics",
						"TestData/Unit_Test/ComputeCamExtrinsics" },
				{ "HandeyeShah",
						"TestData/Unit_Test/HandeyeShah" },
				{ "computeErrors",
						"TestData/Unit_Test/computeErrors" },

		};

const string test_directory_Unit = "TestData/Unit_Test";
const string test_directory_API = "TestData/API_Test/HandeyeCalibration";
bool runAllTests(int argc, char const *argv[]) {

	cute::suite s { };
	// Add test cases
	
	std::vector<string> test_cases; 
	
	for (auto test_directory : shared_test_directories) {
		std::vector<string> unit_test_cases = getDirectories(
				test_directory.second);
		test_cases.insert(std::end(test_cases), std::begin(unit_test_cases),
				std::end(unit_test_cases));
	}

	for (auto test_directory : unit_test_directories) {
		std::vector<string> unit_test_cases = getDirectories(
				test_directory.second);
		test_cases.insert(std::end(test_cases), std::begin(unit_test_cases),
				std::end(unit_test_cases));
	}
	
	std::vector<string> API_test_cases = getDirectories(test_directory_API);
	test_cases.insert(std::end(test_cases), std::begin(API_test_cases),	std::end(API_test_cases));
	
	for (auto test_case : test_cases) {
		std::vector<string> IOs = getFiles(test_case);
		auto it_in = std::find_if(IOs.begin(), IOs.end(),
				[](std::string container) {
					return (container.find("Input.mat") != std::string::npos);
				});
		if (it_in != IOs.end()) {
			auto it_out = std::find_if(IOs.begin(), IOs.end(),
					[](std::string container) {
						return (container.find("Output.mat")
								!= std::string::npos);
					});
			if (it_out != IOs.end()) {
				testHandeyeCalibration test_API(test_case, false);
				s.push_back((test_API));
			} else {
				testHandeyeCalibration test_API(test_case, true);
				s.push_back((test_API));
			}
		}
		it_in = std::find_if(IOs.begin(), IOs.end(), [](std::string container) {
			return (container.find("Input-RobotPoses") != std::string::npos);
		});
		if (it_in != IOs.end()) {
			auto it_out = std::find_if(IOs.begin(), IOs.end(),
					[](std::string container) {
						return (container.find("Output-RobotPoses")
								!= std::string::npos);
					});
			if (it_out != IOs.end()) {
				testReadRobotPoses test_read_robot_poses(test_case, false);
				s.push_back((test_read_robot_poses));
			} else {
				testReadRobotPoses test_read_robot_poses(test_case, true);
				s.push_back((test_read_robot_poses));
			}
		}
		it_in = std::find_if(IOs.begin(), IOs.end(),
				[](std::string container) {
					return (container.find("Input-preprocessImages")
							!= std::string::npos);
				});
		if (it_in != IOs.end()) {
			auto it_out = std::find_if(IOs.begin(), IOs.end(),
					[](std::string container) {
						return (container.find("Output-preprocessImages")
								!= std::string::npos);
					});
			if (it_out != IOs.end()) {
				testPreprocessImages test_preprocess_images(test_case, false);
				s.push_back((test_preprocess_images));
			} else {
				testPreprocessImages test_preprocess_images(test_case, true);
				s.push_back((test_preprocess_images));
			}
		}
		it_in = std::find_if(IOs.begin(), IOs.end(),
				[](std::string container) {
					return (container.find("Input-ComputeCamExtrinsics")
							!= std::string::npos);
				});
		if (it_in != IOs.end()) {
			auto it_out = std::find_if(IOs.begin(), IOs.end(),
					[](std::string container) {
						return (container.find("Output-ComputeCamExtrinsics")
								!= std::string::npos);
					});
			if (it_out != IOs.end()) {
				testComputeCamExtrinsics test_compute_cam_extrinsics(test_case,
						false);
				s.push_back((test_compute_cam_extrinsics));
			} else {
				testComputeCamExtrinsics test_compute_cam_extrinsics(test_case,
						true);
				s.push_back((test_compute_cam_extrinsics));
			}
		}
		it_in = std::find_if(IOs.begin(), IOs.end(), [](std::string container) {
			return (container.find("Input-HandeyeShah") != std::string::npos);
		});
		if (it_in != IOs.end()) {
			auto it_out = std::find_if(IOs.begin(), IOs.end(),
					[](std::string container) {
						return (container.find("Output-HandeyeShah")
								!= std::string::npos);
					});
			if (it_out != IOs.end()) {
				testHandeyeShah test_HandeyeShah(test_case, false);
				s.push_back((test_HandeyeShah));
			} else {
				testHandeyeShah test_HandeyeShah(test_case, true);
				s.push_back((test_HandeyeShah));
			}
		} 

		it_in = std::find_if(IOs.begin(), IOs.end(), [](std::string container) {
			return (container.find("Input-ComputeErrors") != std::string::npos);
		});
		if (it_in != IOs.end()) {
			auto it_out = std::find_if(IOs.begin(), IOs.end(),
					[](std::string container) {
						return (container.find("Output-ComputeErrors")
								!= std::string::npos);
					});
			if (it_out != IOs.end()) {
				testComputeErrors test_compute_errors(test_case, false);
				s.push_back((test_compute_errors));
			} else {
				testComputeErrors test_compute_errors(test_case, true);
				s.push_back((test_compute_errors));
			}
		}

	}
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

#define TEST

#ifdef TEST

int main(int argc, char const *argv[]) {

	std::cout << "Test starts" << std::endl;
	
	std::cout << "Current path is " << std::filesystem::current_path() << '\n'; 


	if(runAllTests(argc, argv))
		std::cout << "Test succeeded" << std::endl;
	else
		std::cout << "Test ended with failure" << std::endl;
	
    return EXIT_SUCCESS;
}

#else


int main(void)
{
  string directory = "Dataset/CS_synthetic_1/";
  string robotPosesMat = "RobotPosesT.mat";
  string imagesMat = "Images.mat";
  std::vector<aliases::double4x4> robotPosesVec;

  calibrationPatternParameters calibPatternParam;
  intrinsicParameters camParam;
  readCamParams(calibPatternParam, camParam);

  std::vector<imageWrap> Images;

  double4x4 handEyeCalibration;
  int usedImages;
  double reprojectionError;
  double rotationError;
  double translationError;
  std::cout << "Function starts" << std::endl;
  // Load robot poses from file
  readRobotPosesMat(directory + robotPosesMat, robotPosesVec);

  // Load input images
  readImages(directory + imagesMat, Images, 1920, 1080, 3);

  calibrateHandEye(Images,
                    robotPosesVec,
                   calibPatternParam,
                   camParam,

                   handEyeCalibration, usedImages,
                   reprojectionError, rotationError,
                   translationError);



  std::cout << "reprojectionError: " << reprojectionError << std::endl;
  std::cout << "rotationError: " << rotationError << std::endl;
  std::cout << "translationError: " << translationError << std::endl;
  std::cout << "Function ends" << std::endl;
  return 0;
}

#endif
