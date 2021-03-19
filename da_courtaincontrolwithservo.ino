// To control a courtain depending the amount of light that is provided
// 2 Buttons
// 1 servoEngine
// 2 resistance (one per each button)
// the courtain

#include <Constants.h>
#include <Servo.h>

const byte PIN_LDR = A0; // set pin Analogic0 for the Light Sensor
const byte PIN_SERVO = 7; // set pin 7 for Servo
int sensibility = 95; // set sensibility level
int value = 0; // set value to 0 for ldr
Servo courtain_engine;

void setup () {
   Serial.begin(SERIAL_RATE);
   pinMode(PIN_LDR,INPUT);
   courtain_engine.attach(PIN_SERVO);
}

void loop() {
   value = analogRead (PIN_LDR); // read ldr value and store value
   Serial.println(value); // print
   delay(1000);
   if (value <=sensibility) {
       courtain_engine.write(RIGHT_MOVEMENT); // turn on and courtain will be opened
       delay (3000); // during 3 seconds. ADJUST DEPENDING OF THE SIZE OF THE COURTAIN
       courtain_engine.write(STOP_MOVEMENT); // stop the engine
   } else {
       courtain_engine.write(LEFT_MOVEMENT); // turn on and courtain will be closed
       delay (3000); // during 3 seconds. ADJUST DEPENDING OF THE SIZE OF THE COURTAIN
       courtain_engine.write(STOP_MOVEMENT); // stop the engine
   }
}