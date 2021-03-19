// blinking led
// one led
// one R220 (if pin is not 13)

#include <Constants.h>
const byte PIN_LED = 13; // pin 13

void setup() {
    pinMode(PIN_LED, OUTPUT); // pin 13 as output
}

void loop () {
    digitalWrite(PIN_LED, HIGH); // when is 5V, light will be on
    delay(ONE_SECOND); // wait
    digitalWrite(PIN_LED, LOW); // when is 5V, light will be off
    delay(ONE_SECOND); // wait
}