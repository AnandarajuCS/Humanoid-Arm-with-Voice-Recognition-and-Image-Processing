#include <Servo.h>

 Servo shld1;
 Servo shld2;     
 Servo shld3;
 Servo elbow;
 Servo palm;

int pos=0;
int incom=0;
int motor_code=0;
int motor_angle=0;
int limit;
//int motor_angle=0;

int pos1=0;
int pos2=0;
int pos3=0;
int pos4=0;

void setup()
{

 Serial.begin(9600);
 shld1.attach(12);
 shld2.attach(9); 
 shld3.attach(8); 
 elbow.attach(7); 
 palm.attach(4);  

 shld1.write(120);
 shld2.write(120);
 shld3.write(90);
 elbow.write(30);
  
}

void loop()
{

  incom = Serial.read();  
   if(incom==1)
   {
     pos1=palm.read();
     pos=pos1;
     Serial.println(pos1);
   }
   if(incom==2)
   {
     pos2=elbow.read();
     pos=pos2;
     Serial.println(pos2);
   }
   if(incom==3)
   {
     pos3=shld3.read();
     pos=pos3;
     Serial.println(pos3);
   }
   if(incom==4)
   {
     pos4=shld1.read();
     pos=pos4
     Serial.println(pos4);
   }
   if(incom !=1 && incom !=2 && incom !=3 && incom !=4)
   {
     motor_code=incom/1000;
     motor_angle=incom-motor_code*1000;
   
   
   if(pos > motor_angle) // works when the currrent position of the
   {
     for( ; pos > motor_angle ; pos-=1)
     {
       shld3.write(pos);
       delay(25);
     }
   }
   
   if(pos < motor_angle)
   {
     for( ; pos < motor_angle ; pos+=1)
     {
       shld3.write(pos);
       delay(25);
     }
   }
   }   
}
