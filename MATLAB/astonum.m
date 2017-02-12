function num = astonum(x)
y=cast(x,'uint8');
siz=size(y);

for i=1:(siz(2)-2)
    if(y(i)==48)
        y(i)=0;
    elseif(y(i)==49)
        y(i)=1;
    elseif(y(i)==50)
        y(i)=2;
    elseif(y(i)==51)
        y(i)=3;
    elseif(y(i)==52)
        y(i)=4;
    elseif(y(i)==53)
        y(i)=5;
    elseif(y(i)==54)
        y(i)=6;
    elseif(y(i)==55)
        y(i)=7;
    elseif(y(i)==56)
        y(i)=8;
    elseif(y(i)==57)
        y(i)=9;
    end
end
% y
% y=fliplr(y);
num=0;
t=zeros(1:(siz(2)-2));
for k=1:(siz(2)-2)
    t(k)=10^(k-1);
end
t=fliplr(t);
% y(1)
for j=1:(siz(2)-2)
    num=num+y(j)*t(j);
end
% num
