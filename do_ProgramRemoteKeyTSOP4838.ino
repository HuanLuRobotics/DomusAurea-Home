// Programming a Remote Control 
// 1 LCD
// 1 TSOP 4838
// Remote control device

#include <IRremote.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,11,12,13);
int RECV_PIN = 4;
IRrecv ir(RECV_PIN);
decode_results results; // to store the remote result

void setup() {
    Serial.begin(9600);
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
    if (results.value == 2498985700) { //button 1 pressed
       lcd.setCursor(0,0);
       lcd.write("Button 1");
       lcd.setCursor(1,0);
       lcd.write("Activated");
    }
    if (results.value == 4129126878) { //button 2 pressed
       lcd.setCursor(0,0);
       lcd.write("Button 2");
       lcd.setCursor(1,0);
       lcd.write("Activated");
    }
    if (results.value == 2172071812) { //button 3 pressed
       lcd.setCursor(0,0);
       lcd.write("Button 3");
       lcd.setCursor(1,0);
       lcd.write("Activated");
    }
    if (results.value == 1301396414) { //button 4 pressed
       lcd.setCursor(0,0);
       lcd.write("Button 4");
       lcd.setCursor(1,0);
       lcd.write("Activated");
    }
    if (results.value == 3345571616) { //button 5 set LCD Active
       lcd.display();
       lcd.setCursor(0,0);
       lcd.write("Display");
       lcd.setCursor(1,0);
       lcd.write("Activated");
    }
    if (results.value == 145526690) { //button 6 set LCD Inactive
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