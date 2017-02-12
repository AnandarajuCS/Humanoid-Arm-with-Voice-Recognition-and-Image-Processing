clc
% obtaining distance from the function
d=distance()
instrreset
s=serial('COM3','Baudrate',9600);
fopen(s);
motcode=2;
% pause(4);
% fwrite(s,motcode);
% % pause(.5);
% key=fscanf(s)
% key=astonum(key)
key=angval(s,motcode)
key=key+10;
% send=motcode*1000 + key;
move(s,motcode,key);

new_dist=distance();

while new_dist<d
    d1=distance();
    key=key+10;
    move(s,motcode,key);
    d2=distance();
    if(d2>d1)
        break;
    end
end

while new_dist>d
    d1=distance();
    key=key-10;
    move(s,motcode,key);
    d2=distance();
    if(d2>d1)
        break;
    end
end

fclose(s)