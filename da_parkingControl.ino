// Parking control
// 1 ultrasound sensor 
// 1 LCD Displays
// 1 KOhm potentiometer
// 1 Red Led
// 1 Green Led
// 1 R220 (for the led that is not conected to the Pin13)

#include <NewPing.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,11,12,13);
#define TRIGGER 4 // set pin 4 for raise the ultrasound pulse
#define ECHO 3 // set  pin 3 for echo ultrasound pulse
#define DISTANCE_MAX 200

int dist = 0;
int pinled_green=2;
int pinled_red=7;
unsigned int tmp;
NewPing sensor (TRIGGER, ECHO, DISTANCE_MAX);

void setup() {
    Serial.begin(9600);
    pinMode(pinled_green, OUTPUT);
    pinMode(pinled_red, OUTPUT);
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
        digitalWrite(pinled_red, HIGH);
        digitalWrite(pinled_green, LOW);
        lcd.setCursor(0,0);
        lcd.write("OCCUPIED");
        lcd.setCursor(0,1);
        lcd.write("SPACE");
    } else {
        digitalWrite(pinled_red, LOW);
        digitalWrite(pinled_green, HIGH);
        lcd.setCursor(0,0);
        lcd.write("FREE");
        lcd.setCursor(0,1);
        lcd.write("SPACE");    
    }
}

