function move(s,x,y)
% s=serial('COM3','Baudrate',9600);
msg=(x*1000) + y;
% fopen(s);
fwrite(s,msg);
% fclose(s);

end