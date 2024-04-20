#define RELAY_PIN 2
void setup() {
  // put your setup code here, to run once:
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RELAY_PIN, LOW);
  delay(2000);
  digitalWrite(RELAY_PIN, HIGH);
  delay(2000);
}
