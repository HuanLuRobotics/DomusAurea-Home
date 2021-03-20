// How to handle interruptions
// 1 button
// 1 R220
//1 led

#include <Constants.h>

const byte PIN_BUTTON = 7;
const byte PIN_LED=13; 
int vb=0;

void setup () {
    pinMode(PIN_BUTTON, INPUT);
    pinMode(PIN_LED, OUTPUT);
    Serial.begin(SERIAL_RATE);
    attachInterrupt(0, blinking, HIGH); // this instruction will handle the interruptions
}

void loop () {
    for (int t=0; t<500; t++) {
        Serial.println(t);
    }
}

void blinking () { // function to do something
    vb=digitalRead(PIN_BUTTON);
    if (vb==HIGH) {
        digitalWrite(PIN_LED, HIGH);
    } else {
        digitalWrite(PIN_LED, LOW);
    }
}
