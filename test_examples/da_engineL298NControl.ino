// how to control a engine 
// 1 L298N controllers
// 2 DC engine
// 1 battery slot with AA battery

const byte PIN_ENGINE_1_A= 2; //
const byte PIN_ENGINE_1_B=3; //
const byte PIN_ENGINE_2_A=4; //
const byte PIN_ENGINE_2_B=5; //

void setup () {
    pinMode(PIN_ENGINE_1_A, OUTPUT);
    pinMode(PIN_ENGINE_1_B, OUTPUT);
    pinMode(PIN_ENGINE_2_A, OUTPUT);
    pinMode(PIN_ENGINE_2_B, OUTPUT);
}

void loop () {
    // move engine 1
    digitalWrite(PIN_ENGINE_1_A, HIGH);
    digitalWrite(PIN_ENGINE_1_B, LOW);

    // move engine 2
    digitalWrite(PIN_ENGINE_2_A, HIGH);
    digitalWrite(PIN_ENGINE_2_B, LOW);
}