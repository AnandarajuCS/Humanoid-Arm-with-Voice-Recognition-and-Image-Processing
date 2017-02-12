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
 
 elbow.write(35);
 
}

void loop()
{
   incom=Serial.read();

   if(incom==2)
   {

   pos=elbow.read();
   Serial.println(pos);
   
   }
   
   if(incom==3)
   {
     elbow.write(50);
   }
   
   if(incom!=2 && incom!=3)
   {
     motor_angle=incom;
     for( ; pos > motor_angle ; pos-=1)
     {
       elbow.write(pos);
       delay(25);
     }
     incom=0;
   }
     
     
}

