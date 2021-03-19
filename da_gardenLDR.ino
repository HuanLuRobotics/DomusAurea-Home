// a LDR for the garden
// 1 LDR
// 1 R1KHOhm
// 3 R220 for leds
// 3 Leds

#include <Constants.h>

const byte PIN_LDR = A0;
const byte PIN_LIGHT_1=2; // pin for Led1
const byte PIN_LIGHT_2=3; // pin for Led2
const byte PIN_LIGHT_3=4; // pin for Led3
int val=0; // variable to store the LDR value
int sensibility = 95; // variable of bottom level

void setup () {
    Serial.begin(SERIAL_RATE);
    pinMode(PIN_LIGHT_1, OUTPUT);
    pinMode(PIN_LIGHT_2, OUTPUT);
    pinMode(PIN_LIGHT_3, OUTPUT);
    pinMode(PIN_LDR, INPUT);
}

void loop () {
    val = analogRead(PIN_LDR); // read the LDR value between 0 to 1.023
    Serial.println(val); // print the value for debug
    delay(100);
    if (val<=sensibility) { // if under the bottom level
        digitalWrite(PIN_LIGHT_1, HIGH);
        digitalWrite(PIN_LIGHT_2, HIGH);
        digitalWrite(PIN_LIGHT_3, HIGH);
    } else { // else the value is over the bottom level
        digitalWrite(PIN_LIGHT_1, LOW);
        digitalWrite(PIN_LIGHT_2, LOW);
        digitalWrite(PIN_LIGHT_3, LOW);
    }
    // if you want to use map() then the code will be written
    // map (value, 0, 1023, 0, 255);
    // if (value == 255) { //when reach the 255 (max value)
    //     Serial.println(value);
    // }
}