%% load parameters and specify data
%clear
close all
load('CamParameters_vga.mat')
seq='_1';
dataAddPI=['seq1\seq',seq,'\'];
imagePoints=readImagePoints(dataAddPI)

%% PITAG

robotpose = eye(4);
handeye = eye(4);
% Tags Initialization
scale=[66.0723];%66.0723 
dataAddPIL=[dataAddPI,'\']
Tag1Model.l0.AB=0.35; Tag1Model.l0.AC=0.60; Tag1Model.l1.AB=0.25; Tag1Model.l1.AC=0.70;

% Tag World Points
CrossRatioLine0_L1.AB=Tag1Model.l0.AB; CrossRatioLine0_L1.AC=Tag1Model.l0.AC;
CrossRatioLine1_L1.AB=Tag1Model.l1.AB; CrossRatioLine1_L1.AC=Tag1Model.l1.AC;
worldpts=[0,0;   CrossRatioLine0_L1.AB,0;   CrossRatioLine0_L1.AC,0;   1,0;... 
                   1,CrossRatioLine1_L1.AB;   1,CrossRatioLine1_L1.AC;   1,1; ...
            	   CrossRatioLine1_L1.AC,1;   CrossRatioLine1_L1.AB,1;   0,1; ...
                   0,CrossRatioLine0_L1.AC;   0,CrossRatioLine0_L1.AB  ]*scale;

%estimate pose
cameraParams = toStruct(cameraParams);
[poseCamera, poseRobot]=estimatePitagPose(imagePoints(:,:,1),robotpose, worldpts, handeye,cameraParams);

