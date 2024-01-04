
#include <Preferences.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

#define WIFIRSTPIN 23

Preferences preferences;
AsyncWebServer server(80);

String wifiMacString = WiFi.macAddress();
String appendToSsid = wifiMacString.substring(9,11)+wifiMacString.substring(12,14)+wifiMacString.substring(15,17);
String ssid     = "Object_"+appendToSsid;
String password = "1234567890";
String ssid_sta;
String pass_sta;

void setup()
{
    Serial.begin(115200);
    pinMode(WIFIRSTPIN, INPUT_PULLUP);
    preferences.begin("wifi", false);
    ssid_sta=preferences.getString("ssid");
    pass_sta=preferences.getString("pass");
    if (ssid_sta == ""){
        Serial.println("\n[*] Creating AP");
        WiFi.mode(WIFI_AP);
        WiFi.softAP(ssid, password);
        Serial.print("[+] AP Created with IP Gateway ");
        Serial.println(WiFi.softAPIP());
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(WIFIRSTPIN)==0) {
    preferences.clear();
    preferences.end();
    ESP.restart();
  }
}
