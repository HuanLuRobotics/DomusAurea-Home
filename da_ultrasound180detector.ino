// scan 180º with a ultrasound Sensor
// 1 180º servo
// 1 ultrasound sensor

#include <Servo.h>
#include <NewPing.h>

#define TRIGGER_PIN 7
#define ECHO_PIN 6
#define DIST_MAX 200
unsigned int tmp; // front distance 
unsigned int tmp1; // distance to the left side 
unsigned int tmp2; // distance to the right side

NewPing sonar(TRIGGER_PIN, ECHO_PIN, DIST_MAX);

Servo servobar;

void setup() {
    servobar.attach(4);
    Serial.begin(9600);
}

void loop() {
    servobar.write(90); // servo in the initial position 
    delay(100); //
    tmp=sonar.ping_cm();
    Serial.print("Ping central: ");
    Serial.print(tmp);
    Serial.println(" cm");
    delay(1000); //
    
    servobar.write(0); // start movement to left side
    delay(1000); //
    tmp1=sonar.ping_cm();
    Serial.print("Ping to the left: ");
    Serial.print(tmp1);
    Serial.println(" cm");
    delay(1000); //

    servobar.write(180); // start movement to right side
    delay(1000); //
    tmp2=sonar.ping_cm();
    Serial.print("Ping to the right: ");
    Serial.print(tmp2);
    Serial.println(" cm");
    delay(1000); //
     
}