/*
 * 
 *  void FollowRightSensor()
 *  
 *  The purpose of the FollowRightSensor() function is to be informed when as obstacle is out of sight.
 *  The helper function irDetect(LED, Sensor, Frequency) is used to parse the input from the sensor.
 *  The sensor is listening at a frequency of 38000Hz (infared), and the digitalRead function is called
 *  every 2 ms. The counter variable is used to count the number of 1's after obstacle has disappeared.
 *  The code below is implemented to stop the BoeBot from moving if an object is not detected on the right-side
 *  for a given distance.
 *  
 */

#include <Servo.h>

#define RIGHT_IR_SENSOR              4
#define RIGHT_IR_LED                 6
#define LEFT_SERVO                   12
#define RIGHT_SERVO                  13
#define MAX_RIGHT_SPEED             1400                                          // Ideal Right Servo Max Speed to got straight
#define MAX_LEFT_SPEED              1638                                          // Ideal Left Servo Max Speed to got straight
#define MIN_SPEED                   1500                                          // Ideal Stop Servo Speed
#define MAX_DELTA_SPEED             (MAX_LEFT_SPEED - MAX_RIGHT_SPEED) / 2        // Approximate Max Speed
#define MIN_DELTA_SPEED               0
#define ACCELERATION                  1


int irRight;
int counter=0;
int timespan;
int ServoRightSpeed = MIN_SPEED;
int ServoLeftSpeed = MIN_SPEED;
Servo ServoRight;
Servo ServoLeft;

void setup() {
  pinMode(RIGHT_IR_LED, OUTPUT);    pinMode(RIGHT_IR_SENSOR, INPUT);      // Assign pins
  ServoRight.attach(LEFT_SERVO);
  ServoLeft.attach(RIGHT_SERVO);
  
  StartDriving();                                                         // Move BoeBot forwards
  FollowRightSensor(200, 2, 38000);                                       // FollowRightSensor called with a stop distance of 200, StopImmediate,
}                                                                         // and a frequency of 38000Hz


void FollowRightSensor(int pause, int stopdriving, int frequency)
{
while (1){
  irRight=irDetect(RIGHT_IR_LED, RIGHT_IR_SENSOR, frequency);
  
  if(irRight==1){
    counter=0;                           
    for(timespan=0; timespan<10; timespan++){
    
      if (irDetect(RIGHT_IR_LED, RIGHT_IR_SENSOR,frequency)==1){
      counter++;}
    
      if(counter >= 10){ 
      delay(pause);
      if(stopdriving ==1)
        StopDriving();
      else if(stopdriving == 2)
        StopImmediate();
      return;}}
  }
}
    delay(50);
}

int irDetect(int irLedPin, int irReceiverPin, long frequency){
  tone(irLedPin, frequency, 8);              // IRLED 38 kHz for at least 1 ms
  delay(1);                                  // Wait 1 ms
  int ir = digitalRead(irReceiverPin);       // IR receiver -> ir variable
  delay(1);                                  // Down time before recheck
  return ir;                                 // Return 1 no detect, 0 detect
} 


/* Code for voidStartDriving() implemented in DriveForwards UnitTest */
void StartDriving(){
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



/* Code for void StopDriving() implemented in StopDriving UnitTest */
void StopDriving(){
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



/* Code for void StopImmedrate() implemented in StopImmediate UnitTest */
void StopImmediate(){
  ServoRight.writeMicroseconds(MIN_SPEED);                    // Pulse Right Servo at min speed
  ServoLeft.writeMicroseconds(MIN_SPEED);                     // Pulse Left Servo at min speeds
}


void loop() {}
