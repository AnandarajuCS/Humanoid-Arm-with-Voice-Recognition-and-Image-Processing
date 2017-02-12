

#include <Servo.h> 
 
Servo left;  
Servo right; 
 

void setup() 
{ 
  left.attach(12); 
  right.attach(9);
  left.write(90);
  right.write(90);
} 
 
 
void loop() 
{ 

} 
