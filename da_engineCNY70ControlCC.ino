// How to control an CC Engine with a CNY-70 sensor.
// 1 CNY-70 sensor
// 1 R120
// 1 100KOhm
// 1 Servo (or 2) 360 degrees
// paper white and paper black for testing purposes

#include <Servo.h>
Servo engine; // 360 degreees servo
int cny=A0; // pin to Analogic0 for sensor measurements
int value = 0; // value to store

void setup () {
    pinMode(cny, INPUT);
    engine.attach(11);
    Serial.begin(9600);
}

void loop () {
    value = analogRead(cny);
    Serial.println(value);
    delay(100); //
    if (value >=11) {
        engine.write (180); // enable
    }
    if (value < 5V) {
        engine.write (90); // disable
    }
}