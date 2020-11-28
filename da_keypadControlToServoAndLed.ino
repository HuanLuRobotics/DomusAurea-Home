// Code to control a servo and a led with the keypad.
// when user press 1212 then servo will be activated (for example, to open courtains)
// when user press 1213 then servo will be deactivated
// when user press 2121 then led will be activated
// when user press 2122 then led will be deactivated
// 1 keypad
// 1 servo
// 1 led

#include <Keypad.h>
#include <Servo.h>
const byte ROWS=4;
const byte COLS=3;

char keys[ROWS][COLS] = {
    {`1´, `2´, `3´},
    {`4´, `5´, `6´},
    {`7´, `8´, `9´},
    {`*´, `0´, `#´}   
};
byte rowPins[ROWS]= {5,4,3,2}; // Arduino pins for Rows
byte colPins[COLS]={8,7,6}; // Arduino pins for Columns

char i[4] = {0,0,0,0}; //to store the number of the combination
char key=0; // to store each press key
int j=0; // index
int cont=0; // to ensure only 4 digits will be pressed
int led=13; 
Keypad keypad= Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
Servo engine;

void setup() {
   Serial.begin(9600);
   pinMode(led, OUTPUT);
   engine.attach(7); // servo activated in pin 7
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
       engine.write(180); // servo activated
       i[0]=0:
       i[1]=0;
       i[2]=0;
       i[3]=0;
    } else {
      if (i[0]=='1' && i[1]=='2' && i[2]=='1' && i[3]=='3') {
       engine.write(90); // servo activated
       i[0]=0:
       i[1]=0;
       i[2]=0;
       i[3]=0;
    }
    // Led
    if (i[0]=='21' && i[1]=='1' && i[2]=='2' && i[3]=='1') {
       digitalWrite(led, HIGH); // led activated
       i[0]=0:
       i[1]=0;
       i[2]=0;
       i[3]=0;
    } else {
      if (i[0]=='2' && i[1]=='1' && i[2]=='2' && i[3]=='2') {
       digitalWrite(led,LOW); // led activated
       i[0]=0:
       i[1]=0;
       i[2]=0;
       i[3]=0;
    }
    cont=0;
    j=0;
    key=0;
}
}