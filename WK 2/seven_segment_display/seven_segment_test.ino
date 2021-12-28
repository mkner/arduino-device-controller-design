/*
  7 segment display 

  -Mike Knerr
  
  runs a test on 7 segment digital display
  
  1) turn on each segment in display pin number sequence
  2) all on
  3) countdown 3,2,1,0
  4) run through segments sequentially & repeatedly
  
  note: pins set for common anode type
  
*/

#define LED_01 2
#define LED_07 8
#define LED_DP 5

#define LED_DELAY 500

//make it easier to resuse
//common analog
#define ON LOW
#define OFF HIGH

/*bool RUNNING_MODE = OFF;*/
bool TEST_MODE = OFF;

void setup() {
  
  //configure pins to LEDs
  for(int i=LED_01; i <= LED_07; i++)
    pinMode(i,OUTPUT);
    
  display_off(100);
  
  //shut off board light
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  
}

void display_off(int t){
  
  //turn off display
  for(int i=LED_01; i <= LED_07; i++)
     {
     digitalWrite(i,OFF);
     }
  delay(t);
}

void display_all_on(int t){
  
  //turn on all segments
  for(int i=LED_01; i <= LED_07; i++)
     {
     digitalWrite(i,ON);
     }
  delay(t);
}

void run_all_segments(int interval) {

for(int i=LED_01; i <= LED_07; i++)
          {
           digitalWrite(i,ON);
           delay(interval);
           digitalWrite(i,OFF);
          } 
}


void loop() {

        run_all_segments(500);

        delay(750);
        display_off(150);
        display_all_on(2000);
        display_off(750);

int one[]={4,5};          
int two[]={6,5,8,2,3};
int three[]={6,5,8,4,3};
int zero[]={2,3,4,5,6,9,7};
int array_size;

        //three
        array_size=(sizeof(three)/sizeof(three[0]));
        for (int i = 0; i < array_size; i++) {
          digitalWrite(three[i],ON);
        }
        delay(LED_DELAY);
        delay(LED_DELAY);
        
        for (int i = 0; i < sizeof(three)-1; i++) {
          digitalWrite(three[i],OFF);
        }
        delay(300);
        display_off(200);
        
        //two
        array_size=(sizeof(two)/sizeof(two[0]));
        for (int i = 0; i < array_size; i++) {
          digitalWrite(two[i],ON);
        }
        delay(1000);
        
        for (int i = 0; i < array_size; i++) {
          digitalWrite(two[i],OFF);
        }
        delay(300);
        display_off(200);
        
        //one
        array_size=(sizeof(one)/sizeof(one[0]));
        for (int i = 0; i < array_size; i++) {
          digitalWrite(one[i],ON);
        }
        delay(1000);
        
        for (int i = 0; i < array_size; i++) {
          digitalWrite(one[i],OFF);
        }
        delay(300);
        display_off(250);
        
        //zero
        array_size=(sizeof(zero)/sizeof(zero[0]));
        for (int i = 0; i < array_size; i++) {
          digitalWrite(zero[i],ON);
        }
   
        delay(1000);
        display_off(1000);
        
        /*
        for (int i = 0; i < array_size; i++) {
          digitalWrite(one[i],OFF);
        }
        delay(300);
        display_off(250);
        */
        
        for (int count=0; count<4; count++) {
          run_all_segments(100);
        }

        display_off(1500);
        
               
}// end loop
