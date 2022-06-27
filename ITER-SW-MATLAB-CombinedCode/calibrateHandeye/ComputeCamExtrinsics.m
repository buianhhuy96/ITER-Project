% images: images in a [row x col x channel x numImages] array
% square: Checkerboard square size in meter size
% cameraParams: camera parameters  matlab object

function [imagePoints,validIdx, camExtrinsics,cameraPoses, worldPoints, err] = ComputeCamExtrinsics(images, squareSize, cameraParams)

% Initialize error and camera parameters
err = int32(0);
cameraParams = cameraParameters(cameraParams);

% Get checkerboard points
[imagePoints, validIdx, worldPoints, err] = extractCheckerboardPoint(images, squareSize, []);

% Terminate in case of error
if (err ~= 0)
    camExtrinsics = [];
    cameraPoses = [];
    return;
end

% compute extrinsics
camExtrinsics = zeros(4,4,size(imagePoints,3));
cameraPoses = zeros(4,4,size(imagePoints,3));

for i = 1:size(imagePoints,3)
    % transformations from the grid/world coordinates to the camera-based coordinates
    [orientation_matrix, translation_vector] = extrinsics(imagePoints(:,:,i), worldPoints, cameraParams); 
   
    camExtrinsics(:,:,i) = [inv(orientation_matrix) translation_vector'; [0 0 0 1]];
	
	% inverted of camExtrinsics
    cameraPoses(:,:,i)= [orientation_matrix -orientation_matrix*translation_vector'; [0 0 0 1]]; 

end
end


