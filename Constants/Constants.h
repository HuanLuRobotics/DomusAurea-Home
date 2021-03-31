/**
 * Author: Juan Luis Gozalo (juanluis.gozalo@huanLuRobotics.com)
 * Date: 22/Mar/2021
 * Version 1.0.0
 * 
 * Description: DomusAurea Constants file for the whole project
 * This file must be located under the library path of the IDE for compilation (including the Directory Name).
 *
 **/

#ifndef DOMUSAUREA_CONSTANTS_H
#define DOMUSAUREA_CONSTANTS_H

#include <Arduino.h>

// Set Debug options
#ifdef DEBUG_MODE
#define DEBUG_PRINT(x) Serial.print(x)
#define DEBUG_PRINTLN(x) Serial.println(x)
#else
#define DEBUG_PRINT(x)
#define DEBUG_PRINTLN(x)
#endif

// Set High-Low Operation Mode Values
#ifdef ACTIVE_LOW
#define MHIGH 0X0
#define MLOW 0X1
#else
#define MHIGH 0X1
#define MLOW 0X0
#endif

// Definition of constants to be used across programs
//
// General Settings
const int MAX_DISTANCE = 200; // max distance 200 cm
const int TRIGGER_PIN = 12; // trigger of distance sensor
const int ECHO_PIN = 11; // echo of distance sensor
const int SERIAL_RATE=9600; // rate for serial communication

// Movements settings
const int RIGHT_MOVEMENT = 180; // value to move the servo to the rigth
const int LEFT_MOVEMENT = 0; // value to move the servo to the left
const int CENTER_MOVEMENT = 90; // value to move the servo to the stop
const int GO_MOVEMENT = 180; // value to move the servo to the go
const int STOP_MOVEMENT = 90; // value to move the servo to the stop

// Infrared Settings
const int IR_UP= 0; //HAY QUE AJUSTAR ESTE VALOR
const int IR_DOWN= 0; //HAY QUE AJUSTAR ESTE VALOR
const int IR_LEFT= 0; //HAY QUE AJUSTAR ESTE VALOR
const int IR_RIGHT= 0; //HAY QUE AJUSTAR ESTE VALOR

// PinPad Keys
const byte ROWS=4;
const byte COLS=3;
char KEYS[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}   
};

// PinPad Remote Button values. These values will be sets when decoding using the da_RemoteKeyTSOP4838Decoding.ino program
const unsigned long BT_UP=3772795063;
const unsigned long BT_DOWN=3772778743;
const unsigned long BT_LEFT=3772829743;
const unsigned long BT_RIGHT=3772833823;
const unsigned long BT_OK=3772837903;
const unsigned long BT_OFF=0;
const unsigned long BT_NUMBER_1=2498985700;
const unsigned long BT_NUMBER_2=4129126878;
const unsigned long BT_NUMBER_3=2172071812;
const unsigned long BT_NUMBER_4=2172071812;
const unsigned long BT_NUMBER_5=3345571616;
const unsigned long BT_NUMBER_6=145526690;
const unsigned long BT_NUMBER_7=0;
const unsigned long BT_NUMBER_8=0;
const unsigned long BT_NUMBER_9=0;
const unsigned long BT_NUMBER_0=0;

// ...

// Time
const int ONE_MINUTE=60000;
const int ONE_SECOND=1000;
const int TWO_SECONDS=2000;

#endif