void ReachBoardTurn(){
   ServoLeft.writeMicroseconds(1450);
  delay (1780);
  ServoLeft.writeMicroseconds(1500);
  delay (1000);
}

void AroundBoardTurn(){
  ServoRight.writeMicroseconds(1550);
  delay (1115);
  ServoLeft.writeMicroseconds(1500);
  delay (1000);}

void AroundBoardTurn2(){
  ServoRight.writeMicroseconds(1550);
  delay (1100);
  ServoLeft.writeMicroseconds(1500);
  delay (1000);}

void FaceBoardTurn(){
  ServoRight.writeMicroseconds(1550);
  delay (2150);
  ServoLeft.writeMicroseconds(1500);
  ServoRight.writeMicroseconds(1500);
} 

void FaceBoardTurn2(){
  ServoRight.writeMicroseconds(1550);
  delay (1850);
  ServoLeft.writeMicroseconds(1500);
  ServoRight.writeMicroseconds(1500);
} 

void TurnLeft() {
  ServoLeft.writeMicroseconds(1500);
  ServoRight.writeMicroseconds(1300);
  delay(1250);
  ServoRight.writeMicroseconds(1500);
}

void ReverseFaceCup(){
   ServoLeft.writeMicroseconds(1450);
  delay (1840);
  ServoLeft.writeMicroseconds(1500);
  delay (1000);
}

void ReverseFaceCupTwo(){
  ServoLeft.writeMicroseconds(1450);
  delay (1725);
  ServoLeft.writeMicroseconds(1500);
  delay (1000);
}

void ReverseFaceCupThree(){
  ServoLeft.writeMicroseconds(1450);
  delay (980);
  ServoLeft.writeMicroseconds(1500);
  delay (1000);
}

