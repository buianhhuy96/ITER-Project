function [robotPoses, err] = computeCalibrationPoses_internal(initialImage, initialRobotPose, handEyeEstimate, roughDistance, angularBounds, squareSize, boardSize, factoryCamParam, requestedNumPoses)

%% Function starts
%% Initialize outputs
robotPoses = zeros(4,4,requestedNumPoses(1)*requestedNumPoses(2)*requestedNumPoses(3)); 
err = int32(0);

%% Setup Parameters
factoryCamParam = cameraParameters(factoryCamParam);
d = roughDistance; % Desired target distance (mm)

RT23 = handEyeEstimate;
RT12initial = initialRobotPose;
%% Detect checker and calculate current pose
if (size(initialImage,3)==1)
    grayImage = initialImage(:,:,1);   
else
    grayImage = rgb2gray(initialImage);    
end
boardSizeDetected = zeros(1,2);
[imagePoints, boardSizeDetected] = detectCheckerboardPoints(grayImage);
if ~all(boardSizeDetected)
    err = int32(-101);
    robotPoses = [];
    return;
elseif ~isequal(boardSize, boardSizeDetected)        
    err = int32(-102);  
    robotPoses = [];
    return;
end
worldPoints = generateCheckerboardPoints(boardSize, squareSize);

% Check for valid checkerboard detected.


[R34,T34] = extrinsics(imagePoints,worldPoints,factoryCamParam);
RT34initial= RTtoTransform(R34, T34); 

%% Calculate Centre Pose
middlepoint = ((boardSize-2)./2)*squareSize;

T34center = [-middlepoint(2), -middlepoint(1), d];
R34center = eul2rotm(deg2rad([0,0,0]));
RT34center= RTtoTransform(R34center, T34center);

RT12center = inv(RT23)*inv(RT34center)*RT34initial*RT23*RT12initial;

%% Creates a set of robot poses
middlepoint = ((boardSize-2)./2)*squareSize;

aroundX = linspace(angularBounds(1, 1), angularBounds(2, 1), requestedNumPoses(1));
aroundY = linspace(angularBounds(1, 2), angularBounds(2, 2), requestedNumPoses(2));
aroundZ = linspace(angularBounds(1, 3), angularBounds(2, 3), requestedNumPoses(3));



[rz, ry, rx] = meshgrid(aroundX, aroundY, aroundZ);



Rchange = cat(1, rx(:)', ry(:)', rz(:)');

for i=1:size (Rchange,2)
    %Calculate transformation
    T = [0,0,0];
    R = eul2rotm(deg2rad(Rchange(:,i)'))';
    RTcenter_center= inv(RTtoTransform(R, T));
    RTcorner_center = RTtoTransform(eye(3,3), [middlepoint(2), middlepoint(1), 0]);
    RTc_pf = inv(RTcorner_center)*RTcenter_center*RTcorner_center*RT34center;
    robotPoses(:,:,i) = inv(RT23)*inv(RTc_pf)*RT34center*RT23*RT12center;
end

end