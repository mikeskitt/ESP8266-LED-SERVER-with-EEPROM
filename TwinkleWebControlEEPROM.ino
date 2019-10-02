#define FASTLED_INTERRUPT_RETRY_COUNT 0
#define FASTLED_ALLOW_INTERRUPTS 0
#include "FastLED.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WiFiMulti.h>
#include <ESP8266WebServer.h>
#include "Secret.h"


#define CURRENT_ROOM 3  // ------------------Set this Sets IP address --------------
#include "RoomSpecific.h"
#include "Webpage.h"
#include <EEPROM.h>

#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif
int addr = 0;
int progVal;
int lastPal;

#define LED_TYPE   WS2811
#define COLOR_ORDER   RGB
#define DATA_PIN        4
#define VOLTS          12
//#define MAX_MA       5000

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

unsigned long gHue = 0;
unsigned long previousMillis = 0;
const long interval = 10000; 

int effet = 1;
int lasteffet = 0;

ESP8266WebServer server(80);

CRGBArray<NUM_LEDS> leds;

IPAddress gateway(192, 168, 1, 1); // set gateway to match your network
IPAddress subnet(255, 255, 255, 0); // set subnet mask to match your network
ESP8266WiFiMulti WiFiMulti;
// Overall twinkle speed.
// 0 (VERY slow) to 8 (VERY fast).  
// 4, 5, and 6 are recommended, default is 4.
uint8_t twinkleSpeed = 3;

// Overall twinkle density.
// 0 (NONE lit) to 8 (ALL lit at once).  
// Default is 5.
uint8_t twinkleDensity = 7;

// How often to change color palettes.
#define SECONDS_PER_PALETTE  10
CRGB gBackgroundColor = CRGB::Black; 
// Example of dim incandescent fairy light background color
// CRGB gBackgroundColor = CRGB(CRGB::FairyLight).nscale8_video(16);

// If AUTO_SELECT_BACKGROUND_COLOR is set to 1,
// then for any palette where the first two entries 
// are the same, a dimmed version of that color will
// automatically be used as the background color.
#define AUTO_SELECT_BACKGROUND_COLOR 0
#define COOL_LIKE_INCANDESCENT 1


CRGBPalette16 gCurrentPalette;
CRGBPalette16 gTargetPalette;


#include "twinkleControl.h"
const uint8_t numberOfPalettes = sizeof(ActivePaletteList) / sizeof(ActivePaletteList[0]);

void parametres(){
  
// Read arguments and parameters
 Serial.print("Effect = ");
 Serial.println(server.arg("effet"));
  
if(server.arg("Lum")!=""){
  data.lum = server.arg("Lum").toInt();
}

if(server.arg("speed")!="" ){
  twinkleSpeed = server.arg("speed").toInt();
  if(twinkleSpeed>8) twinkleSpeed=8;
  data.spd = twinkleSpeed;
}
if(server.arg("Prog")!=""){
  progVal = server.arg("Prog").toInt();
  data.param2 = progVal;
}


  // Parametre de luminosite
  // Brightness parameters 
FastLED.setBrightness(data.lum);
  Serial.print("WEB - Lum = ");
  Serial.println(data.lum);


if(server.arg("effet")!=""){
      //flag_effet = false;
      effet = server.arg("effet").toInt();
      if(effet<=(numberOfPalettes-1))data.param1 = effet;
      //Serial.print(ws2812fx.getModeName(effet));
      Serial.print(" WEB - effet = ");
      Serial.println(data.param1);
    }
    
    Serial.print("Saved Palette : " + String(data.param1) + ", lum : ");
    Serial.println(String(data.lum)+", Speed: "+ String(data.spd)+", Prog: "+ String(data.param2));
    EEPROM.put(addr,data);
    EEPROM.commit();

handleRoot(); 
//server.send(200, "text/html", web_page);
}


void handleRoot() {
  setWebpage();
server.send(200, "text/html", web_page);
}

void setup() {//------------------------------------------SETUP-------------------------
  //delay( 3000 ); //safety startup delay
FastLED.setMaxPowerInVoltsAndMilliamps( VOLTS, MILLI_AMPS);
FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS)
    .setCorrection(TypicalLEDStrip);
  Serial.begin(115200);
  EEPROM.begin(512);
  EEPROM.get(addr, data);
  lastPal = data.param1;
  twinkleSpeed = data.spd;
  Serial.println();
  Serial.print("Retrieved param1: " + String(data.param1) + ", Bright : ");
  Serial.println(String(data.lum)+", Speed: "+ String(data.spd));
  
  FastLED.setBrightness(data.lum);
WiFi.config(ip, gateway, subnet);// set as static IP
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
server.on("/led", HTTP_POST, parametres);
  
server.begin();
  Serial.println("Server Up");
  
  chooseNextColorPalette(gTargetPalette);
}//------------------------------------------------------SETUP END----------------------


void loop()//-------------------------------------------LOOP---------------------------
{
server.handleClient();
  
if(data.param1!=lastPal) { 
    chooseNextColorPalette( gTargetPalette );
    lastPal = data.param1; 
  }
  
  EVERY_N_MILLISECONDS( 20 ) {
    nblendPaletteTowardPalette( gCurrentPalette, gTargetPalette, 12);
  }

if(data.param2==1) {
  drawTwinkles( leds);
  }
else if(data.param2==2){
  Newconfetti();
}
else if(data.param2==3){
  sinelon();
}

else {
  fillBlack();
}
  
  FastLED.show();
}




// Advance to the next color palette in the list (above).
void chooseNextColorPalette( CRGBPalette16& pal)
{
  static uint8_t whichPalette = -1; 
  whichPalette = data.param1;

  pal = *(ActivePaletteList[whichPalette]);
}

void fillBlack(){
  fill_solid(leds, NUM_LEDS, CRGB::BlueViolet);
}

void Newconfetti() 
{
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( leds, NUM_LEDS, pow(data.spd,2));
  for(int x=0;x<8;x++){
  int pos = random16(NUM_LEDS);
  //leds[pos] += CHSV( 85 + random8(64), 100, 255);
  leds[pos] += CHSV( 85 + random8(8), 245, 255);
  }
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV( 42, 255, 255);
}

void sinelon() {
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, data.spd);
  int pos = beatsin16(data.spd, 0, NUM_LEDS);
  static int prevpos = 0;
  CRGB color = ColorFromPalette(gCurrentPalette, gHue, 255);
  if( pos < prevpos ) {
    fill_solid( leds+pos, (prevpos-pos)+1, color);
  } else {
    fill_solid( leds+prevpos, (pos-prevpos)+1, color);
  }
  prevpos = pos;
}
