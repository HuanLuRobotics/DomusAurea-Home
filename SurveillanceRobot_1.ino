// Surveillance Robot based on Pedro Porcuna RAC1 and ROBU robots
// This robot includes a Remote Control with several buttons to make actions

// 1 HC-SR04
// 1 green led
// 2 servo 360º
// 1 TSOP 3848

// TODO ENHANCEMENTS
// TODO 0. Including Interruptions
// TODO 1. Sensors to avoid the death angles (instead one sensor).
// TODO 2. Better way to control the velocity of the sensor
// TODO 3. With 3 sensors the robot will be able to go out of any space in an autonomous way.
// TODO 4. Sensor to control Humidity
// TODO 5. Sensor to control Light level

#include <Constants.h>
#include <NewPing.h>
#include <IRremote.h>
#include <Servo.h>

const byte PIN_TRIGGER=12; // trigger of distance sensor
const byte PIN_ECHO=11; // echo of distance sensor
const int MAX_DISTANCE=200; // max distance 200 cm

int dist= 0; // distance to an object in straigh line
int rightDistance = 0; // distance to an object to the right
int leftDistance = 0; // distance to an object to the left
int cont=0; //
int cont2=0; //
const byte PIN_LED=13; //

NewPing sonar(PIN_TRIGGER, PIN_ECHO, MAX_DISTANCE);

Servo rightServo;
Servo leftServo;
Servo servoBar; // servo to control the scan
const byte PIN_SERVO_RIGHT = 9;
const byte PIN_SERVO_LEFT=3;
const byte PIN_SERVO_BAR=7;

const byte PIN_RECV = 8; // pin to control IRremote
IRrecv ir(PIN_RECV); // assign IR with the corresponding pin
decode_results results; // variable to hold results

void setup() {
    Serial.begin(SERIAL_RATE);
    ir.enableIRIn(); // start reception of IR
    pinMode(PIN_LED, OUTPUT);
    rightServo.attach(PIN_SERVO_RIGHT);
    leftServo.attach(PIN_SERVO_LEFT);
    servoBar.attach(PIN_SERVO_BAR);
    servoBar.write(CENTER_MOVEMENT); // to center the ServoBar scan
}

void loop() {
    dist=0;
    rightDistance=0;
    leftDistance=0;
    doDecodeIR(); // we detect first the human remote orders
    doGoForward(); // and then the robot will move autonomous mode until distance to avoid collision
    doCentralScan(); // detecting any object that might be avoided
    
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

void doDecodeIR () {
    if (ir.decode(&results)) {
        Serial.println(results.value, DEC) ; // print the code of the pressed button
        delay(200); // delay for avoiding double press
        ir.resume(); // to receive next button
    }
    if (results.value == BT_UP) { 
        doGoForward();
    }
    if (results.value == BT_LEFT) {
        leftMove();
    }
    if (results.value == BT_RIGHT) {
        rigthMove();
    }
    if (results.value == BT_DOWN) {
        doGoBack();
    }
    if (results.value == BT_OK) {
        doStop();
    }
// TODO a botton to enter in autonomous mode only when is pressed
}

void doGoForward () {
    rightServo.write(RIGHT_MOVEMENT);
    leftServo.write(LEFT_MOVEMENT);
}

void doStop () {
    leftServo.write(STOP_MOVEMENT);
    rightServo.write(STOP_MOVEMENT);
    delay(1500);
}

void doGoBack() {
    rightServo.write(LEFT_MOVEMENT);
    leftServo.write(RIGHT_MOVEMENT);
    delay(1000);
}

void rigthMove() {
    rightServo.write(STOP_MOVEMENT);
    leftServo.write(LEFT_MOVEMENT);
    while (cont<300){
        leftServo.write(LEFT_MOVEMENT);
        cont++;
        servoBar.write(CENTER_MOVEMENT);
        Serial.println(cont);
    }
    cont=0;
    cont2=0;
}

void leftMove() {
    rightServo.write(RIGHT_MOVEMENT);
    leftServo.write(STOP_MOVEMENT);
    while (cont2<300){
        rigthServo.write(RIGHT_MOVEMENT);
        cont2++;
        servoBar.write(CENTER_MOVEMENT);
        Serial.println(cont2);
    }
    cont=0;
    cont2=0;
}

void rightScan() {
    servoBar.write(RIGHT_MOVEMENT);
    delay(200);
    unsigned int tmp0 = sonar.ping();
    rightDistance = tmp0/ US_ROUNDTRIP_CM;
    delay(1000);
}

void leftScan() {
    servoBar.write(LEFT_MOVEMENT);
    delay(200);
    unsigned int tmp1 = sonar.ping();
    leftDistance = tmp1/ US_ROUNDTRIP_CM;
    delay(1000);
}

void centralScan() {
    servoBar.write(CENTER_MOVEMENT);
    delay(200);
    unsigned int tmp = sonar.ping();
    dist = tmp/ US_ROUNDTRIP_CM;
    delay(1000);
}