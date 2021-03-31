/**
 * Author: Juan Luis Gozalo (juanluis.gozalo@huanLuRobotics.com)
 * Date: 24/Mar/2021
 * Version 1.0.0
 * 
 * Description: Test Robot Head moving right-left-center one time
 *  
 * Material:
 * a Elegoo Servo 180º (connected to pin 5V, GND and PIN 9)
 *  
 **/
#include <Constants.h>
#include <Servo.h>

#ifndef DEBUG_MODE
#define DEBUG_MODE
#endif

const byte PIN_SERVO = 9; // set pin 9 for Servo
int sensibility = 95; // set sensibility level
int counter = 0; // set value to 0 for counter
Servo head_engine;

//#ifndef DEBUG_MODE
void setup () {
    connect_head();
}

void loop() {
   if (counter == 0) {
      initial_hello();
      counter = 1;       
   }
}
//#endif

void connect_head() {
   head_engine.attach(PIN_SERVO);
}

void move_head(int direction) {
   head_engine.write(direction);
   delay(500);
}

void stop_head(){
   head_engine.detach();
}

void initial_hello(){
   move_head(LEFT_MOVEMENT); // move head left
   move_head(RIGHT_MOVEMENT); // move head right
   move_head(CENTER_MOVEMENT); // move head center
   stop_head();
}