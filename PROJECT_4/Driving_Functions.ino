int ServoRightSpeed = MIN_SPEED;
int ServoLeftSpeed = MIN_SPEED;


void StartDriving()
{  
  for(int deltaSpeed = 0; deltaSpeed < MAX_DELTA_SPEED; deltaSpeed += ACCELERATION) {
    ServoLeftSpeed = MIN_SPEED + deltaSpeed;
    ServoRightSpeed = MIN_SPEED - deltaSpeed;
    
    ServoLeft.writeMicroseconds(ServoLeftSpeed);
    ServoRight.writeMicroseconds(ServoRightSpeed);
    delay(10);                                                                    // Apply the deltaSpeed for 10ms
  }
  
  ServoLeft.writeMicroseconds(MAX_LEFT_SPEED);                                    // Set Servo's to maximum speed 
  ServoRight.writeMicroseconds(MAX_RIGHT_SPEED);                                  // after acceleration is completed
}



void StopDriving()
{
  for(int deltaSpeed = MAX_DELTA_SPEED; deltaSpeed >= MIN_DELTA_SPEED; deltaSpeed -= ACCELERATION) {
    ServoLeftSpeed = MIN_SPEED + deltaSpeed;
    ServoRightSpeed = MIN_SPEED - deltaSpeed;
    
    ServoLeft.writeMicroseconds(ServoLeftSpeed);
    ServoRight.writeMicroseconds(ServoRightSpeed);
    delay(10);                                                                    // Apply the deltaSpeed for 10ms
  }

  ServoLeft.writeMicroseconds(MIN_SPEED);                                         // Set Servo's to stop after
  ServoRight.writeMicroseconds(MIN_SPEED);                                        // deceleration is complete
}
  

void Reverse() {
  ServoLeft.writeMicroseconds(1400);
  ServoRight.writeMicroseconds(1639);
  delay(1500);
}

void StopImmediate() {
  ServoLeft.writeMicroseconds(1500);
  ServoRight.writeMicroseconds(1500);
}

