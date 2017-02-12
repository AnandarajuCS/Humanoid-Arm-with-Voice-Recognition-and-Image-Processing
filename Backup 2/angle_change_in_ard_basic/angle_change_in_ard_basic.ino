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
int angcode=0;

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
 elbow.write(120);

  for(pos = 30; pos < 140; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    elbow.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(25);                       // waits 15ms for the servo to reach the position 
  } 
  delay(1000);
  
  for(pos = 120; pos > 30; pos -= 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    shld1.write(pos);              // tell servo to go to position in variable 'pos' 
    shld2.write(pos);              // tell servo to go to position in variable 'pos'     
    delay(25);                       // waits 15ms for the servo to reach the position 
  } 
  delay(1000);
  
  for(pos = 140; pos > 30; pos -= 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    elbow.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(25);                       // waits 15ms for the servo to reach the position 
  } 
}

void loop()
{

  //   pos1=shld1.read();
     pos2=shld3.read();
//   pos3=elbow.read();
//   pos4=palm.read();   
  if (Serial.available() > 0)
   {
   incom=Serial.read();
   Serial.println(pos2);
   }
   if(incom==111)
   {
     for(pos = 10; pos < 120; pos += 1)  // goes from 0 degrees to 180 degrees 
     {                                  // in steps of 1 degree 
        shld1.write(pos);              // tell servo to go to position in variable 'pos' 
        shld2.write(pos);              // tell servo to go to position in variable 'pos'     
        delay(25);                       // waits 15ms for the servo to reach the position 
     } 
     incom=0;
   }     
   if(incom!=0)
   {
     motor_code=incom/10;
     angcode=incom-motor_code*10;
     
     if(angcode==1)
     {
       motor_angle=pos2+5;
     }
     if(angcode==2)
     {
       motor_angle=pos2-5;
     }
     angcode=0;

     if(motor_code==3)
     {
        if(pos2 > motor_angle) // works when the currrent position of the
        {

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
}
