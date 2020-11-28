// how to control a engine 
// 1 L298N controllers
// 2 DC engine
// 1 battery slot with AA battery

int IN2= 2; //
int IN3=3; //
int IN4=4; //
int IN5=5; //

void setup () {
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(IN5, OUTPUT);
}

void loop () {
    // move engine connected to the pins 2 and 3
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);

    // move engine connected to the pins 4 and 5
    digitalWrite(IN4, HIGH);
    digitalWrite(IN5, LOW);

}