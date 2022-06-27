function [initialParams, validIdx, err] = computeInitialParameterEstimate(...
    worldPoints, imagePoints, imageSize, cameraModel, worldUnits, initIntrinsics, initRadial)
% Solve for the camera intriniscs and extrinsics in closed form ignoring
% distortion.
err = int32(0);
[H, validIdx, err] = computeHomographies(imagePoints, worldPoints);

    

if (err == 0)
    
V = computeV(H);
B = computeB(V);
[A,err] = computeIntrinsics(B);

if (err == 0)
[rvecs, tvecs] = computeExtrinsics(A, H);
radialCoeffs = zeros(1, cameraModel.NumRadialDistortionCoefficients);

%iniltialParams = my_CameraParameters(radialCoeffs,worldPoints,worldUnits,cameraModel,rvecs,tvecs,A',size(imagePoints, 3));
initialParams = toStruct(cameraParameters('IntrinsicMatrix', A', ...
    'RotationVectors', rvecs, ...
    'TranslationVectors', tvecs, 'WorldPoints', worldPoints, ...
    'WorldUnits', worldUnits, 'EstimateSkew', cameraModel.EstimateSkew,...
    'NumRadialDistortionCoefficients', cameraModel.NumRadialDistortionCoefficients,...
    'EstimateTangentialDistortion', cameraModel.EstimateTangentialDistortion,...
    'RadialDistortion', radialCoeffs, 'ImageSize', imageSize));
else
 initialParams = toStruct(cameraParameters('ImageSize', imageSize));
end

else
 initialParams = toStruct(cameraParameters('ImageSize', imageSize));
end

end

%--------------------------------------------------------------------------
function H = computeHomography(imagePoints, worldPoints)
% Compute projective transformation from worldPoints to imagePoints

validPointsIdx = ~isnan(imagePoints(:,1));

H = fitgeotrans(worldPoints(validPointsIdx,:), imagePoints(validPointsIdx,:), 'projective');
H = (H.T)';
H = H / H(3,3);
end

%--------------------------------------------------------------------------
function [homographies, validIdx, err] = computeHomographies(points, worldPoints)
% Compute homographies for all images
err = int32(0);
%w1 = warning('Error', 'MATLAB:nearlySingularMatrix'); %#ok
%w2 = warning('Error', 'images:maketform:conditionNumberofAIsHigh'); %#ok

numImages = size(points, 3);
validIdx = true(numImages, 1);
homographies = zeros(3, 3, numImages);
for i = 1:numImages
   % try    
        homographies(:, :, i) = ...
            computeHomography(double(points(:, :, i)), worldPoints);
   % catch 
   %     validIdx(i) = false;
   % end
end
%warning(w1);
%warning(w2);
homographies = homographies(:, :, validIdx);
if ~all(validIdx)
    %warning(message('vision:calibrate:invalidHomographies', ...
    %    numImages - size(homographies, 3), numImages));
    %err = "invalid Homographies";
    err = int32(-201);
    return;
end

if size(homographies, 3) < 2
    %error(message('vision:calibrate:notEnoughValidHomographies'));
    err = int32(-201);
    return;
end
end
%--------------------------------------------------------------------------
function V = computeV(homographies)
% Vb = 0

numImages = size(homographies, 3);
V = zeros(2 * numImages, 6);
for i = 1:numImages
    H = homographies(:, :, i)';
    V(i*2-1,:) = computeLittleV(H, 1, 2);
    V(i*2, :) = computeLittleV(H, 1, 1) - computeLittleV(H, 2, 2);
end
end
%--------------------------------------------------------------------------
function v = computeLittleV(H, i, j)
    v = [H(i,1)*H(j,1), H(i,1)*H(j,2)+H(i,2)*H(j,1), H(i,2)*H(j,2),...
         H(i,3)*H(j,1)+H(i,1)*H(j,3), H(i,3)*H(j,2)+H(i,2)*H(j,3), H(i,3)*H(j,3)];
end
%--------------------------------------------------------------------------     
function B = computeB(V)
% lambda * B = inv(A)' * inv(A), where A is the intrinsic matrix

[~, ~, U] = svd(V);
b = U(:, end);

% b = [B11, B12, B22, B13, B23, B33]
B = [b(1), b(2), b(4); b(2), b(3), b(5); b(4), b(5), b(6)];
end
%--------------------------------------------------------------------------
function [A, err] = computeIntrinsics(B)
% Compute the intrinsic matrix
err = int32(0);
cy = (B(1,2)*B(1,3) - B(1,1)*B(2,3)) / (B(1,1)*B(2,2)-B(1,2)^2);
lambda = B(3,3) - (B(1,3)^2 + cy * (B(1,2)*B(1,3) - B(1,1)*B(2,3))) / B(1,1);

if (lambda / B(1,1) < 0) || (lambda * B(1,1) / (B(1,1) * B(2,2) - B(1,2)^2) < 0)
    %error(message('vision:calibrate:complexCameraMatrix'));
    err = int32(-301);
end
fx = sqrt(lambda / B(1,1));
fy = sqrt(lambda * B(1,1) / (B(1,1) * B(2,2) - B(1,2)^2));
skew = -B(1,2) * fx^2 * fy / lambda;
cx = skew * cy / fx - B(1,3) * fx^2 / lambda;
A = [fx, skew, cx; ...
     0, fy, cy; ...
     0, 0, 1];
end
%--------------------------------------------------------------------------
function [rotationVectors, translationVectors] = ...
    computeExtrinsics(A, homographies)
% Compute translation and rotation vectors for all images

numImages = size(homographies, 3);
rotationVectors = zeros(3, numImages);
translationVectors = zeros(3, numImages); 
Ainv = inv(A);
for i = 1:numImages
    H = homographies(:, :, i);
    h1 = H(:, 1);
    h2 = H(:, 2);
    h3 = H(:, 3);
    lambda = 1 / norm(Ainv * h1); %#ok
    
    % 3D rotation matrix
    r1 = lambda * Ainv * h1; %#ok
    r2 = lambda * Ainv * h2; %#ok
    r3 = cross(r1, r2);
    R = [r1,r2,r3];
    
    rotationVectors(:, i) = vision.internal.calibration.rodriguesMatrixToVector(R);
    
    % translation vector
    t = lambda * Ainv * h3;  %#ok
    translationVectors(:, i) = t;
end

rotationVectors = rotationVectors';
translationVectors = translationVectors';
end

%--------------------------------------------------------------------------
% computeFocalLength compute focal length given a set of homography
% measurements, a fixed principal point and zero skew.

% Copyright 2016 MathWorks, Inc.
function [fx, fy] = computeFocalLength(homographies, cx, cy)

numImages = size(homographies, 3);
Ap = zeros(2*numImages, 2);
bp = zeros(2*numImages, 1);

% Each homography measurement gives two equations:
% [ h11*h21       h12*h22    ][1/fx^2]   [ -h13 h23   ]
%                                      = 
% [ h11^2-h21^2   h12^2-h22^2][1/fy^2]   [ h23^2-h13^2]
%
% where homography matrix is modified to remove the principal point offset
for i = 1 : numImages
    H = homographies(:, :, i);
    H(1, :) = H(1, :) - cx * H(3, :);
    H(2, :) = H(2, :) - cy * H(3, :);
    
    h = [0, 0, 0];
    v = [0, 0, 0];
    d1 = [0, 0, 0];
    d2 = [0, 0, 0];
    n = [0, 0, 0, 0];
    for j = 1:3
        t0 = H(j,1);
        t1 = H(j,2);
        h(j) = t0; 
        v(j) = t1;
        d1(j) = (t0 + t1) * 0.5;
        d2(j) = (t0 - t1) * 0.5;
        n(1) = n(1) + t0 * t0; 
        n(2) = n(2) + t1 * t1;
        n(3) = n(3) + d1(j) * d1(j); 
        n(4) = n(4) + d2(j) * d2(j); 
    end

    n = 1 ./ sqrt(n);
    h = h * n(1);
    v = v * n(2);
    d1 = d1 * n(3);
    d2 = d2 * n(4);
    
    Ap(2 * i - 1, 1) = h(1) * v(1); 
    Ap(2 * i - 1, 2) = h(2) * v(2); 
    Ap(2 * i, 1) = d1(1) * d2(1); 
    Ap(2 * i, 2) = d1(2) * d2(2); 
    bp(2 * i - 1) = -h(3) * v(3); 
    bp(2 * i) = -d1(3) * d2(3); 
end

f = Ap \ bp;
fx = sqrt(abs(1/f(1)));
fy = sqrt(abs(1/f(2)));

end