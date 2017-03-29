/*
 * 
 * void StartImmediate()
 * 
 * The purpose of the StartImmediate() function is to move the BoeBot forwards at max speed
 * as soon as the function is called.
 * 
 * 
 */

#define MAX_RIGHT_SPEED       1400 
#define MAX_LEFT_SPEED        1638
#define RIGHT_SERVO           13
#define LEFT_SERVO            12



void setup() {
  pinMode(RIGHT_SERVO, OUTPUT);  pinMode(LEFT_SERVO, OUTPUT);     // Assign pins for servos

  ServoLeft.attach(LEFT_SERVO);                                   // Attach the servos                    
  ServoRight.attach(RIGHT_SERVO);

  ServoRight.writeMicroseconds(MAX_RIGHT_SPEED);                  // Pulse Right Servo at max speed
  ServoLeft.writeMicroseconds(MAX_LEFT_SPEED);                    // Pulse Left Servo at max speed
}



void loop() {

}
