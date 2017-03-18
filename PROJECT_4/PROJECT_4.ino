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
  pinMode(BUZZER, OUTPUT);          pinMode(LED, OUTPUT);            // Buzzer and LED initialization
  
  ServoLeft.attach(LEFT_SERVO);                      
  ServoRight.attach(RIGHT_SERVO);
  Serial.begin(9600);  

  //FindBoard
  StartDriving();
  CheckFrontSensor();
  NinetyDegreeTurn();

  //FollowBoard
  StartDriving();
  FollowSideSensor(300, 1);
  NinteyDegreeTurnR();

  //AcrossSideBoard
  StartDriving();
  CheckRightSensor();
  FollowSideSensor(0, 2); 

  //FindBoulder
  StartDriving();
  CheckRightSensor(); //bridgethegap
  StopImmediate();
  NinteyDegreeTurn2();
  StartImmediate();
  CheckFrontCup();
  NinteyDegreeTurnR();
  Reverse();
  NinetyDegreeTurnL();
  

  //if(irDetect(RIGHT_IR_LED, RIGHT_IR_SENSOR, 38000)) {    //cup far
     
     
   
    
  //}
  
 // else 
//  {                                                  //cup close
//    FollowSideSensor(60, 2);
//    NinteyDegreeTurn2();
//    StartDriving();
//  }

  StartDriving();
  while(1) {
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED,LOW);
    Serial.println(CheckRightSensor());
    if(!CheckRightSensor()) {
      FollowSideSensor(500, 1);
      break;
    }
  }
  
  NinteyDegreeTurnR();
  StartDriving();
  //delay(90);
  CheckFrontSensor();
  NinetyDegreeTurn3();
  StartDriving();
  CheckFrontCup();
  Beep();
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
  

