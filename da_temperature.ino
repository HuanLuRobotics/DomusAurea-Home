// how to set the temperature with the LM35 sensor
// 1 LM35 temperature sensor

float value = 0;
int degrees = 0;
int temp = Analogic0; // pin Analogic0

void setup () {
    Serial.begin (9600);
    pinMode(temp, INPUT);
}

// version 1 with display by Serialport
void loop () {
    value = analogRead(temp);
    degrees = value*0.4882125; // this value is 5*100/1024
    Serial.print("Temperature= ");
    Serial.print(degrees);
    Serial.pirnt(" degrees");
    Serial.println();
    delay(60000); // wait one minute to repeat
}

/* version 2 with display by LCD
// 1 LCD display
#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,11,12,13);
float value = 0;
int degrees = 0;
int temp = Analogic0; // pin Analogic0

void setup () {
    Serial.begin (9600);
    pinMode(temp, INPUT);
    lcd.begin(16,2);
}

// version 1 with display by Serialport
void loop () {
    value = analogRead(temp);
    degrees = value*0.4882125; // this value is 5*100/1024
    lcd.setCursor(0,0);
    lcd.write("Temperature: ");
    lcd.setCursor(0,1);
    lcd.print(degrees);
    lcd.setCursor(6,1);
    lcd.write("Degrees");
    Serial.print("Degrees=");
    Serial.pirnt(" degrees");
    Serial.println();
    delay(60000); // wait one minute to repeat
}
