// a LDR for the garden
// 1 LDR
// 1 R1KHOhm
// 3 R220 for leds
// 3 Leds

int ldr = AO;
int sensibility = 95; // variable of bottom level
int light_1=2; // pin for Led1
int light_2=3; // pin for Led2
int light_3=4; // pin for Led3
int val=0; // variable to store the LDR value

void setup () {
    Serial.begin(9600);
    pinMode(light_1, OUTPUT);
    pinMode(light_2, OUTPUT);
    pinMode(light_3, OUTPUT);
    pinMode(ldr, INPUT);
}

void loop () {
    val = analogRead(ldr); // read the LDR value between 0 to 1.023
    Serial.println(val); // print the value for debug
    delay(100);
    if (val<=sensibility) { // if under the bottom level
        digitalWrite(light_1, HIGH);
        digitalWrite(light_2, HIGH);
        digitalWrite(light_3, HIGH);
    } else { // else the value is over the bottom level
        digitalWrite(light_1, LOW);
        digitalWrite(light_2, LOW);
        digitalWrite(light_3, LOW);
    }
    // if you want to use map() then the code will be written
    // map (value, 0, 1023, 0, 255);
    // if (value == 255) { //when reach the 255 (max value)
    //     Serial.println(value);
    // }
}