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

#include <Servo.h>
#include <NewPing.h>

#define TRIGGER_PIN 12; // trigger of distance sensor
#define ECHO_PIN 11; // echo of distance sensor
#define MAX_DISTANCE 200 ; // max distance 200 cm

int dist= 0; // distance to an object in straigh line
int value = 0; // values of the CNY-70 sensor
int greenled8mm = 10; //
int cny=A0; //
int greenled=9; // pin to the green led 5 mm
int redled=8; // pin to the red led 5 mm
int buzzer=3; // pin to the buzzer
unsigned int tmp; // to store the ping time

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int leftMove=0;
int stopMove=90;
int rightMove= 180;
Servo headServo; // servo to control the head movement

void setup() {
    Serial.begin(9600);
    pinMode(cny,INPUT);
    pinMode(greenled8mm, OUTPUT);
    pinMode(greenled, OUTPUT);
    pinMode(redled, OUTPUT);
    pinMode(buzzer, OUTPUT);
    headServo.attach(7);
    // set Start on Robot
    digitalWrite(greenled8mm, HIGH);
    digitalWrite(greenled, HIGH;
    digitalWrite(redled, HIGH);
    delay(200);
    digitalWrite(greenled8mm, LOW);
    digitalWrite(greenled, LOW);
    digitalWrite(redled, LOW);
    tone(buzzer, 950,900); // make a sound
    delay(200);
    noTone(buzzer);
    delay(200);
    tone(buzzer, 750,300);
    delay(200);
}

void loop () {
    value = analogRead (cny);
    Serial.println(value);
    delay(100);
    digitalWrite(greenled, LOW);
    digitalWrite(redled, LOW);
    if (value >=80 && value >=260) { // it is detecting black colour
       digitalWrite(greenled, HIGH);
       digitalWrite(redled, LOW);
       tono_no_correcto();
    }
    if (value > 600 && value < 966) { // it is detecting white colour
       digitalWrite(greenled, LOW);
       digitalWrite(redled, HIGH);
       tono_correcto();
    }
    if (value > 6 && value <=30) { // TODO: depending on the light these values might be different
       digitalWrite(greenled, LOW);
       digitalWrite(redled, LOW);
    }
    headServo.write(90); // center serv
    delay(50); //
    tmp=sonar.ping();
    dist=tmp/US_ROUNDTRIP_CM;
    Serial.print("Distance:");
    Serial.print(dist);
    Serial.println("cm.");
    if (dist==0) { // we need to clean possible wrong values
       digitalWrite(greenled8mm, LOW);
    }
    if (dist >=55 && dist <= 65) { // robot will move head to make "happiness"
       digitalWrite(greenled8mm, HIGH);
       headServo.write(180);
       delay(200);
       headServo.write(90);
       delay(200);
    } else { 
       digitalWrite(greenled8mm, LOW);
    }
    if (dist >= 1 && dist <= 54) { 
        digitalWrite(greenled8mm, HIGH);
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