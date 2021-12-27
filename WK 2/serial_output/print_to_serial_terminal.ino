
/*
 * mike knerr
 * simple code to test serial monitor
 */
 
 int counter = 0; 

 void setup() {
  
 Serial.begin(9600);
 Serial.println();
 }

void loop() {

 Serial.print("Counter: ");
 Serial.println(counter);
 delay(500);
 counter++;
}
