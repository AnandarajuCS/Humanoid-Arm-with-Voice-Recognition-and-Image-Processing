#include <Servo.h>

Servo shld1;
Servo shld2;     
Servo shld3;
Servo elbow;
Servo palm;

int incom=0;
int pos=0;
int motor_code;
int motor_angle;

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

//  for(pos = 30; pos < 100; pos += 1)  // goes from 0 degrees to 180 degrees 
//  {                                  // in steps of 1 degree 
//    elbow.write(pos);              // tell servo to go to position in variable 'pos' 
//    delay(25);                       // waits 15ms for the servo to reach the position 
//  } 

  for(pos = 120; pos > 10; pos -= 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    shld1.write(pos);              // tell servo to go to position in variable 'pos' 
    shld2.write(pos);              // tell servo to go to position in variable 'pos'     
    delay(25);                       // waits 15ms for the servo to reach the position 
  } 

}

void loop()
{
   if (Serial.available() > 0)
   {
   incom=Serial.read();
   }
//   pos1=shld1.read();
   pos2=shld3.read();
//   pos3=elbow.read();
//   pos4=palm.read();   
   
   if(incom==2)
   {
   Serial.println(pos2);   
   }

   if(incom!=2 && incom!=0)
   {
     motor_code=incom/1000;
     motor_angle=incom-motor_code*1000;

   if(pos2 > motor_angle) // works when the currrent position of the
   {
     motor_angle=incom;
     for(pos=pos2 ; pos > motor_angle ; pos-=1)
     {
       shld3.write(pos);
       delay(25);
     }
     incom=0;
   }
   
   if(pos2 < motor_angle)
   {
     for(pos=pos2 ; pos < motor_angle ; pos+=1)
     {
       shld3.write(pos);
       delay(25);
     }
   incom=0;
   }
   }
}
