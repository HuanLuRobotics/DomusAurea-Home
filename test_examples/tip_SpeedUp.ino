/*
************************************************************************************************************************************* 
  Know how much memory is available
*************************************************************************************************************************************
*/
unsigned int UnusedRAM()
{
    unsigned int byteCounter = 0;
    byte *byteArray;
    while ( (byteArray = (byte*) malloc (byteCounter * sizeof(byte))) != NULL )
    {
        byteCounter++;
        free(byteArray);
    }
    free(byteArray);
    return byteCounter;
}

/* 
*************************************************************************************************************************************
Analog reading on USB powered Arduino models can produce some weird results, 
that's because the Analog reference voltage is tied to the logic voltage, which is 5 volts, 
but if you power your board from a switching power supply or from USB, 
you can get some serious noise and voltage drop due to the USB cable. 
So it's posible that your controller is running from 4.5 volts instead of 5 volts.

This is not ideal for precision measurements. To do measurements, you will need to use an external precision voltage reference. 
Alternatively, you can use the chip's built in voltage reference to measure the current VCC and do some compensated calculations with that.
*************************************************************************************************************************************
*/
int GetVccMiliVolts()
{
    #if defined(ARDUINO_ARCH_AVR)
    const long int scaleConst = 1156.300 * 1000;
    // Read 1.1V reference against Avcc
    #if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
        ADMUX = _BV(REFS0) | _BV(MUX4) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
    #elif defined (__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__)
        ADMUX = _BV(MUX5) | _BV(MUX0);
    #elif defined (__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
        ADMUX = _BV(MUX3) | _BV(MUX2);
    #else
        ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
    #endif
    delay(2); // Wait for Vref to settle
    ADCSRA |= _BV(ADSC); // Start conversion
    while(bit_is_set(ADCSRA,ADSC)); // measuring
    uint8_t low = ADCL; // must read ADCL first - it then locks ADCH
    uint8_t high = ADCH; // unlocks both
    long int result = (high<<8) | low;
    result = scaleConst / result;
    // Calculate Vcc (in mV); 1125300 = 1.1*1023*1000
    return(int)result; // Vcc in millivolts
    #else
        return -1;
    #endif
    
}

/* 
*************************************************************************************************************************************
If you have to store large amounts of data in your code (like a bitmap or fornt, or whatever) 
make the variable global const & include the PROGMEM statement. 
This directs the compiler to store the data only in the program memory instead of the RAM.
*************************************************************************************************************************************
*/
#include <PGMWrap.h>
const byte big_array[5120] PROGMEM = {0}; //5120 byte array. Normally it woudn't fit into the RAM, but with static storage it gets stored in the program memory


/* 
*************************************************************************************************************************************
Eliminate the delays on the LOOP main program using some additional variables
*************************************************************************************************************************************
*/
unsigned long LastLEDToggleTime = 0; // Time stamp when the LED was last turned on or off. 
bool IsLEDOn = false; // Current state of the LED; true => on; false => off. 
const int LEDTogglePeriod = 1000; // [milliseconds] // Time between turning the LED on or off 
const int LEDPin = 13;
 
void loop()
{
  // This will toggle the LED on and off, with no wasteful delays
  if ((millis() - LastLEDToggleTime) > LEDTogglePeriod)
  {
    IsLEDOn = !IsLEDOn; // toggle status
    digitalWrite(LEDPin, IsLEDOn ? HIGH : LOW);
  }
  // Do something else here with no wasting time
}

