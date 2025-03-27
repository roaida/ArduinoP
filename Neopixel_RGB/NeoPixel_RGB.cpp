#include <Adafruit_NeoPixel.h>

#define PIN 6           // Pin connected to the data input of the NeoPixel strip
#define NUMPIXELS 10    // Number of NeoPixels in the strip

// Create an instance of the NeoPixel strip
Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();   // Initialize the strip
  strip.show();    // Initialize all pixels to 'off'
}

void loop() {
  // Red color
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(255, 0, 0)); // Red color
  }
  strip.show();
  delay(1000); // Wait for 1 second

  // Green color
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(0, 255, 0)); // Green color
  }
  strip.show();
  delay(1000); // Wait for 1 second

  // Blue color
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 255)); // Blue color
  }
  strip.show();
  delay(1000); // Wait for 1 second

  // White color (Red + Green + Blue)
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(255, 255, 255)); // White color
  }
  strip.show();
  delay(1000); // Wait for 1 second
}
