/*
  Potentiometer controlled bar graph (10 segment LED)

  -Mike Knerr
  
  Reads potentiometer input on pin 0 (A0) and
  scales continuous analog input into discrete units
  that map to digital outputs to display LEDs
  on a 10 segment bar graph

*/

#define LED_10 11
#define LED_01 2
#define LED_DELAY 200

#define ANALOG_IN A0

#define ON 1
#define OFF 0

bool RUNNING_MODE = OFF;

bool TEST_MODE = OFF;

void setup() {
  
  //configure pins to LED graph
  for(int i=LED_01; i <= LED_10; i++)
    pinMode(i,OUTPUT);
    
  //turn off display
  for(int i=LED_01; i <= LED_10; i++)
     {
     digitalWrite(i,LOW);
     }
}


void loop() {
  
      // how far pot is turned up determines how many LEDs
      // stay lit simulaneously
      
      int lastLED = map(analogRead(ANALOG_IN),0,1023,LED_01-1,LED_10);
  
          for(int i=LED_01; i <= lastLED; i++)
          {
           digitalWrite(i,HIGH);
             if (RUNNING_MODE == ON && TEST_MODE == OFF) {
             delay(LED_DELAY);
             }
           digitalWrite(i,LOW);
          } 
    
}
