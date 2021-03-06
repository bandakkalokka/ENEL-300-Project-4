/*
 * 
 * void StopImmediate()
 * 
 * The purpose of the StopImmediate() function is to stop the BoeBot from moving
 * as soon as the function is called.
 * 
 * 
 */

#include <Servo.h>

#define MIN_SPEED             1500              // Stop speed for the servos
#define RIGHT_SERVO           13                // Right Servo pin number
#define LEFT_SERVO            12                // Left Servo pin number

Servo ServoLeft;
Servo ServoRight;


void setup() {
  pinMode(RIGHT_SERVO, OUTPUT);  pinMode(LEFT_SERVO, OUTPUT);     // Assign pins for servos

  ServoLeft.attach(LEFT_SERVO);                                   // Attach the servos                    
  ServoRight.attach(RIGHT_SERVO);

  ServoRight.writeMicroseconds(MIN_SPEED);                    // Pulse Right Servo at min speed
  ServoLeft.writeMicroseconds(MIN_SPEED);                     // Pulse Left Servo at min speeds
}



void loop() {

}
