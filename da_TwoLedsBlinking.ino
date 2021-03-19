/* Two leds blinking alternatively */
// two leds 
// 1 R220 for pin 12

const byte PIN_RED_1= 13; // pin 13 to red led 1
const byte PIN_RED_2=12; // pin 12 to red led 2

void setup() {
    pinMode(PIN_RED_1, OUTPUT); // pin 13 as output
    pinMode(PIN_RED_2, OUTPUT); // pin 12 as output
    digitalWrite(PIN_RED_1, LOW); // pin switch off at beginning
    digitalWrite(PIN_RED_2, LOW); // pin switch off at beginning
}

void loop () {
    digitalWrite(PIN_RED_1, HIGH); // when is 5V, light will be on
    delay(1000); // wait
    digitalWrite(PIN_RED_1, LOW); // when is 5V, light will be off
    digitalWrite(PIN_RED_2, HIGH); // when is 5V, light will be on
    delay(1000); // wait
    digitalWrite(PIN_RED_2, LOW); // when is 5V, light will be off
}