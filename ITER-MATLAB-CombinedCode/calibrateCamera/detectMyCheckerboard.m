function [image_points, err] = detectMyCheckerboard(images, boardSize) 

err = int8(0);

num_of_images = size(images,4);  valid_idx = false(num_of_images,1);
board_points = cell(num_of_images,1); board_sizes = cell(num_of_images,1);
for i=1:num_of_images 	% perform checkerboards detection in each image    
    current_image=images(:,:,:,i);     
    [current_board_points, board_size_detected] = detectCheckerboardPoints(current_image, 'PartialDetections', false);
    % mark if checkerboards is detected or not     
    if (~isequal(boardSize,board_size_detected) ||  isempty(current_board_points))     
        valid_idx(i)=false;    
    else  
        valid_idx(i)=true;    
    end         
    board_points{i} = current_board_points;    
    board_sizes{i} = board_size_detected;  
end 

if ~all(valid_idx)   
    %err = "Wrong detection of board size";  
    err = int8(-1);
    image_points = [];
    return;
end 

num_of_valid_images = sum(valid_idx(:) == true);
image_points = zeros([size(board_points{1}) num_of_valid_images]);
for i=1:num_of_valid_images    
    if valid_idx(i)         
        image_points(:,:,i) = board_points{i};     
    end 
end 
end