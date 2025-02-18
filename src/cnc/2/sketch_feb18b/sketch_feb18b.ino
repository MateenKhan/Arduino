// defines pins numbers

const int stepX = 2;
const int dirX = 5;

const int stepY = 3;
const int dirY = 6;

const int stepZ = 4;
const int dirZ = 7;

const int enPin = 8;

const int loopCtr = 200 * 6;

const int min_motor_delay = 400;
const int motor_delay = 1000;

void setup() {
  // Sets the two pins as Outputs
  pinMode(stepX, OUTPUT);
  pinMode(dirX, OUTPUT);

  pinMode(stepY, OUTPUT);
  pinMode(dirY, OUTPUT);

  pinMode(stepZ, OUTPUT);
  pinMode(dirZ, OUTPUT);

  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW);

  digitalWrite(dirX, HIGH);
  digitalWrite(dirY, LOW);

  digitalWrite(dirZ, HIGH);
}

void loop() {

  // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for (int x = 0; x < loopCtr; x++) {
    rotate(stepX,motor_delay);
  }
  // delay(1000);  // One second delay


  for (int x = 0; x < loopCtr; x++) {
    rotate(stepY,motor_delay);
  }

  // delay(1000);  // One second delay

  for (int x = 0; x < loopCtr; x++) {
    rotate(stepZ,motor_delay);
  }

  delay(1000);  // One second delay
}

void rotate(int motor,int t_delay){
    digitalWrite(motor, HIGH);
    delayMicroseconds(t_delay);
    digitalWrite(motor, LOW);
    delayMicroseconds(t_delay);
}