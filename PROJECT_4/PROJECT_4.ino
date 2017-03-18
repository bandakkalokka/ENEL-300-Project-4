//Find Board, Turn, Follow Board, Stop

#include <Servo.h>
#include "BoeBot.h"

Servo ServoRight, ServoLeft;
int irFront, irSide;
int counter=0;
int timespan;

void setup()
{

  pinMode(FRONT_IR_SENSOR, INPUT);  pinMode(FRONT_IR_LED, OUTPUT);   // IR LED & Receiver facing forwards
  pinMode(RIGHT_IR_SENSOR, INPUT);  pinMode(RIGHT_IR_LED, OUTPUT);     // IR LED & Reciever facing right
  
  ServoLeft.attach(LEFT_SERVO);                      
  ServoRight.attach(RIGHT_SERVO);
  Serial.begin(9600);  
 
  StartDriving();
  CheckFrontSensor();
  NinetyDegreeTurn();
  StartDriving();
  FollowSideSensor(300);
  NinteyDegreeTurnR();
  
  StartDriving();
  //exit(1);
  //Edge();
  //delay(650);
  FollowSideSensor(100);
  //StopDriving();
  
  if(irDetect(RIGHT_IR_LED, RIGHT_IR_SENSOR, 38000)) {    //cup far
     NinteyDegreeTurn2();
     //StartDriving();      Takes too long
     ServoLeft.writeMicroseconds(1700);
     ServoRight.writeMicroseconds(1300);
     CheckFrontCup();
     NinteyDegreeTurnR();
     Reverse();
     NinetyDegreeTurnL();
  }
  else {                                                  //cup close
    FollowSideSensor(60);
    NinteyDegreeTurn2();
    StartDriving();
  }
  //NinteyDegreeTurn2();
  //StopDriving();
  
  
  
  
}

void loop()
{ /*
  Serial.print (irDetect(6, 4, 38000));
  if (irDetect(6, 4, 38000)==0){
    FollowSideSensor();
    exit(1);
  }
  */
  }
  

