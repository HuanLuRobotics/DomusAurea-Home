// random Leds
// 1 Led
// 1 R220

const byte MAX_VALUE = 255; // set max_value
const byte PIN_LED = 5; // pin to use is 5

void setup() {
   pinMode(PIN_LED, OUTPUT);
}

void loop() {
    randomSeed(millis());
    analogWrite(PIN_LED, random(MAX_VALUE));
    delay(50);
}