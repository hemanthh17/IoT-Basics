#include<ESP8266WiFi.h>
#include<PubSubClient.h>
#include<Wire.h>
const char* ssid = "RAVIKUMAR";
const char* password = "itm16act";
const char* mqtt_server="192.168.0.13";
WiFiClient espClient;
PubSubClient client(espClient);
const byte ledPin=13;
void callback(char* topic,byte* payload,unsigned int length)
{
  Serial.print("Message arrived[");
  Serial.print(topic);
  Serial.print("]");
  for(int i=0;i<length;i++)
  {
    char receivedChar = (char)payload[i];
    Serial.print(receivedChar);
    if(receivedChar=='1')
    digitalWrite(ledPin,HIGH);
    if(receivedChar=='0')
    digitalWrite(ledPin,LOW);
  }
  Serial.println();
  
}
void reconnect()
{
  while(!client.connected())
  {
    Serial.print("Attempting MQTT Connection...");
    if(client.connect("ESP8266 Client"))
    {
      Serial.println("connected");
      client.subscribe("ledstatus");
      
    }
    else
    {
      Serial.print("falied,rc=");
      Serial.print(client.state());
      Serial.println("try again in 5 seconds");
      delay(5000);
    }
  }
}
void setup()
{
  Serial.begin(9600);
  client.setServer(mqtt_server,1883);
  client.setCallback(callback);
  pinMode(ledPin,OUTPUT);
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED)
  {
    delay(100);
    Serial.print('.');
    
  }
  Serial.println("");
  Serial.print("Connected to");
  Serial.println(ssid);
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  
}
void loop()
{
  if(!client.connected()){
    reconnect();
  }
  client.loop();
}
