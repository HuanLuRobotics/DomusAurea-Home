// how to set a key with the pannel 
// 1 touch key pannel 4x4
// 1 LCD pannel
// 1 green led

#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd (8,9,10,11,12,13);
const byte ROWS = 4; // 4 columns
const byte COLS = 3; // 3 columns

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
Keypad keypad= Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup () {
   Serial.begin(9600);
   pinMode(A0, OUTPUT);
   lcd.begin(16,2);
   doClose();
   doClean();
   doStart();
}

void loop () {
   while (cont<4) {
        key = keypad.getKey();
        i[j]=key;
        if (key) {
            Serial.print('*');
            j=j+1;
            cont=cont+1;
        }
    }
    // Authorised key 1
    if (i[0]=='1' && i[1]=='2' && i[2]=='1' && i[3]=='2') {
       Serial.println();
       Serial.println("Accepted Key");
       Serial.println();
       analogWrite(A0,255);
       doClean();
       lcd.setCursor(0,0);
       lcd.write("Greetings");
       lcd.setCursor(0,1);
       lcd.write("User 1");
       i[0]=0:
       i[1]=0;
       i[2]=0;
       i[3]=0;
       delay(4000);
       doClean();
       doStart();
       analogWrite(A0,0);
    } else {
       // Authorised Key 2
      if (i[0]=='2' && i[1]=='3' && i[2]=='3' && i[3]=='2') {
       Serial.println();
       Serial.println("Accepted Key");
       Serial.println();
       analogWrite(A0,255);
       doClean();
       lcd.setCursor(0,0);
       lcd.write("Greetings");
       lcd.setCursor(0,1);
       lcd.write("User 2");
       i[0]=0:
       i[1]=0;
       i[2]=0;
       i[3]=0;
       delay(4000);
       doClean();
       doStart();
       analogWrite(A0,0);
     } else {
       Serial.println();
       Serial.println("Wrong Key");
       Serial.println();
       doClean();
       lcd.setCursor(0,0);
       lcd.write("Access");
       lcd.setCursor(0,1);
       lcd.write("Denied");
       i[0]=0:
       i[1]=0;
       i[2]=0;
       i[3]=0;
       delay(3000);
       doClean();
       doClose();
       delay(3000);
       doClean();
       doStart();
     }
    cont=0;
}

// Additional functions

void doClean() {
   lcd.setCursor(0,0);
   lcd.write("        ");
   lcd.setCursor(0,1);
   lcd.write("        ");
}

void doStart () {
   lcd.setCursor(0,0);
   lcd.write("ENTER");
   lcd.setCursor(0,1);
   lcd.write("KEY");
}

void doClose() {
   lcd.setCursor(0,0);
   lcd.write("ACCESS");
   lcd.setCursor(0,1);
   lcd.write("CLOSED");
}