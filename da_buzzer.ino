// Buzzer
// 1 Buzzer (4ohms, 8ohms)
// 1 R100 or 1 R220 

int piez = A0; // analog pin

void setup () {
    pinMode (piez, OUTPUT); // set pin as output
}

void loop () {
    delay (100);
    for (int i=200;i<=1800;i=i+100) { // do for each frequent starting from 200
        tone (piez, i, 100); // do sound at pin piez with frequent i during 100 millis
        delay(100);
        noTone(piez); // do silence
    }
}