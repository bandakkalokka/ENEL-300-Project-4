#define MAX_RIGHT_SPEED             1400                                          // Ideal Right Servo Max Speed to got straight
#define MAX_LEFT_SPEED              1638                                          // Ideal Left Servo Max Speed to got straight
#define MIN_SPEED                   1500                                          // Ideal Stop Servo Speed 
#define MAX_DELTA_SPEED             (MAX_LEFT_SPEED - MAX_RIGHT_SPEED) / 2        // Approximate Max Speed
#define MIN_DELTA_SPEED               0
#define ACCELERATION                  1



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
