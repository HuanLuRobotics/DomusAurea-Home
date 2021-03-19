// Programming a Remote Control 
// 1 LCD
// 1 TSOP 4838
// Remote control device

#include <Constants.h>
#include <IRremote.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,11,12,13);
const byte PIN_RECV = 4;
IRrecv ir(PIN_RECV);
decode_results results; // to store the remote result

void setup() {
    Serial.begin(SERIAL_RATE);
    ir.enableIRIn(); // enable the device
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.write("Press");
    lcd.setCursor(1,0);
    lcd.write("a key");
}

void loop() {
    if (ir.decode(&results)) { // when data is received
        Serial.println(results.value, DEC); // print the button code that has been pressed
        delay(200); // wait
        ir.resume(); // receive the next key
        lcd.clear(); // clear the LCD
        lcd.setCursor(0,0);
        lcd.write("Not");
        lcd.setCursor(1,0);
        lcd.write("Assigned");
    }
    if (results.value == BT_NUMBER_1) { //button 1 pressed
       lcd.setCursor(0,0);
       lcd.write("Button 1");
       lcd.setCursor(1,0);
       lcd.write("Activated");
    }
    if (results.value == BT_NUMER_2) { //button 2 pressed
       lcd.setCursor(0,0);
       lcd.write("Button 2");
       lcd.setCursor(1,0);
       lcd.write("Activated");
    }
    if (results.value == BT_NUMBER_3) { //button 3 pressed
       lcd.setCursor(0,0);
       lcd.write("Button 3");
       lcd.setCursor(1,0);
       lcd.write("Activated");
    }
    if (results.value == BT_NUMBER_4) { //button 4 pressed
       lcd.setCursor(0,0);
       lcd.write("Button 4");
       lcd.setCursor(1,0);
       lcd.write("Activated");
    }
    if (results.value == BT_NUMBER_5) { //button 1 pressed5 set LCD Active
       lcd.display();
       lcd.setCursor(0,0);
       lcd.write("Display");
       lcd.setCursor(1,0);
       lcd.write("Activated");
    }
    if (results.value == BT_NUMBER_6) { //button 6 set LCD Inactive
       lcd.setCursor(0,0);
       lcd.write("Display");
       lcd.setCursor(1,0);
       lcd.write("Inactivated");
       delay(3000);
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.write('3');
       delay(3000);
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.write('2');
       delay(3000);
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.write('1');
       delay(3000);
       lcd.clear();
       lcd.noDisplay();       
    }
}