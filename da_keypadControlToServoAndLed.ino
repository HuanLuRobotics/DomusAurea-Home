// Code to control a servo and a led with the keypad.
// when user press 1212 then servo will be activated (for example, to open courtains)
// when user press 1213 then servo will be deactivated
// when user press 2121 then led will be activated
// when user press 2122 then led will be deactivated
// 1 keypad
// 1 servo
// 1 led

#include <Constants.h>
#include <Keypad.h>
#include <Servo.h>

byte ROW_PINS[ROWS]= {5,4,3,2}; // Arduino pins for Rows
byte COLS_PINS[COLS]={8,7,6}; // Arduino pins for Columns

char i[4] = {0,0,0,0}; //to store the number of the combination
char key=0; // to store each press key
byte j=0; // index
byte cont=0; // to ensure only 4 digits will be pressed
const byte PIN_LED=13; 
const byte PIN_ENGINE=7;
Keypad keypad= Keypad(makeKeymap(KEYS), ROW_PINS, COLS_PINS, ROWS, COLS);
Servo engine;

void setup() {
   Serial.begin(SERIAL_RATE);
   pinMode(PIN_LED, OUTPUT);
   engine.attach(PIN_ENGINE); // servo activated in pin 7
}

void loop() {
    while (cont<4) {
        key = keypad.getKey();
        i[j]=key;
        if (key) {
            Serial.println(i[0]);
            Serial.println(i[1]);
            Serial.println(i[2]);
            Serial.println(i[3]);
            j=j+1;
            cont=cont+1;
        }
    }
    // Servo
    if (i[0]=='1' && i[1]=='2' && i[2]=='1' && i[3]=='2') {
       engine.write(GO_MOVEMENT); // servo activated
       i[0]=0;
       i[1]=0;
       i[2]=0;
       i[3]=0;
    } else {
      if (i[0]=='1' && i[1]=='2' && i[2]=='1' && i[3]=='3') {
       engine.write(STOP_MOVEMENT); // servo activated
       i[0]=0;
       i[1]=0;
       i[2]=0;
       i[3]=0;
    }

    // Led
    if (i[0]=='21' && i[1]=='1' && i[2]=='2' && i[3]=='1') {
       digitalWrite(PIN_LED, HIGH); // led activated
       i[0]=0;
       i[1]=0;
       i[2]=0;
       i[3]=0;
    } else {
      if (i[0]=='2' && i[1]=='1' && i[2]=='2' && i[3]=='2') {
       digitalWrite(PIN_LED,LOW); // led disable
       i[0]=0;
       i[1]=0;
       i[2]=0;
       i[3]=0;
    }
    
    cont=0;
    j=0;
    key=0;
}
}