
#include <Preferences.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>



Preferences preferences;
AsyncWebServer server(80);

String ssid="";
String pass="";



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  preferences.begin("wifi", false);
  ssid = preferences.getString("ssid");
  if (ssid=="") {
    Serial.println("Nema snimljena mreza...");
    preferences.putString("ssid", "VesnaR_3");
    }
  else {
    
  }
  preferences.end();
}

void loop() {
  // put your main code here, to run repeatedly:

}
