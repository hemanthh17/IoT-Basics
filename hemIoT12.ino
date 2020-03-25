#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>//WiFi.begin
#include <ESP8266HTTPClient.h>
#define USE_SERIAL Serial
ESP8266WiFiMulti WiFiMulti;
const int relay = 13;//D7
void setup() {
 
    //pinMode(LED_BUILTIN, OUTPUT);  
    pinMode(relay, OUTPUT);
    
    USE_SERIAL.begin(115200);
   // USE_SERIAL.setDebugOutput(true);
 
    //USE_SERIAL.println();
    //USE_SERIAL.println();
    //USE_SERIAL.println();
 
    for(uint8_t t = 4; t > 0; t--) {
        USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);
        USE_SERIAL.flush();
        delay(1000);
    }
 
    WiFiMulti.addAP("RAVIKUMAR", "itm16act" );
 
}
 
void loop() {
    // wait for WiFi connection
    if((WiFiMulti.run() == WL_CONNECTED)) {
 
        HTTPClient http;
 
        USE_SERIAL.print("[HTTP] begin...\n");
       
        http.begin("http://api.thingspeak.com/talkbacks/33245/commands/15915377?api_key=FDDVC6V8L1R57SDN"); //1. talkback id 2. command id 3. api_key
        //https://api.thingspeak.com/talkbacks/28085/commands/13944502?api_key=HAD5ZQNY1DLZ5MGN
        USE_SERIAL.print("[HTTP] GET...\n");
       
        // start connection and send HTTP header
        int httpCode = http.GET();
 
        
       
        if(httpCode > 0) {
            // HTTP header has been send and Server response header has been handled
            USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);
 
            // file found at server
            if(httpCode == HTTP_CODE_OK) //200
            {
                String payload = http.getString();
                USE_SERIAL.println(payload);
            if(payload=="LEDOFF")
            {
              digitalWrite(relay, LOW);  
              USE_SERIAL.println("LED IS OFF");
            }
            else if(payload=="LEDON")
            {
              digitalWrite(relay, HIGH);
              USE_SERIAL.println("LED IS ON");
            }
              
            
        else {
            USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }
 
        http.end();
    }
 
    delay(2000);
}}}
