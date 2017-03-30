/*
 * void StartDriving();
 * 
 * The StartDriving() function is utilized to move the BoeBot in the forward direction.
 * Initially maximum speeds of 1500us and 1300us (as mentioned in the Parallax Tutorials) 
 * were used. However, it soon became evident that the left servo was rotating slower 
 * than the right servo, and the sudden change in speed at the beginnning of the movement
 * caused the BoeBot to lose alignment. The solution to this problem was to re-calibrate 
 * the Servo's and add a linear acceleration at the beginning of the movement.
 * 
 *  
 * The Servo's were tested and calibrated according to Chapter 2 of the Parallax Module. 
 * CSV files were created to determine how the Rotational Velocity (RPM) changed with 
 * the Pulse Width (us). Based on this data maximum/minimum speeds and acceleration values 
 * were chosen for the Servo's
 */

#include <Servo.h>


#define MAX_RIGHT_SPEED               1400                                        // Ideal Right Servo Max Speed to got straight
#define MAX_LEFT_SPEED                1638                                        // Ideal Left Servo Max Speed to got straight
#define MIN_SPEED                     1500                                        // Ideal Stop Servo Speed 
#define MAX_DELTA_SPEED               (MAX_LEFT_SPEED - MAX_RIGHT_SPEED) / 2
#define ACCELERATION                  1


Servo ServoLeft;
Servo ServoRight;
int ServoRightSpeed = MIN_SPEED;                                        
int ServoLeftSpeed = MIN_SPEED;

void setup() {
    
  ServoLeft.attach(12);
  ServoRight.attach(13);
  StartDriving();                                 // Call StartDriving Function
}


void StartDriving() {
  for(int deltaSpeed = 0; deltaSpeed < MAX_DELTA_SPEED; deltaSpeed += ACCELERATION) {
    ServoLeftSpeed = MIN_SPEED + deltaSpeed;
    ServoRightSpeed = MIN_SPEED - deltaSpeed;
    
    ServoLeft.writeMicroseconds(ServoLeftSpeed);
    ServoRight.writeMicroseconds(ServoRightSpeed);
    delay(10);                                                                  // Apply the deltaSpeed for 10ms
  }
  
  ServoLeft.writeMicroseconds(MAX_LEFT_SPEED);                                  // Set Servo's to maximum speed   
  ServoRight.writeMicroseconds(MAX_RIGHT_SPEED);                                // after acceleration is completed
}

void loop() {
}
