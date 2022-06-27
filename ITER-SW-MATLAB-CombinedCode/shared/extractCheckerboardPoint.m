function [imagePoints, validIdx, worldPoints, err] = extractCheckerboardPoint(images, squareSize, boardSize) 

% Initialize error flags
err = int32(0);

board_size_valid = zeros(1,2); 
image_point_valid = [];
num_of_images = size(images,4);  validIdx = false(num_of_images,1);
board_points = cell(1,num_of_images); 

% perform checkerboards detection in each image
for i=1:num_of_images 	    
    current_image=images(:,:,:,i);     
    [current_board_points, board_size_detected] = detectCheckerboardPoints(current_image, 'PartialDetections', false);
    % mark if checkerboards is detected or not  
    if (isequal(board_size_detected, [0 0]) || ...
            (~isempty(boardSize) && ~isequal(board_size_detected,boardSize) ))     
        validIdx(i)=false;    
    else  
        if (isequal(board_size_valid, [0 0]))
            board_size_valid = board_size_detected;
            image_point_valid = current_board_points;
        elseif (~isequal(board_size_valid, board_size_detected))            
              err = int32(-102);              
        end
        validIdx(i)=true;      
    end         
    
       
    board_points{i} = current_board_points;
end 

if (err ~=0)
    %err = "Checkerboards detected has different size from given boardSize"; 
    imagePoints = [];
    worldPoints = [];
    return;
end 

if ~any(validIdx)   
    %err = "No detect of checkerboard in all images";  
    err = int32(-101);
    imagePoints = [];
    worldPoints = [];
    return;
end 

% Extract valid image points into matrix
num_of_valid_images = sum(validIdx(:) == true);
imagePoints = zeros([size(image_point_valid) num_of_valid_images]);
j = 1;
for i=1:num_of_images
    if validIdx(i)
        imagePoints(:,:,j) = board_points{i};
        j=j+1;
    end
end


% Generate world coordinates of the corners of the squares in meters
worldPoints = generateCheckerboardPoints(board_size_valid, squareSize);

end