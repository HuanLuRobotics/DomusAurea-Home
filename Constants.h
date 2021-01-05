// Definition of constants to be used across programs
const int RIGHT_MOVEMENT = 180; // value to move the servo to the rigth
const int LEFT_MOVEMENT = 0; // value to move the servo to the left
const int CENTER_MOVEMENT = 90; // value to move the servo to the stop
const int STOP_MOVEMENT = 90; // value to move the servo to the stop
const int TRIGGER_PIN = 12; // trigger of distance sensor
const int ECHO_PIN = 11; // echo of distance sensor
const int MAX_DISTANCE = 200 ; // max distance 200 cm
const int IR_UP= 0; //HAY QUE AJUSTAR ESTE VALOR
const int IR_DOWN= 0; //HAY QUE AJUSTAR ESTE VALOR
const int IR_LEFT= 0; //HAY QUE AJUSTAR ESTE VALOR
const int IR_RIGHT= 0; //HAY QUE AJUSTAR ESTE VALOR

const byte ROWS=4;
const byte COLS=3;
char keys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}   
};

