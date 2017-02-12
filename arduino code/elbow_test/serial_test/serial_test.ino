int led=13;
void setup()
{
    pinMode(led, OUTPUT);     
// initialize serial
Serial.begin(9600);
  digitalWrite(led, HIGH);   
  delay(2000);
  digitalWrite(led, LOW);     

}


void loop()
{
Serial.println(15);

  byte k = Serial.read();
  if(k==12)
  {
  digitalWrite(led, HIGH);   
  delay(2000);
  digitalWrite(led, LOW);     
  } 

}
