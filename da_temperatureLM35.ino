// how to set the temperature with the LM35 sensor
// 1 LM35 temperature sensor

#include <Constants.h>

float value = 0;
int degrees = 0;
const byte PIN_SENSOR_TEMPERATURE = A0; // pin Analogic0

void setup () {
    Serial.begin (SERIAL_RATE);
    pinMode(PIN_SENSOR_TEMPERATURE, INPUT);
}

// version 1 with display by Serialport
void loop () {
    value = analogRead(PIN_SENSOR_TEMPERATURE);
    degrees = value*0.4882125; // this value is 5*100/1024
    Serial.print("Temperature= ");
    Serial.print(degrees);
    Serial.print(" degrees");
    Serial.println();
    delay(ONE_MINUTE); // wait one minute to repeat
}

/* version 2 with display by LCD
// 1 LCD display
#include <Constants.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,11,12,13);
float value = 0;
int degrees = 0;
const byte PIN_SENSOR_TEMPERATURE = A0; // pin Analogic0

void setup () {
    Serial.begin (SERIAL_RATE);
    pinMode(PIN_SENSOR_TEMPERATURE, INPUT);
    lcd.begin(16,2);
}

// version 1 with display by Serialport
void loop () {
    value = analogRead(PIN_SENSOR_TEMPERATURE);
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
    delay(ONE_MINUTE); // wait one minute to repeat
}
*/