#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FS.h>
#include <ArduinoJson.h>
#include "index.h"


ESP8266WebServer server(80);

const int top = D5;
const int bot = D6;
const int led = D4;
const int sw = D0;

char* ssid = "YOUR_SSID";
char* password = "YOUR_SSID_PASSWORD";
char* ap_ssid = "Smart Pump";



void setup()
{
  pinMode(top, INPUT);
  pinMode(bot, INPUT);
  pinMode(led, OUTPUT);
  pinMode(sw, INPUT);
  SPIFFS.begin();
  WiFi.mode(WIFI_AP);
  IPAddress myIP = WiFi.softAPIP();
  WiFi.softAP(ap_ssid);
  wifiConnect();

  server.on("/", []() {
    server.send_P(200, "text/html", mainpage);
  });

  server.on("/on", on_led);
  server.on("/off", off_led);
  server.on("/setting", HTTP_POST, Setting_Update);

  server.begin();
}

void loop()
{
  server.handleClient();
}



void Setting_Update()
{
  String data = server.arg("plain");
  DynamicJsonDocument jBuffer(1024);
  DeserializationError error = deserializeJson(jBuffer, data);

  File configFile = SPIFFS.open("/config.json", "w");
  serializeJson(jBuffer, configFile);
  configFile.close();

  server.send(200, "application/json", "Settings Updated!");
  delay(500);

  wifiConnect();
}

void wifiConnect()
{
  WiFi.disconnect();
  delay(1000);
  //check for stored credentials
  if (SPIFFS.exists("/config.json")) {
    const char * _ssid = "", *_pass = "";
    File configFile = SPIFFS.open("/config.json", "r");
    if (configFile) {
      size_t size = configFile.size();
      std::unique_ptr<char[]> buf(new char[size]);
      configFile.readBytes(buf.get(), size);
      configFile.close();

      DynamicJsonDocument jsonBuffer(1024);
      DeserializationError error = deserializeJson(jsonBuffer, buf.get());
      if (error)
      {
        return   ;
      }
      else
      {
        _ssid = jsonBuffer["ssid"];
        _pass = jsonBuffer["password"];
        WiFi.mode(WIFI_AP_STA);
        WiFi.begin(_ssid, _pass);
        unsigned long startTime = millis();
        while (WiFi.status() != WL_CONNECTED)
        {
          delay(500);
          if ((unsigned long)(millis() - startTime) >= 5000) break;
        }
      }
    }
  }
}

void on_led()
{
  digitalWrite(led, LOW);
  server.send(204, "");
}

void off_led()
{
  digitalWrite(led, HIGH);
  server.send(204, "");
}
