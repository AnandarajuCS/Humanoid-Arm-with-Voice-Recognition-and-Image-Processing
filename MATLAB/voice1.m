fopen(s)
incoming=0;
outgoing=0;
% c;
% for i=0:25
while (1)
    
    if (s.BytesAvailable > 0)
        incoming=fscanf(s);
        incoming
        si=size(incoming);
        if(si(2)>3)
            continue;
        end
        pause(.5);
        c=incoming(1);
        d=cast(c,'int8');
        outgoing=d;
%         outgoing=cast(incoming(1),'uint8');
        fwrite(s,outgoing);
    else
        disp('Waiting...');
        pause(.5);
    end
end    
fclose(s)