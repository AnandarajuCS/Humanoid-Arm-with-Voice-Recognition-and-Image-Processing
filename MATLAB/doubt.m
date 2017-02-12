clear
[d x1 x2 y1 y2]=distance();
% x1,y1 arm co ordinates   x2,y2 bottle co ordinates
ptax=x2;
ptay=y2;

ptbx=x1;
ptby=y1;

ptcx=x1+30
ptcy=240

% points assigned

% calculating distance
dac=(((ptax-ptcx)^2) + ((ptay-ptcy)^2))^.5

% dab=(((ptax-ptbx)^2) + ((ptay-ptby)^2))^.5;