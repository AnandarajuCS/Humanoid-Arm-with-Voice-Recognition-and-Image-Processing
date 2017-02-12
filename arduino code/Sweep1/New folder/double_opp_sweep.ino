// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo1;  // create servo object to control a servo 
Servo myservo2;
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
int ref=0; 
void setup() 
{ 
  myservo1.attach(12);  // attaches the servo on pin 9 to the servo object 
  myservo2.attach(9);
} 
 
 
void loop() 
{ 
  for(pos = 120,ref=0; pos>=0; pos-=1,ref+=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo1.write(ref);              // tell servo to go to position in variable 'pos' 
    delay(15);
    myservo2.write(pos);
                           // waits 15ms for the servo to reach the position 
  } 
  delay(1000);

  for(pos = 0,ref=120; pos <= 120; pos += 1,ref-=1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo1.write(ref);              // tell servo to go to position in variable 'pos' 
    delay(15);
    myservo2.write(pos);
      // waits 15ms for the servo to reach the position 
  } 
  delay(1000);
} 
