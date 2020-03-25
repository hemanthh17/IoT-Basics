#include<ESP8266WiFi.h>
const int led=13;
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
const char *ssid="RAVIKUMAR";
const char *pass="itm16act";
Serial.begin(115200);
Serial.println("WiFi connection is starting");
Serial.println(ssid);
WiFi.begin(ssid,pass);
while(WiFi.status()!=WL_CONNECTED)
{
  delay(500);
  Serial.println(".");
  digitalWrite(led,HIGH);
  delay(500);
  digitalWrite(led,LOW);
  }
Serial.println();
digitalWrite(led,HIGH);
Serial.println("WiFi connected successfully");
Serial.println("NodeMCU IP Address is:");
Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
int n=WiFi.scanNetworks();
Serial.println("scanning networks");
if(n==0)
{
  Serial.println("No networks found");
  delay(200);
  }
else
{
  Serial.print(n);
  Serial.println("Networks found");
  }
  for(int i=0;i<n;i++)
  {
    Serial.print(i+1);
    Serial.print(":");
    Serial.print(WiFi.SSID(i));
    Serial.print("");
    Serial.print(WiFi.RSSI(i));
    delay(100);
    Serial.println();
  }
  delay(5000);
  Serial.flush();
  }
