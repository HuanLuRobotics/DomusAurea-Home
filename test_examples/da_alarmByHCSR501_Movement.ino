// Alarm by movement
// Sensor PIR HC-SR501 (this sensor send data during 4 seconds that can be adjusted with the potentionmeters)
// 1 Led Red (or a accionable component)

#include <Constants.h>

const byte PIN_LED = 13; // pin 13 to led 
const byte PIN_SENSOR = 8 ; // pin 8 to sensor
int value = 0; // variable to store the value that is read from Sensor
boolean status = false; // status variable

void setup () {
    Serial.begin(SERIAL_RATE);
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_SENSOR, INPUT);
}

void loop () {
    value = digitalRead(PIN_SENSOR); // read the sensor value
    if (value == HIGH) { 
        digitalWrite(PIN_LED, HIGH); // set led to brightness
        while (status == false) { // this loop is to avoid that msg will be printed a lot of times just for one detection
           Serial.println("MOVEMENT ALARM DETECTED!");
           status = true;
        }
    } else {
        digitalWrite(PIN_LED, LOW); // set led to dark
        if (status == true) {
            status == false;
        }
    }
}