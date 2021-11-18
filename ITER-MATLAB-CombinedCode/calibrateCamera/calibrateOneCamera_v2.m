%% Multiple Camera Calibration Toolbox - V1
% Laura Ribeiro, Tampere University, Finland
% (laura.goncalvesribeiro@tuni.fi)
%% Step 1
% Calibrates each camera independently using Matlab Camera Calibrator Application
% Calculates extrinsic parameters between camera N and camera 1
% Inputs: directory of calibration images, squareSize, boardSize
% Follow the naming convetion for calibration images: PositionXXX_CameraXX
%% Step 2
% Overall Optimization
% Options:
% Re-estimate all: [1, 1, 1 ,1];
% Fixed Intrinsics: [1, 1, 0 ,0];
% Fixed lens distortions: [0, 1, 0 ,0];
% Default: Fixed intrinsics.

%{
%% ITER API ALGORITHM IMPLEMENTATION STARTS HERE
%% Calibrate One Camera
function [CameraParameters,errorOptimized, calculation_err, err] = calibrateOneCamera(images, squareSize, boardSize)

% Generate world coordinates of the checkerboard keypoints
worldPoints = generateCheckerboardPoints(boardSize, squareSize);

% REPLACE WITH FOR LOOP OF SINGLE detectCheckerBoardPoints
[ImagePoints, boardSizeDetected , checkFound] = detectCheckerboardPoints(imageFileNames(:)); % detect checkerboard for every position of camera i

disp(boardSize == boardSizeDetected);


% Estimate without using estimateCameraParameters
%If want different values of EstimateSkew, EstimateTangentialDistortion, NumRadialDistortionCoefficients unserializeCalib fuction needs be changed
cameraModel.EstimateSkew = false; 
cameraModel.EstimateTangentialDistortion = false;
cameraModel.NumRadialDistortionCoefficients =3;

[initialParams, imagesUsed] = computeInitialParameterEstimate(...
    worldPoints, ImagePoints, [], cameraModel, 'millimeters', [], []);

%% Convert Extrinsics to my way
clear RTc1pn
tempR= initialParams.RotationMatrices(:,:,imagesUsed);
tempt= initialParams.TranslationVectors(imagesUsed,:);
for i=1:size(tempR,3)
    RTc1pn{i} = RTtoTransform(tempR(:,:,i),tempt(i,:));
end
%% Crete Calibration Struct
calibration.CameraParameters = initialParams;
calibration.PatternPositions = RTc1pn;
calibration.ImagePoints = ImagePoints;
%% Minimization options
% Default options give better outcome
% minimization_options=optimset('LargeScale','on',...
%     'Algorithm','levenberg-marquardt',...
%     'TolFun',1e-10,...
%     'Display','on',...
%     'TolX',1e-10,...
%     'MaxFunEvals',200000,...
%     'MaxIter',10000,...
%     'UseParallel', false);

% Optimization options: fixedK, fixedDistortions, fixedRTpnc1
options = [0,0,0];
%World and Image Points
genPoints = [worldPoints, ones(size(worldPoints,1),1)];
detPoints = calibration.ImagePoints;
%% Convert initial estimate
serialCalib = serializeCalib(calibration, options);

[calibrationConverted] = unserializeCalib(serialCalib, options, calibration);
errorInitial = CalculateCost(serialCalib, options, calibration, genPoints, detPoints);
tmp = errorInitial; tmp(tmp<0.000001)=NaN; 
MREi = mean(tmp(~isnan(tmp(:))));
disp (['Mean Reprojection Error - Before Optimization: ', num2str(MREi)]);
%% Optimization
h = waitbar(0, 'Running global Optimization...','Name', 'Global Optimization');

[optimizedSerialCalib,~,residual,~,~,~,jacobian] = lsqnonlin(@(x) CalculateCost(x, options, calibration, genPoints, detPoints),serialCalib, [],[]);

delete(h);

serialCI = nlparci(optimizedSerialCalib,residual,'jacobian',jacobian);
CI(:,1) = unserializeCalib(serialCI(:,1)', options, calibration);
CI(:,2) = unserializeCalib(serialCI(:,2)', options, calibration);

errorOptimized = CalculateCost(optimizedSerialCalib, options, calibration, genPoints, detPoints);
tmp = errorOptimized; tmp(tmp<0.000001)=NaN; MREf = nanmean(tmp(:));
disp (['Mean Reprojection Error - After Optimization: ', num2str(MREf)]);

[calibrationOptimized] = unserializeCalib(optimizedSerialCalib, options, calibration);

calibrationOptimized.OptimizationOptions = options;
calibrationOptimized.Jacobian = jacobian;
calibrationOptimized.Error = errorOptimized;
calibrationOptimized.CI = CI;

end
%}

function [cameraParams, errorOptimized, MREf, validIdx, err] = calibrateOneCamera_v2(images, squareSize, boardSize)

% Retrieve useful information
image_size = [size(images,1) size(images,2) ];

% Initalize error flag
err = int32(0);
cameraParams = toStruct(cameraParameters('ImageSize', image_size));
errorOptimized = zeros(0,1);
validIdx = logical(zeros(0,1));
MREf = inf;

coder.varsize('errorOptimized','validIdx');
[image_points, validIdx, world_points, err] = extractCheckerboardPoint(images, squareSize, boardSize);

if (err ~= 0)
    return;
end

%% Inital Parameter Estimate
%If want different values of EstimateSkew, EstimateTangentialDistortion, NumRadialDistortionCoefficients unserializeCalib fuction needs be changed
cameraModel.EstimateSkew = false; 
cameraModel.EstimateTangentialDistortion = false;
cameraModel.NumRadialDistortionCoefficients =3;

[initialParams, ~, err] = computeInitialParameterEstimate(...
    world_points, image_points, image_size, cameraModel, 'm', [], []);

if (err ~= 0)
    return;
end

%%
initialParamsSerial = serialize(initialParams);
%unpackedCameraParams = unpackSerializedParams(initialParams, initialParamsSerial, 0);

%% Calculate mre - before optimization 
%[errorInitial] = reprojectWrapper(initialParamsSerial, initialParams, 0, worldPoints, ImagePoints);
%tmp = errorInitial; tmp(tmp<0.000001)=NaN; MREi = nanmean(tmp(:));
%disp (['Mean Reprojection Error - Before Optimization: ', num2str(MREi)]);
%%Optimize
%% Optimization
Opt = (optimoptions(@lsqnonlin,'Algorithm','levenberg-marquardt'));
lb = [];
ub = [];
[optimizedSerialCalib,~,residual,~,~,~,jacobian] = lsqnonlin(@(x) reprojectWrapper(x, initialParams, world_points, image_points),initialParamsSerial, lb,ub, Opt);

%% Calculate mre - after optimization 
errorOptimized = reprojectWrapper(optimizedSerialCalib, initialParams, world_points, image_points);
tmp = errorOptimized; tmp(tmp<0.000001)=NaN; MREf = nanmean(tmp(:));
%disp (['Mean Reprojection Error - After Optimization: ', num2str(MREf)]);

[cameraParams] = (unpackSerializedParams(initialParams, optimizedSerialCalib));
end

function [cost] = reprojectWrapper(paramsVector, cameraParams, worldPoints, ImagePoints)
paramStruct = cameraParameters(unpackSerializedParams(cameraParams, paramsVector));
internal_worldPoints = cat(2,worldPoints,zeros(size(worldPoints,1),1));
cost=zeros(size(paramStruct.RotationVectors,1)*size(ImagePoints,1),1);
for n = 1: size(paramStruct.RotationVectors,1) % for each image
    points = ImagePoints(:,:,n);
    projectedPoints = worldToImage(paramStruct,paramStruct.RotationMatrices(:,:,n), paramStruct.TranslationVectors(n,:),internal_worldPoints, 'ApplyDistortion',true);
    
    
    difference = (projectedPoints - points);
    error = sqrt(sum((difference).^2, 2));
    cost((n-1)*size(ImagePoints,1)+1:n*size(ImagePoints,1)) = error;
end
end

function x = serialize(cameraParams)
cameraParams = cameraParameters(cameraParams);
% x = [fx; fy; cx; cy; skew; radial; tangential; rvecs; tvecs];

    x = [cameraParams.FocalLength(1); cameraParams.FocalLength(2); ...
        cameraParams.PrincipalPoint(1); cameraParams.PrincipalPoint(2)];
    
    if cameraParams.EstimateSkew
        x = [x; cameraParams.Skew];
    end
    
    x = [x; cameraParams.RadialDistortion(1:cameraParams.NumRadialDistortionCoefficients)'];
    
    if cameraParams.EstimateTangentialDistortion
        x = [x; cameraParams.TangentialDistortion'];
    end


rt = [cameraParams.RotationVectors, cameraParams.TranslationVectors]';
x = [x; rt(:)]; % r1, t1, r2, t2, ...
end

function outputParams = unpackSerializedParams(cameraParams, x)

    if cameraParams.EstimateSkew
        skew = x(5);
        numIntrinsicMatrixEntries = 5;
    else
        skew = 0;
        numIntrinsicMatrixEntries = 4;
    end
    
    fx = x(1);
    fy = x(2);
    cx = x(3);
    cy = x(4);
    
    x = x(numIntrinsicMatrixEntries+1:end);
    
    numRadialCoeffs = cameraParams.NumRadialDistortionCoefficients;
    radialDistortion = x(1:numRadialCoeffs)';
    
    if cameraParams.EstimateTangentialDistortion
        tangentialDistortion = ...
            x(numRadialCoeffs+1:numRadialCoeffs+2)';
        numDistortionCoeffs = numRadialCoeffs + 2;
    else
        tangentialDistortion = [0,0];
        numDistortionCoeffs = numRadialCoeffs;
    end
    
    x = x(numDistortionCoeffs+1:end);


if isempty(x)
    rotationVectors = [];
    translationVectors = [];
else
    x = reshape(x, 6, []);
    rotationVectors = x(1:3, :)';
    translationVectors = x(4:6, :)';
end

A = [fx, skew, cx; ...
     0, fy, cy; ...
     0, 0, 1];
outputParams = toStruct(cameraParameters('IntrinsicMatrix', A', ...
    'RotationVectors', rotationVectors, ...
    'TranslationVectors', translationVectors,...
    'EstimateSkew', cameraParams.EstimateSkew,...
    'NumRadialDistortionCoefficients', cameraParams.NumRadialDistortionCoefficients,...
    'EstimateTangentialDistortion', cameraParams.EstimateTangentialDistortion,...
    'RadialDistortion', radialDistortion, 'TangentialDistortion', tangentialDistortion,...
    'ImageSize', cameraParams.ImageSize));


end



% ITER API ALGORITHM IMPLEMENTATION ENDS HERE