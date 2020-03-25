const int led[]={13,11,9};
void setup()
{
  for(int i=0;i<3;i++)
  {
pinMode(led[i],OUTPUT);
  }
Serial.begin(9600);
}

void loop() {
 for(int i=0;i<3;i++)
 {  
 digitalWrite(led[i],HIGH);
 Serial.println("LED IS ON");
 delay(2000);
 digitalWrite(led[i],LOW);
 Serial.println("LED IS OFF");
 delay(2000);
 }
}
 
