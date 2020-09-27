#include <FastLED.h>
#define NUM_LEDS 16
const int dataPin = 3;

CRGB leds[NUM_LEDS];
// define pins here for LEDs

// *update pins.

int status, i;

void setup() 
{
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, dataPin>(leds, NUM_LEDS);
  for (i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(150);
  }
  
  Serial.begin(38400);
}

void loop() {

  if (Serial.available() > 0)
  {
    status = Serial.read();
  }
  
  if (status == '0')
  {
    Serial.println("Modes stopped.");
    
    for (i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = CRGB::Black;
      FastLED.show();
      delay(150);
    }
  }
  else if (status == '1')
  {
    Serial.println("Casual mode.");
    while (Serial.available() <= 0)
    {
      leds[0] = CRGB::Yellow;
      leds[1] = CRGB::Green;
      leds[2] = CRGB::Yellow;
      leds[3] = CRGB::Green;
      FastLED.show();
      delay(750);
      leds[4] = CRGB::Green;
      leds[5] = CRGB::Yellow;
      leds[6] = CRGB::Green;
      leds[7] = CRGB::Yellow;
      FastLED.show();
      delay(750);
      leds[8] = CRGB::Yellow;
      leds[9] = CRGB::Green;
      leds[10] = CRGB::Yellow;
      leds[11] = CRGB::Green;
      FastLED.show();
      delay(750);
      leds[12] = CRGB::Green;
      leds[13] = CRGB::Yellow;
      leds[14] = CRGB::Green;
      leds[15] = CRGB::Yellow;
      FastLED.show();
      delay(5000);

      for (i = 0; i < NUM_LEDS; i++)
      {
        leds[i] = CRGB::Black;
        FastLED.show();
        delay(150);        
      }
    }

    status = Serial.read();
  }
  else if (status == '2')
  {
    Serial.println("Police Mode.");
    
    while(Serial.available() <= 0)
    {
      leds[0] = CRGB::Blue;
      leds[1] = CRGB::Blue;
      leds[2] = CRGB::Blue;
      leds[3] = CRGB::Blue;
      FastLED.show();
      delay(25);
      leds[4] = CRGB::Red;
      leds[5] = CRGB::Red;
      leds[6] = CRGB::Red;
      leds[7] = CRGB::Red;
      FastLED.show();
      delay(50);
      leds[8] = CRGB::Blue;
      leds[9] = CRGB::Blue;
      leds[10] = CRGB::Blue;
      leds[11] = CRGB::Blue;
      FastLED.show();
      delay(50);
      leds[12] = CRGB::Red;
      leds[13] = CRGB::Red;
      leds[14] = CRGB::Red;
      leds[15] = CRGB::Red;
      FastLED.show();
      delay(50);

      for (i = 0; i < NUM_LEDS; i++)
      {
        leds[i] = CRGB::Black;
        FastLED.show();
        delay(150);        
      }
    }

    status = Serial.read();
  }
  else if (status == '3')
  {
    while(Serial.available() <= 0)
    {
      leds[0] = CRGB::Blue;
      leds[1] = CRGB::Red;
      leds[2] = CRGB::Green;
      leds[3] = CRGB::Yellow;
      FastLED.show();
      leds[4] = CRGB::Pink;
      leds[5] = CRGB::Orange;
      leds[6] = CRGB::Purple;
      leds[7] = CRGB::White;
      FastLED.show();
      leds[8] = CRGB::Cyan;
      leds[9] = CRGB::SkyBlue;
      leds[10] = CRGB::Red;
      leds[11] = CRGB::Pink;
      FastLED.show();
     // delay(100);
      leds[12] = CRGB::White;
      leds[13] = CRGB::Blue;
      leds[14] = CRGB::Green;
      leds[15] = CRGB::Yellow;
      FastLED.show();
      //delay(100);

      for (i = 0; i < NUM_LEDS; i++)
      {
        leds[i] = CRGB::Black;
        FastLED.show();
        delay(25);        
      }
    }
    status = Serial.read();    
  }
}
