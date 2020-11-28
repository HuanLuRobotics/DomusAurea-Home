// Control two servors with a Remote KeyPad
// 1 TSOP-4838
// 2 servos 360º
// 1 remote keypad
// Programming a Remote Control 
// 1 LCD
// 1 TSOP 4838
// Remote control device

#include <IRremote.h>
#include <Servo.h>

int RECV_PIN = 11;
IRrecv ir(RECV_PIN);
decode_results results; // to store the remote result
int rightTurn = 180; // value to move the servo to the rigth
int leftTurn = 0; // value to move the servo to the left
int stopMove = 90; // value to move the servo to the stop

Servo rightServo;
Servo leftServo;

void setup() {
    Serial.begin(9600);
    ir.enableIRIn(); // enable the device
    rightServo.attach(9);
    leftServo.attach(3);
}

void loop() {
    if (ir.decode(&results)) { // when data is received
        Serial.println(results.value, DEC); // print the button code that has been pressed
        delay(200); // wait
        ir.resume(); // receive the next key
    }
    if (results.value == 16724685) { // up, then move both servos in the same direction
        rightServo.write(rightTurn);
        leftServo.write(leftTurn);
        if (results.value == 4294967295) {
            rightServo.write(rightTurn);
            leftServo.write(leftTurn);
        }
    }
    if (results.value == 16740495) { // left, then move left servo to the right, and left stop
        rightServo.write(rightTurn);
        leftServo.write(stopMove);
        if (results.value == 4294967295) {
            rightServo.write(rightTurn);
            leftServo.write(stopMove);
        }
    }
    if (results.value == 16740495) { // right, then move right servo to the left and right stop
        rightServo.write(stopMove);
        leftServo.write(leftTurn);
        if (results.value == 4294967295) {
            rightServo.write(stopMove);
            leftServo.write(leftTurn);
        }
    }
    if (results.value == 16740495) { // stop, then stop both servos
        rightServo.write(stopMove);
        leftServo.write(stopMove);
        if (results.value == 4294967295) {
            rightServo.write(stopMove);
            leftServo.write(stopMove);
        }
    }
}