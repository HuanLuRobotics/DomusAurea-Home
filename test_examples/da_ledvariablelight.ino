// set variable ligth to a led using PWM pulses (Pulse Wide Modulation)
// 1 LED
// 1 R220

const byte PIN_LIGHT = 5; // pin to use is 5

void setup() {
    pinMode(PIN_LIGHT, OUTPUT);
}

void loop() {
    analogWrite(PIN_LIGHT, LOW);
    set_bright();
    set_dark();
}

void set_bright() {
    for (int i=0; i<=255; i=i+10) {
        analogWrite(PIN_LIGHT, i);
        delay(200);
    }
}
void set_dark() {
    for (int i=255; i>=0; i=i-10) {
        analogWrite(PIN_LIGHT, i);
        delay(200);
    }
}
