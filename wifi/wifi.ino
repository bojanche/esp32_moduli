
#include <Preferences.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "index.h"

#define WIFIRSTPIN 23

Preferences preferences;
AsyncWebServer server(80);

typedef struct {
    String no;
    String wifiname;
    String rssi;
} item;
item items[20];
size_t num_items = 0;


String wifiMacString = WiFi.macAddress();
String appendToSsid = wifiMacString.substring(9,11)+wifiMacString.substring(12,14)+wifiMacString.substring(15,17);
String ssid     = "Object_"+appendToSsid;
String password = "1234567890";
String ssid_sta;
String pass_sta;
String processor(const String& var){
  //Serial.println(var);
  if(var == "WIFILIST"){
    String wifi_list = "";
    for (int i=0; i<num_items; i++) {
      wifi_list += "<tr><td>"+items[i].wifiname+"</td><td>"+items[i].rssi+"db</td><td><a href=\"#\">Connect</a></td></tr>";  
      }
    return wifi_list;
  }
  return String();
}

void scanNetwork() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);  
  Serial.println("scan start");

  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  num_items = n;
  Serial.println("scan done");
  if (n == 0) {
      Serial.println("no networks found");
  } else {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i) {
      items[i].no = i;
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      items[i].wifiname=WiFi.SSID(i);
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      items[i].rssi=WiFi.RSSI(i);
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
      delay(10);
    }
  }
  Serial.println("");  
  
  }

void setup()
{
    Serial.begin(115200);
    scanNetwork();
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

        server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
              request->send_P(200, "text/html", index_html, processor);
                });
        server.begin();

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
