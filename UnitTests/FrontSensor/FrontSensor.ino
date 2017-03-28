/*
 * 
 *  void CheckFrontSensor()
 *  
 *  
 * 
 */

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  
}




int irDetect(int irLedPin, int irReceiverPin, long frequency){
  
  tone(irLedPin, frequency, 8);              // IRLED 38 kHz for at least 1 ms
  delay(1);                                  // Wait 1 ms
  int ir = digitalRead(irReceiverPin);       // IR receiver -> ir variable
  delay(1);                                  // Down time before recheck
  return ir;                                 // Return 1 no detect, 0 detect
} 
