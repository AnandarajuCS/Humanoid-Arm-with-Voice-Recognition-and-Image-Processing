#include <Servo.h>

Servo elbow;
int pos=0;
void setup()
{
  elbow.attach(7);
  elbow.write(30);
}

void loop()
{
  for(pos = 30; pos<=140; pos+=1)     // goes from 180 degrees to 0 degrees 
  {                                
    elbow.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(25);                       // waits 15ms for the servo to reach the position 
  } 
  delay(1000);
  
   for(pos = 140; pos >= 30; pos -= 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    elbow.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(25);                       // waits 15ms for the servo to reach the position 
  } 
  delay(1000);
    
}
