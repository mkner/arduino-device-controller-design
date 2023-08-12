/*
  Test 10 segment LED bar graph display unit
  Produces a running display on an LED bar graph
  
  (c) 2021 Mike Knerr
  
*/

#define LED_10 11
#define LED_01 2
#define LED_DELAY 200

void setup() {
  //configure pins to LED graph
  for(int i=LED_01; i <= LED_10; i++)
    pinMode(i,OUTPUT);
}


void loop() {
  // keep running the LEDs sequentially until forever
  for(int i=LED_01; i <= LED_10; i++)
    {
    digitalWrite(i,HIGH);
    delay(LED_DELAY);
    digitalWrite(i,LOW);
    }
}
