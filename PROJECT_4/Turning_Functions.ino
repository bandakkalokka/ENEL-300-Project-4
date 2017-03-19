void ReachBoardTurn(){
   ServoLeft.writeMicroseconds(1450);
  delay (1790);
  ServoLeft.writeMicroseconds(1500);
  delay (1000);
}

void AroundBoardTurn(){
  ServoRight.writeMicroseconds(1550);
  delay (1100);
  ServoLeft.writeMicroseconds(1500);
  delay (1000);
}

void FaceBoardTurn(){
  ServoRight.writeMicroseconds(1550);
  delay (2000);
  //ServoRight.writeMicroseconds(1500);
  //delay (1000);
  ServoLeft.writeMicroseconds(1500);
  //ServoRight.writeMicroseconds(1500);
}

void TurnLeft() {
  ServoLeft.writeMicroseconds(1500);
  ServoRight.writeMicroseconds(1300);
  delay(1270);
}

void ReverseFaceCup(){
   ServoLeft.writeMicroseconds(1450);
  delay (1850);
  ServoLeft.writeMicroseconds(1500);
  delay (1000);
}


