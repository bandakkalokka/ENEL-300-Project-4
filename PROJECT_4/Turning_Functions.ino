void ReachBoardTurn(){
   ServoLeft.writeMicroseconds(1450);   //left servo turning at 1450 speed
  delay (1780);                         //how long the turn lasts
  ServoLeft.writeMicroseconds(1500);    //stopping the turn
  delay (1000);                         //cushion delay to prevent tugging on carpet with an immediate task
}

void AroundBoardTurn(){
  ServoRight.writeMicroseconds(1550);
  delay (1115);
  ServoLeft.writeMicroseconds(1500);
  delay (1000);}

void AroundCupTurn(int pause){
  ServoRight.writeMicroseconds(1550);
  delay (pause);
  ServoLeft.writeMicroseconds(1500);
  delay (1000);}

void FaceBoardTurn(){
  ServoRight.writeMicroseconds(1550);
  delay (2150);
  ServoRight.writeMicroseconds(1500);
} 

void TurnLeft() {
  ServoLeft.writeMicroseconds(1500);
  ServoRight.writeMicroseconds(1300);
  delay(1250);
  ServoRight.writeMicroseconds(1500);
}

void ReverseFaceCup(int pause){
   ServoLeft.writeMicroseconds(1450);
  delay (pause);
  ServoLeft.writeMicroseconds(1500);
  delay (1000);
}


