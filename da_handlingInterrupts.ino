// How to handle interruptions
// 1 button
// 1 R220
//1 led

int button = 7;
int led=13; 
int vb=0;

void setup () {
    pinMode(button, INPUT);
    pinMode(led, OUTPUT);
    Serial.begin(9600);
    attachInterrupt(0, blinking, HIGH); // this instruction will handle the interruptions
}

void loop () {
    for (int t=0; t<500; t++) {
        Serial.println(t);
    }
}

void blinking () { // function to do something
    vb=digitalRead(button);
    if (vb==HIGH) {
        digitalWrite(led, HIGH);
    } else {
        digitalWrite(led, LOW);
    }
}
