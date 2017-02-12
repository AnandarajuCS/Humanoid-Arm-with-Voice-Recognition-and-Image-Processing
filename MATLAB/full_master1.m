clc
[d x1 x2 y1 y2]=distance(1);
fwrite(s,11);
ptax=x2;
ptay=y2;

ptcx=x1+30;
ptcy=240;

% points assigned

% calculating distance
dac=(((ptax-ptcx)^2) + ((ptay-ptcy)^2))^.5
dac=dac+20;

while(y1>240-dac)
    fwrite(s,52);
    [d x1 x2 y1 y2]=distance(1);
end
% % obtaining distance from the function

[d x1 x2 y1 y2]=distance(1);
d1=d;

while(x1<x2)
    fwrite(s,31);
    [d x1 x2 y1 y2]=distance(1);
    d2=d;
    if(d2>d1)
%         fwrite(s,32);
        break;
    end
    d1=d2;    
end

while(x1>x2)
    fwrite(s,32);
    [d x1 x2 y1 y2]=distance(1);
    d2=d;
    if(d2>d1)
        if(x1>(x2-10))
            break
        end
        %         fwrite(s,31);
        break;
    end
    d1=d2;
end

fwrite(s,12);

