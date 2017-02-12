function key = angval(s,motcode)
fwrite(s,motcode);
% pause(.5);
key=fscanf(s)
% key=astonum(key)