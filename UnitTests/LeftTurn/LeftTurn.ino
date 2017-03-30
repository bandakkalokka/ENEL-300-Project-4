/*
 * 
 * void TurnLeft()
 * 
 * The purpose of the TurnLeft() function is to stop the BoeBot from moving
 * and turn the right wheel clockwise to turn the BoeBot left by 90 degrees.
 * 
 * Note: The void TurnLeft() function is very similar to void ReachBoardTUrn(), 
 * void ReverseFaceCup(), void ReverseFaceCupTwo(), void ReverseFaceCupThree(). The
 * only differences are that the OPT_LEFT_TURN and TURN_DELAY values are 
 * tweaked due to the inconsistencies of the BoeBot. The specific inconsistencies
 * are discussed in the hardware section of the Detailed Design Resport.
 */


#include <Servo.h>

#define MIN_SPEED             1500              // Stop speed for the servos
#define RIGHT_SERVO           13                // Right Servo pin number
#define LEFT_SERVO            12                // Left Servo pin number
#define OPT_LEFT_TURN         1350              // Left Turn Speed
#define TURN_DELAY            1100              // Turn for 1.1s


Servo ServoLeft;
Servo ServoRight;

void setup() {
  ServoLeft.attach(RIGHT_SERVO);
  ServoRight.attach(LEFT_SERVO);
  
  TurnLeft();                                       // Call to TurnLeft() function
}


void TurnLeft() {
  StopImmediate();
  ServoRight.writeMicroseconds(OPT_LEFT_TURN);                // Pulse Right Servo at 1350 for 1100ms
  delay(TURN_DELAY);
}


void StopImmediate(){
  ServoRight.writeMicroseconds(MIN_SPEED);                    // Pulse Right Servo at min speed
  ServoLeft.writeMicroseconds(MIN_SPEED);                     // Pulse Left Servo at min speeds
}


void loop() {}
