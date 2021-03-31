// blinking led with a button
// one led
// one R220 (if pin is not 13)
// one button

const byte PIN_LED = 13;
const byte PIN_BUTTON = 9;
bool buttonPressed = false;
int ledDelay = 1000;
bool ledBlinkState = HIGH;
long ledTimer;

void setup() {
  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_LED, OUTPUT);
  
  ledTimer = millis();
}

void loop() {
  determineState();
  display();
}

void determineState() {
  checkBlinkTimer();
  checkButtonPress();
  determineLedState();
}

void checkBlinkTimer() {
  if (millis() - ledTimer > ledDelay) {
    ledTimer = millis();
    ledBlinkState = !ledBlinkState;
  }
}

void checkButtonPress() {
  buttonPressed = (digitalRead(PIN_BUTTON) == HIGH);
}

void determineLedState() {
  if (ledBlinkState || buttonPressed) {
    ledBlinkState = HIGH;
  } else {
    ledBlinkState = LOW;
  }
}

void display() {
  digitalWrite(PIN_LED, ledBlinkState);
}