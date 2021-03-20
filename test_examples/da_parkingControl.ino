// Parking control
// 1 ultrasound sensor 
// 1 LCD Displays
// 1 KOhm potentiometer
// 1 Red Led
// 1 Green Led
// 1 R220 (for the led that is not conected to the Pin13)

#include <Constants.h>
#include <NewPing.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,11,12,13);
const byte PIN_TRIGGER = 4; // for raise the ultrasound pulse
const byte PIN_ULTRASOUND_ECHO = 3; // for echo ultrasound pulse
const int DISTANCE_MAX=200;

int dist = 0;
int PIN_LED_GREEN=2;
int PIN_LED_RED=7;
unsigned int tmp;

NewPing sensor (PIN_TRIGGER, PIN_ULTRASOUND_ECHO, DISTANCE_MAX);

void setup() {
    Serial.begin(SERIAL_RATE);
    pinMode(PIN_LED_GREEN, OUTPUT);
    pinMode(PIN_LED_RED, OUTPUT);
    lcd.begin(16,2);
}

void loop() {
    delay(200);
    tmp=sensor.ping();
    Serial.print("Ping: ");
    Serial.print(tmp/US_ROUNDTRIP_CM);
    Serial.println("cm");
    dist =  tmp/ US_ROUNDTRIP_CM;
    if (dist <10) {
        digitalWrite(PIN_LED_RED, HIGH);
        digitalWrite(PIN_LED_GREEN, LOW);
        lcd.setCursor(0,0);
        lcd.write("OCCUPIED");
        lcd.setCursor(0,1);
        lcd.write("SPACE");
    } else {
        digitalWrite(PIN_LED_RED, LOW);
        digitalWrite(PIN_LED_GREEN, HIGH);
        lcd.setCursor(0,0);
        lcd.write("FREE");
        lcd.setCursor(0,1);
        lcd.write("SPACE");    
    }
}

