// To control a courtain depending the amount of light that is provided
// 2 Buttons
// 1 servoEngine
// 2 resistance (one per each button)
// the courtain
#include <Servo.h>
int ldr = A0; // set pin Analogic0 for the Light Sensor
int sensibility = 95; // set sensibility level
itn value = 0; // set value to 0 for ldr
Servo courtain_engine;

void setup () {
   Serial.begin(9600);
   pinMode(ldr,INPUT);
   courtain_engine.attach(7); // servo controlled by pin 7
}

void loop() {
   value = analogRead (ldr); // read ldr value and store value
   Serial.println(value); // print
   delay(1000);
   if (value <=sensibility) {
       courtain_engine.write(180); // turn on and courtain will be opened
       delay (3000); // during 3 seconds. ADJUST DEPENDING OF THE SIZE OF THE COURTAIN
       courtain_engine.write(90); // stop the engine
   } else {
       courtain_engine.write(0); // turn on and courtain will be closed
       delay (3000); // during 3 seconds. ADJUST DEPENDING OF THE SIZE OF THE COURTAIN
       courtain_engine.write(90); // stop the engine
   }
}