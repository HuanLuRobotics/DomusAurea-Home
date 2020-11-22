// sensor for servoEngine
// 1 bumper
// 1 R220 or 1 R330
// 1 Servo 360

#include <Servo.h>
Servo engine;
int bumper = 8; // pin 8 to bumper
int data = 0; // variable for data

void setup () {
    pinMode(bumper, INPUT);
    engine.attach(11);
}

void loop () {
    data = digitalRead(bumper);
    if (data == HIGH) {
        engine.write(20);
    }
    data = digitalRead(bumper);
    if (data == LOW) {
        engine.write(90); // stop the servo
    }
}