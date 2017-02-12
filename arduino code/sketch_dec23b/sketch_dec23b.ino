#include <Servo.h>

Servo elbow;

int incom=0;
int pos=0;
int pos2=0;
int motor_code;
int motor_angle;
void setup()
{
 Serial.begin(9600);
 elbow.attach(7);
 
 elbow.write(30);
 
}

void loop()
{
  while(1)
  {
  
  incom=Serial.read();

   if(incom==2)
   {
     pos2=elbow.read();
     pos=pos2;
     Serial.println(pos2);
   }

if(incom != 2 && incom!=0)
{
     motor_code=incom/1000;
     motor_angle=incom-motor_code*1000;
   
   
   if(pos > motor_angle) // works when the currrent position of the
   {
     for( ; pos > motor_angle ; pos-=1)
     {
       elbow.write(pos);
       delay(25);
     }
   incom=0;
   continue;

   }
   if(pos < motor_angle)
   {
     for( ; pos < motor_angle ; pos+=1)
     {
       elbow.write(pos);
       delay(25);
     }
   incom=0;
   continue;

   }
}
}
}
