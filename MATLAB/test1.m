a=imread('pic.jpg');
[x y z]=size(a);
new=ones(x,y);
new1=ones(x,y);
new2=ones(x,y);

for i=1:x
    for j=1:y
        if(a(i,j,1)>=230 && a(i,j,2)<=50 && a(i,j,3)<=50)
            new(i,j)=0;
        end
    end
end
imshow(new);
figure;
for i=1:x
    for j=1:y
        if(a(i,j,1)<=50 && a(i,j,2)<=50 && a(i,j,3)>=230)
            new1(i,j)=0;
        end
    end
end
imshow(new1);
figure;
for i=1:x
    for j=1:y
        if(a(i,j,1)<=50 && a(i,j,2)>=230 && a(i,j,3)<=50)
            new2(i,j)=0;
        end
    end
end
imshow(new2);
clear