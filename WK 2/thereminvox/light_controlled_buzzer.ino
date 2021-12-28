
/*
 * mike knerr
 * 
 * an optical-thereminvox, not the original analog RF type
 * buzzer tone varies directly with reading 
 * from light sensor (photoresistor)
 * and what a story https://en.wikipedia.org/wiki/Leon_Theremin
 */
 
#define BUZZER_PIN 8 //digital
#define LIGHT_SENSOR A0 //analog


 void setup() {
    pinMode(BUZZER_PIN, OUTPUT);
    Serial.begin(9600);
 }

void loop() {
  
    //monitor numerical output from sensor also
    
    int sensorValue = analogRead(A0); // read input on analog pin 0 (A0)
    Serial.println(sensorValue); // print out result to serial monitor
    
    tone(BUZZER_PIN, analogRead(LIGHT_SENSOR) * 4,10);
  
    //noTone(BUZZER_PIN);
}
