// semaphores in an intersection
// 6 Leds (2 green, 2 red, 2 amber)
// 6 R220 

const byte r1=7; // red semaphore 1
const byte a1=8; // amber semaphore 1
const byte g1=6; // green semaphore 1
const byte r2=10; // red semaphore 2
const byte a2=11; // amber semaphore 2
const byte g2=12; // green semaphore 2

void setup () {
    pinMode (r1, OUTPUT); // r1 as output
    pinMode (r2, OUTPUT); // r2 as output
    pinMode (a1, OUTPUT); // a1 as output
    pinMode (a2, OUTPUT); // a2 as output
    pinMode (g1, OUTPUT); // v1 as output
    pinMode (g2, OUTPUT); // v2 as output

    // set initial state of the semaphores
    digitalWrite(r1, HIGH); // semaphore 1 is closed
    digitalWrite(a1, LOW);
    digitalWrite(g1, LOW);
    digitalWrite(r2, LOW);
    digitalWrite(a1, LOW);
    digitalWrite(g2, HIGH); // semaphore 2 is opened
    delay(1000);
}

void  loop () {
    // semaphore 1 is closed, semaphore 2 is amber
    digitalWrite(r1, HIGH);
    digitalWrite(a1, LOW);
    digitalWrite(g1, LOW);
    digitalWrite(r2, LOW);
    digitalWrite(a1, HIGH);
    digitalWrite(g2, LOW); 
    delay(1000);

    // semaphore 1 is closed, semaphore 2 is closed
    digitalWrite(r1, HIGH);
    digitalWrite(a1, LOW);
    digitalWrite(g1, LOW);
    digitalWrite(r2, HIGH);
    digitalWrite(a1, LOW);
    digitalWrite(g2, LOW);
    delay(1000);
    
    // semaphore 1 is opened, semaphore 2 is closed
    digitalWrite(r1, LOW);
    digitalWrite(a1, LOW);
    digitalWrite(g1, HIGH);
    digitalWrite(r2, HIGH);
    digitalWrite(a1, LOW);
    digitalWrite(g2, LOW);
    delay(1000);
    
    // semaphore 1 is amber, semaphore 2 is closed
    digitalWrite(r1, LOW);
    digitalWrite(a1, HIGH);
    digitalWrite(g1, LOW);
    digitalWrite(r2, HIGH;
    digitalWrite(a1, LOW);
    digitalWrite(g2, LOW);
    delay(1000);
    
    // semaphore 1 is closed, semaphore 2 is closed
    digitalWrite(r1, HIGH);
    digitalWrite(a1, LOW);
    digitalWrite(g1, LOW);
    digitalWrite(r2, HIGH);
    digitalWrite(a1, LOW);
    digitalWrite(g2, LOW);
    delay(1000);
    
    // semaphore 1 is closed, semaphore 2 is opened
    digitalWrite(r1, HIGH);
    digitalWrite(a1, LOW);
    digitalWrite(g1, LOW);
    digitalWrite(r2, LOW);
    digitalWrite(a1, LOW);
    digitalWrite(g2, HIGH);
    delay(1000);
    
}