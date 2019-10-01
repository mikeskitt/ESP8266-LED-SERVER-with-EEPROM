//IP: 523 living, 252 kitchen, 251 pong, 250 foosball room, 249 party room, 248 stairs
       //120 living room, 170 stairs, 337 foosball room, 200 pong
#if CURRENT_ROOM == 1 //FamilyRoom
  IPAddress ip(192, 168, 1, 252);
  #define LOCATION "Family Room"
  #define NUM_LEDS      120
  #define MILLI_AMPS    5000
#elif CURRENT_ROOM == 2 //livingroom
  IPAddress ip(192, 168, 1, 251);
  #define LOCATION "Living Room"
  #define NUM_LEDS      100
  #define MILLI_AMPS    5000
#elif CURRENT_ROOM == 3 //Garage
  IPAddress ip(192, 168, 1, 250);
  #define LOCATION "Garage"
  #define NUM_LEDS      100
  #define MILLI_AMPS    40000
#elif CURRENT_ROOM == 4 //art
  IPAddress ip(192, 168, 1, 249);
  #define LOCATION "Art"
  #define NUM_LEDS      100
  #define MILLI_AMPS    5000
#elif CURRENT_ROOM == 5 //tree1
  IPAddress ip(192, 168, 1, 248);
  #define LOCATION "Christmas Tree"
  #define NUM_LEDS      463
  #define MILLI_AMPS    45000
#elif CURRENT_ROOM == 6 //stairs
  IPAddress ip(192, 168, 1, 247);
  #define NUM_LEDS      189
  #define MILLI_AMPS    15000
#elif CURRENT_ROOM == 7 //lighthouse
  IPAddress ip(192, 168, 1, 247);
  #define NUM_LEDS      198
  #define MILLI_AMPS    20000
#elif CURRENT_ROOM == 20 //calibration
  IPAddress ip(192, 168, 1, 252);
  #define NUM_LEDS      150
  #define MILLI_AMPS    20000
#elif CURRENT_ROOM == 21 //dad's basement
  IPAddress ip(192, 168, 1, 240);
  #define NUM_LEDS      278
  #define MILLI_AMPS    26000
#endif
