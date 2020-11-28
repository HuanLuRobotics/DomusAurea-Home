// Decoding a Remote Control 
// 1 LCD
// 1 TSOP 4838
// Remote control device

#include <IRremote.h>

int RECV_PIN = 7;
IRrecv ir(RECV_PIN);
decode_results result; // to store the remote result

void setup() {
    Serial.begin(9600);
    ir.enableIRIn(); // enable the device
}

void loop() {
    if (ir.decode(&result)) { // when data is received
        Serial.println(result.value, DEC); // print the button code that has been pressed
        delay(200); // wait
        ir.resume(); // receive the next key
    }
}
