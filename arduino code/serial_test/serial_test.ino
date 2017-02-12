int led=13;
int code=15;
void setup()
{
    pinMode(led, OUTPUT);     
// initialize serial
Serial.begin(9600);
//  digitalWrite(led, HIGH);   
//  delay(2000);
//  digitalWrite(led, LOW);     

}


void loop()
{
Serial.println(code);
delay(500);

  byte k = Serial.read();
  if(k==12)
  {
  digitalWrite(led, HIGH);   
  delay(2000);
  digitalWrite(led, LOW);     
  } 

}
