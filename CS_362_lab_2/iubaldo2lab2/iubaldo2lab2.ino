// 1 -Ian Ubaldo - 657982252
// 2- Lab 2 - Input and Output
// 3- Description - use buttons to increment/decrement an LED binary counter
// 4- Assumptions - pins 2, 3, 4, 5 are being used for the binary LEDs and pins 11, 12 are being used for the buttons
// 5- References - https://www.arduino.cc/en/Tutorial/Button
// 6- Demo - in-person demonstration 9/12/22 11:49 Judhajit Roy



// button pins
const int buttonInc = 11;
const int buttonDec = 12;

// led pins
const int led1 = 2;
const int led2 = 3;
const int led4 = 4;
const int led8 = 5;

// button press states
int buttonIncState = 0;
int buttonDecState = 0;

// value to be converted to binary and displayed via LEDs
int counterValue = 0;           

// button press management 
unsigned long prevPressTime = 0;       // time last pressed
unsigned long buttonCD = 500;          // time before button can be pressed again
boolean buttonPressed = false;         // whether a button is currently pressed

void setup() {
  Serial.begin(9600);

  // initialize all pins
  pinMode(buttonInc, INPUT);
  pinMode(buttonDec, OUTPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led8, OUTPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonIncState = digitalRead(buttonInc);
  buttonDecState = digitalRead(buttonDec);

  // read buttons for input and adjust counterValue accordingly
  // input will only work if a button hasn't been pressed recently
  if (buttonIncState == HIGH && buttonPressed == false) {   
    buttonPressed = true;
    prevPressTime = millis();
    counterValue++;
    Serial.println("inc on");
  } 
  else if (buttonDecState == HIGH && buttonPressed == false) {
    buttonPressed = true;
    prevPressTime = millis();
    if (--counterValue < 0)
      counterValue = 0;
    Serial.println("dec on");
  }

  // convert counterValue to binary and output to LEDs
  int temp = counterValue;      // value of the digit being calculated
  int n = 0;                    // array index
  int binaryValue[4] = {0, 0, 0, 0};           // array to store the binary value
  while (temp > 0) {
    binaryValue[n] = temp % 2;
    temp /= 2;
    n++;
  }
  digitalWrite(led1, binaryValue[0] == 1 ? HIGH : LOW);
  digitalWrite(led2, binaryValue[1] == 1 ? HIGH : LOW);
  digitalWrite(led4, binaryValue[2] == 1 ? HIGH : LOW);
  digitalWrite(led8, binaryValue[3] == 1 ? HIGH : LOW);

  Serial.println(counterValue);
  for (int i = 3; i >= 0; i--)
    Serial.print(binaryValue[i]);
  Serial.println();

  // reset buttonPressed after enough time has passed and a button isn't currently being pressed
  unsigned long currTime = millis();
  if (currTime - prevPressTime >= buttonCD && !(buttonIncState == HIGH || buttonDecState == HIGH)){
    buttonPressed = false;
  }
}
