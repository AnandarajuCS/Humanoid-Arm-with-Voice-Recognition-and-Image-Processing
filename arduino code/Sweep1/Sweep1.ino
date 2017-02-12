// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo1;// create servo object to control a servo 
Servo left;  
Servo right; 
Servo el;
//Servo myservo;                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo1.attach(8);
  left.attach(12); 
  right.attach(9);
  el.attach(7);
  myservo1.write(90);
  left.write(60);
  right.write(60);
  el.write(150);
//
//  for(pos = 120; pos>=10; pos-=1)     // goes from 180 degrees to 0 degrees 
//  {                                
//    left.write(pos);              // tell servo to go to position in variable 'pos' 
//    right.write(pos);              // tell servo to go to position in variable 'pos'     
////    myservo.write(pos);              
//    delay(5);                       // waits 15ms for the servo to reach the position 
//  }
//
//  for(pos = 10; pos<=120; pos+=1)     // goes from 180 degrees to 0 degrees 
//  {                                
//    left.write(pos);              // tell servo to go to position in variable 'pos' 
//    right.write(pos);              // tell servo to go to position in variable 'pos'     
////    myservo.write(pos);              
//    delay(5);                       // waits 15ms for the servo to reach the position 
//  } 
// 
//
//  for(pos = 150; pos>=30; pos-=1)     // goes from 180 degrees to 0 degrees 
//  {                                
//    el.write(pos);              // tell servo to go to position in variable 'pos' 
////    myservo.write(pos);              
//    delay(15);                       // waits 15ms for the servo to reach the position 
//  } 

//  myservo.attach(9);
  // attaches the servo on pin 9 to the servo object 
} 
 
 
void loop() 
{ 
//  for(pos = 90; pos>=10; pos-=1)     // goes from 180 degrees to 0 degrees 
//  {                                
//    myservo1.write(pos);              // tell servo to go to position in variable 'pos' 
////    myservo.write(pos);              
//    delay(15);                       // waits 15ms for the servo to reach the position 
//  } 
//  delay(2000);
//  for(pos = 10; pos <= 90; pos += 1)  // goes from 0 degrees to 180 degrees 
//  {                                  // in steps of 1 degree 
//    myservo1.write(pos);              // tell servo to go to position in variable 'pos' 
////    myservo.write(pos);              
//    delay(15);                       // waits 15ms for the servo to reach the position 
//  } 
//  delay(2000);

} 
