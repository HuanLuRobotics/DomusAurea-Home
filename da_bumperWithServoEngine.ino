// sensor for servoEngine
// 1 bumper
// 1 R220 or 1 R330
// 1 Servo 360

#include <Constants.h>
#include <Servo.h>

Servo engine;
const byte PIN_BUMPER = 8; 
const byte PIN_ENGINE = 11; 
int data = 0;

void setup () {
    pinMode(PIN_BUMPER, INPUT);
    engine.attach(PIN_ENGINE);
}

void loop () {
    data = digitalRead(PIN_BUMPER);
    if (data == HIGH) {
        engine.write(20);
    }
    data = digitalRead(PIN_BUMPER);
    if (data == LOW) {
        engine.write(STOP_MOVEMENT);
    }
}