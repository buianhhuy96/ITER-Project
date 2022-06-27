% Solves the problem AX=YB
% using the formulation of
%
% Simultaneous Robot/World and Tool/Flange 
% Calibration by Solving Homogeneous Transformation 
% Equations of the form AX=YB
% M. Shah
%
% Mili Shah
% July 2014
function [X,Y,err]=HandeyeShah(As,Bs)
err = int32(0);
AA = reshape(As,4,[],1); 
BB = reshape(Bs,4,[],1);
[m,n]=size(BB); n = n/4;
A = zeros(9*n,18);
T = zeros(9,9);
b = zeros(9*n,1);
for i = 1:n
    Ra = AA(1:3,4*i-3:4*i-1);
    Rb = BB(1:3,4*i-3:4*i-1);
    T = T + kron(Rb,Ra);
end
% Check for NaN in T
if sum(isnan(T(:)))
    err = int32(-201);
end
[u,s,v]=svd(T);
x0 = v(:,1);
y0 = u(:,1);
x1 = reshape(x0,3,3);
x1 = sign(det(x1))/abs(det(x1))^(1/3)*x1;
% Check for NaN in x1
if sum(isnan(x1(:)))
    err = int32(-201);
end
[u,s,v]=svd(x1); x1 = u*v';
y1 = reshape(y0,3,3);
y1 = sign(det(y1))/abs(det(y1))^(1/3)*y1;
% Check for NaN in Y
if sum(isnan(y1(:)))
    err = int32(-201);
end
[u,s,v]=svd(y1); y1 = u*v';
A = zeros(3*n,6);
b = zeros(3*n,1);
for i = 1:n
    A(3*i-2:3*i,:) = [-AA(1:3,4*i-3:4*i-1) eye(3)];
    b(3*i-2:3*i,:) = AA(1:3,4*i) - kron(BB(1:3,4*i)',eye(3))*reshape(y1,9,1);
end
t = A\b;

X = [x1 t(1:3);[0 0 0 1]];
Y = [y1 t(4:6);[0 0 0 1]];