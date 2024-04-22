#define FLOW_SENSOR_PIN 2
volatile long pulse; 
float volume;

void setup()
{
    pinMode(FLOW_SENSOR_PIN, INPUT);
    Serial.begin(9600);
    attachInterrupt(digitalPinToInterrupt(FLOW_SENSOR_PIN), _increase, RISING);
}

void loop()
{
    volume = 2.663 * pulse;
    Serial.print(volume);
    Serial.println(" mL ");
    delay(500);
}

void _increase(){
    pulse++;
}