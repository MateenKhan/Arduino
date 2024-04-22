#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


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
  
  lcd.print("Speed:");
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
  fluid_speed++;
}

int getVolume(){
  volume++;
}