%% Pose Estimation
function [RT34est, finalMRE, err] = estimateKnucklePose(markerCentroidsOrdered, worldPoints, cameraParams)
cameraParams = cameraParameters(cameraParams);
% Knuckle Points
err = 0;
RT34est = zeros(4);
finalMRE = inf;

minimization_options=optimset('LargeScale','on',...
    'Algorithm','levenberg-marquardt',...
    'TolFun',1e-10,...
    'Display','off',...
    'TolX',1e-10,...
    'MaxFunEvals',20000,...
    'MaxIter',1000,...
    'UseParallel', false);


worldPointsTmp= worldPoints;
imagePointsTmp= markerCentroidsOrdered;

worldPointsTmp(isnan(imagePointsTmp(:,1)),:) = [];
imagePointsTmp(isnan(imagePointsTmp(:,1)),:) = [];

if (size(imagePointsTmp,1) <= 3)
    err = -101;
    finalMRE = nan;
    RT34est(:) = nan;
    return;
end

if (size(imagePointsTmp) ~= size(worldPoints))
    err = -102;
    finalMRE = nan;
    RT34est(:) = nan;
    return;
end

%try
[worldOrientation,worldLocation, inlierIDX] = estimateWorldCameraPose(...
    imagePointsTmp,worldPointsTmp,cameraParams, 'MaxReprojectionError', 3.0);

[rPNP,tPNP] = cameraPoseToExtrinsics(worldOrientation,worldLocation);
RT = RTtoTransform(worldOrientation, worldLocation);
RT34est = inv(RT);
 
% Optimize Pose
RT34serial = zeros(1,6);
RT34serial(1:3) = RT34est(4,1:3);
RT34serial(4:6) = vision.internal.calibration.rodriguesMatrixToVector(RT34est(1:3, 1:3));
[x, ~, residual, ~, ~, ~, jacobian] = lsqnonlin(@(x) calculateReprErr(x,imagePointsTmp, worldPointsTmp(:,1:2), cameraParams), RT34serial,[], [], minimization_options);

finalMRE = mean(residual(:));
RT34est = RTtoTransform(vision.internal.calibration.rodriguesVectorToMatrix(x(4:6)), x(1:3));
%catch
    % Not possible calculate pose
end