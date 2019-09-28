#include <WS2812FX.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WiFiMulti.h>
#include <ESP8266WebServer.h>
#include "Secret.h"
#include "Webpage.h"
#include <EEPROM.h>
bool flag_effet = true;
int addr = 0;
int lum;


struct {
  uint8_t param1;
  uint8_t param2;
  uint8_t param3;
  uint8_t lum;
  uint8_t spd;
  uint8_t rVal;
  uint8_t gVal;
  uint8_t bVal;
  } data;

ESP8266WebServer server(80);

IPAddress ip(192, 168, 1, 251);
IPAddress gateway(192, 168, 1, 1); // set gateway to match your network
IPAddress subnet(255, 255, 255, 0); // set subnet mask to match your network

#define LED_COUNT 100
#define LED_PIN 4

ESP8266WiFiMulti WiFiMulti;
WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);

unsigned long previousMillis = 0;
const long interval = 10000; 

int effet = 1;
int lasteffet = 0;

void parametres(){
  
// Read arguments and parameters
 Serial.print("Effect = ");
 Serial.println(server.arg("effet"));
  
lum = server.arg("Lum").toInt();
effet = server.arg("effet").toInt();

  // Parametre de luminosite
  // Brightness parameters 
ws2812fx.setBrightness(lum);
  Serial.print("WEB - Lum = ");
  Serial.println(lum);

  if(effet == 100){ //mode demo
    flag_effet = true;
    Serial.println("WEB - effect = demo");
  }
  else if(effet > 60){ 
    ws2812fx.setMode(43);
    Serial.println ("WEB - error = mode ");
  }
  else{ // choix effet en cours - Choice of current effect
if (server.arg("effet")!=""){
      flag_effet = false;
      ws2812fx.setMode(effet);
      Serial.print(ws2812fx.getModeName(effet));
      Serial.print(" WEB - effet = ");
      Serial.println(effet);
    }
    data.param1 = effet;
    data.param2 = lum;
    Serial.print("Saved param1: " + String(data.param1) + ", param 2: ");
    Serial.println(String(data.param2)+", param 3: "+ String(data.param3));
    EEPROM.put(addr,data);
    EEPROM.commit();
  }
handleRoot(); 
//server.send(200, "text/html", web_page);
}



void handleRoot() {
  setWebpage();

server.send(200, "text/html", web_page);
}

//--------------------------
//Configuration
//--------------------------
void setup() {
// Initialisation
// Initialization
  ws2812fx.init();

// Réglage de la vitesse des effets  
// Adjusting the speed of effects
  ws2812fx.setSpeed(250);
// Effet arc en ciel 
// Rainbow effect 
  ws2812fx.setColor(255, 128, 230);
  
// Demarrage
// Start  

  Serial.begin(115200);
  EEPROM.begin(512);
  EEPROM.get(addr, data);
  Serial.println();
  Serial.print("Retrieved param1: " + String(data.param1) + ", param 2: ");
  Serial.println(String(data.param2)+", param 3: "+ String(data.param3));
  effet=data.param1;
  lum=data.param2;
  ws2812fx.setMode(effet);
  ws2812fx.setBrightness(lum);
  ws2812fx.start();
WiFi.config(ip, gateway, subnet);
WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(STASSID, STAPSK);
  WiFiMulti.addAP(STASSID2, STAPSK2);
  WiFiMulti.addAP(STASSID3, STAPSK3);
WiFi.setSleepMode(WIFI_NONE_SLEEP);
while (WiFiMulti.run() != WL_CONNECTED) {
//while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(500);
  }
  
  Serial.println();
  Serial.print("Connected to ");
Serial.print(WiFi.SSID());
Serial.print(", ip ");
Serial.println(WiFi.localIP());

   
server.on("/", handleRoot);
  
server.on("/led", parametres);

  
server.begin();
  Serial.println("Server Up");
}

void loop() {
server.handleClient();
  ws2812fx.service();

}
