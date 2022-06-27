% Undistort and convert images into grayscale
% Input:
%images             a row x col x color channels x Number_of_images matrix 
%                   
%cameraParams      camera parameters object
%undistort          logical flag indicate if the images can be/required to
%                   be undistorted

%Output:
%gray_images        matrix contains images in grayscale and undistorted

function gray_images = preprocessImages(images, cameraParams, undistort)
camera_params = cameraParameters(cameraParams);
gray_images = uint8(zeros(size(images,1),size(images,2),1,size(images,4)));
for i=1:size(images,4)
   % If RGB images, convert to gray
   if (size(images,3) == 3)
       current_images = rgb2gray(images(:,:,:,i));
   else
       current_images=images(:,:,:,i);
   end
   % If true, the images get undistorted
   if (undistort)
        gray_images(:,:,:,i) = undistortImage(current_images, camera_params);
   else
       gray_images(:,:,:,i)=current_images;
   end
end