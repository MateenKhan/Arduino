 // Include Wire Library for I2C
#include <Wire.h>
// Include NewLiquidCrystal Library for I2C
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>


const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] ={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};

byte rowPins[ROWS] ={2,3,4,5}; 
byte colPins[COLS] ={6,7,8,9}; 
LiquidCrystal_I2C lcd(0x27, 16,2);


void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.begin(16,2);
}

void loop() {
  lcd.setCursor(0,0);
  char pressedKey = customKeypad.getKey();
  
  if(pressedKey){
    lcd.print(pressedKey);
    Serial.println(pressedKey);
  }

  
  
}