 // Include Wire Library for I2C
#include <Wire.h>
// Include NewLiquidCrystal Library for I2C
#include <LiquidCrystal_I2C.h>
// (0x27)
const int  en = 2, rw = 1, rs = 0, d4 = 4, d5 = 5, d6 = 6, d7 = 7, bl = 3;
 
// Define I2C Address - change if reqiuired
const int i2c_addr = 0x27;
 
// LiquidCrystal_I2C lcd(i2c_addr, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);
LiquidCrystal_I2C lcd(0x27, 16,2);
 
void setup()
{
 
 lcd.init();
  lcd.backlight();
 
}
 
 
void loop()
{
   // Set display type as 16 char, 2 rows
  lcd.begin(16,2);
  
  // Print on first row
  lcd.setCursor(0,0);
  lcd.print("aaaaa world!");
  
  // Wait 1 second
  delay(100);
  
  // Print on second row
  lcd.setCursor(0,1);
  lcd.print("aaaaa are you?");
  
  // Wait 8 seconds
  delay(300);
  
  // Clear the display
  lcd.clear();
 
}