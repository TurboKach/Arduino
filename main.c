
/* Analog Read to LED
   ------------------

   turns on and off a light emitting diode(LED) connected to digital
   pin 13. The amount of time the LED will be on and off depends on
   the value obtained by analogRead(). In the easiest case we connect
   a potentiometer to analog pin 2.

   Created 1 December 2005
   copyleft 2005 DojoDave <http://www.0j0.org>
   http://arduino.berlios.de

*/

int potBrightnessPin = 0;    // select the input pin for the potentiometer
int potRedPin = 1;    // select the input pin for the potentiometer
int potGreenPin = 2;    // select the input pin for the potentiometer
int potBluePin = 3;    // select the input pin for the potentiometer
int ledPin = 13;   // select the pin for the LED
unsigned int potBrightnessVal, potBrightnessFirstVal; // variable to store the value coming from the sensor
unsigned int potRedVal, potRedFirstVal;       // variable to store the value coming from the sensor
unsigned int potGreenVal, potGreenFirstVal;       // variable to store the value coming from the sensor
unsigned int potBlueVal, potBlueFirstVal;       // variable to store the value coming from the sensor

void setup() {
  Serial.begin(9600);
  potBrightnessFirstVal = (analogRead(potBrightnessPin) >> 2)*1.13;
  potRedFirstVal = (analogRead(potRedPin) >> 4)*4*1.14;
  potGreenFirstVal = (analogRead(potGreenPin) >> 4)*4*1.14;
  potBlueFirstVal = (analogRead(potBluePin) >> 4)*4*1.14;
  Serial.println("Setup begins: ");
  Serial.println(potBrightnessFirstVal);
  Serial.println(potRedFirstVal);
  Serial.println(potGreenFirstVal);
  Serial.println(potBlueFirstVal);
  Serial.println("Setup ends. ");
}

void loop() {
  potBrightnessVal = (analogRead(potBrightnessPin) >> 2)*1.13; // read the value from the sensor
  if (potBrightnessVal != potBrightnessFirstVal) {
    potBrightnessFirstVal = potBrightnessVal;
    Serial.println("Brightness: ");
    Serial.println(potBrightnessVal);
  }
  potRedVal = (analogRead(potRedPin) >> 4)*4*1.14; // read the value from the sensor
  if (potRedVal != potRedFirstVal) {
    potRedFirstVal = potRedVal;
    Serial.println("Red: ");
    Serial.println(potRedVal);
  }
  potGreenVal = (analogRead(potGreenPin) >> 4)*4*1.14; // read the value from the sensor
  if (potGreenVal != potGreenFirstVal) {
    potGreenFirstVal = potGreenVal;
    Serial.println("Green: ");
    Serial.println(potGreenVal);
  }
  potBlueVal = (analogRead(potBluePin) >> 4)*4*1.14; // read the value from the sensor
  if (potBlueVal != potBlueFirstVal) {
    potBlueFirstVal = potBlueVal;
    Serial.println("Blue: ");
    Serial.println(potBlueVal);
  }
}
