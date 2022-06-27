function [err2] = costFunc1(imgPts,Wpts,K,x)
        selectRow12=@(x) x(1:2,:);
        normbyZ = @(ptProj) selectRow12(bsxfun(@rdivide, ptProj, ptProj(3,:)));% % Divide with Z to complete the perspective projection and the removing the unit 1  as a resultant of the division

        imgP=imgPts;
        comb = @(val) norm(val)/sqrt(length(val)); 
        HT = @(val)   (    [[quat2rotm(val(1:4)) val(5:7)']; [0 0 0 1] ]  )  ; % either inv(Z)*A*X 
        proj=(  normbyZ(K*(HT(x))*Wpts) )'; %need to invert HT befor invR, if the representation change of whole inverse is followed                        
        err=imgP - proj;
        
        
        err=reshape(permute(err,[2,1,3]),size(err,2),[])';%This is forbenius norm (L2), extra line for the fmincon. Remove this line if using lsqnonlin
        err2=sqrt(sum(err(:).^2));%This is forbenius norm (L2), extra line for the fmincon. Remove this line if using lsqnonlin


