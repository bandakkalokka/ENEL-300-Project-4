#define BUZZER  10
#define LED 7


void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED,LOW);
  tone(BUZZER, 5000, 500);
}

void loop() {
  // put your main code here, to run repeatedly:

}
