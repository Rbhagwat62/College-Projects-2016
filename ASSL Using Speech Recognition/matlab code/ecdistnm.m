function d = ecdistnm(x, y)

% calculates euclidean distance between 3*2 vectors
% (x1.x1 x1.x2...x1.xm)   &  (y1.y1 y1.y2...y1.ym)   
% (x2.x1 x2.x2...x2.xm)   &  (y2.y1 y2.y2...y2.ym)
% (x3.x1 x3.x2...x3.xm)   &  (y3.y1 y3.y2...y3.ym)
% ...................       .....................
% ...................       .....................
% ...................       .....................
% (xn.x1 xn.x2...xn.xm)      (yn.y1 yn.y2...yn.ym)


[r1 c1]=size(x);
[r2 c2]=size(y);

if (r1 ~= r2)
    error('Matrix dimensions do not match.')
end

d = zeros(c1,c2);

for i=1:c1
    for j=1:c2
       d(i,j)= sum((x(:,i)-y(:,j)).^2);     
    end
end

d=d.^0.5;