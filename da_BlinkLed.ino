// blinking led
// one led
// one R220 (if pin is not 13)

int led = 13; // pin 13

void setup() {
    pinMode(led, OUTPUT); // pin 13 as output
}

void loop () {
    digitalWrite(led, HIGH); // when is 5V, light will be on
    delay(1000); // wait
    digitalWrite(led, LOW); // when is 5V, light will be off
    delay(1000); // wait
}