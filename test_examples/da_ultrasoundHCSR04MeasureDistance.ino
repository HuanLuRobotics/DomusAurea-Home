// how to measure distances
// 1 sensor HC-SR04
// 1 led red u other accionable device

const byte PIN_TRIGGER=12; // pin to send the TRIGGER
const byte PIN_ECHO=11; // pin to recibe the ECHO

unsigned int time; // variable to track time of pulse
unsigned int distance; // variable to track distance

void setup () {
    Serial.begin(9600); // start serial communication
    pinMode(PIN_TRIGGER,OUTPUT); // set output pin
    pinMode(PIN_ECHO,INPUT); // set input pin
}

void loop () {
    digitalWrite(PIN_TRIGGER, LOW); // set a low value to the Trigger 
    delayMicroseconds(2); // wait for 2 microseconds before activate the trigger
    digitalWrite(PIN_TRIGGER, HIGH); // set a high value to the Trigger 
    delayMicroseconds(2); // wait for 2 microseconds before deactivate the trigger
    digitalWrite(PIN_TRIGGER, LOW); // set a low value to the Trigger 
    
    // Calculate the distance
    // sound velocity is 340 m/s. So, 29,4 microseconds is the time that is spent in one centimeter.
    // doubling this time is the time to go and return the signal (rounded)
    // d = v.t/2
    time = pulseIn(PIN_ECHO, HIGH); // store the time between the send and return of the signal
    distance = time/58; 
    Serial.print(distance);
    Serial.println(" cm");
    delay(200);
}
