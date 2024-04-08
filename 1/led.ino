

void setup()
{
    Serial.begin(9600);

    pinMode(9, OUTPUT);
}

void loop()
{
    if (Serial.available())
    {
        String command = Serial.readStringUntil('\n'); // read string until meet newline character

        if (command == "ON")
        {
            digitalWrite(9, HIGH);              // turn on LED
            Serial.println("LED is turned ON"); // send action to Serial Monitor
        }
        else if (command == "OFF")
        {
            digitalWrite(9, LOW);                // turn off LED
            Serial.println("LED is turned OFF"); // send action to Serial Monitor
        }
        else
        {
            Serial.println("type either ON OR OFF"); // send action to Serial Monitor
        }
    }
}
