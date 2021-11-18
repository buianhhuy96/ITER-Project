%% This file loads all the relevant data and computes the Hand-eye calibration using MilliShah's Approach
clear; close all

%% Loading input data, not to be QA'd

%set dataset info
DatasetName='CS_synthetic_1'; % CS_synthetic_1,'kuka_2'     NOTE: %d should be replaced with the dataset number
image_path=[pwd,'\Datasets\',DatasetName,'\'];
image_path2=[pwd,'\Datasets\','kuka_3','\'];
if strcmp(DatasetName(1:end-1),'CS_synthetic_')
    GT_hand2eye=[1 0 0 0;    0 -1 0 0;   0.0001 0.0001 -1 0;    0 0 0 1]; % ground truth hand eye pose (4x4 matrix) to compare, if exist,otherwise []
    square_size=0.2; % in meters.  For  CS_synthetic_1=0.2
else
    GT_hand2eye=[]; 
    square_size=0.015; % in meters.  For kuka_2 =0.015 
end

% Load camera parameters
load([pwd,'\Datasets\',DatasetName,'\CameraParameters.mat']);

% Load undistorted Images
images=LoadImages(image_path);
images2 = LoadImages(image_path2);
%valid_idx = logical([1,1,1,1,1,1,1,1,1,1])';
valid_idx = true(size(images,4),1);
camera_params = toStruct(cameraParams);

% Load robot poses
robotPosesVec=dlmread([pwd,'\Datasets\',DatasetName,'\RobotPosesVec.txt']);
for i=1:size(robotPosesVec,1)
    robot_poses(:,:,i)=reshape(robotPosesVec(i,:),4,[])';
end

images = images(:,:,:,valid_idx);
robot_poses = robot_poses(:,:,valid_idx);
%images = images(:,:,:,1:5);
%images2 = images2(:,:,:,1:5);

save("Input.mat","images","camera_params","robot_poses","square_size");

% Undistord images
% Uncomment the line below for camera boundary tests
%camera_params.TangentialDistortion(:) = realmax;
save('Input-preprocessImages.mat','images','camera_params');
images = uint8(preprocessImages(images, camera_params));
save('Output-preprocessImages.mat','images');

save('Input-RobotPoses.mat','robot_poses');
[poses,extrinsics]=readRobotPoses(robot_poses);
save('Output-RobotPoses.mat','poses','extrinsics');

%% Library functionality starts here
% Compute Camera extrinsics 

save('Input-ComputeCamExtrinsics.mat','images','square_size','camera_params');
[image_points, valid_idx, cam_extrinsics, camera_poses, world_points, err] = ComputeCamExtrinsics(images, square_size, camera_params);

if (err ~= 0)
    error("ComputeCamExtrinsics error");
else
    save('Output-ComputeCamExtrinsics.mat','image_points','valid_idx','cam_extrinsics','camera_poses','world_points','err');
end

% Compute hand-eye- transformation (AX=ZB)
clear err;

save('Input-HandeyeShah.mat','extrinsics','cam_extrinsics');
[base2grid,hand_eye_HT, err] = HandeyeShah(extrinsics,cam_extrinsics) ; 
if (err ~= 0)
    error("HandeyeShah error");
else
    save('Output-HandeyeShah.mat','base2grid','hand_eye_HT');
end
% Computing Errors
% This should be reduced to only errors which can be computed without
% ground truth

KM=[cameraParams.IntrinsicMatrix' [0;0;0]];% matlabs interpretation of intrinsic matrix is different than general approach
save('Input-ComputeErrors.mat','extrinsics','hand_eye_HT','base2grid','cam_extrinsics','image_points','world_points','KM');
[errors]=computeErrors(extrinsics,hand_eye_HT,base2grid,cam_extrinsics,image_points,world_points,KM);
save('Output-ComputeErrors.mat','errors');

save("Output.mat","hand_eye_HT","errors");
%fprintf('\n Time(s): %f \n Rerr(deg): %f \n terr(mm): %f \n reproj_px: %f \n',time, errors(1),errors(2)*1000,errors(3));

fprintf('\n Rerr(deg): %f \n terr(mm): %f \n reproj_px: %f \n', errors(1),errors(2)*1000,errors(3));