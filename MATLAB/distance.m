% find distance with the img and img in different images
function [dist x1 x2 y1 y2]= distance(color)
% function [dist mk]= distance(img)
vid=videoinput('winvideo',1, 'YUY2_320x240');
img=getsnapshot(vid);
img=ycbcr2rgb(img);
% imshow(img);
du=0;
figure
% img=imread('bot.jpg');
% img=imread('img.jpg');
% a=imread('pic.jpg');
% b=im2bw(a,0.5);
% b=~b;
% [B L]=bwboundaries(b);

se=strel('disk',5);

% filter yellow color

siz=size(img);
im1=zeros(siz(1),siz(2));
for i=1:siz(1)
    for j=1:siz(2)
%         if(img(i,j,1)>=75 && img(i,j,2)<=70 && img(i,j,3)<=70)
        if(img(i,j,1)>=100 && img(i,j,2)>=70 && img(i,j,3)<=30) %yellow           
%             for k=1:3
%                 if(img(i+k,j,1)>=45 && img(i+k,j,2)>=45 && img(i+k,j,3)<=10)
%                     if(img(i,j+k,1)>=45 && img(i,j+k,2)>=45 && img(i,j+k,3)<=10)
%                     du=1;
%                     end
%                 else
%                     du=0;
%                 end
%             end
%             if du==1
                im1(i,j)=1;
%             end
        end
    end
end
im1=imclose(im1,se);

siz=size(img);
im2=zeros(siz(1),siz(2));

if color==1  % filter blue color
for i=1:siz(1)
    for j=1:siz(2)
        if(img(i,j,1)<=45 && img(i,j,2)<=70 && img(i,j,3)>=85)
            im2(i,j)=1;
        end
    end
end
end

if color==2  % filter green color
for i=1:siz(1)
    for j=1:siz(2)
        if(img(i,j,1)<=45 && img(i,j,2)>=70 && img(i,j,3)<=70)
            im2(i,j)=1;
        end
    end
end
end    

im2=imclose(im2,se);


im=im1+im2;
% imshow(im1)
% figure
% imshow(im2)
imshow(im);
% 
[B1 L1]=bwboundaries(im1);
stat1=regionprops(L1,'Centroid');
x1=stat1(1).Centroid(1); % co ordinate of arm
y1=stat1(1).Centroid(2);

[B2 L2]=bwboundaries(im2);
stat2=regionprops(L2,'Centroid');
x2=stat2(1).Centroid(1); % co ordinate of bottle
y2=stat2(1).Centroid(2);

x=(x2-x1)^2;
y=(y2-y1)^2;
dist=x+y;
dist=sqrt(dist); % distance between the bottle and the img is found

% % if(x1>x2)
% %     mx=1;
% % elseif(x1<x2)
% %     mx=2;
% % end
% 
% % if(y1>y2)
% %     my=3;
% % elseif(y1<y2)
% %     my=4;
end
