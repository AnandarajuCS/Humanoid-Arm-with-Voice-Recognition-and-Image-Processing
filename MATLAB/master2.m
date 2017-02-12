clc
% % obtaining distance from the function
% instrreset
% s=serial('COM3','Baudrate',9600);
% fopen(s);
[d x1 x2 y1 y2]=distance();
d1=d % say current distence is 50 and naturally  x1(arm) is > x2(bottle)
% fwrite(s,31);
% new_dist=distance();

% d1=new_dist;

%while new_dist<d % d=50; new_dist=40; so d1=40; d2=30
%     d1=distance();
% while(mk==2)
while(x1<x2)
    fwrite(s,31);
    d2=distance();
    if(d2>d1)
        fwrite(s,32);
        break;
    end
    d1=d2;    
end

% while new_dist>d   % d=50; new_dist=60; so d1=50; d2=40
% while(mk==1)
while(x1>x2) % d1=50;
    fwrite(s,32);
    d2=distance()  %d2=40
    if(d2>d1)
        fwrite(s,31);
        break;
    end
    d1=d2; 
end