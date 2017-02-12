

#include <Servo.h> 
 
Servo shld1;
Servo shld2;     
Servo shld3;
Servo elbow;
Servo palm;
 
//int shld[6] = {70,80,90,100,110,120};
//int elbow[6] = {68,76,84,92,100,108};
int shld=136;
int el=150;
void setup() 
{ 
 shld1.attach(12);
 shld2.attach(9); 
 shld3.attach(8); 
 elbow.attach(7); 
 palm.attach(4);  
 
 shld3.write(90);
 while(el>30)
 {
 shld1.write(shld);
 shld2.write(shld);
 elbow.write(el);
 shld=shld-8;
 el=el-10;
 delay(2000);
 }
} 
 
 
void loop() 
{ 

} 
