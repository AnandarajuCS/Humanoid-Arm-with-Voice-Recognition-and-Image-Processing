

#include <Servo.h> 
 
Servo left;  
Servo right; 
Servo el;

void setup() 
{ 
  left.attach(12); 
  right.attach(9);
  el.attach(7);
  left.write(136);
  right.write(136);
  el.write(150);
  
} 
 
 
void loop() 
{ 

} 
