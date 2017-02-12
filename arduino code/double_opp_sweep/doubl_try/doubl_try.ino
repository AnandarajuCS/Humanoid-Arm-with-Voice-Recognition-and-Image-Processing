// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
Servo myservo1;
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
int ref=0; 
void setup() 
{ 
  myservo.attach(12);  // attaches the servo on pin 9 to the servo object 
  myservo1.attach(8);
  myservo.write(0);
  myservo1.write(120);
} 
 
 
void loop() 
{ 
  for(pos = 0; pos<=120; pos+=1)     // goes from 180 degrees to 0 degrees 
  {                                
    delay(15);
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    myservo1.write(pos);
                           // waits 15ms for the servo to reach the position 
  } 
  delay(1000);

  for(pos = 120; pos >=0; pos -= 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    delay(15);


    myservo1.write(pos);
    myservo.write(pos);              // tell servo to go to position in variable 'pos'                            // waits 15ms for the servo to reach the position 
  } 
  delay(1000);
} 
