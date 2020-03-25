const int led=13;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial1.begin(9600);
pinMode(led,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:

if(Serial1.available()>0)
{
  delay(100);
  int val=Serial1.read();
if(val=='a')
{
  digitalWrite(led,HIGH);
  Serial.println("LED will be on");
  
  }
  
 else if(val=='b')
  {
    digitalWrite(led,LOW);
    Serial.println("LED will be off");
    }
}
}
