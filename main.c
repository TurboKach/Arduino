#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define LED_PIN     6

#define LED_COUNT  144

// NeoPixel brightness, 0 (min) to 255 (max)
#define BRIGHTNESS 50

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

int potWhitePin = 0;    // select the input pin for the potentiometer
int potRedPin = 1;    // select the input pin for the potentiometer
int potGreenPin = 2;    // select the input pin for the potentiometer
int potBluePin = 3;    // select the input pin for the potentiometer
int ledPin = 13;   // select the pin for the LED
unsigned int potWhiteVal, potWhiteFirstVal; // variable to store the value coming from the sensor
unsigned int potRedVal, potRedFirstVal;       // variable to store the value coming from the sensor
unsigned int potGreenVal, potGreenFirstVal;       // variable to store the value coming from the sensor
unsigned int potBlueVal, potBlueFirstVal;       // variable to store the value coming from the sensor

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(BRIGHTNESS); // Set BRIGHTNESS to about 1/5 (max = 255)
  
  potWhiteFirstVal = (analogRead(potWhitePin) >> 2)*1.13;
  potRedFirstVal = (analogRead(potRedPin) >> 4)*4*1.14;
  potGreenFirstVal = (analogRead(potGreenPin) >> 4)*4*1.14;
  potBlueFirstVal = (analogRead(potBluePin) >> 4)*4*1.14;
  
  strip.Color(255, 0, 0); // Red
  strip.show(); 
}

void loop() {
  // Fill along the length of the strip in various colors...
  strip.fill(strip.Color(potRedFirstVal, potGreenFirstVal, potBlueFirstVal, potWhiteFirstVal));
  strip.show();
  //Potentiometer code BEGINS
  potWhiteVal = (analogRead(potWhitePin) >> 2)*1.13; // read the value from the sensor
  if (potWhiteVal != potWhiteFirstVal) {
    potWhiteFirstVal = potWhiteVal;
  }
  potRedVal = (analogRead(potRedPin) >> 4)*4*1.14; // read the value from the sensor
  if (potRedVal != potRedFirstVal) {
    potRedFirstVal = potRedVal;
  }
  potGreenVal = (analogRead(potGreenPin) >> 4)*4*1.14; // read the value from the sensor
  if (potGreenVal != potGreenFirstVal) {
    potGreenFirstVal = potGreenVal;
  }
  potBlueVal = (analogRead(potBluePin) >> 4)*4*1.14; // read the value from the sensor
  if (potBlueVal != potBlueFirstVal) {
    potBlueFirstVal = potBlueVal;
  }
  //Potentiometer code ENDS

  // Fill along the length of the strip in various colors...
  
}
