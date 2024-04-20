#define RELAY_PIN 2
int ctr =0;
void setup() {
  // put your setup code here, to run once:
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  if(ctr==20){
    ctr=0;
    delay(2000);
  }
  // put your main code here, to run repeatedly:
  digitalWrite(RELAY_PIN, LOW);
  delay(50);
  digitalWrite(RELAY_PIN, HIGH);
  delay(50);
  ctr++;
}
