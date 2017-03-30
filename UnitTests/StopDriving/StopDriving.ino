/*
 * 
 *  void StopDriving()
 *  
 *  The purpose of the void StopDriving() function is to bring the 
 *  BoeBot to a standstill. Similar to the void StartDriving() function,
 *  a linear decelaration was implemented to provide a smooth stop. The
 *  measured values from the CSV file were used to determine optimal stopping
 *  pulse width and deceleration values.
 *  
 *  
 */

#include <Servo.h>

#define MAX_RIGHT_SPEED               1400                                        // Ideal Right Servo Max Speed to got straight
#define MAX_LEFT_SPEED                1638                                        // Ideal Left Servo Max Speed to got straight
#define MIN_SPEED                     1500                                        // Ideal Stop Servo Speed 
#define MAX_DELTA_SPEED               (MAX_LEFT_SPEED - MAX_RIGHT_SPEED) / 2
#define MIN_DELTA_SPEED               0
#define ACCELERATION                  1

Servo ServoLeft;
Servo ServoRight;
int ServoRightSpeed = MAX_RIGHT_SPEED;                                            // Set Servo's to full speed                                        
int ServoLeftSpeed = MAX_LEFT_SPEED;

void setup() {
    
  ServoLeft.attach(12);
  ServoRight.attach(13);

  ServoLeft.writeMicroseconds(ServoLeftSpeed);
  ServoRight.writeMicroseconds(ServoRightSpeed);
  delay(3000);                                                                    // Pulse Servo's at full speed for 3 seconds
  
  
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

void loop() {
}
