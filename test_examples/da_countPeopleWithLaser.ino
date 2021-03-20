// calculate how many people is inside a place with a laser
// 1 Led laser
// 1 R1KHOhm
// 1 Led red (for signal)

#include <Constants.h>

const byte PIN_LASER = 13;
const byte PIN_LDR = A0;
const byte PIN_LED = 4;
int counter=0; // variable for counter
int value= 0; // variable for value


void setup() {
    Serial.begin(SERIAL_RATE);
    pinMode (PIN_LASER,OUTPUT); // pin
    pinMode (PIN_LED,OUTPUT); // pin
    pinMode (PIN_LDR,INPUT); // pin
}

void loop() {
    digitalWrite (PIN_LASER, HIGH); // set laser one
    value = analogRead (PIN_LDR); // read ldr and store value
    if (value <= 200) {
        counter++; // increment number of persons 
        if (counter == 100) {
            Serial.println("WARNING: MAX NUMBER of persons reached");
        } else {
            digitalWrite (PIN_LED, HIGH); // set led for visual warning
            Serial.print(100-counter); // number of persons left
            Serial.println(" still available");
            delay(TWO_SECONDS); // time for a person to pass the entry
            digitalWrite (PIN_LED, LOW); // set led off for visual warning
        }
    }
}