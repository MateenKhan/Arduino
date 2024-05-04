// Include Wire Library for I2C
#include <Wire.h>
// Include NewLiquidCrystal Library for I2C
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'},
};
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};
Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();
    lcd.begin(16, 2);

    lcd.setCursor(0, 0);
    lcd.print("Speed : ");

    lcd.setCursor(14, 0);
    lcd.print("mL");

    lcd.setCursor(0, 1);
    lcd.print("Total : ");

    lcd.setCursor(14, 1);
    lcd.print("mL");
}

void loop()
{

    char pressedKey = customKeypad.getKey();
    if (pressedKey)
    {
        lcd.setCursor(10, 0);
        lcd.print(pressedKey);

        lcd.setCursor(10, 1);
        lcd.print(pressedKey);
    }

    delay(200);
}
