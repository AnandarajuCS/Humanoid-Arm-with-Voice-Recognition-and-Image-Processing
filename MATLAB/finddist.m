target=imread('bottle.jpg');
arm=imread('arm.jpg');
% a=imread('pic.jpg');
% b=im2bw(a,0.5);
% b=~b;
% [B L]=bwboundaries(b);


% filter bottle having red color

siz=size(target);
im1=zeros(siz(1),siz(2));
for i=1:siz(1)
    for j=1:siz(2)
        if(target(i,j,1)>=230 && target(i,j,2)<=50 && target(i,j,3)<=50)
            im1(i,j)=1;
        end
    end
end

% filter arm having blue color

siz=size(target);
im2=zeros(siz(1),siz(2));
for i=1:siz(1)
    for j=1:siz(2)
        if(arm(i,j,1)<=50 && arm(i,j,2)<=50 && arm(i,j,3)>=230)
            im2(i,j)=1;
        end
    end
end

im=im1+im2;
imshow(im);

[B L]=bwboundaries(im);
stat=regionprops(L,'Centroid');
x1=stat(1).Centroid(1);
x2=stat(2).Centroid(1);
y1=stat(1).Centroid(2);
y2=stat(2).Centroid(2);
x=(x2-x1)^2;
y=(y2-y1)^2;
dist=x+y;
dist=sqrt(dist) % distance between the bottle and the arm is found




clear