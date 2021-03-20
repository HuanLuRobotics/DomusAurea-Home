// sensor for bumper
// 1 bumper
// 1 R220 or 1 R330
// 1 led

const byte PIN_BUMPER = 8; // pin 8 to bumper
const byte PIN_LED = 13; // pin 13 to led
int data = 0; // variable for data

void setup () {
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_BUMPER, INPUT);
}

void loop () {
    data = digitalRead(PIN_BUMPER);
    if (data == HIGH) {
        digitalWrite(PIN_LED, HIGH);
    }
    data = digitalRead(PIN_BUMPER);
    if (data == LOW) {
        digitalWrite(PIN_LED, LOW);
    }
}