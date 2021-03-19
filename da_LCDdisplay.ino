// how to show with an LCD display
// 1 LCD display (L1602A o L16216)
// 1 potentiometer 4,7 to 10KOhm

#include <LiquidCrystal.h>

LiquidCrystal lcd(6,7,8,9,10,11,12); // pins connected to LCD

void setup() {
    lcd.begin(16,2); // start LCD with 2 actives lines

    lcd.setCursor(0,0); // enable test in the first line of the LCD
    lcd.write("Demo LCD display"); //
    lcd.setCursor(0,1); // enable test in the second line of the LCD
    lcd.write("================="); //
}
void loop() {
    // it is not required to call
}