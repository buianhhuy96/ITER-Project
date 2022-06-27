function [ret] = isT(T)
%IST Summary of this function goes here
%   Detailed explanation goes here
smallNumber = 0.000001;
ret = true;
if any(abs(T( 1:3,4)) > smallNumber)
   ret = false;
end
if any(abs(T(4,4)-1) > smallNumber)
    ret = false;
end
%R = T(1:3,1:3);
R = tform2rotm(T);
if abs(det(R)-1) > smallNumber
    ret = false;
end


end

