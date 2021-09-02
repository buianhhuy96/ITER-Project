% images: images in a [row x col x channel x numImages] array
% square: Checkerboard square size in meter size
% camera_params: camera parameters  matlab object

function [image_points,valid_idx, cam_extrinsics,camera_poses, world_points] = ComputeCamExtrinsics(images, square_size, camera_params)

camera_params = cameraParameters(camera_params);
num_of_images = size(images,4);

% Detect checkerboards in images
[board_points, board_size] = detectCheckerboardPoints(images(:,:,:,1),  'PartialDetections', false);

board_points = zeros([size(board_points), num_of_images]);
valid_idx = logical(zeros(num_of_images,1));

for i=1:num_of_images
	% perform checkerboards detection in each image
    current_image=images(:,:,:,i);
    [current_board_points, ~] = detectCheckerboardPoints(current_image, 'PartialDetections', false);
	
	% mark if checkerboards is detected or not
    if (isempty(current_board_points))        
        valid_idx(i)=false;
    else
        valid_idx(i)=true;
        board_points(:,:,i)=current_board_points;
    end
    
end


image_points = board_points(:,:,valid_idx);
% Generate world coordinates of the corners of the squares in meters
world_points = generateCheckerboardPoints(board_size, square_size);

% compute extrinsics
num_of_valid_images = size(image_points,3);

cam_extrinsics = zeros(4,4,num_of_valid_images);
camera_poses = zeros(4,4,num_of_valid_images);

for i = 1:num_of_valid_images
    % transformations from the grid/world coordinates to the camera-based coordinates
    [orientation_matrix, translation_vector] = extrinsics(image_points(:,:,i), world_points, camera_params); 
   
    cam_extrinsics(:,:,i) = [inv(orientation_matrix) translation_vector'; [0 0 0 1]];
	
	% inverted of cam_extrinsics
    camera_poses(:,:,i)= [orientation_matrix -orientation_matrix*translation_vector'; [0 0 0 1]]; 

end


