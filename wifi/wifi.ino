
#include <Preferences.h>
#include <WiFi.h>



Preferences preferences;

const char* ssid     = "Object";
const char* password = "1234567890";
String ssid_sta;
String pass_sta;

void setup()
{
    Serial.begin(115200);
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

}
