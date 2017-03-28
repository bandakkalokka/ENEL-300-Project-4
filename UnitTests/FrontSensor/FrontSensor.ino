/*
 * 
 *  void CheckFrontSensor()
 *  
 *  The purpose of the CheckFrontSensor() function is to check for obstacles using the front sensor.
 *  The helper function irDetect(LED, Sensor, Frequency) is used to parse the input from the sensor.
 *  The sensor is listening at a frequency of 38000Hz (infared), and the digitalRead function is called
 *  every 2 ms. The counter variable within is used to count the number of 0's seen since first seeing an object.
 *  The code below is implemented to stop the BoeBot with an exit code of 1 if an object is detected infront
 *  within a given distance.
 *  
 *  Note: CheckFrontSensor() was implemented slightly differently due to not being able to use arguements in the
 *  void loop() function. Due to simplicity, it is implemented using the void loop() function here.
 */

#define FRONT_IR_SENSOR   5
#define FRONT_IR_LED      2

int irFront;
int counter;                                    // An arguement in CheckFrontSensor 
int distance = 200;                             // Specified distance to stop from obstacle 
int stopper = 2;                                // An arguement in CheckFrontSensor
int frequency = 38000;                          // An arguement in CheckFrontSensor


void setup() {
  pinMode(FRONT_IR_LED, OUTPUT);    pinMode(FRONT_IR_SENSOR, INPUT);      // Assign pins
}



void loop() {
  irFront=irDetect(FRONT_IR_LED, FRONT_IR_SENSOR, frequency);                           
  
    if(irFront==0){  
      counter=0;                                                        // Set counter to zero
      for(int timespan=0; timespan<distance; timespan++){
      
        if (irDetect(FRONT_IR_LED,FRONT_IR_SENSOR, frequency)==0){
          counter++;                                                    // Increment counter if object is detected
        }
    
        if(counter >= distance){                                        // Stop if counter > distance
          if(stopper == 1)  
            StopDriving();
          else if(stopper == 2)
            StopImmediate();
          exit(1);
        }
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

/* Code for void StopDriving implemented in StopDriving UnitTest */
void StopDriving(){}

/* Code for void StopImmedrate implemented in StopImmediate UnitTest */
void StopImmediate(){}
