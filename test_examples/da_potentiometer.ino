// using a potentionmeter
// 1 Potentiometer of 10KOhms
// 1 R220 to be used by led if pin 13 is not used
// 1 Led

#include <Constants.h>

const byte PIN_POTENTIOMETER = A0; // assign analog pin A0 to the central terminal of potentionmeter
const byte PIN_LED=13; 
int value; // variable to store the potentionmeter value

void setup() {
    Serial.begin(SERIAL_RATE); // start serial communication
    pinMode(PIN_POTENTIOMETER, INPUT);
    pinMode(PIN_LED, OUTPUT);
}

void loop() {
    value = analogRead(PIN_POTENTIOMETER); // store the values
    Serial.println(value); // print values

    if (value <= 100) {
        digitalWrite(PIN_LED, HIGH); // set led to brightness
    }

    if (value > 300 && value < 500) {
        digitalWrite(PIN_LED, LOW); // set led to dark
    }

    if (value >900) {
        digitalWrite(PIN_LED, HIGH); // set led to bright
    }
}