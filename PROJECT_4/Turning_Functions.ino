void NinetyDegreeTurn(){
   ServoLeft.writeMicroseconds(1450);
  delay (1780);
  ServoLeft.writeMicroseconds(1500);
  delay (1000);
}

//void WideTurn(){
  
//}

void NinteyDegreeTurnR(){
  ServoRight.writeMicroseconds(1550);
  delay (1050);
  ServoLeft.writeMicroseconds(1500);
  delay (1000);
}

void NinteyDegreeTurn2(){
  ServoLeft.writeMicroseconds(1550);
  delay (1000);
  ServoRight.writeMicroseconds(1500);
  delay (1000);
  ServoLeft.writeMicroseconds(1500);
  ServoRight.writeMicroseconds(1500);
}
