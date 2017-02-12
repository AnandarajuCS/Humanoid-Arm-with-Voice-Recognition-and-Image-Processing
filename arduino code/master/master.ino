#include <Servo.h> 
 Servo myservo1;  // create servo object to control a servo 
 Servo myservo2;     
 Servo myservo3;
 Servo myservo4;
 Servo myservo5;
 
 // a maximum of eight servo objects can be created 
 int pos = 0;    // variable to store the servo position 


void setup()
{
 Serial.begin(9600);
  myservo1.attach(12);  // attaches the servo on pin 9 to the servo object   
    myservo2.attach(9);  // attaches the servo on pin 9 to the servo object 
      myservo3.attach(8);  // attaches the servo on pin 9 to the servo object 
        myservo4.attach(7);  // attaches the servo on pin 9 to the servo object 
          myservo5.attach(4);  // attaches the servo on pin 9 to the servo object 
}


void loop()
{
 byte k = Serial.read();

 if(k==12) // palm
 {
   for(pos = 30; pos < 160; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 160; pos>=30; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
 }
 

 if(k==9) // wrist
 {
   for(pos = 10; pos < 120; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo2.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 120; pos>=10; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo2.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
 }
  

 if(k==8) // elbow
 {
  for(pos = 170; pos>=30; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo3.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(25);                       // waits 15ms for the servo to reach the position 
  } 
   for(pos = 30; pos < 170; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo3.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(25);                       // waits 15ms for the servo to reach the position 
  } 

 }
  
 if(k==7) // shoulder 2
 {
   for(pos = 90; pos < 170; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo4.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(25);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 170; pos>=90; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo4.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(25);                       // waits 15ms for the servo to reach the position 
  } 
 }
  
 if(k==4) // shoulder 1
 {
   for(pos =90; pos < 170; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo5.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(25);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 170; pos>=90; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo5.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(25);                       // waits 15ms for the servo to reach the position 
  } 
 }
   
}
