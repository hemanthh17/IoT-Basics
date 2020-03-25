const int led=13;
void setup()
{
pinMode(led,OUTPUT);
Serial.begin(9600);

}

void loop() {
  int value;
  if(Serial.available()>0)
  value=Serial.read();
  if(value=='A')
  {
 digitalWrite(led,HIGH);
 Serial.println("LED IS ON");
 delay(500000);
  }
 else if(value=='B')
 {
 digitalWrite(led,LOW);
 Serial.println("LED IS OFF");
 delay(50000);
}
else
{
  Serial.println("invalid input");
  }
}
