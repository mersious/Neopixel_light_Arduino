#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 16 // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define receive_sw0 2
#define receive_sw1 3

void setup() {
  pixels.begin();               // INITIALIZE NeoPixel strip object (REQUIRED)
  delay(10);                    //to ensure that the pixels begins successfully
  pixels.clear();               // Set all pixel colors to 'off'
}

void loop() {
  which_state();
}


void which_state()
{
  bool sw0 = digitalRead(receive_sw0);
  bool sw1 = digitalRead(receive_sw1);
  if(sw0 == 0 && sw1 == 0)
  {
    show_white();
  }
  else if(sw0 == 1 && sw1 == 0)
  {
    show_error();
  }
  else if(sw0 == 0 && sw1 == 1)
  {
    show_ok();
  }
}

void show_error()
{
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));         //RED color
    pixels.show();                                            // Send the updated pixel colors to the hardware.
  }
}

void show_ok()
{
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));        //Green color
    pixels.show();   
  }
}

void show_white()
{
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 255, 255));   //White color
    pixels.show();   
  }
}
