/*
  7 segment display with shift register
  v0.06
  
  -Mike Knerr
  
  using TI 74HC595 shift register 
  7 segment display (common anode)
  bit patterns are defined for common cathode
  then mapped for common anode display
  input from serial monitor one character at a time
  displays hex 0-F, t is test, ? is help, and other fun stuff!
  lots of predefined functions for easy coding
  decimal point is on 74hc pin Q0

*/

#define DATA_PIN 8
#define LATCH_PIN 9
#define CLOCK_PIN 10

// common cathode
// segment pattern <dp>abcdefg
// first bit (LSB) is dp (decimal point) 
// is signal on Q0 of 74hc595 

// hex: 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F 

byte d0 = 0b01111110;
byte d1 = 0b00110000;
byte d2 = 0b01101101;
byte d3 = 0b01111001;
byte d4 = 0b00110011;
byte d5 = 0b01011011;
byte d6 = 0b00011111;
byte d7 = 0b01110000;
byte d8 = 0b01111111;
byte d9 = 0b01110011;
byte da = 0b01110111;
byte db = 0b00011111;
byte dc = 0b01001110;
byte dd = 0b00111101;
byte de = 0b01001111;
byte df = 0b01000111;

byte dh = 0b00110111;
byte dl = 0b00001110;
byte dp = 0b10000000;

byte off = 0b00000000;

byte xormask = 0b11111111;

//map hex to 7 segment bit patterns
byte bitmap[] = {d0,d1,d2,d3,d4,d5,d6,d7,d8,d9, \
                 da,db,dc,dd,de,df};

void setup() {
  
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);

  Serial.begin(9600); 

  Serial.println("\n");
  Serial.println("Hello!\n");
  Serial.println("Input number (hex) to display, or...");

  //output(toAnode(d2));
  //wait(10);
}

byte toAnode(byte b) {
//convert cathode to anode pattern
   return (b ^ 0b11111111);
}


void turnoff( float s) {
// turn off display s seconds
// non-integer ok eg. 0.5, 1.5 seconds

  s = abs(s); // got it
  output(toAnode(0));
  delay(int(s*1000));
}

void wait(float s) {
 // delay s seconds
  s = abs(s); 
  delay(int(s*1000));
}

byte addDP(byte d) {
  // put in decimal point
  return(d | dp);
}

void output(byte p) {

    digitalWrite(LATCH_PIN, LOW);
    shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST,p);
    digitalWrite(LATCH_PIN, HIGH);
}


void countUp(int j, int k, float t) {
  if (k < j || j < 0 ) { return; }
  
  Serial.print("i=");
  
  for (int i = j; i<=k; i++)
  {
   output(toAnode(bitmap[i]));
   Serial.print(i); 
   if (i < k) {Serial.print(",");}
   wait(t);
   turnoff(0.25);
  }
  Serial.print("\b" "\n");
}


void countDown(int k, int j, float t) {
  if (j > k || j < 0) { return; }

   Serial.print("i=");
   
   for (int i = k; i>=j; i--)
   {
   output(toAnode(bitmap[i]));
   Serial.print(i); 
   if (i > j) {Serial.print(",");}
   wait(t);
   turnoff(0.25);
   }
  Serial.print("\b" "\n");
}

void loop() {
 
      output(toAnode(0)); //display off
      delay(1000);

    if (Serial.available() >0)
       {
        
        char c = Serial.read();

        // display hex code from serial input

        
        char hexchars[]={'0','1','2','3','4','5','6','7','8','9',\
                         'a','b','c','d','e','f'};
       
         for (int i=0; i<=15; i++) {   
              if (c == hexchars[i]) { // check if hex
                output(toAnode(bitmap[i])); //send serial bits to 74hc595
                wait(0.70);
              }
             }

         if (c == 't')  { //enter test mode 
              Serial.println("\nEntering test mode...");
              Serial.println("Running display test...\n");

              // count up & down hex
              countUp(0,15,0.70);
              turnoff(1);
              
              countDown(15,0,0.70);
              turnoff(0.75);
              Serial.println();

              // flash decimal point (on pin Q0)
              for (int i=1; i<=3; i++) {
              // decimal point
              output(toAnode(dp));
              wait(0.5);
              turnoff(0.5);
              }
              
              //eight period
              output(toAnode(addDP(d8)));
              wait(1);
              turnoff(0.75);
              
            }
           
         if (c == 'u') { //eulers
            
             int e[]={2,7,1,8,2,8,1,8,2,8,4};
             
                    Serial.println("e is...\n");
                    for (int d=1; d<=10; d++) {
                         output(toAnode(bitmap[e[d-1]]));
                         wait(0.5);
                        }
           }
           
        if (c == 'p') { //pi
            
             int pi[]={3,1,4,1,5,9,2,6,5,3,5};
             
                    Serial.println("pi is...");
                    for (int d=1; d<=11; d++) {
                         output(toAnode(bitmap[pi[d-1]]));
                         wait(0.5);
                        }
           }

       if (c == 'h') { //hello
 
           Serial.println("Hello!\n");
           
           output(toAnode(dh)); wait(0.5); 
           output(toAnode(de)); wait(0.5);
           output(toAnode(dl)); wait(0.5);
           output(toAnode(0)); wait(0.1);
           output(toAnode(dl)); wait(0.5);
           output(toAnode(d0)); wait(0.5);    
           }

      if (c == '?') { //help 
 
           Serial.println("\nHelp?");
           Serial.println("t - test, 0-f - display hex, h - hello, p - pi, u - euler, ? - help?");
           
           }
       
       } //end while getchar
          
}// end loop
