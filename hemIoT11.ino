#include<DHT.h>
#define DHTPIN 13
DHT dht(DHTPIN,DHT11);
char *ssid="Lucky";
char *pass="lucky000@";
String apiKey="SR665FACG4D5JYKU ";
void setup() {
  Serial2.begin(115200);
  Serial.begin(9600);
  delay(10);
  dht.begin();
  delay(100);
  connectWifi();
}

void loop() {
  float j=dht.readTemperature();
  if (isnan(j))
  {
    Serial.println("Failed to read from DHT Sensor");
    return;
   
  }
  Serial2.println("AT+CIPMUX=0\r\n");
  delay(2000);
  String cmd="AT+CIPSTART=\"TCP\",\"";
  cmd += "api.thingspeak.com";
  cmd += "\",80\r\n\r\n";
  Serial2.println(cmd);
  Serial.println(cmd);
  delay(20000);
  if(Serial2.find("ERROR"))
  {
    Serial.println("AT+CIPSTART error");
  }//https://api.thingspeak.com/update?apikey=gdhgfh&field1=0
  String getStr="GET /update?api_key=";
  getStr += apiKey;
  getStr += "&field1=";
  getStr += j;
  getStr += "\r\n\r\n";
  Serial.println(getStr);
  cmd="AT+CIPSEND=";
  cmd += String(getStr.length());
  cmd += "\r\n";
  Serial2.println(cmd);
  Serial.println(cmd);
  delay(10000);
  if(Serial2.find(">"))
  {
    Serial.println("Connected to cloud");
    Serial2.print(getStr);
  }
  else
  {
    Serial2.println("AT+CIPCLOSE\r\n");
    Serial.println("AT+CIPCLOSE");
  }
  delay(16000);

  
}
void connectWifi()
{
  Serial2.println("AT+CWMODE=1");
  delay(1000);
  Serial2.print("AT+CWJAP=");
  delay(200);
  Serial2.write(0x22);
  delay(1000);
  Serial2.print(ssid);
  delay(20);
  Serial2.write(0x22);
  delay(20);
  Serial2.write(0x2c);
  delay(20);
  Serial2.write(0x22);
  delay(20);
  Serial2.print(pass);
  delay(20);
  Serial2.write(0x22);
  Serial2.write(0x0D);
  Serial2.write(0x0A);
  delay(5000);
  status();

}
void status()
{
  delay(5000);
  Serial2.println("AT+CWJAP?");
  if(Serial2.find("+CWJAP:"))
  {
    Serial.println("OK, Connected to WiFi.");
    IpAddress();
    
  }
  else
  {
    Serial.println("Can not connect to the WiFi.");
  }
  Serial.println(Serial2.readString());
}
void IpAddress()
{
  delay(2000);
  Serial2.println("AT+CIFSR");
  Serial.println(Serial2.readString());
}
