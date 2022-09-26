// 1 -Ian Ubaldo - 657982252
// 2- Lab 4 - Multiple Inputs and Outputs
// 3- Description - Print scrolling text to an LCD
// 4- Assumptions - LCD pins are set up identically to that in the reference
// 5- References - https://docs.arduino.cc/learn/electronics/lcd-displays
// 6- Demo - in-person demonstration 9/26/22, 11:08 am, Michael


const int led1 = 5;
const int led2 = 4;
const int led3 = 3;
const int led4 = 2;

const int buzzer = 8;

const int photores = A1;
const int potentio = A0;

int lightval = 0;
int potenres = 0;

void setup() {
  Serial.begin(9600);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}


void loop() {
  lightval = analogRead(photores);
  potenres = analogRead(potentio);

  int nlightval = map (lightval, 100, 900, 4, 1); // 4 = no light
  digitalWrite(led1, nlightval >= 1 ? HIGH : LOW);
  digitalWrite(led2, nlightval >= 2 ? HIGH : LOW);
  digitalWrite(led3, nlightval >= 3 ? HIGH : LOW);
  digitalWrite(led4, nlightval >= 4 ? HIGH : LOW);
  
  Serial.println(lightval);

  delay(250);
}
