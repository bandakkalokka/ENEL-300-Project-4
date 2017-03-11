int CheckFrontSensor()
{
  while (1){
  irFront=irDetect(2, 10, 38000);       
  Serial.println("Front:"); 
  Serial.println(irFront);                    
  
  if(irFront==0){  
    counter=0;                         
    for(timespan=0; timespan<150; timespan++){
      
      if (irDetect(2,10,38000)==0){
      counter++;}
    
      if(counter >= 150){ 
      StopDriving();
      return 0;}}
  }
    delay(100);}             
 }   

void FollowSideSensor()
{
while (1){
  irSide=irDetect(6, 4, 38000);
  Serial.println("Side:");
  Serial.println(irSide); 
  
  if(irSide==1){
    counter=0;                           
    for(timespan=0; timespan<20; timespan++){
    
      if (irDetect(6,4,38000)==1){
      counter++;}
    
      if(counter >= 10){ 
      delay(300);
      StopDriving();
      return;}}
  }
}
    delay(100);
}

int irDetect(int irLedPin, int irReceiverPin, long frequency)
{
  tone(irLedPin, frequency, 8);              // IRLED 38 kHz for at least 1 ms
  delay(1);                                  // Wait 1 ms
  int ir = digitalRead(irReceiverPin);       // IR receiver -> ir variable
  delay(1);                                  // Down time before recheck
  return ir;                                 // Return 1 no detect, 0 detect
  }  


