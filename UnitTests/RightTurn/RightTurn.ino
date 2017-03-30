/*
 * 
 * void TurnRight()
 * 
 * The purpose of the TurnRight() function is to stop the BoeBot from moving
 * and turn the left wheel counter-clockwise to turn the BoeBot to the right by 90 degrees.
 * 
 * Note: The void TurnRight() function is very similar to void AroundBoardTUrn(), 
 * void AroundBoardTurn2(), void FaceBoardTurn(), void FaceBoardTurn2(). The
 * only differences are that the OPT_LEFT_TURN and TURN_DELAY values are 
 * tweaked due to the inconsistencies of the BoeBot. The specific inconsistencies
 * are discussed in the hardware section of the Detailed Design Resport.
 */


#include <Servo.h>

#define MIN_SPEED             1500              // Stop speed for the servos
#define RIGHT_SERVO           13                // Right Servo pin number
#define LEFT_SERVO            12                // Left Servo pin number
#define OPT_RIGHT_TURN        1650              // Right Turn Speed
#define TURN_DELAY            1100              // Turn for 1.1s


Servo ServoLeft;
Servo ServoRight;

void setup() {
  ServoLeft.attach(RIGHT_SERVO);
  ServoRight.attach(LEFT_SERVO);
  
  TurnRight();                                               // Call to turn Right function
}


void TurnRight() {
  StopImmediate();
  ServoLeft.writeMicroseconds(OPT_RIGHT_TURN);               // Pulse the Left Servo at 1650 for 1100ms
  delay(TURN_DELAY);
}


void StopImmediate(){
  ServoRight.writeMicroseconds(MIN_SPEED);                    // Pulse Right Servo at min speed
  ServoLeft.writeMicroseconds(MIN_SPEED);                     // Pulse Left Servo at min speeds
}


void loop() {}
