int irFront, irRight;
int counter=0;
int timespan;

int CheckFrontSensor(int distance, int stopper)
{
  while (1){
  irFront=irDetect(FRONT_IR_LED, FRONT_IR_SENSOR, 38000);                           
  
  if(irFront==0){  
    counter=0;                         
    for(timespan=0; timespan<distance; timespan++){
      
      if (irDetect(FRONT_IR_LED,FRONT_IR_SENSOR,38000)==0){
      counter++;}
    
      if(counter >= distance){
        if(stopper == 1)  
          StopDriving();
      else if(stopper == 2) {
          StopImmediate();
      }
      return 0;}}
  }
    delay(50);}             
 }   

void FollowRightSensor(int pause, int stopdriving)
{
while (1){
  irRight=irDetect(RIGHT_IR_LED, RIGHT_IR_SENSOR, 38000);
  
  if(irRight==1){
    counter=0;                           
    for(timespan=0; timespan<10; timespan++){
    
      if (irDetect(RIGHT_IR_LED, RIGHT_IR_SENSOR,38000)==1){
      counter++;}
    
      if(counter >= 10){ 
      delay(pause);
      if(stopdriving ==1)
        StopDriving();
      else if(stopdriving == 2)
        StopImmediate();
      return;}}
  }
}
    delay(100);
}

void Edge()
{
  
int count =0;
while(1)
{
  if (irDetect(6,4,38000) == 0)
      return; 
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

int CheckFrontCup()
{
  while (1){
  irFront=irDetect(FRONT_IR_LED, FRONT_IR_SENSOR, 38000);       
  Serial.println("Front:"); 
  Serial.println(irFront);                    
  
  if(irFront==0){  
    counter=0;                         
    for(timespan=0; timespan<50; timespan++){
      
      if (irDetect(2,5,38000)==0){
      counter++;}
    
      if(counter >= 50){ 
      StopImmediate();
      return 0;}}
  }
    delay(100);}             
 }


int CheckRightSensor()
{
  while (1){
  irRight=irDetect(RIGHT_IR_LED, RIGHT_IR_SENSOR, 38000);                          
  Serial.println(irFront);
  if(irRight==0){  
    counter=0;                         
    for(timespan=0; timespan<30; timespan++){
      
      if (irDetect(RIGHT_IR_LED,RIGHT_IR_SENSOR,38000)==0){       // if object detected, increase counter
      counter++;}
    
      if(counter >= 30){ 
      //StopImmediate();
      return 0;}}
  }
    delay(100);}             
 }   

void Beep() {
  for(int i = 0; i < 5; i++){
    tone(BUZZER, 1000, 500);
    delay(1000);
  }
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED,LOW);
  
}

