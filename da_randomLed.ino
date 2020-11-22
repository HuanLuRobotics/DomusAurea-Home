// random Leds
// 1 Led
// 1 R220

int max_value = 255; // set max_value
int pin = 5; // pin to use is 5

void setup() {
   pinMode(pin, OUTPUT);
}

void loop() {
    randomSeed(millis());
    analogWrite(pin, random(max_value));
    delay(50);
}