//Find Board, Turn, Follow Board, Stop

#include <Servo.h>

Servo ServoRight, ServoLeft;
int irFront, irSide;
int counter=0;
int timespan;

void setup()
{
  delay(1000);                               // Delay to finish tone

  pinMode(10, INPUT);  pinMode(2, OUTPUT);   // IR LED & Receiver facing forwards
  pinMode(4, INPUT); pinMode(6, OUTPUT);     // IR LED & Reciever facing right
  ServoLeft.attach(12);                      
  ServoRight.attach(13);
  Serial.begin(9600);  
 
  StartDriving();
  CheckFrontSensor();
  NinetyDegreeTurn();
  StartDriving();
  FollowSideSensor();
  NinteyDegreeTurnR();
  
  StartDriving();
  
}

void loop()
{
  Serial.print (irDetect(6, 4, 38000));
  if (irDetect(6, 4, 38000)==0){
    FollowSideSensor();
    exit(1);
  }}
  

