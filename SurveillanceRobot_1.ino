// Surveillance Robot based on Pedro Porcuna RAC1 and ROBU robots

// 1 HC-SR04
// 1 green led
// 2 servo 360º
// TODO ENHANCEMENTS
// TODO 0. Including Interruptions
// TODO 1. Sensors to avoid the death angles (instead one sensor).
// TODO 2. Better way to control the velocity of the sensor
// TODO 3. With 3 sensors the robot will be able to go out of any space in an autonomous way.
// TODO 4. Sensor to control Humidity
// TODO 5. Sensor to control Light level

#include <NewPing.h>
#include <Servo.h>

#define TRIGGER_PIN 12; // trigger of sensor
#define ECHO_PIN 11; // echo of sensor
#define MAX_DISTANCE 200 ; // max distance 200 cm

int dist= 0; // distance to an object in straigh line
int rightDistance = 0; // distance to an object to the right
int leftDistance = 0; // distance to an object to the left
int cont=0; //
int cont2=0; //
int pinled=13; //
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int rightTurn= 180;
int leftTurn=0;
int stopMove=90;
Servo rightServo;
Servo leftServo;
Servo servoBar; // servo to control the scan

void setup() {
    Serial.begin(9600);
    pinMode(pinled, OUTPUT);
    rightServo.attach(9);
    leftServo.attach(3);
    servoBar.attach(7);
    servoBar.write(90); // to center the ServoBar scan
}

void loop() {
    dist=0;
    rightDistance=0;
    leftDistance=0;
    doGoForward();
    doCentralScan();
    
    if (dist <=25) {
        doStop();
        doGoBack();
        doStop();
        doRightScan();
        doLeftScan();
        
        if ( rigthDistance > leftDistance ) {
            rightMove();
        }
        if ( rigthDistance < leftDistance ) {
            leftMove();
        }
        doGoForward();

        // while (cont <250) { // with 250 the servos will rotate aprox 90º
        // //TODO: verify angle
        //     rigthServo.write(rightTurn);
        //     leftServo.write(stopMove);
        //     Serial.println(cont);
        //     cont=cont+1;   
        //}
    } else { // distance is larger tha 25 cms
        doGoForward();
        cont=0; // to ensure counter is set to 0 for next time
    }
}

//********************************
// AUXILIAR FUNCTIONS
//********************************

void doGoForward () {
    rightServo.attach(9);
    leftServo.attach(3));
    rightServo.write(rightTurn);
    leftServo.write(leftTurn);
}

void doStop () {
    leftServo.dettatch();
    rightServo.dettatch();
    delay(1500);
}

void doGoBack() {
    rightServo.attach(9);
    leftServo.attach(3));
    rightServo.write(leftTurn);
    leftServo.write(rightTurn);
    delay(1000);
}

void leftMove() {
    leftServo.attach(3));
    rightServo.write(stopMove);
    leftServo.write(leftTurn);
    while (cont<300){
        leftServo.write(leftTurn);
        cont++;
        servoBar.write(90); // center
        Serial.println(cont);
    }
    cont=0;
    cont2=0;
}

void rightMove() {
    rigthServo.attach(9));
    rightServo.write(rigthTurn);
    leftServo.write(stopMove);
    while (cont2<300){
        rigthServo.write(rigthTurn);
        cont2++;
        servoBar.write(90); // center
        Serial.println(cont2);
    }
    cont=0;
    cont2=0;
}

void rightScan() {
    servoBar.write(0); //
    delay(200); //
    unsigned int tmp0 = sonar.ping();
    rightDistance = tmp0/ US_ROUNDTRIP_CM;
    delay(1000);
}

void leftScan() {
    servoBar.write(180); //
    delay(200); //
    unsigned int tmp1 = sonar.ping();
    leftDistance = tmp1/ US_ROUNDTRIP_CM;
    delay(1000);
}

void centralScan() {
    servoBar.write(90); //
    delay(200); //
    unsigned int tmp = sonar.ping();
    dist = tmp/ US_ROUNDTRIP_CM;
    delay(1000);
}