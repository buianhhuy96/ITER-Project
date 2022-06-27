function [poses, extrinsics]=readRobotPoses(robotPosesVec)
% Initialize arrays of poses and extrinsics 
poses = zeros(4,4,size(robotPosesVec,3));
extrinsics = zeros(4,4,size(robotPosesVec,3));

%read valid poses and reshape them to 4x4xn matrix
for i=1:size(robotPosesVec,3)
	poses(:,:,i)=robotPosesVec(:,:,i);
	extrinsics(:,:,i)=[poses(1:3,1:3,i)' -poses(1:3,1:3,i)'*poses(1:3,4,i);[0 0 0 1]];
end

    

