#include <LiquidCrystal.h>

LiquidCrystal lcd(A5,A4,A3,A2,A1,A0);

int fluid_speed = 0;
int volume = 0;


void setup()
{
  lcd.begin(16,2);
  

}

void loop() {
  if(volume ==1000){
    fluid_speed = 0;
    volume = 0;
    delay(4000);
  }
  lcd.setCursor(0,0);
  
  lcd.print("Speed : ");
  lcd.print(getFluidSpeed());
  lcd.print("mL");

  lcd.setCursor(0,1);
  lcd.print("Total : ");
  lcd.print(getVolume());
  lcd.print("mL");

  delay(100);
  
  lcd.clear(); 
  
}


int getFluidSpeed(){
  return fluid_speed++;
}

int getVolume(){
  return volume++;
}