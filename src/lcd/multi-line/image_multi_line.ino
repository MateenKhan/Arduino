#include <LiquidCrystal.h>

// LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
LiquidCrystal lcd(A5,A4,A3,A2,A1,A0);
// LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
void setup()
{
  lcd.begin(16,2);
  

}

void loop() {
  // lcd.setCursor(0,0);
  
  lcd.print("Parvind");
  delay(2000);

  lcd.setCursor(0,1);
  lcd.print("Sharma");
  
  delay(1000);
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.clear();
  delay(1000);
  
  
}