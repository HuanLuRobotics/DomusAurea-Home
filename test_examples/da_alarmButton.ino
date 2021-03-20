// set a simple button to make Alarm
// 1 R10KOhms or nearest
// 1 R220
// 1 Led
// 1 Buzzer
// 1 switch button

const byte PIN_BUZZER = A0; // set Analogic0 Pin for buzzer
const byte PIN_BUTTON = 7; // set pin 7 for button
const byte PIN_LED = 13; // set pin 13 for led
int value=0; // set variable vb to store the value of the button

void setup() {
    pinMode(PIN_BUZZER, OUTPUT);
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_BUTTON, OUTPUT);
}

void loop() {
    value=digitalRead(PIN_BUTTON);
    if (value==HIGH) {
        for (int i=0; i<10;i++) { // buzzer 10 times
            delay(220);
            tone (PIN_BUZZER, 220, 100); // set sound
            digitalWrite(PIN_LED, HIGH);
            delay(220);
            noTone(PIN_BUZZER); // set silence
            digitalWrite(PIN_LED, LOW);
        }
    }
}