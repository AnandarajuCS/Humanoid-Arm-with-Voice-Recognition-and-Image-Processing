#include <Servo.h> 
 Servo shld1;  // create servo object to control a servo 
 Servo shld2;     
 Servo shld3;
 Servo elbow;
 Servo palm;
 
 // a maximum of eight servo objects can be created 
 int pos = 0;    // variable to store the servo position 


void setup()
{
 Serial.begin(9600);
  shld1.attach(12);  // attaches the servo on pin 9 to the servo object   
    shld2.attach(9);  // attaches the servo on pin 9 to the servo object 
      shld3.attach(8);  // attaches the servo on pin 9 to the servo object 
        elbow.attach(7);  // attaches the servo on pin 9 to the servo object 
          palm.attach(4);  // attaches the servo on pin 9 to the servo object 

shld1.write(120);
shld2.write(120);
shld3.write(90);
elbow.write(30);
}


void loop()
{
 byte code = Serial.read();
 
 if(code==1) // for opening and closing palm
 {
   for(pos = 30; pos < 160; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    palm.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  delay(1000);
  for(pos = 160; pos>=30; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    palm.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
 }  // end of code 1
 
 if(code==2) // elbow
 {
   for(pos = 30; pos < 140; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    elbow.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(25);                       // waits 15ms for the servo to reach the position 
  } 

   for(pos = 140; pos>=30; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    elbow.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(25);                       // waits 15ms for the servo to reach the position 
  } 
  delay(1000);
 }  // end of code 2
 
 if(code==3) // shoulder 3
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
 } // end of code 3

if(code==4) // shld 1 & 2
{
  
  for(pos = 120; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    shld1.write(pos);              // tell servo to go to position in variable 'pos' 
    shld2.write(pos);              // tell servo to go to position in variable 'pos'     
    delay(25);                       // waits 15ms for the servo to reach the position 
  } 
  delay(1000);

  for(pos = 0; pos < 120; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    shld1.write(pos);              // tell servo to go to position in variable 'pos' 
    shld2.write(pos);              // tell servo to go to position in variable 'pos'     
    delay(25);                       // waits 15ms for the servo to reach the position 
  }
  delay(1000);

}// end cof code 4

}// end of loop section
