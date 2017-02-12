#include <Servo.h>

Servo shld3;
int pos=0;
void setup()
{
  shld3.attach(8);
}

void loop()
{
  for(pos = 90; pos<=150; pos+=1)     // goes from 180 degrees to 0 degrees 
  {                                
    shld3.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(25);                       // waits 15ms for the servo to reach the position 
  } 
  delay(1000);
  
   for(pos = 150; pos >= 90; pos -= 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    shld3.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(25);                       // waits 15ms for the servo to reach the position 
  } 
  delay(1000);
  
  for(pos = 90; pos > 30; pos -= 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    shld3.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(25);                       // waits 15ms for the servo to reach the position 
  }
  delay(1000);
  
  for(pos = 30; pos<=90; pos+=1)     // goes from 180 degrees to 0 degrees 
  {                                
    shld3.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(25);                       // waits 15ms for the servo to reach the position 
  } 
  delay(1000);
  
  
}
