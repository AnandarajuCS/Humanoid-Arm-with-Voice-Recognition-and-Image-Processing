int v1=11;
int v2=10;
int v3=A0;
int v4=A1;
int v5=A2;
int v6=A3;
int v7=A4;
int v8=A5;

int c1=0;
int c2=0;
int c3=0;
int c4=0;
int c5=0;
int c6=0;
int c7=0;
int c8=0;

int code=0;
int code1=0;
int code2=0;
int newcode=0;
int incom;

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
  pinMode(v1, INPUT);
  pinMode(v2, INPUT);
  pinMode(v3, INPUT);
  pinMode(v4, INPUT);
  pinMode(v5, INPUT);
  pinMode(v6, INPUT);
  pinMode(v7, INPUT);
  pinMode(v8, INPUT);

 Serial.begin(9600);
  shld1.attach(12);  // attaches the servo on pin 9 to the servo object   
    shld2.attach(9);  // attaches the servo on pin 9 to the servo object 
      shld3.attach(8);  // attaches the servo on pin 9 to the servo object 
        elbow.attach(7);  // attaches the servo on pin 9 to the servo object 
          palm.attach(4);  // attaches the servo on pin 9 to the servo object 

shld1.write(120);
shld2.write(120);
shld3.write(90);
elbow.write(120);

digitalWrite(13,LOW);
}

void loop()
{
  
  c1=digitalRead(v1);
  c2=digitalRead(v2);
  c3=digitalRead(v3);
  c4=digitalRead(v4);
  c5=digitalRead(v5);
  c6=digitalRead(v6);
  c7=digitalRead(v7);
  c8=digitalRead(v8);
  
  code1=c4*8 + c3*4 + c2*2 + c1*1;
  code2=c8*8 + c7*4 + c6*2 + c5*1;
  // testing with led
  
  
    code=code2 + 10*code1;
    
    if(newcode!=code)
  {
  Serial.println(code);
//  delay(1000);
  } 
  newcode=code;
  
  // ***** beginning of receiving the code fro MATLAB
// if(Serial.available() > 0)
 { 
     incom = Serial.read();
 }
 
 if(incom==49) // for opening and closing palm
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
 
 if(incom==50) // elbow
 {
   for(pos = 120; pos < 160; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    elbow.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(25);                       // waits 15ms for the servo to reach the position 
  } 

   for(pos = 160; pos>=120; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    elbow.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(25);                       // waits 15ms for the servo to reach the position 
  } 
  delay(1000);
 }  // end of code 2
 
 if(incom==51) // shoulder 3
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

if(incom==52) // shld 1 & 2
{
  digitalWrite(13,HIGH);
  for(pos = 120; pos>=10; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    shld1.write(pos);              // tell servo to go to position in variable 'pos' 
    shld2.write(pos);              // tell servo to go to position in variable 'pos'     
    delay(25);                       // waits 15ms for the servo to reach the position 
  } 
  delay(1000);

  for(pos = 10; pos < 120; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    shld1.write(pos);              // tell servo to go to position in variable 'pos' 
    shld2.write(pos);              // tell servo to go to position in variable 'pos'     
    delay(25);                       // waits 15ms for the servo to reach the position 
  }
  delay(1000);

}// end cof code 4
  
  
} // end of loop segment...
