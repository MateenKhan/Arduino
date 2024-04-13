#include <Keypad.h>

#include <LiquidCrystal.h>

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
Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);


void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop() {
  char pressedKey = customKeypad.getKey();
  
  if(pressedKey){
    lcd.print(pressedKey);
    Serial.println(pressedKey);
    
  }

  
  
}