// How to control an CC Engine with a CNY-70 sensor.
// 1 CNY-70 sensor
// 1 R120
// 1 100KOhm
// 1 Servo (or 2) 360 degrees
// paper white and paper black for testing purposes

#include <Constants.h>
#include <Servo.h>

Servo engine; // 360 degreees servo
const byte PIN_CNY=A0; // pin to Analogic0 for sensor measurements
const byte PIN_SERVO=11; 
int value = 0; // value to store

void setup () {
    pinMode(PIN_CNY, INPUT);
    engine.attach(PIN_SERVO);
    Serial.begin(SERIAL_RATE);
}

void loop () {
    value = analogRead(PIN_CNY);
    Serial.println(value);
    delay(100);
    
    if (value >=11) {
        engine.write (GO_MOVEMENT); // enable if color white is detected
    }
    if (value < 5) {
        engine.write (STOP_MOVEMENT); // disable if color black is detected
    }
}