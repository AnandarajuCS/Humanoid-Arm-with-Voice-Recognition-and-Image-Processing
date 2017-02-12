clc
[d x1 x2 y1 y2]=distance();

ptax=x2;
ptay=y2;
 
% ptbx=x1;
% ptby=y1;

ptcx=x1+30;
ptcy=240;

% points assigned

% calculating distance
dac=(((ptax-ptcx)^2) + ((ptay-ptcy)^2))^.5

while(y1>240-dac)
    fwrite(s,52);
    [d x1 x2 y1 y2]=distance();
end
% d1=d;
% yy=my;

% while(my==3)
%     fwrite(s,52);
%     [d mx my]=distance();
%     if(my>yy)
%         fwrite(s,51);
%         break;
%     end
% %     d1=d2;    
% end
% 
% while(my==4)
%     fwrite(s,51);
%     [d mx my]=distance();
%     if(d2>d1)
%         fwrite(s,52);
%         break;
%     end
%     d1=d2;
% end