//MAR 22 2:32

#include <Servo.h>
#include "BoeBot.h"

Servo ServoRight, ServoLeft;
int pacetime= 12500;
int starttime, elaspedtime;

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
  CheckFrontSensor(30, 1, 38000);
  ReachBoardTurn(); //first turn at board
  starttime=millis();

  //FollowBoard
  StartDriving();
  FollowRightSensor(175, 1, 38000);
  elaspedtime=millis()-starttime;
  AroundBoardTurn(); //second turn at the end of board

  //AcrossSideBoard
  StartDriving();
  CheckRightSensor(38000); //find the beginning board 
  FollowRightSensor(0, 2, 38000); //drive till end of board (FollowSideSensor calls StopDriving)
  StartDriving();
  StopImmediate();      //bridge the gap (hard coded)

  //FindBoulder1
  AroundBoardTurn(); //turn to face the boulder 
  if (irDetect(FRONT_IR_LED, FRONT_IR_SENSOR, 38000)==1){
  StartDriving();
  CheckFrontCup();}

  //NavigateBoulder1
  FaceBoardTurn();
  delay(100);
  Reverse();
  TurnLeft();
  StartDriving();
  //CheckRightSensor(41000);
  //FollowRightSensor(825, 1, 41000);
  delay(1995);
  StopImmediate();
  AroundBoardTurn();
  StartImmediate();
  CheckFrontSensor(50, 3, 38000);
  //delay(1585);
  StopImmediate();
  ReverseFaceCup(); //face the middle cup

  //FindMiddleCup
  StartImmediate();
  CheckFrontCup();
  Beep();

  //NavigateMiddleCup
  FaceBoardTurn2();
  delay(100);
  Reverse();
  TurnLeft();
  StartImmediate();
  //CheckRightSensor(41000);
  //FollowRightSensor(1400, 1, 41000);
  delay(2750);
  StopImmediate();
  AroundBoardTurn();
  StartImmediate();
  CheckFrontSensor(50, 3, 38000);
  //delay(1550);
  StopImmediate();
  ReverseFaceCupTwo(); //face the end cup

  //FindBoulder2
  StartImmediate();
  CheckFrontCup();

  //NavigateBoulder2
  FaceBoardTurn();
  delay(100);
  Reverse();
  TurnLeft();
  StartDriving();
  delay(1975);
  StopImmediate();
  //FollowRightSensor(200, 1, 41000);

  //NavigateEndofBoard
  AroundBoardTurn();
  StopImmediate();
  StartImmediate();
  //for (int i=0; i<10; i++) {
  //if(irDetect(FRONT_IR_LED, FRONT_IR_SENSOR, 38000)==0){
  delay (1500);
  StopImmediate();
  ReverseFaceCup(); //face the end cup
  StopImmediate();
  StartImmediate();
  FollowRightSensor(5, 1, 38000);
  AroundBoardTurn();
  StopImmediate();
  StartDriving();
  //break;
  //}
  //}

  delay(2750);
  //CheckRightSensor(38000); //find the beginning board 
  //FollowRightSensor(2200, 2, 38000); //drive till end of board (FollowSideSensor calls StopDriving)
  StopImmediate();
  AroundBoardTurn2();
  StopImmediate();
  StartImmediate();
  //CheckFrontSensor(180, 2, 40000);

  //BacktoOriginal
  delay(pacetime-elaspedtime);
  StopImmediate();
  ReachBoardTurn();
  StartDriving();
  delay(2450);
  StopImmediate();
  
}


void loop(){}
  

