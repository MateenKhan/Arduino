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
int LED = 10;
int relay = 11;
int intput_volume = 0;
int total_volume = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(relay, OUTPUT);
    digitalWrite(relay, LOW);
    lcd.init();
    lcd.backlight();
    lcd.begin(16, 2);
    printConstantFillingInformation();

    pinMode(LED, OUTPUT);
    turnOffPump();
}

void loop()
{

    char pressedKey = customKeypad.getKey();
    if (pressedKey){
        if (pressedKey >= '0' && pressedKey <= '9'){
            intput_volume = intput_volume * 10 + (pressedKey - '0');
        }
        lcd.setCursor(7, 0);
        lcd.print(intput_volume);
        if (pressedKey == 'D'){
            startFillingLiquid();
            while(total_volume<=intput_volume){
                total_volume++;
                lcd.setCursor(7, 1);
                lcd.print(total_volume);
                delay(100);        
            }
            stopFillingLiquid();
        }
    }
    delay(200);
}

void startFillingLiquid(){
    digitalWrite(LED, HIGH);
    turnOnPump();
}

void stopFillingLiquid(){
    digitalWrite(LED, LOW);
    turnOffPump();
    delay(2000);
    intput_volume = 0;
    total_volume = 0;
}

void turnOnPump(){
    digitalWrite(relay, LOW);
}

void turnOffPump(){
    digitalWrite(relay, HIGH);
}

void printConstantFillingInformation(){
    lcd.setCursor(0, 0);
    lcd.print("input : ");

    lcd.setCursor(14, 0);
    lcd.print("mL");

    lcd.setCursor(0, 1);
    lcd.print("Total : ");

    lcd.setCursor(14, 1);
    lcd.print("mL");
}