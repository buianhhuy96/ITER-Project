function gray_images = preprocessImages(images, camera_params)


camera_params = cameraParameters(camera_params);
gray_images = uint8(zeros(size(images,1),size(images,2),1,size(images,4)));
for i=1:size(images,4)
   current_images=undistortImage(images(:,:,:,i), camera_params);
   % If gray images, convert to RGB
   if (size(images,3) == 3)
       gray_images(:,:,:,i)=rgb2gray(current_images);
   else
       gray_images(:,:,:,i)=current_images;
   end
end