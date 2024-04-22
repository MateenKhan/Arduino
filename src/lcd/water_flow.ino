#include <LiquidCrystal.h>

LiquidCrystal lcd(A5,A4,A3,A2,A1,A0);

int fluid_speed = 0;
int volume = 0;


void setup()
{
  lcd.begin(16,2);
}

void loop() {
  if(volume ==100){
    fluid_speed = 0;
    volume = 0;
    lcd.display();
    delay(4000);
    lcd.clear();
  }
  lcd.setCursor(0,0);
  lcd.print("Speed : ");

  lcd.setCursor(14,0);
  lcd.print("mL");


  lcd.setCursor(10,0);
  lcd.print(getFluidSpeed());


  lcd.setCursor(0,1);
  lcd.print("Total : ");

  lcd.setCursor(14,1);
  lcd.print("mL");


  lcd.setCursor(10,1);
  lcd.print(getVolume());



  delay(40);
  
}


int getFluidSpeed(){
  return fluid_speed++;
}

int getVolume(){
  return volume++;
}