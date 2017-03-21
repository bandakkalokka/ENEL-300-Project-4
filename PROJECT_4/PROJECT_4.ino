//Find Board, Turn, Follow Board, Stop

#include <Servo.h>
#include "BoeBot.h"

Servo ServoRight, ServoLeft;
int pacetime= 10000;
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
  FollowRightSensor(300, 1, 38000);
  elaspedtime=millis()-starttime;
  AroundBoardTurn(); //second turn at the end of board

  //AcrossSideBoard
  StartDriving();
  CheckRightSensor(); //find the beginning board 
  FollowRightSensor(0, 2, 38000); //drive till end of board (FollowSideSensor calls StopDriving)
  StartDriving();
  StopImmediate();      //bridge the gap (hard coded)

  //FindBoulder
  AroundBoardTurn(); //turn to face the boulder 
  if (irDetect(FRONT_IR_LED, FRONT_IR_SENSOR, 38000)==1){
  StartDriving();
  CheckFrontCup();}

  //NavigateBoulder
  FaceBoardTurn();
  delay(100);
  //StartImmediate();
  //CheckFrontCup();
  //AroundBoardTurn();
  Reverse();
  delay(25);
  TurnLeft();
  StartDriving();
  CheckRightSensor();
  FollowRightSensor(700, 1, 42000);
  AroundBoardTurn();
  StartImmediate();
  //delay(90);
  CheckFrontSensor(180, 2, 40000);
  ReverseFaceCup(); //face the middle cup

  //FindMiddleCup
  StartImmediate();
  CheckFrontCup();
  Beep();

  //NavigateBoulder
  FaceBoardTurn();
  delay(100);
  //StartImmediate();
  //CheckFrontCup();
  //AroundBoardTurn();
  Reverse();
  TurnLeft();
  StartImmediate();
  CheckRightSensor();
  FollowRightSensor(700, 1, 42000);
  AroundBoardTurn();
  StartImmediate();
  //delay(90);
  CheckFrontSensor(180, 2, 40000);
  ReverseFaceCup(); //face the end cup

  //FindBoulder
  StartImmediate();
  CheckFrontCup();

  //NavigateBoulder
  FaceBoardTurn();
  delay(100);
  //StartImmediate();
  //CheckFrontCup();
  //AroundBoardTurn();
  Reverse();
  TurnLeft();
  StartDriving();
  FollowRightSensor(650, 1, 40000);

  //NavigateEndofBoard
  AroundBoardTurn();
  StartDriving();
  CheckRightSensor(); //find the beginning board 
  FollowRightSensor(850, 2, 38000); //drive till end of board (FollowSideSensor calls StopDriving)
  AroundBoardTurn();

  //BacktoOriginal
  StartDriving();
  delay(pacetime-elaspedtime);
  ReachBoardTurn();
  StartDriving();
  delay(100);
  StopImmediate();
  

  

  
  
 // else 
//  {                                                  //cup close
//    FollowSideSensor(60, 2);
//    NinteyDegreeTurn2();
//    StartDriving();
//  }

  //StartDriving();
  //while(1) {
//    digitalWrite(LED, HIGH);
//    delay(200);
//    digitalWrite(LED,LOW);
//    Serial.println(CheckRightSensor());
//    if(!CheckRightSensor()) {
//      FollowRightSensor(500, 1);
//      break;
//    }
//  }

  
//  AroundBoardTurn();
//  StartDriving();
//  //delay(90);
//  CheckFrontSensor();
//  ReverseFaceCup();
//  StartImmediate();
//  CheckFrontCup();
//  Beep();

  
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

  /*
   * 
   *  FIND_BOARD   0
   *  FOLLOW_BOARD 1
   *  
   * 
   *  int irfront = check front
   *  int irRight = check right
   *  
   *  switch(state):
   *  
   *  case FIND_BOARD:
   *    if(!irfront)
   *      turn left
   *      state = FOLLOW_BOARD
   *    break;
   *    
   * case FOLLOWW_BOARD:
   *    if(irRight)
   *      turn right
   *    break;
   * 
   * case PASS_BOARD_WIDTH:
   *    if(!irRight)
   *      
   */
  
  }
  

