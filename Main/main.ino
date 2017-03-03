#include <Servo.h>

#define FIND_BOARD 0
#define FOLLOW_BOARD 1
#define FIND_BOULDER 2
#define NAVIGATE_BOULDER 3
#define FIND_BEACON 4

int state;
Servo servoRight, servoLeft;

void setup()
{
  tone(4, 3000, 1000);                       // Play tone for 1 second
  delay(1000);                               // Delay to finish tone

  pinMode(10, INPUT);  pinMode(2, OUTPUT);   // IR LED & Receiver facing forwards
  pinMode(4, INPUT); pinMode(6, OUTPUT);     // IR LED & Reciever facing right
  //Serial.begin(9600);  
  servoLeft.attach(13);                      
  servoRight.attach(12);
  //Serial.println(irFront + " " + irRight);
  
  state = FIND_BOARD;
  StartDriving();
}

void loop()
{
int FrontObstructionDetected, SideObstructionDetected;
  
  switch(state){
    case FIND_BOARD:  
    FrontObstructionDetected = CheckFrontSensor();
    break;
  }
  
  switch (state){
    case FIND_BOARD:
    if(FrontObstructionDetected)
      StopDriving();
    break;
  }
}
  
void StartDriving()
{
  servoRight.writeMicroseconds(1700);
  servoLeft.writeMicroseconds(1300);
}

int CheckFrontSensor()
{
int irFront;
  
  while (1){
irFront = irDetect(2, 10, 38000);       // Check for object infront
  
if(irFront == 0) { 
    int o = 0;                           // count zeros
  
    for(int i =0; i<20; i++)  {
      if (irDetect(2,10,38000)==0)
        o++; 
    
      if(o >= 19) {
        irFront = 1;
        return irFront;
      }  
    }  
  }  
  }
}

void StopDriving() {
  servoRight.writeMicroseconds(1500);
  servoLeft.writeMicroseconds(1500); 
}

int irDetect(int irLedPin, int irReceiverPin, long frequency)
{
  tone(irLedPin, frequency, 8);              // IRLED 38 kHz for at least 1 ms
  delay(1);                                  // Wait 1 ms
  int ir = digitalRead(irReceiverPin);       // IR receiver -> ir variable
  delay(1);                                  // Down time before recheck
  return ir;                                 // Return 1 no detect, 0 detect
}  


