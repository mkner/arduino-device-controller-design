
/*
 * mike knerr
 * 
 * simple code to test tact switch operation
 * and noise reduction with a pullup resistor:
 * external and with arduino builtin
 */
 
#define LED_PIN 13 //arduino board light
#define DIGITAL_IN 7 //read this pin



 void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(DIGITAL_IN, INPUT);
    //pinMode(DIGITAL_IN, INPUT_PULLUP);
 }

void loop() {
    // send input signal to the LED continuously
    digitalWrite(LED_PIN, digitalRead(DIGITAL_IN));
}
