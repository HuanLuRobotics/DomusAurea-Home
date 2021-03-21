// This is the Domus Aurea Assistant Robot
// It is created based on the ROBOT K-5 presented by Pedro Porcunas

/* =================================================================
 material:
  Container for the robot body (a plastic bottle)
  Container for the robot head (a box)
  Papers for dress
  Arduino controller
  Protoboard 
  1 Servo motor 180º
  1 Sensor ultrasound
  1 Sensor CNY-70
  2 Resistors for CNY-70 sensors
  1 Speaker 8 ohms
  1 red led light
  2 green led light
  cables
 */
// TODO: Colour sensor decoder
// TODO: Movements with wheels and engines and IR controller
// TODO: Ultrasound decoder to be autonomous

#include <Constants.h>
#include <Servo.h>
#include <NewPing.h>

const byte PIN_TRIGGER=12; // trigger of distance sensor
const byte PIN_ECHO=11; // echo of distance sensor
const int MAX_DISTANCE=200 ; // max distance 200 cm

int dist= 0; // distance to an object in straigh line
int value = 0; // values of the CNY-70 sensor

const byte PIN_LED_GREEN_8MM = 10; // green led 8mm
const byte PIN_CNY=A0; //
const byte PIN_LED_GREEN=9; // green led 5 mm
const byte PIN_LED_RED=8; // red led 5 mm
const byte PIN_BUZZER=3;
const byte PIN_SERVO=7;
unsigned int tmp; // to store the ping time

NewPing sonar(PIN_TRIGGER, PIN_ECHO, MAX_DISTANCE);

Servo headServo; // servo to control the head movement

void setup() {
    Serial.begin(SERIAL_RATE);
    pinMode(PIN_CNY,INPUT);
    pinMode(PIN_LED_GREEN_8MM, OUTPUT);
    pinMode(PIN_LED_GREEN, OUTPUT);
    pinMode(PIN_LED_RED, OUTPUT);
    pinMode(PIN_BUZZER, OUTPUT);
    headServo.attach(PIN_SERVO);
    // set Start on Robot
    digitalWrite(PIN_LED_GREEN_8MM, HIGH);
    digitalWrite(PIN_LED_GREEN, HIGH;
    digitalWrite(PIN_LED_RED, HIGH);
    delay(200);
    digitalWrite(PIN_LED_GREEN_8MM, LOW);
    digitalWrite(PIN_LED_GREEN, LOW);
    digitalWrite(PIN_LED_RED, LOW);
    tone(PIN_BUZZER, 950,900); // make a sound
    delay(200);
    noTone(PIN_BUZZER);
    delay(200);
    tone(PIN_BUZZER, 750,300);
    delay(200);
}

void loop () {
    value = analogRead (PIN_CNY);
    Serial.println(value);
    delay(100);
    digitalWrite(PIN_LED_GREEN, LOW);
    digitalWrite(PIN_LED_RED, LOW);
    if (value >=80 && value >=260) { // it is detecting black colour
       digitalWrite(PIN_LED_GREEN, HIGH);
       digitalWrite(PIN_LED_RED, LOW);
       tono_no_correcto();
    }
    if (value > 600 && value < 966) { // it is detecting white colour
       digitalWrite(PIN_LED_GREEN, LOW);
       digitalWrite(PIN_LED_RED, HIGH);
       tono_correcto();
    }
    if (value > 6 && value <=30) { // TODO: depending on the light these values might be different
       digitalWrite(PIN_LED_GREEN, LOW);
       digitalWrite(PIN_LED_RED, LOW);
    }
    headServo.write(CENTER_MOVEMENT); // center serv
    delay(50); //
    tmp=sonar.ping();
    dist=tmp/US_ROUNDTRIP_CM;
    Serial.print("Distance:");
    Serial.print(dist);
    Serial.println("cm.");
    if (dist==0) { // we need to clean possible wrong values
       digitalWrite(PIN_LED_GREEN_8MM, LOW);
    }
    if (dist >=55 && dist <= 65) { // robot will move head to make "happiness"
       digitalWrite(PIN_LED_GREEN_8MM, HIGH);
       headServo.write(RIGHT_MOVEMENT);
       delay(200);
       headServo.write(CENTER_MOVEMENT);
       delay(200);
    } else { 
       digitalWrite(PIN_LED_GREEN_8MM, LOW);
    }
    if (dist >= 1 && dist <= 54) { 
        digitalWrite(PIN_LED_GREEN_8MM, HIGH);
    }
}


//********************************
// AUXILIAR FUNCTIONS
//********************************

void tono_correcto() {
    tone(3,950,900);
    delay(200);
    noTone(3);
    delay(200);
    tone(3,850,300);
    delay(200);
    noTone(3);
    delay(200);
    tone(3,750,300);
    delay(500);
}

void tono_no_correcto() {
    tone(3,750,900);
    delay(200);
    noTone(3);
    delay(200);
    tone(3,350,300);
    delay(200);
    noTone(3);
    delay(200);
    tone(3,950,900);
    delay(500);
}