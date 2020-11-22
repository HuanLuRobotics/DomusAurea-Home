// sensor for bumper
// 1 bumper
// 1 R220 or 1 R330
// 1 led

int bumper = 8; // pin 8 to bumper
int data = 0; // variable for data
int led = 13; // pin 13 to led

void setup () {
    pinMode(led, OUTPUT);
    pinMode(bumper, INPUT);
}

void loop () {
    data = digitalRead(bumper);
    if (data == HIGH) {
        digitalWrite(led, HIGH);
    }
    data = digitalRead(bumper);
    if (data == LOW) {
        digitalWrite(led, LOW);
    }
}