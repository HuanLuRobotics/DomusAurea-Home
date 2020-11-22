// calculate how many people is insdide a place
// 1 Led laser
// 1 R1KHOhm
// 1 Led red (for signal)

int laser = 13; // pin 13
int ldr=A0; // pin Analogic0
int counter=0; // variable for counter
int value= 0; // variable for value
int led=4; // pint 4

void setup() {
    Serial.begin();
    pinMode (laser,OUTPUT); // pin
    pinMode (led,OUTPUT); // pin
    pinMode (ldr,INPUT); // pin
}

void loop() {
    digitalWrite (laser, HIGH); // set laser one
    value = analogRead (ldr); // read ldr and store value
    if (value <= 200) {
        counter++; // increment number of persons 
        if (counter == 100) {
            Serial.println("WARNING: MAX NUMBER of persons reached");
        } else {
            digitalWrite (led, HIGH); // set led for visual warning
            Serial.print(100-counter); // number of persons left
            Serial.println(" still available");
            delay(2000); // time for a person to pass the entry
            digitalWrite (led, LOW); // set led off for visual warning
        }
    }
}