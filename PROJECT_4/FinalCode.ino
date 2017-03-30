#include <Servo.h>
#include "BoeBot.h"

Servo ServoRight, ServoLeft;
int LengthofBoardTime= 12500; 
int StartTime, ElaspedTime;

void setup() {
  pinMode(FRONT_IR_SENSOR, INPUT);  pinMode(FRONT_IR_LED, OUTPUT);   // IR LED & Receiver facing forwards
  pinMode(RIGHT_IR_SENSOR, INPUT);  pinMode(RIGHT_IR_LED, OUTPUT);     // IR LED & Reciever facing right
  pinMode(BUZZER, OUTPUT);          pinMode(LED, OUTPUT);            // Buzzer and LED initialization
  
  ServoLeft.attach(LEFT_SERVO);                      
  ServoRight.attach(RIGHT_SERVO); 

  //FindBoard
  StartDriving();
  CheckFrontSensor(30, 38000, 0);     //note: every sensor function has a stopping function called in it (0 for a slow stop, 1 for a fast stop)
  ReachBoardTurn();                 
  StartTime=millis();                 //time is recorded when the board is reached

  //FollowBoard
  StartDriving();
  FollowRightSensor(175, 38000, 0);
  ElaspedTime=millis()-StartTime;     //the time between reaching the board and getting to the end of the board is stored
  AroundBoardTurn();                  

  //SearchSideofBoard (FirstTime)
  StartDriving();
  CheckRightSensor(38000);            //find the beginning of the thin side of the board 

  //FollowSideofBoard
  FollowRightSensor(250, 38000, 1);     //drive till end of the thin side of the board 
  AroundBoardTurn();                   //turn around the board again to face the first cup

  //FindCup (First)
  StartDriving();
  CheckFrontSensor(150, 38000, 1);
  FaceBoardTurn();                     //turn in to face the board, reverse out of the cup region and then straighten to be parallel with the board again
  Reverse();
  TurnLeft();

  //NavigateCup (First)
  StartDriving();
  delay(1200);                         //drive past the cup slightly so the right sensor can sense the cup
  FollowRightSensor(825, 41000, 0);    //follow till the end of the cup
  AroundCupTurn(975);

  //FaceCup (Middle) (FirstTime)
  StartImmediate();
  CheckFrontSensor(50, 38000, 1);      //sense the board and stop
  ReverseFaceCup(1840);                //face the middle cup

  //FindMiddleCup
  StartImmediate();
  CheckFrontSensor(150, 38000, 1);
  MiddleCupAlert();
  FaceBoardTurn();
  Reverse();
  TurnLeft();

  //NavigateCup (Middle)
  StartImmediate();
  delay(1200);
  FollowRightSensor(1400, 41000, 0);
  AroundCupTurn(1100);

  //FaceCup (End) (SecondTime)
  StartImmediate();
  CheckFrontSensor(50, 38000, 1);
  ReverseFaceCup(1900);                  //face the end cup

  //FindCup (End)
  StartImmediate();
  CheckFrontSensor(180, 38000, 1);
  FaceBoardTurn();
  Reverse();
  TurnLeft();

  //NavigateCup (End)
  StartImmediate();
  delay(1200);
  FollowRightSensor(1715, 41000, 0);
  AroundCupTurn(1000);

  //FaceCup (AfterCups) (ThirdTime)
  StartImmediate();
  CheckFrontSensor(145, 38000, 1);
  ReverseFaceCup(1830);                   //face no cup, function just used to become parallel with the board

  //FollowBoardAfterCups
  FollowRightSensor(175, 38000, 0);
  AroundBoardTurn();

  //SearchSideofBoard (End) (SecondTime)
  CheckRightSensor(38000);                //sense the thin side of the board

  //AroundBoardtoStartZone
  FollowRightSensor(250, 38000, 1);       //follow till the end of the thin side of the board
  AroundBoardTurn();
  StartDriving();
  delay(LengthofBoardTime-ElaspedTime);            //delay the total time boebot takes to drive along the whole board and subtract it by the stored time
  StopImmediate();

  //ReturntoEndZone
  ReachBoardTurn();
  StartDriving();
  CheckFrontSensor(30, 38000, 0);         //stop at the start zone
}

void loop() {
}
