%% This file loads all the relevant data and computes the Hand-eye calibration using MilliShah's Approach
clear; close all

%% Loading input data, not to be QA'd

%set dataset info
DatasetName='kuka_2'; % CS_synthetic_1,'kuka_%d'     NOTE: %d should be replaced with the dataset number
calibImgPath=[pwd,'\Datasets\',DatasetName,'\'];

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
images=LoadImages(calibImgPath,cameraParams);
%valid_idx = logical(ones(num_of_images,1)); 
valid_idx = logical([0,0,0,0,0,1,1,1,1,1,1,1,1,1,1]);
images = images(:,:,:,valid_idx);
camera_params = toStruct(cameraParams);
images = uint8(preprocessImages(images, camera_params));



% Load robot poses
num_of_images = size(images,4);
robotPosesVec=dlmread([pwd,'\Datasets\',DatasetName,'\RobotPosesVec.txt']);
for i=1:size(robotPosesVec,1)
robot_poses(:,:,i)=reshape(robotPosesVec(i,:),4,[])';
end
%robot_poses(:) = realmax;
save('Input-RobotPoses.mat','robot_poses','valid_idx');
[poses,extrinsics]=readRobotPoses(robot_poses,valid_idx);
save('Output-RobotPoses.mat','poses','extrinsics');

%% Library functionality starts here
% Compute Camera extrinsics 
%images(:) = intmax('uint8');
save('Input-ComputeCamExtrinsics.mat','images','square_size','camera_params');
[image_points, valid_idx, cam_extrinsics, camera_poses, world_points] = ComputeCamExtrinsics(images, square_size, camera_params);
save('Output-ComputeCamExtrinsics.mat','image_points','valid_idx','cam_extrinsics','camera_poses','world_points');

% Compute hand-eye- transformation (AX=ZB)

save('Input-HandeyeShah.mat','extrinsics','cam_extrinsics');
[base2grid,hand_eye_HT,time] = HandeyeShah(extrinsics,cam_extrinsics) ; 
save('Output-HandeyeShah.mat','base2grid','hand_eye_HT');

% Computing Errors
% This should be reduced to only errors which can be computed without
% ground truth
hand_eye_HT(:) = realmin;
KM=[cameraParams.IntrinsicMatrix' [0;0;0]];% matlabs interpretation of intrinsic matrix is different than general approach
save('Input-ComputeErrors.mat','extrinsics','hand_eye_HT','base2grid','cam_extrinsics','image_points','world_points','KM');
[errors]=computeErrors(extrinsics,hand_eye_HT,base2grid,cam_extrinsics,image_points,world_points,KM);
save('Output-ComputeErrors.mat','errors');
fprintf('\n Time(s): %f \n Rerr(deg): %f \n terr(mm): %f \n reproj_px: %f \n',time, errors(1),errors(2)*1000,errors(3));
