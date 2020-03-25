 #include<DHT.h>
 #define DHTPIN 13
 #define DHTTYPE DHT11
 DHT dht(DHTPIN,DHTTYPE);
 
 void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
delay(500);
float temp=dht.readTemperature();
float humidity=dht.readHumidity();
if(isnan(temp)||isnan(humidity))
{
  Serial.print("cannot read data from sensor");
  
  }
Serial.print("The temperature is:");
Serial.println(temp);
Serial.print("the Humidity is:");
Serial.println(humidity);
delay(5000);

}
