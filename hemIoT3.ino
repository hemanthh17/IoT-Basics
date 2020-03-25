const int led=13;
const int sensor=12;
int i=0;
int present=1;
int past=1;
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(sensor,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
present=digitalRead(sensor);
if(present!=past)
{
  if(present==1)
  {
    Serial.println("Obstruction detected!");
    i=i+1;
    Serial.println(i);
    }
    past=present;
    delay(1000);
  }
  else
  {
    Serial.println("Obstruction not detected!");
    delay(1000);
    }
}
