

const TProgmemRGBPalette16 RedGreenWhite_p FL_PROGMEM =
{  CRGB::Red, CRGB::Red, CRGB::Red, CRGB::Red, 
   CRGB::Red, CRGB::Red, CRGB::Red, CRGB::Red, 
   CRGB::Red, CRGB::Red, CRGB::Gray, CRGB::Gray, 
   CRGB::Green, CRGB::Green, CRGB::Green, CRGB::Green };

// A mostly (dark) green palette with red berries.
#define Holly_Green 0x00580c
#define Holly_Red   0xB00402
const TProgmemRGBPalette16 Holly_p FL_PROGMEM =
{  Holly_Green, Holly_Green, Holly_Green, Holly_Green, 
   Holly_Green, Holly_Green, Holly_Green, Holly_Green, 
   Holly_Green, Holly_Green, Holly_Green, Holly_Green, 
   Holly_Green, Holly_Green, Holly_Green, Holly_Red 
};

// A red and white striped palette
// "CRGB::Gray" is used as white to keep the brightness more uniform.
const TProgmemRGBPalette16 RedWhite_p FL_PROGMEM =
{  CRGB::Red,  CRGB::Red,  CRGB::Red,  CRGB::Red, 
   CRGB::Gray, CRGB::Gray, CRGB::Gray, CRGB::Gray,
   CRGB::Red,  CRGB::Red,  CRGB::Red,  CRGB::Red, 
   CRGB::Gray, CRGB::Gray, CRGB::Gray, CRGB::Gray };

// A mostly blue palette with white accents.
// "CRGB::Gray" is used as white to keep the brightness more uniform.
const TProgmemRGBPalette16 BlueWhite_p FL_PROGMEM =
{  CRGB::BlueViolet, CRGB::BlueViolet, CRGB::DarkMagenta, CRGB::DarkMagenta, 
   CRGB::DarkOrchid, CRGB::Purple, CRGB::Purple, CRGB::Blue, 
   CRGB::LightSkyBlue, CRGB::LightSkyBlue, CRGB::LightSkyBlue, CRGB::Blue, 
   CRGB::Blue, CRGB::White, CRGB::White, CRGB::White };

// A pure "fairy light" palette with some brightness variations
#define HALFFAIRY ((CRGB::FairyLight & 0xFEFEFE) / 2)
#define QUARTERFAIRY ((CRGB::FairyLight & 0xFCFCFC) / 4)
const TProgmemRGBPalette16 FairyLight_p FL_PROGMEM =
{  CRGB::FairyLight, CRGB::FairyLight, CRGB::DarkRed, CRGB::FairyLight, 
   HALFFAIRY,        HALFFAIRY,        CRGB::FairyLight, CRGB::FairyLight, 
   QUARTERFAIRY,     QUARTERFAIRY,     CRGB::FairyLight, CRGB::FairyLight, 
   CRGB::FairyLight, CRGB::FairyLight, CRGB::FairyLight, CRGB::FairyLight };

// A palette of soft snowflakes with the occasional bright one
const TProgmemRGBPalette16 Snow_p FL_PROGMEM =
{  0x304048, 0x304048, 0x304048, 0x304048,
   0x304048, 0x304048, 0x304048, 0x304048,
   0x304048, 0x304048, 0x304048, 0x304048,
   0x304048, 0x304048, 0x304048, 0xE0F0FF };

// A palette reminiscent of large 'old-school' C9-size tree lights
// in the five classic colors: red, orange, green, blue, and white.
#define C9_Red    0xB80400
#define C9_Orange 0x902C02
#define C9_Green  0x046002
#define C9_Blue   0x070758
#define C9_White  0x606820
const TProgmemRGBPalette16 RetroC9_p FL_PROGMEM =
{  C9_Red,    C9_Orange, C9_Red,    C9_Orange,
   C9_Orange, C9_Red,    C9_Orange, C9_Red,
   C9_Green,  C9_Green,  C9_Green,  C9_Green,
   C9_Blue,   C9_Blue,   C9_Blue,
   C9_White
};

// A cold, icy pale blue palette
#define Ice_Blue1 0x0C1040
#define Ice_Blue2 0x182080
#define Ice_Blue3 0x5080C0
const TProgmemRGBPalette16 Ice_p FL_PROGMEM =
{
  Ice_Blue1, Ice_Blue1, Ice_Blue1, Ice_Blue1,
  Ice_Blue1, Ice_Blue1, Ice_Blue1, Ice_Blue1,
  Ice_Blue1, Ice_Blue1, Ice_Blue1, Ice_Blue1,
  Ice_Blue2, Ice_Blue2, Ice_Blue2, Ice_Blue3
};

// Lemony
const TProgmemRGBPalette16 Lemon_p FL_PROGMEM =
{  CRGB::DarkOrange, CRGB::DarkOrange, CRGB::Gold, CRGB::Gold, 
   CRGB::LightGreen, CRGB::LightGreen, CRGB::LightGrey, CRGB::LightGrey, 
   CRGB::Orange, CRGB::Orange, CRGB::Yellow, CRGB::Yellow, 
   CRGB::Yellow, CRGB::Yellow, CRGB::Orange, CRGB::Gray };

// SpringForest
const TProgmemRGBPalette16 SpForest_p FL_PROGMEM =
{  CRGB::DarkOrange, CRGB::DarkGreen, CRGB::LightGreen, CRGB::LightGreen, 
   CRGB::LightGreen, CRGB::LightGreen, CRGB::DarkGreen, CRGB::LightGrey, 
   CRGB::DarkGreen, CRGB::Orange, CRGB::DarkGreen, CRGB::Yellow, 
   CRGB::DarkGreen, CRGB::DarkGreen, CRGB::LightGreen , CRGB::LightGreen };

// PurpleRain
const TProgmemRGBPalette16 PurpRain_p FL_PROGMEM =
{  CRGB::Purple, CRGB::BlueViolet, CRGB::DarkBlue, CRGB::Amethyst, 
   CRGB::Indigo, CRGB::Navy, CRGB::Purple, CRGB::Indigo, 
   CRGB::Purple, CRGB::BlueViolet, CRGB::DarkBlue, CRGB::Amethyst, 
   CRGB::Indigo, CRGB::Navy, CRGB::Purple, CRGB::Indigo  };   
   
const TProgmemRGBPalette16* ActivePaletteList[] = {
  &Lemon_p,  //0
  &RetroC9_p, // 1
  &BlueWhite_p,//2
  &RainbowColors_p,//3
  &FairyLight_p,//4
  &RedGreenWhite_p,//5
  &PartyColors_p,//6
  &FairyLight_p,//7
  &Snow_p,//8
  &RedWhite_p,//9
  &Holly_p,//10
  &Ice_p,//11
  &SpForest_p,//12
  &PurpRain_p  //13
};
