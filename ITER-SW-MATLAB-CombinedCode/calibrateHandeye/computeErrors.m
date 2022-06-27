%where the Input:
%Hhand2base         a 4x4xNumber_of_Views Matrix of the form
%                   Hhand2base(:,:,i) = [Ri_3x3 ti_3x1;[ 0 0 0 1]] 
%                   with 
%                   i = number of the view, 
%                   Ri_3x3 the rotation matrix 
%                   ti_3x1 the translation vector.
%Hhand2eye          a 4x4xNumber_entries_to_examine Matrix of the form
%                   Hhand2eye(:,:,i) = [Ri_3x3 ti_3x1;[ 0 0 0 1]] 
%Hbase2grid         a 4x4xNumber_entries_to_examine Matrix of the form
%                   Hbase2grid(:,:,i) = [Ri_3x3 ti_3x1;[ 0 0 0 1]]    
%Hcam2grid          a 4x4xNumber_of_Views Matrix (like above)
%                   Defining the transformation of the  camera to the
%                   grid/calibration block/world
%K                  The camera intrinsic  (4x4 matrix)
%imgPts             an array with  containing the imgpoints corresponding to the corner points on the
%                   calibration board.(Nx2xM), where N is number of corners
%                   in M images
%                   and M is the number of calibration images
%Worldpts           world coordinates of the corners (Nx2) matrix


%Output:
%Rerr               The rotation error in degrees corresponding to each
%                   each entry
%terr               The translation error in meters corresponding to each each entry
%ReprojErr          The reprojection error from reprojecting the world/grid
%                   points on the camera images corresponding to each each entry

function [errors]= computeErrors(Hhand2base,Hhand2eye,Hbase2grid,Hcam2grid,imgPts,Worldpts,K)

num_of_images=size(imgPts,3);
%% computing dependencies
selectRow12=@(x) x(1:2,:);
normbyZ = @(ptProj) selectRow12(bsxfun(@rdivide, ptProj, ptProj(3,:)));% % Divide with Z to complete the perspective projection 
Wpts = [Worldpts, zeros(size(Worldpts,1),1), ones(size(Worldpts,1),1)]';

errreproj = zeros(size(Hhand2eye,3),1);
Rerr = zeros(size(Hhand2eye,3),1);
terr = zeros(size(Hhand2eye,3),1);
%% Computing Errors
for i=1:size(Hhand2eye,3)    
   
    %% Computing Rotation errors distribution
    angR=zeros(num_of_images,1);PoseErrR=zeros(3,3,num_of_images);
    for j=1:num_of_images
        PoseErrR(:,:,j)=inv(Hhand2eye(1:3,1:3,i)*Hcam2grid(1:3,1:3,j))*(Hhand2base(1:3,1:3,j)*Hbase2grid(1:3,1:3,i)) ;         % inv(Rz*Rb)(Ra*Rx)
        AxAngVec=rotm2axang(PoseErrR(:,:,j));
        angR(j,1)=AxAngVec(4)*(180/pi);
    end
    Rerr(i,1)= mean(sqrt(sum(angR.^2,2))); 


    %% Computing Translation errors distribution
    PoseErrt=zeros(num_of_images,3);
    for j=1:num_of_images
         PoseErrt(j,:)= ( ((Hhand2base(1:3,1:3,j)*Hbase2grid(1:3,4,i))+ Hhand2base(1:3,4,j)) -...
                    ((Hhand2eye(1:3,1:3,i)*Hcam2grid(1:3,4,j))+Hhand2eye(1:3,4,i) ) )'  ;%(Ra*tx)+ta -(Rz*tb)+tz
    end
    terr(i,1)=mean(sqrt(sum(PoseErrt.^2,2))); 


    %% Computing Reprojection errors
    err=zeros(size(imgPts,1),num_of_images);
    for j=1:num_of_images
        A=Hhand2base(:,:,j);
        imgP=imgPts(:,:,j);
        HT = inv(Hhand2eye(:,:,i)) * A *  Hbase2grid(:,:,i)    ; % either inv(Z)*A*X  ,where Z is H2e and X is base 2 grid
        proj=  normbyZ(K*(HT*Wpts) )'; %need to invert HT befor invR, if the representation change of whole inverse is followed                        
        err(:,j) = sum((imgP - proj).^2,2);% adopted approach
    end
    errreproj(i,:)=sqrt(mean(err(:)));%rrmse

end

errors=[Rerr terr errreproj];