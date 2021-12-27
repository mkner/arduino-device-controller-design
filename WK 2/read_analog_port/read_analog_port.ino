/*
  Analog Read Serial Port

  -Mike Knerr
  
  Reads an analog input on pin 0 (A0) and
  prints the result to the Serial Monitor 
  or view in serial plotter
  
  Examples:

  Monitor the value of a photoresister or thermistor sensor
  
  Monitor the value of a potentiometer
  Attach the center pin of a potentiometer to board pin A0
  and the outside pins to the board Vcc +5V and GND (ground)

*/

void setup() {
  //init port rate
  Serial.begin(9600);
}


void loop() {
  
  int sensorValue = analogRead(A0); // read input on analog pin 0 (A0)
  Serial.println(sensorValue); // print out result to serial monitor
  //Serial.print(sensorValue); // print out result to serial monitor
  delay(1);        
}
