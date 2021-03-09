// set a simple button to make Alarm
// 1 R10KOhms or nearest
// 1 R220
// 1 Led
// 1 Buzzer
// 1 switch button

int buzzer = A0; // set Analogic0 Pin for buzzer
int button = 7; // set pin 7 for button
int led = 13; // set pin 13 for led
int vb=0; // set variable vb to store the value of the button

void setup() {
    pinMode(button, OUTPUT);
    pinMode(led, OUTPUT);
    pinMode(buzzer, OUTPUT);
}

void loop() {
    vb=digitalRead(button);
    if (vb==HIGH) {
        for (int i=0; i<10;i++) { // buzzer 10 times
            delay(220);
            tone (buzzer, 220, 100); // set sound
            digitalWrite(led, HIGH);
            delay(220);
            noTone(buzzer); // set silence
            digitalWrite(led, LOW);
        }
    }
}