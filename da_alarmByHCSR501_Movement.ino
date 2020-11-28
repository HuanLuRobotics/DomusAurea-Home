// Alarm by movement
// Sensor PIR HC-SR501 (this sensor send data during 4 seconds that can be adjusted with the potentionmeters)
// 1 Led Red (or a accionable component)

int led =13; // pin 13 to led 
int sensor = 8 ; // pin 8 to sensor
int value = 0; // variable to store the value that is read from Sensor
boolean status = false; // status variable

void setup () {
    pinMode(led, OUTPUT);
    pinMode(sensor, INPUT);
    Serial.begin(9600);
}

void loop () {
    value = digitalRead(sensor); // read the sensor value
    if (value == HIGH) { 
        digitalWrite(led, HIGH); // set led to brightness
        while (status == false) { // this loop is to avoid that msg will be printed a lot of times just for one detection
           Serial.println("MOVEMENT ALARM DETECTED!");
           status = true;
        }
    } else {
        digitalWrite(led, LOW); // set led to dark
        if (status == true) {
            status == false;
        }
    }
}