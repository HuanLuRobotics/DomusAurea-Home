// This is the Domus Aurea Assistant Robot
// It is created based on the ROBOT K-5 presented by Pedro Porcunas

/* =================================================================
 material:
  Container for the robot body (a plastic bottle)
  Container for the robot head (a box)
  Papers for dress
  Arduino controller
  Mini Protoboard 
  For the Speaker:
      1 Buzzer (Elegoo Active Buzzer)
      1 Resistor 100 ohms
  cables
 */

#define DEBUG_MODE
#define SKETCH_NAME "DomusAssistantRobot"
#define SKETCH_VERSION "1.0"
#define ACTIVE_LOW

#ifdef DEBUG_MODE
#define DEBUG_PRINT(x) Serial.print(x)
#define DEBUG_PRINTLN(x) Serial.println(x)
#else
#define DEBUG_PRINT(x)
#define DEBUG_PRINTLN(x)
#endif

#ifdef ACTIVE_LOW
#define MHIGH 0X0
#define MLOW 0X1
#else
#define MHIGH 0X1
#define MLOW 0X0
#endif

#include <Constants.h>

const byte PIN_BUZZER=3;

void setup() {
    Serial.begin(SERIAL_RATE);
    pinMode(PIN_BUZZER, OUTPUT);
    // set Start on Robot
    tone(PIN_BUZZER, 950,900); // make a sound
    delay(200);
    noTone(PIN_BUZZER);
    delay(200);
    tone(PIN_BUZZER, 750,300);
    delay(200);
    DEBUG_PRINTLN();
    DEBUG_PRINTLN("Robot started");
}

void loop () {
}


//********************************
// AUXILIAR FUNCTIONS
//********************************

void tono_correcto() {
    tone(3,950,900);
    delay(200);
    noTone(3);
    delay(200);
    tone(3,850,300);
    delay(200);
    noTone(3);
    delay(200);
    tone(3,750,300);
    delay(500);
}

void tono_no_correcto() {
    tone(3,750,900);
    delay(200);
    noTone(3);
    delay(200);
    tone(3,350,300);
    delay(200);
    noTone(3);
    delay(200);
    tone(3,950,900);
    delay(500);
}