// scan 180º with a ultrasound Sensor
// 1 180º servo
// 1 ultrasound sensor

#include <Constants.h>
#include <Servo.h>
#include <NewPing.h>


const byte PIN_TRIGGER=7;
const byte PIN_ECHO=6;
const byte PIN_SERVO=4;
const byte DIST_MAX=200;
unsigned int tmp; // front distance 
unsigned int tmp1; // distance to the left side 
unsigned int tmp2; // distance to the right side

NewPing sonar(PIN_TRIGGER, PIN_ECHO, DIST_MAX);

Servo servobar;

void setup() {
    servobar.attach(PIN_SERVO);
    Serial.begin(SERIAL_RATE);
}

void loop() {
    servobar.write(STOP_MOVEMENT); // servo in the initial position 
    delay(100); //
    tmp=sonar.ping_cm();
    Serial.print("Ping central: ");
    Serial.print(tmp);
    Serial.println(" cm");
    delay(1000); //
    
    servobar.write(LEFT_MOVEMENT); // servostart movement to left side
    delay(1000); //
    tmp1=sonar.ping_cm();
    Serial.print("Ping to the left: ");
    Serial.print(tmp1);
    Serial.println(" cm");
    delay(1000); //

    servobar.write(RIGHT_MOVEMENT); // start movement to right side
    delay(1000); //
    tmp2=sonar.ping_cm();
    Serial.print("Ping to the right: ");
    Serial.print(tmp2);
    Serial.println(" cm");
    delay(1000); //
     
}