#include <Servo.h> 
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
int incom=0;
int co;
int pos=0;
 Servo palm;
 
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

  pinMode(13, OUTPUT);  
  co=0;
  
            palm.attach(4);  // attaches the servo on pin 9 to the servo object 
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
  
    code=code2 + 10*code1;

//code=1;
  if(newcode!=code)
  {
  Serial.println(code);
//  delay(200);
  }
  newcode=code;
  
    // ***** beginning of receiving the code fro MATLAB
    
         incom = Serial.read();
         
 if(incom==49) // for opening and closing palm
 {
   incom=0;        
   digitalWrite(13,HIGH);
   delay(2000);
   digitalWrite(13,LOW);  
   delay(2000);
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
 
    
}
