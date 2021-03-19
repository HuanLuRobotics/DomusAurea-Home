// How to detect the volume of a sound and display in a LCD pannel.
// 2 potentionmeters (one for display and one for measurement)
// 1 LCD Displays

#include <LiquidCrystal.h>
#include <Constants.h>
const byte PIN_POTENTIOMETER=A0; 
int valor;
LiquidCrystal lcd(6,7,9,9,10,11,12);

void setup () {
    Serial.begin(SERIAL_RATE);
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.write("Volume:");
    lcd.setCursor(0,1);
    lcd.write("00");

    pinMode(PIN_POTENTIOMETER, OUTPUT);
}

void loop () {
    valor = analogRead(PIN_POTENTIOMETER);
    Serial.println(valor);
    if (valor <= 100) {
        lcd.setCursor(0,0);
        lcd.write("Volume:");
        lcd.setCursor(0,1);
        lcd.write("0");
    } else {
    if (valor >= 101 && valor <= 200) {
        lcd.setCursor(0,0);
        lcd.write("Volume:");
        lcd.setCursor(0,1);
        lcd.write("10");
    } else {
    if (valor >= 201 && valor <= 300) {
        lcd.setCursor(0,0);
        lcd.write("Volume:");
        lcd.setCursor(0,1);
        lcd.write("20");
    } else {
    if (valor >= 301 && valor <= 400) {
        lcd.setCursor(0,0);
        lcd.write("Volume:");
        lcd.setCursor(0,1);
        lcd.write("30");
    } else {
    if (valor >= 401 && valor <= 500) {
        lcd.setCursor(0,0);
        lcd.write("Volume:");
        lcd.setCursor(0,1);
        lcd.write("40");
    } else {
    if (valor >= 501 && valor <= 600) {
        lcd.setCursor(0,0);
        lcd.write("Volume:");
        lcd.setCursor(0,1);
        lcd.write("50");
    } else {
    if (valor >= 601 && valor <= 700) {
        lcd.setCursor(0,0);
        lcd.write("Volume:");
        lcd.setCursor(0,1);
        lcd.write("60");
    } else {
    if (valor >= 701 && valor <= 800) {
        lcd.setCursor(0,0);
        lcd.write("Volume:");
        lcd.setCursor(0,1);
        lcd.write("70");
    } else {
    if (valor >= 801 && valor <= 900) {
        lcd.setCursor(0,0);
        lcd.write("Volume:");
        lcd.setCursor(0,1);
        lcd.write("80");
    } else {
    if (valor >= 901 && valor <= 1000) {
        lcd.setCursor(0,0);
        lcd.write("Volume:");
        lcd.setCursor(0,1);
        lcd.write("MAX");
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
}