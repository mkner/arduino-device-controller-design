/*
 * traffic light signaling & sequencing
 * светофор (в России)
 * v0.03
 * 
 * (c) 2021-2022 mike knerr
 * 
 * project for:
 * MPIT - Building Arduino Robots and Devices
 * МФТИ - Строим роботов и другие устройства на Arduino
 * 
 * simulate traffic light (generic russian type)- Светофоры в России 
 * sequences & signaling
 * 
 * code is designed to be very readable and follow 
 * written/verbal description and basic project schematic layout
 */
 

// ports for traffic lightS
#define RED_LIGHT 8
#define YELLOW_LIGHT 10
#define GREEN_LIGHT 12

// ms delays 
#define THREE_SECONDS 3000 // arduino ide doesnt like 3_SECONDS!
#define TWO_SECONDS 2000
#define ONE_SECOND 1000

#define SECONDS 1000 //work around naming problem w/ ide eg.now 3*SECONDS


void all_lights_off(){
     // ALL off
   digitalWrite(RED_LIGHT,LOW);
   digitalWrite(YELLOW_LIGHT,LOW);
   digitalWrite(GREEN_LIGHT,LOW);
}

void blink_light(int light, int count){

  for (int i=0; i<=count; i++){
      digitalWrite(light,LOW);
      delay(250); // 
      digitalWrite(light,HIGH); 
      delay(250);
      }
   digitalWrite(light,LOW); //leave off
  }
  
void setup() {

  // config light ports for output
  pinMode(RED_LIGHT,OUTPUT);
  pinMode(YELLOW_LIGHT,OUTPUT);
  pinMode(GREEN_LIGHT,OUTPUT);

  //init all off
  all_lights_off();
  delay(1500);
}


void loop() {
 
 // lights sequence state transitions
 // RED -> RED & YELLOW -> GREEN -> BLINKING GREEN -> YELLOW -> RED
 
   // red
   digitalWrite(RED_LIGHT,HIGH);
   delay(3*SECONDS);
   
   // yellow
   digitalWrite(YELLOW_LIGHT,HIGH);
   delay(3*SECONDS);
   
   //both off
   digitalWrite(RED_LIGHT,LOW);
   digitalWrite(YELLOW_LIGHT,LOW);
   
   // green
   digitalWrite(GREEN_LIGHT,HIGH);
   delay(3*SECONDS);

   blink_light(GREEN_LIGHT,4);

   // yellow
   digitalWrite(YELLOW_LIGHT,HIGH);
   delay(3*SECONDS);
   
   // ALL off
   all_lights_off();

   //test
   delay(0.25*SECONDS);
} 
