// using a potentionmeter
// 1 Potentiometer of 10KOhms
// 1 R220 to be used by led if pin 13 is not used
// 1 Led

int pot = AO; // assign analog pin A0 to the central terminal of potentionmeter
int value; // variable to store the potentionmeter value
int led=13; 

void setup() {
    Serial.begin(9600); // start serial communication
    pinMode(pot, INPUT);
    pinMode(led, OUTPUT);
}

void loop() {
    value = analogRead(pot); // store the values
    Serial.println(value); // print values

    if (value <= 100) {
        digitalWrite(led, HIGH); // set led to brightness
    }

    if (value > 300 && value < 500) {
        digitalWrite(led, LOW); // set led to dark
    }

    if (value >900) {
        digitalWrite(led, HIGH); // set led to bright
    }
}