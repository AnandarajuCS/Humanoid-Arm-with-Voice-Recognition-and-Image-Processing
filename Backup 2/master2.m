clc
% % obtaining distance from the function
% instrreset
% s=serial('COM3','Baudrate',9600);
% fopen(s);
[d mk]=distance();
d1=d;
% fwrite(s,31);
% new_dist=distance();

% d1=new_dist;

%while new_dist<d % d=50; new_dist=40; so d1=40; d2=30
%     d1=distance();
while(mk==2)
    fwrite(s,31);
    d2=distance();
    if(d2>d1)
        fwrite(s,32);
        break;
    end
    d1=d2;    
end

% while new_dist>d   % d=50; new_dist=60; so d1=50; d2=40
while(mk==1)
    fwrite(s,32);
    d2=distance();
    if(d2>d1)
        fwrite(s,31);
        break;
    end
    d1=d2;
end