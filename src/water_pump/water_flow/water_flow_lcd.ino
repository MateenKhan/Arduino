#include <LiquidCrystal.h>
#define FLOW_SENSOR_PIN 2

LiquidCrystal lcd(A5,A4,A3,A2,A1,A0);

int fluid_speed = 0;
volatile long pulse; 
float volume;

void setup()
{
  pinMode(FLOW_SENSOR_PIN, INPUT);
  // Serial.begin(9600);
  lcd.begin(16,2);
  
  lcd.setCursor(0,0);
  lcd.print("Speed : ");
  lcd.setCursor(14,0);
  lcd.print("mL");

  lcd.setCursor(0,1);
  lcd.print("Total : ");
  lcd.setCursor(14,1);
  lcd.print("mL");

  attachInterrupt(digitalPinToInterrupt(FLOW_SENSOR_PIN), increase, RISING);

}

void loop() {

  

  // lcd.setCursor(8,0);
  // lcd.print(getFluidSpeed());
  lcd.setCursor(8,1);
  lcd.print(getVolume());



  delay(500);
  
}

void increase(){
    pulse++;
}

int getFluidSpeed(){
  return fluid_speed++;
}

float getVolume(){
  return 2.663 * pulse;
}