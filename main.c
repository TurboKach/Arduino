int potBrightnessPin = 0;    // select the input pin for the potentiometer
int potRedPin = 1;    // select the input pin for the potentiometer
int potGreenPin = 2;    // select the input pin for the potentiometer
int potBluePin = 3;    // select the input pin for the potentiometer
int ledPin = 13;   // select the pin for the LED
unsigned int potBrightnessVal, potBrightnessFirstVal, potRedVal = 0;       // variable to store the value coming from the sensor

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  // declare the ledPin as an OUTPUT
  potBrightnessFirstVal = (analogRead(potBrightnessPin) >> 2)*1.13;
  Serial.println("Setup ");
  Serial.println(potBrightnessFirstVal);
}

void loop() {
  potBrightnessVal = (analogRead(potBrightnessPin) >> 2)*1.13; // read the value from the sensor
  if (potBrightnessVal != potBrightnessFirstVal) {
    potBrightnessFirstVal = potBrightnessVal;
    Serial.println(potBrightnessVal);
  }
}
