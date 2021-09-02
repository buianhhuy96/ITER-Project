function [poses, extrinsics]=readRobotPoses(robot_poses_vec,valid_idx)

poses = zeros(4,4,size(robot_poses_vec,3));
extrinsics = zeros(4,4,size(robot_poses_vec,3));

%read valid poses and reshape them to 4x4xn matrix
for i=1:size(robot_poses_vec,3)
	poses(:,:,i)=robot_poses_vec(:,:,i);
	extrinsics(:,:,i)=[poses(1:3,1:3,i)' -poses(1:3,1:3,i)'*poses(1:3,4,i);[0 0 0 1]];
end

% keep valid poses that have corresponding image with detected feature points
poses=poses(:,:,valid_idx);
extrinsics=extrinsics(:,:,valid_idx);
    

