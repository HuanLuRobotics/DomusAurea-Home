#include <Key.h>

/* Seven leds blinking alternatively */
// Seven leds
// 7 R220

const int PIN_RED_1=13; // pin 13 to red led 1
const int PIN_RED_2=12; // pin 12 to red led 2
const int PIN_RED_3=11; // pin 11 to red led 3
const int PIN_RED_4=10; // pin 10 to red led 4
const int PIN_RED_5= 9; // pin 09 to red led 5
const int PIN_RED_6= 8; // pin 08 to red led 6
const int PIN_RED_7= 7; // pin 07 to red led 7

void setup() {
    pinMode(PIN_RED_1, OUTPUT); // pin 13 as output
    pinMode(PIN_RED_2, OUTPUT); // pin 12 as output
    pinMode(PIN_RED_3, OUTPUT); // pin 11 as output
    pinMode(PIN_RED_4, OUTPUT); // pin 10 as output
    pinMode(PIN_RED_5, OUTPUT); // pin 09 as output
    pinMode(PIN_RED_6, OUTPUT); // pin 08 as output   
    pinMode(PIN_RED_7, OUTPUT); // pin 07 as output
    
    digitalWrite(PIN_RED_1, LOW); // pin switch off at beginning
    digitalWrite(PIN_RED_2, LOW); // pin switch off at beginning
    digitalWrite(PIN_RED_3, LOW); // pin switch off at beginning
    digitalWrite(PIN_RED_4, LOW); // pin switch off at beginning
    digitalWrite(PIN_RED_5, LOW); // pin switch off at beginning
    digitalWrite(PIN_RED_6, LOW); // pin switch off at beginning
    digitalWrite(PIN_RED_7, LOW); // pin switch off at beginning
}

void loop () {
    digitalWrite(PIN_RED_1, HIGH); // when is 5V, light will be on
    delay(1000); // wait
    digitalWrite(PIN_RED_1, LOW); // when is 5V, light will be off
    digitalWrite(PIN_RED_2, HIGH); // when is 5V, light will be on
    delay(1000); // wait
    digitalWrite(PIN_RED_2, LOW); // when is 5V, light will be off
    digitalWrite(PIN_RED_3, HIGH); // when is 5V, light will be on
    delay(1000); // wait
    digitalWrite(PIN_RED_3, LOW); // when is 5V, light will be off
    digitalWrite(PIN_RED_4, HIGH); // when is 5V, light will be on
    delay(1000); // wait
    digitalWrite(PIN_RED_4, LOW); // when is 5V, light will be off
    digitalWrite(PIN_RED_5, HIGH); // when is 5V, light will be on
    delay(1000); // wait
    digitalWrite(PIN_RED_5, LOW); // when is 5V, light will be off
    digitalWrite(PIN_RED_6, HIGH); // when is 5V, light will be on
    delay(1000); // wait
    digitalWrite(PIN_RED_6, LOW); // when is 5V, light will be off
    digitalWrite(PIN_RED_7, HIGH); // when is 5V, light will be on

    delay(1000); // wait to start back
    
    digitalWrite(PIN_RED_7, LOW); // when is 5V, light will be off
    digitalWrite(PIN_RED_6, HIGH); // when is 5V, light will be on
    delay(1000); // wait
    digitalWrite(PIN_RED_6, LOW); // when is 5V, light will be off
    digitalWrite(PIN_RED_5, HIGH); // when is 5V, light will be on
    delay(1000); // wait
    digitalWrite(PIN_RED_5, LOW); // when is 5V, light will be off
    digitalWrite(PIN_RED_4, HIGH); // when is 5V, light will be on
    delay(1000); // wait
    digitalWrite(PIN_RED_4, LOW); // when is 5V, light will be off
    digitalWrite(PIN_RED_3, HIGH); // when is 5V, light will be on
    delay(1000); // wait
    digitalWrite(PIN_RED_3, LOW); // when is 5V, light will be off
    digitalWrite(PIN_RED_2, HIGH); // when is 5V, light will be on
    delay(1000); // wait
    digitalWrite(PIN_RED_2, LOW); // when is 5V, light will be off
    digitalWrite(PIN_RED_1, HIGH); // when is 5V, light will be on
    delay(1000); // wait
    digitalWrite(PIN_RED_1, LOW); // when is 5V, light will be off
    delay(1000); // wait
    
}