//Find Board, Turn, Follow Board, Stop

#include <Servo.h>

Servo servoRight, servoLeft;
int irFront, irSide;
int counter=0;
int timespan;

void setup()
{
  delay(1000);                               // Delay to finish tone

  pinMode(10, INPUT);  pinMode(2, OUTPUT);   // IR LED & Receiver facing forwards
  pinMode(4, INPUT); pinMode(6, OUTPUT);     // IR LED & Reciever facing right
  servoLeft.attach(13);                      
  servoRight.attach(12);
  Serial.begin(9600);  
 
  StartDriving();
  CheckFrontSensor();
  NinetyDegreeTurn();
  StartDriving();
  FollowSideSensor();
  
}

void loop()
{}
  

