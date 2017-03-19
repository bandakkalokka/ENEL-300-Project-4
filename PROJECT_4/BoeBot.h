/*
 *
 *    BoeBot.h
 *    This file contains all necessary macros
 *    and constants needed for the BoeBot to 
 *    function.
 *
 */


/*----------------------------------------*/
/*	DIGITAL I/O PINS		  */
/*----------------------------------------*/

#define FRONT_IR_LED              2                   				  // Digital I/O pin for front led
#define RIGHT_IR_LED              6                   				  // Digital I/O pin for right-side led
#define FRONT_IR_SENSOR           5                 				    // Digital I/O pin for front sensor
#define RIGHT_IR_SENSOR           4                   				  // Digital I/O pin for right sensor
#define RIGHT_SERVO               13                  			    // Digital I/O pin for right servo
#define LEFT_SERVO                12                  				  // Digital I/O pin for left servo
#define BUZZER            	      10					                  // Digital I/O pin for buzzer 
#define LED			                  7						                  // Digital I/O pin for LED

/*----------------------------------------*/
/*	SERVO CONTROL SPECIFICATIONS	  */
/*----------------------------------------*/

#define MAX_RIGHT_SPEED             1400                                          // Ideal Right Servo Max Speed to got straight
#define MAX_LEFT_SPEED              1638                                          // Ideal Left Servo Max Speed to got straight
#define MIN_SPEED                   1500                                          // Ideal Stop Servo Speed 
#define MAX_DELTA_SPEED             (MAX_LEFT_SPEED - MAX_RIGHT_SPEED) / 2        // Approximate Max Speed
#define MIN_DELTA_SPEED               0
#define ACCELERATION                  1
