/*
 * 
 * void Beep()
 * 
 * The purpose of the Beep function is to inform that the patient has been found.
 * Originally, both the buzzer and LED were attached to pin 10 along with a 1k resistor.
 * However, soon it was evident that the current required to drive the pin was too high.
 * Then the decision was taken to use pin 10 for Buzzer and pin 7 for LED.
 * 
 */



#define BUZZER  10
#define LED 7

void setup() {

  /* Assign pinModes to Buzzer and LED */
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  Beep();                                              // Call to Beep function

}


void Beep() {
  // Beep Buzzer 5 times
  for(int i = 0; i < 5; i++){
    tone(BUZZER, 1000, 500);
    delay(1000);
  }

  //Blink LED once
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED,LOW); 
}

void loop() {

}
