//Find Board, Turn, Follow Board, Stop

#include <Servo.h>

#define FRONT_IR_LED              2                   // Digital I/O pin for front led
#define RIGHT_IR_LED              6                   // Digital I/O pin for right-side led
#define FRONT_IR_SENSOR           10                  // Digital I/O pin for front sensor
#define RIGHT_IR_SENSOR           4                   // Digital I/O pin for right sensor
#define RIGHT_SERVO               13                  // Digital I/O pin for right servo
#define LEFT_SERVO                12                  // Digital I/O pin for left servo

Servo ServoRight, ServoLeft;
int irFront, irSide;
int counter=0;
int timespan;

void setup()
{

  pinMode(FRONT_IR_SENSOR, INPUT);  pinMode(FRONT_IR_LED, OUTPUT);   // IR LED & Receiver facing forwards
  pinMode(RIGHT_IR_SENSOR, INPUT);  pinMode(RIGHT_IR_LED, OUTPUT);     // IR LED & Reciever facing right
  
  ServoLeft.attach(LEFT_SERVO);                      
  ServoRight.attach(RIGHT_SERVO);
  Serial.begin(9600);  
 
  StartDriving();
  CheckFrontSensor();
  NinetyDegreeTurn();
  StartDriving();
  FollowSideSensor();
  NinteyDegreeTurnR();
  
  StartDriving();
  
}

void loop()
{
  Serial.print (irDetect(6, 4, 38000));
  if (irDetect(6, 4, 38000)==0){
    FollowSideSensor();
    exit(1);
  }}
  

