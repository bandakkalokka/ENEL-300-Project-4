int irFront, irRight;
int ObstacleFound=0;
int ObstacleNotFound=0;
int TimeSpanForCheck;

int CheckFrontSensor(int TimeGiven, int frequency, int StopQuickly)
{
  while (1){
  irFront=irDetect(FRONT_IR_LED, FRONT_IR_SENSOR, frequency);                           
  
  if(irFront==0){                                                            //if the sensor sees something enter the timespan check 
    ObstacleFound=0;                         
    for(TimeSpanForCheck=0; TimeSpanForCheck<TimeGiven; TimeSpanForCheck++){  //TimeSpanforCheck loops to the value of TimeGiven (a sample of data)
      
      if (irDetect(FRONT_IR_LED,FRONT_IR_SENSOR, frequency)==0){
      ObstacleFound++;}
    
      if(ObstacleFound >= TimeGiven){                           //if the amount of times the sensor sees something equals the TimeGiven sample, Boebot can stop (prevent false zeros)
        
        if(StopQuickly == 0){                                   //StopQuickly tells the Boebot whether to stop immediately or slow down before stopping  
          StopDriving();}
          
        else if(StopQuickly == 1) {
          StopImmediate();}
         
         return 0;}
         }
  }
    delay(50);}             
 }   

void FollowRightSensor(int PauseBeforeStop, int frequency, int StopQuickly)
{
while (1){
  irRight=irDetect(RIGHT_IR_LED, RIGHT_IR_SENSOR, frequency);
  
  if(irRight==1){
    ObstacleNotFound=0;                           
    for(TimeSpanForCheck=0; TimeSpanForCheck<10; TimeSpanForCheck++){
    
      if (irDetect(RIGHT_IR_LED, RIGHT_IR_SENSOR,frequency)==1){          //modelled after the other sensor functions except reversed to work when the sensor DOES not see anything
      ObstacleNotFound++;}
    
      if(ObstacleNotFound >= 10){ 
      delay(PauseBeforeStop); 
      
      if(StopQuickly ==0){
        StopDriving();}
        
      else if(StopQuickly == 1){
        StopImmediate();}
      return;}}
  }
}
   delay(50);
}

int CheckRightSensor(int frequency)
{
  while (1){
  irRight=irDetect(RIGHT_IR_LED, RIGHT_IR_SENSOR, frequency); 
  if(irRight==0){  
    ObstacleFound=0;                         
    for(TimeSpanForCheck=0; TimeSpanForCheck<30; TimeSpanForCheck++){
      
      if (irDetect(RIGHT_IR_LED,RIGHT_IR_SENSOR,frequency)==0){       // if object detected, increase ObstacleFound
      ObstacleFound++;}
    
      if(ObstacleFound >= 30){ 
      StopImmediate();
      return 0;}}
  }
    delay(100);}             
 }   

void MiddleCupAlert() {
  
  for(int i = 0; i < 5; i++){
    tone(BUZZER, 1000, 500);       //play the buzzer tone 5 times with a delay of 1000 ms in between
    delay(1000);
  }
  digitalWrite(LED, HIGH);         //light up the LED
  delay(500);
  digitalWrite(LED,LOW);
  
}

int irDetect(int irLedPin, int irReceiverPin, long frequency)
{
  tone(irLedPin, frequency, 8);              // IRLED 38 kHz for at least 1 ms
  delay(1);                                  // Wait 1 ms
  int ir = digitalRead(irReceiverPin);       // IR receiver -> ir variable
  if (irLedPin==6){
    Serial.println(ir);
  }
  delay(1);                                  // Down time before recheck
  return ir;                                 // Return 1 no detect, 0 detect
  }  

