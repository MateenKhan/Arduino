#include <LiquidCrystal.h>

// LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
LiquidCrystal lcd(12, 11, 6, 5, 4, 3);
void setup()
{
  lcd.begin(16,1);
  lcd.print("hello, world!");
}

void loop() {}