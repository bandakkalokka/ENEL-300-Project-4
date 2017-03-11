/*
 * void StartDriving();
 * 
 * The StartDriving() function is utilized to move the BoeBot in the forward direction.
 * Initially maximum speeds of 1500us and 1300us (as mentioned in the Parallax Tutorials) 
 * were used. However, it soon became evident that the left servo was rotating slower 
 * than the right servo, and the sudden change in speed at the beginnning of the movement
 * caused the BoeBot to lose alignment.
 * 
 *  
 * 
 */

#include <Servo.h>


Servo servoLeft;
Servo servoRight;
int ServoRightSpeed = 1375;
int ServoLeftSpeed = 1700;

void setup() {
  servoLeft.attach(12);
  servoRight.attach(13);

  servoLeft.writeMicroseconds(ServoLeftSpeed);
  servoRight.writeMicroseconds(ServoRightSpeed);

}

void loop() {
  // put your main code here, to run repeatedly:

}
