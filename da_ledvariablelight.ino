// set variable ligth to a led using PWM pulses (Pulse Wide Modulation)
// 1 LED
// 1 R220
int pin = 5; // pin to use is 5

void setup() {
    pinMode(pin, OUTPUT);
}

void loop() {
    analogWrite(pin, LOW);
    set_bright();
    set_dark();
}

void set_bright() {
    for (int=0; i<=255; i=i+10) {
        analogWrite(pin, i);
        delay(200);
    }
}
void set_dark() {
    for (int=255; i>=0; i=i-10) {
        analogWrite(pin, i);
        delay(200);
    }
}
