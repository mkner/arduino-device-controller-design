/*
  Print on Serial Port

  -Mike Knerr
  
  Test basic print capability on serial port
  by outputing program running time in milliseconds
  
*/

void setup() {
  //init port rate
  Serial.begin(9600);
  Serial.print("\n");
  Serial.println("Hello...");
  Serial.println("Running time in milliseconds:");
  Serial.println("\t");
  
}


void loop() {
  
  Serial.print("\t"); // 
  Serial.println(millis()); // running time of program (ms)
  delay(500);        
}
