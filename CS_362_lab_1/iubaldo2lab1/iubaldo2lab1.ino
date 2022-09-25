// 1 -Ian Ubaldo - 657982252
// 2- Lab 1 - Get started with Arduino -  blinking lights_
// 3- Description - lights 3 LEDs in sequence
// 4- Assumptions - pins 12 and 11 are being used to connect to the LEDs
// 5- References - http://arduino.cc/en/Tutorial/Blink
// 6- Demo - in-person demonstration 9/12/22 11:16 AM Judhajit Roy



int led; // which led to light
int red = 12; // plug red led into pin 12
int green = 11; // plug green led into pin 11

unsigned long prevTime = 0; // time of last blink
unsigned long blinkInterval = 500; // time between blinks in ms

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  led = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currTime = millis();
  if (currTime - prevTime >= blinkInterval) {
    prevTime = currTime;
    if (++led > 2)
      led = 0;

    switch (led) {
      case 0:
        digitalWrite(LED_BUILTIN, HIGH);
        digitalWrite(red, LOW);
        digitalWrite(green, LOW);
        break;
       case 1:
        digitalWrite(LED_BUILTIN, LOW);
        digitalWrite(red, HIGH);
        digitalWrite(green, LOW);
        break;
       case 2:
        digitalWrite(LED_BUILTIN, LOW);
        digitalWrite(red, LOW);
        digitalWrite(green, HIGH);
        break;
    }

    Serial.println("changed to led #" + led);
  }
}
